extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char data_heap;
extern char fdinstall_map;
extern char kprobe_calls;
extern char process_call_heap;
extern char retprobe_map;
extern char socktrack_map;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tg_ipv6_ext_heap;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_0(
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
	case 74ULL: goto x86_l_4a;
	case 81ULL: goto x86_l_51;
	case 87ULL: goto x86_l_57;
	case 98ULL: goto x86_l_62;
	case 105ULL: goto x86_l_69;
	case 113ULL: goto x86_l_71;
	case 118ULL: goto x86_l_76;
	case 120ULL: goto x86_l_78;
	case 123ULL: goto x86_l_7b;
	case 129ULL: goto x86_l_81;
	case 132ULL: goto x86_l_84;
	case 139ULL: goto x86_l_8b;
	case 146ULL: goto x86_l_92;
	case 151ULL: goto x86_l_97;
	case 153ULL: goto x86_l_99;
	case 156ULL: goto x86_l_9c;
	case 162ULL: goto x86_l_a2;
	case 165ULL: goto x86_l_a5;
	case 171ULL: goto x86_l_ab;
	case 176ULL: goto x86_l_b0;
	case 178ULL: goto x86_l_b2;
	case 181ULL: goto x86_l_b5;
	case 183ULL: goto x86_l_b7;
	case 188ULL: goto x86_l_bc;
	case 193ULL: goto x86_l_c1;
	case 195ULL: goto x86_l_c3;
	case 207ULL: goto x86_l_cf;
	case 213ULL: goto x86_l_d5;
	case 217ULL: goto x86_l_d9;
	case 222ULL: goto x86_l_de;
	case 227ULL: goto x86_l_e3;
	case 229ULL: goto x86_l_e5;
	case 231ULL: goto x86_l_e7;
	case 233ULL: goto x86_l_e9;
	case 237ULL: goto x86_l_ed;
	case 243ULL: goto x86_l_f3;
	case 247ULL: goto x86_l_f7;
	case 250ULL: goto x86_l_fa;
	case 258ULL: goto x86_l_102;
	case 263ULL: goto x86_l_107;
	case 275ULL: goto x86_l_113;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 295ULL: goto x86_l_127;
	case 298ULL: goto x86_l_12a;
	case 300ULL: goto x86_l_12c;
	case 302ULL: goto x86_l_12e;
	case 306ULL: goto x86_l_132;
	case 314ULL: goto x86_l_13a;
	case 316ULL: goto x86_l_13c;
	case 319ULL: goto x86_l_13f;
	case 325ULL: goto x86_l_145;
	case 328ULL: goto x86_l_148;
	case 333ULL: goto x86_l_14d;
	case 338ULL: goto x86_l_152;
	case 343ULL: goto x86_l_157;
	case 346ULL: goto x86_l_15a;
	case 351ULL: goto x86_l_15f;
	case 356ULL: goto x86_l_164;
	case 358ULL: goto x86_l_166;
	case 361ULL: goto x86_l_169;
	case 366ULL: goto x86_l_16e;
	case 373ULL: goto x86_l_175;
	case 378ULL: goto x86_l_17a;
	case 380ULL: goto x86_l_17c;
	case 385ULL: goto x86_l_181;
	case 388ULL: goto x86_l_184;
	case 393ULL: goto x86_l_189;
	case 395ULL: goto x86_l_18b;
	case 399ULL: goto x86_l_18f;
	case 402ULL: goto x86_l_192;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 418ULL: goto x86_l_1a2;
	case 420ULL: goto x86_l_1a4;
	case 422ULL: goto x86_l_1a6;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 433ULL: goto x86_l_1b1;
	case 436ULL: goto x86_l_1b4;
	case 444ULL: goto x86_l_1bc;
	case 449ULL: goto x86_l_1c1;
	case 453ULL: goto x86_l_1c5;
	case 455ULL: goto x86_l_1c7;
	case 457ULL: goto x86_l_1c9;
	case 462ULL: goto x86_l_1ce;
	case 466ULL: goto x86_l_1d2;
	case 474ULL: goto x86_l_1da;
	case 477ULL: goto x86_l_1dd;
	case 483ULL: goto x86_l_1e3;
	case 487ULL: goto x86_l_1e7;
	case 490ULL: goto x86_l_1ea;
	case 496ULL: goto x86_l_1f0;
	case 502ULL: goto x86_l_1f6;
	case 505ULL: goto x86_l_1f9;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 522ULL: goto x86_l_20a;
	case 527ULL: goto x86_l_20f;
	case 532ULL: goto x86_l_214;
	case 536ULL: goto x86_l_218;
	case 542ULL: goto x86_l_21e;
	case 550ULL: goto x86_l_226;
	case 557ULL: goto x86_l_22d;
	case 560ULL: goto x86_l_230;
	case 562ULL: goto x86_l_232;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 572ULL: goto x86_l_23c;
	case 577ULL: goto x86_l_241;
	case 582ULL: goto x86_l_246;
	case 585ULL: goto x86_l_249;
	case 590ULL: goto x86_l_24e;
	case 592ULL: goto x86_l_250;
	case 594ULL: goto x86_l_252;
	case 596ULL: goto x86_l_254;
	case 599ULL: goto x86_l_257;
	case 603ULL: goto x86_l_25b;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 617ULL: goto x86_l_269;
	case 619ULL: goto x86_l_26b;
	case 624ULL: goto x86_l_270;
	case 628ULL: goto x86_l_274;
	case 631ULL: goto x86_l_277;
	case 634ULL: goto x86_l_27a;
	case 641ULL: goto x86_l_281;
	case 643ULL: goto x86_l_283;
	case 648ULL: goto x86_l_288;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 657ULL: goto x86_l_291;
	case 664ULL: goto x86_l_298;
	case 666ULL: goto x86_l_29a;
	case 671ULL: goto x86_l_29f;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 686ULL: goto x86_l_2ae;
	case 688ULL: goto x86_l_2b0;
	case 690ULL: goto x86_l_2b2;
	case 692ULL: goto x86_l_2b4;
	case 695ULL: goto x86_l_2b7;
	case 703ULL: goto x86_l_2bf;
	case 706ULL: goto x86_l_2c2;
	case 714ULL: goto x86_l_2ca;
	case 720ULL: goto x86_l_2d0;
	case 724ULL: goto x86_l_2d4;
	case 726ULL: goto x86_l_2d6;
	case 730ULL: goto x86_l_2da;
	case 735ULL: goto x86_l_2df;
	case 737ULL: goto x86_l_2e1;
	case 741ULL: goto x86_l_2e5;
	case 747ULL: goto x86_l_2eb;
	case 751ULL: goto x86_l_2ef;
	case 757ULL: goto x86_l_2f5;
	case 761ULL: goto x86_l_2f9;
	case 764ULL: goto x86_l_2fc;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 780ULL: goto x86_l_30c;
	case 785ULL: goto x86_l_311;
	case 789ULL: goto x86_l_315;
	case 794ULL: goto x86_l_31a;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 806ULL: goto x86_l_326;
	case 810ULL: goto x86_l_32a;
	case 813ULL: goto x86_l_32d;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 829ULL: goto x86_l_33d;
	case 833ULL: goto x86_l_341;
	case 839ULL: goto x86_l_347;
	case 844ULL: goto x86_l_34c;
	case 848ULL: goto x86_l_350;
	case 854ULL: goto x86_l_356;
	case 858ULL: goto x86_l_35a;
	case 861ULL: goto x86_l_35d;
	case 867ULL: goto x86_l_363;
	case 871ULL: goto x86_l_367;
	case 874ULL: goto x86_l_36a;
	case 880ULL: goto x86_l_370;
	case 885ULL: goto x86_l_375;
	case 889ULL: goto x86_l_379;
	case 895ULL: goto x86_l_37f;
	case 899ULL: goto x86_l_383;
	case 905ULL: goto x86_l_389;
	case 909ULL: goto x86_l_38d;
	case 915ULL: goto x86_l_393;
	case 919ULL: goto x86_l_397;
	case 925ULL: goto x86_l_39d;
	case 930ULL: goto x86_l_3a2;
	case 934ULL: goto x86_l_3a6;
	case 940ULL: goto x86_l_3ac;
	case 944ULL: goto x86_l_3b0;
	case 950ULL: goto x86_l_3b6;
	case 954ULL: goto x86_l_3ba;
	case 960ULL: goto x86_l_3c0;
	case 964ULL: goto x86_l_3c4;
	case 970ULL: goto x86_l_3ca;
	case 976ULL: goto x86_l_3d0;
	case 981ULL: goto x86_l_3d5;
	case 985ULL: goto x86_l_3d9;
	case 991ULL: goto x86_l_3df;
	case 995ULL: goto x86_l_3e3;
	case 1001ULL: goto x86_l_3e9;
	case 1005ULL: goto x86_l_3ed;
	case 1007ULL: goto x86_l_3ef;
	case 1011ULL: goto x86_l_3f3;
	case 1017ULL: goto x86_l_3f9;
	case 1022ULL: goto x86_l_3fe;
	case 1026ULL: goto x86_l_402;
	case 1028ULL: goto x86_l_404;
	case 1033ULL: goto x86_l_409;
	case 1037ULL: goto x86_l_40d;
	case 1043ULL: goto x86_l_413;
	case 1047ULL: goto x86_l_417;
	case 1049ULL: goto x86_l_419;
	case 1051ULL: goto x86_l_41b;
	case 1055ULL: goto x86_l_41f;
	case 1058ULL: goto x86_l_422;
	case 1060ULL: goto x86_l_424;
	case 1066ULL: goto x86_l_42a;
	case 1068ULL: goto x86_l_42c;
	case 1074ULL: goto x86_l_432;
	case 1076ULL: goto x86_l_434;
	case 1080ULL: goto x86_l_438;
	case 1082ULL: goto x86_l_43a;
	case 1086ULL: goto x86_l_43e;
	case 1088ULL: goto x86_l_440;
	case 1094ULL: goto x86_l_446;
	case 1096ULL: goto x86_l_448;
	case 1100ULL: goto x86_l_44c;
	case 1102ULL: goto x86_l_44e;
	case 1106ULL: goto x86_l_452;
	case 1108ULL: goto x86_l_454;
	case 1110ULL: goto x86_l_456;
	case 1116ULL: goto x86_l_45c;
	case 1118ULL: goto x86_l_45e;
	case 1122ULL: goto x86_l_462;
	case 1124ULL: goto x86_l_464;
	case 1128ULL: goto x86_l_468;
	case 1130ULL: goto x86_l_46a;
	case 1136ULL: goto x86_l_470;
	case 1138ULL: goto x86_l_472;
	case 1144ULL: goto x86_l_478;
	case 1146ULL: goto x86_l_47a;
	case 1152ULL: goto x86_l_480;
	case 1154ULL: goto x86_l_482;
	case 1158ULL: goto x86_l_486;
	case 1160ULL: goto x86_l_488;
	case 1166ULL: goto x86_l_48e;
	case 1168ULL: goto x86_l_490;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1187ULL: goto x86_l_4a3;
	case 1194ULL: goto x86_l_4aa;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1209ULL: goto x86_l_4b9;
	case 1212ULL: goto x86_l_4bc;
	case 1218ULL: goto x86_l_4c2;
	case 1223ULL: goto x86_l_4c7;
	case 1226ULL: goto x86_l_4ca;
	case 1229ULL: goto x86_l_4cd;
	case 1235ULL: goto x86_l_4d3;
	case 1239ULL: goto x86_l_4d7;
	case 1246ULL: goto x86_l_4de;
	case 1253ULL: goto x86_l_4e5;
	case 1257ULL: goto x86_l_4e9;
	case 1265ULL: goto x86_l_4f1;
	case 1270ULL: goto x86_l_4f6;
	case 1272ULL: goto x86_l_4f8;
	case 1278ULL: goto x86_l_4fe;
	case 1281ULL: goto x86_l_501;
	case 1288ULL: goto x86_l_508;
	case 1295ULL: goto x86_l_50f;
	case 1298ULL: goto x86_l_512;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1320ULL: goto x86_l_528;
	case 1324ULL: goto x86_l_52c;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1339ULL: goto x86_l_53b;
	case 1341ULL: goto x86_l_53d;
	case 1345ULL: goto x86_l_541;
	case 1347ULL: goto x86_l_543;
	case 1351ULL: goto x86_l_547;
	case 1357ULL: goto x86_l_54d;
	case 1361ULL: goto x86_l_551;
	case 1367ULL: goto x86_l_557;
	case 1379ULL: goto x86_l_563;
	case 1387ULL: goto x86_l_56b;
	case 1395ULL: goto x86_l_573;
	case 1400ULL: goto x86_l_578;
	case 1404ULL: goto x86_l_57c;
	case 1410ULL: goto x86_l_582;
	case 1414ULL: goto x86_l_586;
	case 1420ULL: goto x86_l_58c;
	case 1425ULL: goto x86_l_591;
	case 1427ULL: goto x86_l_593;
	case 1432ULL: goto x86_l_598;
	case 1437ULL: goto x86_l_59d;
	case 1442ULL: goto x86_l_5a2;
	case 1447ULL: goto x86_l_5a7;
	case 1450ULL: goto x86_l_5aa;
	case 1455ULL: goto x86_l_5af;
	case 1457ULL: goto x86_l_5b1;
	case 1462ULL: goto x86_l_5b6;
	case 1467ULL: goto x86_l_5bb;
	case 1472ULL: goto x86_l_5c0;
	case 1477ULL: goto x86_l_5c5;
	case 1482ULL: goto x86_l_5ca;
	case 1487ULL: goto x86_l_5cf;
	case 1489ULL: goto x86_l_5d1;
	case 1493ULL: goto x86_l_5d5;
	case 1498ULL: goto x86_l_5da;
	case 1503ULL: goto x86_l_5df;
	case 1508ULL: goto x86_l_5e4;
	case 1513ULL: goto x86_l_5e9;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1534ULL: goto x86_l_5fe;
	case 1539ULL: goto x86_l_603;
	case 1550ULL: goto x86_l_60e;
	case 1557ULL: goto x86_l_615;
	case 1565ULL: goto x86_l_61d;
	case 1570ULL: goto x86_l_622;
	case 1572ULL: goto x86_l_624;
	case 1575ULL: goto x86_l_627;
	case 1581ULL: goto x86_l_62d;
	case 1584ULL: goto x86_l_630;
	case 1589ULL: goto x86_l_635;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1603ULL: goto x86_l_643;
	case 1610ULL: goto x86_l_64a;
	case 1618ULL: goto x86_l_652;
	case 1623ULL: goto x86_l_657;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1635ULL: goto x86_l_663;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1652ULL: goto x86_l_674;
	case 1660ULL: goto x86_l_67c;
	case 1665ULL: goto x86_l_681;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1680ULL: goto x86_l_690;
	case 1685ULL: goto x86_l_695;
	case 1690ULL: goto x86_l_69a;
	case 1692ULL: goto x86_l_69c;
	case 1700ULL: goto x86_l_6a4;
	case 1704ULL: goto x86_l_6a8;
	case 1709ULL: goto x86_l_6ad;
	case 1714ULL: goto x86_l_6b2;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1726ULL: goto x86_l_6be;
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
	/* 0xa: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_11:
	/* 0x11: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xec] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
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
	/* 0x38: je     dd2 <generic_kprobe_process_event+0xdd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3538ULL;
	}
x86_l_3e:
	/* 0x3e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    ebx,DWORD PTR [rax+0x5efc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_47:
	/* 0x47: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a:
	/* 0x4a: cmp    rbp,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 8999ULL);
x86_l_51:
	/* 0x51: ja     d36 <generic_kprobe_process_event+0xd36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3382ULL;
	}
x86_l_57:
	/* 0x57: mov    DWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_62:
	/* 0x62: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_69:
	/* 0x69: lea    rsi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_71:
	/* 0x71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_76:
	/* 0x76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78:
	/* 0x78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b:
	/* 0x7b: je     d36 <generic_kprobe_process_event+0xd36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3382ULL;
	}
x86_l_81:
	/* 0x81: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_84:
	/* 0x84: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_8b:
	/* 0x8b: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_92:
	/* 0x92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_97:
	/* 0x97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99:
	/* 0x99: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_9c:
	/* 0x9c: jg     d36 <generic_kprobe_process_event+0xd36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3382ULL;
	}
x86_l_a2:
	/* 0xa2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a5:
	/* 0xa5: je     d36 <generic_kprobe_process_event+0xd36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3382ULL;
	}
x86_l_ab:
	/* 0xab: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b0:
	/* 0xb0: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_b2:
	/* 0xb2: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b5:
	/* 0xb5: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_b7:
	/* 0xb7: mov    r13d,DWORD PTR [rax+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_bc:
	/* 0xbc: movsxd rsi,DWORD PTR [rax+rbp*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RBP, 2, X86_WIDTH_32), 24ULL);
x86_l_c1:
	/* 0xc1: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_c3:
	/* 0xc3: mov    DWORD PTR [r15+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_cf:
	/* 0xcf: test   esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_d5:
	/* 0xd5: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d9:
	/* 0xd9: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_de:
	/* 0xde: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e3:
	/* 0xe3: jne    107 <generic_kprobe_process_event+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_107;
	}
x86_l_e5:
	/* 0xe5: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_e7:
	/* 0xe7: js     11a <generic_kprobe_process_event+0x11a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_11a;
	}
x86_l_e9:
	/* 0xe9: test   sil,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 64ULL);
x86_l_ed:
	/* 0xed: jne    17c <generic_kprobe_process_event+0x17c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17c;
	}
x86_l_f3:
	/* 0xf3: mov    ecx,DWORD PTR [rax+rdx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 64ULL);
x86_l_f7:
	/* 0xf7: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_fa:
	/* 0xfa: mov    rsi,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_102:
	/* 0x102: jmp    1d2 <generic_kprobe_process_event+0x1d2> */
	goto x86_l_1d2;
x86_l_107:
	/* 0x107: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_113:
	/* 0x113: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_115:
	/* 0x115: jmp    2ca <generic_kprobe_process_event+0x2ca> */
	goto x86_l_2ca;
x86_l_11a:
	/* 0x11a: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11f:
	/* 0x11f: movzx  ecx,BYTE PTR [rax+rdx*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 2, X86_WIDTH_8), 706ULL);
x86_l_127:
	/* 0x127: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_12a:
	/* 0x12a: mov    bl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_8, 64ULL);
x86_l_12c:
	/* 0x12c: sub    bl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_12e:
	/* 0x12e: cmp    DWORD PTR [rax+0x54],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_132:
	/* 0x132: movzx  edx,WORD PTR [rax+rdx*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 2, X86_WIDTH_16), 704ULL);
x86_l_13a:
	/* 0x13a: je     19c <generic_kprobe_process_event+0x19c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19c;
	}
x86_l_13c:
	/* 0x13c: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_13f:
	/* 0x13f: je     1c7 <generic_kprobe_process_event+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c7;
	}
x86_l_145:
	/* 0x145: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_148:
	/* 0x148: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14d:
	/* 0x14d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_152:
	/* 0x152: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_157:
	/* 0x157: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_15a:
	/* 0x15a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f:
	/* 0x15f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_164:
	/* 0x164: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166:
	/* 0x166: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_169:
	/* 0x169: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e:
	/* 0x16e: shlx   rcx,QWORD PTR [rsp+0x68],rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RBX)), ((104ULL << 32) | X86_ALU_SHL));
x86_l_175:
	/* 0x175: sarx   rsi,rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RCX, X86_WIDTH_64, X86_RBX, X86_ALU_SAR);
x86_l_17a:
	/* 0x17a: jmp    1c9 <generic_kprobe_process_event+0x1c9> */
	goto x86_l_1c9;
x86_l_17c:
	/* 0x17c: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_181:
	/* 0x181: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_189:
	/* 0x189: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b:
	/* 0x18b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f:
	/* 0x18f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_192:
	/* 0x192: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_195:
	/* 0x195: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19a:
	/* 0x19a: jmp    1d2 <generic_kprobe_process_event+0x1d2> */
	goto x86_l_1d2;
x86_l_19c:
	/* 0x19c: movzx  ecx,bl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_19f:
	/* 0x19f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a2:
	/* 0x1a2: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1a4:
	/* 0x1a4: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1a6:
	/* 0x1a6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a9:
	/* 0x1a9: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 430ULL);
	__x86_sim_call_depth++;
	return 13423ULL;
x86_l_1ae:
	/* 0x1ae: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1b1:
	/* 0x1b1: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1bc:
	/* 0x1bc: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c1:
	/* 0x1c1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c5:
	/* 0x1c5: jmp    1da <generic_kprobe_process_event+0x1da> */
	goto x86_l_1da;
x86_l_1c7:
	/* 0x1c7: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c9:
	/* 0x1c9: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ce:
	/* 0x1ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2:
	/* 0x1d2: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1da:
	/* 0x1da: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1dd:
	/* 0x1dd: ja     2ca <generic_kprobe_process_event+0x2ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ca;
	}
x86_l_1e3:
	/* 0x1e3: lea    rcx,[rdx+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_1e7:
	/* 0x1e7: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_1ea:
	/* 0x1ea: cmp    WORD PTR [rax+rcx*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 506806140928ULL);
x86_l_1f0:
	/* 0x1f0: je     2ca <generic_kprobe_process_event+0x2ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ca;
	}
x86_l_1f6:
	/* 0x1f6: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f9:
	/* 0x1f9: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_1fd:
	/* 0x1fd: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_202:
	/* 0x202: lea    rax,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_20a:
	/* 0x20a: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_20f:
	/* 0x20f: mov    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_214:
	/* 0x214: lea    rax,[r15+rbp*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_218:
	/* 0x218: add    rax,0x5ea0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24224ULL);
x86_l_21e:
	/* 0x21e: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_226:
	/* 0x226: mov    rax,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_22d:
	/* 0x22d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230:
	/* 0x230: je     291 <generic_kprobe_process_event+0x291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_291;
	}
x86_l_232:
	/* 0x232: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_235:
	/* 0x235: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_23a:
	/* 0x23a: jmp    25d <generic_kprobe_process_event+0x25d> */
	goto x86_l_25d;
x86_l_23c:
	/* 0x23c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_241:
	/* 0x241: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_246:
	/* 0x246: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_249:
	/* 0x249: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24e:
	/* 0x24e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250:
	/* 0x250: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_252:
	/* 0x252: js     2b4 <generic_kprobe_process_event+0x2b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b4;
	}
x86_l_254:
	/* 0x254: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_257:
	/* 0x257: cmp    r15,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 10ULL);
x86_l_25b:
	/* 0x25b: je     2c2 <generic_kprobe_process_event+0x2c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c2;
	}
x86_l_25d:
	/* 0x25d: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_262:
	/* 0x262: cmp    WORD PTR [rax+r15*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 25769803776ULL);
x86_l_269:
	/* 0x269: je     2c2 <generic_kprobe_process_event+0x2c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c2;
	}
x86_l_26b:
	/* 0x26b: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_270:
	/* 0x270: mov    edx,DWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_274:
	/* 0x274: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_277:
	/* 0x277: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27a:
	/* 0x27a: cmp    WORD PTR [rax+r15*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 17179869184ULL);
x86_l_281:
	/* 0x281: je     254 <generic_kprobe_process_event+0x254> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_254;
	}
x86_l_283:
	/* 0x283: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_288:
	/* 0x288: je     23c <generic_kprobe_process_event+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23c;
	}
x86_l_28a:
	/* 0x28a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28f:
	/* 0x28f: jmp    241 <generic_kprobe_process_event+0x241> */
	goto x86_l_241;
x86_l_291:
	/* 0x291: lea    rsi,[rip+0x250] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 592ULL);
x86_l_298:
	/* 0x298: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29a:
	/* 0x29a: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_29f:
	/* 0x29f: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_2a4:
	/* 0x2a4: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_2a9:
	/* 0x2a9: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_2ae:
	/* 0x2ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b0:
	/* 0x2b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b2:
	/* 0x2b2: jmp    2c2 <generic_kprobe_process_event+0x2c2> */
	goto x86_l_2c2;
x86_l_2b4:
	/* 0x2b4: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b7:
	/* 0x2b7: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2bf:
	/* 0x2bf: mov    DWORD PTR [rax],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c2:
	/* 0x2c2: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2ca:
	/* 0x2ca: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_2d0:
	/* 0x2d0: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_2d4:
	/* 0x2d4: jg     311 <generic_kprobe_process_event+0x311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_311;
	}
x86_l_2d6:
	/* 0x2d6: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_2da:
	/* 0x2da: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2df:
	/* 0x2df: jg     34c <generic_kprobe_process_event+0x34c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_34c;
	}
x86_l_2e1:
	/* 0x2e1: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_2e5:
	/* 0x2e5: jg     3d5 <generic_kprobe_process_event+0x3d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3d5;
	}
x86_l_2eb:
	/* 0x2eb: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2ef:
	/* 0x2ef: jg     45e <generic_kprobe_process_event+0x45e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_45e;
	}
x86_l_2f5:
	/* 0x2f5: lea    eax,[r13-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_2f9:
	/* 0x2f9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fc:
	/* 0x2fc: jb     424 <generic_kprobe_process_event+0x424> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_424;
	}
x86_l_302:
	/* 0x302: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_306:
	/* 0x306: je     424 <generic_kprobe_process_event+0x424> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_424;
	}
x86_l_30c:
	/* 0x30c: jmp    490 <generic_kprobe_process_event+0x490> */
	goto x86_l_490;
x86_l_311:
	/* 0x311: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_315:
	/* 0x315: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31a:
	/* 0x31a: jle    375 <generic_kprobe_process_event+0x375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_375;
	}
x86_l_31c:
	/* 0x31c: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_320:
	/* 0x320: jg     3a2 <generic_kprobe_process_event+0x3a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a2;
	}
x86_l_326:
	/* 0x326: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_32a:
	/* 0x32a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32d:
	/* 0x32d: jb     472 <generic_kprobe_process_event+0x472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_472;
	}
x86_l_333:
	/* 0x333: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_337:
	/* 0x337: je     493 <generic_kprobe_process_event+0x493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493;
	}
x86_l_33d:
	/* 0x33d: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_341:
	/* 0x341: je     42c <generic_kprobe_process_event+0x42c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42c;
	}
x86_l_347:
	/* 0x347: jmp    490 <generic_kprobe_process_event+0x490> */
	goto x86_l_490;
x86_l_34c:
	/* 0x34c: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_350:
	/* 0x350: jg     3fe <generic_kprobe_process_event+0x3fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3fe;
	}
x86_l_356:
	/* 0x356: lea    eax,[r13-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_35a:
	/* 0x35a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_35d:
	/* 0x35d: jb     493 <generic_kprobe_process_event+0x493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_493;
	}
x86_l_363:
	/* 0x363: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_367:
	/* 0x367: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_36a:
	/* 0x36a: jb     424 <generic_kprobe_process_event+0x424> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_424;
	}
x86_l_370:
	/* 0x370: jmp    490 <generic_kprobe_process_event+0x490> */
	goto x86_l_490;
x86_l_375:
	/* 0x375: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_379:
	/* 0x379: jg     41b <generic_kprobe_process_event+0x41b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_41b;
	}
x86_l_37f:
	/* 0x37f: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_383:
	/* 0x383: je     42c <generic_kprobe_process_event+0x42c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42c;
	}
x86_l_389:
	/* 0x389: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_38d:
	/* 0x38d: je     472 <generic_kprobe_process_event+0x472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_472;
	}
x86_l_393:
	/* 0x393: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_397:
	/* 0x397: je     488 <generic_kprobe_process_event+0x488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_488;
	}
x86_l_39d:
	/* 0x39d: jmp    490 <generic_kprobe_process_event+0x490> */
	goto x86_l_490;
x86_l_3a2:
	/* 0x3a2: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_3a6:
	/* 0x3a6: jle    448 <generic_kprobe_process_event+0x448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_448;
	}
x86_l_3ac:
	/* 0x3ac: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_3b0:
	/* 0x3b0: je     493 <generic_kprobe_process_event+0x493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493;
	}
x86_l_3b6:
	/* 0x3b6: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_3ba:
	/* 0x3ba: je     456 <generic_kprobe_process_event+0x456> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_456;
	}
x86_l_3c0:
	/* 0x3c0: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_3c4:
	/* 0x3c4: jne    490 <generic_kprobe_process_event+0x490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_490;
	}
x86_l_3ca:
	/* 0x3ca: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_3d0:
	/* 0x3d0: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_3d5:
	/* 0x3d5: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_3d9:
	/* 0x3d9: jg     472 <generic_kprobe_process_event+0x472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_472;
	}
x86_l_3df:
	/* 0x3df: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_3e3:
	/* 0x3e3: je     493 <generic_kprobe_process_event+0x493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493;
	}
x86_l_3e9:
	/* 0x3e9: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_3ed:
	/* 0x3ed: je     46a <generic_kprobe_process_event+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46a;
	}
x86_l_3ef:
	/* 0x3ef: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3f3:
	/* 0x3f3: je     488 <generic_kprobe_process_event+0x488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_488;
	}
x86_l_3f9:
	/* 0x3f9: jmp    490 <generic_kprobe_process_event+0x490> */
	goto x86_l_490;
x86_l_3fe:
	/* 0x3fe: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_402:
	/* 0x402: jg     434 <generic_kprobe_process_event+0x434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_434;
	}
x86_l_404:
	/* 0x404: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_409:
	/* 0x409: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_40d:
	/* 0x40d: je     493 <generic_kprobe_process_event+0x493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493;
	}
x86_l_413:
	/* 0x413: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_417:
	/* 0x417: je     456 <generic_kprobe_process_event+0x456> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_456;
	}
x86_l_419:
	/* 0x419: jmp    490 <generic_kprobe_process_event+0x490> */
	goto x86_l_490;
x86_l_41b:
	/* 0x41b: lea    eax,[r13-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_41f:
	/* 0x41f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_422:
	/* 0x422: jae    482 <generic_kprobe_process_event+0x482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_482;
	}
x86_l_424:
	/* 0x424: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_42a:
	/* 0x42a: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_42c:
	/* 0x42c: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_432:
	/* 0x432: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_434:
	/* 0x434: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_438:
	/* 0x438: je     47a <generic_kprobe_process_event+0x47a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47a;
	}
x86_l_43a:
	/* 0x43a: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_43e:
	/* 0x43e: jne    490 <generic_kprobe_process_event+0x490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_490;
	}
x86_l_440:
	/* 0x440: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_446:
	/* 0x446: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_448:
	/* 0x448: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_44c:
	/* 0x44c: je     456 <generic_kprobe_process_event+0x456> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_456;
	}
x86_l_44e:
	/* 0x44e: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_452:
	/* 0x452: je     46a <generic_kprobe_process_event+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46a;
	}
x86_l_454:
	/* 0x454: jmp    490 <generic_kprobe_process_event+0x490> */
	goto x86_l_490;
x86_l_456:
	/* 0x456: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_45c:
	/* 0x45c: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_45e:
	/* 0x45e: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_462:
	/* 0x462: je     472 <generic_kprobe_process_event+0x472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_472;
	}
x86_l_464:
	/* 0x464: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_468:
	/* 0x468: jne    490 <generic_kprobe_process_event+0x490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_490;
	}
x86_l_46a:
	/* 0x46a: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_470:
	/* 0x470: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_472:
	/* 0x472: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_478:
	/* 0x478: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_47a:
	/* 0x47a: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_480:
	/* 0x480: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_482:
	/* 0x482: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_486:
	/* 0x486: jne    490 <generic_kprobe_process_event+0x490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_490;
	}
x86_l_488:
	/* 0x488: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_48e:
	/* 0x48e: jmp    493 <generic_kprobe_process_event+0x493> */
	goto x86_l_493;
x86_l_490:
	/* 0x490: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_493:
	/* 0x493: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_498:
	/* 0x498: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_4a3:
	/* 0x4a3: mov    rdi,QWORD PTR [rip+0x24c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_4aa:
	/* 0x4aa: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_4b2:
	/* 0x4b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b7:
	/* 0x4b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b9:
	/* 0x4b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4bc:
	/* 0x4bc: je     d36 <generic_kprobe_process_event+0xd36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3382ULL;
	}
x86_l_4c2:
	/* 0x4c2: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_4c7:
	/* 0x4c7: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4ca:
	/* 0x4ca: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_4cd:
	/* 0x4cd: jbe    d36 <generic_kprobe_process_event+0xd36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3382ULL;
	}
x86_l_4d3:
	/* 0x4d3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d7:
	/* 0x4d7: mov    ecx,DWORD PTR [rax+rdx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_4de:
	/* 0x4de: mov    DWORD PTR [rax+rbp*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_4e5:
	/* 0x4e5: lea    r15,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e9:
	/* 0x4e9: mov    QWORD PTR [rax+rdx*8+0x5e78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_4f1:
	/* 0x4f1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4f6:
	/* 0x4f6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4f8:
	/* 0x4f8: jne    d32 <generic_kprobe_process_event+0xd32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3378ULL;
	}
x86_l_4fe:
	/* 0x4fe: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_501:
	/* 0x501: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_508:
	/* 0x508: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_50f:
	/* 0x50f: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_512:
	/* 0x512: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_517:
	/* 0x517: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_51c:
	/* 0x51c: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_528:
	/* 0x528: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_52c:
	/* 0x52c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_531:
	/* 0x531: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_536:
	/* 0x536: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_53b:
	/* 0x53b: jle    578 <generic_kprobe_process_event+0x578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_578;
	}
x86_l_53d:
	/* 0x53d: cmp    r13d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 24ULL);
x86_l_541:
	/* 0x541: je     593 <generic_kprobe_process_event+0x593> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_593;
	}
x86_l_543:
	/* 0x543: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_547:
	/* 0x547: je     5d1 <generic_kprobe_process_event+0x5d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d1;
	}
x86_l_54d:
	/* 0x54d: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_551:
	/* 0x551: jne    b06 <generic_kprobe_process_event+0xb06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2822ULL;
	}
x86_l_557:
	/* 0x557: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_563:
	/* 0x563: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_56b:
	/* 0x56b: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_573:
	/* 0x573: jmp    5fe <generic_kprobe_process_event+0x5fe> */
	goto x86_l_5fe;
x86_l_578:
	/* 0x578: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_57c:
	/* 0x57c: je     a29 <generic_kprobe_process_event+0xa29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2601ULL;
	}
x86_l_582:
	/* 0x582: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_586:
	/* 0x586: jne    b06 <generic_kprobe_process_event+0xb06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2822ULL;
	}
x86_l_58c:
	/* 0x58c: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_591:
	/* 0x591: jmp    5bb <generic_kprobe_process_event+0x5bb> */
	goto x86_l_5bb;
x86_l_593:
	/* 0x593: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_598:
	/* 0x598: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_59d:
	/* 0x59d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a2:
	/* 0x5a2: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5a7:
	/* 0x5a7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5aa:
	/* 0x5aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5af:
	/* 0x5af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b1:
	/* 0x5b1: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5b6:
	/* 0x5b6: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5bb:
	/* 0x5bb: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5c0:
	/* 0x5c0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5c5:
	/* 0x5c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5ca:
	/* 0x5ca: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5cf:
	/* 0x5cf: jmp    5ee <generic_kprobe_process_event+0x5ee> */
	goto x86_l_5ee;
x86_l_5d1:
	/* 0x5d1: add    rdx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_5d5:
	/* 0x5d5: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5da:
	/* 0x5da: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5df:
	/* 0x5df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e4:
	/* 0x5e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e9:
	/* 0x5e9: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5ee:
	/* 0x5ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f3:
	/* 0x5f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f5:
	/* 0x5f5: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5fa:
	/* 0x5fa: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_5fe:
	/* 0x5fe: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_603:
	/* 0x603: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_60e:
	/* 0x60e: mov    rdi,QWORD PTR [rip+0x24c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_615:
	/* 0x615: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_61d:
	/* 0x61d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_622:
	/* 0x622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_624:
	/* 0x624: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_627:
	/* 0x627: je     6d0 <generic_kprobe_process_event+0x6d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1744ULL;
	}
x86_l_62d:
	/* 0x62d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_630:
	/* 0x630: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_635:
	/* 0x635: lea    rbx,[rax+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_63c:
	/* 0x63c: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_641:
	/* 0x641: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_643:
	/* 0x643: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_64a:
	/* 0x64a: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_652:
	/* 0x652: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_657:
	/* 0x657: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_65c:
	/* 0x65c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_661:
	/* 0x661: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_663:
	/* 0x663: mov    r12,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_66b:
	/* 0x66b: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_670:
	/* 0x670: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_674:
	/* 0x674: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_67c:
	/* 0x67c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_681:
	/* 0x681: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_686:
	/* 0x686: lea    rcx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68b:
	/* 0x68b: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_690:
	/* 0x690: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_695:
	/* 0x695: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69a:
	/* 0x69a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69c:
	/* 0x69c: mov    r15,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_6a4:
	/* 0x6a4: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a8:
	/* 0x6a8: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6ad:
	/* 0x6ad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6b2:
	/* 0x6b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b7:
	/* 0x6b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bc:
	/* 0x6bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6be:
	/* 0x6be: cmp    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
	return 1732ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1739ULL: goto x86_l_6cb;
	case 1742ULL: goto x86_l_6ce;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1757ULL: goto x86_l_6dd;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1783ULL: goto x86_l_6f7;
	case 1788ULL: goto x86_l_6fc;
	case 1791ULL: goto x86_l_6ff;
	case 1793ULL: goto x86_l_701;
	case 1796ULL: goto x86_l_704;
	case 1803ULL: goto x86_l_70b;
	case 1813ULL: goto x86_l_715;
	case 1820ULL: goto x86_l_71c;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1844ULL: goto x86_l_734;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1870ULL: goto x86_l_74e;
	case 1882ULL: goto x86_l_75a;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1907ULL: goto x86_l_773;
	case 1914ULL: goto x86_l_77a;
	case 1922ULL: goto x86_l_782;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1941ULL: goto x86_l_795;
	case 1946ULL: goto x86_l_79a;
	case 1954ULL: goto x86_l_7a2;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1970ULL: goto x86_l_7b2;
	case 1972ULL: goto x86_l_7b4;
	case 1977ULL: goto x86_l_7b9;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2047ULL: goto x86_l_7ff;
	case 2055ULL: goto x86_l_807;
	case 2059ULL: goto x86_l_80b;
	case 2067ULL: goto x86_l_813;
	case 2074ULL: goto x86_l_81a;
	case 2077ULL: goto x86_l_81d;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2107ULL: goto x86_l_83b;
	case 2115ULL: goto x86_l_843;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2141ULL: goto x86_l_85d;
	case 2146ULL: goto x86_l_862;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2161ULL: goto x86_l_871;
	case 2169ULL: goto x86_l_879;
	case 2175ULL: goto x86_l_87f;
	case 2179ULL: goto x86_l_883;
	case 2184ULL: goto x86_l_888;
	case 2189ULL: goto x86_l_88d;
	case 2194ULL: goto x86_l_892;
	case 2197ULL: goto x86_l_895;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2228ULL: goto x86_l_8b4;
	case 2230ULL: goto x86_l_8b6;
	case 2234ULL: goto x86_l_8ba;
	case 2239ULL: goto x86_l_8bf;
	case 2247ULL: goto x86_l_8c7;
	case 2252ULL: goto x86_l_8cc;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2262ULL: goto x86_l_8d6;
	case 2267ULL: goto x86_l_8db;
	case 2275ULL: goto x86_l_8e3;
	case 2283ULL: goto x86_l_8eb;
	case 2286ULL: goto x86_l_8ee;
	case 2294ULL: goto x86_l_8f6;
	case 2297ULL: goto x86_l_8f9;
	case 2300ULL: goto x86_l_8fc;
	case 2305ULL: goto x86_l_901;
	case 2308ULL: goto x86_l_904;
	case 2316ULL: goto x86_l_90c;
	case 2318ULL: goto x86_l_90e;
	case 2321ULL: goto x86_l_911;
	case 2325ULL: goto x86_l_915;
	case 2328ULL: goto x86_l_918;
	case 2332ULL: goto x86_l_91c;
	case 2334ULL: goto x86_l_91e;
	case 2337ULL: goto x86_l_921;
	case 2339ULL: goto x86_l_923;
	case 2346ULL: goto x86_l_92a;
	case 2349ULL: goto x86_l_92d;
	case 2355ULL: goto x86_l_933;
	case 2361ULL: goto x86_l_939;
	case 2367ULL: goto x86_l_93f;
	case 2370ULL: goto x86_l_942;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2379ULL: goto x86_l_94b;
	case 2382ULL: goto x86_l_94e;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2402ULL: goto x86_l_962;
	case 2410ULL: goto x86_l_96a;
	case 2413ULL: goto x86_l_96d;
	case 2419ULL: goto x86_l_973;
	case 2424ULL: goto x86_l_978;
	case 2432ULL: goto x86_l_980;
	case 2438ULL: goto x86_l_986;
	case 2440ULL: goto x86_l_988;
	case 2446ULL: goto x86_l_98e;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2492ULL: goto x86_l_9bc;
	case 2498ULL: goto x86_l_9c2;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2523ULL: goto x86_l_9db;
	case 2525ULL: goto x86_l_9dd;
	case 2530ULL: goto x86_l_9e2;
	case 2538ULL: goto x86_l_9ea;
	case 2542ULL: goto x86_l_9ee;
	case 2550ULL: goto x86_l_9f6;
	case 2552ULL: goto x86_l_9f8;
	case 2558ULL: goto x86_l_9fe;
	case 2563ULL: goto x86_l_a03;
	case 2570ULL: goto x86_l_a0a;
	case 2572ULL: goto x86_l_a0c;
	case 2577ULL: goto x86_l_a11;
	case 2582ULL: goto x86_l_a16;
	case 2587ULL: goto x86_l_a1b;
	case 2592ULL: goto x86_l_a20;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2601ULL: goto x86_l_a29;
	case 2609ULL: goto x86_l_a31;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2624ULL: goto x86_l_a40;
	case 2629ULL: goto x86_l_a45;
	case 2631ULL: goto x86_l_a47;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2647ULL: goto x86_l_a57;
	case 2653ULL: goto x86_l_a5d;
	case 2664ULL: goto x86_l_a68;
	case 2671ULL: goto x86_l_a6f;
	case 2679ULL: goto x86_l_a77;
	case 2684ULL: goto x86_l_a7c;
	case 2686ULL: goto x86_l_a7e;
	case 2689ULL: goto x86_l_a81;
	case 2695ULL: goto x86_l_a87;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2708ULL: goto x86_l_a94;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2722ULL: goto x86_l_aa2;
	case 2728ULL: goto x86_l_aa8;
	case 2732ULL: goto x86_l_aac;
	case 2738ULL: goto x86_l_ab2;
	case 2742ULL: goto x86_l_ab6;
	case 2748ULL: goto x86_l_abc;
	case 2752ULL: goto x86_l_ac0;
	case 2758ULL: goto x86_l_ac6;
	case 2762ULL: goto x86_l_aca;
	case 2768ULL: goto x86_l_ad0;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2797ULL: goto x86_l_aed;
	case 2802ULL: goto x86_l_af2;
	case 2809ULL: goto x86_l_af9;
	case 2811ULL: goto x86_l_afb;
	case 2817ULL: goto x86_l_b01;
	case 2822ULL: goto x86_l_b06;
	case 2826ULL: goto x86_l_b0a;
	case 2832ULL: goto x86_l_b10;
	case 2835ULL: goto x86_l_b13;
	case 2845ULL: goto x86_l_b1d;
	case 2849ULL: goto x86_l_b21;
	case 2855ULL: goto x86_l_b27;
	case 2860ULL: goto x86_l_b2c;
	case 2871ULL: goto x86_l_b37;
	case 2878ULL: goto x86_l_b3e;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2915ULL: goto x86_l_b63;
	case 2919ULL: goto x86_l_b67;
	case 2924ULL: goto x86_l_b6c;
	case 2930ULL: goto x86_l_b72;
	case 2934ULL: goto x86_l_b76;
	case 2939ULL: goto x86_l_b7b;
	case 2944ULL: goto x86_l_b80;
	case 2950ULL: goto x86_l_b86;
	case 2954ULL: goto x86_l_b8a;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2967ULL: goto x86_l_b97;
	case 2973ULL: goto x86_l_b9d;
	case 2978ULL: goto x86_l_ba2;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3006ULL: goto x86_l_bbe;
	case 3011ULL: goto x86_l_bc3;
	case 3016ULL: goto x86_l_bc8;
	case 3024ULL: goto x86_l_bd0;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3039ULL: goto x86_l_bdf;
	case 3042ULL: goto x86_l_be2;
	case 3044ULL: goto x86_l_be4;
	case 3052ULL: goto x86_l_bec;
	case 3055ULL: goto x86_l_bef;
	case 3062ULL: goto x86_l_bf6;
	case 3068ULL: goto x86_l_bfc;
	case 3071ULL: goto x86_l_bff;
	case 3073ULL: goto x86_l_c01;
	case 3077ULL: goto x86_l_c05;
	case 3080ULL: goto x86_l_c08;
	case 3085ULL: goto x86_l_c0d;
	case 3091ULL: goto x86_l_c13;
	case 3094ULL: goto x86_l_c16;
	case 3096ULL: goto x86_l_c18;
	case 3099ULL: goto x86_l_c1b;
	case 3101ULL: goto x86_l_c1d;
	case 3104ULL: goto x86_l_c20;
	case 3109ULL: goto x86_l_c25;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3123ULL: goto x86_l_c33;
	case 3130ULL: goto x86_l_c3a;
	case 3135ULL: goto x86_l_c3f;
	case 3138ULL: goto x86_l_c42;
	case 3140ULL: goto x86_l_c44;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3180ULL: goto x86_l_c6c;
	case 3188ULL: goto x86_l_c74;
	case 3193ULL: goto x86_l_c79;
	case 3198ULL: goto x86_l_c7e;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3214ULL: goto x86_l_c8e;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3237ULL: goto x86_l_ca5;
	case 3245ULL: goto x86_l_cad;
	case 3250ULL: goto x86_l_cb2;
	case 3252ULL: goto x86_l_cb4;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3268ULL: goto x86_l_cc4;
	case 3272ULL: goto x86_l_cc8;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3286ULL: goto x86_l_cd6;
	case 3288ULL: goto x86_l_cd8;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3303ULL: goto x86_l_ce7;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3321ULL: goto x86_l_cf9;
	case 3325ULL: goto x86_l_cfd;
	case 3330ULL: goto x86_l_d02;
	case 3333ULL: goto x86_l_d05;
	case 3335ULL: goto x86_l_d07;
	case 3342ULL: goto x86_l_d0e;
	case 3346ULL: goto x86_l_d12;
	case 3349ULL: goto x86_l_d15;
	case 3351ULL: goto x86_l_d17;
	case 3362ULL: goto x86_l_d22;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3380ULL: goto x86_l_d34;
	case 3382ULL: goto x86_l_d36;
	case 3386ULL: goto x86_l_d3a;
	case 3389ULL: goto x86_l_d3d;
	case 3391ULL: goto x86_l_d3f;
	case 3399ULL: goto x86_l_d47;
	case 3406ULL: goto x86_l_d4e;
	case 3411ULL: goto x86_l_d53;
	case 3416ULL: goto x86_l_d58;
	case 3418ULL: goto x86_l_d5a;
	case 3421ULL: goto x86_l_d5d;
	case 3423ULL: goto x86_l_d5f;
	case 3426ULL: goto x86_l_d62;
	case 3433ULL: goto x86_l_d69;
	case 3440ULL: goto x86_l_d70;
	case 3445ULL: goto x86_l_d75;
	case 3447ULL: goto x86_l_d77;
	case 3450ULL: goto x86_l_d7a;
	case 3452ULL: goto x86_l_d7c;
	case 3454ULL: goto x86_l_d7e;
	case 3456ULL: goto x86_l_d80;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3466ULL: goto x86_l_d8a;
	case 3473ULL: goto x86_l_d91;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3490ULL: goto x86_l_da2;
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3500ULL: goto x86_l_dac;
	case 3511ULL: goto x86_l_db7;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3538ULL: goto x86_l_dd2;
	case 3540ULL: goto x86_l_dd4;
	case 3547ULL: goto x86_l_ddb;
	case 3548ULL: goto x86_l_ddc;
	case 3550ULL: goto x86_l_dde;
	case 3552ULL: goto x86_l_de0;
	case 3554ULL: goto x86_l_de2;
	case 3556ULL: goto x86_l_de4;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c4:
	/* 0x6c4: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_6c9:
	/* 0x6c9: je     6dd <generic_kprobe_process_event+0x6dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6dd;
	}
x86_l_6cb:
	/* 0x6cb: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_6ce:
	/* 0x6ce: jmp    72b <generic_kprobe_process_event+0x72b> */
	goto x86_l_72b;
x86_l_6d0:
	/* 0x6d0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d3:
	/* 0x6d3: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d8:
	/* 0x6d8: jmp    cdb <generic_kprobe_process_event+0xcdb> */
	goto x86_l_cdb;
x86_l_6dd:
	/* 0x6dd: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e1:
	/* 0x6e1: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6e6:
	/* 0x6e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6eb:
	/* 0x6eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6f0:
	/* 0x6f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f5:
	/* 0x6f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f7:
	/* 0x6f7: cmp    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6fc:
	/* 0x6fc: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_6ff:
	/* 0x6ff: je     72b <generic_kprobe_process_event+0x72b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_72b;
	}
x86_l_701:
	/* 0x701: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_704:
	/* 0x704: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_70b:
	/* 0x70b: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_715:
	/* 0x715: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_71c:
	/* 0x71c: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_726:
	/* 0x726: mov    ebp,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4086ULL);
x86_l_72b:
	/* 0x72b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_734:
	/* 0x734: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_73d:
	/* 0x73d: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_742:
	/* 0x742: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_74e:
	/* 0x74e: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_75a:
	/* 0x75a: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_766:
	/* 0x766: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_76b:
	/* 0x76b: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_773:
	/* 0x773: mov    DWORD PTR [rsp+0xa0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_77a:
	/* 0x77a: mov    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_782:
	/* 0x782: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_786:
	/* 0x786: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_78b:
	/* 0x78b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_790:
	/* 0x790: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_795:
	/* 0x795: lea    r13,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_79a:
	/* 0x79a: lea    rbx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7a2:
	/* 0x7a2: lea    r15,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7aa:
	/* 0x7aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7af:
	/* 0x7af: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7b2:
	/* 0x7b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b4:
	/* 0x7b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7b9:
	/* 0x7b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7be:
	/* 0x7be: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7c3:
	/* 0x7c3: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_7c6:
	/* 0x7c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7cb:
	/* 0x7cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cd:
	/* 0x7cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7d2:
	/* 0x7d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7d7:
	/* 0x7d7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7dc:
	/* 0x7dc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7df:
	/* 0x7df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e4:
	/* 0x7e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e6:
	/* 0x7e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7eb:
	/* 0x7eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7f0:
	/* 0x7f0: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7f5:
	/* 0x7f5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7f8:
	/* 0x7f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7fd:
	/* 0x7fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ff:
	/* 0x7ff: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_807:
	/* 0x807: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_80b:
	/* 0x80b: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_813:
	/* 0x813: mov    rax,QWORD PTR [rip+0x24c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_81a:
	/* 0x81a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81d:
	/* 0x81d: je     a03 <generic_kprobe_process_event+0xa03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a03;
	}
x86_l_823:
	/* 0x823: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_828:
	/* 0x828: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_82e:
	/* 0x82e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_833:
	/* 0x833: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_83b:
	/* 0x83b: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_843:
	/* 0x843: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_84b:
	/* 0x84b: cmp    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_850:
	/* 0x850: jne    85d <generic_kprobe_process_event+0x85d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_85d;
	}
x86_l_852:
	/* 0x852: cmp    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_857:
	/* 0x857: je     bc8 <generic_kprobe_process_event+0xbc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc8;
	}
x86_l_85d:
	/* 0x85d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_862:
	/* 0x862: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_86a:
	/* 0x86a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_86f:
	/* 0x86f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_871:
	/* 0x871: cmp    r13,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 224ULL);
x86_l_879:
	/* 0x879: je     993 <generic_kprobe_process_event+0x993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_993;
	}
x86_l_87f:
	/* 0x87f: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_883:
	/* 0x883: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_888:
	/* 0x888: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_88d:
	/* 0x88d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_892:
	/* 0x892: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_895:
	/* 0x895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_897:
	/* 0x897: cmp    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_89c:
	/* 0x89c: je     993 <generic_kprobe_process_event+0x993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_993;
	}
x86_l_8a2:
	/* 0x8a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8a7:
	/* 0x8a7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8ac:
	/* 0x8ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b1:
	/* 0x8b1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8b4:
	/* 0x8b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b6:
	/* 0x8b6: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_8ba:
	/* 0x8ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8bf:
	/* 0x8bf: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_8c7:
	/* 0x8c7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_8cc:
	/* 0x8cc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_8d1:
	/* 0x8d1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8d4:
	/* 0x8d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d6:
	/* 0x8d6: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8db:
	/* 0x8db: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8e3:
	/* 0x8e3: mov    r12d,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_8eb:
	/* 0x8eb: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8ee:
	/* 0x8ee: mov    r13d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8f6:
	/* 0x8f6: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_8f9:
	/* 0x8f9: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8fc:
	/* 0x8fc: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_901:
	/* 0x901: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_904:
	/* 0x904: add    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 176ULL);
x86_l_90c:
	/* 0x90c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_90e:
	/* 0x90e: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_911:
	/* 0x911: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_915:
	/* 0x915: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_918:
	/* 0x918: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_91c:
	/* 0x91c: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_91e:
	/* 0x91e: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_921:
	/* 0x921: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_923:
	/* 0x923: mov    DWORD PTR [rsp+0xa0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_92a:
	/* 0x92a: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_92d:
	/* 0x92d: jb     bd0 <generic_kprobe_process_event+0xbd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_bd0;
	}
x86_l_933:
	/* 0x933: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_939:
	/* 0x939: ja     bd0 <generic_kprobe_process_event+0xbd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bd0;
	}
x86_l_93f:
	/* 0x93f: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_942:
	/* 0x942: jbe    949 <generic_kprobe_process_event+0x949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_949;
	}
x86_l_944:
	/* 0x944: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_949:
	/* 0x949: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94b:
	/* 0x94b: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_94e:
	/* 0x94e: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_952:
	/* 0x952: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_955:
	/* 0x955: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_958:
	/* 0x958: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_95b:
	/* 0x95b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_960:
	/* 0x960: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_962:
	/* 0x962: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_96a:
	/* 0x96a: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_96d:
	/* 0x96d: jbe    bd0 <generic_kprobe_process_event+0xbd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_bd0;
	}
x86_l_973:
	/* 0x973: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_978:
	/* 0x978: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_980:
	/* 0x980: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_986:
	/* 0x986: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_988:
	/* 0x988: jne    833 <generic_kprobe_process_event+0x833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_833;
	}
x86_l_98e:
	/* 0x98e: jmp    bd0 <generic_kprobe_process_event+0xbd0> */
	goto x86_l_bd0;
x86_l_993:
	/* 0x993: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_998:
	/* 0x998: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_99d:
	/* 0x99d: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9a2:
	/* 0x9a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a7:
	/* 0x9a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a9:
	/* 0x9a9: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9b1:
	/* 0x9b1: cmp    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 88ULL);
x86_l_9b6:
	/* 0x9b6: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_9bc:
	/* 0x9bc: je     bc8 <generic_kprobe_process_event+0xbc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc8;
	}
x86_l_9c2:
	/* 0x9c2: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_9c6:
	/* 0x9c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9cb:
	/* 0x9cb: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9d3:
	/* 0x9d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d8:
	/* 0x9d8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_9db:
	/* 0x9db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9dd:
	/* 0x9dd: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9e2:
	/* 0x9e2: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9ea:
	/* 0x9ea: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_9ee:
	/* 0x9ee: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9f6:
	/* 0x9f6: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_9f8:
	/* 0x9f8: jne    833 <generic_kprobe_process_event+0x833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_833;
	}
x86_l_9fe:
	/* 0x9fe: jmp    bd0 <generic_kprobe_process_event+0xbd0> */
	goto x86_l_bd0;
x86_l_a03:
	/* 0xa03: lea    rsi,[rip+0x24c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 588ULL);
x86_l_a0a:
	/* 0xa0a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0c:
	/* 0xa0c: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a11:
	/* 0xa11: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_a16:
	/* 0xa16: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_a1b:
	/* 0xa1b: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_a20:
	/* 0xa20: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a22:
	/* 0xa22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a24:
	/* 0xa24: jmp    bd0 <generic_kprobe_process_event+0xbd0> */
	goto x86_l_bd0;
x86_l_a29:
	/* 0xa29: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a31:
	/* 0xa31: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a36:
	/* 0xa36: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a3b:
	/* 0xa3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a40:
	/* 0xa40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a45:
	/* 0xa45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a47:
	/* 0xa47: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a4f:
	/* 0xa4f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a54:
	/* 0xa54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a57:
	/* 0xa57: jne    603 <generic_kprobe_process_event+0x603> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1539ULL;
	}
x86_l_a5d:
	/* 0xa5d: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_a68:
	/* 0xa68: mov    rdi,QWORD PTR [rip+0x24c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a6f:
	/* 0xa6f: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_a77:
	/* 0xa77: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a7c:
	/* 0xa7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7e:
	/* 0xa7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a81:
	/* 0xa81: je     f55 <generic_kprobe_process_event+0xf55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3925ULL;
	}
x86_l_a87:
	/* 0xa87: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a8c:
	/* 0xa8c: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a91:
	/* 0xa91: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a94:
	/* 0xa94: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_a98:
	/* 0xa98: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a9d:
	/* 0xa9d: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aa2:
	/* 0xaa2: jg     1024 <generic_kprobe_process_event+0x1024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4132ULL;
	}
x86_l_aa8:
	/* 0xaa8: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_aac:
	/* 0xaac: jle    1194 <generic_kprobe_process_event+0x1194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4500ULL;
	}
x86_l_ab2:
	/* 0xab2: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_ab6:
	/* 0xab6: jle    153b <generic_kprobe_process_event+0x153b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5435ULL;
	}
x86_l_abc:
	/* 0xabc: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_ac0:
	/* 0xac0: je     1db7 <generic_kprobe_process_event+0x1db7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7607ULL;
	}
x86_l_ac6:
	/* 0xac6: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_aca:
	/* 0xaca: je     1d2d <generic_kprobe_process_event+0x1d2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7469ULL;
	}
x86_l_ad0:
	/* 0xad0: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_ad4:
	/* 0xad4: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ad9:
	/* 0xad9: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ade:
	/* 0xade: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae2:
	/* 0xae2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ae7:
	/* 0xae7: jne    d02 <generic_kprobe_process_event+0xd02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d02;
	}
x86_l_aed:
	/* 0xaed: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_af2:
	/* 0xaf2: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_af9:
	/* 0xaf9: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_afb:
	/* 0xafb: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_b01:
	/* 0xb01: jmp    d02 <generic_kprobe_process_event+0xd02> */
	goto x86_l_d02;
x86_l_b06:
	/* 0xb06: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_b0a:
	/* 0xb0a: ja     a5d <generic_kprobe_process_event+0xa5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a5d;
	}
x86_l_b10:
	/* 0xb10: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_b13:
	/* 0xb13: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_b1d:
	/* 0xb1d: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_b21:
	/* 0xb21: jae    a5d <generic_kprobe_process_event+0xa5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a5d;
	}
x86_l_b27:
	/* 0xb27: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b2c:
	/* 0xb2c: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_b37:
	/* 0xb37: mov    rdi,QWORD PTR [rip+0x24c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_b3e:
	/* 0xb3e: lea    rsi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_b46:
	/* 0xb46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b4b:
	/* 0xb4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4d:
	/* 0xb4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b50:
	/* 0xb50: je     ce7 <generic_kprobe_process_event+0xce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ce7;
	}
x86_l_b56:
	/* 0xb56: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b5b:
	/* 0xb5b: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b60:
	/* 0xb60: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b63:
	/* 0xb63: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_b67:
	/* 0xb67: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b6c:
	/* 0xb6c: jle    dea <generic_kprobe_process_event+0xdea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_dea;
	}
x86_l_b72:
	/* 0xb72: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_b76:
	/* 0xb76: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b7b:
	/* 0xb7b: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b80:
	/* 0xb80: jle    f6c <generic_kprobe_process_event+0xf6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3948ULL;
	}
x86_l_b86:
	/* 0xb86: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_b8a:
	/* 0xb8a: jg     1071 <generic_kprobe_process_event+0x1071> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4209ULL;
	}
x86_l_b90:
	/* 0xb90: lea    eax,[r13-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_b94:
	/* 0xb94: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b97:
	/* 0xb97: jae    1633 <generic_kprobe_process_event+0x1633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5683ULL;
	}
x86_l_b9d:
	/* 0xb9d: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ba2:
	/* 0xba2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_ba8:
	/* 0xba8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bad:
	/* 0xbad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bb2:
	/* 0xbb2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb7:
	/* 0xbb7: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_bbc:
	/* 0xbbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbe:
	/* 0xbbe: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bc3:
	/* 0xbc3: jmp    cf9 <generic_kprobe_process_event+0xcf9> */
	goto x86_l_cf9;
x86_l_bc8:
	/* 0xbc8: mov    BYTE PTR [rsp+0xa4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636545ULL);
x86_l_bd0:
	/* 0xbd0: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_bd8:
	/* 0xbd8: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bdd:
	/* 0xbdd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bdf:
	/* 0xbdf: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_be2:
	/* 0xbe2: je     c1d <generic_kprobe_process_event+0xc1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1d;
	}
x86_l_be4:
	/* 0xbe4: cmp    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_bec:
	/* 0xbec: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_bef:
	/* 0xbef: mov    edx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_bf6:
	/* 0xbf6: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_bfc:
	/* 0xbfc: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_bff:
	/* 0xbff: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_c01:
	/* 0xc01: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_c05:
	/* 0xc05: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c08:
	/* 0xc08: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c0d:
	/* 0xc0d: je     cd8 <generic_kprobe_process_event+0xcd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd8;
	}
x86_l_c13:
	/* 0xc13: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_c16:
	/* 0xc16: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c18:
	/* 0xc18: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c1b:
	/* 0xc1b: jmp    c25 <generic_kprobe_process_event+0xc25> */
	goto x86_l_c25;
x86_l_c1d:
	/* 0xc1d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c20:
	/* 0xc20: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c25:
	/* 0xc25: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c2a:
	/* 0xc2a: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2f:
	/* 0xc2f: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c33:
	/* 0xc33: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c3a:
	/* 0xc3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c3f:
	/* 0xc3f: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_c42:
	/* 0xc42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c44:
	/* 0xc44: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c48:
	/* 0xc48: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c4d:
	/* 0xc4d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c52:
	/* 0xc52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c57:
	/* 0xc57: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c5c:
	/* 0xc5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c61:
	/* 0xc61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c63:
	/* 0xc63: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c68:
	/* 0xc68: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_c6c:
	/* 0xc6c: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c74:
	/* 0xc74: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c79:
	/* 0xc79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c7e:
	/* 0xc7e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c83:
	/* 0xc83: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_c87:
	/* 0xc87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c8c:
	/* 0xc8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8e:
	/* 0xc8e: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c96:
	/* 0xc96: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c9b:
	/* 0xc9b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_ca0:
	/* 0xca0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ca5:
	/* 0xca5: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cad:
	/* 0xcad: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_cb2:
	/* 0xcb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb4:
	/* 0xcb4: mov    DWORD PTR [r13+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_cb9:
	/* 0xcb9: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_cbe:
	/* 0xcbe: mov    WORD PTR [r13+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_cc4:
	/* 0xcc4: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_cc8:
	/* 0xcc8: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ccd:
	/* 0xccd: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cd2:
	/* 0xcd2: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd6:
	/* 0xcd6: jmp    d02 <generic_kprobe_process_event+0xd02> */
	goto x86_l_d02;
x86_l_cd8:
	/* 0xcd8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cdb:
	/* 0xcdb: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ce0:
	/* 0xce0: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ce5:
	/* 0xce5: jmp    d07 <generic_kprobe_process_event+0xd07> */
	goto x86_l_d07;
x86_l_ce7:
	/* 0xce7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cea:
	/* 0xcea: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cef:
	/* 0xcef: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cf4:
	/* 0xcf4: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cf9:
	/* 0xcf9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cfd:
	/* 0xcfd: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d02:
	/* 0xd02: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_d05:
	/* 0xd05: js     d17 <generic_kprobe_process_event+0xd17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_d17;
	}
x86_l_d07:
	/* 0xd07: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_d0e:
	/* 0xd0e: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_d12:
	/* 0xd12: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_d15:
	/* 0xd15: jmp    d32 <generic_kprobe_process_event+0xd32> */
	goto x86_l_d32;
x86_l_d17:
	/* 0xd17: mov    DWORD PTR [rcx+rsi*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 104045582745599ULL);
x86_l_d22:
	/* 0xd22: mov    DWORD PTR [rcx+rbp*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 622770257919ULL);
x86_l_d2d:
	/* 0xd2d: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d32:
	/* 0xd32: add    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d34:
	/* 0xd34: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_d36:
	/* 0xd36: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d3a:
	/* 0xd3a: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_d3d:
	/* 0xd3d: jg     dac <generic_kprobe_process_event+0xdac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dac;
	}
x86_l_d3f:
	/* 0xd3f: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d47:
	/* 0xd47: mov    rdi,QWORD PTR [rip+0x254] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_d4e:
	/* 0xd4e: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d53:
	/* 0xd53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d58:
	/* 0xd58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5a:
	/* 0xd5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d5d:
	/* 0xd5d: je     dac <generic_kprobe_process_event+0xdac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dac;
	}
x86_l_d5f:
	/* 0xd5f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d62:
	/* 0xd62: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_d69:
	/* 0xd69: mov    rdi,QWORD PTR [rip+0x24c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_d70:
	/* 0xd70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d75:
	/* 0xd75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d77:
	/* 0xd77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d7a:
	/* 0xd7a: je     dac <generic_kprobe_process_event+0xdac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dac;
	}
x86_l_d7c:
	/* 0xd7c: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d7e:
	/* 0xd7e: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_d80:
	/* 0xd80: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_d83:
	/* 0xd83: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_d88:
	/* 0xd88: je     dac <generic_kprobe_process_event+0xdac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dac;
	}
x86_l_d8a:
	/* 0xd8a: mov    DWORD PTR [r14+0x5efc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_d91:
	/* 0xd91: mov    rsi,QWORD PTR [rip+0x24c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_d98:
	/* 0xd98: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d9d:
	/* 0xd9d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_da2:
	/* 0xda2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_da5:
	/* 0xda5: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_daa:
	/* 0xdaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dac:
	/* 0xdac: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_db7:
	/* 0xdb7: mov    rsi,QWORD PTR [rip+0x24c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_dbe:
	/* 0xdbe: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_dc3:
	/* 0xdc3: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_dc8:
	/* 0xdc8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_dcb:
	/* 0xdcb: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_dd0:
	/* 0xdd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd2:
	/* 0xdd2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dd4:
	/* 0xdd4: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_ddb:
	/* 0xddb: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ddc:
	/* 0xddc: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_dde:
	/* 0xdde: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_de0:
	/* 0xde0: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_de2:
	/* 0xde2: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_de4:
	/* 0xde4: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_de5:
	/* 0xde5: jmp    3bae <__do_bytes+0xc4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_dea:
	/* 0xdea: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
	return 3566ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3580ULL: goto x86_l_dfc;
	case 3586ULL: goto x86_l_e02;
	case 3590ULL: goto x86_l_e06;
	case 3596ULL: goto x86_l_e0c;
	case 3600ULL: goto x86_l_e10;
	case 3606ULL: goto x86_l_e16;
	case 3610ULL: goto x86_l_e1a;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3625ULL: goto x86_l_e29;
	case 3630ULL: goto x86_l_e2e;
	case 3634ULL: goto x86_l_e32;
	case 3640ULL: goto x86_l_e38;
	case 3645ULL: goto x86_l_e3d;
	case 3650ULL: goto x86_l_e42;
	case 3654ULL: goto x86_l_e46;
	case 3658ULL: goto x86_l_e4a;
	case 3662ULL: goto x86_l_e4e;
	case 3667ULL: goto x86_l_e53;
	case 3672ULL: goto x86_l_e58;
	case 3677ULL: goto x86_l_e5d;
	case 3679ULL: goto x86_l_e5f;
	case 3683ULL: goto x86_l_e63;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	case 3697ULL: goto x86_l_e71;
	case 3702ULL: goto x86_l_e76;
	case 3704ULL: goto x86_l_e78;
	case 3708ULL: goto x86_l_e7c;
	case 3715ULL: goto x86_l_e83;
	case 3720ULL: goto x86_l_e88;
	case 3725ULL: goto x86_l_e8d;
	case 3730ULL: goto x86_l_e92;
	case 3732ULL: goto x86_l_e94;
	case 3736ULL: goto x86_l_e98;
	case 3743ULL: goto x86_l_e9f;
	case 3748ULL: goto x86_l_ea4;
	case 3753ULL: goto x86_l_ea9;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3764ULL: goto x86_l_eb4;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3788ULL: goto x86_l_ecc;
	case 3792ULL: goto x86_l_ed0;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3809ULL: goto x86_l_ee1;
	case 3814ULL: goto x86_l_ee6;
	case 3816ULL: goto x86_l_ee8;
	case 3820ULL: goto x86_l_eec;
	case 3828ULL: goto x86_l_ef4;
	case 3836ULL: goto x86_l_efc;
	case 3844ULL: goto x86_l_f04;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3860ULL: goto x86_l_f14;
	case 3866ULL: goto x86_l_f1a;
	case 3869ULL: goto x86_l_f1d;
	case 3875ULL: goto x86_l_f23;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3889ULL: goto x86_l_f31;
	case 3892ULL: goto x86_l_f34;
	case 3897ULL: goto x86_l_f39;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3912ULL: goto x86_l_f48;
	case 3917ULL: goto x86_l_f4d;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3943ULL: goto x86_l_f67;
	case 3948ULL: goto x86_l_f6c;
	case 3952ULL: goto x86_l_f70;
	case 3958ULL: goto x86_l_f76;
	case 3962ULL: goto x86_l_f7a;
	case 3968ULL: goto x86_l_f80;
	case 3972ULL: goto x86_l_f84;
	case 3978ULL: goto x86_l_f8a;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3991ULL: goto x86_l_f97;
	case 3997ULL: goto x86_l_f9d;
	case 4002ULL: goto x86_l_fa2;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4015ULL: goto x86_l_faf;
	case 4019ULL: goto x86_l_fb3;
	case 4022ULL: goto x86_l_fb6;
	case 4028ULL: goto x86_l_fbc;
	case 4032ULL: goto x86_l_fc0;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4063ULL: goto x86_l_fdf;
	case 4066ULL: goto x86_l_fe2;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4096ULL: goto x86_l_1000;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4112ULL: goto x86_l_1010;
	case 4117ULL: goto x86_l_1015;
	case 4122ULL: goto x86_l_101a;
	case 4127ULL: goto x86_l_101f;
	case 4132ULL: goto x86_l_1024;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4152ULL: goto x86_l_1038;
	case 4155ULL: goto x86_l_103b;
	case 4159ULL: goto x86_l_103f;
	case 4162ULL: goto x86_l_1042;
	case 4168ULL: goto x86_l_1048;
	case 4174ULL: goto x86_l_104e;
	case 4179ULL: goto x86_l_1053;
	case 4184ULL: goto x86_l_1058;
	case 4189ULL: goto x86_l_105d;
	case 4194ULL: goto x86_l_1062;
	case 4197ULL: goto x86_l_1065;
	case 4199ULL: goto x86_l_1067;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4213ULL: goto x86_l_1075;
	case 4219ULL: goto x86_l_107b;
	case 4223ULL: goto x86_l_107f;
	case 4229ULL: goto x86_l_1085;
	case 4233ULL: goto x86_l_1089;
	case 4237ULL: goto x86_l_108d;
	case 4243ULL: goto x86_l_1093;
	case 4248ULL: goto x86_l_1098;
	case 4253ULL: goto x86_l_109d;
	case 4258ULL: goto x86_l_10a2;
	case 4266ULL: goto x86_l_10aa;
	case 4274ULL: goto x86_l_10b2;
	case 4282ULL: goto x86_l_10ba;
	case 4290ULL: goto x86_l_10c2;
	case 4298ULL: goto x86_l_10ca;
	case 4306ULL: goto x86_l_10d2;
	case 4314ULL: goto x86_l_10da;
	case 4322ULL: goto x86_l_10e2;
	case 4330ULL: goto x86_l_10ea;
	case 4338ULL: goto x86_l_10f2;
	case 4346ULL: goto x86_l_10fa;
	case 4354ULL: goto x86_l_1102;
	case 4362ULL: goto x86_l_110a;
	case 4369ULL: goto x86_l_1111;
	case 4374ULL: goto x86_l_1116;
	case 4379ULL: goto x86_l_111b;
	case 4384ULL: goto x86_l_1120;
	case 4387ULL: goto x86_l_1123;
	case 4389ULL: goto x86_l_1125;
	case 4392ULL: goto x86_l_1128;
	case 4398ULL: goto x86_l_112e;
	case 4402ULL: goto x86_l_1132;
	case 4407ULL: goto x86_l_1137;
	case 4412ULL: goto x86_l_113c;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4425ULL: goto x86_l_1149;
	case 4427ULL: goto x86_l_114b;
	case 4430ULL: goto x86_l_114e;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4454ULL: goto x86_l_1166;
	case 4460ULL: goto x86_l_116c;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4478ULL: goto x86_l_117e;
	case 4480ULL: goto x86_l_1180;
	case 4482ULL: goto x86_l_1182;
	case 4487ULL: goto x86_l_1187;
	case 4493ULL: goto x86_l_118d;
	case 4495ULL: goto x86_l_118f;
	case 4500ULL: goto x86_l_1194;
	case 4504ULL: goto x86_l_1198;
	case 4510ULL: goto x86_l_119e;
	case 4513ULL: goto x86_l_11a1;
	case 4517ULL: goto x86_l_11a5;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4532ULL: goto x86_l_11b4;
	case 4537ULL: goto x86_l_11b9;
	case 4542ULL: goto x86_l_11be;
	case 4546ULL: goto x86_l_11c2;
	case 4552ULL: goto x86_l_11c8;
	case 4555ULL: goto x86_l_11cb;
	case 4558ULL: goto x86_l_11ce;
	case 4563ULL: goto x86_l_11d3;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4578ULL: goto x86_l_11e2;
	case 4581ULL: goto x86_l_11e5;
	case 4587ULL: goto x86_l_11eb;
	case 4590ULL: goto x86_l_11ee;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4608ULL: goto x86_l_1200;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4641ULL: goto x86_l_1221;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4661ULL: goto x86_l_1235;
	case 4663ULL: goto x86_l_1237;
	case 4668ULL: goto x86_l_123c;
	case 4673ULL: goto x86_l_1241;
	case 4677ULL: goto x86_l_1245;
	case 4679ULL: goto x86_l_1247;
	case 4683ULL: goto x86_l_124b;
	case 4689ULL: goto x86_l_1251;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4715ULL: goto x86_l_126b;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4755ULL: goto x86_l_1293;
	case 4759ULL: goto x86_l_1297;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4774ULL: goto x86_l_12a6;
	case 4779ULL: goto x86_l_12ab;
	case 4783ULL: goto x86_l_12af;
	case 4789ULL: goto x86_l_12b5;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4802ULL: goto x86_l_12c2;
	case 4808ULL: goto x86_l_12c8;
	case 4811ULL: goto x86_l_12cb;
	case 4814ULL: goto x86_l_12ce;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4829ULL: goto x86_l_12dd;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4847ULL: goto x86_l_12ef;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4857ULL: goto x86_l_12f9;
	case 4863ULL: goto x86_l_12ff;
	case 4868ULL: goto x86_l_1304;
	case 4872ULL: goto x86_l_1308;
	case 4876ULL: goto x86_l_130c;
	case 4880ULL: goto x86_l_1310;
	case 4885ULL: goto x86_l_1315;
	case 4890ULL: goto x86_l_131a;
	case 4895ULL: goto x86_l_131f;
	case 4897ULL: goto x86_l_1321;
	case 4901ULL: goto x86_l_1325;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4920ULL: goto x86_l_1338;
	case 4922ULL: goto x86_l_133a;
	case 4926ULL: goto x86_l_133e;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4950ULL: goto x86_l_1356;
	case 4954ULL: goto x86_l_135a;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4971ULL: goto x86_l_136b;
	case 4976ULL: goto x86_l_1370;
	case 4978ULL: goto x86_l_1372;
	case 4982ULL: goto x86_l_1376;
	case 4989ULL: goto x86_l_137d;
	case 4994ULL: goto x86_l_1382;
	case 4999ULL: goto x86_l_1387;
	case 5001ULL: goto x86_l_1389;
	case 5005ULL: goto x86_l_138d;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5022ULL: goto x86_l_139e;
	case 5024ULL: goto x86_l_13a0;
	case 5028ULL: goto x86_l_13a4;
	case 5036ULL: goto x86_l_13ac;
	case 5044ULL: goto x86_l_13b4;
	case 5052ULL: goto x86_l_13bc;
	case 5060ULL: goto x86_l_13c4;
	case 5064ULL: goto x86_l_13c8;
	case 5067ULL: goto x86_l_13cb;
	case 5073ULL: goto x86_l_13d1;
	case 5076ULL: goto x86_l_13d4;
	case 5082ULL: goto x86_l_13da;
	case 5086ULL: goto x86_l_13de;
	case 5091ULL: goto x86_l_13e3;
	case 5096ULL: goto x86_l_13e8;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5108ULL: goto x86_l_13f4;
	case 5113ULL: goto x86_l_13f9;
	case 5118ULL: goto x86_l_13fe;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5138ULL: goto x86_l_1412;
	case 5144ULL: goto x86_l_1418;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5157ULL: goto x86_l_1425;
	case 5163ULL: goto x86_l_142b;
	case 5166ULL: goto x86_l_142e;
	case 5169ULL: goto x86_l_1431;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5185ULL: goto x86_l_1441;
	case 5193ULL: goto x86_l_1449;
	case 5201ULL: goto x86_l_1451;
	case 5209ULL: goto x86_l_1459;
	case 5217ULL: goto x86_l_1461;
	case 5225ULL: goto x86_l_1469;
	case 5233ULL: goto x86_l_1471;
	case 5241ULL: goto x86_l_1479;
	case 5249ULL: goto x86_l_1481;
	case 5256ULL: goto x86_l_1488;
	case 5260ULL: goto x86_l_148c;
	case 5264ULL: goto x86_l_1490;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5279ULL: goto x86_l_149f;
	case 5281ULL: goto x86_l_14a1;
	case 5284ULL: goto x86_l_14a4;
	case 5290ULL: goto x86_l_14aa;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5311ULL: goto x86_l_14bf;
	case 5316ULL: goto x86_l_14c4;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5328ULL: goto x86_l_14d0;
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5342ULL: goto x86_l_14de;
	case 5346ULL: goto x86_l_14e2;
	case 5352ULL: goto x86_l_14e8;
	case 5356ULL: goto x86_l_14ec;
	case 5361ULL: goto x86_l_14f1;
	case 5364ULL: goto x86_l_14f4;
	case 5369ULL: goto x86_l_14f9;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5396ULL: goto x86_l_1514;
	case 5399ULL: goto x86_l_1517;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_dee:
	/* 0xdee: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_df3:
	/* 0xdf3: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df8:
	/* 0xdf8: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfc:
	/* 0xdfc: jg     fa2 <generic_kprobe_process_event+0xfa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_fa2;
	}
x86_l_e02:
	/* 0xe02: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_e06:
	/* 0xe06: jle    1241 <generic_kprobe_process_event+0x1241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1241;
	}
x86_l_e0c:
	/* 0xe0c: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_e10:
	/* 0xe10: je     181d <generic_kprobe_process_event+0x181d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6173ULL;
	}
x86_l_e16:
	/* 0xe16: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_e1a:
	/* 0xe1a: je     1002 <generic_kprobe_process_event+0x1002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1002;
	}
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e25:
	/* 0xe25: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_e29:
	/* 0xe29: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2e:
	/* 0xe2e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e32:
	/* 0xe32: jne    cfd <generic_kprobe_process_event+0xcfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3325ULL;
	}
x86_l_e38:
	/* 0xe38: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e3d:
	/* 0xe3d: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e42:
	/* 0xe42: mov    QWORD PTR [r13+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e46:
	/* 0xe46: lea    rdi,[r13+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_e4a:
	/* 0xe4a: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e4e:
	/* 0xe4e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e53:
	/* 0xe53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e58:
	/* 0xe58: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e5d:
	/* 0xe5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5f:
	/* 0xe5f: lea    rdi,[r13+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_e63:
	/* 0xe63: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_e67:
	/* 0xe67: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e6c:
	/* 0xe6c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e71:
	/* 0xe71: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_e76:
	/* 0xe76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e78:
	/* 0xe78: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e7c:
	/* 0xe7c: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_e83:
	/* 0xe83: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e88:
	/* 0xe88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e8d:
	/* 0xe8d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e92:
	/* 0xe92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e94:
	/* 0xe94: lea    rdi,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e98:
	/* 0xe98: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_e9f:
	/* 0xe9f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ea4:
	/* 0xea4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ea9:
	/* 0xea9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_eae:
	/* 0xeae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb0:
	/* 0xeb0: lea    rdi,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_eb4:
	/* 0xeb4: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_ebb:
	/* 0xebb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ec0:
	/* 0xec0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ec5:
	/* 0xec5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eca:
	/* 0xeca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ecc:
	/* 0xecc: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ed0:
	/* 0xed0: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_ed7:
	/* 0xed7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_edc:
	/* 0xedc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ee1:
	/* 0xee1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ee6:
	/* 0xee6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee8:
	/* 0xee8: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eec:
	/* 0xeec: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef4:
	/* 0xef4: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_efc:
	/* 0xefc: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f04:
	/* 0xf04: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_f0c:
	/* 0xf0c: movzx  eax,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_f11:
	/* 0xf11: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_f14:
	/* 0xf14: je     213a <generic_kprobe_process_event+0x213a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8506ULL;
	}
x86_l_f1a:
	/* 0xf1a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f1d:
	/* 0xf1d: jne    216a <generic_kprobe_process_event+0x216a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8554ULL;
	}
x86_l_f23:
	/* 0xf23: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f27:
	/* 0xf27: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f2c:
	/* 0xf2c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f31:
	/* 0xf31: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_f34:
	/* 0xf34: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f39:
	/* 0xf39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3b:
	/* 0xf3b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f40:
	/* 0xf40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f45:
	/* 0xf45: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f48:
	/* 0xf48: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f4d:
	/* 0xf4d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f50:
	/* 0xf50: jmp    2168 <generic_kprobe_process_event+0x2168> */
	return 8552ULL;
x86_l_f55:
	/* 0xf55: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f58:
	/* 0xf58: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f5d:
	/* 0xf5d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f62:
	/* 0xf62: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f67:
	/* 0xf67: jmp    ccd <generic_kprobe_process_event+0xccd> */
	return 3277ULL;
x86_l_f6c:
	/* 0xf6c: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_f70:
	/* 0xf70: jg     1216 <generic_kprobe_process_event+0x1216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1216;
	}
x86_l_f76:
	/* 0xf76: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_f7a:
	/* 0xf7a: je     166a <generic_kprobe_process_event+0x166a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5738ULL;
	}
x86_l_f80:
	/* 0xf80: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_f84:
	/* 0xf84: je     172e <generic_kprobe_process_event+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5934ULL;
	}
x86_l_f8a:
	/* 0xf8a: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_f8e:
	/* 0xf8e: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f93:
	/* 0xf93: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f97:
	/* 0xf97: je     1251 <generic_kprobe_process_event+0x1251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1251;
	}
x86_l_f9d:
	/* 0xf9d: jmp    cfd <generic_kprobe_process_event+0xcfd> */
	return 3325ULL;
x86_l_fa2:
	/* 0xfa2: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_fa6:
	/* 0xfa6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fa9:
	/* 0xfa9: jb     1251 <generic_kprobe_process_event+0x1251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1251;
	}
x86_l_faf:
	/* 0xfaf: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_fb3:
	/* 0xfb3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fb6:
	/* 0xfb6: jb     1272 <generic_kprobe_process_event+0x1272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1272;
	}
x86_l_fbc:
	/* 0xfbc: cmp    r13d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 14ULL);
x86_l_fc0:
	/* 0xfc0: jne    cfd <generic_kprobe_process_event+0xcfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3325ULL;
	}
x86_l_fc6:
	/* 0xfc6: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fcb:
	/* 0xfcb: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fd0:
	/* 0xfd0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fd5:
	/* 0xfd5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fda:
	/* 0xfda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fdf:
	/* 0xfdf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fe2:
	/* 0xfe2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe4:
	/* 0xfe4: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fe9:
	/* 0xfe9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fee:
	/* 0xfee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ff3:
	/* 0xff3: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ff8:
	/* 0xff8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_ffb:
	/* 0xffb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1000:
	/* 0x1000: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1002:
	/* 0x1002: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1007:
	/* 0x1007: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_100c:
	/* 0x100c: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1010:
	/* 0x1010: mov    ecx,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4097ULL);
x86_l_1015:
	/* 0x1015: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_101a:
	/* 0x101a: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_101f:
	/* 0x101f: jmp    19fe <generic_kprobe_process_event+0x19fe> */
	return 6654ULL;
x86_l_1024:
	/* 0x1024: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1028:
	/* 0x1028: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_102d:
	/* 0x102d: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1032:
	/* 0x1032: jle    140e <generic_kprobe_process_event+0x140e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_140e;
	}
x86_l_1038:
	/* 0x1038: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_103b:
	/* 0x103b: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_103f:
	/* 0x103f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1042:
	/* 0x1042: jae    12a6 <generic_kprobe_process_event+0x12a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_12a6;
	}
x86_l_1048:
	/* 0x1048: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_104e:
	/* 0x104e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1053:
	/* 0x1053: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1058:
	/* 0x1058: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_105d:
	/* 0x105d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1062:
	/* 0x1062: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1065:
	/* 0x1065: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1067:
	/* 0x1067: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_106c:
	/* 0x106c: jmp    cd2 <generic_kprobe_process_event+0xcd2> */
	return 3282ULL;
x86_l_1071:
	/* 0x1071: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_1075:
	/* 0x1075: je     19dc <generic_kprobe_process_event+0x19dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6620ULL;
	}
x86_l_107b:
	/* 0x107b: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_107f:
	/* 0x107f: je     1a20 <generic_kprobe_process_event+0x1a20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6688ULL;
	}
x86_l_1085:
	/* 0x1085: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_1089:
	/* 0x1089: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_108d:
	/* 0x108d: jne    cfd <generic_kprobe_process_event+0xcfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3325ULL;
	}
x86_l_1093:
	/* 0x1093: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1098:
	/* 0x1098: mov    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_109d:
	/* 0x109d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10a2:
	/* 0x10a2: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_10aa:
	/* 0x10aa: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_10b2:
	/* 0x10b2: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_10ba:
	/* 0x10ba: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_10c2:
	/* 0x10c2: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_10ca:
	/* 0x10ca: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_10d2:
	/* 0x10d2: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_10da:
	/* 0x10da: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_10e2:
	/* 0x10e2: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_10ea:
	/* 0x10ea: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_10f2:
	/* 0x10f2: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10fa:
	/* 0x10fa: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1102:
	/* 0x1102: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_110a:
	/* 0x110a: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1111:
	/* 0x1111: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1116:
	/* 0x1116: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_111b:
	/* 0x111b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1120:
	/* 0x1120: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1123:
	/* 0x1123: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1125:
	/* 0x1125: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1128:
	/* 0x1128: js     2450 <generic_kprobe_process_event+0x2450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9296ULL;
	}
x86_l_112e:
	/* 0x112e: lea    r12,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1132:
	/* 0x1132: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1137:
	/* 0x1137: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_113c:
	/* 0x113c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1141:
	/* 0x1141: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1146:
	/* 0x1146: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1149:
	/* 0x1149: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114b:
	/* 0x114b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_114e:
	/* 0x114e: js     2450 <generic_kprobe_process_event+0x2450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9296ULL;
	}
x86_l_1154:
	/* 0x1154: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1159:
	/* 0x1159: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_115d:
	/* 0x115d: cmp    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1162:
	/* 0x1162: sete   BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_1166:
	/* 0x1166: je     2422 <generic_kprobe_process_event+0x2422> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9250ULL;
	}
x86_l_116c:
	/* 0x116c: mov    ecx,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 108ULL);
x86_l_1171:
	/* 0x1171: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1176:
	/* 0x1176: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_117b:
	/* 0x117b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_117e:
	/* 0x117e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1180:
	/* 0x1180: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1182:
	/* 0x1182: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1187:
	/* 0x1187: js     2450 <generic_kprobe_process_event+0x2450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9296ULL;
	}
x86_l_118d:
	/* 0x118d: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_118f:
	/* 0x118f: jmp    2448 <generic_kprobe_process_event+0x2448> */
	return 9288ULL;
x86_l_1194:
	/* 0x1194: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_1198:
	/* 0x1198: jg     14db <generic_kprobe_process_event+0x14db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_14db;
	}
x86_l_119e:
	/* 0x119e: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_11a1:
	/* 0x11a1: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_11a5:
	/* 0x11a5: je     1ab7 <generic_kprobe_process_event+0x1ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6839ULL;
	}
x86_l_11ab:
	/* 0x11ab: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11b0:
	/* 0x11b0: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_11b4:
	/* 0x11b4: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b9:
	/* 0x11b9: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11be:
	/* 0x11be: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c2:
	/* 0x11c2: jne    d02 <generic_kprobe_process_event+0xd02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3330ULL;
	}
x86_l_11c8:
	/* 0x11c8: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_11cb:
	/* 0x11cb: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_11ce:
	/* 0x11ce: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11d3:
	/* 0x11d3: lea    r13,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_11da:
	/* 0x11da: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11df:
	/* 0x11df: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_11e2:
	/* 0x11e2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11e5:
	/* 0x11e5: jle    22c1 <generic_kprobe_process_event+0x22c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8897ULL;
	}
x86_l_11eb:
	/* 0x11eb: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_11ee:
	/* 0x11ee: je     254b <generic_kprobe_process_event+0x254b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9547ULL;
	}
x86_l_11f4:
	/* 0x11f4: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11f7:
	/* 0x11f7: je     2558 <generic_kprobe_process_event+0x2558> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9560ULL;
	}
x86_l_11fd:
	/* 0x11fd: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1200:
	/* 0x1200: jne    29cc <generic_kprobe_process_event+0x29cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10700ULL;
	}
x86_l_1206:
	/* 0x1206: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_120b:
	/* 0x120b: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_1211:
	/* 0x1211: jmp    2570 <generic_kprobe_process_event+0x2570> */
	return 9584ULL;
x86_l_1216:
	/* 0x1216: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_121b:
	/* 0x121b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1221:
	/* 0x1221: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1226:
	/* 0x1226: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_122b:
	/* 0x122b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1230:
	/* 0x1230: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1235:
	/* 0x1235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1237:
	/* 0x1237: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_123c:
	/* 0x123c: jmp    cf9 <generic_kprobe_process_event+0xcf9> */
	return 3321ULL;
x86_l_1241:
	/* 0x1241: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1245:
	/* 0x1245: je     1272 <generic_kprobe_process_event+0x1272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1272;
	}
x86_l_1247:
	/* 0x1247: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_124b:
	/* 0x124b: jne    cfd <generic_kprobe_process_event+0xcfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3325ULL;
	}
x86_l_1251:
	/* 0x1251: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1257:
	/* 0x1257: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_125c:
	/* 0x125c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1261:
	/* 0x1261: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1266:
	/* 0x1266: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_126b:
	/* 0x126b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1270:
	/* 0x1270: jmp    1291 <generic_kprobe_process_event+0x1291> */
	goto x86_l_1291;
x86_l_1272:
	/* 0x1272: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1277:
	/* 0x1277: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_127d:
	/* 0x127d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1282:
	/* 0x1282: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1287:
	/* 0x1287: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_128c:
	/* 0x128c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1291:
	/* 0x1291: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1293:
	/* 0x1293: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1297:
	/* 0x1297: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_129c:
	/* 0x129c: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12a1:
	/* 0x12a1: jmp    d02 <generic_kprobe_process_event+0xd02> */
	return 3330ULL;
x86_l_12a6:
	/* 0x12a6: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12ab:
	/* 0x12ab: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_12af:
	/* 0x12af: je     1eb9 <generic_kprobe_process_event+0x1eb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7865ULL;
	}
x86_l_12b5:
	/* 0x12b5: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_12b9:
	/* 0x12b9: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12be:
	/* 0x12be: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c2:
	/* 0x12c2: jne    d02 <generic_kprobe_process_event+0xd02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3330ULL;
	}
x86_l_12c8:
	/* 0x12c8: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_12cb:
	/* 0x12cb: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_12ce:
	/* 0x12ce: add    r8,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_12d2:
	/* 0x12d2: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12d7:
	/* 0x12d7: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_12dd:
	/* 0x12dd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12e2:
	/* 0x12e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12e7:
	/* 0x12e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ec:
	/* 0x12ec: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_12ef:
	/* 0x12ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f1:
	/* 0x12f1: mov    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12f6:
	/* 0x12f6: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_12f9:
	/* 0x12f9: je     24fc <generic_kprobe_process_event+0x24fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9468ULL;
	}
x86_l_12ff:
	/* 0x12ff: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1304:
	/* 0x1304: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1308:
	/* 0x1308: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_130c:
	/* 0x130c: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1310:
	/* 0x1310: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1315:
	/* 0x1315: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_131a:
	/* 0x131a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_131f:
	/* 0x131f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1321:
	/* 0x1321: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1325:
	/* 0x1325: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1329:
	/* 0x1329: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_132e:
	/* 0x132e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1333:
	/* 0x1333: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1338:
	/* 0x1338: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133a:
	/* 0x133a: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_133e:
	/* 0x133e: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1345:
	/* 0x1345: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_134a:
	/* 0x134a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_134f:
	/* 0x134f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1354:
	/* 0x1354: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1356:
	/* 0x1356: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_135a:
	/* 0x135a: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1361:
	/* 0x1361: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1366:
	/* 0x1366: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_136b:
	/* 0x136b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1370:
	/* 0x1370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1372:
	/* 0x1372: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1376:
	/* 0x1376: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_137d:
	/* 0x137d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1382:
	/* 0x1382: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1387:
	/* 0x1387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1389:
	/* 0x1389: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_138d:
	/* 0x138d: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1394:
	/* 0x1394: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1399:
	/* 0x1399: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_139e:
	/* 0x139e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a0:
	/* 0x13a0: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a4:
	/* 0x13a4: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ac:
	/* 0x13ac: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13b4:
	/* 0x13b4: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13bc:
	/* 0x13bc: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_13c4:
	/* 0x13c4: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_13c8:
	/* 0x13c8: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_13cb:
	/* 0x13cb: je     2483 <generic_kprobe_process_event+0x2483> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9347ULL;
	}
x86_l_13d1:
	/* 0x13d1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13d4:
	/* 0x13d4: jne    24b5 <generic_kprobe_process_event+0x24b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9397ULL;
	}
x86_l_13da:
	/* 0x13da: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13de:
	/* 0x13de: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13e3:
	/* 0x13e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13e8:
	/* 0x13e8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ed:
	/* 0x13ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13f2:
	/* 0x13f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f4:
	/* 0x13f4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13f9:
	/* 0x13f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13fe:
	/* 0x13fe: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1401:
	/* 0x1401: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1406:
	/* 0x1406: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1409:
	/* 0x1409: jmp    24b3 <generic_kprobe_process_event+0x24b3> */
	return 9395ULL;
x86_l_140e:
	/* 0x140e: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_1412:
	/* 0x1412: je     1f56 <generic_kprobe_process_event+0x1f56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8022ULL;
	}
x86_l_1418:
	/* 0x1418: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_141c:
	/* 0x141c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1421:
	/* 0x1421: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1425:
	/* 0x1425: jne    d02 <generic_kprobe_process_event+0xd02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3330ULL;
	}
x86_l_142b:
	/* 0x142b: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_142e:
	/* 0x142e: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_1431:
	/* 0x1431: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1434:
	/* 0x1434: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1439:
	/* 0x1439: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1441:
	/* 0x1441: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1449:
	/* 0x1449: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1451:
	/* 0x1451: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1459:
	/* 0x1459: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1461:
	/* 0x1461: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1469:
	/* 0x1469: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1471:
	/* 0x1471: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1479:
	/* 0x1479: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1481:
	/* 0x1481: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1488:
	/* 0x1488: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_148c:
	/* 0x148c: lea    rdx,[r8+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1490:
	/* 0x1490: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_1495:
	/* 0x1495: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_149a:
	/* 0x149a: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_149f:
	/* 0x149f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a1:
	/* 0x14a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a4:
	/* 0x14a4: js     2411 <generic_kprobe_process_event+0x2411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9233ULL;
	}
x86_l_14aa:
	/* 0x14aa: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14af:
	/* 0x14af: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14b3:
	/* 0x14b3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14b8:
	/* 0x14b8: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_14bf:
	/* 0x14bf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14c4:
	/* 0x14c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c9:
	/* 0x14c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14ce:
	/* 0x14ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d0:
	/* 0x14d0: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_14d6:
	/* 0x14d6: jmp    2414 <generic_kprobe_process_event+0x2414> */
	return 9236ULL;
x86_l_14db:
	/* 0x14db: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_14de:
	/* 0x14de: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_14e2:
	/* 0x14e2: je     1b21 <generic_kprobe_process_event+0x1b21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6945ULL;
	}
x86_l_14e8:
	/* 0x14e8: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_14ec:
	/* 0x14ec: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14f1:
	/* 0x14f1: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_14f4:
	/* 0x14f4: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14f9:
	/* 0x14f9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14fd:
	/* 0x14fd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1502:
	/* 0x1502: jne    d02 <generic_kprobe_process_event+0xd02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3330ULL;
	}
x86_l_1508:
	/* 0x1508: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_150d:
	/* 0x150d: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1514:
	/* 0x1514: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1517:
	/* 0x1517: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_151a:
	/* 0x151a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_151f:
	/* 0x151f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 5412ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5412ULL: goto x86_l_1524;
	case 5415ULL: goto x86_l_1527;
	case 5417ULL: goto x86_l_1529;
	case 5421ULL: goto x86_l_152d;
	case 5424ULL: goto x86_l_1530;
	case 5427ULL: goto x86_l_1533;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5439ULL: goto x86_l_153f;
	case 5445ULL: goto x86_l_1545;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5459ULL: goto x86_l_1553;
	case 5463ULL: goto x86_l_1557;
	case 5468ULL: goto x86_l_155c;
	case 5474ULL: goto x86_l_1562;
	case 5483ULL: goto x86_l_156b;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5523ULL: goto x86_l_1593;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5545ULL: goto x86_l_15a9;
	case 5550ULL: goto x86_l_15ae;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5560ULL: goto x86_l_15b8;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5587ULL: goto x86_l_15d3;
	case 5594ULL: goto x86_l_15da;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5611ULL: goto x86_l_15eb;
	case 5616ULL: goto x86_l_15f0;
	case 5618ULL: goto x86_l_15f2;
	case 5625ULL: goto x86_l_15f9;
	case 5632ULL: goto x86_l_1600;
	case 5637ULL: goto x86_l_1605;
	case 5642ULL: goto x86_l_160a;
	case 5645ULL: goto x86_l_160d;
	case 5650ULL: goto x86_l_1612;
	case 5653ULL: goto x86_l_1615;
	case 5655ULL: goto x86_l_1617;
	case 5659ULL: goto x86_l_161b;
	case 5662ULL: goto x86_l_161e;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5687ULL: goto x86_l_1637;
	case 5691ULL: goto x86_l_163b;
	case 5697ULL: goto x86_l_1641;
	case 5702ULL: goto x86_l_1646;
	case 5705ULL: goto x86_l_1649;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5738ULL: goto x86_l_166a;
	case 5747ULL: goto x86_l_1673;
	case 5752ULL: goto x86_l_1678;
	case 5754ULL: goto x86_l_167a;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5786ULL: goto x86_l_169a;
	case 5792ULL: goto x86_l_16a0;
	case 5797ULL: goto x86_l_16a5;
	case 5799ULL: goto x86_l_16a7;
	case 5806ULL: goto x86_l_16ae;
	case 5810ULL: goto x86_l_16b2;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5827ULL: goto x86_l_16c3;
	case 5829ULL: goto x86_l_16c5;
	case 5832ULL: goto x86_l_16c8;
	case 5838ULL: goto x86_l_16ce;
	case 5841ULL: goto x86_l_16d1;
	case 5849ULL: goto x86_l_16d9;
	case 5852ULL: goto x86_l_16dc;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5872ULL: goto x86_l_16f0;
	case 5879ULL: goto x86_l_16f7;
	case 5883ULL: goto x86_l_16fb;
	case 5887ULL: goto x86_l_16ff;
	case 5892ULL: goto x86_l_1704;
	case 5895ULL: goto x86_l_1707;
	case 5897ULL: goto x86_l_1709;
	case 5901ULL: goto x86_l_170d;
	case 5905ULL: goto x86_l_1711;
	case 5909ULL: goto x86_l_1715;
	case 5913ULL: goto x86_l_1719;
	case 5918ULL: goto x86_l_171e;
	case 5923ULL: goto x86_l_1723;
	case 5925ULL: goto x86_l_1725;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5965ULL: goto x86_l_174d;
	case 5968ULL: goto x86_l_1750;
	case 5970ULL: goto x86_l_1752;
	case 5978ULL: goto x86_l_175a;
	case 5980ULL: goto x86_l_175c;
	case 5986ULL: goto x86_l_1762;
	case 5989ULL: goto x86_l_1765;
	case 5995ULL: goto x86_l_176b;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6010ULL: goto x86_l_177a;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6043ULL: goto x86_l_179b;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6069ULL: goto x86_l_17b5;
	case 6074ULL: goto x86_l_17ba;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6091ULL: goto x86_l_17cb;
	case 6099ULL: goto x86_l_17d3;
	case 6104ULL: goto x86_l_17d8;
	case 6109ULL: goto x86_l_17dd;
	case 6113ULL: goto x86_l_17e1;
	case 6120ULL: goto x86_l_17e8;
	case 6125ULL: goto x86_l_17ed;
	case 6131ULL: goto x86_l_17f3;
	case 6138ULL: goto x86_l_17fa;
	case 6144ULL: goto x86_l_1800;
	case 6150ULL: goto x86_l_1806;
	case 6154ULL: goto x86_l_180a;
	case 6159ULL: goto x86_l_180f;
	case 6162ULL: goto x86_l_1812;
	case 6165ULL: goto x86_l_1815;
	case 6168ULL: goto x86_l_1818;
	case 6173ULL: goto x86_l_181d;
	case 6178ULL: goto x86_l_1822;
	case 6183ULL: goto x86_l_1827;
	case 6187ULL: goto x86_l_182b;
	case 6195ULL: goto x86_l_1833;
	case 6200ULL: goto x86_l_1838;
	case 6205ULL: goto x86_l_183d;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6236ULL: goto x86_l_185c;
	case 6238ULL: goto x86_l_185e;
	case 6242ULL: goto x86_l_1862;
	case 6250ULL: goto x86_l_186a;
	case 6255ULL: goto x86_l_186f;
	case 6260ULL: goto x86_l_1874;
	case 6265ULL: goto x86_l_1879;
	case 6267ULL: goto x86_l_187b;
	case 6271ULL: goto x86_l_187f;
	case 6279ULL: goto x86_l_1887;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6294ULL: goto x86_l_1896;
	case 6296ULL: goto x86_l_1898;
	case 6305ULL: goto x86_l_18a1;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6335ULL: goto x86_l_18bf;
	case 6343ULL: goto x86_l_18c7;
	case 6351ULL: goto x86_l_18cf;
	case 6356ULL: goto x86_l_18d4;
	case 6361ULL: goto x86_l_18d9;
	case 6366ULL: goto x86_l_18de;
	case 6368ULL: goto x86_l_18e0;
	case 6377ULL: goto x86_l_18e9;
	case 6382ULL: goto x86_l_18ee;
	case 6390ULL: goto x86_l_18f6;
	case 6395ULL: goto x86_l_18fb;
	case 6400ULL: goto x86_l_1900;
	case 6405ULL: goto x86_l_1905;
	case 6408ULL: goto x86_l_1908;
	case 6410ULL: goto x86_l_190a;
	case 6418ULL: goto x86_l_1912;
	case 6421ULL: goto x86_l_1915;
	case 6424ULL: goto x86_l_1918;
	case 6430ULL: goto x86_l_191e;
	case 6433ULL: goto x86_l_1921;
	case 6439ULL: goto x86_l_1927;
	case 6443ULL: goto x86_l_192b;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6485ULL: goto x86_l_1955;
	case 6491ULL: goto x86_l_195b;
	case 6495ULL: goto x86_l_195f;
	case 6502ULL: goto x86_l_1966;
	case 6510ULL: goto x86_l_196e;
	case 6518ULL: goto x86_l_1976;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6572ULL: goto x86_l_19ac;
	case 6574ULL: goto x86_l_19ae;
	case 6582ULL: goto x86_l_19b6;
	case 6590ULL: goto x86_l_19be;
	case 6595ULL: goto x86_l_19c3;
	case 6600ULL: goto x86_l_19c8;
	case 6605ULL: goto x86_l_19cd;
	case 6607ULL: goto x86_l_19cf;
	case 6615ULL: goto x86_l_19d7;
	case 6620ULL: goto x86_l_19dc;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6662ULL: goto x86_l_1a06;
	case 6668ULL: goto x86_l_1a0c;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6706ULL: goto x86_l_1a32;
	case 6714ULL: goto x86_l_1a3a;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6732ULL: goto x86_l_1a4c;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6743ULL: goto x86_l_1a57;
	case 6745ULL: goto x86_l_1a59;
	case 6748ULL: goto x86_l_1a5c;
	case 6754ULL: goto x86_l_1a62;
	case 6759ULL: goto x86_l_1a67;
	case 6762ULL: goto x86_l_1a6a;
	case 6768ULL: goto x86_l_1a70;
	case 6771ULL: goto x86_l_1a73;
	case 6777ULL: goto x86_l_1a79;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6801ULL: goto x86_l_1a91;
	case 6803ULL: goto x86_l_1a93;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6816ULL: goto x86_l_1aa0;
	case 6820ULL: goto x86_l_1aa4;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6847ULL: goto x86_l_1abf;
	case 6851ULL: goto x86_l_1ac3;
	case 6858ULL: goto x86_l_1aca;
	case 6870ULL: goto x86_l_1ad6;
	case 6875ULL: goto x86_l_1adb;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6889ULL: goto x86_l_1ae9;
	case 6892ULL: goto x86_l_1aec;
	case 6894ULL: goto x86_l_1aee;
	case 6897ULL: goto x86_l_1af1;
	case 6900ULL: goto x86_l_1af4;
	case 6906ULL: goto x86_l_1afa;
	case 6909ULL: goto x86_l_1afd;
	case 6915ULL: goto x86_l_1b03;
	case 6918ULL: goto x86_l_1b06;
	case 6924ULL: goto x86_l_1b0c;
	case 6927ULL: goto x86_l_1b0f;
	case 6933ULL: goto x86_l_1b15;
	case 6940ULL: goto x86_l_1b1c;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6954ULL: goto x86_l_1b2a;
	case 6958ULL: goto x86_l_1b2e;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7007ULL: goto x86_l_1b5f;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7045ULL: goto x86_l_1b85;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7071ULL: goto x86_l_1b9f;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7097ULL: goto x86_l_1bb9;
	case 7101ULL: goto x86_l_1bbd;
	case 7106ULL: goto x86_l_1bc2;
	case 7111ULL: goto x86_l_1bc7;
	case 7116ULL: goto x86_l_1bcc;
	case 7121ULL: goto x86_l_1bd1;
	case 7123ULL: goto x86_l_1bd3;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7137ULL: goto x86_l_1be1;
	case 7142ULL: goto x86_l_1be6;
	case 7147ULL: goto x86_l_1beb;
	case 7149ULL: goto x86_l_1bed;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7175ULL: goto x86_l_1c07;
	case 7183ULL: goto x86_l_1c0f;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7207ULL: goto x86_l_1c27;
	case 7209ULL: goto x86_l_1c29;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1524:
	/* 0x1524: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1527:
	/* 0x1527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1529:
	/* 0x1529: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_152d:
	/* 0x152d: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1530:
	/* 0x1530: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1533:
	/* 0x1533: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_1536:
	/* 0x1536: jmp    d02 <generic_kprobe_process_event+0xd02> */
	return 3330ULL;
x86_l_153b:
	/* 0x153b: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_153f:
	/* 0x153f: je     1e4b <generic_kprobe_process_event+0x1e4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7755ULL;
	}
x86_l_1545:
	/* 0x1545: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_1549:
	/* 0x1549: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_154e:
	/* 0x154e: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1553:
	/* 0x1553: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1557:
	/* 0x1557: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_155c:
	/* 0x155c: jne    d02 <generic_kprobe_process_event+0xd02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3330ULL;
	}
x86_l_1562:
	/* 0x1562: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_156b:
	/* 0x156b: lea    rdx,[r8+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1572:
	/* 0x1572: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1577:
	/* 0x1577: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_157c:
	/* 0x157c: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_157f:
	/* 0x157f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1584:
	/* 0x1584: lea    r15,[r8+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_158b:
	/* 0x158b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1590:
	/* 0x1590: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_1593:
	/* 0x1593: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1595:
	/* 0x1595: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_159a:
	/* 0x159a: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_159f:
	/* 0x159f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15a4:
	/* 0x15a4: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a9:
	/* 0x15a9: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15ae:
	/* 0x15ae: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_15b1:
	/* 0x15b1: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_15b6:
	/* 0x15b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b8:
	/* 0x15b8: lea    rdi,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_15bf:
	/* 0x15bf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15c4:
	/* 0x15c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15c9:
	/* 0x15c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15ce:
	/* 0x15ce: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15d1:
	/* 0x15d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d3:
	/* 0x15d3: lea    rdi,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_15da:
	/* 0x15da: lea    rdx,[rbx+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_15e1:
	/* 0x15e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15e6:
	/* 0x15e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15eb:
	/* 0x15eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15f0:
	/* 0x15f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f2:
	/* 0x15f2: add    r13,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_15f9:
	/* 0x15f9: add    rbx,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_1600:
	/* 0x1600: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1605:
	/* 0x1605: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_160a:
	/* 0x160a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_160d:
	/* 0x160d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1612:
	/* 0x1612: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1615:
	/* 0x1615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1617:
	/* 0x1617: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_161b:
	/* 0x161b: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_161e:
	/* 0x161e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1623:
	/* 0x1623: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1628:
	/* 0x1628: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_162e:
	/* 0x162e: jmp    d02 <generic_kprobe_process_event+0xd02> */
	return 3330ULL;
x86_l_1633:
	/* 0x1633: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_1637:
	/* 0x1637: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163b:
	/* 0x163b: jne    cfd <generic_kprobe_process_event+0xcfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3325ULL;
	}
x86_l_1641:
	/* 0x1641: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1646:
	/* 0x1646: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1649:
	/* 0x1649: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_164c:
	/* 0x164c: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_164f:
	/* 0x164f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1655:
	/* 0x1655: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165a:
	/* 0x165a: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_165e:
	/* 0x165e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1660:
	/* 0x1660: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1665:
	/* 0x1665: jmp    19fe <generic_kprobe_process_event+0x19fe> */
	goto x86_l_19fe;
x86_l_166a:
	/* 0x166a: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1673:
	/* 0x1673: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1678:
	/* 0x1678: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_167a:
	/* 0x167a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_167e:
	/* 0x167e: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1683:
	/* 0x1683: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_168b:
	/* 0x168b: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1690:
	/* 0x1690: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1695:
	/* 0x1695: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_169a:
	/* 0x169a: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_16a0:
	/* 0x16a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16a5:
	/* 0x16a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a7:
	/* 0x16a7: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16ae:
	/* 0x16ae: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16b2:
	/* 0x16b2: mov    rdi,QWORD PTR [rip+0x248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_16b9:
	/* 0x16b9: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16be:
	/* 0x16be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16c3:
	/* 0x16c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c5:
	/* 0x16c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16c8:
	/* 0x16c8: je     1fd4 <generic_kprobe_process_event+0x1fd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8148ULL;
	}
x86_l_16ce:
	/* 0x16ce: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d1:
	/* 0x16d1: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16d9:
	/* 0x16d9: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_16dc:
	/* 0x16dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16e1:
	/* 0x16e1: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e6:
	/* 0x16e6: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_16e9:
	/* 0x16e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16ee:
	/* 0x16ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f0:
	/* 0x16f0: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16f7:
	/* 0x16f7: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16fb:
	/* 0x16fb: lea    rsi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16ff:
	/* 0x16ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1704:
	/* 0x1704: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1707:
	/* 0x1707: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1709:
	/* 0x1709: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_170d:
	/* 0x170d: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1711:
	/* 0x1711: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1715:
	/* 0x1715: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1719:
	/* 0x1719: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_171e:
	/* 0x171e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1723:
	/* 0x1723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1725:
	/* 0x1725: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1729:
	/* 0x1729: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_172e:
	/* 0x172e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1731:
	/* 0x1731: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1736:
	/* 0x1736: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_173e:
	/* 0x173e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1743:
	/* 0x1743: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1748:
	/* 0x1748: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_174d:
	/* 0x174d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1750:
	/* 0x1750: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1752:
	/* 0x1752: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_175a:
	/* 0x175a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_175c:
	/* 0x175c: je     1fe0 <generic_kprobe_process_event+0x1fe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8160ULL;
	}
x86_l_1762:
	/* 0x1762: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1765:
	/* 0x1765: jne    21f7 <generic_kprobe_process_event+0x21f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8695ULL;
	}
x86_l_176b:
	/* 0x176b: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_176f:
	/* 0x176f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1774:
	/* 0x1774: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_177a:
	/* 0x177a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_177f:
	/* 0x177f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1784:
	/* 0x1784: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1789:
	/* 0x1789: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_178c:
	/* 0x178c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178e:
	/* 0x178e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1793:
	/* 0x1793: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_179b:
	/* 0x179b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17a0:
	/* 0x17a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17a5:
	/* 0x17a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17aa:
	/* 0x17aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ac:
	/* 0x17ac: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17b1:
	/* 0x17b1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17b5:
	/* 0x17b5: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17ba:
	/* 0x17ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17bf:
	/* 0x17bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c4:
	/* 0x17c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c9:
	/* 0x17c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17cb:
	/* 0x17cb: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17d3:
	/* 0x17d3: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17d8:
	/* 0x17d8: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17dd:
	/* 0x17dd: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_17e1:
	/* 0x17e1: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_17e8:
	/* 0x17e8: test   BYTE PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_17ed:
	/* 0x17ed: je     2ad6 <generic_kprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10966ULL;
	}
x86_l_17f3:
	/* 0x17f3: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_17fa:
	/* 0x17fa: jb     2ab2 <generic_kprobe_process_event+0x2ab2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10930ULL;
	}
x86_l_1800:
	/* 0x1800: mov    DWORD PTR [rbx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1806:
	/* 0x1806: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_180a:
	/* 0x180a: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_180f:
	/* 0x180f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1812:
	/* 0x1812: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1815:
	/* 0x1815: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1818:
	/* 0x1818: jmp    2074 <generic_kprobe_process_event+0x2074> */
	return 8308ULL;
x86_l_181d:
	/* 0x181d: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1822:
	/* 0x1822: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1827:
	/* 0x1827: lea    rdi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_182b:
	/* 0x182b: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1833:
	/* 0x1833: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1838:
	/* 0x1838: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_183d:
	/* 0x183d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1842:
	/* 0x1842: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1844:
	/* 0x1844: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1848:
	/* 0x1848: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_184d:
	/* 0x184d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1852:
	/* 0x1852: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1857:
	/* 0x1857: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_185c:
	/* 0x185c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185e:
	/* 0x185e: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1862:
	/* 0x1862: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_186a:
	/* 0x186a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_186f:
	/* 0x186f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1874:
	/* 0x1874: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1879:
	/* 0x1879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187b:
	/* 0x187b: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_187f:
	/* 0x187f: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1887:
	/* 0x1887: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_188c:
	/* 0x188c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1891:
	/* 0x1891: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1896:
	/* 0x1896: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1898:
	/* 0x1898: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_18a1:
	/* 0x18a1: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18a9:
	/* 0x18a9: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_18ae:
	/* 0x18ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18b3:
	/* 0x18b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b8:
	/* 0x18b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18bd:
	/* 0x18bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18bf:
	/* 0x18bf: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_18c7:
	/* 0x18c7: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18cf:
	/* 0x18cf: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_18d4:
	/* 0x18d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d9:
	/* 0x18d9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_18de:
	/* 0x18de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e0:
	/* 0x18e0: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_18e9:
	/* 0x18e9: add    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_18ee:
	/* 0x18ee: lea    rdi,[rsp+0xbb] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 187ULL);
x86_l_18f6:
	/* 0x18f6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18fb:
	/* 0x18fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1900:
	/* 0x1900: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1905:
	/* 0x1905: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1908:
	/* 0x1908: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190a:
	/* 0x190a: movzx  eax,BYTE PTR [rsp+0xbb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 187ULL);
x86_l_1912:
	/* 0x1912: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1915:
	/* 0x1915: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1918:
	/* 0x1918: je     208a <generic_kprobe_process_event+0x208a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8330ULL;
	}
x86_l_191e:
	/* 0x191e: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1921:
	/* 0x1921: jne    3457 <generic_kprobe_process_event+0x3457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13399ULL;
	}
x86_l_1927:
	/* 0x1927: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_192b:
	/* 0x192b: lea    rdi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1933:
	/* 0x1933: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1938:
	/* 0x1938: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_193d:
	/* 0x193d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1942:
	/* 0x1942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1944:
	/* 0x1944: movzx  eax,BYTE PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 188ULL);
x86_l_194c:
	/* 0x194c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1951:
	/* 0x1951: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1955:
	/* 0x1955: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_195b:
	/* 0x195b: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_195f:
	/* 0x195f: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1966:
	/* 0x1966: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_196e:
	/* 0x196e: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1976:
	/* 0x1976: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_197e:
	/* 0x197e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1983:
	/* 0x1983: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1988:
	/* 0x1988: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_198c:
	/* 0x198c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1991:
	/* 0x1991: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1993:
	/* 0x1993: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1997:
	/* 0x1997: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_199c:
	/* 0x199c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a1:
	/* 0x19a1: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_19a4:
	/* 0x19a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19a9:
	/* 0x19a9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19ac:
	/* 0x19ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ae:
	/* 0x19ae: lea    rdx,[r12+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_19b6:
	/* 0x19b6: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_19be:
	/* 0x19be: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19c3:
	/* 0x19c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c8:
	/* 0x19c8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_19cd:
	/* 0x19cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19cf:
	/* 0x19cf: movzx  ebp,BYTE PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 188ULL);
x86_l_19d7:
	/* 0x19d7: jmp    32e9 <generic_kprobe_process_event+0x32e9> */
	return 13033ULL;
x86_l_19dc:
	/* 0x19dc: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_19e1:
	/* 0x19e1: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_19e6:
	/* 0x19e6: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19eb:
	/* 0x19eb: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19ef:
	/* 0x19ef: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_19f4:
	/* 0x19f4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19f9:
	/* 0x19f9: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_19fe:
	/* 0x19fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a00:
	/* 0x1a00: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1a03:
	/* 0x1a03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a06:
	/* 0x1a06: js     233e <generic_kprobe_process_event+0x233e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9022ULL;
	}
x86_l_1a0c:
	/* 0x1a0c: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1a10:
	/* 0x1a10: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a12:
	/* 0x1a12: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1a16:
	/* 0x1a16: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a1b:
	/* 0x1a1b: jmp    cf9 <generic_kprobe_process_event+0xcf9> */
	return 3321ULL;
x86_l_1a20:
	/* 0x1a20: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a25:
	/* 0x1a25: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a32:
	/* 0x1a32: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a42:
	/* 0x1a42: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a47:
	/* 0x1a47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1a4f:
	/* 0x1a4f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1a54:
	/* 0x1a54: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a57:
	/* 0x1a57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a59:
	/* 0x1a59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a5c:
	/* 0x1a5c: js     2338 <generic_kprobe_process_event+0x2338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9016ULL;
	}
x86_l_1a62:
	/* 0x1a62: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a67:
	/* 0x1a67: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1a6a:
	/* 0x1a6a: je     22e3 <generic_kprobe_process_event+0x22e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8931ULL;
	}
x86_l_1a70:
	/* 0x1a70: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a73:
	/* 0x1a73: jne    231f <generic_kprobe_process_event+0x231f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8991ULL;
	}
x86_l_1a79:
	/* 0x1a79: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a7d:
	/* 0x1a7d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a82:
	/* 0x1a82: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a87:
	/* 0x1a87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a91:
	/* 0x1a91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a93:
	/* 0x1a93: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a97:
	/* 0x1a97: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa0:
	/* 0x1aa0: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1aa4:
	/* 0x1aa4: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1aad:
	/* 0x1aad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ab2:
	/* 0x1ab2: jmp    2315 <generic_kprobe_process_event+0x2315> */
	return 8981ULL;
x86_l_1ab7:
	/* 0x1ab7: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1abc:
	/* 0x1abc: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1abf:
	/* 0x1abf: lea    rbp,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ac3:
	/* 0x1ac3: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1aca:
	/* 0x1aca: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_1ad6:
	/* 0x1ad6: test   BYTE PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691856ULL);
x86_l_1adb:
	/* 0x1adb: jne    2213 <generic_kprobe_process_event+0x2213> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8723ULL;
	}
x86_l_1ae1:
	/* 0x1ae1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ae6:
	/* 0x1ae6: mov    r12d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_32);
x86_l_1ae9:
	/* 0x1ae9: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1aec:
	/* 0x1aec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aee:
	/* 0x1aee: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1af1:
	/* 0x1af1: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1af4:
	/* 0x1af4: jle    2465 <generic_kprobe_process_event+0x2465> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9317ULL;
	}
x86_l_1afa:
	/* 0x1afa: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1afd:
	/* 0x1afd: je     2c54 <generic_kprobe_process_event+0x2c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11348ULL;
	}
x86_l_1b03:
	/* 0x1b03: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b06:
	/* 0x1b06: je     2c5d <generic_kprobe_process_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11357ULL;
	}
x86_l_1b0c:
	/* 0x1b0c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1b0f:
	/* 0x1b0f: jne    2c70 <generic_kprobe_process_event+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11376ULL;
	}
x86_l_1b15:
	/* 0x1b15: lea    rax,[rbx+0x5e70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_1b1c:
	/* 0x1b1c: jmp    2c6d <generic_kprobe_process_event+0x2c6d> */
	return 11373ULL;
x86_l_1b21:
	/* 0x1b21: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b26:
	/* 0x1b26: lea    r13,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b2a:
	/* 0x1b2a: lea    rax,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b2e:
	/* 0x1b2e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b33:
	/* 0x1b33: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b38:
	/* 0x1b38: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b42:
	/* 0x1b42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b47:
	/* 0x1b47: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1b4a:
	/* 0x1b4a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b4f:
	/* 0x1b4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b51:
	/* 0x1b51: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b55:
	/* 0x1b55: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b5a:
	/* 0x1b5a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b5f:
	/* 0x1b5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b64:
	/* 0x1b64: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b69:
	/* 0x1b69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6b:
	/* 0x1b6b: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b6f:
	/* 0x1b6f: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b74:
	/* 0x1b74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b79:
	/* 0x1b79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b83:
	/* 0x1b83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b85:
	/* 0x1b85: lea    rdi,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b89:
	/* 0x1b89: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b93:
	/* 0x1b93: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b98:
	/* 0x1b98: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b9d:
	/* 0x1b9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9f:
	/* 0x1b9f: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba3:
	/* 0x1ba3: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bad:
	/* 0x1bad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bb7:
	/* 0x1bb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb9:
	/* 0x1bb9: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bbd:
	/* 0x1bbd: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1bc2:
	/* 0x1bc2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bc7:
	/* 0x1bc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bcc:
	/* 0x1bcc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bd1:
	/* 0x1bd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd3:
	/* 0x1bd3: lea    rdi,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bd7:
	/* 0x1bd7: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1be1:
	/* 0x1be1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be6:
	/* 0x1be6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1beb:
	/* 0x1beb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bed:
	/* 0x1bed: lea    rdi,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1bf1:
	/* 0x1bf1: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c00:
	/* 0x1c00: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c05:
	/* 0x1c05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c07:
	/* 0x1c07: mov    DWORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1c0f:
	/* 0x1c0f: lea    rdi,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c13:
	/* 0x1c13: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c18:
	/* 0x1c18: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c22:
	/* 0x1c22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c27:
	/* 0x1c27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c29:
	/* 0x1c29: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 7213ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7213ULL: goto x86_l_1c2d;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7235ULL: goto x86_l_1c43;
	case 7239ULL: goto x86_l_1c47;
	case 7244ULL: goto x86_l_1c4c;
	case 7249ULL: goto x86_l_1c51;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7261ULL: goto x86_l_1c5d;
	case 7266ULL: goto x86_l_1c62;
	case 7271ULL: goto x86_l_1c67;
	case 7276ULL: goto x86_l_1c6c;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	case 7286ULL: goto x86_l_1c76;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7313ULL: goto x86_l_1c91;
	case 7316ULL: goto x86_l_1c94;
	case 7318ULL: goto x86_l_1c96;
	case 7323ULL: goto x86_l_1c9b;
	case 7331ULL: goto x86_l_1ca3;
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7353ULL: goto x86_l_1cb9;
	case 7357ULL: goto x86_l_1cbd;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7382ULL: goto x86_l_1cd6;
	case 7386ULL: goto x86_l_1cda;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7404ULL: goto x86_l_1cec;
	case 7409ULL: goto x86_l_1cf1;
	case 7411ULL: goto x86_l_1cf3;
	case 7415ULL: goto x86_l_1cf7;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7443ULL: goto x86_l_1d13;
	case 7445ULL: goto x86_l_1d15;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7481ULL: goto x86_l_1d39;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7499ULL: goto x86_l_1d4b;
	case 7504ULL: goto x86_l_1d50;
	case 7506ULL: goto x86_l_1d52;
	case 7510ULL: goto x86_l_1d56;
	case 7517ULL: goto x86_l_1d5d;
	case 7522ULL: goto x86_l_1d62;
	case 7527ULL: goto x86_l_1d67;
	case 7532ULL: goto x86_l_1d6c;
	case 7534ULL: goto x86_l_1d6e;
	case 7538ULL: goto x86_l_1d72;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7562ULL: goto x86_l_1d8a;
	case 7566ULL: goto x86_l_1d8e;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7586ULL: goto x86_l_1da2;
	case 7591ULL: goto x86_l_1da7;
	case 7594ULL: goto x86_l_1daa;
	case 7596ULL: goto x86_l_1dac;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7641ULL: goto x86_l_1dd9;
	case 7645ULL: goto x86_l_1ddd;
	case 7649ULL: goto x86_l_1de1;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7664ULL: goto x86_l_1df0;
	case 7666ULL: goto x86_l_1df2;
	case 7670ULL: goto x86_l_1df6;
	case 7674ULL: goto x86_l_1dfa;
	case 7679ULL: goto x86_l_1dff;
	case 7684ULL: goto x86_l_1e04;
	case 7689ULL: goto x86_l_1e09;
	case 7691ULL: goto x86_l_1e0b;
	case 7695ULL: goto x86_l_1e0f;
	case 7699ULL: goto x86_l_1e13;
	case 7704ULL: goto x86_l_1e18;
	case 7709ULL: goto x86_l_1e1d;
	case 7714ULL: goto x86_l_1e22;
	case 7716ULL: goto x86_l_1e24;
	case 7720ULL: goto x86_l_1e28;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7745ULL: goto x86_l_1e41;
	case 7747ULL: goto x86_l_1e43;
	case 7753ULL: goto x86_l_1e49;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7778ULL: goto x86_l_1e62;
	case 7783ULL: goto x86_l_1e67;
	case 7786ULL: goto x86_l_1e6a;
	case 7788ULL: goto x86_l_1e6c;
	case 7792ULL: goto x86_l_1e70;
	case 7796ULL: goto x86_l_1e74;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7813ULL: goto x86_l_1e85;
	case 7817ULL: goto x86_l_1e89;
	case 7821ULL: goto x86_l_1e8d;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7842ULL: goto x86_l_1ea2;
	case 7844ULL: goto x86_l_1ea4;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7892ULL: goto x86_l_1ed4;
	case 7894ULL: goto x86_l_1ed6;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7906ULL: goto x86_l_1ee2;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7930ULL: goto x86_l_1efa;
	case 7932ULL: goto x86_l_1efc;
	case 7936ULL: goto x86_l_1f00;
	case 7940ULL: goto x86_l_1f04;
	case 7944ULL: goto x86_l_1f08;
	case 7949ULL: goto x86_l_1f0d;
	case 7954ULL: goto x86_l_1f12;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7983ULL: goto x86_l_1f2f;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 8001ULL: goto x86_l_1f41;
	case 8004ULL: goto x86_l_1f44;
	case 8009ULL: goto x86_l_1f49;
	case 8011ULL: goto x86_l_1f4b;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8027ULL: goto x86_l_1f5b;
	case 8035ULL: goto x86_l_1f63;
	case 8043ULL: goto x86_l_1f6b;
	case 8051ULL: goto x86_l_1f73;
	case 8059ULL: goto x86_l_1f7b;
	case 8067ULL: goto x86_l_1f83;
	case 8075ULL: goto x86_l_1f8b;
	case 8083ULL: goto x86_l_1f93;
	case 8091ULL: goto x86_l_1f9b;
	case 8099ULL: goto x86_l_1fa3;
	case 8106ULL: goto x86_l_1faa;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8131ULL: goto x86_l_1fc3;
	case 8134ULL: goto x86_l_1fc6;
	case 8140ULL: goto x86_l_1fcc;
	case 8143ULL: goto x86_l_1fcf;
	case 8148ULL: goto x86_l_1fd4;
	case 8155ULL: goto x86_l_1fdb;
	case 8160ULL: goto x86_l_1fe0;
	case 8165ULL: goto x86_l_1fe5;
	case 8173ULL: goto x86_l_1fed;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8200ULL: goto x86_l_2008;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8214ULL: goto x86_l_2016;
	case 8219ULL: goto x86_l_201b;
	case 8224ULL: goto x86_l_2020;
	case 8227ULL: goto x86_l_2023;
	case 8229ULL: goto x86_l_2025;
	case 8237ULL: goto x86_l_202d;
	case 8242ULL: goto x86_l_2032;
	case 8247ULL: goto x86_l_2037;
	case 8251ULL: goto x86_l_203b;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8269ULL: goto x86_l_204d;
	case 8276ULL: goto x86_l_2054;
	case 8282ULL: goto x86_l_205a;
	case 8290ULL: goto x86_l_2062;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8302ULL: goto x86_l_206e;
	case 8305ULL: goto x86_l_2071;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8316ULL: goto x86_l_207c;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8346ULL: goto x86_l_209a;
	case 8354ULL: goto x86_l_20a2;
	case 8361ULL: goto x86_l_20a9;
	case 8369ULL: goto x86_l_20b1;
	case 8374ULL: goto x86_l_20b6;
	case 8379ULL: goto x86_l_20bb;
	case 8383ULL: goto x86_l_20bf;
	case 8385ULL: goto x86_l_20c1;
	case 8388ULL: goto x86_l_20c4;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8400ULL: goto x86_l_20d0;
	case 8404ULL: goto x86_l_20d4;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8415ULL: goto x86_l_20df;
	case 8419ULL: goto x86_l_20e3;
	case 8424ULL: goto x86_l_20e8;
	case 8429ULL: goto x86_l_20ed;
	case 8434ULL: goto x86_l_20f2;
	case 8439ULL: goto x86_l_20f7;
	case 8441ULL: goto x86_l_20f9;
	case 8444ULL: goto x86_l_20fc;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8458ULL: goto x86_l_210a;
	case 8464ULL: goto x86_l_2110;
	case 8466ULL: goto x86_l_2112;
	case 8472ULL: goto x86_l_2118;
	case 8475ULL: goto x86_l_211b;
	case 8481ULL: goto x86_l_2121;
	case 8484ULL: goto x86_l_2124;
	case 8490ULL: goto x86_l_212a;
	case 8497ULL: goto x86_l_2131;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
	case 8510ULL: goto x86_l_213e;
	case 8515ULL: goto x86_l_2143;
	case 8520ULL: goto x86_l_2148;
	case 8523ULL: goto x86_l_214b;
	case 8528ULL: goto x86_l_2150;
	case 8530ULL: goto x86_l_2152;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8547ULL: goto x86_l_2163;
	case 8552ULL: goto x86_l_2168;
	case 8554ULL: goto x86_l_216a;
	case 8558ULL: goto x86_l_216e;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8576ULL: goto x86_l_2180;
	case 8581ULL: goto x86_l_2185;
	case 8584ULL: goto x86_l_2188;
	case 8586ULL: goto x86_l_218a;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8608ULL: goto x86_l_21a0;
	case 8610ULL: goto x86_l_21a2;
	case 8615ULL: goto x86_l_21a7;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8632ULL: goto x86_l_21b8;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8649ULL: goto x86_l_21c9;
	case 8651ULL: goto x86_l_21cb;
	case 8654ULL: goto x86_l_21ce;
	case 8660ULL: goto x86_l_21d4;
	case 8662ULL: goto x86_l_21d6;
	case 8667ULL: goto x86_l_21db;
	case 8670ULL: goto x86_l_21de;
	case 8674ULL: goto x86_l_21e2;
	case 8678ULL: goto x86_l_21e6;
	case 8681ULL: goto x86_l_21e9;
	case 8684ULL: goto x86_l_21ec;
	case 8690ULL: goto x86_l_21f2;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8712ULL: goto x86_l_2208;
	case 8718ULL: goto x86_l_220e;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8730ULL: goto x86_l_221a;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8741ULL: goto x86_l_2225;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8763ULL: goto x86_l_223b;
	case 8768ULL: goto x86_l_2240;
	case 8777ULL: goto x86_l_2249;
	case 8785ULL: goto x86_l_2251;
	case 8793ULL: goto x86_l_2259;
	case 8800ULL: goto x86_l_2260;
	case 8802ULL: goto x86_l_2262;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8822ULL: goto x86_l_2276;
	case 8824ULL: goto x86_l_2278;
	case 8827ULL: goto x86_l_227b;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8847ULL: goto x86_l_228f;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8869ULL: goto x86_l_22a5;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8881ULL: goto x86_l_22b1;
	case 8884ULL: goto x86_l_22b4;
	case 8890ULL: goto x86_l_22ba;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8900ULL: goto x86_l_22c4;
	case 8906ULL: goto x86_l_22ca;
	case 8909ULL: goto x86_l_22cd;
	case 8915ULL: goto x86_l_22d3;
	case 8920ULL: goto x86_l_22d8;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8960ULL: goto x86_l_2300;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8981ULL: goto x86_l_2315;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c2d:
	/* 0x1c2d: lea    rdx,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c32:
	/* 0x1c32: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c37:
	/* 0x1c37: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c41:
	/* 0x1c41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c43:
	/* 0x1c43: lea    rdi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c47:
	/* 0x1c47: lea    rdx,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c4c:
	/* 0x1c4c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c51:
	/* 0x1c51: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c56:
	/* 0x1c56: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c5b:
	/* 0x1c5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c5d:
	/* 0x1c5d: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c62:
	/* 0x1c62: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c67:
	/* 0x1c67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c6c:
	/* 0x1c6c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1c6f:
	/* 0x1c6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c74:
	/* 0x1c74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c76:
	/* 0x1c76: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1c7d:
	/* 0x1c7d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c82:
	/* 0x1c82: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c87:
	/* 0x1c87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c91:
	/* 0x1c91: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c94:
	/* 0x1c94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c96:
	/* 0x1c96: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c9b:
	/* 0x1c9b: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ca3:
	/* 0x1ca3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ca8:
	/* 0x1ca8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cad:
	/* 0x1cad: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cb2:
	/* 0x1cb2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cb7:
	/* 0x1cb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb9:
	/* 0x1cb9: lea    rdi,[r15+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1cbd:
	/* 0x1cbd: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cca:
	/* 0x1cca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ccf:
	/* 0x1ccf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cd4:
	/* 0x1cd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd6:
	/* 0x1cd6: lea    rdi,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1cda:
	/* 0x1cda: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1ce2:
	/* 0x1ce2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ce7:
	/* 0x1ce7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cec:
	/* 0x1cec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cf1:
	/* 0x1cf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf3:
	/* 0x1cf3: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1cf7:
	/* 0x1cf7: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1cfe:
	/* 0x1cfe: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d03:
	/* 0x1d03: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d08:
	/* 0x1d08: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d0b:
	/* 0x1d0b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d10:
	/* 0x1d10: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d13:
	/* 0x1d13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d15:
	/* 0x1d15: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1d1b:
	/* 0x1d1b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d20:
	/* 0x1d20: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1d23:
	/* 0x1d23: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d28:
	/* 0x1d28: jmp    cd2 <generic_kprobe_process_event+0xcd2> */
	return 3282ULL;
x86_l_1d2d:
	/* 0x1d2d: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d32:
	/* 0x1d32: lea    rdx,[r15+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1d39:
	/* 0x1d39: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d3e:
	/* 0x1d3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d43:
	/* 0x1d43: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d48:
	/* 0x1d48: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d4b:
	/* 0x1d4b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d50:
	/* 0x1d50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d52:
	/* 0x1d52: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d56:
	/* 0x1d56: lea    rdx,[r15+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1d5d:
	/* 0x1d5d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d62:
	/* 0x1d62: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d67:
	/* 0x1d67: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d6c:
	/* 0x1d6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6e:
	/* 0x1d6e: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d72:
	/* 0x1d72: lea    rdx,[r15+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1d79:
	/* 0x1d79: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d7e:
	/* 0x1d7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d83:
	/* 0x1d83: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d88:
	/* 0x1d88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8a:
	/* 0x1d8a: add    rbx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1d8e:
	/* 0x1d8e: add    r15,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1d95:
	/* 0x1d95: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1da2:
	/* 0x1da2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1da7:
	/* 0x1da7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1daa:
	/* 0x1daa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dac:
	/* 0x1dac: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1db2:
	/* 0x1db2: jmp    1eaa <generic_kprobe_process_event+0x1eaa> */
	goto x86_l_1eaa;
x86_l_1db7:
	/* 0x1db7: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dbc:
	/* 0x1dbc: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dca:
	/* 0x1dca: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1dd2:
	/* 0x1dd2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dd7:
	/* 0x1dd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd9:
	/* 0x1dd9: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ddd:
	/* 0x1ddd: lea    rdx,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1de1:
	/* 0x1de1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1de6:
	/* 0x1de6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1deb:
	/* 0x1deb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1df0:
	/* 0x1df0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df2:
	/* 0x1df2: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df6:
	/* 0x1df6: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dfa:
	/* 0x1dfa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dff:
	/* 0x1dff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e04:
	/* 0x1e04: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e09:
	/* 0x1e09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0b:
	/* 0x1e0b: lea    rdi,[rbx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e0f:
	/* 0x1e0f: lea    rdx,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e13:
	/* 0x1e13: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e18:
	/* 0x1e18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e1d:
	/* 0x1e1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e22:
	/* 0x1e22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e24:
	/* 0x1e24: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e28:
	/* 0x1e28: add    r15,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1e31:
	/* 0x1e31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e36:
	/* 0x1e36: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e39:
	/* 0x1e39: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e41:
	/* 0x1e41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e43:
	/* 0x1e43: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1e49:
	/* 0x1e49: jmp    1eaa <generic_kprobe_process_event+0x1eaa> */
	goto x86_l_1eaa;
x86_l_1e4b:
	/* 0x1e4b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e50:
	/* 0x1e50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e55:
	/* 0x1e55: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5a:
	/* 0x1e5a: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e5f:
	/* 0x1e5f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e62:
	/* 0x1e62: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e67:
	/* 0x1e67: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e6a:
	/* 0x1e6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6c:
	/* 0x1e6c: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e70:
	/* 0x1e70: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e74:
	/* 0x1e74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e79:
	/* 0x1e79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e83:
	/* 0x1e83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e85:
	/* 0x1e85: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e89:
	/* 0x1e89: add    r15,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1e8d:
	/* 0x1e8d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1e92:
	/* 0x1e92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e97:
	/* 0x1e97: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e9a:
	/* 0x1e9a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e9f:
	/* 0x1e9f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ea2:
	/* 0x1ea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea4:
	/* 0x1ea4: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eaf:
	/* 0x1eaf: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1eb4:
	/* 0x1eb4: jmp    cd2 <generic_kprobe_process_event+0xcd2> */
	return 3282ULL;
x86_l_1eb9:
	/* 0x1eb9: lea    rdx,[r8+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ebd:
	/* 0x1ebd: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ec7:
	/* 0x1ec7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_1ed4:
	/* 0x1ed4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed6:
	/* 0x1ed6: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1eda:
	/* 0x1eda: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1edf:
	/* 0x1edf: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee2:
	/* 0x1ee2: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ee6:
	/* 0x1ee6: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1eeb:
	/* 0x1eeb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ef0:
	/* 0x1ef0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef5:
	/* 0x1ef5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1efa:
	/* 0x1efa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1efc:
	/* 0x1efc: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f00:
	/* 0x1f00: mov    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f04:
	/* 0x1f04: add    r13,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1f08:
	/* 0x1f08: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f0d:
	/* 0x1f0d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f12:
	/* 0x1f12: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f17:
	/* 0x1f17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f1c:
	/* 0x1f1c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1f1f:
	/* 0x1f1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f21:
	/* 0x1f21: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f25:
	/* 0x1f25: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1f2a:
	/* 0x1f2a: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f2f:
	/* 0x1f2f: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f32:
	/* 0x1f32: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f37:
	/* 0x1f37: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f3c:
	/* 0x1f3c: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_1f41:
	/* 0x1f41: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f44:
	/* 0x1f44: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f49:
	/* 0x1f49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f4b:
	/* 0x1f4b: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1f51:
	/* 0x1f51: jmp    1067 <generic_kprobe_process_event+0x1067> */
	return 4199ULL;
x86_l_1f56:
	/* 0x1f56: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1f63:
	/* 0x1f63: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1f6b:
	/* 0x1f6b: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1f73:
	/* 0x1f73: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1f7b:
	/* 0x1f7b: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1f83:
	/* 0x1f83: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1f93:
	/* 0x1f93: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f9b:
	/* 0x1f9b: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1fa3:
	/* 0x1fa3: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1faa:
	/* 0x1faa: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1faf:
	/* 0x1faf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fb4:
	/* 0x1fb4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fb9:
	/* 0x1fb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1fc1:
	/* 0x1fc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc3:
	/* 0x1fc3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fc6:
	/* 0x1fc6: je     2348 <generic_kprobe_process_event+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9032ULL;
	}
x86_l_1fcc:
	/* 0x1fcc: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fcf:
	/* 0x1fcf: jmp    cc8 <generic_kprobe_process_event+0xcc8> */
	return 3272ULL;
x86_l_1fd4:
	/* 0x1fd4: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1fdb:
	/* 0x1fdb: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_1fe0:
	/* 0x1fe0: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fe5:
	/* 0x1fe5: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1fed:
	/* 0x1fed: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1ff2:
	/* 0x1ff2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ff7:
	/* 0x1ff7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ffc:
	/* 0x1ffc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2001:
	/* 0x2001: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2006:
	/* 0x2006: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2008:
	/* 0x2008: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_200c:
	/* 0x200c: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2011:
	/* 0x2011: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2016:
	/* 0x2016: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_201b:
	/* 0x201b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2020:
	/* 0x2020: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2023:
	/* 0x2023: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2025:
	/* 0x2025: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_202d:
	/* 0x202d: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2032:
	/* 0x2032: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2037:
	/* 0x2037: lea    r12,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_203b:
	/* 0x203b: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2042:
	/* 0x2042: test   BYTE PTR [rsp+0x50],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383712ULL);
x86_l_2047:
	/* 0x2047: je     2b45 <generic_kprobe_process_event+0x2b45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11077ULL;
	}
x86_l_204d:
	/* 0x204d: cmp    rbx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4096ULL);
x86_l_2054:
	/* 0x2054: jb     2b19 <generic_kprobe_process_event+0x2b19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11033ULL;
	}
x86_l_205a:
	/* 0x205a: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2062:
	/* 0x2062: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2066:
	/* 0x2066: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_206b:
	/* 0x206b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_206e:
	/* 0x206e: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_2071:
	/* 0x2071: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2074:
	/* 0x2074: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8313ULL);
	__x86_sim_call_depth++;
	return 14263ULL;
x86_l_2079:
	/* 0x2079: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_207c:
	/* 0x207c: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2080:
	/* 0x2080: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2085:
	/* 0x2085: jmp    cf4 <generic_kprobe_process_event+0xcf4> */
	return 3316ULL;
x86_l_208a:
	/* 0x208a: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_208f:
	/* 0x208f: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_209a:
	/* 0x209a: movzx  ebp,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_20a2:
	/* 0x20a2: mov    rdi,QWORD PTR [rip+0x248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_20a9:
	/* 0x20a9: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_20b1:
	/* 0x20b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20b6:
	/* 0x20b6: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20bb:
	/* 0x20bb: lea    r13,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_20bf:
	/* 0x20bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c1:
	/* 0x20c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20c4:
	/* 0x20c4: je     3296 <generic_kprobe_process_event+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12950ULL;
	}
x86_l_20ca:
	/* 0x20ca: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_20cd:
	/* 0x20cd: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d0:
	/* 0x20d0: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_20d4:
	/* 0x20d4: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_20d8:
	/* 0x20d8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_20db:
	/* 0x20db: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_20df:
	/* 0x20df: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_20e3:
	/* 0x20e3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_20e8:
	/* 0x20e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20ed:
	/* 0x20ed: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20f2:
	/* 0x20f2: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_20f7:
	/* 0x20f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f9:
	/* 0x20f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20fc:
	/* 0x20fc: js     3296 <generic_kprobe_process_event+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12950ULL;
	}
x86_l_2102:
	/* 0x2102: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2107:
	/* 0x2107: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_210a:
	/* 0x210a: jg     2b92 <generic_kprobe_process_event+0x2b92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11154ULL;
	}
x86_l_2110:
	/* 0x2110: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2112:
	/* 0x2112: je     2c43 <generic_kprobe_process_event+0x2c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11331ULL;
	}
x86_l_2118:
	/* 0x2118: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_211b:
	/* 0x211b: je     2c43 <generic_kprobe_process_event+0x2c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11331ULL;
	}
x86_l_2121:
	/* 0x2121: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2124:
	/* 0x2124: jne    2e17 <generic_kprobe_process_event+0x2e17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11799ULL;
	}
x86_l_212a:
	/* 0x212a: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2131:
	/* 0x2131: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2135:
	/* 0x2135: jmp    2d61 <generic_kprobe_process_event+0x2d61> */
	return 11617ULL;
x86_l_213a:
	/* 0x213a: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_213e:
	/* 0x213e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2143:
	/* 0x2143: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2148:
	/* 0x2148: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_214b:
	/* 0x214b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2150:
	/* 0x2150: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2152:
	/* 0x2152: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2156:
	/* 0x2156: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_215b:
	/* 0x215b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2160:
	/* 0x2160: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2163:
	/* 0x2163: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2168:
	/* 0x2168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216a:
	/* 0x216a: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_216e:
	/* 0x216e: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2172:
	/* 0x2172: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2176:
	/* 0x2176: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_217b:
	/* 0x217b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2180:
	/* 0x2180: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2185:
	/* 0x2185: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2188:
	/* 0x2188: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218a:
	/* 0x218a: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_218e:
	/* 0x218e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2193:
	/* 0x2193: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2198:
	/* 0x2198: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_219d:
	/* 0x219d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21a0:
	/* 0x21a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a2:
	/* 0x21a2: movzx  eax,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_21a7:
	/* 0x21a7: movbe  WORD PTR [r13+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_21ae:
	/* 0x21ae: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21b3:
	/* 0x21b3: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_21b8:
	/* 0x21b8: mov    rdi,QWORD PTR [rip+0x248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_21bf:
	/* 0x21bf: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_21c4:
	/* 0x21c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21c9:
	/* 0x21c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21cb:
	/* 0x21cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21ce:
	/* 0x21ce: je     3457 <generic_kprobe_process_event+0x3457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13399ULL;
	}
x86_l_21d4:
	/* 0x21d4: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21d6:
	/* 0x21d6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21db:
	/* 0x21db: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21de:
	/* 0x21de: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e2:
	/* 0x21e2: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21e6:
	/* 0x21e6: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21e9:
	/* 0x21e9: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_21ec:
	/* 0x21ec: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_21f2:
	/* 0x21f2: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_21f7:
	/* 0x21f7: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21fc:
	/* 0x21fc: mov    QWORD PTR [rbp+rax*1+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 618475290624ULL);
x86_l_2208:
	/* 0x2208: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_220e:
	/* 0x220e: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_2213:
	/* 0x2213: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2218:
	/* 0x2218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221a:
	/* 0x221a: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_221e:
	/* 0x221e: jne    2229 <generic_kprobe_process_event+0x2229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2229;
	}
x86_l_2220:
	/* 0x2220: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2225:
	/* 0x2225: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2229:
	/* 0x2229: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222d:
	/* 0x222d: mov    rdx,QWORD PTR [rbx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2231:
	/* 0x2231: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2236:
	/* 0x2236: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_223b:
	/* 0x223b: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2240:
	/* 0x2240: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2249:
	/* 0x2249: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2251:
	/* 0x2251: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2259:
	/* 0x2259: mov    rdi,QWORD PTR [rip+0x248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2260:
	/* 0x2260: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2262:
	/* 0x2262: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_226a:
	/* 0x226a: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_226f:
	/* 0x226f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2274:
	/* 0x2274: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2276:
	/* 0x2276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2278:
	/* 0x2278: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_227b:
	/* 0x227b: je     2be9 <generic_kprobe_process_event+0x2be9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11241ULL;
	}
x86_l_2281:
	/* 0x2281: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2283:
	/* 0x2283: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2288:
	/* 0x2288: mov    WORD PTR [rsp+0x5a],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 386547056645ULL);
x86_l_228f:
	/* 0x228f: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_2299:
	/* 0x2299: mov    QWORD PTR [rsp+0x5c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_229e:
	/* 0x229e: mov    rdi,QWORD PTR [rip+0x248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_22a5:
	/* 0x22a5: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_22aa:
	/* 0x22aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22af:
	/* 0x22af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b1:
	/* 0x22b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22b4:
	/* 0x22b4: je     2bbf <generic_kprobe_process_event+0x2bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11199ULL;
	}
x86_l_22ba:
	/* 0x22ba: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_22bc:
	/* 0x22bc: jmp    2be9 <generic_kprobe_process_event+0x2be9> */
	return 11241ULL;
x86_l_22c1:
	/* 0x22c1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22c4:
	/* 0x22c4: je     2565 <generic_kprobe_process_event+0x2565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9573ULL;
	}
x86_l_22ca:
	/* 0x22ca: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22cd:
	/* 0x22cd: jne    29cc <generic_kprobe_process_event+0x29cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10700ULL;
	}
x86_l_22d3:
	/* 0x22d3: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22d8:
	/* 0x22d8: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_22de:
	/* 0x22de: jmp    2570 <generic_kprobe_process_event+0x2570> */
	return 9584ULL;
x86_l_22e3:
	/* 0x22e3: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22e8:
	/* 0x22e8: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ed:
	/* 0x22ed: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f1:
	/* 0x22f1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_22f6:
	/* 0x22f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22fb:
	/* 0x22fb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2300:
	/* 0x2300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2302:
	/* 0x2302: lea    rdi,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2307:
	/* 0x2307: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_230b:
	/* 0x230b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2310:
	/* 0x2310: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2315:
	/* 0x2315: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
	return 8986ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8986ULL: goto x86_l_231a;
	case 8989ULL: goto x86_l_231d;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9000ULL: goto x86_l_2328;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9016ULL: goto x86_l_2338;
	case 9022ULL: goto x86_l_233e;
	case 9027ULL: goto x86_l_2343;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9056ULL: goto x86_l_2360;
	case 9061ULL: goto x86_l_2365;
	case 9066ULL: goto x86_l_236a;
	case 9068ULL: goto x86_l_236c;
	case 9071ULL: goto x86_l_236f;
	case 9077ULL: goto x86_l_2375;
	case 9082ULL: goto x86_l_237a;
	case 9086ULL: goto x86_l_237e;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9109ULL: goto x86_l_2395;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9133ULL: goto x86_l_23ad;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9146ULL: goto x86_l_23ba;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9161ULL: goto x86_l_23c9;
	case 9165ULL: goto x86_l_23cd;
	case 9173ULL: goto x86_l_23d5;
	case 9178ULL: goto x86_l_23da;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9191ULL: goto x86_l_23e7;
	case 9193ULL: goto x86_l_23e9;
	case 9199ULL: goto x86_l_23ef;
	case 9202ULL: goto x86_l_23f2;
	case 9208ULL: goto x86_l_23f8;
	case 9210ULL: goto x86_l_23fa;
	case 9218ULL: goto x86_l_2402;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9228ULL: goto x86_l_240c;
	case 9233ULL: goto x86_l_2411;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9242ULL: goto x86_l_241a;
	case 9245ULL: goto x86_l_241d;
	case 9250ULL: goto x86_l_2422;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9269ULL: goto x86_l_2435;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9277ULL: goto x86_l_243d;
	case 9279ULL: goto x86_l_243f;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9326ULL: goto x86_l_246e;
	case 9329ULL: goto x86_l_2471;
	case 9335ULL: goto x86_l_2477;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9351ULL: goto x86_l_2487;
	case 9356ULL: goto x86_l_248c;
	case 9361ULL: goto x86_l_2491;
	case 9366ULL: goto x86_l_2496;
	case 9371ULL: goto x86_l_249b;
	case 9373ULL: goto x86_l_249d;
	case 9377ULL: goto x86_l_24a1;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9390ULL: goto x86_l_24ae;
	case 9395ULL: goto x86_l_24b3;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9406ULL: goto x86_l_24be;
	case 9410ULL: goto x86_l_24c2;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9429ULL: goto x86_l_24d5;
	case 9432ULL: goto x86_l_24d8;
	case 9434ULL: goto x86_l_24da;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9448ULL: goto x86_l_24e8;
	case 9453ULL: goto x86_l_24ed;
	case 9456ULL: goto x86_l_24f0;
	case 9458ULL: goto x86_l_24f2;
	case 9462ULL: goto x86_l_24f6;
	case 9468ULL: goto x86_l_24fc;
	case 9473ULL: goto x86_l_2501;
	case 9477ULL: goto x86_l_2505;
	case 9482ULL: goto x86_l_250a;
	case 9489ULL: goto x86_l_2511;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9501ULL: goto x86_l_251d;
	case 9504ULL: goto x86_l_2520;
	case 9506ULL: goto x86_l_2522;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9516ULL: goto x86_l_252c;
	case 9520ULL: goto x86_l_2530;
	case 9524ULL: goto x86_l_2534;
	case 9527ULL: goto x86_l_2537;
	case 9530ULL: goto x86_l_253a;
	case 9536ULL: goto x86_l_2540;
	case 9539ULL: goto x86_l_2543;
	case 9542ULL: goto x86_l_2546;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9558ULL: goto x86_l_2556;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9584ULL: goto x86_l_2570;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9598ULL: goto x86_l_257e;
	case 9601ULL: goto x86_l_2581;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9618ULL: goto x86_l_2592;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9638ULL: goto x86_l_25a6;
	case 9640ULL: goto x86_l_25a8;
	case 9645ULL: goto x86_l_25ad;
	case 9647ULL: goto x86_l_25af;
	case 9653ULL: goto x86_l_25b5;
	case 9658ULL: goto x86_l_25ba;
	case 9663ULL: goto x86_l_25bf;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9678ULL: goto x86_l_25ce;
	case 9684ULL: goto x86_l_25d4;
	case 9689ULL: goto x86_l_25d9;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9704ULL: goto x86_l_25e8;
	case 9707ULL: goto x86_l_25eb;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9736ULL: goto x86_l_2608;
	case 9742ULL: goto x86_l_260e;
	case 9746ULL: goto x86_l_2612;
	case 9752ULL: goto x86_l_2618;
	case 9757ULL: goto x86_l_261d;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9796ULL: goto x86_l_2644;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9823ULL: goto x86_l_265f;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9850ULL: goto x86_l_267a;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9868ULL: goto x86_l_268c;
	case 9873ULL: goto x86_l_2691;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9882ULL: goto x86_l_269a;
	case 9888ULL: goto x86_l_26a0;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9902ULL: goto x86_l_26ae;
	case 9908ULL: goto x86_l_26b4;
	case 9913ULL: goto x86_l_26b9;
	case 9917ULL: goto x86_l_26bd;
	case 9922ULL: goto x86_l_26c2;
	case 9928ULL: goto x86_l_26c8;
	case 9933ULL: goto x86_l_26cd;
	case 9938ULL: goto x86_l_26d2;
	case 9943ULL: goto x86_l_26d7;
	case 9945ULL: goto x86_l_26d9;
	case 9950ULL: goto x86_l_26de;
	case 9952ULL: goto x86_l_26e0;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9976ULL: goto x86_l_26f8;
	case 9982ULL: goto x86_l_26fe;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10009ULL: goto x86_l_2719;
	case 10012ULL: goto x86_l_271c;
	case 10017ULL: goto x86_l_2721;
	case 10022ULL: goto x86_l_2726;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10037ULL: goto x86_l_2735;
	case 10042ULL: goto x86_l_273a;
	case 10044ULL: goto x86_l_273c;
	case 10050ULL: goto x86_l_2742;
	case 10058ULL: goto x86_l_274a;
	case 10063ULL: goto x86_l_274f;
	case 10067ULL: goto x86_l_2753;
	case 10073ULL: goto x86_l_2759;
	case 10078ULL: goto x86_l_275e;
	case 10082ULL: goto x86_l_2762;
	case 10087ULL: goto x86_l_2767;
	case 10093ULL: goto x86_l_276d;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10117ULL: goto x86_l_2785;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10138ULL: goto x86_l_279a;
	case 10144ULL: goto x86_l_27a0;
	case 10150ULL: goto x86_l_27a6;
	case 10158ULL: goto x86_l_27ae;
	case 10163ULL: goto x86_l_27b3;
	case 10171ULL: goto x86_l_27bb;
	case 10177ULL: goto x86_l_27c1;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10209ULL: goto x86_l_27e1;
	case 10215ULL: goto x86_l_27e7;
	case 10220ULL: goto x86_l_27ec;
	case 10225ULL: goto x86_l_27f1;
	case 10229ULL: goto x86_l_27f5;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10272ULL: goto x86_l_2820;
	case 10277ULL: goto x86_l_2825;
	case 10279ULL: goto x86_l_2827;
	case 10285ULL: goto x86_l_282d;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10306ULL: goto x86_l_2842;
	case 10312ULL: goto x86_l_2848;
	case 10317ULL: goto x86_l_284d;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10336ULL: goto x86_l_2860;
	case 10339ULL: goto x86_l_2863;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10368ULL: goto x86_l_2880;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10384ULL: goto x86_l_2890;
	case 10388ULL: goto x86_l_2894;
	case 10394ULL: goto x86_l_289a;
	case 10399ULL: goto x86_l_289f;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10414ULL: goto x86_l_28ae;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10438ULL: goto x86_l_28c6;
	case 10444ULL: goto x86_l_28cc;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10462ULL: goto x86_l_28de;
	case 10468ULL: goto x86_l_28e4;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10495ULL: goto x86_l_28ff;
	case 10498ULL: goto x86_l_2902;
	case 10503ULL: goto x86_l_2907;
	case 10508ULL: goto x86_l_290c;
	case 10516ULL: goto x86_l_2914;
	case 10521ULL: goto x86_l_2919;
	case 10523ULL: goto x86_l_291b;
	case 10528ULL: goto x86_l_2920;
	case 10530ULL: goto x86_l_2922;
	case 10536ULL: goto x86_l_2928;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10553ULL: goto x86_l_2939;
	case 10559ULL: goto x86_l_293f;
	case 10564ULL: goto x86_l_2944;
	case 10568ULL: goto x86_l_2948;
	case 10573ULL: goto x86_l_294d;
	case 10579ULL: goto x86_l_2953;
	case 10584ULL: goto x86_l_2958;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10603ULL: goto x86_l_296b;
	case 10605ULL: goto x86_l_296d;
	case 10610ULL: goto x86_l_2972;
	case 10615ULL: goto x86_l_2977;
	case 10622ULL: goto x86_l_297e;
	case 10624ULL: goto x86_l_2980;
	case 10632ULL: goto x86_l_2988;
	case 10637ULL: goto x86_l_298d;
	case 10643ULL: goto x86_l_2993;
	case 10646ULL: goto x86_l_2996;
	case 10651ULL: goto x86_l_299b;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10664ULL: goto x86_l_29a8;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10703ULL: goto x86_l_29cf;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10724ULL: goto x86_l_29e4;
	case 10729ULL: goto x86_l_29e9;
	case 10731ULL: goto x86_l_29eb;
	case 10735ULL: goto x86_l_29ef;
	case 10737ULL: goto x86_l_29f1;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10750ULL: goto x86_l_29fe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_231a:
	/* 0x231a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_231d:
	/* 0x231d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231f:
	/* 0x231f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2324:
	/* 0x2324: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2328:
	/* 0x2328: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_232e:
	/* 0x232e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2333:
	/* 0x2333: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2338:
	/* 0x2338: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_233e:
	/* 0x233e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2343:
	/* 0x2343: jmp    cf9 <generic_kprobe_process_event+0xcf9> */
	return 3321ULL;
x86_l_2348:
	/* 0x2348: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_234d:
	/* 0x234d: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2351:
	/* 0x2351: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2356:
	/* 0x2356: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_235b:
	/* 0x235b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2360:
	/* 0x2360: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2365:
	/* 0x2365: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_236a:
	/* 0x236a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236c:
	/* 0x236c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_236f:
	/* 0x236f: js     1fcc <generic_kprobe_process_event+0x1fcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8140ULL;
	}
x86_l_2375:
	/* 0x2375: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_237a:
	/* 0x237a: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_237e:
	/* 0x237e: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2386:
	/* 0x2386: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_238b:
	/* 0x238b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2390:
	/* 0x2390: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2395:
	/* 0x2395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2397:
	/* 0x2397: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239c:
	/* 0x239c: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23a0:
	/* 0x23a0: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_23a5:
	/* 0x23a5: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_23ad:
	/* 0x23ad: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23b0:
	/* 0x23b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b5:
	/* 0x23b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ba:
	/* 0x23ba: add    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_23c2:
	/* 0x23c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23c7:
	/* 0x23c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c9:
	/* 0x23c9: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_23cd:
	/* 0x23cd: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_23d5:
	/* 0x23d5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_23da:
	/* 0x23da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23df:
	/* 0x23df: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23e4:
	/* 0x23e4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23e7:
	/* 0x23e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23e9:
	/* 0x23e9: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_23ef:
	/* 0x23ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23f2:
	/* 0x23f2: jne    cc8 <generic_kprobe_process_event+0xcc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3272ULL;
	}
x86_l_23f8:
	/* 0x23f8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23fa:
	/* 0x23fa: cmp    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2402:
	/* 0x2402: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2405:
	/* 0x2405: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_240a:
	/* 0x240a: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240c:
	/* 0x240c: jmp    cc8 <generic_kprobe_process_event+0xcc8> */
	return 3272ULL;
x86_l_2411:
	/* 0x2411: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2414:
	/* 0x2414: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2417:
	/* 0x2417: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_241a:
	/* 0x241a: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_241d:
	/* 0x241d: jmp    ccd <generic_kprobe_process_event+0xccd> */
	return 3277ULL;
x86_l_2422:
	/* 0x2422: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_2426:
	/* 0x2426: mov    ecx,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 107ULL);
x86_l_242b:
	/* 0x242b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2430:
	/* 0x2430: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_2435:
	/* 0x2435: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2438:
	/* 0x2438: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243a:
	/* 0x243a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_243d:
	/* 0x243d: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_243f:
	/* 0x243f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2441:
	/* 0x2441: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2446:
	/* 0x2446: js     2450 <generic_kprobe_process_event+0x2450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2450;
	}
x86_l_2448:
	/* 0x2448: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_244d:
	/* 0x244d: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_2450:
	/* 0x2450: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_2456:
	/* 0x2456: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_245b:
	/* 0x245b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2460:
	/* 0x2460: jmp    cf9 <generic_kprobe_process_event+0xcf9> */
	return 3321ULL;
x86_l_2465:
	/* 0x2465: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2468:
	/* 0x2468: je     2c66 <generic_kprobe_process_event+0x2c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11366ULL;
	}
x86_l_246e:
	/* 0x246e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2471:
	/* 0x2471: jne    2c70 <generic_kprobe_process_event+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11376ULL;
	}
x86_l_2477:
	/* 0x2477: lea    rax,[rbx+0x5e58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_247e:
	/* 0x247e: jmp    2c6d <generic_kprobe_process_event+0x2c6d> */
	return 11373ULL;
x86_l_2483:
	/* 0x2483: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2487:
	/* 0x2487: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_248c:
	/* 0x248c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2491:
	/* 0x2491: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2496:
	/* 0x2496: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_249b:
	/* 0x249b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249d:
	/* 0x249d: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24a1:
	/* 0x24a1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_24a6:
	/* 0x24a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ab:
	/* 0x24ab: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_24ae:
	/* 0x24ae: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24b3:
	/* 0x24b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b5:
	/* 0x24b5: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ba:
	/* 0x24ba: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24be:
	/* 0x24be: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_24c2:
	/* 0x24c2: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_24c6:
	/* 0x24c6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_24cb:
	/* 0x24cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24d0:
	/* 0x24d0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24d5:
	/* 0x24d5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_24d8:
	/* 0x24d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24da:
	/* 0x24da: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_24de:
	/* 0x24de: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_24e3:
	/* 0x24e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24e8:
	/* 0x24e8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24ed:
	/* 0x24ed: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24f0:
	/* 0x24f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f2:
	/* 0x24f2: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_24f6:
	/* 0x24f6: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_24fc:
	/* 0x24fc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2501:
	/* 0x2501: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2505:
	/* 0x2505: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_250a:
	/* 0x250a: mov    rdi,QWORD PTR [rip+0x248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2511:
	/* 0x2511: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2516:
	/* 0x2516: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_251b:
	/* 0x251b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251d:
	/* 0x251d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2520:
	/* 0x2520: je     253a <generic_kprobe_process_event+0x253a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253a;
	}
x86_l_2522:
	/* 0x2522: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2524:
	/* 0x2524: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2529:
	/* 0x2529: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_252c:
	/* 0x252c: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2530:
	/* 0x2530: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2534:
	/* 0x2534: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2537:
	/* 0x2537: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_253a:
	/* 0x253a: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_2540:
	/* 0x2540: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2543:
	/* 0x2543: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_2546:
	/* 0x2546: jmp    f62 <generic_kprobe_process_event+0xf62> */
	return 3938ULL;
x86_l_254b:
	/* 0x254b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2550:
	/* 0x2550: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_2556:
	/* 0x2556: jmp    2570 <generic_kprobe_process_event+0x2570> */
	goto x86_l_2570;
x86_l_2558:
	/* 0x2558: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_255d:
	/* 0x255d: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2563:
	/* 0x2563: jmp    2570 <generic_kprobe_process_event+0x2570> */
	goto x86_l_2570;
x86_l_2565:
	/* 0x2565: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_256a:
	/* 0x256a: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_2570:
	/* 0x2570: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2573:
	/* 0x2573: test   BYTE PTR [rsp+0x50],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383696ULL);
x86_l_2578:
	/* 0x2578: jne    29e4 <generic_kprobe_process_event+0x29e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29e4;
	}
x86_l_257e:
	/* 0x257e: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_2581:
	/* 0x2581: je     2a8e <generic_kprobe_process_event+0x2a8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10894ULL;
	}
x86_l_2587:
	/* 0x2587: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_258c:
	/* 0x258c: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2592:
	/* 0x2592: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2597:
	/* 0x2597: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_259c:
	/* 0x259c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25a1:
	/* 0x25a1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25a6:
	/* 0x25a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a8:
	/* 0x25a8: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25ad:
	/* 0x25ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25af:
	/* 0x25af: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_25b5:
	/* 0x25b5: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25ba:
	/* 0x25ba: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_25bf:
	/* 0x25bf: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_25c2:
	/* 0x25c2: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c7:
	/* 0x25c7: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_25ce:
	/* 0x25ce: ja     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29bd;
	}
x86_l_25d4:
	/* 0x25d4: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25d9:
	/* 0x25d9: lea    rdi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_25dd:
	/* 0x25dd: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25e2:
	/* 0x25e2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25e8:
	/* 0x25e8: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25eb:
	/* 0x25eb: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25f0:
	/* 0x25f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25f5:
	/* 0x25f5: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25fa:
	/* 0x25fa: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25ff:
	/* 0x25ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2601:
	/* 0x2601: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2606:
	/* 0x2606: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2608:
	/* 0x2608: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_260e:
	/* 0x260e: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_2612:
	/* 0x2612: je     2a95 <generic_kprobe_process_event+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10901ULL;
	}
x86_l_2618:
	/* 0x2618: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_261d:
	/* 0x261d: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2621:
	/* 0x2621: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2626:
	/* 0x2626: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_262c:
	/* 0x262c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2631:
	/* 0x2631: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2636:
	/* 0x2636: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_263b:
	/* 0x263b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263d:
	/* 0x263d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2642:
	/* 0x2642: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2644:
	/* 0x2644: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_264a:
	/* 0x264a: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_264f:
	/* 0x264f: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2654:
	/* 0x2654: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2659:
	/* 0x2659: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_265f:
	/* 0x265f: ja     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29bd;
	}
x86_l_2665:
	/* 0x2665: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_266a:
	/* 0x266a: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_266f:
	/* 0x266f: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2674:
	/* 0x2674: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_267a:
	/* 0x267a: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_267d:
	/* 0x267d: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2682:
	/* 0x2682: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2687:
	/* 0x2687: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_268c:
	/* 0x268c: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2691:
	/* 0x2691: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2693:
	/* 0x2693: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2698:
	/* 0x2698: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_269a:
	/* 0x269a: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_26a0:
	/* 0x26a0: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26a5:
	/* 0x26a5: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26aa:
	/* 0x26aa: cmp    r12,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 3ULL);
x86_l_26ae:
	/* 0x26ae: jb     2a95 <generic_kprobe_process_event+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10901ULL;
	}
x86_l_26b4:
	/* 0x26b4: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26b9:
	/* 0x26b9: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26bd:
	/* 0x26bd: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_26c2:
	/* 0x26c2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_26c8:
	/* 0x26c8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_26cd:
	/* 0x26cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26d2:
	/* 0x26d2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26d7:
	/* 0x26d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d9:
	/* 0x26d9: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_26de:
	/* 0x26de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26e0:
	/* 0x26e0: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_26e6:
	/* 0x26e6: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26eb:
	/* 0x26eb: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_26f0:
	/* 0x26f0: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26f8:
	/* 0x26f8: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_26fe:
	/* 0x26fe: ja     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29bd;
	}
x86_l_2704:
	/* 0x2704: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2709:
	/* 0x2709: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_270e:
	/* 0x270e: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2713:
	/* 0x2713: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2719:
	/* 0x2719: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_271c:
	/* 0x271c: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2721:
	/* 0x2721: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2726:
	/* 0x2726: mov    rsi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_272e:
	/* 0x272e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2733:
	/* 0x2733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2735:
	/* 0x2735: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_273a:
	/* 0x273a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_273c:
	/* 0x273c: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_2742:
	/* 0x2742: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_274a:
	/* 0x274a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_274f:
	/* 0x274f: cmp    r12,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 3ULL);
x86_l_2753:
	/* 0x2753: je     2a95 <generic_kprobe_process_event+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10901ULL;
	}
x86_l_2759:
	/* 0x2759: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_275e:
	/* 0x275e: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2762:
	/* 0x2762: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2767:
	/* 0x2767: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_276d:
	/* 0x276d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2772:
	/* 0x2772: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2777:
	/* 0x2777: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_277c:
	/* 0x277c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277e:
	/* 0x277e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2783:
	/* 0x2783: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2785:
	/* 0x2785: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_278b:
	/* 0x278b: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2790:
	/* 0x2790: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2795:
	/* 0x2795: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_279a:
	/* 0x279a: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_27a0:
	/* 0x27a0: ja     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29bd;
	}
x86_l_27a6:
	/* 0x27a6: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_27ae:
	/* 0x27ae: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_27b3:
	/* 0x27b3: mov    QWORD PTR [rsp+0xc0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_27bb:
	/* 0x27bb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27c1:
	/* 0x27c1: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27c4:
	/* 0x27c4: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27c9:
	/* 0x27c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27ce:
	/* 0x27ce: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27d3:
	/* 0x27d3: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27d8:
	/* 0x27d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27da:
	/* 0x27da: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27df:
	/* 0x27df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27e1:
	/* 0x27e1: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_27e7:
	/* 0x27e7: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27ec:
	/* 0x27ec: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_27f1:
	/* 0x27f1: cmp    r12,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 5ULL);
x86_l_27f5:
	/* 0x27f5: jb     2a95 <generic_kprobe_process_event+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10901ULL;
	}
x86_l_27fb:
	/* 0x27fb: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2800:
	/* 0x2800: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2804:
	/* 0x2804: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2809:
	/* 0x2809: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_280f:
	/* 0x280f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2814:
	/* 0x2814: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2819:
	/* 0x2819: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_281e:
	/* 0x281e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2820:
	/* 0x2820: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2825:
	/* 0x2825: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2827:
	/* 0x2827: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_282d:
	/* 0x282d: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2832:
	/* 0x2832: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2837:
	/* 0x2837: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_283c:
	/* 0x283c: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2842:
	/* 0x2842: ja     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29bd;
	}
x86_l_2848:
	/* 0x2848: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_284d:
	/* 0x284d: add    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 192ULL);
x86_l_2855:
	/* 0x2855: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_285a:
	/* 0x285a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2860:
	/* 0x2860: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2863:
	/* 0x2863: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2868:
	/* 0x2868: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_286d:
	/* 0x286d: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2872:
	/* 0x2872: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2877:
	/* 0x2877: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2879:
	/* 0x2879: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_287e:
	/* 0x287e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2880:
	/* 0x2880: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_2886:
	/* 0x2886: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_288b:
	/* 0x288b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2890:
	/* 0x2890: cmp    r12,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 5ULL);
x86_l_2894:
	/* 0x2894: je     2a95 <generic_kprobe_process_event+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10901ULL;
	}
x86_l_289a:
	/* 0x289a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_289f:
	/* 0x289f: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28a3:
	/* 0x28a3: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28a8:
	/* 0x28a8: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_28ae:
	/* 0x28ae: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_28b3:
	/* 0x28b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28b8:
	/* 0x28b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28bd:
	/* 0x28bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28bf:
	/* 0x28bf: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28c4:
	/* 0x28c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28c6:
	/* 0x28c6: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_28cc:
	/* 0x28cc: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_28d1:
	/* 0x28d1: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_28d6:
	/* 0x28d6: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_28de:
	/* 0x28de: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_28e4:
	/* 0x28e4: ja     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29bd;
	}
x86_l_28ea:
	/* 0x28ea: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28ef:
	/* 0x28ef: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_28f4:
	/* 0x28f4: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28f9:
	/* 0x28f9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_28ff:
	/* 0x28ff: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2902:
	/* 0x2902: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2907:
	/* 0x2907: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_290c:
	/* 0x290c: mov    rsi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2914:
	/* 0x2914: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2919:
	/* 0x2919: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291b:
	/* 0x291b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2920:
	/* 0x2920: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2922:
	/* 0x2922: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_2928:
	/* 0x2928: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2930:
	/* 0x2930: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2935:
	/* 0x2935: cmp    r12,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 7ULL);
x86_l_2939:
	/* 0x2939: jb     2a95 <generic_kprobe_process_event+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10901ULL;
	}
x86_l_293f:
	/* 0x293f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2944:
	/* 0x2944: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2948:
	/* 0x2948: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_294d:
	/* 0x294d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2953:
	/* 0x2953: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2958:
	/* 0x2958: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_295d:
	/* 0x295d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2962:
	/* 0x2962: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2964:
	/* 0x2964: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2969:
	/* 0x2969: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_296b:
	/* 0x296b: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_296d:
	/* 0x296d: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2972:
	/* 0x2972: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2977:
	/* 0x2977: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_297e:
	/* 0x297e: ja     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29bd;
	}
x86_l_2980:
	/* 0x2980: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2988:
	/* 0x2988: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_298d:
	/* 0x298d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2993:
	/* 0x2993: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2996:
	/* 0x2996: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_299b:
	/* 0x299b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29a0:
	/* 0x29a0: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_29a5:
	/* 0x29a5: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_29a8:
	/* 0x29a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29aa:
	/* 0x29aa: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_29af:
	/* 0x29af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29b1:
	/* 0x29b1: js     29bd <generic_kprobe_process_event+0x29bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29bd;
	}
x86_l_29b3:
	/* 0x29b3: add    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_29b8:
	/* 0x29b8: jmp    2a95 <generic_kprobe_process_event+0x2a95> */
	return 10901ULL;
x86_l_29bd:
	/* 0x29bd: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29c2:
	/* 0x29c2: mov    DWORD PTR [r13+rax*1+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_29c7:
	/* 0x29c7: jmp    2c33 <generic_kprobe_process_event+0x2c33> */
	return 11315ULL;
x86_l_29cc:
	/* 0x29cc: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29cf:
	/* 0x29cf: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_29d4:
	/* 0x29d4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29d9:
	/* 0x29d9: test   BYTE PTR [rsp+0x50],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383696ULL);
x86_l_29de:
	/* 0x29de: je     2a95 <generic_kprobe_process_event+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10901ULL;
	}
x86_l_29e4:
	/* 0x29e4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_29e9:
	/* 0x29e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29eb:
	/* 0x29eb: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_29ef:
	/* 0x29ef: jne    29f5 <generic_kprobe_process_event+0x29f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29f5;
	}
x86_l_29f1:
	/* 0x29f1: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29f5:
	/* 0x29f5: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29fa:
	/* 0x29fa: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fe:
	/* 0x29fe: mov    rdx,QWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
	return 10754ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10782ULL: goto x86_l_2a1e;
	case 10790ULL: goto x86_l_2a26;
	case 10797ULL: goto x86_l_2a2d;
	case 10799ULL: goto x86_l_2a2f;
	case 10807ULL: goto x86_l_2a37;
	case 10812ULL: goto x86_l_2a3c;
	case 10817ULL: goto x86_l_2a41;
	case 10819ULL: goto x86_l_2a43;
	case 10821ULL: goto x86_l_2a45;
	case 10824ULL: goto x86_l_2a48;
	case 10830ULL: goto x86_l_2a4e;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10844ULL: goto x86_l_2a5c;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10866ULL: goto x86_l_2a72;
	case 10871ULL: goto x86_l_2a77;
	case 10876ULL: goto x86_l_2a7c;
	case 10878ULL: goto x86_l_2a7e;
	case 10881ULL: goto x86_l_2a81;
	case 10887ULL: goto x86_l_2a87;
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10921ULL: goto x86_l_2aa9;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10937ULL: goto x86_l_2ab9;
	case 10943ULL: goto x86_l_2abf;
	case 10948ULL: goto x86_l_2ac4;
	case 10951ULL: goto x86_l_2ac7;
	case 10957ULL: goto x86_l_2acd;
	case 10960ULL: goto x86_l_2ad0;
	case 10966ULL: goto x86_l_2ad6;
	case 10973ULL: goto x86_l_2add;
	case 10979ULL: goto x86_l_2ae3;
	case 10983ULL: goto x86_l_2ae7;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10995ULL: goto x86_l_2af3;
	case 10997ULL: goto x86_l_2af5;
	case 10999ULL: goto x86_l_2af7;
	case 11001ULL: goto x86_l_2af9;
	case 11004ULL: goto x86_l_2afc;
	case 11008ULL: goto x86_l_2b00;
	case 11011ULL: goto x86_l_2b03;
	case 11016ULL: goto x86_l_2b08;
	case 11022ULL: goto x86_l_2b0e;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11040ULL: goto x86_l_2b20;
	case 11048ULL: goto x86_l_2b28;
	case 11053ULL: goto x86_l_2b2d;
	case 11057ULL: goto x86_l_2b31;
	case 11064ULL: goto x86_l_2b38;
	case 11067ULL: goto x86_l_2b3b;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11084ULL: goto x86_l_2b4c;
	case 11090ULL: goto x86_l_2b52;
	case 11094ULL: goto x86_l_2b56;
	case 11099ULL: goto x86_l_2b5b;
	case 11104ULL: goto x86_l_2b60;
	case 11110ULL: goto x86_l_2b66;
	case 11113ULL: goto x86_l_2b69;
	case 11115ULL: goto x86_l_2b6b;
	case 11117ULL: goto x86_l_2b6d;
	case 11119ULL: goto x86_l_2b6f;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11149ULL: goto x86_l_2b8d;
	case 11154ULL: goto x86_l_2b92;
	case 11157ULL: goto x86_l_2b95;
	case 11163ULL: goto x86_l_2b9b;
	case 11166ULL: goto x86_l_2b9e;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11183ULL: goto x86_l_2baf;
	case 11190ULL: goto x86_l_2bb6;
	case 11194ULL: goto x86_l_2bba;
	case 11199ULL: goto x86_l_2bbf;
	case 11210ULL: goto x86_l_2bca;
	case 11217ULL: goto x86_l_2bd1;
	case 11219ULL: goto x86_l_2bd3;
	case 11224ULL: goto x86_l_2bd8;
	case 11232ULL: goto x86_l_2be0;
	case 11237ULL: goto x86_l_2be5;
	case 11239ULL: goto x86_l_2be7;
	case 11241ULL: goto x86_l_2be9;
	case 11248ULL: goto x86_l_2bf0;
	case 11254ULL: goto x86_l_2bf6;
	case 11259ULL: goto x86_l_2bfb;
	case 11267ULL: goto x86_l_2c03;
	case 11274ULL: goto x86_l_2c0a;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11291ULL: goto x86_l_2c1b;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11309ULL: goto x86_l_2c2d;
	case 11315ULL: goto x86_l_2c33;
	case 11320ULL: goto x86_l_2c38;
	case 11323ULL: goto x86_l_2c3b;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11343ULL: goto x86_l_2c4f;
	case 11348ULL: goto x86_l_2c54;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11364ULL: goto x86_l_2c64;
	case 11366ULL: goto x86_l_2c66;
	case 11373ULL: goto x86_l_2c6d;
	case 11376ULL: goto x86_l_2c70;
	case 11381ULL: goto x86_l_2c75;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11417ULL: goto x86_l_2c99;
	case 11425ULL: goto x86_l_2ca1;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11438ULL: goto x86_l_2cae;
	case 11440ULL: goto x86_l_2cb0;
	case 11447ULL: goto x86_l_2cb7;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11459ULL: goto x86_l_2cc3;
	case 11462ULL: goto x86_l_2cc6;
	case 11467ULL: goto x86_l_2ccb;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11478ULL: goto x86_l_2cd6;
	case 11482ULL: goto x86_l_2cda;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11499ULL: goto x86_l_2ceb;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11514ULL: goto x86_l_2cfa;
	case 11520ULL: goto x86_l_2d00;
	case 11523ULL: goto x86_l_2d03;
	case 11529ULL: goto x86_l_2d09;
	case 11536ULL: goto x86_l_2d10;
	case 11541ULL: goto x86_l_2d15;
	case 11545ULL: goto x86_l_2d19;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11559ULL: goto x86_l_2d27;
	case 11561ULL: goto x86_l_2d29;
	case 11563ULL: goto x86_l_2d2b;
	case 11565ULL: goto x86_l_2d2d;
	case 11567ULL: goto x86_l_2d2f;
	case 11571ULL: goto x86_l_2d33;
	case 11574ULL: goto x86_l_2d36;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11589ULL: goto x86_l_2d45;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11621ULL: goto x86_l_2d65;
	case 11625ULL: goto x86_l_2d69;
	case 11630ULL: goto x86_l_2d6e;
	case 11634ULL: goto x86_l_2d72;
	case 11640ULL: goto x86_l_2d78;
	case 11650ULL: goto x86_l_2d82;
	case 11654ULL: goto x86_l_2d86;
	case 11660ULL: goto x86_l_2d8c;
	case 11664ULL: goto x86_l_2d90;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11675ULL: goto x86_l_2d9b;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11694ULL: goto x86_l_2dae;
	case 11697ULL: goto x86_l_2db1;
	case 11702ULL: goto x86_l_2db6;
	case 11704ULL: goto x86_l_2db8;
	case 11707ULL: goto x86_l_2dbb;
	case 11713ULL: goto x86_l_2dc1;
	case 11718ULL: goto x86_l_2dc6;
	case 11721ULL: goto x86_l_2dc9;
	case 11723ULL: goto x86_l_2dcb;
	case 11725ULL: goto x86_l_2dcd;
	case 11727ULL: goto x86_l_2dcf;
	case 11730ULL: goto x86_l_2dd2;
	case 11732ULL: goto x86_l_2dd4;
	case 11735ULL: goto x86_l_2dd7;
	case 11737ULL: goto x86_l_2dd9;
	case 11744ULL: goto x86_l_2de0;
	case 11748ULL: goto x86_l_2de4;
	case 11750ULL: goto x86_l_2de6;
	case 11753ULL: goto x86_l_2de9;
	case 11755ULL: goto x86_l_2deb;
	case 11758ULL: goto x86_l_2dee;
	case 11760ULL: goto x86_l_2df0;
	case 11765ULL: goto x86_l_2df5;
	case 11767ULL: goto x86_l_2df7;
	case 11774ULL: goto x86_l_2dfe;
	case 11778ULL: goto x86_l_2e02;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11792ULL: goto x86_l_2e10;
	case 11797ULL: goto x86_l_2e15;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11809ULL: goto x86_l_2e21;
	case 11814ULL: goto x86_l_2e26;
	case 11821ULL: goto x86_l_2e2d;
	case 11826ULL: goto x86_l_2e32;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11837ULL: goto x86_l_2e3d;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11850ULL: goto x86_l_2e4a;
	case 11856ULL: goto x86_l_2e50;
	case 11866ULL: goto x86_l_2e5a;
	case 11870ULL: goto x86_l_2e5e;
	case 11876ULL: goto x86_l_2e64;
	case 11880ULL: goto x86_l_2e68;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11901ULL: goto x86_l_2e7d;
	case 11906ULL: goto x86_l_2e82;
	case 11910ULL: goto x86_l_2e86;
	case 11913ULL: goto x86_l_2e89;
	case 11918ULL: goto x86_l_2e8e;
	case 11920ULL: goto x86_l_2e90;
	case 11923ULL: goto x86_l_2e93;
	case 11929ULL: goto x86_l_2e99;
	case 11934ULL: goto x86_l_2e9e;
	case 11937ULL: goto x86_l_2ea1;
	case 11939ULL: goto x86_l_2ea3;
	case 11941ULL: goto x86_l_2ea5;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11948ULL: goto x86_l_2eac;
	case 11951ULL: goto x86_l_2eaf;
	case 11953ULL: goto x86_l_2eb1;
	case 11960ULL: goto x86_l_2eb8;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11971ULL: goto x86_l_2ec3;
	case 11974ULL: goto x86_l_2ec6;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11983ULL: goto x86_l_2ecf;
	case 11990ULL: goto x86_l_2ed6;
	case 11994ULL: goto x86_l_2eda;
	case 11996ULL: goto x86_l_2edc;
	case 12001ULL: goto x86_l_2ee1;
	case 12008ULL: goto x86_l_2ee8;
	case 12013ULL: goto x86_l_2eed;
	case 12015ULL: goto x86_l_2eef;
	case 12020ULL: goto x86_l_2ef4;
	case 12027ULL: goto x86_l_2efb;
	case 12032ULL: goto x86_l_2f00;
	case 12034ULL: goto x86_l_2f02;
	case 12039ULL: goto x86_l_2f07;
	case 12043ULL: goto x86_l_2f0b;
	case 12047ULL: goto x86_l_2f0f;
	case 12052ULL: goto x86_l_2f14;
	case 12056ULL: goto x86_l_2f18;
	case 12062ULL: goto x86_l_2f1e;
	case 12072ULL: goto x86_l_2f28;
	case 12076ULL: goto x86_l_2f2c;
	case 12082ULL: goto x86_l_2f32;
	case 12086ULL: goto x86_l_2f36;
	case 12089ULL: goto x86_l_2f39;
	case 12094ULL: goto x86_l_2f3e;
	case 12097ULL: goto x86_l_2f41;
	case 12102ULL: goto x86_l_2f46;
	case 12107ULL: goto x86_l_2f4b;
	case 12112ULL: goto x86_l_2f50;
	case 12116ULL: goto x86_l_2f54;
	case 12119ULL: goto x86_l_2f57;
	case 12124ULL: goto x86_l_2f5c;
	case 12126ULL: goto x86_l_2f5e;
	case 12129ULL: goto x86_l_2f61;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12143ULL: goto x86_l_2f6f;
	case 12145ULL: goto x86_l_2f71;
	case 12147ULL: goto x86_l_2f73;
	case 12149ULL: goto x86_l_2f75;
	case 12152ULL: goto x86_l_2f78;
	case 12154ULL: goto x86_l_2f7a;
	case 12157ULL: goto x86_l_2f7d;
	case 12159ULL: goto x86_l_2f7f;
	case 12166ULL: goto x86_l_2f86;
	case 12170ULL: goto x86_l_2f8a;
	case 12172ULL: goto x86_l_2f8c;
	case 12175ULL: goto x86_l_2f8f;
	case 12177ULL: goto x86_l_2f91;
	case 12180ULL: goto x86_l_2f94;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12189ULL: goto x86_l_2f9d;
	case 12196ULL: goto x86_l_2fa4;
	case 12200ULL: goto x86_l_2fa8;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12214ULL: goto x86_l_2fb6;
	case 12219ULL: goto x86_l_2fbb;
	case 12221ULL: goto x86_l_2fbd;
	case 12226ULL: goto x86_l_2fc2;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12240ULL: goto x86_l_2fd0;
	case 12245ULL: goto x86_l_2fd5;
	case 12249ULL: goto x86_l_2fd9;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12262ULL: goto x86_l_2fe6;
	case 12268ULL: goto x86_l_2fec;
	case 12278ULL: goto x86_l_2ff6;
	case 12282ULL: goto x86_l_2ffa;
	case 12288ULL: goto x86_l_3000;
	case 12292ULL: goto x86_l_3004;
	case 12295ULL: goto x86_l_3007;
	case 12300ULL: goto x86_l_300c;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12318ULL: goto x86_l_301e;
	case 12322ULL: goto x86_l_3022;
	case 12325ULL: goto x86_l_3025;
	case 12330ULL: goto x86_l_302a;
	case 12332ULL: goto x86_l_302c;
	case 12335ULL: goto x86_l_302f;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12349ULL: goto x86_l_303d;
	case 12351ULL: goto x86_l_303f;
	case 12353ULL: goto x86_l_3041;
	case 12355ULL: goto x86_l_3043;
	case 12358ULL: goto x86_l_3046;
	case 12360ULL: goto x86_l_3048;
	case 12363ULL: goto x86_l_304b;
	case 12365ULL: goto x86_l_304d;
	case 12372ULL: goto x86_l_3054;
	case 12376ULL: goto x86_l_3058;
	case 12378ULL: goto x86_l_305a;
	case 12381ULL: goto x86_l_305d;
	case 12383ULL: goto x86_l_305f;
	case 12386ULL: goto x86_l_3062;
	case 12388ULL: goto x86_l_3064;
	case 12393ULL: goto x86_l_3069;
	case 12395ULL: goto x86_l_306b;
	case 12402ULL: goto x86_l_3072;
	case 12406ULL: goto x86_l_3076;
	case 12408ULL: goto x86_l_3078;
	case 12413ULL: goto x86_l_307d;
	case 12420ULL: goto x86_l_3084;
	case 12425ULL: goto x86_l_3089;
	case 12427ULL: goto x86_l_308b;
	case 12432ULL: goto x86_l_3090;
	case 12439ULL: goto x86_l_3097;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a02:
	/* 0x2a02: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2a07:
	/* 0x2a07: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a0c:
	/* 0x2a0c: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a11:
	/* 0x2a11: mov    QWORD PTR [rsp+0x78],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2a16:
	/* 0x2a16: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a1e:
	/* 0x2a1e: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2a26:
	/* 0x2a26: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2a2d:
	/* 0x2a2d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a2f:
	/* 0x2a2f: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a37:
	/* 0x2a37: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2a3c:
	/* 0x2a3c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a41:
	/* 0x2a41: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a43:
	/* 0x2a43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a45:
	/* 0x2a45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a48:
	/* 0x2a48: je     2c1f <generic_kprobe_process_event+0x2c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c1f;
	}
x86_l_2a4e:
	/* 0x2a4e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2a50:
	/* 0x2a50: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a55:
	/* 0x2a55: mov    WORD PTR [rsp+0x5a],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 386547056645ULL);
x86_l_2a5c:
	/* 0x2a5c: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2a66:
	/* 0x2a66: mov    QWORD PTR [rsp+0x5c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    rdi,QWORD PTR [rip+0x248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a72:
	/* 0x2a72: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a77:
	/* 0x2a77: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a7c:
	/* 0x2a7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7e:
	/* 0x2a7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a81:
	/* 0x2a81: je     2bfb <generic_kprobe_process_event+0x2bfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bfb;
	}
x86_l_2a87:
	/* 0x2a87: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2a89:
	/* 0x2a89: jmp    2c1f <generic_kprobe_process_event+0x2c1f> */
	goto x86_l_2c1f;
x86_l_2a8e:
	/* 0x2a8e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a90:
	/* 0x2a90: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a95:
	/* 0x2a95: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a9a:
	/* 0x2a9a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    DWORD PTR [r13+rax*1+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2aa4:
	/* 0x2aa4: mov    DWORD PTR [r13+rax*1+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_2aa9:
	/* 0x2aa9: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2aad:
	/* 0x2aad: jmp    2c33 <generic_kprobe_process_event+0x2c33> */
	goto x86_l_2c33;
x86_l_2ab2:
	/* 0x2ab2: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2ab9:
	/* 0x2ab9: mov    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2abf:
	/* 0x2abf: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ac4:
	/* 0x2ac4: lea    ebx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ac7:
	/* 0x2ac7: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2acd:
	/* 0x2acd: add    rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ad0:
	/* 0x2ad0: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_2ad6:
	/* 0x2ad6: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_2add:
	/* 0x2add: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_2ae3:
	/* 0x2ae3: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2ae7:
	/* 0x2ae7: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2af0:
	/* 0x2af0: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2af3:
	/* 0x2af3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af5:
	/* 0x2af5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2af7:
	/* 0x2af7: js     2b08 <generic_kprobe_process_event+0x2b08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b08;
	}
x86_l_2af9:
	/* 0x2af9: mov    DWORD PTR [rbx],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2afc:
	/* 0x2afc: mov    DWORD PTR [rbx+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b00:
	/* 0x2b00: add    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b03:
	/* 0x2b03: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_2b08:
	/* 0x2b08: mov    DWORD PTR [rbx],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2b0e:
	/* 0x2b0e: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2b14:
	/* 0x2b14: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_2b19:
	/* 0x2b19: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2b20:
	/* 0x2b20: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b28:
	/* 0x2b28: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b2d:
	/* 0x2b2d: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b31:
	/* 0x2b31: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b38:
	/* 0x2b38: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b3b:
	/* 0x2b3b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b40:
	/* 0x2b40: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b45:
	/* 0x2b45: cmp    rbx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4095ULL);
x86_l_2b4c:
	/* 0x2b4c: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_2b52:
	/* 0x2b52: cmovb  r13,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_64, X86_CC_B);
x86_l_2b56:
	/* 0x2b56: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5b:
	/* 0x2b5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b60:
	/* 0x2b60: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2b66:
	/* 0x2b66: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2b69:
	/* 0x2b69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6b:
	/* 0x2b6b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b6d:
	/* 0x2b6d: js     2b85 <generic_kprobe_process_event+0x2b85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b85;
	}
x86_l_2b6f:
	/* 0x2b6f: mov    DWORD PTR [r12],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b73:
	/* 0x2b73: mov    DWORD PTR [r12+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b78:
	/* 0x2b78: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b7d:
	/* 0x2b7d: add    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b80:
	/* 0x2b80: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_2b85:
	/* 0x2b85: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2b8d:
	/* 0x2b8d: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_2b92:
	/* 0x2b92: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2b95:
	/* 0x2b95: je     2d50 <generic_kprobe_process_event+0x2d50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d50;
	}
x86_l_2b9b:
	/* 0x2b9b: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2b9e:
	/* 0x2b9e: je     2c43 <generic_kprobe_process_event+0x2c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c43;
	}
x86_l_2ba4:
	/* 0x2ba4: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2ba9:
	/* 0x2ba9: jne    2e17 <generic_kprobe_process_event+0x2e17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e17;
	}
x86_l_2baf:
	/* 0x2baf: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2bba:
	/* 0x2bba: jmp    2d61 <generic_kprobe_process_event+0x2d61> */
	goto x86_l_2d61;
x86_l_2bbf:
	/* 0x2bbf: mov    DWORD PTR [rsp+0xc8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459201ULL);
x86_l_2bca:
	/* 0x2bca: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2bd1:
	/* 0x2bd1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bd3:
	/* 0x2bd3: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2bd8:
	/* 0x2bd8: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2be0:
	/* 0x2be0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2be5:
	/* 0x2be5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2be7:
	/* 0x2be7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be9:
	/* 0x2be9: mov    DWORD PTR [rbp+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_2bf0:
	/* 0x2bf0: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2bf6:
	/* 0x2bf6: jmp    f58 <generic_kprobe_process_event+0xf58> */
	return 3928ULL;
x86_l_2bfb:
	/* 0x2bfb: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_2c03:
	/* 0x2c03: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2c0a:
	/* 0x2c0a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c0c:
	/* 0x2c0c: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c11:
	/* 0x2c11: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c16:
	/* 0x2c16: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c1b:
	/* 0x2c1b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c1d:
	/* 0x2c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1f:
	/* 0x2c1f: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c24:
	/* 0x2c24: mov    DWORD PTR [r13+rax*1+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_2c2d:
	/* 0x2c2d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2c33:
	/* 0x2c33: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c38:
	/* 0x2c38: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_2c3b:
	/* 0x2c3b: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_2c3e:
	/* 0x2c3e: jmp    ccd <generic_kprobe_process_event+0xccd> */
	return 3277ULL;
x86_l_2c43:
	/* 0x2c43: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c48:
	/* 0x2c48: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2c4f:
	/* 0x2c4f: jmp    2d5c <generic_kprobe_process_event+0x2d5c> */
	goto x86_l_2d5c;
x86_l_2c54:
	/* 0x2c54: lea    rax,[rbx+0x5e60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_2c5b:
	/* 0x2c5b: jmp    2c6d <generic_kprobe_process_event+0x2c6d> */
	goto x86_l_2c6d;
x86_l_2c5d:
	/* 0x2c5d: lea    rax,[rbx+0x5e68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2c64:
	/* 0x2c64: jmp    2c6d <generic_kprobe_process_event+0x2c6d> */
	goto x86_l_2c6d;
x86_l_2c66:
	/* 0x2c66: lea    rax,[rbx+0x5e50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c70:
	/* 0x2c70: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c75:
	/* 0x2c75: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c7d:
	/* 0x2c7d: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c82:
	/* 0x2c82: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c87:
	/* 0x2c87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c8c:
	/* 0x2c8c: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_2c92:
	/* 0x2c92: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c97:
	/* 0x2c97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c99:
	/* 0x2c99: mov    r13,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2ca1:
	/* 0x2ca1: test   r12b,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 32ULL);
x86_l_2ca5:
	/* 0x2ca5: je     2d09 <generic_kprobe_process_event+0x2d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d09;
	}
x86_l_2ca7:
	/* 0x2ca7: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_2cae:
	/* 0x2cae: jb     2ce4 <generic_kprobe_process_event+0x2ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ce4;
	}
x86_l_2cb0:
	/* 0x2cb0: mov    DWORD PTR [rbp+0x0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2cb7:
	/* 0x2cb7: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2cbb:
	/* 0x2cbb: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cc0:
	/* 0x2cc0: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2cc3:
	/* 0x2cc3: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_2cc6:
	/* 0x2cc6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ccb:
	/* 0x2ccb: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2cce:
	/* 0x2cce: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 11475ULL);
	__x86_sim_call_depth++;
	return 14263ULL;
x86_l_2cd3:
	/* 0x2cd3: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2cd6:
	/* 0x2cd6: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2cda:
	/* 0x2cda: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cdf:
	/* 0x2cdf: jmp    f62 <generic_kprobe_process_event+0xf62> */
	return 3938ULL;
x86_l_2ce4:
	/* 0x2ce4: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2ceb:
	/* 0x2ceb: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf2:
	/* 0x2cf2: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cf7:
	/* 0x2cf7: lea    ebp,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cfa:
	/* 0x2cfa: and    ebp,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2d00:
	/* 0x2d00: add    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d03:
	/* 0x2d03: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_2d09:
	/* 0x2d09: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_2d10:
	/* 0x2d10: mov    ebx,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4095ULL);
x86_l_2d15:
	/* 0x2d15: cmovb  rbx,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2d19:
	/* 0x2d19: lea    rdi,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d1d:
	/* 0x2d1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d22:
	/* 0x2d22: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d27:
	/* 0x2d27: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2d29:
	/* 0x2d29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2b:
	/* 0x2d2b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d2d:
	/* 0x2d2d: js     2d3e <generic_kprobe_process_event+0x2d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2d3e;
	}
x86_l_2d2f:
	/* 0x2d2f: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d33:
	/* 0x2d33: mov    DWORD PTR [rbp+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d36:
	/* 0x2d36: add    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d39:
	/* 0x2d39: jmp    f58 <generic_kprobe_process_event+0xf58> */
	return 3928ULL;
x86_l_2d3e:
	/* 0x2d3e: mov    DWORD PTR [rbp+0x0],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2d45:
	/* 0x2d45: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2d4b:
	/* 0x2d4b: jmp    f58 <generic_kprobe_process_event+0xf58> */
	return 3928ULL;
x86_l_2d50:
	/* 0x2d50: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d55:
	/* 0x2d55: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d61:
	/* 0x2d61: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d65:
	/* 0x2d65: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d69:
	/* 0x2d69: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2d6e:
	/* 0x2d6e: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2d72:
	/* 0x2d72: ja     3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13410ULL;
	}
x86_l_2d78:
	/* 0x2d78: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2d82:
	/* 0x2d82: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2d86:
	/* 0x2d86: jae    3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13410ULL;
	}
x86_l_2d8c:
	/* 0x2d8c: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2d90:
	/* 0x2d90: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d93:
	/* 0x2d93: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d98:
	/* 0x2d98: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d9b:
	/* 0x2d9b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2da0:
	/* 0x2da0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2da5:
	/* 0x2da5: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2daa:
	/* 0x2daa: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dae:
	/* 0x2dae: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2db1:
	/* 0x2db1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2db6:
	/* 0x2db6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db8:
	/* 0x2db8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2dbb:
	/* 0x2dbb: js     3296 <generic_kprobe_process_event+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12950ULL;
	}
x86_l_2dc1:
	/* 0x2dc1: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2dc6:
	/* 0x2dc6: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2dc9:
	/* 0x2dc9: jg     2de6 <generic_kprobe_process_event+0x2de6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2de6;
	}
x86_l_2dcb:
	/* 0x2dcb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dcd:
	/* 0x2dcd: je     2e04 <generic_kprobe_process_event+0x2e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e04;
	}
x86_l_2dcf:
	/* 0x2dcf: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2dd2:
	/* 0x2dd2: je     2e04 <generic_kprobe_process_event+0x2e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e04;
	}
x86_l_2dd4:
	/* 0x2dd4: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2dd7:
	/* 0x2dd7: jne    2e34 <generic_kprobe_process_event+0x2e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e34;
	}
x86_l_2dd9:
	/* 0x2dd9: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2de0:
	/* 0x2de0: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2de4:
	/* 0x2de4: jmp    2e39 <generic_kprobe_process_event+0x2e39> */
	goto x86_l_2e39;
x86_l_2de6:
	/* 0x2de6: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2de9:
	/* 0x2de9: je     2e21 <generic_kprobe_process_event+0x2e21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e21;
	}
x86_l_2deb:
	/* 0x2deb: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2dee:
	/* 0x2dee: je     2e04 <generic_kprobe_process_event+0x2e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e04;
	}
x86_l_2df0:
	/* 0x2df0: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2df5:
	/* 0x2df5: jne    2e34 <generic_kprobe_process_event+0x2e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e34;
	}
x86_l_2df7:
	/* 0x2df7: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2dfe:
	/* 0x2dfe: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2e02:
	/* 0x2e02: jmp    2e39 <generic_kprobe_process_event+0x2e39> */
	goto x86_l_2e39;
x86_l_2e04:
	/* 0x2e04: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e09:
	/* 0x2e09: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2e10:
	/* 0x2e10: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2e15:
	/* 0x2e15: jmp    2e39 <generic_kprobe_process_event+0x2e39> */
	goto x86_l_2e39;
x86_l_2e17:
	/* 0x2e17: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2e1c:
	/* 0x2e1c: jmp    2d61 <generic_kprobe_process_event+0x2d61> */
	goto x86_l_2d61;
x86_l_2e21:
	/* 0x2e21: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e26:
	/* 0x2e26: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2e2d:
	/* 0x2e2d: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2e32:
	/* 0x2e32: jmp    2e39 <generic_kprobe_process_event+0x2e39> */
	goto x86_l_2e39;
x86_l_2e34:
	/* 0x2e34: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2e39:
	/* 0x2e39: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e3d:
	/* 0x2e3d: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e41:
	/* 0x2e41: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2e46:
	/* 0x2e46: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2e4a:
	/* 0x2e4a: ja     3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13410ULL;
	}
x86_l_2e50:
	/* 0x2e50: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2e5a:
	/* 0x2e5a: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2e5e:
	/* 0x2e5e: jae    3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13410ULL;
	}
x86_l_2e64:
	/* 0x2e64: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2e68:
	/* 0x2e68: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e6b:
	/* 0x2e6b: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e70:
	/* 0x2e70: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e73:
	/* 0x2e73: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2e78:
	/* 0x2e78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e82:
	/* 0x2e82: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e86:
	/* 0x2e86: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e89:
	/* 0x2e89: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2e8e:
	/* 0x2e8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e90:
	/* 0x2e90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e93:
	/* 0x2e93: js     3296 <generic_kprobe_process_event+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12950ULL;
	}
x86_l_2e99:
	/* 0x2e99: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2e9e:
	/* 0x2e9e: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2ea1:
	/* 0x2ea1: jg     2ebe <generic_kprobe_process_event+0x2ebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ebe;
	}
x86_l_2ea3:
	/* 0x2ea3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ea5:
	/* 0x2ea5: je     2edc <generic_kprobe_process_event+0x2edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2edc;
	}
x86_l_2ea7:
	/* 0x2ea7: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2eaa:
	/* 0x2eaa: je     2edc <generic_kprobe_process_event+0x2edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2edc;
	}
x86_l_2eac:
	/* 0x2eac: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2eaf:
	/* 0x2eaf: jne    2f02 <generic_kprobe_process_event+0x2f02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f02;
	}
x86_l_2eb1:
	/* 0x2eb1: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2eb8:
	/* 0x2eb8: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2ebc:
	/* 0x2ebc: jmp    2f07 <generic_kprobe_process_event+0x2f07> */
	goto x86_l_2f07;
x86_l_2ebe:
	/* 0x2ebe: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2ec1:
	/* 0x2ec1: je     2eef <generic_kprobe_process_event+0x2eef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eef;
	}
x86_l_2ec3:
	/* 0x2ec3: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2ec6:
	/* 0x2ec6: je     2edc <generic_kprobe_process_event+0x2edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2edc;
	}
x86_l_2ec8:
	/* 0x2ec8: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2ecd:
	/* 0x2ecd: jne    2f02 <generic_kprobe_process_event+0x2f02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f02;
	}
x86_l_2ecf:
	/* 0x2ecf: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2ed6:
	/* 0x2ed6: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2eda:
	/* 0x2eda: jmp    2f07 <generic_kprobe_process_event+0x2f07> */
	goto x86_l_2f07;
x86_l_2edc:
	/* 0x2edc: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ee1:
	/* 0x2ee1: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2ee8:
	/* 0x2ee8: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2eed:
	/* 0x2eed: jmp    2f07 <generic_kprobe_process_event+0x2f07> */
	goto x86_l_2f07;
x86_l_2eef:
	/* 0x2eef: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ef4:
	/* 0x2ef4: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2efb:
	/* 0x2efb: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f00:
	/* 0x2f00: jmp    2f07 <generic_kprobe_process_event+0x2f07> */
	goto x86_l_2f07;
x86_l_2f02:
	/* 0x2f02: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2f07:
	/* 0x2f07: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f0b:
	/* 0x2f0b: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f0f:
	/* 0x2f0f: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2f14:
	/* 0x2f14: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2f18:
	/* 0x2f18: ja     3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13410ULL;
	}
x86_l_2f1e:
	/* 0x2f1e: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2f28:
	/* 0x2f28: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2f2c:
	/* 0x2f2c: jae    3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13410ULL;
	}
x86_l_2f32:
	/* 0x2f32: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2f36:
	/* 0x2f36: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f39:
	/* 0x2f39: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f3e:
	/* 0x2f3e: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f41:
	/* 0x2f41: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2f46:
	/* 0x2f46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f4b:
	/* 0x2f4b: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f50:
	/* 0x2f50: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f54:
	/* 0x2f54: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f57:
	/* 0x2f57: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f5c:
	/* 0x2f5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f5e:
	/* 0x2f5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f61:
	/* 0x2f61: js     3296 <generic_kprobe_process_event+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12950ULL;
	}
x86_l_2f67:
	/* 0x2f67: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2f6c:
	/* 0x2f6c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2f6f:
	/* 0x2f6f: jg     2f8c <generic_kprobe_process_event+0x2f8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f8c;
	}
x86_l_2f71:
	/* 0x2f71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f73:
	/* 0x2f73: je     2faa <generic_kprobe_process_event+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2faa;
	}
x86_l_2f75:
	/* 0x2f75: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2f78:
	/* 0x2f78: je     2faa <generic_kprobe_process_event+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2faa;
	}
x86_l_2f7a:
	/* 0x2f7a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2f7d:
	/* 0x2f7d: jne    2fd0 <generic_kprobe_process_event+0x2fd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fd0;
	}
x86_l_2f7f:
	/* 0x2f7f: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2f86:
	/* 0x2f86: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2f8a:
	/* 0x2f8a: jmp    2fd5 <generic_kprobe_process_event+0x2fd5> */
	goto x86_l_2fd5;
x86_l_2f8c:
	/* 0x2f8c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2f8f:
	/* 0x2f8f: je     2fbd <generic_kprobe_process_event+0x2fbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fbd;
	}
x86_l_2f91:
	/* 0x2f91: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2f94:
	/* 0x2f94: je     2faa <generic_kprobe_process_event+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2faa;
	}
x86_l_2f96:
	/* 0x2f96: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2f9b:
	/* 0x2f9b: jne    2fd0 <generic_kprobe_process_event+0x2fd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fd0;
	}
x86_l_2f9d:
	/* 0x2f9d: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2fa4:
	/* 0x2fa4: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2fa8:
	/* 0x2fa8: jmp    2fd5 <generic_kprobe_process_event+0x2fd5> */
	goto x86_l_2fd5;
x86_l_2faa:
	/* 0x2faa: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2faf:
	/* 0x2faf: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2fb6:
	/* 0x2fb6: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2fbb:
	/* 0x2fbb: jmp    2fd5 <generic_kprobe_process_event+0x2fd5> */
	goto x86_l_2fd5;
x86_l_2fbd:
	/* 0x2fbd: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2fc2:
	/* 0x2fc2: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2fce:
	/* 0x2fce: jmp    2fd5 <generic_kprobe_process_event+0x2fd5> */
	goto x86_l_2fd5;
x86_l_2fd0:
	/* 0x2fd0: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2fd5:
	/* 0x2fd5: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2fd9:
	/* 0x2fd9: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fdd:
	/* 0x2fdd: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2fe2:
	/* 0x2fe2: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2fe6:
	/* 0x2fe6: ja     3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13410ULL;
	}
x86_l_2fec:
	/* 0x2fec: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2ff6:
	/* 0x2ff6: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2ffa:
	/* 0x2ffa: jae    3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13410ULL;
	}
x86_l_3000:
	/* 0x3000: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3004:
	/* 0x3004: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3007:
	/* 0x3007: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_300c:
	/* 0x300c: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_300f:
	/* 0x300f: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3014:
	/* 0x3014: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3019:
	/* 0x3019: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_301e:
	/* 0x301e: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3022:
	/* 0x3022: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3025:
	/* 0x3025: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_302a:
	/* 0x302a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_302c:
	/* 0x302c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_302f:
	/* 0x302f: js     3296 <generic_kprobe_process_event+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12950ULL;
	}
x86_l_3035:
	/* 0x3035: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_303a:
	/* 0x303a: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_303d:
	/* 0x303d: jg     305a <generic_kprobe_process_event+0x305a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_305a;
	}
x86_l_303f:
	/* 0x303f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3041:
	/* 0x3041: je     3078 <generic_kprobe_process_event+0x3078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3078;
	}
x86_l_3043:
	/* 0x3043: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3046:
	/* 0x3046: je     3078 <generic_kprobe_process_event+0x3078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3078;
	}
x86_l_3048:
	/* 0x3048: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_304b:
	/* 0x304b: jne    309e <generic_kprobe_process_event+0x309e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12446ULL;
	}
x86_l_304d:
	/* 0x304d: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_3054:
	/* 0x3054: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_3058:
	/* 0x3058: jmp    30a3 <generic_kprobe_process_event+0x30a3> */
	return 12451ULL;
x86_l_305a:
	/* 0x305a: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_305d:
	/* 0x305d: je     308b <generic_kprobe_process_event+0x308b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_308b;
	}
x86_l_305f:
	/* 0x305f: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3062:
	/* 0x3062: je     3078 <generic_kprobe_process_event+0x3078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3078;
	}
x86_l_3064:
	/* 0x3064: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_3069:
	/* 0x3069: jne    309e <generic_kprobe_process_event+0x309e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12446ULL;
	}
x86_l_306b:
	/* 0x306b: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3072:
	/* 0x3072: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3076:
	/* 0x3076: jmp    30a3 <generic_kprobe_process_event+0x30a3> */
	return 12451ULL;
x86_l_3078:
	/* 0x3078: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_307d:
	/* 0x307d: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3084:
	/* 0x3084: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3089:
	/* 0x3089: jmp    30a3 <generic_kprobe_process_event+0x30a3> */
	return 12451ULL;
x86_l_308b:
	/* 0x308b: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3090:
	/* 0x3090: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3097:
	/* 0x3097: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
	return 12444ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12444ULL: goto x86_l_309c;
	case 12446ULL: goto x86_l_309e;
	case 12451ULL: goto x86_l_30a3;
	case 12455ULL: goto x86_l_30a7;
	case 12459ULL: goto x86_l_30ab;
	case 12464ULL: goto x86_l_30b0;
	case 12468ULL: goto x86_l_30b4;
	case 12474ULL: goto x86_l_30ba;
	case 12484ULL: goto x86_l_30c4;
	case 12488ULL: goto x86_l_30c8;
	case 12494ULL: goto x86_l_30ce;
	case 12498ULL: goto x86_l_30d2;
	case 12501ULL: goto x86_l_30d5;
	case 12506ULL: goto x86_l_30da;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12519ULL: goto x86_l_30e7;
	case 12524ULL: goto x86_l_30ec;
	case 12528ULL: goto x86_l_30f0;
	case 12531ULL: goto x86_l_30f3;
	case 12536ULL: goto x86_l_30f8;
	case 12538ULL: goto x86_l_30fa;
	case 12541ULL: goto x86_l_30fd;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12555ULL: goto x86_l_310b;
	case 12557ULL: goto x86_l_310d;
	case 12559ULL: goto x86_l_310f;
	case 12561ULL: goto x86_l_3111;
	case 12564ULL: goto x86_l_3114;
	case 12566ULL: goto x86_l_3116;
	case 12569ULL: goto x86_l_3119;
	case 12571ULL: goto x86_l_311b;
	case 12578ULL: goto x86_l_3122;
	case 12582ULL: goto x86_l_3126;
	case 12584ULL: goto x86_l_3128;
	case 12587ULL: goto x86_l_312b;
	case 12589ULL: goto x86_l_312d;
	case 12592ULL: goto x86_l_3130;
	case 12594ULL: goto x86_l_3132;
	case 12599ULL: goto x86_l_3137;
	case 12601ULL: goto x86_l_3139;
	case 12608ULL: goto x86_l_3140;
	case 12612ULL: goto x86_l_3144;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12633ULL: goto x86_l_3159;
	case 12638ULL: goto x86_l_315e;
	case 12645ULL: goto x86_l_3165;
	case 12650ULL: goto x86_l_316a;
	case 12652ULL: goto x86_l_316c;
	case 12657ULL: goto x86_l_3171;
	case 12661ULL: goto x86_l_3175;
	case 12665ULL: goto x86_l_3179;
	case 12670ULL: goto x86_l_317e;
	case 12674ULL: goto x86_l_3182;
	case 12680ULL: goto x86_l_3188;
	case 12690ULL: goto x86_l_3192;
	case 12694ULL: goto x86_l_3196;
	case 12700ULL: goto x86_l_319c;
	case 12704ULL: goto x86_l_31a0;
	case 12707ULL: goto x86_l_31a3;
	case 12712ULL: goto x86_l_31a8;
	case 12715ULL: goto x86_l_31ab;
	case 12720ULL: goto x86_l_31b0;
	case 12725ULL: goto x86_l_31b5;
	case 12730ULL: goto x86_l_31ba;
	case 12734ULL: goto x86_l_31be;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12744ULL: goto x86_l_31c8;
	case 12747ULL: goto x86_l_31cb;
	case 12753ULL: goto x86_l_31d1;
	case 12758ULL: goto x86_l_31d6;
	case 12761ULL: goto x86_l_31d9;
	case 12763ULL: goto x86_l_31db;
	case 12765ULL: goto x86_l_31dd;
	case 12767ULL: goto x86_l_31df;
	case 12770ULL: goto x86_l_31e2;
	case 12772ULL: goto x86_l_31e4;
	case 12775ULL: goto x86_l_31e7;
	case 12777ULL: goto x86_l_31e9;
	case 12784ULL: goto x86_l_31f0;
	case 12788ULL: goto x86_l_31f4;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12795ULL: goto x86_l_31fb;
	case 12798ULL: goto x86_l_31fe;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12807ULL: goto x86_l_3207;
	case 12814ULL: goto x86_l_320e;
	case 12818ULL: goto x86_l_3212;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12832ULL: goto x86_l_3220;
	case 12837ULL: goto x86_l_3225;
	case 12839ULL: goto x86_l_3227;
	case 12844ULL: goto x86_l_322c;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12867ULL: goto x86_l_3243;
	case 12871ULL: goto x86_l_3247;
	case 12876ULL: goto x86_l_324c;
	case 12880ULL: goto x86_l_3250;
	case 12886ULL: goto x86_l_3256;
	case 12896ULL: goto x86_l_3260;
	case 12900ULL: goto x86_l_3264;
	case 12906ULL: goto x86_l_326a;
	case 12910ULL: goto x86_l_326e;
	case 12913ULL: goto x86_l_3271;
	case 12918ULL: goto x86_l_3276;
	case 12921ULL: goto x86_l_3279;
	case 12926ULL: goto x86_l_327e;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12940ULL: goto x86_l_328c;
	case 12943ULL: goto x86_l_328f;
	case 12948ULL: goto x86_l_3294;
	case 12950ULL: goto x86_l_3296;
	case 12952ULL: goto x86_l_3298;
	case 12960ULL: goto x86_l_32a0;
	case 12964ULL: goto x86_l_32a4;
	case 12969ULL: goto x86_l_32a9;
	case 12974ULL: goto x86_l_32ae;
	case 12981ULL: goto x86_l_32b5;
	case 12985ULL: goto x86_l_32b9;
	case 12990ULL: goto x86_l_32be;
	case 12995ULL: goto x86_l_32c3;
	case 12998ULL: goto x86_l_32c6;
	case 13003ULL: goto x86_l_32cb;
	case 13005ULL: goto x86_l_32cd;
	case 13009ULL: goto x86_l_32d1;
	case 13013ULL: goto x86_l_32d5;
	case 13018ULL: goto x86_l_32da;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13031ULL: goto x86_l_32e7;
	case 13033ULL: goto x86_l_32e9;
	case 13037ULL: goto x86_l_32ed;
	case 13039ULL: goto x86_l_32ef;
	case 13043ULL: goto x86_l_32f3;
	case 13046ULL: goto x86_l_32f6;
	case 13052ULL: goto x86_l_32fc;
	case 13057ULL: goto x86_l_3301;
	case 13066ULL: goto x86_l_330a;
	case 13070ULL: goto x86_l_330e;
	case 13075ULL: goto x86_l_3313;
	case 13079ULL: goto x86_l_3317;
	case 13084ULL: goto x86_l_331c;
	case 13089ULL: goto x86_l_3321;
	case 13094ULL: goto x86_l_3326;
	case 13096ULL: goto x86_l_3328;
	case 13100ULL: goto x86_l_332c;
	case 13104ULL: goto x86_l_3330;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	case 13125ULL: goto x86_l_3345;
	case 13134ULL: goto x86_l_334e;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13147ULL: goto x86_l_335b;
	case 13152ULL: goto x86_l_3360;
	case 13157ULL: goto x86_l_3365;
	case 13162ULL: goto x86_l_336a;
	case 13164ULL: goto x86_l_336c;
	case 13168ULL: goto x86_l_3370;
	case 13172ULL: goto x86_l_3374;
	case 13176ULL: goto x86_l_3378;
	case 13181ULL: goto x86_l_337d;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13193ULL: goto x86_l_3389;
	case 13195ULL: goto x86_l_338b;
	case 13200ULL: goto x86_l_3390;
	case 13207ULL: goto x86_l_3397;
	case 13212ULL: goto x86_l_339c;
	case 13216ULL: goto x86_l_33a0;
	case 13220ULL: goto x86_l_33a4;
	case 13226ULL: goto x86_l_33aa;
	case 13232ULL: goto x86_l_33b0;
	case 13239ULL: goto x86_l_33b7;
	case 13247ULL: goto x86_l_33bf;
	case 13252ULL: goto x86_l_33c4;
	case 13257ULL: goto x86_l_33c9;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13271ULL: goto x86_l_33d7;
	case 13273ULL: goto x86_l_33d9;
	case 13281ULL: goto x86_l_33e1;
	case 13284ULL: goto x86_l_33e4;
	case 13286ULL: goto x86_l_33e6;
	case 13290ULL: goto x86_l_33ea;
	case 13295ULL: goto x86_l_33ef;
	case 13300ULL: goto x86_l_33f4;
	case 13305ULL: goto x86_l_33f9;
	case 13313ULL: goto x86_l_3401;
	case 13317ULL: goto x86_l_3405;
	case 13322ULL: goto x86_l_340a;
	case 13324ULL: goto x86_l_340c;
	case 13332ULL: goto x86_l_3414;
	case 13337ULL: goto x86_l_3419;
	case 13345ULL: goto x86_l_3421;
	case 13348ULL: goto x86_l_3424;
	case 13353ULL: goto x86_l_3429;
	case 13357ULL: goto x86_l_342d;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13369ULL: goto x86_l_3439;
	case 13373ULL: goto x86_l_343d;
	case 13381ULL: goto x86_l_3445;
	case 13384ULL: goto x86_l_3448;
	case 13389ULL: goto x86_l_344d;
	case 13392ULL: goto x86_l_3450;
	case 13397ULL: goto x86_l_3455;
	case 13399ULL: goto x86_l_3457;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13418ULL: goto x86_l_346a;
	case 13423ULL: goto x86_l_346f;
	case 13429ULL: goto x86_l_3475;
	case 13431ULL: goto x86_l_3477;
	case 13434ULL: goto x86_l_347a;
	case 13436ULL: goto x86_l_347c;
	case 13439ULL: goto x86_l_347f;
	case 13441ULL: goto x86_l_3481;
	case 13444ULL: goto x86_l_3484;
	case 13450ULL: goto x86_l_348a;
	case 13453ULL: goto x86_l_348d;
	case 13459ULL: goto x86_l_3493;
	case 13462ULL: goto x86_l_3496;
	case 13468ULL: goto x86_l_349c;
	case 13471ULL: goto x86_l_349f;
	case 13477ULL: goto x86_l_34a5;
	case 13484ULL: goto x86_l_34ac;
	case 13489ULL: goto x86_l_34b1;
	case 13492ULL: goto x86_l_34b4;
	case 13494ULL: goto x86_l_34b6;
	case 13497ULL: goto x86_l_34b9;
	case 13499ULL: goto x86_l_34bb;
	case 13501ULL: goto x86_l_34bd;
	case 13507ULL: goto x86_l_34c3;
	case 13510ULL: goto x86_l_34c6;
	case 13516ULL: goto x86_l_34cc;
	case 13520ULL: goto x86_l_34d0;
	case 13525ULL: goto x86_l_34d5;
	case 13528ULL: goto x86_l_34d8;
	case 13530ULL: goto x86_l_34da;
	case 13533ULL: goto x86_l_34dd;
	case 13535ULL: goto x86_l_34df;
	case 13538ULL: goto x86_l_34e2;
	case 13544ULL: goto x86_l_34e8;
	case 13548ULL: goto x86_l_34ec;
	case 13553ULL: goto x86_l_34f1;
	case 13556ULL: goto x86_l_34f4;
	case 13558ULL: goto x86_l_34f6;
	case 13561ULL: goto x86_l_34f9;
	case 13563ULL: goto x86_l_34fb;
	case 13566ULL: goto x86_l_34fe;
	case 13572ULL: goto x86_l_3504;
	case 13576ULL: goto x86_l_3508;
	case 13578ULL: goto x86_l_350a;
	case 13581ULL: goto x86_l_350d;
	case 13583ULL: goto x86_l_350f;
	case 13586ULL: goto x86_l_3512;
	case 13588ULL: goto x86_l_3514;
	case 13592ULL: goto x86_l_3518;
	case 13594ULL: goto x86_l_351a;
	case 13597ULL: goto x86_l_351d;
	case 13599ULL: goto x86_l_351f;
	case 13602ULL: goto x86_l_3522;
	case 13604ULL: goto x86_l_3524;
	case 13608ULL: goto x86_l_3528;
	case 13610ULL: goto x86_l_352a;
	case 13613ULL: goto x86_l_352d;
	case 13615ULL: goto x86_l_352f;
	case 13618ULL: goto x86_l_3532;
	case 13620ULL: goto x86_l_3534;
	case 13624ULL: goto x86_l_3538;
	case 13626ULL: goto x86_l_353a;
	case 13629ULL: goto x86_l_353d;
	case 13631ULL: goto x86_l_353f;
	case 13634ULL: goto x86_l_3542;
	case 13636ULL: goto x86_l_3544;
	case 13640ULL: goto x86_l_3548;
	case 13642ULL: goto x86_l_354a;
	case 13646ULL: goto x86_l_354e;
	case 13648ULL: goto x86_l_3550;
	case 13652ULL: goto x86_l_3554;
	case 13654ULL: goto x86_l_3556;
	case 13658ULL: goto x86_l_355a;
	case 13660ULL: goto x86_l_355c;
	case 13664ULL: goto x86_l_3560;
	case 13666ULL: goto x86_l_3562;
	case 13670ULL: goto x86_l_3566;
	case 13672ULL: goto x86_l_3568;
	case 13676ULL: goto x86_l_356c;
	case 13678ULL: goto x86_l_356e;
	case 13682ULL: goto x86_l_3572;
	case 13684ULL: goto x86_l_3574;
	case 13688ULL: goto x86_l_3578;
	case 13693ULL: goto x86_l_357d;
	case 13695ULL: goto x86_l_357f;
	case 13700ULL: goto x86_l_3584;
	case 13701ULL: goto x86_l_3585;
	case 13706ULL: goto x86_l_358a;
	case 13709ULL: goto x86_l_358d;
	case 13711ULL: goto x86_l_358f;
	case 13713ULL: goto x86_l_3591;
	case 13714ULL: goto x86_l_3592;
	case 13715ULL: goto x86_l_3593;
	case 13718ULL: goto x86_l_3596;
	case 13721ULL: goto x86_l_3599;
	case 13728ULL: goto x86_l_35a0;
	case 13730ULL: goto x86_l_35a2;
	case 13734ULL: goto x86_l_35a6;
	case 13738ULL: goto x86_l_35aa;
	case 13741ULL: goto x86_l_35ad;
	case 13744ULL: goto x86_l_35b0;
	case 13746ULL: goto x86_l_35b2;
	case 13753ULL: goto x86_l_35b9;
	case 13755ULL: goto x86_l_35bb;
	case 13757ULL: goto x86_l_35bd;
	case 13761ULL: goto x86_l_35c1;
	case 13763ULL: goto x86_l_35c3;
	case 13768ULL: goto x86_l_35c8;
	case 13773ULL: goto x86_l_35cd;
	case 13775ULL: goto x86_l_35cf;
	case 13780ULL: goto x86_l_35d4;
	case 13785ULL: goto x86_l_35d9;
	case 13788ULL: goto x86_l_35dc;
	case 13792ULL: goto x86_l_35e0;
	case 13795ULL: goto x86_l_35e3;
	case 13800ULL: goto x86_l_35e8;
	case 13802ULL: goto x86_l_35ea;
	case 13804ULL: goto x86_l_35ec;
	case 13809ULL: goto x86_l_35f1;
	case 13811ULL: goto x86_l_35f3;
	case 13813ULL: goto x86_l_35f5;
	case 13817ULL: goto x86_l_35f9;
	case 13819ULL: goto x86_l_35fb;
	case 13824ULL: goto x86_l_3600;
	case 13828ULL: goto x86_l_3604;
	case 13829ULL: goto x86_l_3605;
	case 13831ULL: goto x86_l_3607;
	case 13832ULL: goto x86_l_3608;
	case 13833ULL: goto x86_l_3609;
	case 13835ULL: goto x86_l_360b;
	case 13837ULL: goto x86_l_360d;
	case 13839ULL: goto x86_l_360f;
	case 13841ULL: goto x86_l_3611;
	case 13842ULL: goto x86_l_3612;
	case 13846ULL: goto x86_l_3616;
	case 13849ULL: goto x86_l_3619;
	case 13853ULL: goto x86_l_361d;
	case 13857ULL: goto x86_l_3621;
	case 13861ULL: goto x86_l_3625;
	case 13864ULL: goto x86_l_3628;
	case 13866ULL: goto x86_l_362a;
	case 13870ULL: goto x86_l_362e;
	case 13876ULL: goto x86_l_3634;
	case 13880ULL: goto x86_l_3638;
	case 13885ULL: goto x86_l_363d;
	case 13890ULL: goto x86_l_3642;
	case 13895ULL: goto x86_l_3647;
	case 13900ULL: goto x86_l_364c;
	case 13902ULL: goto x86_l_364e;
	case 13907ULL: goto x86_l_3653;
	case 13913ULL: goto x86_l_3659;
	case 13918ULL: goto x86_l_365e;
	case 13923ULL: goto x86_l_3663;
	case 13928ULL: goto x86_l_3668;
	case 13933ULL: goto x86_l_366d;
	case 13938ULL: goto x86_l_3672;
	case 13941ULL: goto x86_l_3675;
	case 13943ULL: goto x86_l_3677;
	case 13948ULL: goto x86_l_367c;
	case 13954ULL: goto x86_l_3682;
	default: return 0xffffffffffffffffULL;
	}
x86_l_309c:
	/* 0x309c: jmp    30a3 <generic_kprobe_process_event+0x30a3> */
	goto x86_l_30a3;
x86_l_309e:
	/* 0x309e: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_30a3:
	/* 0x30a3: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_30a7:
	/* 0x30a7: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30ab:
	/* 0x30ab: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_30b0:
	/* 0x30b0: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_30b4:
	/* 0x30b4: ja     3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3462;
	}
x86_l_30ba:
	/* 0x30ba: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_30c4:
	/* 0x30c4: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_30c8:
	/* 0x30c8: jae    3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3462;
	}
x86_l_30ce:
	/* 0x30ce: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_30d2:
	/* 0x30d2: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_30d5:
	/* 0x30d5: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30da:
	/* 0x30da: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30dd:
	/* 0x30dd: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_30e2:
	/* 0x30e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30e7:
	/* 0x30e7: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30ec:
	/* 0x30ec: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30f0:
	/* 0x30f0: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30f3:
	/* 0x30f3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_30f8:
	/* 0x30f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30fa:
	/* 0x30fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30fd:
	/* 0x30fd: js     3296 <generic_kprobe_process_event+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3296;
	}
x86_l_3103:
	/* 0x3103: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_3108:
	/* 0x3108: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_310b:
	/* 0x310b: jg     3128 <generic_kprobe_process_event+0x3128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3128;
	}
x86_l_310d:
	/* 0x310d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_310f:
	/* 0x310f: je     3146 <generic_kprobe_process_event+0x3146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3146;
	}
x86_l_3111:
	/* 0x3111: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3114:
	/* 0x3114: je     3146 <generic_kprobe_process_event+0x3146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3146;
	}
x86_l_3116:
	/* 0x3116: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_3119:
	/* 0x3119: jne    316c <generic_kprobe_process_event+0x316c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_316c;
	}
x86_l_311b:
	/* 0x311b: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_3122:
	/* 0x3122: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_3126:
	/* 0x3126: jmp    3171 <generic_kprobe_process_event+0x3171> */
	goto x86_l_3171;
x86_l_3128:
	/* 0x3128: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_312b:
	/* 0x312b: je     3159 <generic_kprobe_process_event+0x3159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3159;
	}
x86_l_312d:
	/* 0x312d: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3130:
	/* 0x3130: je     3146 <generic_kprobe_process_event+0x3146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3146;
	}
x86_l_3132:
	/* 0x3132: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_3137:
	/* 0x3137: jne    316c <generic_kprobe_process_event+0x316c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_316c;
	}
x86_l_3139:
	/* 0x3139: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3140:
	/* 0x3140: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3144:
	/* 0x3144: jmp    3171 <generic_kprobe_process_event+0x3171> */
	goto x86_l_3171;
x86_l_3146:
	/* 0x3146: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_314b:
	/* 0x314b: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3152:
	/* 0x3152: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3157:
	/* 0x3157: jmp    3171 <generic_kprobe_process_event+0x3171> */
	goto x86_l_3171;
x86_l_3159:
	/* 0x3159: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_315e:
	/* 0x315e: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3165:
	/* 0x3165: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_316a:
	/* 0x316a: jmp    3171 <generic_kprobe_process_event+0x3171> */
	goto x86_l_3171;
x86_l_316c:
	/* 0x316c: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3171:
	/* 0x3171: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3175:
	/* 0x3175: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3179:
	/* 0x3179: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_317e:
	/* 0x317e: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_3182:
	/* 0x3182: ja     3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3462;
	}
x86_l_3188:
	/* 0x3188: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3192:
	/* 0x3192: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_3196:
	/* 0x3196: jae    3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3462;
	}
x86_l_319c:
	/* 0x319c: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_31a0:
	/* 0x31a0: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_31a3:
	/* 0x31a3: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31a8:
	/* 0x31a8: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31ab:
	/* 0x31ab: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_31b0:
	/* 0x31b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31b5:
	/* 0x31b5: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31ba:
	/* 0x31ba: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31be:
	/* 0x31be: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31c1:
	/* 0x31c1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_31c6:
	/* 0x31c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c8:
	/* 0x31c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31cb:
	/* 0x31cb: js     3296 <generic_kprobe_process_event+0x3296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3296;
	}
x86_l_31d1:
	/* 0x31d1: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_31d6:
	/* 0x31d6: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_31d9:
	/* 0x31d9: jg     31f6 <generic_kprobe_process_event+0x31f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_31f6;
	}
x86_l_31db:
	/* 0x31db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31dd:
	/* 0x31dd: je     3214 <generic_kprobe_process_event+0x3214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3214;
	}
x86_l_31df:
	/* 0x31df: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_31e2:
	/* 0x31e2: je     3214 <generic_kprobe_process_event+0x3214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3214;
	}
x86_l_31e4:
	/* 0x31e4: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_31e7:
	/* 0x31e7: jne    323a <generic_kprobe_process_event+0x323a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_323a;
	}
x86_l_31e9:
	/* 0x31e9: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_31f0:
	/* 0x31f0: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_31f4:
	/* 0x31f4: jmp    323f <generic_kprobe_process_event+0x323f> */
	goto x86_l_323f;
x86_l_31f6:
	/* 0x31f6: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_31f9:
	/* 0x31f9: je     3227 <generic_kprobe_process_event+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3227;
	}
x86_l_31fb:
	/* 0x31fb: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_31fe:
	/* 0x31fe: je     3214 <generic_kprobe_process_event+0x3214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3214;
	}
x86_l_3200:
	/* 0x3200: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_3205:
	/* 0x3205: jne    323a <generic_kprobe_process_event+0x323a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_323a;
	}
x86_l_3207:
	/* 0x3207: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_320e:
	/* 0x320e: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3212:
	/* 0x3212: jmp    323f <generic_kprobe_process_event+0x323f> */
	goto x86_l_323f;
x86_l_3214:
	/* 0x3214: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3219:
	/* 0x3219: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3220:
	/* 0x3220: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3225:
	/* 0x3225: jmp    323f <generic_kprobe_process_event+0x323f> */
	goto x86_l_323f;
x86_l_3227:
	/* 0x3227: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_322c:
	/* 0x322c: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3233:
	/* 0x3233: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3238:
	/* 0x3238: jmp    323f <generic_kprobe_process_event+0x323f> */
	goto x86_l_323f;
x86_l_323a:
	/* 0x323a: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_323f:
	/* 0x323f: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3243:
	/* 0x3243: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3247:
	/* 0x3247: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_324c:
	/* 0x324c: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_3250:
	/* 0x3250: ja     3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3462;
	}
x86_l_3256:
	/* 0x3256: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3260:
	/* 0x3260: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_3264:
	/* 0x3264: jae    3462 <generic_kprobe_process_event+0x3462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3462;
	}
x86_l_326a:
	/* 0x326a: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_326e:
	/* 0x326e: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3271:
	/* 0x3271: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3276:
	/* 0x3276: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3279:
	/* 0x3279: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_327e:
	/* 0x327e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3283:
	/* 0x3283: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3288:
	/* 0x3288: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_328c:
	/* 0x328c: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_328f:
	/* 0x328f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3294:
	/* 0x3294: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3296:
	/* 0x3296: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3298:
	/* 0x3298: mov    BYTE PTR [rsp+0xbc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_32a0:
	/* 0x32a0: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32a4:
	/* 0x32a4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32a9:
	/* 0x32a9: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_32ae:
	/* 0x32ae: mov    WORD PTR [r15+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_32b5:
	/* 0x32b5: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32b9:
	/* 0x32b9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32be:
	/* 0x32be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32c3:
	/* 0x32c3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_32c6:
	/* 0x32c6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_32cb:
	/* 0x32cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32cd:
	/* 0x32cd: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32d1:
	/* 0x32d1: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_32d5:
	/* 0x32d5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32da:
	/* 0x32da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32df:
	/* 0x32df: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_32e4:
	/* 0x32e4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_32e7:
	/* 0x32e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e9:
	/* 0x32e9: cmp    bpl,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 17ULL);
x86_l_32ed:
	/* 0x32ed: je     3340 <generic_kprobe_process_event+0x3340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3340;
	}
x86_l_32ef:
	/* 0x32ef: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32f3:
	/* 0x32f3: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_32f6:
	/* 0x32f6: jne    338b <generic_kprobe_process_event+0x338b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_338b;
	}
x86_l_32fc:
	/* 0x32fc: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3301:
	/* 0x3301: movzx  r15d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_330a:
	/* 0x330a: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_330e:
	/* 0x330e: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3313:
	/* 0x3313: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3317:
	/* 0x3317: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_331c:
	/* 0x331c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3321:
	/* 0x3321: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3326:
	/* 0x3326: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3328:
	/* 0x3328: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_332c:
	/* 0x332c: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3330:
	/* 0x3330: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3334:
	/* 0x3334: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3339:
	/* 0x3339: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_333e:
	/* 0x333e: jmp    3382 <generic_kprobe_process_event+0x3382> */
	goto x86_l_3382;
x86_l_3340:
	/* 0x3340: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3345:
	/* 0x3345: movzx  r15d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_334e:
	/* 0x334e: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3352:
	/* 0x3352: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3357:
	/* 0x3357: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_335b:
	/* 0x335b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3360:
	/* 0x3360: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3365:
	/* 0x3365: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_336a:
	/* 0x336a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_336c:
	/* 0x336c: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3370:
	/* 0x3370: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3374:
	/* 0x3374: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3378:
	/* 0x3378: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_337d:
	/* 0x337d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3382:
	/* 0x3382: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3387:
	/* 0x3387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3389:
	/* 0x3389: jmp    3397 <generic_kprobe_process_event+0x3397> */
	goto x86_l_3397;
x86_l_338b:
	/* 0x338b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3390:
	/* 0x3390: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3397:
	/* 0x3397: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_339c:
	/* 0x339c: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_33a0:
	/* 0x33a0: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_33a4:
	/* 0x33a4: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_33aa:
	/* 0x33aa: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_33b0:
	/* 0x33b0: add    r12,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_33b7:
	/* 0x33b7: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_33bf:
	/* 0x33bf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33c4:
	/* 0x33c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33c9:
	/* 0x33c9: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_33cf:
	/* 0x33cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33d4:
	/* 0x33d4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_33d7:
	/* 0x33d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33d9:
	/* 0x33d9: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_33e1:
	/* 0x33e1: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_33e4:
	/* 0x33e4: je     3457 <generic_kprobe_process_event+0x3457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3457;
	}
x86_l_33e6:
	/* 0x33e6: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_33ea:
	/* 0x33ea: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_33ef:
	/* 0x33ef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33f4:
	/* 0x33f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33f9:
	/* 0x33f9: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3401:
	/* 0x3401: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_3405:
	/* 0x3405: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_340a:
	/* 0x340a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340c:
	/* 0x340c: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3414:
	/* 0x3414: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3419:
	/* 0x3419: lea    rdx,[r12*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_3421:
	/* 0x3421: add    rdx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3424:
	/* 0x3424: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3429:
	/* 0x3429: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_342d:
	/* 0x342d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3432:
	/* 0x3432: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3437:
	/* 0x3437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3439:
	/* 0x3439: add    rbp,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_343d:
	/* 0x343d: lea    rdx,[r12*8+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 4ULL);
x86_l_3445:
	/* 0x3445: add    rdx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3448:
	/* 0x3448: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_344d:
	/* 0x344d: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3450:
	/* 0x3450: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3455:
	/* 0x3455: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3457:
	/* 0x3457: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_345d:
	/* 0x345d: jmp    cea <generic_kprobe_process_event+0xcea> */
	return 3306ULL;
x86_l_3462:
	/* 0x3462: mov    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_346a:
	/* 0x346a: jmp    3298 <generic_kprobe_process_event+0x3298> */
	goto x86_l_3298;
x86_l_346f:
	/* 0x346f: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_3475:
	/* 0x3475: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3477:
	/* 0x3477: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_347a:
	/* 0x347a: jle    34b1 <read_reg+0x42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_34b1;
	}
x86_l_347c:
	/* 0x347c: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_347f:
	/* 0x347f: jle    34d5 <read_reg+0x66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_34d5;
	}
x86_l_3481:
	/* 0x3481: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3484:
	/* 0x3484: jle    353a <read_reg+0xcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_353a;
	}
x86_l_348a:
	/* 0x348a: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_348d:
	/* 0x348d: je     356e <read_reg+0xff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_356e;
	}
x86_l_3493:
	/* 0x3493: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3496:
	/* 0x3496: je     3556 <read_reg+0xe7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3556;
	}
x86_l_349c:
	/* 0x349c: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_349f:
	/* 0x349f: jne    3584 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3584;
	}
x86_l_34a5:
	/* 0x34a5: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_34ac:
	/* 0x34ac: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_34b1:
	/* 0x34b1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_34b4:
	/* 0x34b4: jg     34f1 <read_reg+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_34f1;
	}
x86_l_34b6:
	/* 0x34b6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_34b9:
	/* 0x34b9: jg     351a <read_reg+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_351a;
	}
x86_l_34bb:
	/* 0x34bb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_34bd:
	/* 0x34bd: je     3578 <read_reg+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3578;
	}
x86_l_34c3:
	/* 0x34c3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_34c6:
	/* 0x34c6: jne    3584 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3584;
	}
x86_l_34cc:
	/* 0x34cc: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34d0:
	/* 0x34d0: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_34d5:
	/* 0x34d5: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_34d8:
	/* 0x34d8: jg     350a <read_reg+0x9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_350a;
	}
x86_l_34da:
	/* 0x34da: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34dd:
	/* 0x34dd: je     354a <read_reg+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354a;
	}
x86_l_34df:
	/* 0x34df: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_34e2:
	/* 0x34e2: jne    3584 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3584;
	}
x86_l_34e8:
	/* 0x34e8: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_34ec:
	/* 0x34ec: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_34f1:
	/* 0x34f1: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_34f4:
	/* 0x34f4: jg     352a <read_reg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_352a;
	}
x86_l_34f6:
	/* 0x34f6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_34f9:
	/* 0x34f9: je     355c <read_reg+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355c;
	}
x86_l_34fb:
	/* 0x34fb: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_34fe:
	/* 0x34fe: jne    3584 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3584;
	}
x86_l_3504:
	/* 0x3504: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3508:
	/* 0x3508: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_350a:
	/* 0x350a: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_350d:
	/* 0x350d: je     3550 <read_reg+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_350f:
	/* 0x350f: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3512:
	/* 0x3512: jne    3584 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3584;
	}
x86_l_3514:
	/* 0x3514: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_3518:
	/* 0x3518: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_351a:
	/* 0x351a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_351d:
	/* 0x351d: je     3562 <read_reg+0xf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3562;
	}
x86_l_351f:
	/* 0x351f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3522:
	/* 0x3522: jne    3584 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3584;
	}
x86_l_3524:
	/* 0x3524: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3528:
	/* 0x3528: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_352a:
	/* 0x352a: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_352d:
	/* 0x352d: je     3568 <read_reg+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3568;
	}
x86_l_352f:
	/* 0x352f: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_3532:
	/* 0x3532: jne    3584 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3584;
	}
x86_l_3534:
	/* 0x3534: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3538:
	/* 0x3538: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_353a:
	/* 0x353a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_353d:
	/* 0x353d: je     3574 <read_reg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3574;
	}
x86_l_353f:
	/* 0x353f: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3542:
	/* 0x3542: jne    3584 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3584;
	}
x86_l_3544:
	/* 0x3544: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_3548:
	/* 0x3548: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_354a:
	/* 0x354a: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_354e:
	/* 0x354e: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_3550:
	/* 0x3550: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3554:
	/* 0x3554: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_3556:
	/* 0x3556: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_355a:
	/* 0x355a: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_355c:
	/* 0x355c: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3560:
	/* 0x3560: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_3562:
	/* 0x3562: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3566:
	/* 0x3566: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_3568:
	/* 0x3568: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_356c:
	/* 0x356c: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_356e:
	/* 0x356e: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_3572:
	/* 0x3572: jmp    3578 <read_reg+0x109> */
	goto x86_l_3578;
x86_l_3574:
	/* 0x3574: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_3578:
	/* 0x3578: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_357d:
	/* 0x357d: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_357f:
	/* 0x357f: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_3584:
	/* 0x3584: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3585:
	/* 0x3585: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_358a:
	/* 0x358a: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_358d:
	/* 0x358d: ja     3607 <extract_arg_depth+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3607;
	}
x86_l_358f:
	/* 0x358f: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3591:
	/* 0x3591: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3592:
	/* 0x3592: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3593:
	/* 0x3593: mov    r8,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3596:
	/* 0x3596: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_3599:
	/* 0x3599: cmp    WORD PTR [r8+r9*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 25769803776ULL);
x86_l_35a0:
	/* 0x35a0: je     3600 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3600;
	}
x86_l_35a2:
	/* 0x35a2: mov    rcx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35a6:
	/* 0x35a6: mov    edx,DWORD PTR [r8+r9*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 3), 0ULL);
x86_l_35aa:
	/* 0x35aa: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35ad:
	/* 0x35ad: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35b0:
	/* 0x35b0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35b2:
	/* 0x35b2: cmp    WORD PTR [r8+r9*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 17179869184ULL);
x86_l_35b9:
	/* 0x35b9: je     3600 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3600;
	}
x86_l_35bb:
	/* 0x35bb: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_35bd:
	/* 0x35bd: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_35c1:
	/* 0x35c1: je     35cf <extract_arg_depth+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35cf;
	}
x86_l_35c3:
	/* 0x35c3: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_35c8:
	/* 0x35c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35cd:
	/* 0x35cd: jmp    35d9 <extract_arg_depth+0x54> */
	goto x86_l_35d9;
x86_l_35cf:
	/* 0x35cf: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_35d4:
	/* 0x35d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35d9:
	/* 0x35d9: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_35dc:
	/* 0x35dc: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35e0:
	/* 0x35e0: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35e3:
	/* 0x35e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35e8:
	/* 0x35e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ea:
	/* 0x35ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35ec:
	/* 0x35ec: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_35f1:
	/* 0x35f1: jns    3600 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3600;
	}
x86_l_35f3:
	/* 0x35f3: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_35f5:
	/* 0x35f5: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35f9:
	/* 0x35f9: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35fb:
	/* 0x35fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3600:
	/* 0x3600: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3604:
	/* 0x3604: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3605:
	/* 0x3605: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3607:
	/* 0x3607: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3608:
	/* 0x3608: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_3609:
	/* 0x3609: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_360b:
	/* 0x360b: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_360d:
	/* 0x360d: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_360f:
	/* 0x360f: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3611:
	/* 0x3611: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3612:
	/* 0x3612: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_3616:
	/* 0x3616: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_3619:
	/* 0x3619: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_361d:
	/* 0x361d: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3621:
	/* 0x3621: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3625:
	/* 0x3625: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_3628:
	/* 0x3628: jne    3634 <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3634;
	}
x86_l_362a:
	/* 0x362a: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_362e:
	/* 0x362e: je     379f <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14239ULL;
	}
x86_l_3634:
	/* 0x3634: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3638:
	/* 0x3638: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_363d:
	/* 0x363d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3642:
	/* 0x3642: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3647:
	/* 0x3647: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_364c:
	/* 0x364c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364e:
	/* 0x364e: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3653:
	/* 0x3653: je     374a <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14154ULL;
	}
x86_l_3659:
	/* 0x3659: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_365e:
	/* 0x365e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3663:
	/* 0x3663: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3668:
	/* 0x3668: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_366d:
	/* 0x366d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3672:
	/* 0x3672: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3675:
	/* 0x3675: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3677:
	/* 0x3677: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_367c:
	/* 0x367c: je     374a <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14154ULL;
	}
x86_l_3682:
	/* 0x3682: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 13959ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13959ULL: goto x86_l_3687;
	case 13964ULL: goto x86_l_368c;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13977ULL: goto x86_l_3699;
	case 13979ULL: goto x86_l_369b;
	case 13983ULL: goto x86_l_369f;
	case 13988ULL: goto x86_l_36a4;
	case 13993ULL: goto x86_l_36a9;
	case 13998ULL: goto x86_l_36ae;
	case 14003ULL: goto x86_l_36b3;
	case 14006ULL: goto x86_l_36b6;
	case 14008ULL: goto x86_l_36b8;
	case 14012ULL: goto x86_l_36bc;
	case 14016ULL: goto x86_l_36c0;
	case 14020ULL: goto x86_l_36c4;
	case 14023ULL: goto x86_l_36c7;
	case 14027ULL: goto x86_l_36cb;
	case 14029ULL: goto x86_l_36cd;
	case 14031ULL: goto x86_l_36cf;
	case 14034ULL: goto x86_l_36d2;
	case 14037ULL: goto x86_l_36d5;
	case 14042ULL: goto x86_l_36da;
	case 14044ULL: goto x86_l_36dc;
	case 14047ULL: goto x86_l_36df;
	case 14051ULL: goto x86_l_36e3;
	case 14053ULL: goto x86_l_36e5;
	case 14057ULL: goto x86_l_36e9;
	case 14059ULL: goto x86_l_36eb;
	case 14062ULL: goto x86_l_36ee;
	case 14064ULL: goto x86_l_36f0;
	case 14067ULL: goto x86_l_36f3;
	case 14072ULL: goto x86_l_36f8;
	case 14075ULL: goto x86_l_36fb;
	case 14081ULL: goto x86_l_3701;
	case 14088ULL: goto x86_l_3708;
	case 14094ULL: goto x86_l_370e;
	case 14097ULL: goto x86_l_3711;
	case 14099ULL: goto x86_l_3713;
	case 14104ULL: goto x86_l_3718;
	case 14106ULL: goto x86_l_371a;
	case 14109ULL: goto x86_l_371d;
	case 14113ULL: goto x86_l_3721;
	case 14117ULL: goto x86_l_3725;
	case 14120ULL: goto x86_l_3728;
	case 14123ULL: goto x86_l_372b;
	case 14128ULL: goto x86_l_3730;
	case 14130ULL: goto x86_l_3732;
	case 14134ULL: goto x86_l_3736;
	case 14137ULL: goto x86_l_3739;
	case 14142ULL: goto x86_l_373e;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14152ULL: goto x86_l_3748;
	case 14154ULL: goto x86_l_374a;
	case 14158ULL: goto x86_l_374e;
	case 14163ULL: goto x86_l_3753;
	case 14168ULL: goto x86_l_3758;
	case 14173ULL: goto x86_l_375d;
	case 14178ULL: goto x86_l_3762;
	case 14180ULL: goto x86_l_3764;
	case 14184ULL: goto x86_l_3768;
	case 14189ULL: goto x86_l_376d;
	case 14191ULL: goto x86_l_376f;
	case 14195ULL: goto x86_l_3773;
	case 14200ULL: goto x86_l_3778;
	case 14205ULL: goto x86_l_377d;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14216ULL: goto x86_l_3788;
	case 14218ULL: goto x86_l_378a;
	case 14223ULL: goto x86_l_378f;
	case 14227ULL: goto x86_l_3793;
	case 14231ULL: goto x86_l_3797;
	case 14235ULL: goto x86_l_379b;
	case 14237ULL: goto x86_l_379d;
	case 14239ULL: goto x86_l_379f;
	case 14243ULL: goto x86_l_37a3;
	case 14248ULL: goto x86_l_37a8;
	case 14252ULL: goto x86_l_37ac;
	case 14253ULL: goto x86_l_37ad;
	case 14255ULL: goto x86_l_37af;
	case 14257ULL: goto x86_l_37b1;
	case 14259ULL: goto x86_l_37b3;
	case 14261ULL: goto x86_l_37b5;
	case 14262ULL: goto x86_l_37b6;
	case 14263ULL: goto x86_l_37b7;
	case 14264ULL: goto x86_l_37b8;
	case 14266ULL: goto x86_l_37ba;
	case 14268ULL: goto x86_l_37bc;
	case 14270ULL: goto x86_l_37be;
	case 14272ULL: goto x86_l_37c0;
	case 14273ULL: goto x86_l_37c1;
	case 14274ULL: goto x86_l_37c2;
	case 14277ULL: goto x86_l_37c5;
	case 14280ULL: goto x86_l_37c8;
	case 14283ULL: goto x86_l_37cb;
	case 14286ULL: goto x86_l_37ce;
	case 14294ULL: goto x86_l_37d6;
	case 14301ULL: goto x86_l_37dd;
	case 14306ULL: goto x86_l_37e2;
	case 14311ULL: goto x86_l_37e7;
	case 14313ULL: goto x86_l_37e9;
	case 14316ULL: goto x86_l_37ec;
	case 14318ULL: goto x86_l_37ee;
	case 14321ULL: goto x86_l_37f1;
	case 14327ULL: goto x86_l_37f7;
	case 14332ULL: goto x86_l_37fc;
	case 14334ULL: goto x86_l_37fe;
	case 14337ULL: goto x86_l_3801;
	case 14341ULL: goto x86_l_3805;
	case 14345ULL: goto x86_l_3809;
	case 14349ULL: goto x86_l_380d;
	case 14351ULL: goto x86_l_380f;
	case 14356ULL: goto x86_l_3814;
	case 14360ULL: goto x86_l_3818;
	case 14365ULL: goto x86_l_381d;
	case 14367ULL: goto x86_l_381f;
	case 14371ULL: goto x86_l_3823;
	case 14375ULL: goto x86_l_3827;
	case 14379ULL: goto x86_l_382b;
	case 14383ULL: goto x86_l_382f;
	case 14387ULL: goto x86_l_3833;
	case 14390ULL: goto x86_l_3836;
	case 14393ULL: goto x86_l_3839;
	case 14396ULL: goto x86_l_383c;
	case 14399ULL: goto x86_l_383f;
	case 14404ULL: goto x86_l_3844;
	case 14406ULL: goto x86_l_3846;
	case 14408ULL: goto x86_l_3848;
	case 14415ULL: goto x86_l_384f;
	case 14418ULL: goto x86_l_3852;
	case 14420ULL: goto x86_l_3854;
	case 14422ULL: goto x86_l_3856;
	case 14426ULL: goto x86_l_385a;
	case 14429ULL: goto x86_l_385d;
	case 14431ULL: goto x86_l_385f;
	case 14433ULL: goto x86_l_3861;
	case 14435ULL: goto x86_l_3863;
	case 14437ULL: goto x86_l_3865;
	case 14444ULL: goto x86_l_386c;
	case 14446ULL: goto x86_l_386e;
	case 14448ULL: goto x86_l_3870;
	case 14451ULL: goto x86_l_3873;
	case 14454ULL: goto x86_l_3876;
	case 14459ULL: goto x86_l_387b;
	case 14463ULL: goto x86_l_387f;
	case 14464ULL: goto x86_l_3880;
	case 14466ULL: goto x86_l_3882;
	case 14468ULL: goto x86_l_3884;
	case 14470ULL: goto x86_l_3886;
	case 14472ULL: goto x86_l_3888;
	case 14473ULL: goto x86_l_3889;
	case 14474ULL: goto x86_l_388a;
	case 14475ULL: goto x86_l_388b;
	case 14477ULL: goto x86_l_388d;
	case 14479ULL: goto x86_l_388f;
	case 14481ULL: goto x86_l_3891;
	case 14483ULL: goto x86_l_3893;
	case 14484ULL: goto x86_l_3894;
	case 14485ULL: goto x86_l_3895;
	case 14488ULL: goto x86_l_3898;
	case 14491ULL: goto x86_l_389b;
	case 14494ULL: goto x86_l_389e;
	case 14497ULL: goto x86_l_38a1;
	case 14502ULL: goto x86_l_38a6;
	case 14504ULL: goto x86_l_38a8;
	case 14510ULL: goto x86_l_38ae;
	case 14513ULL: goto x86_l_38b1;
	case 14520ULL: goto x86_l_38b8;
	case 14523ULL: goto x86_l_38bb;
	case 14526ULL: goto x86_l_38be;
	case 14532ULL: goto x86_l_38c4;
	case 14536ULL: goto x86_l_38c8;
	case 14539ULL: goto x86_l_38cb;
	case 14542ULL: goto x86_l_38ce;
	case 14547ULL: goto x86_l_38d3;
	case 14549ULL: goto x86_l_38d5;
	case 14555ULL: goto x86_l_38db;
	case 14560ULL: goto x86_l_38e0;
	case 14563ULL: goto x86_l_38e3;
	case 14566ULL: goto x86_l_38e6;
	case 14569ULL: goto x86_l_38e9;
	case 14572ULL: goto x86_l_38ec;
	case 14578ULL: goto x86_l_38f2;
	case 14582ULL: goto x86_l_38f6;
	case 14585ULL: goto x86_l_38f9;
	case 14588ULL: goto x86_l_38fc;
	case 14593ULL: goto x86_l_3901;
	case 14595ULL: goto x86_l_3903;
	case 14601ULL: goto x86_l_3909;
	case 14606ULL: goto x86_l_390e;
	case 14609ULL: goto x86_l_3911;
	case 14612ULL: goto x86_l_3914;
	case 14615ULL: goto x86_l_3917;
	case 14618ULL: goto x86_l_391a;
	case 14624ULL: goto x86_l_3920;
	case 14628ULL: goto x86_l_3924;
	case 14631ULL: goto x86_l_3927;
	case 14634ULL: goto x86_l_392a;
	case 14639ULL: goto x86_l_392f;
	case 14641ULL: goto x86_l_3931;
	case 14647ULL: goto x86_l_3937;
	case 14652ULL: goto x86_l_393c;
	case 14655ULL: goto x86_l_393f;
	case 14658ULL: goto x86_l_3942;
	case 14661ULL: goto x86_l_3945;
	case 14664ULL: goto x86_l_3948;
	case 14670ULL: goto x86_l_394e;
	case 14674ULL: goto x86_l_3952;
	case 14677ULL: goto x86_l_3955;
	case 14680ULL: goto x86_l_3958;
	case 14685ULL: goto x86_l_395d;
	case 14687ULL: goto x86_l_395f;
	case 14693ULL: goto x86_l_3965;
	case 14698ULL: goto x86_l_396a;
	case 14701ULL: goto x86_l_396d;
	case 14704ULL: goto x86_l_3970;
	case 14707ULL: goto x86_l_3973;
	case 14710ULL: goto x86_l_3976;
	case 14716ULL: goto x86_l_397c;
	case 14720ULL: goto x86_l_3980;
	case 14723ULL: goto x86_l_3983;
	case 14726ULL: goto x86_l_3986;
	case 14731ULL: goto x86_l_398b;
	case 14733ULL: goto x86_l_398d;
	case 14739ULL: goto x86_l_3993;
	case 14744ULL: goto x86_l_3998;
	case 14747ULL: goto x86_l_399b;
	case 14750ULL: goto x86_l_399e;
	case 14753ULL: goto x86_l_39a1;
	case 14756ULL: goto x86_l_39a4;
	case 14762ULL: goto x86_l_39aa;
	case 14766ULL: goto x86_l_39ae;
	case 14769ULL: goto x86_l_39b1;
	case 14772ULL: goto x86_l_39b4;
	case 14777ULL: goto x86_l_39b9;
	case 14779ULL: goto x86_l_39bb;
	case 14785ULL: goto x86_l_39c1;
	case 14790ULL: goto x86_l_39c6;
	case 14793ULL: goto x86_l_39c9;
	case 14796ULL: goto x86_l_39cc;
	case 14799ULL: goto x86_l_39cf;
	case 14802ULL: goto x86_l_39d2;
	case 14808ULL: goto x86_l_39d8;
	case 14812ULL: goto x86_l_39dc;
	case 14815ULL: goto x86_l_39df;
	case 14818ULL: goto x86_l_39e2;
	case 14823ULL: goto x86_l_39e7;
	case 14825ULL: goto x86_l_39e9;
	case 14827ULL: goto x86_l_39eb;
	case 14832ULL: goto x86_l_39f0;
	case 14835ULL: goto x86_l_39f3;
	case 14838ULL: goto x86_l_39f6;
	case 14841ULL: goto x86_l_39f9;
	case 14844ULL: goto x86_l_39fc;
	case 14850ULL: goto x86_l_3a02;
	case 14854ULL: goto x86_l_3a06;
	case 14857ULL: goto x86_l_3a09;
	case 14860ULL: goto x86_l_3a0c;
	case 14865ULL: goto x86_l_3a11;
	case 14867ULL: goto x86_l_3a13;
	case 14869ULL: goto x86_l_3a15;
	case 14874ULL: goto x86_l_3a1a;
	case 14877ULL: goto x86_l_3a1d;
	case 14880ULL: goto x86_l_3a20;
	case 14883ULL: goto x86_l_3a23;
	case 14886ULL: goto x86_l_3a26;
	case 14892ULL: goto x86_l_3a2c;
	case 14895ULL: goto x86_l_3a2f;
	case 14898ULL: goto x86_l_3a32;
	case 14901ULL: goto x86_l_3a35;
	case 14904ULL: goto x86_l_3a38;
	case 14909ULL: goto x86_l_3a3d;
	case 14911ULL: goto x86_l_3a3f;
	case 14913ULL: goto x86_l_3a41;
	case 14918ULL: goto x86_l_3a46;
	case 14921ULL: goto x86_l_3a49;
	case 14924ULL: goto x86_l_3a4c;
	case 14929ULL: goto x86_l_3a51;
	case 14932ULL: goto x86_l_3a54;
	case 14940ULL: goto x86_l_3a5c;
	case 14947ULL: goto x86_l_3a63;
	case 14952ULL: goto x86_l_3a68;
	case 14957ULL: goto x86_l_3a6d;
	case 14959ULL: goto x86_l_3a6f;
	case 14962ULL: goto x86_l_3a72;
	case 14964ULL: goto x86_l_3a74;
	case 14968ULL: goto x86_l_3a78;
	case 14970ULL: goto x86_l_3a7a;
	case 14974ULL: goto x86_l_3a7e;
	case 14976ULL: goto x86_l_3a80;
	case 14980ULL: goto x86_l_3a84;
	case 14982ULL: goto x86_l_3a86;
	case 14986ULL: goto x86_l_3a8a;
	case 14988ULL: goto x86_l_3a8c;
	case 14994ULL: goto x86_l_3a92;
	case 14996ULL: goto x86_l_3a94;
	case 15000ULL: goto x86_l_3a98;
	case 15002ULL: goto x86_l_3a9a;
	case 15006ULL: goto x86_l_3a9e;
	case 15008ULL: goto x86_l_3aa0;
	case 15012ULL: goto x86_l_3aa4;
	case 15014ULL: goto x86_l_3aa6;
	case 15020ULL: goto x86_l_3aac;
	case 15022ULL: goto x86_l_3aae;
	case 15028ULL: goto x86_l_3ab4;
	case 15030ULL: goto x86_l_3ab6;
	case 15036ULL: goto x86_l_3abc;
	case 15038ULL: goto x86_l_3abe;
	case 15044ULL: goto x86_l_3ac4;
	case 15046ULL: goto x86_l_3ac6;
	case 15052ULL: goto x86_l_3acc;
	case 15054ULL: goto x86_l_3ace;
	case 15060ULL: goto x86_l_3ad4;
	case 15064ULL: goto x86_l_3ad8;
	case 15067ULL: goto x86_l_3adb;
	case 15071ULL: goto x86_l_3adf;
	case 15072ULL: goto x86_l_3ae0;
	case 15074ULL: goto x86_l_3ae2;
	case 15076ULL: goto x86_l_3ae4;
	case 15078ULL: goto x86_l_3ae6;
	case 15080ULL: goto x86_l_3ae8;
	case 15081ULL: goto x86_l_3ae9;
	case 15082ULL: goto x86_l_3aea;
	case 15084ULL: goto x86_l_3aec;
	case 15086ULL: goto x86_l_3aee;
	case 15088ULL: goto x86_l_3af0;
	case 15089ULL: goto x86_l_3af1;
	case 15090ULL: goto x86_l_3af2;
	case 15093ULL: goto x86_l_3af5;
	case 15099ULL: goto x86_l_3afb;
	case 15102ULL: goto x86_l_3afe;
	case 15105ULL: goto x86_l_3b01;
	case 15112ULL: goto x86_l_3b08;
	case 15117ULL: goto x86_l_3b0d;
	case 15121ULL: goto x86_l_3b11;
	case 15125ULL: goto x86_l_3b15;
	case 15130ULL: goto x86_l_3b1a;
	case 15132ULL: goto x86_l_3b1c;
	case 15134ULL: goto x86_l_3b1e;
	case 15136ULL: goto x86_l_3b20;
	case 15138ULL: goto x86_l_3b22;
	case 15142ULL: goto x86_l_3b26;
	case 15146ULL: goto x86_l_3b2a;
	case 15154ULL: goto x86_l_3b32;
	case 15161ULL: goto x86_l_3b39;
	case 15166ULL: goto x86_l_3b3e;
	case 15171ULL: goto x86_l_3b43;
	case 15173ULL: goto x86_l_3b45;
	case 15176ULL: goto x86_l_3b48;
	case 15178ULL: goto x86_l_3b4a;
	case 15182ULL: goto x86_l_3b4e;
	case 15184ULL: goto x86_l_3b50;
	case 15191ULL: goto x86_l_3b57;
	case 15196ULL: goto x86_l_3b5c;
	case 15201ULL: goto x86_l_3b61;
	case 15204ULL: goto x86_l_3b64;
	case 15209ULL: goto x86_l_3b69;
	case 15212ULL: goto x86_l_3b6c;
	case 15215ULL: goto x86_l_3b6f;
	case 15217ULL: goto x86_l_3b71;
	case 15219ULL: goto x86_l_3b73;
	case 15221ULL: goto x86_l_3b75;
	case 15223ULL: goto x86_l_3b77;
	case 15230ULL: goto x86_l_3b7e;
	case 15232ULL: goto x86_l_3b80;
	case 15239ULL: goto x86_l_3b87;
	case 15241ULL: goto x86_l_3b89;
	case 15246ULL: goto x86_l_3b8e;
	case 15249ULL: goto x86_l_3b91;
	case 15252ULL: goto x86_l_3b94;
	case 15254ULL: goto x86_l_3b96;
	case 15256ULL: goto x86_l_3b98;
	case 15258ULL: goto x86_l_3b9a;
	case 15260ULL: goto x86_l_3b9c;
	case 15263ULL: goto x86_l_3b9f;
	case 15266ULL: goto x86_l_3ba2;
	case 15270ULL: goto x86_l_3ba6;
	case 15271ULL: goto x86_l_3ba7;
	case 15273ULL: goto x86_l_3ba9;
	case 15275ULL: goto x86_l_3bab;
	case 15277ULL: goto x86_l_3bad;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3687:
	/* 0x3687: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_368c:
	/* 0x368c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3691:
	/* 0x3691: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3696:
	/* 0x3696: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3699:
	/* 0x3699: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_369b:
	/* 0x369b: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_369f:
	/* 0x369f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36a4:
	/* 0x36a4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_36a9:
	/* 0x36a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36ae:
	/* 0x36ae: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_36b3:
	/* 0x36b3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_36b6:
	/* 0x36b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b8:
	/* 0x36b8: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36bc:
	/* 0x36bc: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36c0:
	/* 0x36c0: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_36c4:
	/* 0x36c4: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36c7:
	/* 0x36c7: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36cb:
	/* 0x36cb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36cd:
	/* 0x36cd: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_36cf:
	/* 0x36cf: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_36d2:
	/* 0x36d2: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_36d5:
	/* 0x36d5: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36da:
	/* 0x36da: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36dc:
	/* 0x36dc: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_36df:
	/* 0x36df: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_36e3:
	/* 0x36e3: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_36e5:
	/* 0x36e5: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_36e9:
	/* 0x36e9: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_36eb:
	/* 0x36eb: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_36ee:
	/* 0x36ee: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_36f0:
	/* 0x36f0: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36f3:
	/* 0x36f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36f8:
	/* 0x36f8: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36fb:
	/* 0x36fb: jb     37a8 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37a8;
	}
x86_l_3701:
	/* 0x3701: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_3708:
	/* 0x3708: ja     37a8 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_37a8;
	}
x86_l_370e:
	/* 0x370e: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3711:
	/* 0x3711: jbe    3718 <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3718;
	}
x86_l_3713:
	/* 0x3713: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3718:
	/* 0x3718: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_371a:
	/* 0x371a: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_371d:
	/* 0x371d: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3721:
	/* 0x3721: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3725:
	/* 0x3725: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3728:
	/* 0x3728: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_372b:
	/* 0x372b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3730:
	/* 0x3730: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3732:
	/* 0x3732: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3736:
	/* 0x3736: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3739:
	/* 0x3739: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_373e:
	/* 0x373e: jbe    37a8 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_37a8;
	}
x86_l_3740:
	/* 0x3740: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3745:
	/* 0x3745: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3748:
	/* 0x3748: jmp    379b <cwd_read_v61+0x193> */
	goto x86_l_379b;
x86_l_374a:
	/* 0x374a: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_374e:
	/* 0x374e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3753:
	/* 0x3753: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3758:
	/* 0x3758: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_375d:
	/* 0x375d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3762:
	/* 0x3762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3764:
	/* 0x3764: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3768:
	/* 0x3768: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_376d:
	/* 0x376d: je     379f <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_379f;
	}
x86_l_376f:
	/* 0x376f: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3773:
	/* 0x3773: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3778:
	/* 0x3778: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_377d:
	/* 0x377d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3780:
	/* 0x3780: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3785:
	/* 0x3785: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3788:
	/* 0x3788: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_378a:
	/* 0x378a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_378f:
	/* 0x378f: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3793:
	/* 0x3793: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3797:
	/* 0x3797: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_379b:
	/* 0x379b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_379d:
	/* 0x379d: jmp    37a8 <cwd_read_v61+0x1a0> */
	goto x86_l_37a8;
x86_l_379f:
	/* 0x379f: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_37a3:
	/* 0x37a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37a8:
	/* 0x37a8: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_37ac:
	/* 0x37ac: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_37ad:
	/* 0x37ad: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_37af:
	/* 0x37af: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_37b1:
	/* 0x37b1: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_37b3:
	/* 0x37b3: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_37b5:
	/* 0x37b5: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_37b6:
	/* 0x37b6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_37b7:
	/* 0x37b7: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_37b8:
	/* 0x37b8: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_37ba:
	/* 0x37ba: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_37bc:
	/* 0x37bc: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_37be:
	/* 0x37be: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_37c0:
	/* 0x37c0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_37c1:
	/* 0x37c1: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_37c2:
	/* 0x37c2: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_37c5:
	/* 0x37c5: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_37c8:
	/* 0x37c8: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_37cb:
	/* 0x37cb: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_37ce:
	/* 0x37ce: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_37d6:
	/* 0x37d6: mov    rdi,QWORD PTR [rip+0x360] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_37dd:
	/* 0x37dd: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37e2:
	/* 0x37e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37e7:
	/* 0x37e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37e9:
	/* 0x37e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37ec:
	/* 0x37ec: je     385f <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_385f;
	}
x86_l_37ee:
	/* 0x37ee: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_37f1:
	/* 0x37f1: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_37f7:
	/* 0x37f7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_37fc:
	/* 0x37fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37fe:
	/* 0x37fe: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_3801:
	/* 0x3801: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3805:
	/* 0x3805: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3809:
	/* 0x3809: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_380d:
	/* 0x380d: jne    3818 <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3818;
	}
x86_l_380f:
	/* 0x380f: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3814:
	/* 0x3814: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3818:
	/* 0x3818: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_381d:
	/* 0x381d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_381f:
	/* 0x381f: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3823:
	/* 0x3823: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3827:
	/* 0x3827: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_382b:
	/* 0x382b: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_382f:
	/* 0x382f: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3833:
	/* 0x3833: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3836:
	/* 0x3836: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3839:
	/* 0x3839: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_383c:
	/* 0x383c: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_383f:
	/* 0x383f: call   388a <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14404ULL);
	__x86_sim_call_depth++;
	goto x86_l_388a;
x86_l_3844:
	/* 0x3844: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3846:
	/* 0x3846: js     3863 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3863;
	}
x86_l_3848:
	/* 0x3848: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_384f:
	/* 0x384f: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_3852:
	/* 0x3852: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3854:
	/* 0x3854: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3856:
	/* 0x3856: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_385a:
	/* 0x385a: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_385d:
	/* 0x385d: jmp    3870 <data_event_bytes+0xb9> */
	goto x86_l_3870;
x86_l_385f:
	/* 0x385f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3861:
	/* 0x3861: jmp    387b <data_event_bytes+0xc4> */
	goto x86_l_387b;
x86_l_3863:
	/* 0x3863: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3865:
	/* 0x3865: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_386c:
	/* 0x386c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_386e:
	/* 0x386e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3870:
	/* 0x3870: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3873:
	/* 0x3873: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3876:
	/* 0x3876: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_387b:
	/* 0x387b: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_387f:
	/* 0x387f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3880:
	/* 0x3880: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3882:
	/* 0x3882: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3884:
	/* 0x3884: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3886:
	/* 0x3886: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3888:
	/* 0x3888: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3889:
	/* 0x3889: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_388a:
	/* 0x388a: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_388b:
	/* 0x388b: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_388d:
	/* 0x388d: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_388f:
	/* 0x388f: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_3891:
	/* 0x3891: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3893:
	/* 0x3893: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3894:
	/* 0x3894: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3895:
	/* 0x3895: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_3898:
	/* 0x3898: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_389b:
	/* 0x389b: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_389e:
	/* 0x389e: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_38a1:
	/* 0x38a1: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14502ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_38a6:
	/* 0x38a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38a8:
	/* 0x38a8: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_38ae:
	/* 0x38ae: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_38b1:
	/* 0x38b1: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_38b8:
	/* 0x38b8: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_38bb:
	/* 0x38bb: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_38be:
	/* 0x38be: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_38c4:
	/* 0x38c4: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_38c8:
	/* 0x38c8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_38cb:
	/* 0x38cb: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_38ce:
	/* 0x38ce: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14547ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_38d3:
	/* 0x38d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38d5:
	/* 0x38d5: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_38db:
	/* 0x38db: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_38e0:
	/* 0x38e0: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_38e3:
	/* 0x38e3: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38e6:
	/* 0x38e6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_38e9:
	/* 0x38e9: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_38ec:
	/* 0x38ec: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_38f2:
	/* 0x38f2: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_38f6:
	/* 0x38f6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_38f9:
	/* 0x38f9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_38fc:
	/* 0x38fc: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14593ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_3901:
	/* 0x3901: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3903:
	/* 0x3903: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_3909:
	/* 0x3909: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_390e:
	/* 0x390e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3911:
	/* 0x3911: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3914:
	/* 0x3914: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3917:
	/* 0x3917: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_391a:
	/* 0x391a: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_3920:
	/* 0x3920: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3924:
	/* 0x3924: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3927:
	/* 0x3927: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_392a:
	/* 0x392a: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14639ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_392f:
	/* 0x392f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3931:
	/* 0x3931: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_3937:
	/* 0x3937: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_393c:
	/* 0x393c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_393f:
	/* 0x393f: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3942:
	/* 0x3942: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3945:
	/* 0x3945: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3948:
	/* 0x3948: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_394e:
	/* 0x394e: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3952:
	/* 0x3952: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3955:
	/* 0x3955: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3958:
	/* 0x3958: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14685ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_395d:
	/* 0x395d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_395f:
	/* 0x395f: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_3965:
	/* 0x3965: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_396a:
	/* 0x396a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_396d:
	/* 0x396d: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3970:
	/* 0x3970: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3973:
	/* 0x3973: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3976:
	/* 0x3976: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_397c:
	/* 0x397c: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3980:
	/* 0x3980: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3983:
	/* 0x3983: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3986:
	/* 0x3986: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14731ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_398b:
	/* 0x398b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_398d:
	/* 0x398d: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_3993:
	/* 0x3993: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3998:
	/* 0x3998: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_399b:
	/* 0x399b: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_399e:
	/* 0x399e: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_39a1:
	/* 0x39a1: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_39a4:
	/* 0x39a4: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_39aa:
	/* 0x39aa: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_39ae:
	/* 0x39ae: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_39b1:
	/* 0x39b1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_39b4:
	/* 0x39b4: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14777ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_39b9:
	/* 0x39b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39bb:
	/* 0x39bb: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_39c1:
	/* 0x39c1: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_39c6:
	/* 0x39c6: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_39c9:
	/* 0x39c9: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39cc:
	/* 0x39cc: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_39cf:
	/* 0x39cf: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_39d2:
	/* 0x39d2: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_39d8:
	/* 0x39d8: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_39dc:
	/* 0x39dc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_39df:
	/* 0x39df: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_39e2:
	/* 0x39e2: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14823ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_39e7:
	/* 0x39e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39e9:
	/* 0x39e9: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_39eb:
	/* 0x39eb: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_39f0:
	/* 0x39f0: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_39f3:
	/* 0x39f3: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39f6:
	/* 0x39f6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_39f9:
	/* 0x39f9: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_39fc:
	/* 0x39fc: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_3a02:
	/* 0x3a02: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3a06:
	/* 0x3a06: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3a09:
	/* 0x3a09: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3a0c:
	/* 0x3a0c: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14865ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_3a11:
	/* 0x3a11: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a13:
	/* 0x3a13: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_3a15:
	/* 0x3a15: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3a1a:
	/* 0x3a1a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3a1d:
	/* 0x3a1d: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a20:
	/* 0x3a20: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3a23:
	/* 0x3a23: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3a26:
	/* 0x3a26: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_3a2c:
	/* 0x3a2c: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a2f:
	/* 0x3a2f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3a32:
	/* 0x3a32: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3a35:
	/* 0x3a35: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3a38:
	/* 0x3a38: call   3aea <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14909ULL);
	__x86_sim_call_depth++;
	goto x86_l_3aea;
x86_l_3a3d:
	/* 0x3a3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a3f:
	/* 0x3a3f: js     3a51 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a51;
	}
x86_l_3a41:
	/* 0x3a41: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3a46:
	/* 0x3a46: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a49:
	/* 0x3a49: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3a4c:
	/* 0x3a4c: jmp    3ad8 <do_bytes+0x24e> */
	goto x86_l_3ad8;
x86_l_3a51:
	/* 0x3a51: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3a54:
	/* 0x3a54: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3a5c:
	/* 0x3a5c: mov    rdi,QWORD PTR [rip+0x440] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_3a63:
	/* 0x3a63: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a68:
	/* 0x3a68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a6d:
	/* 0x3a6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a6f:
	/* 0x3a6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a72:
	/* 0x3a72: je     3ad8 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad8;
	}
x86_l_3a74:
	/* 0x3a74: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_3a78:
	/* 0x3a78: jg     3a94 <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a94;
	}
x86_l_3a7a:
	/* 0x3a7a: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_3a7e:
	/* 0x3a7e: je     3aae <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aae;
	}
x86_l_3a80:
	/* 0x3a80: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_3a84:
	/* 0x3a84: je     3ac6 <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ac6;
	}
x86_l_3a86:
	/* 0x3a86: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_3a8a:
	/* 0x3a8a: jne    3abe <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3abe;
	}
x86_l_3a8c:
	/* 0x3a8c: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_3a92:
	/* 0x3a92: jmp    3ad4 <do_bytes+0x24a> */
	goto x86_l_3ad4;
x86_l_3a94:
	/* 0x3a94: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_3a98:
	/* 0x3a98: je     3ab6 <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ab6;
	}
x86_l_3a9a:
	/* 0x3a9a: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_3a9e:
	/* 0x3a9e: je     3ace <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ace;
	}
x86_l_3aa0:
	/* 0x3aa0: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3aa4:
	/* 0x3aa4: jne    3abe <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3abe;
	}
x86_l_3aa6:
	/* 0x3aa6: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_3aac:
	/* 0x3aac: jmp    3ad4 <do_bytes+0x24a> */
	goto x86_l_3ad4;
x86_l_3aae:
	/* 0x3aae: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_3ab4:
	/* 0x3ab4: jmp    3ad4 <do_bytes+0x24a> */
	goto x86_l_3ad4;
x86_l_3ab6:
	/* 0x3ab6: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_3abc:
	/* 0x3abc: jmp    3ad4 <do_bytes+0x24a> */
	goto x86_l_3ad4;
x86_l_3abe:
	/* 0x3abe: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_3ac4:
	/* 0x3ac4: jmp    3ad4 <do_bytes+0x24a> */
	goto x86_l_3ad4;
x86_l_3ac6:
	/* 0x3ac6: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_3acc:
	/* 0x3acc: jmp    3ad4 <do_bytes+0x24a> */
	goto x86_l_3ad4;
x86_l_3ace:
	/* 0x3ace: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_3ad4:
	/* 0x3ad4: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3ad8:
	/* 0x3ad8: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3adb:
	/* 0x3adb: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3adf:
	/* 0x3adf: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3ae0:
	/* 0x3ae0: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3ae2:
	/* 0x3ae2: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3ae4:
	/* 0x3ae4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3ae6:
	/* 0x3ae6: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3ae8:
	/* 0x3ae8: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3ae9:
	/* 0x3ae9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3aea:
	/* 0x3aea: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3aec:
	/* 0x3aec: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3aee:
	/* 0x3aee: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3af0:
	/* 0x3af0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3af1:
	/* 0x3af1: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3af2:
	/* 0x3af2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3af5:
	/* 0x3af5: js     3b77 <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b77;
	}
x86_l_3afb:
	/* 0x3afb: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_3afe:
	/* 0x3afe: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_3b01:
	/* 0x3b01: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_3b08:
	/* 0x3b08: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_3b0d:
	/* 0x3b0d: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_3b11:
	/* 0x3b11: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b15:
	/* 0x3b15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b1a:
	/* 0x3b1a: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_3b1c:
	/* 0x3b1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b1e:
	/* 0x3b1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b20:
	/* 0x3b20: js     3b9c <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b9c;
	}
x86_l_3b22:
	/* 0x3b22: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b26:
	/* 0x3b26: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b2a:
	/* 0x3b2a: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3b32:
	/* 0x3b32: mov    rdi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_3b39:
	/* 0x3b39: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b3e:
	/* 0x3b3e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b43:
	/* 0x3b43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b45:
	/* 0x3b45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b48:
	/* 0x3b48: je     3b80 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b80;
	}
x86_l_3b4a:
	/* 0x3b4a: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3b4e:
	/* 0x3b4e: je     3b80 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b80;
	}
x86_l_3b50:
	/* 0x3b50: mov    rsi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_3b57:
	/* 0x3b57: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3b5c:
	/* 0x3b5c: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3b61:
	/* 0x3b61: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3b64:
	/* 0x3b64: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3b69:
	/* 0x3b69: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3b6c:
	/* 0x3b6c: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_3b6f:
	/* 0x3b6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b71:
	/* 0x3b71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b73:
	/* 0x3b73: js     3b9c <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b9c;
	}
x86_l_3b75:
	/* 0x3b75: jmp    3b9f <__do_bytes+0xb5> */
	goto x86_l_3b9f;
x86_l_3b77:
	/* 0x3b77: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3b7e:
	/* 0x3b7e: jmp    3b9f <__do_bytes+0xb5> */
	goto x86_l_3b9f;
x86_l_3b80:
	/* 0x3b80: mov    rdi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_3b87:
	/* 0x3b87: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b89:
	/* 0x3b89: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_3b8e:
	/* 0x3b8e: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3b91:
	/* 0x3b91: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3b94:
	/* 0x3b94: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b96:
	/* 0x3b96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b98:
	/* 0x3b98: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b9a:
	/* 0x3b9a: jns    3b9f <__do_bytes+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3b9f;
	}
x86_l_3b9c:
	/* 0x3b9c: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3b9f:
	/* 0x3b9f: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3ba2:
	/* 0x3ba2: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3ba6:
	/* 0x3ba6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3ba7:
	/* 0x3ba7: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3ba9:
	/* 0x3ba9: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3bab:
	/* 0x3bab: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3bad:
	/* 0x3bad: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13820U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1726ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1732ULL && __x86_pc <= 3562ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3566ULL && __x86_pc <= 5407ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5412ULL && __x86_pc <= 7209ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7213ULL && __x86_pc <= 8981ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8986ULL && __x86_pc <= 10750ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10754ULL && __x86_pc <= 12439ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12444ULL && __x86_pc <= 13954ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13959ULL && __x86_pc <= 15277ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

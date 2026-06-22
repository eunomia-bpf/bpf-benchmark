extern char CONFIG_ITER_NUM;
extern char ENV_VARS_ENABLED;
extern char buffer_heap_map;
extern char data_heap;
extern char execve_calls;
extern char execve_heap;
extern char execve_map;
extern char execve_msg_heap_map;
extern char tcpmon_map;
extern char tg_cgtracker_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tg_execve_joined_info_map;
extern char tg_execve_joined_info_map_stats;
extern char tg_mbset_gen;
extern char tg_mbset_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 18ULL: goto x86_l_12;
	case 20ULL: goto x86_l_14;
	case 23ULL: goto x86_l_17;
	case 28ULL: goto x86_l_1c;
	case 39ULL: goto x86_l_27;
	case 46ULL: goto x86_l_2e;
	case 54ULL: goto x86_l_36;
	case 59ULL: goto x86_l_3b;
	case 61ULL: goto x86_l_3d;
	case 64ULL: goto x86_l_40;
	case 70ULL: goto x86_l_46;
	case 73ULL: goto x86_l_49;
	case 78ULL: goto x86_l_4e;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 88ULL: goto x86_l_58;
	case 90ULL: goto x86_l_5a;
	case 93ULL: goto x86_l_5d;
	case 98ULL: goto x86_l_62;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 115ULL: goto x86_l_73;
	case 120ULL: goto x86_l_78;
	case 125ULL: goto x86_l_7d;
	case 130ULL: goto x86_l_82;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 142ULL: goto x86_l_8e;
	case 145ULL: goto x86_l_91;
	case 153ULL: goto x86_l_99;
	case 161ULL: goto x86_l_a1;
	case 167ULL: goto x86_l_a7;
	case 174ULL: goto x86_l_ae;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 204ULL: goto x86_l_cc;
	case 206ULL: goto x86_l_ce;
	case 210ULL: goto x86_l_d2;
	case 213ULL: goto x86_l_d5;
	case 220ULL: goto x86_l_dc;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 230ULL: goto x86_l_e6;
	case 233ULL: goto x86_l_e9;
	case 235ULL: goto x86_l_eb;
	case 238ULL: goto x86_l_ee;
	case 243ULL: goto x86_l_f3;
	case 249ULL: goto x86_l_f9;
	case 254ULL: goto x86_l_fe;
	case 259ULL: goto x86_l_103;
	case 262ULL: goto x86_l_106;
	case 267ULL: goto x86_l_10b;
	case 272ULL: goto x86_l_110;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 297ULL: goto x86_l_129;
	case 303ULL: goto x86_l_12f;
	case 310ULL: goto x86_l_136;
	case 315ULL: goto x86_l_13b;
	case 320ULL: goto x86_l_140;
	case 325ULL: goto x86_l_145;
	case 330ULL: goto x86_l_14a;
	case 335ULL: goto x86_l_14f;
	case 340ULL: goto x86_l_154;
	case 342ULL: goto x86_l_156;
	case 346ULL: goto x86_l_15a;
	case 349ULL: goto x86_l_15d;
	case 356ULL: goto x86_l_164;
	case 359ULL: goto x86_l_167;
	case 364ULL: goto x86_l_16c;
	case 366ULL: goto x86_l_16e;
	case 369ULL: goto x86_l_171;
	case 371ULL: goto x86_l_173;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 390ULL: goto x86_l_186;
	case 395ULL: goto x86_l_18b;
	case 398ULL: goto x86_l_18e;
	case 403ULL: goto x86_l_193;
	case 408ULL: goto x86_l_198;
	case 413ULL: goto x86_l_19d;
	case 418ULL: goto x86_l_1a2;
	case 423ULL: goto x86_l_1a7;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 433ULL: goto x86_l_1b1;
	case 439ULL: goto x86_l_1b7;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 461ULL: goto x86_l_1cd;
	case 466ULL: goto x86_l_1d2;
	case 471ULL: goto x86_l_1d7;
	case 476ULL: goto x86_l_1dc;
	case 478ULL: goto x86_l_1de;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 492ULL: goto x86_l_1ec;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 502ULL: goto x86_l_1f6;
	case 505ULL: goto x86_l_1f9;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 515ULL: goto x86_l_203;
	case 521ULL: goto x86_l_209;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 544ULL: goto x86_l_220;
	case 549ULL: goto x86_l_225;
	case 554ULL: goto x86_l_22a;
	case 559ULL: goto x86_l_22f;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 569ULL: goto x86_l_239;
	case 575ULL: goto x86_l_23f;
	case 582ULL: goto x86_l_246;
	case 587ULL: goto x86_l_24b;
	case 592ULL: goto x86_l_250;
	case 597ULL: goto x86_l_255;
	case 602ULL: goto x86_l_25a;
	case 607ULL: goto x86_l_25f;
	case 612ULL: goto x86_l_264;
	case 614ULL: goto x86_l_266;
	case 618ULL: goto x86_l_26a;
	case 621ULL: goto x86_l_26d;
	case 628ULL: goto x86_l_274;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 638ULL: goto x86_l_27e;
	case 641ULL: goto x86_l_281;
	case 647ULL: goto x86_l_287;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 661ULL: goto x86_l_295;
	case 665ULL: goto x86_l_299;
	case 669ULL: goto x86_l_29d;
	case 676ULL: goto x86_l_2a4;
	case 683ULL: goto x86_l_2ab;
	case 690ULL: goto x86_l_2b2;
	case 697ULL: goto x86_l_2b9;
	case 700ULL: goto x86_l_2bc;
	case 705ULL: goto x86_l_2c1;
	case 707ULL: goto x86_l_2c3;
	case 710ULL: goto x86_l_2c6;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 726ULL: goto x86_l_2d6;
	case 732ULL: goto x86_l_2dc;
	case 737ULL: goto x86_l_2e1;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 757ULL: goto x86_l_2f5;
	case 760ULL: goto x86_l_2f8;
	case 766ULL: goto x86_l_2fe;
	case 771ULL: goto x86_l_303;
	case 774ULL: goto x86_l_306;
	case 781ULL: goto x86_l_30d;
	case 784ULL: goto x86_l_310;
	case 788ULL: goto x86_l_314;
	case 793ULL: goto x86_l_319;
	case 800ULL: goto x86_l_320;
	case 805ULL: goto x86_l_325;
	case 807ULL: goto x86_l_327;
	case 810ULL: goto x86_l_32a;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 833ULL: goto x86_l_341;
	case 836ULL: goto x86_l_344;
	case 838ULL: goto x86_l_346;
	case 841ULL: goto x86_l_349;
	case 844ULL: goto x86_l_34c;
	case 846ULL: goto x86_l_34e;
	case 854ULL: goto x86_l_356;
	case 857ULL: goto x86_l_359;
	case 860ULL: goto x86_l_35c;
	case 863ULL: goto x86_l_35f;
	case 869ULL: goto x86_l_365;
	case 872ULL: goto x86_l_368;
	case 874ULL: goto x86_l_36a;
	case 876ULL: goto x86_l_36c;
	case 881ULL: goto x86_l_371;
	case 888ULL: goto x86_l_378;
	case 893ULL: goto x86_l_37d;
	case 898ULL: goto x86_l_382;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 918ULL: goto x86_l_396;
	case 920ULL: goto x86_l_398;
	case 927ULL: goto x86_l_39f;
	case 932ULL: goto x86_l_3a4;
	case 937ULL: goto x86_l_3a9;
	case 942ULL: goto x86_l_3ae;
	case 947ULL: goto x86_l_3b3;
	case 949ULL: goto x86_l_3b5;
	case 953ULL: goto x86_l_3b9;
	case 955ULL: goto x86_l_3bb;
	case 957ULL: goto x86_l_3bd;
	case 964ULL: goto x86_l_3c4;
	case 975ULL: goto x86_l_3cf;
	case 980ULL: goto x86_l_3d4;
	case 985ULL: goto x86_l_3d9;
	case 990ULL: goto x86_l_3de;
	case 993ULL: goto x86_l_3e1;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1007ULL: goto x86_l_3ef;
	case 1012ULL: goto x86_l_3f4;
	case 1019ULL: goto x86_l_3fb;
	case 1024ULL: goto x86_l_400;
	case 1026ULL: goto x86_l_402;
	case 1029ULL: goto x86_l_405;
	case 1031ULL: goto x86_l_407;
	case 1034ULL: goto x86_l_40a;
	case 1038ULL: goto x86_l_40e;
	case 1043ULL: goto x86_l_413;
	case 1046ULL: goto x86_l_416;
	case 1048ULL: goto x86_l_418;
	case 1051ULL: goto x86_l_41b;
	case 1053ULL: goto x86_l_41d;
	case 1056ULL: goto x86_l_420;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1069ULL: goto x86_l_42d;
	case 1072ULL: goto x86_l_430;
	case 1075ULL: goto x86_l_433;
	case 1078ULL: goto x86_l_436;
	case 1080ULL: goto x86_l_438;
	case 1083ULL: goto x86_l_43b;
	case 1085ULL: goto x86_l_43d;
	case 1087ULL: goto x86_l_43f;
	case 1092ULL: goto x86_l_444;
	case 1095ULL: goto x86_l_447;
	case 1102ULL: goto x86_l_44e;
	case 1110ULL: goto x86_l_456;
	case 1118ULL: goto x86_l_45e;
	case 1123ULL: goto x86_l_463;
	case 1125ULL: goto x86_l_465;
	case 1132ULL: goto x86_l_46c;
	case 1143ULL: goto x86_l_477;
	case 1146ULL: goto x86_l_47a;
	case 1150ULL: goto x86_l_47e;
	case 1161ULL: goto x86_l_489;
	case 1168ULL: goto x86_l_490;
	case 1175ULL: goto x86_l_497;
	case 1180ULL: goto x86_l_49c;
	case 1182ULL: goto x86_l_49e;
	case 1186ULL: goto x86_l_4a2;
	case 1189ULL: goto x86_l_4a5;
	case 1194ULL: goto x86_l_4aa;
	case 1199ULL: goto x86_l_4af;
	case 1204ULL: goto x86_l_4b4;
	case 1206ULL: goto x86_l_4b6;
	case 1210ULL: goto x86_l_4ba;
	case 1212ULL: goto x86_l_4bc;
	case 1215ULL: goto x86_l_4bf;
	case 1217ULL: goto x86_l_4c1;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1236ULL: goto x86_l_4d4;
	case 1240ULL: goto x86_l_4d8;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1251ULL: goto x86_l_4e3;
	case 1255ULL: goto x86_l_4e7;
	case 1257ULL: goto x86_l_4e9;
	case 1259ULL: goto x86_l_4eb;
	case 1263ULL: goto x86_l_4ef;
	case 1266ULL: goto x86_l_4f2;
	case 1269ULL: goto x86_l_4f5;
	case 1276ULL: goto x86_l_4fc;
	case 1281ULL: goto x86_l_501;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1295ULL: goto x86_l_50f;
	case 1299ULL: goto x86_l_513;
	case 1302ULL: goto x86_l_516;
	case 1305ULL: goto x86_l_519;
	case 1312ULL: goto x86_l_520;
	case 1317ULL: goto x86_l_525;
	case 1319ULL: goto x86_l_527;
	case 1323ULL: goto x86_l_52b;
	case 1330ULL: goto x86_l_532;
	case 1335ULL: goto x86_l_537;
	case 1337ULL: goto x86_l_539;
	case 1344ULL: goto x86_l_540;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1362ULL: goto x86_l_552;
	case 1371ULL: goto x86_l_55b;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1379ULL: goto x86_l_563;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1398ULL: goto x86_l_576;
	case 1403ULL: goto x86_l_57b;
	case 1405ULL: goto x86_l_57d;
	case 1410ULL: goto x86_l_582;
	case 1412ULL: goto x86_l_584;
	case 1414ULL: goto x86_l_586;
	case 1421ULL: goto x86_l_58d;
	case 1426ULL: goto x86_l_592;
	case 1433ULL: goto x86_l_599;
	case 1438ULL: goto x86_l_59e;
	case 1443ULL: goto x86_l_5a3;
	case 1446ULL: goto x86_l_5a6;
	case 1448ULL: goto x86_l_5a8;
	case 1451ULL: goto x86_l_5ab;
	case 1453ULL: goto x86_l_5ad;
	case 1455ULL: goto x86_l_5af;
	case 1462ULL: goto x86_l_5b6;
	case 1466ULL: goto x86_l_5ba;
	case 1473ULL: goto x86_l_5c1;
	case 1476ULL: goto x86_l_5c4;
	case 1483ULL: goto x86_l_5cb;
	case 1488ULL: goto x86_l_5d0;
	case 1495ULL: goto x86_l_5d7;
	case 1500ULL: goto x86_l_5dc;
	case 1505ULL: goto x86_l_5e1;
	case 1507ULL: goto x86_l_5e3;
	case 1509ULL: goto x86_l_5e5;
	case 1511ULL: goto x86_l_5e7;
	case 1518ULL: goto x86_l_5ee;
	case 1525ULL: goto x86_l_5f5;
	case 1528ULL: goto x86_l_5f8;
	case 1533ULL: goto x86_l_5fd;
	case 1535ULL: goto x86_l_5ff;
	case 1538ULL: goto x86_l_602;
	case 1540ULL: goto x86_l_604;
	case 1543ULL: goto x86_l_607;
	case 1545ULL: goto x86_l_609;
	case 1556ULL: goto x86_l_614;
	case 1567ULL: goto x86_l_61f;
	case 1578ULL: goto x86_l_62a;
	case 1580ULL: goto x86_l_62c;
	case 1587ULL: goto x86_l_633;
	case 1594ULL: goto x86_l_63a;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1604ULL: goto x86_l_644;
	case 1607ULL: goto x86_l_647;
	case 1609ULL: goto x86_l_649;
	case 1612ULL: goto x86_l_64c;
	case 1619ULL: goto x86_l_653;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
	case 1632ULL: goto x86_l_660;
	case 1637ULL: goto x86_l_665;
	case 1640ULL: goto x86_l_668;
	case 1642ULL: goto x86_l_66a;
	case 1644ULL: goto x86_l_66c;
	case 1646ULL: goto x86_l_66e;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1655ULL: goto x86_l_677;
	case 1658ULL: goto x86_l_67a;
	case 1661ULL: goto x86_l_67d;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1672ULL: goto x86_l_688;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
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
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_12:
	/* 0x12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14:
	/* 0x14: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_17:
	/* 0x17: movzx  r12d,WORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1c:
	/* 0x1c: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_27:
	/* 0x27: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_2e:
	/* 0x2e: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_36:
	/* 0x36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b:
	/* 0x3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d:
	/* 0x3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40:
	/* 0x40: je     1f70 <event_execve+0x1f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8048ULL;
	}
x86_l_46:
	/* 0x46: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_49:
	/* 0x49: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_58:
	/* 0x58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a:
	/* 0x5a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_62:
	/* 0x62: add    rcx,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_69:
	/* 0x69: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e:
	/* 0x6e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_73:
	/* 0x73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_78:
	/* 0x78: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_7d:
	/* 0x7d: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_82:
	/* 0x82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_87:
	/* 0x87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89:
	/* 0x89: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8e:
	/* 0x8e: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_91:
	/* 0x91: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_99:
	/* 0x99: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a1:
	/* 0xa1: je     371 <event_execve+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_a7:
	/* 0xa7: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_ae:
	/* 0xae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b3:
	/* 0xb3: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_b8:
	/* 0xb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bd:
	/* 0xbd: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_c2:
	/* 0xc2: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_c7:
	/* 0xc7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cc:
	/* 0xcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce:
	/* 0xce: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d2:
	/* 0xd2: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5:
	/* 0xd5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_dc:
	/* 0xdc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_df:
	/* 0xdf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e4:
	/* 0xe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6:
	/* 0xe6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e9:
	/* 0xe9: je     f9 <event_execve+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f9;
	}
x86_l_eb:
	/* 0xeb: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ee:
	/* 0xee: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f3:
	/* 0xf3: jne    295 <event_execve+0x295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_295;
	}
x86_l_f9:
	/* 0xf9: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_fe:
	/* 0xfe: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_103:
	/* 0x103: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_106:
	/* 0x106: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10b:
	/* 0x10b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_110:
	/* 0x110: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_115:
	/* 0x115: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_11a:
	/* 0x11a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11f:
	/* 0x11f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121:
	/* 0x121: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_126:
	/* 0x126: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_129:
	/* 0x129: je     371 <event_execve+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_12f:
	/* 0x12f: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_136:
	/* 0x136: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b:
	/* 0x13b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_140:
	/* 0x140: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_145:
	/* 0x145: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_14a:
	/* 0x14a: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_14f:
	/* 0x14f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_154:
	/* 0x154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156:
	/* 0x156: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15a:
	/* 0x15a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d:
	/* 0x15d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_164:
	/* 0x164: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_167:
	/* 0x167: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16c:
	/* 0x16c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e:
	/* 0x16e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_171:
	/* 0x171: je     181 <event_execve+0x181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_181;
	}
x86_l_173:
	/* 0x173: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_176:
	/* 0x176: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_17b:
	/* 0x17b: jne    295 <event_execve+0x295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_295;
	}
x86_l_181:
	/* 0x181: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_186:
	/* 0x186: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18b:
	/* 0x18b: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18e:
	/* 0x18e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_193:
	/* 0x193: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_198:
	/* 0x198: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19d:
	/* 0x19d: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1a2:
	/* 0x1a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a7:
	/* 0x1a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a9:
	/* 0x1a9: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae:
	/* 0x1ae: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1b1:
	/* 0x1b1: je     371 <event_execve+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_1b7:
	/* 0x1b7: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_1be:
	/* 0x1be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c3:
	/* 0x1c3: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1c8:
	/* 0x1c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cd:
	/* 0x1cd: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_1d2:
	/* 0x1d2: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1d7:
	/* 0x1d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dc:
	/* 0x1dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de:
	/* 0x1de: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e2:
	/* 0x1e2: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e5:
	/* 0x1e5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1ec:
	/* 0x1ec: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1ef:
	/* 0x1ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f4:
	/* 0x1f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6:
	/* 0x1f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f9:
	/* 0x1f9: je     209 <event_execve+0x209> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209;
	}
x86_l_1fb:
	/* 0x1fb: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1fe:
	/* 0x1fe: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_203:
	/* 0x203: jne    295 <event_execve+0x295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_295;
	}
x86_l_209:
	/* 0x209: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_20e:
	/* 0x20e: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_213:
	/* 0x213: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_216:
	/* 0x216: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21b:
	/* 0x21b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_220:
	/* 0x220: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_225:
	/* 0x225: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_22a:
	/* 0x22a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f:
	/* 0x22f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231:
	/* 0x231: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_236:
	/* 0x236: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_239:
	/* 0x239: je     371 <event_execve+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_23f:
	/* 0x23f: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_246:
	/* 0x246: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24b:
	/* 0x24b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_250:
	/* 0x250: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_255:
	/* 0x255: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_25a:
	/* 0x25a: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_25f:
	/* 0x25f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_264:
	/* 0x264: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_266:
	/* 0x266: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26a:
	/* 0x26a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d:
	/* 0x26d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_274:
	/* 0x274: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_277:
	/* 0x277: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27c:
	/* 0x27c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e:
	/* 0x27e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_281:
	/* 0x281: je     371 <event_execve+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_287:
	/* 0x287: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_28a:
	/* 0x28a: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_28f:
	/* 0x28f: je     371 <event_execve+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_295:
	/* 0x295: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_299:
	/* 0x299: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29d:
	/* 0x29d: mov    QWORD PTR [r14+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a4:
	/* 0x2a4: mov    QWORD PTR [r14+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2ab:
	/* 0x2ab: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b2:
	/* 0x2b2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_gen)));
x86_l_2b9:
	/* 0x2b9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2bc:
	/* 0x2bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c1:
	/* 0x2c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c3:
	/* 0x2c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c6:
	/* 0x2c6: je     463 <event_execve+0x463> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_463;
	}
x86_l_2cc:
	/* 0x2cc: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf:
	/* 0x2cf: cmp    rcx,QWORD PTR [rbp+0x378] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 888ULL);
x86_l_2d6:
	/* 0x2d6: je     463 <event_execve+0x463> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_463;
	}
x86_l_2dc:
	/* 0x2dc: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e1:
	/* 0x2e1: mov    QWORD PTR [rsp+0x88],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2e9:
	/* 0x2e9: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ee:
	/* 0x2ee: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2f5:
	/* 0x2f5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f8:
	/* 0x2f8: je     3d9 <event_execve+0x3d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d9;
	}
x86_l_2fe:
	/* 0x2fe: mov    ebx,0x1869f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 99999ULL);
x86_l_303:
	/* 0x303: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_306:
	/* 0x306: mov    r13,QWORD PTR [rip+0x7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_30d:
	/* 0x30d: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_310:
	/* 0x310: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_314:
	/* 0x314: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_319:
	/* 0x319: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_320:
	/* 0x320: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_325:
	/* 0x325: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_327:
	/* 0x327: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32a:
	/* 0x32a: je     43f <event_execve+0x43f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f;
	}
x86_l_330:
	/* 0x330: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_333:
	/* 0x333: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_337:
	/* 0x337: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33c:
	/* 0x33c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_33f:
	/* 0x33f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341:
	/* 0x341: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_344:
	/* 0x344: je     356 <event_execve+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_356;
	}
x86_l_346:
	/* 0x346: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_349:
	/* 0x349: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34c:
	/* 0x34c: je     356 <event_execve+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_356;
	}
x86_l_34e:
	/* 0x34e: or QWORD PTR [rbp+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_356:
	/* 0x356: sub    ebx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_359:
	/* 0x359: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_35c:
	/* 0x35c: cmp    r12,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R15, X86_WIDTH_64);
x86_l_35f:
	/* 0x35f: je     43f <event_execve+0x43f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f;
	}
x86_l_365:
	/* 0x365: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_368:
	/* 0x368: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_36a:
	/* 0x36a: je     30d <event_execve+0x30d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30d;
	}
x86_l_36c:
	/* 0x36c: jmp    43f <event_execve+0x43f> */
	goto x86_l_43f;
x86_l_371:
	/* 0x371: lea    rdx,[rbx+0xae0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2784ULL);
x86_l_378:
	/* 0x378: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37d:
	/* 0x37d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_382:
	/* 0x382: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_387:
	/* 0x387: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38c:
	/* 0x38c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e:
	/* 0x38e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_393:
	/* 0x393: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_396:
	/* 0x396: je     3bb <event_execve+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bb;
	}
x86_l_398:
	/* 0x398: add    rdx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_39f:
	/* 0x39f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a4:
	/* 0x3a4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3a9:
	/* 0x3a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ae:
	/* 0x3ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b3:
	/* 0x3b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b5:
	/* 0x3b5: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b9:
	/* 0x3b9: jmp    3bd <event_execve+0x3bd> */
	goto x86_l_3bd;
x86_l_3bb:
	/* 0x3bb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3bd:
	/* 0x3bd: mov    DWORD PTR [r14+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3c4:
	/* 0x3c4: mov    QWORD PTR [r14+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3cf:
	/* 0x3cf: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_3d4:
	/* 0x3d4: jmp    465 <event_execve+0x465> */
	goto x86_l_465;
x86_l_3d9:
	/* 0x3d9: mov    ebx,0x3ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1023ULL);
x86_l_3de:
	/* 0x3de: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e1:
	/* 0x3e1: mov    r13,QWORD PTR [rip+0x13] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_3e8:
	/* 0x3e8: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eb:
	/* 0x3eb: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ef:
	/* 0x3ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f4:
	/* 0x3f4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_3fb:
	/* 0x3fb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_400:
	/* 0x400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_402:
	/* 0x402: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_405:
	/* 0x405: je     43f <event_execve+0x43f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f;
	}
x86_l_407:
	/* 0x407: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_40a:
	/* 0x40a: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40e:
	/* 0x40e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_413:
	/* 0x413: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_416:
	/* 0x416: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_418:
	/* 0x418: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41b:
	/* 0x41b: je     42d <event_execve+0x42d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42d;
	}
x86_l_41d:
	/* 0x41d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_420:
	/* 0x420: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_423:
	/* 0x423: je     42d <event_execve+0x42d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42d;
	}
x86_l_425:
	/* 0x425: or QWORD PTR [rbp+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_42d:
	/* 0x42d: sub    ebx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_430:
	/* 0x430: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_433:
	/* 0x433: cmp    r12,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R15, X86_WIDTH_64);
x86_l_436:
	/* 0x436: je     43f <event_execve+0x43f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f;
	}
x86_l_438:
	/* 0x438: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_43b:
	/* 0x43b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_43d:
	/* 0x43d: je     3e8 <event_execve+0x3e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e8;
	}
x86_l_43f:
	/* 0x43f: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_444:
	/* 0x444: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_447:
	/* 0x447: mov    QWORD PTR [rbp+0x378],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 888ULL);
x86_l_44e:
	/* 0x44e: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_456:
	/* 0x456: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_45e:
	/* 0x45e: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_463:
	/* 0x463: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_465:
	/* 0x465: mov    QWORD PTR [r14+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_46c:
	/* 0x46c: mov    DWORD PTR [r14+0x15c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619009ULL);
x86_l_477:
	/* 0x477: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_47a:
	/* 0x47a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_47e:
	/* 0x47e: mov    QWORD PTR [r14+0x178],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1614907703296ULL);
x86_l_489:
	/* 0x489: mov    DWORD PTR [r14+0x144],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_490:
	/* 0x490: mov    DWORD PTR [r14+0x148],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_497:
	/* 0x497: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_49c:
	/* 0x49c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49e:
	/* 0x49e: lea    rdx,[rax+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4a2:
	/* 0x4a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a5:
	/* 0x4a5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4aa:
	/* 0x4aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4af:
	/* 0x4af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b4:
	/* 0x4b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b6:
	/* 0x4b6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ba:
	/* 0x4ba: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bc:
	/* 0x4bc: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4bf:
	/* 0x4bf: je     52b <event_execve+0x52b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52b;
	}
x86_l_4c1:
	/* 0x4c1: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4c5:
	/* 0x4c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ca:
	/* 0x4ca: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4cf:
	/* 0x4cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d4:
	/* 0x4d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d8:
	/* 0x4d8: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4dc:
	/* 0x4dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e1:
	/* 0x4e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e3:
	/* 0x4e3: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e7:
	/* 0x4e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e9:
	/* 0x4e9: je     52b <event_execve+0x52b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52b;
	}
x86_l_4eb:
	/* 0x4eb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ef:
	/* 0x4ef: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_4f2:
	/* 0x4f2: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f5:
	/* 0x4f5: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_4fc:
	/* 0x4fc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_501:
	/* 0x501: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_506:
	/* 0x506: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50b:
	/* 0x50b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50f:
	/* 0x50f: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_513:
	/* 0x513: shl    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_516:
	/* 0x516: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_519:
	/* 0x519: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_520:
	/* 0x520: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_525:
	/* 0x525: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_527:
	/* 0x527: mov    ebx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52b:
	/* 0x52b: mov    DWORD PTR [r14+0x14c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 332ULL);
x86_l_532:
	/* 0x532: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_537:
	/* 0x537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_539:
	/* 0x539: mov    QWORD PTR [r14+0x170],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_540:
	/* 0x540: mov    DWORD PTR [r14+0x140],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534784ULL);
x86_l_54b:
	/* 0x54b: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_550:
	/* 0x550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552:
	/* 0x552: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_55b:
	/* 0x55b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55e:
	/* 0x55e: je     584 <event_execve+0x584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_584;
	}
x86_l_560:
	/* 0x560: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_563:
	/* 0x563: add    rdx,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_567:
	/* 0x567: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56c:
	/* 0x56c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_571:
	/* 0x571: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_576:
	/* 0x576: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57b:
	/* 0x57b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57d:
	/* 0x57d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_582:
	/* 0x582: jmp    586 <event_execve+0x586> */
	goto x86_l_586;
x86_l_584:
	/* 0x584: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_586:
	/* 0x586: mov    DWORD PTR [r14+0x158],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_58d:
	/* 0x58d: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_592:
	/* 0x592: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map)));
x86_l_599:
	/* 0x599: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_59e:
	/* 0x59e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a3:
	/* 0x5a3: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5a6:
	/* 0x5a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a8:
	/* 0x5a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ab:
	/* 0x5ab: je     609 <event_execve+0x609> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_609;
	}
x86_l_5ad:
	/* 0x5ad: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5af:
	/* 0x5af: mov    DWORD PTR [r14+0x150],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_5b6:
	/* 0x5b6: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ba:
	/* 0x5ba: mov    QWORD PTR [r14+0x168],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_5c1:
	/* 0x5c1: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5c4:
	/* 0x5c4: mov    DWORD PTR [r14+0x160],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_5cb:
	/* 0x5cb: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d0:
	/* 0x5d0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map)));
x86_l_5d7:
	/* 0x5d7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5dc:
	/* 0x5dc: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5e1:
	/* 0x5e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e3:
	/* 0x5e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e5:
	/* 0x5e5: je     62c <event_execve+0x62c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_62c;
	}
x86_l_5e7:
	/* 0x5e7: mov    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_5ee:
	/* 0x5ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map_stats)));
x86_l_5f5:
	/* 0x5f5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5f8:
	/* 0x5f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fd:
	/* 0x5fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ff:
	/* 0x5ff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_602:
	/* 0x602: je     64c <event_execve+0x64c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_64c;
	}
x86_l_604:
	/* 0x604: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_607:
	/* 0x607: jmp    64c <event_execve+0x64c> */
	goto x86_l_64c;
x86_l_609:
	/* 0x609: mov    DWORD PTR [r14+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_614:
	/* 0x614: mov    QWORD PTR [r14+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_61f:
	/* 0x61f: mov    DWORD PTR [r14+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_62a:
	/* 0x62a: jmp    64c <event_execve+0x64c> */
	goto x86_l_64c;
x86_l_62c:
	/* 0x62c: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_633:
	/* 0x633: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map_stats)));
x86_l_63a:
	/* 0x63a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_63d:
	/* 0x63d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_642:
	/* 0x642: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_644:
	/* 0x644: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_647:
	/* 0x647: je     64c <event_execve+0x64c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_64c;
	}
x86_l_649:
	/* 0x649: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_64c:
	/* 0x64c: lea    rbx,[r14+0x180] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_653:
	/* 0x653: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_658:
	/* 0x658: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_65d:
	/* 0x65d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_660:
	/* 0x660: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_665:
	/* 0x665: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_668:
	/* 0x668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66a:
	/* 0x66a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_66c:
	/* 0x66c: js     699 <event_execve+0x699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1689ULL;
	}
x86_l_66e:
	/* 0x66e: je     6a2 <event_execve+0x6a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1698ULL;
	}
x86_l_670:
	/* 0x670: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_675:
	/* 0x675: jne    6a6 <event_execve+0x6a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1702ULL;
	}
x86_l_677:
	/* 0x677: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_67a:
	/* 0x67a: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_67d:
	/* 0x67d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_680:
	/* 0x680: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1669ULL);
	__x86_sim_call_depth++;
	return 8065ULL;
x86_l_685:
	/* 0x685: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_688:
	/* 0x688: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_68a:
	/* 0x68a: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_68f:
	/* 0x68f: mov    eax,0x800000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8388608ULL);
	return 1684ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1684ULL: goto x86_l_694;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1691ULL: goto x86_l_69b;
	case 1696ULL: goto x86_l_6a0;
	case 1698ULL: goto x86_l_6a2;
	case 1700ULL: goto x86_l_6a4;
	case 1702ULL: goto x86_l_6a6;
	case 1704ULL: goto x86_l_6a8;
	case 1706ULL: goto x86_l_6aa;
	case 1708ULL: goto x86_l_6ac;
	case 1716ULL: goto x86_l_6b4;
	case 1723ULL: goto x86_l_6bb;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1737ULL: goto x86_l_6c9;
	case 1748ULL: goto x86_l_6d4;
	case 1755ULL: goto x86_l_6db;
	case 1760ULL: goto x86_l_6e0;
	case 1765ULL: goto x86_l_6e5;
	case 1770ULL: goto x86_l_6ea;
	case 1775ULL: goto x86_l_6ef;
	case 1777ULL: goto x86_l_6f1;
	case 1780ULL: goto x86_l_6f4;
	case 1782ULL: goto x86_l_6f6;
	case 1784ULL: goto x86_l_6f8;
	case 1789ULL: goto x86_l_6fd;
	case 1796ULL: goto x86_l_704;
	case 1806ULL: goto x86_l_70e;
	case 1811ULL: goto x86_l_713;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1830ULL: goto x86_l_726;
	case 1833ULL: goto x86_l_729;
	case 1835ULL: goto x86_l_72b;
	case 1837ULL: goto x86_l_72d;
	case 1839ULL: goto x86_l_72f;
	case 1846ULL: goto x86_l_736;
	case 1853ULL: goto x86_l_73d;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1870ULL: goto x86_l_74e;
	case 1872ULL: goto x86_l_750;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1886ULL: goto x86_l_75e;
	case 1891ULL: goto x86_l_763;
	case 1894ULL: goto x86_l_766;
	case 1900ULL: goto x86_l_76c;
	case 1907ULL: goto x86_l_773;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1937ULL: goto x86_l_791;
	case 1940ULL: goto x86_l_794;
	case 1942ULL: goto x86_l_796;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1956ULL: goto x86_l_7a4;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1990ULL: goto x86_l_7c6;
	case 1993ULL: goto x86_l_7c9;
	case 1995ULL: goto x86_l_7cb;
	case 1997ULL: goto x86_l_7cd;
	case 1999ULL: goto x86_l_7cf;
	case 2007ULL: goto x86_l_7d7;
	case 2014ULL: goto x86_l_7de;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2033ULL: goto x86_l_7f1;
	case 2035ULL: goto x86_l_7f3;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2048ULL: goto x86_l_800;
	case 2053ULL: goto x86_l_805;
	case 2058ULL: goto x86_l_80a;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2073ULL: goto x86_l_819;
	case 2075ULL: goto x86_l_81b;
	case 2078ULL: goto x86_l_81e;
	case 2080ULL: goto x86_l_820;
	case 2082ULL: goto x86_l_822;
	case 2087ULL: goto x86_l_827;
	case 2094ULL: goto x86_l_82e;
	case 2104ULL: goto x86_l_838;
	case 2109ULL: goto x86_l_83d;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2137ULL: goto x86_l_859;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2155ULL: goto x86_l_86b;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2172ULL: goto x86_l_87c;
	case 2179ULL: goto x86_l_883;
	case 2187ULL: goto x86_l_88b;
	case 2192ULL: goto x86_l_890;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2202ULL: goto x86_l_89a;
	case 2208ULL: goto x86_l_8a0;
	case 2211ULL: goto x86_l_8a3;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2229ULL: goto x86_l_8b5;
	case 2234ULL: goto x86_l_8ba;
	case 2236ULL: goto x86_l_8bc;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2250ULL: goto x86_l_8ca;
	case 2253ULL: goto x86_l_8cd;
	case 2257ULL: goto x86_l_8d1;
	case 2261ULL: goto x86_l_8d5;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2277ULL: goto x86_l_8e5;
	case 2284ULL: goto x86_l_8ec;
	case 2291ULL: goto x86_l_8f3;
	case 2296ULL: goto x86_l_8f8;
	case 2299ULL: goto x86_l_8fb;
	case 2302ULL: goto x86_l_8fe;
	case 2309ULL: goto x86_l_905;
	case 2315ULL: goto x86_l_90b;
	case 2318ULL: goto x86_l_90e;
	case 2321ULL: goto x86_l_911;
	case 2328ULL: goto x86_l_918;
	case 2331ULL: goto x86_l_91b;
	case 2337ULL: goto x86_l_921;
	case 2339ULL: goto x86_l_923;
	case 2345ULL: goto x86_l_929;
	case 2347ULL: goto x86_l_92b;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2358ULL: goto x86_l_936;
	case 2362ULL: goto x86_l_93a;
	case 2365ULL: goto x86_l_93d;
	case 2368ULL: goto x86_l_940;
	case 2370ULL: goto x86_l_942;
	case 2373ULL: goto x86_l_945;
	case 2379ULL: goto x86_l_94b;
	case 2382ULL: goto x86_l_94e;
	case 2384ULL: goto x86_l_950;
	case 2389ULL: goto x86_l_955;
	case 2396ULL: goto x86_l_95c;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2430ULL: goto x86_l_97e;
	case 2433ULL: goto x86_l_981;
	case 2435ULL: goto x86_l_983;
	case 2437ULL: goto x86_l_985;
	case 2439ULL: goto x86_l_987;
	case 2447ULL: goto x86_l_98f;
	case 2454ULL: goto x86_l_996;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2491ULL: goto x86_l_9bb;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2514ULL: goto x86_l_9d2;
	case 2516ULL: goto x86_l_9d4;
	case 2518ULL: goto x86_l_9d6;
	case 2520ULL: goto x86_l_9d8;
	case 2523ULL: goto x86_l_9db;
	case 2525ULL: goto x86_l_9dd;
	case 2533ULL: goto x86_l_9e5;
	case 2540ULL: goto x86_l_9ec;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2559ULL: goto x86_l_9ff;
	case 2561ULL: goto x86_l_a01;
	case 2563ULL: goto x86_l_a03;
	case 2566ULL: goto x86_l_a06;
	case 2568ULL: goto x86_l_a08;
	case 2570ULL: goto x86_l_a0a;
	case 2575ULL: goto x86_l_a0f;
	case 2582ULL: goto x86_l_a16;
	case 2589ULL: goto x86_l_a1d;
	case 2597ULL: goto x86_l_a25;
	case 2604ULL: goto x86_l_a2c;
	case 2611ULL: goto x86_l_a33;
	case 2619ULL: goto x86_l_a3b;
	case 2625ULL: goto x86_l_a41;
	case 2633ULL: goto x86_l_a49;
	case 2640ULL: goto x86_l_a50;
	case 2645ULL: goto x86_l_a55;
	case 2647ULL: goto x86_l_a57;
	case 2654ULL: goto x86_l_a5e;
	case 2657ULL: goto x86_l_a61;
	case 2663ULL: goto x86_l_a67;
	case 2666ULL: goto x86_l_a6a;
	case 2673ULL: goto x86_l_a71;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2693ULL: goto x86_l_a85;
	case 2696ULL: goto x86_l_a88;
	case 2702ULL: goto x86_l_a8e;
	case 2709ULL: goto x86_l_a95;
	case 2714ULL: goto x86_l_a9a;
	case 2719ULL: goto x86_l_a9f;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2732ULL: goto x86_l_aac;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2742ULL: goto x86_l_ab6;
	case 2748ULL: goto x86_l_abc;
	case 2755ULL: goto x86_l_ac3;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2775ULL: goto x86_l_ad7;
	case 2778ULL: goto x86_l_ada;
	case 2784ULL: goto x86_l_ae0;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2814ULL: goto x86_l_afe;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2824ULL: goto x86_l_b08;
	case 2830ULL: goto x86_l_b0e;
	case 2837ULL: goto x86_l_b15;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2855ULL: goto x86_l_b27;
	case 2857ULL: goto x86_l_b29;
	case 2860ULL: goto x86_l_b2c;
	case 2866ULL: goto x86_l_b32;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2906ULL: goto x86_l_b5a;
	case 2912ULL: goto x86_l_b60;
	case 2919ULL: goto x86_l_b67;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2939ULL: goto x86_l_b7b;
	case 2942ULL: goto x86_l_b7e;
	case 2948ULL: goto x86_l_b84;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2975ULL: goto x86_l_b9f;
	case 2978ULL: goto x86_l_ba2;
	case 2980ULL: goto x86_l_ba4;
	case 2985ULL: goto x86_l_ba9;
	case 2988ULL: goto x86_l_bac;
	case 2994ULL: goto x86_l_bb2;
	case 3001ULL: goto x86_l_bb9;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3019ULL: goto x86_l_bcb;
	case 3021ULL: goto x86_l_bcd;
	case 3024ULL: goto x86_l_bd0;
	case 3030ULL: goto x86_l_bd6;
	case 3037ULL: goto x86_l_bdd;
	case 3042ULL: goto x86_l_be2;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3060ULL: goto x86_l_bf4;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3076ULL: goto x86_l_c04;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3112ULL: goto x86_l_c28;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3139ULL: goto x86_l_c43;
	case 3142ULL: goto x86_l_c46;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3152ULL: goto x86_l_c50;
	case 3158ULL: goto x86_l_c56;
	case 3165ULL: goto x86_l_c5d;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3183ULL: goto x86_l_c6f;
	case 3185ULL: goto x86_l_c71;
	case 3188ULL: goto x86_l_c74;
	case 3194ULL: goto x86_l_c7a;
	case 3201ULL: goto x86_l_c81;
	case 3206ULL: goto x86_l_c86;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3221ULL: goto x86_l_c95;
	case 3224ULL: goto x86_l_c98;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3234ULL: goto x86_l_ca2;
	case 3240ULL: goto x86_l_ca8;
	case 3247ULL: goto x86_l_caf;
	case 3250ULL: goto x86_l_cb2;
	case 3255ULL: goto x86_l_cb7;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3267ULL: goto x86_l_cc3;
	case 3270ULL: goto x86_l_cc6;
	case 3276ULL: goto x86_l_ccc;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3306ULL: goto x86_l_cea;
	case 3308ULL: goto x86_l_cec;
	case 3313ULL: goto x86_l_cf1;
	case 3316ULL: goto x86_l_cf4;
	case 3322ULL: goto x86_l_cfa;
	case 3329ULL: goto x86_l_d01;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3349ULL: goto x86_l_d15;
	case 3352ULL: goto x86_l_d18;
	case 3358ULL: goto x86_l_d1e;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3388ULL: goto x86_l_d3c;
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	default: return 0xffffffffffffffffULL;
	}
x86_l_694:
	/* 0x694: cmove  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_E);
x86_l_697:
	/* 0x697: jmp    6ac <event_execve+0x6ac> */
	goto x86_l_6ac;
x86_l_699:
	/* 0x699: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69b:
	/* 0x69b: mov    eax,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_6a0:
	/* 0x6a0: jmp    6ac <event_execve+0x6ac> */
	goto x86_l_6ac;
x86_l_6a2:
	/* 0x6a2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6a4:
	/* 0x6a4: jmp    6ac <event_execve+0x6ac> */
	goto x86_l_6ac;
x86_l_6a6:
	/* 0x6a6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6a8:
	/* 0x6a8: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_6aa:
	/* 0x6aa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ac:
	/* 0x6ac: mov    WORD PTR [r14+0x178],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_6b4:
	/* 0x6b4: or     DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_6bb:
	/* 0x6bb: add    DWORD PTR [r14+0x140],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 320ULL);
x86_l_6c2:
	/* 0x6c2: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_6c7:
	/* 0x6c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c9:
	/* 0x6c9: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_6d4:
	/* 0x6d4: lea    rdx,[rax+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_6db:
	/* 0x6db: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e0:
	/* 0x6e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6e5:
	/* 0x6e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6ea:
	/* 0x6ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ef:
	/* 0x6ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f1:
	/* 0x6f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f4:
	/* 0x6f4: je     750 <event_execve+0x750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_750;
	}
x86_l_6f6:
	/* 0x6f6: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_6f8:
	/* 0x6f8: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6fd:
	/* 0x6fd: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_704:
	/* 0x704: movabs rax,0x400000042 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869250ULL);
x86_l_70e:
	/* 0x70e: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_713:
	/* 0x713: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_71a:
	/* 0x71a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_71f:
	/* 0x71f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_724:
	/* 0x724: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_726:
	/* 0x726: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_729:
	/* 0x729: je     72f <event_execve+0x72f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_72f;
	}
x86_l_72b:
	/* 0x72b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_72d:
	/* 0x72d: jmp    750 <event_execve+0x750> */
	goto x86_l_750;
x86_l_72f:
	/* 0x72f: mov    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_736:
	/* 0x736: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_73d:
	/* 0x73d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73f:
	/* 0x73f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_744:
	/* 0x744: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_747:
	/* 0x747: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_74c:
	/* 0x74c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_74e:
	/* 0x74e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_750:
	/* 0x750: lea    r12,[r14+0x140] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_757:
	/* 0x757: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_75c:
	/* 0x75c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75e:
	/* 0x75e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_763:
	/* 0x763: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_766:
	/* 0x766: je     a25 <event_execve+0xa25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a25;
	}
x86_l_76c:
	/* 0x76c: add    rcx,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_773:
	/* 0x773: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_776:
	/* 0x776: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_77b:
	/* 0x77b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_780:
	/* 0x780: mov    edx,0x188 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 392ULL);
x86_l_785:
	/* 0x785: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_78a:
	/* 0x78a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_78f:
	/* 0x78f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_791:
	/* 0x791: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_794:
	/* 0x794: je     7f3 <event_execve+0x7f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7f3;
	}
x86_l_796:
	/* 0x796: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_798:
	/* 0x798: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_79d:
	/* 0x79d: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_7a4:
	/* 0x7a4: movabs rax,0x400000047 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869255ULL);
x86_l_7ae:
	/* 0x7ae: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7b3:
	/* 0x7b3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7ba:
	/* 0x7ba: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7bf:
	/* 0x7bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7c4:
	/* 0x7c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c6:
	/* 0x7c6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c9:
	/* 0x7c9: je     7cf <event_execve+0x7cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7cf;
	}
x86_l_7cb:
	/* 0x7cb: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7cd:
	/* 0x7cd: jmp    7f3 <event_execve+0x7f3> */
	goto x86_l_7f3;
x86_l_7cf:
	/* 0x7cf: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_7d7:
	/* 0x7d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7de:
	/* 0x7de: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e0:
	/* 0x7e0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7e5:
	/* 0x7e5: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7ea:
	/* 0x7ea: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7ef:
	/* 0x7ef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f1:
	/* 0x7f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f3:
	/* 0x7f3: mov    edx,0x190 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 400ULL);
x86_l_7f8:
	/* 0x7f8: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7fd:
	/* 0x7fd: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_800:
	/* 0x800: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_805:
	/* 0x805: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_80a:
	/* 0x80a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_80f:
	/* 0x80f: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_814:
	/* 0x814: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_819:
	/* 0x819: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81b:
	/* 0x81b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_81e:
	/* 0x81e: je     85b <event_execve+0x85b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_85b;
	}
x86_l_820:
	/* 0x820: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_822:
	/* 0x822: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_827:
	/* 0x827: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_82e:
	/* 0x82e: movabs rax,0x400000048 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869256ULL);
x86_l_838:
	/* 0x838: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_83d:
	/* 0x83d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_844:
	/* 0x844: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_849:
	/* 0x849: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_84e:
	/* 0x84e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_850:
	/* 0x850: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_853:
	/* 0x853: je     987 <event_execve+0x987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_987;
	}
x86_l_859:
	/* 0x859: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_85b:
	/* 0x85b: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_860:
	/* 0x860: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_865:
	/* 0x865: je     a25 <event_execve+0xa25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a25;
	}
x86_l_86b:
	/* 0x86b: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_871:
	/* 0x871: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_876:
	/* 0x876: je     a25 <event_execve+0xa25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a25;
	}
x86_l_87c:
	/* 0x87c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_heap)));
x86_l_883:
	/* 0x883: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_88b:
	/* 0x88b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_890:
	/* 0x890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_892:
	/* 0x892: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_897:
	/* 0x897: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_89a:
	/* 0x89a: je     a25 <event_execve+0xa25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a25;
	}
x86_l_8a0:
	/* 0x8a0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_8a3:
	/* 0x8a3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a7:
	/* 0x8a7: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_8ac:
	/* 0x8ac: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_8b1:
	/* 0x8b1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b5:
	/* 0x8b5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_8ba:
	/* 0x8ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bc:
	/* 0x8bc: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_8c1:
	/* 0x8c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c4:
	/* 0x8c4: js     a25 <event_execve+0xa25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a25;
	}
x86_l_8ca:
	/* 0x8ca: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_8cd:
	/* 0x8cd: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8d1:
	/* 0x8d1: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8d5:
	/* 0x8d5: mov    eax,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_8dc:
	/* 0x8dc: and    eax,0x1ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 511ULL);
x86_l_8e1:
	/* 0x8e1: lea    r8,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8e5:
	/* 0x8e5: add    r8,0x140 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 320ULL);
x86_l_8ec:
	/* 0x8ec: mov    DWORD PTR [r14+0x184c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6220ULL);
x86_l_8f3:
	/* 0x8f3: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f8:
	/* 0x8f8: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8fb:
	/* 0x8fb: sub    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8fe:
	/* 0x8fe: cmp    rcx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 1023ULL);
x86_l_905:
	/* 0x905: ja     9bd <event_execve+0x9bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9bd;
	}
x86_l_90b:
	/* 0x90b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_90e:
	/* 0x90e: sub    rdi,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_911:
	/* 0x911: add    rdi,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 1024ULL);
x86_l_918:
	/* 0x918: cmp    rcx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_91b:
	/* 0x91b: jae    9bd <event_execve+0x9bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9bd;
	}
x86_l_921:
	/* 0x921: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_923:
	/* 0x923: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_929:
	/* 0x929: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_92b:
	/* 0x92b: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_92e:
	/* 0x92e: cmovne esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_931:
	/* 0x931: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_936:
	/* 0x936: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_93a:
	/* 0x93a: mov    rdi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_64);
x86_l_93d:
	/* 0x93d: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_940:
	/* 0x940: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_942:
	/* 0x942: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_945:
	/* 0x945: je     9d8 <event_execve+0x9d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9d8;
	}
x86_l_94b:
	/* 0x94b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_94e:
	/* 0x94e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_950:
	/* 0x950: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_955:
	/* 0x955: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_95c:
	/* 0x95c: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_966:
	/* 0x966: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_96b:
	/* 0x96b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_972:
	/* 0x972: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_977:
	/* 0x977: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_97c:
	/* 0x97c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97e:
	/* 0x97e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_981:
	/* 0x981: je     9dd <event_execve+0x9dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9dd;
	}
x86_l_983:
	/* 0x983: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_985:
	/* 0x985: jmp    a01 <event_execve+0xa01> */
	goto x86_l_a01;
x86_l_987:
	/* 0x987: mov    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_98f:
	/* 0x98f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_996:
	/* 0x996: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_998:
	/* 0x998: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_99d:
	/* 0x99d: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9a2:
	/* 0x9a2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9a7:
	/* 0x9a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a9:
	/* 0x9a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ab:
	/* 0x9ab: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b0:
	/* 0x9b0: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_9b5:
	/* 0x9b5: jne    86b <event_execve+0x86b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_86b;
	}
x86_l_9bb:
	/* 0x9bb: jmp    a25 <event_execve+0xa25> */
	goto x86_l_a25;
x86_l_9bd:
	/* 0x9bd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_9c0:
	/* 0x9c0: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_9c3:
	/* 0x9c3: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2504ULL);
	__x86_sim_call_depth++;
	return 8253ULL;
x86_l_9c8:
	/* 0x9c8: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_9cb:
	/* 0x9cb: mov    eax,0x1000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16777216ULL);
x86_l_9d0:
	/* 0x9d0: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_9d2:
	/* 0x9d2: jne    a0f <event_execve+0xa0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a0f;
	}
x86_l_9d4:
	/* 0x9d4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9d6:
	/* 0x9d6: jmp    a16 <event_execve+0xa16> */
	goto x86_l_a16;
x86_l_9d8:
	/* 0x9d8: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_9db:
	/* 0x9db: jmp    a16 <event_execve+0xa16> */
	goto x86_l_a16;
x86_l_9dd:
	/* 0x9dd: mov    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_9e5:
	/* 0x9e5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9ec:
	/* 0x9ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ee:
	/* 0x9ee: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f3:
	/* 0x9f3: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9f8:
	/* 0x9f8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9fd:
	/* 0x9fd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ff:
	/* 0x9ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a01:
	/* 0xa01: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_a03:
	/* 0xa03: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_a06:
	/* 0xa06: jns    a16 <event_execve+0xa16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_a16;
	}
x86_l_a08:
	/* 0xa08: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0a:
	/* 0xa0a: mov    eax,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_a0f:
	/* 0xa0f: or     DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_a16:
	/* 0xa16: mov    DWORD PTR [r14+0x1848],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6216ULL);
x86_l_a1d:
	/* 0xa1d: mov    WORD PTR [r14+0x17a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 378ULL);
x86_l_a25:
	/* 0xa25: add    ebx,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 320ULL);
x86_l_a2c:
	/* 0xa2c: mov    DWORD PTR [r14+0x140],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_a33:
	/* 0xa33: test   BYTE PTR [r14+0x15d],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1498943586336ULL);
x86_l_a3b:
	/* 0xa3b: jne    157f <event_execve+0x157f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5503ULL;
	}
x86_l_a41:
	/* 0xa41: mov    QWORD PTR [rsp+0x88],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a49:
	/* 0xa49: mov    ebx,DWORD PTR [r14+0x144] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_a50:
	/* 0xa50: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_a55:
	/* 0xa55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a57:
	/* 0xa57: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5e:
	/* 0xa5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a61:
	/* 0xa61: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_a67:
	/* 0xa67: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_a6a:
	/* 0xa6a: lea    rdx,[rax+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_a71:
	/* 0xa71: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a74:
	/* 0xa74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a79:
	/* 0xa79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a7e:
	/* 0xa7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a83:
	/* 0xa83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a85:
	/* 0xa85: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a88:
	/* 0xa88: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_a8e:
	/* 0xa8e: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_a95:
	/* 0xa95: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a9a:
	/* 0xa9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a9f:
	/* 0xa9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aa4:
	/* 0xaa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aa9:
	/* 0xaa9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_aac:
	/* 0xaac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aae:
	/* 0xaae: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ab3:
	/* 0xab3: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_ab6:
	/* 0xab6: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_abc:
	/* 0xabc: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_ac3:
	/* 0xac3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ac6:
	/* 0xac6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_acb:
	/* 0xacb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ad0:
	/* 0xad0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ad5:
	/* 0xad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad7:
	/* 0xad7: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ada:
	/* 0xada: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_ae0:
	/* 0xae0: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_ae7:
	/* 0xae7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aec:
	/* 0xaec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_af1:
	/* 0xaf1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_af6:
	/* 0xaf6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_afb:
	/* 0xafb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_afe:
	/* 0xafe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b00:
	/* 0xb00: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b05:
	/* 0xb05: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_b08:
	/* 0xb08: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_b0e:
	/* 0xb0e: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_b15:
	/* 0xb15: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b18:
	/* 0xb18: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b1d:
	/* 0xb1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b22:
	/* 0xb22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b27:
	/* 0xb27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b29:
	/* 0xb29: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2c:
	/* 0xb2c: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_b32:
	/* 0xb32: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_b39:
	/* 0xb39: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b3e:
	/* 0xb3e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b43:
	/* 0xb43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b48:
	/* 0xb48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b4d:
	/* 0xb4d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b50:
	/* 0xb50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b52:
	/* 0xb52: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b57:
	/* 0xb57: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_b5a:
	/* 0xb5a: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_b60:
	/* 0xb60: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_b67:
	/* 0xb67: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b6a:
	/* 0xb6a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b6f:
	/* 0xb6f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b74:
	/* 0xb74: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b79:
	/* 0xb79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7b:
	/* 0xb7b: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7e:
	/* 0xb7e: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_b84:
	/* 0xb84: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_b8b:
	/* 0xb8b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b90:
	/* 0xb90: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b95:
	/* 0xb95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b9a:
	/* 0xb9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b9f:
	/* 0xb9f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ba2:
	/* 0xba2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba4:
	/* 0xba4: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ba9:
	/* 0xba9: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_bac:
	/* 0xbac: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_bb2:
	/* 0xbb2: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_bb9:
	/* 0xbb9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bbc:
	/* 0xbbc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_bc1:
	/* 0xbc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bc6:
	/* 0xbc6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bcb:
	/* 0xbcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcd:
	/* 0xbcd: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd0:
	/* 0xbd0: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_bd6:
	/* 0xbd6: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_bdd:
	/* 0xbdd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be2:
	/* 0xbe2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_be7:
	/* 0xbe7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bec:
	/* 0xbec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf1:
	/* 0xbf1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_bf4:
	/* 0xbf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf6:
	/* 0xbf6: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bfb:
	/* 0xbfb: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_bfe:
	/* 0xbfe: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_c04:
	/* 0xc04: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_c0b:
	/* 0xc0b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c0e:
	/* 0xc0e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c13:
	/* 0xc13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c18:
	/* 0xc18: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c1d:
	/* 0xc1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1f:
	/* 0xc1f: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c22:
	/* 0xc22: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_c28:
	/* 0xc28: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_c2f:
	/* 0xc2f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c34:
	/* 0xc34: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c39:
	/* 0xc39: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c3e:
	/* 0xc3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c43:
	/* 0xc43: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c46:
	/* 0xc46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c48:
	/* 0xc48: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c4d:
	/* 0xc4d: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_c50:
	/* 0xc50: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_c56:
	/* 0xc56: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_c5d:
	/* 0xc5d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c60:
	/* 0xc60: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c65:
	/* 0xc65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c6a:
	/* 0xc6a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c6f:
	/* 0xc6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c71:
	/* 0xc71: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c74:
	/* 0xc74: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_c7a:
	/* 0xc7a: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_c81:
	/* 0xc81: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c86:
	/* 0xc86: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c8b:
	/* 0xc8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c90:
	/* 0xc90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c95:
	/* 0xc95: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c98:
	/* 0xc98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9a:
	/* 0xc9a: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c9f:
	/* 0xc9f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_ca2:
	/* 0xca2: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_ca8:
	/* 0xca8: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_caf:
	/* 0xcaf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_cb2:
	/* 0xcb2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cb7:
	/* 0xcb7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cbc:
	/* 0xcbc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cc1:
	/* 0xcc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc3:
	/* 0xcc3: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc6:
	/* 0xcc6: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_ccc:
	/* 0xccc: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_cd3:
	/* 0xcd3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd8:
	/* 0xcd8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cdd:
	/* 0xcdd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce2:
	/* 0xce2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ce7:
	/* 0xce7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_cea:
	/* 0xcea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cec:
	/* 0xcec: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cf1:
	/* 0xcf1: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_cf4:
	/* 0xcf4: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4287ULL;
	}
x86_l_cfa:
	/* 0xcfa: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_d01:
	/* 0xd01: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d04:
	/* 0xd04: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d09:
	/* 0xd09: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d0e:
	/* 0xd0e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d13:
	/* 0xd13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d15:
	/* 0xd15: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d18:
	/* 0xd18: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4290ULL;
	}
x86_l_d1e:
	/* 0xd1e: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_d25:
	/* 0xd25: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d2a:
	/* 0xd2a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d2f:
	/* 0xd2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d34:
	/* 0xd34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d39:
	/* 0xd39: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d3c:
	/* 0xd3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3e:
	/* 0xd3e: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d43:
	/* 0xd43: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
	return 3398ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3398ULL: goto x86_l_d46;
	case 3404ULL: goto x86_l_d4c;
	case 3411ULL: goto x86_l_d53;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3429ULL: goto x86_l_d65;
	case 3431ULL: goto x86_l_d67;
	case 3434ULL: goto x86_l_d6a;
	case 3440ULL: goto x86_l_d70;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3477ULL: goto x86_l_d95;
	case 3480ULL: goto x86_l_d98;
	case 3486ULL: goto x86_l_d9e;
	case 3493ULL: goto x86_l_da5;
	case 3496ULL: goto x86_l_da8;
	case 3501ULL: goto x86_l_dad;
	case 3506ULL: goto x86_l_db2;
	case 3511ULL: goto x86_l_db7;
	case 3513ULL: goto x86_l_db9;
	case 3516ULL: goto x86_l_dbc;
	case 3522ULL: goto x86_l_dc2;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3552ULL: goto x86_l_de0;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3562ULL: goto x86_l_dea;
	case 3568ULL: goto x86_l_df0;
	case 3575ULL: goto x86_l_df7;
	case 3578ULL: goto x86_l_dfa;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3593ULL: goto x86_l_e09;
	case 3595ULL: goto x86_l_e0b;
	case 3598ULL: goto x86_l_e0e;
	case 3604ULL: goto x86_l_e14;
	case 3611ULL: goto x86_l_e1b;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3634ULL: goto x86_l_e32;
	case 3636ULL: goto x86_l_e34;
	case 3641ULL: goto x86_l_e39;
	case 3644ULL: goto x86_l_e3c;
	case 3650ULL: goto x86_l_e42;
	case 3657ULL: goto x86_l_e49;
	case 3660ULL: goto x86_l_e4c;
	case 3665ULL: goto x86_l_e51;
	case 3670ULL: goto x86_l_e56;
	case 3675ULL: goto x86_l_e5b;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3686ULL: goto x86_l_e66;
	case 3693ULL: goto x86_l_e6d;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3718ULL: goto x86_l_e86;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3732ULL: goto x86_l_e94;
	case 3739ULL: goto x86_l_e9b;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3762ULL: goto x86_l_eb2;
	case 3768ULL: goto x86_l_eb8;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3795ULL: goto x86_l_ed3;
	case 3798ULL: goto x86_l_ed6;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3814ULL: goto x86_l_ee6;
	case 3821ULL: goto x86_l_eed;
	case 3824ULL: goto x86_l_ef0;
	case 3829ULL: goto x86_l_ef5;
	case 3834ULL: goto x86_l_efa;
	case 3839ULL: goto x86_l_eff;
	case 3841ULL: goto x86_l_f01;
	case 3844ULL: goto x86_l_f04;
	case 3850ULL: goto x86_l_f0a;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3872ULL: goto x86_l_f20;
	case 3877ULL: goto x86_l_f25;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3887ULL: goto x86_l_f2f;
	case 3890ULL: goto x86_l_f32;
	case 3896ULL: goto x86_l_f38;
	case 3903ULL: goto x86_l_f3f;
	case 3906ULL: goto x86_l_f42;
	case 3911ULL: goto x86_l_f47;
	case 3916ULL: goto x86_l_f4c;
	case 3921ULL: goto x86_l_f51;
	case 3923ULL: goto x86_l_f53;
	case 3926ULL: goto x86_l_f56;
	case 3932ULL: goto x86_l_f5c;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3962ULL: goto x86_l_f7a;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3978ULL: goto x86_l_f8a;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3998ULL: goto x86_l_f9e;
	case 4003ULL: goto x86_l_fa3;
	case 4005ULL: goto x86_l_fa5;
	case 4008ULL: goto x86_l_fa8;
	case 4014ULL: goto x86_l_fae;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4054ULL: goto x86_l_fd6;
	case 4060ULL: goto x86_l_fdc;
	case 4067ULL: goto x86_l_fe3;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4087ULL: goto x86_l_ff7;
	case 4090ULL: goto x86_l_ffa;
	case 4096ULL: goto x86_l_1000;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4118ULL: goto x86_l_1016;
	case 4123ULL: goto x86_l_101b;
	case 4126ULL: goto x86_l_101e;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4142ULL: goto x86_l_102e;
	case 4149ULL: goto x86_l_1035;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4169ULL: goto x86_l_1049;
	case 4172ULL: goto x86_l_104c;
	case 4174ULL: goto x86_l_104e;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4201ULL: goto x86_l_1069;
	case 4204ULL: goto x86_l_106c;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4214ULL: goto x86_l_1076;
	case 4216ULL: goto x86_l_1078;
	case 4223ULL: goto x86_l_107f;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4243ULL: goto x86_l_1093;
	case 4246ULL: goto x86_l_1096;
	case 4248ULL: goto x86_l_1098;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4278ULL: goto x86_l_10b6;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4287ULL: goto x86_l_10bf;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4295ULL: goto x86_l_10c7;
	case 4299ULL: goto x86_l_10cb;
	case 4306ULL: goto x86_l_10d2;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4329ULL: goto x86_l_10e9;
	case 4332ULL: goto x86_l_10ec;
	case 4334ULL: goto x86_l_10ee;
	case 4342ULL: goto x86_l_10f6;
	case 4345ULL: goto x86_l_10f9;
	case 4351ULL: goto x86_l_10ff;
	case 4362ULL: goto x86_l_110a;
	case 4369ULL: goto x86_l_1111;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4384ULL: goto x86_l_1120;
	case 4387ULL: goto x86_l_1123;
	case 4393ULL: goto x86_l_1129;
	case 4396ULL: goto x86_l_112c;
	case 4401ULL: goto x86_l_1131;
	case 4405ULL: goto x86_l_1135;
	case 4413ULL: goto x86_l_113d;
	case 4420ULL: goto x86_l_1144;
	case 4425ULL: goto x86_l_1149;
	case 4430ULL: goto x86_l_114e;
	case 4432ULL: goto x86_l_1150;
	case 4439ULL: goto x86_l_1157;
	case 4447ULL: goto x86_l_115f;
	case 4452ULL: goto x86_l_1164;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4464ULL: goto x86_l_1170;
	case 4472ULL: goto x86_l_1178;
	case 4476ULL: goto x86_l_117c;
	case 4484ULL: goto x86_l_1184;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4498ULL: goto x86_l_1192;
	case 4506ULL: goto x86_l_119a;
	case 4511ULL: goto x86_l_119f;
	case 4514ULL: goto x86_l_11a2;
	case 4516ULL: goto x86_l_11a4;
	case 4524ULL: goto x86_l_11ac;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4538ULL: goto x86_l_11ba;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4550ULL: goto x86_l_11c6;
	case 4556ULL: goto x86_l_11cc;
	case 4562ULL: goto x86_l_11d2;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4571ULL: goto x86_l_11db;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4622ULL: goto x86_l_120e;
	case 4625ULL: goto x86_l_1211;
	case 4632ULL: goto x86_l_1218;
	case 4642ULL: goto x86_l_1222;
	case 4649ULL: goto x86_l_1229;
	case 4658ULL: goto x86_l_1232;
	case 4664ULL: goto x86_l_1238;
	case 4673ULL: goto x86_l_1241;
	case 4682ULL: goto x86_l_124a;
	case 4687ULL: goto x86_l_124f;
	case 4696ULL: goto x86_l_1258;
	case 4705ULL: goto x86_l_1261;
	case 4714ULL: goto x86_l_126a;
	case 4719ULL: goto x86_l_126f;
	case 4724ULL: goto x86_l_1274;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4796ULL: goto x86_l_12bc;
	case 4799ULL: goto x86_l_12bf;
	case 4804ULL: goto x86_l_12c4;
	case 4806ULL: goto x86_l_12c6;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4819ULL: goto x86_l_12d3;
	case 4824ULL: goto x86_l_12d8;
	case 4827ULL: goto x86_l_12db;
	case 4829ULL: goto x86_l_12dd;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4847ULL: goto x86_l_12ef;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4878ULL: goto x86_l_130e;
	case 4881ULL: goto x86_l_1311;
	case 4887ULL: goto x86_l_1317;
	case 4893ULL: goto x86_l_131d;
	case 4899ULL: goto x86_l_1323;
	case 4904ULL: goto x86_l_1328;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4932ULL: goto x86_l_1344;
	case 4937ULL: goto x86_l_1349;
	case 4942ULL: goto x86_l_134e;
	case 4947ULL: goto x86_l_1353;
	case 4949ULL: goto x86_l_1355;
	case 4954ULL: goto x86_l_135a;
	case 4960ULL: goto x86_l_1360;
	case 4964ULL: goto x86_l_1364;
	case 4969ULL: goto x86_l_1369;
	case 4974ULL: goto x86_l_136e;
	case 4979ULL: goto x86_l_1373;
	case 4982ULL: goto x86_l_1376;
	case 4984ULL: goto x86_l_1378;
	case 4989ULL: goto x86_l_137d;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5015ULL: goto x86_l_1397;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5027ULL: goto x86_l_13a3;
	case 5032ULL: goto x86_l_13a8;
	case 5037ULL: goto x86_l_13ad;
	case 5040ULL: goto x86_l_13b0;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5064ULL: goto x86_l_13c8;
	case 5066ULL: goto x86_l_13ca;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5084ULL: goto x86_l_13dc;
	case 5087ULL: goto x86_l_13df;
	case 5091ULL: goto x86_l_13e3;
	case 5093ULL: goto x86_l_13e5;
	case 5097ULL: goto x86_l_13e9;
	case 5099ULL: goto x86_l_13eb;
	case 5102ULL: goto x86_l_13ee;
	case 5104ULL: goto x86_l_13f0;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5117ULL: goto x86_l_13fd;
	case 5123ULL: goto x86_l_1403;
	case 5129ULL: goto x86_l_1409;
	case 5132ULL: goto x86_l_140c;
	case 5134ULL: goto x86_l_140e;
	case 5138ULL: goto x86_l_1412;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5147ULL: goto x86_l_141b;
	case 5150ULL: goto x86_l_141e;
	case 5153ULL: goto x86_l_1421;
	case 5156ULL: goto x86_l_1424;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d46:
	/* 0xd46: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_d4c:
	/* 0xd4c: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_d53:
	/* 0xd53: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d56:
	/* 0xd56: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d5b:
	/* 0xd5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d60:
	/* 0xd60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d65:
	/* 0xd65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d67:
	/* 0xd67: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6a:
	/* 0xd6a: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_d70:
	/* 0xd70: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_d77:
	/* 0xd77: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7c:
	/* 0xd7c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d81:
	/* 0xd81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d86:
	/* 0xd86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d8b:
	/* 0xd8b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d8e:
	/* 0xd8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d90:
	/* 0xd90: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d95:
	/* 0xd95: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d98:
	/* 0xd98: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_d9e:
	/* 0xd9e: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_da5:
	/* 0xda5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_da8:
	/* 0xda8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_dad:
	/* 0xdad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_db2:
	/* 0xdb2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_db7:
	/* 0xdb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db9:
	/* 0xdb9: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbc:
	/* 0xdbc: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_dc2:
	/* 0xdc2: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_dc9:
	/* 0xdc9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dce:
	/* 0xdce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dd3:
	/* 0xdd3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dd8:
	/* 0xdd8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ddd:
	/* 0xddd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_de0:
	/* 0xde0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de2:
	/* 0xde2: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_de7:
	/* 0xde7: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_dea:
	/* 0xdea: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_df0:
	/* 0xdf0: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_df7:
	/* 0xdf7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_dfa:
	/* 0xdfa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_dff:
	/* 0xdff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e04:
	/* 0xe04: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e09:
	/* 0xe09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0b:
	/* 0xe0b: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e0e:
	/* 0xe0e: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_e14:
	/* 0xe14: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_e1b:
	/* 0xe1b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e20:
	/* 0xe20: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e25:
	/* 0xe25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e2a:
	/* 0xe2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e2f:
	/* 0xe2f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e32:
	/* 0xe32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e34:
	/* 0xe34: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e39:
	/* 0xe39: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_e3c:
	/* 0xe3c: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_e42:
	/* 0xe42: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_e49:
	/* 0xe49: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e4c:
	/* 0xe4c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e51:
	/* 0xe51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e56:
	/* 0xe56: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e5b:
	/* 0xe5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5d:
	/* 0xe5d: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e60:
	/* 0xe60: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_e66:
	/* 0xe66: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_e6d:
	/* 0xe6d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e72:
	/* 0xe72: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e77:
	/* 0xe77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e7c:
	/* 0xe7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e81:
	/* 0xe81: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e84:
	/* 0xe84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e86:
	/* 0xe86: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e8b:
	/* 0xe8b: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_e8e:
	/* 0xe8e: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_e94:
	/* 0xe94: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_e9b:
	/* 0xe9b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e9e:
	/* 0xe9e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ea3:
	/* 0xea3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea8:
	/* 0xea8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ead:
	/* 0xead: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eaf:
	/* 0xeaf: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb2:
	/* 0xeb2: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_eb8:
	/* 0xeb8: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_ebf:
	/* 0xebf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ec4:
	/* 0xec4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ec9:
	/* 0xec9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ece:
	/* 0xece: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ed3:
	/* 0xed3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ed6:
	/* 0xed6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed8:
	/* 0xed8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_edd:
	/* 0xedd: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_ee0:
	/* 0xee0: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_ee6:
	/* 0xee6: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_eed:
	/* 0xeed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ef0:
	/* 0xef0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ef5:
	/* 0xef5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_efa:
	/* 0xefa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eff:
	/* 0xeff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f01:
	/* 0xf01: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f04:
	/* 0xf04: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_f0a:
	/* 0xf0a: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_f11:
	/* 0xf11: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f16:
	/* 0xf16: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f1b:
	/* 0xf1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f20:
	/* 0xf20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f25:
	/* 0xf25: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f28:
	/* 0xf28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2a:
	/* 0xf2a: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f2f:
	/* 0xf2f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_f32:
	/* 0xf32: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_f38:
	/* 0xf38: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_f3f:
	/* 0xf3f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f42:
	/* 0xf42: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f47:
	/* 0xf47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f4c:
	/* 0xf4c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f51:
	/* 0xf51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f53:
	/* 0xf53: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f56:
	/* 0xf56: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_f5c:
	/* 0xf5c: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_f63:
	/* 0xf63: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f68:
	/* 0xf68: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f6d:
	/* 0xf6d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f72:
	/* 0xf72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f77:
	/* 0xf77: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f7a:
	/* 0xf7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7c:
	/* 0xf7c: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f81:
	/* 0xf81: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_f84:
	/* 0xf84: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_f8a:
	/* 0xf8a: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_f91:
	/* 0xf91: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f94:
	/* 0xf94: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f99:
	/* 0xf99: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f9e:
	/* 0xf9e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fa3:
	/* 0xfa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa5:
	/* 0xfa5: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa8:
	/* 0xfa8: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_fae:
	/* 0xfae: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_fb5:
	/* 0xfb5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fba:
	/* 0xfba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fbf:
	/* 0xfbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fc4:
	/* 0xfc4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fc9:
	/* 0xfc9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_fcc:
	/* 0xfcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fce:
	/* 0xfce: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd3:
	/* 0xfd3: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_fd6:
	/* 0xfd6: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_fdc:
	/* 0xfdc: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_fe3:
	/* 0xfe3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fe6:
	/* 0xfe6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_feb:
	/* 0xfeb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff0:
	/* 0xff0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ff5:
	/* 0xff5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff7:
	/* 0xff7: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ffa:
	/* 0xffa: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_1000:
	/* 0x1000: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1007:
	/* 0x1007: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_100c:
	/* 0x100c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1011:
	/* 0x1011: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1016:
	/* 0x1016: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_101b:
	/* 0x101b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_101e:
	/* 0x101e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1020:
	/* 0x1020: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1025:
	/* 0x1025: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1028:
	/* 0x1028: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_102e:
	/* 0x102e: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1035:
	/* 0x1035: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1038:
	/* 0x1038: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_103d:
	/* 0x103d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1042:
	/* 0x1042: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1047:
	/* 0x1047: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1049:
	/* 0x1049: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104c:
	/* 0x104c: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_104e:
	/* 0x104e: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1055:
	/* 0x1055: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_105a:
	/* 0x105a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_105f:
	/* 0x105f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1064:
	/* 0x1064: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1069:
	/* 0x1069: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_106c:
	/* 0x106c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106e:
	/* 0x106e: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1073:
	/* 0x1073: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1076:
	/* 0x1076: je     10bf <event_execve+0x10bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bf;
	}
x86_l_1078:
	/* 0x1078: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_107f:
	/* 0x107f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1082:
	/* 0x1082: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1087:
	/* 0x1087: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_108c:
	/* 0x108c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1091:
	/* 0x1091: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1093:
	/* 0x1093: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1096:
	/* 0x1096: je     10c2 <event_execve+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_1098:
	/* 0x1098: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_109f:
	/* 0x109f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10a4:
	/* 0x10a4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10a9:
	/* 0x10a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10ae:
	/* 0x10ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b3:
	/* 0x10b3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10b6:
	/* 0x10b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b8:
	/* 0x10b8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10bd:
	/* 0x10bd: jmp    10c2 <event_execve+0x10c2> */
	goto x86_l_10c2;
x86_l_10bf:
	/* 0x10bf: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c2:
	/* 0x10c2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c4:
	/* 0x10c4: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c7:
	/* 0x10c7: cmovne r13,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_64, X86_CC_NE);
x86_l_10cb:
	/* 0x10cb: add    r13,0xd30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3376ULL);
x86_l_10d2:
	/* 0x10d2: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10da:
	/* 0x10da: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10df:
	/* 0x10df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10e4:
	/* 0x10e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10e9:
	/* 0x10e9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10ec:
	/* 0x10ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ee:
	/* 0x10ee: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10f6:
	/* 0x10f6: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_10f9:
	/* 0x10f9: je     11db <event_execve+0x11db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11db;
	}
x86_l_10ff:
	/* 0x10ff: mov    DWORD PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_110a:
	/* 0x110a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_1111:
	/* 0x1111: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1119:
	/* 0x1119: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111e:
	/* 0x111e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1120:
	/* 0x1120: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1123:
	/* 0x1123: je     1506 <event_execve+0x1506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5382ULL;
	}
x86_l_1129:
	/* 0x1129: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_112c:
	/* 0x112c: mov    QWORD PTR [rsp+0x78],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1131:
	/* 0x1131: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1135:
	/* 0x1135: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_113d:
	/* 0x113d: lea    rax,[rbp+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_1144:
	/* 0x1144: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1149:
	/* 0x1149: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_114e:
	/* 0x114e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1150:
	/* 0x1150: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_1157:
	/* 0x1157: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_115f:
	/* 0x115f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1164:
	/* 0x1164: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1169:
	/* 0x1169: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_116e:
	/* 0x116e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1170:
	/* 0x1170: mov    r13,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1178:
	/* 0x1178: add    rbx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_117c:
	/* 0x117c: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1184:
	/* 0x1184: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1189:
	/* 0x1189: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_118e:
	/* 0x118e: lea    rcx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1192:
	/* 0x1192: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_119a:
	/* 0x119a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_119f:
	/* 0x119f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_11a2:
	/* 0x11a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a4:
	/* 0x11a4: mov    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_11ac:
	/* 0x11ac: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b0:
	/* 0x11b0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11b5:
	/* 0x11b5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11ba:
	/* 0x11ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11bf:
	/* 0x11bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11c4:
	/* 0x11c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c6:
	/* 0x11c6: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_11cc:
	/* 0x11cc: mov    r12d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4096ULL);
x86_l_11d2:
	/* 0x11d2: je     11e8 <event_execve+0x11e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e8;
	}
x86_l_11d4:
	/* 0x11d4: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11d9:
	/* 0x11d9: jmp    1238 <event_execve+0x1238> */
	goto x86_l_1238;
x86_l_11db:
	/* 0x11db: or     BYTE PTR [r14+0x15d],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 1498943586336ULL);
x86_l_11e3:
	/* 0x11e3: jmp    157b <event_execve+0x157b> */
	return 5499ULL;
x86_l_11e8:
	/* 0x11e8: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ec:
	/* 0x11ec: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11f1:
	/* 0x11f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11f6:
	/* 0x11f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11fb:
	/* 0x11fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1200:
	/* 0x1200: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1202:
	/* 0x1202: cmp    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1207:
	/* 0x1207: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_120c:
	/* 0x120c: je     1238 <event_execve+0x1238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1238;
	}
x86_l_120e:
	/* 0x120e: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1211:
	/* 0x1211: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_1218:
	/* 0x1218: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_1222:
	/* 0x1222: mov    QWORD PTR [rbp+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1229:
	/* 0x1229: mov    WORD PTR [rbp+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_1232:
	/* 0x1232: mov    r12d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4086ULL);
x86_l_1238:
	/* 0x1238: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1241:
	/* 0x1241: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_124a:
	/* 0x124a: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_124f:
	/* 0x124f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1258:
	/* 0x1258: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1261:
	/* 0x1261: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_126a:
	/* 0x126a: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_126f:
	/* 0x126f: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1274:
	/* 0x1274: mov    DWORD PTR [rsp+0x58],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1279:
	/* 0x1279: mov    BYTE PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_127e:
	/* 0x127e: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1282:
	/* 0x1282: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1287:
	/* 0x1287: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_128c:
	/* 0x128c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1291:
	/* 0x1291: lea    rbp,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1296:
	/* 0x1296: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_129b:
	/* 0x129b: lea    r12,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12a0:
	/* 0x12a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a5:
	/* 0x12a5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_12a8:
	/* 0x12a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12aa:
	/* 0x12aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12af:
	/* 0x12af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12b4:
	/* 0x12b4: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_12bc:
	/* 0x12bc: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_12bf:
	/* 0x12bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12c4:
	/* 0x12c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c6:
	/* 0x12c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12cb:
	/* 0x12cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12d0:
	/* 0x12d0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_12d3:
	/* 0x12d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12d8:
	/* 0x12d8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_12db:
	/* 0x12db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12dd:
	/* 0x12dd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12e2:
	/* 0x12e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12e7:
	/* 0x12e7: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_12ef:
	/* 0x12ef: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_12f2:
	/* 0x12f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12f7:
	/* 0x12f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f9:
	/* 0x12f9: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12fe:
	/* 0x12fe: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_1302:
	/* 0x1302: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1307:
	/* 0x1307: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_130e:
	/* 0x130e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1311:
	/* 0x1311: je     14a9 <event_execve+0x14a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5289ULL;
	}
x86_l_1317:
	/* 0x1317: mov    r13d,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2048ULL);
x86_l_131d:
	/* 0x131d: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1323:
	/* 0x1323: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1328:
	/* 0x1328: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_132d:
	/* 0x132d: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1332:
	/* 0x1332: cmp    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1337:
	/* 0x1337: jne    1344 <event_execve+0x1344> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1344;
	}
x86_l_1339:
	/* 0x1339: cmp    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_133e:
	/* 0x133e: je     150a <event_execve+0x150a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5386ULL;
	}
x86_l_1344:
	/* 0x1344: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1349:
	/* 0x1349: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_134e:
	/* 0x134e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1353:
	/* 0x1353: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1355:
	/* 0x1355: cmp    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_135a:
	/* 0x135a: je     144e <event_execve+0x144e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5198ULL;
	}
x86_l_1360:
	/* 0x1360: lea    rbx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1364:
	/* 0x1364: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1369:
	/* 0x1369: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_136e:
	/* 0x136e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1373:
	/* 0x1373: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1376:
	/* 0x1376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1378:
	/* 0x1378: cmp    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_137d:
	/* 0x137d: je     144e <event_execve+0x144e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5198ULL;
	}
x86_l_1383:
	/* 0x1383: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1388:
	/* 0x1388: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_138d:
	/* 0x138d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1392:
	/* 0x1392: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1395:
	/* 0x1395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1397:
	/* 0x1397: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_139b:
	/* 0x139b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13a0:
	/* 0x13a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13a3:
	/* 0x13a3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_13a8:
	/* 0x13a8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_13ad:
	/* 0x13ad: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_13b0:
	/* 0x13b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b2:
	/* 0x13b2: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13b7:
	/* 0x13b7: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13bc:
	/* 0x13bc: mov    ebp,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13c0:
	/* 0x13c0: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_13c3:
	/* 0x13c3: mov    r15d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13c8:
	/* 0x13c8: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_13ca:
	/* 0x13ca: sub    edx,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_13cd:
	/* 0x13cd: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_13d2:
	/* 0x13d2: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_13d5:
	/* 0x13d5: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_13da:
	/* 0x13da: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13dc:
	/* 0x13dc: cmp    r15d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_13df:
	/* 0x13df: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_13e3:
	/* 0x13e3: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_13e5:
	/* 0x13e5: cmovb  ecx,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R15, X86_WIDTH_32, X86_CC_B);
x86_l_13e9:
	/* 0x13e9: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13eb:
	/* 0x13eb: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_13ee:
	/* 0x13ee: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_13f0:
	/* 0x13f0: mov    DWORD PTR [rsp+0x58],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13f4:
	/* 0x13f4: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_13f7:
	/* 0x13f7: jb     14ca <event_execve+0x14ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5322ULL;
	}
x86_l_13fd:
	/* 0x13fd: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1403:
	/* 0x1403: ja     14ca <event_execve+0x14ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5322ULL;
	}
x86_l_1409:
	/* 0x1409: cmp    r15d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_140c:
	/* 0x140c: jbe    1412 <event_execve+0x1412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1412;
	}
x86_l_140e:
	/* 0x140e: mov    BYTE PTR [rbx+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1412:
	/* 0x1412: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1414:
	/* 0x1414: cmp    r15d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1417:
	/* 0x1417: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_141b:
	/* 0x141b: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_141e:
	/* 0x141e: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1421:
	/* 0x1421: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1424:
	/* 0x1424: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 5161ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5161ULL: goto x86_l_1429;
	case 5163ULL: goto x86_l_142b;
	case 5168ULL: goto x86_l_1430;
	case 5171ULL: goto x86_l_1433;
	case 5177ULL: goto x86_l_1439;
	case 5182ULL: goto x86_l_143e;
	case 5187ULL: goto x86_l_1443;
	case 5190ULL: goto x86_l_1446;
	case 5196ULL: goto x86_l_144c;
	case 5198ULL: goto x86_l_144e;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5235ULL: goto x86_l_1473;
	case 5239ULL: goto x86_l_1477;
	case 5244ULL: goto x86_l_147c;
	case 5249ULL: goto x86_l_1481;
	case 5254ULL: goto x86_l_1486;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5269ULL: goto x86_l_1495;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5281ULL: goto x86_l_14a1;
	case 5287ULL: goto x86_l_14a7;
	case 5289ULL: goto x86_l_14a9;
	case 5296ULL: goto x86_l_14b0;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5318ULL: goto x86_l_14c6;
	case 5320ULL: goto x86_l_14c8;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5332ULL: goto x86_l_14d4;
	case 5335ULL: goto x86_l_14d7;
	case 5337ULL: goto x86_l_14d9;
	case 5339ULL: goto x86_l_14db;
	case 5344ULL: goto x86_l_14e0;
	case 5347ULL: goto x86_l_14e3;
	case 5351ULL: goto x86_l_14e7;
	case 5356ULL: goto x86_l_14ec;
	case 5358ULL: goto x86_l_14ee;
	case 5360ULL: goto x86_l_14f0;
	case 5363ULL: goto x86_l_14f3;
	case 5366ULL: goto x86_l_14f6;
	case 5371ULL: goto x86_l_14fb;
	case 5373ULL: goto x86_l_14fd;
	case 5375ULL: goto x86_l_14ff;
	case 5377ULL: goto x86_l_1501;
	case 5380ULL: goto x86_l_1504;
	case 5382ULL: goto x86_l_1506;
	case 5384ULL: goto x86_l_1508;
	case 5386ULL: goto x86_l_150a;
	case 5391ULL: goto x86_l_150f;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5408ULL: goto x86_l_1520;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5423ULL: goto x86_l_152f;
	case 5429ULL: goto x86_l_1535;
	case 5435ULL: goto x86_l_153b;
	case 5438ULL: goto x86_l_153e;
	case 5443ULL: goto x86_l_1543;
	case 5445ULL: goto x86_l_1545;
	case 5447ULL: goto x86_l_1547;
	case 5454ULL: goto x86_l_154e;
	case 5456ULL: goto x86_l_1550;
	case 5462ULL: goto x86_l_1556;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5469ULL: goto x86_l_155d;
	case 5474ULL: goto x86_l_1562;
	case 5476ULL: goto x86_l_1564;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5491ULL: goto x86_l_1573;
	case 5499ULL: goto x86_l_157b;
	case 5503ULL: goto x86_l_157f;
	case 5505ULL: goto x86_l_1581;
	case 5509ULL: goto x86_l_1585;
	case 5517ULL: goto x86_l_158d;
	case 5524ULL: goto x86_l_1594;
	case 5527ULL: goto x86_l_1597;
	case 5530ULL: goto x86_l_159a;
	case 5536ULL: goto x86_l_15a0;
	case 5542ULL: goto x86_l_15a6;
	case 5548ULL: goto x86_l_15ac;
	case 5553ULL: goto x86_l_15b1;
	case 5555ULL: goto x86_l_15b3;
	case 5562ULL: goto x86_l_15ba;
	case 5565ULL: goto x86_l_15bd;
	case 5570ULL: goto x86_l_15c2;
	case 5575ULL: goto x86_l_15c7;
	case 5580ULL: goto x86_l_15cc;
	case 5582ULL: goto x86_l_15ce;
	case 5586ULL: goto x86_l_15d2;
	case 5589ULL: goto x86_l_15d5;
	case 5595ULL: goto x86_l_15db;
	case 5602ULL: goto x86_l_15e2;
	case 5607ULL: goto x86_l_15e7;
	case 5612ULL: goto x86_l_15ec;
	case 5617ULL: goto x86_l_15f1;
	case 5622ULL: goto x86_l_15f6;
	case 5626ULL: goto x86_l_15fa;
	case 5631ULL: goto x86_l_15ff;
	case 5633ULL: goto x86_l_1601;
	case 5636ULL: goto x86_l_1604;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5652ULL: goto x86_l_1614;
	case 5662ULL: goto x86_l_161e;
	case 5667ULL: goto x86_l_1623;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5684ULL: goto x86_l_1634;
	case 5686ULL: goto x86_l_1636;
	case 5689ULL: goto x86_l_1639;
	case 5691ULL: goto x86_l_163b;
	case 5693ULL: goto x86_l_163d;
	case 5695ULL: goto x86_l_163f;
	case 5703ULL: goto x86_l_1647;
	case 5710ULL: goto x86_l_164e;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5727ULL: goto x86_l_165f;
	case 5729ULL: goto x86_l_1661;
	case 5731ULL: goto x86_l_1663;
	case 5736ULL: goto x86_l_1668;
	case 5740ULL: goto x86_l_166c;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5769ULL: goto x86_l_1689;
	case 5772ULL: goto x86_l_168c;
	case 5774ULL: goto x86_l_168e;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5788ULL: goto x86_l_169c;
	case 5798ULL: goto x86_l_16a6;
	case 5803ULL: goto x86_l_16ab;
	case 5810ULL: goto x86_l_16b2;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5822ULL: goto x86_l_16be;
	case 5825ULL: goto x86_l_16c1;
	case 5831ULL: goto x86_l_16c7;
	case 5833ULL: goto x86_l_16c9;
	case 5838ULL: goto x86_l_16ce;
	case 5841ULL: goto x86_l_16d1;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5855ULL: goto x86_l_16df;
	case 5861ULL: goto x86_l_16e5;
	case 5863ULL: goto x86_l_16e7;
	case 5867ULL: goto x86_l_16eb;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5887ULL: goto x86_l_16ff;
	case 5889ULL: goto x86_l_1701;
	case 5896ULL: goto x86_l_1708;
	case 5899ULL: goto x86_l_170b;
	case 5902ULL: goto x86_l_170e;
	case 5904ULL: goto x86_l_1710;
	case 5907ULL: goto x86_l_1713;
	case 5914ULL: goto x86_l_171a;
	case 5916ULL: goto x86_l_171c;
	case 5919ULL: goto x86_l_171f;
	case 5923ULL: goto x86_l_1723;
	case 5928ULL: goto x86_l_1728;
	case 5933ULL: goto x86_l_172d;
	case 5936ULL: goto x86_l_1730;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5948ULL: goto x86_l_173c;
	case 5951ULL: goto x86_l_173f;
	case 5954ULL: goto x86_l_1742;
	case 5958ULL: goto x86_l_1746;
	case 5960ULL: goto x86_l_1748;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5979ULL: goto x86_l_175b;
	case 5981ULL: goto x86_l_175d;
	case 5984ULL: goto x86_l_1760;
	case 5987ULL: goto x86_l_1763;
	case 5989ULL: goto x86_l_1765;
	case 5997ULL: goto x86_l_176d;
	case 6004ULL: goto x86_l_1774;
	case 6011ULL: goto x86_l_177b;
	case 6015ULL: goto x86_l_177f;
	case 6022ULL: goto x86_l_1786;
	case 6028ULL: goto x86_l_178c;
	case 6035ULL: goto x86_l_1793;
	case 6039ULL: goto x86_l_1797;
	case 6047ULL: goto x86_l_179f;
	case 6051ULL: goto x86_l_17a3;
	case 6059ULL: goto x86_l_17ab;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6081ULL: goto x86_l_17c1;
	case 6088ULL: goto x86_l_17c8;
	case 6094ULL: goto x86_l_17ce;
	case 6099ULL: goto x86_l_17d3;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6120ULL: goto x86_l_17e8;
	case 6125ULL: goto x86_l_17ed;
	case 6129ULL: goto x86_l_17f1;
	case 6132ULL: goto x86_l_17f4;
	case 6137ULL: goto x86_l_17f9;
	case 6139ULL: goto x86_l_17fb;
	case 6146ULL: goto x86_l_1802;
	case 6151ULL: goto x86_l_1807;
	case 6155ULL: goto x86_l_180b;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6181ULL: goto x86_l_1825;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6197ULL: goto x86_l_1835;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6223ULL: goto x86_l_184f;
	case 6230ULL: goto x86_l_1856;
	case 6235ULL: goto x86_l_185b;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6258ULL: goto x86_l_1872;
	case 6263ULL: goto x86_l_1877;
	case 6265ULL: goto x86_l_1879;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6281ULL: goto x86_l_1889;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6300ULL: goto x86_l_189c;
	case 6305ULL: goto x86_l_18a1;
	case 6307ULL: goto x86_l_18a3;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6342ULL: goto x86_l_18c6;
	case 6347ULL: goto x86_l_18cb;
	case 6349ULL: goto x86_l_18cd;
	case 6356ULL: goto x86_l_18d4;
	case 6361ULL: goto x86_l_18d9;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6375ULL: goto x86_l_18e7;
	case 6380ULL: goto x86_l_18ec;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6391ULL: goto x86_l_18f7;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6407ULL: goto x86_l_1907;
	case 6412ULL: goto x86_l_190c;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6426ULL: goto x86_l_191a;
	case 6431ULL: goto x86_l_191f;
	case 6433ULL: goto x86_l_1921;
	case 6440ULL: goto x86_l_1928;
	case 6445ULL: goto x86_l_192d;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6464ULL: goto x86_l_1940;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6475ULL: goto x86_l_194b;
	case 6480ULL: goto x86_l_1950;
	case 6487ULL: goto x86_l_1957;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6508ULL: goto x86_l_196c;
	case 6513ULL: goto x86_l_1971;
	case 6515ULL: goto x86_l_1973;
	case 6522ULL: goto x86_l_197a;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6557ULL: goto x86_l_199d;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6568ULL: goto x86_l_19a8;
	case 6570ULL: goto x86_l_19aa;
	case 6577ULL: goto x86_l_19b1;
	case 6584ULL: goto x86_l_19b8;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6613ULL: goto x86_l_19d5;
	case 6618ULL: goto x86_l_19da;
	case 6620ULL: goto x86_l_19dc;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6662ULL: goto x86_l_1a06;
	case 6665ULL: goto x86_l_1a09;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6680ULL: goto x86_l_1a18;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6690ULL: goto x86_l_1a22;
	case 6697ULL: goto x86_l_1a29;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6774ULL: goto x86_l_1a76;
	case 6783ULL: goto x86_l_1a7f;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6820ULL: goto x86_l_1aa4;
	case 6826ULL: goto x86_l_1aaa;
	case 6834ULL: goto x86_l_1ab2;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6857ULL: goto x86_l_1ac9;
	case 6862ULL: goto x86_l_1ace;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1429:
	/* 0x1429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142b:
	/* 0x142b: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1430:
	/* 0x1430: cmp    r15d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1433:
	/* 0x1433: jbe    14ca <event_execve+0x14ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_14ca;
	}
x86_l_1439:
	/* 0x1439: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_143e:
	/* 0x143e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1443:
	/* 0x1443: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1446:
	/* 0x1446: jne    1323 <event_execve+0x1323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4899ULL;
	}
x86_l_144c:
	/* 0x144c: jmp    14ca <event_execve+0x14ca> */
	goto x86_l_14ca;
x86_l_144e:
	/* 0x144e: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1452:
	/* 0x1452: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1457:
	/* 0x1457: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_145c:
	/* 0x145c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1461:
	/* 0x1461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1463:
	/* 0x1463: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1468:
	/* 0x1468: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_146d:
	/* 0x146d: je     150a <event_execve+0x150a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_150a;
	}
x86_l_1473:
	/* 0x1473: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1477:
	/* 0x1477: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_147c:
	/* 0x147c: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1481:
	/* 0x1481: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1486:
	/* 0x1486: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1489:
	/* 0x1489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148b:
	/* 0x148b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1490:
	/* 0x1490: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1495:
	/* 0x1495: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1499:
	/* 0x1499: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_149e:
	/* 0x149e: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_14a1:
	/* 0x14a1: jne    1323 <event_execve+0x1323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4899ULL;
	}
x86_l_14a7:
	/* 0x14a7: jmp    14ca <event_execve+0x14ca> */
	goto x86_l_14ca;
x86_l_14a9:
	/* 0x14a9: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_14b0:
	/* 0x14b0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b2:
	/* 0x14b2: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14b7:
	/* 0x14b7: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_14bc:
	/* 0x14bc: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_14c1:
	/* 0x14c1: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_14c6:
	/* 0x14c6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c8:
	/* 0x14c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ca:
	/* 0x14ca: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14cf:
	/* 0x14cf: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14d4:
	/* 0x14d4: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_14d7:
	/* 0x14d7: je     151e <event_execve+0x151e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_151e;
	}
x86_l_14d9:
	/* 0x14d9: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14db:
	/* 0x14db: cmp    BYTE PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_14e0:
	/* 0x14e0: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_14e3:
	/* 0x14e3: mov    edx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14e7:
	/* 0x14e7: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_14ec:
	/* 0x14ec: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_14ee:
	/* 0x14ee: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_14f0:
	/* 0x14f0: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_14f3:
	/* 0x14f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14f6:
	/* 0x14f6: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14fb:
	/* 0x14fb: je     1506 <event_execve+0x1506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1506;
	}
x86_l_14fd:
	/* 0x14fd: mov    bl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_8);
x86_l_14ff:
	/* 0x14ff: add    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1501:
	/* 0x1501: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1504:
	/* 0x1504: jmp    1527 <event_execve+0x1527> */
	goto x86_l_1527;
x86_l_1506:
	/* 0x1506: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1508:
	/* 0x1508: jmp    157b <event_execve+0x157b> */
	goto x86_l_157b;
x86_l_150a:
	/* 0x150a: mov    BYTE PTR [rsp+0x5c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991233ULL);
x86_l_150f:
	/* 0x150f: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1514:
	/* 0x1514: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1519:
	/* 0x1519: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_151c:
	/* 0x151c: jne    14d9 <event_execve+0x14d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14d9;
	}
x86_l_151e:
	/* 0x151e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1520:
	/* 0x1520: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1522:
	/* 0x1522: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1527:
	/* 0x1527: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_152f:
	/* 0x152f: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1535:
	/* 0x1535: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_153b:
	/* 0x153b: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_153e:
	/* 0x153e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1543:
	/* 0x1543: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1545:
	/* 0x1545: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1547:
	/* 0x1547: mov    eax,DWORD PTR [r14+0x15c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_154e:
	/* 0x154e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1550:
	/* 0x1550: or     ecx,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 4096ULL);
x86_l_1556:
	/* 0x1556: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1558:
	/* 0x1558: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_155b:
	/* 0x155b: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_155d:
	/* 0x155d: or     eax,0x400000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 4194304ULL);
x86_l_1562:
	/* 0x1562: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_1564:
	/* 0x1564: cmove  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_1567:
	/* 0x1567: and    eax,0xffffdbff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294958079ULL);
x86_l_156c:
	/* 0x156c: mov    DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_1573:
	/* 0x1573: mov    WORD PTR [r14+0x17c],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 380ULL);
x86_l_157b:
	/* 0x157b: mov    ebx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_157f:
	/* 0x157f: add    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1581:
	/* 0x1581: mov    DWORD PTR [r12],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1585:
	/* 0x1585: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158d:
	/* 0x158d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&ENV_VARS_ENABLED)));
x86_l_1594:
	/* 0x1594: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1597:
	/* 0x1597: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_159a:
	/* 0x159a: je     1774 <event_execve+0x1774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1774;
	}
x86_l_15a0:
	/* 0x15a0: cmp    ebx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1023ULL);
x86_l_15a6:
	/* 0x15a6: ja     1774 <event_execve+0x1774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1774;
	}
x86_l_15ac:
	/* 0x15ac: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_15b1:
	/* 0x15b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b3:
	/* 0x15b3: lea    rdx,[rax+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_15ba:
	/* 0x15ba: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15bd:
	/* 0x15bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15c2:
	/* 0x15c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15c7:
	/* 0x15c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15cc:
	/* 0x15cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ce:
	/* 0x15ce: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d2:
	/* 0x15d2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15d5:
	/* 0x15d5: je     1774 <event_execve+0x1774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1774;
	}
x86_l_15db:
	/* 0x15db: add    rcx,0x198 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 408ULL);
x86_l_15e2:
	/* 0x15e2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e7:
	/* 0x15e7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15ec:
	/* 0x15ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f1:
	/* 0x15f1: mov    edx,0x198 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 408ULL);
x86_l_15f6:
	/* 0x15f6: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15fa:
	/* 0x15fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15ff:
	/* 0x15ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1601:
	/* 0x1601: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1604:
	/* 0x1604: je     1663 <event_execve+0x1663> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1663;
	}
x86_l_1606:
	/* 0x1606: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1608:
	/* 0x1608: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_160d:
	/* 0x160d: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_1614:
	/* 0x1614: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_161e:
	/* 0x161e: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1623:
	/* 0x1623: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_162a:
	/* 0x162a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_162f:
	/* 0x162f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1634:
	/* 0x1634: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1636:
	/* 0x1636: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1639:
	/* 0x1639: je     163f <event_execve+0x163f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_163f;
	}
x86_l_163b:
	/* 0x163b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_163d:
	/* 0x163d: jmp    1663 <event_execve+0x1663> */
	goto x86_l_1663;
x86_l_163f:
	/* 0x163f: mov    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1647:
	/* 0x1647: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_164e:
	/* 0x164e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1650:
	/* 0x1650: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1655:
	/* 0x1655: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_165a:
	/* 0x165a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_165f:
	/* 0x165f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1661:
	/* 0x1661: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1663:
	/* 0x1663: mov    edx,0x1a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 416ULL);
x86_l_1668:
	/* 0x1668: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166c:
	/* 0x166c: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_166f:
	/* 0x166f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1674:
	/* 0x1674: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1679:
	/* 0x1679: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_167e:
	/* 0x167e: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1682:
	/* 0x1682: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1687:
	/* 0x1687: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1689:
	/* 0x1689: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_168c:
	/* 0x168c: je     16c9 <event_execve+0x16c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16c9;
	}
x86_l_168e:
	/* 0x168e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1690:
	/* 0x1690: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1695:
	/* 0x1695: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_169c:
	/* 0x169c: movabs rax,0x40000009b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869339ULL);
x86_l_16a6:
	/* 0x16a6: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_16ab:
	/* 0x16ab: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16b2:
	/* 0x16b2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16b7:
	/* 0x16b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16bc:
	/* 0x16bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16be:
	/* 0x16be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16c1:
	/* 0x16c1: je     1ef2 <event_execve+0x1ef2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7922ULL;
	}
x86_l_16c7:
	/* 0x16c7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16c9:
	/* 0x16c9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ce:
	/* 0x16ce: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_16d1:
	/* 0x16d1: je     1774 <event_execve+0x1774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1774;
	}
x86_l_16d7:
	/* 0x16d7: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16dc:
	/* 0x16dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16df:
	/* 0x16df: je     1774 <event_execve+0x1774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1774;
	}
x86_l_16e5:
	/* 0x16e5: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_16e7:
	/* 0x16e7: lea    rsi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_16eb:
	/* 0x16eb: add    rsi,0x140 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 320ULL);
x86_l_16f2:
	/* 0x16f2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_16f5:
	/* 0x16f5: sub    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_16f8:
	/* 0x16f8: cmp    r13,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1023ULL);
x86_l_16ff:
	/* 0x16ff: ja     1748 <event_execve+0x1748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1748;
	}
x86_l_1701:
	/* 0x1701: lea    rcx,[r14+0x540] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1344ULL);
x86_l_1708:
	/* 0x1708: sub    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_170b:
	/* 0x170b: cmp    r13,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_170e:
	/* 0x170e: jae    1748 <event_execve+0x1748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1748;
	}
x86_l_1710:
	/* 0x1710: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1713:
	/* 0x1713: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_171a:
	/* 0x171a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_171c:
	/* 0x171c: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_171f:
	/* 0x171f: cmove  r13d,ebx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_32, X86_CC_E);
x86_l_1723:
	/* 0x1723: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1728:
	/* 0x1728: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_172d:
	/* 0x172d: mov    rdi,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1730:
	/* 0x1730: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1733:
	/* 0x1733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1735:
	/* 0x1735: and    eax,0x80000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483648ULL);
x86_l_173a:
	/* 0x173a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_173c:
	/* 0x173c: shr    ecx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 28ULL);
x86_l_173f:
	/* 0x173f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1742:
	/* 0x1742: cmovne r13d,ebx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_32, X86_CC_NE);
x86_l_1746:
	/* 0x1746: jmp    1765 <event_execve+0x1765> */
	goto x86_l_1765;
x86_l_1748:
	/* 0x1748: mov    rdi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1750:
	/* 0x1750: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1753:
	/* 0x1753: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5976ULL);
	__x86_sim_call_depth++;
	return 8253ULL;
x86_l_1758:
	/* 0x1758: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_175b:
	/* 0x175b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_175d:
	/* 0x175d: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1760:
	/* 0x1760: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1763:
	/* 0x1763: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1765:
	/* 0x1765: mov    WORD PTR [r14+0x17e],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 382ULL);
x86_l_176d:
	/* 0x176d: or     DWORD PTR [r14+0x15c],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_1774:
	/* 0x1774: mov    eax,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_177b:
	/* 0x177b: lea    ecx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_177f:
	/* 0x177f: mov    DWORD PTR [r14+0x140],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1786:
	/* 0x1786: mov    WORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_178c:
	/* 0x178c: mov    rcx,QWORD PTR [r14+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_1793:
	/* 0x1793: mov    QWORD PTR [r14+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1797:
	/* 0x1797: lea    eax,[rax+r13*1+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 320ULL);
x86_l_179f:
	/* 0x179f: mov    DWORD PTR [r14+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17a3:
	/* 0x17a3: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_17ab:
	/* 0x17ab: lea    rdx,[r13+0xce0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_17b2:
	/* 0x17b2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17b7:
	/* 0x17b7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17bc:
	/* 0x17bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c1:
	/* 0x17c1: lea    rbx,[r14+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17c8:
	/* 0x17c8: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_17ce:
	/* 0x17ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17d3:
	/* 0x17d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d5:
	/* 0x17d5: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17da:
	/* 0x17da: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17de:
	/* 0x17de: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_17e3:
	/* 0x17e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17e8:
	/* 0x17e8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17ed:
	/* 0x17ed: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17f1:
	/* 0x17f1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17f4:
	/* 0x17f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17f9:
	/* 0x17f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17fb:
	/* 0x17fb: lea    rdi,[r14+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1802:
	/* 0x1802: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1807:
	/* 0x1807: add    rcx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_180b:
	/* 0x180b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1810:
	/* 0x1810: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1815:
	/* 0x1815: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_181a:
	/* 0x181a: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_181e:
	/* 0x181e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1823:
	/* 0x1823: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1825:
	/* 0x1825: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_182c:
	/* 0x182c: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1831:
	/* 0x1831: add    rcx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1835:
	/* 0x1835: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_183a:
	/* 0x183a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_183f:
	/* 0x183f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1844:
	/* 0x1844: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1848:
	/* 0x1848: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_184d:
	/* 0x184d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184f:
	/* 0x184f: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1856:
	/* 0x1856: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_185b:
	/* 0x185b: add    rcx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_185f:
	/* 0x185f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1864:
	/* 0x1864: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1869:
	/* 0x1869: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_186e:
	/* 0x186e: add    rdx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_1872:
	/* 0x1872: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1877:
	/* 0x1877: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1879:
	/* 0x1879: lea    rdi,[r14+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1880:
	/* 0x1880: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1885:
	/* 0x1885: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1889:
	/* 0x1889: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_188e:
	/* 0x188e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1893:
	/* 0x1893: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1898:
	/* 0x1898: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_189c:
	/* 0x189c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18a1:
	/* 0x18a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a3:
	/* 0x18a3: lea    rdi,[r14+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_18aa:
	/* 0x18aa: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18af:
	/* 0x18af: add    rcx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_18b3:
	/* 0x18b3: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_18b8:
	/* 0x18b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18bd:
	/* 0x18bd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c2:
	/* 0x18c2: add    rdx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_18c6:
	/* 0x18c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18cb:
	/* 0x18cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18cd:
	/* 0x18cd: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_18d4:
	/* 0x18d4: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18d9:
	/* 0x18d9: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_18dd:
	/* 0x18dd: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_18e2:
	/* 0x18e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e7:
	/* 0x18e7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18ec:
	/* 0x18ec: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_18f0:
	/* 0x18f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18f5:
	/* 0x18f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f7:
	/* 0x18f7: lea    rdi,[r14+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_18fe:
	/* 0x18fe: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1903:
	/* 0x1903: add    rcx,0x24 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 36ULL);
x86_l_1907:
	/* 0x1907: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_190c:
	/* 0x190c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1911:
	/* 0x1911: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1916:
	/* 0x1916: add    rdx,0x24 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 36ULL);
x86_l_191a:
	/* 0x191a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_191f:
	/* 0x191f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1921:
	/* 0x1921: lea    rdi,[r14+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1928:
	/* 0x1928: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_192d:
	/* 0x192d: add    rcx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1931:
	/* 0x1931: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1936:
	/* 0x1936: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_193b:
	/* 0x193b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1940:
	/* 0x1940: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1944:
	/* 0x1944: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1949:
	/* 0x1949: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194b:
	/* 0x194b: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1950:
	/* 0x1950: lea    rdi,[r14+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1957:
	/* 0x1957: lea    rdx,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_195b:
	/* 0x195b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1960:
	/* 0x1960: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1965:
	/* 0x1965: lea    r15,[r14+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_196c:
	/* 0x196c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1971:
	/* 0x1971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1973:
	/* 0x1973: lea    rdi,[r14+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_197a:
	/* 0x197a: lea    rdx,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_197e:
	/* 0x197e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1983:
	/* 0x1983: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1988:
	/* 0x1988: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_198d:
	/* 0x198d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_198f:
	/* 0x198f: add    rbx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1993:
	/* 0x1993: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1998:
	/* 0x1998: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_199d:
	/* 0x199d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19a0:
	/* 0x19a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19a5:
	/* 0x19a5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_19a8:
	/* 0x19a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19aa:
	/* 0x19aa: mov    eax,DWORD PTR [r14+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_19b1:
	/* 0x19b1: mov    DWORD PTR [r14+0x154],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 340ULL);
x86_l_19b8:
	/* 0x19b8: lea    rdx,[r13+0xd48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_19bf:
	/* 0x19bf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19c4:
	/* 0x19c4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19c9:
	/* 0x19c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19ce:
	/* 0x19ce: lea    rbx,[r14+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_19d5:
	/* 0x19d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19da:
	/* 0x19da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19dc:
	/* 0x19dc: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e1:
	/* 0x19e1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19e6:
	/* 0x19e6: mov    edx,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 72ULL);
x86_l_19eb:
	/* 0x19eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f0:
	/* 0x19f0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f5:
	/* 0x19f5: mov    esi,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 72ULL);
x86_l_19fa:
	/* 0x19fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fc:
	/* 0x19fc: mov    edx,0x1a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 424ULL);
x86_l_1a01:
	/* 0x1a01: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a06:
	/* 0x1a06: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a09:
	/* 0x1a09: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a0e:
	/* 0x1a0e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a13:
	/* 0x1a13: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_1a18:
	/* 0x1a18: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a1b:
	/* 0x1a1b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a20:
	/* 0x1a20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a22:
	/* 0x1a22: lea    rdi,[r14+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_1a29:
	/* 0x1a29: mov    edx,0x470 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1136ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a33:
	/* 0x1a33: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a36:
	/* 0x1a36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a3b:
	/* 0x1a3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a40:
	/* 0x1a40: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1a45:
	/* 0x1a45: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a4a:
	/* 0x1a4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4c:
	/* 0x1a4c: lea    rdi,[r14+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1a53:
	/* 0x1a53: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a58:
	/* 0x1a58: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a5c:
	/* 0x1a5c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1a61:
	/* 0x1a61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a66:
	/* 0x1a66: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a6b:
	/* 0x1a6b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a6f:
	/* 0x1a6f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a74:
	/* 0x1a74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a76:
	/* 0x1a76: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1a7f:
	/* 0x1a7f: lea    rdx,[r13+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_1a86:
	/* 0x1a86: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a90:
	/* 0x1a90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a95:
	/* 0x1a95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a9a:
	/* 0x1a9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a9c:
	/* 0x1a9c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aa1:
	/* 0x1aa1: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1aa4:
	/* 0x1aa4: je     1b3b <event_execve+0x1b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6971ULL;
	}
x86_l_1aaa:
	/* 0x1aaa: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1ab2:
	/* 0x1ab2: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ab6:
	/* 0x1ab6: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1abb:
	/* 0x1abb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ac5:
	/* 0x1ac5: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ac9:
	/* 0x1ac9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ace:
	/* 0x1ace: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 6864ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6878ULL: goto x86_l_1ade;
	case 6881ULL: goto x86_l_1ae1;
	case 6888ULL: goto x86_l_1ae8;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6901ULL: goto x86_l_1af5;
	case 6906ULL: goto x86_l_1afa;
	case 6911ULL: goto x86_l_1aff;
	case 6915ULL: goto x86_l_1b03;
	case 6918ULL: goto x86_l_1b06;
	case 6925ULL: goto x86_l_1b0d;
	case 6930ULL: goto x86_l_1b12;
	case 6932ULL: goto x86_l_1b14;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6969ULL: goto x86_l_1b39;
	case 6971ULL: goto x86_l_1b3b;
	case 6982ULL: goto x86_l_1b46;
	case 6990ULL: goto x86_l_1b4e;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7006ULL: goto x86_l_1b5e;
	case 7011ULL: goto x86_l_1b63;
	case 7016ULL: goto x86_l_1b68;
	case 7021ULL: goto x86_l_1b6d;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7032ULL: goto x86_l_1b78;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7049ULL: goto x86_l_1b89;
	case 7052ULL: goto x86_l_1b8c;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7074ULL: goto x86_l_1ba2;
	case 7081ULL: goto x86_l_1ba9;
	case 7086ULL: goto x86_l_1bae;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7105ULL: goto x86_l_1bc1;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7116ULL: goto x86_l_1bcc;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7132ULL: goto x86_l_1bdc;
	case 7137ULL: goto x86_l_1be1;
	case 7142ULL: goto x86_l_1be6;
	case 7147ULL: goto x86_l_1beb;
	case 7151ULL: goto x86_l_1bef;
	case 7156ULL: goto x86_l_1bf4;
	case 7158ULL: goto x86_l_1bf6;
	case 7165ULL: goto x86_l_1bfd;
	case 7170ULL: goto x86_l_1c02;
	case 7174ULL: goto x86_l_1c06;
	case 7179ULL: goto x86_l_1c0b;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7193ULL: goto x86_l_1c19;
	case 7198ULL: goto x86_l_1c1e;
	case 7200ULL: goto x86_l_1c20;
	case 7208ULL: goto x86_l_1c28;
	case 7215ULL: goto x86_l_1c2f;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7244ULL: goto x86_l_1c4c;
	case 7247ULL: goto x86_l_1c4f;
	case 7252ULL: goto x86_l_1c54;
	case 7257ULL: goto x86_l_1c59;
	case 7262ULL: goto x86_l_1c5e;
	case 7266ULL: goto x86_l_1c62;
	case 7271ULL: goto x86_l_1c67;
	case 7273ULL: goto x86_l_1c69;
	case 7280ULL: goto x86_l_1c70;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7313ULL: goto x86_l_1c91;
	case 7315ULL: goto x86_l_1c93;
	case 7319ULL: goto x86_l_1c97;
	case 7327ULL: goto x86_l_1c9f;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7337ULL: goto x86_l_1ca9;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7363ULL: goto x86_l_1cc3;
	case 7366ULL: goto x86_l_1cc6;
	case 7368ULL: goto x86_l_1cc8;
	case 7371ULL: goto x86_l_1ccb;
	case 7379ULL: goto x86_l_1cd3;
	case 7383ULL: goto x86_l_1cd7;
	case 7385ULL: goto x86_l_1cd9;
	case 7387ULL: goto x86_l_1cdb;
	case 7396ULL: goto x86_l_1ce4;
	case 7403ULL: goto x86_l_1ceb;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7416ULL: goto x86_l_1cf8;
	case 7421ULL: goto x86_l_1cfd;
	case 7424ULL: goto x86_l_1d00;
	case 7426ULL: goto x86_l_1d02;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7439ULL: goto x86_l_1d0f;
	case 7442ULL: goto x86_l_1d12;
	case 7444ULL: goto x86_l_1d14;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7471ULL: goto x86_l_1d2f;
	case 7475ULL: goto x86_l_1d33;
	case 7480ULL: goto x86_l_1d38;
	case 7482ULL: goto x86_l_1d3a;
	case 7487ULL: goto x86_l_1d3f;
	case 7490ULL: goto x86_l_1d42;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7503ULL: goto x86_l_1d4f;
	case 7505ULL: goto x86_l_1d51;
	case 7509ULL: goto x86_l_1d55;
	case 7512ULL: goto x86_l_1d58;
	case 7518ULL: goto x86_l_1d5e;
	case 7523ULL: goto x86_l_1d63;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7540ULL: goto x86_l_1d74;
	case 7542ULL: goto x86_l_1d76;
	case 7545ULL: goto x86_l_1d79;
	case 7551ULL: goto x86_l_1d7f;
	case 7554ULL: goto x86_l_1d82;
	case 7558ULL: goto x86_l_1d86;
	case 7563ULL: goto x86_l_1d8b;
	case 7566ULL: goto x86_l_1d8e;
	case 7572ULL: goto x86_l_1d94;
	case 7574ULL: goto x86_l_1d96;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7597ULL: goto x86_l_1dad;
	case 7601ULL: goto x86_l_1db1;
	case 7606ULL: goto x86_l_1db6;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7642ULL: goto x86_l_1dda;
	case 7647ULL: goto x86_l_1ddf;
	case 7649ULL: goto x86_l_1de1;
	case 7654ULL: goto x86_l_1de6;
	case 7657ULL: goto x86_l_1de9;
	case 7663ULL: goto x86_l_1def;
	case 7665ULL: goto x86_l_1df1;
	case 7674ULL: goto x86_l_1dfa;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7701ULL: goto x86_l_1e15;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7717ULL: goto x86_l_1e25;
	case 7720ULL: goto x86_l_1e28;
	case 7726ULL: goto x86_l_1e2e;
	case 7730ULL: goto x86_l_1e32;
	case 7735ULL: goto x86_l_1e37;
	case 7740ULL: goto x86_l_1e3c;
	case 7745ULL: goto x86_l_1e41;
	case 7750ULL: goto x86_l_1e46;
	case 7752ULL: goto x86_l_1e48;
	case 7757ULL: goto x86_l_1e4d;
	case 7761ULL: goto x86_l_1e51;
	case 7764ULL: goto x86_l_1e54;
	case 7770ULL: goto x86_l_1e5a;
	case 7776ULL: goto x86_l_1e60;
	case 7778ULL: goto x86_l_1e62;
	case 7780ULL: goto x86_l_1e64;
	case 7784ULL: goto x86_l_1e68;
	case 7791ULL: goto x86_l_1e6f;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7812ULL: goto x86_l_1e84;
	case 7814ULL: goto x86_l_1e86;
	case 7818ULL: goto x86_l_1e8a;
	case 7822ULL: goto x86_l_1e8e;
	case 7827ULL: goto x86_l_1e93;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7841ULL: goto x86_l_1ea1;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7852ULL: goto x86_l_1eac;
	case 7857ULL: goto x86_l_1eb1;
	case 7860ULL: goto x86_l_1eb4;
	case 7862ULL: goto x86_l_1eb6;
	case 7867ULL: goto x86_l_1ebb;
	case 7870ULL: goto x86_l_1ebe;
	case 7872ULL: goto x86_l_1ec0;
	case 7875ULL: goto x86_l_1ec3;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7894ULL: goto x86_l_1ed6;
	case 7896ULL: goto x86_l_1ed8;
	case 7898ULL: goto x86_l_1eda;
	case 7900ULL: goto x86_l_1edc;
	case 7902ULL: goto x86_l_1ede;
	case 7904ULL: goto x86_l_1ee0;
	case 7908ULL: goto x86_l_1ee4;
	case 7911ULL: goto x86_l_1ee7;
	case 7917ULL: goto x86_l_1eed;
	case 7922ULL: goto x86_l_1ef2;
	case 7930ULL: goto x86_l_1efa;
	case 7937ULL: goto x86_l_1f01;
	case 7939ULL: goto x86_l_1f03;
	case 7944ULL: goto x86_l_1f08;
	case 7949ULL: goto x86_l_1f0d;
	case 7954ULL: goto x86_l_1f12;
	case 7956ULL: goto x86_l_1f14;
	case 7958ULL: goto x86_l_1f16;
	case 7963ULL: goto x86_l_1f1b;
	case 7966ULL: goto x86_l_1f1e;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7987ULL: goto x86_l_1f33;
	case 7990ULL: goto x86_l_1f36;
	case 7996ULL: goto x86_l_1f3c;
	case 7998ULL: goto x86_l_1f3e;
	case 8005ULL: goto x86_l_1f45;
	case 8016ULL: goto x86_l_1f50;
	case 8027ULL: goto x86_l_1f5b;
	case 8034ULL: goto x86_l_1f62;
	case 8036ULL: goto x86_l_1f64;
	case 8041ULL: goto x86_l_1f69;
	case 8044ULL: goto x86_l_1f6c;
	case 8046ULL: goto x86_l_1f6e;
	case 8048ULL: goto x86_l_1f70;
	case 8050ULL: goto x86_l_1f72;
	case 8057ULL: goto x86_l_1f79;
	case 8059ULL: goto x86_l_1f7b;
	case 8060ULL: goto x86_l_1f7c;
	case 8065ULL: goto x86_l_1f81;
	case 8067ULL: goto x86_l_1f83;
	case 8069ULL: goto x86_l_1f85;
	case 8071ULL: goto x86_l_1f87;
	case 8073ULL: goto x86_l_1f89;
	case 8074ULL: goto x86_l_1f8a;
	case 8078ULL: goto x86_l_1f8e;
	case 8081ULL: goto x86_l_1f91;
	case 8084ULL: goto x86_l_1f94;
	case 8087ULL: goto x86_l_1f97;
	case 8095ULL: goto x86_l_1f9f;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8114ULL: goto x86_l_1fb2;
	case 8117ULL: goto x86_l_1fb5;
	case 8119ULL: goto x86_l_1fb7;
	case 8122ULL: goto x86_l_1fba;
	case 8128ULL: goto x86_l_1fc0;
	case 8133ULL: goto x86_l_1fc5;
	case 8135ULL: goto x86_l_1fc7;
	case 8138ULL: goto x86_l_1fca;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8151ULL: goto x86_l_1fd7;
	case 8153ULL: goto x86_l_1fd9;
	case 8157ULL: goto x86_l_1fdd;
	case 8161ULL: goto x86_l_1fe1;
	case 8166ULL: goto x86_l_1fe6;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8177ULL: goto x86_l_1ff1;
	case 8181ULL: goto x86_l_1ff5;
	case 8185ULL: goto x86_l_1ff9;
	case 8189ULL: goto x86_l_1ffd;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8198ULL: goto x86_l_2006;
	case 8203ULL: goto x86_l_200b;
	case 8205ULL: goto x86_l_200d;
	case 8208ULL: goto x86_l_2010;
	case 8210ULL: goto x86_l_2012;
	case 8212ULL: goto x86_l_2014;
	case 8214ULL: goto x86_l_2016;
	case 8216ULL: goto x86_l_2018;
	case 8219ULL: goto x86_l_201b;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8235ULL: goto x86_l_202b;
	case 8237ULL: goto x86_l_202d;
	case 8239ULL: goto x86_l_202f;
	case 8243ULL: goto x86_l_2033;
	case 8244ULL: goto x86_l_2034;
	case 8246ULL: goto x86_l_2036;
	case 8248ULL: goto x86_l_2038;
	case 8250ULL: goto x86_l_203a;
	case 8252ULL: goto x86_l_203c;
	case 8253ULL: goto x86_l_203d;
	case 8254ULL: goto x86_l_203e;
	case 8256ULL: goto x86_l_2040;
	case 8258ULL: goto x86_l_2042;
	case 8260ULL: goto x86_l_2044;
	case 8262ULL: goto x86_l_2046;
	case 8263ULL: goto x86_l_2047;
	case 8264ULL: goto x86_l_2048;
	case 8267ULL: goto x86_l_204b;
	case 8270ULL: goto x86_l_204e;
	case 8273ULL: goto x86_l_2051;
	case 8276ULL: goto x86_l_2054;
	case 8284ULL: goto x86_l_205c;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8301ULL: goto x86_l_206d;
	case 8303ULL: goto x86_l_206f;
	case 8306ULL: goto x86_l_2072;
	case 8308ULL: goto x86_l_2074;
	case 8311ULL: goto x86_l_2077;
	case 8317ULL: goto x86_l_207d;
	case 8322ULL: goto x86_l_2082;
	case 8324ULL: goto x86_l_2084;
	case 8327ULL: goto x86_l_2087;
	case 8331ULL: goto x86_l_208b;
	case 8335ULL: goto x86_l_208f;
	case 8339ULL: goto x86_l_2093;
	case 8341ULL: goto x86_l_2095;
	case 8346ULL: goto x86_l_209a;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8357ULL: goto x86_l_20a5;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8369ULL: goto x86_l_20b1;
	case 8373ULL: goto x86_l_20b5;
	case 8377ULL: goto x86_l_20b9;
	case 8380ULL: goto x86_l_20bc;
	case 8383ULL: goto x86_l_20bf;
	case 8386ULL: goto x86_l_20c2;
	case 8389ULL: goto x86_l_20c5;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8398ULL: goto x86_l_20ce;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8416ULL: goto x86_l_20e0;
	case 8419ULL: goto x86_l_20e3;
	case 8421ULL: goto x86_l_20e5;
	case 8423ULL: goto x86_l_20e7;
	case 8425ULL: goto x86_l_20e9;
	case 8427ULL: goto x86_l_20eb;
	case 8434ULL: goto x86_l_20f2;
	case 8436ULL: goto x86_l_20f4;
	case 8438ULL: goto x86_l_20f6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ad0:
	/* 0x1ad0: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ad5:
	/* 0x1ad5: movsxd rcx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 104ULL);
x86_l_1ada:
	/* 0x1ada: shl    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1ade:
	/* 0x1ade: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ae1:
	/* 0x1ae1: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1aeb:
	/* 0x1aeb: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1af0:
	/* 0x1af0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1af5:
	/* 0x1af5: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1afa:
	/* 0x1afa: movsxd rdx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 104ULL);
x86_l_1aff:
	/* 0x1aff: shl    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1b03:
	/* 0x1b03: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b06:
	/* 0x1b06: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1b0d:
	/* 0x1b0d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b12:
	/* 0x1b12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b14:
	/* 0x1b14: lea    rdi,[r14+0x114] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 276ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b20:
	/* 0x1b20: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1b24:
	/* 0x1b24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b29:
	/* 0x1b29: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b2e:
	/* 0x1b2e: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1b32:
	/* 0x1b32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b37:
	/* 0x1b37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b39:
	/* 0x1b39: jmp    1b46 <event_execve+0x1b46> */
	goto x86_l_1b46;
x86_l_1b3b:
	/* 0x1b3b: mov    DWORD PTR [r14+0x114],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_1b46:
	/* 0x1b46: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b4e:
	/* 0x1b4e: lea    rdi,[r14+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1b55:
	/* 0x1b55: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b5a:
	/* 0x1b5a: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1b5e:
	/* 0x1b5e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b63:
	/* 0x1b63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b68:
	/* 0x1b68: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b6d:
	/* 0x1b6d: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1b71:
	/* 0x1b71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b76:
	/* 0x1b76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b78:
	/* 0x1b78: lea    rdi,[r14+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    edx,0xa8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 168ULL);
x86_l_1b84:
	/* 0x1b84: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b89:
	/* 0x1b89: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b8c:
	/* 0x1b8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b91:
	/* 0x1b91: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b96:
	/* 0x1b96: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1b9b:
	/* 0x1b9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ba0:
	/* 0x1ba0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba2:
	/* 0x1ba2: lea    rdi,[r14+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1ba9:
	/* 0x1ba9: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bae:
	/* 0x1bae: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bc1:
	/* 0x1bc1: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bca:
	/* 0x1bca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcc:
	/* 0x1bcc: lea    rdi,[r14+0x124] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bd8:
	/* 0x1bd8: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1be1:
	/* 0x1be1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be6:
	/* 0x1be6: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1beb:
	/* 0x1beb: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1bef:
	/* 0x1bef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bf4:
	/* 0x1bf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf6:
	/* 0x1bf6: lea    rdi,[r14+0x128] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1bfd:
	/* 0x1bfd: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c02:
	/* 0x1c02: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c06:
	/* 0x1c06: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1c0b:
	/* 0x1c0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c10:
	/* 0x1c10: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c15:
	/* 0x1c15: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c19:
	/* 0x1c19: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c1e:
	/* 0x1c1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c20:
	/* 0x1c20: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c28:
	/* 0x1c28: lea    rdx,[r13+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x1c43: mov    edx,0x4a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1184ULL);
x86_l_1c48:
	/* 0x1c48: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c4c:
	/* 0x1c4c: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c4f:
	/* 0x1c4f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c54:
	/* 0x1c54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c59:
	/* 0x1c59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c5e:
	/* 0x1c5e: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c62:
	/* 0x1c62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c67:
	/* 0x1c67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c69:
	/* 0x1c69: lea    rdi,[r14+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_1c70:
	/* 0x1c70: mov    edx,0xe8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 232ULL);
x86_l_1c75:
	/* 0x1c75: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c7a:
	/* 0x1c7a: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c7d:
	/* 0x1c7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c82:
	/* 0x1c82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c87:
	/* 0x1c87: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c91:
	/* 0x1c91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c93:
	/* 0x1c93: lea    r12,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c97:
	/* 0x1c97: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1c9f:
	/* 0x1c9f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca1:
	/* 0x1ca1: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1ca9:
	/* 0x1ca9: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cab:
	/* 0x1cab: call   1cb0 <event_execve+0x1cb0> */
	X86_SIM_L_EXEC_CALL_MEMSET(144ULL);
x86_l_1cb0:
	/* 0x1cb0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_1cb7:
	/* 0x1cb7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cbc:
	/* 0x1cbc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cc1:
	/* 0x1cc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc3:
	/* 0x1cc3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cc6:
	/* 0x1cc6: je     1cd9 <event_execve+0x1cd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cd9;
	}
x86_l_1cc8:
	/* 0x1cc8: mov    ebx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ccb:
	/* 0x1ccb: cmp    QWORD PTR [rax+0x20],0x63677270 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 139106677360ULL);
x86_l_1cd3:
	/* 0x1cd3: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_1cd7:
	/* 0x1cd7: jmp    1cdb <event_execve+0x1cdb> */
	goto x86_l_1cdb;
x86_l_1cd9:
	/* 0x1cd9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cdb:
	/* 0x1cdb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ce4:
	/* 0x1ce4: add    r13,0xf60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3936ULL);
x86_l_1ceb:
	/* 0x1ceb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cee:
	/* 0x1cee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cf3:
	/* 0x1cf3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cf8:
	/* 0x1cf8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cfd:
	/* 0x1cfd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d00:
	/* 0x1d00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d02:
	/* 0x1d02: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d06:
	/* 0x1d06: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1d09:
	/* 0x1d09: je     1f3c <event_execve+0x1f3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f3c;
	}
x86_l_1d0f:
	/* 0x1d0f: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1d12:
	/* 0x1d12: je     1d8b <event_execve+0x1d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d8b;
	}
x86_l_1d14:
	/* 0x1d14: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1d1b:
	/* 0x1d1b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d20:
	/* 0x1d20: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d25:
	/* 0x1d25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    edx,0x88 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 136ULL);
x86_l_1d2f:
	/* 0x1d2f: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d33:
	/* 0x1d33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d38:
	/* 0x1d38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3a:
	/* 0x1d3a: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d3f:
	/* 0x1d3f: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1d42:
	/* 0x1d42: je     1f3c <event_execve+0x1f3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f3c;
	}
x86_l_1d48:
	/* 0x1d48: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_1d4d:
	/* 0x1d4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4f:
	/* 0x1d4f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d51:
	/* 0x1d51: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d55:
	/* 0x1d55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d58:
	/* 0x1d58: je     1e5a <event_execve+0x1e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e5a;
	}
x86_l_1d5e:
	/* 0x1d5e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d63:
	/* 0x1d63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgtracker_map)));
x86_l_1d6a:
	/* 0x1d6a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d6f:
	/* 0x1d6f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d74:
	/* 0x1d74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d76:
	/* 0x1d76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d79:
	/* 0x1d79: je     1e62 <event_execve+0x1e62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e62;
	}
x86_l_1d7f:
	/* 0x1d7f: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d82:
	/* 0x1d82: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d86:
	/* 0x1d86: jmp    1e68 <event_execve+0x1e68> */
	goto x86_l_1e68;
x86_l_1d8b:
	/* 0x1d8b: cmp    ebx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 11ULL);
x86_l_1d8e:
	/* 0x1d8e: ja     1f3c <event_execve+0x1f3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f3c;
	}
x86_l_1d94:
	/* 0x1d94: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_1d96:
	/* 0x1d96: lea    rcx,[rcx+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_1d9a:
	/* 0x1d9a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da4:
	/* 0x1da4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1da9:
	/* 0x1da9: shl    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 3ULL);
x86_l_1dad:
	/* 0x1dad: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1db1:
	/* 0x1db1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1db6:
	/* 0x1db6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db8:
	/* 0x1db8: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dbd:
	/* 0x1dbd: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1dc0:
	/* 0x1dc0: je     1f29 <event_execve+0x1f29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f29;
	}
x86_l_1dc6:
	/* 0x1dc6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dcb:
	/* 0x1dcb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dd5:
	/* 0x1dd5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dda:
	/* 0x1dda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ddf:
	/* 0x1ddf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de1:
	/* 0x1de1: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1de6:
	/* 0x1de6: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1de9:
	/* 0x1de9: je     1f3c <event_execve+0x1f3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f3c;
	}
x86_l_1def:
	/* 0x1def: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1df1:
	/* 0x1df1: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1dfa:
	/* 0x1dfa: lea    rdx,[rbx+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1e01:
	/* 0x1e01: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e06:
	/* 0x1e06: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e10:
	/* 0x1e10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e15:
	/* 0x1e15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e17:
	/* 0x1e17: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e1c:
	/* 0x1e1c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e25:
	/* 0x1e25: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1e28:
	/* 0x1e28: je     1ede <event_execve+0x1ede> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ede;
	}
x86_l_1e2e:
	/* 0x1e2e: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1e32:
	/* 0x1e32: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e37:
	/* 0x1e37: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e3c:
	/* 0x1e3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e41:
	/* 0x1e41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e46:
	/* 0x1e46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e48:
	/* 0x1e48: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e4d:
	/* 0x1e4d: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e51:
	/* 0x1e51: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e54:
	/* 0x1e54: jne    1d5e <event_execve+0x1d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5e;
	}
x86_l_1e5a:
	/* 0x1e5a: or     ebp,0x200000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 2097152ULL);
x86_l_1e60:
	/* 0x1e60: jmp    1e68 <event_execve+0x1e68> */
	goto x86_l_1e68;
x86_l_1e62:
	/* 0x1e62: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e64:
	/* 0x1e64: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e68:
	/* 0x1e68: add    rbx,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_1e6f:
	/* 0x1e6f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e72:
	/* 0x1e72: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e77:
	/* 0x1e77: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e7c:
	/* 0x1e7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e81:
	/* 0x1e81: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1e84:
	/* 0x1e84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e86:
	/* 0x1e86: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e8a:
	/* 0x1e8a: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e8e:
	/* 0x1e8e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e93:
	/* 0x1e93: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e98:
	/* 0x1e98: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e9d:
	/* 0x1e9d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ea1:
	/* 0x1ea1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ea5:
	/* 0x1ea5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eaa:
	/* 0x1eaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eac:
	/* 0x1eac: mov    ecx,0x10000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_1eb1:
	/* 0x1eb1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1eb4:
	/* 0x1eb4: jne    1eda <event_execve+0x1eda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1eda;
	}
x86_l_1eb6:
	/* 0x1eb6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ebb:
	/* 0x1ebb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1ebe:
	/* 0x1ebe: je     1eda <event_execve+0x1eda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eda;
	}
x86_l_1ec0:
	/* 0x1ec0: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1ec3:
	/* 0x1ec3: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1ec7:
	/* 0x1ec7: mov    ecx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 128ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1ed6:
	/* 0x1ed6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed8:
	/* 0x1ed8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eda:
	/* 0x1eda: or     ecx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_1edc:
	/* 0x1edc: jmp    1f3e <event_execve+0x1f3e> */
	goto x86_l_1f3e;
x86_l_1ede:
	/* 0x1ede: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee0:
	/* 0x1ee0: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee4:
	/* 0x1ee4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ee7:
	/* 0x1ee7: jne    1d5e <event_execve+0x1d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5e;
	}
x86_l_1eed:
	/* 0x1eed: jmp    1e5a <event_execve+0x1e5a> */
	goto x86_l_1e5a;
x86_l_1ef2:
	/* 0x1ef2: mov    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_1efa:
	/* 0x1efa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1f01:
	/* 0x1f01: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f03:
	/* 0x1f03: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f08:
	/* 0x1f08: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f0d:
	/* 0x1f0d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f12:
	/* 0x1f12: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f14:
	/* 0x1f14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f16:
	/* 0x1f16: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f1b:
	/* 0x1f1b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1f1e:
	/* 0x1f1e: jne    16d7 <event_execve+0x16d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5847ULL;
	}
x86_l_1f24:
	/* 0x1f24: jmp    1774 <event_execve+0x1774> */
	return 6004ULL;
x86_l_1f29:
	/* 0x1f29: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f2e:
	/* 0x1f2e: mov    ebp,0x80000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 524288ULL);
x86_l_1f33:
	/* 0x1f33: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1f36:
	/* 0x1f36: jne    1df1 <event_execve+0x1df1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1df1;
	}
x86_l_1f3c:
	/* 0x1f3c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f3e:
	/* 0x1f3e: or     DWORD PTR [r14+0x15c],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_1f45:
	/* 0x1f45: mov    QWORD PTR [r14+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_1f50:
	/* 0x1f50: mov    QWORD PTR [r14+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_1f62:
	/* 0x1f62: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f64:
	/* 0x1f64: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f69:
	/* 0x1f69: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f6c:
	/* 0x1f6c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f6e:
	/* 0x1f6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f70:
	/* 0x1f70: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f72:
	/* 0x1f72: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1f79:
	/* 0x1f79: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1f7b:
	/* 0x1f7b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1f7c:
	/* 0x1f7c: jmp    2801 <__do_str+0x1bf> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f81:
	/* 0x1f81: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1f83:
	/* 0x1f83: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1f85:
	/* 0x1f85: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1f87:
	/* 0x1f87: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1f89:
	/* 0x1f89: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1f8a:
	/* 0x1f8a: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_1f91:
	/* 0x1f91: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1f94:
	/* 0x1f94: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1f97:
	/* 0x1f97: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1f9f:
	/* 0x1f9f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_1fa6:
	/* 0x1fa6: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fab:
	/* 0x1fab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fb0:
	/* 0x1fb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb2:
	/* 0x1fb2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb5:
	/* 0x1fb5: je     202d <data_event_str+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_202d;
	}
x86_l_1fb7:
	/* 0x1fb7: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1fba:
	/* 0x1fba: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fc0:
	/* 0x1fc0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1fc5:
	/* 0x1fc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc7:
	/* 0x1fc7: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1fca:
	/* 0x1fca: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fce:
	/* 0x1fce: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd3:
	/* 0x1fd3: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1fd7:
	/* 0x1fd7: jne    1fe1 <data_event_str+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fe1;
	}
x86_l_1fd9:
	/* 0x1fd9: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fdd:
	/* 0x1fdd: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe1:
	/* 0x1fe1: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1fe6:
	/* 0x1fe6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe8:
	/* 0x1fe8: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fed:
	/* 0x1fed: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff1:
	/* 0x1ff1: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ff5:
	/* 0x1ff5: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff9:
	/* 0x1ff9: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ffd:
	/* 0x1ffd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2000:
	/* 0x2000: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2003:
	/* 0x2003: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2006:
	/* 0x2006: call   25e3 <do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8203ULL);
	__x86_sim_call_depth++;
	return 9699ULL;
x86_l_200b:
	/* 0x200b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_200d:
	/* 0x200d: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_2010:
	/* 0x2010: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_2012:
	/* 0x2012: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2014:
	/* 0x2014: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2016:
	/* 0x2016: mov    DWORD PTR [rbx],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2018:
	/* 0x2018: cmovg  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_G);
x86_l_201b:
	/* 0x201b: mov    QWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2023:
	/* 0x2023: mov    DWORD PTR [rbx+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2026:
	/* 0x2026: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_202b:
	/* 0x202b: jmp    202f <data_event_str+0xae> */
	goto x86_l_202f;
x86_l_202d:
	/* 0x202d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_202f:
	/* 0x202f: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2033:
	/* 0x2033: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2034:
	/* 0x2034: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2036:
	/* 0x2036: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2038:
	/* 0x2038: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_203a:
	/* 0x203a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_203c:
	/* 0x203c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_203d:
	/* 0x203d: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_203e:
	/* 0x203e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2040:
	/* 0x2040: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2042:
	/* 0x2042: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_2044:
	/* 0x2044: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2046:
	/* 0x2046: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2047:
	/* 0x2047: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_2048:
	/* 0x2048: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_204b:
	/* 0x204b: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_204e:
	/* 0x204e: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2051:
	/* 0x2051: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_2054:
	/* 0x2054: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_205c:
	/* 0x205c: mov    rdi,QWORD PTR [rip+0x2e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_2063:
	/* 0x2063: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2068:
	/* 0x2068: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_206d:
	/* 0x206d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206f:
	/* 0x206f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2072:
	/* 0x2072: je     20e5 <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e5;
	}
x86_l_2074:
	/* 0x2074: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2077:
	/* 0x2077: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_207d:
	/* 0x207d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2082:
	/* 0x2082: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2084:
	/* 0x2084: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_2087:
	/* 0x2087: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_208b:
	/* 0x208b: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_208f:
	/* 0x208f: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2093:
	/* 0x2093: jne    209e <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209e;
	}
x86_l_2095:
	/* 0x2095: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_209a:
	/* 0x209a: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_209e:
	/* 0x209e: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_20a3:
	/* 0x20a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a5:
	/* 0x20a5: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20a9:
	/* 0x20a9: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ad:
	/* 0x20ad: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b1:
	/* 0x20b1: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20b5:
	/* 0x20b5: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b9:
	/* 0x20b9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_20bc:
	/* 0x20bc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_20bf:
	/* 0x20bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20c2:
	/* 0x20c2: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_20c5:
	/* 0x20c5: call   22bf <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8394ULL);
	__x86_sim_call_depth++;
	return 8895ULL;
x86_l_20ca:
	/* 0x20ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20cc:
	/* 0x20cc: js     20e9 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_20e9;
	}
x86_l_20ce:
	/* 0x20ce: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d5:
	/* 0x20d5: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_20d8:
	/* 0x20d8: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_20da:
	/* 0x20da: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20dc:
	/* 0x20dc: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_20e0:
	/* 0x20e0: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_20e3:
	/* 0x20e3: jmp    20f6 <data_event_bytes+0xb9> */
	goto x86_l_20f6;
x86_l_20e5:
	/* 0x20e5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e7:
	/* 0x20e7: jmp    2101 <data_event_bytes+0xc4> */
	return 8449ULL;
x86_l_20e9:
	/* 0x20e9: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20eb:
	/* 0x20eb: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_20f2:
	/* 0x20f2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20f4:
	/* 0x20f4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20f6:
	/* 0x20f6: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 8441ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8441ULL: goto x86_l_20f9;
	case 8444ULL: goto x86_l_20fc;
	case 8449ULL: goto x86_l_2101;
	case 8453ULL: goto x86_l_2105;
	case 8454ULL: goto x86_l_2106;
	case 8456ULL: goto x86_l_2108;
	case 8458ULL: goto x86_l_210a;
	case 8460ULL: goto x86_l_210c;
	case 8462ULL: goto x86_l_210e;
	case 8463ULL: goto x86_l_210f;
	case 8464ULL: goto x86_l_2110;
	case 8465ULL: goto x86_l_2111;
	case 8467ULL: goto x86_l_2113;
	case 8469ULL: goto x86_l_2115;
	case 8471ULL: goto x86_l_2117;
	case 8473ULL: goto x86_l_2119;
	case 8474ULL: goto x86_l_211a;
	case 8478ULL: goto x86_l_211e;
	case 8481ULL: goto x86_l_2121;
	case 8485ULL: goto x86_l_2125;
	case 8489ULL: goto x86_l_2129;
	case 8493ULL: goto x86_l_212d;
	case 8496ULL: goto x86_l_2130;
	case 8498ULL: goto x86_l_2132;
	case 8502ULL: goto x86_l_2136;
	case 8508ULL: goto x86_l_213c;
	case 8512ULL: goto x86_l_2140;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8532ULL: goto x86_l_2154;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8545ULL: goto x86_l_2161;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8573ULL: goto x86_l_217d;
	case 8575ULL: goto x86_l_217f;
	case 8580ULL: goto x86_l_2184;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8596ULL: goto x86_l_2194;
	case 8601ULL: goto x86_l_2199;
	case 8606ULL: goto x86_l_219e;
	case 8609ULL: goto x86_l_21a1;
	case 8611ULL: goto x86_l_21a3;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8638ULL: goto x86_l_21be;
	case 8640ULL: goto x86_l_21c0;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8652ULL: goto x86_l_21cc;
	case 8655ULL: goto x86_l_21cf;
	case 8659ULL: goto x86_l_21d3;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8666ULL: goto x86_l_21da;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8679ULL: goto x86_l_21e7;
	case 8683ULL: goto x86_l_21eb;
	case 8685ULL: goto x86_l_21ed;
	case 8689ULL: goto x86_l_21f1;
	case 8691ULL: goto x86_l_21f3;
	case 8694ULL: goto x86_l_21f6;
	case 8696ULL: goto x86_l_21f8;
	case 8699ULL: goto x86_l_21fb;
	case 8704ULL: goto x86_l_2200;
	case 8707ULL: goto x86_l_2203;
	case 8713ULL: goto x86_l_2209;
	case 8720ULL: goto x86_l_2210;
	case 8726ULL: goto x86_l_2216;
	case 8729ULL: goto x86_l_2219;
	case 8731ULL: goto x86_l_221b;
	case 8736ULL: goto x86_l_2220;
	case 8738ULL: goto x86_l_2222;
	case 8741ULL: goto x86_l_2225;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8752ULL: goto x86_l_2230;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8762ULL: goto x86_l_223a;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8784ULL: goto x86_l_2250;
	case 8786ULL: goto x86_l_2252;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8800ULL: goto x86_l_2260;
	case 8805ULL: goto x86_l_2265;
	case 8810ULL: goto x86_l_226a;
	case 8812ULL: goto x86_l_226c;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8823ULL: goto x86_l_2277;
	case 8827ULL: goto x86_l_227b;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8859ULL: goto x86_l_229b;
	case 8863ULL: goto x86_l_229f;
	case 8867ULL: goto x86_l_22a3;
	case 8869ULL: goto x86_l_22a5;
	case 8871ULL: goto x86_l_22a7;
	case 8875ULL: goto x86_l_22ab;
	case 8880ULL: goto x86_l_22b0;
	case 8884ULL: goto x86_l_22b4;
	case 8885ULL: goto x86_l_22b5;
	case 8887ULL: goto x86_l_22b7;
	case 8889ULL: goto x86_l_22b9;
	case 8891ULL: goto x86_l_22bb;
	case 8893ULL: goto x86_l_22bd;
	case 8894ULL: goto x86_l_22be;
	case 8895ULL: goto x86_l_22bf;
	case 8896ULL: goto x86_l_22c0;
	case 8898ULL: goto x86_l_22c2;
	case 8900ULL: goto x86_l_22c4;
	case 8902ULL: goto x86_l_22c6;
	case 8904ULL: goto x86_l_22c8;
	case 8905ULL: goto x86_l_22c9;
	case 8906ULL: goto x86_l_22ca;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8915ULL: goto x86_l_22d3;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8925ULL: goto x86_l_22dd;
	case 8931ULL: goto x86_l_22e3;
	case 8934ULL: goto x86_l_22e6;
	case 8941ULL: goto x86_l_22ed;
	case 8944ULL: goto x86_l_22f0;
	case 8947ULL: goto x86_l_22f3;
	case 8953ULL: goto x86_l_22f9;
	case 8957ULL: goto x86_l_22fd;
	case 8960ULL: goto x86_l_2300;
	case 8963ULL: goto x86_l_2303;
	case 8968ULL: goto x86_l_2308;
	case 8970ULL: goto x86_l_230a;
	case 8976ULL: goto x86_l_2310;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8987ULL: goto x86_l_231b;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8999ULL: goto x86_l_2327;
	case 9003ULL: goto x86_l_232b;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9016ULL: goto x86_l_2338;
	case 9022ULL: goto x86_l_233e;
	case 9027ULL: goto x86_l_2343;
	case 9030ULL: goto x86_l_2346;
	case 9033ULL: goto x86_l_2349;
	case 9036ULL: goto x86_l_234c;
	case 9039ULL: goto x86_l_234f;
	case 9045ULL: goto x86_l_2355;
	case 9049ULL: goto x86_l_2359;
	case 9052ULL: goto x86_l_235c;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9062ULL: goto x86_l_2366;
	case 9068ULL: goto x86_l_236c;
	case 9073ULL: goto x86_l_2371;
	case 9076ULL: goto x86_l_2374;
	case 9079ULL: goto x86_l_2377;
	case 9082ULL: goto x86_l_237a;
	case 9085ULL: goto x86_l_237d;
	case 9091ULL: goto x86_l_2383;
	case 9095ULL: goto x86_l_2387;
	case 9098ULL: goto x86_l_238a;
	case 9101ULL: goto x86_l_238d;
	case 9106ULL: goto x86_l_2392;
	case 9108ULL: goto x86_l_2394;
	case 9114ULL: goto x86_l_239a;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9131ULL: goto x86_l_23ab;
	case 9137ULL: goto x86_l_23b1;
	case 9141ULL: goto x86_l_23b5;
	case 9144ULL: goto x86_l_23b8;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9154ULL: goto x86_l_23c2;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9168ULL: goto x86_l_23d0;
	case 9171ULL: goto x86_l_23d3;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9183ULL: goto x86_l_23df;
	case 9187ULL: goto x86_l_23e3;
	case 9190ULL: goto x86_l_23e6;
	case 9193ULL: goto x86_l_23e9;
	case 9198ULL: goto x86_l_23ee;
	case 9200ULL: goto x86_l_23f0;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9214ULL: goto x86_l_23fe;
	case 9217ULL: goto x86_l_2401;
	case 9220ULL: goto x86_l_2404;
	case 9223ULL: goto x86_l_2407;
	case 9229ULL: goto x86_l_240d;
	case 9233ULL: goto x86_l_2411;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9244ULL: goto x86_l_241c;
	case 9246ULL: goto x86_l_241e;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9256ULL: goto x86_l_2428;
	case 9259ULL: goto x86_l_242b;
	case 9262ULL: goto x86_l_242e;
	case 9265ULL: goto x86_l_2431;
	case 9271ULL: goto x86_l_2437;
	case 9275ULL: goto x86_l_243b;
	case 9278ULL: goto x86_l_243e;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9288ULL: goto x86_l_2448;
	case 9290ULL: goto x86_l_244a;
	case 9295ULL: goto x86_l_244f;
	case 9298ULL: goto x86_l_2452;
	case 9301ULL: goto x86_l_2455;
	case 9304ULL: goto x86_l_2458;
	case 9307ULL: goto x86_l_245b;
	case 9313ULL: goto x86_l_2461;
	case 9316ULL: goto x86_l_2464;
	case 9319ULL: goto x86_l_2467;
	case 9322ULL: goto x86_l_246a;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9332ULL: goto x86_l_2474;
	case 9334ULL: goto x86_l_2476;
	case 9339ULL: goto x86_l_247b;
	case 9342ULL: goto x86_l_247e;
	case 9345ULL: goto x86_l_2481;
	case 9350ULL: goto x86_l_2486;
	case 9353ULL: goto x86_l_2489;
	case 9361ULL: goto x86_l_2491;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9380ULL: goto x86_l_24a4;
	case 9383ULL: goto x86_l_24a7;
	case 9385ULL: goto x86_l_24a9;
	case 9389ULL: goto x86_l_24ad;
	case 9391ULL: goto x86_l_24af;
	case 9395ULL: goto x86_l_24b3;
	case 9397ULL: goto x86_l_24b5;
	case 9401ULL: goto x86_l_24b9;
	case 9403ULL: goto x86_l_24bb;
	case 9407ULL: goto x86_l_24bf;
	case 9409ULL: goto x86_l_24c1;
	case 9415ULL: goto x86_l_24c7;
	case 9417ULL: goto x86_l_24c9;
	case 9421ULL: goto x86_l_24cd;
	case 9423ULL: goto x86_l_24cf;
	case 9427ULL: goto x86_l_24d3;
	case 9429ULL: goto x86_l_24d5;
	case 9433ULL: goto x86_l_24d9;
	case 9435ULL: goto x86_l_24db;
	case 9441ULL: goto x86_l_24e1;
	case 9443ULL: goto x86_l_24e3;
	case 9449ULL: goto x86_l_24e9;
	case 9451ULL: goto x86_l_24eb;
	case 9457ULL: goto x86_l_24f1;
	case 9459ULL: goto x86_l_24f3;
	case 9465ULL: goto x86_l_24f9;
	case 9467ULL: goto x86_l_24fb;
	case 9473ULL: goto x86_l_2501;
	case 9475ULL: goto x86_l_2503;
	case 9481ULL: goto x86_l_2509;
	case 9485ULL: goto x86_l_250d;
	case 9488ULL: goto x86_l_2510;
	case 9492ULL: goto x86_l_2514;
	case 9493ULL: goto x86_l_2515;
	case 9495ULL: goto x86_l_2517;
	case 9497ULL: goto x86_l_2519;
	case 9499ULL: goto x86_l_251b;
	case 9501ULL: goto x86_l_251d;
	case 9502ULL: goto x86_l_251e;
	case 9503ULL: goto x86_l_251f;
	case 9505ULL: goto x86_l_2521;
	case 9507ULL: goto x86_l_2523;
	case 9509ULL: goto x86_l_2525;
	case 9510ULL: goto x86_l_2526;
	case 9511ULL: goto x86_l_2527;
	case 9514ULL: goto x86_l_252a;
	case 9520ULL: goto x86_l_2530;
	case 9523ULL: goto x86_l_2533;
	case 9526ULL: goto x86_l_2536;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9542ULL: goto x86_l_2546;
	case 9546ULL: goto x86_l_254a;
	case 9551ULL: goto x86_l_254f;
	case 9553ULL: goto x86_l_2551;
	case 9555ULL: goto x86_l_2553;
	case 9557ULL: goto x86_l_2555;
	case 9559ULL: goto x86_l_2557;
	case 9563ULL: goto x86_l_255b;
	case 9567ULL: goto x86_l_255f;
	case 9575ULL: goto x86_l_2567;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9597ULL: goto x86_l_257d;
	case 9599ULL: goto x86_l_257f;
	case 9603ULL: goto x86_l_2583;
	case 9605ULL: goto x86_l_2585;
	case 9612ULL: goto x86_l_258c;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9633ULL: goto x86_l_25a1;
	case 9636ULL: goto x86_l_25a4;
	case 9638ULL: goto x86_l_25a6;
	case 9640ULL: goto x86_l_25a8;
	case 9642ULL: goto x86_l_25aa;
	case 9644ULL: goto x86_l_25ac;
	case 9651ULL: goto x86_l_25b3;
	case 9653ULL: goto x86_l_25b5;
	case 9660ULL: goto x86_l_25bc;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9670ULL: goto x86_l_25c6;
	case 9673ULL: goto x86_l_25c9;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9679ULL: goto x86_l_25cf;
	case 9681ULL: goto x86_l_25d1;
	case 9684ULL: goto x86_l_25d4;
	case 9687ULL: goto x86_l_25d7;
	case 9691ULL: goto x86_l_25db;
	case 9692ULL: goto x86_l_25dc;
	case 9694ULL: goto x86_l_25de;
	case 9696ULL: goto x86_l_25e0;
	case 9698ULL: goto x86_l_25e2;
	case 9699ULL: goto x86_l_25e3;
	case 9701ULL: goto x86_l_25e5;
	case 9703ULL: goto x86_l_25e7;
	case 9704ULL: goto x86_l_25e8;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9735ULL: goto x86_l_2607;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9744ULL: goto x86_l_2610;
	case 9747ULL: goto x86_l_2613;
	case 9752ULL: goto x86_l_2618;
	case 9755ULL: goto x86_l_261b;
	case 9758ULL: goto x86_l_261e;
	case 9761ULL: goto x86_l_2621;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9771ULL: goto x86_l_262b;
	case 9774ULL: goto x86_l_262e;
	case 9778ULL: goto x86_l_2632;
	default: return 0xffffffffffffffffULL;
	}
x86_l_20f9:
	/* 0x20f9: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20fc:
	/* 0x20fc: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_2101:
	/* 0x2101: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2105:
	/* 0x2105: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2106:
	/* 0x2106: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2108:
	/* 0x2108: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_210a:
	/* 0x210a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_210c:
	/* 0x210c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_210e:
	/* 0x210e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_210f:
	/* 0x210f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2110:
	/* 0x2110: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_2111:
	/* 0x2111: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2113:
	/* 0x2113: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2115:
	/* 0x2115: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_2117:
	/* 0x2117: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2119:
	/* 0x2119: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_211a:
	/* 0x211a: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_211e:
	/* 0x211e: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2121:
	/* 0x2121: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2125:
	/* 0x2125: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2129:
	/* 0x2129: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_212d:
	/* 0x212d: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2130:
	/* 0x2130: jne    213c <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_213c;
	}
x86_l_2132:
	/* 0x2132: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2136:
	/* 0x2136: je     22a7 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a7;
	}
x86_l_213c:
	/* 0x213c: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2140:
	/* 0x2140: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2145:
	/* 0x2145: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_214a:
	/* 0x214a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_214f:
	/* 0x214f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2154:
	/* 0x2154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2156:
	/* 0x2156: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_215b:
	/* 0x215b: je     2252 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2252;
	}
x86_l_2161:
	/* 0x2161: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2166:
	/* 0x2166: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_216b:
	/* 0x216b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2170:
	/* 0x2170: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2175:
	/* 0x2175: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_217a:
	/* 0x217a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_217d:
	/* 0x217d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217f:
	/* 0x217f: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2184:
	/* 0x2184: je     2252 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2252;
	}
x86_l_218a:
	/* 0x218a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_218f:
	/* 0x218f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2194:
	/* 0x2194: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2199:
	/* 0x2199: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_219e:
	/* 0x219e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_21a1:
	/* 0x21a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a3:
	/* 0x21a3: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_21a7:
	/* 0x21a7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ac:
	/* 0x21ac: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_21b1:
	/* 0x21b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21b6:
	/* 0x21b6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21bb:
	/* 0x21bb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21be:
	/* 0x21be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c0:
	/* 0x21c0: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c4:
	/* 0x21c4: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21c8:
	/* 0x21c8: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21cc:
	/* 0x21cc: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_21cf:
	/* 0x21cf: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21d3:
	/* 0x21d3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21d5:
	/* 0x21d5: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_21d7:
	/* 0x21d7: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21da:
	/* 0x21da: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_21dd:
	/* 0x21dd: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_21e2:
	/* 0x21e2: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21e4:
	/* 0x21e4: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_21e7:
	/* 0x21e7: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_21eb:
	/* 0x21eb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_21ed:
	/* 0x21ed: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_21f1:
	/* 0x21f1: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21f3:
	/* 0x21f3: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_21f6:
	/* 0x21f6: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21f8:
	/* 0x21f8: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21fb:
	/* 0x21fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2200:
	/* 0x2200: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2203:
	/* 0x2203: jb     22b0 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_22b0;
	}
x86_l_2209:
	/* 0x2209: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_2210:
	/* 0x2210: ja     22b0 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_22b0;
	}
x86_l_2216:
	/* 0x2216: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2219:
	/* 0x2219: jbe    2220 <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2220;
	}
x86_l_221b:
	/* 0x221b: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2220:
	/* 0x2220: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2222:
	/* 0x2222: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2225:
	/* 0x2225: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2229:
	/* 0x2229: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_222d:
	/* 0x222d: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2230:
	/* 0x2230: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2233:
	/* 0x2233: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2238:
	/* 0x2238: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223a:
	/* 0x223a: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_223e:
	/* 0x223e: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2241:
	/* 0x2241: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2246:
	/* 0x2246: jbe    22b0 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_22b0;
	}
x86_l_2248:
	/* 0x2248: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_224d:
	/* 0x224d: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2250:
	/* 0x2250: jmp    22a3 <cwd_read_v61+0x193> */
	goto x86_l_22a3;
x86_l_2252:
	/* 0x2252: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2256:
	/* 0x2256: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_225b:
	/* 0x225b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2260:
	/* 0x2260: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2265:
	/* 0x2265: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_226a:
	/* 0x226a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226c:
	/* 0x226c: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2270:
	/* 0x2270: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2275:
	/* 0x2275: je     22a7 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a7;
	}
x86_l_2277:
	/* 0x2277: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_227b:
	/* 0x227b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2280:
	/* 0x2280: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2285:
	/* 0x2285: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2288:
	/* 0x2288: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_228d:
	/* 0x228d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2290:
	/* 0x2290: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2292:
	/* 0x2292: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2297:
	/* 0x2297: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_229b:
	/* 0x229b: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_229f:
	/* 0x229f: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22a3:
	/* 0x22a3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22a5:
	/* 0x22a5: jmp    22b0 <cwd_read_v61+0x1a0> */
	goto x86_l_22b0;
x86_l_22a7:
	/* 0x22a7: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_22ab:
	/* 0x22ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22b0:
	/* 0x22b0: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_22b4:
	/* 0x22b4: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_22b5:
	/* 0x22b5: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_22b7:
	/* 0x22b7: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_22b9:
	/* 0x22b9: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_22bb:
	/* 0x22bb: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_22bd:
	/* 0x22bd: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_22be:
	/* 0x22be: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_22bf:
	/* 0x22bf: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_22c0:
	/* 0x22c0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_22c2:
	/* 0x22c2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_22c4:
	/* 0x22c4: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_22c6:
	/* 0x22c6: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_22c8:
	/* 0x22c8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_22c9:
	/* 0x22c9: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_22ca:
	/* 0x22ca: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_22cd:
	/* 0x22cd: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_22d0:
	/* 0x22d0: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_22d3:
	/* 0x22d3: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_22d6:
	/* 0x22d6: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8923ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_22db:
	/* 0x22db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22dd:
	/* 0x22dd: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_22e3:
	/* 0x22e3: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_22e6:
	/* 0x22e6: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_22ed:
	/* 0x22ed: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_22f0:
	/* 0x22f0: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_22f3:
	/* 0x22f3: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_22f9:
	/* 0x22f9: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_22fd:
	/* 0x22fd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2300:
	/* 0x2300: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2303:
	/* 0x2303: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8968ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_2308:
	/* 0x2308: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_230a:
	/* 0x230a: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_2310:
	/* 0x2310: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2315:
	/* 0x2315: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2318:
	/* 0x2318: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_231b:
	/* 0x231b: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_231e:
	/* 0x231e: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2321:
	/* 0x2321: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_2327:
	/* 0x2327: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_232b:
	/* 0x232b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_232e:
	/* 0x232e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2331:
	/* 0x2331: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9014ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_2336:
	/* 0x2336: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2338:
	/* 0x2338: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_233e:
	/* 0x233e: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2343:
	/* 0x2343: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2346:
	/* 0x2346: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2349:
	/* 0x2349: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_234c:
	/* 0x234c: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_234f:
	/* 0x234f: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_2355:
	/* 0x2355: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2359:
	/* 0x2359: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_235c:
	/* 0x235c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_235f:
	/* 0x235f: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9060ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_2364:
	/* 0x2364: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2366:
	/* 0x2366: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_236c:
	/* 0x236c: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2371:
	/* 0x2371: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2374:
	/* 0x2374: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2377:
	/* 0x2377: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_237a:
	/* 0x237a: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_237d:
	/* 0x237d: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_2383:
	/* 0x2383: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2387:
	/* 0x2387: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_238a:
	/* 0x238a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_238d:
	/* 0x238d: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9106ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_2392:
	/* 0x2392: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2394:
	/* 0x2394: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_239a:
	/* 0x239a: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_239f:
	/* 0x239f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_23a2:
	/* 0x23a2: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23a5:
	/* 0x23a5: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_23a8:
	/* 0x23a8: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_23ab:
	/* 0x23ab: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_23b1:
	/* 0x23b1: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_23b5:
	/* 0x23b5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_23b8:
	/* 0x23b8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_23bb:
	/* 0x23bb: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9152ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_23c0:
	/* 0x23c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c2:
	/* 0x23c2: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_23c8:
	/* 0x23c8: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_23cd:
	/* 0x23cd: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_23d0:
	/* 0x23d0: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23d3:
	/* 0x23d3: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_23d6:
	/* 0x23d6: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_23d9:
	/* 0x23d9: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_23df:
	/* 0x23df: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_23e3:
	/* 0x23e3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_23e6:
	/* 0x23e6: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_23e9:
	/* 0x23e9: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9198ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_23ee:
	/* 0x23ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23f0:
	/* 0x23f0: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_23f6:
	/* 0x23f6: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_23fb:
	/* 0x23fb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_23fe:
	/* 0x23fe: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2401:
	/* 0x2401: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2404:
	/* 0x2404: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2407:
	/* 0x2407: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_240d:
	/* 0x240d: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2411:
	/* 0x2411: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2414:
	/* 0x2414: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2417:
	/* 0x2417: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9244ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_241c:
	/* 0x241c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_241e:
	/* 0x241e: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_2420:
	/* 0x2420: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2425:
	/* 0x2425: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2428:
	/* 0x2428: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_242b:
	/* 0x242b: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_242e:
	/* 0x242e: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2431:
	/* 0x2431: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_2437:
	/* 0x2437: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_243b:
	/* 0x243b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_243e:
	/* 0x243e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2441:
	/* 0x2441: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9286ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_2446:
	/* 0x2446: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2448:
	/* 0x2448: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_244a:
	/* 0x244a: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_244f:
	/* 0x244f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2452:
	/* 0x2452: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2455:
	/* 0x2455: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2458:
	/* 0x2458: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_245b:
	/* 0x245b: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_2461:
	/* 0x2461: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2464:
	/* 0x2464: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2467:
	/* 0x2467: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_246a:
	/* 0x246a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_246d:
	/* 0x246d: call   251f <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9330ULL);
	__x86_sim_call_depth++;
	goto x86_l_251f;
x86_l_2472:
	/* 0x2472: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2474:
	/* 0x2474: js     2486 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2486;
	}
x86_l_2476:
	/* 0x2476: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_247b:
	/* 0x247b: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_247e:
	/* 0x247e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2481:
	/* 0x2481: jmp    250d <do_bytes+0x24e> */
	goto x86_l_250d;
x86_l_2486:
	/* 0x2486: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2489:
	/* 0x2489: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2491:
	/* 0x2491: mov    rdi,QWORD PTR [rip+0x3c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_2498:
	/* 0x2498: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_249d:
	/* 0x249d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24a2:
	/* 0x24a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a4:
	/* 0x24a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a7:
	/* 0x24a7: je     250d <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250d;
	}
x86_l_24a9:
	/* 0x24a9: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_24ad:
	/* 0x24ad: jg     24c9 <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24c9;
	}
x86_l_24af:
	/* 0x24af: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_24b3:
	/* 0x24b3: je     24e3 <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e3;
	}
x86_l_24b5:
	/* 0x24b5: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_24b9:
	/* 0x24b9: je     24fb <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24fb;
	}
x86_l_24bb:
	/* 0x24bb: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_24bf:
	/* 0x24bf: jne    24f3 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f3;
	}
x86_l_24c1:
	/* 0x24c1: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_24c7:
	/* 0x24c7: jmp    2509 <do_bytes+0x24a> */
	goto x86_l_2509;
x86_l_24c9:
	/* 0x24c9: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_24cd:
	/* 0x24cd: je     24eb <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24eb;
	}
x86_l_24cf:
	/* 0x24cf: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_24d3:
	/* 0x24d3: je     2503 <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2503;
	}
x86_l_24d5:
	/* 0x24d5: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_24d9:
	/* 0x24d9: jne    24f3 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f3;
	}
x86_l_24db:
	/* 0x24db: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_24e1:
	/* 0x24e1: jmp    2509 <do_bytes+0x24a> */
	goto x86_l_2509;
x86_l_24e3:
	/* 0x24e3: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_24e9:
	/* 0x24e9: jmp    2509 <do_bytes+0x24a> */
	goto x86_l_2509;
x86_l_24eb:
	/* 0x24eb: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_24f1:
	/* 0x24f1: jmp    2509 <do_bytes+0x24a> */
	goto x86_l_2509;
x86_l_24f3:
	/* 0x24f3: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_24f9:
	/* 0x24f9: jmp    2509 <do_bytes+0x24a> */
	goto x86_l_2509;
x86_l_24fb:
	/* 0x24fb: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_2501:
	/* 0x2501: jmp    2509 <do_bytes+0x24a> */
	goto x86_l_2509;
x86_l_2503:
	/* 0x2503: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_2509:
	/* 0x2509: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_250d:
	/* 0x250d: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_2510:
	/* 0x2510: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2514:
	/* 0x2514: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2515:
	/* 0x2515: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2517:
	/* 0x2517: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2519:
	/* 0x2519: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_251b:
	/* 0x251b: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_251d:
	/* 0x251d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_251e:
	/* 0x251e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_251f:
	/* 0x251f: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2521:
	/* 0x2521: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2523:
	/* 0x2523: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2525:
	/* 0x2525: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2526:
	/* 0x2526: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_2527:
	/* 0x2527: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_252a:
	/* 0x252a: js     25ac <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25ac;
	}
x86_l_2530:
	/* 0x2530: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_2533:
	/* 0x2533: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_2536:
	/* 0x2536: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_253d:
	/* 0x253d: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_2542:
	/* 0x2542: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_2546:
	/* 0x2546: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_254a:
	/* 0x254a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_254f:
	/* 0x254f: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2551:
	/* 0x2551: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2553:
	/* 0x2553: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2555:
	/* 0x2555: js     25d1 <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25d1;
	}
x86_l_2557:
	/* 0x2557: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_255b:
	/* 0x255b: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_255f:
	/* 0x255f: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2567:
	/* 0x2567: mov    rdi,QWORD PTR [rip+0x61c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_256e:
	/* 0x256e: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2573:
	/* 0x2573: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2578:
	/* 0x2578: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257a:
	/* 0x257a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_257d:
	/* 0x257d: je     25b5 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b5;
	}
x86_l_257f:
	/* 0x257f: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2583:
	/* 0x2583: je     25b5 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b5;
	}
x86_l_2585:
	/* 0x2585: mov    rsi,QWORD PTR [rip+0x61c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_258c:
	/* 0x258c: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2591:
	/* 0x2591: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2596:
	/* 0x2596: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2599:
	/* 0x2599: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_259e:
	/* 0x259e: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_25a1:
	/* 0x25a1: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_25a4:
	/* 0x25a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a6:
	/* 0x25a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25a8:
	/* 0x25a8: js     25d1 <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25d1;
	}
x86_l_25aa:
	/* 0x25aa: jmp    25d4 <__do_bytes+0xb5> */
	goto x86_l_25d4;
x86_l_25ac:
	/* 0x25ac: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_25b3:
	/* 0x25b3: jmp    25d4 <__do_bytes+0xb5> */
	goto x86_l_25d4;
x86_l_25b5:
	/* 0x25b5: mov    rdi,QWORD PTR [rip+0x61c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_25bc:
	/* 0x25bc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25be:
	/* 0x25be: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_25c3:
	/* 0x25c3: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_25c6:
	/* 0x25c6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25c9:
	/* 0x25c9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25cb:
	/* 0x25cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cd:
	/* 0x25cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25cf:
	/* 0x25cf: jns    25d4 <__do_bytes+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_25d4;
	}
x86_l_25d1:
	/* 0x25d1: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_25d4:
	/* 0x25d4: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_25d7:
	/* 0x25d7: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_25db:
	/* 0x25db: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_25dc:
	/* 0x25dc: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_25de:
	/* 0x25de: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_25e0:
	/* 0x25e0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_25e2:
	/* 0x25e2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_25e3:
	/* 0x25e3: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_25e5:
	/* 0x25e5: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_25e7:
	/* 0x25e7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_25e8:
	/* 0x25e8: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_25ec:
	/* 0x25ec: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_25ef:
	/* 0x25ef: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_25f2:
	/* 0x25f2: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_25f5:
	/* 0x25f5: mov    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_25fa:
	/* 0x25fa: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_25ff:
	/* 0x25ff: call   2642 <__do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9732ULL);
	__x86_sim_call_depth++;
	return 9794ULL;
x86_l_2604:
	/* 0x2604: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2607:
	/* 0x2607: js     2638 <do_str+0x55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9784ULL;
	}
x86_l_2609:
	/* 0x2609: cmp    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_260e:
	/* 0x260e: jne    2638 <do_str+0x55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9784ULL;
	}
x86_l_2610:
	/* 0x2610: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2613:
	/* 0x2613: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_2618:
	/* 0x2618: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_261b:
	/* 0x261b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_261e:
	/* 0x261e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2621:
	/* 0x2621: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2624:
	/* 0x2624: call   2642 <__do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9769ULL);
	__x86_sim_call_depth++;
	return 9794ULL;
x86_l_2629:
	/* 0x2629: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_262b:
	/* 0x262b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_262e:
	/* 0x262e: cmovns rcx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_64, X86_CC_NS);
x86_l_2632:
	/* 0x2632: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
	return 9781ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9781ULL: goto x86_l_2635;
	case 9784ULL: goto x86_l_2638;
	case 9788ULL: goto x86_l_263c;
	case 9789ULL: goto x86_l_263d;
	case 9791ULL: goto x86_l_263f;
	case 9793ULL: goto x86_l_2641;
	case 9794ULL: goto x86_l_2642;
	case 9796ULL: goto x86_l_2644;
	case 9798ULL: goto x86_l_2646;
	case 9800ULL: goto x86_l_2648;
	case 9801ULL: goto x86_l_2649;
	case 9805ULL: goto x86_l_264d;
	case 9808ULL: goto x86_l_2650;
	case 9811ULL: goto x86_l_2653;
	case 9814ULL: goto x86_l_2656;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9835ULL: goto x86_l_266b;
	case 9838ULL: goto x86_l_266e;
	case 9844ULL: goto x86_l_2674;
	case 9850ULL: goto x86_l_267a;
	case 9854ULL: goto x86_l_267e;
	case 9857ULL: goto x86_l_2681;
	case 9863ULL: goto x86_l_2687;
	case 9866ULL: goto x86_l_268a;
	case 9870ULL: goto x86_l_268e;
	case 9877ULL: goto x86_l_2695;
	case 9881ULL: goto x86_l_2699;
	case 9889ULL: goto x86_l_26a1;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9908ULL: goto x86_l_26b4;
	case 9911ULL: goto x86_l_26b7;
	case 9917ULL: goto x86_l_26bd;
	case 9921ULL: goto x86_l_26c1;
	case 9923ULL: goto x86_l_26c3;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9948ULL: goto x86_l_26dc;
	case 9951ULL: goto x86_l_26df;
	case 9954ULL: goto x86_l_26e2;
	case 9956ULL: goto x86_l_26e4;
	case 9959ULL: goto x86_l_26e7;
	case 9965ULL: goto x86_l_26ed;
	case 9968ULL: goto x86_l_26f0;
	case 9976ULL: goto x86_l_26f8;
	case 9983ULL: goto x86_l_26ff;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 9995ULL: goto x86_l_270b;
	case 9998ULL: goto x86_l_270e;
	case 10004ULL: goto x86_l_2714;
	case 10008ULL: goto x86_l_2718;
	case 10014ULL: goto x86_l_271e;
	case 10018ULL: goto x86_l_2722;
	case 10024ULL: goto x86_l_2728;
	case 10028ULL: goto x86_l_272c;
	case 10030ULL: goto x86_l_272e;
	case 10036ULL: goto x86_l_2734;
	case 10041ULL: goto x86_l_2739;
	case 10048ULL: goto x86_l_2740;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10058ULL: goto x86_l_274a;
	case 10061ULL: goto x86_l_274d;
	case 10063ULL: goto x86_l_274f;
	case 10065ULL: goto x86_l_2751;
	case 10068ULL: goto x86_l_2754;
	case 10074ULL: goto x86_l_275a;
	case 10077ULL: goto x86_l_275d;
	case 10085ULL: goto x86_l_2765;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10104ULL: goto x86_l_2778;
	case 10107ULL: goto x86_l_277b;
	case 10109ULL: goto x86_l_277d;
	case 10113ULL: goto x86_l_2781;
	case 10115ULL: goto x86_l_2783;
	case 10119ULL: goto x86_l_2787;
	case 10121ULL: goto x86_l_2789;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10131ULL: goto x86_l_2793;
	case 10133ULL: goto x86_l_2795;
	case 10139ULL: goto x86_l_279b;
	case 10141ULL: goto x86_l_279d;
	case 10143ULL: goto x86_l_279f;
	case 10145ULL: goto x86_l_27a1;
	case 10149ULL: goto x86_l_27a5;
	case 10151ULL: goto x86_l_27a7;
	case 10155ULL: goto x86_l_27ab;
	case 10157ULL: goto x86_l_27ad;
	case 10161ULL: goto x86_l_27b1;
	case 10163ULL: goto x86_l_27b3;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10175ULL: goto x86_l_27bf;
	case 10177ULL: goto x86_l_27c1;
	case 10181ULL: goto x86_l_27c5;
	case 10183ULL: goto x86_l_27c7;
	case 10187ULL: goto x86_l_27cb;
	case 10189ULL: goto x86_l_27cd;
	case 10195ULL: goto x86_l_27d3;
	case 10197ULL: goto x86_l_27d5;
	case 10203ULL: goto x86_l_27db;
	case 10205ULL: goto x86_l_27dd;
	case 10211ULL: goto x86_l_27e3;
	case 10213ULL: goto x86_l_27e5;
	case 10219ULL: goto x86_l_27eb;
	case 10223ULL: goto x86_l_27ef;
	case 10226ULL: goto x86_l_27f2;
	case 10229ULL: goto x86_l_27f5;
	case 10233ULL: goto x86_l_27f9;
	case 10234ULL: goto x86_l_27fa;
	case 10236ULL: goto x86_l_27fc;
	case 10238ULL: goto x86_l_27fe;
	case 10240ULL: goto x86_l_2800;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2635:
	/* 0x2635: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2638:
	/* 0x2638: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_263c:
	/* 0x263c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_263d:
	/* 0x263d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_263f:
	/* 0x263f: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2641:
	/* 0x2641: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2642:
	/* 0x2642: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2644:
	/* 0x2644: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2646:
	/* 0x2646: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2648:
	/* 0x2648: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2649:
	/* 0x2649: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_264d:
	/* 0x264d: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_2650:
	/* 0x2650: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2653:
	/* 0x2653: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2656:
	/* 0x2656: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_265a:
	/* 0x265a: mov    ecx,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32735ULL);
x86_l_265f:
	/* 0x265f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2664:
	/* 0x2664: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_2669:
	/* 0x2669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_266b:
	/* 0x266b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_266e:
	/* 0x266e: js     27f5 <__do_str+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27f5;
	}
x86_l_2674:
	/* 0x2674: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_267a:
	/* 0x267a: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_267e:
	/* 0x267e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2681:
	/* 0x2681: je     279d <__do_str+0x15b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_279d;
	}
x86_l_2687:
	/* 0x2687: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_268a:
	/* 0x268a: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_268e:
	/* 0x268e: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2695:
	/* 0x2695: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2699:
	/* 0x2699: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_26a1:
	/* 0x26a1: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_26a8:
	/* 0x26a8: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_26ad:
	/* 0x26ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26b2:
	/* 0x26b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b4:
	/* 0x26b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26b7:
	/* 0x26b7: je     2739 <__do_str+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2739;
	}
x86_l_26bd:
	/* 0x26bd: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_26c1:
	/* 0x26c1: je     2739 <__do_str+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2739;
	}
x86_l_26c3:
	/* 0x26c3: mov    rsi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_26ca:
	/* 0x26ca: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_26cf:
	/* 0x26cf: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_26d4:
	/* 0x26d4: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_26d9:
	/* 0x26d9: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_26dc:
	/* 0x26dc: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_26df:
	/* 0x26df: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_26e2:
	/* 0x26e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e4:
	/* 0x26e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26e7:
	/* 0x26e7: jns    27ef <__do_str+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_27ef;
	}
x86_l_26ed:
	/* 0x26ed: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_26f0:
	/* 0x26f0: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_26f8:
	/* 0x26f8: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_26ff:
	/* 0x26ff: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2704:
	/* 0x2704: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2709:
	/* 0x2709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270b:
	/* 0x270b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_270e:
	/* 0x270e: je     27ef <__do_str+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ef;
	}
x86_l_2714:
	/* 0x2714: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2718:
	/* 0x2718: jg     27bb <__do_str+0x179> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_27bb;
	}
x86_l_271e:
	/* 0x271e: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2722:
	/* 0x2722: je     27d5 <__do_str+0x193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d5;
	}
x86_l_2728:
	/* 0x2728: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_272c:
	/* 0x272c: jne    278f <__do_str+0x14d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_278f;
	}
x86_l_272e:
	/* 0x272e: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_2734:
	/* 0x2734: jmp    27eb <__do_str+0x1a9> */
	goto x86_l_27eb;
x86_l_2739:
	/* 0x2739: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_2740:
	/* 0x2740: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2742:
	/* 0x2742: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_2747:
	/* 0x2747: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_274a:
	/* 0x274a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_274d:
	/* 0x274d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_274f:
	/* 0x274f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2751:
	/* 0x2751: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2754:
	/* 0x2754: jns    27ef <__do_str+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_27ef;
	}
x86_l_275a:
	/* 0x275a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_275d:
	/* 0x275d: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2765:
	/* 0x2765: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_276c:
	/* 0x276c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2771:
	/* 0x2771: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2776:
	/* 0x2776: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2778:
	/* 0x2778: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_277b:
	/* 0x277b: je     27ef <__do_str+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ef;
	}
x86_l_277d:
	/* 0x277d: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2781:
	/* 0x2781: jg     27a1 <__do_str+0x15f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_27a1;
	}
x86_l_2783:
	/* 0x2783: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2787:
	/* 0x2787: je     27d5 <__do_str+0x193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d5;
	}
x86_l_2789:
	/* 0x2789: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_278d:
	/* 0x278d: je     272e <__do_str+0xec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272e;
	}
x86_l_278f:
	/* 0x278f: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_2793:
	/* 0x2793: jne    27cd <__do_str+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27cd;
	}
x86_l_2795:
	/* 0x2795: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_279b:
	/* 0x279b: jmp    27eb <__do_str+0x1a9> */
	goto x86_l_27eb;
x86_l_279d:
	/* 0x279d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_279f:
	/* 0x279f: jmp    27f5 <__do_str+0x1b3> */
	goto x86_l_27f5;
x86_l_27a1:
	/* 0x27a1: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_27a5:
	/* 0x27a5: je     27dd <__do_str+0x19b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27dd;
	}
x86_l_27a7:
	/* 0x27a7: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_27ab:
	/* 0x27ab: je     27e5 <__do_str+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e5;
	}
x86_l_27ad:
	/* 0x27ad: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_27b1:
	/* 0x27b1: jne    27cd <__do_str+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27cd;
	}
x86_l_27b3:
	/* 0x27b3: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_27b9:
	/* 0x27b9: jmp    27eb <__do_str+0x1a9> */
	goto x86_l_27eb;
x86_l_27bb:
	/* 0x27bb: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_27bf:
	/* 0x27bf: je     27dd <__do_str+0x19b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27dd;
	}
x86_l_27c1:
	/* 0x27c1: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_27c5:
	/* 0x27c5: je     27e5 <__do_str+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e5;
	}
x86_l_27c7:
	/* 0x27c7: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_27cb:
	/* 0x27cb: je     27b3 <__do_str+0x171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27b3;
	}
x86_l_27cd:
	/* 0x27cd: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_27d3:
	/* 0x27d3: jmp    27eb <__do_str+0x1a9> */
	goto x86_l_27eb;
x86_l_27d5:
	/* 0x27d5: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_27db:
	/* 0x27db: jmp    27eb <__do_str+0x1a9> */
	goto x86_l_27eb;
x86_l_27dd:
	/* 0x27dd: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_27e3:
	/* 0x27e3: jmp    27eb <__do_str+0x1a9> */
	goto x86_l_27eb;
x86_l_27e5:
	/* 0x27e5: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_27eb:
	/* 0x27eb: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_27ef:
	/* 0x27ef: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_27f2:
	/* 0x27f2: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_27f5:
	/* 0x27f5: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_27f9:
	/* 0x27f9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_27fa:
	/* 0x27fa: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_27fc:
	/* 0x27fc: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_27fe:
	/* 0x27fe: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2800:
	/* 0x2800: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_execve_event_v61_event_execve_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 9708U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1679ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1684ULL && __x86_pc <= 3395ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3398ULL && __x86_pc <= 5156ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5161ULL && __x86_pc <= 6862ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6864ULL && __x86_pc <= 8438ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8441ULL && __x86_pc <= 9778ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9781ULL && __x86_pc <= 10240ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

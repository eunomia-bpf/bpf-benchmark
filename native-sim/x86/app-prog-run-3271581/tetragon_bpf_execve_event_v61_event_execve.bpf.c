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
	case 5ULL: goto x86_l_5;
	case 7ULL: goto x86_l_7;
	case 9ULL: goto x86_l_9;
	case 10ULL: goto x86_l_a;
	case 17ULL: goto x86_l_11;
	case 20ULL: goto x86_l_14;
	case 25ULL: goto x86_l_19;
	case 27ULL: goto x86_l_1b;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 46ULL: goto x86_l_2e;
	case 53ULL: goto x86_l_35;
	case 61ULL: goto x86_l_3d;
	case 66ULL: goto x86_l_42;
	case 68ULL: goto x86_l_44;
	case 71ULL: goto x86_l_47;
	case 77ULL: goto x86_l_4d;
	case 80ULL: goto x86_l_50;
	case 85ULL: goto x86_l_55;
	case 87ULL: goto x86_l_57;
	case 90ULL: goto x86_l_5a;
	case 95ULL: goto x86_l_5f;
	case 97ULL: goto x86_l_61;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 132ULL: goto x86_l_84;
	case 137ULL: goto x86_l_89;
	case 142ULL: goto x86_l_8e;
	case 144ULL: goto x86_l_90;
	case 149ULL: goto x86_l_95;
	case 152ULL: goto x86_l_98;
	case 160ULL: goto x86_l_a0;
	case 168ULL: goto x86_l_a8;
	case 174ULL: goto x86_l_ae;
	case 181ULL: goto x86_l_b5;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 196ULL: goto x86_l_c4;
	case 201ULL: goto x86_l_c9;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 213ULL: goto x86_l_d5;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 227ULL: goto x86_l_e3;
	case 230ULL: goto x86_l_e6;
	case 235ULL: goto x86_l_eb;
	case 237ULL: goto x86_l_ed;
	case 240ULL: goto x86_l_f0;
	case 242ULL: goto x86_l_f2;
	case 245ULL: goto x86_l_f5;
	case 250ULL: goto x86_l_fa;
	case 256ULL: goto x86_l_100;
	case 261ULL: goto x86_l_105;
	case 266ULL: goto x86_l_10a;
	case 269ULL: goto x86_l_10d;
	case 274ULL: goto x86_l_112;
	case 279ULL: goto x86_l_117;
	case 284ULL: goto x86_l_11c;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 296ULL: goto x86_l_128;
	case 301ULL: goto x86_l_12d;
	case 304ULL: goto x86_l_130;
	case 310ULL: goto x86_l_136;
	case 317ULL: goto x86_l_13d;
	case 322ULL: goto x86_l_142;
	case 327ULL: goto x86_l_147;
	case 332ULL: goto x86_l_14c;
	case 337ULL: goto x86_l_151;
	case 342ULL: goto x86_l_156;
	case 347ULL: goto x86_l_15b;
	case 349ULL: goto x86_l_15d;
	case 353ULL: goto x86_l_161;
	case 356ULL: goto x86_l_164;
	case 363ULL: goto x86_l_16b;
	case 366ULL: goto x86_l_16e;
	case 371ULL: goto x86_l_173;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 386ULL: goto x86_l_182;
	case 392ULL: goto x86_l_188;
	case 397ULL: goto x86_l_18d;
	case 402ULL: goto x86_l_192;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 415ULL: goto x86_l_19f;
	case 420ULL: goto x86_l_1a4;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 432ULL: goto x86_l_1b0;
	case 437ULL: goto x86_l_1b5;
	case 440ULL: goto x86_l_1b8;
	case 446ULL: goto x86_l_1be;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 489ULL: goto x86_l_1e9;
	case 492ULL: goto x86_l_1ec;
	case 499ULL: goto x86_l_1f3;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 512ULL: goto x86_l_200;
	case 514ULL: goto x86_l_202;
	case 517ULL: goto x86_l_205;
	case 522ULL: goto x86_l_20a;
	case 528ULL: goto x86_l_210;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 541ULL: goto x86_l_21d;
	case 546ULL: goto x86_l_222;
	case 551ULL: goto x86_l_227;
	case 556ULL: goto x86_l_22c;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 582ULL: goto x86_l_246;
	case 589ULL: goto x86_l_24d;
	case 594ULL: goto x86_l_252;
	case 599ULL: goto x86_l_257;
	case 604ULL: goto x86_l_25c;
	case 609ULL: goto x86_l_261;
	case 614ULL: goto x86_l_266;
	case 619ULL: goto x86_l_26b;
	case 621ULL: goto x86_l_26d;
	case 625ULL: goto x86_l_271;
	case 628ULL: goto x86_l_274;
	case 635ULL: goto x86_l_27b;
	case 638ULL: goto x86_l_27e;
	case 643ULL: goto x86_l_283;
	case 645ULL: goto x86_l_285;
	case 648ULL: goto x86_l_288;
	case 654ULL: goto x86_l_28e;
	case 657ULL: goto x86_l_291;
	case 662ULL: goto x86_l_296;
	case 668ULL: goto x86_l_29c;
	case 672ULL: goto x86_l_2a0;
	case 676ULL: goto x86_l_2a4;
	case 683ULL: goto x86_l_2ab;
	case 690ULL: goto x86_l_2b2;
	case 697ULL: goto x86_l_2b9;
	case 704ULL: goto x86_l_2c0;
	case 707ULL: goto x86_l_2c3;
	case 712ULL: goto x86_l_2c8;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 726ULL: goto x86_l_2d6;
	case 733ULL: goto x86_l_2dd;
	case 739ULL: goto x86_l_2e3;
	case 744ULL: goto x86_l_2e8;
	case 752ULL: goto x86_l_2f0;
	case 757ULL: goto x86_l_2f5;
	case 764ULL: goto x86_l_2fc;
	case 767ULL: goto x86_l_2ff;
	case 773ULL: goto x86_l_305;
	case 778ULL: goto x86_l_30a;
	case 781ULL: goto x86_l_30d;
	case 788ULL: goto x86_l_314;
	case 791ULL: goto x86_l_317;
	case 795ULL: goto x86_l_31b;
	case 800ULL: goto x86_l_320;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 814ULL: goto x86_l_32e;
	case 817ULL: goto x86_l_331;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 830ULL: goto x86_l_33e;
	case 835ULL: goto x86_l_343;
	case 838ULL: goto x86_l_346;
	case 840ULL: goto x86_l_348;
	case 843ULL: goto x86_l_34b;
	case 845ULL: goto x86_l_34d;
	case 848ULL: goto x86_l_350;
	case 851ULL: goto x86_l_353;
	case 853ULL: goto x86_l_355;
	case 861ULL: goto x86_l_35d;
	case 864ULL: goto x86_l_360;
	case 867ULL: goto x86_l_363;
	case 870ULL: goto x86_l_366;
	case 876ULL: goto x86_l_36c;
	case 879ULL: goto x86_l_36f;
	case 881ULL: goto x86_l_371;
	case 883ULL: goto x86_l_373;
	case 888ULL: goto x86_l_378;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 905ULL: goto x86_l_389;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 917ULL: goto x86_l_395;
	case 922ULL: goto x86_l_39a;
	case 925ULL: goto x86_l_39d;
	case 927ULL: goto x86_l_39f;
	case 934ULL: goto x86_l_3a6;
	case 939ULL: goto x86_l_3ab;
	case 944ULL: goto x86_l_3b0;
	case 949ULL: goto x86_l_3b5;
	case 954ULL: goto x86_l_3ba;
	case 956ULL: goto x86_l_3bc;
	case 960ULL: goto x86_l_3c0;
	case 962ULL: goto x86_l_3c2;
	case 964ULL: goto x86_l_3c4;
	case 971ULL: goto x86_l_3cb;
	case 982ULL: goto x86_l_3d6;
	case 987ULL: goto x86_l_3db;
	case 992ULL: goto x86_l_3e0;
	case 997ULL: goto x86_l_3e5;
	case 1000ULL: goto x86_l_3e8;
	case 1007ULL: goto x86_l_3ef;
	case 1010ULL: goto x86_l_3f2;
	case 1014ULL: goto x86_l_3f6;
	case 1019ULL: goto x86_l_3fb;
	case 1026ULL: goto x86_l_402;
	case 1031ULL: goto x86_l_407;
	case 1033ULL: goto x86_l_409;
	case 1036ULL: goto x86_l_40c;
	case 1038ULL: goto x86_l_40e;
	case 1041ULL: goto x86_l_411;
	case 1045ULL: goto x86_l_415;
	case 1050ULL: goto x86_l_41a;
	case 1053ULL: goto x86_l_41d;
	case 1055ULL: goto x86_l_41f;
	case 1058ULL: goto x86_l_422;
	case 1060ULL: goto x86_l_424;
	case 1063ULL: goto x86_l_427;
	case 1066ULL: goto x86_l_42a;
	case 1068ULL: goto x86_l_42c;
	case 1076ULL: goto x86_l_434;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1085ULL: goto x86_l_43d;
	case 1087ULL: goto x86_l_43f;
	case 1090ULL: goto x86_l_442;
	case 1092ULL: goto x86_l_444;
	case 1094ULL: goto x86_l_446;
	case 1099ULL: goto x86_l_44b;
	case 1102ULL: goto x86_l_44e;
	case 1109ULL: goto x86_l_455;
	case 1117ULL: goto x86_l_45d;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1132ULL: goto x86_l_46c;
	case 1139ULL: goto x86_l_473;
	case 1150ULL: goto x86_l_47e;
	case 1153ULL: goto x86_l_481;
	case 1157ULL: goto x86_l_485;
	case 1168ULL: goto x86_l_490;
	case 1175ULL: goto x86_l_497;
	case 1182ULL: goto x86_l_49e;
	case 1187ULL: goto x86_l_4a3;
	case 1189ULL: goto x86_l_4a5;
	case 1193ULL: goto x86_l_4a9;
	case 1196ULL: goto x86_l_4ac;
	case 1201ULL: goto x86_l_4b1;
	case 1206ULL: goto x86_l_4b6;
	case 1211ULL: goto x86_l_4bb;
	case 1213ULL: goto x86_l_4bd;
	case 1217ULL: goto x86_l_4c1;
	case 1219ULL: goto x86_l_4c3;
	case 1222ULL: goto x86_l_4c6;
	case 1224ULL: goto x86_l_4c8;
	case 1228ULL: goto x86_l_4cc;
	case 1233ULL: goto x86_l_4d1;
	case 1238ULL: goto x86_l_4d6;
	case 1243ULL: goto x86_l_4db;
	case 1247ULL: goto x86_l_4df;
	case 1251ULL: goto x86_l_4e3;
	case 1256ULL: goto x86_l_4e8;
	case 1258ULL: goto x86_l_4ea;
	case 1262ULL: goto x86_l_4ee;
	case 1264ULL: goto x86_l_4f0;
	case 1266ULL: goto x86_l_4f2;
	case 1270ULL: goto x86_l_4f6;
	case 1273ULL: goto x86_l_4f9;
	case 1276ULL: goto x86_l_4fc;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1298ULL: goto x86_l_512;
	case 1302ULL: goto x86_l_516;
	case 1306ULL: goto x86_l_51a;
	case 1309ULL: goto x86_l_51d;
	case 1312ULL: goto x86_l_520;
	case 1319ULL: goto x86_l_527;
	case 1324ULL: goto x86_l_52c;
	case 1326ULL: goto x86_l_52e;
	case 1330ULL: goto x86_l_532;
	case 1337ULL: goto x86_l_539;
	case 1342ULL: goto x86_l_53e;
	case 1344ULL: goto x86_l_540;
	case 1351ULL: goto x86_l_547;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1369ULL: goto x86_l_559;
	case 1378ULL: goto x86_l_562;
	case 1381ULL: goto x86_l_565;
	case 1383ULL: goto x86_l_567;
	case 1386ULL: goto x86_l_56a;
	case 1390ULL: goto x86_l_56e;
	case 1395ULL: goto x86_l_573;
	case 1400ULL: goto x86_l_578;
	case 1405ULL: goto x86_l_57d;
	case 1410ULL: goto x86_l_582;
	case 1412ULL: goto x86_l_584;
	case 1417ULL: goto x86_l_589;
	case 1419ULL: goto x86_l_58b;
	case 1421ULL: goto x86_l_58d;
	case 1428ULL: goto x86_l_594;
	case 1433ULL: goto x86_l_599;
	case 1440ULL: goto x86_l_5a0;
	case 1445ULL: goto x86_l_5a5;
	case 1450ULL: goto x86_l_5aa;
	case 1453ULL: goto x86_l_5ad;
	case 1455ULL: goto x86_l_5af;
	case 1458ULL: goto x86_l_5b2;
	case 1460ULL: goto x86_l_5b4;
	case 1462ULL: goto x86_l_5b6;
	case 1469ULL: goto x86_l_5bd;
	case 1473ULL: goto x86_l_5c1;
	case 1480ULL: goto x86_l_5c8;
	case 1483ULL: goto x86_l_5cb;
	case 1490ULL: goto x86_l_5d2;
	case 1495ULL: goto x86_l_5d7;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1514ULL: goto x86_l_5ea;
	case 1516ULL: goto x86_l_5ec;
	case 1518ULL: goto x86_l_5ee;
	case 1525ULL: goto x86_l_5f5;
	case 1532ULL: goto x86_l_5fc;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1542ULL: goto x86_l_606;
	case 1545ULL: goto x86_l_609;
	case 1547ULL: goto x86_l_60b;
	case 1550ULL: goto x86_l_60e;
	case 1552ULL: goto x86_l_610;
	case 1563ULL: goto x86_l_61b;
	case 1574ULL: goto x86_l_626;
	case 1585ULL: goto x86_l_631;
	case 1587ULL: goto x86_l_633;
	case 1594ULL: goto x86_l_63a;
	case 1601ULL: goto x86_l_641;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1611ULL: goto x86_l_64b;
	case 1614ULL: goto x86_l_64e;
	case 1616ULL: goto x86_l_650;
	case 1619ULL: goto x86_l_653;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1639ULL: goto x86_l_667;
	case 1644ULL: goto x86_l_66c;
	case 1647ULL: goto x86_l_66f;
	case 1649ULL: goto x86_l_671;
	case 1651ULL: goto x86_l_673;
	case 1653ULL: goto x86_l_675;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1662ULL: goto x86_l_67e;
	case 1665ULL: goto x86_l_681;
	case 1668ULL: goto x86_l_684;
	case 1671ULL: goto x86_l_687;
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
	/* 0xa: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_11:
	/* 0x11: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_19:
	/* 0x19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b:
	/* 0x1b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1e:
	/* 0x1e: movzx  r12d,WORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_23:
	/* 0x23: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_2e:
	/* 0x2e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_35:
	/* 0x35: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3d:
	/* 0x3d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42:
	/* 0x42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44:
	/* 0x44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_47:
	/* 0x47: je     1f77 <event_execve+0x1f77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8055ULL;
	}
x86_l_4d:
	/* 0x4d: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_55:
	/* 0x55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57:
	/* 0x57: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5a:
	/* 0x5a: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_5f:
	/* 0x5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61:
	/* 0x61: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69:
	/* 0x69: add    rcx,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_70:
	/* 0x70: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_75:
	/* 0x75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_7a:
	/* 0x7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f:
	/* 0x7f: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_84:
	/* 0x84: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_89:
	/* 0x89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e:
	/* 0x8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90:
	/* 0x90: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_95:
	/* 0x95: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_98:
	/* 0x98: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a0:
	/* 0xa0: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a8:
	/* 0xa8: je     378 <event_execve+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_ae:
	/* 0xae: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_b5:
	/* 0xb5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba:
	/* 0xba: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_bf:
	/* 0xbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c4:
	/* 0xc4: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_c9:
	/* 0xc9: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_ce:
	/* 0xce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d3:
	/* 0xd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5:
	/* 0xd5: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d9:
	/* 0xd9: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc:
	/* 0xdc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_e3:
	/* 0xe3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e6:
	/* 0xe6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eb:
	/* 0xeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed:
	/* 0xed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0:
	/* 0xf0: je     100 <event_execve+0x100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_100;
	}
x86_l_f2:
	/* 0xf2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_f5:
	/* 0xf5: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fa:
	/* 0xfa: jne    29c <event_execve+0x29c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29c;
	}
x86_l_100:
	/* 0x100: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_105:
	/* 0x105: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10a:
	/* 0x10a: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_10d:
	/* 0x10d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_112:
	/* 0x112: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_117:
	/* 0x117: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11c:
	/* 0x11c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_121:
	/* 0x121: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_126:
	/* 0x126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128:
	/* 0x128: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12d:
	/* 0x12d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_130:
	/* 0x130: je     378 <event_execve+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_136:
	/* 0x136: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_13d:
	/* 0x13d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_142:
	/* 0x142: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_147:
	/* 0x147: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14c:
	/* 0x14c: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_151:
	/* 0x151: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_156:
	/* 0x156: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15b:
	/* 0x15b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d:
	/* 0x15d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161:
	/* 0x161: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_164:
	/* 0x164: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_16b:
	/* 0x16b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_16e:
	/* 0x16e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_173:
	/* 0x173: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175:
	/* 0x175: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_178:
	/* 0x178: je     188 <event_execve+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_188;
	}
x86_l_17a:
	/* 0x17a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_17d:
	/* 0x17d: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_182:
	/* 0x182: jne    29c <event_execve+0x29c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29c;
	}
x86_l_188:
	/* 0x188: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_18d:
	/* 0x18d: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_192:
	/* 0x192: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_195:
	/* 0x195: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19a:
	/* 0x19a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f:
	/* 0x19f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a4:
	/* 0x1a4: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1a9:
	/* 0x1a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae:
	/* 0x1ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0:
	/* 0x1b0: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b5:
	/* 0x1b5: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1b8:
	/* 0x1b8: je     378 <event_execve+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_1be:
	/* 0x1be: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_1c5:
	/* 0x1c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ca:
	/* 0x1ca: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1cf:
	/* 0x1cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d4:
	/* 0x1d4: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_1d9:
	/* 0x1d9: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1de:
	/* 0x1de: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e3:
	/* 0x1e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5:
	/* 0x1e5: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e9:
	/* 0x1e9: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec:
	/* 0x1ec: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1f3:
	/* 0x1f3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fb:
	/* 0x1fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd:
	/* 0x1fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_200:
	/* 0x200: je     210 <event_execve+0x210> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_210;
	}
x86_l_202:
	/* 0x202: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_205:
	/* 0x205: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_20a:
	/* 0x20a: jne    29c <event_execve+0x29c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29c;
	}
x86_l_210:
	/* 0x210: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_215:
	/* 0x215: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21a:
	/* 0x21a: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21d:
	/* 0x21d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_222:
	/* 0x222: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_227:
	/* 0x227: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c:
	/* 0x22c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_231:
	/* 0x231: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_236:
	/* 0x236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238:
	/* 0x238: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23d:
	/* 0x23d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_240:
	/* 0x240: je     378 <event_execve+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_246:
	/* 0x246: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_24d:
	/* 0x24d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_252:
	/* 0x252: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_257:
	/* 0x257: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25c:
	/* 0x25c: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_261:
	/* 0x261: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_266:
	/* 0x266: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26b:
	/* 0x26b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d:
	/* 0x26d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_271:
	/* 0x271: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_274:
	/* 0x274: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_27b:
	/* 0x27b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_27e:
	/* 0x27e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_283:
	/* 0x283: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285:
	/* 0x285: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_288:
	/* 0x288: je     378 <event_execve+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_28e:
	/* 0x28e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_291:
	/* 0x291: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_296:
	/* 0x296: je     378 <event_execve+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_29c:
	/* 0x29c: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a0:
	/* 0x2a0: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a4:
	/* 0x2a4: mov    QWORD PTR [r14+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2ab:
	/* 0x2ab: mov    QWORD PTR [r14+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b2:
	/* 0x2b2: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9:
	/* 0x2b9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_gen)));
x86_l_2c0:
	/* 0x2c0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2c3:
	/* 0x2c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c8:
	/* 0x2c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca:
	/* 0x2ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cd:
	/* 0x2cd: je     46a <event_execve+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46a;
	}
x86_l_2d3:
	/* 0x2d3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d6:
	/* 0x2d6: cmp    rcx,QWORD PTR [rbp+0x378] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 888ULL);
x86_l_2dd:
	/* 0x2dd: je     46a <event_execve+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46a;
	}
x86_l_2e3:
	/* 0x2e3: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e8:
	/* 0x2e8: mov    QWORD PTR [rsp+0x88],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2f0:
	/* 0x2f0: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f5:
	/* 0x2f5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2fc:
	/* 0x2fc: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ff:
	/* 0x2ff: je     3e0 <event_execve+0x3e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e0;
	}
x86_l_305:
	/* 0x305: mov    ebx,0x1869f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 99999ULL);
x86_l_30a:
	/* 0x30a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30d:
	/* 0x30d: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_314:
	/* 0x314: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_317:
	/* 0x317: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31b:
	/* 0x31b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_320:
	/* 0x320: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_327:
	/* 0x327: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32c:
	/* 0x32c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e:
	/* 0x32e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_331:
	/* 0x331: je     446 <event_execve+0x446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_446;
	}
x86_l_337:
	/* 0x337: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_33a:
	/* 0x33a: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_33e:
	/* 0x33e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_343:
	/* 0x343: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_346:
	/* 0x346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_348:
	/* 0x348: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34b:
	/* 0x34b: je     35d <event_execve+0x35d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d;
	}
x86_l_34d:
	/* 0x34d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_350:
	/* 0x350: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_353:
	/* 0x353: je     35d <event_execve+0x35d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d;
	}
x86_l_355:
	/* 0x355: or QWORD PTR [rbp+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_35d:
	/* 0x35d: sub    ebx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_360:
	/* 0x360: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_363:
	/* 0x363: cmp    r12,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R15, X86_WIDTH_64);
x86_l_366:
	/* 0x366: je     446 <event_execve+0x446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_446;
	}
x86_l_36c:
	/* 0x36c: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_36f:
	/* 0x36f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_371:
	/* 0x371: je     314 <event_execve+0x314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314;
	}
x86_l_373:
	/* 0x373: jmp    446 <event_execve+0x446> */
	goto x86_l_446;
x86_l_378:
	/* 0x378: lea    rdx,[rbx+0xae0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2784ULL);
x86_l_37f:
	/* 0x37f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_384:
	/* 0x384: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_389:
	/* 0x389: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38e:
	/* 0x38e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_393:
	/* 0x393: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_395:
	/* 0x395: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39a:
	/* 0x39a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_39d:
	/* 0x39d: je     3c2 <event_execve+0x3c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c2;
	}
x86_l_39f:
	/* 0x39f: add    rdx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_3a6:
	/* 0x3a6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ab:
	/* 0x3ab: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3b0:
	/* 0x3b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b5:
	/* 0x3b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ba:
	/* 0x3ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bc:
	/* 0x3bc: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c0:
	/* 0x3c0: jmp    3c4 <event_execve+0x3c4> */
	goto x86_l_3c4;
x86_l_3c2:
	/* 0x3c2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c4:
	/* 0x3c4: mov    DWORD PTR [r14+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3cb:
	/* 0x3cb: mov    QWORD PTR [r14+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3d6:
	/* 0x3d6: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_3db:
	/* 0x3db: jmp    46c <event_execve+0x46c> */
	goto x86_l_46c;
x86_l_3e0:
	/* 0x3e0: mov    ebx,0x3ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1023ULL);
x86_l_3e5:
	/* 0x3e5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e8:
	/* 0x3e8: mov    r13,QWORD PTR [rip+0xc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_3ef:
	/* 0x3ef: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f2:
	/* 0x3f2: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f6:
	/* 0x3f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3fb:
	/* 0x3fb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_402:
	/* 0x402: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_407:
	/* 0x407: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_409:
	/* 0x409: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40c:
	/* 0x40c: je     446 <event_execve+0x446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_446;
	}
x86_l_40e:
	/* 0x40e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_411:
	/* 0x411: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_415:
	/* 0x415: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41a:
	/* 0x41a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_41d:
	/* 0x41d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41f:
	/* 0x41f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_422:
	/* 0x422: je     434 <event_execve+0x434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_434;
	}
x86_l_424:
	/* 0x424: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_427:
	/* 0x427: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_42a:
	/* 0x42a: je     434 <event_execve+0x434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_434;
	}
x86_l_42c:
	/* 0x42c: or QWORD PTR [rbp+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_434:
	/* 0x434: sub    ebx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_437:
	/* 0x437: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_43a:
	/* 0x43a: cmp    r12,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R15, X86_WIDTH_64);
x86_l_43d:
	/* 0x43d: je     446 <event_execve+0x446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_446;
	}
x86_l_43f:
	/* 0x43f: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_442:
	/* 0x442: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_444:
	/* 0x444: je     3ef <event_execve+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ef;
	}
x86_l_446:
	/* 0x446: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_44b:
	/* 0x44b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44e:
	/* 0x44e: mov    QWORD PTR [rbp+0x378],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 888ULL);
x86_l_455:
	/* 0x455: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_45d:
	/* 0x45d: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_465:
	/* 0x465: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_46a:
	/* 0x46a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46c:
	/* 0x46c: mov    QWORD PTR [r14+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_473:
	/* 0x473: mov    DWORD PTR [r14+0x15c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619009ULL);
x86_l_47e:
	/* 0x47e: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_481:
	/* 0x481: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_485:
	/* 0x485: mov    QWORD PTR [r14+0x178],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1614907703296ULL);
x86_l_490:
	/* 0x490: mov    DWORD PTR [r14+0x144],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_497:
	/* 0x497: mov    DWORD PTR [r14+0x148],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_49e:
	/* 0x49e: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_4a3:
	/* 0x4a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a5:
	/* 0x4a5: lea    rdx,[rax+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4a9:
	/* 0x4a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ac:
	/* 0x4ac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b1:
	/* 0x4b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b6:
	/* 0x4b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bb:
	/* 0x4bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bd:
	/* 0x4bd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c1:
	/* 0x4c1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c3:
	/* 0x4c3: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4c6:
	/* 0x4c6: je     532 <event_execve+0x532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_532;
	}
x86_l_4c8:
	/* 0x4c8: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4cc:
	/* 0x4cc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d1:
	/* 0x4d1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4d6:
	/* 0x4d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4db:
	/* 0x4db: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4df:
	/* 0x4df: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4e3:
	/* 0x4e3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e8:
	/* 0x4e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ea:
	/* 0x4ea: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ee:
	/* 0x4ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f0:
	/* 0x4f0: je     532 <event_execve+0x532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_532;
	}
x86_l_4f2:
	/* 0x4f2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f6:
	/* 0x4f6: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_4f9:
	/* 0x4f9: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4fc:
	/* 0x4fc: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_503:
	/* 0x503: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_508:
	/* 0x508: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_50d:
	/* 0x50d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_512:
	/* 0x512: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_516:
	/* 0x516: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51a:
	/* 0x51a: shl    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_51d:
	/* 0x51d: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_520:
	/* 0x520: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_527:
	/* 0x527: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_52c:
	/* 0x52c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52e:
	/* 0x52e: mov    ebx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_532:
	/* 0x532: mov    DWORD PTR [r14+0x14c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 332ULL);
x86_l_539:
	/* 0x539: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_53e:
	/* 0x53e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_540:
	/* 0x540: mov    QWORD PTR [r14+0x170],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_547:
	/* 0x547: mov    DWORD PTR [r14+0x140],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534784ULL);
x86_l_552:
	/* 0x552: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_557:
	/* 0x557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_559:
	/* 0x559: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_562:
	/* 0x562: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_565:
	/* 0x565: je     58b <event_execve+0x58b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58b;
	}
x86_l_567:
	/* 0x567: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_56a:
	/* 0x56a: add    rdx,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_56e:
	/* 0x56e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_573:
	/* 0x573: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_578:
	/* 0x578: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_57d:
	/* 0x57d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_582:
	/* 0x582: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_584:
	/* 0x584: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_589:
	/* 0x589: jmp    58d <event_execve+0x58d> */
	goto x86_l_58d;
x86_l_58b:
	/* 0x58b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58d:
	/* 0x58d: mov    DWORD PTR [r14+0x158],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_594:
	/* 0x594: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_599:
	/* 0x599: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map)));
x86_l_5a0:
	/* 0x5a0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a5:
	/* 0x5a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5aa:
	/* 0x5aa: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ad:
	/* 0x5ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5af:
	/* 0x5af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b2:
	/* 0x5b2: je     610 <event_execve+0x610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_610;
	}
x86_l_5b4:
	/* 0x5b4: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b6:
	/* 0x5b6: mov    DWORD PTR [r14+0x150],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_5bd:
	/* 0x5bd: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c1:
	/* 0x5c1: mov    QWORD PTR [r14+0x168],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_5c8:
	/* 0x5c8: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5cb:
	/* 0x5cb: mov    DWORD PTR [r14+0x160],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_5d2:
	/* 0x5d2: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d7:
	/* 0x5d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map)));
x86_l_5de:
	/* 0x5de: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e3:
	/* 0x5e3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5e8:
	/* 0x5e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ea:
	/* 0x5ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ec:
	/* 0x5ec: je     633 <event_execve+0x633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_633;
	}
x86_l_5ee:
	/* 0x5ee: mov    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_5f5:
	/* 0x5f5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map_stats)));
x86_l_5fc:
	/* 0x5fc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5ff:
	/* 0x5ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_604:
	/* 0x604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_606:
	/* 0x606: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_609:
	/* 0x609: je     653 <event_execve+0x653> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_653;
	}
x86_l_60b:
	/* 0x60b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_60e:
	/* 0x60e: jmp    653 <event_execve+0x653> */
	goto x86_l_653;
x86_l_610:
	/* 0x610: mov    DWORD PTR [r14+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_61b:
	/* 0x61b: mov    QWORD PTR [r14+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_626:
	/* 0x626: mov    DWORD PTR [r14+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_631:
	/* 0x631: jmp    653 <event_execve+0x653> */
	goto x86_l_653;
x86_l_633:
	/* 0x633: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63a:
	/* 0x63a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map_stats)));
x86_l_641:
	/* 0x641: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_644:
	/* 0x644: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_649:
	/* 0x649: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64b:
	/* 0x64b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64e:
	/* 0x64e: je     653 <event_execve+0x653> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_653;
	}
x86_l_650:
	/* 0x650: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_653:
	/* 0x653: lea    rbx,[r14+0x180] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_65a:
	/* 0x65a: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_65f:
	/* 0x65f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_664:
	/* 0x664: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_667:
	/* 0x667: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_66c:
	/* 0x66c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_66f:
	/* 0x66f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_671:
	/* 0x671: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_673:
	/* 0x673: js     6a0 <event_execve+0x6a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1696ULL;
	}
x86_l_675:
	/* 0x675: je     6a9 <event_execve+0x6a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1705ULL;
	}
x86_l_677:
	/* 0x677: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_67c:
	/* 0x67c: jne    6ad <event_execve+0x6ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1709ULL;
	}
x86_l_67e:
	/* 0x67e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_681:
	/* 0x681: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_684:
	/* 0x684: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_687:
	/* 0x687: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1676ULL);
	__x86_sim_call_depth++;
	return 8079ULL;
	return 1676ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1676ULL: goto x86_l_68c;
	case 1679ULL: goto x86_l_68f;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1694ULL: goto x86_l_69e;
	case 1696ULL: goto x86_l_6a0;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1705ULL: goto x86_l_6a9;
	case 1707ULL: goto x86_l_6ab;
	case 1709ULL: goto x86_l_6ad;
	case 1711ULL: goto x86_l_6af;
	case 1713ULL: goto x86_l_6b1;
	case 1715ULL: goto x86_l_6b3;
	case 1723ULL: goto x86_l_6bb;
	case 1730ULL: goto x86_l_6c2;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1744ULL: goto x86_l_6d0;
	case 1755ULL: goto x86_l_6db;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1772ULL: goto x86_l_6ec;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1784ULL: goto x86_l_6f8;
	case 1787ULL: goto x86_l_6fb;
	case 1789ULL: goto x86_l_6fd;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1803ULL: goto x86_l_70b;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1837ULL: goto x86_l_72d;
	case 1840ULL: goto x86_l_730;
	case 1842ULL: goto x86_l_732;
	case 1844ULL: goto x86_l_734;
	case 1846ULL: goto x86_l_736;
	case 1853ULL: goto x86_l_73d;
	case 1860ULL: goto x86_l_744;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1877ULL: goto x86_l_755;
	case 1879ULL: goto x86_l_757;
	case 1886ULL: goto x86_l_75e;
	case 1891ULL: goto x86_l_763;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1901ULL: goto x86_l_76d;
	case 1907ULL: goto x86_l_773;
	case 1914ULL: goto x86_l_77a;
	case 1917ULL: goto x86_l_77d;
	case 1922ULL: goto x86_l_782;
	case 1927ULL: goto x86_l_787;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1944ULL: goto x86_l_798;
	case 1947ULL: goto x86_l_79b;
	case 1949ULL: goto x86_l_79d;
	case 1951ULL: goto x86_l_79f;
	case 1956ULL: goto x86_l_7a4;
	case 1963ULL: goto x86_l_7ab;
	case 1973ULL: goto x86_l_7b5;
	case 1978ULL: goto x86_l_7ba;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 1997ULL: goto x86_l_7cd;
	case 2000ULL: goto x86_l_7d0;
	case 2002ULL: goto x86_l_7d2;
	case 2004ULL: goto x86_l_7d4;
	case 2006ULL: goto x86_l_7d6;
	case 2014ULL: goto x86_l_7de;
	case 2021ULL: goto x86_l_7e5;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2042ULL: goto x86_l_7fa;
	case 2047ULL: goto x86_l_7ff;
	case 2052ULL: goto x86_l_804;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2082ULL: goto x86_l_822;
	case 2085ULL: goto x86_l_825;
	case 2087ULL: goto x86_l_827;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2101ULL: goto x86_l_835;
	case 2111ULL: goto x86_l_83f;
	case 2116ULL: goto x86_l_844;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2138ULL: goto x86_l_85a;
	case 2144ULL: goto x86_l_860;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2156ULL: goto x86_l_86c;
	case 2162ULL: goto x86_l_872;
	case 2168ULL: goto x86_l_878;
	case 2173ULL: goto x86_l_87d;
	case 2179ULL: goto x86_l_883;
	case 2186ULL: goto x86_l_88a;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2215ULL: goto x86_l_8a7;
	case 2218ULL: goto x86_l_8aa;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2232ULL: goto x86_l_8b8;
	case 2236ULL: goto x86_l_8bc;
	case 2241ULL: goto x86_l_8c1;
	case 2243ULL: goto x86_l_8c3;
	case 2248ULL: goto x86_l_8c8;
	case 2251ULL: goto x86_l_8cb;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2264ULL: goto x86_l_8d8;
	case 2268ULL: goto x86_l_8dc;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2284ULL: goto x86_l_8ec;
	case 2291ULL: goto x86_l_8f3;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2306ULL: goto x86_l_902;
	case 2309ULL: goto x86_l_905;
	case 2316ULL: goto x86_l_90c;
	case 2322ULL: goto x86_l_912;
	case 2325ULL: goto x86_l_915;
	case 2328ULL: goto x86_l_918;
	case 2335ULL: goto x86_l_91f;
	case 2338ULL: goto x86_l_922;
	case 2344ULL: goto x86_l_928;
	case 2346ULL: goto x86_l_92a;
	case 2352ULL: goto x86_l_930;
	case 2354ULL: goto x86_l_932;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2372ULL: goto x86_l_944;
	case 2375ULL: goto x86_l_947;
	case 2377ULL: goto x86_l_949;
	case 2380ULL: goto x86_l_94c;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2403ULL: goto x86_l_963;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2425ULL: goto x86_l_979;
	case 2430ULL: goto x86_l_97e;
	case 2435ULL: goto x86_l_983;
	case 2437ULL: goto x86_l_985;
	case 2440ULL: goto x86_l_988;
	case 2442ULL: goto x86_l_98a;
	case 2444ULL: goto x86_l_98c;
	case 2446ULL: goto x86_l_98e;
	case 2454ULL: goto x86_l_996;
	case 2461ULL: goto x86_l_99d;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2473ULL: goto x86_l_9a9;
	case 2478ULL: goto x86_l_9ae;
	case 2480ULL: goto x86_l_9b0;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2498ULL: goto x86_l_9c2;
	case 2500ULL: goto x86_l_9c4;
	case 2503ULL: goto x86_l_9c7;
	case 2506ULL: goto x86_l_9ca;
	case 2511ULL: goto x86_l_9cf;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2521ULL: goto x86_l_9d9;
	case 2523ULL: goto x86_l_9db;
	case 2525ULL: goto x86_l_9dd;
	case 2527ULL: goto x86_l_9df;
	case 2530ULL: goto x86_l_9e2;
	case 2532ULL: goto x86_l_9e4;
	case 2540ULL: goto x86_l_9ec;
	case 2547ULL: goto x86_l_9f3;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2568ULL: goto x86_l_a08;
	case 2570ULL: goto x86_l_a0a;
	case 2573ULL: goto x86_l_a0d;
	case 2575ULL: goto x86_l_a0f;
	case 2577ULL: goto x86_l_a11;
	case 2582ULL: goto x86_l_a16;
	case 2589ULL: goto x86_l_a1d;
	case 2596ULL: goto x86_l_a24;
	case 2604ULL: goto x86_l_a2c;
	case 2611ULL: goto x86_l_a33;
	case 2618ULL: goto x86_l_a3a;
	case 2626ULL: goto x86_l_a42;
	case 2632ULL: goto x86_l_a48;
	case 2640ULL: goto x86_l_a50;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2654ULL: goto x86_l_a5e;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2670ULL: goto x86_l_a6e;
	case 2673ULL: goto x86_l_a71;
	case 2680ULL: goto x86_l_a78;
	case 2683ULL: goto x86_l_a7b;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2700ULL: goto x86_l_a8c;
	case 2703ULL: goto x86_l_a8f;
	case 2709ULL: goto x86_l_a95;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2736ULL: goto x86_l_ab0;
	case 2739ULL: goto x86_l_ab3;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2749ULL: goto x86_l_abd;
	case 2755ULL: goto x86_l_ac3;
	case 2762ULL: goto x86_l_aca;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2775ULL: goto x86_l_ad7;
	case 2780ULL: goto x86_l_adc;
	case 2782ULL: goto x86_l_ade;
	case 2785ULL: goto x86_l_ae1;
	case 2791ULL: goto x86_l_ae7;
	case 2798ULL: goto x86_l_aee;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2821ULL: goto x86_l_b05;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2831ULL: goto x86_l_b0f;
	case 2837ULL: goto x86_l_b15;
	case 2844ULL: goto x86_l_b1c;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2857ULL: goto x86_l_b29;
	case 2862ULL: goto x86_l_b2e;
	case 2864ULL: goto x86_l_b30;
	case 2867ULL: goto x86_l_b33;
	case 2873ULL: goto x86_l_b39;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2903ULL: goto x86_l_b57;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2913ULL: goto x86_l_b61;
	case 2919ULL: goto x86_l_b67;
	case 2926ULL: goto x86_l_b6e;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2939ULL: goto x86_l_b7b;
	case 2944ULL: goto x86_l_b80;
	case 2946ULL: goto x86_l_b82;
	case 2949ULL: goto x86_l_b85;
	case 2955ULL: goto x86_l_b8b;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2985ULL: goto x86_l_ba9;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2995ULL: goto x86_l_bb3;
	case 3001ULL: goto x86_l_bb9;
	case 3008ULL: goto x86_l_bc0;
	case 3011ULL: goto x86_l_bc3;
	case 3016ULL: goto x86_l_bc8;
	case 3021ULL: goto x86_l_bcd;
	case 3026ULL: goto x86_l_bd2;
	case 3028ULL: goto x86_l_bd4;
	case 3031ULL: goto x86_l_bd7;
	case 3037ULL: goto x86_l_bdd;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3064ULL: goto x86_l_bf8;
	case 3067ULL: goto x86_l_bfb;
	case 3069ULL: goto x86_l_bfd;
	case 3074ULL: goto x86_l_c02;
	case 3077ULL: goto x86_l_c05;
	case 3083ULL: goto x86_l_c0b;
	case 3090ULL: goto x86_l_c12;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3103ULL: goto x86_l_c1f;
	case 3108ULL: goto x86_l_c24;
	case 3110ULL: goto x86_l_c26;
	case 3113ULL: goto x86_l_c29;
	case 3119ULL: goto x86_l_c2f;
	case 3126ULL: goto x86_l_c36;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3146ULL: goto x86_l_c4a;
	case 3149ULL: goto x86_l_c4d;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3159ULL: goto x86_l_c57;
	case 3165ULL: goto x86_l_c5d;
	case 3172ULL: goto x86_l_c64;
	case 3175ULL: goto x86_l_c67;
	case 3180ULL: goto x86_l_c6c;
	case 3185ULL: goto x86_l_c71;
	case 3190ULL: goto x86_l_c76;
	case 3192ULL: goto x86_l_c78;
	case 3195ULL: goto x86_l_c7b;
	case 3201ULL: goto x86_l_c81;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3218ULL: goto x86_l_c92;
	case 3223ULL: goto x86_l_c97;
	case 3228ULL: goto x86_l_c9c;
	case 3231ULL: goto x86_l_c9f;
	case 3233ULL: goto x86_l_ca1;
	case 3238ULL: goto x86_l_ca6;
	case 3241ULL: goto x86_l_ca9;
	case 3247ULL: goto x86_l_caf;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3267ULL: goto x86_l_cc3;
	case 3272ULL: goto x86_l_cc8;
	case 3274ULL: goto x86_l_cca;
	case 3277ULL: goto x86_l_ccd;
	case 3283ULL: goto x86_l_cd3;
	case 3290ULL: goto x86_l_cda;
	case 3295ULL: goto x86_l_cdf;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3310ULL: goto x86_l_cee;
	case 3313ULL: goto x86_l_cf1;
	case 3315ULL: goto x86_l_cf3;
	case 3320ULL: goto x86_l_cf8;
	case 3323ULL: goto x86_l_cfb;
	case 3329ULL: goto x86_l_d01;
	case 3336ULL: goto x86_l_d08;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3354ULL: goto x86_l_d1a;
	case 3356ULL: goto x86_l_d1c;
	case 3359ULL: goto x86_l_d1f;
	case 3365ULL: goto x86_l_d25;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_68c:
	/* 0x68c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_68f:
	/* 0x68f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_691:
	/* 0x691: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_696:
	/* 0x696: mov    eax,0x800000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8388608ULL);
x86_l_69b:
	/* 0x69b: cmove  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_E);
x86_l_69e:
	/* 0x69e: jmp    6b3 <event_execve+0x6b3> */
	goto x86_l_6b3;
x86_l_6a0:
	/* 0x6a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a2:
	/* 0x6a2: mov    eax,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_6a7:
	/* 0x6a7: jmp    6b3 <event_execve+0x6b3> */
	goto x86_l_6b3;
x86_l_6a9:
	/* 0x6a9: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6ab:
	/* 0x6ab: jmp    6b3 <event_execve+0x6b3> */
	goto x86_l_6b3;
x86_l_6ad:
	/* 0x6ad: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6af:
	/* 0x6af: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_6b1:
	/* 0x6b1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b3:
	/* 0x6b3: mov    WORD PTR [r14+0x178],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_6bb:
	/* 0x6bb: or     DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_6c2:
	/* 0x6c2: add    DWORD PTR [r14+0x140],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 320ULL);
x86_l_6c9:
	/* 0x6c9: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_6ce:
	/* 0x6ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d0:
	/* 0x6d0: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_6db:
	/* 0x6db: lea    rdx,[rax+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_6e2:
	/* 0x6e2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e7:
	/* 0x6e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6ec:
	/* 0x6ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6f1:
	/* 0x6f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f6:
	/* 0x6f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f8:
	/* 0x6f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6fb:
	/* 0x6fb: je     757 <event_execve+0x757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_757;
	}
x86_l_6fd:
	/* 0x6fd: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_6ff:
	/* 0x6ff: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_704:
	/* 0x704: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_70b:
	/* 0x70b: movabs rax,0x400000042 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869250ULL);
x86_l_715:
	/* 0x715: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_71a:
	/* 0x71a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_721:
	/* 0x721: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_726:
	/* 0x726: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_72b:
	/* 0x72b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72d:
	/* 0x72d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_730:
	/* 0x730: je     736 <event_execve+0x736> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_736;
	}
x86_l_732:
	/* 0x732: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_734:
	/* 0x734: jmp    757 <event_execve+0x757> */
	goto x86_l_757;
x86_l_736:
	/* 0x736: mov    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_73d:
	/* 0x73d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_744:
	/* 0x744: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_746:
	/* 0x746: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_74b:
	/* 0x74b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_74e:
	/* 0x74e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_753:
	/* 0x753: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_755:
	/* 0x755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_757:
	/* 0x757: lea    r12,[r14+0x140] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_75e:
	/* 0x75e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_763:
	/* 0x763: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_765:
	/* 0x765: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_76a:
	/* 0x76a: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_76d:
	/* 0x76d: je     a2c <event_execve+0xa2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a2c;
	}
x86_l_773:
	/* 0x773: add    rcx,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_77a:
	/* 0x77a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_77d:
	/* 0x77d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_782:
	/* 0x782: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_787:
	/* 0x787: mov    edx,0x188 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 392ULL);
x86_l_78c:
	/* 0x78c: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_791:
	/* 0x791: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_796:
	/* 0x796: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_798:
	/* 0x798: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_79b:
	/* 0x79b: je     7fa <event_execve+0x7fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7fa;
	}
x86_l_79d:
	/* 0x79d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_79f:
	/* 0x79f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a4:
	/* 0x7a4: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_7ab:
	/* 0x7ab: movabs rax,0x400000047 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869255ULL);
x86_l_7b5:
	/* 0x7b5: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7ba:
	/* 0x7ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7c1:
	/* 0x7c1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7c6:
	/* 0x7c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7cb:
	/* 0x7cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cd:
	/* 0x7cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d0:
	/* 0x7d0: je     7d6 <event_execve+0x7d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d6;
	}
x86_l_7d2:
	/* 0x7d2: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7d4:
	/* 0x7d4: jmp    7fa <event_execve+0x7fa> */
	goto x86_l_7fa;
x86_l_7d6:
	/* 0x7d6: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_7de:
	/* 0x7de: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7e5:
	/* 0x7e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e7:
	/* 0x7e7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7ec:
	/* 0x7ec: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7f1:
	/* 0x7f1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7f6:
	/* 0x7f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f8:
	/* 0x7f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fa:
	/* 0x7fa: mov    edx,0x190 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 400ULL);
x86_l_7ff:
	/* 0x7ff: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_804:
	/* 0x804: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_807:
	/* 0x807: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_80c:
	/* 0x80c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_811:
	/* 0x811: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_816:
	/* 0x816: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_81b:
	/* 0x81b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_820:
	/* 0x820: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_822:
	/* 0x822: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_825:
	/* 0x825: je     862 <event_execve+0x862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_862;
	}
x86_l_827:
	/* 0x827: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_829:
	/* 0x829: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_82e:
	/* 0x82e: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_835:
	/* 0x835: movabs rax,0x400000048 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869256ULL);
x86_l_83f:
	/* 0x83f: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_844:
	/* 0x844: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_84b:
	/* 0x84b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_850:
	/* 0x850: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_855:
	/* 0x855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_857:
	/* 0x857: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85a:
	/* 0x85a: je     98e <event_execve+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_860:
	/* 0x860: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_862:
	/* 0x862: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_867:
	/* 0x867: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_86c:
	/* 0x86c: je     a2c <event_execve+0xa2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a2c;
	}
x86_l_872:
	/* 0x872: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_878:
	/* 0x878: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_87d:
	/* 0x87d: je     a2c <event_execve+0xa2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a2c;
	}
x86_l_883:
	/* 0x883: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_heap)));
x86_l_88a:
	/* 0x88a: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_892:
	/* 0x892: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_897:
	/* 0x897: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_899:
	/* 0x899: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_89e:
	/* 0x89e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8a1:
	/* 0x8a1: je     a2c <event_execve+0xa2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a2c;
	}
x86_l_8a7:
	/* 0x8a7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_8aa:
	/* 0x8aa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ae:
	/* 0x8ae: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_8b3:
	/* 0x8b3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_8b8:
	/* 0x8b8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8bc:
	/* 0x8bc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_8c1:
	/* 0x8c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c3:
	/* 0x8c3: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_8c8:
	/* 0x8c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8cb:
	/* 0x8cb: js     a2c <event_execve+0xa2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a2c;
	}
x86_l_8d1:
	/* 0x8d1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_8d4:
	/* 0x8d4: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8d8:
	/* 0x8d8: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8dc:
	/* 0x8dc: mov    eax,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_8e3:
	/* 0x8e3: and    eax,0x1ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 511ULL);
x86_l_8e8:
	/* 0x8e8: lea    r8,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8ec:
	/* 0x8ec: add    r8,0x140 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 320ULL);
x86_l_8f3:
	/* 0x8f3: mov    DWORD PTR [r14+0x184c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6220ULL);
x86_l_8fa:
	/* 0x8fa: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ff:
	/* 0x8ff: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_902:
	/* 0x902: sub    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_905:
	/* 0x905: cmp    rcx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 1023ULL);
x86_l_90c:
	/* 0x90c: ja     9c4 <event_execve+0x9c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9c4;
	}
x86_l_912:
	/* 0x912: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_915:
	/* 0x915: sub    rdi,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_918:
	/* 0x918: add    rdi,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 1024ULL);
x86_l_91f:
	/* 0x91f: cmp    rcx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_922:
	/* 0x922: jae    9c4 <event_execve+0x9c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9c4;
	}
x86_l_928:
	/* 0x928: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_92a:
	/* 0x92a: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_930:
	/* 0x930: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_932:
	/* 0x932: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_935:
	/* 0x935: cmovne esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_938:
	/* 0x938: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_93d:
	/* 0x93d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_941:
	/* 0x941: mov    rdi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_64);
x86_l_944:
	/* 0x944: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_947:
	/* 0x947: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_949:
	/* 0x949: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_94c:
	/* 0x94c: je     9df <event_execve+0x9df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9df;
	}
x86_l_952:
	/* 0x952: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_955:
	/* 0x955: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_957:
	/* 0x957: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_95c:
	/* 0x95c: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_963:
	/* 0x963: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_96d:
	/* 0x96d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_972:
	/* 0x972: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_979:
	/* 0x979: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_97e:
	/* 0x97e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_983:
	/* 0x983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_985:
	/* 0x985: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_988:
	/* 0x988: je     9e4 <event_execve+0x9e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e4;
	}
x86_l_98a:
	/* 0x98a: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_98c:
	/* 0x98c: jmp    a08 <event_execve+0xa08> */
	goto x86_l_a08;
x86_l_98e:
	/* 0x98e: mov    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_996:
	/* 0x996: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_99d:
	/* 0x99d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_99f:
	/* 0x99f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a4:
	/* 0x9a4: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9a9:
	/* 0x9a9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9ae:
	/* 0x9ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b0:
	/* 0x9b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b2:
	/* 0x9b2: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b7:
	/* 0x9b7: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_9bc:
	/* 0x9bc: jne    872 <event_execve+0x872> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_872;
	}
x86_l_9c2:
	/* 0x9c2: jmp    a2c <event_execve+0xa2c> */
	goto x86_l_a2c;
x86_l_9c4:
	/* 0x9c4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_9c7:
	/* 0x9c7: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_9ca:
	/* 0x9ca: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2511ULL);
	__x86_sim_call_depth++;
	return 8267ULL;
x86_l_9cf:
	/* 0x9cf: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_9d2:
	/* 0x9d2: mov    eax,0x1000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16777216ULL);
x86_l_9d7:
	/* 0x9d7: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_9d9:
	/* 0x9d9: jne    a16 <event_execve+0xa16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a16;
	}
x86_l_9db:
	/* 0x9db: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9dd:
	/* 0x9dd: jmp    a1d <event_execve+0xa1d> */
	goto x86_l_a1d;
x86_l_9df:
	/* 0x9df: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_9e2:
	/* 0x9e2: jmp    a1d <event_execve+0xa1d> */
	goto x86_l_a1d;
x86_l_9e4:
	/* 0x9e4: mov    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_9ec:
	/* 0x9ec: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9f3:
	/* 0x9f3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f5:
	/* 0x9f5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9fa:
	/* 0x9fa: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9ff:
	/* 0x9ff: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a04:
	/* 0xa04: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a06:
	/* 0xa06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a08:
	/* 0xa08: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_a0a:
	/* 0xa0a: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_a0d:
	/* 0xa0d: jns    a1d <event_execve+0xa1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_a1d;
	}
x86_l_a0f:
	/* 0xa0f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a11:
	/* 0xa11: mov    eax,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_a16:
	/* 0xa16: or     DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_a1d:
	/* 0xa1d: mov    DWORD PTR [r14+0x1848],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6216ULL);
x86_l_a24:
	/* 0xa24: mov    WORD PTR [r14+0x17a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 378ULL);
x86_l_a2c:
	/* 0xa2c: add    ebx,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 320ULL);
x86_l_a33:
	/* 0xa33: mov    DWORD PTR [r14+0x140],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_a3a:
	/* 0xa3a: test   BYTE PTR [r14+0x15d],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1498943586336ULL);
x86_l_a42:
	/* 0xa42: jne    1586 <event_execve+0x1586> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5510ULL;
	}
x86_l_a48:
	/* 0xa48: mov    QWORD PTR [rsp+0x88],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a50:
	/* 0xa50: mov    ebx,DWORD PTR [r14+0x144] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_a57:
	/* 0xa57: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_a5c:
	/* 0xa5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5e:
	/* 0xa5e: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a65:
	/* 0xa65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a68:
	/* 0xa68: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_a6e:
	/* 0xa6e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_a71:
	/* 0xa71: lea    rdx,[rax+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_a78:
	/* 0xa78: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a7b:
	/* 0xa7b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a80:
	/* 0xa80: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a85:
	/* 0xa85: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a8a:
	/* 0xa8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8c:
	/* 0xa8c: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a8f:
	/* 0xa8f: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_a95:
	/* 0xa95: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_a9c:
	/* 0xa9c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aa1:
	/* 0xaa1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_aa6:
	/* 0xaa6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aab:
	/* 0xaab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ab0:
	/* 0xab0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ab3:
	/* 0xab3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab5:
	/* 0xab5: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aba:
	/* 0xaba: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_abd:
	/* 0xabd: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_ac3:
	/* 0xac3: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_aca:
	/* 0xaca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_acd:
	/* 0xacd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ad2:
	/* 0xad2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ad7:
	/* 0xad7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_adc:
	/* 0xadc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ade:
	/* 0xade: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae1:
	/* 0xae1: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_ae7:
	/* 0xae7: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_aee:
	/* 0xaee: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_af3:
	/* 0xaf3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_af8:
	/* 0xaf8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_afd:
	/* 0xafd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b02:
	/* 0xb02: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b05:
	/* 0xb05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b07:
	/* 0xb07: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b0c:
	/* 0xb0c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_b0f:
	/* 0xb0f: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_b15:
	/* 0xb15: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_b1c:
	/* 0xb1c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b1f:
	/* 0xb1f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b24:
	/* 0xb24: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b29:
	/* 0xb29: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b2e:
	/* 0xb2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b30:
	/* 0xb30: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b33:
	/* 0xb33: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_b39:
	/* 0xb39: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_b40:
	/* 0xb40: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b45:
	/* 0xb45: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b4a:
	/* 0xb4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b4f:
	/* 0xb4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b54:
	/* 0xb54: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b57:
	/* 0xb57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b59:
	/* 0xb59: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b5e:
	/* 0xb5e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_b61:
	/* 0xb61: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_b67:
	/* 0xb67: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_b6e:
	/* 0xb6e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b71:
	/* 0xb71: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b76:
	/* 0xb76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b7b:
	/* 0xb7b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b80:
	/* 0xb80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b82:
	/* 0xb82: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b85:
	/* 0xb85: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_b8b:
	/* 0xb8b: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_b92:
	/* 0xb92: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b97:
	/* 0xb97: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b9c:
	/* 0xb9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ba1:
	/* 0xba1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ba6:
	/* 0xba6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ba9:
	/* 0xba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bab:
	/* 0xbab: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb0:
	/* 0xbb0: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_bb3:
	/* 0xbb3: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_bb9:
	/* 0xbb9: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_bc0:
	/* 0xbc0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bc3:
	/* 0xbc3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_bc8:
	/* 0xbc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bcd:
	/* 0xbcd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bd2:
	/* 0xbd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd4:
	/* 0xbd4: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd7:
	/* 0xbd7: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_bdd:
	/* 0xbdd: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_be4:
	/* 0xbe4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be9:
	/* 0xbe9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bee:
	/* 0xbee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bf3:
	/* 0xbf3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf8:
	/* 0xbf8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_bfb:
	/* 0xbfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfd:
	/* 0xbfd: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c02:
	/* 0xc02: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_c05:
	/* 0xc05: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_c0b:
	/* 0xc0b: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_c12:
	/* 0xc12: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c15:
	/* 0xc15: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c1a:
	/* 0xc1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c1f:
	/* 0xc1f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c24:
	/* 0xc24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c26:
	/* 0xc26: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c29:
	/* 0xc29: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_c2f:
	/* 0xc2f: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_c36:
	/* 0xc36: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c3b:
	/* 0xc3b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c40:
	/* 0xc40: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c45:
	/* 0xc45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c4a:
	/* 0xc4a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c4d:
	/* 0xc4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4f:
	/* 0xc4f: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c54:
	/* 0xc54: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_c57:
	/* 0xc57: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_c5d:
	/* 0xc5d: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_c64:
	/* 0xc64: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c67:
	/* 0xc67: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c6c:
	/* 0xc6c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c71:
	/* 0xc71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c76:
	/* 0xc76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c78:
	/* 0xc78: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7b:
	/* 0xc7b: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_c81:
	/* 0xc81: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_c88:
	/* 0xc88: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c8d:
	/* 0xc8d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c92:
	/* 0xc92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c97:
	/* 0xc97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c9c:
	/* 0xc9c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c9f:
	/* 0xc9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca1:
	/* 0xca1: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca6:
	/* 0xca6: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_ca9:
	/* 0xca9: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_caf:
	/* 0xcaf: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_cb6:
	/* 0xcb6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_cb9:
	/* 0xcb9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cbe:
	/* 0xcbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cc3:
	/* 0xcc3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cc8:
	/* 0xcc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cca:
	/* 0xcca: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ccd:
	/* 0xccd: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_cd3:
	/* 0xcd3: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_cda:
	/* 0xcda: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cdf:
	/* 0xcdf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ce4:
	/* 0xce4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce9:
	/* 0xce9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cee:
	/* 0xcee: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_cf1:
	/* 0xcf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf3:
	/* 0xcf3: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cf8:
	/* 0xcf8: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_cfb:
	/* 0xcfb: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_d01:
	/* 0xd01: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_d08:
	/* 0xd08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d0b:
	/* 0xd0b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d10:
	/* 0xd10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d15:
	/* 0xd15: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d1a:
	/* 0xd1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1c:
	/* 0xd1c: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d1f:
	/* 0xd1f: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4297ULL;
	}
x86_l_d25:
	/* 0xd25: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_d2c:
	/* 0xd2c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d31:
	/* 0xd31: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d36:
	/* 0xd36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d3b:
	/* 0xd3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 3392ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3392ULL: goto x86_l_d40;
	case 3395ULL: goto x86_l_d43;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3405ULL: goto x86_l_d4d;
	case 3411ULL: goto x86_l_d53;
	case 3418ULL: goto x86_l_d5a;
	case 3421ULL: goto x86_l_d5d;
	case 3426ULL: goto x86_l_d62;
	case 3431ULL: goto x86_l_d67;
	case 3436ULL: goto x86_l_d6c;
	case 3438ULL: goto x86_l_d6e;
	case 3441ULL: goto x86_l_d71;
	case 3447ULL: goto x86_l_d77;
	case 3454ULL: goto x86_l_d7e;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3469ULL: goto x86_l_d8d;
	case 3474ULL: goto x86_l_d92;
	case 3477ULL: goto x86_l_d95;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3487ULL: goto x86_l_d9f;
	case 3493ULL: goto x86_l_da5;
	case 3500ULL: goto x86_l_dac;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3520ULL: goto x86_l_dc0;
	case 3523ULL: goto x86_l_dc3;
	case 3529ULL: goto x86_l_dc9;
	case 3536ULL: goto x86_l_dd0;
	case 3541ULL: goto x86_l_dd5;
	case 3546ULL: goto x86_l_dda;
	case 3551ULL: goto x86_l_ddf;
	case 3556ULL: goto x86_l_de4;
	case 3559ULL: goto x86_l_de7;
	case 3561ULL: goto x86_l_de9;
	case 3566ULL: goto x86_l_dee;
	case 3569ULL: goto x86_l_df1;
	case 3575ULL: goto x86_l_df7;
	case 3582ULL: goto x86_l_dfe;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3600ULL: goto x86_l_e10;
	case 3602ULL: goto x86_l_e12;
	case 3605ULL: goto x86_l_e15;
	case 3611ULL: goto x86_l_e1b;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3628ULL: goto x86_l_e2c;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3641ULL: goto x86_l_e39;
	case 3643ULL: goto x86_l_e3b;
	case 3648ULL: goto x86_l_e40;
	case 3651ULL: goto x86_l_e43;
	case 3657ULL: goto x86_l_e49;
	case 3664ULL: goto x86_l_e50;
	case 3667ULL: goto x86_l_e53;
	case 3672ULL: goto x86_l_e58;
	case 3677ULL: goto x86_l_e5d;
	case 3682ULL: goto x86_l_e62;
	case 3684ULL: goto x86_l_e64;
	case 3687ULL: goto x86_l_e67;
	case 3693ULL: goto x86_l_e6d;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3720ULL: goto x86_l_e88;
	case 3723ULL: goto x86_l_e8b;
	case 3725ULL: goto x86_l_e8d;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3739ULL: goto x86_l_e9b;
	case 3746ULL: goto x86_l_ea2;
	case 3749ULL: goto x86_l_ea5;
	case 3754ULL: goto x86_l_eaa;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3766ULL: goto x86_l_eb6;
	case 3769ULL: goto x86_l_eb9;
	case 3775ULL: goto x86_l_ebf;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3797ULL: goto x86_l_ed5;
	case 3802ULL: goto x86_l_eda;
	case 3805ULL: goto x86_l_edd;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3815ULL: goto x86_l_ee7;
	case 3821ULL: goto x86_l_eed;
	case 3828ULL: goto x86_l_ef4;
	case 3831ULL: goto x86_l_ef7;
	case 3836ULL: goto x86_l_efc;
	case 3841ULL: goto x86_l_f01;
	case 3846ULL: goto x86_l_f06;
	case 3848ULL: goto x86_l_f08;
	case 3851ULL: goto x86_l_f0b;
	case 3857ULL: goto x86_l_f11;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3887ULL: goto x86_l_f2f;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3897ULL: goto x86_l_f39;
	case 3903ULL: goto x86_l_f3f;
	case 3910ULL: goto x86_l_f46;
	case 3913ULL: goto x86_l_f49;
	case 3918ULL: goto x86_l_f4e;
	case 3923ULL: goto x86_l_f53;
	case 3928ULL: goto x86_l_f58;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3939ULL: goto x86_l_f63;
	case 3946ULL: goto x86_l_f6a;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3969ULL: goto x86_l_f81;
	case 3971ULL: goto x86_l_f83;
	case 3976ULL: goto x86_l_f88;
	case 3979ULL: goto x86_l_f8b;
	case 3985ULL: goto x86_l_f91;
	case 3992ULL: goto x86_l_f98;
	case 3995ULL: goto x86_l_f9b;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4010ULL: goto x86_l_faa;
	case 4012ULL: goto x86_l_fac;
	case 4015ULL: goto x86_l_faf;
	case 4021ULL: goto x86_l_fb5;
	case 4028ULL: goto x86_l_fbc;
	case 4033ULL: goto x86_l_fc1;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4051ULL: goto x86_l_fd3;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4061ULL: goto x86_l_fdd;
	case 4067ULL: goto x86_l_fe3;
	case 4074ULL: goto x86_l_fea;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4094ULL: goto x86_l_ffe;
	case 4097ULL: goto x86_l_1001;
	case 4103ULL: goto x86_l_1007;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4133ULL: goto x86_l_1025;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4143ULL: goto x86_l_102f;
	case 4149ULL: goto x86_l_1035;
	case 4156ULL: goto x86_l_103c;
	case 4159ULL: goto x86_l_103f;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4174ULL: goto x86_l_104e;
	case 4176ULL: goto x86_l_1050;
	case 4179ULL: goto x86_l_1053;
	case 4181ULL: goto x86_l_1055;
	case 4188ULL: goto x86_l_105c;
	case 4193ULL: goto x86_l_1061;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4211ULL: goto x86_l_1073;
	case 4213ULL: goto x86_l_1075;
	case 4218ULL: goto x86_l_107a;
	case 4221ULL: goto x86_l_107d;
	case 4223ULL: goto x86_l_107f;
	case 4230ULL: goto x86_l_1086;
	case 4233ULL: goto x86_l_1089;
	case 4238ULL: goto x86_l_108e;
	case 4243ULL: goto x86_l_1093;
	case 4248ULL: goto x86_l_1098;
	case 4250ULL: goto x86_l_109a;
	case 4253ULL: goto x86_l_109d;
	case 4255ULL: goto x86_l_109f;
	case 4262ULL: goto x86_l_10a6;
	case 4267ULL: goto x86_l_10ab;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4294ULL: goto x86_l_10c6;
	case 4297ULL: goto x86_l_10c9;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4306ULL: goto x86_l_10d2;
	case 4313ULL: goto x86_l_10d9;
	case 4321ULL: goto x86_l_10e1;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4339ULL: goto x86_l_10f3;
	case 4341ULL: goto x86_l_10f5;
	case 4349ULL: goto x86_l_10fd;
	case 4352ULL: goto x86_l_1100;
	case 4358ULL: goto x86_l_1106;
	case 4369ULL: goto x86_l_1111;
	case 4376ULL: goto x86_l_1118;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4391ULL: goto x86_l_1127;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4403ULL: goto x86_l_1133;
	case 4408ULL: goto x86_l_1138;
	case 4412ULL: goto x86_l_113c;
	case 4420ULL: goto x86_l_1144;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4437ULL: goto x86_l_1155;
	case 4439ULL: goto x86_l_1157;
	case 4446ULL: goto x86_l_115e;
	case 4454ULL: goto x86_l_1166;
	case 4459ULL: goto x86_l_116b;
	case 4464ULL: goto x86_l_1170;
	case 4469ULL: goto x86_l_1175;
	case 4471ULL: goto x86_l_1177;
	case 4479ULL: goto x86_l_117f;
	case 4483ULL: goto x86_l_1183;
	case 4491ULL: goto x86_l_118b;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4505ULL: goto x86_l_1199;
	case 4513ULL: goto x86_l_11a1;
	case 4518ULL: goto x86_l_11a6;
	case 4521ULL: goto x86_l_11a9;
	case 4523ULL: goto x86_l_11ab;
	case 4531ULL: goto x86_l_11b3;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4557ULL: goto x86_l_11cd;
	case 4563ULL: goto x86_l_11d3;
	case 4569ULL: goto x86_l_11d9;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4595ULL: goto x86_l_11f3;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4627ULL: goto x86_l_1213;
	case 4629ULL: goto x86_l_1215;
	case 4632ULL: goto x86_l_1218;
	case 4639ULL: goto x86_l_121f;
	case 4649ULL: goto x86_l_1229;
	case 4656ULL: goto x86_l_1230;
	case 4665ULL: goto x86_l_1239;
	case 4671ULL: goto x86_l_123f;
	case 4680ULL: goto x86_l_1248;
	case 4689ULL: goto x86_l_1251;
	case 4694ULL: goto x86_l_1256;
	case 4703ULL: goto x86_l_125f;
	case 4712ULL: goto x86_l_1268;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4731ULL: goto x86_l_127b;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4765ULL: goto x86_l_129d;
	case 4770ULL: goto x86_l_12a2;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4783ULL: goto x86_l_12af;
	case 4785ULL: goto x86_l_12b1;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4803ULL: goto x86_l_12c3;
	case 4806ULL: goto x86_l_12c6;
	case 4811ULL: goto x86_l_12cb;
	case 4813ULL: goto x86_l_12cd;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4826ULL: goto x86_l_12da;
	case 4831ULL: goto x86_l_12df;
	case 4834ULL: goto x86_l_12e2;
	case 4836ULL: goto x86_l_12e4;
	case 4841ULL: goto x86_l_12e9;
	case 4846ULL: goto x86_l_12ee;
	case 4854ULL: goto x86_l_12f6;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4873ULL: goto x86_l_1309;
	case 4878ULL: goto x86_l_130e;
	case 4885ULL: goto x86_l_1315;
	case 4888ULL: goto x86_l_1318;
	case 4894ULL: goto x86_l_131e;
	case 4900ULL: goto x86_l_1324;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4916ULL: goto x86_l_1334;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4928ULL: goto x86_l_1340;
	case 4933ULL: goto x86_l_1345;
	case 4939ULL: goto x86_l_134b;
	case 4944ULL: goto x86_l_1350;
	case 4949ULL: goto x86_l_1355;
	case 4954ULL: goto x86_l_135a;
	case 4956ULL: goto x86_l_135c;
	case 4961ULL: goto x86_l_1361;
	case 4967ULL: goto x86_l_1367;
	case 4971ULL: goto x86_l_136b;
	case 4976ULL: goto x86_l_1370;
	case 4981ULL: goto x86_l_1375;
	case 4986ULL: goto x86_l_137a;
	case 4989ULL: goto x86_l_137d;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5020ULL: goto x86_l_139c;
	case 5022ULL: goto x86_l_139e;
	case 5026ULL: goto x86_l_13a2;
	case 5031ULL: goto x86_l_13a7;
	case 5034ULL: goto x86_l_13aa;
	case 5039ULL: goto x86_l_13af;
	case 5044ULL: goto x86_l_13b4;
	case 5047ULL: goto x86_l_13b7;
	case 5049ULL: goto x86_l_13b9;
	case 5054ULL: goto x86_l_13be;
	case 5059ULL: goto x86_l_13c3;
	case 5063ULL: goto x86_l_13c7;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5073ULL: goto x86_l_13d1;
	case 5076ULL: goto x86_l_13d4;
	case 5081ULL: goto x86_l_13d9;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5091ULL: goto x86_l_13e3;
	case 5094ULL: goto x86_l_13e6;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5104ULL: goto x86_l_13f0;
	case 5106ULL: goto x86_l_13f2;
	case 5109ULL: goto x86_l_13f5;
	case 5111ULL: goto x86_l_13f7;
	case 5115ULL: goto x86_l_13fb;
	case 5118ULL: goto x86_l_13fe;
	case 5124ULL: goto x86_l_1404;
	case 5130ULL: goto x86_l_140a;
	case 5136ULL: goto x86_l_1410;
	case 5139ULL: goto x86_l_1413;
	case 5141ULL: goto x86_l_1415;
	case 5145ULL: goto x86_l_1419;
	case 5147ULL: goto x86_l_141b;
	case 5150ULL: goto x86_l_141e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d40:
	/* 0xd40: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d43:
	/* 0xd43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d45:
	/* 0xd45: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d4a:
	/* 0xd4a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d4d:
	/* 0xd4d: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_d53:
	/* 0xd53: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_d5a:
	/* 0xd5a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d5d:
	/* 0xd5d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d62:
	/* 0xd62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d67:
	/* 0xd67: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d6c:
	/* 0xd6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d6e:
	/* 0xd6e: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d71:
	/* 0xd71: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_d77:
	/* 0xd77: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_d7e:
	/* 0xd7e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d83:
	/* 0xd83: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d88:
	/* 0xd88: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d8d:
	/* 0xd8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d92:
	/* 0xd92: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d95:
	/* 0xd95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d97:
	/* 0xd97: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d9c:
	/* 0xd9c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d9f:
	/* 0xd9f: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_da5:
	/* 0xda5: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_dac:
	/* 0xdac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_daf:
	/* 0xdaf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_db4:
	/* 0xdb4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_db9:
	/* 0xdb9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dbe:
	/* 0xdbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc0:
	/* 0xdc0: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc3:
	/* 0xdc3: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_dc9:
	/* 0xdc9: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_dd0:
	/* 0xdd0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dd5:
	/* 0xdd5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dda:
	/* 0xdda: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ddf:
	/* 0xddf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_de4:
	/* 0xde4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_de7:
	/* 0xde7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de9:
	/* 0xde9: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dee:
	/* 0xdee: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_df1:
	/* 0xdf1: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_df7:
	/* 0xdf7: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_dfe:
	/* 0xdfe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e01:
	/* 0xe01: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e06:
	/* 0xe06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e0b:
	/* 0xe0b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e10:
	/* 0xe10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e12:
	/* 0xe12: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e15:
	/* 0xe15: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_e1b:
	/* 0xe1b: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_e22:
	/* 0xe22: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e27:
	/* 0xe27: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e2c:
	/* 0xe2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e31:
	/* 0xe31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e36:
	/* 0xe36: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e39:
	/* 0xe39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3b:
	/* 0xe3b: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e40:
	/* 0xe40: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_e43:
	/* 0xe43: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_e49:
	/* 0xe49: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_e50:
	/* 0xe50: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e53:
	/* 0xe53: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e58:
	/* 0xe58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e5d:
	/* 0xe5d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e62:
	/* 0xe62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e64:
	/* 0xe64: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e67:
	/* 0xe67: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_e6d:
	/* 0xe6d: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_e74:
	/* 0xe74: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e79:
	/* 0xe79: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e7e:
	/* 0xe7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e83:
	/* 0xe83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e88:
	/* 0xe88: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e8b:
	/* 0xe8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8d:
	/* 0xe8d: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e92:
	/* 0xe92: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_e95:
	/* 0xe95: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_e9b:
	/* 0xe9b: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_ea2:
	/* 0xea2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ea5:
	/* 0xea5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_eaa:
	/* 0xeaa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eaf:
	/* 0xeaf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eb4:
	/* 0xeb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb6:
	/* 0xeb6: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb9:
	/* 0xeb9: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_ebf:
	/* 0xebf: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_ec6:
	/* 0xec6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ecb:
	/* 0xecb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ed0:
	/* 0xed0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ed5:
	/* 0xed5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eda:
	/* 0xeda: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_edd:
	/* 0xedd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_edf:
	/* 0xedf: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ee4:
	/* 0xee4: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_ee7:
	/* 0xee7: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_eed:
	/* 0xeed: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_ef4:
	/* 0xef4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ef7:
	/* 0xef7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_efc:
	/* 0xefc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f01:
	/* 0xf01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f06:
	/* 0xf06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f08:
	/* 0xf08: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f0b:
	/* 0xf0b: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_f11:
	/* 0xf11: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_f18:
	/* 0xf18: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f1d:
	/* 0xf1d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f22:
	/* 0xf22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f27:
	/* 0xf27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f2c:
	/* 0xf2c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f2f:
	/* 0xf2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f31:
	/* 0xf31: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f36:
	/* 0xf36: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_f39:
	/* 0xf39: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_f3f:
	/* 0xf3f: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_f46:
	/* 0xf46: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f49:
	/* 0xf49: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f4e:
	/* 0xf4e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f53:
	/* 0xf53: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f58:
	/* 0xf58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5a:
	/* 0xf5a: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f5d:
	/* 0xf5d: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_f63:
	/* 0xf63: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_f6a:
	/* 0xf6a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f6f:
	/* 0xf6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f74:
	/* 0xf74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f79:
	/* 0xf79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f7e:
	/* 0xf7e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f81:
	/* 0xf81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f83:
	/* 0xf83: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f88:
	/* 0xf88: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_f8b:
	/* 0xf8b: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_f91:
	/* 0xf91: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_f98:
	/* 0xf98: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f9b:
	/* 0xf9b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fa0:
	/* 0xfa0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fa5:
	/* 0xfa5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_faa:
	/* 0xfaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fac:
	/* 0xfac: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_faf:
	/* 0xfaf: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_fb5:
	/* 0xfb5: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_fbc:
	/* 0xfbc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fc1:
	/* 0xfc1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fc6:
	/* 0xfc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fcb:
	/* 0xfcb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fd0:
	/* 0xfd0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_fd3:
	/* 0xfd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd5:
	/* 0xfd5: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fda:
	/* 0xfda: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_fdd:
	/* 0xfdd: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_fe3:
	/* 0xfe3: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_fea:
	/* 0xfea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fed:
	/* 0xfed: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ff2:
	/* 0xff2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff7:
	/* 0xff7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ffc:
	/* 0xffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffe:
	/* 0xffe: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1001:
	/* 0x1001: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_1007:
	/* 0x1007: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_100e:
	/* 0x100e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1013:
	/* 0x1013: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1018:
	/* 0x1018: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_101d:
	/* 0x101d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1022:
	/* 0x1022: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1025:
	/* 0x1025: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1027:
	/* 0x1027: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_102c:
	/* 0x102c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_102f:
	/* 0x102f: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_1035:
	/* 0x1035: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_103c:
	/* 0x103c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_103f:
	/* 0x103f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1044:
	/* 0x1044: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1049:
	/* 0x1049: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_104e:
	/* 0x104e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1050:
	/* 0x1050: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1053:
	/* 0x1053: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_1055:
	/* 0x1055: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_105c:
	/* 0x105c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1061:
	/* 0x1061: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1066:
	/* 0x1066: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_106b:
	/* 0x106b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1070:
	/* 0x1070: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1073:
	/* 0x1073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1075:
	/* 0x1075: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_107a:
	/* 0x107a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_107d:
	/* 0x107d: je     10c6 <event_execve+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_107f:
	/* 0x107f: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1086:
	/* 0x1086: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1089:
	/* 0x1089: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_108e:
	/* 0x108e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1093:
	/* 0x1093: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1098:
	/* 0x1098: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109a:
	/* 0x109a: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_109d:
	/* 0x109d: je     10c9 <event_execve+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_109f:
	/* 0x109f: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_10a6:
	/* 0x10a6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10ab:
	/* 0x10ab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10b0:
	/* 0x10b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10b5:
	/* 0x10b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10ba:
	/* 0x10ba: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10bd:
	/* 0x10bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bf:
	/* 0x10bf: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10c4:
	/* 0x10c4: jmp    10c9 <event_execve+0x10c9> */
	goto x86_l_10c9;
x86_l_10c6:
	/* 0x10c6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c9:
	/* 0x10c9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10cb:
	/* 0x10cb: cmp    DWORD PTR [rsp],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ce:
	/* 0x10ce: cmovne r13,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_64, X86_CC_NE);
x86_l_10d2:
	/* 0x10d2: add    r13,0xd30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3376ULL);
x86_l_10d9:
	/* 0x10d9: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10e1:
	/* 0x10e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10e6:
	/* 0x10e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10eb:
	/* 0x10eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10f0:
	/* 0x10f0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10f3:
	/* 0x10f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f5:
	/* 0x10f5: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10fd:
	/* 0x10fd: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1100:
	/* 0x1100: je     11e2 <event_execve+0x11e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e2;
	}
x86_l_1106:
	/* 0x1106: mov    DWORD PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1111:
	/* 0x1111: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_1118:
	/* 0x1118: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1120:
	/* 0x1120: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1125:
	/* 0x1125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1127:
	/* 0x1127: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112a:
	/* 0x112a: je     150d <event_execve+0x150d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5389ULL;
	}
x86_l_1130:
	/* 0x1130: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1133:
	/* 0x1133: mov    QWORD PTR [rsp+0x78],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1138:
	/* 0x1138: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_113c:
	/* 0x113c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1144:
	/* 0x1144: lea    rax,[rbp+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_114b:
	/* 0x114b: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1150:
	/* 0x1150: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1155:
	/* 0x1155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1157:
	/* 0x1157: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_115e:
	/* 0x115e: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1166:
	/* 0x1166: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_116b:
	/* 0x116b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1170:
	/* 0x1170: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1175:
	/* 0x1175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1177:
	/* 0x1177: mov    r13,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_117f:
	/* 0x117f: add    rbx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1183:
	/* 0x1183: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_118b:
	/* 0x118b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1190:
	/* 0x1190: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1195:
	/* 0x1195: lea    rcx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1199:
	/* 0x1199: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_11a1:
	/* 0x11a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11a6:
	/* 0x11a6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_11a9:
	/* 0x11a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ab:
	/* 0x11ab: mov    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_11b3:
	/* 0x11b3: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b7:
	/* 0x11b7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11bc:
	/* 0x11bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11c1:
	/* 0x11c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11c6:
	/* 0x11c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11cb:
	/* 0x11cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11cd:
	/* 0x11cd: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_11d3:
	/* 0x11d3: mov    r12d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4096ULL);
x86_l_11d9:
	/* 0x11d9: je     11ef <event_execve+0x11ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ef;
	}
x86_l_11db:
	/* 0x11db: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11e0:
	/* 0x11e0: jmp    123f <event_execve+0x123f> */
	goto x86_l_123f;
x86_l_11e2:
	/* 0x11e2: or     BYTE PTR [r14+0x15d],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 1498943586336ULL);
x86_l_11ea:
	/* 0x11ea: jmp    1582 <event_execve+0x1582> */
	return 5506ULL;
x86_l_11ef:
	/* 0x11ef: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11f3:
	/* 0x11f3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11f8:
	/* 0x11f8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11fd:
	/* 0x11fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1202:
	/* 0x1202: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1207:
	/* 0x1207: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1209:
	/* 0x1209: cmp    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_120e:
	/* 0x120e: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1213:
	/* 0x1213: je     123f <event_execve+0x123f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_123f;
	}
x86_l_1215:
	/* 0x1215: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1218:
	/* 0x1218: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_121f:
	/* 0x121f: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_1229:
	/* 0x1229: mov    QWORD PTR [rbp+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1230:
	/* 0x1230: mov    WORD PTR [rbp+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_1239:
	/* 0x1239: mov    r12d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4086ULL);
x86_l_123f:
	/* 0x123f: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1248:
	/* 0x1248: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1251:
	/* 0x1251: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1256:
	/* 0x1256: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_125f:
	/* 0x125f: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1268:
	/* 0x1268: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1271:
	/* 0x1271: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1276:
	/* 0x1276: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_127b:
	/* 0x127b: mov    DWORD PTR [rsp+0x58],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1280:
	/* 0x1280: mov    BYTE PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_1285:
	/* 0x1285: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1289:
	/* 0x1289: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_128e:
	/* 0x128e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1293:
	/* 0x1293: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1298:
	/* 0x1298: lea    rbp,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_129d:
	/* 0x129d: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12a2:
	/* 0x12a2: lea    r12,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12a7:
	/* 0x12a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ac:
	/* 0x12ac: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_12af:
	/* 0x12af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b1:
	/* 0x12b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12b6:
	/* 0x12b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12bb:
	/* 0x12bb: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_12c3:
	/* 0x12c3: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_12c6:
	/* 0x12c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12cb:
	/* 0x12cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cd:
	/* 0x12cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12d2:
	/* 0x12d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12d7:
	/* 0x12d7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_12da:
	/* 0x12da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12df:
	/* 0x12df: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_12e2:
	/* 0x12e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e4:
	/* 0x12e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12e9:
	/* 0x12e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ee:
	/* 0x12ee: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_12f6:
	/* 0x12f6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_12f9:
	/* 0x12f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12fe:
	/* 0x12fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1300:
	/* 0x1300: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1305:
	/* 0x1305: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_1309:
	/* 0x1309: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_130e:
	/* 0x130e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1315:
	/* 0x1315: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1318:
	/* 0x1318: je     14b0 <event_execve+0x14b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5296ULL;
	}
x86_l_131e:
	/* 0x131e: mov    r13d,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2048ULL);
x86_l_1324:
	/* 0x1324: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_132a:
	/* 0x132a: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_132f:
	/* 0x132f: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1334:
	/* 0x1334: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1339:
	/* 0x1339: cmp    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_133e:
	/* 0x133e: jne    134b <event_execve+0x134b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_134b;
	}
x86_l_1340:
	/* 0x1340: cmp    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1345:
	/* 0x1345: je     1511 <event_execve+0x1511> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5393ULL;
	}
x86_l_134b:
	/* 0x134b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1350:
	/* 0x1350: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1355:
	/* 0x1355: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_135a:
	/* 0x135a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135c:
	/* 0x135c: cmp    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_1361:
	/* 0x1361: je     1455 <event_execve+0x1455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5205ULL;
	}
x86_l_1367:
	/* 0x1367: lea    rbx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_136b:
	/* 0x136b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1370:
	/* 0x1370: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1375:
	/* 0x1375: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_137a:
	/* 0x137a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_137d:
	/* 0x137d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137f:
	/* 0x137f: cmp    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1384:
	/* 0x1384: je     1455 <event_execve+0x1455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5205ULL;
	}
x86_l_138a:
	/* 0x138a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_138f:
	/* 0x138f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1394:
	/* 0x1394: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1399:
	/* 0x1399: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_139c:
	/* 0x139c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139e:
	/* 0x139e: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_13a2:
	/* 0x13a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13a7:
	/* 0x13a7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13aa:
	/* 0x13aa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_13af:
	/* 0x13af: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_13b4:
	/* 0x13b4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_13b7:
	/* 0x13b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b9:
	/* 0x13b9: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13be:
	/* 0x13be: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13c3:
	/* 0x13c3: mov    ebp,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13c7:
	/* 0x13c7: sub    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_13ca:
	/* 0x13ca: mov    r15d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13cf:
	/* 0x13cf: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_13d1:
	/* 0x13d1: sub    edx,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_13d4:
	/* 0x13d4: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_13d9:
	/* 0x13d9: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_13dc:
	/* 0x13dc: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_13e1:
	/* 0x13e1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e3:
	/* 0x13e3: cmp    r15d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_13e6:
	/* 0x13e6: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_13ea:
	/* 0x13ea: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_13ec:
	/* 0x13ec: cmovb  ecx,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R15, X86_WIDTH_32, X86_CC_B);
x86_l_13f0:
	/* 0x13f0: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13f2:
	/* 0x13f2: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_13f5:
	/* 0x13f5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_13f7:
	/* 0x13f7: mov    DWORD PTR [rsp+0x58],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13fb:
	/* 0x13fb: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_13fe:
	/* 0x13fe: jb     14d1 <event_execve+0x14d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5329ULL;
	}
x86_l_1404:
	/* 0x1404: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_140a:
	/* 0x140a: ja     14d1 <event_execve+0x14d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5329ULL;
	}
x86_l_1410:
	/* 0x1410: cmp    r15d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1413:
	/* 0x1413: jbe    1419 <event_execve+0x1419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1419;
	}
x86_l_1415:
	/* 0x1415: mov    BYTE PTR [rbx+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1419:
	/* 0x1419: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_141b:
	/* 0x141b: cmp    r15d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_141e:
	/* 0x141e: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
	return 5154ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5154ULL: goto x86_l_1422;
	case 5157ULL: goto x86_l_1425;
	case 5160ULL: goto x86_l_1428;
	case 5163ULL: goto x86_l_142b;
	case 5168ULL: goto x86_l_1430;
	case 5170ULL: goto x86_l_1432;
	case 5175ULL: goto x86_l_1437;
	case 5178ULL: goto x86_l_143a;
	case 5184ULL: goto x86_l_1440;
	case 5189ULL: goto x86_l_1445;
	case 5194ULL: goto x86_l_144a;
	case 5197ULL: goto x86_l_144d;
	case 5203ULL: goto x86_l_1453;
	case 5205ULL: goto x86_l_1455;
	case 5209ULL: goto x86_l_1459;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5226ULL: goto x86_l_146a;
	case 5231ULL: goto x86_l_146f;
	case 5236ULL: goto x86_l_1474;
	case 5242ULL: goto x86_l_147a;
	case 5246ULL: goto x86_l_147e;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5264ULL: goto x86_l_1490;
	case 5266ULL: goto x86_l_1492;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5294ULL: goto x86_l_14ae;
	case 5296ULL: goto x86_l_14b0;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5320ULL: goto x86_l_14c8;
	case 5325ULL: goto x86_l_14cd;
	case 5327ULL: goto x86_l_14cf;
	case 5329ULL: goto x86_l_14d1;
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5342ULL: goto x86_l_14de;
	case 5344ULL: goto x86_l_14e0;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	case 5354ULL: goto x86_l_14ea;
	case 5358ULL: goto x86_l_14ee;
	case 5363ULL: goto x86_l_14f3;
	case 5365ULL: goto x86_l_14f5;
	case 5367ULL: goto x86_l_14f7;
	case 5370ULL: goto x86_l_14fa;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5380ULL: goto x86_l_1504;
	case 5382ULL: goto x86_l_1506;
	case 5384ULL: goto x86_l_1508;
	case 5387ULL: goto x86_l_150b;
	case 5389ULL: goto x86_l_150d;
	case 5391ULL: goto x86_l_150f;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5403ULL: goto x86_l_151b;
	case 5408ULL: goto x86_l_1520;
	case 5411ULL: goto x86_l_1523;
	case 5413ULL: goto x86_l_1525;
	case 5415ULL: goto x86_l_1527;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5430ULL: goto x86_l_1536;
	case 5436ULL: goto x86_l_153c;
	case 5442ULL: goto x86_l_1542;
	case 5445ULL: goto x86_l_1545;
	case 5450ULL: goto x86_l_154a;
	case 5452ULL: goto x86_l_154c;
	case 5454ULL: goto x86_l_154e;
	case 5461ULL: goto x86_l_1555;
	case 5463ULL: goto x86_l_1557;
	case 5469ULL: goto x86_l_155d;
	case 5471ULL: goto x86_l_155f;
	case 5474ULL: goto x86_l_1562;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5483ULL: goto x86_l_156b;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5498ULL: goto x86_l_157a;
	case 5506ULL: goto x86_l_1582;
	case 5510ULL: goto x86_l_1586;
	case 5512ULL: goto x86_l_1588;
	case 5516ULL: goto x86_l_158c;
	case 5524ULL: goto x86_l_1594;
	case 5531ULL: goto x86_l_159b;
	case 5534ULL: goto x86_l_159e;
	case 5537ULL: goto x86_l_15a1;
	case 5543ULL: goto x86_l_15a7;
	case 5549ULL: goto x86_l_15ad;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5562ULL: goto x86_l_15ba;
	case 5569ULL: goto x86_l_15c1;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5593ULL: goto x86_l_15d9;
	case 5596ULL: goto x86_l_15dc;
	case 5602ULL: goto x86_l_15e2;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5619ULL: goto x86_l_15f3;
	case 5624ULL: goto x86_l_15f8;
	case 5629ULL: goto x86_l_15fd;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	case 5643ULL: goto x86_l_160b;
	case 5645ULL: goto x86_l_160d;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5659ULL: goto x86_l_161b;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5691ULL: goto x86_l_163b;
	case 5693ULL: goto x86_l_163d;
	case 5696ULL: goto x86_l_1640;
	case 5698ULL: goto x86_l_1642;
	case 5700ULL: goto x86_l_1644;
	case 5702ULL: goto x86_l_1646;
	case 5710ULL: goto x86_l_164e;
	case 5717ULL: goto x86_l_1655;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5729ULL: goto x86_l_1661;
	case 5734ULL: goto x86_l_1666;
	case 5736ULL: goto x86_l_1668;
	case 5738ULL: goto x86_l_166a;
	case 5743ULL: goto x86_l_166f;
	case 5747ULL: goto x86_l_1673;
	case 5750ULL: goto x86_l_1676;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5776ULL: goto x86_l_1690;
	case 5779ULL: goto x86_l_1693;
	case 5781ULL: goto x86_l_1695;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5795ULL: goto x86_l_16a3;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5827ULL: goto x86_l_16c3;
	case 5829ULL: goto x86_l_16c5;
	case 5832ULL: goto x86_l_16c8;
	case 5838ULL: goto x86_l_16ce;
	case 5840ULL: goto x86_l_16d0;
	case 5845ULL: goto x86_l_16d5;
	case 5848ULL: goto x86_l_16d8;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5862ULL: goto x86_l_16e6;
	case 5868ULL: goto x86_l_16ec;
	case 5870ULL: goto x86_l_16ee;
	case 5874ULL: goto x86_l_16f2;
	case 5881ULL: goto x86_l_16f9;
	case 5884ULL: goto x86_l_16fc;
	case 5887ULL: goto x86_l_16ff;
	case 5894ULL: goto x86_l_1706;
	case 5896ULL: goto x86_l_1708;
	case 5903ULL: goto x86_l_170f;
	case 5906ULL: goto x86_l_1712;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5914ULL: goto x86_l_171a;
	case 5921ULL: goto x86_l_1721;
	case 5923ULL: goto x86_l_1723;
	case 5926ULL: goto x86_l_1726;
	case 5930ULL: goto x86_l_172a;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5943ULL: goto x86_l_1737;
	case 5946ULL: goto x86_l_173a;
	case 5948ULL: goto x86_l_173c;
	case 5953ULL: goto x86_l_1741;
	case 5955ULL: goto x86_l_1743;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5965ULL: goto x86_l_174d;
	case 5967ULL: goto x86_l_174f;
	case 5975ULL: goto x86_l_1757;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5986ULL: goto x86_l_1762;
	case 5988ULL: goto x86_l_1764;
	case 5991ULL: goto x86_l_1767;
	case 5994ULL: goto x86_l_176a;
	case 5996ULL: goto x86_l_176c;
	case 6004ULL: goto x86_l_1774;
	case 6011ULL: goto x86_l_177b;
	case 6018ULL: goto x86_l_1782;
	case 6022ULL: goto x86_l_1786;
	case 6029ULL: goto x86_l_178d;
	case 6035ULL: goto x86_l_1793;
	case 6042ULL: goto x86_l_179a;
	case 6046ULL: goto x86_l_179e;
	case 6054ULL: goto x86_l_17a6;
	case 6058ULL: goto x86_l_17aa;
	case 6066ULL: goto x86_l_17b2;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6083ULL: goto x86_l_17c3;
	case 6088ULL: goto x86_l_17c8;
	case 6095ULL: goto x86_l_17cf;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6108ULL: goto x86_l_17dc;
	case 6113ULL: goto x86_l_17e1;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6127ULL: goto x86_l_17ef;
	case 6132ULL: goto x86_l_17f4;
	case 6136ULL: goto x86_l_17f8;
	case 6139ULL: goto x86_l_17fb;
	case 6144ULL: goto x86_l_1800;
	case 6146ULL: goto x86_l_1802;
	case 6153ULL: goto x86_l_1809;
	case 6158ULL: goto x86_l_180e;
	case 6162ULL: goto x86_l_1812;
	case 6167ULL: goto x86_l_1817;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6181ULL: goto x86_l_1825;
	case 6186ULL: goto x86_l_182a;
	case 6188ULL: goto x86_l_182c;
	case 6195ULL: goto x86_l_1833;
	case 6200ULL: goto x86_l_1838;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6214ULL: goto x86_l_1846;
	case 6219ULL: goto x86_l_184b;
	case 6223ULL: goto x86_l_184f;
	case 6228ULL: goto x86_l_1854;
	case 6230ULL: goto x86_l_1856;
	case 6237ULL: goto x86_l_185d;
	case 6242ULL: goto x86_l_1862;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6261ULL: goto x86_l_1875;
	case 6265ULL: goto x86_l_1879;
	case 6270ULL: goto x86_l_187e;
	case 6272ULL: goto x86_l_1880;
	case 6279ULL: goto x86_l_1887;
	case 6284ULL: goto x86_l_188c;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6303ULL: goto x86_l_189f;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6314ULL: goto x86_l_18aa;
	case 6321ULL: goto x86_l_18b1;
	case 6326ULL: goto x86_l_18b6;
	case 6330ULL: goto x86_l_18ba;
	case 6335ULL: goto x86_l_18bf;
	case 6340ULL: goto x86_l_18c4;
	case 6345ULL: goto x86_l_18c9;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6356ULL: goto x86_l_18d4;
	case 6363ULL: goto x86_l_18db;
	case 6368ULL: goto x86_l_18e0;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6382ULL: goto x86_l_18ee;
	case 6387ULL: goto x86_l_18f3;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6398ULL: goto x86_l_18fe;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6440ULL: goto x86_l_1928;
	case 6447ULL: goto x86_l_192f;
	case 6452ULL: goto x86_l_1934;
	case 6456ULL: goto x86_l_1938;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6471ULL: goto x86_l_1947;
	case 6475ULL: goto x86_l_194b;
	case 6480ULL: goto x86_l_1950;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6494ULL: goto x86_l_195e;
	case 6498ULL: goto x86_l_1962;
	case 6503ULL: goto x86_l_1967;
	case 6508ULL: goto x86_l_196c;
	case 6515ULL: goto x86_l_1973;
	case 6520ULL: goto x86_l_1978;
	case 6522ULL: goto x86_l_197a;
	case 6529ULL: goto x86_l_1981;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6550ULL: goto x86_l_1996;
	case 6554ULL: goto x86_l_199a;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6575ULL: goto x86_l_19af;
	case 6577ULL: goto x86_l_19b1;
	case 6584ULL: goto x86_l_19b8;
	case 6591ULL: goto x86_l_19bf;
	case 6598ULL: goto x86_l_19c6;
	case 6603ULL: goto x86_l_19cb;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6620ULL: goto x86_l_19dc;
	case 6625ULL: goto x86_l_19e1;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6677ULL: goto x86_l_1a15;
	case 6682ULL: goto x86_l_1a1a;
	case 6687ULL: goto x86_l_1a1f;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6697ULL: goto x86_l_1a29;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6739ULL: goto x86_l_1a53;
	case 6746ULL: goto x86_l_1a5a;
	case 6751ULL: goto x86_l_1a5f;
	case 6755ULL: goto x86_l_1a63;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6770ULL: goto x86_l_1a72;
	case 6774ULL: goto x86_l_1a76;
	case 6779ULL: goto x86_l_1a7b;
	case 6781ULL: goto x86_l_1a7d;
	case 6790ULL: goto x86_l_1a86;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6827ULL: goto x86_l_1aab;
	case 6833ULL: goto x86_l_1ab1;
	case 6841ULL: goto x86_l_1ab9;
	case 6845ULL: goto x86_l_1abd;
	case 6850ULL: goto x86_l_1ac2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1422:
	/* 0x1422: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1425:
	/* 0x1425: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1428:
	/* 0x1428: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_142b:
	/* 0x142b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1430:
	/* 0x1430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1432:
	/* 0x1432: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1437:
	/* 0x1437: cmp    r15d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_143a:
	/* 0x143a: jbe    14d1 <event_execve+0x14d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_14d1;
	}
x86_l_1440:
	/* 0x1440: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1445:
	/* 0x1445: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_144a:
	/* 0x144a: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_144d:
	/* 0x144d: jne    132a <event_execve+0x132a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4906ULL;
	}
x86_l_1453:
	/* 0x1453: jmp    14d1 <event_execve+0x14d1> */
	goto x86_l_14d1;
x86_l_1455:
	/* 0x1455: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1459:
	/* 0x1459: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_145e:
	/* 0x145e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1463:
	/* 0x1463: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1468:
	/* 0x1468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146a:
	/* 0x146a: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_146f:
	/* 0x146f: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1474:
	/* 0x1474: je     1511 <event_execve+0x1511> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1511;
	}
x86_l_147a:
	/* 0x147a: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_147e:
	/* 0x147e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1483:
	/* 0x1483: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1488:
	/* 0x1488: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_148d:
	/* 0x148d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1490:
	/* 0x1490: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1492:
	/* 0x1492: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1497:
	/* 0x1497: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_149c:
	/* 0x149c: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_14a0:
	/* 0x14a0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14a5:
	/* 0x14a5: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_14a8:
	/* 0x14a8: jne    132a <event_execve+0x132a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4906ULL;
	}
x86_l_14ae:
	/* 0x14ae: jmp    14d1 <event_execve+0x14d1> */
	goto x86_l_14d1;
x86_l_14b0:
	/* 0x14b0: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_14b7:
	/* 0x14b7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b9:
	/* 0x14b9: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14be:
	/* 0x14be: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_14c3:
	/* 0x14c3: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_14c8:
	/* 0x14c8: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_14cd:
	/* 0x14cd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14cf:
	/* 0x14cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d1:
	/* 0x14d1: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14d6:
	/* 0x14d6: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14db:
	/* 0x14db: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_14de:
	/* 0x14de: je     1525 <event_execve+0x1525> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1525;
	}
x86_l_14e0:
	/* 0x14e0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e2:
	/* 0x14e2: cmp    BYTE PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_14e7:
	/* 0x14e7: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_14ea:
	/* 0x14ea: mov    edx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14ee:
	/* 0x14ee: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_14f3:
	/* 0x14f3: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_14f5:
	/* 0x14f5: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_14f7:
	/* 0x14f7: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_14fa:
	/* 0x14fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14fd:
	/* 0x14fd: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1502:
	/* 0x1502: je     150d <event_execve+0x150d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_150d;
	}
x86_l_1504:
	/* 0x1504: mov    bl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_8);
x86_l_1506:
	/* 0x1506: add    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1508:
	/* 0x1508: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_150b:
	/* 0x150b: jmp    152e <event_execve+0x152e> */
	goto x86_l_152e;
x86_l_150d:
	/* 0x150d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150f:
	/* 0x150f: jmp    1582 <event_execve+0x1582> */
	goto x86_l_1582;
x86_l_1511:
	/* 0x1511: mov    BYTE PTR [rsp+0x5c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991233ULL);
x86_l_1516:
	/* 0x1516: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_151b:
	/* 0x151b: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1520:
	/* 0x1520: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1523:
	/* 0x1523: jne    14e0 <event_execve+0x14e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14e0;
	}
x86_l_1525:
	/* 0x1525: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1527:
	/* 0x1527: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1529:
	/* 0x1529: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_152e:
	/* 0x152e: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1536:
	/* 0x1536: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_153c:
	/* 0x153c: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1542:
	/* 0x1542: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1545:
	/* 0x1545: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_154a:
	/* 0x154a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_154c:
	/* 0x154c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154e:
	/* 0x154e: mov    eax,DWORD PTR [r14+0x15c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_1555:
	/* 0x1555: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1557:
	/* 0x1557: or     ecx,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 4096ULL);
x86_l_155d:
	/* 0x155d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_155f:
	/* 0x155f: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1562:
	/* 0x1562: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1564:
	/* 0x1564: or     eax,0x400000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 4194304ULL);
x86_l_1569:
	/* 0x1569: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_156b:
	/* 0x156b: cmove  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_156e:
	/* 0x156e: and    eax,0xffffdbff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294958079ULL);
x86_l_1573:
	/* 0x1573: mov    DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_157a:
	/* 0x157a: mov    WORD PTR [r14+0x17c],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 380ULL);
x86_l_1582:
	/* 0x1582: mov    ebx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1586:
	/* 0x1586: add    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1588:
	/* 0x1588: mov    DWORD PTR [r12],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158c:
	/* 0x158c: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1594:
	/* 0x1594: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&ENV_VARS_ENABLED)));
x86_l_159b:
	/* 0x159b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_159e:
	/* 0x159e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15a1:
	/* 0x15a1: je     177b <event_execve+0x177b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_177b;
	}
x86_l_15a7:
	/* 0x15a7: cmp    ebx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1023ULL);
x86_l_15ad:
	/* 0x15ad: ja     177b <event_execve+0x177b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_177b;
	}
x86_l_15b3:
	/* 0x15b3: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_15b8:
	/* 0x15b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ba:
	/* 0x15ba: lea    rdx,[rax+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_15c1:
	/* 0x15c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15c4:
	/* 0x15c4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15c9:
	/* 0x15c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15ce:
	/* 0x15ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15d3:
	/* 0x15d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d5:
	/* 0x15d5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d9:
	/* 0x15d9: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15dc:
	/* 0x15dc: je     177b <event_execve+0x177b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_177b;
	}
x86_l_15e2:
	/* 0x15e2: add    rcx,0x198 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 408ULL);
x86_l_15e9:
	/* 0x15e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ee:
	/* 0x15ee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15f3:
	/* 0x15f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f8:
	/* 0x15f8: mov    edx,0x198 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 408ULL);
x86_l_15fd:
	/* 0x15fd: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1601:
	/* 0x1601: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1606:
	/* 0x1606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1608:
	/* 0x1608: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_160b:
	/* 0x160b: je     166a <event_execve+0x166a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166a;
	}
x86_l_160d:
	/* 0x160d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_160f:
	/* 0x160f: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1614:
	/* 0x1614: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_161b:
	/* 0x161b: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_1625:
	/* 0x1625: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_162a:
	/* 0x162a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1631:
	/* 0x1631: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1636:
	/* 0x1636: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_163b:
	/* 0x163b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163d:
	/* 0x163d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1640:
	/* 0x1640: je     1646 <event_execve+0x1646> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1646;
	}
x86_l_1642:
	/* 0x1642: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1644:
	/* 0x1644: jmp    166a <event_execve+0x166a> */
	goto x86_l_166a;
x86_l_1646:
	/* 0x1646: mov    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_164e:
	/* 0x164e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1655:
	/* 0x1655: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1657:
	/* 0x1657: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_165c:
	/* 0x165c: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1661:
	/* 0x1661: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1666:
	/* 0x1666: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1668:
	/* 0x1668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166a:
	/* 0x166a: mov    edx,0x1a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 416ULL);
x86_l_166f:
	/* 0x166f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1673:
	/* 0x1673: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1676:
	/* 0x1676: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_167b:
	/* 0x167b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1680:
	/* 0x1680: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1685:
	/* 0x1685: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1689:
	/* 0x1689: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_168e:
	/* 0x168e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1690:
	/* 0x1690: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1693:
	/* 0x1693: je     16d0 <event_execve+0x16d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16d0;
	}
x86_l_1695:
	/* 0x1695: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1697:
	/* 0x1697: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_169c:
	/* 0x169c: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_16a3:
	/* 0x16a3: movabs rax,0x40000009b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869339ULL);
x86_l_16ad:
	/* 0x16ad: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_16b2:
	/* 0x16b2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16b9:
	/* 0x16b9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x16c8: je     1ef9 <event_execve+0x1ef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7929ULL;
	}
x86_l_16ce:
	/* 0x16ce: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16d0:
	/* 0x16d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16d5:
	/* 0x16d5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_16d8:
	/* 0x16d8: je     177b <event_execve+0x177b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_177b;
	}
x86_l_16de:
	/* 0x16de: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16e3:
	/* 0x16e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16e6:
	/* 0x16e6: je     177b <event_execve+0x177b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_177b;
	}
x86_l_16ec:
	/* 0x16ec: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_16ee:
	/* 0x16ee: lea    rsi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_16f2:
	/* 0x16f2: add    rsi,0x140 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 320ULL);
x86_l_16f9:
	/* 0x16f9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_16fc:
	/* 0x16fc: sub    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_16ff:
	/* 0x16ff: cmp    r13,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1023ULL);
x86_l_1706:
	/* 0x1706: ja     174f <event_execve+0x174f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_174f;
	}
x86_l_1708:
	/* 0x1708: lea    rcx,[r14+0x540] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1344ULL);
x86_l_170f:
	/* 0x170f: sub    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1712:
	/* 0x1712: cmp    r13,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1715:
	/* 0x1715: jae    174f <event_execve+0x174f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_174f;
	}
x86_l_1717:
	/* 0x1717: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_171a:
	/* 0x171a: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1721:
	/* 0x1721: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1723:
	/* 0x1723: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1726:
	/* 0x1726: cmove  r13d,ebx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_32, X86_CC_E);
x86_l_172a:
	/* 0x172a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_172f:
	/* 0x172f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1734:
	/* 0x1734: mov    rdi,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1737:
	/* 0x1737: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_173a:
	/* 0x173a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173c:
	/* 0x173c: and    eax,0x80000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483648ULL);
x86_l_1741:
	/* 0x1741: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1743:
	/* 0x1743: shr    ecx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 28ULL);
x86_l_1746:
	/* 0x1746: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1749:
	/* 0x1749: cmovne r13d,ebx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_32, X86_CC_NE);
x86_l_174d:
	/* 0x174d: jmp    176c <event_execve+0x176c> */
	goto x86_l_176c;
x86_l_174f:
	/* 0x174f: mov    rdi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1757:
	/* 0x1757: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_175a:
	/* 0x175a: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5983ULL);
	__x86_sim_call_depth++;
	return 8267ULL;
x86_l_175f:
	/* 0x175f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1762:
	/* 0x1762: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1764:
	/* 0x1764: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1767:
	/* 0x1767: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_176a:
	/* 0x176a: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_176c:
	/* 0x176c: mov    WORD PTR [r14+0x17e],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 382ULL);
x86_l_1774:
	/* 0x1774: or     DWORD PTR [r14+0x15c],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_177b:
	/* 0x177b: mov    eax,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1782:
	/* 0x1782: lea    ecx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1786:
	/* 0x1786: mov    DWORD PTR [r14+0x140],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_178d:
	/* 0x178d: mov    WORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1793:
	/* 0x1793: mov    rcx,QWORD PTR [r14+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_179a:
	/* 0x179a: mov    QWORD PTR [r14+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_179e:
	/* 0x179e: lea    eax,[rax+r13*1+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 320ULL);
x86_l_17a6:
	/* 0x17a6: mov    DWORD PTR [r14+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17aa:
	/* 0x17aa: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_17b2:
	/* 0x17b2: lea    rdx,[r13+0xce0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_17b9:
	/* 0x17b9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17be:
	/* 0x17be: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17c3:
	/* 0x17c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c8:
	/* 0x17c8: lea    rbx,[r14+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17cf:
	/* 0x17cf: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_17d5:
	/* 0x17d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17da:
	/* 0x17da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17dc:
	/* 0x17dc: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17e1:
	/* 0x17e1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17e5:
	/* 0x17e5: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_17ea:
	/* 0x17ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17ef:
	/* 0x17ef: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17f4:
	/* 0x17f4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17f8:
	/* 0x17f8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17fb:
	/* 0x17fb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1800:
	/* 0x1800: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1802:
	/* 0x1802: lea    rdi,[r14+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1809:
	/* 0x1809: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_180e:
	/* 0x180e: add    rcx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1812:
	/* 0x1812: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1817:
	/* 0x1817: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_181c:
	/* 0x181c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1821:
	/* 0x1821: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1825:
	/* 0x1825: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_182a:
	/* 0x182a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182c:
	/* 0x182c: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1833:
	/* 0x1833: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1838:
	/* 0x1838: add    rcx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_183c:
	/* 0x183c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1841:
	/* 0x1841: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1846:
	/* 0x1846: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_184b:
	/* 0x184b: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_184f:
	/* 0x184f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1854:
	/* 0x1854: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1856:
	/* 0x1856: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_185d:
	/* 0x185d: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1862:
	/* 0x1862: add    rcx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_1866:
	/* 0x1866: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_186b:
	/* 0x186b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1870:
	/* 0x1870: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1875:
	/* 0x1875: add    rdx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_1879:
	/* 0x1879: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_187e:
	/* 0x187e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1880:
	/* 0x1880: lea    rdi,[r14+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1887:
	/* 0x1887: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_188c:
	/* 0x188c: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1890:
	/* 0x1890: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1895:
	/* 0x1895: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_189a:
	/* 0x189a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_189f:
	/* 0x189f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18a3:
	/* 0x18a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18a8:
	/* 0x18a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18aa:
	/* 0x18aa: lea    rdi,[r14+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_18b1:
	/* 0x18b1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18b6:
	/* 0x18b6: add    rcx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_18ba:
	/* 0x18ba: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_18bf:
	/* 0x18bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18c4:
	/* 0x18c4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c9:
	/* 0x18c9: add    rdx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_18cd:
	/* 0x18cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18d2:
	/* 0x18d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d4:
	/* 0x18d4: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_18db:
	/* 0x18db: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18e0:
	/* 0x18e0: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_18e4:
	/* 0x18e4: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_18e9:
	/* 0x18e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ee:
	/* 0x18ee: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18f3:
	/* 0x18f3: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_18f7:
	/* 0x18f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18fc:
	/* 0x18fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18fe:
	/* 0x18fe: lea    rdi,[r14+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1905:
	/* 0x1905: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_190a:
	/* 0x190a: add    rcx,0x24 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 36ULL);
x86_l_190e:
	/* 0x190e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1913:
	/* 0x1913: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1918:
	/* 0x1918: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_191d:
	/* 0x191d: add    rdx,0x24 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 36ULL);
x86_l_1921:
	/* 0x1921: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1926:
	/* 0x1926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1928:
	/* 0x1928: lea    rdi,[r14+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_192f:
	/* 0x192f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1934:
	/* 0x1934: add    rcx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1938:
	/* 0x1938: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_193d:
	/* 0x193d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1942:
	/* 0x1942: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1947:
	/* 0x1947: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_194b:
	/* 0x194b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1950:
	/* 0x1950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1952:
	/* 0x1952: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1957:
	/* 0x1957: lea    rdi,[r14+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_195e:
	/* 0x195e: lea    rdx,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1962:
	/* 0x1962: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1967:
	/* 0x1967: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_196c:
	/* 0x196c: lea    r15,[r14+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1973:
	/* 0x1973: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1978:
	/* 0x1978: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197a:
	/* 0x197a: lea    rdi,[r14+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1981:
	/* 0x1981: lea    rdx,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1985:
	/* 0x1985: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_198a:
	/* 0x198a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_198f:
	/* 0x198f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1994:
	/* 0x1994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1996:
	/* 0x1996: add    rbx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_199a:
	/* 0x199a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_199f:
	/* 0x199f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a4:
	/* 0x19a4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19a7:
	/* 0x19a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19ac:
	/* 0x19ac: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_19af:
	/* 0x19af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b1:
	/* 0x19b1: mov    eax,DWORD PTR [r14+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_19b8:
	/* 0x19b8: mov    DWORD PTR [r14+0x154],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 340ULL);
x86_l_19bf:
	/* 0x19bf: lea    rdx,[r13+0xd48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_19c6:
	/* 0x19c6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19cb:
	/* 0x19cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19d0:
	/* 0x19d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19d5:
	/* 0x19d5: lea    rbx,[r14+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_19dc:
	/* 0x19dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19e1:
	/* 0x19e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e3:
	/* 0x19e3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e8:
	/* 0x19e8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19ed:
	/* 0x19ed: mov    edx,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 72ULL);
x86_l_19f2:
	/* 0x19f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f7:
	/* 0x19f7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fc:
	/* 0x19fc: mov    esi,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 72ULL);
x86_l_1a01:
	/* 0x1a01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a03:
	/* 0x1a03: mov    edx,0x1a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 424ULL);
x86_l_1a08:
	/* 0x1a08: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a0d:
	/* 0x1a0d: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a10:
	/* 0x1a10: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a15:
	/* 0x1a15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a1a:
	/* 0x1a1a: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_1a1f:
	/* 0x1a1f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a22:
	/* 0x1a22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a27:
	/* 0x1a27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a29:
	/* 0x1a29: lea    rdi,[r14+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_1a30:
	/* 0x1a30: mov    edx,0x470 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1136ULL);
x86_l_1a35:
	/* 0x1a35: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a3a:
	/* 0x1a3a: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a3d:
	/* 0x1a3d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a42:
	/* 0x1a42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a47:
	/* 0x1a47: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a51:
	/* 0x1a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a53:
	/* 0x1a53: lea    rdi,[r14+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1a5a:
	/* 0x1a5a: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a5f:
	/* 0x1a5f: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a63:
	/* 0x1a63: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1a68:
	/* 0x1a68: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a72:
	/* 0x1a72: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a76:
	/* 0x1a76: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a7b:
	/* 0x1a7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7d:
	/* 0x1a7d: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1a86:
	/* 0x1a86: lea    rdx,[r13+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_1a8d:
	/* 0x1a8d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a92:
	/* 0x1a92: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a97:
	/* 0x1a97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa1:
	/* 0x1aa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa3:
	/* 0x1aa3: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aa8:
	/* 0x1aa8: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1aab:
	/* 0x1aab: je     1b42 <event_execve+0x1b42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6978ULL;
	}
x86_l_1ab1:
	/* 0x1ab1: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1ab9:
	/* 0x1ab9: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1abd:
	/* 0x1abd: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ac2:
	/* 0x1ac2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 6855ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6885ULL: goto x86_l_1ae5;
	case 6888ULL: goto x86_l_1ae8;
	case 6895ULL: goto x86_l_1aef;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6918ULL: goto x86_l_1b06;
	case 6922ULL: goto x86_l_1b0a;
	case 6925ULL: goto x86_l_1b0d;
	case 6932ULL: goto x86_l_1b14;
	case 6937ULL: goto x86_l_1b19;
	case 6939ULL: goto x86_l_1b1b;
	case 6946ULL: goto x86_l_1b22;
	case 6951ULL: goto x86_l_1b27;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6978ULL: goto x86_l_1b42;
	case 6989ULL: goto x86_l_1b4d;
	case 6997ULL: goto x86_l_1b55;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7032ULL: goto x86_l_1b78;
	case 7037ULL: goto x86_l_1b7d;
	case 7039ULL: goto x86_l_1b7f;
	case 7046ULL: goto x86_l_1b86;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7074ULL: goto x86_l_1ba2;
	case 7079ULL: goto x86_l_1ba7;
	case 7081ULL: goto x86_l_1ba9;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7116ULL: goto x86_l_1bcc;
	case 7121ULL: goto x86_l_1bd1;
	case 7123ULL: goto x86_l_1bd3;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7154ULL: goto x86_l_1bf2;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7165ULL: goto x86_l_1bfd;
	case 7172ULL: goto x86_l_1c04;
	case 7177ULL: goto x86_l_1c09;
	case 7181ULL: goto x86_l_1c0d;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7200ULL: goto x86_l_1c20;
	case 7205ULL: goto x86_l_1c25;
	case 7207ULL: goto x86_l_1c27;
	case 7215ULL: goto x86_l_1c2f;
	case 7222ULL: goto x86_l_1c36;
	case 7225ULL: goto x86_l_1c39;
	case 7230ULL: goto x86_l_1c3e;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7242ULL: goto x86_l_1c4a;
	case 7247ULL: goto x86_l_1c4f;
	case 7251ULL: goto x86_l_1c53;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7273ULL: goto x86_l_1c69;
	case 7278ULL: goto x86_l_1c6e;
	case 7280ULL: goto x86_l_1c70;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7297ULL: goto x86_l_1c81;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7326ULL: goto x86_l_1c9e;
	case 7334ULL: goto x86_l_1ca6;
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7344ULL: goto x86_l_1cb0;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7370ULL: goto x86_l_1cca;
	case 7373ULL: goto x86_l_1ccd;
	case 7375ULL: goto x86_l_1ccf;
	case 7378ULL: goto x86_l_1cd2;
	case 7386ULL: goto x86_l_1cda;
	case 7390ULL: goto x86_l_1cde;
	case 7392ULL: goto x86_l_1ce0;
	case 7394ULL: goto x86_l_1ce2;
	case 7403ULL: goto x86_l_1ceb;
	case 7410ULL: goto x86_l_1cf2;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7431ULL: goto x86_l_1d07;
	case 7433ULL: goto x86_l_1d09;
	case 7437ULL: goto x86_l_1d0d;
	case 7440ULL: goto x86_l_1d10;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7451ULL: goto x86_l_1d1b;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7482ULL: goto x86_l_1d3a;
	case 7487ULL: goto x86_l_1d3f;
	case 7489ULL: goto x86_l_1d41;
	case 7494ULL: goto x86_l_1d46;
	case 7497ULL: goto x86_l_1d49;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7510ULL: goto x86_l_1d56;
	case 7512ULL: goto x86_l_1d58;
	case 7516ULL: goto x86_l_1d5c;
	case 7519ULL: goto x86_l_1d5f;
	case 7525ULL: goto x86_l_1d65;
	case 7530ULL: goto x86_l_1d6a;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7549ULL: goto x86_l_1d7d;
	case 7552ULL: goto x86_l_1d80;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7573ULL: goto x86_l_1d95;
	case 7579ULL: goto x86_l_1d9b;
	case 7581ULL: goto x86_l_1d9d;
	case 7585ULL: goto x86_l_1da1;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7604ULL: goto x86_l_1db4;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7623ULL: goto x86_l_1dc7;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7644ULL: goto x86_l_1ddc;
	case 7649ULL: goto x86_l_1de1;
	case 7654ULL: goto x86_l_1de6;
	case 7656ULL: goto x86_l_1de8;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7670ULL: goto x86_l_1df6;
	case 7672ULL: goto x86_l_1df8;
	case 7681ULL: goto x86_l_1e01;
	case 7688ULL: goto x86_l_1e08;
	case 7693ULL: goto x86_l_1e0d;
	case 7698ULL: goto x86_l_1e12;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7710ULL: goto x86_l_1e1e;
	case 7715ULL: goto x86_l_1e23;
	case 7724ULL: goto x86_l_1e2c;
	case 7727ULL: goto x86_l_1e2f;
	case 7733ULL: goto x86_l_1e35;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7752ULL: goto x86_l_1e48;
	case 7757ULL: goto x86_l_1e4d;
	case 7759ULL: goto x86_l_1e4f;
	case 7764ULL: goto x86_l_1e54;
	case 7768ULL: goto x86_l_1e58;
	case 7771ULL: goto x86_l_1e5b;
	case 7777ULL: goto x86_l_1e61;
	case 7783ULL: goto x86_l_1e67;
	case 7785ULL: goto x86_l_1e69;
	case 7787ULL: goto x86_l_1e6b;
	case 7791ULL: goto x86_l_1e6f;
	case 7798ULL: goto x86_l_1e76;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7816ULL: goto x86_l_1e88;
	case 7819ULL: goto x86_l_1e8b;
	case 7821ULL: goto x86_l_1e8d;
	case 7825ULL: goto x86_l_1e91;
	case 7829ULL: goto x86_l_1e95;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7844ULL: goto x86_l_1ea4;
	case 7848ULL: goto x86_l_1ea8;
	case 7852ULL: goto x86_l_1eac;
	case 7857ULL: goto x86_l_1eb1;
	case 7859ULL: goto x86_l_1eb3;
	case 7864ULL: goto x86_l_1eb8;
	case 7867ULL: goto x86_l_1ebb;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7879ULL: goto x86_l_1ec7;
	case 7882ULL: goto x86_l_1eca;
	case 7886ULL: goto x86_l_1ece;
	case 7891ULL: goto x86_l_1ed3;
	case 7896ULL: goto x86_l_1ed8;
	case 7901ULL: goto x86_l_1edd;
	case 7903ULL: goto x86_l_1edf;
	case 7905ULL: goto x86_l_1ee1;
	case 7907ULL: goto x86_l_1ee3;
	case 7909ULL: goto x86_l_1ee5;
	case 7911ULL: goto x86_l_1ee7;
	case 7915ULL: goto x86_l_1eeb;
	case 7918ULL: goto x86_l_1eee;
	case 7924ULL: goto x86_l_1ef4;
	case 7929ULL: goto x86_l_1ef9;
	case 7937ULL: goto x86_l_1f01;
	case 7944ULL: goto x86_l_1f08;
	case 7946ULL: goto x86_l_1f0a;
	case 7951ULL: goto x86_l_1f0f;
	case 7956ULL: goto x86_l_1f14;
	case 7961ULL: goto x86_l_1f19;
	case 7963ULL: goto x86_l_1f1b;
	case 7965ULL: goto x86_l_1f1d;
	case 7970ULL: goto x86_l_1f22;
	case 7973ULL: goto x86_l_1f25;
	case 7979ULL: goto x86_l_1f2b;
	case 7984ULL: goto x86_l_1f30;
	case 7989ULL: goto x86_l_1f35;
	case 7994ULL: goto x86_l_1f3a;
	case 7997ULL: goto x86_l_1f3d;
	case 8003ULL: goto x86_l_1f43;
	case 8005ULL: goto x86_l_1f45;
	case 8012ULL: goto x86_l_1f4c;
	case 8023ULL: goto x86_l_1f57;
	case 8034ULL: goto x86_l_1f62;
	case 8041ULL: goto x86_l_1f69;
	case 8043ULL: goto x86_l_1f6b;
	case 8048ULL: goto x86_l_1f70;
	case 8051ULL: goto x86_l_1f73;
	case 8053ULL: goto x86_l_1f75;
	case 8055ULL: goto x86_l_1f77;
	case 8057ULL: goto x86_l_1f79;
	case 8064ULL: goto x86_l_1f80;
	case 8065ULL: goto x86_l_1f81;
	case 8067ULL: goto x86_l_1f83;
	case 8069ULL: goto x86_l_1f85;
	case 8071ULL: goto x86_l_1f87;
	case 8073ULL: goto x86_l_1f89;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8081ULL: goto x86_l_1f91;
	case 8083ULL: goto x86_l_1f93;
	case 8085ULL: goto x86_l_1f95;
	case 8087ULL: goto x86_l_1f97;
	case 8088ULL: goto x86_l_1f98;
	case 8092ULL: goto x86_l_1f9c;
	case 8095ULL: goto x86_l_1f9f;
	case 8098ULL: goto x86_l_1fa2;
	case 8101ULL: goto x86_l_1fa5;
	case 8109ULL: goto x86_l_1fad;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8131ULL: goto x86_l_1fc3;
	case 8133ULL: goto x86_l_1fc5;
	case 8136ULL: goto x86_l_1fc8;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8149ULL: goto x86_l_1fd5;
	case 8152ULL: goto x86_l_1fd8;
	case 8156ULL: goto x86_l_1fdc;
	case 8161ULL: goto x86_l_1fe1;
	case 8165ULL: goto x86_l_1fe5;
	case 8167ULL: goto x86_l_1fe7;
	case 8171ULL: goto x86_l_1feb;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8191ULL: goto x86_l_1fff;
	case 8195ULL: goto x86_l_2003;
	case 8199ULL: goto x86_l_2007;
	case 8203ULL: goto x86_l_200b;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8219ULL: goto x86_l_201b;
	case 8222ULL: goto x86_l_201e;
	case 8224ULL: goto x86_l_2020;
	case 8226ULL: goto x86_l_2022;
	case 8228ULL: goto x86_l_2024;
	case 8230ULL: goto x86_l_2026;
	case 8233ULL: goto x86_l_2029;
	case 8241ULL: goto x86_l_2031;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8251ULL: goto x86_l_203b;
	case 8253ULL: goto x86_l_203d;
	case 8257ULL: goto x86_l_2041;
	case 8258ULL: goto x86_l_2042;
	case 8260ULL: goto x86_l_2044;
	case 8262ULL: goto x86_l_2046;
	case 8264ULL: goto x86_l_2048;
	case 8266ULL: goto x86_l_204a;
	case 8267ULL: goto x86_l_204b;
	case 8268ULL: goto x86_l_204c;
	case 8270ULL: goto x86_l_204e;
	case 8272ULL: goto x86_l_2050;
	case 8274ULL: goto x86_l_2052;
	case 8276ULL: goto x86_l_2054;
	case 8277ULL: goto x86_l_2055;
	case 8278ULL: goto x86_l_2056;
	case 8281ULL: goto x86_l_2059;
	case 8284ULL: goto x86_l_205c;
	case 8287ULL: goto x86_l_205f;
	case 8290ULL: goto x86_l_2062;
	case 8298ULL: goto x86_l_206a;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8317ULL: goto x86_l_207d;
	case 8320ULL: goto x86_l_2080;
	case 8322ULL: goto x86_l_2082;
	case 8325ULL: goto x86_l_2085;
	case 8331ULL: goto x86_l_208b;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8341ULL: goto x86_l_2095;
	case 8345ULL: goto x86_l_2099;
	case 8349ULL: goto x86_l_209d;
	case 8353ULL: goto x86_l_20a1;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8364ULL: goto x86_l_20ac;
	case 8369ULL: goto x86_l_20b1;
	case 8371ULL: goto x86_l_20b3;
	case 8375ULL: goto x86_l_20b7;
	case 8379ULL: goto x86_l_20bb;
	case 8383ULL: goto x86_l_20bf;
	case 8387ULL: goto x86_l_20c3;
	case 8391ULL: goto x86_l_20c7;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8400ULL: goto x86_l_20d0;
	case 8403ULL: goto x86_l_20d3;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8419ULL: goto x86_l_20e3;
	case 8422ULL: goto x86_l_20e6;
	case 8424ULL: goto x86_l_20e8;
	case 8426ULL: goto x86_l_20ea;
	case 8430ULL: goto x86_l_20ee;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ac7:
	/* 0x1ac7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1acc:
	/* 0x1acc: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ad5:
	/* 0x1ad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad7:
	/* 0x1ad7: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1adc:
	/* 0x1adc: movsxd rcx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 104ULL);
x86_l_1ae1:
	/* 0x1ae1: shl    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1ae5:
	/* 0x1ae5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ae8:
	/* 0x1ae8: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1aef:
	/* 0x1aef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1af2:
	/* 0x1af2: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1af7:
	/* 0x1af7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1afc:
	/* 0x1afc: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b01:
	/* 0x1b01: movsxd rdx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 104ULL);
x86_l_1b06:
	/* 0x1b06: shl    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1b0a:
	/* 0x1b0a: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b0d:
	/* 0x1b0d: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1b14:
	/* 0x1b14: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b19:
	/* 0x1b19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b1b:
	/* 0x1b1b: lea    rdi,[r14+0x114] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 276ULL);
x86_l_1b22:
	/* 0x1b22: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b27:
	/* 0x1b27: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1b2b:
	/* 0x1b2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b30:
	/* 0x1b30: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b35:
	/* 0x1b35: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1b39:
	/* 0x1b39: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b3e:
	/* 0x1b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b40:
	/* 0x1b40: jmp    1b4d <event_execve+0x1b4d> */
	goto x86_l_1b4d;
x86_l_1b42:
	/* 0x1b42: mov    DWORD PTR [r14+0x114],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b55:
	/* 0x1b55: lea    rdi,[r14+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b61:
	/* 0x1b61: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1b65:
	/* 0x1b65: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b6a:
	/* 0x1b6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b6f:
	/* 0x1b6f: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b74:
	/* 0x1b74: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1b78:
	/* 0x1b78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b7d:
	/* 0x1b7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7f:
	/* 0x1b7f: lea    rdi,[r14+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_1b86:
	/* 0x1b86: mov    edx,0xa8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 168ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b90:
	/* 0x1b90: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b93:
	/* 0x1b93: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b98:
	/* 0x1b98: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b9d:
	/* 0x1b9d: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1ba2:
	/* 0x1ba2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ba7:
	/* 0x1ba7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba9:
	/* 0x1ba9: lea    rdi,[r14+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bb5:
	/* 0x1bb5: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bc8:
	/* 0x1bc8: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1bcc:
	/* 0x1bcc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bd1:
	/* 0x1bd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd3:
	/* 0x1bd3: lea    rdi,[r14+0x124] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292ULL);
x86_l_1bda:
	/* 0x1bda: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bdf:
	/* 0x1bdf: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1be3:
	/* 0x1be3: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1be8:
	/* 0x1be8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bed:
	/* 0x1bed: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bf2:
	/* 0x1bf2: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bfb:
	/* 0x1bfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfd:
	/* 0x1bfd: lea    rdi,[r14+0x128] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1c04:
	/* 0x1c04: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c09:
	/* 0x1c09: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1c12:
	/* 0x1c12: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c17:
	/* 0x1c17: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c1c:
	/* 0x1c1c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c20:
	/* 0x1c20: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c25:
	/* 0x1c25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c27:
	/* 0x1c27: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c2f:
	/* 0x1c2f: lea    rdx,[r13+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_1c36:
	/* 0x1c36: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c39:
	/* 0x1c39: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c3e:
	/* 0x1c3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c43:
	/* 0x1c43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c48:
	/* 0x1c48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4a:
	/* 0x1c4a: mov    edx,0x4a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1184ULL);
x86_l_1c4f:
	/* 0x1c4f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c53:
	/* 0x1c53: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c56:
	/* 0x1c56: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c60:
	/* 0x1c60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c65:
	/* 0x1c65: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c69:
	/* 0x1c69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c6e:
	/* 0x1c6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c70:
	/* 0x1c70: lea    rdi,[r14+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_1c77:
	/* 0x1c77: mov    edx,0xe8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 232ULL);
x86_l_1c7c:
	/* 0x1c7c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c81:
	/* 0x1c81: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c84:
	/* 0x1c84: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c89:
	/* 0x1c89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c8e:
	/* 0x1c8e: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1c93:
	/* 0x1c93: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c98:
	/* 0x1c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9a:
	/* 0x1c9a: lea    r12,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c9e:
	/* 0x1c9e: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1ca6:
	/* 0x1ca6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca8:
	/* 0x1ca8: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1cad:
	/* 0x1cad: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1cb0:
	/* 0x1cb0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb2:
	/* 0x1cb2: call   1cb7 <event_execve+0x1cb7> */
	X86_SIM_L_EXEC_CALL_MEMSET(144ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_1cbe:
	/* 0x1cbe: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cc3:
	/* 0x1cc3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cc8:
	/* 0x1cc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cca:
	/* 0x1cca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ccd:
	/* 0x1ccd: je     1ce0 <event_execve+0x1ce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ce0;
	}
x86_l_1ccf:
	/* 0x1ccf: mov    ebx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd2:
	/* 0x1cd2: cmp    QWORD PTR [rax+0x20],0x63677270 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 139106677360ULL);
x86_l_1cda:
	/* 0x1cda: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_1cde:
	/* 0x1cde: jmp    1ce2 <event_execve+0x1ce2> */
	goto x86_l_1ce2;
x86_l_1ce0:
	/* 0x1ce0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ce2:
	/* 0x1ce2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ceb:
	/* 0x1ceb: add    r13,0xf60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3936ULL);
x86_l_1cf2:
	/* 0x1cf2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cf5:
	/* 0x1cf5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cff:
	/* 0x1cff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d04:
	/* 0x1d04: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d07:
	/* 0x1d07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d09:
	/* 0x1d09: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d0d:
	/* 0x1d0d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1d10:
	/* 0x1d10: je     1f43 <event_execve+0x1f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f43;
	}
x86_l_1d16:
	/* 0x1d16: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1d19:
	/* 0x1d19: je     1d92 <event_execve+0x1d92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d92;
	}
x86_l_1d1b:
	/* 0x1d1b: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1d22:
	/* 0x1d22: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d27:
	/* 0x1d27: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d2c:
	/* 0x1d2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d31:
	/* 0x1d31: mov    edx,0x88 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 136ULL);
x86_l_1d36:
	/* 0x1d36: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d3a:
	/* 0x1d3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d3f:
	/* 0x1d3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d41:
	/* 0x1d41: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d46:
	/* 0x1d46: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1d49:
	/* 0x1d49: je     1f43 <event_execve+0x1f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f43;
	}
x86_l_1d4f:
	/* 0x1d4f: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_1d54:
	/* 0x1d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d56:
	/* 0x1d56: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d58:
	/* 0x1d58: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d5c:
	/* 0x1d5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d5f:
	/* 0x1d5f: je     1e61 <event_execve+0x1e61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e61;
	}
x86_l_1d65:
	/* 0x1d65: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d6a:
	/* 0x1d6a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgtracker_map)));
x86_l_1d71:
	/* 0x1d71: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d76:
	/* 0x1d76: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d7b:
	/* 0x1d7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7d:
	/* 0x1d7d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d80:
	/* 0x1d80: je     1e69 <event_execve+0x1e69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e69;
	}
x86_l_1d86:
	/* 0x1d86: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d89:
	/* 0x1d89: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d8d:
	/* 0x1d8d: jmp    1e6f <event_execve+0x1e6f> */
	goto x86_l_1e6f;
x86_l_1d92:
	/* 0x1d92: cmp    ebx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 11ULL);
x86_l_1d95:
	/* 0x1d95: ja     1f43 <event_execve+0x1f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f43;
	}
x86_l_1d9b:
	/* 0x1d9b: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_1d9d:
	/* 0x1d9d: lea    rcx,[rcx+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_1da1:
	/* 0x1da1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1da6:
	/* 0x1da6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dab:
	/* 0x1dab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1db0:
	/* 0x1db0: shl    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 3ULL);
x86_l_1db4:
	/* 0x1db4: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1db8:
	/* 0x1db8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dbd:
	/* 0x1dbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbf:
	/* 0x1dbf: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dc4:
	/* 0x1dc4: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1dc7:
	/* 0x1dc7: je     1f30 <event_execve+0x1f30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f30;
	}
x86_l_1dcd:
	/* 0x1dcd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1dd7:
	/* 0x1dd7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ddc:
	/* 0x1ddc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1de1:
	/* 0x1de1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1de6:
	/* 0x1de6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de8:
	/* 0x1de8: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ded:
	/* 0x1ded: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1df0:
	/* 0x1df0: je     1f43 <event_execve+0x1f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f43;
	}
x86_l_1df6:
	/* 0x1df6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1df8:
	/* 0x1df8: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e01:
	/* 0x1e01: lea    rdx,[rbx+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1e08:
	/* 0x1e08: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e12:
	/* 0x1e12: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e17:
	/* 0x1e17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e1c:
	/* 0x1e1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1e:
	/* 0x1e1e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e23:
	/* 0x1e23: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e2c:
	/* 0x1e2c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1e2f:
	/* 0x1e2f: je     1ee5 <event_execve+0x1ee5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee5;
	}
x86_l_1e35:
	/* 0x1e35: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1e39:
	/* 0x1e39: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e43:
	/* 0x1e43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e48:
	/* 0x1e48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e4d:
	/* 0x1e4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4f:
	/* 0x1e4f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e54:
	/* 0x1e54: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e58:
	/* 0x1e58: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e5b:
	/* 0x1e5b: jne    1d65 <event_execve+0x1d65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d65;
	}
x86_l_1e61:
	/* 0x1e61: or     ebp,0x200000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 2097152ULL);
x86_l_1e67:
	/* 0x1e67: jmp    1e6f <event_execve+0x1e6f> */
	goto x86_l_1e6f;
x86_l_1e69:
	/* 0x1e69: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e6b:
	/* 0x1e6b: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e6f:
	/* 0x1e6f: add    rbx,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_1e76:
	/* 0x1e76: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e79:
	/* 0x1e79: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e83:
	/* 0x1e83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e88:
	/* 0x1e88: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1e8b:
	/* 0x1e8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8d:
	/* 0x1e8d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e91:
	/* 0x1e91: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e95:
	/* 0x1e95: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e9f:
	/* 0x1e9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ea4:
	/* 0x1ea4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ea8:
	/* 0x1ea8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1eac:
	/* 0x1eac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb1:
	/* 0x1eb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb3:
	/* 0x1eb3: mov    ecx,0x10000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_1eb8:
	/* 0x1eb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ebb:
	/* 0x1ebb: jne    1ee1 <event_execve+0x1ee1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ee1;
	}
x86_l_1ebd:
	/* 0x1ebd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ec2:
	/* 0x1ec2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1ec5:
	/* 0x1ec5: je     1ee1 <event_execve+0x1ee1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee1;
	}
x86_l_1ec7:
	/* 0x1ec7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1eca:
	/* 0x1eca: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1ece:
	/* 0x1ece: mov    ecx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 128ULL);
x86_l_1ed3:
	/* 0x1ed3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ed8:
	/* 0x1ed8: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1edd:
	/* 0x1edd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1edf:
	/* 0x1edf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee1:
	/* 0x1ee1: or     ecx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ee3:
	/* 0x1ee3: jmp    1f45 <event_execve+0x1f45> */
	goto x86_l_1f45;
x86_l_1ee5:
	/* 0x1ee5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee7:
	/* 0x1ee7: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eeb:
	/* 0x1eeb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1eee:
	/* 0x1eee: jne    1d65 <event_execve+0x1d65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d65;
	}
x86_l_1ef4:
	/* 0x1ef4: jmp    1e61 <event_execve+0x1e61> */
	goto x86_l_1e61;
x86_l_1ef9:
	/* 0x1ef9: mov    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_1f01:
	/* 0x1f01: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1f08:
	/* 0x1f08: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f0a:
	/* 0x1f0a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f0f:
	/* 0x1f0f: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f14:
	/* 0x1f14: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f19:
	/* 0x1f19: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f1b:
	/* 0x1f1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1d:
	/* 0x1f1d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f22:
	/* 0x1f22: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1f25:
	/* 0x1f25: jne    16de <event_execve+0x16de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5854ULL;
	}
x86_l_1f2b:
	/* 0x1f2b: jmp    177b <event_execve+0x177b> */
	return 6011ULL;
x86_l_1f30:
	/* 0x1f30: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f35:
	/* 0x1f35: mov    ebp,0x80000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 524288ULL);
x86_l_1f3a:
	/* 0x1f3a: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1f3d:
	/* 0x1f3d: jne    1df8 <event_execve+0x1df8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1df8;
	}
x86_l_1f43:
	/* 0x1f43: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f45:
	/* 0x1f45: or     DWORD PTR [r14+0x15c],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_1f4c:
	/* 0x1f4c: mov    QWORD PTR [r14+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_1f57:
	/* 0x1f57: mov    QWORD PTR [r14+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_1f62:
	/* 0x1f62: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_1f69:
	/* 0x1f69: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f6b:
	/* 0x1f6b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f70:
	/* 0x1f70: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f73:
	/* 0x1f73: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f75:
	/* 0x1f75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f77:
	/* 0x1f77: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f79:
	/* 0x1f79: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1f80:
	/* 0x1f80: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f81:
	/* 0x1f81: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1f83:
	/* 0x1f83: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1f85:
	/* 0x1f85: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f87:
	/* 0x1f87: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1f89:
	/* 0x1f89: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1f8a:
	/* 0x1f8a: jmp    280f <__do_str+0x1bf> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f8f:
	/* 0x1f8f: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1f91:
	/* 0x1f91: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1f93:
	/* 0x1f93: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1f95:
	/* 0x1f95: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1f97:
	/* 0x1f97: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1f98:
	/* 0x1f98: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_1f9f:
	/* 0x1f9f: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1fa2:
	/* 0x1fa2: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1fa5:
	/* 0x1fa5: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1fad:
	/* 0x1fad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_1fb4:
	/* 0x1fb4: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fb9:
	/* 0x1fb9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fbe:
	/* 0x1fbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc0:
	/* 0x1fc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fc3:
	/* 0x1fc3: je     203b <data_event_str+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_203b;
	}
x86_l_1fc5:
	/* 0x1fc5: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1fc8:
	/* 0x1fc8: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fce:
	/* 0x1fce: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1fd3:
	/* 0x1fd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd5:
	/* 0x1fd5: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1fd8:
	/* 0x1fd8: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fe1:
	/* 0x1fe1: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1fe5:
	/* 0x1fe5: jne    1fef <data_event_str+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fef;
	}
x86_l_1fe7:
	/* 0x1fe7: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1feb:
	/* 0x1feb: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fef:
	/* 0x1fef: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1ff4:
	/* 0x1ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff6:
	/* 0x1ff6: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fff:
	/* 0x1fff: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2003:
	/* 0x2003: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2007:
	/* 0x2007: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_200b:
	/* 0x200b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_200e:
	/* 0x200e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2011:
	/* 0x2011: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2014:
	/* 0x2014: call   25f1 <do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8217ULL);
	__x86_sim_call_depth++;
	return 9713ULL;
x86_l_2019:
	/* 0x2019: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_201b:
	/* 0x201b: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_201e:
	/* 0x201e: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_2020:
	/* 0x2020: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2022:
	/* 0x2022: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2024:
	/* 0x2024: mov    DWORD PTR [rbx],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2026:
	/* 0x2026: cmovg  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_G);
x86_l_2029:
	/* 0x2029: mov    QWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2031:
	/* 0x2031: mov    DWORD PTR [rbx+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2034:
	/* 0x2034: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_2039:
	/* 0x2039: jmp    203d <data_event_str+0xae> */
	goto x86_l_203d;
x86_l_203b:
	/* 0x203b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_203d:
	/* 0x203d: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2041:
	/* 0x2041: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2042:
	/* 0x2042: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2044:
	/* 0x2044: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2046:
	/* 0x2046: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2048:
	/* 0x2048: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_204a:
	/* 0x204a: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_204b:
	/* 0x204b: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_204c:
	/* 0x204c: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_204e:
	/* 0x204e: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2050:
	/* 0x2050: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_2052:
	/* 0x2052: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2054:
	/* 0x2054: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2055:
	/* 0x2055: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_2056:
	/* 0x2056: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_2059:
	/* 0x2059: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_205c:
	/* 0x205c: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_205f:
	/* 0x205f: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_2062:
	/* 0x2062: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_206a:
	/* 0x206a: mov    rdi,QWORD PTR [rip+0x2e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_2071:
	/* 0x2071: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2076:
	/* 0x2076: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_207b:
	/* 0x207b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_207d:
	/* 0x207d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2080:
	/* 0x2080: je     20f3 <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8435ULL;
	}
x86_l_2082:
	/* 0x2082: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2085:
	/* 0x2085: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_208b:
	/* 0x208b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2090:
	/* 0x2090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2092:
	/* 0x2092: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_2095:
	/* 0x2095: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2099:
	/* 0x2099: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_209d:
	/* 0x209d: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_20a1:
	/* 0x20a1: jne    20ac <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20ac;
	}
x86_l_20a3:
	/* 0x20a3: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20a8:
	/* 0x20a8: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ac:
	/* 0x20ac: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_20b1:
	/* 0x20b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b3:
	/* 0x20b3: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b7:
	/* 0x20b7: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20bb:
	/* 0x20bb: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20bf:
	/* 0x20bf: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c3:
	/* 0x20c3: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20c7:
	/* 0x20c7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_20ca:
	/* 0x20ca: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_20cd:
	/* 0x20cd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20d0:
	/* 0x20d0: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_20d3:
	/* 0x20d3: call   22cd <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8408ULL);
	__x86_sim_call_depth++;
	return 8909ULL;
x86_l_20d8:
	/* 0x20d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20da:
	/* 0x20da: js     20f7 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8439ULL;
	}
x86_l_20dc:
	/* 0x20dc: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e3:
	/* 0x20e3: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_20e6:
	/* 0x20e6: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_20e8:
	/* 0x20e8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20ea:
	/* 0x20ea: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_20ee:
	/* 0x20ee: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
	return 8433ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8433ULL: goto x86_l_20f1;
	case 8435ULL: goto x86_l_20f3;
	case 8437ULL: goto x86_l_20f5;
	case 8439ULL: goto x86_l_20f7;
	case 8441ULL: goto x86_l_20f9;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8452ULL: goto x86_l_2104;
	case 8455ULL: goto x86_l_2107;
	case 8458ULL: goto x86_l_210a;
	case 8463ULL: goto x86_l_210f;
	case 8467ULL: goto x86_l_2113;
	case 8468ULL: goto x86_l_2114;
	case 8470ULL: goto x86_l_2116;
	case 8472ULL: goto x86_l_2118;
	case 8474ULL: goto x86_l_211a;
	case 8476ULL: goto x86_l_211c;
	case 8477ULL: goto x86_l_211d;
	case 8478ULL: goto x86_l_211e;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8483ULL: goto x86_l_2123;
	case 8485ULL: goto x86_l_2125;
	case 8487ULL: goto x86_l_2127;
	case 8488ULL: goto x86_l_2128;
	case 8492ULL: goto x86_l_212c;
	case 8495ULL: goto x86_l_212f;
	case 8499ULL: goto x86_l_2133;
	case 8503ULL: goto x86_l_2137;
	case 8507ULL: goto x86_l_213b;
	case 8510ULL: goto x86_l_213e;
	case 8512ULL: goto x86_l_2140;
	case 8516ULL: goto x86_l_2144;
	case 8522ULL: goto x86_l_214a;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8536ULL: goto x86_l_2158;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8548ULL: goto x86_l_2164;
	case 8553ULL: goto x86_l_2169;
	case 8559ULL: goto x86_l_216f;
	case 8564ULL: goto x86_l_2174;
	case 8569ULL: goto x86_l_2179;
	case 8574ULL: goto x86_l_217e;
	case 8579ULL: goto x86_l_2183;
	case 8584ULL: goto x86_l_2188;
	case 8587ULL: goto x86_l_218b;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8610ULL: goto x86_l_21a2;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8623ULL: goto x86_l_21af;
	case 8625ULL: goto x86_l_21b1;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8649ULL: goto x86_l_21c9;
	case 8652ULL: goto x86_l_21cc;
	case 8654ULL: goto x86_l_21ce;
	case 8658ULL: goto x86_l_21d2;
	case 8662ULL: goto x86_l_21d6;
	case 8666ULL: goto x86_l_21da;
	case 8669ULL: goto x86_l_21dd;
	case 8673ULL: goto x86_l_21e1;
	case 8675ULL: goto x86_l_21e3;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8693ULL: goto x86_l_21f5;
	case 8697ULL: goto x86_l_21f9;
	case 8699ULL: goto x86_l_21fb;
	case 8703ULL: goto x86_l_21ff;
	case 8705ULL: goto x86_l_2201;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8713ULL: goto x86_l_2209;
	case 8718ULL: goto x86_l_220e;
	case 8721ULL: goto x86_l_2211;
	case 8727ULL: goto x86_l_2217;
	case 8734ULL: goto x86_l_221e;
	case 8740ULL: goto x86_l_2224;
	case 8743ULL: goto x86_l_2227;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8752ULL: goto x86_l_2230;
	case 8755ULL: goto x86_l_2233;
	case 8759ULL: goto x86_l_2237;
	case 8763ULL: goto x86_l_223b;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8776ULL: goto x86_l_2248;
	case 8780ULL: goto x86_l_224c;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8798ULL: goto x86_l_225e;
	case 8800ULL: goto x86_l_2260;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8824ULL: goto x86_l_2278;
	case 8826ULL: goto x86_l_227a;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8837ULL: goto x86_l_2285;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8862ULL: goto x86_l_229e;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8873ULL: goto x86_l_22a9;
	case 8877ULL: goto x86_l_22ad;
	case 8881ULL: goto x86_l_22b1;
	case 8883ULL: goto x86_l_22b3;
	case 8885ULL: goto x86_l_22b5;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8898ULL: goto x86_l_22c2;
	case 8899ULL: goto x86_l_22c3;
	case 8901ULL: goto x86_l_22c5;
	case 8903ULL: goto x86_l_22c7;
	case 8905ULL: goto x86_l_22c9;
	case 8907ULL: goto x86_l_22cb;
	case 8908ULL: goto x86_l_22cc;
	case 8909ULL: goto x86_l_22cd;
	case 8910ULL: goto x86_l_22ce;
	case 8912ULL: goto x86_l_22d0;
	case 8914ULL: goto x86_l_22d2;
	case 8916ULL: goto x86_l_22d4;
	case 8918ULL: goto x86_l_22d6;
	case 8919ULL: goto x86_l_22d7;
	case 8920ULL: goto x86_l_22d8;
	case 8923ULL: goto x86_l_22db;
	case 8926ULL: goto x86_l_22de;
	case 8929ULL: goto x86_l_22e1;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8939ULL: goto x86_l_22eb;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8955ULL: goto x86_l_22fb;
	case 8958ULL: goto x86_l_22fe;
	case 8961ULL: goto x86_l_2301;
	case 8967ULL: goto x86_l_2307;
	case 8971ULL: goto x86_l_230b;
	case 8974ULL: goto x86_l_230e;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8984ULL: goto x86_l_2318;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 8998ULL: goto x86_l_2326;
	case 9001ULL: goto x86_l_2329;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9013ULL: goto x86_l_2335;
	case 9017ULL: goto x86_l_2339;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9030ULL: goto x86_l_2346;
	case 9036ULL: goto x86_l_234c;
	case 9041ULL: goto x86_l_2351;
	case 9044ULL: goto x86_l_2354;
	case 9047ULL: goto x86_l_2357;
	case 9050ULL: goto x86_l_235a;
	case 9053ULL: goto x86_l_235d;
	case 9059ULL: goto x86_l_2363;
	case 9063ULL: goto x86_l_2367;
	case 9066ULL: goto x86_l_236a;
	case 9069ULL: goto x86_l_236d;
	case 9074ULL: goto x86_l_2372;
	case 9076ULL: goto x86_l_2374;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9090ULL: goto x86_l_2382;
	case 9093ULL: goto x86_l_2385;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9105ULL: goto x86_l_2391;
	case 9109ULL: goto x86_l_2395;
	case 9112ULL: goto x86_l_2398;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9122ULL: goto x86_l_23a2;
	case 9128ULL: goto x86_l_23a8;
	case 9133ULL: goto x86_l_23ad;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9142ULL: goto x86_l_23b6;
	case 9145ULL: goto x86_l_23b9;
	case 9151ULL: goto x86_l_23bf;
	case 9155ULL: goto x86_l_23c3;
	case 9158ULL: goto x86_l_23c6;
	case 9161ULL: goto x86_l_23c9;
	case 9166ULL: goto x86_l_23ce;
	case 9168ULL: goto x86_l_23d0;
	case 9174ULL: goto x86_l_23d6;
	case 9179ULL: goto x86_l_23db;
	case 9182ULL: goto x86_l_23de;
	case 9185ULL: goto x86_l_23e1;
	case 9188ULL: goto x86_l_23e4;
	case 9191ULL: goto x86_l_23e7;
	case 9197ULL: goto x86_l_23ed;
	case 9201ULL: goto x86_l_23f1;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	case 9212ULL: goto x86_l_23fc;
	case 9214ULL: goto x86_l_23fe;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9228ULL: goto x86_l_240c;
	case 9231ULL: goto x86_l_240f;
	case 9234ULL: goto x86_l_2412;
	case 9237ULL: goto x86_l_2415;
	case 9243ULL: goto x86_l_241b;
	case 9247ULL: goto x86_l_241f;
	case 9250ULL: goto x86_l_2422;
	case 9253ULL: goto x86_l_2425;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9270ULL: goto x86_l_2436;
	case 9273ULL: goto x86_l_2439;
	case 9276ULL: goto x86_l_243c;
	case 9279ULL: goto x86_l_243f;
	case 9285ULL: goto x86_l_2445;
	case 9289ULL: goto x86_l_2449;
	case 9292ULL: goto x86_l_244c;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9302ULL: goto x86_l_2456;
	case 9304ULL: goto x86_l_2458;
	case 9309ULL: goto x86_l_245d;
	case 9312ULL: goto x86_l_2460;
	case 9315ULL: goto x86_l_2463;
	case 9318ULL: goto x86_l_2466;
	case 9321ULL: goto x86_l_2469;
	case 9327ULL: goto x86_l_246f;
	case 9330ULL: goto x86_l_2472;
	case 9333ULL: goto x86_l_2475;
	case 9336ULL: goto x86_l_2478;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9346ULL: goto x86_l_2482;
	case 9348ULL: goto x86_l_2484;
	case 9353ULL: goto x86_l_2489;
	case 9356ULL: goto x86_l_248c;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9367ULL: goto x86_l_2497;
	case 9375ULL: goto x86_l_249f;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9392ULL: goto x86_l_24b0;
	case 9394ULL: goto x86_l_24b2;
	case 9397ULL: goto x86_l_24b5;
	case 9399ULL: goto x86_l_24b7;
	case 9403ULL: goto x86_l_24bb;
	case 9405ULL: goto x86_l_24bd;
	case 9409ULL: goto x86_l_24c1;
	case 9411ULL: goto x86_l_24c3;
	case 9415ULL: goto x86_l_24c7;
	case 9417ULL: goto x86_l_24c9;
	case 9421ULL: goto x86_l_24cd;
	case 9423ULL: goto x86_l_24cf;
	case 9429ULL: goto x86_l_24d5;
	case 9431ULL: goto x86_l_24d7;
	case 9435ULL: goto x86_l_24db;
	case 9437ULL: goto x86_l_24dd;
	case 9441ULL: goto x86_l_24e1;
	case 9443ULL: goto x86_l_24e3;
	case 9447ULL: goto x86_l_24e7;
	case 9449ULL: goto x86_l_24e9;
	case 9455ULL: goto x86_l_24ef;
	case 9457ULL: goto x86_l_24f1;
	case 9463ULL: goto x86_l_24f7;
	case 9465ULL: goto x86_l_24f9;
	case 9471ULL: goto x86_l_24ff;
	case 9473ULL: goto x86_l_2501;
	case 9479ULL: goto x86_l_2507;
	case 9481ULL: goto x86_l_2509;
	case 9487ULL: goto x86_l_250f;
	case 9489ULL: goto x86_l_2511;
	case 9495ULL: goto x86_l_2517;
	case 9499ULL: goto x86_l_251b;
	case 9502ULL: goto x86_l_251e;
	case 9506ULL: goto x86_l_2522;
	case 9507ULL: goto x86_l_2523;
	case 9509ULL: goto x86_l_2525;
	case 9511ULL: goto x86_l_2527;
	case 9513ULL: goto x86_l_2529;
	case 9515ULL: goto x86_l_252b;
	case 9516ULL: goto x86_l_252c;
	case 9517ULL: goto x86_l_252d;
	case 9519ULL: goto x86_l_252f;
	case 9521ULL: goto x86_l_2531;
	case 9523ULL: goto x86_l_2533;
	case 9524ULL: goto x86_l_2534;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9534ULL: goto x86_l_253e;
	case 9537ULL: goto x86_l_2541;
	case 9540ULL: goto x86_l_2544;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9556ULL: goto x86_l_2554;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9567ULL: goto x86_l_255f;
	case 9569ULL: goto x86_l_2561;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9577ULL: goto x86_l_2569;
	case 9581ULL: goto x86_l_256d;
	case 9589ULL: goto x86_l_2575;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9606ULL: goto x86_l_2586;
	case 9608ULL: goto x86_l_2588;
	case 9611ULL: goto x86_l_258b;
	case 9613ULL: goto x86_l_258d;
	case 9617ULL: goto x86_l_2591;
	case 9619ULL: goto x86_l_2593;
	case 9626ULL: goto x86_l_259a;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9647ULL: goto x86_l_25af;
	case 9650ULL: goto x86_l_25b2;
	case 9652ULL: goto x86_l_25b4;
	case 9654ULL: goto x86_l_25b6;
	case 9656ULL: goto x86_l_25b8;
	case 9658ULL: goto x86_l_25ba;
	case 9665ULL: goto x86_l_25c1;
	case 9667ULL: goto x86_l_25c3;
	case 9674ULL: goto x86_l_25ca;
	case 9676ULL: goto x86_l_25cc;
	case 9681ULL: goto x86_l_25d1;
	case 9684ULL: goto x86_l_25d4;
	case 9687ULL: goto x86_l_25d7;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9693ULL: goto x86_l_25dd;
	case 9695ULL: goto x86_l_25df;
	case 9698ULL: goto x86_l_25e2;
	case 9701ULL: goto x86_l_25e5;
	case 9705ULL: goto x86_l_25e9;
	case 9706ULL: goto x86_l_25ea;
	case 9708ULL: goto x86_l_25ec;
	case 9710ULL: goto x86_l_25ee;
	case 9712ULL: goto x86_l_25f0;
	case 9713ULL: goto x86_l_25f1;
	case 9715ULL: goto x86_l_25f3;
	case 9717ULL: goto x86_l_25f5;
	case 9718ULL: goto x86_l_25f6;
	case 9722ULL: goto x86_l_25fa;
	case 9725ULL: goto x86_l_25fd;
	case 9728ULL: goto x86_l_2600;
	case 9731ULL: goto x86_l_2603;
	case 9736ULL: goto x86_l_2608;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9758ULL: goto x86_l_261e;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	default: return 0xffffffffffffffffULL;
	}
x86_l_20f1:
	/* 0x20f1: jmp    2104 <data_event_bytes+0xb9> */
	goto x86_l_2104;
x86_l_20f3:
	/* 0x20f3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20f5:
	/* 0x20f5: jmp    210f <data_event_bytes+0xc4> */
	goto x86_l_210f;
x86_l_20f7:
	/* 0x20f7: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f9:
	/* 0x20f9: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2100:
	/* 0x2100: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2102:
	/* 0x2102: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2104:
	/* 0x2104: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2107:
	/* 0x2107: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_210a:
	/* 0x210a: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_210f:
	/* 0x210f: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2113:
	/* 0x2113: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2114:
	/* 0x2114: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2116:
	/* 0x2116: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2118:
	/* 0x2118: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_211a:
	/* 0x211a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_211c:
	/* 0x211c: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_211d:
	/* 0x211d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_211e:
	/* 0x211e: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_211f:
	/* 0x211f: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2121:
	/* 0x2121: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2123:
	/* 0x2123: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_2125:
	/* 0x2125: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2127:
	/* 0x2127: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2128:
	/* 0x2128: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_212c:
	/* 0x212c: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_212f:
	/* 0x212f: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2133:
	/* 0x2133: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2137:
	/* 0x2137: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_213b:
	/* 0x213b: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_213e:
	/* 0x213e: jne    214a <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_214a;
	}
x86_l_2140:
	/* 0x2140: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2144:
	/* 0x2144: je     22b5 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22b5;
	}
x86_l_214a:
	/* 0x214a: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_214e:
	/* 0x214e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2153:
	/* 0x2153: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2158:
	/* 0x2158: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_215d:
	/* 0x215d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2162:
	/* 0x2162: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2164:
	/* 0x2164: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2169:
	/* 0x2169: je     2260 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2260;
	}
x86_l_216f:
	/* 0x216f: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2174:
	/* 0x2174: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2179:
	/* 0x2179: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_217e:
	/* 0x217e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2183:
	/* 0x2183: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2188:
	/* 0x2188: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_218b:
	/* 0x218b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218d:
	/* 0x218d: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2192:
	/* 0x2192: je     2260 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2260;
	}
x86_l_2198:
	/* 0x2198: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_219d:
	/* 0x219d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21a2:
	/* 0x21a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21a7:
	/* 0x21a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21ac:
	/* 0x21ac: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_21af:
	/* 0x21af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b1:
	/* 0x21b1: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_21b5:
	/* 0x21b5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ba:
	/* 0x21ba: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_21bf:
	/* 0x21bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21c4:
	/* 0x21c4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21c9:
	/* 0x21c9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21cc:
	/* 0x21cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ce:
	/* 0x21ce: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d2:
	/* 0x21d2: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21d6:
	/* 0x21d6: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21da:
	/* 0x21da: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_21dd:
	/* 0x21dd: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21e1:
	/* 0x21e1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21e3:
	/* 0x21e3: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_21e5:
	/* 0x21e5: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21e8:
	/* 0x21e8: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_21eb:
	/* 0x21eb: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_21f0:
	/* 0x21f0: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21f2:
	/* 0x21f2: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_21f5:
	/* 0x21f5: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_21f9:
	/* 0x21f9: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_21fb:
	/* 0x21fb: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_21ff:
	/* 0x21ff: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2201:
	/* 0x2201: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2204:
	/* 0x2204: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2206:
	/* 0x2206: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2209:
	/* 0x2209: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_220e:
	/* 0x220e: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2211:
	/* 0x2211: jb     22be <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_22be;
	}
x86_l_2217:
	/* 0x2217: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_221e:
	/* 0x221e: ja     22be <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_22be;
	}
x86_l_2224:
	/* 0x2224: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2227:
	/* 0x2227: jbe    222e <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_222e;
	}
x86_l_2229:
	/* 0x2229: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_222e:
	/* 0x222e: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2230:
	/* 0x2230: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2233:
	/* 0x2233: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2237:
	/* 0x2237: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_223b:
	/* 0x223b: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_223e:
	/* 0x223e: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2241:
	/* 0x2241: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2246:
	/* 0x2246: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2248:
	/* 0x2248: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_224c:
	/* 0x224c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_224f:
	/* 0x224f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2254:
	/* 0x2254: jbe    22be <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_22be;
	}
x86_l_2256:
	/* 0x2256: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_225b:
	/* 0x225b: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225e:
	/* 0x225e: jmp    22b1 <cwd_read_v61+0x193> */
	goto x86_l_22b1;
x86_l_2260:
	/* 0x2260: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2264:
	/* 0x2264: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2269:
	/* 0x2269: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_226e:
	/* 0x226e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2273:
	/* 0x2273: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2278:
	/* 0x2278: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227a:
	/* 0x227a: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_227e:
	/* 0x227e: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2283:
	/* 0x2283: je     22b5 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22b5;
	}
x86_l_2285:
	/* 0x2285: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2289:
	/* 0x2289: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_228e:
	/* 0x228e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2293:
	/* 0x2293: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2296:
	/* 0x2296: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_229b:
	/* 0x229b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_229e:
	/* 0x229e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a0:
	/* 0x22a0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a5:
	/* 0x22a5: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22a9:
	/* 0x22a9: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_22ad:
	/* 0x22ad: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22b1:
	/* 0x22b1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22b3:
	/* 0x22b3: jmp    22be <cwd_read_v61+0x1a0> */
	goto x86_l_22be;
x86_l_22b5:
	/* 0x22b5: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_22b9:
	/* 0x22b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22be:
	/* 0x22be: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_22c2:
	/* 0x22c2: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_22c3:
	/* 0x22c3: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_22c5:
	/* 0x22c5: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_22c7:
	/* 0x22c7: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_22c9:
	/* 0x22c9: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_22cb:
	/* 0x22cb: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_22cc:
	/* 0x22cc: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_22cd:
	/* 0x22cd: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_22ce:
	/* 0x22ce: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_22d0:
	/* 0x22d0: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_22d2:
	/* 0x22d2: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_22d4:
	/* 0x22d4: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_22d6:
	/* 0x22d6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_22d7:
	/* 0x22d7: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_22d8:
	/* 0x22d8: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_22db:
	/* 0x22db: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_22de:
	/* 0x22de: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_22e1:
	/* 0x22e1: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_22e4:
	/* 0x22e4: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8937ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_22e9:
	/* 0x22e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22eb:
	/* 0x22eb: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_22f1:
	/* 0x22f1: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_22f4:
	/* 0x22f4: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_22fb:
	/* 0x22fb: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_22fe:
	/* 0x22fe: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2301:
	/* 0x2301: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_2307:
	/* 0x2307: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_230b:
	/* 0x230b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_230e:
	/* 0x230e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2311:
	/* 0x2311: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8982ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_2316:
	/* 0x2316: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2318:
	/* 0x2318: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_231e:
	/* 0x231e: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2323:
	/* 0x2323: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2326:
	/* 0x2326: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2329:
	/* 0x2329: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_232c:
	/* 0x232c: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_232f:
	/* 0x232f: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_2335:
	/* 0x2335: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2339:
	/* 0x2339: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_233c:
	/* 0x233c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_233f:
	/* 0x233f: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9028ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_2344:
	/* 0x2344: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2346:
	/* 0x2346: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_234c:
	/* 0x234c: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2351:
	/* 0x2351: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2354:
	/* 0x2354: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2357:
	/* 0x2357: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_235a:
	/* 0x235a: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_235d:
	/* 0x235d: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_2363:
	/* 0x2363: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2367:
	/* 0x2367: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_236a:
	/* 0x236a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_236d:
	/* 0x236d: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9074ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_2372:
	/* 0x2372: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2374:
	/* 0x2374: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_237a:
	/* 0x237a: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_237f:
	/* 0x237f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2382:
	/* 0x2382: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2385:
	/* 0x2385: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2388:
	/* 0x2388: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_238b:
	/* 0x238b: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_2391:
	/* 0x2391: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2395:
	/* 0x2395: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2398:
	/* 0x2398: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_239b:
	/* 0x239b: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9120ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_23a0:
	/* 0x23a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23a2:
	/* 0x23a2: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_23a8:
	/* 0x23a8: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_23ad:
	/* 0x23ad: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_23b0:
	/* 0x23b0: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23b3:
	/* 0x23b3: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_23b6:
	/* 0x23b6: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_23b9:
	/* 0x23b9: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_23bf:
	/* 0x23bf: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_23c3:
	/* 0x23c3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_23c6:
	/* 0x23c6: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_23c9:
	/* 0x23c9: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9166ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_23ce:
	/* 0x23ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23d0:
	/* 0x23d0: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_23d6:
	/* 0x23d6: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_23db:
	/* 0x23db: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_23de:
	/* 0x23de: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23e1:
	/* 0x23e1: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_23e4:
	/* 0x23e4: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_23e7:
	/* 0x23e7: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_23ed:
	/* 0x23ed: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_23f1:
	/* 0x23f1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_23f4:
	/* 0x23f4: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_23f7:
	/* 0x23f7: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9212ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_23fc:
	/* 0x23fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23fe:
	/* 0x23fe: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_2404:
	/* 0x2404: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2409:
	/* 0x2409: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_240c:
	/* 0x240c: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_240f:
	/* 0x240f: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2412:
	/* 0x2412: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2415:
	/* 0x2415: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_241b:
	/* 0x241b: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_241f:
	/* 0x241f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2422:
	/* 0x2422: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2425:
	/* 0x2425: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9258ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_242a:
	/* 0x242a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_242c:
	/* 0x242c: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_242e:
	/* 0x242e: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2433:
	/* 0x2433: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2436:
	/* 0x2436: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2439:
	/* 0x2439: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_243c:
	/* 0x243c: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_243f:
	/* 0x243f: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_2445:
	/* 0x2445: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2449:
	/* 0x2449: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_244c:
	/* 0x244c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_244f:
	/* 0x244f: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9300ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_2454:
	/* 0x2454: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2456:
	/* 0x2456: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_2458:
	/* 0x2458: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_245d:
	/* 0x245d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2460:
	/* 0x2460: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2463:
	/* 0x2463: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2466:
	/* 0x2466: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2469:
	/* 0x2469: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_246f:
	/* 0x246f: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2472:
	/* 0x2472: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2475:
	/* 0x2475: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2478:
	/* 0x2478: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_247b:
	/* 0x247b: call   252d <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9344ULL);
	__x86_sim_call_depth++;
	goto x86_l_252d;
x86_l_2480:
	/* 0x2480: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2482:
	/* 0x2482: js     2494 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2494;
	}
x86_l_2484:
	/* 0x2484: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2489:
	/* 0x2489: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_248c:
	/* 0x248c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_248f:
	/* 0x248f: jmp    251b <do_bytes+0x24e> */
	goto x86_l_251b;
x86_l_2494:
	/* 0x2494: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2497:
	/* 0x2497: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_249f:
	/* 0x249f: mov    rdi,QWORD PTR [rip+0x3c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_24a6:
	/* 0x24a6: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24ab:
	/* 0x24ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24b0:
	/* 0x24b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b2:
	/* 0x24b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24b5:
	/* 0x24b5: je     251b <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251b;
	}
x86_l_24b7:
	/* 0x24b7: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_24bb:
	/* 0x24bb: jg     24d7 <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24d7;
	}
x86_l_24bd:
	/* 0x24bd: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_24c1:
	/* 0x24c1: je     24f1 <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f1;
	}
x86_l_24c3:
	/* 0x24c3: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_24c7:
	/* 0x24c7: je     2509 <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2509;
	}
x86_l_24c9:
	/* 0x24c9: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_24cd:
	/* 0x24cd: jne    2501 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2501;
	}
x86_l_24cf:
	/* 0x24cf: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_24d5:
	/* 0x24d5: jmp    2517 <do_bytes+0x24a> */
	goto x86_l_2517;
x86_l_24d7:
	/* 0x24d7: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_24db:
	/* 0x24db: je     24f9 <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f9;
	}
x86_l_24dd:
	/* 0x24dd: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_24e1:
	/* 0x24e1: je     2511 <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2511;
	}
x86_l_24e3:
	/* 0x24e3: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_24e7:
	/* 0x24e7: jne    2501 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2501;
	}
x86_l_24e9:
	/* 0x24e9: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_24ef:
	/* 0x24ef: jmp    2517 <do_bytes+0x24a> */
	goto x86_l_2517;
x86_l_24f1:
	/* 0x24f1: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_24f7:
	/* 0x24f7: jmp    2517 <do_bytes+0x24a> */
	goto x86_l_2517;
x86_l_24f9:
	/* 0x24f9: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_24ff:
	/* 0x24ff: jmp    2517 <do_bytes+0x24a> */
	goto x86_l_2517;
x86_l_2501:
	/* 0x2501: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_2507:
	/* 0x2507: jmp    2517 <do_bytes+0x24a> */
	goto x86_l_2517;
x86_l_2509:
	/* 0x2509: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_250f:
	/* 0x250f: jmp    2517 <do_bytes+0x24a> */
	goto x86_l_2517;
x86_l_2511:
	/* 0x2511: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_2517:
	/* 0x2517: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_251b:
	/* 0x251b: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_251e:
	/* 0x251e: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2522:
	/* 0x2522: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2523:
	/* 0x2523: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2525:
	/* 0x2525: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2527:
	/* 0x2527: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2529:
	/* 0x2529: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_252b:
	/* 0x252b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_252c:
	/* 0x252c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_252d:
	/* 0x252d: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_252f:
	/* 0x252f: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2531:
	/* 0x2531: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2533:
	/* 0x2533: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2534:
	/* 0x2534: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_2535:
	/* 0x2535: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2538:
	/* 0x2538: js     25ba <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25ba;
	}
x86_l_253e:
	/* 0x253e: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_2541:
	/* 0x2541: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_2544:
	/* 0x2544: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_254b:
	/* 0x254b: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_2550:
	/* 0x2550: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_2554:
	/* 0x2554: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2558:
	/* 0x2558: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_255d:
	/* 0x255d: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_255f:
	/* 0x255f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2561:
	/* 0x2561: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2563:
	/* 0x2563: js     25df <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25df;
	}
x86_l_2565:
	/* 0x2565: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2569:
	/* 0x2569: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_256d:
	/* 0x256d: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2575:
	/* 0x2575: mov    rdi,QWORD PTR [rip+0x61c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_257c:
	/* 0x257c: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2581:
	/* 0x2581: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2586:
	/* 0x2586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2588:
	/* 0x2588: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_258b:
	/* 0x258b: je     25c3 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25c3;
	}
x86_l_258d:
	/* 0x258d: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2591:
	/* 0x2591: je     25c3 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25c3;
	}
x86_l_2593:
	/* 0x2593: mov    rsi,QWORD PTR [rip+0x61c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_259a:
	/* 0x259a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_259f:
	/* 0x259f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_25a4:
	/* 0x25a4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_25a7:
	/* 0x25a7: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_25ac:
	/* 0x25ac: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_25af:
	/* 0x25af: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_25b2:
	/* 0x25b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b4:
	/* 0x25b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25b6:
	/* 0x25b6: js     25df <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25df;
	}
x86_l_25b8:
	/* 0x25b8: jmp    25e2 <__do_bytes+0xb5> */
	goto x86_l_25e2;
x86_l_25ba:
	/* 0x25ba: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_25c1:
	/* 0x25c1: jmp    25e2 <__do_bytes+0xb5> */
	goto x86_l_25e2;
x86_l_25c3:
	/* 0x25c3: mov    rdi,QWORD PTR [rip+0x61c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_25ca:
	/* 0x25ca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25cc:
	/* 0x25cc: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_25d1:
	/* 0x25d1: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_25d4:
	/* 0x25d4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25d7:
	/* 0x25d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d9:
	/* 0x25d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25db:
	/* 0x25db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25dd:
	/* 0x25dd: jns    25e2 <__do_bytes+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_25e2;
	}
x86_l_25df:
	/* 0x25df: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_25e2:
	/* 0x25e2: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_25e5:
	/* 0x25e5: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_25e9:
	/* 0x25e9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_25ea:
	/* 0x25ea: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_25ec:
	/* 0x25ec: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_25ee:
	/* 0x25ee: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_25f0:
	/* 0x25f0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_25f1:
	/* 0x25f1: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_25f3:
	/* 0x25f3: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_25f5:
	/* 0x25f5: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_25f6:
	/* 0x25f6: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_25fa:
	/* 0x25fa: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_25fd:
	/* 0x25fd: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_2600:
	/* 0x2600: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_2603:
	/* 0x2603: mov    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_2608:
	/* 0x2608: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_260d:
	/* 0x260d: call   2650 <__do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9746ULL);
	__x86_sim_call_depth++;
	return 9808ULL;
x86_l_2612:
	/* 0x2612: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2615:
	/* 0x2615: js     2646 <do_str+0x55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9798ULL;
	}
x86_l_2617:
	/* 0x2617: cmp    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_261c:
	/* 0x261c: jne    2646 <do_str+0x55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9798ULL;
	}
x86_l_261e:
	/* 0x261e: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2621:
	/* 0x2621: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_2626:
	/* 0x2626: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
	return 9769ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9769ULL: goto x86_l_2629;
	case 9772ULL: goto x86_l_262c;
	case 9775ULL: goto x86_l_262f;
	case 9778ULL: goto x86_l_2632;
	case 9783ULL: goto x86_l_2637;
	case 9785ULL: goto x86_l_2639;
	case 9788ULL: goto x86_l_263c;
	case 9792ULL: goto x86_l_2640;
	case 9795ULL: goto x86_l_2643;
	case 9798ULL: goto x86_l_2646;
	case 9802ULL: goto x86_l_264a;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9807ULL: goto x86_l_264f;
	case 9808ULL: goto x86_l_2650;
	case 9810ULL: goto x86_l_2652;
	case 9812ULL: goto x86_l_2654;
	case 9814ULL: goto x86_l_2656;
	case 9815ULL: goto x86_l_2657;
	case 9819ULL: goto x86_l_265b;
	case 9822ULL: goto x86_l_265e;
	case 9825ULL: goto x86_l_2661;
	case 9828ULL: goto x86_l_2664;
	case 9832ULL: goto x86_l_2668;
	case 9837ULL: goto x86_l_266d;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9849ULL: goto x86_l_2679;
	case 9852ULL: goto x86_l_267c;
	case 9858ULL: goto x86_l_2682;
	case 9864ULL: goto x86_l_2688;
	case 9868ULL: goto x86_l_268c;
	case 9871ULL: goto x86_l_268f;
	case 9877ULL: goto x86_l_2695;
	case 9880ULL: goto x86_l_2698;
	case 9884ULL: goto x86_l_269c;
	case 9891ULL: goto x86_l_26a3;
	case 9895ULL: goto x86_l_26a7;
	case 9903ULL: goto x86_l_26af;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9922ULL: goto x86_l_26c2;
	case 9925ULL: goto x86_l_26c5;
	case 9931ULL: goto x86_l_26cb;
	case 9935ULL: goto x86_l_26cf;
	case 9937ULL: goto x86_l_26d1;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9962ULL: goto x86_l_26ea;
	case 9965ULL: goto x86_l_26ed;
	case 9968ULL: goto x86_l_26f0;
	case 9970ULL: goto x86_l_26f2;
	case 9973ULL: goto x86_l_26f5;
	case 9979ULL: goto x86_l_26fb;
	case 9982ULL: goto x86_l_26fe;
	case 9990ULL: goto x86_l_2706;
	case 9997ULL: goto x86_l_270d;
	case 10002ULL: goto x86_l_2712;
	case 10007ULL: goto x86_l_2717;
	case 10009ULL: goto x86_l_2719;
	case 10012ULL: goto x86_l_271c;
	case 10018ULL: goto x86_l_2722;
	case 10022ULL: goto x86_l_2726;
	case 10028ULL: goto x86_l_272c;
	case 10032ULL: goto x86_l_2730;
	case 10038ULL: goto x86_l_2736;
	case 10042ULL: goto x86_l_273a;
	case 10044ULL: goto x86_l_273c;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10062ULL: goto x86_l_274e;
	case 10064ULL: goto x86_l_2750;
	case 10069ULL: goto x86_l_2755;
	case 10072ULL: goto x86_l_2758;
	case 10075ULL: goto x86_l_275b;
	case 10077ULL: goto x86_l_275d;
	case 10079ULL: goto x86_l_275f;
	case 10082ULL: goto x86_l_2762;
	case 10088ULL: goto x86_l_2768;
	case 10091ULL: goto x86_l_276b;
	case 10099ULL: goto x86_l_2773;
	case 10106ULL: goto x86_l_277a;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10118ULL: goto x86_l_2786;
	case 10121ULL: goto x86_l_2789;
	case 10123ULL: goto x86_l_278b;
	case 10127ULL: goto x86_l_278f;
	case 10129ULL: goto x86_l_2791;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10139ULL: goto x86_l_279b;
	case 10141ULL: goto x86_l_279d;
	case 10145ULL: goto x86_l_27a1;
	case 10147ULL: goto x86_l_27a3;
	case 10153ULL: goto x86_l_27a9;
	case 10155ULL: goto x86_l_27ab;
	case 10157ULL: goto x86_l_27ad;
	case 10159ULL: goto x86_l_27af;
	case 10163ULL: goto x86_l_27b3;
	case 10165ULL: goto x86_l_27b5;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10175ULL: goto x86_l_27bf;
	case 10177ULL: goto x86_l_27c1;
	case 10183ULL: goto x86_l_27c7;
	case 10185ULL: goto x86_l_27c9;
	case 10189ULL: goto x86_l_27cd;
	case 10191ULL: goto x86_l_27cf;
	case 10195ULL: goto x86_l_27d3;
	case 10197ULL: goto x86_l_27d5;
	case 10201ULL: goto x86_l_27d9;
	case 10203ULL: goto x86_l_27db;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10217ULL: goto x86_l_27e9;
	case 10219ULL: goto x86_l_27eb;
	case 10225ULL: goto x86_l_27f1;
	case 10227ULL: goto x86_l_27f3;
	case 10233ULL: goto x86_l_27f9;
	case 10237ULL: goto x86_l_27fd;
	case 10240ULL: goto x86_l_2800;
	case 10243ULL: goto x86_l_2803;
	case 10247ULL: goto x86_l_2807;
	case 10248ULL: goto x86_l_2808;
	case 10250ULL: goto x86_l_280a;
	case 10252ULL: goto x86_l_280c;
	case 10254ULL: goto x86_l_280e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2629:
	/* 0x2629: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_262c:
	/* 0x262c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_262f:
	/* 0x262f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2632:
	/* 0x2632: call   2650 <__do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 9783ULL);
	__x86_sim_call_depth++;
	goto x86_l_2650;
x86_l_2637:
	/* 0x2637: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2639:
	/* 0x2639: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_263c:
	/* 0x263c: cmovns rcx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_64, X86_CC_NS);
x86_l_2640:
	/* 0x2640: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2643:
	/* 0x2643: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2646:
	/* 0x2646: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_264a:
	/* 0x264a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_264b:
	/* 0x264b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_264d:
	/* 0x264d: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_264f:
	/* 0x264f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2650:
	/* 0x2650: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2652:
	/* 0x2652: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2654:
	/* 0x2654: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2656:
	/* 0x2656: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2657:
	/* 0x2657: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_265b:
	/* 0x265b: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_265e:
	/* 0x265e: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2661:
	/* 0x2661: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2664:
	/* 0x2664: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2668:
	/* 0x2668: mov    ecx,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32735ULL);
x86_l_266d:
	/* 0x266d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2672:
	/* 0x2672: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_2677:
	/* 0x2677: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2679:
	/* 0x2679: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_267c:
	/* 0x267c: js     2803 <__do_str+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2803;
	}
x86_l_2682:
	/* 0x2682: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_2688:
	/* 0x2688: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_268c:
	/* 0x268c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_268f:
	/* 0x268f: je     27ab <__do_str+0x15b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ab;
	}
x86_l_2695:
	/* 0x2695: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2698:
	/* 0x2698: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_269c:
	/* 0x269c: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_26a3:
	/* 0x26a3: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26a7:
	/* 0x26a7: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_26af:
	/* 0x26af: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_26b6:
	/* 0x26b6: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_26bb:
	/* 0x26bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26c0:
	/* 0x26c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c2:
	/* 0x26c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26c5:
	/* 0x26c5: je     2747 <__do_str+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2747;
	}
x86_l_26cb:
	/* 0x26cb: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_26cf:
	/* 0x26cf: je     2747 <__do_str+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2747;
	}
x86_l_26d1:
	/* 0x26d1: mov    rsi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_26d8:
	/* 0x26d8: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_26dd:
	/* 0x26dd: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_26e2:
	/* 0x26e2: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_26e7:
	/* 0x26e7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_26ea:
	/* 0x26ea: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_26ed:
	/* 0x26ed: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_26f0:
	/* 0x26f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f2:
	/* 0x26f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26f5:
	/* 0x26f5: jns    27fd <__do_str+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_27fd;
	}
x86_l_26fb:
	/* 0x26fb: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_26fe:
	/* 0x26fe: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2706:
	/* 0x2706: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_270d:
	/* 0x270d: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2712:
	/* 0x2712: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2717:
	/* 0x2717: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2719:
	/* 0x2719: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_271c:
	/* 0x271c: je     27fd <__do_str+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27fd;
	}
x86_l_2722:
	/* 0x2722: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2726:
	/* 0x2726: jg     27c9 <__do_str+0x179> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_27c9;
	}
x86_l_272c:
	/* 0x272c: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2730:
	/* 0x2730: je     27e3 <__do_str+0x193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e3;
	}
x86_l_2736:
	/* 0x2736: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_273a:
	/* 0x273a: jne    279d <__do_str+0x14d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_279d;
	}
x86_l_273c:
	/* 0x273c: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_2742:
	/* 0x2742: jmp    27f9 <__do_str+0x1a9> */
	goto x86_l_27f9;
x86_l_2747:
	/* 0x2747: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_274e:
	/* 0x274e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2750:
	/* 0x2750: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_2755:
	/* 0x2755: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2758:
	/* 0x2758: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_275b:
	/* 0x275b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_275d:
	/* 0x275d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275f:
	/* 0x275f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2762:
	/* 0x2762: jns    27fd <__do_str+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_27fd;
	}
x86_l_2768:
	/* 0x2768: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_276b:
	/* 0x276b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2773:
	/* 0x2773: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_277a:
	/* 0x277a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_277f:
	/* 0x277f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2784:
	/* 0x2784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2786:
	/* 0x2786: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2789:
	/* 0x2789: je     27fd <__do_str+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27fd;
	}
x86_l_278b:
	/* 0x278b: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_278f:
	/* 0x278f: jg     27af <__do_str+0x15f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_27af;
	}
x86_l_2791:
	/* 0x2791: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2795:
	/* 0x2795: je     27e3 <__do_str+0x193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e3;
	}
x86_l_2797:
	/* 0x2797: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_279b:
	/* 0x279b: je     273c <__do_str+0xec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_273c;
	}
x86_l_279d:
	/* 0x279d: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_27a1:
	/* 0x27a1: jne    27db <__do_str+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27db;
	}
x86_l_27a3:
	/* 0x27a3: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_27a9:
	/* 0x27a9: jmp    27f9 <__do_str+0x1a9> */
	goto x86_l_27f9;
x86_l_27ab:
	/* 0x27ab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27ad:
	/* 0x27ad: jmp    2803 <__do_str+0x1b3> */
	goto x86_l_2803;
x86_l_27af:
	/* 0x27af: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_27b3:
	/* 0x27b3: je     27eb <__do_str+0x19b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27eb;
	}
x86_l_27b5:
	/* 0x27b5: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_27b9:
	/* 0x27b9: je     27f3 <__do_str+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27f3;
	}
x86_l_27bb:
	/* 0x27bb: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_27bf:
	/* 0x27bf: jne    27db <__do_str+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27db;
	}
x86_l_27c1:
	/* 0x27c1: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_27c7:
	/* 0x27c7: jmp    27f9 <__do_str+0x1a9> */
	goto x86_l_27f9;
x86_l_27c9:
	/* 0x27c9: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_27cd:
	/* 0x27cd: je     27eb <__do_str+0x19b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27eb;
	}
x86_l_27cf:
	/* 0x27cf: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_27d3:
	/* 0x27d3: je     27f3 <__do_str+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27f3;
	}
x86_l_27d5:
	/* 0x27d5: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_27d9:
	/* 0x27d9: je     27c1 <__do_str+0x171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27c1;
	}
x86_l_27db:
	/* 0x27db: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_27e1:
	/* 0x27e1: jmp    27f9 <__do_str+0x1a9> */
	goto x86_l_27f9;
x86_l_27e3:
	/* 0x27e3: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_27e9:
	/* 0x27e9: jmp    27f9 <__do_str+0x1a9> */
	goto x86_l_27f9;
x86_l_27eb:
	/* 0x27eb: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_27f1:
	/* 0x27f1: jmp    27f9 <__do_str+0x1a9> */
	goto x86_l_27f9;
x86_l_27f3:
	/* 0x27f3: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_27f9:
	/* 0x27f9: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_27fd:
	/* 0x27fd: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_2800:
	/* 0x2800: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2803:
	/* 0x2803: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2807:
	/* 0x2807: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2808:
	/* 0x2808: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_280a:
	/* 0x280a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_280c:
	/* 0x280c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_280e:
	/* 0x280e: ret */
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
	for (__u32 __x86_iter = 0; __x86_iter < 9740U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1671ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1676ULL && __x86_pc <= 3387ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3392ULL && __x86_pc <= 5150ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5154ULL && __x86_pc <= 6850ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6855ULL && __x86_pc <= 8430ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8433ULL && __x86_pc <= 9766ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9769ULL && __x86_pc <= 10254ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

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
	case 44ULL: goto x86_l_2c;
	case 51ULL: goto x86_l_33;
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
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 115ULL: goto x86_l_73;
	case 120ULL: goto x86_l_78;
	case 122ULL: goto x86_l_7a;
	case 128ULL: goto x86_l_80;
	case 136ULL: goto x86_l_88;
	case 144ULL: goto x86_l_90;
	case 150ULL: goto x86_l_96;
	case 155ULL: goto x86_l_9b;
	case 160ULL: goto x86_l_a0;
	case 165ULL: goto x86_l_a5;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 177ULL: goto x86_l_b1;
	case 181ULL: goto x86_l_b5;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 197ULL: goto x86_l_c5;
	case 202ULL: goto x86_l_ca;
	case 204ULL: goto x86_l_cc;
	case 207ULL: goto x86_l_cf;
	case 209ULL: goto x86_l_d1;
	case 212ULL: goto x86_l_d4;
	case 217ULL: goto x86_l_d9;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 233ULL: goto x86_l_e9;
	case 238ULL: goto x86_l_ee;
	case 243ULL: goto x86_l_f3;
	case 248ULL: goto x86_l_f8;
	case 250ULL: goto x86_l_fa;
	case 256ULL: goto x86_l_100;
	case 262ULL: goto x86_l_106;
	case 267ULL: goto x86_l_10b;
	case 272ULL: goto x86_l_110;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 289ULL: goto x86_l_121;
	case 293ULL: goto x86_l_125;
	case 297ULL: goto x86_l_129;
	case 302ULL: goto x86_l_12e;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 316ULL: goto x86_l_13c;
	case 319ULL: goto x86_l_13f;
	case 321ULL: goto x86_l_141;
	case 324ULL: goto x86_l_144;
	case 329ULL: goto x86_l_149;
	case 335ULL: goto x86_l_14f;
	case 340ULL: goto x86_l_154;
	case 345ULL: goto x86_l_159;
	case 350ULL: goto x86_l_15e;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 362ULL: goto x86_l_16a;
	case 368ULL: goto x86_l_170;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 384ULL: goto x86_l_180;
	case 389ULL: goto x86_l_185;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 401ULL: goto x86_l_191;
	case 405ULL: goto x86_l_195;
	case 409ULL: goto x86_l_199;
	case 414ULL: goto x86_l_19e;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 428ULL: goto x86_l_1ac;
	case 431ULL: goto x86_l_1af;
	case 433ULL: goto x86_l_1b1;
	case 436ULL: goto x86_l_1b4;
	case 441ULL: goto x86_l_1b9;
	case 443ULL: goto x86_l_1bb;
	case 448ULL: goto x86_l_1c0;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 468ULL: goto x86_l_1d4;
	case 470ULL: goto x86_l_1d6;
	case 476ULL: goto x86_l_1dc;
	case 482ULL: goto x86_l_1e2;
	case 487ULL: goto x86_l_1e7;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 513ULL: goto x86_l_201;
	case 517ULL: goto x86_l_205;
	case 522ULL: goto x86_l_20a;
	case 529ULL: goto x86_l_211;
	case 534ULL: goto x86_l_216;
	case 536ULL: goto x86_l_218;
	case 539ULL: goto x86_l_21b;
	case 545ULL: goto x86_l_221;
	case 548ULL: goto x86_l_224;
	case 553ULL: goto x86_l_229;
	case 559ULL: goto x86_l_22f;
	case 563ULL: goto x86_l_233;
	case 567ULL: goto x86_l_237;
	case 574ULL: goto x86_l_23e;
	case 581ULL: goto x86_l_245;
	case 589ULL: goto x86_l_24d;
	case 594ULL: goto x86_l_252;
	case 601ULL: goto x86_l_259;
	case 606ULL: goto x86_l_25e;
	case 608ULL: goto x86_l_260;
	case 611ULL: goto x86_l_263;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 627ULL: goto x86_l_273;
	case 633ULL: goto x86_l_279;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 654ULL: goto x86_l_28e;
	case 661ULL: goto x86_l_295;
	case 664ULL: goto x86_l_298;
	case 670ULL: goto x86_l_29e;
	case 676ULL: goto x86_l_2a4;
	case 678ULL: goto x86_l_2a6;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 690ULL: goto x86_l_2b2;
	case 695ULL: goto x86_l_2b7;
	case 702ULL: goto x86_l_2be;
	case 705ULL: goto x86_l_2c1;
	case 707ULL: goto x86_l_2c3;
	case 710ULL: goto x86_l_2c6;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 723ULL: goto x86_l_2d3;
	case 728ULL: goto x86_l_2d8;
	case 735ULL: goto x86_l_2df;
	case 737ULL: goto x86_l_2e1;
	case 740ULL: goto x86_l_2e4;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 748ULL: goto x86_l_2ec;
	case 750ULL: goto x86_l_2ee;
	case 758ULL: goto x86_l_2f6;
	case 762ULL: goto x86_l_2fa;
	case 765ULL: goto x86_l_2fd;
	case 768ULL: goto x86_l_300;
	case 774ULL: goto x86_l_306;
	case 777ULL: goto x86_l_309;
	case 779ULL: goto x86_l_30b;
	case 781ULL: goto x86_l_30d;
	case 786ULL: goto x86_l_312;
	case 793ULL: goto x86_l_319;
	case 798ULL: goto x86_l_31e;
	case 803ULL: goto x86_l_323;
	case 808ULL: goto x86_l_328;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 818ULL: goto x86_l_332;
	case 820ULL: goto x86_l_334;
	case 827ULL: goto x86_l_33b;
	case 832ULL: goto x86_l_340;
	case 837ULL: goto x86_l_345;
	case 842ULL: goto x86_l_34a;
	case 844ULL: goto x86_l_34c;
	case 848ULL: goto x86_l_350;
	case 850ULL: goto x86_l_352;
	case 852ULL: goto x86_l_354;
	case 859ULL: goto x86_l_35b;
	case 870ULL: goto x86_l_366;
	case 875ULL: goto x86_l_36b;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 893ULL: goto x86_l_37d;
	case 896ULL: goto x86_l_380;
	case 900ULL: goto x86_l_384;
	case 905ULL: goto x86_l_389;
	case 912ULL: goto x86_l_390;
	case 915ULL: goto x86_l_393;
	case 917ULL: goto x86_l_395;
	case 920ULL: goto x86_l_398;
	case 922ULL: goto x86_l_39a;
	case 925ULL: goto x86_l_39d;
	case 929ULL: goto x86_l_3a1;
	case 934ULL: goto x86_l_3a6;
	case 941ULL: goto x86_l_3ad;
	case 943ULL: goto x86_l_3af;
	case 946ULL: goto x86_l_3b2;
	case 948ULL: goto x86_l_3b4;
	case 951ULL: goto x86_l_3b7;
	case 954ULL: goto x86_l_3ba;
	case 956ULL: goto x86_l_3bc;
	case 964ULL: goto x86_l_3c4;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 974ULL: goto x86_l_3ce;
	case 976ULL: goto x86_l_3d0;
	case 979ULL: goto x86_l_3d3;
	case 981ULL: goto x86_l_3d5;
	case 983ULL: goto x86_l_3d7;
	case 991ULL: goto x86_l_3df;
	case 994ULL: goto x86_l_3e2;
	case 1001ULL: goto x86_l_3e9;
	case 1009ULL: goto x86_l_3f1;
	case 1014ULL: goto x86_l_3f6;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1031ULL: goto x86_l_407;
	case 1042ULL: goto x86_l_412;
	case 1045ULL: goto x86_l_415;
	case 1049ULL: goto x86_l_419;
	case 1060ULL: goto x86_l_424;
	case 1067ULL: goto x86_l_42b;
	case 1074ULL: goto x86_l_432;
	case 1079ULL: goto x86_l_437;
	case 1081ULL: goto x86_l_439;
	case 1085ULL: goto x86_l_43d;
	case 1090ULL: goto x86_l_442;
	case 1095ULL: goto x86_l_447;
	case 1100ULL: goto x86_l_44c;
	case 1102ULL: goto x86_l_44e;
	case 1104ULL: goto x86_l_450;
	case 1110ULL: goto x86_l_456;
	case 1112ULL: goto x86_l_458;
	case 1117ULL: goto x86_l_45d;
	case 1122ULL: goto x86_l_462;
	case 1126ULL: goto x86_l_466;
	case 1131ULL: goto x86_l_46b;
	case 1136ULL: goto x86_l_470;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1145ULL: goto x86_l_479;
	case 1150ULL: goto x86_l_47e;
	case 1155ULL: goto x86_l_483;
	case 1159ULL: goto x86_l_487;
	case 1162ULL: goto x86_l_48a;
	case 1165ULL: goto x86_l_48d;
	case 1172ULL: goto x86_l_494;
	case 1177ULL: goto x86_l_499;
	case 1182ULL: goto x86_l_49e;
	case 1184ULL: goto x86_l_4a0;
	case 1188ULL: goto x86_l_4a4;
	case 1195ULL: goto x86_l_4ab;
	case 1200ULL: goto x86_l_4b0;
	case 1202ULL: goto x86_l_4b2;
	case 1209ULL: goto x86_l_4b9;
	case 1220ULL: goto x86_l_4c4;
	case 1225ULL: goto x86_l_4c9;
	case 1227ULL: goto x86_l_4cb;
	case 1236ULL: goto x86_l_4d4;
	case 1239ULL: goto x86_l_4d7;
	case 1241ULL: goto x86_l_4d9;
	case 1245ULL: goto x86_l_4dd;
	case 1250ULL: goto x86_l_4e2;
	case 1255ULL: goto x86_l_4e7;
	case 1260ULL: goto x86_l_4ec;
	case 1263ULL: goto x86_l_4ef;
	case 1265ULL: goto x86_l_4f1;
	case 1270ULL: goto x86_l_4f6;
	case 1272ULL: goto x86_l_4f8;
	case 1274ULL: goto x86_l_4fa;
	case 1277ULL: goto x86_l_4fd;
	case 1284ULL: goto x86_l_504;
	case 1289ULL: goto x86_l_509;
	case 1294ULL: goto x86_l_50e;
	case 1301ULL: goto x86_l_515;
	case 1306ULL: goto x86_l_51a;
	case 1308ULL: goto x86_l_51c;
	case 1311ULL: goto x86_l_51f;
	case 1313ULL: goto x86_l_521;
	case 1315ULL: goto x86_l_523;
	case 1322ULL: goto x86_l_52a;
	case 1326ULL: goto x86_l_52e;
	case 1333ULL: goto x86_l_535;
	case 1336ULL: goto x86_l_538;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1353ULL: goto x86_l_549;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1367ULL: goto x86_l_557;
	case 1369ULL: goto x86_l_559;
	case 1371ULL: goto x86_l_55b;
	case 1379ULL: goto x86_l_563;
	case 1384ULL: goto x86_l_568;
	case 1391ULL: goto x86_l_56f;
	case 1396ULL: goto x86_l_574;
	case 1398ULL: goto x86_l_576;
	case 1401ULL: goto x86_l_579;
	case 1403ULL: goto x86_l_57b;
	case 1406ULL: goto x86_l_57e;
	case 1408ULL: goto x86_l_580;
	case 1419ULL: goto x86_l_58b;
	case 1430ULL: goto x86_l_596;
	case 1441ULL: goto x86_l_5a1;
	case 1443ULL: goto x86_l_5a3;
	case 1451ULL: goto x86_l_5ab;
	case 1456ULL: goto x86_l_5b0;
	case 1463ULL: goto x86_l_5b7;
	case 1468ULL: goto x86_l_5bc;
	case 1470ULL: goto x86_l_5be;
	case 1473ULL: goto x86_l_5c1;
	case 1475ULL: goto x86_l_5c3;
	case 1478ULL: goto x86_l_5c6;
	case 1485ULL: goto x86_l_5cd;
	case 1490ULL: goto x86_l_5d2;
	case 1493ULL: goto x86_l_5d5;
	case 1498ULL: goto x86_l_5da;
	case 1501ULL: goto x86_l_5dd;
	case 1503ULL: goto x86_l_5df;
	case 1505ULL: goto x86_l_5e1;
	case 1507ULL: goto x86_l_5e3;
	case 1509ULL: goto x86_l_5e5;
	case 1514ULL: goto x86_l_5ea;
	case 1516ULL: goto x86_l_5ec;
	case 1519ULL: goto x86_l_5ef;
	case 1522ULL: goto x86_l_5f2;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1533ULL: goto x86_l_5fd;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1548ULL: goto x86_l_60c;
	case 1550ULL: goto x86_l_60e;
	case 1552ULL: goto x86_l_610;
	case 1557ULL: goto x86_l_615;
	case 1559ULL: goto x86_l_617;
	case 1561ULL: goto x86_l_619;
	case 1563ULL: goto x86_l_61b;
	case 1565ULL: goto x86_l_61d;
	case 1567ULL: goto x86_l_61f;
	case 1569ULL: goto x86_l_621;
	case 1577ULL: goto x86_l_629;
	case 1584ULL: goto x86_l_630;
	case 1591ULL: goto x86_l_637;
	case 1596ULL: goto x86_l_63c;
	case 1598ULL: goto x86_l_63e;
	case 1609ULL: goto x86_l_649;
	case 1616ULL: goto x86_l_650;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1633ULL: goto x86_l_661;
	case 1636ULL: goto x86_l_664;
	case 1638ULL: goto x86_l_666;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	case 1652ULL: goto x86_l_674;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1686ULL: goto x86_l_696;
	case 1689ULL: goto x86_l_699;
	case 1691ULL: goto x86_l_69b;
	case 1693ULL: goto x86_l_69d;
	case 1695ULL: goto x86_l_69f;
	case 1703ULL: goto x86_l_6a7;
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
	/* 0x1c: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_33:
	/* 0x33: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3b:
	/* 0x3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d:
	/* 0x3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40:
	/* 0x40: je     1c60 <event_execve+0x1c60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7264ULL;
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
	/* 0x5a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f:
	/* 0x5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64:
	/* 0x64: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_69:
	/* 0x69: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_6e:
	/* 0x6e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_73:
	/* 0x73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_78:
	/* 0x78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a:
	/* 0x7a: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_80:
	/* 0x80: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_88:
	/* 0x88: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_90:
	/* 0x90: je     312 <event_execve+0x312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_312;
	}
x86_l_96:
	/* 0x96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b:
	/* 0x9b: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_a0:
	/* 0xa0: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_a5:
	/* 0xa5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aa:
	/* 0xaa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_af:
	/* 0xaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1:
	/* 0xb1: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9:
	/* 0xb9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_be:
	/* 0xbe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c5:
	/* 0xc5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca:
	/* 0xca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc:
	/* 0xcc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf:
	/* 0xcf: je     df <event_execve+0xdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df;
	}
x86_l_d1:
	/* 0xd1: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_d4:
	/* 0xd4: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d9:
	/* 0xd9: jne    22f <event_execve+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22f;
	}
x86_l_df:
	/* 0xdf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e4:
	/* 0xe4: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_e9:
	/* 0xe9: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_ee:
	/* 0xee: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f3:
	/* 0xf3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f8:
	/* 0xf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa:
	/* 0xfa: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_100:
	/* 0x100: je     312 <event_execve+0x312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_312;
	}
x86_l_106:
	/* 0x106: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10b:
	/* 0x10b: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_110:
	/* 0x110: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_115:
	/* 0x115: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11a:
	/* 0x11a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11f:
	/* 0x11f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121:
	/* 0x121: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_125:
	/* 0x125: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_129:
	/* 0x129: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e:
	/* 0x12e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_135:
	/* 0x135: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13a:
	/* 0x13a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c:
	/* 0x13c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13f:
	/* 0x13f: je     14f <event_execve+0x14f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f;
	}
x86_l_141:
	/* 0x141: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_144:
	/* 0x144: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_149:
	/* 0x149: jne    22f <event_execve+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22f;
	}
x86_l_14f:
	/* 0x14f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_154:
	/* 0x154: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_159:
	/* 0x159: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_15e:
	/* 0x15e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_163:
	/* 0x163: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_168:
	/* 0x168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a:
	/* 0x16a: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_170:
	/* 0x170: je     312 <event_execve+0x312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_312;
	}
x86_l_176:
	/* 0x176: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17b:
	/* 0x17b: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_180:
	/* 0x180: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_185:
	/* 0x185: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a:
	/* 0x18a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18f:
	/* 0x18f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191:
	/* 0x191: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_195:
	/* 0x195: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199:
	/* 0x199: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19e:
	/* 0x19e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1a5:
	/* 0x1a5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa:
	/* 0x1aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac:
	/* 0x1ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1af:
	/* 0x1af: je     1bb <event_execve+0x1bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb;
	}
x86_l_1b1:
	/* 0x1b1: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1b4:
	/* 0x1b4: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b9:
	/* 0x1b9: jne    22f <event_execve+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22f;
	}
x86_l_1bb:
	/* 0x1bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c0:
	/* 0x1c0: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_1c5:
	/* 0x1c5: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1ca:
	/* 0x1ca: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cf:
	/* 0x1cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d4:
	/* 0x1d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6:
	/* 0x1d6: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1dc:
	/* 0x1dc: je     312 <event_execve+0x312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_312;
	}
x86_l_1e2:
	/* 0x1e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e7:
	/* 0x1e7: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_1ec:
	/* 0x1ec: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1f1:
	/* 0x1f1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f6:
	/* 0x1f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fb:
	/* 0x1fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd:
	/* 0x1fd: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_201:
	/* 0x201: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_205:
	/* 0x205: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20a:
	/* 0x20a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_211:
	/* 0x211: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_216:
	/* 0x216: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218:
	/* 0x218: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21b:
	/* 0x21b: je     312 <event_execve+0x312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_312;
	}
x86_l_221:
	/* 0x221: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_224:
	/* 0x224: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_229:
	/* 0x229: je     312 <event_execve+0x312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_312;
	}
x86_l_22f:
	/* 0x22f: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_233:
	/* 0x233: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_237:
	/* 0x237: mov    QWORD PTR [r14+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_23e:
	/* 0x23e: mov    QWORD PTR [r14+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_245:
	/* 0x245: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_24d:
	/* 0x24d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_252:
	/* 0x252: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_gen)));
x86_l_259:
	/* 0x259: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25e:
	/* 0x25e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260:
	/* 0x260: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_263:
	/* 0x263: je     3fe <event_execve+0x3fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fe;
	}
x86_l_269:
	/* 0x269: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26c:
	/* 0x26c: cmp    rcx,QWORD PTR [rbp+0x378] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 888ULL);
x86_l_273:
	/* 0x273: je     3fe <event_execve+0x3fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fe;
	}
x86_l_279:
	/* 0x279: mov    QWORD PTR [rsp+0x90],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_281:
	/* 0x281: mov    QWORD PTR [rsp+0x78],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_286:
	/* 0x286: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_28e:
	/* 0x28e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_295:
	/* 0x295: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298:
	/* 0x298: je     370 <event_execve+0x370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_370;
	}
x86_l_29e:
	/* 0x29e: mov    r12d,0x1869f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 99999ULL);
x86_l_2a4:
	/* 0x2a4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a6:
	/* 0x2a6: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ab:
	/* 0x2ab: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ae:
	/* 0x2ae: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b2:
	/* 0x2b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b7:
	/* 0x2b7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2be:
	/* 0x2be: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c3:
	/* 0x2c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c6:
	/* 0x2c6: je     3d7 <event_execve+0x3d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d7;
	}
x86_l_2cc:
	/* 0x2cc: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2cf:
	/* 0x2cf: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d3:
	/* 0x2d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d8:
	/* 0x2d8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_2df:
	/* 0x2df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e1:
	/* 0x2e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e4:
	/* 0x2e4: je     2f6 <event_execve+0x2f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f6;
	}
x86_l_2e6:
	/* 0x2e6: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e9:
	/* 0x2e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ec:
	/* 0x2ec: je     2f6 <event_execve+0x2f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f6;
	}
x86_l_2ee:
	/* 0x2ee: or QWORD PTR [rbp+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_2f6:
	/* 0x2f6: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_2fa:
	/* 0x2fa: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_2fd:
	/* 0x2fd: cmp    r13,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_300:
	/* 0x300: je     3d7 <event_execve+0x3d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d7;
	}
x86_l_306:
	/* 0x306: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_309:
	/* 0x309: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_30b:
	/* 0x30b: je     2ab <event_execve+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ab;
	}
x86_l_30d:
	/* 0x30d: jmp    3d7 <event_execve+0x3d7> */
	goto x86_l_3d7;
x86_l_312:
	/* 0x312: lea    rdx,[rbx+0xae0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2784ULL);
x86_l_319:
	/* 0x319: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31e:
	/* 0x31e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_323:
	/* 0x323: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_328:
	/* 0x328: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a:
	/* 0x32a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32f:
	/* 0x32f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_332:
	/* 0x332: je     352 <event_execve+0x352> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_352;
	}
x86_l_334:
	/* 0x334: add    rdx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_33b:
	/* 0x33b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_340:
	/* 0x340: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_345:
	/* 0x345: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34a:
	/* 0x34a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34c:
	/* 0x34c: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_350:
	/* 0x350: jmp    354 <event_execve+0x354> */
	goto x86_l_354;
x86_l_352:
	/* 0x352: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_354:
	/* 0x354: mov    DWORD PTR [r14+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_35b:
	/* 0x35b: mov    QWORD PTR [r14+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_366:
	/* 0x366: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_36b:
	/* 0x36b: jmp    400 <event_execve+0x400> */
	goto x86_l_400;
x86_l_370:
	/* 0x370: mov    r12d,0x3ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_376:
	/* 0x376: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_378:
	/* 0x378: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37d:
	/* 0x37d: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_380:
	/* 0x380: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_384:
	/* 0x384: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_389:
	/* 0x389: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_390:
	/* 0x390: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_393:
	/* 0x393: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_395:
	/* 0x395: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_398:
	/* 0x398: je     3d7 <event_execve+0x3d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d7;
	}
x86_l_39a:
	/* 0x39a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_39d:
	/* 0x39d: lea    rsi,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3a1:
	/* 0x3a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a6:
	/* 0x3a6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mbset_map)));
x86_l_3ad:
	/* 0x3ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3af:
	/* 0x3af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b2:
	/* 0x3b2: je     3c4 <event_execve+0x3c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c4;
	}
x86_l_3b4:
	/* 0x3b4: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b7:
	/* 0x3b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ba:
	/* 0x3ba: je     3c4 <event_execve+0x3c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c4;
	}
x86_l_3bc:
	/* 0x3bc: or QWORD PTR [rbp+0x370],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 880ULL);
x86_l_3c4:
	/* 0x3c4: sub    r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SUB, 1ULL);
x86_l_3c8:
	/* 0x3c8: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_3cb:
	/* 0x3cb: cmp    r13,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_3ce:
	/* 0x3ce: je     3d7 <event_execve+0x3d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d7;
	}
x86_l_3d0:
	/* 0x3d0: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_3d3:
	/* 0x3d3: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3d5:
	/* 0x3d5: je     37d <event_execve+0x37d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37d;
	}
x86_l_3d7:
	/* 0x3d7: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3df:
	/* 0x3df: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e2:
	/* 0x3e2: mov    QWORD PTR [rbp+0x378],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 888ULL);
x86_l_3e9:
	/* 0x3e9: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3f1:
	/* 0x3f1: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3f6:
	/* 0x3f6: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3fe:
	/* 0x3fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_400:
	/* 0x400: mov    QWORD PTR [r14+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_407:
	/* 0x407: mov    DWORD PTR [r14+0x15c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619009ULL);
x86_l_412:
	/* 0x412: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_415:
	/* 0x415: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_419:
	/* 0x419: mov    QWORD PTR [r14+0x178],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1614907703296ULL);
x86_l_424:
	/* 0x424: mov    DWORD PTR [r14+0x144],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_42b:
	/* 0x42b: mov    DWORD PTR [r14+0x148],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_432:
	/* 0x432: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_437:
	/* 0x437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_439:
	/* 0x439: lea    rdx,[rax+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_43d:
	/* 0x43d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_442:
	/* 0x442: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_447:
	/* 0x447: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44c:
	/* 0x44c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44e:
	/* 0x44e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_450:
	/* 0x450: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_456:
	/* 0x456: je     4a4 <event_execve+0x4a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a4;
	}
x86_l_458:
	/* 0x458: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_45d:
	/* 0x45d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_462:
	/* 0x462: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_466:
	/* 0x466: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46b:
	/* 0x46b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_470:
	/* 0x470: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_472:
	/* 0x472: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_477:
	/* 0x477: je     4a4 <event_execve+0x4a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a4;
	}
x86_l_479:
	/* 0x479: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47e:
	/* 0x47e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_483:
	/* 0x483: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_487:
	/* 0x487: shl    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_48a:
	/* 0x48a: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_48d:
	/* 0x48d: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_494:
	/* 0x494: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_499:
	/* 0x499: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_49e:
	/* 0x49e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a0:
	/* 0x4a0: mov    ebx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a4:
	/* 0x4a4: mov    DWORD PTR [r14+0x14c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 332ULL);
x86_l_4ab:
	/* 0x4ab: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_4b0:
	/* 0x4b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b2:
	/* 0x4b2: mov    QWORD PTR [r14+0x170],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4b9:
	/* 0x4b9: mov    DWORD PTR [r14+0x140],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534784ULL);
x86_l_4c4:
	/* 0x4c4: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_4c9:
	/* 0x4c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cb:
	/* 0x4cb: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d4:
	/* 0x4d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4d7:
	/* 0x4d7: je     4f8 <event_execve+0x4f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f8;
	}
x86_l_4d9:
	/* 0x4d9: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_4dd:
	/* 0x4dd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4e2:
	/* 0x4e2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e7:
	/* 0x4e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ec:
	/* 0x4ec: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4ef:
	/* 0x4ef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4f1:
	/* 0x4f1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f6:
	/* 0x4f6: jmp    4fa <event_execve+0x4fa> */
	goto x86_l_4fa;
x86_l_4f8:
	/* 0x4f8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fa:
	/* 0x4fa: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4fd:
	/* 0x4fd: mov    DWORD PTR [r14+0x158],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_504:
	/* 0x504: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_509:
	/* 0x509: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_50e:
	/* 0x50e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map)));
x86_l_515:
	/* 0x515: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51a:
	/* 0x51a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51c:
	/* 0x51c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51f:
	/* 0x51f: je     580 <event_execve+0x580> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_580;
	}
x86_l_521:
	/* 0x521: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_523:
	/* 0x523: mov    DWORD PTR [r14+0x150],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_52a:
	/* 0x52a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52e:
	/* 0x52e: mov    QWORD PTR [r14+0x168],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_535:
	/* 0x535: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_538:
	/* 0x538: mov    DWORD PTR [r14+0x160],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_53f:
	/* 0x53f: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_544:
	/* 0x544: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_549:
	/* 0x549: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map)));
x86_l_550:
	/* 0x550: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_555:
	/* 0x555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_557:
	/* 0x557: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_559:
	/* 0x559: je     5a3 <event_execve+0x5a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a3;
	}
x86_l_55b:
	/* 0x55b: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_563:
	/* 0x563: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_568:
	/* 0x568: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map_stats)));
x86_l_56f:
	/* 0x56f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_574:
	/* 0x574: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_576:
	/* 0x576: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_579:
	/* 0x579: je     5c6 <event_execve+0x5c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c6;
	}
x86_l_57b:
	/* 0x57b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_57e:
	/* 0x57e: jmp    5c6 <event_execve+0x5c6> */
	goto x86_l_5c6;
x86_l_580:
	/* 0x580: mov    DWORD PTR [r14+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_58b:
	/* 0x58b: mov    QWORD PTR [r14+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_596:
	/* 0x596: mov    DWORD PTR [r14+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_5a1:
	/* 0x5a1: jmp    5c6 <event_execve+0x5c6> */
	goto x86_l_5c6;
x86_l_5a3:
	/* 0x5a3: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5ab:
	/* 0x5ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b0:
	/* 0x5b0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map_stats)));
x86_l_5b7:
	/* 0x5b7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bc:
	/* 0x5bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5be:
	/* 0x5be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c1:
	/* 0x5c1: je     5c6 <event_execve+0x5c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c6;
	}
x86_l_5c3:
	/* 0x5c3: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_5c6:
	/* 0x5c6: lea    rbx,[r14+0x180] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_5cd:
	/* 0x5cd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5d2:
	/* 0x5d2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5d5:
	/* 0x5d5: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_5da:
	/* 0x5da: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5dd:
	/* 0x5dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5df:
	/* 0x5df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e1:
	/* 0x5e1: js     60e <event_execve+0x60e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60e;
	}
x86_l_5e3:
	/* 0x5e3: je     617 <event_execve+0x617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_617;
	}
x86_l_5e5:
	/* 0x5e5: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_5ea:
	/* 0x5ea: jne    61b <event_execve+0x61b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_61b;
	}
x86_l_5ec:
	/* 0x5ec: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5ef:
	/* 0x5ef: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_5f2:
	/* 0x5f2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5f5:
	/* 0x5f5: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1530ULL);
	return 7281ULL;
x86_l_5fa:
	/* 0x5fa: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5fd:
	/* 0x5fd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5ff:
	/* 0x5ff: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_604:
	/* 0x604: mov    eax,0x800000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8388608ULL);
x86_l_609:
	/* 0x609: cmove  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_E);
x86_l_60c:
	/* 0x60c: jmp    621 <event_execve+0x621> */
	goto x86_l_621;
x86_l_60e:
	/* 0x60e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_610:
	/* 0x610: mov    eax,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_615:
	/* 0x615: jmp    621 <event_execve+0x621> */
	goto x86_l_621;
x86_l_617:
	/* 0x617: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_619:
	/* 0x619: jmp    621 <event_execve+0x621> */
	goto x86_l_621;
x86_l_61b:
	/* 0x61b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_61d:
	/* 0x61d: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_61f:
	/* 0x61f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_621:
	/* 0x621: mov    WORD PTR [r14+0x178],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_629:
	/* 0x629: or     DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_630:
	/* 0x630: add    DWORD PTR [r14+0x140],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 320ULL);
x86_l_637:
	/* 0x637: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_63c:
	/* 0x63c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63e:
	/* 0x63e: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_649:
	/* 0x649: lea    rdx,[rax+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_650:
	/* 0x650: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_655:
	/* 0x655: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_65a:
	/* 0x65a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65f:
	/* 0x65f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_661:
	/* 0x661: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_664:
	/* 0x664: je     6c1 <event_execve+0x6c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1729ULL;
	}
x86_l_666:
	/* 0x666: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_668:
	/* 0x668: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66d:
	/* 0x66d: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_674:
	/* 0x674: movabs rax,0x400000042 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869250ULL);
x86_l_67e:
	/* 0x67e: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_683:
	/* 0x683: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_688:
	/* 0x688: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_68f:
	/* 0x68f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_694:
	/* 0x694: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_696:
	/* 0x696: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_699:
	/* 0x699: je     69f <event_execve+0x69f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_69f;
	}
x86_l_69b:
	/* 0x69b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_69d:
	/* 0x69d: jmp    6c1 <event_execve+0x6c1> */
	return 1729ULL;
x86_l_69f:
	/* 0x69f: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_6a7:
	/* 0x6a7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
	return 1708ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1708ULL: goto x86_l_6ac;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1727ULL: goto x86_l_6bf;
	case 1729ULL: goto x86_l_6c1;
	case 1736ULL: goto x86_l_6c8;
	case 1738ULL: goto x86_l_6ca;
	case 1744ULL: goto x86_l_6d0;
	case 1750ULL: goto x86_l_6d6;
	case 1756ULL: goto x86_l_6dc;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1783ULL: goto x86_l_6f7;
	case 1786ULL: goto x86_l_6fa;
	case 1788ULL: goto x86_l_6fc;
	case 1790ULL: goto x86_l_6fe;
	case 1795ULL: goto x86_l_703;
	case 1802ULL: goto x86_l_70a;
	case 1812ULL: goto x86_l_714;
	case 1817ULL: goto x86_l_719;
	case 1822ULL: goto x86_l_71e;
	case 1829ULL: goto x86_l_725;
	case 1834ULL: goto x86_l_72a;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1841ULL: goto x86_l_731;
	case 1843ULL: goto x86_l_733;
	case 1845ULL: goto x86_l_735;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1877ULL: goto x86_l_755;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1906ULL: goto x86_l_772;
	case 1909ULL: goto x86_l_775;
	case 1911ULL: goto x86_l_777;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1925ULL: goto x86_l_785;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1959ULL: goto x86_l_7a7;
	case 1962ULL: goto x86_l_7aa;
	case 1968ULL: goto x86_l_7b0;
	case 1970ULL: goto x86_l_7b2;
	case 1976ULL: goto x86_l_7b8;
	case 1982ULL: goto x86_l_7be;
	case 1988ULL: goto x86_l_7c4;
	case 1994ULL: goto x86_l_7ca;
	case 2000ULL: goto x86_l_7d0;
	case 2006ULL: goto x86_l_7d6;
	case 2011ULL: goto x86_l_7db;
	case 2018ULL: goto x86_l_7e2;
	case 2026ULL: goto x86_l_7ea;
	case 2028ULL: goto x86_l_7ec;
	case 2034ULL: goto x86_l_7f2;
	case 2037ULL: goto x86_l_7f5;
	case 2043ULL: goto x86_l_7fb;
	case 2048ULL: goto x86_l_800;
	case 2053ULL: goto x86_l_805;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2063ULL: goto x86_l_80f;
	case 2069ULL: goto x86_l_815;
	case 2072ULL: goto x86_l_818;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2095ULL: goto x86_l_82f;
	case 2101ULL: goto x86_l_835;
	case 2105ULL: goto x86_l_839;
	case 2112ULL: goto x86_l_840;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2127ULL: goto x86_l_84f;
	case 2130ULL: goto x86_l_852;
	case 2137ULL: goto x86_l_859;
	case 2143ULL: goto x86_l_85f;
	case 2146ULL: goto x86_l_862;
	case 2149ULL: goto x86_l_865;
	case 2156ULL: goto x86_l_86c;
	case 2159ULL: goto x86_l_86f;
	case 2165ULL: goto x86_l_875;
	case 2168ULL: goto x86_l_878;
	case 2170ULL: goto x86_l_87a;
	case 2176ULL: goto x86_l_880;
	case 2179ULL: goto x86_l_883;
	case 2182ULL: goto x86_l_886;
	case 2186ULL: goto x86_l_88a;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2199ULL: goto x86_l_897;
	case 2202ULL: goto x86_l_89a;
	case 2204ULL: goto x86_l_89c;
	case 2207ULL: goto x86_l_89f;
	case 2213ULL: goto x86_l_8a5;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2230ULL: goto x86_l_8b6;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2257ULL: goto x86_l_8d1;
	case 2262ULL: goto x86_l_8d6;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2269ULL: goto x86_l_8dd;
	case 2271ULL: goto x86_l_8df;
	case 2273ULL: goto x86_l_8e1;
	case 2281ULL: goto x86_l_8e9;
	case 2286ULL: goto x86_l_8ee;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2313ULL: goto x86_l_909;
	case 2319ULL: goto x86_l_90f;
	case 2325ULL: goto x86_l_915;
	case 2327ULL: goto x86_l_917;
	case 2330ULL: goto x86_l_91a;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2349ULL: goto x86_l_92d;
	case 2351ULL: goto x86_l_92f;
	case 2354ULL: goto x86_l_932;
	case 2356ULL: goto x86_l_934;
	case 2359ULL: goto x86_l_937;
	case 2361ULL: goto x86_l_939;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2381ULL: goto x86_l_94d;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2393ULL: goto x86_l_959;
	case 2395ULL: goto x86_l_95b;
	case 2397ULL: goto x86_l_95d;
	case 2400ULL: goto x86_l_960;
	case 2402ULL: goto x86_l_962;
	case 2405ULL: goto x86_l_965;
	case 2410ULL: goto x86_l_96a;
	case 2417ULL: goto x86_l_971;
	case 2424ULL: goto x86_l_978;
	case 2432ULL: goto x86_l_980;
	case 2439ULL: goto x86_l_987;
	case 2446ULL: goto x86_l_98e;
	case 2454ULL: goto x86_l_996;
	case 2460ULL: goto x86_l_99c;
	case 2468ULL: goto x86_l_9a4;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2482ULL: goto x86_l_9b2;
	case 2490ULL: goto x86_l_9ba;
	case 2493ULL: goto x86_l_9bd;
	case 2499ULL: goto x86_l_9c3;
	case 2502ULL: goto x86_l_9c6;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2524ULL: goto x86_l_9dc;
	case 2526ULL: goto x86_l_9de;
	case 2530ULL: goto x86_l_9e2;
	case 2536ULL: goto x86_l_9e8;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2561ULL: goto x86_l_a01;
	case 2563ULL: goto x86_l_a03;
	case 2568ULL: goto x86_l_a08;
	case 2571ULL: goto x86_l_a0b;
	case 2577ULL: goto x86_l_a11;
	case 2584ULL: goto x86_l_a18;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2601ULL: goto x86_l_a29;
	case 2605ULL: goto x86_l_a2d;
	case 2611ULL: goto x86_l_a33;
	case 2618ULL: goto x86_l_a3a;
	case 2623ULL: goto x86_l_a3f;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2636ULL: goto x86_l_a4c;
	case 2638ULL: goto x86_l_a4e;
	case 2643ULL: goto x86_l_a53;
	case 2646ULL: goto x86_l_a56;
	case 2652ULL: goto x86_l_a5c;
	case 2659ULL: goto x86_l_a63;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2676ULL: goto x86_l_a74;
	case 2680ULL: goto x86_l_a78;
	case 2686ULL: goto x86_l_a7e;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2711ULL: goto x86_l_a97;
	case 2713ULL: goto x86_l_a99;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2727ULL: goto x86_l_aa7;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2751ULL: goto x86_l_abf;
	case 2755ULL: goto x86_l_ac3;
	case 2761ULL: goto x86_l_ac9;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2783ULL: goto x86_l_adf;
	case 2786ULL: goto x86_l_ae2;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2796ULL: goto x86_l_aec;
	case 2802ULL: goto x86_l_af2;
	case 2809ULL: goto x86_l_af9;
	case 2814ULL: goto x86_l_afe;
	case 2819ULL: goto x86_l_b03;
	case 2824ULL: goto x86_l_b08;
	case 2826ULL: goto x86_l_b0a;
	case 2830ULL: goto x86_l_b0e;
	case 2836ULL: goto x86_l_b14;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2861ULL: goto x86_l_b2d;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2871ULL: goto x86_l_b37;
	case 2877ULL: goto x86_l_b3d;
	case 2884ULL: goto x86_l_b44;
	case 2889ULL: goto x86_l_b49;
	case 2894ULL: goto x86_l_b4e;
	case 2899ULL: goto x86_l_b53;
	case 2901ULL: goto x86_l_b55;
	case 2905ULL: goto x86_l_b59;
	case 2911ULL: goto x86_l_b5f;
	case 2918ULL: goto x86_l_b66;
	case 2923ULL: goto x86_l_b6b;
	case 2928ULL: goto x86_l_b70;
	case 2933ULL: goto x86_l_b75;
	case 2936ULL: goto x86_l_b78;
	case 2938ULL: goto x86_l_b7a;
	case 2943ULL: goto x86_l_b7f;
	case 2946ULL: goto x86_l_b82;
	case 2952ULL: goto x86_l_b88;
	case 2959ULL: goto x86_l_b8f;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2976ULL: goto x86_l_ba0;
	case 2980ULL: goto x86_l_ba4;
	case 2986ULL: goto x86_l_baa;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3003ULL: goto x86_l_bbb;
	case 3008ULL: goto x86_l_bc0;
	case 3011ULL: goto x86_l_bc3;
	case 3013ULL: goto x86_l_bc5;
	case 3018ULL: goto x86_l_bca;
	case 3021ULL: goto x86_l_bcd;
	case 3027ULL: goto x86_l_bd3;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3051ULL: goto x86_l_beb;
	case 3055ULL: goto x86_l_bef;
	case 3061ULL: goto x86_l_bf5;
	case 3068ULL: goto x86_l_bfc;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3096ULL: goto x86_l_c18;
	case 3102ULL: goto x86_l_c1e;
	case 3109ULL: goto x86_l_c25;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3126ULL: goto x86_l_c36;
	case 3130ULL: goto x86_l_c3a;
	case 3136ULL: goto x86_l_c40;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3153ULL: goto x86_l_c51;
	case 3158ULL: goto x86_l_c56;
	case 3161ULL: goto x86_l_c59;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3177ULL: goto x86_l_c69;
	case 3184ULL: goto x86_l_c70;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3201ULL: goto x86_l_c81;
	case 3205ULL: goto x86_l_c85;
	case 3211ULL: goto x86_l_c8b;
	case 3218ULL: goto x86_l_c92;
	case 3223ULL: goto x86_l_c97;
	case 3228ULL: goto x86_l_c9c;
	case 3233ULL: goto x86_l_ca1;
	case 3236ULL: goto x86_l_ca4;
	case 3238ULL: goto x86_l_ca6;
	case 3243ULL: goto x86_l_cab;
	case 3246ULL: goto x86_l_cae;
	case 3252ULL: goto x86_l_cb4;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3276ULL: goto x86_l_ccc;
	case 3280ULL: goto x86_l_cd0;
	case 3286ULL: goto x86_l_cd6;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3311ULL: goto x86_l_cef;
	case 3313ULL: goto x86_l_cf1;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3334ULL: goto x86_l_d06;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3351ULL: goto x86_l_d17;
	case 3355ULL: goto x86_l_d1b;
	case 3361ULL: goto x86_l_d21;
	case 3368ULL: goto x86_l_d28;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3396ULL: goto x86_l_d44;
	case 3402ULL: goto x86_l_d4a;
	case 3409ULL: goto x86_l_d51;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3426ULL: goto x86_l_d62;
	case 3430ULL: goto x86_l_d66;
	case 3436ULL: goto x86_l_d6c;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3461ULL: goto x86_l_d85;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3471ULL: goto x86_l_d8f;
	case 3477ULL: goto x86_l_d95;
	case 3484ULL: goto x86_l_d9c;
	case 3489ULL: goto x86_l_da1;
	case 3494ULL: goto x86_l_da6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6ac:
	/* 0x6ac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_6b3:
	/* 0x6b3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b8:
	/* 0x6b8: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6bd:
	/* 0x6bd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6bf:
	/* 0x6bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c1:
	/* 0x6c1: lea    rbx,[r14+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_6c8:
	/* 0x6c8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ca:
	/* 0x6ca: cmp    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6d0:
	/* 0x6d0: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_6d6:
	/* 0x6d6: je     980 <event_execve+0x980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_980;
	}
x86_l_6dc:
	/* 0x6dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6e1:
	/* 0x6e1: mov    edx,0x188 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 392ULL);
x86_l_6e6:
	/* 0x6e6: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_6eb:
	/* 0x6eb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f0:
	/* 0x6f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f5:
	/* 0x6f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f7:
	/* 0x6f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6fa:
	/* 0x6fa: je     757 <event_execve+0x757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_757;
	}
x86_l_6fc:
	/* 0x6fc: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_6fe:
	/* 0x6fe: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_703:
	/* 0x703: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_70a:
	/* 0x70a: movabs rax,0x400000047 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869255ULL);
x86_l_714:
	/* 0x714: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_719:
	/* 0x719: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_71e:
	/* 0x71e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_725:
	/* 0x725: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_72a:
	/* 0x72a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72c:
	/* 0x72c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72f:
	/* 0x72f: je     735 <event_execve+0x735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_735;
	}
x86_l_731:
	/* 0x731: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_733:
	/* 0x733: jmp    757 <event_execve+0x757> */
	goto x86_l_757;
x86_l_735:
	/* 0x735: mov    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_73d:
	/* 0x73d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_742:
	/* 0x742: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_749:
	/* 0x749: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_74e:
	/* 0x74e: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_753:
	/* 0x753: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_755:
	/* 0x755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_757:
	/* 0x757: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_75c:
	/* 0x75c: mov    edx,0x190 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 400ULL);
x86_l_761:
	/* 0x761: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_766:
	/* 0x766: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_76b:
	/* 0x76b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_770:
	/* 0x770: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_772:
	/* 0x772: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_775:
	/* 0x775: je     7b2 <event_execve+0x7b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7b2;
	}
x86_l_777:
	/* 0x777: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_779:
	/* 0x779: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_77e:
	/* 0x77e: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_785:
	/* 0x785: movabs rax,0x400000048 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869256ULL);
x86_l_78f:
	/* 0x78f: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_794:
	/* 0x794: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_799:
	/* 0x799: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7a0:
	/* 0x7a0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a5:
	/* 0x7a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a7:
	/* 0x7a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7aa:
	/* 0x7aa: je     8e1 <event_execve+0x8e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8e1;
	}
x86_l_7b0:
	/* 0x7b0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7b2:
	/* 0x7b2: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_7b8:
	/* 0x7b8: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_7be:
	/* 0x7be: je     980 <event_execve+0x980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_980;
	}
x86_l_7c4:
	/* 0x7c4: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_7ca:
	/* 0x7ca: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_7d0:
	/* 0x7d0: je     980 <event_execve+0x980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_980;
	}
x86_l_7d6:
	/* 0x7d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7db:
	/* 0x7db: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_heap)));
x86_l_7e2:
	/* 0x7e2: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7ea:
	/* 0x7ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ec:
	/* 0x7ec: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_7f2:
	/* 0x7f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f5:
	/* 0x7f5: je     980 <event_execve+0x980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_980;
	}
x86_l_7fb:
	/* 0x7fb: mov    ecx,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 45ULL);
x86_l_800:
	/* 0x800: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_805:
	/* 0x805: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_808:
	/* 0x808: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_80d:
	/* 0x80d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_80f:
	/* 0x80f: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_815:
	/* 0x815: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_818:
	/* 0x818: js     980 <event_execve+0x980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_980;
	}
x86_l_81e:
	/* 0x81e: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_823:
	/* 0x823: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_828:
	/* 0x828: mov    ecx,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_82f:
	/* 0x82f: and    ecx,0x1ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 511ULL);
x86_l_835:
	/* 0x835: lea    rsi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_839:
	/* 0x839: add    rsi,0x140 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 320ULL);
x86_l_840:
	/* 0x840: mov    DWORD PTR [r14+0x184c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6220ULL);
x86_l_847:
	/* 0x847: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_84c:
	/* 0x84c: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_84f:
	/* 0x84f: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_852:
	/* 0x852: cmp    rcx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 1023ULL);
x86_l_859:
	/* 0x859: ja     917 <event_execve+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_917;
	}
x86_l_85f:
	/* 0x85f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_862:
	/* 0x862: sub    rdi,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_865:
	/* 0x865: add    rdi,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 1024ULL);
x86_l_86c:
	/* 0x86c: cmp    rcx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_86f:
	/* 0x86f: jae    917 <event_execve+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_917;
	}
x86_l_875:
	/* 0x875: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_878:
	/* 0x878: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_87a:
	/* 0x87a: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_880:
	/* 0x880: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_883:
	/* 0x883: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_886:
	/* 0x886: cmovne r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_88a:
	/* 0x88a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_88f:
	/* 0x88f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_894:
	/* 0x894: mov    rdi,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_897:
	/* 0x897: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_89a:
	/* 0x89a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89c:
	/* 0x89c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_89f:
	/* 0x89f: je     934 <event_execve+0x934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_934;
	}
x86_l_8a5:
	/* 0x8a5: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_8a8:
	/* 0x8a8: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_8aa:
	/* 0x8aa: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8af:
	/* 0x8af: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_8b6:
	/* 0x8b6: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_8c0:
	/* 0x8c0: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8c5:
	/* 0x8c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8ca:
	/* 0x8ca: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8d1:
	/* 0x8d1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8d6:
	/* 0x8d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d8:
	/* 0x8d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: je     939 <event_execve+0x939> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_939;
	}
x86_l_8dd:
	/* 0x8dd: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8df:
	/* 0x8df: jmp    95b <event_execve+0x95b> */
	goto x86_l_95b;
x86_l_8e1:
	/* 0x8e1: mov    DWORD PTR [rsp+0x70],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337153ULL);
x86_l_8e9:
	/* 0x8e9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8ee:
	/* 0x8ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8f5:
	/* 0x8f5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8fa:
	/* 0x8fa: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8ff:
	/* 0x8ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_901:
	/* 0x901: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_903:
	/* 0x903: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_909:
	/* 0x909: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_90f:
	/* 0x90f: jne    7c4 <event_execve+0x7c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7c4;
	}
x86_l_915:
	/* 0x915: jmp    980 <event_execve+0x980> */
	goto x86_l_980;
x86_l_917:
	/* 0x917: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_91a:
	/* 0x91a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_91d:
	/* 0x91d: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2338ULL);
	return 7469ULL;
x86_l_922:
	/* 0x922: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_925:
	/* 0x925: mov    eax,0x1000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16777216ULL);
x86_l_92a:
	/* 0x92a: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_92d:
	/* 0x92d: jne    96a <event_execve+0x96a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_96a;
	}
x86_l_92f:
	/* 0x92f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_932:
	/* 0x932: jmp    971 <event_execve+0x971> */
	goto x86_l_971;
x86_l_934:
	/* 0x934: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_937:
	/* 0x937: jmp    971 <event_execve+0x971> */
	goto x86_l_971;
x86_l_939:
	/* 0x939: mov    DWORD PTR [rsp+0x70],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337153ULL);
x86_l_941:
	/* 0x941: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_946:
	/* 0x946: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_94d:
	/* 0x94d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_952:
	/* 0x952: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_957:
	/* 0x957: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_959:
	/* 0x959: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95b:
	/* 0x95b: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_95d:
	/* 0x95d: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_960:
	/* 0x960: jns    971 <event_execve+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_971;
	}
x86_l_962:
	/* 0x962: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_965:
	/* 0x965: mov    eax,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_96a:
	/* 0x96a: or     DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_971:
	/* 0x971: mov    DWORD PTR [r14+0x1848],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6216ULL);
x86_l_978:
	/* 0x978: mov    WORD PTR [r14+0x17a],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 378ULL);
x86_l_980:
	/* 0x980: add    r12d,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 320ULL);
x86_l_987:
	/* 0x987: mov    DWORD PTR [r14+0x140],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_98e:
	/* 0x98e: test   BYTE PTR [r14+0x15d],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1498943586336ULL);
x86_l_996:
	/* 0x996: jne    1429 <event_execve+0x1429> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5161ULL;
	}
x86_l_99c:
	/* 0x99c: mov    QWORD PTR [rsp+0x80],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9a4:
	/* 0x9a4: mov    ebx,DWORD PTR [r14+0x144] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_9ab:
	/* 0x9ab: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_9b0:
	/* 0x9b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b2:
	/* 0x9b2: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_9ba:
	/* 0x9ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9bd:
	/* 0x9bd: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_9c3:
	/* 0x9c3: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_9c6:
	/* 0x9c6: lea    rdx,[rax+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_9cd:
	/* 0x9cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9d2:
	/* 0x9d2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d7:
	/* 0x9d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9dc:
	/* 0x9dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9de:
	/* 0x9de: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e2:
	/* 0x9e2: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_9e8:
	/* 0x9e8: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_9ef:
	/* 0x9ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9f4:
	/* 0x9f4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f9:
	/* 0x9f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9fe:
	/* 0x9fe: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a01:
	/* 0xa01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a03:
	/* 0xa03: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a08:
	/* 0xa08: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_a0b:
	/* 0xa0b: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_a11:
	/* 0xa11: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_a18:
	/* 0xa18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a1d:
	/* 0xa1d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a22:
	/* 0xa22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a27:
	/* 0xa27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a29:
	/* 0xa29: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2d:
	/* 0xa2d: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_a33:
	/* 0xa33: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_a3a:
	/* 0xa3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a3f:
	/* 0xa3f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a44:
	/* 0xa44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a49:
	/* 0xa49: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a4c:
	/* 0xa4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4e:
	/* 0xa4e: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a53:
	/* 0xa53: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_a56:
	/* 0xa56: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_a5c:
	/* 0xa5c: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_a63:
	/* 0xa63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a68:
	/* 0xa68: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6d:
	/* 0xa6d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a72:
	/* 0xa72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a74:
	/* 0xa74: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a78:
	/* 0xa78: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_a7e:
	/* 0xa7e: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_a85:
	/* 0xa85: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a8a:
	/* 0xa8a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a8f:
	/* 0xa8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a94:
	/* 0xa94: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a97:
	/* 0xa97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a99:
	/* 0xa99: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a9e:
	/* 0xa9e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_aa1:
	/* 0xaa1: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_aa7:
	/* 0xaa7: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_aae:
	/* 0xaae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ab3:
	/* 0xab3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ab8:
	/* 0xab8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_abd:
	/* 0xabd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abf:
	/* 0xabf: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac3:
	/* 0xac3: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_ac9:
	/* 0xac9: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_ad0:
	/* 0xad0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ad5:
	/* 0xad5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ada:
	/* 0xada: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_adf:
	/* 0xadf: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ae2:
	/* 0xae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae4:
	/* 0xae4: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ae9:
	/* 0xae9: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_aec:
	/* 0xaec: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_af2:
	/* 0xaf2: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_af9:
	/* 0xaf9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_afe:
	/* 0xafe: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b03:
	/* 0xb03: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b08:
	/* 0xb08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0a:
	/* 0xb0a: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b0e:
	/* 0xb0e: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_b14:
	/* 0xb14: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_b1b:
	/* 0xb1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b20:
	/* 0xb20: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b25:
	/* 0xb25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b2a:
	/* 0xb2a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b2d:
	/* 0xb2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2f:
	/* 0xb2f: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b34:
	/* 0xb34: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_b37:
	/* 0xb37: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_b3d:
	/* 0xb3d: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_b44:
	/* 0xb44: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b49:
	/* 0xb49: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b4e:
	/* 0xb4e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b53:
	/* 0xb53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b55:
	/* 0xb55: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b59:
	/* 0xb59: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_b5f:
	/* 0xb5f: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_b66:
	/* 0xb66: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b6b:
	/* 0xb6b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b70:
	/* 0xb70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b75:
	/* 0xb75: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b78:
	/* 0xb78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7a:
	/* 0xb7a: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b7f:
	/* 0xb7f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_b82:
	/* 0xb82: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_b88:
	/* 0xb88: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_b8f:
	/* 0xb8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b94:
	/* 0xb94: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b99:
	/* 0xb99: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b9e:
	/* 0xb9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba0:
	/* 0xba0: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba4:
	/* 0xba4: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_baa:
	/* 0xbaa: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_bb1:
	/* 0xbb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bb6:
	/* 0xbb6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bbb:
	/* 0xbbb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc0:
	/* 0xbc0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_bc3:
	/* 0xbc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc5:
	/* 0xbc5: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bca:
	/* 0xbca: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_bcd:
	/* 0xbcd: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_bd3:
	/* 0xbd3: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_bda:
	/* 0xbda: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bdf:
	/* 0xbdf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be4:
	/* 0xbe4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_be9:
	/* 0xbe9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_beb:
	/* 0xbeb: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bef:
	/* 0xbef: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_bf5:
	/* 0xbf5: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_bfc:
	/* 0xbfc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c01:
	/* 0xc01: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c06:
	/* 0xc06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c0b:
	/* 0xc0b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c0e:
	/* 0xc0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c10:
	/* 0xc10: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c15:
	/* 0xc15: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_c18:
	/* 0xc18: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_c1e:
	/* 0xc1e: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_c25:
	/* 0xc25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c2a:
	/* 0xc2a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2f:
	/* 0xc2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c34:
	/* 0xc34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c36:
	/* 0xc36: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3a:
	/* 0xc3a: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_c40:
	/* 0xc40: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_c47:
	/* 0xc47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c4c:
	/* 0xc4c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c51:
	/* 0xc51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c56:
	/* 0xc56: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c59:
	/* 0xc59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5b:
	/* 0xc5b: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c60:
	/* 0xc60: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_c63:
	/* 0xc63: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_c69:
	/* 0xc69: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_c70:
	/* 0xc70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c75:
	/* 0xc75: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c7a:
	/* 0xc7a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c7f:
	/* 0xc7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c81:
	/* 0xc81: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c85:
	/* 0xc85: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_c8b:
	/* 0xc8b: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_c92:
	/* 0xc92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c97:
	/* 0xc97: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c9c:
	/* 0xc9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca1:
	/* 0xca1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ca4:
	/* 0xca4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca6:
	/* 0xca6: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cab:
	/* 0xcab: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_cae:
	/* 0xcae: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_cb4:
	/* 0xcb4: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_cbb:
	/* 0xcbb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cc0:
	/* 0xcc0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc5:
	/* 0xcc5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cca:
	/* 0xcca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ccc:
	/* 0xccc: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd0:
	/* 0xcd0: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_cd6:
	/* 0xcd6: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_cdd:
	/* 0xcdd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce2:
	/* 0xce2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ce7:
	/* 0xce7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cec:
	/* 0xcec: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_cef:
	/* 0xcef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf1:
	/* 0xcf1: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cf6:
	/* 0xcf6: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_cf9:
	/* 0xcf9: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_cff:
	/* 0xcff: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_d06:
	/* 0xd06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d0b:
	/* 0xd0b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d10:
	/* 0xd10: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d15:
	/* 0xd15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d17:
	/* 0xd17: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1b:
	/* 0xd1b: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_d21:
	/* 0xd21: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_d28:
	/* 0xd28: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d2d:
	/* 0xd2d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d32:
	/* 0xd32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d37:
	/* 0xd37: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d3a:
	/* 0xd3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3c:
	/* 0xd3c: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d41:
	/* 0xd41: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d44:
	/* 0xd44: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_d4a:
	/* 0xd4a: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_d51:
	/* 0xd51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d56:
	/* 0xd56: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5b:
	/* 0xd5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d60:
	/* 0xd60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d62:
	/* 0xd62: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d66:
	/* 0xd66: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3986ULL;
	}
x86_l_d6c:
	/* 0xd6c: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_d73:
	/* 0xd73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d78:
	/* 0xd78: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7d:
	/* 0xd7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d82:
	/* 0xd82: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d85:
	/* 0xd85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d87:
	/* 0xd87: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8c:
	/* 0xd8c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d8f:
	/* 0xd8f: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3983ULL;
	}
x86_l_d95:
	/* 0xd95: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_d9c:
	/* 0xd9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_da1:
	/* 0xda1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da6:
	/* 0xda6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 3499ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3499ULL: goto x86_l_dab;
	case 3501ULL: goto x86_l_dad;
	case 3505ULL: goto x86_l_db1;
	case 3511ULL: goto x86_l_db7;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3533ULL: goto x86_l_dcd;
	case 3536ULL: goto x86_l_dd0;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3546ULL: goto x86_l_dda;
	case 3552ULL: goto x86_l_de0;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3574ULL: goto x86_l_df6;
	case 3576ULL: goto x86_l_df8;
	case 3580ULL: goto x86_l_dfc;
	case 3586ULL: goto x86_l_e02;
	case 3593ULL: goto x86_l_e09;
	case 3598ULL: goto x86_l_e0e;
	case 3603ULL: goto x86_l_e13;
	case 3608ULL: goto x86_l_e18;
	case 3611ULL: goto x86_l_e1b;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3621ULL: goto x86_l_e25;
	case 3627ULL: goto x86_l_e2b;
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3651ULL: goto x86_l_e43;
	case 3655ULL: goto x86_l_e47;
	case 3661ULL: goto x86_l_e4d;
	case 3668ULL: goto x86_l_e54;
	case 3673ULL: goto x86_l_e59;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3686ULL: goto x86_l_e66;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3702ULL: goto x86_l_e76;
	case 3709ULL: goto x86_l_e7d;
	case 3714ULL: goto x86_l_e82;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3726ULL: goto x86_l_e8e;
	case 3730ULL: goto x86_l_e92;
	case 3736ULL: goto x86_l_e98;
	case 3743ULL: goto x86_l_e9f;
	case 3748ULL: goto x86_l_ea4;
	case 3753ULL: goto x86_l_ea9;
	case 3758ULL: goto x86_l_eae;
	case 3761ULL: goto x86_l_eb1;
	case 3763ULL: goto x86_l_eb3;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3777ULL: goto x86_l_ec1;
	case 3784ULL: goto x86_l_ec8;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3801ULL: goto x86_l_ed9;
	case 3805ULL: goto x86_l_edd;
	case 3811ULL: goto x86_l_ee3;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3836ULL: goto x86_l_efc;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3846ULL: goto x86_l_f06;
	case 3852ULL: goto x86_l_f0c;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3876ULL: goto x86_l_f24;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3907ULL: goto x86_l_f43;
	case 3909ULL: goto x86_l_f45;
	case 3914ULL: goto x86_l_f4a;
	case 3917ULL: goto x86_l_f4d;
	case 3919ULL: goto x86_l_f4f;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3941ULL: goto x86_l_f65;
	case 3943ULL: goto x86_l_f67;
	case 3947ULL: goto x86_l_f6b;
	case 3949ULL: goto x86_l_f6d;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3971ULL: goto x86_l_f83;
	case 3974ULL: goto x86_l_f86;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3983ULL: goto x86_l_f8f;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3992ULL: goto x86_l_f98;
	case 3996ULL: goto x86_l_f9c;
	case 4003ULL: goto x86_l_fa3;
	case 4008ULL: goto x86_l_fa8;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4024ULL: goto x86_l_fb8;
	case 4026ULL: goto x86_l_fba;
	case 4034ULL: goto x86_l_fc2;
	case 4037ULL: goto x86_l_fc5;
	case 4043ULL: goto x86_l_fcb;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4066ULL: goto x86_l_fe2;
	case 4074ULL: goto x86_l_fea;
	case 4076ULL: goto x86_l_fec;
	case 4079ULL: goto x86_l_fef;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4092ULL: goto x86_l_ffc;
	case 4100ULL: goto x86_l_1004;
	case 4107ULL: goto x86_l_100b;
	case 4112ULL: goto x86_l_1010;
	case 4117ULL: goto x86_l_1015;
	case 4119ULL: goto x86_l_1017;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4139ULL: goto x86_l_102b;
	case 4144ULL: goto x86_l_1030;
	case 4146ULL: goto x86_l_1032;
	case 4154ULL: goto x86_l_103a;
	case 4158ULL: goto x86_l_103e;
	case 4166ULL: goto x86_l_1046;
	case 4170ULL: goto x86_l_104a;
	case 4175ULL: goto x86_l_104f;
	case 4183ULL: goto x86_l_1057;
	case 4188ULL: goto x86_l_105c;
	case 4191ULL: goto x86_l_105f;
	case 4193ULL: goto x86_l_1061;
	case 4201ULL: goto x86_l_1069;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4222ULL: goto x86_l_107e;
	case 4228ULL: goto x86_l_1084;
	case 4233ULL: goto x86_l_1089;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4274ULL: goto x86_l_10b2;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4291ULL: goto x86_l_10c3;
	case 4293ULL: goto x86_l_10c5;
	case 4296ULL: goto x86_l_10c8;
	case 4303ULL: goto x86_l_10cf;
	case 4313ULL: goto x86_l_10d9;
	case 4320ULL: goto x86_l_10e0;
	case 4329ULL: goto x86_l_10e9;
	case 4334ULL: goto x86_l_10ee;
	case 4343ULL: goto x86_l_10f7;
	case 4352ULL: goto x86_l_1100;
	case 4357ULL: goto x86_l_1105;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4376ULL: goto x86_l_1118;
	case 4385ULL: goto x86_l_1121;
	case 4394ULL: goto x86_l_112a;
	case 4399ULL: goto x86_l_112f;
	case 4404ULL: goto x86_l_1134;
	case 4408ULL: goto x86_l_1138;
	case 4413ULL: goto x86_l_113d;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4435ULL: goto x86_l_1153;
	case 4437ULL: goto x86_l_1155;
	case 4442ULL: goto x86_l_115a;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4458ULL: goto x86_l_116a;
	case 4460ULL: goto x86_l_116c;
	case 4465ULL: goto x86_l_1171;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4476ULL: goto x86_l_117c;
	case 4478ULL: goto x86_l_117e;
	case 4483ULL: goto x86_l_1183;
	case 4488ULL: goto x86_l_1188;
	case 4493ULL: goto x86_l_118d;
	case 4501ULL: goto x86_l_1195;
	case 4503ULL: goto x86_l_1197;
	case 4508ULL: goto x86_l_119c;
	case 4512ULL: goto x86_l_11a0;
	case 4517ULL: goto x86_l_11a5;
	case 4524ULL: goto x86_l_11ac;
	case 4527ULL: goto x86_l_11af;
	case 4533ULL: goto x86_l_11b5;
	case 4538ULL: goto x86_l_11ba;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4558ULL: goto x86_l_11ce;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4586ULL: goto x86_l_11ea;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4599ULL: goto x86_l_11f7;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4621ULL: goto x86_l_120d;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4634ULL: goto x86_l_121a;
	case 4639ULL: goto x86_l_121f;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4652ULL: goto x86_l_122c;
	case 4654ULL: goto x86_l_122e;
	case 4658ULL: goto x86_l_1232;
	case 4663ULL: goto x86_l_1237;
	case 4668ULL: goto x86_l_123c;
	case 4673ULL: goto x86_l_1241;
	case 4676ULL: goto x86_l_1244;
	case 4678ULL: goto x86_l_1246;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4692ULL: goto x86_l_1254;
	case 4695ULL: goto x86_l_1257;
	case 4699ULL: goto x86_l_125b;
	case 4701ULL: goto x86_l_125d;
	case 4703ULL: goto x86_l_125f;
	case 4708ULL: goto x86_l_1264;
	case 4711ULL: goto x86_l_1267;
	case 4716ULL: goto x86_l_126c;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4725ULL: goto x86_l_1275;
	case 4727ULL: goto x86_l_1277;
	case 4730ULL: goto x86_l_127a;
	case 4733ULL: goto x86_l_127d;
	case 4736ULL: goto x86_l_1280;
	case 4739ULL: goto x86_l_1283;
	case 4744ULL: goto x86_l_1288;
	case 4747ULL: goto x86_l_128b;
	case 4753ULL: goto x86_l_1291;
	case 4759ULL: goto x86_l_1297;
	case 4765ULL: goto x86_l_129d;
	case 4767ULL: goto x86_l_129f;
	case 4773ULL: goto x86_l_12a5;
	case 4777ULL: goto x86_l_12a9;
	case 4782ULL: goto x86_l_12ae;
	case 4786ULL: goto x86_l_12b2;
	case 4790ULL: goto x86_l_12b6;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4815ULL: goto x86_l_12cf;
	case 4817ULL: goto x86_l_12d1;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4832ULL: goto x86_l_12e0;
	case 4837ULL: goto x86_l_12e5;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4859ULL: goto x86_l_12fb;
	case 4861ULL: goto x86_l_12fd;
	case 4865ULL: goto x86_l_1301;
	case 4870ULL: goto x86_l_1306;
	case 4875ULL: goto x86_l_130b;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4885ULL: goto x86_l_1315;
	case 4890ULL: goto x86_l_131a;
	case 4895ULL: goto x86_l_131f;
	case 4899ULL: goto x86_l_1323;
	case 4904ULL: goto x86_l_1328;
	case 4906ULL: goto x86_l_132a;
	case 4912ULL: goto x86_l_1330;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4938ULL: goto x86_l_134a;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4953ULL: goto x86_l_1359;
	case 4955ULL: goto x86_l_135b;
	case 4957ULL: goto x86_l_135d;
	case 4962ULL: goto x86_l_1362;
	case 4967ULL: goto x86_l_1367;
	case 4972ULL: goto x86_l_136c;
	case 4975ULL: goto x86_l_136f;
	case 4977ULL: goto x86_l_1371;
	case 4979ULL: goto x86_l_1373;
	case 4984ULL: goto x86_l_1378;
	case 4987ULL: goto x86_l_137b;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 4998ULL: goto x86_l_1386;
	case 5000ULL: goto x86_l_1388;
	case 5003ULL: goto x86_l_138b;
	case 5006ULL: goto x86_l_138e;
	case 5008ULL: goto x86_l_1390;
	case 5010ULL: goto x86_l_1392;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5017ULL: goto x86_l_1399;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5028ULL: goto x86_l_13a4;
	case 5031ULL: goto x86_l_13a7;
	case 5036ULL: goto x86_l_13ac;
	case 5039ULL: goto x86_l_13af;
	case 5041ULL: goto x86_l_13b1;
	case 5046ULL: goto x86_l_13b6;
	case 5051ULL: goto x86_l_13bb;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5061ULL: goto x86_l_13c5;
	case 5063ULL: goto x86_l_13c7;
	case 5065ULL: goto x86_l_13c9;
	case 5072ULL: goto x86_l_13d0;
	case 5078ULL: goto x86_l_13d6;
	case 5086ULL: goto x86_l_13de;
	case 5091ULL: goto x86_l_13e3;
	case 5094ULL: goto x86_l_13e6;
	case 5096ULL: goto x86_l_13e8;
	case 5098ULL: goto x86_l_13ea;
	case 5105ULL: goto x86_l_13f1;
	case 5107ULL: goto x86_l_13f3;
	case 5113ULL: goto x86_l_13f9;
	case 5115ULL: goto x86_l_13fb;
	case 5118ULL: goto x86_l_13fe;
	case 5120ULL: goto x86_l_1400;
	case 5125ULL: goto x86_l_1405;
	case 5127ULL: goto x86_l_1407;
	case 5130ULL: goto x86_l_140a;
	case 5135ULL: goto x86_l_140f;
	case 5142ULL: goto x86_l_1416;
	case 5150ULL: goto x86_l_141e;
	case 5158ULL: goto x86_l_1426;
	case 5161ULL: goto x86_l_1429;
	case 5164ULL: goto x86_l_142c;
	case 5167ULL: goto x86_l_142f;
	case 5176ULL: goto x86_l_1438;
	case 5183ULL: goto x86_l_143f;
	case 5186ULL: goto x86_l_1442;
	case 5189ULL: goto x86_l_1445;
	case 5195ULL: goto x86_l_144b;
	case 5202ULL: goto x86_l_1452;
	case 5208ULL: goto x86_l_1458;
	case 5213ULL: goto x86_l_145d;
	case 5215ULL: goto x86_l_145f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_dab:
	/* 0xdab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dad:
	/* 0xdad: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db1:
	/* 0xdb1: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f92;
	}
x86_l_db7:
	/* 0xdb7: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_dbe:
	/* 0xdbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dc3:
	/* 0xdc3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dc8:
	/* 0xdc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dcd:
	/* 0xdcd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_dd0:
	/* 0xdd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd2:
	/* 0xdd2: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dd7:
	/* 0xdd7: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_dda:
	/* 0xdda: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_de0:
	/* 0xde0: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_de7:
	/* 0xde7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dec:
	/* 0xdec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df1:
	/* 0xdf1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_df6:
	/* 0xdf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df8:
	/* 0xdf8: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dfc:
	/* 0xdfc: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f92;
	}
x86_l_e02:
	/* 0xe02: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_e09:
	/* 0xe09: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e0e:
	/* 0xe0e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e13:
	/* 0xe13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e18:
	/* 0xe18: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e1b:
	/* 0xe1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e1d:
	/* 0xe1d: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e22:
	/* 0xe22: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_e25:
	/* 0xe25: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_e2b:
	/* 0xe2b: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_e32:
	/* 0xe32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e37:
	/* 0xe37: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3c:
	/* 0xe3c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e41:
	/* 0xe41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e43:
	/* 0xe43: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e47:
	/* 0xe47: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f92;
	}
x86_l_e4d:
	/* 0xe4d: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_e54:
	/* 0xe54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e59:
	/* 0xe59: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e5e:
	/* 0xe5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e63:
	/* 0xe63: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e66:
	/* 0xe66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e68:
	/* 0xe68: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e6d:
	/* 0xe6d: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_e70:
	/* 0xe70: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_e76:
	/* 0xe76: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_e7d:
	/* 0xe7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e82:
	/* 0xe82: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e87:
	/* 0xe87: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e8c:
	/* 0xe8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8e:
	/* 0xe8e: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e92:
	/* 0xe92: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f92;
	}
x86_l_e98:
	/* 0xe98: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_e9f:
	/* 0xe9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea4:
	/* 0xea4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ea9:
	/* 0xea9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eae:
	/* 0xeae: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_eb1:
	/* 0xeb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb3:
	/* 0xeb3: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eb8:
	/* 0xeb8: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_ebb:
	/* 0xebb: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_ec1:
	/* 0xec1: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_ec8:
	/* 0xec8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ecd:
	/* 0xecd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed2:
	/* 0xed2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ed7:
	/* 0xed7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed9:
	/* 0xed9: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_edd:
	/* 0xedd: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f92;
	}
x86_l_ee3:
	/* 0xee3: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_eea:
	/* 0xeea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eef:
	/* 0xeef: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ef4:
	/* 0xef4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ef9:
	/* 0xef9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_efc:
	/* 0xefc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efe:
	/* 0xefe: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f03:
	/* 0xf03: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_f06:
	/* 0xf06: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_f0c:
	/* 0xf0c: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_f13:
	/* 0xf13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f18:
	/* 0xf18: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f1d:
	/* 0xf1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f22:
	/* 0xf22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f24:
	/* 0xf24: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f28:
	/* 0xf28: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f92;
	}
x86_l_f2a:
	/* 0xf2a: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_f31:
	/* 0xf31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f36:
	/* 0xf36: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f3b:
	/* 0xf3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f40:
	/* 0xf40: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f43:
	/* 0xf43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f45:
	/* 0xf45: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f4a:
	/* 0xf4a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_f4d:
	/* 0xf4d: je     f8f <event_execve+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_f4f:
	/* 0xf4f: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_f56:
	/* 0xf56: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f5b:
	/* 0xf5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f60:
	/* 0xf60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f65:
	/* 0xf65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f67:
	/* 0xf67: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6b:
	/* 0xf6b: je     f92 <event_execve+0xf92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f92;
	}
x86_l_f6d:
	/* 0xf6d: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_f74:
	/* 0xf74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f79:
	/* 0xf79: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f7e:
	/* 0xf7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f83:
	/* 0xf83: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f86:
	/* 0xf86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f88:
	/* 0xf88: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8d:
	/* 0xf8d: jmp    f92 <event_execve+0xf92> */
	goto x86_l_f92;
x86_l_f8f:
	/* 0xf8f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f92:
	/* 0xf92: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f94:
	/* 0xf94: cmp    DWORD PTR [rsp+0x8],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f98:
	/* 0xf98: cmovne r13,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_64, X86_CC_NE);
x86_l_f9c:
	/* 0xf9c: add    r13,0xd30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3376ULL);
x86_l_fa3:
	/* 0xfa3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fa8:
	/* 0xfa8: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_fb0:
	/* 0xfb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fb5:
	/* 0xfb5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_fb8:
	/* 0xfb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fba:
	/* 0xfba: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_fc2:
	/* 0xfc2: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_fc5:
	/* 0xfc5: je     1092 <event_execve+0x1092> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1092;
	}
x86_l_fcb:
	/* 0xfcb: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_fd6:
	/* 0xfd6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fdb:
	/* 0xfdb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_fe2:
	/* 0xfe2: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_fea:
	/* 0xfea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fec:
	/* 0xfec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fef:
	/* 0xfef: je     1399 <event_execve+0x1399> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1399;
	}
x86_l_ff5:
	/* 0xff5: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ff8:
	/* 0xff8: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ffc:
	/* 0xffc: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1004:
	/* 0x1004: lea    rax,[rbp+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_100b:
	/* 0x100b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1010:
	/* 0x1010: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1015:
	/* 0x1015: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1017:
	/* 0x1017: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_101e:
	/* 0x101e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1023:
	/* 0x1023: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_102b:
	/* 0x102b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1030:
	/* 0x1030: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1032:
	/* 0x1032: mov    r15,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_103a:
	/* 0x103a: lea    rax,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_103e:
	/* 0x103e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1046:
	/* 0x1046: add    rbx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_104a:
	/* 0x104a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_104f:
	/* 0x104f: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1057:
	/* 0x1057: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_105c:
	/* 0x105c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_105f:
	/* 0x105f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1061:
	/* 0x1061: mov    r13,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1069:
	/* 0x1069: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_106d:
	/* 0x106d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1072:
	/* 0x1072: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1077:
	/* 0x1077: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_107c:
	/* 0x107c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107e:
	/* 0x107e: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1084:
	/* 0x1084: mov    eax,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_1089:
	/* 0x1089: je     109f <event_execve+0x109f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_109f;
	}
x86_l_108b:
	/* 0x108b: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1090:
	/* 0x1090: jmp    10ee <event_execve+0x10ee> */
	goto x86_l_10ee;
x86_l_1092:
	/* 0x1092: or     BYTE PTR [r14+0x15d],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 1498943586336ULL);
x86_l_109a:
	/* 0x109a: jmp    141e <event_execve+0x141e> */
	goto x86_l_141e;
x86_l_109f:
	/* 0x109f: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10a3:
	/* 0x10a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10a8:
	/* 0x10a8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10ad:
	/* 0x10ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b2:
	/* 0x10b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b4:
	/* 0x10b4: mov    eax,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4096ULL);
x86_l_10b9:
	/* 0x10b9: cmp    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10be:
	/* 0x10be: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10c3:
	/* 0x10c3: je     10ee <event_execve+0x10ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10ee;
	}
x86_l_10c5:
	/* 0x10c5: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_10c8:
	/* 0x10c8: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_10cf:
	/* 0x10cf: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_10d9:
	/* 0x10d9: mov    QWORD PTR [rbp+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_10e0:
	/* 0x10e0: mov    WORD PTR [rbp+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_10e9:
	/* 0x10e9: mov    eax,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4086ULL);
x86_l_10ee:
	/* 0x10ee: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_10f7:
	/* 0x10f7: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1100:
	/* 0x1100: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1105:
	/* 0x1105: lea    rbp,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_110a:
	/* 0x110a: lea    r13,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_110f:
	/* 0x110f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1118:
	/* 0x1118: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1121:
	/* 0x1121: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_112a:
	/* 0x112a: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_112f:
	/* 0x112f: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1134:
	/* 0x1134: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1138:
	/* 0x1138: mov    BYTE PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_113d:
	/* 0x113d: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1141:
	/* 0x1141: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1146:
	/* 0x1146: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_114b:
	/* 0x114b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1150:
	/* 0x1150: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1153:
	/* 0x1153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1155:
	/* 0x1155: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_115a:
	/* 0x115a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_115d:
	/* 0x115d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1162:
	/* 0x1162: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_116a:
	/* 0x116a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116c:
	/* 0x116c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1171:
	/* 0x1171: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1174:
	/* 0x1174: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1179:
	/* 0x1179: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_117c:
	/* 0x117c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117e:
	/* 0x117e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1183:
	/* 0x1183: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1188:
	/* 0x1188: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_118d:
	/* 0x118d: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1195:
	/* 0x1195: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1197:
	/* 0x1197: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_119c:
	/* 0x119c: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_11a0:
	/* 0x11a0: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11a5:
	/* 0x11a5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_11ac:
	/* 0x11ac: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11af:
	/* 0x11af: je     1332 <event_execve+0x1332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1332;
	}
x86_l_11b5:
	/* 0x11b5: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_11ba:
	/* 0x11ba: mov    r13,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11bf:
	/* 0x11bf: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11c4:
	/* 0x11c4: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11c9:
	/* 0x11c9: cmp    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_11ce:
	/* 0x11ce: jne    11db <event_execve+0x11db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11db;
	}
x86_l_11d0:
	/* 0x11d0: cmp    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_11d5:
	/* 0x11d5: je     135d <event_execve+0x135d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_135d;
	}
x86_l_11db:
	/* 0x11db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11e0:
	/* 0x11e0: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11e5:
	/* 0x11e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11ea:
	/* 0x11ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ec:
	/* 0x11ec: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_11f1:
	/* 0x11f1: je     12dc <event_execve+0x12dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12dc;
	}
x86_l_11f7:
	/* 0x11f7: lea    rbx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11fb:
	/* 0x11fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1200:
	/* 0x1200: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1205:
	/* 0x1205: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_120a:
	/* 0x120a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_120d:
	/* 0x120d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120f:
	/* 0x120f: cmp    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1214:
	/* 0x1214: je     12dc <event_execve+0x12dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12dc;
	}
x86_l_121a:
	/* 0x121a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_121f:
	/* 0x121f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1224:
	/* 0x1224: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1229:
	/* 0x1229: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_122c:
	/* 0x122c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122e:
	/* 0x122e: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1232:
	/* 0x1232: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1237:
	/* 0x1237: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_123c:
	/* 0x123c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1241:
	/* 0x1241: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1244:
	/* 0x1244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1246:
	/* 0x1246: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_124b:
	/* 0x124b: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1250:
	/* 0x1250: mov    ecx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1254:
	/* 0x1254: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1257:
	/* 0x1257: mov    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_125b:
	/* 0x125b: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_125d:
	/* 0x125d: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_125f:
	/* 0x125f: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_1264:
	/* 0x1264: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1267:
	/* 0x1267: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_126c:
	/* 0x126c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_126f:
	/* 0x126f: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1271:
	/* 0x1271: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_1275:
	/* 0x1275: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_1277:
	/* 0x1277: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_127a:
	/* 0x127a: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_127d:
	/* 0x127d: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_1280:
	/* 0x1280: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1283:
	/* 0x1283: mov    DWORD PTR [rsp+0x58],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1288:
	/* 0x1288: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_128b:
	/* 0x128b: jb     1362 <event_execve+0x1362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1362;
	}
x86_l_1291:
	/* 0x1291: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1297:
	/* 0x1297: ja     1362 <event_execve+0x1362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1362;
	}
x86_l_129d:
	/* 0x129d: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_129f:
	/* 0x129f: jbe    13a0 <event_execve+0x13a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_13a0;
	}
x86_l_12a5:
	/* 0x12a5: lea    rbx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_12a9:
	/* 0x12a9: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_12ae:
	/* 0x12ae: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_12b2:
	/* 0x12b2: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_12b6:
	/* 0x12b6: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_12b9:
	/* 0x12b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12be:
	/* 0x12be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c0:
	/* 0x12c0: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12c5:
	/* 0x12c5: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12ca:
	/* 0x12ca: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12cf:
	/* 0x12cf: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_12d1:
	/* 0x12d1: jne    11ba <event_execve+0x11ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11ba;
	}
x86_l_12d7:
	/* 0x12d7: jmp    1362 <event_execve+0x1362> */
	goto x86_l_1362;
x86_l_12dc:
	/* 0x12dc: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12e0:
	/* 0x12e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12e5:
	/* 0x12e5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12ea:
	/* 0x12ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ef:
	/* 0x12ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f1:
	/* 0x12f1: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_12f6:
	/* 0x12f6: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_12fb:
	/* 0x12fb: je     135d <event_execve+0x135d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_135d;
	}
x86_l_12fd:
	/* 0x12fd: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1301:
	/* 0x1301: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1306:
	/* 0x1306: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_130b:
	/* 0x130b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1310:
	/* 0x1310: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1313:
	/* 0x1313: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1315:
	/* 0x1315: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_131a:
	/* 0x131a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_131f:
	/* 0x131f: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1323:
	/* 0x1323: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1328:
	/* 0x1328: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_132a:
	/* 0x132a: jne    11ba <event_execve+0x11ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11ba;
	}
x86_l_1330:
	/* 0x1330: jmp    1362 <event_execve+0x1362> */
	goto x86_l_1362;
x86_l_1332:
	/* 0x1332: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_1337:
	/* 0x1337: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_133e:
	/* 0x133e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1343:
	/* 0x1343: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_1348:
	/* 0x1348: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134a:
	/* 0x134a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134c:
	/* 0x134c: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1351:
	/* 0x1351: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1356:
	/* 0x1356: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1359:
	/* 0x1359: jne    1371 <event_execve+0x1371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1371;
	}
x86_l_135b:
	/* 0x135b: jmp    13c5 <event_execve+0x13c5> */
	goto x86_l_13c5;
x86_l_135d:
	/* 0x135d: mov    BYTE PTR [rsp+0x5c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991233ULL);
x86_l_1362:
	/* 0x1362: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1367:
	/* 0x1367: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_136c:
	/* 0x136c: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_136f:
	/* 0x136f: je     13c5 <event_execve+0x13c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13c5;
	}
x86_l_1371:
	/* 0x1371: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1373:
	/* 0x1373: cmp    BYTE PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_1378:
	/* 0x1378: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_137b:
	/* 0x137b: mov    edx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_137f:
	/* 0x137f: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_1384:
	/* 0x1384: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1386:
	/* 0x1386: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1388:
	/* 0x1388: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_138b:
	/* 0x138b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_138e:
	/* 0x138e: je     1399 <event_execve+0x1399> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1399;
	}
x86_l_1390:
	/* 0x1390: mov    bl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_8);
x86_l_1392:
	/* 0x1392: add    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1394:
	/* 0x1394: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1397:
	/* 0x1397: jmp    13c9 <event_execve+0x13c9> */
	goto x86_l_13c9;
x86_l_1399:
	/* 0x1399: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_139b:
	/* 0x139b: jmp    141e <event_execve+0x141e> */
	goto x86_l_141e;
x86_l_13a0:
	/* 0x13a0: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_13a4:
	/* 0x13a4: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13a7:
	/* 0x13a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13ac:
	/* 0x13ac: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_13af:
	/* 0x13af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b1:
	/* 0x13b1: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13b6:
	/* 0x13b6: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13bb:
	/* 0x13bb: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13c0:
	/* 0x13c0: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_13c3:
	/* 0x13c3: jne    1371 <event_execve+0x1371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1371;
	}
x86_l_13c5:
	/* 0x13c5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13c7:
	/* 0x13c7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13c9:
	/* 0x13c9: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_13d0:
	/* 0x13d0: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13d6:
	/* 0x13d6: add    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_13de:
	/* 0x13de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13e3:
	/* 0x13e3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_13e6:
	/* 0x13e6: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_13e8:
	/* 0x13e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ea:
	/* 0x13ea: mov    eax,DWORD PTR [r14+0x15c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_13f1:
	/* 0x13f1: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_13f3:
	/* 0x13f3: or     ecx,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 4096ULL);
x86_l_13f9:
	/* 0x13f9: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_13fb:
	/* 0x13fb: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_13fe:
	/* 0x13fe: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1400:
	/* 0x1400: or     eax,0x400000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 4194304ULL);
x86_l_1405:
	/* 0x1405: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_1407:
	/* 0x1407: cmove  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_140a:
	/* 0x140a: and    eax,0xffffdbff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294958079ULL);
x86_l_140f:
	/* 0x140f: mov    DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_1416:
	/* 0x1416: mov    WORD PTR [r14+0x17c],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 380ULL);
x86_l_141e:
	/* 0x141e: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1426:
	/* 0x1426: mov    r12d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1429:
	/* 0x1429: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_142c:
	/* 0x142c: mov    DWORD PTR [rbx],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_142f:
	/* 0x142f: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1438:
	/* 0x1438: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&ENV_VARS_ENABLED)));
x86_l_143f:
	/* 0x143f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1442:
	/* 0x1442: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1445:
	/* 0x1445: je     1605 <event_execve+0x1605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5637ULL;
	}
x86_l_144b:
	/* 0x144b: cmp    r12d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_1452:
	/* 0x1452: ja     1605 <event_execve+0x1605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5637ULL;
	}
x86_l_1458:
	/* 0x1458: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_145d:
	/* 0x145d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145f:
	/* 0x145f: lea    rdx,[rax+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
	return 5222ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5222ULL: goto x86_l_1466;
	case 5227ULL: goto x86_l_146b;
	case 5232ULL: goto x86_l_1470;
	case 5237ULL: goto x86_l_1475;
	case 5239ULL: goto x86_l_1477;
	case 5245ULL: goto x86_l_147d;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5278ULL: goto x86_l_149e;
	case 5281ULL: goto x86_l_14a1;
	case 5283ULL: goto x86_l_14a3;
	case 5285ULL: goto x86_l_14a5;
	case 5290ULL: goto x86_l_14aa;
	case 5297ULL: goto x86_l_14b1;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5317ULL: goto x86_l_14c5;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5334ULL: goto x86_l_14d6;
	case 5336ULL: goto x86_l_14d8;
	case 5338ULL: goto x86_l_14da;
	case 5340ULL: goto x86_l_14dc;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5360ULL: goto x86_l_14f0;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5372ULL: goto x86_l_14fc;
	case 5374ULL: goto x86_l_14fe;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5394ULL: goto x86_l_1512;
	case 5399ULL: goto x86_l_1517;
	case 5401ULL: goto x86_l_1519;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5408ULL: goto x86_l_1520;
	case 5413ULL: goto x86_l_1525;
	case 5420ULL: goto x86_l_152c;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5440ULL: goto x86_l_1540;
	case 5447ULL: goto x86_l_1547;
	case 5452ULL: goto x86_l_154c;
	case 5454ULL: goto x86_l_154e;
	case 5457ULL: goto x86_l_1551;
	case 5463ULL: goto x86_l_1557;
	case 5465ULL: goto x86_l_1559;
	case 5470ULL: goto x86_l_155e;
	case 5473ULL: goto x86_l_1561;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5487ULL: goto x86_l_156f;
	case 5493ULL: goto x86_l_1575;
	case 5496ULL: goto x86_l_1578;
	case 5500ULL: goto x86_l_157c;
	case 5507ULL: goto x86_l_1583;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5520ULL: goto x86_l_1590;
	case 5522ULL: goto x86_l_1592;
	case 5529ULL: goto x86_l_1599;
	case 5532ULL: goto x86_l_159c;
	case 5535ULL: goto x86_l_159f;
	case 5537ULL: goto x86_l_15a1;
	case 5540ULL: goto x86_l_15a4;
	case 5547ULL: goto x86_l_15ab;
	case 5549ULL: goto x86_l_15ad;
	case 5552ULL: goto x86_l_15b0;
	case 5556ULL: goto x86_l_15b4;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5569ULL: goto x86_l_15c1;
	case 5572ULL: goto x86_l_15c4;
	case 5574ULL: goto x86_l_15c6;
	case 5579ULL: goto x86_l_15cb;
	case 5581ULL: goto x86_l_15cd;
	case 5584ULL: goto x86_l_15d0;
	case 5587ULL: goto x86_l_15d3;
	case 5591ULL: goto x86_l_15d7;
	case 5593ULL: goto x86_l_15d9;
	case 5601ULL: goto x86_l_15e1;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5612ULL: goto x86_l_15ec;
	case 5614ULL: goto x86_l_15ee;
	case 5617ULL: goto x86_l_15f1;
	case 5620ULL: goto x86_l_15f4;
	case 5622ULL: goto x86_l_15f6;
	case 5630ULL: goto x86_l_15fe;
	case 5637ULL: goto x86_l_1605;
	case 5644ULL: goto x86_l_160c;
	case 5648ULL: goto x86_l_1610;
	case 5655ULL: goto x86_l_1617;
	case 5661ULL: goto x86_l_161d;
	case 5668ULL: goto x86_l_1624;
	case 5672ULL: goto x86_l_1628;
	case 5680ULL: goto x86_l_1630;
	case 5684ULL: goto x86_l_1634;
	case 5691ULL: goto x86_l_163b;
	case 5699ULL: goto x86_l_1643;
	case 5706ULL: goto x86_l_164a;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5737ULL: goto x86_l_1669;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5747ULL: goto x86_l_1673;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5782ULL: goto x86_l_1696;
	case 5787ULL: goto x86_l_169b;
	case 5792ULL: goto x86_l_16a0;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5810ULL: goto x86_l_16b2;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5831ULL: goto x86_l_16c7;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5852ULL: goto x86_l_16dc;
	case 5857ULL: goto x86_l_16e1;
	case 5859ULL: goto x86_l_16e3;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5887ULL: goto x86_l_16ff;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5904ULL: goto x86_l_1710;
	case 5908ULL: goto x86_l_1714;
	case 5913ULL: goto x86_l_1719;
	case 5915ULL: goto x86_l_171b;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5932ULL: goto x86_l_172c;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5943ULL: goto x86_l_1737;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5964ULL: goto x86_l_174c;
	case 5969ULL: goto x86_l_1751;
	case 5971ULL: goto x86_l_1753;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5990ULL: goto x86_l_1766;
	case 5994ULL: goto x86_l_176a;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6006ULL: goto x86_l_1776;
	case 6013ULL: goto x86_l_177d;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6027ULL: goto x86_l_178b;
	case 6029ULL: goto x86_l_178d;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6041ULL: goto x86_l_1799;
	case 6046ULL: goto x86_l_179e;
	case 6049ULL: goto x86_l_17a1;
	case 6051ULL: goto x86_l_17a3;
	case 6058ULL: goto x86_l_17aa;
	case 6065ULL: goto x86_l_17b1;
	case 6072ULL: goto x86_l_17b8;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6111ULL: goto x86_l_17df;
	case 6116ULL: goto x86_l_17e4;
	case 6118ULL: goto x86_l_17e6;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6143ULL: goto x86_l_17ff;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6172ULL: goto x86_l_181c;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6200ULL: goto x86_l_1838;
	case 6209ULL: goto x86_l_1841;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6233ULL: goto x86_l_1859;
	case 6239ULL: goto x86_l_185f;
	case 6241ULL: goto x86_l_1861;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6263ULL: goto x86_l_1877;
	case 6268ULL: goto x86_l_187c;
	case 6273ULL: goto x86_l_1881;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6285ULL: goto x86_l_188d;
	case 6290ULL: goto x86_l_1892;
	case 6294ULL: goto x86_l_1896;
	case 6297ULL: goto x86_l_1899;
	case 6304ULL: goto x86_l_18a0;
	case 6309ULL: goto x86_l_18a5;
	case 6314ULL: goto x86_l_18aa;
	case 6316ULL: goto x86_l_18ac;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6357ULL: goto x86_l_18d5;
	case 6365ULL: goto x86_l_18dd;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6382ULL: goto x86_l_18ee;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6393ULL: goto x86_l_18f9;
	case 6400ULL: goto x86_l_1900;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6415ULL: goto x86_l_190f;
	case 6420ULL: goto x86_l_1914;
	case 6422ULL: goto x86_l_1916;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6450ULL: goto x86_l_1932;
	case 6457ULL: goto x86_l_1939;
	case 6462ULL: goto x86_l_193e;
	case 6467ULL: goto x86_l_1943;
	case 6471ULL: goto x86_l_1947;
	case 6476ULL: goto x86_l_194c;
	case 6478ULL: goto x86_l_194e;
	case 6485ULL: goto x86_l_1955;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6506ULL: goto x86_l_196a;
	case 6515ULL: goto x86_l_1973;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6532ULL: goto x86_l_1984;
	case 6537ULL: goto x86_l_1989;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6566ULL: goto x86_l_19a6;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6583ULL: goto x86_l_19b7;
	case 6588ULL: goto x86_l_19bc;
	case 6593ULL: goto x86_l_19c1;
	case 6595ULL: goto x86_l_19c3;
	case 6599ULL: goto x86_l_19c7;
	case 6607ULL: goto x86_l_19cf;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6617ULL: goto x86_l_19d9;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6636ULL: goto x86_l_19ec;
	case 6641ULL: goto x86_l_19f1;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6648ULL: goto x86_l_19f8;
	case 6651ULL: goto x86_l_19fb;
	case 6659ULL: goto x86_l_1a03;
	case 6663ULL: goto x86_l_1a07;
	case 6665ULL: goto x86_l_1a09;
	case 6667ULL: goto x86_l_1a0b;
	case 6676ULL: goto x86_l_1a14;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6701ULL: goto x86_l_1a2d;
	case 6703ULL: goto x86_l_1a2f;
	case 6709ULL: goto x86_l_1a35;
	case 6715ULL: goto x86_l_1a3b;
	case 6718ULL: goto x86_l_1a3e;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6761ULL: goto x86_l_1a69;
	case 6766ULL: goto x86_l_1a6e;
	case 6768ULL: goto x86_l_1a70;
	case 6770ULL: goto x86_l_1a72;
	case 6774ULL: goto x86_l_1a76;
	case 6777ULL: goto x86_l_1a79;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6807ULL: goto x86_l_1a97;
	case 6810ULL: goto x86_l_1a9a;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6831ULL: goto x86_l_1aaf;
	case 6837ULL: goto x86_l_1ab5;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6865ULL: goto x86_l_1ad1;
	case 6871ULL: goto x86_l_1ad7;
	case 6877ULL: goto x86_l_1add;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6904ULL: goto x86_l_1af8;
	case 6907ULL: goto x86_l_1afb;
	case 6913ULL: goto x86_l_1b01;
	case 6915ULL: goto x86_l_1b03;
	case 6924ULL: goto x86_l_1b0c;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6946ULL: goto x86_l_1b22;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6962ULL: goto x86_l_1b32;
	case 6965ULL: goto x86_l_1b35;
	case 6971ULL: goto x86_l_1b3b;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6985ULL: goto x86_l_1b49;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1466:
	/* 0x1466: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_146b:
	/* 0x146b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1470:
	/* 0x1470: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1475:
	/* 0x1475: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1477:
	/* 0x1477: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_147d:
	/* 0x147d: je     1605 <event_execve+0x1605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1605;
	}
x86_l_1483:
	/* 0x1483: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1488:
	/* 0x1488: mov    edx,0x198 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 408ULL);
x86_l_148d:
	/* 0x148d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1492:
	/* 0x1492: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1497:
	/* 0x1497: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_149c:
	/* 0x149c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149e:
	/* 0x149e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a1:
	/* 0x14a1: je     14fe <event_execve+0x14fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14fe;
	}
x86_l_14a3:
	/* 0x14a3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_14a5:
	/* 0x14a5: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14aa:
	/* 0x14aa: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_14b1:
	/* 0x14b1: movabs rax,0x40000009a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869338ULL);
x86_l_14bb:
	/* 0x14bb: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14c0:
	/* 0x14c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c5:
	/* 0x14c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_14cc:
	/* 0x14cc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14d1:
	/* 0x14d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d3:
	/* 0x14d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d6:
	/* 0x14d6: je     14dc <event_execve+0x14dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14dc;
	}
x86_l_14d8:
	/* 0x14d8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_14da:
	/* 0x14da: jmp    14fe <event_execve+0x14fe> */
	goto x86_l_14fe;
x86_l_14dc:
	/* 0x14dc: mov    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_14e4:
	/* 0x14e4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14e9:
	/* 0x14e9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_14f0:
	/* 0x14f0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14f5:
	/* 0x14f5: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14fa:
	/* 0x14fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14fc:
	/* 0x14fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fe:
	/* 0x14fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1503:
	/* 0x1503: mov    edx,0x1a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 416ULL);
x86_l_1508:
	/* 0x1508: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_150d:
	/* 0x150d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1512:
	/* 0x1512: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1517:
	/* 0x1517: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1519:
	/* 0x1519: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_151c:
	/* 0x151c: je     1559 <event_execve+0x1559> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1559;
	}
x86_l_151e:
	/* 0x151e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1520:
	/* 0x1520: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1525:
	/* 0x1525: mov    WORD PTR [rsp+0x22],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888073ULL);
x86_l_152c:
	/* 0x152c: movabs rax,0x40000009b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869339ULL);
x86_l_1536:
	/* 0x1536: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_153b:
	/* 0x153b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1540:
	/* 0x1540: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1547:
	/* 0x1547: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_154c:
	/* 0x154c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154e:
	/* 0x154e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1551:
	/* 0x1551: je     1be6 <event_execve+0x1be6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7142ULL;
	}
x86_l_1557:
	/* 0x1557: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1559:
	/* 0x1559: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_155e:
	/* 0x155e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1561:
	/* 0x1561: je     1605 <event_execve+0x1605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1605;
	}
x86_l_1567:
	/* 0x1567: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_156c:
	/* 0x156c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_156f:
	/* 0x156f: je     1605 <event_execve+0x1605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1605;
	}
x86_l_1575:
	/* 0x1575: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1578:
	/* 0x1578: lea    rsi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_157c:
	/* 0x157c: add    rsi,0x140 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 320ULL);
x86_l_1583:
	/* 0x1583: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1586:
	/* 0x1586: sub    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1589:
	/* 0x1589: cmp    r13,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1023ULL);
x86_l_1590:
	/* 0x1590: ja     15d9 <event_execve+0x15d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15d9;
	}
x86_l_1592:
	/* 0x1592: lea    rcx,[r14+0x540] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1344ULL);
x86_l_1599:
	/* 0x1599: sub    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_159c:
	/* 0x159c: cmp    r13,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_159f:
	/* 0x159f: jae    15d9 <event_execve+0x15d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15d9;
	}
x86_l_15a1:
	/* 0x15a1: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_15a4:
	/* 0x15a4: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_15ab:
	/* 0x15ab: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ad:
	/* 0x15ad: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_15b0:
	/* 0x15b0: cmove  r13d,ebx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_32, X86_CC_E);
x86_l_15b4:
	/* 0x15b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15b9:
	/* 0x15b9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15be:
	/* 0x15be: mov    rdi,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_15c1:
	/* 0x15c1: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_15c4:
	/* 0x15c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c6:
	/* 0x15c6: and    eax,0x80000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483648ULL);
x86_l_15cb:
	/* 0x15cb: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_15cd:
	/* 0x15cd: shr    ecx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 28ULL);
x86_l_15d0:
	/* 0x15d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d3:
	/* 0x15d3: cmovne r13d,ebx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_32, X86_CC_NE);
x86_l_15d7:
	/* 0x15d7: jmp    15f6 <event_execve+0x15f6> */
	goto x86_l_15f6;
x86_l_15d9:
	/* 0x15d9: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_15e1:
	/* 0x15e1: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_15e4:
	/* 0x15e4: call   0 <event_execve> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5609ULL);
	return 7469ULL;
x86_l_15e9:
	/* 0x15e9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_15ec:
	/* 0x15ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ee:
	/* 0x15ee: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_15f1:
	/* 0x15f1: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_15f4:
	/* 0x15f4: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15f6:
	/* 0x15f6: mov    WORD PTR [r14+0x17e],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 382ULL);
x86_l_15fe:
	/* 0x15fe: or     DWORD PTR [r14+0x15c],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_1605:
	/* 0x1605: mov    eax,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_160c:
	/* 0x160c: lea    ecx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1610:
	/* 0x1610: mov    DWORD PTR [r14+0x140],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1617:
	/* 0x1617: mov    WORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_161d:
	/* 0x161d: mov    rcx,QWORD PTR [r14+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_1624:
	/* 0x1624: mov    QWORD PTR [r14+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1628:
	/* 0x1628: lea    eax,[rax+r13*1+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 320ULL);
x86_l_1630:
	/* 0x1630: mov    DWORD PTR [r14+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1634:
	/* 0x1634: lea    rbx,[r14+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_163b:
	/* 0x163b: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1643:
	/* 0x1643: lea    rdx,[r13+0xce0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_164a:
	/* 0x164a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_164f:
	/* 0x164f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1654:
	/* 0x1654: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1659:
	/* 0x1659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165b:
	/* 0x165b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1660:
	/* 0x1660: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1665:
	/* 0x1665: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1669:
	/* 0x1669: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_166c:
	/* 0x166c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1671:
	/* 0x1671: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1673:
	/* 0x1673: lea    rdi,[r14+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_167a:
	/* 0x167a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_167f:
	/* 0x167f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1684:
	/* 0x1684: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1688:
	/* 0x1688: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_168d:
	/* 0x168d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168f:
	/* 0x168f: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1696:
	/* 0x1696: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_169b:
	/* 0x169b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16a0:
	/* 0x16a0: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_16a4:
	/* 0x16a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16a9:
	/* 0x16a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ab:
	/* 0x16ab: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_16b2:
	/* 0x16b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b7:
	/* 0x16b7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16bc:
	/* 0x16bc: add    rdx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_16c0:
	/* 0x16c0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16c5:
	/* 0x16c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c7:
	/* 0x16c7: lea    rdi,[r14+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_16ce:
	/* 0x16ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16d3:
	/* 0x16d3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16d8:
	/* 0x16d8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16dc:
	/* 0x16dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16e1:
	/* 0x16e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e3:
	/* 0x16e3: lea    rdi,[r14+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_16ea:
	/* 0x16ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16ef:
	/* 0x16ef: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16f4:
	/* 0x16f4: add    rdx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_16f8:
	/* 0x16f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16fd:
	/* 0x16fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ff:
	/* 0x16ff: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1706:
	/* 0x1706: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_170b:
	/* 0x170b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1710:
	/* 0x1710: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1714:
	/* 0x1714: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1719:
	/* 0x1719: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171b:
	/* 0x171b: lea    rdi,[r14+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1722:
	/* 0x1722: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1727:
	/* 0x1727: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_172c:
	/* 0x172c: add    rdx,0x24 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 36ULL);
x86_l_1730:
	/* 0x1730: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1735:
	/* 0x1735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1737:
	/* 0x1737: lea    rdi,[r14+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_173e:
	/* 0x173e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1743:
	/* 0x1743: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1748:
	/* 0x1748: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_174c:
	/* 0x174c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1751:
	/* 0x1751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1753:
	/* 0x1753: lea    r15,[r14+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_175a:
	/* 0x175a: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_175f:
	/* 0x175f: lea    rdi,[r14+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1766:
	/* 0x1766: lea    rdx,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_176a:
	/* 0x176a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_176f:
	/* 0x176f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1774:
	/* 0x1774: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1776:
	/* 0x1776: lea    rdi,[r14+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_177d:
	/* 0x177d: lea    rdx,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1781:
	/* 0x1781: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1786:
	/* 0x1786: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_178b:
	/* 0x178b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178d:
	/* 0x178d: add    rbx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1791:
	/* 0x1791: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1796:
	/* 0x1796: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1799:
	/* 0x1799: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_179e:
	/* 0x179e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_17a1:
	/* 0x17a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a3:
	/* 0x17a3: mov    eax,DWORD PTR [r14+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_17aa:
	/* 0x17aa: mov    DWORD PTR [r14+0x154],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 340ULL);
x86_l_17b1:
	/* 0x17b1: lea    rbx,[r14+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_17b8:
	/* 0x17b8: lea    rdx,[r13+0xd48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_17bf:
	/* 0x17bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c4:
	/* 0x17c4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17c9:
	/* 0x17c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17ce:
	/* 0x17ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d0:
	/* 0x17d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d5:
	/* 0x17d5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17da:
	/* 0x17da: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17df:
	/* 0x17df: mov    esi,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 72ULL);
x86_l_17e4:
	/* 0x17e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e6:
	/* 0x17e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17eb:
	/* 0x17eb: mov    edx,0x1a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 424ULL);
x86_l_17f0:
	/* 0x17f0: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_17f5:
	/* 0x17f5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17f8:
	/* 0x17f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17fd:
	/* 0x17fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ff:
	/* 0x17ff: lea    rdi,[r14+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_1806:
	/* 0x1806: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_180b:
	/* 0x180b: mov    edx,0x470 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1136ULL);
x86_l_1810:
	/* 0x1810: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1815:
	/* 0x1815: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_181a:
	/* 0x181a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181c:
	/* 0x181c: lea    rdi,[r14+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1823:
	/* 0x1823: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1828:
	/* 0x1828: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_182d:
	/* 0x182d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1831:
	/* 0x1831: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1836:
	/* 0x1836: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1838:
	/* 0x1838: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1841:
	/* 0x1841: lea    rdx,[r13+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_1848:
	/* 0x1848: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_184d:
	/* 0x184d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1852:
	/* 0x1852: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1857:
	/* 0x1857: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1859:
	/* 0x1859: cmp    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_185f:
	/* 0x185f: je     18ca <event_execve+0x18ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ca;
	}
x86_l_1861:
	/* 0x1861: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1869:
	/* 0x1869: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_186e:
	/* 0x186e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1873:
	/* 0x1873: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1877:
	/* 0x1877: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_187c:
	/* 0x187c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1881:
	/* 0x1881: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1883:
	/* 0x1883: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1888:
	/* 0x1888: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_188d:
	/* 0x188d: movsxd rdx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 112ULL);
x86_l_1892:
	/* 0x1892: shl    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1896:
	/* 0x1896: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1899:
	/* 0x1899: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_18a0:
	/* 0x18a0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18a5:
	/* 0x18a5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_18aa:
	/* 0x18aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ac:
	/* 0x18ac: lea    rdi,[r14+0x114] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 276ULL);
x86_l_18b3:
	/* 0x18b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b8:
	/* 0x18b8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18bd:
	/* 0x18bd: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_18c1:
	/* 0x18c1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18c6:
	/* 0x18c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c8:
	/* 0x18c8: jmp    18d5 <event_execve+0x18d5> */
	goto x86_l_18d5;
x86_l_18ca:
	/* 0x18ca: mov    DWORD PTR [r14+0x114],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_18d5:
	/* 0x18d5: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18dd:
	/* 0x18dd: lea    rdi,[r14+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_18e4:
	/* 0x18e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e9:
	/* 0x18e9: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18ee:
	/* 0x18ee: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_18f2:
	/* 0x18f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18f7:
	/* 0x18f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f9:
	/* 0x18f9: lea    rdi,[r14+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_1900:
	/* 0x1900: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1905:
	/* 0x1905: mov    edx,0xa8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 168ULL);
x86_l_190a:
	/* 0x190a: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_190f:
	/* 0x190f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1914:
	/* 0x1914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1916:
	/* 0x1916: lea    rdi,[r14+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_191d:
	/* 0x191d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1922:
	/* 0x1922: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1927:
	/* 0x1927: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_192b:
	/* 0x192b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1930:
	/* 0x1930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1932:
	/* 0x1932: lea    rdi,[r14+0x124] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292ULL);
x86_l_1939:
	/* 0x1939: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_193e:
	/* 0x193e: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1943:
	/* 0x1943: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1947:
	/* 0x1947: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_194c:
	/* 0x194c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194e:
	/* 0x194e: lea    rdi,[r14+0x128] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1955:
	/* 0x1955: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_195a:
	/* 0x195a: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_195f:
	/* 0x195f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1963:
	/* 0x1963: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1968:
	/* 0x1968: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196a:
	/* 0x196a: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1973:
	/* 0x1973: lea    rdx,[r13+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_197a:
	/* 0x197a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_197f:
	/* 0x197f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1984:
	/* 0x1984: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1989:
	/* 0x1989: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_198b:
	/* 0x198b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1990:
	/* 0x1990: mov    edx,0x4a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1184ULL);
x86_l_1995:
	/* 0x1995: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_199a:
	/* 0x199a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_199f:
	/* 0x199f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19a4:
	/* 0x19a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a6:
	/* 0x19a6: lea    rdi,[r14+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_19ad:
	/* 0x19ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b2:
	/* 0x19b2: mov    edx,0xe8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 232ULL);
x86_l_19b7:
	/* 0x19b7: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_19bc:
	/* 0x19bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19c1:
	/* 0x19c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c3:
	/* 0x19c3: lea    r12,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19c7:
	/* 0x19c7: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_19cf:
	/* 0x19cf: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d1:
	/* 0x19d1: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_19d6:
	/* 0x19d6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19d9:
	/* 0x19d9: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19db:
	/* 0x19db: call   19e0 <event_execve+0x19e0> */
	X86_SIM_L_EXEC_CALL_MEMSET(144ULL);
x86_l_19e0:
	/* 0x19e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19e5:
	/* 0x19e5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_19ec:
	/* 0x19ec: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19f1:
	/* 0x19f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f3:
	/* 0x19f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19f6:
	/* 0x19f6: je     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a09;
	}
x86_l_19f8:
	/* 0x19f8: mov    ebx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fb:
	/* 0x19fb: cmp    QWORD PTR [rax+0x20],0x63677270 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 139106677360ULL);
x86_l_1a03:
	/* 0x1a03: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_1a07:
	/* 0x1a07: jmp    1a0b <event_execve+0x1a0b> */
	goto x86_l_1a0b;
x86_l_1a09:
	/* 0x1a09: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0b:
	/* 0x1a0b: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1a14:
	/* 0x1a14: add    r13,0xf60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3936ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a20:
	/* 0x1a20: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a25:
	/* 0x1a25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1a2d:
	/* 0x1a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2f:
	/* 0x1a2f: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1a35:
	/* 0x1a35: je     1c2e <event_execve+0x1c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7214ULL;
	}
x86_l_1a3b:
	/* 0x1a3b: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1a3e:
	/* 0x1a3e: je     1aac <event_execve+0x1aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aac;
	}
x86_l_1a40:
	/* 0x1a40: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a45:
	/* 0x1a45: mov    edx,0x88 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 136ULL);
x86_l_1a4a:
	/* 0x1a4a: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a4f:
	/* 0x1a4f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a54:
	/* 0x1a54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a59:
	/* 0x1a59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5b:
	/* 0x1a5b: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a60:
	/* 0x1a60: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1a63:
	/* 0x1a63: je     1c2e <event_execve+0x1c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7214ULL;
	}
x86_l_1a69:
	/* 0x1a69: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_1a6e:
	/* 0x1a6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a70:
	/* 0x1a70: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a72:
	/* 0x1a72: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a76:
	/* 0x1a76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a79:
	/* 0x1a79: je     1b62 <event_execve+0x1b62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7010ULL;
	}
x86_l_1a7f:
	/* 0x1a7f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a84:
	/* 0x1a84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a89:
	/* 0x1a89: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgtracker_map)));
x86_l_1a90:
	/* 0x1a90: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a95:
	/* 0x1a95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a97:
	/* 0x1a97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a9a:
	/* 0x1a9a: je     1b6a <event_execve+0x1b6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7018ULL;
	}
x86_l_1aa0:
	/* 0x1aa0: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aa7:
	/* 0x1aa7: jmp    1b70 <event_execve+0x1b70> */
	return 7024ULL;
x86_l_1aac:
	/* 0x1aac: cmp    ebx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 11ULL);
x86_l_1aaf:
	/* 0x1aaf: ja     1c2e <event_execve+0x1c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7214ULL;
	}
x86_l_1ab5:
	/* 0x1ab5: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_1ab7:
	/* 0x1ab7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1abc:
	/* 0x1abc: shl    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 3ULL);
x86_l_1ac0:
	/* 0x1ac0: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ac5:
	/* 0x1ac5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1aca:
	/* 0x1aca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1acf:
	/* 0x1acf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad1:
	/* 0x1ad1: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ad7:
	/* 0x1ad7: je     1c1b <event_execve+0x1c1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7195ULL;
	}
x86_l_1add:
	/* 0x1add: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae7:
	/* 0x1ae7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aec:
	/* 0x1aec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1af1:
	/* 0x1af1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af3:
	/* 0x1af3: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1af8:
	/* 0x1af8: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1afb:
	/* 0x1afb: je     1c2e <event_execve+0x1c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7214ULL;
	}
x86_l_1b01:
	/* 0x1b01: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b03:
	/* 0x1b03: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b0c:
	/* 0x1b0c: lea    rdx,[rbx+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1b13:
	/* 0x1b13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b18:
	/* 0x1b18: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b22:
	/* 0x1b22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b24:
	/* 0x1b24: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b29:
	/* 0x1b29: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b32:
	/* 0x1b32: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1b35:
	/* 0x1b35: je     1bd2 <event_execve+0x1bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7122ULL;
	}
x86_l_1b3b:
	/* 0x1b3b: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b44:
	/* 0x1b44: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b49:
	/* 0x1b49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 6990ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6990ULL: goto x86_l_1b4e;
	case 6992ULL: goto x86_l_1b50;
	case 6997ULL: goto x86_l_1b55;
	case 7001ULL: goto x86_l_1b59;
	case 7004ULL: goto x86_l_1b5c;
	case 7010ULL: goto x86_l_1b62;
	case 7016ULL: goto x86_l_1b68;
	case 7018ULL: goto x86_l_1b6a;
	case 7020ULL: goto x86_l_1b6c;
	case 7024ULL: goto x86_l_1b70;
	case 7031ULL: goto x86_l_1b77;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7049ULL: goto x86_l_1b89;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7065ULL: goto x86_l_1b99;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7077ULL: goto x86_l_1ba5;
	case 7082ULL: goto x86_l_1baa;
	case 7085ULL: goto x86_l_1bad;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7097ULL: goto x86_l_1bb9;
	case 7100ULL: goto x86_l_1bbc;
	case 7104ULL: goto x86_l_1bc0;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7116ULL: goto x86_l_1bcc;
	case 7118ULL: goto x86_l_1bce;
	case 7120ULL: goto x86_l_1bd0;
	case 7122ULL: goto x86_l_1bd2;
	case 7124ULL: goto x86_l_1bd4;
	case 7128ULL: goto x86_l_1bd8;
	case 7131ULL: goto x86_l_1bdb;
	case 7137ULL: goto x86_l_1be1;
	case 7142ULL: goto x86_l_1be6;
	case 7150ULL: goto x86_l_1bee;
	case 7155ULL: goto x86_l_1bf3;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7174ULL: goto x86_l_1c06;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7184ULL: goto x86_l_1c10;
	case 7190ULL: goto x86_l_1c16;
	case 7195ULL: goto x86_l_1c1b;
	case 7200ULL: goto x86_l_1c20;
	case 7205ULL: goto x86_l_1c25;
	case 7208ULL: goto x86_l_1c28;
	case 7214ULL: goto x86_l_1c2e;
	case 7216ULL: goto x86_l_1c30;
	case 7223ULL: goto x86_l_1c37;
	case 7234ULL: goto x86_l_1c42;
	case 7245ULL: goto x86_l_1c4d;
	case 7250ULL: goto x86_l_1c52;
	case 7257ULL: goto x86_l_1c59;
	case 7260ULL: goto x86_l_1c5c;
	case 7262ULL: goto x86_l_1c5e;
	case 7264ULL: goto x86_l_1c60;
	case 7266ULL: goto x86_l_1c62;
	case 7273ULL: goto x86_l_1c69;
	case 7275ULL: goto x86_l_1c6b;
	case 7276ULL: goto x86_l_1c6c;
	case 7281ULL: goto x86_l_1c71;
	case 7283ULL: goto x86_l_1c73;
	case 7285ULL: goto x86_l_1c75;
	case 7287ULL: goto x86_l_1c77;
	case 7289ULL: goto x86_l_1c79;
	case 7290ULL: goto x86_l_1c7a;
	case 7294ULL: goto x86_l_1c7e;
	case 7297ULL: goto x86_l_1c81;
	case 7300ULL: goto x86_l_1c84;
	case 7303ULL: goto x86_l_1c87;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7333ULL: goto x86_l_1ca5;
	case 7335ULL: goto x86_l_1ca7;
	case 7338ULL: goto x86_l_1caa;
	case 7344ULL: goto x86_l_1cb0;
	case 7349ULL: goto x86_l_1cb5;
	case 7351ULL: goto x86_l_1cb7;
	case 7354ULL: goto x86_l_1cba;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7367ULL: goto x86_l_1cc7;
	case 7369ULL: goto x86_l_1cc9;
	case 7373ULL: goto x86_l_1ccd;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7384ULL: goto x86_l_1cd8;
	case 7389ULL: goto x86_l_1cdd;
	case 7393ULL: goto x86_l_1ce1;
	case 7397ULL: goto x86_l_1ce5;
	case 7401ULL: goto x86_l_1ce9;
	case 7405ULL: goto x86_l_1ced;
	case 7408ULL: goto x86_l_1cf0;
	case 7411ULL: goto x86_l_1cf3;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7421ULL: goto x86_l_1cfd;
	case 7424ULL: goto x86_l_1d00;
	case 7426ULL: goto x86_l_1d02;
	case 7428ULL: goto x86_l_1d04;
	case 7430ULL: goto x86_l_1d06;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7451ULL: goto x86_l_1d1b;
	case 7453ULL: goto x86_l_1d1d;
	case 7455ULL: goto x86_l_1d1f;
	case 7459ULL: goto x86_l_1d23;
	case 7460ULL: goto x86_l_1d24;
	case 7462ULL: goto x86_l_1d26;
	case 7464ULL: goto x86_l_1d28;
	case 7466ULL: goto x86_l_1d2a;
	case 7468ULL: goto x86_l_1d2c;
	case 7469ULL: goto x86_l_1d2d;
	case 7470ULL: goto x86_l_1d2e;
	case 7472ULL: goto x86_l_1d30;
	case 7474ULL: goto x86_l_1d32;
	case 7476ULL: goto x86_l_1d34;
	case 7478ULL: goto x86_l_1d36;
	case 7479ULL: goto x86_l_1d37;
	case 7480ULL: goto x86_l_1d38;
	case 7483ULL: goto x86_l_1d3b;
	case 7486ULL: goto x86_l_1d3e;
	case 7489ULL: goto x86_l_1d41;
	case 7492ULL: goto x86_l_1d44;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7512ULL: goto x86_l_1d58;
	case 7517ULL: goto x86_l_1d5d;
	case 7519ULL: goto x86_l_1d5f;
	case 7522ULL: goto x86_l_1d62;
	case 7524ULL: goto x86_l_1d64;
	case 7527ULL: goto x86_l_1d67;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7540ULL: goto x86_l_1d74;
	case 7543ULL: goto x86_l_1d77;
	case 7547ULL: goto x86_l_1d7b;
	case 7551ULL: goto x86_l_1d7f;
	case 7555ULL: goto x86_l_1d83;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7573ULL: goto x86_l_1d95;
	case 7577ULL: goto x86_l_1d99;
	case 7581ULL: goto x86_l_1d9d;
	case 7585ULL: goto x86_l_1da1;
	case 7589ULL: goto x86_l_1da5;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7599ULL: goto x86_l_1daf;
	case 7602ULL: goto x86_l_1db2;
	case 7605ULL: goto x86_l_1db5;
	case 7610ULL: goto x86_l_1dba;
	case 7612ULL: goto x86_l_1dbc;
	case 7614ULL: goto x86_l_1dbe;
	case 7621ULL: goto x86_l_1dc5;
	case 7624ULL: goto x86_l_1dc8;
	case 7626ULL: goto x86_l_1dca;
	case 7628ULL: goto x86_l_1dcc;
	case 7632ULL: goto x86_l_1dd0;
	case 7635ULL: goto x86_l_1dd3;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	case 7641ULL: goto x86_l_1dd9;
	case 7643ULL: goto x86_l_1ddb;
	case 7650ULL: goto x86_l_1de2;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7657ULL: goto x86_l_1de9;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7669ULL: goto x86_l_1df5;
	case 7670ULL: goto x86_l_1df6;
	case 7672ULL: goto x86_l_1df8;
	case 7674ULL: goto x86_l_1dfa;
	case 7676ULL: goto x86_l_1dfc;
	case 7678ULL: goto x86_l_1dfe;
	case 7679ULL: goto x86_l_1dff;
	case 7680ULL: goto x86_l_1e00;
	case 7682ULL: goto x86_l_1e02;
	case 7684ULL: goto x86_l_1e04;
	case 7686ULL: goto x86_l_1e06;
	case 7687ULL: goto x86_l_1e07;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7698ULL: goto x86_l_1e12;
	case 7702ULL: goto x86_l_1e16;
	case 7706ULL: goto x86_l_1e1a;
	case 7709ULL: goto x86_l_1e1d;
	case 7711ULL: goto x86_l_1e1f;
	case 7715ULL: goto x86_l_1e23;
	case 7721ULL: goto x86_l_1e29;
	case 7726ULL: goto x86_l_1e2e;
	case 7731ULL: goto x86_l_1e33;
	case 7736ULL: goto x86_l_1e38;
	case 7738ULL: goto x86_l_1e3a;
	case 7743ULL: goto x86_l_1e3f;
	case 7749ULL: goto x86_l_1e45;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7771ULL: goto x86_l_1e5b;
	case 7773ULL: goto x86_l_1e5d;
	case 7778ULL: goto x86_l_1e62;
	case 7784ULL: goto x86_l_1e68;
	case 7789ULL: goto x86_l_1e6d;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7802ULL: goto x86_l_1e7a;
	case 7804ULL: goto x86_l_1e7c;
	case 7808ULL: goto x86_l_1e80;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7828ULL: goto x86_l_1e94;
	case 7832ULL: goto x86_l_1e98;
	case 7836ULL: goto x86_l_1e9c;
	case 7840ULL: goto x86_l_1ea0;
	case 7843ULL: goto x86_l_1ea3;
	case 7846ULL: goto x86_l_1ea6;
	case 7848ULL: goto x86_l_1ea8;
	case 7850ULL: goto x86_l_1eaa;
	case 7852ULL: goto x86_l_1eac;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7869ULL: goto x86_l_1ebd;
	case 7872ULL: goto x86_l_1ec0;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7881ULL: goto x86_l_1ec9;
	case 7884ULL: goto x86_l_1ecc;
	case 7887ULL: goto x86_l_1ecf;
	case 7892ULL: goto x86_l_1ed4;
	case 7895ULL: goto x86_l_1ed7;
	case 7901ULL: goto x86_l_1edd;
	case 7908ULL: goto x86_l_1ee4;
	case 7914ULL: goto x86_l_1eea;
	case 7916ULL: goto x86_l_1eec;
	case 7922ULL: goto x86_l_1ef2;
	case 7926ULL: goto x86_l_1ef6;
	case 7931ULL: goto x86_l_1efb;
	case 7935ULL: goto x86_l_1eff;
	case 7939ULL: goto x86_l_1f03;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7949ULL: goto x86_l_1f0d;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7962ULL: goto x86_l_1f1a;
	case 7964ULL: goto x86_l_1f1c;
	case 7966ULL: goto x86_l_1f1e;
	case 7970ULL: goto x86_l_1f22;
	case 7975ULL: goto x86_l_1f27;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7987ULL: goto x86_l_1f33;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 7998ULL: goto x86_l_1f3e;
	case 8002ULL: goto x86_l_1f42;
	case 8006ULL: goto x86_l_1f46;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8019ULL: goto x86_l_1f53;
	case 8021ULL: goto x86_l_1f55;
	case 8026ULL: goto x86_l_1f5a;
	case 8030ULL: goto x86_l_1f5e;
	case 8034ULL: goto x86_l_1f62;
	case 8038ULL: goto x86_l_1f66;
	case 8040ULL: goto x86_l_1f68;
	case 8042ULL: goto x86_l_1f6a;
	case 8046ULL: goto x86_l_1f6e;
	case 8051ULL: goto x86_l_1f73;
	case 8055ULL: goto x86_l_1f77;
	case 8056ULL: goto x86_l_1f78;
	case 8058ULL: goto x86_l_1f7a;
	case 8060ULL: goto x86_l_1f7c;
	case 8062ULL: goto x86_l_1f7e;
	case 8063ULL: goto x86_l_1f7f;
	case 8067ULL: goto x86_l_1f83;
	case 8070ULL: goto x86_l_1f86;
	case 8075ULL: goto x86_l_1f8b;
	case 8078ULL: goto x86_l_1f8e;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8089ULL: goto x86_l_1f99;
	case 8091ULL: goto x86_l_1f9b;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8098ULL: goto x86_l_1fa2;
	case 8100ULL: goto x86_l_1fa4;
	case 8101ULL: goto x86_l_1fa5;
	case 8102ULL: goto x86_l_1fa6;
	case 8105ULL: goto x86_l_1fa9;
	case 8108ULL: goto x86_l_1fac;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8119ULL: goto x86_l_1fb7;
	case 8121ULL: goto x86_l_1fb9;
	case 8127ULL: goto x86_l_1fbf;
	case 8130ULL: goto x86_l_1fc2;
	case 8137ULL: goto x86_l_1fc9;
	case 8140ULL: goto x86_l_1fcc;
	case 8143ULL: goto x86_l_1fcf;
	case 8149ULL: goto x86_l_1fd5;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8166ULL: goto x86_l_1fe6;
	case 8172ULL: goto x86_l_1fec;
	case 8177ULL: goto x86_l_1ff1;
	case 8180ULL: goto x86_l_1ff4;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8189ULL: goto x86_l_1ffd;
	case 8195ULL: goto x86_l_2003;
	case 8199ULL: goto x86_l_2007;
	case 8202ULL: goto x86_l_200a;
	case 8205ULL: goto x86_l_200d;
	case 8210ULL: goto x86_l_2012;
	case 8212ULL: goto x86_l_2014;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8229ULL: goto x86_l_2025;
	case 8232ULL: goto x86_l_2028;
	case 8235ULL: goto x86_l_202b;
	case 8241ULL: goto x86_l_2031;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8258ULL: goto x86_l_2042;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8275ULL: goto x86_l_2053;
	case 8278ULL: goto x86_l_2056;
	case 8281ULL: goto x86_l_2059;
	case 8287ULL: goto x86_l_205f;
	case 8291ULL: goto x86_l_2063;
	case 8294ULL: goto x86_l_2066;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8304ULL: goto x86_l_2070;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8318ULL: goto x86_l_207e;
	case 8321ULL: goto x86_l_2081;
	case 8324ULL: goto x86_l_2084;
	case 8327ULL: goto x86_l_2087;
	case 8333ULL: goto x86_l_208d;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8364ULL: goto x86_l_20ac;
	case 8367ULL: goto x86_l_20af;
	case 8370ULL: goto x86_l_20b2;
	case 8373ULL: goto x86_l_20b5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b4e:
	/* 0x1b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b50:
	/* 0x1b50: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b55:
	/* 0x1b55: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b59:
	/* 0x1b59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5c:
	/* 0x1b5c: jne    1a7f <event_execve+0x1a7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6783ULL;
	}
x86_l_1b62:
	/* 0x1b62: or     ebp,0x200000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 2097152ULL);
x86_l_1b68:
	/* 0x1b68: jmp    1b70 <event_execve+0x1b70> */
	goto x86_l_1b70;
x86_l_1b6a:
	/* 0x1b6a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6c:
	/* 0x1b6c: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b70:
	/* 0x1b70: add    rbx,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_1b77:
	/* 0x1b77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b7c:
	/* 0x1b7c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b81:
	/* 0x1b81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b86:
	/* 0x1b86: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1b89:
	/* 0x1b89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b8b:
	/* 0x1b8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b90:
	/* 0x1b90: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b95:
	/* 0x1b95: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b99:
	/* 0x1b99: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b9e:
	/* 0x1b9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ba3:
	/* 0x1ba3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba5:
	/* 0x1ba5: mov    ecx,0x10000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_1baa:
	/* 0x1baa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bad:
	/* 0x1bad: jne    1bce <event_execve+0x1bce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bce;
	}
x86_l_1baf:
	/* 0x1baf: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bb4:
	/* 0x1bb4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1bb7:
	/* 0x1bb7: je     1bce <event_execve+0x1bce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bce;
	}
x86_l_1bb9:
	/* 0x1bb9: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1bbc:
	/* 0x1bbc: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1bc0:
	/* 0x1bc0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1bca:
	/* 0x1bca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcc:
	/* 0x1bcc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bce:
	/* 0x1bce: or     ecx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_1bd0:
	/* 0x1bd0: jmp    1c30 <event_execve+0x1c30> */
	goto x86_l_1c30;
x86_l_1bd2:
	/* 0x1bd2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd4:
	/* 0x1bd4: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd8:
	/* 0x1bd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bdb:
	/* 0x1bdb: jne    1a7f <event_execve+0x1a7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6783ULL;
	}
x86_l_1be1:
	/* 0x1be1: jmp    1b62 <event_execve+0x1b62> */
	goto x86_l_1b62;
x86_l_1be6:
	/* 0x1be6: mov    DWORD PTR [rsp+0x70],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337153ULL);
x86_l_1bee:
	/* 0x1bee: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1bfa:
	/* 0x1bfa: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bff:
	/* 0x1bff: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c04:
	/* 0x1c04: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c06:
	/* 0x1c06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c08:
	/* 0x1c08: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c0d:
	/* 0x1c0d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1c10:
	/* 0x1c10: jne    1567 <event_execve+0x1567> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5479ULL;
	}
x86_l_1c16:
	/* 0x1c16: jmp    1605 <event_execve+0x1605> */
	return 5637ULL;
x86_l_1c1b:
	/* 0x1c1b: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c20:
	/* 0x1c20: mov    ebp,0x80000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 524288ULL);
x86_l_1c25:
	/* 0x1c25: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1c28:
	/* 0x1c28: jne    1b03 <event_execve+0x1b03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6915ULL;
	}
x86_l_1c2e:
	/* 0x1c2e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c30:
	/* 0x1c30: or     DWORD PTR [r14+0x15c],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_1c37:
	/* 0x1c37: mov    QWORD PTR [r14+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_1c42:
	/* 0x1c42: mov    QWORD PTR [r14+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_1c4d:
	/* 0x1c4d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1c52:
	/* 0x1c52: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_1c59:
	/* 0x1c59: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c5c:
	/* 0x1c5c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c5e:
	/* 0x1c5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c60:
	/* 0x1c60: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c62:
	/* 0x1c62: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1c69:
	/* 0x1c69: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1c6b:
	/* 0x1c6b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1c6c:
	/* 0x1c6c: jmp    24c2 <__do_str+0x1af> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_1c71:
	/* 0x1c71: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1c73:
	/* 0x1c73: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1c75:
	/* 0x1c75: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1c77:
	/* 0x1c77: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1c79:
	/* 0x1c79: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1c7a:
	/* 0x1c7a: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_1c81:
	/* 0x1c81: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1c84:
	/* 0x1c84: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1c87:
	/* 0x1c87: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c94:
	/* 0x1c94: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_1c9b:
	/* 0x1c9b: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ca0:
	/* 0x1ca0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca2:
	/* 0x1ca2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ca5:
	/* 0x1ca5: je     1d1d <data_event_str+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d1d;
	}
x86_l_1ca7:
	/* 0x1ca7: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1caa:
	/* 0x1caa: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cb0:
	/* 0x1cb0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1cb5:
	/* 0x1cb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb7:
	/* 0x1cb7: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1cba:
	/* 0x1cba: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc3:
	/* 0x1cc3: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1cc7:
	/* 0x1cc7: jne    1cd1 <data_event_str+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cd1;
	}
x86_l_1cc9:
	/* 0x1cc9: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ccd:
	/* 0x1ccd: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd1:
	/* 0x1cd1: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1cd6:
	/* 0x1cd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd8:
	/* 0x1cd8: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cdd:
	/* 0x1cdd: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce5:
	/* 0x1ce5: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ced:
	/* 0x1ced: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1cf0:
	/* 0x1cf0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1cf3:
	/* 0x1cf3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1cf6:
	/* 0x1cf6: call   22b4 <do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 7419ULL);
	return 8884ULL;
x86_l_1cfb:
	/* 0x1cfb: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1cfd:
	/* 0x1cfd: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1d00:
	/* 0x1d00: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_1d02:
	/* 0x1d02: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d04:
	/* 0x1d04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d06:
	/* 0x1d06: mov    DWORD PTR [rbx],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d08:
	/* 0x1d08: cmovg  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_G);
x86_l_1d0b:
	/* 0x1d0b: mov    QWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1d13:
	/* 0x1d13: mov    DWORD PTR [rbx+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d16:
	/* 0x1d16: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1d1b:
	/* 0x1d1b: jmp    1d1f <data_event_str+0xae> */
	goto x86_l_1d1f;
x86_l_1d1d:
	/* 0x1d1d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d1f:
	/* 0x1d1f: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d23:
	/* 0x1d23: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1d24:
	/* 0x1d24: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1d26:
	/* 0x1d26: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1d28:
	/* 0x1d28: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1d2a:
	/* 0x1d2a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1d2c:
	/* 0x1d2c: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1d2d:
	/* 0x1d2d: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1d2e:
	/* 0x1d2e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1d30:
	/* 0x1d30: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1d32:
	/* 0x1d32: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1d34:
	/* 0x1d34: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1d36:
	/* 0x1d36: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1d37:
	/* 0x1d37: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1d38:
	/* 0x1d38: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_1d3b:
	/* 0x1d3b: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_1d3e:
	/* 0x1d3e: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1d41:
	/* 0x1d41: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_1d44:
	/* 0x1d44: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1d4c:
	/* 0x1d4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d51:
	/* 0x1d51: mov    rdi,QWORD PTR [rip+0x2d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_1d58:
	/* 0x1d58: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d5d:
	/* 0x1d5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d5f:
	/* 0x1d5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d62:
	/* 0x1d62: je     1dd5 <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd5;
	}
x86_l_1d64:
	/* 0x1d64: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1d67:
	/* 0x1d67: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d72:
	/* 0x1d72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d74:
	/* 0x1d74: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_1d77:
	/* 0x1d77: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d7b:
	/* 0x1d7b: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7f:
	/* 0x1d7f: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1d83:
	/* 0x1d83: jne    1d8e <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d8e;
	}
x86_l_1d85:
	/* 0x1d85: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8e:
	/* 0x1d8e: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1d93:
	/* 0x1d93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d95:
	/* 0x1d95: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d99:
	/* 0x1d99: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d9d:
	/* 0x1d9d: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da1:
	/* 0x1da1: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da5:
	/* 0x1da5: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1da9:
	/* 0x1da9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1dac:
	/* 0x1dac: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1daf:
	/* 0x1daf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1db2:
	/* 0x1db2: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1db5:
	/* 0x1db5: call   1f9b <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 7610ULL);
	goto x86_l_1f9b;
x86_l_1dba:
	/* 0x1dba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dbc:
	/* 0x1dbc: js     1dd9 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1dd9;
	}
x86_l_1dbe:
	/* 0x1dbe: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_1dc8:
	/* 0x1dc8: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1dca:
	/* 0x1dca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dcc:
	/* 0x1dcc: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1dd0:
	/* 0x1dd0: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_1dd3:
	/* 0x1dd3: jmp    1de6 <data_event_bytes+0xb9> */
	goto x86_l_1de6;
x86_l_1dd5:
	/* 0x1dd5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dd7:
	/* 0x1dd7: jmp    1df1 <data_event_bytes+0xc4> */
	goto x86_l_1df1;
x86_l_1dd9:
	/* 0x1dd9: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1de2:
	/* 0x1de2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de4:
	/* 0x1de4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de6:
	/* 0x1de6: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de9:
	/* 0x1de9: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1dec:
	/* 0x1dec: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1df1:
	/* 0x1df1: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1df5:
	/* 0x1df5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1df6:
	/* 0x1df6: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1df8:
	/* 0x1df8: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1dfa:
	/* 0x1dfa: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1dfc:
	/* 0x1dfc: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1dfe:
	/* 0x1dfe: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1dff:
	/* 0x1dff: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1e00:
	/* 0x1e00: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1e02:
	/* 0x1e02: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1e04:
	/* 0x1e04: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1e06:
	/* 0x1e06: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1e07:
	/* 0x1e07: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1e0e:
	/* 0x1e0e: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e12:
	/* 0x1e12: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e16:
	/* 0x1e16: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e1a:
	/* 0x1e1a: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1e1d:
	/* 0x1e1d: jne    1e29 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e29;
	}
x86_l_1e1f:
	/* 0x1e1f: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1e23:
	/* 0x1e23: je     1f6a <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6a;
	}
x86_l_1e29:
	/* 0x1e29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e2e:
	/* 0x1e2e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e33:
	/* 0x1e33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e38:
	/* 0x1e38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3a:
	/* 0x1e3a: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1e3f:
	/* 0x1e3f: je     1f1e <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f1e;
	}
x86_l_1e45:
	/* 0x1e45: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e49:
	/* 0x1e49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e4e:
	/* 0x1e4e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e53:
	/* 0x1e53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e58:
	/* 0x1e58: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e5b:
	/* 0x1e5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5d:
	/* 0x1e5d: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e62:
	/* 0x1e62: je     1f1e <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f1e;
	}
x86_l_1e68:
	/* 0x1e68: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e6d:
	/* 0x1e6d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e72:
	/* 0x1e72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e77:
	/* 0x1e77: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e7a:
	/* 0x1e7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7c:
	/* 0x1e7c: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1e80:
	/* 0x1e80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e85:
	/* 0x1e85: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e8a:
	/* 0x1e8a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e8f:
	/* 0x1e8f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e92:
	/* 0x1e92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e94:
	/* 0x1e94: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e98:
	/* 0x1e98: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ea0:
	/* 0x1ea0: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1ea3:
	/* 0x1ea3: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ea6:
	/* 0x1ea6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ea8:
	/* 0x1ea8: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1eaa:
	/* 0x1eaa: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1eac:
	/* 0x1eac: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1eaf:
	/* 0x1eaf: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1eb4:
	/* 0x1eb4: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eb7:
	/* 0x1eb7: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1eb9:
	/* 0x1eb9: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_1ebd:
	/* 0x1ebd: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_1ec0:
	/* 0x1ec0: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1ec4:
	/* 0x1ec4: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ec7:
	/* 0x1ec7: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_1ec9:
	/* 0x1ec9: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ecc:
	/* 0x1ecc: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ecf:
	/* 0x1ecf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ed4:
	/* 0x1ed4: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1ed7:
	/* 0x1ed7: jb     1f73 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f73;
	}
x86_l_1edd:
	/* 0x1edd: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_1ee4:
	/* 0x1ee4: ja     1f73 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f73;
	}
x86_l_1eea:
	/* 0x1eea: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1eec:
	/* 0x1eec: jbe    1f7f <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f7f;
	}
x86_l_1ef2:
	/* 0x1ef2: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1efb:
	/* 0x1efb: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1eff:
	/* 0x1eff: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1f03:
	/* 0x1f03: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f06:
	/* 0x1f06: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f0b:
	/* 0x1f0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0d:
	/* 0x1f0d: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f11:
	/* 0x1f11: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f16:
	/* 0x1f16: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f1a:
	/* 0x1f1a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f1c:
	/* 0x1f1c: jmp    1f73 <cwd_read_v61+0x173> */
	goto x86_l_1f73;
x86_l_1f1e:
	/* 0x1f1e: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f22:
	/* 0x1f22: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f27:
	/* 0x1f27: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f31:
	/* 0x1f31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f33:
	/* 0x1f33: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f37:
	/* 0x1f37: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1f3c:
	/* 0x1f3c: je     1f6a <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6a;
	}
x86_l_1f3e:
	/* 0x1f3e: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f42:
	/* 0x1f42: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f46:
	/* 0x1f46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f4b:
	/* 0x1f4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f50:
	/* 0x1f50: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1f53:
	/* 0x1f53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f55:
	/* 0x1f55: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f5e:
	/* 0x1f5e: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1f62:
	/* 0x1f62: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f66:
	/* 0x1f66: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f68:
	/* 0x1f68: jmp    1f73 <cwd_read_v61+0x173> */
	goto x86_l_1f73;
x86_l_1f6a:
	/* 0x1f6a: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f73:
	/* 0x1f73: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1f77:
	/* 0x1f77: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f78:
	/* 0x1f78: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1f7a:
	/* 0x1f7a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f7c:
	/* 0x1f7c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1f7e:
	/* 0x1f7e: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f7f:
	/* 0x1f7f: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f83:
	/* 0x1f83: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f86:
	/* 0x1f86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1f8e:
	/* 0x1f8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f90:
	/* 0x1f90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f95:
	/* 0x1f95: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f99:
	/* 0x1f99: jmp    1f73 <cwd_read_v61+0x173> */
	goto x86_l_1f73;
x86_l_1f9b:
	/* 0x1f9b: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1f9c:
	/* 0x1f9c: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1f9e:
	/* 0x1f9e: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1fa0:
	/* 0x1fa0: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1fa2:
	/* 0x1fa2: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1fa4:
	/* 0x1fa4: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1fa5:
	/* 0x1fa5: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1fa6:
	/* 0x1fa6: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1fa9:
	/* 0x1fa9: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_1fac:
	/* 0x1fac: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_1faf:
	/* 0x1faf: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_1fb2:
	/* 0x1fb2: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8119ULL);
	return 8699ULL;
x86_l_1fb7:
	/* 0x1fb7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fb9:
	/* 0x1fb9: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8546ULL;
	}
x86_l_1fbf:
	/* 0x1fbf: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1fc2:
	/* 0x1fc2: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1fcc:
	/* 0x1fcc: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1fcf:
	/* 0x1fcf: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8681ULL;
	}
x86_l_1fd5:
	/* 0x1fd5: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1fd9:
	/* 0x1fd9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1fdc:
	/* 0x1fdc: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1fdf:
	/* 0x1fdf: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8164ULL);
	return 8699ULL;
x86_l_1fe4:
	/* 0x1fe4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fe6:
	/* 0x1fe6: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8546ULL;
	}
x86_l_1fec:
	/* 0x1fec: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1ff1:
	/* 0x1ff1: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1ff4:
	/* 0x1ff4: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ff7:
	/* 0x1ff7: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1ffa:
	/* 0x1ffa: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1ffd:
	/* 0x1ffd: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8681ULL;
	}
x86_l_2003:
	/* 0x2003: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2007:
	/* 0x2007: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_200a:
	/* 0x200a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_200d:
	/* 0x200d: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8210ULL);
	return 8699ULL;
x86_l_2012:
	/* 0x2012: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2014:
	/* 0x2014: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8546ULL;
	}
x86_l_201a:
	/* 0x201a: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_201f:
	/* 0x201f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2022:
	/* 0x2022: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2025:
	/* 0x2025: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2028:
	/* 0x2028: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_202b:
	/* 0x202b: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8681ULL;
	}
x86_l_2031:
	/* 0x2031: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2035:
	/* 0x2035: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2038:
	/* 0x2038: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_203b:
	/* 0x203b: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8256ULL);
	return 8699ULL;
x86_l_2040:
	/* 0x2040: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2042:
	/* 0x2042: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8546ULL;
	}
x86_l_2048:
	/* 0x2048: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_204d:
	/* 0x204d: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2050:
	/* 0x2050: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2053:
	/* 0x2053: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2056:
	/* 0x2056: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2059:
	/* 0x2059: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8681ULL;
	}
x86_l_205f:
	/* 0x205f: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2063:
	/* 0x2063: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2066:
	/* 0x2066: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2069:
	/* 0x2069: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8302ULL);
	return 8699ULL;
x86_l_206e:
	/* 0x206e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2070:
	/* 0x2070: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8546ULL;
	}
x86_l_2076:
	/* 0x2076: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_207b:
	/* 0x207b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_207e:
	/* 0x207e: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2081:
	/* 0x2081: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2084:
	/* 0x2084: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2087:
	/* 0x2087: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8681ULL;
	}
x86_l_208d:
	/* 0x208d: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2091:
	/* 0x2091: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2094:
	/* 0x2094: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2097:
	/* 0x2097: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8348ULL);
	return 8699ULL;
x86_l_209c:
	/* 0x209c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_209e:
	/* 0x209e: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8546ULL;
	}
x86_l_20a4:
	/* 0x20a4: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_20a9:
	/* 0x20a9: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_20ac:
	/* 0x20ac: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20af:
	/* 0x20af: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_20b2:
	/* 0x20b2: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_20b5:
	/* 0x20b5: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8681ULL;
	}
	return 8379ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_v61_event_execve_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8379ULL: goto x86_l_20bb;
	case 8383ULL: goto x86_l_20bf;
	case 8386ULL: goto x86_l_20c2;
	case 8389ULL: goto x86_l_20c5;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8402ULL: goto x86_l_20d2;
	case 8407ULL: goto x86_l_20d7;
	case 8410ULL: goto x86_l_20da;
	case 8413ULL: goto x86_l_20dd;
	case 8416ULL: goto x86_l_20e0;
	case 8419ULL: goto x86_l_20e3;
	case 8425ULL: goto x86_l_20e9;
	case 8429ULL: goto x86_l_20ed;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8442ULL: goto x86_l_20fa;
	case 8444ULL: goto x86_l_20fc;
	case 8449ULL: goto x86_l_2101;
	case 8452ULL: goto x86_l_2104;
	case 8455ULL: goto x86_l_2107;
	case 8458ULL: goto x86_l_210a;
	case 8461ULL: goto x86_l_210d;
	case 8467ULL: goto x86_l_2113;
	case 8471ULL: goto x86_l_2117;
	case 8474ULL: goto x86_l_211a;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8484ULL: goto x86_l_2124;
	case 8486ULL: goto x86_l_2126;
	case 8491ULL: goto x86_l_212b;
	case 8494ULL: goto x86_l_212e;
	case 8497ULL: goto x86_l_2131;
	case 8500ULL: goto x86_l_2134;
	case 8503ULL: goto x86_l_2137;
	case 8509ULL: goto x86_l_213d;
	case 8512ULL: goto x86_l_2140;
	case 8515ULL: goto x86_l_2143;
	case 8518ULL: goto x86_l_2146;
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8528ULL: goto x86_l_2150;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8549ULL: goto x86_l_2165;
	case 8557ULL: goto x86_l_216d;
	case 8562ULL: goto x86_l_2172;
	case 8569ULL: goto x86_l_2179;
	case 8574ULL: goto x86_l_217e;
	case 8576ULL: goto x86_l_2180;
	case 8579ULL: goto x86_l_2183;
	case 8581ULL: goto x86_l_2185;
	case 8585ULL: goto x86_l_2189;
	case 8587ULL: goto x86_l_218b;
	case 8591ULL: goto x86_l_218f;
	case 8593ULL: goto x86_l_2191;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8603ULL: goto x86_l_219b;
	case 8605ULL: goto x86_l_219d;
	case 8611ULL: goto x86_l_21a3;
	case 8613ULL: goto x86_l_21a5;
	case 8617ULL: goto x86_l_21a9;
	case 8619ULL: goto x86_l_21ab;
	case 8623ULL: goto x86_l_21af;
	case 8625ULL: goto x86_l_21b1;
	case 8629ULL: goto x86_l_21b5;
	case 8631ULL: goto x86_l_21b7;
	case 8637ULL: goto x86_l_21bd;
	case 8639ULL: goto x86_l_21bf;
	case 8645ULL: goto x86_l_21c5;
	case 8647ULL: goto x86_l_21c7;
	case 8653ULL: goto x86_l_21cd;
	case 8655ULL: goto x86_l_21cf;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8669ULL: goto x86_l_21dd;
	case 8671ULL: goto x86_l_21df;
	case 8677ULL: goto x86_l_21e5;
	case 8681ULL: goto x86_l_21e9;
	case 8684ULL: goto x86_l_21ec;
	case 8688ULL: goto x86_l_21f0;
	case 8689ULL: goto x86_l_21f1;
	case 8691ULL: goto x86_l_21f3;
	case 8693ULL: goto x86_l_21f5;
	case 8695ULL: goto x86_l_21f7;
	case 8697ULL: goto x86_l_21f9;
	case 8698ULL: goto x86_l_21fa;
	case 8699ULL: goto x86_l_21fb;
	case 8701ULL: goto x86_l_21fd;
	case 8703ULL: goto x86_l_21ff;
	case 8705ULL: goto x86_l_2201;
	case 8706ULL: goto x86_l_2202;
	case 8707ULL: goto x86_l_2203;
	case 8710ULL: goto x86_l_2206;
	case 8712ULL: goto x86_l_2208;
	case 8715ULL: goto x86_l_220b;
	case 8718ULL: goto x86_l_220e;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8734ULL: goto x86_l_221e;
	case 8738ULL: goto x86_l_2222;
	case 8743ULL: goto x86_l_2227;
	case 8745ULL: goto x86_l_2229;
	case 8747ULL: goto x86_l_222b;
	case 8749ULL: goto x86_l_222d;
	case 8751ULL: goto x86_l_222f;
	case 8755ULL: goto x86_l_2233;
	case 8759ULL: goto x86_l_2237;
	case 8767ULL: goto x86_l_223f;
	case 8772ULL: goto x86_l_2244;
	case 8779ULL: goto x86_l_224b;
	case 8784ULL: goto x86_l_2250;
	case 8786ULL: goto x86_l_2252;
	case 8789ULL: goto x86_l_2255;
	case 8791ULL: goto x86_l_2257;
	case 8795ULL: goto x86_l_225b;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8817ULL: goto x86_l_2271;
	case 8820ULL: goto x86_l_2274;
	case 8823ULL: goto x86_l_2277;
	case 8825ULL: goto x86_l_2279;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8831ULL: goto x86_l_227f;
	case 8838ULL: goto x86_l_2286;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8852ULL: goto x86_l_2294;
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8860ULL: goto x86_l_229c;
	case 8862ULL: goto x86_l_229e;
	case 8864ULL: goto x86_l_22a0;
	case 8866ULL: goto x86_l_22a2;
	case 8869ULL: goto x86_l_22a5;
	case 8872ULL: goto x86_l_22a8;
	case 8876ULL: goto x86_l_22ac;
	case 8877ULL: goto x86_l_22ad;
	case 8879ULL: goto x86_l_22af;
	case 8881ULL: goto x86_l_22b1;
	case 8883ULL: goto x86_l_22b3;
	case 8884ULL: goto x86_l_22b4;
	case 8886ULL: goto x86_l_22b6;
	case 8888ULL: goto x86_l_22b8;
	case 8889ULL: goto x86_l_22b9;
	case 8893ULL: goto x86_l_22bd;
	case 8896ULL: goto x86_l_22c0;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8920ULL: goto x86_l_22d8;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8929ULL: goto x86_l_22e1;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8940ULL: goto x86_l_22ec;
	case 8943ULL: goto x86_l_22ef;
	case 8946ULL: goto x86_l_22f2;
	case 8949ULL: goto x86_l_22f5;
	case 8954ULL: goto x86_l_22fa;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8963ULL: goto x86_l_2303;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8973ULL: goto x86_l_230d;
	case 8974ULL: goto x86_l_230e;
	case 8976ULL: goto x86_l_2310;
	case 8978ULL: goto x86_l_2312;
	case 8979ULL: goto x86_l_2313;
	case 8981ULL: goto x86_l_2315;
	case 8983ULL: goto x86_l_2317;
	case 8985ULL: goto x86_l_2319;
	case 8986ULL: goto x86_l_231a;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9003ULL: goto x86_l_232b;
	case 9008ULL: goto x86_l_2330;
	case 9013ULL: goto x86_l_2335;
	case 9015ULL: goto x86_l_2337;
	case 9018ULL: goto x86_l_233a;
	case 9024ULL: goto x86_l_2340;
	case 9030ULL: goto x86_l_2346;
	case 9034ULL: goto x86_l_234a;
	case 9037ULL: goto x86_l_234d;
	case 9043ULL: goto x86_l_2353;
	case 9046ULL: goto x86_l_2356;
	case 9050ULL: goto x86_l_235a;
	case 9057ULL: goto x86_l_2361;
	case 9061ULL: goto x86_l_2365;
	case 9069ULL: goto x86_l_236d;
	case 9074ULL: goto x86_l_2372;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9088ULL: goto x86_l_2380;
	case 9091ULL: goto x86_l_2383;
	case 9093ULL: goto x86_l_2385;
	case 9097ULL: goto x86_l_2389;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9125ULL: goto x86_l_23a5;
	case 9127ULL: goto x86_l_23a7;
	case 9130ULL: goto x86_l_23aa;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9159ULL: goto x86_l_23c7;
	case 9164ULL: goto x86_l_23cc;
	case 9166ULL: goto x86_l_23ce;
	case 9169ULL: goto x86_l_23d1;
	case 9175ULL: goto x86_l_23d7;
	case 9179ULL: goto x86_l_23db;
	case 9185ULL: goto x86_l_23e1;
	case 9189ULL: goto x86_l_23e5;
	case 9195ULL: goto x86_l_23eb;
	case 9199ULL: goto x86_l_23ef;
	case 9201ULL: goto x86_l_23f1;
	case 9207ULL: goto x86_l_23f7;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9224ULL: goto x86_l_2408;
	case 9227ULL: goto x86_l_240b;
	case 9230ULL: goto x86_l_240e;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9237ULL: goto x86_l_2415;
	case 9243ULL: goto x86_l_241b;
	case 9246ULL: goto x86_l_241e;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9266ULL: goto x86_l_2432;
	case 9271ULL: goto x86_l_2437;
	case 9273ULL: goto x86_l_2439;
	case 9276ULL: goto x86_l_243c;
	case 9278ULL: goto x86_l_243e;
	case 9282ULL: goto x86_l_2442;
	case 9284ULL: goto x86_l_2444;
	case 9288ULL: goto x86_l_2448;
	case 9290ULL: goto x86_l_244a;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9300ULL: goto x86_l_2454;
	case 9302ULL: goto x86_l_2456;
	case 9308ULL: goto x86_l_245c;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9314ULL: goto x86_l_2462;
	case 9318ULL: goto x86_l_2466;
	case 9320ULL: goto x86_l_2468;
	case 9324ULL: goto x86_l_246c;
	case 9326ULL: goto x86_l_246e;
	case 9330ULL: goto x86_l_2472;
	case 9332ULL: goto x86_l_2474;
	case 9338ULL: goto x86_l_247a;
	case 9340ULL: goto x86_l_247c;
	case 9344ULL: goto x86_l_2480;
	case 9346ULL: goto x86_l_2482;
	case 9350ULL: goto x86_l_2486;
	case 9352ULL: goto x86_l_2488;
	case 9356ULL: goto x86_l_248c;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9366ULL: goto x86_l_2496;
	case 9372ULL: goto x86_l_249c;
	case 9374ULL: goto x86_l_249e;
	case 9380ULL: goto x86_l_24a4;
	case 9382ULL: goto x86_l_24a6;
	case 9388ULL: goto x86_l_24ac;
	case 9392ULL: goto x86_l_24b0;
	case 9395ULL: goto x86_l_24b3;
	case 9398ULL: goto x86_l_24b6;
	case 9402ULL: goto x86_l_24ba;
	case 9403ULL: goto x86_l_24bb;
	case 9405ULL: goto x86_l_24bd;
	case 9407ULL: goto x86_l_24bf;
	case 9409ULL: goto x86_l_24c1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_20bb:
	/* 0x20bb: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_20bf:
	/* 0x20bf: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_20c2:
	/* 0x20c2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_20c5:
	/* 0x20c5: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8394ULL);
	goto x86_l_21fb;
x86_l_20ca:
	/* 0x20ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20cc:
	/* 0x20cc: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2162;
	}
x86_l_20d2:
	/* 0x20d2: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_20d7:
	/* 0x20d7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_20da:
	/* 0x20da: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20dd:
	/* 0x20dd: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_20e0:
	/* 0x20e0: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_20e3:
	/* 0x20e3: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21e9;
	}
x86_l_20e9:
	/* 0x20e9: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_20ed:
	/* 0x20ed: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_20f0:
	/* 0x20f0: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_20f3:
	/* 0x20f3: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8440ULL);
	goto x86_l_21fb;
x86_l_20f8:
	/* 0x20f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20fa:
	/* 0x20fa: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2162;
	}
x86_l_20fc:
	/* 0x20fc: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2101:
	/* 0x2101: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2104:
	/* 0x2104: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2107:
	/* 0x2107: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_210a:
	/* 0x210a: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_210d:
	/* 0x210d: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21e9;
	}
x86_l_2113:
	/* 0x2113: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2117:
	/* 0x2117: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_211a:
	/* 0x211a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_211d:
	/* 0x211d: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8482ULL);
	goto x86_l_21fb;
x86_l_2122:
	/* 0x2122: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2124:
	/* 0x2124: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2162;
	}
x86_l_2126:
	/* 0x2126: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_212b:
	/* 0x212b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_212e:
	/* 0x212e: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2131:
	/* 0x2131: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2134:
	/* 0x2134: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2137:
	/* 0x2137: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21e9;
	}
x86_l_213d:
	/* 0x213d: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2140:
	/* 0x2140: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2143:
	/* 0x2143: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2146:
	/* 0x2146: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2149:
	/* 0x2149: call   21fb <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8526ULL);
	goto x86_l_21fb;
x86_l_214e:
	/* 0x214e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2150:
	/* 0x2150: js     2162 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2162;
	}
x86_l_2152:
	/* 0x2152: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2157:
	/* 0x2157: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_215a:
	/* 0x215a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_215d:
	/* 0x215d: jmp    21e9 <do_bytes+0x24e> */
	goto x86_l_21e9;
x86_l_2162:
	/* 0x2162: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2165:
	/* 0x2165: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_216d:
	/* 0x216d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2172:
	/* 0x2172: mov    rdi,QWORD PTR [rip+0x3b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_2179:
	/* 0x2179: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_217e:
	/* 0x217e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2180:
	/* 0x2180: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2183:
	/* 0x2183: je     21e9 <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21e9;
	}
x86_l_2185:
	/* 0x2185: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2189:
	/* 0x2189: jg     21a5 <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21a5;
	}
x86_l_218b:
	/* 0x218b: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_218f:
	/* 0x218f: je     21bf <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21bf;
	}
x86_l_2191:
	/* 0x2191: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2195:
	/* 0x2195: je     21d7 <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21d7;
	}
x86_l_2197:
	/* 0x2197: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_219b:
	/* 0x219b: jne    21cf <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21cf;
	}
x86_l_219d:
	/* 0x219d: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_21a3:
	/* 0x21a3: jmp    21e5 <do_bytes+0x24a> */
	goto x86_l_21e5;
x86_l_21a5:
	/* 0x21a5: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_21a9:
	/* 0x21a9: je     21c7 <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_21ab:
	/* 0x21ab: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_21af:
	/* 0x21af: je     21df <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21df;
	}
x86_l_21b1:
	/* 0x21b1: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_21b5:
	/* 0x21b5: jne    21cf <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21cf;
	}
x86_l_21b7:
	/* 0x21b7: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_21bd:
	/* 0x21bd: jmp    21e5 <do_bytes+0x24a> */
	goto x86_l_21e5;
x86_l_21bf:
	/* 0x21bf: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_21c5:
	/* 0x21c5: jmp    21e5 <do_bytes+0x24a> */
	goto x86_l_21e5;
x86_l_21c7:
	/* 0x21c7: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_21cd:
	/* 0x21cd: jmp    21e5 <do_bytes+0x24a> */
	goto x86_l_21e5;
x86_l_21cf:
	/* 0x21cf: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_21d5:
	/* 0x21d5: jmp    21e5 <do_bytes+0x24a> */
	goto x86_l_21e5;
x86_l_21d7:
	/* 0x21d7: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_21dd:
	/* 0x21dd: jmp    21e5 <do_bytes+0x24a> */
	goto x86_l_21e5;
x86_l_21df:
	/* 0x21df: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_21e5:
	/* 0x21e5: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_21e9:
	/* 0x21e9: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_21ec:
	/* 0x21ec: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_21f0:
	/* 0x21f0: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_21f1:
	/* 0x21f1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_21f3:
	/* 0x21f3: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_21f5:
	/* 0x21f5: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_21f7:
	/* 0x21f7: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_21f9:
	/* 0x21f9: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_21fa:
	/* 0x21fa: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_21fb:
	/* 0x21fb: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_21fd:
	/* 0x21fd: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_21ff:
	/* 0x21ff: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2201:
	/* 0x2201: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2202:
	/* 0x2202: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_2203:
	/* 0x2203: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2206:
	/* 0x2206: js     227f <__do_bytes+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_227f;
	}
x86_l_2208:
	/* 0x2208: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_220b:
	/* 0x220b: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_220e:
	/* 0x220e: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_2215:
	/* 0x2215: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_221a:
	/* 0x221a: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_221e:
	/* 0x221e: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2222:
	/* 0x2222: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2227:
	/* 0x2227: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2229:
	/* 0x2229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_222b:
	/* 0x222b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_222d:
	/* 0x222d: js     22a2 <__do_bytes+0xa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_22a2;
	}
x86_l_222f:
	/* 0x222f: lea    r12d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2233:
	/* 0x2233: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2237:
	/* 0x2237: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_223f:
	/* 0x223f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2244:
	/* 0x2244: mov    rdi,QWORD PTR [rip+0x610] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_224b:
	/* 0x224b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2250:
	/* 0x2250: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2252:
	/* 0x2252: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2255:
	/* 0x2255: je     2288 <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2288;
	}
x86_l_2257:
	/* 0x2257: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_225b:
	/* 0x225b: je     2288 <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2288;
	}
x86_l_225d:
	/* 0x225d: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2262:
	/* 0x2262: mov    rsi,QWORD PTR [rip+0x610] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_2269:
	/* 0x2269: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_226e:
	/* 0x226e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2271:
	/* 0x2271: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2274:
	/* 0x2274: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_2277:
	/* 0x2277: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2279:
	/* 0x2279: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_227b:
	/* 0x227b: js     22a2 <__do_bytes+0xa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_22a2;
	}
x86_l_227d:
	/* 0x227d: jmp    22a5 <__do_bytes+0xaa> */
	goto x86_l_22a5;
x86_l_227f:
	/* 0x227f: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2286:
	/* 0x2286: jmp    22a5 <__do_bytes+0xaa> */
	goto x86_l_22a5;
x86_l_2288:
	/* 0x2288: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_228d:
	/* 0x228d: mov    rdi,QWORD PTR [rip+0x610] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_2294:
	/* 0x2294: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2297:
	/* 0x2297: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_229a:
	/* 0x229a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_229c:
	/* 0x229c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_229e:
	/* 0x229e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22a0:
	/* 0x22a0: jns    22a5 <__do_bytes+0xaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_22a5;
	}
x86_l_22a2:
	/* 0x22a2: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_22a5:
	/* 0x22a5: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_22a8:
	/* 0x22a8: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22ac:
	/* 0x22ac: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_22ad:
	/* 0x22ad: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_22af:
	/* 0x22af: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_22b1:
	/* 0x22b1: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_22b3:
	/* 0x22b3: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_22b4:
	/* 0x22b4: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_22b6:
	/* 0x22b6: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_22b8:
	/* 0x22b8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_22b9:
	/* 0x22b9: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_22bd:
	/* 0x22bd: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_22c0:
	/* 0x22c0: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_22c3:
	/* 0x22c3: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_22c6:
	/* 0x22c6: mov    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_22cb:
	/* 0x22cb: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_22d0:
	/* 0x22d0: call   2313 <__do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8917ULL);
	goto x86_l_2313;
x86_l_22d5:
	/* 0x22d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22d8:
	/* 0x22d8: js     2309 <do_str+0x55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2309;
	}
x86_l_22da:
	/* 0x22da: cmp    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_22df:
	/* 0x22df: jne    2309 <do_str+0x55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2309;
	}
x86_l_22e1:
	/* 0x22e1: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22e4:
	/* 0x22e4: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_22e9:
	/* 0x22e9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_22ec:
	/* 0x22ec: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_22ef:
	/* 0x22ef: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_22f2:
	/* 0x22f2: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_22f5:
	/* 0x22f5: call   2313 <__do_str> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8954ULL);
	goto x86_l_2313;
x86_l_22fa:
	/* 0x22fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22fc:
	/* 0x22fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22ff:
	/* 0x22ff: cmovns rcx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_64, X86_CC_NS);
x86_l_2303:
	/* 0x2303: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2306:
	/* 0x2306: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2309:
	/* 0x2309: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_230d:
	/* 0x230d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_230e:
	/* 0x230e: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2310:
	/* 0x2310: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2312:
	/* 0x2312: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2313:
	/* 0x2313: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2315:
	/* 0x2315: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2317:
	/* 0x2317: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2319:
	/* 0x2319: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_231a:
	/* 0x231a: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_231e:
	/* 0x231e: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_2321:
	/* 0x2321: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2324:
	/* 0x2324: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2327:
	/* 0x2327: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_232b:
	/* 0x232b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2330:
	/* 0x2330: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_2335:
	/* 0x2335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2337:
	/* 0x2337: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_233a:
	/* 0x233a: js     24b6 <__do_str+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24b6;
	}
x86_l_2340:
	/* 0x2340: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_2346:
	/* 0x2346: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_234a:
	/* 0x234a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_234d:
	/* 0x234d: je     245e <__do_str+0x14b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_245e;
	}
x86_l_2353:
	/* 0x2353: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2356:
	/* 0x2356: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_235a:
	/* 0x235a: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2361:
	/* 0x2361: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2365:
	/* 0x2365: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_236d:
	/* 0x236d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2372:
	/* 0x2372: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_2379:
	/* 0x2379: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_237e:
	/* 0x237e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2380:
	/* 0x2380: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2383:
	/* 0x2383: je     23fc <__do_str+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23fc;
	}
x86_l_2385:
	/* 0x2385: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2389:
	/* 0x2389: je     23fc <__do_str+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23fc;
	}
x86_l_238b:
	/* 0x238b: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2390:
	/* 0x2390: mov    rsi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_2397:
	/* 0x2397: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_239c:
	/* 0x239c: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_239f:
	/* 0x239f: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_23a2:
	/* 0x23a2: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_23a5:
	/* 0x23a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a7:
	/* 0x23a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23aa:
	/* 0x23aa: jns    24b0 <__do_str+0x19d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_24b0;
	}
x86_l_23b0:
	/* 0x23b0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_23b3:
	/* 0x23b3: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_23bb:
	/* 0x23bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23c0:
	/* 0x23c0: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_23c7:
	/* 0x23c7: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_23cc:
	/* 0x23cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ce:
	/* 0x23ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d1:
	/* 0x23d1: je     24b0 <__do_str+0x19d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24b0;
	}
x86_l_23d7:
	/* 0x23d7: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_23db:
	/* 0x23db: jg     247c <__do_str+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_247c;
	}
x86_l_23e1:
	/* 0x23e1: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_23e5:
	/* 0x23e5: je     2496 <__do_str+0x183> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2496;
	}
x86_l_23eb:
	/* 0x23eb: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_23ef:
	/* 0x23ef: jne    2450 <__do_str+0x13d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2450;
	}
x86_l_23f1:
	/* 0x23f1: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_23f7:
	/* 0x23f7: jmp    24ac <__do_str+0x199> */
	goto x86_l_24ac;
x86_l_23fc:
	/* 0x23fc: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_2401:
	/* 0x2401: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_2408:
	/* 0x2408: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_240b:
	/* 0x240b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_240e:
	/* 0x240e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2410:
	/* 0x2410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2412:
	/* 0x2412: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2415:
	/* 0x2415: jns    24b0 <__do_str+0x19d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_24b0;
	}
x86_l_241b:
	/* 0x241b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_241e:
	/* 0x241e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2426:
	/* 0x2426: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242b:
	/* 0x242b: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_2432:
	/* 0x2432: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2437:
	/* 0x2437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2439:
	/* 0x2439: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_243c:
	/* 0x243c: je     24b0 <__do_str+0x19d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24b0;
	}
x86_l_243e:
	/* 0x243e: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2442:
	/* 0x2442: jg     2462 <__do_str+0x14f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2462;
	}
x86_l_2444:
	/* 0x2444: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2448:
	/* 0x2448: je     2496 <__do_str+0x183> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2496;
	}
x86_l_244a:
	/* 0x244a: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_244e:
	/* 0x244e: je     23f1 <__do_str+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f1;
	}
x86_l_2450:
	/* 0x2450: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_2454:
	/* 0x2454: jne    248e <__do_str+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_248e;
	}
x86_l_2456:
	/* 0x2456: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_245c:
	/* 0x245c: jmp    24ac <__do_str+0x199> */
	goto x86_l_24ac;
x86_l_245e:
	/* 0x245e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2460:
	/* 0x2460: jmp    24b6 <__do_str+0x1a3> */
	goto x86_l_24b6;
x86_l_2462:
	/* 0x2462: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_2466:
	/* 0x2466: je     249e <__do_str+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_249e;
	}
x86_l_2468:
	/* 0x2468: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_246c:
	/* 0x246c: je     24a6 <__do_str+0x193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a6;
	}
x86_l_246e:
	/* 0x246e: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_2472:
	/* 0x2472: jne    248e <__do_str+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_248e;
	}
x86_l_2474:
	/* 0x2474: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_247a:
	/* 0x247a: jmp    24ac <__do_str+0x199> */
	goto x86_l_24ac;
x86_l_247c:
	/* 0x247c: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_2480:
	/* 0x2480: je     249e <__do_str+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_249e;
	}
x86_l_2482:
	/* 0x2482: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_2486:
	/* 0x2486: je     24a6 <__do_str+0x193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a6;
	}
x86_l_2488:
	/* 0x2488: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_248c:
	/* 0x248c: je     2474 <__do_str+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2474;
	}
x86_l_248e:
	/* 0x248e: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_2494:
	/* 0x2494: jmp    24ac <__do_str+0x199> */
	goto x86_l_24ac;
x86_l_2496:
	/* 0x2496: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_249c:
	/* 0x249c: jmp    24ac <__do_str+0x199> */
	goto x86_l_24ac;
x86_l_249e:
	/* 0x249e: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_24a4:
	/* 0x24a4: jmp    24ac <__do_str+0x199> */
	goto x86_l_24ac;
x86_l_24a6:
	/* 0x24a6: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_24ac:
	/* 0x24ac: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_24b0:
	/* 0x24b0: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_24b3:
	/* 0x24b3: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_24b6:
	/* 0x24b6: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_24ba:
	/* 0x24ba: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_24bb:
	/* 0x24bb: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_24bd:
	/* 0x24bd: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_24bf:
	/* 0x24bf: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_24c1:
	/* 0x24c1: ret */
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
	for (__u32 __x86_iter = 0; __x86_iter < 8856U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1703ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1708ULL && __x86_pc <= 3494ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3499ULL && __x86_pc <= 5215ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5222ULL && __x86_pc <= 6985ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6990ULL && __x86_pc <= 8373ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8379ULL && __x86_pc <= 9409ULL)
			__x86_pc = tetragon_bpf_execve_event_v61_event_execve_x86_chunk_5(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

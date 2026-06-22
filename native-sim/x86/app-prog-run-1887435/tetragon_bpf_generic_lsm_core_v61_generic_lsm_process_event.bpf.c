extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char data_heap;
extern char fdinstall_map;
extern char lsm_calls;
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

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_0(
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
	case 171ULL: goto x86_l_ab;
	case 174ULL: goto x86_l_ae;
	case 177ULL: goto x86_l_b1;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 189ULL: goto x86_l_bd;
	case 191ULL: goto x86_l_bf;
	case 203ULL: goto x86_l_cb;
	case 209ULL: goto x86_l_d1;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 224ULL: goto x86_l_e0;
	case 226ULL: goto x86_l_e2;
	case 228ULL: goto x86_l_e4;
	case 230ULL: goto x86_l_e6;
	case 234ULL: goto x86_l_ea;
	case 236ULL: goto x86_l_ec;
	case 240ULL: goto x86_l_f0;
	case 243ULL: goto x86_l_f3;
	case 251ULL: goto x86_l_fb;
	case 253ULL: goto x86_l_fd;
	case 265ULL: goto x86_l_109;
	case 267ULL: goto x86_l_10b;
	case 272ULL: goto x86_l_110;
	case 284ULL: goto x86_l_11c;
	case 286ULL: goto x86_l_11e;
	case 288ULL: goto x86_l_120;
	case 293ULL: goto x86_l_125;
	case 298ULL: goto x86_l_12a;
	case 301ULL: goto x86_l_12d;
	case 304ULL: goto x86_l_130;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 317ULL: goto x86_l_13d;
	case 320ULL: goto x86_l_140;
	case 325ULL: goto x86_l_145;
	case 333ULL: goto x86_l_14d;
	case 336ULL: goto x86_l_150;
	case 342ULL: goto x86_l_156;
	case 346ULL: goto x86_l_15a;
	case 349ULL: goto x86_l_15d;
	case 355ULL: goto x86_l_163;
	case 361ULL: goto x86_l_169;
	case 364ULL: goto x86_l_16c;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 381ULL: goto x86_l_17d;
	case 386ULL: goto x86_l_182;
	case 391ULL: goto x86_l_187;
	case 395ULL: goto x86_l_18b;
	case 401ULL: goto x86_l_191;
	case 409ULL: goto x86_l_199;
	case 416ULL: goto x86_l_1a0;
	case 419ULL: goto x86_l_1a3;
	case 421ULL: goto x86_l_1a5;
	case 424ULL: goto x86_l_1a8;
	case 426ULL: goto x86_l_1aa;
	case 431ULL: goto x86_l_1af;
	case 436ULL: goto x86_l_1b4;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 446ULL: goto x86_l_1be;
	case 448ULL: goto x86_l_1c0;
	case 450ULL: goto x86_l_1c2;
	case 453ULL: goto x86_l_1c5;
	case 457ULL: goto x86_l_1c9;
	case 459ULL: goto x86_l_1cb;
	case 464ULL: goto x86_l_1d0;
	case 471ULL: goto x86_l_1d7;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 492ULL: goto x86_l_1ec;
	case 494ULL: goto x86_l_1ee;
	case 499ULL: goto x86_l_1f3;
	case 501ULL: goto x86_l_1f5;
	case 506ULL: goto x86_l_1fa;
	case 508ULL: goto x86_l_1fc;
	case 513ULL: goto x86_l_201;
	case 520ULL: goto x86_l_208;
	case 525ULL: goto x86_l_20d;
	case 530ULL: goto x86_l_212;
	case 532ULL: goto x86_l_214;
	case 534ULL: goto x86_l_216;
	case 536ULL: goto x86_l_218;
	case 539ULL: goto x86_l_21b;
	case 547ULL: goto x86_l_223;
	case 550ULL: goto x86_l_226;
	case 558ULL: goto x86_l_22e;
	case 564ULL: goto x86_l_234;
	case 568ULL: goto x86_l_238;
	case 570ULL: goto x86_l_23a;
	case 574ULL: goto x86_l_23e;
	case 579ULL: goto x86_l_243;
	case 581ULL: goto x86_l_245;
	case 585ULL: goto x86_l_249;
	case 591ULL: goto x86_l_24f;
	case 595ULL: goto x86_l_253;
	case 601ULL: goto x86_l_259;
	case 606ULL: goto x86_l_25e;
	case 609ULL: goto x86_l_261;
	case 615ULL: goto x86_l_267;
	case 619ULL: goto x86_l_26b;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 634ULL: goto x86_l_27a;
	case 639ULL: goto x86_l_27f;
	case 641ULL: goto x86_l_281;
	case 645ULL: goto x86_l_285;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 659ULL: goto x86_l_293;
	case 665ULL: goto x86_l_299;
	case 669ULL: goto x86_l_29d;
	case 675ULL: goto x86_l_2a3;
	case 679ULL: goto x86_l_2a7;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 714ULL: goto x86_l_2ca;
	case 719ULL: goto x86_l_2cf;
	case 722ULL: goto x86_l_2d2;
	case 728ULL: goto x86_l_2d8;
	case 733ULL: goto x86_l_2dd;
	case 737ULL: goto x86_l_2e1;
	case 743ULL: goto x86_l_2e7;
	case 747ULL: goto x86_l_2eb;
	case 753ULL: goto x86_l_2f1;
	case 757ULL: goto x86_l_2f5;
	case 763ULL: goto x86_l_2fb;
	case 767ULL: goto x86_l_2ff;
	case 773ULL: goto x86_l_305;
	case 778ULL: goto x86_l_30a;
	case 782ULL: goto x86_l_30e;
	case 788ULL: goto x86_l_314;
	case 792ULL: goto x86_l_318;
	case 798ULL: goto x86_l_31e;
	case 802ULL: goto x86_l_322;
	case 808ULL: goto x86_l_328;
	case 812ULL: goto x86_l_32c;
	case 818ULL: goto x86_l_332;
	case 824ULL: goto x86_l_338;
	case 829ULL: goto x86_l_33d;
	case 833ULL: goto x86_l_341;
	case 839ULL: goto x86_l_347;
	case 843ULL: goto x86_l_34b;
	case 849ULL: goto x86_l_351;
	case 853ULL: goto x86_l_355;
	case 859ULL: goto x86_l_35b;
	case 863ULL: goto x86_l_35f;
	case 869ULL: goto x86_l_365;
	case 874ULL: goto x86_l_36a;
	case 878ULL: goto x86_l_36e;
	case 880ULL: goto x86_l_370;
	case 885ULL: goto x86_l_375;
	case 889ULL: goto x86_l_379;
	case 895ULL: goto x86_l_37f;
	case 899ULL: goto x86_l_383;
	case 901ULL: goto x86_l_385;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 911ULL: goto x86_l_38f;
	case 913ULL: goto x86_l_391;
	case 919ULL: goto x86_l_397;
	case 921ULL: goto x86_l_399;
	case 927ULL: goto x86_l_39f;
	case 929ULL: goto x86_l_3a1;
	case 933ULL: goto x86_l_3a5;
	case 935ULL: goto x86_l_3a7;
	case 939ULL: goto x86_l_3ab;
	case 941ULL: goto x86_l_3ad;
	case 947ULL: goto x86_l_3b3;
	case 949ULL: goto x86_l_3b5;
	case 953ULL: goto x86_l_3b9;
	case 955ULL: goto x86_l_3bb;
	case 959ULL: goto x86_l_3bf;
	case 961ULL: goto x86_l_3c1;
	case 963ULL: goto x86_l_3c3;
	case 969ULL: goto x86_l_3c9;
	case 971ULL: goto x86_l_3cb;
	case 975ULL: goto x86_l_3cf;
	case 977ULL: goto x86_l_3d1;
	case 981ULL: goto x86_l_3d5;
	case 983ULL: goto x86_l_3d7;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 997ULL: goto x86_l_3e5;
	case 999ULL: goto x86_l_3e7;
	case 1005ULL: goto x86_l_3ed;
	case 1007ULL: goto x86_l_3ef;
	case 1011ULL: goto x86_l_3f3;
	case 1013ULL: goto x86_l_3f5;
	case 1019ULL: goto x86_l_3fb;
	case 1021ULL: goto x86_l_3fd;
	case 1024ULL: goto x86_l_400;
	case 1029ULL: goto x86_l_405;
	case 1040ULL: goto x86_l_410;
	case 1045ULL: goto x86_l_415;
	case 1052ULL: goto x86_l_41c;
	case 1060ULL: goto x86_l_424;
	case 1062ULL: goto x86_l_426;
	case 1065ULL: goto x86_l_429;
	case 1071ULL: goto x86_l_42f;
	case 1076ULL: goto x86_l_434;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1088ULL: goto x86_l_440;
	case 1093ULL: goto x86_l_445;
	case 1100ULL: goto x86_l_44c;
	case 1107ULL: goto x86_l_453;
	case 1111ULL: goto x86_l_457;
	case 1119ULL: goto x86_l_45f;
	case 1124ULL: goto x86_l_464;
	case 1126ULL: goto x86_l_466;
	case 1132ULL: goto x86_l_46c;
	case 1135ULL: goto x86_l_46f;
	case 1142ULL: goto x86_l_476;
	case 1149ULL: goto x86_l_47d;
	case 1152ULL: goto x86_l_480;
	case 1157ULL: goto x86_l_485;
	case 1162ULL: goto x86_l_48a;
	case 1174ULL: goto x86_l_496;
	case 1178ULL: goto x86_l_49a;
	case 1183ULL: goto x86_l_49f;
	case 1188ULL: goto x86_l_4a4;
	case 1190ULL: goto x86_l_4a6;
	case 1194ULL: goto x86_l_4aa;
	case 1196ULL: goto x86_l_4ac;
	case 1200ULL: goto x86_l_4b0;
	case 1202ULL: goto x86_l_4b2;
	case 1206ULL: goto x86_l_4b6;
	case 1212ULL: goto x86_l_4bc;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1232ULL: goto x86_l_4d0;
	case 1234ULL: goto x86_l_4d2;
	case 1239ULL: goto x86_l_4d7;
	case 1244ULL: goto x86_l_4dc;
	case 1246ULL: goto x86_l_4de;
	case 1250ULL: goto x86_l_4e2;
	case 1256ULL: goto x86_l_4e8;
	case 1260ULL: goto x86_l_4ec;
	case 1266ULL: goto x86_l_4f2;
	case 1271ULL: goto x86_l_4f7;
	case 1276ULL: goto x86_l_4fc;
	case 1281ULL: goto x86_l_501;
	case 1283ULL: goto x86_l_503;
	case 1295ULL: goto x86_l_50f;
	case 1303ULL: goto x86_l_517;
	case 1311ULL: goto x86_l_51f;
	case 1313ULL: goto x86_l_521;
	case 1317ULL: goto x86_l_525;
	case 1322ULL: goto x86_l_52a;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1337ULL: goto x86_l_539;
	case 1342ULL: goto x86_l_53e;
	case 1344ULL: goto x86_l_540;
	case 1349ULL: goto x86_l_545;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1369ULL: goto x86_l_559;
	case 1374ULL: goto x86_l_55e;
	case 1381ULL: goto x86_l_565;
	case 1389ULL: goto x86_l_56d;
	case 1391ULL: goto x86_l_56f;
	case 1394ULL: goto x86_l_572;
	case 1400ULL: goto x86_l_578;
	case 1403ULL: goto x86_l_57b;
	case 1408ULL: goto x86_l_580;
	case 1414ULL: goto x86_l_586;
	case 1419ULL: goto x86_l_58b;
	case 1424ULL: goto x86_l_590;
	case 1426ULL: goto x86_l_592;
	case 1433ULL: goto x86_l_599;
	case 1438ULL: goto x86_l_59e;
	case 1446ULL: goto x86_l_5a6;
	case 1451ULL: goto x86_l_5ab;
	case 1453ULL: goto x86_l_5ad;
	case 1461ULL: goto x86_l_5b5;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1475ULL: goto x86_l_5c3;
	case 1479ULL: goto x86_l_5c7;
	case 1484ULL: goto x86_l_5cc;
	case 1492ULL: goto x86_l_5d4;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1504ULL: goto x86_l_5e0;
	case 1512ULL: goto x86_l_5e8;
	case 1516ULL: goto x86_l_5ec;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1533ULL: goto x86_l_5fd;
	case 1539ULL: goto x86_l_603;
	case 1545ULL: goto x86_l_609;
	case 1547ULL: goto x86_l_60b;
	case 1552ULL: goto x86_l_610;
	case 1554ULL: goto x86_l_612;
	case 1557ULL: goto x86_l_615;
	case 1562ULL: goto x86_l_61a;
	case 1567ULL: goto x86_l_61f;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1600ULL: goto x86_l_640;
	case 1603ULL: goto x86_l_643;
	case 1610ULL: goto x86_l_64a;
	case 1620ULL: goto x86_l_654;
	case 1627ULL: goto x86_l_65b;
	case 1637ULL: goto x86_l_665;
	case 1643ULL: goto x86_l_66b;
	case 1652ULL: goto x86_l_674;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1679ULL: goto x86_l_68f;
	case 1691ULL: goto x86_l_69b;
	case 1703ULL: goto x86_l_6a7;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1728ULL: goto x86_l_6c0;
	case 1736ULL: goto x86_l_6c8;
	case 1744ULL: goto x86_l_6d0;
	case 1752ULL: goto x86_l_6d8;
	case 1756ULL: goto x86_l_6dc;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1774ULL: goto x86_l_6ee;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1784ULL: goto x86_l_6f8;
	case 1789ULL: goto x86_l_6fd;
	case 1794ULL: goto x86_l_702;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1814ULL: goto x86_l_716;
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x1b7] */
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
	/* 0x31: je     2f11 <generic_lsm_process_event+0x2f11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12049ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r13d,DWORD PTR [rax+0x5efc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_41:
	/* 0x41: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_44:
	/* 0x44: cmp    rbp,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 8999ULL);
x86_l_4b:
	/* 0x4b: ja     2e7d <generic_lsm_process_event+0x2e7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11901ULL;
	}
x86_l_51:
	/* 0x51: mov    DWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_5c:
	/* 0x5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_61:
	/* 0x61: mov    rdi,QWORD PTR [rip+0x1b0] */
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
	/* 0x75: je     2e7d <generic_lsm_process_event+0x2e7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11901ULL;
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
	/* 0x8a: mov    rdi,QWORD PTR [rip+0x1b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_91:
	/* 0x91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93:
	/* 0x93: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_97:
	/* 0x97: jg     2e7d <generic_lsm_process_event+0x2e7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11901ULL;
	}
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: je     2e7d <generic_lsm_process_event+0x2e7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11901ULL;
	}
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ab:
	/* 0xab: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_ae:
	/* 0xae: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b1:
	/* 0xb1: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_b3:
	/* 0xb3: mov    r12d,DWORD PTR [rax+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_b8:
	/* 0xb8: movsxd rsi,DWORD PTR [rax+rbp*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RBP, 2, X86_WIDTH_32), 24ULL);
x86_l_bd:
	/* 0xbd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_bf:
	/* 0xbf: mov    DWORD PTR [r15+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_cb:
	/* 0xcb: test   esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_d1:
	/* 0xd1: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d6:
	/* 0xd6: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_db:
	/* 0xdb: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e0:
	/* 0xe0: jne    fd <generic_lsm_process_event+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fd;
	}
x86_l_e2:
	/* 0xe2: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_e4:
	/* 0xe4: js     110 <generic_lsm_process_event+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_110;
	}
x86_l_e6:
	/* 0xe6: test   sil,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 64ULL);
x86_l_ea:
	/* 0xea: jne    120 <generic_lsm_process_event+0x120> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_120;
	}
x86_l_ec:
	/* 0xec: mov    ecx,DWORD PTR [rax+rdx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 64ULL);
x86_l_f0:
	/* 0xf0: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f3:
	/* 0xf3: mov    rsi,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_fb:
	/* 0xfb: jmp    145 <generic_lsm_process_event+0x145> */
	goto x86_l_145;
x86_l_fd:
	/* 0xfd: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_109:
	/* 0x109: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b:
	/* 0x10b: jmp    22e <generic_lsm_process_event+0x22e> */
	goto x86_l_22e;
x86_l_110:
	/* 0x110: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_11c:
	/* 0x11c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e:
	/* 0x11e: jmp    14d <generic_lsm_process_event+0x14d> */
	goto x86_l_14d;
x86_l_120:
	/* 0x120: mov    ecx,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 35ULL);
x86_l_125:
	/* 0x125: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12a:
	/* 0x12a: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_12d:
	/* 0x12d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_130:
	/* 0x130: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_132:
	/* 0x132: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_137:
	/* 0x137: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13a:
	/* 0x13a: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_13d:
	/* 0x13d: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_140:
	/* 0x140: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_145:
	/* 0x145: mov    QWORD PTR [rsp+0xe0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_14d:
	/* 0x14d: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_150:
	/* 0x150: ja     22e <generic_lsm_process_event+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_22e;
	}
x86_l_156:
	/* 0x156: lea    rcx,[rdx+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_15a:
	/* 0x15a: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_15d:
	/* 0x15d: cmp    WORD PTR [rax+rcx*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 506806140928ULL);
x86_l_163:
	/* 0x163: je     22e <generic_lsm_process_event+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22e;
	}
x86_l_169:
	/* 0x169: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16c:
	/* 0x16c: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_170:
	/* 0x170: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_175:
	/* 0x175: lea    rax,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_17d:
	/* 0x17d: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_182:
	/* 0x182: mov    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_187:
	/* 0x187: lea    rax,[r15+rbp*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_18b:
	/* 0x18b: add    rax,0x5ea0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24224ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_199:
	/* 0x199: mov    rax,QWORD PTR [rip+0x1b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1a0:
	/* 0x1a0: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a3:
	/* 0x1a3: je     1fc <generic_lsm_process_event+0x1fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fc;
	}
x86_l_1a5:
	/* 0x1a5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8:
	/* 0x1a8: jmp    1cb <generic_lsm_process_event+0x1cb> */
	goto x86_l_1cb;
x86_l_1aa:
	/* 0x1aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1af:
	/* 0x1af: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b4:
	/* 0x1b4: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b7:
	/* 0x1b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bc:
	/* 0x1bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be:
	/* 0x1be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c0:
	/* 0x1c0: js     218 <generic_lsm_process_event+0x218> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_218;
	}
x86_l_1c2:
	/* 0x1c2: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1c5:
	/* 0x1c5: cmp    r15,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 10ULL);
x86_l_1c9:
	/* 0x1c9: je     226 <generic_lsm_process_event+0x226> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_226;
	}
x86_l_1cb:
	/* 0x1cb: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d0:
	/* 0x1d0: cmp    WORD PTR [rax+r15*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 25769803776ULL);
x86_l_1d7:
	/* 0x1d7: je     226 <generic_lsm_process_event+0x226> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_226;
	}
x86_l_1d9:
	/* 0x1d9: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1de:
	/* 0x1de: mov    edx,DWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_1e2:
	/* 0x1e2: add    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e5:
	/* 0x1e5: cmp    WORD PTR [rax+r15*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 17179869184ULL);
x86_l_1ec:
	/* 0x1ec: je     1c2 <generic_lsm_process_event+0x1c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2;
	}
x86_l_1ee:
	/* 0x1ee: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1f3:
	/* 0x1f3: je     1aa <generic_lsm_process_event+0x1aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aa;
	}
x86_l_1f5:
	/* 0x1f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fa:
	/* 0x1fa: jmp    1af <generic_lsm_process_event+0x1af> */
	goto x86_l_1af;
x86_l_1fc:
	/* 0x1fc: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_201:
	/* 0x201: lea    rsi,[rip+0x1b7] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 439ULL);
x86_l_208:
	/* 0x208: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20d:
	/* 0x20d: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_212:
	/* 0x212: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_214:
	/* 0x214: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216:
	/* 0x216: jmp    226 <generic_lsm_process_event+0x226> */
	goto x86_l_226;
x86_l_218:
	/* 0x218: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_21b:
	/* 0x21b: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_223:
	/* 0x223: mov    DWORD PTR [rax],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226:
	/* 0x226: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_22e:
	/* 0x22e: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_234:
	/* 0x234: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_238:
	/* 0x238: jg     276 <generic_lsm_process_event+0x276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_276;
	}
x86_l_23a:
	/* 0x23a: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_23e:
	/* 0x23e: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_243:
	/* 0x243: jg     2b2 <generic_lsm_process_event+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b2;
	}
x86_l_245:
	/* 0x245: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_249:
	/* 0x249: jg     33d <generic_lsm_process_event+0x33d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_33d;
	}
x86_l_24f:
	/* 0x24f: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_253:
	/* 0x253: jg     3cb <generic_lsm_process_event+0x3cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3cb;
	}
x86_l_259:
	/* 0x259: lea    eax,[r12-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_25e:
	/* 0x25e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_261:
	/* 0x261: jb     391 <generic_lsm_process_event+0x391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_391;
	}
x86_l_267:
	/* 0x267: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_26b:
	/* 0x26b: je     391 <generic_lsm_process_event+0x391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_391;
	}
x86_l_271:
	/* 0x271: jmp    3fd <generic_lsm_process_event+0x3fd> */
	goto x86_l_3fd;
x86_l_276:
	/* 0x276: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_27a:
	/* 0x27a: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27f:
	/* 0x27f: jle    2dd <generic_lsm_process_event+0x2dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2dd;
	}
x86_l_281:
	/* 0x281: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_285:
	/* 0x285: jg     30a <generic_lsm_process_event+0x30a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30a;
	}
x86_l_28b:
	/* 0x28b: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_290:
	/* 0x290: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_293:
	/* 0x293: jb     3df <generic_lsm_process_event+0x3df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3df;
	}
x86_l_299:
	/* 0x299: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_29d:
	/* 0x29d: je     400 <generic_lsm_process_event+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400;
	}
x86_l_2a3:
	/* 0x2a3: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_2a7:
	/* 0x2a7: je     399 <generic_lsm_process_event+0x399> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_399;
	}
x86_l_2ad:
	/* 0x2ad: jmp    3fd <generic_lsm_process_event+0x3fd> */
	goto x86_l_3fd;
x86_l_2b2:
	/* 0x2b2: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_2b6:
	/* 0x2b6: jg     36a <generic_lsm_process_event+0x36a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_36a;
	}
x86_l_2bc:
	/* 0x2bc: lea    eax,[r12-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2c1:
	/* 0x2c1: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2c4:
	/* 0x2c4: jb     400 <generic_lsm_process_event+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_400;
	}
x86_l_2ca:
	/* 0x2ca: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_2cf:
	/* 0x2cf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d2:
	/* 0x2d2: jb     391 <generic_lsm_process_event+0x391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_391;
	}
x86_l_2d8:
	/* 0x2d8: jmp    3fd <generic_lsm_process_event+0x3fd> */
	goto x86_l_3fd;
x86_l_2dd:
	/* 0x2dd: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_2e1:
	/* 0x2e1: jg     387 <generic_lsm_process_event+0x387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_387;
	}
x86_l_2e7:
	/* 0x2e7: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_2eb:
	/* 0x2eb: je     399 <generic_lsm_process_event+0x399> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_399;
	}
x86_l_2f1:
	/* 0x2f1: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_2f5:
	/* 0x2f5: je     3df <generic_lsm_process_event+0x3df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3df;
	}
x86_l_2fb:
	/* 0x2fb: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_2ff:
	/* 0x2ff: je     3f5 <generic_lsm_process_event+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f5;
	}
x86_l_305:
	/* 0x305: jmp    3fd <generic_lsm_process_event+0x3fd> */
	goto x86_l_3fd;
x86_l_30a:
	/* 0x30a: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_30e:
	/* 0x30e: jle    3b5 <generic_lsm_process_event+0x3b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3b5;
	}
x86_l_314:
	/* 0x314: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_318:
	/* 0x318: je     400 <generic_lsm_process_event+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400;
	}
x86_l_31e:
	/* 0x31e: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_322:
	/* 0x322: je     3c3 <generic_lsm_process_event+0x3c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c3;
	}
x86_l_328:
	/* 0x328: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_32c:
	/* 0x32c: jne    3fd <generic_lsm_process_event+0x3fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3fd;
	}
x86_l_332:
	/* 0x332: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_338:
	/* 0x338: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_33d:
	/* 0x33d: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_341:
	/* 0x341: jg     3df <generic_lsm_process_event+0x3df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3df;
	}
x86_l_347:
	/* 0x347: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_34b:
	/* 0x34b: je     400 <generic_lsm_process_event+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400;
	}
x86_l_351:
	/* 0x351: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_355:
	/* 0x355: je     3d7 <generic_lsm_process_event+0x3d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d7;
	}
x86_l_35b:
	/* 0x35b: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_35f:
	/* 0x35f: je     3f5 <generic_lsm_process_event+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f5;
	}
x86_l_365:
	/* 0x365: jmp    3fd <generic_lsm_process_event+0x3fd> */
	goto x86_l_3fd;
x86_l_36a:
	/* 0x36a: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_36e:
	/* 0x36e: jg     3a1 <generic_lsm_process_event+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a1;
	}
x86_l_370:
	/* 0x370: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_375:
	/* 0x375: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_379:
	/* 0x379: je     400 <generic_lsm_process_event+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400;
	}
x86_l_37f:
	/* 0x37f: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_383:
	/* 0x383: je     3c3 <generic_lsm_process_event+0x3c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c3;
	}
x86_l_385:
	/* 0x385: jmp    3fd <generic_lsm_process_event+0x3fd> */
	goto x86_l_3fd;
x86_l_387:
	/* 0x387: lea    eax,[r12-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_38c:
	/* 0x38c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38f:
	/* 0x38f: jae    3ef <generic_lsm_process_event+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3ef;
	}
x86_l_391:
	/* 0x391: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_397:
	/* 0x397: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_399:
	/* 0x399: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_39f:
	/* 0x39f: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_3a1:
	/* 0x3a1: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_3a5:
	/* 0x3a5: je     3e7 <generic_lsm_process_event+0x3e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e7;
	}
x86_l_3a7:
	/* 0x3a7: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_3ab:
	/* 0x3ab: jne    3fd <generic_lsm_process_event+0x3fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3fd;
	}
x86_l_3ad:
	/* 0x3ad: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_3b3:
	/* 0x3b3: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_3b5:
	/* 0x3b5: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_3b9:
	/* 0x3b9: je     3c3 <generic_lsm_process_event+0x3c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c3;
	}
x86_l_3bb:
	/* 0x3bb: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_3bf:
	/* 0x3bf: je     3d7 <generic_lsm_process_event+0x3d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d7;
	}
x86_l_3c1:
	/* 0x3c1: jmp    3fd <generic_lsm_process_event+0x3fd> */
	goto x86_l_3fd;
x86_l_3c3:
	/* 0x3c3: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_3c9:
	/* 0x3c9: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_3cb:
	/* 0x3cb: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3cf:
	/* 0x3cf: je     3df <generic_lsm_process_event+0x3df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3df;
	}
x86_l_3d1:
	/* 0x3d1: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_3d5:
	/* 0x3d5: jne    3fd <generic_lsm_process_event+0x3fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3fd;
	}
x86_l_3d7:
	/* 0x3d7: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_3dd:
	/* 0x3dd: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_3df:
	/* 0x3df: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_3e5:
	/* 0x3e5: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_3e7:
	/* 0x3e7: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_3ed:
	/* 0x3ed: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_3ef:
	/* 0x3ef: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_3f3:
	/* 0x3f3: jne    3fd <generic_lsm_process_event+0x3fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3fd;
	}
x86_l_3f5:
	/* 0x3f5: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_3fb:
	/* 0x3fb: jmp    400 <generic_lsm_process_event+0x400> */
	goto x86_l_400;
x86_l_3fd:
	/* 0x3fd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_400:
	/* 0x400: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_405:
	/* 0x405: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_410:
	/* 0x410: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_415:
	/* 0x415: mov    rdi,QWORD PTR [rip+0x1b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_41c:
	/* 0x41c: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_424:
	/* 0x424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_426:
	/* 0x426: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_429:
	/* 0x429: je     2e7d <generic_lsm_process_event+0x2e7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11901ULL;
	}
x86_l_42f:
	/* 0x42f: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_434:
	/* 0x434: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_437:
	/* 0x437: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_43a:
	/* 0x43a: jbe    2e7d <generic_lsm_process_event+0x2e7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11901ULL;
	}
x86_l_440:
	/* 0x440: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_445:
	/* 0x445: mov    ecx,DWORD PTR [rax+rdx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_44c:
	/* 0x44c: mov    DWORD PTR [rax+rbp*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_453:
	/* 0x453: lea    r15,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_457:
	/* 0x457: mov    QWORD PTR [rax+rdx*8+0x5e78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_45f:
	/* 0x45f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_464:
	/* 0x464: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_466:
	/* 0x466: jne    2e79 <generic_lsm_process_event+0x2e79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11897ULL;
	}
x86_l_46c:
	/* 0x46c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_46f:
	/* 0x46f: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_476:
	/* 0x476: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_47d:
	/* 0x47d: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_480:
	/* 0x480: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_485:
	/* 0x485: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_48a:
	/* 0x48a: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_496:
	/* 0x496: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_49a:
	/* 0x49a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_49f:
	/* 0x49f: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4a4:
	/* 0x4a4: jle    4de <generic_lsm_process_event+0x4de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4de;
	}
x86_l_4a6:
	/* 0x4a6: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_4aa:
	/* 0x4aa: je     503 <generic_lsm_process_event+0x503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_503;
	}
x86_l_4ac:
	/* 0x4ac: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_4b0:
	/* 0x4b0: je     521 <generic_lsm_process_event+0x521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_521;
	}
x86_l_4b2:
	/* 0x4b2: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_4b6:
	/* 0x4b6: jne    a0d <generic_lsm_process_event+0xa0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2573ULL;
	}
x86_l_4bc:
	/* 0x4bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c1:
	/* 0x4c1: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4c6:
	/* 0x4c6: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4cb:
	/* 0x4cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d0:
	/* 0x4d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d2:
	/* 0x4d2: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d7:
	/* 0x4d7: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4dc:
	/* 0x4dc: jmp    4f2 <generic_lsm_process_event+0x4f2> */
	goto x86_l_4f2;
x86_l_4de:
	/* 0x4de: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_4e2:
	/* 0x4e2: je     939 <generic_lsm_process_event+0x939> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2361ULL;
	}
x86_l_4e8:
	/* 0x4e8: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_4ec:
	/* 0x4ec: jne    a0d <generic_lsm_process_event+0xa0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2573ULL;
	}
x86_l_4f2:
	/* 0x4f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f7:
	/* 0x4f7: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4fc:
	/* 0x4fc: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_501:
	/* 0x501: jmp    539 <generic_lsm_process_event+0x539> */
	goto x86_l_539;
x86_l_503:
	/* 0x503: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_50f:
	/* 0x50f: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_517:
	/* 0x517: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_51f:
	/* 0x51f: jmp    549 <generic_lsm_process_event+0x549> */
	goto x86_l_549;
x86_l_521:
	/* 0x521: add    rdx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_525:
	/* 0x525: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_52a:
	/* 0x52a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52f:
	/* 0x52f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_534:
	/* 0x534: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_539:
	/* 0x539: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53e:
	/* 0x53e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_540:
	/* 0x540: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_545:
	/* 0x545: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_549:
	/* 0x549: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_54e:
	/* 0x54e: mov    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_559:
	/* 0x559: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55e:
	/* 0x55e: mov    rdi,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_565:
	/* 0x565: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_56d:
	/* 0x56d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56f:
	/* 0x56f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_572:
	/* 0x572: je     612 <generic_lsm_process_event+0x612> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_612;
	}
x86_l_578:
	/* 0x578: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_57b:
	/* 0x57b: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_580:
	/* 0x580: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_586:
	/* 0x586: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58b:
	/* 0x58b: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_590:
	/* 0x590: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_592:
	/* 0x592: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_599:
	/* 0x599: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_59e:
	/* 0x59e: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5a6:
	/* 0x5a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ab:
	/* 0x5ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ad:
	/* 0x5ad: mov    rbp,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5b5:
	/* 0x5b5: lea    rax,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b9:
	/* 0x5b9: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5be:
	/* 0x5be: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5c3:
	/* 0x5c3: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c7:
	/* 0x5c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5cc:
	/* 0x5cc: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_5d4:
	/* 0x5d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d9:
	/* 0x5d9: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5de:
	/* 0x5de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e0:
	/* 0x5e0: mov    r15,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_5e8:
	/* 0x5e8: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ec:
	/* 0x5ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5f1:
	/* 0x5f1: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f6:
	/* 0x5f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fb:
	/* 0x5fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fd:
	/* 0x5fd: cmp    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_603:
	/* 0x603: mov    r12d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4096ULL);
x86_l_609:
	/* 0x609: je     61f <generic_lsm_process_event+0x61f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61f;
	}
x86_l_60b:
	/* 0x60b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_610:
	/* 0x610: jmp    66b <generic_lsm_process_event+0x66b> */
	goto x86_l_66b;
x86_l_612:
	/* 0x612: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_615:
	/* 0x615: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_61a:
	/* 0x61a: jmp    b9f <generic_lsm_process_event+0xb9f> */
	return 2975ULL;
x86_l_61f:
	/* 0x61f: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_623:
	/* 0x623: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_628:
	/* 0x628: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_62d:
	/* 0x62d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_632:
	/* 0x632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_634:
	/* 0x634: cmp    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_639:
	/* 0x639: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63e:
	/* 0x63e: je     66b <generic_lsm_process_event+0x66b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_66b;
	}
x86_l_640:
	/* 0x640: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_643:
	/* 0x643: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_64a:
	/* 0x64a: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_654:
	/* 0x654: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_65b:
	/* 0x65b: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_665:
	/* 0x665: mov    r12d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4086ULL);
x86_l_66b:
	/* 0x66b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_674:
	/* 0x674: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_67d:
	/* 0x67d: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_682:
	/* 0x682: lea    r13,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_687:
	/* 0x687: lea    r15,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_68f:
	/* 0x68f: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_69b:
	/* 0x69b: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_6a7:
	/* 0x6a7: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_6b3:
	/* 0x6b3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b8:
	/* 0x6b8: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6c0:
	/* 0x6c0: mov    DWORD PTR [rsp+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6c8:
	/* 0x6c8: lea    r12,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_6d0:
	/* 0x6d0: mov    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_6d8:
	/* 0x6d8: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_6dc:
	/* 0x6dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6e1:
	/* 0x6e1: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6e6:
	/* 0x6e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6eb:
	/* 0x6eb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6ee:
	/* 0x6ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f0:
	/* 0x6f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6f5:
	/* 0x6f5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_6f8:
	/* 0x6f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6fd:
	/* 0x6fd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_702:
	/* 0x702: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_704:
	/* 0x704: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_709:
	/* 0x709: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_70c:
	/* 0x70c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_711:
	/* 0x711: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_716:
	/* 0x716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1816ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1824ULL: goto x86_l_720;
	case 1829ULL: goto x86_l_725;
	case 1834ULL: goto x86_l_72a;
	case 1836ULL: goto x86_l_72c;
	case 1844ULL: goto x86_l_734;
	case 1848ULL: goto x86_l_738;
	case 1856ULL: goto x86_l_740;
	case 1863ULL: goto x86_l_747;
	case 1866ULL: goto x86_l_74a;
	case 1872ULL: goto x86_l_750;
	case 1878ULL: goto x86_l_756;
	case 1886ULL: goto x86_l_75e;
	case 1894ULL: goto x86_l_766;
	case 1902ULL: goto x86_l_76e;
	case 1907ULL: goto x86_l_773;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1933ULL: goto x86_l_78d;
	case 1938ULL: goto x86_l_792;
	case 1940ULL: goto x86_l_794;
	case 1948ULL: goto x86_l_79c;
	case 1954ULL: goto x86_l_7a2;
	case 1958ULL: goto x86_l_7a6;
	case 1963ULL: goto x86_l_7ab;
	case 1968ULL: goto x86_l_7b0;
	case 1973ULL: goto x86_l_7b5;
	case 1976ULL: goto x86_l_7b8;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1989ULL: goto x86_l_7c5;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2007ULL: goto x86_l_7d7;
	case 2009ULL: goto x86_l_7d9;
	case 2013ULL: goto x86_l_7dd;
	case 2018ULL: goto x86_l_7e2;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2034ULL: goto x86_l_7f2;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2049ULL: goto x86_l_801;
	case 2056ULL: goto x86_l_808;
	case 2059ULL: goto x86_l_80b;
	case 2066ULL: goto x86_l_812;
	case 2068ULL: goto x86_l_814;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2078ULL: goto x86_l_81e;
	case 2086ULL: goto x86_l_826;
	case 2089ULL: goto x86_l_829;
	case 2091ULL: goto x86_l_82b;
	case 2095ULL: goto x86_l_82f;
	case 2097ULL: goto x86_l_831;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2106ULL: goto x86_l_83a;
	case 2109ULL: goto x86_l_83d;
	case 2117ULL: goto x86_l_845;
	case 2120ULL: goto x86_l_848;
	case 2126ULL: goto x86_l_84e;
	case 2132ULL: goto x86_l_854;
	case 2138ULL: goto x86_l_85a;
	case 2140ULL: goto x86_l_85c;
	case 2146ULL: goto x86_l_862;
	case 2149ULL: goto x86_l_865;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2162ULL: goto x86_l_872;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2176ULL: goto x86_l_880;
	case 2184ULL: goto x86_l_888;
	case 2187ULL: goto x86_l_88b;
	case 2192ULL: goto x86_l_890;
	case 2200ULL: goto x86_l_898;
	case 2205ULL: goto x86_l_89d;
	case 2208ULL: goto x86_l_8a0;
	case 2214ULL: goto x86_l_8a6;
	case 2219ULL: goto x86_l_8ab;
	case 2223ULL: goto x86_l_8af;
	case 2228ULL: goto x86_l_8b4;
	case 2233ULL: goto x86_l_8b9;
	case 2238ULL: goto x86_l_8be;
	case 2240ULL: goto x86_l_8c0;
	case 2248ULL: goto x86_l_8c8;
	case 2253ULL: goto x86_l_8cd;
	case 2259ULL: goto x86_l_8d3;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2276ULL: goto x86_l_8e4;
	case 2281ULL: goto x86_l_8e9;
	case 2284ULL: goto x86_l_8ec;
	case 2286ULL: goto x86_l_8ee;
	case 2291ULL: goto x86_l_8f3;
	case 2299ULL: goto x86_l_8fb;
	case 2303ULL: goto x86_l_8ff;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2319ULL: goto x86_l_90f;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2352ULL: goto x86_l_930;
	case 2354ULL: goto x86_l_932;
	case 2356ULL: goto x86_l_934;
	case 2361ULL: goto x86_l_939;
	case 2366ULL: goto x86_l_93e;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2386ULL: goto x86_l_952;
	case 2394ULL: goto x86_l_95a;
	case 2399ULL: goto x86_l_95f;
	case 2402ULL: goto x86_l_962;
	case 2408ULL: goto x86_l_968;
	case 2419ULL: goto x86_l_973;
	case 2424ULL: goto x86_l_978;
	case 2431ULL: goto x86_l_97f;
	case 2439ULL: goto x86_l_987;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2460ULL: goto x86_l_99c;
	case 2463ULL: goto x86_l_99f;
	case 2467ULL: goto x86_l_9a3;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2483ULL: goto x86_l_9b3;
	case 2487ULL: goto x86_l_9b7;
	case 2493ULL: goto x86_l_9bd;
	case 2497ULL: goto x86_l_9c1;
	case 2503ULL: goto x86_l_9c7;
	case 2507ULL: goto x86_l_9cb;
	case 2513ULL: goto x86_l_9d1;
	case 2517ULL: goto x86_l_9d5;
	case 2523ULL: goto x86_l_9db;
	case 2527ULL: goto x86_l_9df;
	case 2532ULL: goto x86_l_9e4;
	case 2537ULL: goto x86_l_9e9;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2562ULL: goto x86_l_a02;
	case 2568ULL: goto x86_l_a08;
	case 2573ULL: goto x86_l_a0d;
	case 2577ULL: goto x86_l_a11;
	case 2583ULL: goto x86_l_a17;
	case 2586ULL: goto x86_l_a1a;
	case 2596ULL: goto x86_l_a24;
	case 2600ULL: goto x86_l_a28;
	case 2606ULL: goto x86_l_a2e;
	case 2611ULL: goto x86_l_a33;
	case 2622ULL: goto x86_l_a3e;
	case 2627ULL: goto x86_l_a43;
	case 2634ULL: goto x86_l_a4a;
	case 2642ULL: goto x86_l_a52;
	case 2644ULL: goto x86_l_a54;
	case 2647ULL: goto x86_l_a57;
	case 2653ULL: goto x86_l_a5d;
	case 2656ULL: goto x86_l_a60;
	case 2659ULL: goto x86_l_a63;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2674ULL: goto x86_l_a72;
	case 2678ULL: goto x86_l_a76;
	case 2684ULL: goto x86_l_a7c;
	case 2688ULL: goto x86_l_a80;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2702ULL: goto x86_l_a8e;
	case 2708ULL: goto x86_l_a94;
	case 2714ULL: goto x86_l_a9a;
	case 2719ULL: goto x86_l_a9f;
	case 2724ULL: goto x86_l_aa4;
	case 2727ULL: goto x86_l_aa7;
	case 2732ULL: goto x86_l_aac;
	case 2737ULL: goto x86_l_ab1;
	case 2745ULL: goto x86_l_ab9;
	case 2750ULL: goto x86_l_abe;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2765ULL: goto x86_l_acd;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2778ULL: goto x86_l_ada;
	case 2781ULL: goto x86_l_add;
	case 2788ULL: goto x86_l_ae4;
	case 2794ULL: goto x86_l_aea;
	case 2797ULL: goto x86_l_aed;
	case 2799ULL: goto x86_l_aef;
	case 2803ULL: goto x86_l_af3;
	case 2806ULL: goto x86_l_af6;
	case 2812ULL: goto x86_l_afc;
	case 2815ULL: goto x86_l_aff;
	case 2817ULL: goto x86_l_b01;
	case 2820ULL: goto x86_l_b04;
	case 2822ULL: goto x86_l_b06;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2835ULL: goto x86_l_b13;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2850ULL: goto x86_l_b22;
	case 2852ULL: goto x86_l_b24;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2892ULL: goto x86_l_b4c;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2942ULL: goto x86_l_b7e;
	case 2948ULL: goto x86_l_b84;
	case 2952ULL: goto x86_l_b88;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2985ULL: goto x86_l_ba9;
	case 2988ULL: goto x86_l_bac;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3013ULL: goto x86_l_bc5;
	case 3017ULL: goto x86_l_bc9;
	case 3023ULL: goto x86_l_bcf;
	case 3027ULL: goto x86_l_bd3;
	case 3033ULL: goto x86_l_bd9;
	case 3036ULL: goto x86_l_bdc;
	case 3040ULL: goto x86_l_be0;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3060ULL: goto x86_l_bf4;
	case 3063ULL: goto x86_l_bf7;
	case 3068ULL: goto x86_l_bfc;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3084ULL: goto x86_l_c0c;
	case 3088ULL: goto x86_l_c10;
	case 3092ULL: goto x86_l_c14;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3108ULL: goto x86_l_c24;
	case 3112ULL: goto x86_l_c28;
	case 3116ULL: goto x86_l_c2c;
	case 3121ULL: goto x86_l_c31;
	case 3126ULL: goto x86_l_c36;
	case 3128ULL: goto x86_l_c38;
	case 3132ULL: goto x86_l_c3c;
	case 3139ULL: goto x86_l_c43;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3151ULL: goto x86_l_c4f;
	case 3155ULL: goto x86_l_c53;
	case 3162ULL: goto x86_l_c5a;
	case 3167ULL: goto x86_l_c5f;
	case 3172ULL: goto x86_l_c64;
	case 3174ULL: goto x86_l_c66;
	case 3178ULL: goto x86_l_c6a;
	case 3185ULL: goto x86_l_c71;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3197ULL: goto x86_l_c7d;
	case 3201ULL: goto x86_l_c81;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3218ULL: goto x86_l_c92;
	case 3220ULL: goto x86_l_c94;
	case 3224ULL: goto x86_l_c98;
	case 3232ULL: goto x86_l_ca0;
	case 3240ULL: goto x86_l_ca8;
	case 3248ULL: goto x86_l_cb0;
	case 3256ULL: goto x86_l_cb8;
	case 3260ULL: goto x86_l_cbc;
	case 3263ULL: goto x86_l_cbf;
	case 3269ULL: goto x86_l_cc5;
	case 3272ULL: goto x86_l_cc8;
	case 3278ULL: goto x86_l_cce;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3315ULL: goto x86_l_cf3;
	case 3320ULL: goto x86_l_cf8;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3332ULL: goto x86_l_d04;
	case 3335ULL: goto x86_l_d07;
	case 3337ULL: goto x86_l_d09;
	case 3345ULL: goto x86_l_d11;
	case 3350ULL: goto x86_l_d16;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3372ULL: goto x86_l_d2c;
	case 3378ULL: goto x86_l_d32;
	case 3382ULL: goto x86_l_d36;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3397ULL: goto x86_l_d45;
	case 3403ULL: goto x86_l_d4b;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3431ULL: goto x86_l_d67;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3445ULL: goto x86_l_d75;
	case 3451ULL: goto x86_l_d7b;
	case 3455ULL: goto x86_l_d7f;
	case 3461ULL: goto x86_l_d85;
	case 3464ULL: goto x86_l_d88;
	case 3469ULL: goto x86_l_d8d;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3487ULL: goto x86_l_d9f;
	case 3489ULL: goto x86_l_da1;
	case 3494ULL: goto x86_l_da6;
	case 3499ULL: goto x86_l_dab;
	case 3502ULL: goto x86_l_dae;
	case 3507ULL: goto x86_l_db3;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3530ULL: goto x86_l_dca;
	case 3533ULL: goto x86_l_dcd;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3549ULL: goto x86_l_ddd;
	case 3553ULL: goto x86_l_de1;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3565ULL: goto x86_l_ded;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3582ULL: goto x86_l_dfe;
	case 3588ULL: goto x86_l_e04;
	case 3593ULL: goto x86_l_e09;
	case 3598ULL: goto x86_l_e0e;
	case 3603ULL: goto x86_l_e13;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3625ULL: goto x86_l_e29;
	default: return 0xffffffffffffffffULL;
	}
x86_l_718:
	/* 0x718: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_71d:
	/* 0x71d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_720:
	/* 0x720: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_725:
	/* 0x725: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_72a:
	/* 0x72a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72c:
	/* 0x72c: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_734:
	/* 0x734: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_738:
	/* 0x738: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_740:
	/* 0x740: mov    rax,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_747:
	/* 0x747: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_74a:
	/* 0x74a: je     91a <generic_lsm_process_event+0x91a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_91a;
	}
x86_l_750:
	/* 0x750: mov    r12d,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2048ULL);
x86_l_756:
	/* 0x756: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_75e:
	/* 0x75e: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_766:
	/* 0x766: mov    rbp,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_76e:
	/* 0x76e: cmp    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_773:
	/* 0x773: jne    780 <generic_lsm_process_event+0x780> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_780;
	}
x86_l_775:
	/* 0x775: cmp    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_77a:
	/* 0x77a: je     ab1 <generic_lsm_process_event+0xab1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab1;
	}
x86_l_780:
	/* 0x780: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_785:
	/* 0x785: lea    rdi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_78d:
	/* 0x78d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_792:
	/* 0x792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_794:
	/* 0x794: cmp    r13,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 216ULL);
x86_l_79c:
	/* 0x79c: je     8ab <generic_lsm_process_event+0x8ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ab;
	}
x86_l_7a2:
	/* 0x7a2: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a6:
	/* 0x7a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7ab:
	/* 0x7ab: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7b0:
	/* 0x7b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7b5:
	/* 0x7b5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7b8:
	/* 0x7b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ba:
	/* 0x7ba: cmp    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7bf:
	/* 0x7bf: je     8ab <generic_lsm_process_event+0x8ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ab;
	}
x86_l_7c5:
	/* 0x7c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7ca:
	/* 0x7ca: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7cf:
	/* 0x7cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7d4:
	/* 0x7d4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7d7:
	/* 0x7d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d9:
	/* 0x7d9: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7dd:
	/* 0x7dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7e2:
	/* 0x7e2: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7ea:
	/* 0x7ea: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_7ef:
	/* 0x7ef: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7f2:
	/* 0x7f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f4:
	/* 0x7f4: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7f9:
	/* 0x7f9: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_801:
	/* 0x801: mov    ecx,DWORD PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_808:
	/* 0x808: sub    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_80b:
	/* 0x80b: mov    esi,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_812:
	/* 0x812: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_814:
	/* 0x814: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_816:
	/* 0x816: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_81b:
	/* 0x81b: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_81e:
	/* 0x81e: add    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 184ULL);
x86_l_826:
	/* 0x826: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_829:
	/* 0x829: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_82b:
	/* 0x82b: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_82f:
	/* 0x82f: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_831:
	/* 0x831: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_834:
	/* 0x834: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_837:
	/* 0x837: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_83a:
	/* 0x83a: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_83d:
	/* 0x83d: mov    DWORD PTR [rsp+0xa0],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_845:
	/* 0x845: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_848:
	/* 0x848: jb     ab9 <generic_lsm_process_event+0xab9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ab9;
	}
x86_l_84e:
	/* 0x84e: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_854:
	/* 0x854: ja     ab9 <generic_lsm_process_event+0xab9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ab9;
	}
x86_l_85a:
	/* 0x85a: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_85c:
	/* 0x85c: jbe    cf8 <generic_lsm_process_event+0xcf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_cf8;
	}
x86_l_862:
	/* 0x862: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_865:
	/* 0x865: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_869:
	/* 0x869: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_86e:
	/* 0x86e: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_872:
	/* 0x872: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_876:
	/* 0x876: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_879:
	/* 0x879: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_87e:
	/* 0x87e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_880:
	/* 0x880: mov    QWORD PTR [rsp+0x98],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_888:
	/* 0x888: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_88b:
	/* 0x88b: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_890:
	/* 0x890: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_898:
	/* 0x898: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_89d:
	/* 0x89d: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_8a0:
	/* 0x8a0: jne    756 <generic_lsm_process_event+0x756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_756;
	}
x86_l_8a6:
	/* 0x8a6: jmp    abe <generic_lsm_process_event+0xabe> */
	goto x86_l_abe;
x86_l_8ab:
	/* 0x8ab: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8af:
	/* 0x8af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8b4:
	/* 0x8b4: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8b9:
	/* 0x8b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8be:
	/* 0x8be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c0:
	/* 0x8c0: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8c8:
	/* 0x8c8: cmp    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 80ULL);
x86_l_8cd:
	/* 0x8cd: je     ab1 <generic_lsm_process_event+0xab1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab1;
	}
x86_l_8d3:
	/* 0x8d3: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_8d7:
	/* 0x8d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8dc:
	/* 0x8dc: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8e4:
	/* 0x8e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e9:
	/* 0x8e9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8ec:
	/* 0x8ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ee:
	/* 0x8ee: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8f3:
	/* 0x8f3: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8fb:
	/* 0x8fb: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_8ff:
	/* 0x8ff: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_907:
	/* 0x907: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_90c:
	/* 0x90c: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_90f:
	/* 0x90f: jne    756 <generic_lsm_process_event+0x756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_756;
	}
x86_l_915:
	/* 0x915: jmp    abe <generic_lsm_process_event+0xabe> */
	goto x86_l_abe;
x86_l_91a:
	/* 0x91a: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_91f:
	/* 0x91f: lea    rsi,[rip+0x1af] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 431ULL);
x86_l_926:
	/* 0x926: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_92b:
	/* 0x92b: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_930:
	/* 0x930: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_932:
	/* 0x932: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_934:
	/* 0x934: jmp    ab9 <generic_lsm_process_event+0xab9> */
	goto x86_l_ab9;
x86_l_939:
	/* 0x939: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_93e:
	/* 0x93e: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_946:
	/* 0x946: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_94b:
	/* 0x94b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_950:
	/* 0x950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_952:
	/* 0x952: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_95a:
	/* 0x95a: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_95f:
	/* 0x95f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_962:
	/* 0x962: jne    54e <generic_lsm_process_event+0x54e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1358ULL;
	}
x86_l_968:
	/* 0x968: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_973:
	/* 0x973: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_978:
	/* 0x978: mov    rdi,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_97f:
	/* 0x97f: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_987:
	/* 0x987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_989:
	/* 0x989: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98c:
	/* 0x98c: je     d16 <generic_lsm_process_event+0xd16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d16;
	}
x86_l_992:
	/* 0x992: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_997:
	/* 0x997: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_99c:
	/* 0x99c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_99f:
	/* 0x99f: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_9a3:
	/* 0x9a3: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9a8:
	/* 0x9a8: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9ad:
	/* 0x9ad: jg     de9 <generic_lsm_process_event+0xde9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_de9;
	}
x86_l_9b3:
	/* 0x9b3: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_9b7:
	/* 0x9b7: jle    f32 <generic_lsm_process_event+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3890ULL;
	}
x86_l_9bd:
	/* 0x9bd: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_9c1:
	/* 0x9c1: jle    12a1 <generic_lsm_process_event+0x12a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4769ULL;
	}
x86_l_9c7:
	/* 0x9c7: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_9cb:
	/* 0x9cb: je     19f6 <generic_lsm_process_event+0x19f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6646ULL;
	}
x86_l_9d1:
	/* 0x9d1: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_9d5:
	/* 0x9d5: je     197d <generic_lsm_process_event+0x197d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6525ULL;
	}
x86_l_9db:
	/* 0x9db: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_9df:
	/* 0x9df: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9e4:
	/* 0x9e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e9:
	/* 0x9e9: jne    2e49 <generic_lsm_process_event+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11849ULL;
	}
x86_l_9ef:
	/* 0x9ef: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9f4:
	/* 0x9f4: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_9fb:
	/* 0x9fb: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a00:
	/* 0xa00: mov    DWORD PTR [rax],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a02:
	/* 0xa02: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_a08:
	/* 0xa08: jmp    2e49 <generic_lsm_process_event+0x2e49> */
	return 11849ULL;
x86_l_a0d:
	/* 0xa0d: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_a11:
	/* 0xa11: ja     968 <generic_lsm_process_event+0x968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_968;
	}
x86_l_a17:
	/* 0xa17: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_a1a:
	/* 0xa1a: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_a24:
	/* 0xa24: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_a28:
	/* 0xa28: jae    968 <generic_lsm_process_event+0x968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_968;
	}
x86_l_a2e:
	/* 0xa2e: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a33:
	/* 0xa33: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_a3e:
	/* 0xa3e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a43:
	/* 0xa43: mov    rdi,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a4a:
	/* 0xa4a: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_a52:
	/* 0xa52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a54:
	/* 0xa54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a57:
	/* 0xa57: je     ba9 <generic_lsm_process_event+0xba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ba9;
	}
x86_l_a5d:
	/* 0xa5d: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_a60:
	/* 0xa60: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a63:
	/* 0xa63: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_a67:
	/* 0xa67: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a6c:
	/* 0xa6c: jle    bb6 <generic_lsm_process_event+0xbb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_bb6;
	}
x86_l_a72:
	/* 0xa72: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_a76:
	/* 0xa76: jle    d28 <generic_lsm_process_event+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d28;
	}
x86_l_a7c:
	/* 0xa7c: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_a80:
	/* 0xa80: jg     e25 <generic_lsm_process_event+0xe25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_e25;
	}
x86_l_a86:
	/* 0xa86: lea    eax,[r12-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_a8b:
	/* 0xa8b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a8e:
	/* 0xa8e: jae    1373 <generic_lsm_process_event+0x1373> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4979ULL;
	}
x86_l_a94:
	/* 0xa94: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_a9a:
	/* 0xa9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a9f:
	/* 0xa9f: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_aa4:
	/* 0xaa4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_aa7:
	/* 0xaa7: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_aac:
	/* 0xaac: jmp    fc2 <generic_lsm_process_event+0xfc2> */
	return 4034ULL;
x86_l_ab1:
	/* 0xab1: mov    BYTE PTR [rsp+0xa4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636545ULL);
x86_l_ab9:
	/* 0xab9: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_abe:
	/* 0xabe: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ac6:
	/* 0xac6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_acb:
	/* 0xacb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_acd:
	/* 0xacd: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ad0:
	/* 0xad0: je     b06 <generic_lsm_process_event+0xb06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b06;
	}
x86_l_ad2:
	/* 0xad2: cmp    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_ada:
	/* 0xada: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_add:
	/* 0xadd: mov    edx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ae4:
	/* 0xae4: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_aea:
	/* 0xaea: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_aed:
	/* 0xaed: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_aef:
	/* 0xaef: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_af3:
	/* 0xaf3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af6:
	/* 0xaf6: je     b9c <generic_lsm_process_event+0xb9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b9c;
	}
x86_l_afc:
	/* 0xafc: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_aff:
	/* 0xaff: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b01:
	/* 0xb01: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_b04:
	/* 0xb04: jmp    b09 <generic_lsm_process_event+0xb09> */
	goto x86_l_b09;
x86_l_b06:
	/* 0xb06: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b09:
	/* 0xb09: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b0e:
	/* 0xb0e: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b13:
	/* 0xb13: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b1a:
	/* 0xb1a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b1f:
	/* 0xb1f: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_b22:
	/* 0xb22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b24:
	/* 0xb24: mov    DWORD PTR [r12],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b28:
	/* 0xb28: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b2d:
	/* 0xb2d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b32:
	/* 0xb32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b37:
	/* 0xb37: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b3c:
	/* 0xb3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3e:
	/* 0xb3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b43:
	/* 0xb43: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b48:
	/* 0xb48: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_b4c:
	/* 0xb4c: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b54:
	/* 0xb54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b59:
	/* 0xb59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5b:
	/* 0xb5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b60:
	/* 0xb60: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b68:
	/* 0xb68: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b6d:
	/* 0xb6d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b72:
	/* 0xb72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b74:
	/* 0xb74: mov    DWORD PTR [r12+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_b79:
	/* 0xb79: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_b7e:
	/* 0xb7e: mov    WORD PTR [r12+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_b84:
	/* 0xb84: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_b88:
	/* 0xb88: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b8d:
	/* 0xb8d: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b92:
	/* 0xb92: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b97:
	/* 0xb97: jmp    2e49 <generic_lsm_process_event+0x2e49> */
	return 11849ULL;
x86_l_b9c:
	/* 0xb9c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9f:
	/* 0xb9f: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ba4:
	/* 0xba4: jmp    2e4e <generic_lsm_process_event+0x2e4e> */
	return 11854ULL;
x86_l_ba9:
	/* 0xba9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bac:
	/* 0xbac: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb1:
	/* 0xbb1: jmp    2e3a <generic_lsm_process_event+0x2e3a> */
	return 11834ULL;
x86_l_bb6:
	/* 0xbb6: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_bba:
	/* 0xbba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bbf:
	/* 0xbbf: jg     d5f <generic_lsm_process_event+0xd5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d5f;
	}
x86_l_bc5:
	/* 0xbc5: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_bc9:
	/* 0xbc9: jle    fd5 <generic_lsm_process_event+0xfd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4053ULL;
	}
x86_l_bcf:
	/* 0xbcf: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_bd3:
	/* 0xbd3: je     1541 <generic_lsm_process_event+0x1541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5441ULL;
	}
x86_l_bd9:
	/* 0xbd9: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_bdc:
	/* 0xbdc: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_be0:
	/* 0xbe0: je     db5 <generic_lsm_process_event+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db5;
	}
x86_l_be6:
	/* 0xbe6: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_beb:
	/* 0xbeb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf0:
	/* 0xbf0: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_bf4:
	/* 0xbf4: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_bf7:
	/* 0xbf7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfc:
	/* 0xbfc: jne    2e3f <generic_lsm_process_event+0x2e3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11839ULL;
	}
x86_l_c02:
	/* 0xc02: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c07:
	/* 0xc07: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c0c:
	/* 0xc0c: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c10:
	/* 0xc10: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_c14:
	/* 0xc14: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c18:
	/* 0xc18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c1d:
	/* 0xc1d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c22:
	/* 0xc22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c24:
	/* 0xc24: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_c28:
	/* 0xc28: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_c2c:
	/* 0xc2c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c31:
	/* 0xc31: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_c36:
	/* 0xc36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c38:
	/* 0xc38: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c3c:
	/* 0xc3c: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_c43:
	/* 0xc43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c48:
	/* 0xc48: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c4d:
	/* 0xc4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4f:
	/* 0xc4f: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c53:
	/* 0xc53: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_c5a:
	/* 0xc5a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c5f:
	/* 0xc5f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c64:
	/* 0xc64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c66:
	/* 0xc66: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c6a:
	/* 0xc6a: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_c71:
	/* 0xc71: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c76:
	/* 0xc76: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c7b:
	/* 0xc7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7d:
	/* 0xc7d: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c81:
	/* 0xc81: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_c88:
	/* 0xc88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c8d:
	/* 0xc8d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c92:
	/* 0xc92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c94:
	/* 0xc94: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c98:
	/* 0xc98: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca0:
	/* 0xca0: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ca8:
	/* 0xca8: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_cb0:
	/* 0xcb0: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_cb8:
	/* 0xcb8: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_cbc:
	/* 0xcbc: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_cbf:
	/* 0xcbf: je     1d17 <generic_lsm_process_event+0x1d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7447ULL;
	}
x86_l_cc5:
	/* 0xcc5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cc8:
	/* 0xcc8: jne    1d3f <generic_lsm_process_event+0x1d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7487ULL;
	}
x86_l_cce:
	/* 0xcce: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cd2:
	/* 0xcd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd7:
	/* 0xcd7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cdc:
	/* 0xcdc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ce1:
	/* 0xce1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce3:
	/* 0xce3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ce8:
	/* 0xce8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ceb:
	/* 0xceb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cf0:
	/* 0xcf0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_cf3:
	/* 0xcf3: jmp    1d3d <generic_lsm_process_event+0x1d3d> */
	return 7485ULL;
x86_l_cf8:
	/* 0xcf8: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_cfc:
	/* 0xcfc: add    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cff:
	/* 0xcff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d04:
	/* 0xd04: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d07:
	/* 0xd07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d09:
	/* 0xd09: mov    QWORD PTR [rsp+0x98],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d11:
	/* 0xd11: jmp    ab9 <generic_lsm_process_event+0xab9> */
	goto x86_l_ab9;
x86_l_d16:
	/* 0xd16: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d19:
	/* 0xd19: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d1e:
	/* 0xd1e: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d23:
	/* 0xd23: jmp    b8d <generic_lsm_process_event+0xb8d> */
	goto x86_l_b8d;
x86_l_d28:
	/* 0xd28: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_d2c:
	/* 0xd2c: jg     faa <generic_lsm_process_event+0xfaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4010ULL;
	}
x86_l_d32:
	/* 0xd32: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_d36:
	/* 0xd36: je     13a9 <generic_lsm_process_event+0x13a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5033ULL;
	}
x86_l_d3c:
	/* 0xd3c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d41:
	/* 0xd41: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_d45:
	/* 0xd45: je     1463 <generic_lsm_process_event+0x1463> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5219ULL;
	}
x86_l_d4b:
	/* 0xd4b: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_d4f:
	/* 0xd4f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d54:
	/* 0xd54: je     fe5 <generic_lsm_process_event+0xfe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4069ULL;
	}
x86_l_d5a:
	/* 0xd5a: jmp    2e3f <generic_lsm_process_event+0x2e3f> */
	return 11839ULL;
x86_l_d5f:
	/* 0xd5f: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_d64:
	/* 0xd64: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d67:
	/* 0xd67: jb     fe5 <generic_lsm_process_event+0xfe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4069ULL;
	}
x86_l_d6d:
	/* 0xd6d: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_d72:
	/* 0xd72: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d75:
	/* 0xd75: jb     1015 <generic_lsm_process_event+0x1015> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4117ULL;
	}
x86_l_d7b:
	/* 0xd7b: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_d7f:
	/* 0xd7f: jne    2e3f <generic_lsm_process_event+0x2e3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11839ULL;
	}
x86_l_d85:
	/* 0xd85: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_d88:
	/* 0xd88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d8d:
	/* 0xd8d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d92:
	/* 0xd92: lea    r15,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d97:
	/* 0xd97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d9c:
	/* 0xd9c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d9f:
	/* 0xd9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da1:
	/* 0xda1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_da6:
	/* 0xda6: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_dab:
	/* 0xdab: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_dae:
	/* 0xdae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_db3:
	/* 0xdb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db5:
	/* 0xdb5: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_dba:
	/* 0xdba: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dbe:
	/* 0xdbe: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_dc3:
	/* 0xdc3: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_dc8:
	/* 0xdc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dca:
	/* 0xdca: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_dcd:
	/* 0xdcd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dd0:
	/* 0xdd0: js     145b <generic_lsm_process_event+0x145b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5211ULL;
	}
x86_l_dd6:
	/* 0xdd6: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_dda:
	/* 0xdda: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ddd:
	/* 0xddd: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_de1:
	/* 0xde1: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_de4:
	/* 0xde4: jmp    2e3a <generic_lsm_process_event+0x2e3a> */
	return 11834ULL;
x86_l_de9:
	/* 0xde9: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_ded:
	/* 0xded: jle    1184 <generic_lsm_process_event+0x1184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4484ULL;
	}
x86_l_df3:
	/* 0xdf3: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_df6:
	/* 0xdf6: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_dfb:
	/* 0xdfb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dfe:
	/* 0xdfe: jae    1045 <generic_lsm_process_event+0x1045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4165ULL;
	}
x86_l_e04:
	/* 0xe04: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e09:
	/* 0xe09: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e0e:
	/* 0xe0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e13:
	/* 0xe13: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e18:
	/* 0xe18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e1a:
	/* 0xe1a: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_e20:
	/* 0xe20: jmp    1b43 <generic_lsm_process_event+0x1b43> */
	return 6979ULL;
x86_l_e25:
	/* 0xe25: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_e29:
	/* 0xe29: je     16cf <generic_lsm_process_event+0x16cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5839ULL;
	}
	return 3631ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3631ULL: goto x86_l_e2f;
	case 3635ULL: goto x86_l_e33;
	case 3641ULL: goto x86_l_e39;
	case 3645ULL: goto x86_l_e3d;
	case 3650ULL: goto x86_l_e42;
	case 3656ULL: goto x86_l_e48;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3669ULL: goto x86_l_e55;
	case 3677ULL: goto x86_l_e5d;
	case 3685ULL: goto x86_l_e65;
	case 3693ULL: goto x86_l_e6d;
	case 3701ULL: goto x86_l_e75;
	case 3709ULL: goto x86_l_e7d;
	case 3717ULL: goto x86_l_e85;
	case 3725ULL: goto x86_l_e8d;
	case 3733ULL: goto x86_l_e95;
	case 3741ULL: goto x86_l_e9d;
	case 3749ULL: goto x86_l_ea5;
	case 3757ULL: goto x86_l_ead;
	case 3765ULL: goto x86_l_eb5;
	case 3773ULL: goto x86_l_ebd;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3797ULL: goto x86_l_ed5;
	case 3799ULL: goto x86_l_ed7;
	case 3802ULL: goto x86_l_eda;
	case 3808ULL: goto x86_l_ee0;
	case 3812ULL: goto x86_l_ee4;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3827ULL: goto x86_l_ef3;
	case 3830ULL: goto x86_l_ef6;
	case 3832ULL: goto x86_l_ef8;
	case 3835ULL: goto x86_l_efb;
	case 3841ULL: goto x86_l_f01;
	case 3845ULL: goto x86_l_f05;
	case 3850ULL: goto x86_l_f0a;
	case 3854ULL: goto x86_l_f0e;
	case 3860ULL: goto x86_l_f14;
	case 3865ULL: goto x86_l_f19;
	case 3870ULL: goto x86_l_f1e;
	case 3873ULL: goto x86_l_f21;
	case 3875ULL: goto x86_l_f23;
	case 3877ULL: goto x86_l_f25;
	case 3883ULL: goto x86_l_f2b;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3894ULL: goto x86_l_f36;
	case 3900ULL: goto x86_l_f3c;
	case 3903ULL: goto x86_l_f3f;
	case 3907ULL: goto x86_l_f43;
	case 3913ULL: goto x86_l_f49;
	case 3918ULL: goto x86_l_f4e;
	case 3922ULL: goto x86_l_f52;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3938ULL: goto x86_l_f62;
	case 3943ULL: goto x86_l_f67;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3958ULL: goto x86_l_f76;
	case 3961ULL: goto x86_l_f79;
	case 3967ULL: goto x86_l_f7f;
	case 3970ULL: goto x86_l_f82;
	case 3976ULL: goto x86_l_f88;
	case 3979ULL: goto x86_l_f8b;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4005ULL: goto x86_l_fa5;
	case 4010ULL: goto x86_l_faa;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4029ULL: goto x86_l_fbd;
	case 4034ULL: goto x86_l_fc2;
	case 4037ULL: goto x86_l_fc5;
	case 4040ULL: goto x86_l_fc8;
	case 4042ULL: goto x86_l_fca;
	case 4045ULL: goto x86_l_fcd;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4057ULL: goto x86_l_fd9;
	case 4059ULL: goto x86_l_fdb;
	case 4063ULL: goto x86_l_fdf;
	case 4069ULL: goto x86_l_fe5;
	case 4074ULL: goto x86_l_fea;
	case 4079ULL: goto x86_l_fef;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4090ULL: goto x86_l_ffa;
	case 4093ULL: goto x86_l_ffd;
	case 4095ULL: goto x86_l_fff;
	case 4100ULL: goto x86_l_1004;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4112ULL: goto x86_l_1010;
	case 4117ULL: goto x86_l_1015;
	case 4123ULL: goto x86_l_101b;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4144ULL: goto x86_l_1030;
	case 4147ULL: goto x86_l_1033;
	case 4149ULL: goto x86_l_1035;
	case 4154ULL: goto x86_l_103a;
	case 4157ULL: goto x86_l_103d;
	case 4160ULL: goto x86_l_1040;
	case 4165ULL: goto x86_l_1045;
	case 4170ULL: goto x86_l_104a;
	case 4174ULL: goto x86_l_104e;
	case 4180ULL: goto x86_l_1054;
	case 4184ULL: goto x86_l_1058;
	case 4189ULL: goto x86_l_105d;
	case 4194ULL: goto x86_l_1062;
	case 4200ULL: goto x86_l_1068;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4212ULL: goto x86_l_1074;
	case 4217ULL: goto x86_l_1079;
	case 4222ULL: goto x86_l_107e;
	case 4227ULL: goto x86_l_1083;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4237ULL: goto x86_l_108d;
	case 4243ULL: goto x86_l_1093;
	case 4248ULL: goto x86_l_1098;
	case 4252ULL: goto x86_l_109c;
	case 4256ULL: goto x86_l_10a0;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4276ULL: goto x86_l_10b4;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4296ULL: goto x86_l_10c8;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4313ULL: goto x86_l_10d9;
	case 4315ULL: goto x86_l_10db;
	case 4319ULL: goto x86_l_10df;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4338ULL: goto x86_l_10f2;
	case 4342ULL: goto x86_l_10f6;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4361ULL: goto x86_l_1109;
	case 4365ULL: goto x86_l_110d;
	case 4372ULL: goto x86_l_1114;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4384ULL: goto x86_l_1120;
	case 4388ULL: goto x86_l_1124;
	case 4396ULL: goto x86_l_112c;
	case 4404ULL: goto x86_l_1134;
	case 4412ULL: goto x86_l_113c;
	case 4420ULL: goto x86_l_1144;
	case 4424ULL: goto x86_l_1148;
	case 4427ULL: goto x86_l_114b;
	case 4433ULL: goto x86_l_1151;
	case 4436ULL: goto x86_l_1154;
	case 4442ULL: goto x86_l_115a;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4471ULL: goto x86_l_1177;
	case 4476ULL: goto x86_l_117c;
	case 4479ULL: goto x86_l_117f;
	case 4484ULL: goto x86_l_1184;
	case 4488ULL: goto x86_l_1188;
	case 4494ULL: goto x86_l_118e;
	case 4498ULL: goto x86_l_1192;
	case 4503ULL: goto x86_l_1197;
	case 4508ULL: goto x86_l_119c;
	case 4514ULL: goto x86_l_11a2;
	case 4517ULL: goto x86_l_11a5;
	case 4522ULL: goto x86_l_11aa;
	case 4530ULL: goto x86_l_11b2;
	case 4538ULL: goto x86_l_11ba;
	case 4546ULL: goto x86_l_11c2;
	case 4554ULL: goto x86_l_11ca;
	case 4562ULL: goto x86_l_11d2;
	case 4570ULL: goto x86_l_11da;
	case 4578ULL: goto x86_l_11e2;
	case 4586ULL: goto x86_l_11ea;
	case 4594ULL: goto x86_l_11f2;
	case 4601ULL: goto x86_l_11f9;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4624ULL: goto x86_l_1210;
	case 4626ULL: goto x86_l_1212;
	case 4629ULL: goto x86_l_1215;
	case 4635ULL: goto x86_l_121b;
	case 4640ULL: goto x86_l_1220;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4656ULL: goto x86_l_1230;
	case 4661ULL: goto x86_l_1235;
	case 4666ULL: goto x86_l_123a;
	case 4668ULL: goto x86_l_123c;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4682ULL: goto x86_l_124a;
	case 4686ULL: goto x86_l_124e;
	case 4692ULL: goto x86_l_1254;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4706ULL: goto x86_l_1262;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4724ULL: goto x86_l_1274;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4750ULL: goto x86_l_128e;
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
	case 4825ULL: goto x86_l_12d9;
	case 4832ULL: goto x86_l_12e0;
	case 4837ULL: goto x86_l_12e5;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4859ULL: goto x86_l_12fb;
	case 4864ULL: goto x86_l_1300;
	case 4867ULL: goto x86_l_1303;
	case 4872ULL: goto x86_l_1308;
	case 4874ULL: goto x86_l_130a;
	case 4882ULL: goto x86_l_1312;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4907ULL: goto x86_l_132b;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4924ULL: goto x86_l_133c;
	case 4926ULL: goto x86_l_133e;
	case 4933ULL: goto x86_l_1345;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4956ULL: goto x86_l_135c;
	case 4958ULL: goto x86_l_135e;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4974ULL: goto x86_l_136e;
	case 4979ULL: goto x86_l_1373;
	case 4983ULL: goto x86_l_1377;
	case 4988ULL: goto x86_l_137c;
	case 4994ULL: goto x86_l_1382;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5005ULL: goto x86_l_138d;
	case 5008ULL: goto x86_l_1390;
	case 5011ULL: goto x86_l_1393;
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
	case 5144ULL: goto x86_l_1418;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5154ULL: goto x86_l_1422;
	case 5161ULL: goto x86_l_1429;
	case 5165ULL: goto x86_l_142d;
	case 5169ULL: goto x86_l_1431;
	case 5174ULL: goto x86_l_1436;
	case 5177ULL: goto x86_l_1439;
	case 5179ULL: goto x86_l_143b;
	case 5183ULL: goto x86_l_143f;
	case 5187ULL: goto x86_l_1443;
	case 5191ULL: goto x86_l_1447;
	case 5195ULL: goto x86_l_144b;
	case 5200ULL: goto x86_l_1450;
	case 5205ULL: goto x86_l_1455;
	case 5207ULL: goto x86_l_1457;
	case 5211ULL: goto x86_l_145b;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5245ULL: goto x86_l_147d;
	case 5247ULL: goto x86_l_147f;
	case 5255ULL: goto x86_l_1487;
	case 5257ULL: goto x86_l_1489;
	case 5263ULL: goto x86_l_148f;
	case 5266ULL: goto x86_l_1492;
	case 5272ULL: goto x86_l_1498;
	case 5276ULL: goto x86_l_149c;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5294ULL: goto x86_l_14ae;
	case 5296ULL: goto x86_l_14b0;
	case 5301ULL: goto x86_l_14b5;
	case 5306ULL: goto x86_l_14ba;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5330ULL: goto x86_l_14d2;
	case 5335ULL: goto x86_l_14d7;
	case 5340ULL: goto x86_l_14dc;
	case 5345ULL: goto x86_l_14e1;
	case 5347ULL: goto x86_l_14e3;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5374ULL: goto x86_l_14fe;
	case 5381ULL: goto x86_l_1505;
	case 5387ULL: goto x86_l_150b;
	case 5392ULL: goto x86_l_1510;
	case 5398ULL: goto x86_l_1516;
	case 5407ULL: goto x86_l_151f;
	case 5413ULL: goto x86_l_1525;
	case 5421ULL: goto x86_l_152d;
	case 5425ULL: goto x86_l_1531;
	case 5428ULL: goto x86_l_1534;
	case 5431ULL: goto x86_l_1537;
	case 5436ULL: goto x86_l_153c;
	case 5441ULL: goto x86_l_1541;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5455ULL: goto x86_l_154f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e2f:
	/* 0xe2f: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_e33:
	/* 0xe33: je     1707 <generic_lsm_process_event+0x1707> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5895ULL;
	}
x86_l_e39:
	/* 0xe39: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_e3d:
	/* 0xe3d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e42:
	/* 0xe42: jne    2e3f <generic_lsm_process_event+0x2e3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11839ULL;
	}
x86_l_e48:
	/* 0xe48: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_e4b:
	/* 0xe4b: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e50:
	/* 0xe50: mov    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e55:
	/* 0xe55: mov    QWORD PTR [r13+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e5d:
	/* 0xe5d: mov    QWORD PTR [r13+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e65:
	/* 0xe65: mov    QWORD PTR [r13+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_e6d:
	/* 0xe6d: mov    QWORD PTR [r13+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_e75:
	/* 0xe75: mov    QWORD PTR [r13+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e7d:
	/* 0xe7d: mov    QWORD PTR [r13+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_e85:
	/* 0xe85: mov    QWORD PTR [r13+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_e8d:
	/* 0xe8d: mov    QWORD PTR [r13+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_e95:
	/* 0xe95: mov    QWORD PTR [r13+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_e9d:
	/* 0xe9d: mov    QWORD PTR [r13+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ea5:
	/* 0xea5: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_ead:
	/* 0xead: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_eb5:
	/* 0xeb5: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ebd:
	/* 0xebd: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec5:
	/* 0xec5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_eca:
	/* 0xeca: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_ecd:
	/* 0xecd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ed2:
	/* 0xed2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ed5:
	/* 0xed5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed7:
	/* 0xed7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eda:
	/* 0xeda: js     1fc8 <generic_lsm_process_event+0x1fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8136ULL;
	}
x86_l_ee0:
	/* 0xee0: lea    r12,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_ee4:
	/* 0xee4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ee9:
	/* 0xee9: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_eee:
	/* 0xeee: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_ef3:
	/* 0xef3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ef6:
	/* 0xef6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef8:
	/* 0xef8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_efb:
	/* 0xefb: js     1fc8 <generic_lsm_process_event+0x1fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8136ULL;
	}
x86_l_f01:
	/* 0xf01: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f05:
	/* 0xf05: cmp    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_f0a:
	/* 0xf0a: sete   BYTE PTR [rbp+0x2] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RBP, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_f0e:
	/* 0xf0e: je     1fa8 <generic_lsm_process_event+0x1fa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8104ULL;
	}
x86_l_f14:
	/* 0xf14: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_f19:
	/* 0xf19: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_f1e:
	/* 0xf1e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f21:
	/* 0xf21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f23:
	/* 0xf23: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f25:
	/* 0xf25: js     1fc8 <generic_lsm_process_event+0x1fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8136ULL;
	}
x86_l_f2b:
	/* 0xf2b: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_f2d:
	/* 0xf2d: jmp    1fc4 <generic_lsm_process_event+0x1fc4> */
	return 8132ULL;
x86_l_f32:
	/* 0xf32: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_f36:
	/* 0xf36: jg     124a <generic_lsm_process_event+0x124a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_124a;
	}
x86_l_f3c:
	/* 0xf3c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_f3f:
	/* 0xf3f: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f43:
	/* 0xf43: je     178a <generic_lsm_process_event+0x178a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6026ULL;
	}
x86_l_f49:
	/* 0xf49: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f4e:
	/* 0xf4e: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f52:
	/* 0xf52: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f57:
	/* 0xf57: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f5c:
	/* 0xf5c: jne    2e49 <generic_lsm_process_event+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11849ULL;
	}
x86_l_f62:
	/* 0xf62: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f67:
	/* 0xf67: lea    rbp,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f6e:
	/* 0xf6e: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f73:
	/* 0xf73: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_f76:
	/* 0xf76: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f79:
	/* 0xf79: jle    1e8e <generic_lsm_process_event+0x1e8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7822ULL;
	}
x86_l_f7f:
	/* 0xf7f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f82:
	/* 0xf82: je     20a8 <generic_lsm_process_event+0x20a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8360ULL;
	}
x86_l_f88:
	/* 0xf88: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f8b:
	/* 0xf8b: je     20b5 <generic_lsm_process_event+0x20b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8373ULL;
	}
x86_l_f91:
	/* 0xf91: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_f94:
	/* 0xf94: jne    249d <generic_lsm_process_event+0x249d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9373ULL;
	}
x86_l_f9a:
	/* 0xf9a: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f9f:
	/* 0xf9f: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_fa5:
	/* 0xfa5: jmp    20cd <generic_lsm_process_event+0x20cd> */
	return 8397ULL;
x86_l_faa:
	/* 0xfaa: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_fb0:
	/* 0xfb0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fb5:
	/* 0xfb5: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fba:
	/* 0xfba: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_fbd:
	/* 0xfbd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_fc2:
	/* 0xfc2: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_fc5:
	/* 0xfc5: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_fc8:
	/* 0xfc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fca:
	/* 0xfca: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_fcd:
	/* 0xfcd: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_fd0:
	/* 0xfd0: jmp    2e3a <generic_lsm_process_event+0x2e3a> */
	return 11834ULL;
x86_l_fd5:
	/* 0xfd5: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_fd9:
	/* 0xfd9: je     1015 <generic_lsm_process_event+0x1015> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1015;
	}
x86_l_fdb:
	/* 0xfdb: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_fdf:
	/* 0xfdf: jne    2e3f <generic_lsm_process_event+0x2e3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11839ULL;
	}
x86_l_fe5:
	/* 0xfe5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fea:
	/* 0xfea: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fef:
	/* 0xfef: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ff2:
	/* 0xff2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff7:
	/* 0xff7: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_ffa:
	/* 0xffa: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_ffd:
	/* 0xffd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fff:
	/* 0xfff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1004:
	/* 0x1004: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1007:
	/* 0x1007: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_100a:
	/* 0x100a: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1010:
	/* 0x1010: jmp    2e3f <generic_lsm_process_event+0x2e3f> */
	return 11839ULL;
x86_l_1015:
	/* 0x1015: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_101b:
	/* 0x101b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1020:
	/* 0x1020: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1025:
	/* 0x1025: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1028:
	/* 0x1028: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_102d:
	/* 0x102d: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1030:
	/* 0x1030: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1033:
	/* 0x1033: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1035:
	/* 0x1035: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103a:
	/* 0x103a: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_103d:
	/* 0x103d: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_1040:
	/* 0x1040: jmp    2e3f <generic_lsm_process_event+0x2e3f> */
	return 11839ULL;
x86_l_1045:
	/* 0x1045: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_104a:
	/* 0x104a: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_104e:
	/* 0x104e: je     1ac3 <generic_lsm_process_event+0x1ac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6851ULL;
	}
x86_l_1054:
	/* 0x1054: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_1058:
	/* 0x1058: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_105d:
	/* 0x105d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1062:
	/* 0x1062: jne    2e49 <generic_lsm_process_event+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11849ULL;
	}
x86_l_1068:
	/* 0x1068: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_106b:
	/* 0x106b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1070:
	/* 0x1070: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1074:
	/* 0x1074: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1079:
	/* 0x1079: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_107e:
	/* 0x107e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1083:
	/* 0x1083: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1085:
	/* 0x1085: mov    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_108a:
	/* 0x108a: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_108d:
	/* 0x108d: je     2057 <generic_lsm_process_event+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8279ULL;
	}
x86_l_1093:
	/* 0x1093: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1098:
	/* 0x1098: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_109c:
	/* 0x109c: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
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
	/* 0x10b0: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_10b4:
	/* 0x10b4: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_10b8:
	/* 0x10b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10bd:
	/* 0x10bd: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_10c2:
	/* 0x10c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c4:
	/* 0x10c4: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10c8:
	/* 0x10c8: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_10cf:
	/* 0x10cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10d4:
	/* 0x10d4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10d9:
	/* 0x10d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10db:
	/* 0x10db: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_10df:
	/* 0x10df: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_10e6:
	/* 0x10e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10eb:
	/* 0x10eb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10f0:
	/* 0x10f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f2:
	/* 0x10f2: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10f6:
	/* 0x10f6: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_10fd:
	/* 0x10fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1102:
	/* 0x1102: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1107:
	/* 0x1107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1109:
	/* 0x1109: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_110d:
	/* 0x110d: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1114:
	/* 0x1114: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1119:
	/* 0x1119: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_111e:
	/* 0x111e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1120:
	/* 0x1120: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1124:
	/* 0x1124: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_112c:
	/* 0x112c: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1134:
	/* 0x1134: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_113c:
	/* 0x113c: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1144:
	/* 0x1144: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1148:
	/* 0x1148: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_114b:
	/* 0x114b: je     1ff2 <generic_lsm_process_event+0x1ff2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8178ULL;
	}
x86_l_1151:
	/* 0x1151: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1154:
	/* 0x1154: jne    201a <generic_lsm_process_event+0x201a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8218ULL;
	}
x86_l_115a:
	/* 0x115a: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_115e:
	/* 0x115e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1163:
	/* 0x1163: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1168:
	/* 0x1168: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_116d:
	/* 0x116d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116f:
	/* 0x116f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1174:
	/* 0x1174: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1177:
	/* 0x1177: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_117c:
	/* 0x117c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_117f:
	/* 0x117f: jmp    2018 <generic_lsm_process_event+0x2018> */
	return 8216ULL;
x86_l_1184:
	/* 0x1184: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_1188:
	/* 0x1188: je     1b4d <generic_lsm_process_event+0x1b4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6989ULL;
	}
x86_l_118e:
	/* 0x118e: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_1192:
	/* 0x1192: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1197:
	/* 0x1197: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_119c:
	/* 0x119c: jne    2e49 <generic_lsm_process_event+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11849ULL;
	}
x86_l_11a2:
	/* 0x11a2: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_11a5:
	/* 0x11a5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11aa:
	/* 0x11aa: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_11b2:
	/* 0x11b2: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_11ba:
	/* 0x11ba: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_11c2:
	/* 0x11c2: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_11ca:
	/* 0x11ca: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_11d2:
	/* 0x11d2: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_11da:
	/* 0x11da: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_11e2:
	/* 0x11e2: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_11ea:
	/* 0x11ea: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_11f2:
	/* 0x11f2: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f9:
	/* 0x11f9: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11fd:
	/* 0x11fd: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1202:
	/* 0x1202: lea    rdx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1206:
	/* 0x1206: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_120b:
	/* 0x120b: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1210:
	/* 0x1210: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1212:
	/* 0x1212: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1215:
	/* 0x1215: js     1f9d <generic_lsm_process_event+0x1f9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8093ULL;
	}
x86_l_121b:
	/* 0x121b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1220:
	/* 0x1220: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1224:
	/* 0x1224: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1229:
	/* 0x1229: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_1230:
	/* 0x1230: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1235:
	/* 0x1235: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_123a:
	/* 0x123a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123c:
	/* 0x123c: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1242:
	/* 0x1242: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1245:
	/* 0x1245: jmp    b8d <generic_lsm_process_event+0xb8d> */
	return 2957ULL;
x86_l_124a:
	/* 0x124a: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_124e:
	/* 0x124e: je     17fa <generic_lsm_process_event+0x17fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6138ULL;
	}
x86_l_1254:
	/* 0x1254: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_1258:
	/* 0x1258: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_125d:
	/* 0x125d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1262:
	/* 0x1262: jne    2e49 <generic_lsm_process_event+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11849ULL;
	}
x86_l_1268:
	/* 0x1268: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_126d:
	/* 0x126d: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1274:
	/* 0x1274: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1279:
	/* 0x1279: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_127e:
	/* 0x127e: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1281:
	/* 0x1281: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1286:
	/* 0x1286: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1289:
	/* 0x1289: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_128c:
	/* 0x128c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128e:
	/* 0x128e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1293:
	/* 0x1293: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1296:
	/* 0x1296: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1299:
	/* 0x1299: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_129c:
	/* 0x129c: jmp    2e49 <generic_lsm_process_event+0x2e49> */
	return 11849ULL;
x86_l_12a1:
	/* 0x12a1: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_12a5:
	/* 0x12a5: je     1a78 <generic_lsm_process_event+0x1a78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6776ULL;
	}
x86_l_12ab:
	/* 0x12ab: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_12af:
	/* 0x12af: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12b4:
	/* 0x12b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b9:
	/* 0x12b9: jne    2e49 <generic_lsm_process_event+0x2e49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11849ULL;
	}
x86_l_12bf:
	/* 0x12bf: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_12c8:
	/* 0x12c8: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12cd:
	/* 0x12cd: lea    rax,[r15+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_12d4:
	/* 0x12d4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12d9:
	/* 0x12d9: lea    rdx,[r15+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_12e0:
	/* 0x12e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12e5:
	/* 0x12e5: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12ea:
	/* 0x12ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ef:
	/* 0x12ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f1:
	/* 0x12f1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_12f6:
	/* 0x12f6: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12fb:
	/* 0x12fb: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1300:
	/* 0x1300: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1303:
	/* 0x1303: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1308:
	/* 0x1308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130a:
	/* 0x130a: lea    rdi,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1312:
	/* 0x1312: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1317:
	/* 0x1317: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_131c:
	/* 0x131c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1321:
	/* 0x1321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1323:
	/* 0x1323: lea    rdi,[r12+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_132b:
	/* 0x132b: lea    rdx,[r15+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1332:
	/* 0x1332: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1337:
	/* 0x1337: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_133c:
	/* 0x133c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133e:
	/* 0x133e: add    r12,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1345:
	/* 0x1345: add    r15,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_134c:
	/* 0x134c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1351:
	/* 0x1351: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1354:
	/* 0x1354: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1359:
	/* 0x1359: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_135c:
	/* 0x135c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135e:
	/* 0x135e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1363:
	/* 0x1363: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1368:
	/* 0x1368: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_136e:
	/* 0x136e: jmp    2e49 <generic_lsm_process_event+0x2e49> */
	return 11849ULL;
x86_l_1373:
	/* 0x1373: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_1377:
	/* 0x1377: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_137c:
	/* 0x137c: jne    2e3f <generic_lsm_process_event+0x2e3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11839ULL;
	}
x86_l_1382:
	/* 0x1382: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1385:
	/* 0x1385: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_138a:
	/* 0x138a: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_138d:
	/* 0x138d: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1390:
	/* 0x1390: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1393:
	/* 0x1393: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
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
	/* 0x13a4: jmp    16ea <generic_lsm_process_event+0x16ea> */
	return 5866ULL;
x86_l_13a9:
	/* 0x13a9: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_13ac:
	/* 0x13ac: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
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
	/* 0x13c0: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_13c5:
	/* 0x13c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13ca:
	/* 0x13ca: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13d2:
	/* 0x13d2: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13d7:
	/* 0x13d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13dc:
	/* 0x13dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13de:
	/* 0x13de: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13e5:
	/* 0x13e5: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13e9:
	/* 0x13e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ee:
	/* 0x13ee: mov    rdi,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_13f5:
	/* 0x13f5: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_13fa:
	/* 0x13fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fc:
	/* 0x13fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13ff:
	/* 0x13ff: je     1bc8 <generic_lsm_process_event+0x1bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7112ULL;
	}
x86_l_1405:
	/* 0x1405: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1408:
	/* 0x1408: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_140d:
	/* 0x140d: lea    rdx,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1415:
	/* 0x1415: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1418:
	/* 0x1418: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_141d:
	/* 0x141d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1420:
	/* 0x1420: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1422:
	/* 0x1422: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1429:
	/* 0x1429: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_142d:
	/* 0x142d: lea    esi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1431:
	/* 0x1431: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1436:
	/* 0x1436: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1439:
	/* 0x1439: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143b:
	/* 0x143b: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_143f:
	/* 0x143f: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1443:
	/* 0x1443: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1447:
	/* 0x1447: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_144b:
	/* 0x144b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1450:
	/* 0x1450: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1455:
	/* 0x1455: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1457:
	/* 0x1457: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_145b:
	/* 0x145b: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_145e:
	/* 0x145e: jmp    2e3a <generic_lsm_process_event+0x2e3a> */
	return 11834ULL;
x86_l_1463:
	/* 0x1463: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1468:
	/* 0x1468: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_146d:
	/* 0x146d: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1475:
	/* 0x1475: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_147a:
	/* 0x147a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_147d:
	/* 0x147d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147f:
	/* 0x147f: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_1487:
	/* 0x1487: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1489:
	/* 0x1489: je     1bd7 <generic_lsm_process_event+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7127ULL;
	}
x86_l_148f:
	/* 0x148f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1492:
	/* 0x1492: jne    1dc4 <generic_lsm_process_event+0x1dc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7620ULL;
	}
x86_l_1498:
	/* 0x1498: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_149c:
	/* 0x149c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a1:
	/* 0x14a1: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14a6:
	/* 0x14a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14ab:
	/* 0x14ab: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14ae:
	/* 0x14ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b0:
	/* 0x14b0: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14b5:
	/* 0x14b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ba:
	/* 0x14ba: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14c2:
	/* 0x14c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c7:
	/* 0x14c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c9:
	/* 0x14c9: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14ce:
	/* 0x14ce: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14d2:
	/* 0x14d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14d7:
	/* 0x14d7: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14dc:
	/* 0x14dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14e1:
	/* 0x14e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e3:
	/* 0x14e3: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14eb:
	/* 0x14eb: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14f0:
	/* 0x14f0: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14f5:
	/* 0x14f5: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14fa:
	/* 0x14fa: lea    r12,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_14fe:
	/* 0x14fe: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1505:
	/* 0x1505: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_150b:
	/* 0x150b: test   BYTE PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_1510:
	/* 0x1510: je     25a3 <generic_lsm_process_event+0x25a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9635ULL;
	}
x86_l_1516:
	/* 0x1516: cmp    QWORD PTR [rsp+0x30],0x1000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158434304ULL);
x86_l_151f:
	/* 0x151f: jb     2577 <generic_lsm_process_event+0x2577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9591ULL;
	}
x86_l_1525:
	/* 0x1525: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_152d:
	/* 0x152d: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1531:
	/* 0x1531: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1534:
	/* 0x1534: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1537:
	/* 0x1537: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_153c:
	/* 0x153c: jmp    1c60 <generic_lsm_process_event+0x1c60> */
	return 7264ULL;
x86_l_1541:
	/* 0x1541: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1546:
	/* 0x1546: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_154b:
	/* 0x154b: lea    rdi,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_154f:
	/* 0x154f: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
	return 5463ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5463ULL: goto x86_l_1557;
	case 5468ULL: goto x86_l_155c;
	case 5473ULL: goto x86_l_1561;
	case 5475ULL: goto x86_l_1563;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5496ULL: goto x86_l_1578;
	case 5500ULL: goto x86_l_157c;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5518ULL: goto x86_l_158e;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5529ULL: goto x86_l_1599;
	case 5537ULL: goto x86_l_15a1;
	case 5542ULL: goto x86_l_15a6;
	case 5547ULL: goto x86_l_15ab;
	case 5549ULL: goto x86_l_15ad;
	case 5558ULL: goto x86_l_15b6;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5581ULL: goto x86_l_15cd;
	case 5583ULL: goto x86_l_15cf;
	case 5591ULL: goto x86_l_15d7;
	case 5596ULL: goto x86_l_15dc;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5611ULL: goto x86_l_15eb;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5638ULL: goto x86_l_1606;
	case 5643ULL: goto x86_l_160b;
	case 5646ULL: goto x86_l_160e;
	case 5648ULL: goto x86_l_1610;
	case 5656ULL: goto x86_l_1618;
	case 5659ULL: goto x86_l_161b;
	case 5662ULL: goto x86_l_161e;
	case 5668ULL: goto x86_l_1624;
	case 5671ULL: goto x86_l_1627;
	case 5677ULL: goto x86_l_162d;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5701ULL: goto x86_l_1645;
	case 5709ULL: goto x86_l_164d;
	case 5714ULL: goto x86_l_1652;
	case 5718ULL: goto x86_l_1656;
	case 5724ULL: goto x86_l_165c;
	case 5728ULL: goto x86_l_1660;
	case 5732ULL: goto x86_l_1664;
	case 5739ULL: goto x86_l_166b;
	case 5747ULL: goto x86_l_1673;
	case 5755ULL: goto x86_l_167b;
	case 5763ULL: goto x86_l_1683;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5779ULL: goto x86_l_1693;
	case 5784ULL: goto x86_l_1698;
	case 5787ULL: goto x86_l_169b;
	case 5792ULL: goto x86_l_16a0;
	case 5795ULL: goto x86_l_16a3;
	case 5797ULL: goto x86_l_16a5;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5825ULL: goto x86_l_16c1;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5842ULL: goto x86_l_16d2;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5856ULL: goto x86_l_16e0;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5868ULL: goto x86_l_16ec;
	case 5871ULL: goto x86_l_16ef;
	case 5874ULL: goto x86_l_16f2;
	case 5876ULL: goto x86_l_16f4;
	case 5880ULL: goto x86_l_16f8;
	case 5883ULL: goto x86_l_16fb;
	case 5887ULL: goto x86_l_16ff;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5898ULL: goto x86_l_170a;
	case 5903ULL: goto x86_l_170f;
	case 5911ULL: goto x86_l_1717;
	case 5919ULL: goto x86_l_171f;
	case 5927ULL: goto x86_l_1727;
	case 5932ULL: goto x86_l_172c;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5943ULL: goto x86_l_1737;
	case 5945ULL: goto x86_l_1739;
	case 5948ULL: goto x86_l_173c;
	case 5954ULL: goto x86_l_1742;
	case 5957ULL: goto x86_l_1745;
	case 5961ULL: goto x86_l_1749;
	case 5964ULL: goto x86_l_174c;
	case 5970ULL: goto x86_l_1752;
	case 5973ULL: goto x86_l_1755;
	case 5979ULL: goto x86_l_175b;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6000ULL: goto x86_l_1770;
	case 6004ULL: goto x86_l_1774;
	case 6008ULL: goto x86_l_1778;
	case 6012ULL: goto x86_l_177c;
	case 6016ULL: goto x86_l_1780;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6039ULL: goto x86_l_1797;
	case 6043ULL: goto x86_l_179b;
	case 6050ULL: goto x86_l_17a2;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6086ULL: goto x86_l_17c6;
	case 6089ULL: goto x86_l_17c9;
	case 6092ULL: goto x86_l_17cc;
	case 6098ULL: goto x86_l_17d2;
	case 6101ULL: goto x86_l_17d5;
	case 6107ULL: goto x86_l_17db;
	case 6110ULL: goto x86_l_17de;
	case 6116ULL: goto x86_l_17e4;
	case 6119ULL: goto x86_l_17e7;
	case 6125ULL: goto x86_l_17ed;
	case 6133ULL: goto x86_l_17f5;
	case 6138ULL: goto x86_l_17fa;
	case 6143ULL: goto x86_l_17ff;
	case 6147ULL: goto x86_l_1803;
	case 6152ULL: goto x86_l_1808;
	case 6157ULL: goto x86_l_180d;
	case 6162ULL: goto x86_l_1812;
	case 6167ULL: goto x86_l_1817;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6177ULL: goto x86_l_1821;
	case 6181ULL: goto x86_l_1825;
	case 6186ULL: goto x86_l_182a;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6219ULL: goto x86_l_184b;
	case 6223ULL: goto x86_l_184f;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6240ULL: goto x86_l_1860;
	case 6244ULL: goto x86_l_1864;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6261ULL: goto x86_l_1875;
	case 6265ULL: goto x86_l_1879;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6282ULL: goto x86_l_188a;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6303ULL: goto x86_l_189f;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6317ULL: goto x86_l_18ad;
	case 6322ULL: goto x86_l_18b2;
	case 6324ULL: goto x86_l_18b4;
	case 6332ULL: goto x86_l_18bc;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6346ULL: goto x86_l_18ca;
	case 6351ULL: goto x86_l_18cf;
	case 6353ULL: goto x86_l_18d1;
	case 6358ULL: goto x86_l_18d6;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6371ULL: goto x86_l_18e3;
	case 6376ULL: goto x86_l_18e8;
	case 6380ULL: goto x86_l_18ec;
	case 6387ULL: goto x86_l_18f3;
	case 6392ULL: goto x86_l_18f8;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6407ULL: goto x86_l_1907;
	case 6412ULL: goto x86_l_190c;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6435ULL: goto x86_l_1923;
	case 6437ULL: goto x86_l_1925;
	case 6441ULL: goto x86_l_1929;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6461ULL: goto x86_l_193d;
	case 6465ULL: goto x86_l_1941;
	case 6473ULL: goto x86_l_1949;
	case 6478ULL: goto x86_l_194e;
	case 6483ULL: goto x86_l_1953;
	case 6485ULL: goto x86_l_1955;
	case 6489ULL: goto x86_l_1959;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6512ULL: goto x86_l_1970;
	case 6514ULL: goto x86_l_1972;
	case 6520ULL: goto x86_l_1978;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6538ULL: goto x86_l_198a;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6558ULL: goto x86_l_199e;
	case 6562ULL: goto x86_l_19a2;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6582ULL: goto x86_l_19b6;
	case 6586ULL: goto x86_l_19ba;
	case 6594ULL: goto x86_l_19c2;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6606ULL: goto x86_l_19ce;
	case 6610ULL: goto x86_l_19d2;
	case 6617ULL: goto x86_l_19d9;
	case 6622ULL: goto x86_l_19de;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6633ULL: goto x86_l_19e9;
	case 6635ULL: goto x86_l_19eb;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6651ULL: goto x86_l_19fb;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6666ULL: goto x86_l_1a0a;
	case 6669ULL: goto x86_l_1a0d;
	case 6674ULL: goto x86_l_1a12;
	case 6676ULL: goto x86_l_1a14;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6697ULL: goto x86_l_1a29;
	case 6701ULL: goto x86_l_1a2d;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6716ULL: goto x86_l_1a3c;
	case 6718ULL: goto x86_l_1a3e;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6739ULL: goto x86_l_1a53;
	case 6743ULL: goto x86_l_1a57;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6760ULL: goto x86_l_1a68;
	case 6763ULL: goto x86_l_1a6b;
	case 6765ULL: goto x86_l_1a6d;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6789ULL: goto x86_l_1a85;
	case 6794ULL: goto x86_l_1a8a;
	case 6799ULL: goto x86_l_1a8f;
	case 6802ULL: goto x86_l_1a92;
	case 6804ULL: goto x86_l_1a94;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6825ULL: goto x86_l_1aa9;
	case 6829ULL: goto x86_l_1aad;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6849ULL: goto x86_l_1ac1;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6878ULL: goto x86_l_1ade;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6890ULL: goto x86_l_1aea;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6912ULL: goto x86_l_1b00;
	case 6916ULL: goto x86_l_1b04;
	case 6920ULL: goto x86_l_1b08;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6942ULL: goto x86_l_1b1e;
	case 6944ULL: goto x86_l_1b20;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6963ULL: goto x86_l_1b33;
	case 6966ULL: goto x86_l_1b36;
	case 6971ULL: goto x86_l_1b3b;
	case 6973ULL: goto x86_l_1b3d;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 7002ULL: goto x86_l_1b5a;
	case 7010ULL: goto x86_l_1b62;
	case 7018ULL: goto x86_l_1b6a;
	case 7026ULL: goto x86_l_1b72;
	case 7034ULL: goto x86_l_1b7a;
	case 7042ULL: goto x86_l_1b82;
	case 7050ULL: goto x86_l_1b8a;
	case 7058ULL: goto x86_l_1b92;
	case 7066ULL: goto x86_l_1b9a;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7119ULL: goto x86_l_1bcf;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7131ULL: goto x86_l_1bdb;
	case 7136ULL: goto x86_l_1be0;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7151ULL: goto x86_l_1bef;
	case 7155ULL: goto x86_l_1bf3;
	case 7160ULL: goto x86_l_1bf8;
	case 7165ULL: goto x86_l_1bfd;
	case 7170ULL: goto x86_l_1c02;
	case 7173ULL: goto x86_l_1c05;
	case 7175ULL: goto x86_l_1c07;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7198ULL: goto x86_l_1c1e;
	case 7202ULL: goto x86_l_1c22;
	case 7209ULL: goto x86_l_1c29;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7226ULL: goto x86_l_1c3a;
	case 7235ULL: goto x86_l_1c43;
	case 7241ULL: goto x86_l_1c49;
	case 7249ULL: goto x86_l_1c51;
	case 7253ULL: goto x86_l_1c55;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1557:
	/* 0x1557: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_155c:
	/* 0x155c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1561:
	/* 0x1561: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1563:
	/* 0x1563: lea    rdi,[rbp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1567:
	/* 0x1567: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_156c:
	/* 0x156c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1571:
	/* 0x1571: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1576:
	/* 0x1576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1578:
	/* 0x1578: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_157c:
	/* 0x157c: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1584:
	/* 0x1584: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1589:
	/* 0x1589: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_158e:
	/* 0x158e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1590:
	/* 0x1590: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1595:
	/* 0x1595: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1599:
	/* 0x1599: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15a1:
	/* 0x15a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15a6:
	/* 0x15a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15ab:
	/* 0x15ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ad:
	/* 0x15ad: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_15b6:
	/* 0x15b6: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_15be:
	/* 0x15be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15c3:
	/* 0x15c3: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15c8:
	/* 0x15c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15cd:
	/* 0x15cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15cf:
	/* 0x15cf: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15d7:
	/* 0x15d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15dc:
	/* 0x15dc: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_15e4:
	/* 0x15e4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15e9:
	/* 0x15e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15eb:
	/* 0x15eb: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_15f4:
	/* 0x15f4: add    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_15f9:
	/* 0x15f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15fe:
	/* 0x15fe: lea    rdi,[rsp+0xaf] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 175ULL);
x86_l_1606:
	/* 0x1606: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_160b:
	/* 0x160b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_160e:
	/* 0x160e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1610:
	/* 0x1610: movzx  eax,BYTE PTR [rsp+0xaf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 175ULL);
x86_l_1618:
	/* 0x1618: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_161b:
	/* 0x161b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_161e:
	/* 0x161e: je     1c71 <generic_lsm_process_event+0x1c71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7281ULL;
	}
x86_l_1624:
	/* 0x1624: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1627:
	/* 0x1627: jne    2e2a <generic_lsm_process_event+0x2e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11818ULL;
	}
x86_l_162d:
	/* 0x162d: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1631:
	/* 0x1631: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1636:
	/* 0x1636: lea    rdi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_163e:
	/* 0x163e: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1643:
	/* 0x1643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1645:
	/* 0x1645: movzx  eax,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_164d:
	/* 0x164d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1652:
	/* 0x1652: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1656:
	/* 0x1656: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_165c:
	/* 0x165c: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1660:
	/* 0x1660: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1664:
	/* 0x1664: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166b:
	/* 0x166b: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1673:
	/* 0x1673: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_167b:
	/* 0x167b: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1683:
	/* 0x1683: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1688:
	/* 0x1688: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_168d:
	/* 0x168d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168f:
	/* 0x168f: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1693:
	/* 0x1693: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1698:
	/* 0x1698: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_169b:
	/* 0x169b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16a0:
	/* 0x16a0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_16a3:
	/* 0x16a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a5:
	/* 0x16a5: lea    rdx,[r12+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_16ad:
	/* 0x16ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b2:
	/* 0x16b2: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_16ba:
	/* 0x16ba: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_16bf:
	/* 0x16bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c1:
	/* 0x16c1: movzx  r15d,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_16ca:
	/* 0x16ca: jmp    2cf3 <generic_lsm_process_event+0x2cf3> */
	return 11507ULL;
x86_l_16cf:
	/* 0x16cf: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_16d2:
	/* 0x16d2: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_16d7:
	/* 0x16d7: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_16dc:
	/* 0x16dc: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16e0:
	/* 0x16e0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_16e5:
	/* 0x16e5: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_16ea:
	/* 0x16ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ec:
	/* 0x16ec: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_16ef:
	/* 0x16ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16f2:
	/* 0x16f2: js     16ff <generic_lsm_process_event+0x16ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_16ff;
	}
x86_l_16f4:
	/* 0x16f4: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_16f8:
	/* 0x16f8: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16fb:
	/* 0x16fb: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_16ff:
	/* 0x16ff: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1702:
	/* 0x1702: jmp    2e3a <generic_lsm_process_event+0x2e3a> */
	return 11834ULL;
x86_l_1707:
	/* 0x1707: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_170a:
	/* 0x170a: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_170f:
	/* 0x170f: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1717:
	/* 0x1717: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_171f:
	/* 0x171f: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1727:
	/* 0x1727: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_172c:
	/* 0x172c: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_172f:
	/* 0x172f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1734:
	/* 0x1734: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1737:
	/* 0x1737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1739:
	/* 0x1739: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_173c:
	/* 0x173c: js     1eea <generic_lsm_process_event+0x1eea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7914ULL;
	}
x86_l_1742:
	/* 0x1742: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_1745:
	/* 0x1745: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1749:
	/* 0x1749: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_174c:
	/* 0x174c: je     1eb0 <generic_lsm_process_event+0x1eb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7856ULL;
	}
x86_l_1752:
	/* 0x1752: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1755:
	/* 0x1755: jne    1ede <generic_lsm_process_event+0x1ede> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7902ULL;
	}
x86_l_175b:
	/* 0x175b: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_175f:
	/* 0x175f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1764:
	/* 0x1764: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1769:
	/* 0x1769: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_176e:
	/* 0x176e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1770:
	/* 0x1770: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1774:
	/* 0x1774: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1778:
	/* 0x1778: lea    rdi,[r13+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_177c:
	/* 0x177c: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1780:
	/* 0x1780: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1785:
	/* 0x1785: jmp    1ed4 <generic_lsm_process_event+0x1ed4> */
	return 7892ULL;
x86_l_178a:
	/* 0x178a: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_178f:
	/* 0x178f: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1794:
	/* 0x1794: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1797:
	/* 0x1797: lea    rbx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_179b:
	/* 0x179b: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_17a2:
	/* 0x17a2: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_17ae:
	/* 0x17ae: test   BYTE PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691856ULL);
x86_l_17b3:
	/* 0x17b3: jne    1de0 <generic_lsm_process_event+0x1de0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7648ULL;
	}
x86_l_17b9:
	/* 0x17b9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17be:
	/* 0x17be: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_17c1:
	/* 0x17c1: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_17c4:
	/* 0x17c4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17c6:
	/* 0x17c6: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_17c9:
	/* 0x17c9: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_17cc:
	/* 0x17cc: jle    1fd3 <generic_lsm_process_event+0x1fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8147ULL;
	}
x86_l_17d2:
	/* 0x17d2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_17d5:
	/* 0x17d5: je     2703 <generic_lsm_process_event+0x2703> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9987ULL;
	}
x86_l_17db:
	/* 0x17db: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17de:
	/* 0x17de: je     270d <generic_lsm_process_event+0x270d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9997ULL;
	}
x86_l_17e4:
	/* 0x17e4: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_17e7:
	/* 0x17e7: jne    2722 <generic_lsm_process_event+0x2722> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10018ULL;
	}
x86_l_17ed:
	/* 0x17ed: lea    rax,[r12+0x5e70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_17f5:
	/* 0x17f5: jmp    271f <generic_lsm_process_event+0x271f> */
	return 10015ULL;
x86_l_17fa:
	/* 0x17fa: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17ff:
	/* 0x17ff: lea    rax,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1803:
	/* 0x1803: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1808:
	/* 0x1808: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180d:
	/* 0x180d: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1812:
	/* 0x1812: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1817:
	/* 0x1817: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_181a:
	/* 0x181a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_181f:
	/* 0x181f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1821:
	/* 0x1821: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1825:
	/* 0x1825: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_182a:
	/* 0x182a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_182f:
	/* 0x182f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1834:
	/* 0x1834: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1836:
	/* 0x1836: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_183a:
	/* 0x183a: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_183f:
	/* 0x183f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1844:
	/* 0x1844: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1849:
	/* 0x1849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184b:
	/* 0x184b: lea    rdi,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_184f:
	/* 0x184f: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1854:
	/* 0x1854: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1859:
	/* 0x1859: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_185e:
	/* 0x185e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1860:
	/* 0x1860: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1864:
	/* 0x1864: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1869:
	/* 0x1869: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_186e:
	/* 0x186e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1873:
	/* 0x1873: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1875:
	/* 0x1875: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1879:
	/* 0x1879: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_187e:
	/* 0x187e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1883:
	/* 0x1883: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1888:
	/* 0x1888: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188a:
	/* 0x188a: lea    rdi,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188e:
	/* 0x188e: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1893:
	/* 0x1893: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1898:
	/* 0x1898: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_189d:
	/* 0x189d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189f:
	/* 0x189f: lea    rdi,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18a3:
	/* 0x18a3: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_18a8:
	/* 0x18a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ad:
	/* 0x18ad: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18b2:
	/* 0x18b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b4:
	/* 0x18b4: mov    DWORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_18bc:
	/* 0x18bc: lea    rdi,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c0:
	/* 0x18c0: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18c5:
	/* 0x18c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ca:
	/* 0x18ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18cf:
	/* 0x18cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d1:
	/* 0x18d1: mov    rax,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18d6:
	/* 0x18d6: mov    QWORD PTR [r15+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18da:
	/* 0x18da: mov    rax,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18df:
	/* 0x18df: mov    QWORD PTR [r15+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18e3:
	/* 0x18e3: mov    rax,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18e8:
	/* 0x18e8: mov    QWORD PTR [r15+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18ec:
	/* 0x18ec: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_18f3:
	/* 0x18f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18f8:
	/* 0x18f8: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_18fd:
	/* 0x18fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1902:
	/* 0x1902: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1905:
	/* 0x1905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1907:
	/* 0x1907: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_190c:
	/* 0x190c: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1914:
	/* 0x1914: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1919:
	/* 0x1919: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_191e:
	/* 0x191e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1923:
	/* 0x1923: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1925:
	/* 0x1925: lea    rdi,[r15+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1929:
	/* 0x1929: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1931:
	/* 0x1931: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1936:
	/* 0x1936: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_193b:
	/* 0x193b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193d:
	/* 0x193d: lea    rdi,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1941:
	/* 0x1941: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1949:
	/* 0x1949: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_194e:
	/* 0x194e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1953:
	/* 0x1953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1955:
	/* 0x1955: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1959:
	/* 0x1959: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1960:
	/* 0x1960: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1965:
	/* 0x1965: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1968:
	/* 0x1968: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_196d:
	/* 0x196d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1970:
	/* 0x1970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1972:
	/* 0x1972: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1978:
	/* 0x1978: jmp    1b43 <generic_lsm_process_event+0x1b43> */
	goto x86_l_1b43;
x86_l_197d:
	/* 0x197d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1982:
	/* 0x1982: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_198a:
	/* 0x198a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_198f:
	/* 0x198f: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1994:
	/* 0x1994: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1997:
	/* 0x1997: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_199c:
	/* 0x199c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199e:
	/* 0x199e: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19a2:
	/* 0x19a2: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_19aa:
	/* 0x19aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19af:
	/* 0x19af: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19b4:
	/* 0x19b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b6:
	/* 0x19b6: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ba:
	/* 0x19ba: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_19c2:
	/* 0x19c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c7:
	/* 0x19c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19cc:
	/* 0x19cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ce:
	/* 0x19ce: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_19d2:
	/* 0x19d2: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_19d9:
	/* 0x19d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19de:
	/* 0x19de: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19e1:
	/* 0x19e1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19e6:
	/* 0x19e6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_19e9:
	/* 0x19e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19eb:
	/* 0x19eb: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_19f1:
	/* 0x19f1: jmp    1b43 <generic_lsm_process_event+0x1b43> */
	goto x86_l_1b43;
x86_l_19f6:
	/* 0x19f6: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fb:
	/* 0x19fb: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a00:
	/* 0x1a00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a05:
	/* 0x1a05: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a0a:
	/* 0x1a0a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1a0d:
	/* 0x1a0d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a12:
	/* 0x1a12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a14:
	/* 0x1a14: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a18:
	/* 0x1a18: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a22:
	/* 0x1a22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a27:
	/* 0x1a27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a29:
	/* 0x1a29: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2d:
	/* 0x1a2d: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a32:
	/* 0x1a32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a37:
	/* 0x1a37: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a3c:
	/* 0x1a3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3e:
	/* 0x1a3e: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a42:
	/* 0x1a42: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a47:
	/* 0x1a47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a51:
	/* 0x1a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a53:
	/* 0x1a53: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a57:
	/* 0x1a57: add    r12,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a60:
	/* 0x1a60: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1a63:
	/* 0x1a63: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a68:
	/* 0x1a68: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a6b:
	/* 0x1a6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6d:
	/* 0x1a6d: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1a73:
	/* 0x1a73: jmp    1b43 <generic_lsm_process_event+0x1b43> */
	goto x86_l_1b43;
x86_l_1a78:
	/* 0x1a78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a82:
	/* 0x1a82: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1a85:
	/* 0x1a85: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a8a:
	/* 0x1a8a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a8f:
	/* 0x1a8f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a92:
	/* 0x1a92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a94:
	/* 0x1a94: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a98:
	/* 0x1a98: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a9d:
	/* 0x1a9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aa7:
	/* 0x1aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa9:
	/* 0x1aa9: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1aad:
	/* 0x1aad: add    r12,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1ab1:
	/* 0x1ab1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ab6:
	/* 0x1ab6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1ab9:
	/* 0x1ab9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1abe:
	/* 0x1abe: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ac1:
	/* 0x1ac1: jmp    1b3b <generic_lsm_process_event+0x1b3b> */
	goto x86_l_1b3b;
x86_l_1ac3:
	/* 0x1ac3: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ac8:
	/* 0x1ac8: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1acd:
	/* 0x1acd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad2:
	/* 0x1ad2: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ad7:
	/* 0x1ad7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1adc:
	/* 0x1adc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ade:
	/* 0x1ade: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aea:
	/* 0x1aea: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1aef:
	/* 0x1aef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1af4:
	/* 0x1af4: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1af9:
	/* 0x1af9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1afe:
	/* 0x1afe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b00:
	/* 0x1b00: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b04:
	/* 0x1b04: mov    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b08:
	/* 0x1b08: add    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b11:
	/* 0x1b11: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b16:
	/* 0x1b16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b1e:
	/* 0x1b1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b20:
	/* 0x1b20: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b24:
	/* 0x1b24: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b29:
	/* 0x1b29: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1b2e:
	/* 0x1b2e: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_1b33:
	/* 0x1b33: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1b36:
	/* 0x1b36: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b3b:
	/* 0x1b3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3d:
	/* 0x1b3d: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1b43:
	/* 0x1b43: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b48:
	/* 0x1b48: jmp    b92 <generic_lsm_process_event+0xb92> */
	return 2962ULL;
x86_l_1b4d:
	/* 0x1b4d: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b52:
	/* 0x1b52: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b5a:
	/* 0x1b5a: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b62:
	/* 0x1b62: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1b6a:
	/* 0x1b6a: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b72:
	/* 0x1b72: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b82:
	/* 0x1b82: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b92:
	/* 0x1b92: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ba6:
	/* 0x1ba6: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1bab:
	/* 0x1bab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bb5:
	/* 0x1bb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb7:
	/* 0x1bb7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bba:
	/* 0x1bba: je     1ef8 <generic_lsm_process_event+0x1ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7928ULL;
	}
x86_l_1bc0:
	/* 0x1bc0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bc3:
	/* 0x1bc3: jmp    b88 <generic_lsm_process_event+0xb88> */
	return 2952ULL;
x86_l_1bc8:
	/* 0x1bc8: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1bd2:
	/* 0x1bd2: jmp    2e3a <generic_lsm_process_event+0x2e3a> */
	return 11834ULL;
x86_l_1bd7:
	/* 0x1bd7: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bdb:
	/* 0x1bdb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be0:
	/* 0x1be0: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1be8:
	/* 0x1be8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bed:
	/* 0x1bed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bef:
	/* 0x1bef: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bf8:
	/* 0x1bf8: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bfd:
	/* 0x1bfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c02:
	/* 0x1c02: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c05:
	/* 0x1c05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c07:
	/* 0x1c07: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c14:
	/* 0x1c14: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c19:
	/* 0x1c19: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c1e:
	/* 0x1c1e: lea    r12,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1c22:
	/* 0x1c22: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1c29:
	/* 0x1c29: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1c2f:
	/* 0x1c2f: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_1c34:
	/* 0x1c34: je     2602 <generic_lsm_process_event+0x2602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9730ULL;
	}
x86_l_1c3a:
	/* 0x1c3a: cmp    QWORD PTR [rsp+0x28],0x1000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798695936ULL);
x86_l_1c43:
	/* 0x1c43: jb     25d6 <generic_lsm_process_event+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9686ULL;
	}
x86_l_1c49:
	/* 0x1c49: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1c51:
	/* 0x1c51: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c55:
	/* 0x1c55: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
	return 7256ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7272ULL: goto x86_l_1c68;
	case 7276ULL: goto x86_l_1c6c;
	case 7281ULL: goto x86_l_1c71;
	case 7286ULL: goto x86_l_1c76;
	case 7295ULL: goto x86_l_1c7f;
	case 7299ULL: goto x86_l_1c83;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7322ULL: goto x86_l_1c9a;
	case 7330ULL: goto x86_l_1ca2;
	case 7332ULL: goto x86_l_1ca4;
	case 7335ULL: goto x86_l_1ca7;
	case 7341ULL: goto x86_l_1cad;
	case 7344ULL: goto x86_l_1cb0;
	case 7348ULL: goto x86_l_1cb4;
	case 7352ULL: goto x86_l_1cb8;
	case 7356ULL: goto x86_l_1cbc;
	case 7359ULL: goto x86_l_1cbf;
	case 7363ULL: goto x86_l_1cc3;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7384ULL: goto x86_l_1cd8;
	case 7387ULL: goto x86_l_1cdb;
	case 7393ULL: goto x86_l_1ce1;
	case 7397ULL: goto x86_l_1ce5;
	case 7400ULL: goto x86_l_1ce8;
	case 7406ULL: goto x86_l_1cee;
	case 7408ULL: goto x86_l_1cf0;
	case 7414ULL: goto x86_l_1cf6;
	case 7417ULL: goto x86_l_1cf9;
	case 7423ULL: goto x86_l_1cff;
	case 7426ULL: goto x86_l_1d02;
	case 7432ULL: goto x86_l_1d08;
	case 7438ULL: goto x86_l_1d0e;
	case 7442ULL: goto x86_l_1d12;
	case 7447ULL: goto x86_l_1d17;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7468ULL: goto x86_l_1d2c;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7496ULL: goto x86_l_1d48;
	case 7500ULL: goto x86_l_1d4c;
	case 7504ULL: goto x86_l_1d50;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7517ULL: goto x86_l_1d5d;
	case 7519ULL: goto x86_l_1d5f;
	case 7523ULL: goto x86_l_1d63;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7536ULL: goto x86_l_1d70;
	case 7538ULL: goto x86_l_1d72;
	case 7542ULL: goto x86_l_1d76;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7563ULL: goto x86_l_1d8b;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7577ULL: goto x86_l_1d99;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7592ULL: goto x86_l_1da8;
	case 7596ULL: goto x86_l_1dac;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7606ULL: goto x86_l_1db6;
	case 7612ULL: goto x86_l_1dbc;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7625ULL: goto x86_l_1dc9;
	case 7637ULL: goto x86_l_1dd5;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7653ULL: goto x86_l_1de5;
	case 7655ULL: goto x86_l_1de7;
	case 7659ULL: goto x86_l_1deb;
	case 7661ULL: goto x86_l_1ded;
	case 7666ULL: goto x86_l_1df2;
	case 7670ULL: goto x86_l_1df6;
	case 7675ULL: goto x86_l_1dfb;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7704ULL: goto x86_l_1e18;
	case 7712ULL: goto x86_l_1e20;
	case 7720ULL: goto x86_l_1e28;
	case 7725ULL: goto x86_l_1e2d;
	case 7732ULL: goto x86_l_1e34;
	case 7740ULL: goto x86_l_1e3c;
	case 7745ULL: goto x86_l_1e41;
	case 7747ULL: goto x86_l_1e43;
	case 7749ULL: goto x86_l_1e45;
	case 7752ULL: goto x86_l_1e48;
	case 7758ULL: goto x86_l_1e4e;
	case 7760ULL: goto x86_l_1e50;
	case 7765ULL: goto x86_l_1e55;
	case 7772ULL: goto x86_l_1e5c;
	case 7782ULL: goto x86_l_1e66;
	case 7787ULL: goto x86_l_1e6b;
	case 7792ULL: goto x86_l_1e70;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7806ULL: goto x86_l_1e7e;
	case 7809ULL: goto x86_l_1e81;
	case 7815ULL: goto x86_l_1e87;
	case 7817ULL: goto x86_l_1e89;
	case 7822ULL: goto x86_l_1e8e;
	case 7825ULL: goto x86_l_1e91;
	case 7831ULL: goto x86_l_1e97;
	case 7834ULL: goto x86_l_1e9a;
	case 7840ULL: goto x86_l_1ea0;
	case 7845ULL: goto x86_l_1ea5;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7859ULL: goto x86_l_1eb3;
	case 7863ULL: goto x86_l_1eb7;
	case 7867ULL: goto x86_l_1ebb;
	case 7872ULL: goto x86_l_1ec0;
	case 7877ULL: goto x86_l_1ec5;
	case 7879ULL: goto x86_l_1ec7;
	case 7883ULL: goto x86_l_1ecb;
	case 7887ULL: goto x86_l_1ecf;
	case 7892ULL: goto x86_l_1ed4;
	case 7897ULL: goto x86_l_1ed9;
	case 7900ULL: goto x86_l_1edc;
	case 7902ULL: goto x86_l_1ede;
	case 7907ULL: goto x86_l_1ee3;
	case 7914ULL: goto x86_l_1eea;
	case 7920ULL: goto x86_l_1ef0;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7952ULL: goto x86_l_1f10;
	case 7954ULL: goto x86_l_1f12;
	case 7957ULL: goto x86_l_1f15;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8011ULL: goto x86_l_1f4b;
	case 8019ULL: goto x86_l_1f53;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8043ULL: goto x86_l_1f6b;
	case 8048ULL: goto x86_l_1f70;
	case 8051ULL: goto x86_l_1f73;
	case 8053ULL: goto x86_l_1f75;
	case 8059ULL: goto x86_l_1f7b;
	case 8062ULL: goto x86_l_1f7e;
	case 8068ULL: goto x86_l_1f84;
	case 8070ULL: goto x86_l_1f86;
	case 8078ULL: goto x86_l_1f8e;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8088ULL: goto x86_l_1f98;
	case 8093ULL: goto x86_l_1f9d;
	case 8096ULL: goto x86_l_1fa0;
	case 8099ULL: goto x86_l_1fa3;
	case 8104ULL: goto x86_l_1fa8;
	case 8108ULL: goto x86_l_1fac;
	case 8113ULL: goto x86_l_1fb1;
	case 8118ULL: goto x86_l_1fb6;
	case 8121ULL: goto x86_l_1fb9;
	case 8123ULL: goto x86_l_1fbb;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8130ULL: goto x86_l_1fc2;
	case 8132ULL: goto x86_l_1fc4;
	case 8136ULL: goto x86_l_1fc8;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8150ULL: goto x86_l_1fd6;
	case 8156ULL: goto x86_l_1fdc;
	case 8159ULL: goto x86_l_1fdf;
	case 8165ULL: goto x86_l_1fe5;
	case 8173ULL: goto x86_l_1fed;
	case 8178ULL: goto x86_l_1ff2;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8192ULL: goto x86_l_2000;
	case 8197ULL: goto x86_l_2005;
	case 8199ULL: goto x86_l_2007;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8227ULL: goto x86_l_2023;
	case 8231ULL: goto x86_l_2027;
	case 8235ULL: goto x86_l_202b;
	case 8240ULL: goto x86_l_2030;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8250ULL: goto x86_l_203a;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8264ULL: goto x86_l_2048;
	case 8267ULL: goto x86_l_204b;
	case 8269ULL: goto x86_l_204d;
	case 8273ULL: goto x86_l_2051;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8312ULL: goto x86_l_2078;
	case 8315ULL: goto x86_l_207b;
	case 8317ULL: goto x86_l_207d;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8327ULL: goto x86_l_2087;
	case 8331ULL: goto x86_l_208b;
	case 8335ULL: goto x86_l_208f;
	case 8338ULL: goto x86_l_2092;
	case 8341ULL: goto x86_l_2095;
	case 8347ULL: goto x86_l_209b;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8373ULL: goto x86_l_20b5;
	case 8378ULL: goto x86_l_20ba;
	case 8384ULL: goto x86_l_20c0;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8397ULL: goto x86_l_20cd;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8411ULL: goto x86_l_20db;
	case 8414ULL: goto x86_l_20de;
	case 8420ULL: goto x86_l_20e4;
	case 8426ULL: goto x86_l_20ea;
	case 8431ULL: goto x86_l_20ef;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8446ULL: goto x86_l_20fe;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8455ULL: goto x86_l_2107;
	case 8461ULL: goto x86_l_210d;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8478ULL: goto x86_l_211e;
	case 8484ULL: goto x86_l_2124;
	case 8489ULL: goto x86_l_2129;
	case 8493ULL: goto x86_l_212d;
	case 8498ULL: goto x86_l_2132;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8517ULL: goto x86_l_2145;
	case 8520ULL: goto x86_l_2148;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8529ULL: goto x86_l_2151;
	case 8535ULL: goto x86_l_2157;
	case 8539ULL: goto x86_l_215b;
	case 8545ULL: goto x86_l_2161;
	case 8550ULL: goto x86_l_2166;
	case 8554ULL: goto x86_l_216a;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8611ULL: goto x86_l_21a3;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8636ULL: goto x86_l_21bc;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8649ULL: goto x86_l_21c9;
	case 8654ULL: goto x86_l_21ce;
	case 8656ULL: goto x86_l_21d0;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	case 8678ULL: goto x86_l_21e6;
	case 8684ULL: goto x86_l_21ec;
	case 8689ULL: goto x86_l_21f1;
	case 8693ULL: goto x86_l_21f5;
	case 8699ULL: goto x86_l_21fb;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8714ULL: goto x86_l_220a;
	case 8716ULL: goto x86_l_220c;
	case 8721ULL: goto x86_l_2211;
	case 8723ULL: goto x86_l_2213;
	case 8729ULL: goto x86_l_2219;
	case 8734ULL: goto x86_l_221e;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8750ULL: goto x86_l_222e;
	case 8756ULL: goto x86_l_2234;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8771ULL: goto x86_l_2243;
	case 8777ULL: goto x86_l_2249;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8804ULL: goto x86_l_2264;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8819ULL: goto x86_l_2273;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8834ULL: goto x86_l_2282;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8864ULL: goto x86_l_22a0;
	case 8870ULL: goto x86_l_22a6;
	case 8875ULL: goto x86_l_22ab;
	case 8880ULL: goto x86_l_22b0;
	case 8885ULL: goto x86_l_22b5;
	case 8891ULL: goto x86_l_22bb;
	case 8897ULL: goto x86_l_22c1;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8918ULL: goto x86_l_22d6;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8938ULL: goto x86_l_22ea;
	case 8943ULL: goto x86_l_22ef;
	case 8945ULL: goto x86_l_22f1;
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8960ULL: goto x86_l_2300;
	case 8966ULL: goto x86_l_2306;
	case 8971ULL: goto x86_l_230b;
	case 8975ULL: goto x86_l_230f;
	case 8981ULL: goto x86_l_2315;
	case 8986ULL: goto x86_l_231a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c58:
	/* 0x1c58: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1c5b:
	/* 0x1c5b: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c60:
	/* 0x1c60: call   0 <generic_lsm_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 7269ULL);
	__x86_sim_call_depth++;
	return 12605ULL;
x86_l_1c65:
	/* 0x1c65: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1c68:
	/* 0x1c68: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c6c:
	/* 0x1c6c: jmp    bac <generic_lsm_process_event+0xbac> */
	return 2988ULL;
x86_l_1c71:
	/* 0x1c71: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c76:
	/* 0x1c76: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_1c7f:
	/* 0x1c7f: lea    r13,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1c83:
	/* 0x1c83: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c93:
	/* 0x1c93: mov    rdi,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1c9a:
	/* 0x1c9a: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1ca2:
	/* 0x1ca2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca4:
	/* 0x1ca4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ca7:
	/* 0x1ca7: je     2cab <generic_lsm_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11435ULL;
	}
x86_l_1cad:
	/* 0x1cad: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1cb0:
	/* 0x1cb0: mov    WORD PTR [rax],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1cb8:
	/* 0x1cb8: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1cbc:
	/* 0x1cbc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1cbf:
	/* 0x1cbf: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1cc3:
	/* 0x1cc3: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd1:
	/* 0x1cd1: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1cd6:
	/* 0x1cd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd8:
	/* 0x1cd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cdb:
	/* 0x1cdb: js     2cab <generic_lsm_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11435ULL;
	}
x86_l_1ce1:
	/* 0x1ce1: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1ce5:
	/* 0x1ce5: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1ce8:
	/* 0x1ce8: jg     2654 <generic_lsm_process_event+0x2654> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9812ULL;
	}
x86_l_1cee:
	/* 0x1cee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cf0:
	/* 0x1cf0: je     26f3 <generic_lsm_process_event+0x26f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9971ULL;
	}
x86_l_1cf6:
	/* 0x1cf6: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1cf9:
	/* 0x1cf9: je     26f3 <generic_lsm_process_event+0x26f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9971ULL;
	}
x86_l_1cff:
	/* 0x1cff: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1d02:
	/* 0x1d02: jne    28b5 <generic_lsm_process_event+0x28b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10421ULL;
	}
x86_l_1d08:
	/* 0x1d08: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1d12:
	/* 0x1d12: jmp    2814 <generic_lsm_process_event+0x2814> */
	return 10260ULL;
x86_l_1d17:
	/* 0x1d17: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d1b:
	/* 0x1d1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d20:
	/* 0x1d20: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d25:
	/* 0x1d25: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d2a:
	/* 0x1d2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2c:
	/* 0x1d2c: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d30:
	/* 0x1d30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d35:
	/* 0x1d35: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1d38:
	/* 0x1d38: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d3d:
	/* 0x1d3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3f:
	/* 0x1d3f: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d44:
	/* 0x1d44: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d48:
	/* 0x1d48: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d4c:
	/* 0x1d4c: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1d50:
	/* 0x1d50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d55:
	/* 0x1d55: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d5d:
	/* 0x1d5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d5f:
	/* 0x1d5f: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1d63:
	/* 0x1d63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d68:
	/* 0x1d68: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d70:
	/* 0x1d70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d72:
	/* 0x1d72: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1d76:
	/* 0x1d76: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1d7c:
	/* 0x1d7c: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d81:
	/* 0x1d81: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d86:
	/* 0x1d86: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    rdi,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1d92:
	/* 0x1d92: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d97:
	/* 0x1d97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d99:
	/* 0x1d99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d9c:
	/* 0x1d9c: je     1db6 <generic_lsm_process_event+0x1db6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1db6;
	}
x86_l_1d9e:
	/* 0x1d9e: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1da0:
	/* 0x1da0: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da5:
	/* 0x1da5: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da8:
	/* 0x1da8: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dac:
	/* 0x1dac: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1db0:
	/* 0x1db0: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1db3:
	/* 0x1db3: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1db6:
	/* 0x1db6: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_1dbc:
	/* 0x1dbc: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1dbf:
	/* 0x1dbf: jmp    2e3a <generic_lsm_process_event+0x2e3a> */
	return 11834ULL;
x86_l_1dc4:
	/* 0x1dc4: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    QWORD PTR [rax+r13*1+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 618475290624ULL);
x86_l_1dd5:
	/* 0x1dd5: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1ddb:
	/* 0x1ddb: jmp    bac <generic_lsm_process_event+0xbac> */
	return 2988ULL;
x86_l_1de0:
	/* 0x1de0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1de5:
	/* 0x1de5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de7:
	/* 0x1de7: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1deb:
	/* 0x1deb: jne    1df6 <generic_lsm_process_event+0x1df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1df6;
	}
x86_l_1ded:
	/* 0x1ded: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1df2:
	/* 0x1df2: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1df6:
	/* 0x1df6: mov    rcx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dfb:
	/* 0x1dfb: mov    rdx,QWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e00:
	/* 0x1e00: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e05:
	/* 0x1e05: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e0a:
	/* 0x1e0a: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1e18:
	/* 0x1e18: mov    QWORD PTR [rsp+0xb0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e20:
	/* 0x1e20: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1e28:
	/* 0x1e28: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e2d:
	/* 0x1e2d: mov    rdi,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_1e34:
	/* 0x1e34: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e3c:
	/* 0x1e3c: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e41:
	/* 0x1e41: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e43:
	/* 0x1e43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e45:
	/* 0x1e45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e48:
	/* 0x1e48: je     26a8 <generic_lsm_process_event+0x26a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9896ULL;
	}
x86_l_1e4e:
	/* 0x1e4e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1e50:
	/* 0x1e50: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e55:
	/* 0x1e55: mov    WORD PTR [rsp+0x52],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 352187318277ULL);
x86_l_1e5c:
	/* 0x1e5c: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_1e66:
	/* 0x1e66: mov    QWORD PTR [rsp+0x54],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1e6b:
	/* 0x1e6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e70:
	/* 0x1e70: mov    rdi,QWORD PTR [rip+0x1b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1e77:
	/* 0x1e77: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e7c:
	/* 0x1e7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7e:
	/* 0x1e7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e81:
	/* 0x1e81: je     2680 <generic_lsm_process_event+0x2680> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9856ULL;
	}
x86_l_1e87:
	/* 0x1e87: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e89:
	/* 0x1e89: jmp    26a8 <generic_lsm_process_event+0x26a8> */
	return 9896ULL;
x86_l_1e8e:
	/* 0x1e8e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e91:
	/* 0x1e91: je     20c2 <generic_lsm_process_event+0x20c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c2;
	}
x86_l_1e97:
	/* 0x1e97: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e9a:
	/* 0x1e9a: jne    249d <generic_lsm_process_event+0x249d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9373ULL;
	}
x86_l_1ea0:
	/* 0x1ea0: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ea5:
	/* 0x1ea5: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_1eab:
	/* 0x1eab: jmp    20cd <generic_lsm_process_event+0x20cd> */
	goto x86_l_20cd;
x86_l_1eb0:
	/* 0x1eb0: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_1eb3:
	/* 0x1eb3: lea    rdi,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb7:
	/* 0x1eb7: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ebb:
	/* 0x1ebb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ec0:
	/* 0x1ec0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ec5:
	/* 0x1ec5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec7:
	/* 0x1ec7: lea    rdi,[r13+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1ecb:
	/* 0x1ecb: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1ecf:
	/* 0x1ecf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ed4:
	/* 0x1ed4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1ed9:
	/* 0x1ed9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1edc:
	/* 0x1edc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ede:
	/* 0x1ede: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1ee3:
	/* 0x1ee3: movbe  WORD PTR [r13+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1eea:
	/* 0x1eea: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1ef0:
	/* 0x1ef0: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1ef3:
	/* 0x1ef3: jmp    2e3a <generic_lsm_process_event+0x2e3a> */
	return 11834ULL;
x86_l_1ef8:
	/* 0x1ef8: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1efd:
	/* 0x1efd: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f01:
	/* 0x1f01: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f06:
	/* 0x1f06: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1f10:
	/* 0x1f10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f12:
	/* 0x1f12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f15:
	/* 0x1f15: js     1bc0 <generic_lsm_process_event+0x1bc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7104ULL;
	}
x86_l_1f1b:
	/* 0x1f1b: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f20:
	/* 0x1f20: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f24:
	/* 0x1f24: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f29:
	/* 0x1f29: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f31:
	/* 0x1f31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f36:
	/* 0x1f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f38:
	/* 0x1f38: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f3d:
	/* 0x1f3d: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f41:
	/* 0x1f41: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f46:
	/* 0x1f46: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1f4b:
	/* 0x1f4b: add    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 176ULL);
x86_l_1f53:
	/* 0x1f53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f58:
	/* 0x1f58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f5a:
	/* 0x1f5a: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_1f5e:
	/* 0x1f5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f63:
	/* 0x1f63: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f6b:
	/* 0x1f6b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f70:
	/* 0x1f70: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f73:
	/* 0x1f73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f75:
	/* 0x1f75: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1f7b:
	/* 0x1f7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f7e:
	/* 0x1f7e: jne    b88 <generic_lsm_process_event+0xb88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2952ULL;
	}
x86_l_1f84:
	/* 0x1f84: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f86:
	/* 0x1f86: cmp    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_1f8e:
	/* 0x1f8e: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1f91:
	/* 0x1f91: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f96:
	/* 0x1f96: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f98:
	/* 0x1f98: jmp    b88 <generic_lsm_process_event+0xb88> */
	return 2952ULL;
x86_l_1f9d:
	/* 0x1f9d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa0:
	/* 0x1fa0: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1fa3:
	/* 0x1fa3: jmp    b8d <generic_lsm_process_event+0xb8d> */
	return 2957ULL;
x86_l_1fa8:
	/* 0x1fa8: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1fac:
	/* 0x1fac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fb1:
	/* 0x1fb1: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_1fb6:
	/* 0x1fb6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1fb9:
	/* 0x1fb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fbb:
	/* 0x1fbb: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1fbe:
	/* 0x1fbe: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_1fc0:
	/* 0x1fc0: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1fc2:
	/* 0x1fc2: js     1fc8 <generic_lsm_process_event+0x1fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1fc8;
	}
x86_l_1fc4:
	/* 0x1fc4: mov    BYTE PTR [r13+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_1fc8:
	/* 0x1fc8: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_1fce:
	/* 0x1fce: jmp    bac <generic_lsm_process_event+0xbac> */
	return 2988ULL;
x86_l_1fd3:
	/* 0x1fd3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1fd6:
	/* 0x1fd6: je     2717 <generic_lsm_process_event+0x2717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10007ULL;
	}
x86_l_1fdc:
	/* 0x1fdc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1fdf:
	/* 0x1fdf: jne    2722 <generic_lsm_process_event+0x2722> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10018ULL;
	}
x86_l_1fe5:
	/* 0x1fe5: lea    rax,[r12+0x5e58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_1fed:
	/* 0x1fed: jmp    271f <generic_lsm_process_event+0x271f> */
	return 10015ULL;
x86_l_1ff2:
	/* 0x1ff2: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ff6:
	/* 0x1ff6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2000:
	/* 0x2000: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2005:
	/* 0x2005: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2007:
	/* 0x2007: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_200b:
	/* 0x200b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2010:
	/* 0x2010: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2013:
	/* 0x2013: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2018:
	/* 0x2018: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201a:
	/* 0x201a: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_201f:
	/* 0x201f: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2023:
	/* 0x2023: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2027:
	/* 0x2027: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_202b:
	/* 0x202b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2030:
	/* 0x2030: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2035:
	/* 0x2035: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2038:
	/* 0x2038: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_203a:
	/* 0x203a: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_203e:
	/* 0x203e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2043:
	/* 0x2043: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2048:
	/* 0x2048: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_204b:
	/* 0x204b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204d:
	/* 0x204d: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2051:
	/* 0x2051: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2057:
	/* 0x2057: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_205c:
	/* 0x205c: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2060:
	/* 0x2060: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2065:
	/* 0x2065: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_206a:
	/* 0x206a: mov    rdi,QWORD PTR [rip+0x1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2071:
	/* 0x2071: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2076:
	/* 0x2076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2078:
	/* 0x2078: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_207b:
	/* 0x207b: je     2095 <generic_lsm_process_event+0x2095> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2095;
	}
x86_l_207d:
	/* 0x207d: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_207f:
	/* 0x207f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2084:
	/* 0x2084: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2087:
	/* 0x2087: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_208b:
	/* 0x208b: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_208f:
	/* 0x208f: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2092:
	/* 0x2092: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2095:
	/* 0x2095: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_209b:
	/* 0x209b: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_209e:
	/* 0x209e: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20a3:
	/* 0x20a3: jmp    b8d <generic_lsm_process_event+0xb8d> */
	return 2957ULL;
x86_l_20a8:
	/* 0x20a8: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20ad:
	/* 0x20ad: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_20b3:
	/* 0x20b3: jmp    20cd <generic_lsm_process_event+0x20cd> */
	goto x86_l_20cd;
x86_l_20b5:
	/* 0x20b5: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20ba:
	/* 0x20ba: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_20c0:
	/* 0x20c0: jmp    20cd <generic_lsm_process_event+0x20cd> */
	goto x86_l_20cd;
x86_l_20c2:
	/* 0x20c2: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20c7:
	/* 0x20c7: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_20cd:
	/* 0x20cd: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d0:
	/* 0x20d0: test   BYTE PTR [rsp+0x30],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430224ULL);
x86_l_20d5:
	/* 0x20d5: jne    24b1 <generic_lsm_process_event+0x24b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9393ULL;
	}
x86_l_20db:
	/* 0x20db: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_20de:
	/* 0x20de: je     2559 <generic_lsm_process_event+0x2559> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9561ULL;
	}
x86_l_20e4:
	/* 0x20e4: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_20ea:
	/* 0x20ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20ef:
	/* 0x20ef: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20f4:
	/* 0x20f4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20f9:
	/* 0x20f9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20fe:
	/* 0x20fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2100:
	/* 0x2100: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2105:
	/* 0x2105: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2107:
	/* 0x2107: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9359ULL;
	}
x86_l_210d:
	/* 0x210d: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2112:
	/* 0x2112: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2117:
	/* 0x2117: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_211e:
	/* 0x211e: ja     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9359ULL;
	}
x86_l_2124:
	/* 0x2124: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2129:
	/* 0x2129: lea    rdi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_212d:
	/* 0x212d: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2132:
	/* 0x2132: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2138:
	/* 0x2138: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_213b:
	/* 0x213b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2140:
	/* 0x2140: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2145:
	/* 0x2145: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2148:
	/* 0x2148: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_214a:
	/* 0x214a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_214f:
	/* 0x214f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2151:
	/* 0x2151: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9359ULL;
	}
x86_l_2157:
	/* 0x2157: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_215b:
	/* 0x215b: je     255c <generic_lsm_process_event+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9564ULL;
	}
x86_l_2161:
	/* 0x2161: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2166:
	/* 0x2166: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_216a:
	/* 0x216a: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2170:
	/* 0x2170: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2175:
	/* 0x2175: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_217a:
	/* 0x217a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_217f:
	/* 0x217f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2181:
	/* 0x2181: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2186:
	/* 0x2186: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2188:
	/* 0x2188: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9359ULL;
	}
x86_l_218e:
	/* 0x218e: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2193:
	/* 0x2193: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2198:
	/* 0x2198: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_219d:
	/* 0x219d: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_21a3:
	/* 0x21a3: ja     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9359ULL;
	}
x86_l_21a9:
	/* 0x21a9: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21ae:
	/* 0x21ae: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21b1:
	/* 0x21b1: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21b6:
	/* 0x21b6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_21bc:
	/* 0x21bc: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21bf:
	/* 0x21bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21c4:
	/* 0x21c4: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_21c9:
	/* 0x21c9: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ce:
	/* 0x21ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d0:
	/* 0x21d0: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_21d5:
	/* 0x21d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21d7:
	/* 0x21d7: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9359ULL;
	}
x86_l_21dd:
	/* 0x21dd: add    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_21e2:
	/* 0x21e2: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_21e6:
	/* 0x21e6: jb     255c <generic_lsm_process_event+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9564ULL;
	}
x86_l_21ec:
	/* 0x21ec: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21f1:
	/* 0x21f1: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21f5:
	/* 0x21f5: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_21fb:
	/* 0x21fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2200:
	/* 0x2200: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2205:
	/* 0x2205: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_220a:
	/* 0x220a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220c:
	/* 0x220c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2211:
	/* 0x2211: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2213:
	/* 0x2213: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9359ULL;
	}
x86_l_2219:
	/* 0x2219: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_221e:
	/* 0x221e: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2223:
	/* 0x2223: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2228:
	/* 0x2228: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_222e:
	/* 0x222e: ja     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9359ULL;
	}
x86_l_2234:
	/* 0x2234: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2239:
	/* 0x2239: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_223e:
	/* 0x223e: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2243:
	/* 0x2243: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2249:
	/* 0x2249: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_224c:
	/* 0x224c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2251:
	/* 0x2251: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2256:
	/* 0x2256: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_225b:
	/* 0x225b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225d:
	/* 0x225d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2262:
	/* 0x2262: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2264:
	/* 0x2264: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9359ULL;
	}
x86_l_226a:
	/* 0x226a: add    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_226f:
	/* 0x226f: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_2273:
	/* 0x2273: je     255c <generic_lsm_process_event+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9564ULL;
	}
x86_l_2279:
	/* 0x2279: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_227e:
	/* 0x227e: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2282:
	/* 0x2282: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2288:
	/* 0x2288: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_228d:
	/* 0x228d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2292:
	/* 0x2292: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2297:
	/* 0x2297: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2299:
	/* 0x2299: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_229e:
	/* 0x229e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22a0:
	/* 0x22a0: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9359ULL;
	}
x86_l_22a6:
	/* 0x22a6: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_22ab:
	/* 0x22ab: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_22b0:
	/* 0x22b0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22b5:
	/* 0x22b5: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_22bb:
	/* 0x22bb: ja     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9359ULL;
	}
x86_l_22c1:
	/* 0x22c1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22c6:
	/* 0x22c6: add    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_22cb:
	/* 0x22cb: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22d0:
	/* 0x22d0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_22d6:
	/* 0x22d6: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22d9:
	/* 0x22d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22de:
	/* 0x22de: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_22e3:
	/* 0x22e3: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22e8:
	/* 0x22e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ea:
	/* 0x22ea: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_22ef:
	/* 0x22ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f1:
	/* 0x22f1: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9359ULL;
	}
x86_l_22f7:
	/* 0x22f7: add    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_22fc:
	/* 0x22fc: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2300:
	/* 0x2300: jb     255c <generic_lsm_process_event+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9564ULL;
	}
x86_l_2306:
	/* 0x2306: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_230b:
	/* 0x230b: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_230f:
	/* 0x230f: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2315:
	/* 0x2315: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_231a:
	/* 0x231a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
	return 8991ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 8998ULL: goto x86_l_2326;
	case 9003ULL: goto x86_l_232b;
	case 9005ULL: goto x86_l_232d;
	case 9011ULL: goto x86_l_2333;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9026ULL: goto x86_l_2342;
	case 9032ULL: goto x86_l_2348;
	case 9038ULL: goto x86_l_234e;
	case 9043ULL: goto x86_l_2353;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9059ULL: goto x86_l_2363;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9086ULL: goto x86_l_237e;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9101ULL: goto x86_l_238d;
	case 9107ULL: goto x86_l_2393;
	case 9112ULL: goto x86_l_2398;
	case 9116ULL: goto x86_l_239c;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9146ULL: goto x86_l_23ba;
	case 9152ULL: goto x86_l_23c0;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9167ULL: goto x86_l_23cf;
	case 9173ULL: goto x86_l_23d5;
	case 9179ULL: goto x86_l_23db;
	case 9184ULL: goto x86_l_23e0;
	case 9189ULL: goto x86_l_23e5;
	case 9194ULL: goto x86_l_23ea;
	case 9200ULL: goto x86_l_23f0;
	case 9203ULL: goto x86_l_23f3;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9218ULL: goto x86_l_2402;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9227ULL: goto x86_l_240b;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9242ULL: goto x86_l_241a;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9257ULL: goto x86_l_2429;
	case 9263ULL: goto x86_l_242f;
	case 9268ULL: goto x86_l_2434;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9280ULL: goto x86_l_2440;
	case 9285ULL: goto x86_l_2445;
	case 9287ULL: goto x86_l_2447;
	case 9289ULL: goto x86_l_2449;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9306ULL: goto x86_l_245a;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9324ULL: goto x86_l_246c;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9340ULL: goto x86_l_247c;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9349ULL: goto x86_l_2485;
	case 9351ULL: goto x86_l_2487;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9400ULL: goto x86_l_24b8;
	case 9404ULL: goto x86_l_24bc;
	case 9406ULL: goto x86_l_24be;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9451ULL: goto x86_l_24eb;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9471ULL: goto x86_l_24ff;
	case 9479ULL: goto x86_l_2507;
	case 9484ULL: goto x86_l_250c;
	case 9486ULL: goto x86_l_250e;
	case 9488ULL: goto x86_l_2510;
	case 9491ULL: goto x86_l_2513;
	case 9497ULL: goto x86_l_2519;
	case 9499ULL: goto x86_l_251b;
	case 9504ULL: goto x86_l_2520;
	case 9511ULL: goto x86_l_2527;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9545ULL: goto x86_l_2549;
	case 9548ULL: goto x86_l_254c;
	case 9554ULL: goto x86_l_2552;
	case 9556ULL: goto x86_l_2554;
	case 9561ULL: goto x86_l_2559;
	case 9564ULL: goto x86_l_255c;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9583ULL: goto x86_l_256f;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9602ULL: goto x86_l_2582;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9619ULL: goto x86_l_2593;
	case 9626ULL: goto x86_l_259a;
	case 9629ULL: goto x86_l_259d;
	case 9635ULL: goto x86_l_25a3;
	case 9640ULL: goto x86_l_25a8;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9655ULL: goto x86_l_25b7;
	case 9660ULL: goto x86_l_25bc;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9673ULL: goto x86_l_25c9;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9686ULL: goto x86_l_25d6;
	case 9691ULL: goto x86_l_25db;
	case 9697ULL: goto x86_l_25e1;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9714ULL: goto x86_l_25f2;
	case 9721ULL: goto x86_l_25f9;
	case 9724ULL: goto x86_l_25fc;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9768ULL: goto x86_l_2628;
	case 9770ULL: goto x86_l_262a;
	case 9772ULL: goto x86_l_262c;
	case 9774ULL: goto x86_l_262e;
	case 9779ULL: goto x86_l_2633;
	case 9783ULL: goto x86_l_2637;
	case 9788ULL: goto x86_l_263c;
	case 9791ULL: goto x86_l_263f;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9815ULL: goto x86_l_2657;
	case 9821ULL: goto x86_l_265d;
	case 9824ULL: goto x86_l_2660;
	case 9830ULL: goto x86_l_2666;
	case 9835ULL: goto x86_l_266b;
	case 9841ULL: goto x86_l_2671;
	case 9847ULL: goto x86_l_2677;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9867ULL: goto x86_l_268b;
	case 9872ULL: goto x86_l_2690;
	case 9879ULL: goto x86_l_2697;
	case 9884ULL: goto x86_l_269c;
	case 9892ULL: goto x86_l_26a4;
	case 9894ULL: goto x86_l_26a6;
	case 9896ULL: goto x86_l_26a8;
	case 9902ULL: goto x86_l_26ae;
	case 9908ULL: goto x86_l_26b4;
	case 9913ULL: goto x86_l_26b9;
	case 9921ULL: goto x86_l_26c1;
	case 9926ULL: goto x86_l_26c6;
	case 9933ULL: goto x86_l_26cd;
	case 9938ULL: goto x86_l_26d2;
	case 9943ULL: goto x86_l_26d7;
	case 9945ULL: goto x86_l_26d9;
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9960ULL: goto x86_l_26e8;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9975ULL: goto x86_l_26f7;
	case 9982ULL: goto x86_l_26fe;
	case 9987ULL: goto x86_l_2703;
	case 9995ULL: goto x86_l_270b;
	case 9997ULL: goto x86_l_270d;
	case 10005ULL: goto x86_l_2715;
	case 10007ULL: goto x86_l_2717;
	case 10015ULL: goto x86_l_271f;
	case 10018ULL: goto x86_l_2722;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10036ULL: goto x86_l_2734;
	case 10041ULL: goto x86_l_2739;
	case 10046ULL: goto x86_l_273e;
	case 10048ULL: goto x86_l_2740;
	case 10056ULL: goto x86_l_2748;
	case 10062ULL: goto x86_l_274e;
	case 10066ULL: goto x86_l_2752;
	case 10068ULL: goto x86_l_2754;
	case 10075ULL: goto x86_l_275b;
	case 10077ULL: goto x86_l_275d;
	case 10080ULL: goto x86_l_2760;
	case 10086ULL: goto x86_l_2766;
	case 10090ULL: goto x86_l_276a;
	case 10095ULL: goto x86_l_276f;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10106ULL: goto x86_l_277a;
	case 10111ULL: goto x86_l_277f;
	case 10114ULL: goto x86_l_2782;
	case 10118ULL: goto x86_l_2786;
	case 10123ULL: goto x86_l_278b;
	case 10130ULL: goto x86_l_2792;
	case 10136ULL: goto x86_l_2798;
	case 10141ULL: goto x86_l_279d;
	case 10144ULL: goto x86_l_27a0;
	case 10150ULL: goto x86_l_27a6;
	case 10153ULL: goto x86_l_27a9;
	case 10159ULL: goto x86_l_27af;
	case 10166ULL: goto x86_l_27b6;
	case 10172ULL: goto x86_l_27bc;
	case 10176ULL: goto x86_l_27c0;
	case 10180ULL: goto x86_l_27c4;
	case 10186ULL: goto x86_l_27ca;
	case 10191ULL: goto x86_l_27cf;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10201ULL: goto x86_l_27d9;
	case 10203ULL: goto x86_l_27db;
	case 10205ULL: goto x86_l_27dd;
	case 10207ULL: goto x86_l_27df;
	case 10211ULL: goto x86_l_27e3;
	case 10214ULL: goto x86_l_27e6;
	case 10217ULL: goto x86_l_27e9;
	case 10219ULL: goto x86_l_27eb;
	case 10225ULL: goto x86_l_27f1;
	case 10230ULL: goto x86_l_27f6;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10249ULL: goto x86_l_2809;
	case 10256ULL: goto x86_l_2810;
	case 10260ULL: goto x86_l_2814;
	case 10264ULL: goto x86_l_2818;
	case 10268ULL: goto x86_l_281c;
	case 10273ULL: goto x86_l_2821;
	case 10277ULL: goto x86_l_2825;
	case 10283ULL: goto x86_l_282b;
	case 10293ULL: goto x86_l_2835;
	case 10297ULL: goto x86_l_2839;
	case 10303ULL: goto x86_l_283f;
	case 10307ULL: goto x86_l_2843;
	case 10312ULL: goto x86_l_2848;
	case 10316ULL: goto x86_l_284c;
	case 10319ULL: goto x86_l_284f;
	case 10324ULL: goto x86_l_2854;
	case 10329ULL: goto x86_l_2859;
	case 10331ULL: goto x86_l_285b;
	case 10334ULL: goto x86_l_285e;
	case 10340ULL: goto x86_l_2864;
	case 10344ULL: goto x86_l_2868;
	case 10347ULL: goto x86_l_286b;
	case 10349ULL: goto x86_l_286d;
	case 10351ULL: goto x86_l_286f;
	case 10353ULL: goto x86_l_2871;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10361ULL: goto x86_l_2879;
	case 10363ULL: goto x86_l_287b;
	case 10369ULL: goto x86_l_2881;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10378ULL: goto x86_l_288a;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10385ULL: goto x86_l_2891;
	case 10390ULL: goto x86_l_2896;
	case 10392ULL: goto x86_l_2898;
	case 10398ULL: goto x86_l_289e;
	case 10402ULL: goto x86_l_28a2;
	case 10404ULL: goto x86_l_28a4;
	case 10408ULL: goto x86_l_28a8;
	case 10415ULL: goto x86_l_28af;
	case 10419ULL: goto x86_l_28b3;
	case 10421ULL: goto x86_l_28b5;
	case 10425ULL: goto x86_l_28b9;
	case 10430ULL: goto x86_l_28be;
	case 10434ULL: goto x86_l_28c2;
	case 10441ULL: goto x86_l_28c9;
	case 10445ULL: goto x86_l_28cd;
	case 10447ULL: goto x86_l_28cf;
	case 10451ULL: goto x86_l_28d3;
	case 10455ULL: goto x86_l_28d7;
	case 10459ULL: goto x86_l_28db;
	case 10464ULL: goto x86_l_28e0;
	case 10468ULL: goto x86_l_28e4;
	case 10474ULL: goto x86_l_28ea;
	case 10484ULL: goto x86_l_28f4;
	case 10488ULL: goto x86_l_28f8;
	case 10494ULL: goto x86_l_28fe;
	case 10498ULL: goto x86_l_2902;
	case 10503ULL: goto x86_l_2907;
	case 10507ULL: goto x86_l_290b;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10522ULL: goto x86_l_291a;
	case 10525ULL: goto x86_l_291d;
	case 10531ULL: goto x86_l_2923;
	case 10535ULL: goto x86_l_2927;
	case 10538ULL: goto x86_l_292a;
	case 10540ULL: goto x86_l_292c;
	case 10542ULL: goto x86_l_292e;
	case 10544ULL: goto x86_l_2930;
	case 10547ULL: goto x86_l_2933;
	case 10549ULL: goto x86_l_2935;
	case 10552ULL: goto x86_l_2938;
	case 10554ULL: goto x86_l_293a;
	case 10560ULL: goto x86_l_2940;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10569ULL: goto x86_l_2949;
	case 10571ULL: goto x86_l_294b;
	case 10574ULL: goto x86_l_294e;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10583ULL: goto x86_l_2957;
	case 10589ULL: goto x86_l_295d;
	case 10593ULL: goto x86_l_2961;
	case 10595ULL: goto x86_l_2963;
	case 10599ULL: goto x86_l_2967;
	case 10606ULL: goto x86_l_296e;
	case 10610ULL: goto x86_l_2972;
	case 10612ULL: goto x86_l_2974;
	case 10616ULL: goto x86_l_2978;
	case 10623ULL: goto x86_l_297f;
	case 10627ULL: goto x86_l_2983;
	case 10629ULL: goto x86_l_2985;
	case 10633ULL: goto x86_l_2989;
	case 10637ULL: goto x86_l_298d;
	case 10641ULL: goto x86_l_2991;
	case 10646ULL: goto x86_l_2996;
	case 10650ULL: goto x86_l_299a;
	case 10656ULL: goto x86_l_29a0;
	case 10666ULL: goto x86_l_29aa;
	case 10670ULL: goto x86_l_29ae;
	case 10676ULL: goto x86_l_29b4;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10689ULL: goto x86_l_29c1;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10702ULL: goto x86_l_29ce;
	case 10704ULL: goto x86_l_29d0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_231f:
	/* 0x231f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2324:
	/* 0x2324: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2326:
	/* 0x2326: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_232b:
	/* 0x232b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_232d:
	/* 0x232d: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_248f;
	}
x86_l_2333:
	/* 0x2333: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2338:
	/* 0x2338: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_233d:
	/* 0x233d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2342:
	/* 0x2342: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2348:
	/* 0x2348: ja     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_248f;
	}
x86_l_234e:
	/* 0x234e: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2353:
	/* 0x2353: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2358:
	/* 0x2358: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_235d:
	/* 0x235d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2363:
	/* 0x2363: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2366:
	/* 0x2366: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_236b:
	/* 0x236b: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2370:
	/* 0x2370: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2375:
	/* 0x2375: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2377:
	/* 0x2377: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_237c:
	/* 0x237c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_237e:
	/* 0x237e: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_248f;
	}
x86_l_2384:
	/* 0x2384: add    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2389:
	/* 0x2389: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_238d:
	/* 0x238d: je     255c <generic_lsm_process_event+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_255c;
	}
x86_l_2393:
	/* 0x2393: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2398:
	/* 0x2398: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_239c:
	/* 0x239c: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_23a2:
	/* 0x23a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23a7:
	/* 0x23a7: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_23ac:
	/* 0x23ac: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23b1:
	/* 0x23b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b3:
	/* 0x23b3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_23b8:
	/* 0x23b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23ba:
	/* 0x23ba: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_248f;
	}
x86_l_23c0:
	/* 0x23c0: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_23c5:
	/* 0x23c5: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_23ca:
	/* 0x23ca: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23cf:
	/* 0x23cf: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_23d5:
	/* 0x23d5: ja     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_248f;
	}
x86_l_23db:
	/* 0x23db: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23e0:
	/* 0x23e0: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_23e5:
	/* 0x23e5: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23ea:
	/* 0x23ea: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_23f0:
	/* 0x23f0: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23f3:
	/* 0x23f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23f8:
	/* 0x23f8: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_23fd:
	/* 0x23fd: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2402:
	/* 0x2402: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2404:
	/* 0x2404: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2409:
	/* 0x2409: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_240b:
	/* 0x240b: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_248f;
	}
x86_l_2411:
	/* 0x2411: add    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2416:
	/* 0x2416: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_241a:
	/* 0x241a: jb     255c <generic_lsm_process_event+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_255c;
	}
x86_l_2420:
	/* 0x2420: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2425:
	/* 0x2425: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2429:
	/* 0x2429: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_242f:
	/* 0x242f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2434:
	/* 0x2434: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2439:
	/* 0x2439: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_243e:
	/* 0x243e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2440:
	/* 0x2440: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2445:
	/* 0x2445: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2447:
	/* 0x2447: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_248f;
	}
x86_l_2449:
	/* 0x2449: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_244e:
	/* 0x244e: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2453:
	/* 0x2453: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_245a:
	/* 0x245a: ja     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_248f;
	}
x86_l_245c:
	/* 0x245c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2461:
	/* 0x2461: add    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2466:
	/* 0x2466: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_246c:
	/* 0x246c: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_246f:
	/* 0x246f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2474:
	/* 0x2474: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2479:
	/* 0x2479: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_247c:
	/* 0x247c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247e:
	/* 0x247e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2483:
	/* 0x2483: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2485:
	/* 0x2485: js     248f <generic_lsm_process_event+0x248f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_248f;
	}
x86_l_2487:
	/* 0x2487: add    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_248a:
	/* 0x248a: jmp    255c <generic_lsm_process_event+0x255c> */
	goto x86_l_255c;
x86_l_248f:
	/* 0x248f: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2494:
	/* 0x2494: mov    DWORD PTR [rbp+rax*1+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2498:
	/* 0x2498: jmp    d19 <generic_lsm_process_event+0xd19> */
	return 3353ULL;
x86_l_249d:
	/* 0x249d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24a0:
	/* 0x24a0: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_24a6:
	/* 0x24a6: test   BYTE PTR [rsp+0x30],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430224ULL);
x86_l_24ab:
	/* 0x24ab: je     255c <generic_lsm_process_event+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_255c;
	}
x86_l_24b1:
	/* 0x24b1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_24b6:
	/* 0x24b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b8:
	/* 0x24b8: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_24bc:
	/* 0x24bc: jne    24c2 <generic_lsm_process_event+0x24c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24c2;
	}
x86_l_24be:
	/* 0x24be: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24c2:
	/* 0x24c2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24c7:
	/* 0x24c7: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24cb:
	/* 0x24cb: mov    rdx,QWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24cf:
	/* 0x24cf: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24d4:
	/* 0x24d4: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d9:
	/* 0x24d9: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24de:
	/* 0x24de: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_24e3:
	/* 0x24e3: mov    QWORD PTR [rsp+0xb0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_24eb:
	/* 0x24eb: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_24f3:
	/* 0x24f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24f8:
	/* 0x24f8: mov    rdi,QWORD PTR [rip+0x1ab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_24ff:
	/* 0x24ff: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2507:
	/* 0x2507: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_250c:
	/* 0x250c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_250e:
	/* 0x250e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2510:
	/* 0x2510: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2513:
	/* 0x2513: je     26db <generic_lsm_process_event+0x26db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26db;
	}
x86_l_2519:
	/* 0x2519: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_251b:
	/* 0x251b: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2520:
	/* 0x2520: mov    WORD PTR [rsp+0x52],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 352187318277ULL);
x86_l_2527:
	/* 0x2527: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2531:
	/* 0x2531: mov    QWORD PTR [rsp+0x54],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2536:
	/* 0x2536: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_253b:
	/* 0x253b: mov    rdi,QWORD PTR [rip+0x1ab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2542:
	/* 0x2542: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2547:
	/* 0x2547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2549:
	/* 0x2549: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_254c:
	/* 0x254c: je     26b9 <generic_lsm_process_event+0x26b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b9;
	}
x86_l_2552:
	/* 0x2552: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2554:
	/* 0x2554: jmp    26db <generic_lsm_process_event+0x26db> */
	goto x86_l_26db;
x86_l_2559:
	/* 0x2559: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_255c:
	/* 0x255c: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2561:
	/* 0x2561: mov    DWORD PTR [rbp+rax*1+0x0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2566:
	/* 0x2566: mov    DWORD PTR [rbp+rax*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_256b:
	/* 0x256b: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_256f:
	/* 0x256f: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2572:
	/* 0x2572: jmp    d19 <generic_lsm_process_event+0xd19> */
	return 3353ULL;
x86_l_2577:
	/* 0x2577: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_257c:
	/* 0x257c: add    rax,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2582:
	/* 0x2582: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_258a:
	/* 0x258a: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_258f:
	/* 0x258f: lea    r12d,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2593:
	/* 0x2593: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_259a:
	/* 0x259a: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_259d:
	/* 0x259d: mov    r13d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 12ULL);
x86_l_25a3:
	/* 0x25a3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25a8:
	/* 0x25a8: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_25ae:
	/* 0x25ae: mov    ebp,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4095ULL);
x86_l_25b3:
	/* 0x25b3: cmovb  rbp,rax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_25b7:
	/* 0x25b7: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25bc:
	/* 0x25bc: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_25c2:
	/* 0x25c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25c7:
	/* 0x25c7: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_25c9:
	/* 0x25c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cb:
	/* 0x25cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25cd:
	/* 0x25cd: js     2647 <generic_lsm_process_event+0x2647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2647;
	}
x86_l_25cf:
	/* 0x25cf: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25d4:
	/* 0x25d4: jmp    2633 <generic_lsm_process_event+0x2633> */
	goto x86_l_2633;
x86_l_25d6:
	/* 0x25d6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25db:
	/* 0x25db: add    rax,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_25e1:
	/* 0x25e1: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25e9:
	/* 0x25e9: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25ee:
	/* 0x25ee: lea    r12d,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25f2:
	/* 0x25f2: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25f9:
	/* 0x25f9: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25fc:
	/* 0x25fc: mov    r13d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 12ULL);
x86_l_2602:
	/* 0x2602: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2607:
	/* 0x2607: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_260d:
	/* 0x260d: mov    ebp,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4095ULL);
x86_l_2612:
	/* 0x2612: cmovb  rbp,rax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_2616:
	/* 0x2616: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_261b:
	/* 0x261b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2621:
	/* 0x2621: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2626:
	/* 0x2626: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2628:
	/* 0x2628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_262a:
	/* 0x262a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_262c:
	/* 0x262c: js     2647 <generic_lsm_process_event+0x2647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2647;
	}
x86_l_262e:
	/* 0x262e: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2633:
	/* 0x2633: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2637:
	/* 0x2637: mov    DWORD PTR [r12+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_263c:
	/* 0x263c: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_263f:
	/* 0x263f: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2642:
	/* 0x2642: jmp    bac <generic_lsm_process_event+0xbac> */
	return 2988ULL;
x86_l_2647:
	/* 0x2647: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_264f:
	/* 0x264f: jmp    bac <generic_lsm_process_event+0xbac> */
	return 2988ULL;
x86_l_2654:
	/* 0x2654: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2657:
	/* 0x2657: je     2805 <generic_lsm_process_event+0x2805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2805;
	}
x86_l_265d:
	/* 0x265d: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2660:
	/* 0x2660: je     26f3 <generic_lsm_process_event+0x26f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26f3;
	}
x86_l_2666:
	/* 0x2666: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_266b:
	/* 0x266b: jne    28b5 <generic_lsm_process_event+0x28b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28b5;
	}
x86_l_2671:
	/* 0x2671: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2677:
	/* 0x2677: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_267b:
	/* 0x267b: jmp    2814 <generic_lsm_process_event+0x2814> */
	goto x86_l_2814;
x86_l_2680:
	/* 0x2680: mov    DWORD PTR [rsp+0xc8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459201ULL);
x86_l_268b:
	/* 0x268b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2690:
	/* 0x2690: mov    rdi,QWORD PTR [rip+0x1ab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2697:
	/* 0x2697: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_269c:
	/* 0x269c: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_26a4:
	/* 0x26a4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26a6:
	/* 0x26a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26a8:
	/* 0x26a8: mov    DWORD PTR [rbx],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_26ae:
	/* 0x26ae: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_26b4:
	/* 0x26b4: jmp    27f1 <generic_lsm_process_event+0x27f1> */
	goto x86_l_27f1;
x86_l_26b9:
	/* 0x26b9: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_26c1:
	/* 0x26c1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26c6:
	/* 0x26c6: mov    rdi,QWORD PTR [rip+0x1ab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_26cd:
	/* 0x26cd: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26d2:
	/* 0x26d2: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_26d7:
	/* 0x26d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26d9:
	/* 0x26d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26db:
	/* 0x26db: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26e0:
	/* 0x26e0: mov    DWORD PTR [rbp+rax*1+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_26e8:
	/* 0x26e8: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_26ee:
	/* 0x26ee: jmp    d19 <generic_lsm_process_event+0xd19> */
	return 3353ULL;
x86_l_26f3:
	/* 0x26f3: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_26f7:
	/* 0x26f7: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_26fe:
	/* 0x26fe: jmp    2810 <generic_lsm_process_event+0x2810> */
	goto x86_l_2810;
x86_l_2703:
	/* 0x2703: lea    rax,[r12+0x5e60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_270b:
	/* 0x270b: jmp    271f <generic_lsm_process_event+0x271f> */
	goto x86_l_271f;
x86_l_270d:
	/* 0x270d: lea    rax,[r12+0x5e68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2715:
	/* 0x2715: jmp    271f <generic_lsm_process_event+0x271f> */
	goto x86_l_271f;
x86_l_2717:
	/* 0x2717: lea    rax,[r12+0x5e50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_271f:
	/* 0x271f: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2722:
	/* 0x2722: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2727:
	/* 0x2727: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_272c:
	/* 0x272c: lea    rdi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2734:
	/* 0x2734: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2739:
	/* 0x2739: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_273e:
	/* 0x273e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2740:
	/* 0x2740: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2748:
	/* 0x2748: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_274e:
	/* 0x274e: test   r15b,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_8, 32ULL);
x86_l_2752:
	/* 0x2752: je     27af <generic_lsm_process_event+0x27af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27af;
	}
x86_l_2754:
	/* 0x2754: cmp    rbp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4096ULL);
x86_l_275b:
	/* 0x275b: jb     278b <generic_lsm_process_event+0x278b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_278b;
	}
x86_l_275d:
	/* 0x275d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2760:
	/* 0x2760: mov    DWORD PTR [rbx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2766:
	/* 0x2766: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_276a:
	/* 0x276a: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_276f:
	/* 0x276f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2772:
	/* 0x2772: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2777:
	/* 0x2777: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_277a:
	/* 0x277a: call   0 <generic_lsm_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 10111ULL);
	__x86_sim_call_depth++;
	return 12605ULL;
x86_l_277f:
	/* 0x277f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2782:
	/* 0x2782: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2786:
	/* 0x2786: jmp    d19 <generic_lsm_process_event+0xd19> */
	return 3353ULL;
x86_l_278b:
	/* 0x278b: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2792:
	/* 0x2792: mov    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2798:
	/* 0x2798: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_279d:
	/* 0x279d: lea    ebx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a0:
	/* 0x27a0: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27a6:
	/* 0x27a6: add    rbx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27a9:
	/* 0x27a9: mov    r13d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 12ULL);
x86_l_27af:
	/* 0x27af: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_27b6:
	/* 0x27b6: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_27bc:
	/* 0x27bc: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_27c0:
	/* 0x27c0: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27c4:
	/* 0x27c4: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_27ca:
	/* 0x27ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27cf:
	/* 0x27cf: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_27d2:
	/* 0x27d2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27d7:
	/* 0x27d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d9:
	/* 0x27d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27db:
	/* 0x27db: js     27eb <generic_lsm_process_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27eb;
	}
x86_l_27dd:
	/* 0x27dd: mov    DWORD PTR [rbx],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27df:
	/* 0x27df: mov    DWORD PTR [rbx+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_27e3:
	/* 0x27e3: add    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27e6:
	/* 0x27e6: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_27e9:
	/* 0x27e9: jmp    27f1 <generic_lsm_process_event+0x27f1> */
	goto x86_l_27f1;
x86_l_27eb:
	/* 0x27eb: mov    DWORD PTR [rbx],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_27f1:
	/* 0x27f1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27f6:
	/* 0x27f6: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27fb:
	/* 0x27fb: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2800:
	/* 0x2800: jmp    b8d <generic_lsm_process_event+0xb8d> */
	return 2957ULL;
x86_l_2805:
	/* 0x2805: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2809:
	/* 0x2809: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2810:
	/* 0x2810: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2814:
	/* 0x2814: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2818:
	/* 0x2818: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_281c:
	/* 0x281c: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2821:
	/* 0x2821: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2825:
	/* 0x2825: ja     2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12066ULL;
	}
x86_l_282b:
	/* 0x282b: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2835:
	/* 0x2835: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2839:
	/* 0x2839: jae    2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12066ULL;
	}
x86_l_283f:
	/* 0x283f: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2843:
	/* 0x2843: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2848:
	/* 0x2848: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_284c:
	/* 0x284c: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_284f:
	/* 0x284f: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2854:
	/* 0x2854: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2859:
	/* 0x2859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285b:
	/* 0x285b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_285e:
	/* 0x285e: js     2cab <generic_lsm_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11435ULL;
	}
x86_l_2864:
	/* 0x2864: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2868:
	/* 0x2868: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_286b:
	/* 0x286b: jg     2887 <generic_lsm_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2887;
	}
x86_l_286d:
	/* 0x286d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_286f:
	/* 0x286f: je     28a4 <generic_lsm_process_event+0x28a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28a4;
	}
x86_l_2871:
	/* 0x2871: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2874:
	/* 0x2874: je     28a4 <generic_lsm_process_event+0x28a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28a4;
	}
x86_l_2876:
	/* 0x2876: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2879:
	/* 0x2879: jne    28cf <generic_lsm_process_event+0x28cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28cf;
	}
x86_l_287b:
	/* 0x287b: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2881:
	/* 0x2881: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2885:
	/* 0x2885: jmp    28d3 <generic_lsm_process_event+0x28d3> */
	goto x86_l_28d3;
x86_l_2887:
	/* 0x2887: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_288a:
	/* 0x288a: je     28be <generic_lsm_process_event+0x28be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28be;
	}
x86_l_288c:
	/* 0x288c: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_288f:
	/* 0x288f: je     28a4 <generic_lsm_process_event+0x28a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28a4;
	}
x86_l_2891:
	/* 0x2891: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2896:
	/* 0x2896: jne    28cf <generic_lsm_process_event+0x28cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28cf;
	}
x86_l_2898:
	/* 0x2898: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_289e:
	/* 0x289e: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_28a2:
	/* 0x28a2: jmp    28d3 <generic_lsm_process_event+0x28d3> */
	goto x86_l_28d3;
x86_l_28a4:
	/* 0x28a4: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_28a8:
	/* 0x28a8: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_28af:
	/* 0x28af: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_28b3:
	/* 0x28b3: jmp    28d3 <generic_lsm_process_event+0x28d3> */
	goto x86_l_28d3;
x86_l_28b5:
	/* 0x28b5: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_28b9:
	/* 0x28b9: jmp    2814 <generic_lsm_process_event+0x2814> */
	goto x86_l_2814;
x86_l_28be:
	/* 0x28be: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_28c2:
	/* 0x28c2: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_28c9:
	/* 0x28c9: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_28cd:
	/* 0x28cd: jmp    28d3 <generic_lsm_process_event+0x28d3> */
	goto x86_l_28d3;
x86_l_28cf:
	/* 0x28cf: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_28d3:
	/* 0x28d3: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28d7:
	/* 0x28d7: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28db:
	/* 0x28db: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_28e0:
	/* 0x28e0: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_28e4:
	/* 0x28e4: ja     2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12066ULL;
	}
x86_l_28ea:
	/* 0x28ea: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_28f4:
	/* 0x28f4: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_28f8:
	/* 0x28f8: jae    2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12066ULL;
	}
x86_l_28fe:
	/* 0x28fe: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2902:
	/* 0x2902: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2907:
	/* 0x2907: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_290b:
	/* 0x290b: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_290e:
	/* 0x290e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2913:
	/* 0x2913: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2918:
	/* 0x2918: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291a:
	/* 0x291a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_291d:
	/* 0x291d: js     2cab <generic_lsm_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11435ULL;
	}
x86_l_2923:
	/* 0x2923: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2927:
	/* 0x2927: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_292a:
	/* 0x292a: jg     2946 <generic_lsm_process_event+0x2946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2946;
	}
x86_l_292c:
	/* 0x292c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_292e:
	/* 0x292e: je     2963 <generic_lsm_process_event+0x2963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2963;
	}
x86_l_2930:
	/* 0x2930: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2933:
	/* 0x2933: je     2963 <generic_lsm_process_event+0x2963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2963;
	}
x86_l_2935:
	/* 0x2935: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2938:
	/* 0x2938: jne    2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2985;
	}
x86_l_293a:
	/* 0x293a: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2940:
	/* 0x2940: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2944:
	/* 0x2944: jmp    2989 <generic_lsm_process_event+0x2989> */
	goto x86_l_2989;
x86_l_2946:
	/* 0x2946: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2949:
	/* 0x2949: je     2974 <generic_lsm_process_event+0x2974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2974;
	}
x86_l_294b:
	/* 0x294b: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_294e:
	/* 0x294e: je     2963 <generic_lsm_process_event+0x2963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2963;
	}
x86_l_2950:
	/* 0x2950: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2955:
	/* 0x2955: jne    2985 <generic_lsm_process_event+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2985;
	}
x86_l_2957:
	/* 0x2957: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_295d:
	/* 0x295d: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2961:
	/* 0x2961: jmp    2989 <generic_lsm_process_event+0x2989> */
	goto x86_l_2989;
x86_l_2963:
	/* 0x2963: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2967:
	/* 0x2967: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_296e:
	/* 0x296e: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2972:
	/* 0x2972: jmp    2989 <generic_lsm_process_event+0x2989> */
	goto x86_l_2989;
x86_l_2974:
	/* 0x2974: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2978:
	/* 0x2978: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_297f:
	/* 0x297f: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2983:
	/* 0x2983: jmp    2989 <generic_lsm_process_event+0x2989> */
	goto x86_l_2989;
x86_l_2985:
	/* 0x2985: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2989:
	/* 0x2989: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_298d:
	/* 0x298d: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2991:
	/* 0x2991: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2996:
	/* 0x2996: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_299a:
	/* 0x299a: ja     2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12066ULL;
	}
x86_l_29a0:
	/* 0x29a0: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_29aa:
	/* 0x29aa: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_29ae:
	/* 0x29ae: jae    2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12066ULL;
	}
x86_l_29b4:
	/* 0x29b4: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_29b8:
	/* 0x29b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29bd:
	/* 0x29bd: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29c1:
	/* 0x29c1: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29c4:
	/* 0x29c4: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29c9:
	/* 0x29c9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29ce:
	/* 0x29ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d0:
	/* 0x29d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 10707ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10707ULL: goto x86_l_29d3;
	case 10713ULL: goto x86_l_29d9;
	case 10717ULL: goto x86_l_29dd;
	case 10720ULL: goto x86_l_29e0;
	case 10722ULL: goto x86_l_29e2;
	case 10724ULL: goto x86_l_29e4;
	case 10726ULL: goto x86_l_29e6;
	case 10729ULL: goto x86_l_29e9;
	case 10731ULL: goto x86_l_29eb;
	case 10734ULL: goto x86_l_29ee;
	case 10736ULL: goto x86_l_29f0;
	case 10742ULL: goto x86_l_29f6;
	case 10746ULL: goto x86_l_29fa;
	case 10748ULL: goto x86_l_29fc;
	case 10751ULL: goto x86_l_29ff;
	case 10753ULL: goto x86_l_2a01;
	case 10756ULL: goto x86_l_2a04;
	case 10758ULL: goto x86_l_2a06;
	case 10763ULL: goto x86_l_2a0b;
	case 10765ULL: goto x86_l_2a0d;
	case 10771ULL: goto x86_l_2a13;
	case 10775ULL: goto x86_l_2a17;
	case 10777ULL: goto x86_l_2a19;
	case 10781ULL: goto x86_l_2a1d;
	case 10788ULL: goto x86_l_2a24;
	case 10792ULL: goto x86_l_2a28;
	case 10794ULL: goto x86_l_2a2a;
	case 10798ULL: goto x86_l_2a2e;
	case 10805ULL: goto x86_l_2a35;
	case 10809ULL: goto x86_l_2a39;
	case 10811ULL: goto x86_l_2a3b;
	case 10815ULL: goto x86_l_2a3f;
	case 10819ULL: goto x86_l_2a43;
	case 10823ULL: goto x86_l_2a47;
	case 10828ULL: goto x86_l_2a4c;
	case 10832ULL: goto x86_l_2a50;
	case 10838ULL: goto x86_l_2a56;
	case 10848ULL: goto x86_l_2a60;
	case 10852ULL: goto x86_l_2a64;
	case 10858ULL: goto x86_l_2a6a;
	case 10862ULL: goto x86_l_2a6e;
	case 10867ULL: goto x86_l_2a73;
	case 10871ULL: goto x86_l_2a77;
	case 10874ULL: goto x86_l_2a7a;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10886ULL: goto x86_l_2a86;
	case 10889ULL: goto x86_l_2a89;
	case 10895ULL: goto x86_l_2a8f;
	case 10899ULL: goto x86_l_2a93;
	case 10902ULL: goto x86_l_2a96;
	case 10904ULL: goto x86_l_2a98;
	case 10906ULL: goto x86_l_2a9a;
	case 10908ULL: goto x86_l_2a9c;
	case 10911ULL: goto x86_l_2a9f;
	case 10913ULL: goto x86_l_2aa1;
	case 10916ULL: goto x86_l_2aa4;
	case 10918ULL: goto x86_l_2aa6;
	case 10924ULL: goto x86_l_2aac;
	case 10928ULL: goto x86_l_2ab0;
	case 10930ULL: goto x86_l_2ab2;
	case 10933ULL: goto x86_l_2ab5;
	case 10935ULL: goto x86_l_2ab7;
	case 10938ULL: goto x86_l_2aba;
	case 10940ULL: goto x86_l_2abc;
	case 10945ULL: goto x86_l_2ac1;
	case 10947ULL: goto x86_l_2ac3;
	case 10953ULL: goto x86_l_2ac9;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10963ULL: goto x86_l_2ad3;
	case 10970ULL: goto x86_l_2ada;
	case 10974ULL: goto x86_l_2ade;
	case 10976ULL: goto x86_l_2ae0;
	case 10980ULL: goto x86_l_2ae4;
	case 10987ULL: goto x86_l_2aeb;
	case 10991ULL: goto x86_l_2aef;
	case 10993ULL: goto x86_l_2af1;
	case 10997ULL: goto x86_l_2af5;
	case 11001ULL: goto x86_l_2af9;
	case 11005ULL: goto x86_l_2afd;
	case 11010ULL: goto x86_l_2b02;
	case 11014ULL: goto x86_l_2b06;
	case 11020ULL: goto x86_l_2b0c;
	case 11030ULL: goto x86_l_2b16;
	case 11034ULL: goto x86_l_2b1a;
	case 11040ULL: goto x86_l_2b20;
	case 11044ULL: goto x86_l_2b24;
	case 11049ULL: goto x86_l_2b29;
	case 11053ULL: goto x86_l_2b2d;
	case 11056ULL: goto x86_l_2b30;
	case 11061ULL: goto x86_l_2b35;
	case 11066ULL: goto x86_l_2b3a;
	case 11068ULL: goto x86_l_2b3c;
	case 11071ULL: goto x86_l_2b3f;
	case 11077ULL: goto x86_l_2b45;
	case 11081ULL: goto x86_l_2b49;
	case 11084ULL: goto x86_l_2b4c;
	case 11086ULL: goto x86_l_2b4e;
	case 11088ULL: goto x86_l_2b50;
	case 11090ULL: goto x86_l_2b52;
	case 11093ULL: goto x86_l_2b55;
	case 11095ULL: goto x86_l_2b57;
	case 11098ULL: goto x86_l_2b5a;
	case 11100ULL: goto x86_l_2b5c;
	case 11106ULL: goto x86_l_2b62;
	case 11110ULL: goto x86_l_2b66;
	case 11112ULL: goto x86_l_2b68;
	case 11115ULL: goto x86_l_2b6b;
	case 11117ULL: goto x86_l_2b6d;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11129ULL: goto x86_l_2b79;
	case 11135ULL: goto x86_l_2b7f;
	case 11139ULL: goto x86_l_2b83;
	case 11141ULL: goto x86_l_2b85;
	case 11145ULL: goto x86_l_2b89;
	case 11152ULL: goto x86_l_2b90;
	case 11156ULL: goto x86_l_2b94;
	case 11158ULL: goto x86_l_2b96;
	case 11162ULL: goto x86_l_2b9a;
	case 11169ULL: goto x86_l_2ba1;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11179ULL: goto x86_l_2bab;
	case 11183ULL: goto x86_l_2baf;
	case 11187ULL: goto x86_l_2bb3;
	case 11192ULL: goto x86_l_2bb8;
	case 11196ULL: goto x86_l_2bbc;
	case 11202ULL: goto x86_l_2bc2;
	case 11212ULL: goto x86_l_2bcc;
	case 11216ULL: goto x86_l_2bd0;
	case 11222ULL: goto x86_l_2bd6;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11235ULL: goto x86_l_2be3;
	case 11238ULL: goto x86_l_2be6;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11250ULL: goto x86_l_2bf2;
	case 11253ULL: goto x86_l_2bf5;
	case 11259ULL: goto x86_l_2bfb;
	case 11263ULL: goto x86_l_2bff;
	case 11266ULL: goto x86_l_2c02;
	case 11268ULL: goto x86_l_2c04;
	case 11270ULL: goto x86_l_2c06;
	case 11272ULL: goto x86_l_2c08;
	case 11275ULL: goto x86_l_2c0b;
	case 11277ULL: goto x86_l_2c0d;
	case 11280ULL: goto x86_l_2c10;
	case 11282ULL: goto x86_l_2c12;
	case 11288ULL: goto x86_l_2c18;
	case 11292ULL: goto x86_l_2c1c;
	case 11294ULL: goto x86_l_2c1e;
	case 11297ULL: goto x86_l_2c21;
	case 11299ULL: goto x86_l_2c23;
	case 11302ULL: goto x86_l_2c26;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11311ULL: goto x86_l_2c2f;
	case 11317ULL: goto x86_l_2c35;
	case 11321ULL: goto x86_l_2c39;
	case 11323ULL: goto x86_l_2c3b;
	case 11327ULL: goto x86_l_2c3f;
	case 11334ULL: goto x86_l_2c46;
	case 11338ULL: goto x86_l_2c4a;
	case 11340ULL: goto x86_l_2c4c;
	case 11344ULL: goto x86_l_2c50;
	case 11351ULL: goto x86_l_2c57;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11361ULL: goto x86_l_2c61;
	case 11365ULL: goto x86_l_2c65;
	case 11369ULL: goto x86_l_2c69;
	case 11374ULL: goto x86_l_2c6e;
	case 11378ULL: goto x86_l_2c72;
	case 11384ULL: goto x86_l_2c78;
	case 11394ULL: goto x86_l_2c82;
	case 11398ULL: goto x86_l_2c86;
	case 11404ULL: goto x86_l_2c8c;
	case 11408ULL: goto x86_l_2c90;
	case 11413ULL: goto x86_l_2c95;
	case 11417ULL: goto x86_l_2c99;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11430ULL: goto x86_l_2ca6;
	case 11433ULL: goto x86_l_2ca9;
	case 11435ULL: goto x86_l_2cab;
	case 11438ULL: goto x86_l_2cae;
	case 11446ULL: goto x86_l_2cb6;
	case 11450ULL: goto x86_l_2cba;
	case 11455ULL: goto x86_l_2cbf;
	case 11459ULL: goto x86_l_2cc3;
	case 11465ULL: goto x86_l_2cc9;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11484ULL: goto x86_l_2cdc;
	case 11488ULL: goto x86_l_2ce0;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11502ULL: goto x86_l_2cee;
	case 11505ULL: goto x86_l_2cf1;
	case 11507ULL: goto x86_l_2cf3;
	case 11511ULL: goto x86_l_2cf7;
	case 11513ULL: goto x86_l_2cf9;
	case 11517ULL: goto x86_l_2cfd;
	case 11520ULL: goto x86_l_2d00;
	case 11522ULL: goto x86_l_2d02;
	case 11527ULL: goto x86_l_2d07;
	case 11536ULL: goto x86_l_2d10;
	case 11540ULL: goto x86_l_2d14;
	case 11545ULL: goto x86_l_2d19;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11559ULL: goto x86_l_2d27;
	case 11561ULL: goto x86_l_2d29;
	case 11565ULL: goto x86_l_2d2d;
	case 11569ULL: goto x86_l_2d31;
	case 11573ULL: goto x86_l_2d35;
	case 11578ULL: goto x86_l_2d3a;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11594ULL: goto x86_l_2d4a;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11619ULL: goto x86_l_2d63;
	case 11623ULL: goto x86_l_2d67;
	case 11627ULL: goto x86_l_2d6b;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11643ULL: goto x86_l_2d7b;
	case 11645ULL: goto x86_l_2d7d;
	case 11650ULL: goto x86_l_2d82;
	case 11657ULL: goto x86_l_2d89;
	case 11662ULL: goto x86_l_2d8e;
	case 11666ULL: goto x86_l_2d92;
	case 11670ULL: goto x86_l_2d96;
	case 11676ULL: goto x86_l_2d9c;
	case 11682ULL: goto x86_l_2da2;
	case 11689ULL: goto x86_l_2da9;
	case 11694ULL: goto x86_l_2dae;
	case 11702ULL: goto x86_l_2db6;
	case 11707ULL: goto x86_l_2dbb;
	case 11710ULL: goto x86_l_2dbe;
	case 11712ULL: goto x86_l_2dc0;
	case 11721ULL: goto x86_l_2dc9;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11736ULL: goto x86_l_2dd8;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11750ULL: goto x86_l_2de6;
	case 11752ULL: goto x86_l_2de8;
	case 11760ULL: goto x86_l_2df0;
	case 11765ULL: goto x86_l_2df5;
	case 11769ULL: goto x86_l_2df9;
	case 11774ULL: goto x86_l_2dfe;
	case 11779ULL: goto x86_l_2e03;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11791ULL: goto x86_l_2e0f;
	case 11795ULL: goto x86_l_2e13;
	case 11799ULL: goto x86_l_2e17;
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11834ULL: goto x86_l_2e3a;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11849ULL: goto x86_l_2e49;
	case 11852ULL: goto x86_l_2e4c;
	case 11854ULL: goto x86_l_2e4e;
	case 11861ULL: goto x86_l_2e55;
	case 11865ULL: goto x86_l_2e59;
	case 11868ULL: goto x86_l_2e5c;
	case 11870ULL: goto x86_l_2e5e;
	case 11881ULL: goto x86_l_2e69;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11899ULL: goto x86_l_2e7b;
	case 11901ULL: goto x86_l_2e7d;
	case 11905ULL: goto x86_l_2e81;
	case 11909ULL: goto x86_l_2e85;
	case 11911ULL: goto x86_l_2e87;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11931ULL: goto x86_l_2e9b;
	case 11936ULL: goto x86_l_2ea0;
	case 11938ULL: goto x86_l_2ea2;
	case 11941ULL: goto x86_l_2ea5;
	case 11943ULL: goto x86_l_2ea7;
	case 11949ULL: goto x86_l_2ead;
	case 11954ULL: goto x86_l_2eb2;
	case 11961ULL: goto x86_l_2eb9;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11971ULL: goto x86_l_2ec3;
	case 11974ULL: goto x86_l_2ec6;
	case 11977ULL: goto x86_l_2ec9;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11987ULL: goto x86_l_2ed3;
	case 11994ULL: goto x86_l_2eda;
	case 11999ULL: goto x86_l_2edf;
	case 12006ULL: goto x86_l_2ee6;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12016ULL: goto x86_l_2ef0;
	case 12027ULL: goto x86_l_2efb;
	case 12032ULL: goto x86_l_2f00;
	case 12039ULL: goto x86_l_2f07;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12049ULL: goto x86_l_2f11;
	case 12051ULL: goto x86_l_2f13;
	case 12058ULL: goto x86_l_2f1a;
	case 12060ULL: goto x86_l_2f1c;
	case 12061ULL: goto x86_l_2f1d;
	case 12066ULL: goto x86_l_2f22;
	case 12074ULL: goto x86_l_2f2a;
	case 12079ULL: goto x86_l_2f2f;
	case 12084ULL: goto x86_l_2f34;
	case 12087ULL: goto x86_l_2f37;
	case 12089ULL: goto x86_l_2f39;
	case 12091ULL: goto x86_l_2f3b;
	case 12092ULL: goto x86_l_2f3c;
	case 12093ULL: goto x86_l_2f3d;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12104ULL: goto x86_l_2f48;
	case 12106ULL: goto x86_l_2f4a;
	case 12110ULL: goto x86_l_2f4e;
	case 12114ULL: goto x86_l_2f52;
	case 12117ULL: goto x86_l_2f55;
	case 12119ULL: goto x86_l_2f57;
	case 12125ULL: goto x86_l_2f5d;
	case 12127ULL: goto x86_l_2f5f;
	case 12129ULL: goto x86_l_2f61;
	case 12133ULL: goto x86_l_2f65;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12150ULL: goto x86_l_2f76;
	case 12154ULL: goto x86_l_2f7a;
	case 12157ULL: goto x86_l_2f7d;
	case 12162ULL: goto x86_l_2f82;
	case 12164ULL: goto x86_l_2f84;
	case 12166ULL: goto x86_l_2f86;
	case 12171ULL: goto x86_l_2f8b;
	case 12173ULL: goto x86_l_2f8d;
	case 12175ULL: goto x86_l_2f8f;
	case 12179ULL: goto x86_l_2f93;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12190ULL: goto x86_l_2f9e;
	case 12191ULL: goto x86_l_2f9f;
	case 12193ULL: goto x86_l_2fa1;
	case 12194ULL: goto x86_l_2fa2;
	case 12196ULL: goto x86_l_2fa4;
	case 12198ULL: goto x86_l_2fa6;
	case 12200ULL: goto x86_l_2fa8;
	case 12201ULL: goto x86_l_2fa9;
	case 12205ULL: goto x86_l_2fad;
	case 12208ULL: goto x86_l_2fb0;
	case 12212ULL: goto x86_l_2fb4;
	case 12216ULL: goto x86_l_2fb8;
	case 12220ULL: goto x86_l_2fbc;
	case 12223ULL: goto x86_l_2fbf;
	case 12225ULL: goto x86_l_2fc1;
	case 12229ULL: goto x86_l_2fc5;
	case 12235ULL: goto x86_l_2fcb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29d3:
	/* 0x29d3: js     2cab <generic_lsm_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2cab;
	}
x86_l_29d9:
	/* 0x29d9: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_29dd:
	/* 0x29dd: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_29e0:
	/* 0x29e0: jg     29fc <generic_lsm_process_event+0x29fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_29fc;
	}
x86_l_29e2:
	/* 0x29e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29e4:
	/* 0x29e4: je     2a19 <generic_lsm_process_event+0x2a19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a19;
	}
x86_l_29e6:
	/* 0x29e6: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_29e9:
	/* 0x29e9: je     2a19 <generic_lsm_process_event+0x2a19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a19;
	}
x86_l_29eb:
	/* 0x29eb: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_29ee:
	/* 0x29ee: jne    2a3b <generic_lsm_process_event+0x2a3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a3b;
	}
x86_l_29f0:
	/* 0x29f0: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_29f6:
	/* 0x29f6: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_29fa:
	/* 0x29fa: jmp    2a3f <generic_lsm_process_event+0x2a3f> */
	goto x86_l_2a3f;
x86_l_29fc:
	/* 0x29fc: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_29ff:
	/* 0x29ff: je     2a2a <generic_lsm_process_event+0x2a2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2a;
	}
x86_l_2a01:
	/* 0x2a01: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2a04:
	/* 0x2a04: je     2a19 <generic_lsm_process_event+0x2a19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a19;
	}
x86_l_2a06:
	/* 0x2a06: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2a0b:
	/* 0x2a0b: jne    2a3b <generic_lsm_process_event+0x2a3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a3b;
	}
x86_l_2a0d:
	/* 0x2a0d: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2a13:
	/* 0x2a13: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2a17:
	/* 0x2a17: jmp    2a3f <generic_lsm_process_event+0x2a3f> */
	goto x86_l_2a3f;
x86_l_2a19:
	/* 0x2a19: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2a1d:
	/* 0x2a1d: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2a24:
	/* 0x2a24: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2a28:
	/* 0x2a28: jmp    2a3f <generic_lsm_process_event+0x2a3f> */
	goto x86_l_2a3f;
x86_l_2a2a:
	/* 0x2a2a: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2a2e:
	/* 0x2a2e: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2a35:
	/* 0x2a35: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2a39:
	/* 0x2a39: jmp    2a3f <generic_lsm_process_event+0x2a3f> */
	goto x86_l_2a3f;
x86_l_2a3b:
	/* 0x2a3b: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2a3f:
	/* 0x2a3f: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a43:
	/* 0x2a43: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a47:
	/* 0x2a47: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2a4c:
	/* 0x2a4c: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2a50:
	/* 0x2a50: ja     2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f22;
	}
x86_l_2a56:
	/* 0x2a56: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2a60:
	/* 0x2a60: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2a64:
	/* 0x2a64: jae    2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f22;
	}
x86_l_2a6a:
	/* 0x2a6a: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2a6e:
	/* 0x2a6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a73:
	/* 0x2a73: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a77:
	/* 0x2a77: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a7a:
	/* 0x2a7a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a7f:
	/* 0x2a7f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2a84:
	/* 0x2a84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a86:
	/* 0x2a86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a89:
	/* 0x2a89: js     2cab <generic_lsm_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2cab;
	}
x86_l_2a8f:
	/* 0x2a8f: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2a93:
	/* 0x2a93: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2a96:
	/* 0x2a96: jg     2ab2 <generic_lsm_process_event+0x2ab2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ab2;
	}
x86_l_2a98:
	/* 0x2a98: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a9a:
	/* 0x2a9a: je     2acf <generic_lsm_process_event+0x2acf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2acf;
	}
x86_l_2a9c:
	/* 0x2a9c: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2a9f:
	/* 0x2a9f: je     2acf <generic_lsm_process_event+0x2acf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2acf;
	}
x86_l_2aa1:
	/* 0x2aa1: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2aa4:
	/* 0x2aa4: jne    2af1 <generic_lsm_process_event+0x2af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2af1;
	}
x86_l_2aa6:
	/* 0x2aa6: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2aac:
	/* 0x2aac: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2ab0:
	/* 0x2ab0: jmp    2af5 <generic_lsm_process_event+0x2af5> */
	goto x86_l_2af5;
x86_l_2ab2:
	/* 0x2ab2: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2ab5:
	/* 0x2ab5: je     2ae0 <generic_lsm_process_event+0x2ae0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae0;
	}
x86_l_2ab7:
	/* 0x2ab7: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2aba:
	/* 0x2aba: je     2acf <generic_lsm_process_event+0x2acf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2acf;
	}
x86_l_2abc:
	/* 0x2abc: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2ac1:
	/* 0x2ac1: jne    2af1 <generic_lsm_process_event+0x2af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2af1;
	}
x86_l_2ac3:
	/* 0x2ac3: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2ac9:
	/* 0x2ac9: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2acd:
	/* 0x2acd: jmp    2af5 <generic_lsm_process_event+0x2af5> */
	goto x86_l_2af5;
x86_l_2acf:
	/* 0x2acf: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ad3:
	/* 0x2ad3: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2ada:
	/* 0x2ada: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ade:
	/* 0x2ade: jmp    2af5 <generic_lsm_process_event+0x2af5> */
	goto x86_l_2af5;
x86_l_2ae0:
	/* 0x2ae0: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ae4:
	/* 0x2ae4: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2aef:
	/* 0x2aef: jmp    2af5 <generic_lsm_process_event+0x2af5> */
	goto x86_l_2af5;
x86_l_2af1:
	/* 0x2af1: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2af5:
	/* 0x2af5: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2af9:
	/* 0x2af9: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2afd:
	/* 0x2afd: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2b02:
	/* 0x2b02: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2b06:
	/* 0x2b06: ja     2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f22;
	}
x86_l_2b0c:
	/* 0x2b0c: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2b16:
	/* 0x2b16: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2b1a:
	/* 0x2b1a: jae    2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f22;
	}
x86_l_2b20:
	/* 0x2b20: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2b24:
	/* 0x2b24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b29:
	/* 0x2b29: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b2d:
	/* 0x2b2d: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b30:
	/* 0x2b30: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b35:
	/* 0x2b35: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2b3a:
	/* 0x2b3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3c:
	/* 0x2b3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b3f:
	/* 0x2b3f: js     2cab <generic_lsm_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2cab;
	}
x86_l_2b45:
	/* 0x2b45: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2b49:
	/* 0x2b49: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2b4c:
	/* 0x2b4c: jg     2b68 <generic_lsm_process_event+0x2b68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b68;
	}
x86_l_2b4e:
	/* 0x2b4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b50:
	/* 0x2b50: je     2b85 <generic_lsm_process_event+0x2b85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b85;
	}
x86_l_2b52:
	/* 0x2b52: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2b55:
	/* 0x2b55: je     2b85 <generic_lsm_process_event+0x2b85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b85;
	}
x86_l_2b57:
	/* 0x2b57: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2b5a:
	/* 0x2b5a: jne    2ba7 <generic_lsm_process_event+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba7;
	}
x86_l_2b5c:
	/* 0x2b5c: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2b62:
	/* 0x2b62: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2b66:
	/* 0x2b66: jmp    2bab <generic_lsm_process_event+0x2bab> */
	goto x86_l_2bab;
x86_l_2b68:
	/* 0x2b68: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2b6b:
	/* 0x2b6b: je     2b96 <generic_lsm_process_event+0x2b96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b96;
	}
x86_l_2b6d:
	/* 0x2b6d: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2b70:
	/* 0x2b70: je     2b85 <generic_lsm_process_event+0x2b85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b85;
	}
x86_l_2b72:
	/* 0x2b72: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2b77:
	/* 0x2b77: jne    2ba7 <generic_lsm_process_event+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba7;
	}
x86_l_2b79:
	/* 0x2b79: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2b7f:
	/* 0x2b7f: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2b83:
	/* 0x2b83: jmp    2bab <generic_lsm_process_event+0x2bab> */
	goto x86_l_2bab;
x86_l_2b85:
	/* 0x2b85: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b89:
	/* 0x2b89: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2b90:
	/* 0x2b90: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2b94:
	/* 0x2b94: jmp    2bab <generic_lsm_process_event+0x2bab> */
	goto x86_l_2bab;
x86_l_2b96:
	/* 0x2b96: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b9a:
	/* 0x2b9a: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2ba1:
	/* 0x2ba1: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ba5:
	/* 0x2ba5: jmp    2bab <generic_lsm_process_event+0x2bab> */
	goto x86_l_2bab;
x86_l_2ba7:
	/* 0x2ba7: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2bab:
	/* 0x2bab: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2baf:
	/* 0x2baf: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bb3:
	/* 0x2bb3: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2bb8:
	/* 0x2bb8: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2bbc:
	/* 0x2bbc: ja     2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f22;
	}
x86_l_2bc2:
	/* 0x2bc2: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2bcc:
	/* 0x2bcc: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2bd0:
	/* 0x2bd0: jae    2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f22;
	}
x86_l_2bd6:
	/* 0x2bd6: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2bda:
	/* 0x2bda: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bdf:
	/* 0x2bdf: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2be3:
	/* 0x2be3: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2be6:
	/* 0x2be6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2beb:
	/* 0x2beb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2bf0:
	/* 0x2bf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf2:
	/* 0x2bf2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bf5:
	/* 0x2bf5: js     2cab <generic_lsm_process_event+0x2cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2cab;
	}
x86_l_2bfb:
	/* 0x2bfb: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2bff:
	/* 0x2bff: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2c02:
	/* 0x2c02: jg     2c1e <generic_lsm_process_event+0x2c1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c1e;
	}
x86_l_2c04:
	/* 0x2c04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c06:
	/* 0x2c06: je     2c3b <generic_lsm_process_event+0x2c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c3b;
	}
x86_l_2c08:
	/* 0x2c08: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2c0b:
	/* 0x2c0b: je     2c3b <generic_lsm_process_event+0x2c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c3b;
	}
x86_l_2c0d:
	/* 0x2c0d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2c10:
	/* 0x2c10: jne    2c5d <generic_lsm_process_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c5d;
	}
x86_l_2c12:
	/* 0x2c12: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2c18:
	/* 0x2c18: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2c1c:
	/* 0x2c1c: jmp    2c61 <generic_lsm_process_event+0x2c61> */
	goto x86_l_2c61;
x86_l_2c1e:
	/* 0x2c1e: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2c21:
	/* 0x2c21: je     2c4c <generic_lsm_process_event+0x2c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c4c;
	}
x86_l_2c23:
	/* 0x2c23: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2c26:
	/* 0x2c26: je     2c3b <generic_lsm_process_event+0x2c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c3b;
	}
x86_l_2c28:
	/* 0x2c28: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2c2d:
	/* 0x2c2d: jne    2c5d <generic_lsm_process_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c5d;
	}
x86_l_2c2f:
	/* 0x2c2f: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2c35:
	/* 0x2c35: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2c39:
	/* 0x2c39: jmp    2c61 <generic_lsm_process_event+0x2c61> */
	goto x86_l_2c61;
x86_l_2c3b:
	/* 0x2c3b: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c3f:
	/* 0x2c3f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2c46:
	/* 0x2c46: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c4a:
	/* 0x2c4a: jmp    2c61 <generic_lsm_process_event+0x2c61> */
	goto x86_l_2c61;
x86_l_2c4c:
	/* 0x2c4c: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c50:
	/* 0x2c50: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2c57:
	/* 0x2c57: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c5b:
	/* 0x2c5b: jmp    2c61 <generic_lsm_process_event+0x2c61> */
	goto x86_l_2c61;
x86_l_2c5d:
	/* 0x2c5d: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2c61:
	/* 0x2c61: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c65:
	/* 0x2c65: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c69:
	/* 0x2c69: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2c6e:
	/* 0x2c6e: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2c72:
	/* 0x2c72: ja     2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f22;
	}
x86_l_2c78:
	/* 0x2c78: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2c82:
	/* 0x2c82: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2c86:
	/* 0x2c86: jae    2f22 <generic_lsm_process_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f22;
	}
x86_l_2c8c:
	/* 0x2c8c: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2c90:
	/* 0x2c90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c95:
	/* 0x2c95: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c99:
	/* 0x2c99: add    rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c9c:
	/* 0x2c9c: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca1:
	/* 0x2ca1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2ca6:
	/* 0x2ca6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2ca9:
	/* 0x2ca9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cab:
	/* 0x2cab: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cae:
	/* 0x2cae: mov    BYTE PTR [rsp+0xc4],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_2cb6:
	/* 0x2cb6: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cba:
	/* 0x2cba: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cbf:
	/* 0x2cbf: mov    WORD PTR [rbx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    WORD PTR [rbx+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_2cc9:
	/* 0x2cc9: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cd2:
	/* 0x2cd2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2cd5:
	/* 0x2cd5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2cda:
	/* 0x2cda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdc:
	/* 0x2cdc: lea    rdi,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce0:
	/* 0x2ce0: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2ce4:
	/* 0x2ce4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ce9:
	/* 0x2ce9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2cee:
	/* 0x2cee: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2cf1:
	/* 0x2cf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf3:
	/* 0x2cf3: cmp    r15b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 17ULL);
x86_l_2cf7:
	/* 0x2cf7: je     2d3c <generic_lsm_process_event+0x2d3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d3c;
	}
x86_l_2cf9:
	/* 0x2cf9: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cfd:
	/* 0x2cfd: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2d00:
	/* 0x2d00: jne    2d7d <generic_lsm_process_event+0x2d7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d7d;
	}
x86_l_2d02:
	/* 0x2d02: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2d07:
	/* 0x2d07: movzx  r15d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_2d10:
	/* 0x2d10: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2d14:
	/* 0x2d14: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d19:
	/* 0x2d19: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d1d:
	/* 0x2d1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d22:
	/* 0x2d22: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d27:
	/* 0x2d27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d29:
	/* 0x2d29: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2d2d:
	/* 0x2d2d: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2d31:
	/* 0x2d31: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2d35:
	/* 0x2d35: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d3a:
	/* 0x2d3a: jmp    2d74 <generic_lsm_process_event+0x2d74> */
	goto x86_l_2d74;
x86_l_2d3c:
	/* 0x2d3c: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2d41:
	/* 0x2d41: movzx  r15d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_2d4a:
	/* 0x2d4a: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2d4e:
	/* 0x2d4e: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d53:
	/* 0x2d53: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d57:
	/* 0x2d57: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d61:
	/* 0x2d61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d63:
	/* 0x2d63: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2d67:
	/* 0x2d67: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2d6b:
	/* 0x2d6b: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d74:
	/* 0x2d74: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d79:
	/* 0x2d79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7b:
	/* 0x2d7b: jmp    2d89 <generic_lsm_process_event+0x2d89> */
	goto x86_l_2d89;
x86_l_2d7d:
	/* 0x2d7d: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d82:
	/* 0x2d82: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2d89:
	/* 0x2d89: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d8e:
	/* 0x2d8e: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2d92:
	/* 0x2d92: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2d96:
	/* 0x2d96: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2d9c:
	/* 0x2d9c: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2da2:
	/* 0x2da2: add    r12,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2da9:
	/* 0x2da9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dae:
	/* 0x2dae: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2db6:
	/* 0x2db6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dbb:
	/* 0x2dbb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2dbe:
	/* 0x2dbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc0:
	/* 0x2dc0: cmp    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_2dc9:
	/* 0x2dc9: je     2e2a <generic_lsm_process_event+0x2e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e2a;
	}
x86_l_2dcb:
	/* 0x2dcb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dd0:
	/* 0x2dd0: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2dd8:
	/* 0x2dd8: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2ddc:
	/* 0x2ddc: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2de1:
	/* 0x2de1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2de6:
	/* 0x2de6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de8:
	/* 0x2de8: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2df0:
	/* 0x2df0: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2df5:
	/* 0x2df5: lea    rdx,[rbx+r15*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_2df9:
	/* 0x2df9: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dfe:
	/* 0x2dfe: lea    rdi,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e03:
	/* 0x2e03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e08:
	/* 0x2e08: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e0d:
	/* 0x2e0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e0f:
	/* 0x2e0f: add    r12,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_2e13:
	/* 0x2e13: lea    rdx,[rbx+r15*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_2e17:
	/* 0x2e17: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2e1b:
	/* 0x2e1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e20:
	/* 0x2e20: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2e23:
	/* 0x2e23: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e28:
	/* 0x2e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2a:
	/* 0x2e2a: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_2e30:
	/* 0x2e30: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e35:
	/* 0x2e35: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e3a:
	/* 0x2e3a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e3f:
	/* 0x2e3f: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e44:
	/* 0x2e44: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e49:
	/* 0x2e49: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_2e4c:
	/* 0x2e4c: js     2e5e <generic_lsm_process_event+0x2e5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e5e;
	}
x86_l_2e4e:
	/* 0x2e4e: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2e55:
	/* 0x2e55: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e59:
	/* 0x2e59: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_2e5c:
	/* 0x2e5c: jmp    2e79 <generic_lsm_process_event+0x2e79> */
	goto x86_l_2e79;
x86_l_2e5e:
	/* 0x2e5e: mov    DWORD PTR [rcx+rdx*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104045582745599ULL);
x86_l_2e69:
	/* 0x2e69: mov    DWORD PTR [rcx+rbp*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 622770257919ULL);
x86_l_2e74:
	/* 0x2e74: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2e79:
	/* 0x2e79: add    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e7b:
	/* 0x2e7b: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_2e7d:
	/* 0x2e7d: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e81:
	/* 0x2e81: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2e85:
	/* 0x2e85: jg     2ef0 <generic_lsm_process_event+0x2ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ef0;
	}
x86_l_2e87:
	/* 0x2e87: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2e8f:
	/* 0x2e8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e94:
	/* 0x2e94: mov    rdi,QWORD PTR [rip+0x1ab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2e9b:
	/* 0x2e9b: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2ea0:
	/* 0x2ea0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea2:
	/* 0x2ea2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ea5:
	/* 0x2ea5: je     2ef0 <generic_lsm_process_event+0x2ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ef0;
	}
x86_l_2ea7:
	/* 0x2ea7: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_2ead:
	/* 0x2ead: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2eb2:
	/* 0x2eb2: mov    rdi,QWORD PTR [rip+0x1ab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_2eb9:
	/* 0x2eb9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2ebc:
	/* 0x2ebc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2ebe:
	/* 0x2ebe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ec1:
	/* 0x2ec1: je     2ef0 <generic_lsm_process_event+0x2ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ef0;
	}
x86_l_2ec3:
	/* 0x2ec3: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ec6:
	/* 0x2ec6: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2ec9:
	/* 0x2ec9: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2ecc:
	/* 0x2ecc: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_2ed1:
	/* 0x2ed1: je     2ef0 <generic_lsm_process_event+0x2ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ef0;
	}
x86_l_2ed3:
	/* 0x2ed3: mov    DWORD PTR [r14+0x5efc],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_2eda:
	/* 0x2eda: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2edf:
	/* 0x2edf: mov    rsi,QWORD PTR [rip+0x1ab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_2ee6:
	/* 0x2ee6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ee9:
	/* 0x2ee9: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2eee:
	/* 0x2eee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef0:
	/* 0x2ef0: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_2efb:
	/* 0x2efb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2f00:
	/* 0x2f00: mov    rsi,QWORD PTR [rip+0x1ab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_2f07:
	/* 0x2f07: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2f0a:
	/* 0x2f0a: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2f0f:
	/* 0x2f0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f11:
	/* 0x2f11: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f13:
	/* 0x2f13: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_2f1a:
	/* 0x2f1a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2f1c:
	/* 0x2f1c: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2f1d:
	/* 0x2f1d: jmp    3529 <__do_bytes+0xb9> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2f22:
	/* 0x2f22: mov    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2f2a:
	/* 0x2f2a: jmp    2cae <generic_lsm_process_event+0x2cae> */
	goto x86_l_2cae;
x86_l_2f2f:
	/* 0x2f2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f34:
	/* 0x2f34: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_2f37:
	/* 0x2f37: ja     2fa1 <extract_arg_depth+0x72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fa1;
	}
x86_l_2f39:
	/* 0x2f39: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2f3b:
	/* 0x2f3b: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2f3c:
	/* 0x2f3c: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_2f3d:
	/* 0x2f3d: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f40:
	/* 0x2f40: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2f42:
	/* 0x2f42: cmp    WORD PTR [rcx+rdx*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 3), 25769803776ULL);
x86_l_2f48:
	/* 0x2f48: je     2f9a <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9a;
	}
x86_l_2f4a:
	/* 0x2f4a: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    r8d,DWORD PTR [rcx+rdx*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_2f52:
	/* 0x2f52: add    QWORD PTR [rax],r8 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R8, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f55:
	/* 0x2f55: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f57:
	/* 0x2f57: cmp    WORD PTR [rcx+rdx*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 3), 17179869184ULL);
x86_l_2f5d:
	/* 0x2f5d: je     2f9a <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9a;
	}
x86_l_2f5f:
	/* 0x2f5f: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_2f61:
	/* 0x2f61: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f65:
	/* 0x2f65: je     2f6e <extract_arg_depth+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f6e;
	}
x86_l_2f67:
	/* 0x2f67: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f6c:
	/* 0x2f6c: jmp    2f73 <extract_arg_depth+0x44> */
	goto x86_l_2f73;
x86_l_2f6e:
	/* 0x2f6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f73:
	/* 0x2f73: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_2f76:
	/* 0x2f76: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f7d:
	/* 0x2f7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f82:
	/* 0x2f82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f84:
	/* 0x2f84: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f86:
	/* 0x2f86: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2f8b:
	/* 0x2f8b: jns    2f9a <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2f9a;
	}
x86_l_2f8d:
	/* 0x2f8d: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f8f:
	/* 0x2f8f: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f93:
	/* 0x2f93: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f95:
	/* 0x2f95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f9a:
	/* 0x2f9a: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f9e:
	/* 0x2f9e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2f9f:
	/* 0x2f9f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2fa1:
	/* 0x2fa1: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2fa2:
	/* 0x2fa2: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2fa4:
	/* 0x2fa4: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2fa6:
	/* 0x2fa6: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2fa8:
	/* 0x2fa8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2fa9:
	/* 0x2fa9: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_2fad:
	/* 0x2fad: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2fb0:
	/* 0x2fb0: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fb4:
	/* 0x2fb4: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fb8:
	/* 0x2fb8: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fbc:
	/* 0x2fbc: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2fbf:
	/* 0x2fbf: jne    2fcb <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fcb;
	}
x86_l_2fc1:
	/* 0x2fc1: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2fc5:
	/* 0x2fc5: je     310c <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12556ULL;
	}
x86_l_2fcb:
	/* 0x2fcb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 12240ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12240ULL: goto x86_l_2fd0;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12252ULL: goto x86_l_2fdc;
	case 12257ULL: goto x86_l_2fe1;
	case 12263ULL: goto x86_l_2fe7;
	case 12267ULL: goto x86_l_2feb;
	case 12272ULL: goto x86_l_2ff0;
	case 12277ULL: goto x86_l_2ff5;
	case 12282ULL: goto x86_l_2ffa;
	case 12285ULL: goto x86_l_2ffd;
	case 12287ULL: goto x86_l_2fff;
	case 12292ULL: goto x86_l_3004;
	case 12298ULL: goto x86_l_300a;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12316ULL: goto x86_l_301c;
	case 12318ULL: goto x86_l_301e;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12340ULL: goto x86_l_3034;
	case 12342ULL: goto x86_l_3036;
	case 12346ULL: goto x86_l_303a;
	case 12350ULL: goto x86_l_303e;
	case 12354ULL: goto x86_l_3042;
	case 12357ULL: goto x86_l_3045;
	case 12360ULL: goto x86_l_3048;
	case 12362ULL: goto x86_l_304a;
	case 12364ULL: goto x86_l_304c;
	case 12366ULL: goto x86_l_304e;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12377ULL: goto x86_l_3059;
	case 12379ULL: goto x86_l_305b;
	case 12383ULL: goto x86_l_305f;
	case 12386ULL: goto x86_l_3062;
	case 12390ULL: goto x86_l_3066;
	case 12393ULL: goto x86_l_3069;
	case 12395ULL: goto x86_l_306b;
	case 12398ULL: goto x86_l_306e;
	case 12401ULL: goto x86_l_3071;
	case 12406ULL: goto x86_l_3076;
	case 12409ULL: goto x86_l_3079;
	case 12415ULL: goto x86_l_307f;
	case 12422ULL: goto x86_l_3086;
	case 12428ULL: goto x86_l_308c;
	case 12430ULL: goto x86_l_308e;
	case 12436ULL: goto x86_l_3094;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12449ULL: goto x86_l_30a1;
	case 12453ULL: goto x86_l_30a5;
	case 12456ULL: goto x86_l_30a8;
	case 12461ULL: goto x86_l_30ad;
	case 12463ULL: goto x86_l_30af;
	case 12467ULL: goto x86_l_30b3;
	case 12472ULL: goto x86_l_30b8;
	case 12476ULL: goto x86_l_30bc;
	case 12478ULL: goto x86_l_30be;
	case 12480ULL: goto x86_l_30c0;
	case 12484ULL: goto x86_l_30c4;
	case 12489ULL: goto x86_l_30c9;
	case 12494ULL: goto x86_l_30ce;
	case 12499ULL: goto x86_l_30d3;
	case 12501ULL: goto x86_l_30d5;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12512ULL: goto x86_l_30e0;
	case 12516ULL: goto x86_l_30e4;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12530ULL: goto x86_l_30f2;
	case 12533ULL: goto x86_l_30f5;
	case 12535ULL: goto x86_l_30f7;
	case 12540ULL: goto x86_l_30fc;
	case 12544ULL: goto x86_l_3100;
	case 12548ULL: goto x86_l_3104;
	case 12552ULL: goto x86_l_3108;
	case 12554ULL: goto x86_l_310a;
	case 12556ULL: goto x86_l_310c;
	case 12560ULL: goto x86_l_3110;
	case 12565ULL: goto x86_l_3115;
	case 12569ULL: goto x86_l_3119;
	case 12570ULL: goto x86_l_311a;
	case 12572ULL: goto x86_l_311c;
	case 12574ULL: goto x86_l_311e;
	case 12576ULL: goto x86_l_3120;
	case 12577ULL: goto x86_l_3121;
	case 12581ULL: goto x86_l_3125;
	case 12584ULL: goto x86_l_3128;
	case 12589ULL: goto x86_l_312d;
	case 12592ULL: goto x86_l_3130;
	case 12594ULL: goto x86_l_3132;
	case 12599ULL: goto x86_l_3137;
	case 12603ULL: goto x86_l_313b;
	case 12605ULL: goto x86_l_313d;
	case 12606ULL: goto x86_l_313e;
	case 12608ULL: goto x86_l_3140;
	case 12610ULL: goto x86_l_3142;
	case 12612ULL: goto x86_l_3144;
	case 12614ULL: goto x86_l_3146;
	case 12615ULL: goto x86_l_3147;
	case 12616ULL: goto x86_l_3148;
	case 12619ULL: goto x86_l_314b;
	case 12622ULL: goto x86_l_314e;
	case 12625ULL: goto x86_l_3151;
	case 12628ULL: goto x86_l_3154;
	case 12636ULL: goto x86_l_315c;
	case 12641ULL: goto x86_l_3161;
	case 12648ULL: goto x86_l_3168;
	case 12653ULL: goto x86_l_316d;
	case 12655ULL: goto x86_l_316f;
	case 12658ULL: goto x86_l_3172;
	case 12660ULL: goto x86_l_3174;
	case 12663ULL: goto x86_l_3177;
	case 12669ULL: goto x86_l_317d;
	case 12674ULL: goto x86_l_3182;
	case 12676ULL: goto x86_l_3184;
	case 12679ULL: goto x86_l_3187;
	case 12683ULL: goto x86_l_318b;
	case 12687ULL: goto x86_l_318f;
	case 12691ULL: goto x86_l_3193;
	case 12693ULL: goto x86_l_3195;
	case 12698ULL: goto x86_l_319a;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12709ULL: goto x86_l_31a5;
	case 12713ULL: goto x86_l_31a9;
	case 12717ULL: goto x86_l_31ad;
	case 12721ULL: goto x86_l_31b1;
	case 12725ULL: goto x86_l_31b5;
	case 12729ULL: goto x86_l_31b9;
	case 12732ULL: goto x86_l_31bc;
	case 12735ULL: goto x86_l_31bf;
	case 12738ULL: goto x86_l_31c2;
	case 12741ULL: goto x86_l_31c5;
	case 12746ULL: goto x86_l_31ca;
	case 12748ULL: goto x86_l_31cc;
	case 12750ULL: goto x86_l_31ce;
	case 12757ULL: goto x86_l_31d5;
	case 12760ULL: goto x86_l_31d8;
	case 12762ULL: goto x86_l_31da;
	case 12764ULL: goto x86_l_31dc;
	case 12768ULL: goto x86_l_31e0;
	case 12771ULL: goto x86_l_31e3;
	case 12773ULL: goto x86_l_31e5;
	case 12775ULL: goto x86_l_31e7;
	case 12777ULL: goto x86_l_31e9;
	case 12779ULL: goto x86_l_31eb;
	case 12786ULL: goto x86_l_31f2;
	case 12788ULL: goto x86_l_31f4;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12796ULL: goto x86_l_31fc;
	case 12801ULL: goto x86_l_3201;
	case 12805ULL: goto x86_l_3205;
	case 12806ULL: goto x86_l_3206;
	case 12808ULL: goto x86_l_3208;
	case 12810ULL: goto x86_l_320a;
	case 12812ULL: goto x86_l_320c;
	case 12814ULL: goto x86_l_320e;
	case 12815ULL: goto x86_l_320f;
	case 12816ULL: goto x86_l_3210;
	case 12817ULL: goto x86_l_3211;
	case 12819ULL: goto x86_l_3213;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12825ULL: goto x86_l_3219;
	case 12826ULL: goto x86_l_321a;
	case 12827ULL: goto x86_l_321b;
	case 12830ULL: goto x86_l_321e;
	case 12833ULL: goto x86_l_3221;
	case 12836ULL: goto x86_l_3224;
	case 12839ULL: goto x86_l_3227;
	case 12844ULL: goto x86_l_322c;
	case 12846ULL: goto x86_l_322e;
	case 12852ULL: goto x86_l_3234;
	case 12855ULL: goto x86_l_3237;
	case 12862ULL: goto x86_l_323e;
	case 12865ULL: goto x86_l_3241;
	case 12868ULL: goto x86_l_3244;
	case 12874ULL: goto x86_l_324a;
	case 12878ULL: goto x86_l_324e;
	case 12881ULL: goto x86_l_3251;
	case 12884ULL: goto x86_l_3254;
	case 12889ULL: goto x86_l_3259;
	case 12891ULL: goto x86_l_325b;
	case 12897ULL: goto x86_l_3261;
	case 12902ULL: goto x86_l_3266;
	case 12905ULL: goto x86_l_3269;
	case 12908ULL: goto x86_l_326c;
	case 12911ULL: goto x86_l_326f;
	case 12914ULL: goto x86_l_3272;
	case 12920ULL: goto x86_l_3278;
	case 12924ULL: goto x86_l_327c;
	case 12927ULL: goto x86_l_327f;
	case 12930ULL: goto x86_l_3282;
	case 12935ULL: goto x86_l_3287;
	case 12937ULL: goto x86_l_3289;
	case 12943ULL: goto x86_l_328f;
	case 12948ULL: goto x86_l_3294;
	case 12951ULL: goto x86_l_3297;
	case 12954ULL: goto x86_l_329a;
	case 12957ULL: goto x86_l_329d;
	case 12960ULL: goto x86_l_32a0;
	case 12966ULL: goto x86_l_32a6;
	case 12970ULL: goto x86_l_32aa;
	case 12973ULL: goto x86_l_32ad;
	case 12976ULL: goto x86_l_32b0;
	case 12981ULL: goto x86_l_32b5;
	case 12983ULL: goto x86_l_32b7;
	case 12989ULL: goto x86_l_32bd;
	case 12994ULL: goto x86_l_32c2;
	case 12997ULL: goto x86_l_32c5;
	case 13000ULL: goto x86_l_32c8;
	case 13003ULL: goto x86_l_32cb;
	case 13006ULL: goto x86_l_32ce;
	case 13012ULL: goto x86_l_32d4;
	case 13016ULL: goto x86_l_32d8;
	case 13019ULL: goto x86_l_32db;
	case 13022ULL: goto x86_l_32de;
	case 13027ULL: goto x86_l_32e3;
	case 13029ULL: goto x86_l_32e5;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13043ULL: goto x86_l_32f3;
	case 13046ULL: goto x86_l_32f6;
	case 13049ULL: goto x86_l_32f9;
	case 13052ULL: goto x86_l_32fc;
	case 13058ULL: goto x86_l_3302;
	case 13062ULL: goto x86_l_3306;
	case 13065ULL: goto x86_l_3309;
	case 13068ULL: goto x86_l_330c;
	case 13073ULL: goto x86_l_3311;
	case 13075ULL: goto x86_l_3313;
	case 13081ULL: goto x86_l_3319;
	case 13086ULL: goto x86_l_331e;
	case 13089ULL: goto x86_l_3321;
	case 13092ULL: goto x86_l_3324;
	case 13095ULL: goto x86_l_3327;
	case 13098ULL: goto x86_l_332a;
	case 13104ULL: goto x86_l_3330;
	case 13108ULL: goto x86_l_3334;
	case 13111ULL: goto x86_l_3337;
	case 13114ULL: goto x86_l_333a;
	case 13119ULL: goto x86_l_333f;
	case 13121ULL: goto x86_l_3341;
	case 13127ULL: goto x86_l_3347;
	case 13132ULL: goto x86_l_334c;
	case 13135ULL: goto x86_l_334f;
	case 13138ULL: goto x86_l_3352;
	case 13141ULL: goto x86_l_3355;
	case 13144ULL: goto x86_l_3358;
	case 13150ULL: goto x86_l_335e;
	case 13154ULL: goto x86_l_3362;
	case 13157ULL: goto x86_l_3365;
	case 13160ULL: goto x86_l_3368;
	case 13165ULL: goto x86_l_336d;
	case 13167ULL: goto x86_l_336f;
	case 13169ULL: goto x86_l_3371;
	case 13174ULL: goto x86_l_3376;
	case 13177ULL: goto x86_l_3379;
	case 13180ULL: goto x86_l_337c;
	case 13183ULL: goto x86_l_337f;
	case 13186ULL: goto x86_l_3382;
	case 13192ULL: goto x86_l_3388;
	case 13196ULL: goto x86_l_338c;
	case 13199ULL: goto x86_l_338f;
	case 13202ULL: goto x86_l_3392;
	case 13207ULL: goto x86_l_3397;
	case 13209ULL: goto x86_l_3399;
	case 13211ULL: goto x86_l_339b;
	case 13216ULL: goto x86_l_33a0;
	case 13219ULL: goto x86_l_33a3;
	case 13222ULL: goto x86_l_33a6;
	case 13225ULL: goto x86_l_33a9;
	case 13228ULL: goto x86_l_33ac;
	case 13234ULL: goto x86_l_33b2;
	case 13237ULL: goto x86_l_33b5;
	case 13240ULL: goto x86_l_33b8;
	case 13243ULL: goto x86_l_33bb;
	case 13246ULL: goto x86_l_33be;
	case 13251ULL: goto x86_l_33c3;
	case 13253ULL: goto x86_l_33c5;
	case 13255ULL: goto x86_l_33c7;
	case 13260ULL: goto x86_l_33cc;
	case 13263ULL: goto x86_l_33cf;
	case 13266ULL: goto x86_l_33d2;
	case 13271ULL: goto x86_l_33d7;
	case 13274ULL: goto x86_l_33da;
	case 13282ULL: goto x86_l_33e2;
	case 13287ULL: goto x86_l_33e7;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13301ULL: goto x86_l_33f5;
	case 13304ULL: goto x86_l_33f8;
	case 13306ULL: goto x86_l_33fa;
	case 13310ULL: goto x86_l_33fe;
	case 13312ULL: goto x86_l_3400;
	case 13316ULL: goto x86_l_3404;
	case 13318ULL: goto x86_l_3406;
	case 13322ULL: goto x86_l_340a;
	case 13324ULL: goto x86_l_340c;
	case 13328ULL: goto x86_l_3410;
	case 13330ULL: goto x86_l_3412;
	case 13336ULL: goto x86_l_3418;
	case 13338ULL: goto x86_l_341a;
	case 13342ULL: goto x86_l_341e;
	case 13344ULL: goto x86_l_3420;
	case 13348ULL: goto x86_l_3424;
	case 13350ULL: goto x86_l_3426;
	case 13354ULL: goto x86_l_342a;
	case 13356ULL: goto x86_l_342c;
	case 13362ULL: goto x86_l_3432;
	case 13364ULL: goto x86_l_3434;
	case 13370ULL: goto x86_l_343a;
	case 13372ULL: goto x86_l_343c;
	case 13378ULL: goto x86_l_3442;
	case 13380ULL: goto x86_l_3444;
	case 13386ULL: goto x86_l_344a;
	case 13388ULL: goto x86_l_344c;
	case 13394ULL: goto x86_l_3452;
	case 13396ULL: goto x86_l_3454;
	case 13402ULL: goto x86_l_345a;
	case 13406ULL: goto x86_l_345e;
	case 13409ULL: goto x86_l_3461;
	case 13413ULL: goto x86_l_3465;
	case 13414ULL: goto x86_l_3466;
	case 13416ULL: goto x86_l_3468;
	case 13418ULL: goto x86_l_346a;
	case 13420ULL: goto x86_l_346c;
	case 13422ULL: goto x86_l_346e;
	case 13423ULL: goto x86_l_346f;
	case 13424ULL: goto x86_l_3470;
	case 13426ULL: goto x86_l_3472;
	case 13428ULL: goto x86_l_3474;
	case 13430ULL: goto x86_l_3476;
	case 13431ULL: goto x86_l_3477;
	case 13432ULL: goto x86_l_3478;
	case 13435ULL: goto x86_l_347b;
	case 13437ULL: goto x86_l_347d;
	case 13440ULL: goto x86_l_3480;
	case 13443ULL: goto x86_l_3483;
	case 13450ULL: goto x86_l_348a;
	case 13455ULL: goto x86_l_348f;
	case 13459ULL: goto x86_l_3493;
	case 13463ULL: goto x86_l_3497;
	case 13468ULL: goto x86_l_349c;
	case 13470ULL: goto x86_l_349e;
	case 13472ULL: goto x86_l_34a0;
	case 13474ULL: goto x86_l_34a2;
	case 13476ULL: goto x86_l_34a4;
	case 13480ULL: goto x86_l_34a8;
	case 13484ULL: goto x86_l_34ac;
	case 13492ULL: goto x86_l_34b4;
	case 13497ULL: goto x86_l_34b9;
	case 13504ULL: goto x86_l_34c0;
	case 13509ULL: goto x86_l_34c5;
	case 13511ULL: goto x86_l_34c7;
	case 13514ULL: goto x86_l_34ca;
	case 13516ULL: goto x86_l_34cc;
	case 13520ULL: goto x86_l_34d0;
	case 13522ULL: goto x86_l_34d2;
	case 13527ULL: goto x86_l_34d7;
	case 13534ULL: goto x86_l_34de;
	case 13539ULL: goto x86_l_34e3;
	case 13542ULL: goto x86_l_34e6;
	case 13545ULL: goto x86_l_34e9;
	case 13548ULL: goto x86_l_34ec;
	case 13550ULL: goto x86_l_34ee;
	case 13552ULL: goto x86_l_34f0;
	case 13554ULL: goto x86_l_34f2;
	case 13556ULL: goto x86_l_34f4;
	case 13563ULL: goto x86_l_34fb;
	case 13565ULL: goto x86_l_34fd;
	case 13570ULL: goto x86_l_3502;
	case 13577ULL: goto x86_l_3509;
	case 13580ULL: goto x86_l_350c;
	case 13583ULL: goto x86_l_350f;
	case 13585ULL: goto x86_l_3511;
	case 13587ULL: goto x86_l_3513;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2fd0:
	/* 0x2fd0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fd5:
	/* 0x2fd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fda:
	/* 0x2fda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fdc:
	/* 0x2fdc: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2fe1:
	/* 0x2fe1: je     30c0 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30c0;
	}
x86_l_2fe7:
	/* 0x2fe7: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2feb:
	/* 0x2feb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ff0:
	/* 0x2ff0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ff5:
	/* 0x2ff5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ffa:
	/* 0x2ffa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ffd:
	/* 0x2ffd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fff:
	/* 0x2fff: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3004:
	/* 0x3004: je     30c0 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30c0;
	}
x86_l_300a:
	/* 0x300a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_300f:
	/* 0x300f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3014:
	/* 0x3014: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3019:
	/* 0x3019: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_301c:
	/* 0x301c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301e:
	/* 0x301e: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3022:
	/* 0x3022: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3027:
	/* 0x3027: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_302c:
	/* 0x302c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3031:
	/* 0x3031: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3034:
	/* 0x3034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3036:
	/* 0x3036: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_303a:
	/* 0x303a: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_303e:
	/* 0x303e: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3042:
	/* 0x3042: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3045:
	/* 0x3045: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3048:
	/* 0x3048: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_304a:
	/* 0x304a: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_304c:
	/* 0x304c: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_304e:
	/* 0x304e: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_3051:
	/* 0x3051: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3056:
	/* 0x3056: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3059:
	/* 0x3059: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_305b:
	/* 0x305b: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_305f:
	/* 0x305f: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_3062:
	/* 0x3062: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_3066:
	/* 0x3066: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3069:
	/* 0x3069: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_306b:
	/* 0x306b: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_306e:
	/* 0x306e: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3071:
	/* 0x3071: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3076:
	/* 0x3076: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3079:
	/* 0x3079: jb     3115 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3115;
	}
x86_l_307f:
	/* 0x307f: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_3086:
	/* 0x3086: ja     3115 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3115;
	}
x86_l_308c:
	/* 0x308c: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_308e:
	/* 0x308e: jbe    3121 <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3121;
	}
x86_l_3094:
	/* 0x3094: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3098:
	/* 0x3098: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_309d:
	/* 0x309d: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_30a1:
	/* 0x30a1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_30a5:
	/* 0x30a5: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_30a8:
	/* 0x30a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30ad:
	/* 0x30ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30af:
	/* 0x30af: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30b3:
	/* 0x30b3: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30b8:
	/* 0x30b8: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30bc:
	/* 0x30bc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30be:
	/* 0x30be: jmp    3115 <cwd_read_v61+0x173> */
	goto x86_l_3115;
x86_l_30c0:
	/* 0x30c0: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30c4:
	/* 0x30c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30c9:
	/* 0x30c9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30ce:
	/* 0x30ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d3:
	/* 0x30d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d5:
	/* 0x30d5: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30d9:
	/* 0x30d9: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_30de:
	/* 0x30de: je     310c <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_310c;
	}
x86_l_30e0:
	/* 0x30e0: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30e4:
	/* 0x30e4: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_30e8:
	/* 0x30e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30ed:
	/* 0x30ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30f2:
	/* 0x30f2: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_30f5:
	/* 0x30f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f7:
	/* 0x30f7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30fc:
	/* 0x30fc: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3100:
	/* 0x3100: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3104:
	/* 0x3104: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3108:
	/* 0x3108: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_310a:
	/* 0x310a: jmp    3115 <cwd_read_v61+0x173> */
	goto x86_l_3115;
x86_l_310c:
	/* 0x310c: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_3110:
	/* 0x3110: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3115:
	/* 0x3115: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3119:
	/* 0x3119: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_311a:
	/* 0x311a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_311c:
	/* 0x311c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_311e:
	/* 0x311e: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3120:
	/* 0x3120: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3121:
	/* 0x3121: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3125:
	/* 0x3125: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3128:
	/* 0x3128: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_312d:
	/* 0x312d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3130:
	/* 0x3130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3132:
	/* 0x3132: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3137:
	/* 0x3137: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_313b:
	/* 0x313b: jmp    3115 <cwd_read_v61+0x173> */
	goto x86_l_3115;
x86_l_313d:
	/* 0x313d: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_313e:
	/* 0x313e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3140:
	/* 0x3140: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3142:
	/* 0x3142: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_3144:
	/* 0x3144: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3146:
	/* 0x3146: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3147:
	/* 0x3147: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3148:
	/* 0x3148: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_314b:
	/* 0x314b: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_314e:
	/* 0x314e: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_3151:
	/* 0x3151: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_3154:
	/* 0x3154: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_315c:
	/* 0x315c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3161:
	/* 0x3161: mov    rdi,QWORD PTR [rip+0x220] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_3168:
	/* 0x3168: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_316d:
	/* 0x316d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_316f:
	/* 0x316f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3172:
	/* 0x3172: je     31e5 <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31e5;
	}
x86_l_3174:
	/* 0x3174: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3177:
	/* 0x3177: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_317d:
	/* 0x317d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3182:
	/* 0x3182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3184:
	/* 0x3184: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_3187:
	/* 0x3187: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_318b:
	/* 0x318b: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_318f:
	/* 0x318f: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_3193:
	/* 0x3193: jne    319e <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_319e;
	}
x86_l_3195:
	/* 0x3195: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_319a:
	/* 0x319a: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_319e:
	/* 0x319e: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_31a3:
	/* 0x31a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a5:
	/* 0x31a5: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31a9:
	/* 0x31a9: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31ad:
	/* 0x31ad: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31b1:
	/* 0x31b1: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b5:
	/* 0x31b5: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31b9:
	/* 0x31b9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_31bc:
	/* 0x31bc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_31bf:
	/* 0x31bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31c2:
	/* 0x31c2: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_31c5:
	/* 0x31c5: call   3210 <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 12746ULL);
	__x86_sim_call_depth++;
	goto x86_l_3210;
x86_l_31ca:
	/* 0x31ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31cc:
	/* 0x31cc: js     31e9 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31e9;
	}
x86_l_31ce:
	/* 0x31ce: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31d5:
	/* 0x31d5: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_31d8:
	/* 0x31d8: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31da:
	/* 0x31da: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31dc:
	/* 0x31dc: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_31e0:
	/* 0x31e0: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_31e3:
	/* 0x31e3: jmp    31f6 <data_event_bytes+0xb9> */
	goto x86_l_31f6;
x86_l_31e5:
	/* 0x31e5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31e7:
	/* 0x31e7: jmp    3201 <data_event_bytes+0xc4> */
	goto x86_l_3201;
x86_l_31e9:
	/* 0x31e9: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31eb:
	/* 0x31eb: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_31f2:
	/* 0x31f2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31f4:
	/* 0x31f4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31f6:
	/* 0x31f6: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f9:
	/* 0x31f9: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_31fc:
	/* 0x31fc: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_3201:
	/* 0x3201: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3205:
	/* 0x3205: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3206:
	/* 0x3206: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3208:
	/* 0x3208: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_320a:
	/* 0x320a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_320c:
	/* 0x320c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_320e:
	/* 0x320e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_320f:
	/* 0x320f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3210:
	/* 0x3210: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_3211:
	/* 0x3211: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3213:
	/* 0x3213: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3215:
	/* 0x3215: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_3217:
	/* 0x3217: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3219:
	/* 0x3219: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_321a:
	/* 0x321a: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_321b:
	/* 0x321b: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_321e:
	/* 0x321e: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_3221:
	/* 0x3221: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_3224:
	/* 0x3224: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_3227:
	/* 0x3227: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 12844ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_322c:
	/* 0x322c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_322e:
	/* 0x322e: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_3234:
	/* 0x3234: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3237:
	/* 0x3237: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_323e:
	/* 0x323e: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3241:
	/* 0x3241: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3244:
	/* 0x3244: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_324a:
	/* 0x324a: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_324e:
	/* 0x324e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3251:
	/* 0x3251: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3254:
	/* 0x3254: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 12889ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_3259:
	/* 0x3259: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_325b:
	/* 0x325b: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_3261:
	/* 0x3261: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3266:
	/* 0x3266: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3269:
	/* 0x3269: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_326c:
	/* 0x326c: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_326f:
	/* 0x326f: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3272:
	/* 0x3272: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_3278:
	/* 0x3278: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_327c:
	/* 0x327c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_327f:
	/* 0x327f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3282:
	/* 0x3282: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 12935ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_3287:
	/* 0x3287: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3289:
	/* 0x3289: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_328f:
	/* 0x328f: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3294:
	/* 0x3294: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3297:
	/* 0x3297: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_329a:
	/* 0x329a: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_329d:
	/* 0x329d: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_32a0:
	/* 0x32a0: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_32a6:
	/* 0x32a6: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_32aa:
	/* 0x32aa: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32ad:
	/* 0x32ad: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_32b0:
	/* 0x32b0: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 12981ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_32b5:
	/* 0x32b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32b7:
	/* 0x32b7: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_32bd:
	/* 0x32bd: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_32c2:
	/* 0x32c2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_32c5:
	/* 0x32c5: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32c8:
	/* 0x32c8: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_32cb:
	/* 0x32cb: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_32ce:
	/* 0x32ce: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_32d4:
	/* 0x32d4: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_32d8:
	/* 0x32d8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32db:
	/* 0x32db: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_32de:
	/* 0x32de: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13027ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_32e3:
	/* 0x32e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32e5:
	/* 0x32e5: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_32eb:
	/* 0x32eb: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_32f0:
	/* 0x32f0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_32f3:
	/* 0x32f3: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32f6:
	/* 0x32f6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_32f9:
	/* 0x32f9: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_32fc:
	/* 0x32fc: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_3302:
	/* 0x3302: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3306:
	/* 0x3306: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3309:
	/* 0x3309: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_330c:
	/* 0x330c: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13073ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_3311:
	/* 0x3311: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3313:
	/* 0x3313: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_3319:
	/* 0x3319: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_331e:
	/* 0x331e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3321:
	/* 0x3321: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3324:
	/* 0x3324: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3327:
	/* 0x3327: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_332a:
	/* 0x332a: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_3330:
	/* 0x3330: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3334:
	/* 0x3334: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3337:
	/* 0x3337: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_333a:
	/* 0x333a: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13119ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_333f:
	/* 0x333f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3341:
	/* 0x3341: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_3347:
	/* 0x3347: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_334c:
	/* 0x334c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_334f:
	/* 0x334f: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3352:
	/* 0x3352: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3355:
	/* 0x3355: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3358:
	/* 0x3358: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_335e:
	/* 0x335e: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3362:
	/* 0x3362: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3365:
	/* 0x3365: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3368:
	/* 0x3368: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13165ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_336d:
	/* 0x336d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_336f:
	/* 0x336f: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_3371:
	/* 0x3371: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3376:
	/* 0x3376: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3379:
	/* 0x3379: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_337c:
	/* 0x337c: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_337f:
	/* 0x337f: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3382:
	/* 0x3382: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_3388:
	/* 0x3388: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_338c:
	/* 0x338c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_338f:
	/* 0x338f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3392:
	/* 0x3392: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13207ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_3397:
	/* 0x3397: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3399:
	/* 0x3399: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_339b:
	/* 0x339b: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_33a0:
	/* 0x33a0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_33a3:
	/* 0x33a3: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33a6:
	/* 0x33a6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_33a9:
	/* 0x33a9: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_33ac:
	/* 0x33ac: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_33b2:
	/* 0x33b2: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33b5:
	/* 0x33b5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_33b8:
	/* 0x33b8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_33bb:
	/* 0x33bb: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_33be:
	/* 0x33be: call   3470 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13251ULL);
	__x86_sim_call_depth++;
	goto x86_l_3470;
x86_l_33c3:
	/* 0x33c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33c5:
	/* 0x33c5: js     33d7 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_33d7;
	}
x86_l_33c7:
	/* 0x33c7: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_33cc:
	/* 0x33cc: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33cf:
	/* 0x33cf: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_33d2:
	/* 0x33d2: jmp    345e <do_bytes+0x24e> */
	goto x86_l_345e;
x86_l_33d7:
	/* 0x33d7: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_33da:
	/* 0x33da: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_33e2:
	/* 0x33e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33e7:
	/* 0x33e7: mov    rdi,QWORD PTR [rip+0x300] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_33ee:
	/* 0x33ee: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_33f3:
	/* 0x33f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f5:
	/* 0x33f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33f8:
	/* 0x33f8: je     345e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345e;
	}
x86_l_33fa:
	/* 0x33fa: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_33fe:
	/* 0x33fe: jg     341a <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_341a;
	}
x86_l_3400:
	/* 0x3400: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_3404:
	/* 0x3404: je     3434 <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3434;
	}
x86_l_3406:
	/* 0x3406: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_340a:
	/* 0x340a: je     344c <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_344c;
	}
x86_l_340c:
	/* 0x340c: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_3410:
	/* 0x3410: jne    3444 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3444;
	}
x86_l_3412:
	/* 0x3412: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_3418:
	/* 0x3418: jmp    345a <do_bytes+0x24a> */
	goto x86_l_345a;
x86_l_341a:
	/* 0x341a: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_341e:
	/* 0x341e: je     343c <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_343c;
	}
x86_l_3420:
	/* 0x3420: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_3424:
	/* 0x3424: je     3454 <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3454;
	}
x86_l_3426:
	/* 0x3426: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_342a:
	/* 0x342a: jne    3444 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3444;
	}
x86_l_342c:
	/* 0x342c: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_3432:
	/* 0x3432: jmp    345a <do_bytes+0x24a> */
	goto x86_l_345a;
x86_l_3434:
	/* 0x3434: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_343a:
	/* 0x343a: jmp    345a <do_bytes+0x24a> */
	goto x86_l_345a;
x86_l_343c:
	/* 0x343c: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_3442:
	/* 0x3442: jmp    345a <do_bytes+0x24a> */
	goto x86_l_345a;
x86_l_3444:
	/* 0x3444: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_344a:
	/* 0x344a: jmp    345a <do_bytes+0x24a> */
	goto x86_l_345a;
x86_l_344c:
	/* 0x344c: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_3452:
	/* 0x3452: jmp    345a <do_bytes+0x24a> */
	goto x86_l_345a;
x86_l_3454:
	/* 0x3454: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_345a:
	/* 0x345a: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_345e:
	/* 0x345e: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3461:
	/* 0x3461: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3465:
	/* 0x3465: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3466:
	/* 0x3466: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3468:
	/* 0x3468: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_346a:
	/* 0x346a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_346c:
	/* 0x346c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_346e:
	/* 0x346e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_346f:
	/* 0x346f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3470:
	/* 0x3470: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3472:
	/* 0x3472: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3474:
	/* 0x3474: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3476:
	/* 0x3476: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3477:
	/* 0x3477: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3478:
	/* 0x3478: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_347b:
	/* 0x347b: js     34f4 <__do_bytes+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34f4;
	}
x86_l_347d:
	/* 0x347d: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_3480:
	/* 0x3480: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_3483:
	/* 0x3483: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_348a:
	/* 0x348a: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_348f:
	/* 0x348f: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_3493:
	/* 0x3493: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3497:
	/* 0x3497: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_349c:
	/* 0x349c: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_349e:
	/* 0x349e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a0:
	/* 0x34a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34a2:
	/* 0x34a2: js     3517 <__do_bytes+0xa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13591ULL;
	}
x86_l_34a4:
	/* 0x34a4: lea    r12d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34a8:
	/* 0x34a8: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34ac:
	/* 0x34ac: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_34b4:
	/* 0x34b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34b9:
	/* 0x34b9: mov    rdi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_34c0:
	/* 0x34c0: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34c5:
	/* 0x34c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34c7:
	/* 0x34c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34ca:
	/* 0x34ca: je     34fd <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34fd;
	}
x86_l_34cc:
	/* 0x34cc: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_34d0:
	/* 0x34d0: je     34fd <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34fd;
	}
x86_l_34d2:
	/* 0x34d2: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_34d7:
	/* 0x34d7: mov    rsi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_34de:
	/* 0x34de: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_34e3:
	/* 0x34e3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_34e6:
	/* 0x34e6: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_34e9:
	/* 0x34e9: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_34ec:
	/* 0x34ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34ee:
	/* 0x34ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34f0:
	/* 0x34f0: js     3517 <__do_bytes+0xa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13591ULL;
	}
x86_l_34f2:
	/* 0x34f2: jmp    351a <__do_bytes+0xaa> */
	return 13594ULL;
x86_l_34f4:
	/* 0x34f4: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_34fb:
	/* 0x34fb: jmp    351a <__do_bytes+0xaa> */
	return 13594ULL;
x86_l_34fd:
	/* 0x34fd: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_3502:
	/* 0x3502: mov    rdi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_3509:
	/* 0x3509: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_350c:
	/* 0x350c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_350f:
	/* 0x350f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3511:
	/* 0x3511: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3513:
	/* 0x3513: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 13589ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13589ULL: goto x86_l_3515;
	case 13591ULL: goto x86_l_3517;
	case 13594ULL: goto x86_l_351a;
	case 13597ULL: goto x86_l_351d;
	case 13601ULL: goto x86_l_3521;
	case 13602ULL: goto x86_l_3522;
	case 13604ULL: goto x86_l_3524;
	case 13606ULL: goto x86_l_3526;
	case 13608ULL: goto x86_l_3528;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3515:
	/* 0x3515: jns    351a <__do_bytes+0xaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_351a;
	}
x86_l_3517:
	/* 0x3517: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_351a:
	/* 0x351a: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_351d:
	/* 0x351d: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3521:
	/* 0x3521: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3522:
	/* 0x3522: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3524:
	/* 0x3524: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3526:
	/* 0x3526: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3528:
	/* 0x3528: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12324U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1814ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1816ULL && __x86_pc <= 3625ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3631ULL && __x86_pc <= 5455ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5463ULL && __x86_pc <= 7253ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7256ULL && __x86_pc <= 8986ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8991ULL && __x86_pc <= 10704ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10707ULL && __x86_pc <= 12235ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12240ULL && __x86_pc <= 13587ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13589ULL && __x86_pc <= 13608ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v61_generic_lsm_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

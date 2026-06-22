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
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 31ULL: goto x86_l_1f;
	case 39ULL: goto x86_l_27;
	case 44ULL: goto x86_l_2c;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 64ULL: goto x86_l_40;
	case 67ULL: goto x86_l_43;
	case 74ULL: goto x86_l_4a;
	case 80ULL: goto x86_l_50;
	case 91ULL: goto x86_l_5b;
	case 98ULL: goto x86_l_62;
	case 106ULL: goto x86_l_6a;
	case 111ULL: goto x86_l_6f;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 122ULL: goto x86_l_7a;
	case 125ULL: goto x86_l_7d;
	case 132ULL: goto x86_l_84;
	case 139ULL: goto x86_l_8b;
	case 144ULL: goto x86_l_90;
	case 146ULL: goto x86_l_92;
	case 149ULL: goto x86_l_95;
	case 155ULL: goto x86_l_9b;
	case 158ULL: goto x86_l_9e;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 171ULL: goto x86_l_ab;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 186ULL: goto x86_l_ba;
	case 188ULL: goto x86_l_bc;
	case 200ULL: goto x86_l_c8;
	case 206ULL: goto x86_l_ce;
	case 210ULL: goto x86_l_d2;
	case 215ULL: goto x86_l_d7;
	case 220ULL: goto x86_l_dc;
	case 222ULL: goto x86_l_de;
	case 224ULL: goto x86_l_e0;
	case 226ULL: goto x86_l_e2;
	case 230ULL: goto x86_l_e6;
	case 236ULL: goto x86_l_ec;
	case 240ULL: goto x86_l_f0;
	case 243ULL: goto x86_l_f3;
	case 251ULL: goto x86_l_fb;
	case 256ULL: goto x86_l_100;
	case 268ULL: goto x86_l_10c;
	case 270ULL: goto x86_l_10e;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 288ULL: goto x86_l_120;
	case 291ULL: goto x86_l_123;
	case 293ULL: goto x86_l_125;
	case 295ULL: goto x86_l_127;
	case 299ULL: goto x86_l_12b;
	case 307ULL: goto x86_l_133;
	case 309ULL: goto x86_l_135;
	case 312ULL: goto x86_l_138;
	case 318ULL: goto x86_l_13e;
	case 321ULL: goto x86_l_141;
	case 326ULL: goto x86_l_146;
	case 331ULL: goto x86_l_14b;
	case 336ULL: goto x86_l_150;
	case 339ULL: goto x86_l_153;
	case 344ULL: goto x86_l_158;
	case 349ULL: goto x86_l_15d;
	case 351ULL: goto x86_l_15f;
	case 354ULL: goto x86_l_162;
	case 359ULL: goto x86_l_167;
	case 366ULL: goto x86_l_16e;
	case 371ULL: goto x86_l_173;
	case 373ULL: goto x86_l_175;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 386ULL: goto x86_l_182;
	case 388ULL: goto x86_l_184;
	case 392ULL: goto x86_l_188;
	case 395ULL: goto x86_l_18b;
	case 398ULL: goto x86_l_18e;
	case 403ULL: goto x86_l_193;
	case 405ULL: goto x86_l_195;
	case 408ULL: goto x86_l_198;
	case 411ULL: goto x86_l_19b;
	case 413ULL: goto x86_l_19d;
	case 415ULL: goto x86_l_19f;
	case 418ULL: goto x86_l_1a2;
	case 423ULL: goto x86_l_1a7;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 437ULL: goto x86_l_1b5;
	case 442ULL: goto x86_l_1ba;
	case 446ULL: goto x86_l_1be;
	case 448ULL: goto x86_l_1c0;
	case 450ULL: goto x86_l_1c2;
	case 455ULL: goto x86_l_1c7;
	case 459ULL: goto x86_l_1cb;
	case 467ULL: goto x86_l_1d3;
	case 470ULL: goto x86_l_1d6;
	case 476ULL: goto x86_l_1dc;
	case 480ULL: goto x86_l_1e0;
	case 483ULL: goto x86_l_1e3;
	case 489ULL: goto x86_l_1e9;
	case 495ULL: goto x86_l_1ef;
	case 498ULL: goto x86_l_1f2;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 515ULL: goto x86_l_203;
	case 520ULL: goto x86_l_208;
	case 525ULL: goto x86_l_20d;
	case 529ULL: goto x86_l_211;
	case 535ULL: goto x86_l_217;
	case 543ULL: goto x86_l_21f;
	case 550ULL: goto x86_l_226;
	case 553ULL: goto x86_l_229;
	case 555ULL: goto x86_l_22b;
	case 558ULL: goto x86_l_22e;
	case 563ULL: goto x86_l_233;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 575ULL: goto x86_l_23f;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 585ULL: goto x86_l_249;
	case 587ULL: goto x86_l_24b;
	case 589ULL: goto x86_l_24d;
	case 592ULL: goto x86_l_250;
	case 596ULL: goto x86_l_254;
	case 598ULL: goto x86_l_256;
	case 603ULL: goto x86_l_25b;
	case 610ULL: goto x86_l_262;
	case 612ULL: goto x86_l_264;
	case 617ULL: goto x86_l_269;
	case 621ULL: goto x86_l_26d;
	case 624ULL: goto x86_l_270;
	case 627ULL: goto x86_l_273;
	case 634ULL: goto x86_l_27a;
	case 636ULL: goto x86_l_27c;
	case 641ULL: goto x86_l_281;
	case 643ULL: goto x86_l_283;
	case 648ULL: goto x86_l_288;
	case 650ULL: goto x86_l_28a;
	case 657ULL: goto x86_l_291;
	case 659ULL: goto x86_l_293;
	case 664ULL: goto x86_l_298;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 679ULL: goto x86_l_2a7;
	case 681ULL: goto x86_l_2a9;
	case 683ULL: goto x86_l_2ab;
	case 685ULL: goto x86_l_2ad;
	case 688ULL: goto x86_l_2b0;
	case 696ULL: goto x86_l_2b8;
	case 699ULL: goto x86_l_2bb;
	case 707ULL: goto x86_l_2c3;
	case 713ULL: goto x86_l_2c9;
	case 717ULL: goto x86_l_2cd;
	case 719ULL: goto x86_l_2cf;
	case 723ULL: goto x86_l_2d3;
	case 728ULL: goto x86_l_2d8;
	case 730ULL: goto x86_l_2da;
	case 734ULL: goto x86_l_2de;
	case 740ULL: goto x86_l_2e4;
	case 744ULL: goto x86_l_2e8;
	case 750ULL: goto x86_l_2ee;
	case 754ULL: goto x86_l_2f2;
	case 757ULL: goto x86_l_2f5;
	case 763ULL: goto x86_l_2fb;
	case 767ULL: goto x86_l_2ff;
	case 773ULL: goto x86_l_305;
	case 778ULL: goto x86_l_30a;
	case 782ULL: goto x86_l_30e;
	case 787ULL: goto x86_l_313;
	case 789ULL: goto x86_l_315;
	case 793ULL: goto x86_l_319;
	case 799ULL: goto x86_l_31f;
	case 803ULL: goto x86_l_323;
	case 806ULL: goto x86_l_326;
	case 812ULL: goto x86_l_32c;
	case 816ULL: goto x86_l_330;
	case 822ULL: goto x86_l_336;
	case 826ULL: goto x86_l_33a;
	case 832ULL: goto x86_l_340;
	case 837ULL: goto x86_l_345;
	case 841ULL: goto x86_l_349;
	case 847ULL: goto x86_l_34f;
	case 851ULL: goto x86_l_353;
	case 854ULL: goto x86_l_356;
	case 860ULL: goto x86_l_35c;
	case 864ULL: goto x86_l_360;
	case 867ULL: goto x86_l_363;
	case 873ULL: goto x86_l_369;
	case 878ULL: goto x86_l_36e;
	case 882ULL: goto x86_l_372;
	case 888ULL: goto x86_l_378;
	case 892ULL: goto x86_l_37c;
	case 898ULL: goto x86_l_382;
	case 902ULL: goto x86_l_386;
	case 908ULL: goto x86_l_38c;
	case 912ULL: goto x86_l_390;
	case 918ULL: goto x86_l_396;
	case 923ULL: goto x86_l_39b;
	case 927ULL: goto x86_l_39f;
	case 933ULL: goto x86_l_3a5;
	case 937ULL: goto x86_l_3a9;
	case 943ULL: goto x86_l_3af;
	case 947ULL: goto x86_l_3b3;
	case 953ULL: goto x86_l_3b9;
	case 957ULL: goto x86_l_3bd;
	case 963ULL: goto x86_l_3c3;
	case 969ULL: goto x86_l_3c9;
	case 974ULL: goto x86_l_3ce;
	case 978ULL: goto x86_l_3d2;
	case 984ULL: goto x86_l_3d8;
	case 988ULL: goto x86_l_3dc;
	case 994ULL: goto x86_l_3e2;
	case 998ULL: goto x86_l_3e6;
	case 1000ULL: goto x86_l_3e8;
	case 1004ULL: goto x86_l_3ec;
	case 1010ULL: goto x86_l_3f2;
	case 1015ULL: goto x86_l_3f7;
	case 1019ULL: goto x86_l_3fb;
	case 1021ULL: goto x86_l_3fd;
	case 1026ULL: goto x86_l_402;
	case 1030ULL: goto x86_l_406;
	case 1036ULL: goto x86_l_40c;
	case 1040ULL: goto x86_l_410;
	case 1042ULL: goto x86_l_412;
	case 1044ULL: goto x86_l_414;
	case 1048ULL: goto x86_l_418;
	case 1051ULL: goto x86_l_41b;
	case 1053ULL: goto x86_l_41d;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1067ULL: goto x86_l_42b;
	case 1069ULL: goto x86_l_42d;
	case 1073ULL: goto x86_l_431;
	case 1075ULL: goto x86_l_433;
	case 1079ULL: goto x86_l_437;
	case 1081ULL: goto x86_l_439;
	case 1087ULL: goto x86_l_43f;
	case 1089ULL: goto x86_l_441;
	case 1093ULL: goto x86_l_445;
	case 1095ULL: goto x86_l_447;
	case 1099ULL: goto x86_l_44b;
	case 1101ULL: goto x86_l_44d;
	case 1103ULL: goto x86_l_44f;
	case 1109ULL: goto x86_l_455;
	case 1111ULL: goto x86_l_457;
	case 1115ULL: goto x86_l_45b;
	case 1117ULL: goto x86_l_45d;
	case 1121ULL: goto x86_l_461;
	case 1123ULL: goto x86_l_463;
	case 1129ULL: goto x86_l_469;
	case 1131ULL: goto x86_l_46b;
	case 1137ULL: goto x86_l_471;
	case 1139ULL: goto x86_l_473;
	case 1145ULL: goto x86_l_479;
	case 1147ULL: goto x86_l_47b;
	case 1151ULL: goto x86_l_47f;
	case 1153ULL: goto x86_l_481;
	case 1159ULL: goto x86_l_487;
	case 1161ULL: goto x86_l_489;
	case 1164ULL: goto x86_l_48c;
	case 1169ULL: goto x86_l_491;
	case 1180ULL: goto x86_l_49c;
	case 1187ULL: goto x86_l_4a3;
	case 1195ULL: goto x86_l_4ab;
	case 1200ULL: goto x86_l_4b0;
	case 1202ULL: goto x86_l_4b2;
	case 1205ULL: goto x86_l_4b5;
	case 1211ULL: goto x86_l_4bb;
	case 1216ULL: goto x86_l_4c0;
	case 1219ULL: goto x86_l_4c3;
	case 1222ULL: goto x86_l_4c6;
	case 1228ULL: goto x86_l_4cc;
	case 1232ULL: goto x86_l_4d0;
	case 1239ULL: goto x86_l_4d7;
	case 1246ULL: goto x86_l_4de;
	case 1250ULL: goto x86_l_4e2;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1265ULL: goto x86_l_4f1;
	case 1271ULL: goto x86_l_4f7;
	case 1274ULL: goto x86_l_4fa;
	case 1281ULL: goto x86_l_501;
	case 1288ULL: goto x86_l_508;
	case 1291ULL: goto x86_l_50b;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1313ULL: goto x86_l_521;
	case 1317ULL: goto x86_l_525;
	case 1322ULL: goto x86_l_52a;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1334ULL: goto x86_l_536;
	case 1338ULL: goto x86_l_53a;
	case 1340ULL: goto x86_l_53c;
	case 1344ULL: goto x86_l_540;
	case 1350ULL: goto x86_l_546;
	case 1354ULL: goto x86_l_54a;
	case 1360ULL: goto x86_l_550;
	case 1372ULL: goto x86_l_55c;
	case 1380ULL: goto x86_l_564;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1397ULL: goto x86_l_575;
	case 1403ULL: goto x86_l_57b;
	case 1407ULL: goto x86_l_57f;
	case 1413ULL: goto x86_l_585;
	case 1418ULL: goto x86_l_58a;
	case 1420ULL: goto x86_l_58c;
	case 1425ULL: goto x86_l_591;
	case 1430ULL: goto x86_l_596;
	case 1435ULL: goto x86_l_59b;
	case 1440ULL: goto x86_l_5a0;
	case 1443ULL: goto x86_l_5a3;
	case 1448ULL: goto x86_l_5a8;
	case 1450ULL: goto x86_l_5aa;
	case 1455ULL: goto x86_l_5af;
	case 1460ULL: goto x86_l_5b4;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1475ULL: goto x86_l_5c3;
	case 1480ULL: goto x86_l_5c8;
	case 1482ULL: goto x86_l_5ca;
	case 1486ULL: goto x86_l_5ce;
	case 1491ULL: goto x86_l_5d3;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1506ULL: goto x86_l_5e2;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1527ULL: goto x86_l_5f7;
	case 1532ULL: goto x86_l_5fc;
	case 1543ULL: goto x86_l_607;
	case 1550ULL: goto x86_l_60e;
	case 1558ULL: goto x86_l_616;
	case 1563ULL: goto x86_l_61b;
	case 1565ULL: goto x86_l_61d;
	case 1568ULL: goto x86_l_620;
	case 1574ULL: goto x86_l_626;
	case 1577ULL: goto x86_l_629;
	case 1582ULL: goto x86_l_62e;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1596ULL: goto x86_l_63c;
	case 1603ULL: goto x86_l_643;
	case 1611ULL: goto x86_l_64b;
	case 1616ULL: goto x86_l_650;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1628ULL: goto x86_l_65c;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1645ULL: goto x86_l_66d;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1673ULL: goto x86_l_689;
	case 1678ULL: goto x86_l_68e;
	case 1683ULL: goto x86_l_693;
	case 1685ULL: goto x86_l_695;
	case 1693ULL: goto x86_l_69d;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1719ULL: goto x86_l_6b7;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1732ULL: goto x86_l_6c4;
	case 1735ULL: goto x86_l_6c7;
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
	/* 0x18: mov    rdi,QWORD PTR [rip+0x257] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xec] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     dcb <generic_kprobe_process_event+0xdcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3531ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    ebx,DWORD PTR [rax+0x5efc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_40:
	/* 0x40: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_43:
	/* 0x43: cmp    rbp,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 8999ULL);
x86_l_4a:
	/* 0x4a: ja     d2f <generic_kprobe_process_event+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3375ULL;
	}
x86_l_50:
	/* 0x50: mov    DWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_5b:
	/* 0x5b: mov    rdi,QWORD PTR [rip+0x257] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_62:
	/* 0x62: lea    rsi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_6a:
	/* 0x6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6f:
	/* 0x6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71:
	/* 0x71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: je     d2f <generic_kprobe_process_event+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_7a:
	/* 0x7a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_84:
	/* 0x84: mov    rdi,QWORD PTR [rip+0x257] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_8b:
	/* 0x8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_90:
	/* 0x90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92:
	/* 0x92: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_95:
	/* 0x95: jg     d2f <generic_kprobe_process_event+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3375ULL;
	}
x86_l_9b:
	/* 0x9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e:
	/* 0x9e: je     d2f <generic_kprobe_process_event+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_a4:
	/* 0xa4: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a9:
	/* 0xa9: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_ab:
	/* 0xab: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_ae:
	/* 0xae: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_b0:
	/* 0xb0: mov    r13d,DWORD PTR [rax+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_b5:
	/* 0xb5: movsxd rsi,DWORD PTR [rax+rbp*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RBP, 2, X86_WIDTH_32), 24ULL);
x86_l_ba:
	/* 0xba: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_bc:
	/* 0xbc: mov    DWORD PTR [r15+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_c8:
	/* 0xc8: test   esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_ce:
	/* 0xce: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d2:
	/* 0xd2: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d7:
	/* 0xd7: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dc:
	/* 0xdc: jne    100 <generic_kprobe_process_event+0x100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_100;
	}
x86_l_de:
	/* 0xde: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_e0:
	/* 0xe0: js     113 <generic_kprobe_process_event+0x113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_113;
	}
x86_l_e2:
	/* 0xe2: test   sil,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 64ULL);
x86_l_e6:
	/* 0xe6: jne    175 <generic_kprobe_process_event+0x175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_175;
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
	/* 0xfb: jmp    1cb <generic_kprobe_process_event+0x1cb> */
	goto x86_l_1cb;
x86_l_100:
	/* 0x100: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_10c:
	/* 0x10c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e:
	/* 0x10e: jmp    2c3 <generic_kprobe_process_event+0x2c3> */
	goto x86_l_2c3;
x86_l_113:
	/* 0x113: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_118:
	/* 0x118: movzx  ecx,BYTE PTR [rax+rdx*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 2, X86_WIDTH_8), 706ULL);
x86_l_120:
	/* 0x120: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_123:
	/* 0x123: mov    bl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_8, 64ULL);
x86_l_125:
	/* 0x125: sub    bl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_127:
	/* 0x127: cmp    DWORD PTR [rax+0x54],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_12b:
	/* 0x12b: movzx  edx,WORD PTR [rax+rdx*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 2, X86_WIDTH_16), 704ULL);
x86_l_133:
	/* 0x133: je     195 <generic_kprobe_process_event+0x195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_195;
	}
x86_l_135:
	/* 0x135: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_138:
	/* 0x138: je     1c0 <generic_kprobe_process_event+0x1c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c0;
	}
x86_l_13e:
	/* 0x13e: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_141:
	/* 0x141: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_146:
	/* 0x146: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14b:
	/* 0x14b: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_150:
	/* 0x150: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_153:
	/* 0x153: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_158:
	/* 0x158: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15d:
	/* 0x15d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f:
	/* 0x15f: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_162:
	/* 0x162: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_167:
	/* 0x167: shlx   rcx,QWORD PTR [rsp+0x68],rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RBX)), ((104ULL << 32) | X86_ALU_SHL));
x86_l_16e:
	/* 0x16e: sarx   rsi,rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RCX, X86_WIDTH_64, X86_RBX, X86_ALU_SAR);
x86_l_173:
	/* 0x173: jmp    1c2 <generic_kprobe_process_event+0x1c2> */
	goto x86_l_1c2;
x86_l_175:
	/* 0x175: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17a:
	/* 0x17a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_17d:
	/* 0x17d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_182:
	/* 0x182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184:
	/* 0x184: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_188:
	/* 0x188: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_18e:
	/* 0x18e: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_193:
	/* 0x193: jmp    1cb <generic_kprobe_process_event+0x1cb> */
	goto x86_l_1cb;
x86_l_195:
	/* 0x195: movzx  ecx,bl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_198:
	/* 0x198: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19b:
	/* 0x19b: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_19d:
	/* 0x19d: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_19f:
	/* 0x19f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a2:
	/* 0x1a2: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 423ULL);
	__x86_sim_call_depth++;
	return 13409ULL;
x86_l_1a7:
	/* 0x1a7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1aa:
	/* 0x1aa: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_1ad:
	/* 0x1ad: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1b5:
	/* 0x1b5: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ba:
	/* 0x1ba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be:
	/* 0x1be: jmp    1d3 <generic_kprobe_process_event+0x1d3> */
	goto x86_l_1d3;
x86_l_1c0:
	/* 0x1c0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c2:
	/* 0x1c2: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c7:
	/* 0x1c7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb:
	/* 0x1cb: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1d3:
	/* 0x1d3: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1d6:
	/* 0x1d6: ja     2c3 <generic_kprobe_process_event+0x2c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c3;
	}
x86_l_1dc:
	/* 0x1dc: lea    rcx,[rdx+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_1e0:
	/* 0x1e0: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_1e3:
	/* 0x1e3: cmp    WORD PTR [rax+rcx*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 506806140928ULL);
x86_l_1e9:
	/* 0x1e9: je     2c3 <generic_kprobe_process_event+0x2c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c3;
	}
x86_l_1ef:
	/* 0x1ef: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f2:
	/* 0x1f2: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_1f6:
	/* 0x1f6: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1fb:
	/* 0x1fb: lea    rax,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_203:
	/* 0x203: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_208:
	/* 0x208: mov    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_20d:
	/* 0x20d: lea    rax,[r15+rbp*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_211:
	/* 0x211: add    rax,0x5ea0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24224ULL);
x86_l_217:
	/* 0x217: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_21f:
	/* 0x21f: mov    rax,QWORD PTR [rip+0x257] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_226:
	/* 0x226: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_229:
	/* 0x229: je     28a <generic_kprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28a;
	}
x86_l_22b:
	/* 0x22b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22e:
	/* 0x22e: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_233:
	/* 0x233: jmp    256 <generic_kprobe_process_event+0x256> */
	goto x86_l_256;
x86_l_235:
	/* 0x235: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23a:
	/* 0x23a: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_23f:
	/* 0x23f: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_242:
	/* 0x242: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_247:
	/* 0x247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249:
	/* 0x249: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b:
	/* 0x24b: js     2ad <generic_kprobe_process_event+0x2ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ad;
	}
x86_l_24d:
	/* 0x24d: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_250:
	/* 0x250: cmp    r15,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 10ULL);
x86_l_254:
	/* 0x254: je     2bb <generic_kprobe_process_event+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bb;
	}
x86_l_256:
	/* 0x256: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25b:
	/* 0x25b: cmp    WORD PTR [rax+r15*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 25769803776ULL);
x86_l_262:
	/* 0x262: je     2bb <generic_kprobe_process_event+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bb;
	}
x86_l_264:
	/* 0x264: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_269:
	/* 0x269: mov    edx,DWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_26d:
	/* 0x26d: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_270:
	/* 0x270: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273:
	/* 0x273: cmp    WORD PTR [rax+r15*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 17179869184ULL);
x86_l_27a:
	/* 0x27a: je     24d <generic_kprobe_process_event+0x24d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d;
	}
x86_l_27c:
	/* 0x27c: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_281:
	/* 0x281: je     235 <generic_kprobe_process_event+0x235> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235;
	}
x86_l_283:
	/* 0x283: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_288:
	/* 0x288: jmp    23a <generic_kprobe_process_event+0x23a> */
	goto x86_l_23a;
x86_l_28a:
	/* 0x28a: lea    rsi,[rip+0x257] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 599ULL);
x86_l_291:
	/* 0x291: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_293:
	/* 0x293: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_298:
	/* 0x298: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_29d:
	/* 0x29d: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_2a2:
	/* 0x2a2: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_2a7:
	/* 0x2a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a9:
	/* 0x2a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab:
	/* 0x2ab: jmp    2bb <generic_kprobe_process_event+0x2bb> */
	goto x86_l_2bb;
x86_l_2ad:
	/* 0x2ad: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b0:
	/* 0x2b0: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2b8:
	/* 0x2b8: mov    DWORD PTR [rax],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bb:
	/* 0x2bb: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2c3:
	/* 0x2c3: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_2c9:
	/* 0x2c9: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_2cd:
	/* 0x2cd: jg     30a <generic_kprobe_process_event+0x30a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30a;
	}
x86_l_2cf:
	/* 0x2cf: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_2d3:
	/* 0x2d3: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d8:
	/* 0x2d8: jg     345 <generic_kprobe_process_event+0x345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_345;
	}
x86_l_2da:
	/* 0x2da: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_2de:
	/* 0x2de: jg     3ce <generic_kprobe_process_event+0x3ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3ce;
	}
x86_l_2e4:
	/* 0x2e4: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2e8:
	/* 0x2e8: jg     457 <generic_kprobe_process_event+0x457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_457;
	}
x86_l_2ee:
	/* 0x2ee: lea    eax,[r13-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_2f2:
	/* 0x2f2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f5:
	/* 0x2f5: jb     41d <generic_kprobe_process_event+0x41d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_41d;
	}
x86_l_2fb:
	/* 0x2fb: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2ff:
	/* 0x2ff: je     41d <generic_kprobe_process_event+0x41d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41d;
	}
x86_l_305:
	/* 0x305: jmp    489 <generic_kprobe_process_event+0x489> */
	goto x86_l_489;
x86_l_30a:
	/* 0x30a: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_30e:
	/* 0x30e: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_313:
	/* 0x313: jle    36e <generic_kprobe_process_event+0x36e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_36e;
	}
x86_l_315:
	/* 0x315: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_319:
	/* 0x319: jg     39b <generic_kprobe_process_event+0x39b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_39b;
	}
x86_l_31f:
	/* 0x31f: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_323:
	/* 0x323: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_326:
	/* 0x326: jb     46b <generic_kprobe_process_event+0x46b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_46b;
	}
x86_l_32c:
	/* 0x32c: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_330:
	/* 0x330: je     48c <generic_kprobe_process_event+0x48c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48c;
	}
x86_l_336:
	/* 0x336: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_33a:
	/* 0x33a: je     425 <generic_kprobe_process_event+0x425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_425;
	}
x86_l_340:
	/* 0x340: jmp    489 <generic_kprobe_process_event+0x489> */
	goto x86_l_489;
x86_l_345:
	/* 0x345: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_349:
	/* 0x349: jg     3f7 <generic_kprobe_process_event+0x3f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3f7;
	}
x86_l_34f:
	/* 0x34f: lea    eax,[r13-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_353:
	/* 0x353: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_356:
	/* 0x356: jb     48c <generic_kprobe_process_event+0x48c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_48c;
	}
x86_l_35c:
	/* 0x35c: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_360:
	/* 0x360: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_363:
	/* 0x363: jb     41d <generic_kprobe_process_event+0x41d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_41d;
	}
x86_l_369:
	/* 0x369: jmp    489 <generic_kprobe_process_event+0x489> */
	goto x86_l_489;
x86_l_36e:
	/* 0x36e: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_372:
	/* 0x372: jg     414 <generic_kprobe_process_event+0x414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_414;
	}
x86_l_378:
	/* 0x378: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_37c:
	/* 0x37c: je     425 <generic_kprobe_process_event+0x425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_425;
	}
x86_l_382:
	/* 0x382: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_386:
	/* 0x386: je     46b <generic_kprobe_process_event+0x46b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46b;
	}
x86_l_38c:
	/* 0x38c: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_390:
	/* 0x390: je     481 <generic_kprobe_process_event+0x481> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_481;
	}
x86_l_396:
	/* 0x396: jmp    489 <generic_kprobe_process_event+0x489> */
	goto x86_l_489;
x86_l_39b:
	/* 0x39b: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_39f:
	/* 0x39f: jle    441 <generic_kprobe_process_event+0x441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_441;
	}
x86_l_3a5:
	/* 0x3a5: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_3a9:
	/* 0x3a9: je     48c <generic_kprobe_process_event+0x48c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48c;
	}
x86_l_3af:
	/* 0x3af: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_3b3:
	/* 0x3b3: je     44f <generic_kprobe_process_event+0x44f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44f;
	}
x86_l_3b9:
	/* 0x3b9: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_3bd:
	/* 0x3bd: jne    489 <generic_kprobe_process_event+0x489> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_489;
	}
x86_l_3c3:
	/* 0x3c3: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_3c9:
	/* 0x3c9: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_3ce:
	/* 0x3ce: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_3d2:
	/* 0x3d2: jg     46b <generic_kprobe_process_event+0x46b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_46b;
	}
x86_l_3d8:
	/* 0x3d8: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_3dc:
	/* 0x3dc: je     48c <generic_kprobe_process_event+0x48c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48c;
	}
x86_l_3e2:
	/* 0x3e2: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_3e6:
	/* 0x3e6: je     463 <generic_kprobe_process_event+0x463> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_463;
	}
x86_l_3e8:
	/* 0x3e8: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3ec:
	/* 0x3ec: je     481 <generic_kprobe_process_event+0x481> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_481;
	}
x86_l_3f2:
	/* 0x3f2: jmp    489 <generic_kprobe_process_event+0x489> */
	goto x86_l_489;
x86_l_3f7:
	/* 0x3f7: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_3fb:
	/* 0x3fb: jg     42d <generic_kprobe_process_event+0x42d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_42d;
	}
x86_l_3fd:
	/* 0x3fd: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_402:
	/* 0x402: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_406:
	/* 0x406: je     48c <generic_kprobe_process_event+0x48c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48c;
	}
x86_l_40c:
	/* 0x40c: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_410:
	/* 0x410: je     44f <generic_kprobe_process_event+0x44f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44f;
	}
x86_l_412:
	/* 0x412: jmp    489 <generic_kprobe_process_event+0x489> */
	goto x86_l_489;
x86_l_414:
	/* 0x414: lea    eax,[r13-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_418:
	/* 0x418: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41b:
	/* 0x41b: jae    47b <generic_kprobe_process_event+0x47b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_47b;
	}
x86_l_41d:
	/* 0x41d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_423:
	/* 0x423: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_425:
	/* 0x425: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_42b:
	/* 0x42b: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_42d:
	/* 0x42d: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_431:
	/* 0x431: je     473 <generic_kprobe_process_event+0x473> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_473;
	}
x86_l_433:
	/* 0x433: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_437:
	/* 0x437: jne    489 <generic_kprobe_process_event+0x489> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_489;
	}
x86_l_439:
	/* 0x439: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_43f:
	/* 0x43f: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_441:
	/* 0x441: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_445:
	/* 0x445: je     44f <generic_kprobe_process_event+0x44f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44f;
	}
x86_l_447:
	/* 0x447: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_44b:
	/* 0x44b: je     463 <generic_kprobe_process_event+0x463> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_463;
	}
x86_l_44d:
	/* 0x44d: jmp    489 <generic_kprobe_process_event+0x489> */
	goto x86_l_489;
x86_l_44f:
	/* 0x44f: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_455:
	/* 0x455: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_457:
	/* 0x457: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_45b:
	/* 0x45b: je     46b <generic_kprobe_process_event+0x46b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46b;
	}
x86_l_45d:
	/* 0x45d: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_461:
	/* 0x461: jne    489 <generic_kprobe_process_event+0x489> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_489;
	}
x86_l_463:
	/* 0x463: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_469:
	/* 0x469: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_46b:
	/* 0x46b: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_471:
	/* 0x471: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_473:
	/* 0x473: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_479:
	/* 0x479: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_47b:
	/* 0x47b: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_47f:
	/* 0x47f: jne    489 <generic_kprobe_process_event+0x489> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_489;
	}
x86_l_481:
	/* 0x481: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_487:
	/* 0x487: jmp    48c <generic_kprobe_process_event+0x48c> */
	goto x86_l_48c;
x86_l_489:
	/* 0x489: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48c:
	/* 0x48c: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_491:
	/* 0x491: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_49c:
	/* 0x49c: mov    rdi,QWORD PTR [rip+0x253] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_4a3:
	/* 0x4a3: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_4ab:
	/* 0x4ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b0:
	/* 0x4b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b2:
	/* 0x4b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b5:
	/* 0x4b5: je     d2f <generic_kprobe_process_event+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3375ULL;
	}
x86_l_4bb:
	/* 0x4bb: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_4c0:
	/* 0x4c0: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4c3:
	/* 0x4c3: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_4c6:
	/* 0x4c6: jbe    d2f <generic_kprobe_process_event+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3375ULL;
	}
x86_l_4cc:
	/* 0x4cc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d0:
	/* 0x4d0: mov    ecx,DWORD PTR [rax+rdx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_4d7:
	/* 0x4d7: mov    DWORD PTR [rax+rbp*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_4de:
	/* 0x4de: lea    r15,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e2:
	/* 0x4e2: mov    QWORD PTR [rax+rdx*8+0x5e78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_4ea:
	/* 0x4ea: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4ef:
	/* 0x4ef: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4f1:
	/* 0x4f1: jne    d2b <generic_kprobe_process_event+0xd2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3371ULL;
	}
x86_l_4f7:
	/* 0x4f7: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_4fa:
	/* 0x4fa: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_501:
	/* 0x501: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_508:
	/* 0x508: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50b:
	/* 0x50b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_510:
	/* 0x510: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_515:
	/* 0x515: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_521:
	/* 0x521: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_525:
	/* 0x525: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52a:
	/* 0x52a: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_52f:
	/* 0x52f: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_534:
	/* 0x534: jle    571 <generic_kprobe_process_event+0x571> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_571;
	}
x86_l_536:
	/* 0x536: cmp    r13d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 24ULL);
x86_l_53a:
	/* 0x53a: je     58c <generic_kprobe_process_event+0x58c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58c;
	}
x86_l_53c:
	/* 0x53c: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_540:
	/* 0x540: je     5ca <generic_kprobe_process_event+0x5ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ca;
	}
x86_l_546:
	/* 0x546: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_54a:
	/* 0x54a: jne    aff <generic_kprobe_process_event+0xaff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2815ULL;
	}
x86_l_550:
	/* 0x550: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_55c:
	/* 0x55c: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_564:
	/* 0x564: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_56c:
	/* 0x56c: jmp    5f7 <generic_kprobe_process_event+0x5f7> */
	goto x86_l_5f7;
x86_l_571:
	/* 0x571: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_575:
	/* 0x575: je     a22 <generic_kprobe_process_event+0xa22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2594ULL;
	}
x86_l_57b:
	/* 0x57b: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_57f:
	/* 0x57f: jne    aff <generic_kprobe_process_event+0xaff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2815ULL;
	}
x86_l_585:
	/* 0x585: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_58a:
	/* 0x58a: jmp    5b4 <generic_kprobe_process_event+0x5b4> */
	goto x86_l_5b4;
x86_l_58c:
	/* 0x58c: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_591:
	/* 0x591: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_596:
	/* 0x596: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_59b:
	/* 0x59b: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5a0:
	/* 0x5a0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5a3:
	/* 0x5a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a8:
	/* 0x5a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aa:
	/* 0x5aa: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5af:
	/* 0x5af: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5b4:
	/* 0x5b4: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5b9:
	/* 0x5b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5be:
	/* 0x5be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5c3:
	/* 0x5c3: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5c8:
	/* 0x5c8: jmp    5e7 <generic_kprobe_process_event+0x5e7> */
	goto x86_l_5e7;
x86_l_5ca:
	/* 0x5ca: add    rdx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_5ce:
	/* 0x5ce: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5d3:
	/* 0x5d3: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5d8:
	/* 0x5d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5dd:
	/* 0x5dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e2:
	/* 0x5e2: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5e7:
	/* 0x5e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ec:
	/* 0x5ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ee:
	/* 0x5ee: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5f3:
	/* 0x5f3: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_5f7:
	/* 0x5f7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5fc:
	/* 0x5fc: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_607:
	/* 0x607: mov    rdi,QWORD PTR [rip+0x253] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_60e:
	/* 0x60e: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_616:
	/* 0x616: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_61b:
	/* 0x61b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61d:
	/* 0x61d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_620:
	/* 0x620: je     6c9 <generic_kprobe_process_event+0x6c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1737ULL;
	}
x86_l_626:
	/* 0x626: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_629:
	/* 0x629: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62e:
	/* 0x62e: lea    rbx,[rax+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_635:
	/* 0x635: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_63a:
	/* 0x63a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63c:
	/* 0x63c: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_643:
	/* 0x643: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_64b:
	/* 0x64b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_650:
	/* 0x650: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_655:
	/* 0x655: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65a:
	/* 0x65a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65c:
	/* 0x65c: mov    r12,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_664:
	/* 0x664: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_669:
	/* 0x669: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66d:
	/* 0x66d: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_675:
	/* 0x675: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_67a:
	/* 0x67a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_67f:
	/* 0x67f: lea    rcx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_684:
	/* 0x684: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_689:
	/* 0x689: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68e:
	/* 0x68e: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_693:
	/* 0x693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_695:
	/* 0x695: mov    r15,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_69d:
	/* 0x69d: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a1:
	/* 0x6a1: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6a6:
	/* 0x6a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6ab:
	/* 0x6ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b0:
	/* 0x6b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b5:
	/* 0x6b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b7:
	/* 0x6b7: cmp    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6bd:
	/* 0x6bd: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_6c2:
	/* 0x6c2: je     6d6 <generic_kprobe_process_event+0x6d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1750ULL;
	}
x86_l_6c4:
	/* 0x6c4: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_6c7:
	/* 0x6c7: jmp    724 <generic_kprobe_process_event+0x724> */
	return 1828ULL;
	return 1737ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1754ULL: goto x86_l_6da;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1784ULL: goto x86_l_6f8;
	case 1786ULL: goto x86_l_6fa;
	case 1789ULL: goto x86_l_6fd;
	case 1796ULL: goto x86_l_704;
	case 1806ULL: goto x86_l_70e;
	case 1813ULL: goto x86_l_715;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1837ULL: goto x86_l_72d;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1863ULL: goto x86_l_747;
	case 1875ULL: goto x86_l_753;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1900ULL: goto x86_l_76c;
	case 1907ULL: goto x86_l_773;
	case 1915ULL: goto x86_l_77b;
	case 1919ULL: goto x86_l_77f;
	case 1924ULL: goto x86_l_784;
	case 1929ULL: goto x86_l_789;
	case 1934ULL: goto x86_l_78e;
	case 1939ULL: goto x86_l_793;
	case 1947ULL: goto x86_l_79b;
	case 1955ULL: goto x86_l_7a3;
	case 1960ULL: goto x86_l_7a8;
	case 1963ULL: goto x86_l_7ab;
	case 1965ULL: goto x86_l_7ad;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2048ULL: goto x86_l_800;
	case 2052ULL: goto x86_l_804;
	case 2060ULL: goto x86_l_80c;
	case 2067ULL: goto x86_l_813;
	case 2070ULL: goto x86_l_816;
	case 2076ULL: goto x86_l_81c;
	case 2081ULL: goto x86_l_821;
	case 2087ULL: goto x86_l_827;
	case 2092ULL: goto x86_l_82c;
	case 2100ULL: goto x86_l_834;
	case 2108ULL: goto x86_l_83c;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2147ULL: goto x86_l_863;
	case 2152ULL: goto x86_l_868;
	case 2154ULL: goto x86_l_86a;
	case 2162ULL: goto x86_l_872;
	case 2168ULL: goto x86_l_878;
	case 2172ULL: goto x86_l_87c;
	case 2177ULL: goto x86_l_881;
	case 2182ULL: goto x86_l_886;
	case 2187ULL: goto x86_l_88b;
	case 2190ULL: goto x86_l_88e;
	case 2192ULL: goto x86_l_890;
	case 2197ULL: goto x86_l_895;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2227ULL: goto x86_l_8b3;
	case 2232ULL: goto x86_l_8b8;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2253ULL: goto x86_l_8cd;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2268ULL: goto x86_l_8dc;
	case 2276ULL: goto x86_l_8e4;
	case 2279ULL: goto x86_l_8e7;
	case 2287ULL: goto x86_l_8ef;
	case 2290ULL: goto x86_l_8f2;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2301ULL: goto x86_l_8fd;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2314ULL: goto x86_l_90a;
	case 2318ULL: goto x86_l_90e;
	case 2321ULL: goto x86_l_911;
	case 2325ULL: goto x86_l_915;
	case 2327ULL: goto x86_l_917;
	case 2330ULL: goto x86_l_91a;
	case 2332ULL: goto x86_l_91c;
	case 2339ULL: goto x86_l_923;
	case 2342ULL: goto x86_l_926;
	case 2348ULL: goto x86_l_92c;
	case 2354ULL: goto x86_l_932;
	case 2360ULL: goto x86_l_938;
	case 2363ULL: goto x86_l_93b;
	case 2365ULL: goto x86_l_93d;
	case 2370ULL: goto x86_l_942;
	case 2372ULL: goto x86_l_944;
	case 2375ULL: goto x86_l_947;
	case 2379ULL: goto x86_l_94b;
	case 2382ULL: goto x86_l_94e;
	case 2385ULL: goto x86_l_951;
	case 2388ULL: goto x86_l_954;
	case 2393ULL: goto x86_l_959;
	case 2395ULL: goto x86_l_95b;
	case 2403ULL: goto x86_l_963;
	case 2406ULL: goto x86_l_966;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2425ULL: goto x86_l_979;
	case 2431ULL: goto x86_l_97f;
	case 2433ULL: goto x86_l_981;
	case 2439ULL: goto x86_l_987;
	case 2444ULL: goto x86_l_98c;
	case 2449ULL: goto x86_l_991;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2466ULL: goto x86_l_9a2;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2485ULL: goto x86_l_9b5;
	case 2491ULL: goto x86_l_9bb;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2508ULL: goto x86_l_9cc;
	case 2513ULL: goto x86_l_9d1;
	case 2516ULL: goto x86_l_9d4;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2531ULL: goto x86_l_9e3;
	case 2535ULL: goto x86_l_9e7;
	case 2543ULL: goto x86_l_9ef;
	case 2545ULL: goto x86_l_9f1;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2563ULL: goto x86_l_a03;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2587ULL: goto x86_l_a1b;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2602ULL: goto x86_l_a2a;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2624ULL: goto x86_l_a40;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2640ULL: goto x86_l_a50;
	case 2646ULL: goto x86_l_a56;
	case 2657ULL: goto x86_l_a61;
	case 2664ULL: goto x86_l_a68;
	case 2672ULL: goto x86_l_a70;
	case 2677ULL: goto x86_l_a75;
	case 2679ULL: goto x86_l_a77;
	case 2682ULL: goto x86_l_a7a;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2701ULL: goto x86_l_a8d;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2715ULL: goto x86_l_a9b;
	case 2721ULL: goto x86_l_aa1;
	case 2725ULL: goto x86_l_aa5;
	case 2731ULL: goto x86_l_aab;
	case 2735ULL: goto x86_l_aaf;
	case 2741ULL: goto x86_l_ab5;
	case 2745ULL: goto x86_l_ab9;
	case 2751ULL: goto x86_l_abf;
	case 2755ULL: goto x86_l_ac3;
	case 2761ULL: goto x86_l_ac9;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2775ULL: goto x86_l_ad7;
	case 2779ULL: goto x86_l_adb;
	case 2784ULL: goto x86_l_ae0;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2802ULL: goto x86_l_af2;
	case 2804ULL: goto x86_l_af4;
	case 2810ULL: goto x86_l_afa;
	case 2815ULL: goto x86_l_aff;
	case 2819ULL: goto x86_l_b03;
	case 2825ULL: goto x86_l_b09;
	case 2828ULL: goto x86_l_b0c;
	case 2838ULL: goto x86_l_b16;
	case 2842ULL: goto x86_l_b1a;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2864ULL: goto x86_l_b30;
	case 2871ULL: goto x86_l_b37;
	case 2879ULL: goto x86_l_b3f;
	case 2884ULL: goto x86_l_b44;
	case 2886ULL: goto x86_l_b46;
	case 2889ULL: goto x86_l_b49;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2908ULL: goto x86_l_b5c;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2923ULL: goto x86_l_b6b;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2943ULL: goto x86_l_b7f;
	case 2947ULL: goto x86_l_b83;
	case 2953ULL: goto x86_l_b89;
	case 2957ULL: goto x86_l_b8d;
	case 2960ULL: goto x86_l_b90;
	case 2966ULL: goto x86_l_b96;
	case 2971ULL: goto x86_l_b9b;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3017ULL: goto x86_l_bc9;
	case 3025ULL: goto x86_l_bd1;
	case 3030ULL: goto x86_l_bd6;
	case 3032ULL: goto x86_l_bd8;
	case 3035ULL: goto x86_l_bdb;
	case 3037ULL: goto x86_l_bdd;
	case 3045ULL: goto x86_l_be5;
	case 3048ULL: goto x86_l_be8;
	case 3055ULL: goto x86_l_bef;
	case 3061ULL: goto x86_l_bf5;
	case 3064ULL: goto x86_l_bf8;
	case 3066ULL: goto x86_l_bfa;
	case 3070ULL: goto x86_l_bfe;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3084ULL: goto x86_l_c0c;
	case 3087ULL: goto x86_l_c0f;
	case 3089ULL: goto x86_l_c11;
	case 3092ULL: goto x86_l_c14;
	case 3094ULL: goto x86_l_c16;
	case 3097ULL: goto x86_l_c19;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3116ULL: goto x86_l_c2c;
	case 3123ULL: goto x86_l_c33;
	case 3128ULL: goto x86_l_c38;
	case 3131ULL: goto x86_l_c3b;
	case 3133ULL: goto x86_l_c3d;
	case 3137ULL: goto x86_l_c41;
	case 3142ULL: goto x86_l_c46;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3162ULL: goto x86_l_c5a;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3173ULL: goto x86_l_c65;
	case 3181ULL: goto x86_l_c6d;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3196ULL: goto x86_l_c7c;
	case 3200ULL: goto x86_l_c80;
	case 3205ULL: goto x86_l_c85;
	case 3207ULL: goto x86_l_c87;
	case 3215ULL: goto x86_l_c8f;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3238ULL: goto x86_l_ca6;
	case 3243ULL: goto x86_l_cab;
	case 3245ULL: goto x86_l_cad;
	case 3250ULL: goto x86_l_cb2;
	case 3255ULL: goto x86_l_cb7;
	case 3261ULL: goto x86_l_cbd;
	case 3265ULL: goto x86_l_cc1;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3279ULL: goto x86_l_ccf;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3289ULL: goto x86_l_cd9;
	case 3294ULL: goto x86_l_cde;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3309ULL: goto x86_l_ced;
	case 3314ULL: goto x86_l_cf2;
	case 3318ULL: goto x86_l_cf6;
	case 3323ULL: goto x86_l_cfb;
	case 3326ULL: goto x86_l_cfe;
	case 3328ULL: goto x86_l_d00;
	case 3335ULL: goto x86_l_d07;
	case 3339ULL: goto x86_l_d0b;
	case 3342ULL: goto x86_l_d0e;
	case 3344ULL: goto x86_l_d10;
	case 3355ULL: goto x86_l_d1b;
	case 3366ULL: goto x86_l_d26;
	case 3371ULL: goto x86_l_d2b;
	case 3373ULL: goto x86_l_d2d;
	case 3375ULL: goto x86_l_d2f;
	case 3379ULL: goto x86_l_d33;
	case 3382ULL: goto x86_l_d36;
	case 3384ULL: goto x86_l_d38;
	case 3392ULL: goto x86_l_d40;
	case 3399ULL: goto x86_l_d47;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3411ULL: goto x86_l_d53;
	case 3414ULL: goto x86_l_d56;
	case 3416ULL: goto x86_l_d58;
	case 3419ULL: goto x86_l_d5b;
	case 3426ULL: goto x86_l_d62;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3440ULL: goto x86_l_d70;
	case 3443ULL: goto x86_l_d73;
	case 3445ULL: goto x86_l_d75;
	case 3447ULL: goto x86_l_d77;
	case 3449ULL: goto x86_l_d79;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3459ULL: goto x86_l_d83;
	case 3466ULL: goto x86_l_d8a;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3493ULL: goto x86_l_da5;
	case 3504ULL: goto x86_l_db0;
	case 3511ULL: goto x86_l_db7;
	case 3516ULL: goto x86_l_dbc;
	case 3521ULL: goto x86_l_dc1;
	case 3524ULL: goto x86_l_dc4;
	case 3529ULL: goto x86_l_dc9;
	case 3531ULL: goto x86_l_dcb;
	case 3533ULL: goto x86_l_dcd;
	case 3540ULL: goto x86_l_dd4;
	case 3542ULL: goto x86_l_dd6;
	case 3543ULL: goto x86_l_dd7;
	case 3548ULL: goto x86_l_ddc;
	case 3552ULL: goto x86_l_de0;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3566ULL: goto x86_l_dee;
	case 3572ULL: goto x86_l_df4;
	case 3576ULL: goto x86_l_df8;
	case 3582ULL: goto x86_l_dfe;
	case 3586ULL: goto x86_l_e02;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c9:
	/* 0x6c9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6cc:
	/* 0x6cc: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d1:
	/* 0x6d1: jmp    cd4 <generic_kprobe_process_event+0xcd4> */
	goto x86_l_cd4;
x86_l_6d6:
	/* 0x6d6: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6da:
	/* 0x6da: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6df:
	/* 0x6df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6e4:
	/* 0x6e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6e9:
	/* 0x6e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ee:
	/* 0x6ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f0:
	/* 0x6f0: cmp    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6f5:
	/* 0x6f5: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_6f8:
	/* 0x6f8: je     724 <generic_kprobe_process_event+0x724> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_724;
	}
x86_l_6fa:
	/* 0x6fa: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_6fd:
	/* 0x6fd: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_704:
	/* 0x704: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_70e:
	/* 0x70e: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_715:
	/* 0x715: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_71f:
	/* 0x71f: mov    ebp,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4086ULL);
x86_l_724:
	/* 0x724: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_72d:
	/* 0x72d: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_736:
	/* 0x736: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_73b:
	/* 0x73b: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_747:
	/* 0x747: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_753:
	/* 0x753: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_75f:
	/* 0x75f: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_764:
	/* 0x764: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_76c:
	/* 0x76c: mov    DWORD PTR [rsp+0xa0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_773:
	/* 0x773: mov    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_77b:
	/* 0x77b: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_77f:
	/* 0x77f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_784:
	/* 0x784: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_789:
	/* 0x789: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_78e:
	/* 0x78e: lea    r13,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_793:
	/* 0x793: lea    rbx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_79b:
	/* 0x79b: lea    r15,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7a3:
	/* 0x7a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a8:
	/* 0x7a8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7ab:
	/* 0x7ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ad:
	/* 0x7ad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7b2:
	/* 0x7b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7b7:
	/* 0x7b7: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7bc:
	/* 0x7bc: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_7bf:
	/* 0x7bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7c4:
	/* 0x7c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c6:
	/* 0x7c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7cb:
	/* 0x7cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7d0:
	/* 0x7d0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7d5:
	/* 0x7d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7d8:
	/* 0x7d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7dd:
	/* 0x7dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7df:
	/* 0x7df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7e4:
	/* 0x7e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7e9:
	/* 0x7e9: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7ee:
	/* 0x7ee: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7f1:
	/* 0x7f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f6:
	/* 0x7f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f8:
	/* 0x7f8: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_800:
	/* 0x800: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_804:
	/* 0x804: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_80c:
	/* 0x80c: mov    rax,QWORD PTR [rip+0x253] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_813:
	/* 0x813: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_816:
	/* 0x816: je     9fc <generic_kprobe_process_event+0x9fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9fc;
	}
x86_l_81c:
	/* 0x81c: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_821:
	/* 0x821: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_827:
	/* 0x827: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_82c:
	/* 0x82c: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_834:
	/* 0x834: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_83c:
	/* 0x83c: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_844:
	/* 0x844: cmp    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_849:
	/* 0x849: jne    856 <generic_kprobe_process_event+0x856> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_856;
	}
x86_l_84b:
	/* 0x84b: cmp    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_850:
	/* 0x850: je     bc1 <generic_kprobe_process_event+0xbc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc1;
	}
x86_l_856:
	/* 0x856: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_85b:
	/* 0x85b: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_863:
	/* 0x863: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_868:
	/* 0x868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86a:
	/* 0x86a: cmp    r13,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 224ULL);
x86_l_872:
	/* 0x872: je     98c <generic_kprobe_process_event+0x98c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98c;
	}
x86_l_878:
	/* 0x878: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_87c:
	/* 0x87c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_881:
	/* 0x881: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_886:
	/* 0x886: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_88b:
	/* 0x88b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_88e:
	/* 0x88e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_890:
	/* 0x890: cmp    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_895:
	/* 0x895: je     98c <generic_kprobe_process_event+0x98c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98c;
	}
x86_l_89b:
	/* 0x89b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8a0:
	/* 0x8a0: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8a5:
	/* 0x8a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8aa:
	/* 0x8aa: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8ad:
	/* 0x8ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8af:
	/* 0x8af: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_8b3:
	/* 0x8b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8b8:
	/* 0x8b8: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_8c0:
	/* 0x8c0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_8c5:
	/* 0x8c5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_8ca:
	/* 0x8ca: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8cd:
	/* 0x8cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8cf:
	/* 0x8cf: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8d4:
	/* 0x8d4: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8dc:
	/* 0x8dc: mov    r12d,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_8e4:
	/* 0x8e4: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8e7:
	/* 0x8e7: mov    r13d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8ef:
	/* 0x8ef: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_8f2:
	/* 0x8f2: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8f5:
	/* 0x8f5: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_8fa:
	/* 0x8fa: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_8fd:
	/* 0x8fd: add    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 176ULL);
x86_l_905:
	/* 0x905: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_907:
	/* 0x907: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_90a:
	/* 0x90a: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_90e:
	/* 0x90e: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_911:
	/* 0x911: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_915:
	/* 0x915: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_917:
	/* 0x917: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_91a:
	/* 0x91a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_91c:
	/* 0x91c: mov    DWORD PTR [rsp+0xa0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_923:
	/* 0x923: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_926:
	/* 0x926: jb     bc9 <generic_kprobe_process_event+0xbc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_bc9;
	}
x86_l_92c:
	/* 0x92c: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_932:
	/* 0x932: ja     bc9 <generic_kprobe_process_event+0xbc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bc9;
	}
x86_l_938:
	/* 0x938: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_93b:
	/* 0x93b: jbe    942 <generic_kprobe_process_event+0x942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_942;
	}
x86_l_93d:
	/* 0x93d: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_942:
	/* 0x942: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_944:
	/* 0x944: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_947:
	/* 0x947: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_94b:
	/* 0x94b: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_94e:
	/* 0x94e: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_951:
	/* 0x951: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_954:
	/* 0x954: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_959:
	/* 0x959: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95b:
	/* 0x95b: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_963:
	/* 0x963: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_966:
	/* 0x966: jbe    bc9 <generic_kprobe_process_event+0xbc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_bc9;
	}
x86_l_96c:
	/* 0x96c: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_971:
	/* 0x971: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_979:
	/* 0x979: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_97f:
	/* 0x97f: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_981:
	/* 0x981: jne    82c <generic_kprobe_process_event+0x82c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_82c;
	}
x86_l_987:
	/* 0x987: jmp    bc9 <generic_kprobe_process_event+0xbc9> */
	goto x86_l_bc9;
x86_l_98c:
	/* 0x98c: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_991:
	/* 0x991: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_996:
	/* 0x996: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_99b:
	/* 0x99b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a0:
	/* 0x9a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a2:
	/* 0x9a2: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9aa:
	/* 0x9aa: cmp    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 88ULL);
x86_l_9af:
	/* 0x9af: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_9b5:
	/* 0x9b5: je     bc1 <generic_kprobe_process_event+0xbc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc1;
	}
x86_l_9bb:
	/* 0x9bb: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_9bf:
	/* 0x9bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9c4:
	/* 0x9c4: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9cc:
	/* 0x9cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d1:
	/* 0x9d1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_9d4:
	/* 0x9d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d6:
	/* 0x9d6: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9db:
	/* 0x9db: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9e3:
	/* 0x9e3: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_9e7:
	/* 0x9e7: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9ef:
	/* 0x9ef: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_9f1:
	/* 0x9f1: jne    82c <generic_kprobe_process_event+0x82c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_82c;
	}
x86_l_9f7:
	/* 0x9f7: jmp    bc9 <generic_kprobe_process_event+0xbc9> */
	goto x86_l_bc9;
x86_l_9fc:
	/* 0x9fc: lea    rsi,[rip+0x253] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 595ULL);
x86_l_a03:
	/* 0xa03: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a05:
	/* 0xa05: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a0a:
	/* 0xa0a: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_a0f:
	/* 0xa0f: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_a14:
	/* 0xa14: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_a19:
	/* 0xa19: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a1b:
	/* 0xa1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1d:
	/* 0xa1d: jmp    bc9 <generic_kprobe_process_event+0xbc9> */
	goto x86_l_bc9;
x86_l_a22:
	/* 0xa22: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a2a:
	/* 0xa2a: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a2f:
	/* 0xa2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a34:
	/* 0xa34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a39:
	/* 0xa39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a3e:
	/* 0xa3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a40:
	/* 0xa40: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a48:
	/* 0xa48: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a4d:
	/* 0xa4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a50:
	/* 0xa50: jne    5fc <generic_kprobe_process_event+0x5fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1532ULL;
	}
x86_l_a56:
	/* 0xa56: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_a61:
	/* 0xa61: mov    rdi,QWORD PTR [rip+0x253] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a68:
	/* 0xa68: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_a70:
	/* 0xa70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a75:
	/* 0xa75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a77:
	/* 0xa77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7a:
	/* 0xa7a: je     f47 <generic_kprobe_process_event+0xf47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3911ULL;
	}
x86_l_a80:
	/* 0xa80: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a85:
	/* 0xa85: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a8a:
	/* 0xa8a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a8d:
	/* 0xa8d: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_a91:
	/* 0xa91: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a96:
	/* 0xa96: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a9b:
	/* 0xa9b: jg     1016 <generic_kprobe_process_event+0x1016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4118ULL;
	}
x86_l_aa1:
	/* 0xaa1: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_aa5:
	/* 0xaa5: jle    1186 <generic_kprobe_process_event+0x1186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4486ULL;
	}
x86_l_aab:
	/* 0xaab: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_aaf:
	/* 0xaaf: jle    152d <generic_kprobe_process_event+0x152d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5421ULL;
	}
x86_l_ab5:
	/* 0xab5: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_ab9:
	/* 0xab9: je     1da9 <generic_kprobe_process_event+0x1da9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7593ULL;
	}
x86_l_abf:
	/* 0xabf: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_ac3:
	/* 0xac3: je     1d1f <generic_kprobe_process_event+0x1d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7455ULL;
	}
x86_l_ac9:
	/* 0xac9: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_acd:
	/* 0xacd: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ad2:
	/* 0xad2: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ad7:
	/* 0xad7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_adb:
	/* 0xadb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ae0:
	/* 0xae0: jne    cfb <generic_kprobe_process_event+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cfb;
	}
x86_l_ae6:
	/* 0xae6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aeb:
	/* 0xaeb: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_af2:
	/* 0xaf2: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af4:
	/* 0xaf4: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_afa:
	/* 0xafa: jmp    cfb <generic_kprobe_process_event+0xcfb> */
	goto x86_l_cfb;
x86_l_aff:
	/* 0xaff: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_b03:
	/* 0xb03: ja     a56 <generic_kprobe_process_event+0xa56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a56;
	}
x86_l_b09:
	/* 0xb09: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_b0c:
	/* 0xb0c: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_b16:
	/* 0xb16: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_b1a:
	/* 0xb1a: jae    a56 <generic_kprobe_process_event+0xa56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a56;
	}
x86_l_b20:
	/* 0xb20: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b25:
	/* 0xb25: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_b30:
	/* 0xb30: mov    rdi,QWORD PTR [rip+0x253] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_b37:
	/* 0xb37: lea    rsi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_b3f:
	/* 0xb3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b44:
	/* 0xb44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b46:
	/* 0xb46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b49:
	/* 0xb49: je     ce0 <generic_kprobe_process_event+0xce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ce0;
	}
x86_l_b4f:
	/* 0xb4f: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b54:
	/* 0xb54: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b59:
	/* 0xb59: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b5c:
	/* 0xb5c: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_b60:
	/* 0xb60: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b65:
	/* 0xb65: jle    ddc <generic_kprobe_process_event+0xddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_ddc;
	}
x86_l_b6b:
	/* 0xb6b: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_b6f:
	/* 0xb6f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b74:
	/* 0xb74: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b79:
	/* 0xb79: jle    f5e <generic_kprobe_process_event+0xf5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3934ULL;
	}
x86_l_b7f:
	/* 0xb7f: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_b83:
	/* 0xb83: jg     1063 <generic_kprobe_process_event+0x1063> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4195ULL;
	}
x86_l_b89:
	/* 0xb89: lea    eax,[r13-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_b8d:
	/* 0xb8d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b90:
	/* 0xb90: jae    1625 <generic_kprobe_process_event+0x1625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5669ULL;
	}
x86_l_b96:
	/* 0xb96: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b9b:
	/* 0xb9b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_ba1:
	/* 0xba1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ba6:
	/* 0xba6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bab:
	/* 0xbab: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb0:
	/* 0xbb0: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_bb5:
	/* 0xbb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb7:
	/* 0xbb7: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bbc:
	/* 0xbbc: jmp    cf2 <generic_kprobe_process_event+0xcf2> */
	goto x86_l_cf2;
x86_l_bc1:
	/* 0xbc1: mov    BYTE PTR [rsp+0xa4],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636545ULL);
x86_l_bc9:
	/* 0xbc9: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_bd1:
	/* 0xbd1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bd6:
	/* 0xbd6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd8:
	/* 0xbd8: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_bdb:
	/* 0xbdb: je     c16 <generic_kprobe_process_event+0xc16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c16;
	}
x86_l_bdd:
	/* 0xbdd: cmp    BYTE PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_be5:
	/* 0xbe5: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_be8:
	/* 0xbe8: mov    edx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_bef:
	/* 0xbef: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_bf5:
	/* 0xbf5: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_bf8:
	/* 0xbf8: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_bfa:
	/* 0xbfa: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_bfe:
	/* 0xbfe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c01:
	/* 0xc01: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c06:
	/* 0xc06: je     cd1 <generic_kprobe_process_event+0xcd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd1;
	}
x86_l_c0c:
	/* 0xc0c: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_c0f:
	/* 0xc0f: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c11:
	/* 0xc11: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c14:
	/* 0xc14: jmp    c1e <generic_kprobe_process_event+0xc1e> */
	goto x86_l_c1e;
x86_l_c16:
	/* 0xc16: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c19:
	/* 0xc19: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c1e:
	/* 0xc1e: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c23:
	/* 0xc23: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c28:
	/* 0xc28: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c2c:
	/* 0xc2c: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c33:
	/* 0xc33: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c38:
	/* 0xc38: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_c3b:
	/* 0xc3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3d:
	/* 0xc3d: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c41:
	/* 0xc41: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c46:
	/* 0xc46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c4b:
	/* 0xc4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c50:
	/* 0xc50: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c55:
	/* 0xc55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c5a:
	/* 0xc5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5c:
	/* 0xc5c: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c61:
	/* 0xc61: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_c65:
	/* 0xc65: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c6d:
	/* 0xc6d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c72:
	/* 0xc72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c77:
	/* 0xc77: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c7c:
	/* 0xc7c: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_c80:
	/* 0xc80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c85:
	/* 0xc85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c87:
	/* 0xc87: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c8f:
	/* 0xc8f: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c94:
	/* 0xc94: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_c99:
	/* 0xc99: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c9e:
	/* 0xc9e: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ca6:
	/* 0xca6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_cab:
	/* 0xcab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cad:
	/* 0xcad: mov    DWORD PTR [r13+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_cb2:
	/* 0xcb2: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_cb7:
	/* 0xcb7: mov    WORD PTR [r13+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_cbd:
	/* 0xcbd: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_cc1:
	/* 0xcc1: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc6:
	/* 0xcc6: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ccb:
	/* 0xccb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ccf:
	/* 0xccf: jmp    cfb <generic_kprobe_process_event+0xcfb> */
	goto x86_l_cfb;
x86_l_cd1:
	/* 0xcd1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd4:
	/* 0xcd4: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cd9:
	/* 0xcd9: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cde:
	/* 0xcde: jmp    d00 <generic_kprobe_process_event+0xd00> */
	goto x86_l_d00;
x86_l_ce0:
	/* 0xce0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce3:
	/* 0xce3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce8:
	/* 0xce8: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ced:
	/* 0xced: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cf2:
	/* 0xcf2: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf6:
	/* 0xcf6: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cfb:
	/* 0xcfb: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_cfe:
	/* 0xcfe: js     d10 <generic_kprobe_process_event+0xd10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_d10;
	}
x86_l_d00:
	/* 0xd00: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_d07:
	/* 0xd07: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_d0b:
	/* 0xd0b: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_d0e:
	/* 0xd0e: jmp    d2b <generic_kprobe_process_event+0xd2b> */
	goto x86_l_d2b;
x86_l_d10:
	/* 0xd10: mov    DWORD PTR [rcx+rsi*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 104045582745599ULL);
x86_l_d1b:
	/* 0xd1b: mov    DWORD PTR [rcx+rbp*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 622770257919ULL);
x86_l_d26:
	/* 0xd26: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d2b:
	/* 0xd2b: add    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d2d:
	/* 0xd2d: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_d2f:
	/* 0xd2f: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d33:
	/* 0xd33: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_d36:
	/* 0xd36: jg     da5 <generic_kprobe_process_event+0xda5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_da5;
	}
x86_l_d38:
	/* 0xd38: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d40:
	/* 0xd40: mov    rdi,QWORD PTR [rip+0x24d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_d47:
	/* 0xd47: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d4c:
	/* 0xd4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d51:
	/* 0xd51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d53:
	/* 0xd53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d56:
	/* 0xd56: je     da5 <generic_kprobe_process_event+0xda5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da5;
	}
x86_l_d58:
	/* 0xd58: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d5b:
	/* 0xd5b: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_d62:
	/* 0xd62: mov    rdi,QWORD PTR [rip+0x253] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_d69:
	/* 0xd69: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d6e:
	/* 0xd6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d70:
	/* 0xd70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d73:
	/* 0xd73: je     da5 <generic_kprobe_process_event+0xda5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da5;
	}
x86_l_d75:
	/* 0xd75: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d77:
	/* 0xd77: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_d79:
	/* 0xd79: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_d7c:
	/* 0xd7c: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_d81:
	/* 0xd81: je     da5 <generic_kprobe_process_event+0xda5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da5;
	}
x86_l_d83:
	/* 0xd83: mov    DWORD PTR [r14+0x5efc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_d8a:
	/* 0xd8a: mov    rsi,QWORD PTR [rip+0x253] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_d91:
	/* 0xd91: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d96:
	/* 0xd96: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d9b:
	/* 0xd9b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d9e:
	/* 0xd9e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_da3:
	/* 0xda3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da5:
	/* 0xda5: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_db0:
	/* 0xdb0: mov    rsi,QWORD PTR [rip+0x253] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_db7:
	/* 0xdb7: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_dbc:
	/* 0xdbc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_dc1:
	/* 0xdc1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_dc4:
	/* 0xdc4: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_dc9:
	/* 0xdc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dcb:
	/* 0xdcb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dcd:
	/* 0xdcd: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_dd4:
	/* 0xdd4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_dd6:
	/* 0xdd6: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_dd7:
	/* 0xdd7: jmp    3ba0 <__do_bytes+0xc4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ddc:
	/* 0xddc: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_de0:
	/* 0xde0: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de5:
	/* 0xde5: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dea:
	/* 0xdea: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dee:
	/* 0xdee: jg     f94 <generic_kprobe_process_event+0xf94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3988ULL;
	}
x86_l_df4:
	/* 0xdf4: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_df8:
	/* 0xdf8: jle    1233 <generic_kprobe_process_event+0x1233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4659ULL;
	}
x86_l_dfe:
	/* 0xdfe: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_e02:
	/* 0xe02: je     180f <generic_kprobe_process_event+0x180f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6159ULL;
	}
	return 3592ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3592ULL: goto x86_l_e08;
	case 3596ULL: goto x86_l_e0c;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3611ULL: goto x86_l_e1b;
	case 3616ULL: goto x86_l_e20;
	case 3620ULL: goto x86_l_e24;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3658ULL: goto x86_l_e4a;
	case 3663ULL: goto x86_l_e4f;
	case 3665ULL: goto x86_l_e51;
	case 3669ULL: goto x86_l_e55;
	case 3673ULL: goto x86_l_e59;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3690ULL: goto x86_l_e6a;
	case 3694ULL: goto x86_l_e6e;
	case 3701ULL: goto x86_l_e75;
	case 3706ULL: goto x86_l_e7a;
	case 3711ULL: goto x86_l_e7f;
	case 3716ULL: goto x86_l_e84;
	case 3718ULL: goto x86_l_e86;
	case 3722ULL: goto x86_l_e8a;
	case 3729ULL: goto x86_l_e91;
	case 3734ULL: goto x86_l_e96;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3746ULL: goto x86_l_ea2;
	case 3750ULL: goto x86_l_ea6;
	case 3757ULL: goto x86_l_ead;
	case 3762ULL: goto x86_l_eb2;
	case 3767ULL: goto x86_l_eb7;
	case 3772ULL: goto x86_l_ebc;
	case 3774ULL: goto x86_l_ebe;
	case 3778ULL: goto x86_l_ec2;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3802ULL: goto x86_l_eda;
	case 3806ULL: goto x86_l_ede;
	case 3814ULL: goto x86_l_ee6;
	case 3822ULL: goto x86_l_eee;
	case 3830ULL: goto x86_l_ef6;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3846ULL: goto x86_l_f06;
	case 3852ULL: goto x86_l_f0c;
	case 3855ULL: goto x86_l_f0f;
	case 3861ULL: goto x86_l_f15;
	case 3865ULL: goto x86_l_f19;
	case 3870ULL: goto x86_l_f1e;
	case 3875ULL: goto x86_l_f23;
	case 3878ULL: goto x86_l_f26;
	case 3883ULL: goto x86_l_f2b;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3906ULL: goto x86_l_f42;
	case 3911ULL: goto x86_l_f47;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3934ULL: goto x86_l_f5e;
	case 3938ULL: goto x86_l_f62;
	case 3944ULL: goto x86_l_f68;
	case 3948ULL: goto x86_l_f6c;
	case 3954ULL: goto x86_l_f72;
	case 3958ULL: goto x86_l_f76;
	case 3964ULL: goto x86_l_f7c;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3977ULL: goto x86_l_f89;
	case 3983ULL: goto x86_l_f8f;
	case 3988ULL: goto x86_l_f94;
	case 3992ULL: goto x86_l_f98;
	case 3995ULL: goto x86_l_f9b;
	case 4001ULL: goto x86_l_fa1;
	case 4005ULL: goto x86_l_fa5;
	case 4008ULL: goto x86_l_fa8;
	case 4014ULL: goto x86_l_fae;
	case 4018ULL: goto x86_l_fb2;
	case 4024ULL: goto x86_l_fb8;
	case 4029ULL: goto x86_l_fbd;
	case 4034ULL: goto x86_l_fc2;
	case 4039ULL: goto x86_l_fc7;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4052ULL: goto x86_l_fd4;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4064ULL: goto x86_l_fe0;
	case 4069ULL: goto x86_l_fe5;
	case 4074ULL: goto x86_l_fea;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4094ULL: goto x86_l_ffe;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4118ULL: goto x86_l_1016;
	case 4122ULL: goto x86_l_101a;
	case 4127ULL: goto x86_l_101f;
	case 4132ULL: goto x86_l_1024;
	case 4138ULL: goto x86_l_102a;
	case 4141ULL: goto x86_l_102d;
	case 4145ULL: goto x86_l_1031;
	case 4148ULL: goto x86_l_1034;
	case 4154ULL: goto x86_l_103a;
	case 4160ULL: goto x86_l_1040;
	case 4165ULL: goto x86_l_1045;
	case 4170ULL: goto x86_l_104a;
	case 4175ULL: goto x86_l_104f;
	case 4180ULL: goto x86_l_1054;
	case 4183ULL: goto x86_l_1057;
	case 4185ULL: goto x86_l_1059;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4199ULL: goto x86_l_1067;
	case 4205ULL: goto x86_l_106d;
	case 4209ULL: goto x86_l_1071;
	case 4215ULL: goto x86_l_1077;
	case 4219ULL: goto x86_l_107b;
	case 4223ULL: goto x86_l_107f;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4244ULL: goto x86_l_1094;
	case 4252ULL: goto x86_l_109c;
	case 4260ULL: goto x86_l_10a4;
	case 4268ULL: goto x86_l_10ac;
	case 4276ULL: goto x86_l_10b4;
	case 4284ULL: goto x86_l_10bc;
	case 4292ULL: goto x86_l_10c4;
	case 4300ULL: goto x86_l_10cc;
	case 4308ULL: goto x86_l_10d4;
	case 4316ULL: goto x86_l_10dc;
	case 4324ULL: goto x86_l_10e4;
	case 4332ULL: goto x86_l_10ec;
	case 4340ULL: goto x86_l_10f4;
	case 4348ULL: goto x86_l_10fc;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4378ULL: goto x86_l_111a;
	case 4384ULL: goto x86_l_1120;
	case 4388ULL: goto x86_l_1124;
	case 4393ULL: goto x86_l_1129;
	case 4398ULL: goto x86_l_112e;
	case 4403ULL: goto x86_l_1133;
	case 4408ULL: goto x86_l_1138;
	case 4411ULL: goto x86_l_113b;
	case 4413ULL: goto x86_l_113d;
	case 4416ULL: goto x86_l_1140;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4431ULL: goto x86_l_114f;
	case 4436ULL: goto x86_l_1154;
	case 4440ULL: goto x86_l_1158;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4464ULL: goto x86_l_1170;
	case 4466ULL: goto x86_l_1172;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4479ULL: goto x86_l_117f;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4490ULL: goto x86_l_118a;
	case 4496ULL: goto x86_l_1190;
	case 4499ULL: goto x86_l_1193;
	case 4503ULL: goto x86_l_1197;
	case 4509ULL: goto x86_l_119d;
	case 4514ULL: goto x86_l_11a2;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4532ULL: goto x86_l_11b4;
	case 4538ULL: goto x86_l_11ba;
	case 4541ULL: goto x86_l_11bd;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4564ULL: goto x86_l_11d4;
	case 4567ULL: goto x86_l_11d7;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4582ULL: goto x86_l_11e6;
	case 4585ULL: goto x86_l_11e9;
	case 4591ULL: goto x86_l_11ef;
	case 4594ULL: goto x86_l_11f2;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4621ULL: goto x86_l_120d;
	case 4627ULL: goto x86_l_1213;
	case 4632ULL: goto x86_l_1218;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4647ULL: goto x86_l_1227;
	case 4649ULL: goto x86_l_1229;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4663ULL: goto x86_l_1237;
	case 4665ULL: goto x86_l_1239;
	case 4669ULL: goto x86_l_123d;
	case 4675ULL: goto x86_l_1243;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4706ULL: goto x86_l_1262;
	case 4708ULL: goto x86_l_1264;
	case 4713ULL: goto x86_l_1269;
	case 4719ULL: goto x86_l_126f;
	case 4724ULL: goto x86_l_1274;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4739ULL: goto x86_l_1283;
	case 4741ULL: goto x86_l_1285;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4765ULL: goto x86_l_129d;
	case 4769ULL: goto x86_l_12a1;
	case 4775ULL: goto x86_l_12a7;
	case 4779ULL: goto x86_l_12ab;
	case 4784ULL: goto x86_l_12b0;
	case 4788ULL: goto x86_l_12b4;
	case 4794ULL: goto x86_l_12ba;
	case 4797ULL: goto x86_l_12bd;
	case 4800ULL: goto x86_l_12c0;
	case 4804ULL: goto x86_l_12c4;
	case 4809ULL: goto x86_l_12c9;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4830ULL: goto x86_l_12de;
	case 4833ULL: goto x86_l_12e1;
	case 4835ULL: goto x86_l_12e3;
	case 4840ULL: goto x86_l_12e8;
	case 4843ULL: goto x86_l_12eb;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4858ULL: goto x86_l_12fa;
	case 4862ULL: goto x86_l_12fe;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4881ULL: goto x86_l_1311;
	case 4883ULL: goto x86_l_1313;
	case 4887ULL: goto x86_l_1317;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4912ULL: goto x86_l_1330;
	case 4919ULL: goto x86_l_1337;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4934ULL: goto x86_l_1346;
	case 4936ULL: goto x86_l_1348;
	case 4940ULL: goto x86_l_134c;
	case 4947ULL: goto x86_l_1353;
	case 4952ULL: goto x86_l_1358;
	case 4957ULL: goto x86_l_135d;
	case 4962ULL: goto x86_l_1362;
	case 4964ULL: goto x86_l_1364;
	case 4968ULL: goto x86_l_1368;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4987ULL: goto x86_l_137b;
	case 4991ULL: goto x86_l_137f;
	case 4998ULL: goto x86_l_1386;
	case 5003ULL: goto x86_l_138b;
	case 5008ULL: goto x86_l_1390;
	case 5010ULL: goto x86_l_1392;
	case 5014ULL: goto x86_l_1396;
	case 5022ULL: goto x86_l_139e;
	case 5030ULL: goto x86_l_13a6;
	case 5038ULL: goto x86_l_13ae;
	case 5046ULL: goto x86_l_13b6;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5059ULL: goto x86_l_13c3;
	case 5062ULL: goto x86_l_13c6;
	case 5068ULL: goto x86_l_13cc;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5092ULL: goto x86_l_13e4;
	case 5094ULL: goto x86_l_13e6;
	case 5099ULL: goto x86_l_13eb;
	case 5104ULL: goto x86_l_13f0;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5124ULL: goto x86_l_1404;
	case 5130ULL: goto x86_l_140a;
	case 5134ULL: goto x86_l_140e;
	case 5139ULL: goto x86_l_1413;
	case 5143ULL: goto x86_l_1417;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5155ULL: goto x86_l_1423;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5171ULL: goto x86_l_1433;
	case 5179ULL: goto x86_l_143b;
	case 5187ULL: goto x86_l_1443;
	case 5195ULL: goto x86_l_144b;
	case 5203ULL: goto x86_l_1453;
	case 5211ULL: goto x86_l_145b;
	case 5219ULL: goto x86_l_1463;
	case 5227ULL: goto x86_l_146b;
	case 5235ULL: goto x86_l_1473;
	case 5242ULL: goto x86_l_147a;
	case 5246ULL: goto x86_l_147e;
	case 5250ULL: goto x86_l_1482;
	case 5255ULL: goto x86_l_1487;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5276ULL: goto x86_l_149c;
	case 5281ULL: goto x86_l_14a1;
	case 5285ULL: goto x86_l_14a5;
	case 5290ULL: goto x86_l_14aa;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5314ULL: goto x86_l_14c2;
	case 5320ULL: goto x86_l_14c8;
	case 5325ULL: goto x86_l_14cd;
	case 5328ULL: goto x86_l_14d0;
	case 5332ULL: goto x86_l_14d4;
	case 5338ULL: goto x86_l_14da;
	case 5342ULL: goto x86_l_14de;
	case 5347ULL: goto x86_l_14e3;
	case 5350ULL: goto x86_l_14e6;
	case 5355ULL: goto x86_l_14eb;
	case 5359ULL: goto x86_l_14ef;
	case 5364ULL: goto x86_l_14f4;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5382ULL: goto x86_l_1506;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5401ULL: goto x86_l_1519;
	case 5403ULL: goto x86_l_151b;
	case 5407ULL: goto x86_l_151f;
	case 5410ULL: goto x86_l_1522;
	case 5413ULL: goto x86_l_1525;
	case 5416ULL: goto x86_l_1528;
	case 5421ULL: goto x86_l_152d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e08:
	/* 0xe08: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_e0c:
	/* 0xe0c: je     ff4 <generic_kprobe_process_event+0xff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ff4;
	}
x86_l_e12:
	/* 0xe12: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e17:
	/* 0xe17: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_e1b:
	/* 0xe1b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e20:
	/* 0xe20: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e24:
	/* 0xe24: jne    cf6 <generic_kprobe_process_event+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3318ULL;
	}
x86_l_e2a:
	/* 0xe2a: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e2f:
	/* 0xe2f: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e34:
	/* 0xe34: mov    QWORD PTR [r13+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e38:
	/* 0xe38: lea    rdi,[r13+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_e3c:
	/* 0xe3c: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e40:
	/* 0xe40: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e45:
	/* 0xe45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e4a:
	/* 0xe4a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e4f:
	/* 0xe4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e51:
	/* 0xe51: lea    rdi,[r13+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_e55:
	/* 0xe55: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_e59:
	/* 0xe59: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e5e:
	/* 0xe5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e63:
	/* 0xe63: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_e68:
	/* 0xe68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6a:
	/* 0xe6a: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e6e:
	/* 0xe6e: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_e75:
	/* 0xe75: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e7a:
	/* 0xe7a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e7f:
	/* 0xe7f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e84:
	/* 0xe84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e86:
	/* 0xe86: lea    rdi,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e8a:
	/* 0xe8a: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_e91:
	/* 0xe91: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e96:
	/* 0xe96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e9b:
	/* 0xe9b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ea0:
	/* 0xea0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea2:
	/* 0xea2: lea    rdi,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ea6:
	/* 0xea6: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_ead:
	/* 0xead: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_eb2:
	/* 0xeb2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_eb7:
	/* 0xeb7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ebc:
	/* 0xebc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ebe:
	/* 0xebe: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ec2:
	/* 0xec2: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_ec9:
	/* 0xec9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ece:
	/* 0xece: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ed3:
	/* 0xed3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ed8:
	/* 0xed8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eda:
	/* 0xeda: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ede:
	/* 0xede: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee6:
	/* 0xee6: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_eee:
	/* 0xeee: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ef6:
	/* 0xef6: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_efe:
	/* 0xefe: movzx  eax,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_f03:
	/* 0xf03: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_f06:
	/* 0xf06: je     212c <generic_kprobe_process_event+0x212c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8492ULL;
	}
x86_l_f0c:
	/* 0xf0c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f0f:
	/* 0xf0f: jne    215c <generic_kprobe_process_event+0x215c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8540ULL;
	}
x86_l_f15:
	/* 0xf15: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f19:
	/* 0xf19: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f1e:
	/* 0xf1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f23:
	/* 0xf23: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_f26:
	/* 0xf26: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f2b:
	/* 0xf2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2d:
	/* 0xf2d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f32:
	/* 0xf32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f37:
	/* 0xf37: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f3a:
	/* 0xf3a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f3f:
	/* 0xf3f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f42:
	/* 0xf42: jmp    215a <generic_kprobe_process_event+0x215a> */
	return 8538ULL;
x86_l_f47:
	/* 0xf47: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f4a:
	/* 0xf4a: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f4f:
	/* 0xf4f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f54:
	/* 0xf54: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f59:
	/* 0xf59: jmp    cc6 <generic_kprobe_process_event+0xcc6> */
	return 3270ULL;
x86_l_f5e:
	/* 0xf5e: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_f62:
	/* 0xf62: jg     1208 <generic_kprobe_process_event+0x1208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1208;
	}
x86_l_f68:
	/* 0xf68: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_f6c:
	/* 0xf6c: je     165c <generic_kprobe_process_event+0x165c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5724ULL;
	}
x86_l_f72:
	/* 0xf72: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_f76:
	/* 0xf76: je     1720 <generic_kprobe_process_event+0x1720> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5920ULL;
	}
x86_l_f7c:
	/* 0xf7c: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_f80:
	/* 0xf80: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f85:
	/* 0xf85: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f89:
	/* 0xf89: je     1243 <generic_kprobe_process_event+0x1243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1243;
	}
x86_l_f8f:
	/* 0xf8f: jmp    cf6 <generic_kprobe_process_event+0xcf6> */
	return 3318ULL;
x86_l_f94:
	/* 0xf94: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_f98:
	/* 0xf98: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f9b:
	/* 0xf9b: jb     1243 <generic_kprobe_process_event+0x1243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1243;
	}
x86_l_fa1:
	/* 0xfa1: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_fa5:
	/* 0xfa5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fa8:
	/* 0xfa8: jb     1264 <generic_kprobe_process_event+0x1264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1264;
	}
x86_l_fae:
	/* 0xfae: cmp    r13d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 14ULL);
x86_l_fb2:
	/* 0xfb2: jne    cf6 <generic_kprobe_process_event+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3318ULL;
	}
x86_l_fb8:
	/* 0xfb8: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fbd:
	/* 0xfbd: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fc2:
	/* 0xfc2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fc7:
	/* 0xfc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fcc:
	/* 0xfcc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fd1:
	/* 0xfd1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fd4:
	/* 0xfd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd6:
	/* 0xfd6: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fdb:
	/* 0xfdb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fe0:
	/* 0xfe0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fe5:
	/* 0xfe5: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fea:
	/* 0xfea: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fed:
	/* 0xfed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff2:
	/* 0xff2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff4:
	/* 0xff4: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ff9:
	/* 0xff9: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ffe:
	/* 0xffe: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1002:
	/* 0x1002: mov    ecx,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4097ULL);
x86_l_1007:
	/* 0x1007: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_100c:
	/* 0x100c: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_1011:
	/* 0x1011: jmp    19f0 <generic_kprobe_process_event+0x19f0> */
	return 6640ULL;
x86_l_1016:
	/* 0x1016: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_101a:
	/* 0x101a: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_101f:
	/* 0x101f: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1024:
	/* 0x1024: jle    1400 <generic_kprobe_process_event+0x1400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1400;
	}
x86_l_102a:
	/* 0x102a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_102d:
	/* 0x102d: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_1031:
	/* 0x1031: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1034:
	/* 0x1034: jae    1298 <generic_kprobe_process_event+0x1298> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1298;
	}
x86_l_103a:
	/* 0x103a: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1040:
	/* 0x1040: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1045:
	/* 0x1045: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_104a:
	/* 0x104a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_104f:
	/* 0x104f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1054:
	/* 0x1054: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1057:
	/* 0x1057: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1059:
	/* 0x1059: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105e:
	/* 0x105e: jmp    ccb <generic_kprobe_process_event+0xccb> */
	return 3275ULL;
x86_l_1063:
	/* 0x1063: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_1067:
	/* 0x1067: je     19ce <generic_kprobe_process_event+0x19ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6606ULL;
	}
x86_l_106d:
	/* 0x106d: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_1071:
	/* 0x1071: je     1a12 <generic_kprobe_process_event+0x1a12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6674ULL;
	}
x86_l_1077:
	/* 0x1077: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_107b:
	/* 0x107b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_107f:
	/* 0x107f: jne    cf6 <generic_kprobe_process_event+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3318ULL;
	}
x86_l_1085:
	/* 0x1085: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_108a:
	/* 0x108a: mov    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_108f:
	/* 0x108f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1094:
	/* 0x1094: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_109c:
	/* 0x109c: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_10a4:
	/* 0x10a4: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_10ac:
	/* 0x10ac: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_10b4:
	/* 0x10b4: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_10bc:
	/* 0x10bc: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_10c4:
	/* 0x10c4: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_10cc:
	/* 0x10cc: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_10d4:
	/* 0x10d4: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_10dc:
	/* 0x10dc: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_10e4:
	/* 0x10e4: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10ec:
	/* 0x10ec: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10f4:
	/* 0x10f4: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10fc:
	/* 0x10fc: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1108:
	/* 0x1108: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_110d:
	/* 0x110d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1112:
	/* 0x1112: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1115:
	/* 0x1115: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1117:
	/* 0x1117: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_111a:
	/* 0x111a: js     2442 <generic_kprobe_process_event+0x2442> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9282ULL;
	}
x86_l_1120:
	/* 0x1120: lea    r12,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1124:
	/* 0x1124: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1129:
	/* 0x1129: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_112e:
	/* 0x112e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1133:
	/* 0x1133: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1138:
	/* 0x1138: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_113b:
	/* 0x113b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_113d:
	/* 0x113d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1140:
	/* 0x1140: js     2442 <generic_kprobe_process_event+0x2442> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9282ULL;
	}
x86_l_1146:
	/* 0x1146: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114b:
	/* 0x114b: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_114f:
	/* 0x114f: cmp    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1154:
	/* 0x1154: sete   BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_1158:
	/* 0x1158: je     2414 <generic_kprobe_process_event+0x2414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9236ULL;
	}
x86_l_115e:
	/* 0x115e: mov    ecx,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 108ULL);
x86_l_1163:
	/* 0x1163: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1168:
	/* 0x1168: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_116d:
	/* 0x116d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1170:
	/* 0x1170: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1172:
	/* 0x1172: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1174:
	/* 0x1174: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1179:
	/* 0x1179: js     2442 <generic_kprobe_process_event+0x2442> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9282ULL;
	}
x86_l_117f:
	/* 0x117f: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_1181:
	/* 0x1181: jmp    243a <generic_kprobe_process_event+0x243a> */
	return 9274ULL;
x86_l_1186:
	/* 0x1186: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_118a:
	/* 0x118a: jg     14cd <generic_kprobe_process_event+0x14cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_14cd;
	}
x86_l_1190:
	/* 0x1190: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1193:
	/* 0x1193: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1197:
	/* 0x1197: je     1aa9 <generic_kprobe_process_event+0x1aa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6825ULL;
	}
x86_l_119d:
	/* 0x119d: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11a2:
	/* 0x11a2: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_11a6:
	/* 0x11a6: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ab:
	/* 0x11ab: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11b0:
	/* 0x11b0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b4:
	/* 0x11b4: jne    cfb <generic_kprobe_process_event+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3323ULL;
	}
x86_l_11ba:
	/* 0x11ba: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_11bd:
	/* 0x11bd: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_11c0:
	/* 0x11c0: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11c5:
	/* 0x11c5: lea    r13,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_11cc:
	/* 0x11cc: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11d1:
	/* 0x11d1: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_11d4:
	/* 0x11d4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11d7:
	/* 0x11d7: jle    22b3 <generic_kprobe_process_event+0x22b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8883ULL;
	}
x86_l_11dd:
	/* 0x11dd: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_11e0:
	/* 0x11e0: je     253d <generic_kprobe_process_event+0x253d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9533ULL;
	}
x86_l_11e6:
	/* 0x11e6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11e9:
	/* 0x11e9: je     254a <generic_kprobe_process_event+0x254a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9546ULL;
	}
x86_l_11ef:
	/* 0x11ef: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_11f2:
	/* 0x11f2: jne    29be <generic_kprobe_process_event+0x29be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10686ULL;
	}
x86_l_11f8:
	/* 0x11f8: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11fd:
	/* 0x11fd: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_1203:
	/* 0x1203: jmp    2562 <generic_kprobe_process_event+0x2562> */
	return 9570ULL;
x86_l_1208:
	/* 0x1208: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_120d:
	/* 0x120d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1213:
	/* 0x1213: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1218:
	/* 0x1218: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_121d:
	/* 0x121d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1222:
	/* 0x1222: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1227:
	/* 0x1227: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1229:
	/* 0x1229: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_122e:
	/* 0x122e: jmp    cf2 <generic_kprobe_process_event+0xcf2> */
	return 3314ULL;
x86_l_1233:
	/* 0x1233: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1237:
	/* 0x1237: je     1264 <generic_kprobe_process_event+0x1264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1264;
	}
x86_l_1239:
	/* 0x1239: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_123d:
	/* 0x123d: jne    cf6 <generic_kprobe_process_event+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3318ULL;
	}
x86_l_1243:
	/* 0x1243: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1249:
	/* 0x1249: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_124e:
	/* 0x124e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1253:
	/* 0x1253: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1258:
	/* 0x1258: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_125d:
	/* 0x125d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1262:
	/* 0x1262: jmp    1283 <generic_kprobe_process_event+0x1283> */
	goto x86_l_1283;
x86_l_1264:
	/* 0x1264: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1269:
	/* 0x1269: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_126f:
	/* 0x126f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1274:
	/* 0x1274: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1279:
	/* 0x1279: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_127e:
	/* 0x127e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1283:
	/* 0x1283: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1285:
	/* 0x1285: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1289:
	/* 0x1289: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_128e:
	/* 0x128e: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1293:
	/* 0x1293: jmp    cfb <generic_kprobe_process_event+0xcfb> */
	return 3323ULL;
x86_l_1298:
	/* 0x1298: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_129d:
	/* 0x129d: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_12a1:
	/* 0x12a1: je     1eab <generic_kprobe_process_event+0x1eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7851ULL;
	}
x86_l_12a7:
	/* 0x12a7: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_12ab:
	/* 0x12ab: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b0:
	/* 0x12b0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b4:
	/* 0x12b4: jne    cfb <generic_kprobe_process_event+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3323ULL;
	}
x86_l_12ba:
	/* 0x12ba: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_12bd:
	/* 0x12bd: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_12c0:
	/* 0x12c0: add    r8,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_12c4:
	/* 0x12c4: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12c9:
	/* 0x12c9: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_12cf:
	/* 0x12cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12d4:
	/* 0x12d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12d9:
	/* 0x12d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12de:
	/* 0x12de: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_12e1:
	/* 0x12e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e3:
	/* 0x12e3: mov    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12e8:
	/* 0x12e8: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_12eb:
	/* 0x12eb: je     24ee <generic_kprobe_process_event+0x24ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9454ULL;
	}
x86_l_12f1:
	/* 0x12f1: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12f6:
	/* 0x12f6: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12fa:
	/* 0x12fa: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_12fe:
	/* 0x12fe: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1302:
	/* 0x1302: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1307:
	/* 0x1307: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_130c:
	/* 0x130c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1311:
	/* 0x1311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1313:
	/* 0x1313: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1317:
	/* 0x1317: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_131b:
	/* 0x131b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1320:
	/* 0x1320: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1325:
	/* 0x1325: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_132a:
	/* 0x132a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132c:
	/* 0x132c: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1330:
	/* 0x1330: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1337:
	/* 0x1337: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_133c:
	/* 0x133c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1341:
	/* 0x1341: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1346:
	/* 0x1346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1348:
	/* 0x1348: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_134c:
	/* 0x134c: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1353:
	/* 0x1353: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1358:
	/* 0x1358: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_135d:
	/* 0x135d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1362:
	/* 0x1362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1364:
	/* 0x1364: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1368:
	/* 0x1368: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_136f:
	/* 0x136f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1374:
	/* 0x1374: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1379:
	/* 0x1379: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137b:
	/* 0x137b: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_137f:
	/* 0x137f: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1386:
	/* 0x1386: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_138b:
	/* 0x138b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1390:
	/* 0x1390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1392:
	/* 0x1392: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1396:
	/* 0x1396: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_139e:
	/* 0x139e: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13a6:
	/* 0x13a6: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13ae:
	/* 0x13ae: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_13b6:
	/* 0x13b6: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_13ba:
	/* 0x13ba: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_13bd:
	/* 0x13bd: je     2475 <generic_kprobe_process_event+0x2475> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9333ULL;
	}
x86_l_13c3:
	/* 0x13c3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13c6:
	/* 0x13c6: jne    24a7 <generic_kprobe_process_event+0x24a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9383ULL;
	}
x86_l_13cc:
	/* 0x13cc: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13d0:
	/* 0x13d0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13d5:
	/* 0x13d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13da:
	/* 0x13da: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13df:
	/* 0x13df: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13e4:
	/* 0x13e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e6:
	/* 0x13e6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13eb:
	/* 0x13eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13f0:
	/* 0x13f0: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_13f3:
	/* 0x13f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13f8:
	/* 0x13f8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_13fb:
	/* 0x13fb: jmp    24a5 <generic_kprobe_process_event+0x24a5> */
	return 9381ULL;
x86_l_1400:
	/* 0x1400: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_1404:
	/* 0x1404: je     1f48 <generic_kprobe_process_event+0x1f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8008ULL;
	}
x86_l_140a:
	/* 0x140a: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_140e:
	/* 0x140e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1413:
	/* 0x1413: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1417:
	/* 0x1417: jne    cfb <generic_kprobe_process_event+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3323ULL;
	}
x86_l_141d:
	/* 0x141d: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1420:
	/* 0x1420: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_1423:
	/* 0x1423: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1426:
	/* 0x1426: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_142b:
	/* 0x142b: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1433:
	/* 0x1433: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_143b:
	/* 0x143b: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1443:
	/* 0x1443: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_144b:
	/* 0x144b: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1453:
	/* 0x1453: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_145b:
	/* 0x145b: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1463:
	/* 0x1463: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_146b:
	/* 0x146b: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1473:
	/* 0x1473: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147a:
	/* 0x147a: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_147e:
	/* 0x147e: lea    rdx,[r8+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1482:
	/* 0x1482: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_1487:
	/* 0x1487: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_148c:
	/* 0x148c: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1491:
	/* 0x1491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1493:
	/* 0x1493: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1496:
	/* 0x1496: js     2403 <generic_kprobe_process_event+0x2403> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9219ULL;
	}
x86_l_149c:
	/* 0x149c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a1:
	/* 0x14a1: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14a5:
	/* 0x14a5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14aa:
	/* 0x14aa: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_14b1:
	/* 0x14b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14b6:
	/* 0x14b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14bb:
	/* 0x14bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c0:
	/* 0x14c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c2:
	/* 0x14c2: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_14c8:
	/* 0x14c8: jmp    2406 <generic_kprobe_process_event+0x2406> */
	return 9222ULL;
x86_l_14cd:
	/* 0x14cd: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_14d0:
	/* 0x14d0: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_14d4:
	/* 0x14d4: je     1b13 <generic_kprobe_process_event+0x1b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6931ULL;
	}
x86_l_14da:
	/* 0x14da: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_14de:
	/* 0x14de: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e3:
	/* 0x14e3: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_14e6:
	/* 0x14e6: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14eb:
	/* 0x14eb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ef:
	/* 0x14ef: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14f4:
	/* 0x14f4: jne    cfb <generic_kprobe_process_event+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3323ULL;
	}
x86_l_14fa:
	/* 0x14fa: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14ff:
	/* 0x14ff: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1506:
	/* 0x1506: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1509:
	/* 0x1509: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_150c:
	/* 0x150c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1511:
	/* 0x1511: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1516:
	/* 0x1516: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1519:
	/* 0x1519: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151b:
	/* 0x151b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151f:
	/* 0x151f: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1522:
	/* 0x1522: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1525:
	/* 0x1525: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_1528:
	/* 0x1528: jmp    cfb <generic_kprobe_process_event+0xcfb> */
	return 3323ULL;
x86_l_152d:
	/* 0x152d: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
	return 5425ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5425ULL: goto x86_l_1531;
	case 5431ULL: goto x86_l_1537;
	case 5435ULL: goto x86_l_153b;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5460ULL: goto x86_l_1554;
	case 5469ULL: goto x86_l_155d;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5486ULL: goto x86_l_156e;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5501ULL: goto x86_l_157d;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5511ULL: goto x86_l_1587;
	case 5516ULL: goto x86_l_158c;
	case 5521ULL: goto x86_l_1591;
	case 5526ULL: goto x86_l_1596;
	case 5531ULL: goto x86_l_159b;
	case 5536ULL: goto x86_l_15a0;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5546ULL: goto x86_l_15aa;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5571ULL: goto x86_l_15c3;
	case 5573ULL: goto x86_l_15c5;
	case 5580ULL: goto x86_l_15cc;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5597ULL: goto x86_l_15dd;
	case 5602ULL: goto x86_l_15e2;
	case 5604ULL: goto x86_l_15e4;
	case 5611ULL: goto x86_l_15eb;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5631ULL: goto x86_l_15ff;
	case 5636ULL: goto x86_l_1604;
	case 5639ULL: goto x86_l_1607;
	case 5641ULL: goto x86_l_1609;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5653ULL: goto x86_l_1615;
	case 5658ULL: goto x86_l_161a;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5673ULL: goto x86_l_1629;
	case 5677ULL: goto x86_l_162d;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5691ULL: goto x86_l_163b;
	case 5694ULL: goto x86_l_163e;
	case 5697ULL: goto x86_l_1641;
	case 5703ULL: goto x86_l_1647;
	case 5708ULL: goto x86_l_164c;
	case 5712ULL: goto x86_l_1650;
	case 5714ULL: goto x86_l_1652;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5733ULL: goto x86_l_1665;
	case 5738ULL: goto x86_l_166a;
	case 5740ULL: goto x86_l_166c;
	case 5744ULL: goto x86_l_1670;
	case 5749ULL: goto x86_l_1675;
	case 5757ULL: goto x86_l_167d;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5772ULL: goto x86_l_168c;
	case 5778ULL: goto x86_l_1692;
	case 5783ULL: goto x86_l_1697;
	case 5785ULL: goto x86_l_1699;
	case 5792ULL: goto x86_l_16a0;
	case 5796ULL: goto x86_l_16a4;
	case 5803ULL: goto x86_l_16ab;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5815ULL: goto x86_l_16b7;
	case 5818ULL: goto x86_l_16ba;
	case 5824ULL: goto x86_l_16c0;
	case 5827ULL: goto x86_l_16c3;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5851ULL: goto x86_l_16db;
	case 5856ULL: goto x86_l_16e0;
	case 5858ULL: goto x86_l_16e2;
	case 5865ULL: goto x86_l_16e9;
	case 5869ULL: goto x86_l_16ed;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5881ULL: goto x86_l_16f9;
	case 5883ULL: goto x86_l_16fb;
	case 5887ULL: goto x86_l_16ff;
	case 5891ULL: goto x86_l_1703;
	case 5895ULL: goto x86_l_1707;
	case 5899ULL: goto x86_l_170b;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5923ULL: goto x86_l_1723;
	case 5928ULL: goto x86_l_1728;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5954ULL: goto x86_l_1742;
	case 5956ULL: goto x86_l_1744;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5972ULL: goto x86_l_1754;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5996ULL: goto x86_l_176c;
	case 6001ULL: goto x86_l_1771;
	case 6006ULL: goto x86_l_1776;
	case 6011ULL: goto x86_l_177b;
	case 6014ULL: goto x86_l_177e;
	case 6016ULL: goto x86_l_1780;
	case 6021ULL: goto x86_l_1785;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6046ULL: goto x86_l_179e;
	case 6051ULL: goto x86_l_17a3;
	case 6055ULL: goto x86_l_17a7;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6077ULL: goto x86_l_17bd;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6099ULL: goto x86_l_17d3;
	case 6106ULL: goto x86_l_17da;
	case 6111ULL: goto x86_l_17df;
	case 6117ULL: goto x86_l_17e5;
	case 6124ULL: goto x86_l_17ec;
	case 6130ULL: goto x86_l_17f2;
	case 6136ULL: goto x86_l_17f8;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6151ULL: goto x86_l_1807;
	case 6154ULL: goto x86_l_180a;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6173ULL: goto x86_l_181d;
	case 6181ULL: goto x86_l_1825;
	case 6186ULL: goto x86_l_182a;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6224ULL: goto x86_l_1850;
	case 6228ULL: goto x86_l_1854;
	case 6236ULL: goto x86_l_185c;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6253ULL: goto x86_l_186d;
	case 6257ULL: goto x86_l_1871;
	case 6265ULL: goto x86_l_1879;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6282ULL: goto x86_l_188a;
	case 6291ULL: goto x86_l_1893;
	case 6299ULL: goto x86_l_189b;
	case 6304ULL: goto x86_l_18a0;
	case 6309ULL: goto x86_l_18a5;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6321ULL: goto x86_l_18b1;
	case 6329ULL: goto x86_l_18b9;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6347ULL: goto x86_l_18cb;
	case 6352ULL: goto x86_l_18d0;
	case 6354ULL: goto x86_l_18d2;
	case 6363ULL: goto x86_l_18db;
	case 6368ULL: goto x86_l_18e0;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6394ULL: goto x86_l_18fa;
	case 6396ULL: goto x86_l_18fc;
	case 6404ULL: goto x86_l_1904;
	case 6407ULL: goto x86_l_1907;
	case 6410ULL: goto x86_l_190a;
	case 6416ULL: goto x86_l_1910;
	case 6419ULL: goto x86_l_1913;
	case 6425ULL: goto x86_l_1919;
	case 6429ULL: goto x86_l_191d;
	case 6437ULL: goto x86_l_1925;
	case 6442ULL: goto x86_l_192a;
	case 6447ULL: goto x86_l_192f;
	case 6452ULL: goto x86_l_1934;
	case 6454ULL: goto x86_l_1936;
	case 6462ULL: goto x86_l_193e;
	case 6467ULL: goto x86_l_1943;
	case 6471ULL: goto x86_l_1947;
	case 6477ULL: goto x86_l_194d;
	case 6481ULL: goto x86_l_1951;
	case 6488ULL: goto x86_l_1958;
	case 6496ULL: goto x86_l_1960;
	case 6504ULL: goto x86_l_1968;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6533ULL: goto x86_l_1985;
	case 6537ULL: goto x86_l_1989;
	case 6542ULL: goto x86_l_198e;
	case 6547ULL: goto x86_l_1993;
	case 6550ULL: goto x86_l_1996;
	case 6555ULL: goto x86_l_199b;
	case 6558ULL: goto x86_l_199e;
	case 6560ULL: goto x86_l_19a0;
	case 6568ULL: goto x86_l_19a8;
	case 6576ULL: goto x86_l_19b0;
	case 6581ULL: goto x86_l_19b5;
	case 6586ULL: goto x86_l_19ba;
	case 6591ULL: goto x86_l_19bf;
	case 6593ULL: goto x86_l_19c1;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6611ULL: goto x86_l_19d3;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6642ULL: goto x86_l_19f2;
	case 6645ULL: goto x86_l_19f5;
	case 6648ULL: goto x86_l_19f8;
	case 6654ULL: goto x86_l_19fe;
	case 6658ULL: goto x86_l_1a02;
	case 6660ULL: goto x86_l_1a04;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6674ULL: goto x86_l_1a12;
	case 6679ULL: goto x86_l_1a17;
	case 6684ULL: goto x86_l_1a1c;
	case 6692ULL: goto x86_l_1a24;
	case 6700ULL: goto x86_l_1a2c;
	case 6708ULL: goto x86_l_1a34;
	case 6713ULL: goto x86_l_1a39;
	case 6718ULL: goto x86_l_1a3e;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6729ULL: goto x86_l_1a49;
	case 6731ULL: goto x86_l_1a4b;
	case 6734ULL: goto x86_l_1a4e;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6748ULL: goto x86_l_1a5c;
	case 6754ULL: goto x86_l_1a62;
	case 6757ULL: goto x86_l_1a65;
	case 6763ULL: goto x86_l_1a6b;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6782ULL: goto x86_l_1a7e;
	case 6787ULL: goto x86_l_1a83;
	case 6789ULL: goto x86_l_1a85;
	case 6793ULL: goto x86_l_1a89;
	case 6798ULL: goto x86_l_1a8e;
	case 6802ULL: goto x86_l_1a92;
	case 6806ULL: goto x86_l_1a96;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6833ULL: goto x86_l_1ab1;
	case 6837ULL: goto x86_l_1ab5;
	case 6844ULL: goto x86_l_1abc;
	case 6856ULL: goto x86_l_1ac8;
	case 6861ULL: goto x86_l_1acd;
	case 6867ULL: goto x86_l_1ad3;
	case 6872ULL: goto x86_l_1ad8;
	case 6875ULL: goto x86_l_1adb;
	case 6878ULL: goto x86_l_1ade;
	case 6880ULL: goto x86_l_1ae0;
	case 6883ULL: goto x86_l_1ae3;
	case 6886ULL: goto x86_l_1ae6;
	case 6892ULL: goto x86_l_1aec;
	case 6895ULL: goto x86_l_1aef;
	case 6901ULL: goto x86_l_1af5;
	case 6904ULL: goto x86_l_1af8;
	case 6910ULL: goto x86_l_1afe;
	case 6913ULL: goto x86_l_1b01;
	case 6919ULL: goto x86_l_1b07;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6940ULL: goto x86_l_1b1c;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6972ULL: goto x86_l_1b3c;
	case 6977ULL: goto x86_l_1b41;
	case 6979ULL: goto x86_l_1b43;
	case 6983ULL: goto x86_l_1b47;
	case 6988ULL: goto x86_l_1b4c;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7005ULL: goto x86_l_1b5d;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7029ULL: goto x86_l_1b75;
	case 7031ULL: goto x86_l_1b77;
	case 7035ULL: goto x86_l_1b7b;
	case 7040ULL: goto x86_l_1b80;
	case 7045ULL: goto x86_l_1b85;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7057ULL: goto x86_l_1b91;
	case 7061ULL: goto x86_l_1b95;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7083ULL: goto x86_l_1bab;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7107ULL: goto x86_l_1bc3;
	case 7109ULL: goto x86_l_1bc5;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7133ULL: goto x86_l_1bdd;
	case 7135ULL: goto x86_l_1bdf;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7161ULL: goto x86_l_1bf9;
	case 7169ULL: goto x86_l_1c01;
	case 7173ULL: goto x86_l_1c05;
	case 7178ULL: goto x86_l_1c0a;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7195ULL: goto x86_l_1c1b;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7209ULL: goto x86_l_1c29;
	case 7214ULL: goto x86_l_1c2e;
	case 7219ULL: goto x86_l_1c33;
	case 7221ULL: goto x86_l_1c35;
	case 7225ULL: goto x86_l_1c39;
	case 7230ULL: goto x86_l_1c3e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1531:
	/* 0x1531: je     1e3d <generic_kprobe_process_event+0x1e3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7741ULL;
	}
x86_l_1537:
	/* 0x1537: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_153b:
	/* 0x153b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1540:
	/* 0x1540: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1545:
	/* 0x1545: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1549:
	/* 0x1549: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_154e:
	/* 0x154e: jne    cfb <generic_kprobe_process_event+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3323ULL;
	}
x86_l_1554:
	/* 0x1554: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_155d:
	/* 0x155d: lea    rdx,[r8+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1564:
	/* 0x1564: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1569:
	/* 0x1569: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_156e:
	/* 0x156e: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1571:
	/* 0x1571: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1576:
	/* 0x1576: lea    r15,[r8+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_157d:
	/* 0x157d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1582:
	/* 0x1582: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_1585:
	/* 0x1585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1587:
	/* 0x1587: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_158c:
	/* 0x158c: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_1591:
	/* 0x1591: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1596:
	/* 0x1596: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_159b:
	/* 0x159b: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15a0:
	/* 0x15a0: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_15a3:
	/* 0x15a3: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_15a8:
	/* 0x15a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15aa:
	/* 0x15aa: lea    rdi,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_15b1:
	/* 0x15b1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15b6:
	/* 0x15b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15bb:
	/* 0x15bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15c0:
	/* 0x15c0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15c3:
	/* 0x15c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c5:
	/* 0x15c5: lea    rdi,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_15cc:
	/* 0x15cc: lea    rdx,[rbx+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_15d3:
	/* 0x15d3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15d8:
	/* 0x15d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15dd:
	/* 0x15dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15e2:
	/* 0x15e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e4:
	/* 0x15e4: add    r13,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_15eb:
	/* 0x15eb: add    rbx,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_15f2:
	/* 0x15f2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15f7:
	/* 0x15f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15fc:
	/* 0x15fc: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_15ff:
	/* 0x15ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1604:
	/* 0x1604: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1607:
	/* 0x1607: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1609:
	/* 0x1609: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_160d:
	/* 0x160d: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1610:
	/* 0x1610: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1615:
	/* 0x1615: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_161a:
	/* 0x161a: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_1620:
	/* 0x1620: jmp    cfb <generic_kprobe_process_event+0xcfb> */
	return 3323ULL;
x86_l_1625:
	/* 0x1625: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_1629:
	/* 0x1629: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_162d:
	/* 0x162d: jne    cf6 <generic_kprobe_process_event+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3318ULL;
	}
x86_l_1633:
	/* 0x1633: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1638:
	/* 0x1638: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_163b:
	/* 0x163b: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_163e:
	/* 0x163e: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1641:
	/* 0x1641: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1647:
	/* 0x1647: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_164c:
	/* 0x164c: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1650:
	/* 0x1650: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1652:
	/* 0x1652: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1657:
	/* 0x1657: jmp    19f0 <generic_kprobe_process_event+0x19f0> */
	goto x86_l_19f0;
x86_l_165c:
	/* 0x165c: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1665:
	/* 0x1665: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_166a:
	/* 0x166a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166c:
	/* 0x166c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1670:
	/* 0x1670: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1675:
	/* 0x1675: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_167d:
	/* 0x167d: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1682:
	/* 0x1682: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1687:
	/* 0x1687: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_168c:
	/* 0x168c: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1692:
	/* 0x1692: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1697:
	/* 0x1697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1699:
	/* 0x1699: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16a0:
	/* 0x16a0: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16a4:
	/* 0x16a4: mov    rdi,QWORD PTR [rip+0x256] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_16ab:
	/* 0x16ab: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16b0:
	/* 0x16b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16b5:
	/* 0x16b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b7:
	/* 0x16b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16ba:
	/* 0x16ba: je     1fc6 <generic_kprobe_process_event+0x1fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8134ULL;
	}
x86_l_16c0:
	/* 0x16c0: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16c3:
	/* 0x16c3: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16cb:
	/* 0x16cb: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_16ce:
	/* 0x16ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16d3:
	/* 0x16d3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16d8:
	/* 0x16d8: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_16db:
	/* 0x16db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16e0:
	/* 0x16e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e2:
	/* 0x16e2: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16e9:
	/* 0x16e9: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16ed:
	/* 0x16ed: lea    rsi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16f1:
	/* 0x16f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16f6:
	/* 0x16f6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16f9:
	/* 0x16f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fb:
	/* 0x16fb: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_16ff:
	/* 0x16ff: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1703:
	/* 0x1703: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1707:
	/* 0x1707: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_170b:
	/* 0x170b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1710:
	/* 0x1710: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1715:
	/* 0x1715: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1717:
	/* 0x1717: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_171b:
	/* 0x171b: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_1720:
	/* 0x1720: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1723:
	/* 0x1723: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1728:
	/* 0x1728: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1730:
	/* 0x1730: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1735:
	/* 0x1735: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_173a:
	/* 0x173a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_173f:
	/* 0x173f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1742:
	/* 0x1742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1744:
	/* 0x1744: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_174c:
	/* 0x174c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174e:
	/* 0x174e: je     1fd2 <generic_kprobe_process_event+0x1fd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8146ULL;
	}
x86_l_1754:
	/* 0x1754: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1757:
	/* 0x1757: jne    21e9 <generic_kprobe_process_event+0x21e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8681ULL;
	}
x86_l_175d:
	/* 0x175d: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1761:
	/* 0x1761: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1766:
	/* 0x1766: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_176c:
	/* 0x176c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1771:
	/* 0x1771: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1776:
	/* 0x1776: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177b:
	/* 0x177b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_177e:
	/* 0x177e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1780:
	/* 0x1780: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1785:
	/* 0x1785: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_178d:
	/* 0x178d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1792:
	/* 0x1792: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1797:
	/* 0x1797: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_179c:
	/* 0x179c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179e:
	/* 0x179e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17a3:
	/* 0x17a3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17a7:
	/* 0x17a7: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17ac:
	/* 0x17ac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17b1:
	/* 0x17b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17b6:
	/* 0x17b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17bb:
	/* 0x17bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bd:
	/* 0x17bd: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17c5:
	/* 0x17c5: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17ca:
	/* 0x17ca: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17cf:
	/* 0x17cf: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_17d3:
	/* 0x17d3: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_17da:
	/* 0x17da: test   BYTE PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_17df:
	/* 0x17df: je     2ac8 <generic_kprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10952ULL;
	}
x86_l_17e5:
	/* 0x17e5: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_17ec:
	/* 0x17ec: jb     2aa4 <generic_kprobe_process_event+0x2aa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10916ULL;
	}
x86_l_17f2:
	/* 0x17f2: mov    DWORD PTR [rbx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_17f8:
	/* 0x17f8: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_17fc:
	/* 0x17fc: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1801:
	/* 0x1801: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1804:
	/* 0x1804: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1807:
	/* 0x1807: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_180a:
	/* 0x180a: jmp    2066 <generic_kprobe_process_event+0x2066> */
	return 8294ULL;
x86_l_180f:
	/* 0x180f: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1814:
	/* 0x1814: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1819:
	/* 0x1819: lea    rdi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_181d:
	/* 0x181d: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1825:
	/* 0x1825: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
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
	/* 0x1836: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_183a:
	/* 0x183a: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_183f:
	/* 0x183f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1844:
	/* 0x1844: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1849:
	/* 0x1849: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_184e:
	/* 0x184e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1850:
	/* 0x1850: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1854:
	/* 0x1854: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_185c:
	/* 0x185c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1861:
	/* 0x1861: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1866:
	/* 0x1866: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_186b:
	/* 0x186b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186d:
	/* 0x186d: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1871:
	/* 0x1871: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1879:
	/* 0x1879: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
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
	/* 0x188a: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1893:
	/* 0x1893: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_189b:
	/* 0x189b: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_18a0:
	/* 0x18a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18a5:
	/* 0x18a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18aa:
	/* 0x18aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18af:
	/* 0x18af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b1:
	/* 0x18b1: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_18b9:
	/* 0x18b9: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18c1:
	/* 0x18c1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_18c6:
	/* 0x18c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18cb:
	/* 0x18cb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_18d0:
	/* 0x18d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d2:
	/* 0x18d2: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_18db:
	/* 0x18db: add    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_18e0:
	/* 0x18e0: lea    rdi,[rsp+0xbb] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 187ULL);
x86_l_18e8:
	/* 0x18e8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18ed:
	/* 0x18ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18f2:
	/* 0x18f2: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_18f7:
	/* 0x18f7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18fa:
	/* 0x18fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18fc:
	/* 0x18fc: movzx  eax,BYTE PTR [rsp+0xbb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 187ULL);
x86_l_1904:
	/* 0x1904: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1907:
	/* 0x1907: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_190a:
	/* 0x190a: je     207c <generic_kprobe_process_event+0x207c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8316ULL;
	}
x86_l_1910:
	/* 0x1910: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1913:
	/* 0x1913: jne    3449 <generic_kprobe_process_event+0x3449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13385ULL;
	}
x86_l_1919:
	/* 0x1919: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_191d:
	/* 0x191d: lea    rdi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1925:
	/* 0x1925: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_192a:
	/* 0x192a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_192f:
	/* 0x192f: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1934:
	/* 0x1934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1936:
	/* 0x1936: movzx  eax,BYTE PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 188ULL);
x86_l_193e:
	/* 0x193e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1943:
	/* 0x1943: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1947:
	/* 0x1947: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_194d:
	/* 0x194d: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1951:
	/* 0x1951: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1958:
	/* 0x1958: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1960:
	/* 0x1960: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1968:
	/* 0x1968: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1970:
	/* 0x1970: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1975:
	/* 0x1975: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_197a:
	/* 0x197a: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_197e:
	/* 0x197e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1983:
	/* 0x1983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1985:
	/* 0x1985: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1989:
	/* 0x1989: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_198e:
	/* 0x198e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1993:
	/* 0x1993: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1996:
	/* 0x1996: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_199b:
	/* 0x199b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_199e:
	/* 0x199e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a0:
	/* 0x19a0: lea    rdx,[r12+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_19a8:
	/* 0x19a8: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_19b0:
	/* 0x19b0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19b5:
	/* 0x19b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19ba:
	/* 0x19ba: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_19bf:
	/* 0x19bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c1:
	/* 0x19c1: movzx  ebp,BYTE PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 188ULL);
x86_l_19c9:
	/* 0x19c9: jmp    32db <generic_kprobe_process_event+0x32db> */
	return 13019ULL;
x86_l_19ce:
	/* 0x19ce: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_19d3:
	/* 0x19d3: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_19d8:
	/* 0x19d8: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19dd:
	/* 0x19dd: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19e1:
	/* 0x19e1: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_19e6:
	/* 0x19e6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19eb:
	/* 0x19eb: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_19f0:
	/* 0x19f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f2:
	/* 0x19f2: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_19f5:
	/* 0x19f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19f8:
	/* 0x19f8: js     2330 <generic_kprobe_process_event+0x2330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9008ULL;
	}
x86_l_19fe:
	/* 0x19fe: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1a02:
	/* 0x1a02: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a04:
	/* 0x1a04: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1a08:
	/* 0x1a08: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0d:
	/* 0x1a0d: jmp    cf2 <generic_kprobe_process_event+0xcf2> */
	return 3314ULL;
x86_l_1a12:
	/* 0x1a12: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a17:
	/* 0x1a17: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a1c:
	/* 0x1a1c: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a24:
	/* 0x1a24: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a34:
	/* 0x1a34: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a39:
	/* 0x1a39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a3e:
	/* 0x1a3e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1a41:
	/* 0x1a41: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1a46:
	/* 0x1a46: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a49:
	/* 0x1a49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4b:
	/* 0x1a4b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a4e:
	/* 0x1a4e: js     232a <generic_kprobe_process_event+0x232a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9002ULL;
	}
x86_l_1a54:
	/* 0x1a54: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a59:
	/* 0x1a59: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1a5c:
	/* 0x1a5c: je     22d5 <generic_kprobe_process_event+0x22d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8917ULL;
	}
x86_l_1a62:
	/* 0x1a62: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a65:
	/* 0x1a65: jne    2311 <generic_kprobe_process_event+0x2311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8977ULL;
	}
x86_l_1a6b:
	/* 0x1a6b: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a6f:
	/* 0x1a6f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a74:
	/* 0x1a74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a79:
	/* 0x1a79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a83:
	/* 0x1a83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a85:
	/* 0x1a85: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a89:
	/* 0x1a89: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8e:
	/* 0x1a8e: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a92:
	/* 0x1a92: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1a96:
	/* 0x1a96: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa4:
	/* 0x1aa4: jmp    2307 <generic_kprobe_process_event+0x2307> */
	return 8967ULL;
x86_l_1aa9:
	/* 0x1aa9: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1aae:
	/* 0x1aae: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1ab1:
	/* 0x1ab1: lea    rbp,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ab5:
	/* 0x1ab5: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1abc:
	/* 0x1abc: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_1ac8:
	/* 0x1ac8: test   BYTE PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691856ULL);
x86_l_1acd:
	/* 0x1acd: jne    2205 <generic_kprobe_process_event+0x2205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8709ULL;
	}
x86_l_1ad3:
	/* 0x1ad3: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    r12d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_32);
x86_l_1adb:
	/* 0x1adb: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1ade:
	/* 0x1ade: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae0:
	/* 0x1ae0: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1ae3:
	/* 0x1ae3: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1ae6:
	/* 0x1ae6: jle    2457 <generic_kprobe_process_event+0x2457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9303ULL;
	}
x86_l_1aec:
	/* 0x1aec: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1aef:
	/* 0x1aef: je     2c46 <generic_kprobe_process_event+0x2c46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11334ULL;
	}
x86_l_1af5:
	/* 0x1af5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1af8:
	/* 0x1af8: je     2c4f <generic_kprobe_process_event+0x2c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11343ULL;
	}
x86_l_1afe:
	/* 0x1afe: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1b01:
	/* 0x1b01: jne    2c62 <generic_kprobe_process_event+0x2c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11362ULL;
	}
x86_l_1b07:
	/* 0x1b07: lea    rax,[rbx+0x5e70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_1b0e:
	/* 0x1b0e: jmp    2c5f <generic_kprobe_process_event+0x2c5f> */
	return 11359ULL;
x86_l_1b13:
	/* 0x1b13: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b18:
	/* 0x1b18: lea    r13,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b1c:
	/* 0x1b1c: lea    rax,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b20:
	/* 0x1b20: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b25:
	/* 0x1b25: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b2a:
	/* 0x1b2a: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b34:
	/* 0x1b34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b39:
	/* 0x1b39: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1b3c:
	/* 0x1b3c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b41:
	/* 0x1b41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b43:
	/* 0x1b43: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b47:
	/* 0x1b47: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b51:
	/* 0x1b51: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b56:
	/* 0x1b56: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b5b:
	/* 0x1b5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5d:
	/* 0x1b5d: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b61:
	/* 0x1b61: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b66:
	/* 0x1b66: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b6b:
	/* 0x1b6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b70:
	/* 0x1b70: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b75:
	/* 0x1b75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b77:
	/* 0x1b77: lea    rdi,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b7b:
	/* 0x1b7b: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b80:
	/* 0x1b80: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b85:
	/* 0x1b85: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b8f:
	/* 0x1b8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b91:
	/* 0x1b91: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b95:
	/* 0x1b95: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b9f:
	/* 0x1b9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ba4:
	/* 0x1ba4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ba9:
	/* 0x1ba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bab:
	/* 0x1bab: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1baf:
	/* 0x1baf: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bc3:
	/* 0x1bc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc5:
	/* 0x1bc5: lea    rdi,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bc9:
	/* 0x1bc9: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bce:
	/* 0x1bce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bdd:
	/* 0x1bdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bdf:
	/* 0x1bdf: lea    rdi,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1be3:
	/* 0x1be3: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1be8:
	/* 0x1be8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bed:
	/* 0x1bed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bf7:
	/* 0x1bf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf9:
	/* 0x1bf9: mov    DWORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1c01:
	/* 0x1c01: lea    rdi,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c05:
	/* 0x1c05: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c0a:
	/* 0x1c0a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c14:
	/* 0x1c14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c19:
	/* 0x1c19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1b:
	/* 0x1c1b: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c1f:
	/* 0x1c1f: lea    rdx,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c24:
	/* 0x1c24: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c29:
	/* 0x1c29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c2e:
	/* 0x1c2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c33:
	/* 0x1c33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c35:
	/* 0x1c35: lea    rdi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c39:
	/* 0x1c39: lea    rdx,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c3e:
	/* 0x1c3e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 7235ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7245ULL: goto x86_l_1c4d;
	case 7247ULL: goto x86_l_1c4f;
	case 7252ULL: goto x86_l_1c54;
	case 7257ULL: goto x86_l_1c59;
	case 7262ULL: goto x86_l_1c5e;
	case 7265ULL: goto x86_l_1c61;
	case 7270ULL: goto x86_l_1c66;
	case 7272ULL: goto x86_l_1c68;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	case 7289ULL: goto x86_l_1c79;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7302ULL: goto x86_l_1c86;
	case 7304ULL: goto x86_l_1c88;
	case 7309ULL: goto x86_l_1c8d;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7339ULL: goto x86_l_1cab;
	case 7343ULL: goto x86_l_1caf;
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7368ULL: goto x86_l_1cc8;
	case 7372ULL: goto x86_l_1ccc;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7401ULL: goto x86_l_1ce9;
	case 7408ULL: goto x86_l_1cf0;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7421ULL: goto x86_l_1cfd;
	case 7426ULL: goto x86_l_1d02;
	case 7429ULL: goto x86_l_1d05;
	case 7431ULL: goto x86_l_1d07;
	case 7437ULL: goto x86_l_1d0d;
	case 7442ULL: goto x86_l_1d12;
	case 7445ULL: goto x86_l_1d15;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7482ULL: goto x86_l_1d3a;
	case 7485ULL: goto x86_l_1d3d;
	case 7490ULL: goto x86_l_1d42;
	case 7492ULL: goto x86_l_1d44;
	case 7496ULL: goto x86_l_1d48;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7518ULL: goto x86_l_1d5e;
	case 7520ULL: goto x86_l_1d60;
	case 7524ULL: goto x86_l_1d64;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7548ULL: goto x86_l_1d7c;
	case 7552ULL: goto x86_l_1d80;
	case 7559ULL: goto x86_l_1d87;
	case 7564ULL: goto x86_l_1d8c;
	case 7569ULL: goto x86_l_1d91;
	case 7572ULL: goto x86_l_1d94;
	case 7577ULL: goto x86_l_1d99;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7598ULL: goto x86_l_1dae;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7617ULL: goto x86_l_1dc1;
	case 7620ULL: goto x86_l_1dc4;
	case 7625ULL: goto x86_l_1dc9;
	case 7627ULL: goto x86_l_1dcb;
	case 7631ULL: goto x86_l_1dcf;
	case 7635ULL: goto x86_l_1dd3;
	case 7640ULL: goto x86_l_1dd8;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7652ULL: goto x86_l_1de4;
	case 7656ULL: goto x86_l_1de8;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7670ULL: goto x86_l_1df6;
	case 7675ULL: goto x86_l_1dfb;
	case 7677ULL: goto x86_l_1dfd;
	case 7681ULL: goto x86_l_1e01;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7700ULL: goto x86_l_1e14;
	case 7702ULL: goto x86_l_1e16;
	case 7706ULL: goto x86_l_1e1a;
	case 7710ULL: goto x86_l_1e1e;
	case 7715ULL: goto x86_l_1e23;
	case 7720ULL: goto x86_l_1e28;
	case 7723ULL: goto x86_l_1e2b;
	case 7728ULL: goto x86_l_1e30;
	case 7731ULL: goto x86_l_1e33;
	case 7733ULL: goto x86_l_1e35;
	case 7739ULL: goto x86_l_1e3b;
	case 7741ULL: goto x86_l_1e3d;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7756ULL: goto x86_l_1e4c;
	case 7761ULL: goto x86_l_1e51;
	case 7764ULL: goto x86_l_1e54;
	case 7769ULL: goto x86_l_1e59;
	case 7772ULL: goto x86_l_1e5c;
	case 7774ULL: goto x86_l_1e5e;
	case 7778ULL: goto x86_l_1e62;
	case 7782ULL: goto x86_l_1e66;
	case 7787ULL: goto x86_l_1e6b;
	case 7792ULL: goto x86_l_1e70;
	case 7797ULL: goto x86_l_1e75;
	case 7799ULL: goto x86_l_1e77;
	case 7803ULL: goto x86_l_1e7b;
	case 7807ULL: goto x86_l_1e7f;
	case 7812ULL: goto x86_l_1e84;
	case 7817ULL: goto x86_l_1e89;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7828ULL: goto x86_l_1e94;
	case 7830ULL: goto x86_l_1e96;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7878ULL: goto x86_l_1ec6;
	case 7880ULL: goto x86_l_1ec8;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7892ULL: goto x86_l_1ed4;
	case 7896ULL: goto x86_l_1ed8;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7918ULL: goto x86_l_1eee;
	case 7922ULL: goto x86_l_1ef2;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7940ULL: goto x86_l_1f04;
	case 7945ULL: goto x86_l_1f09;
	case 7950ULL: goto x86_l_1f0e;
	case 7953ULL: goto x86_l_1f11;
	case 7955ULL: goto x86_l_1f13;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7987ULL: goto x86_l_1f33;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 7997ULL: goto x86_l_1f3d;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8013ULL: goto x86_l_1f4d;
	case 8021ULL: goto x86_l_1f55;
	case 8029ULL: goto x86_l_1f5d;
	case 8037ULL: goto x86_l_1f65;
	case 8045ULL: goto x86_l_1f6d;
	case 8053ULL: goto x86_l_1f75;
	case 8061ULL: goto x86_l_1f7d;
	case 8069ULL: goto x86_l_1f85;
	case 8077ULL: goto x86_l_1f8d;
	case 8085ULL: goto x86_l_1f95;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8115ULL: goto x86_l_1fb3;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8134ULL: goto x86_l_1fc6;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8151ULL: goto x86_l_1fd7;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8169ULL: goto x86_l_1fe9;
	case 8174ULL: goto x86_l_1fee;
	case 8179ULL: goto x86_l_1ff3;
	case 8184ULL: goto x86_l_1ff8;
	case 8186ULL: goto x86_l_1ffa;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8200ULL: goto x86_l_2008;
	case 8205ULL: goto x86_l_200d;
	case 8210ULL: goto x86_l_2012;
	case 8213ULL: goto x86_l_2015;
	case 8215ULL: goto x86_l_2017;
	case 8223ULL: goto x86_l_201f;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8237ULL: goto x86_l_202d;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8255ULL: goto x86_l_203f;
	case 8262ULL: goto x86_l_2046;
	case 8268ULL: goto x86_l_204c;
	case 8276ULL: goto x86_l_2054;
	case 8280ULL: goto x86_l_2058;
	case 8285ULL: goto x86_l_205d;
	case 8288ULL: goto x86_l_2060;
	case 8291ULL: goto x86_l_2063;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8302ULL: goto x86_l_206e;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8316ULL: goto x86_l_207c;
	case 8321ULL: goto x86_l_2081;
	case 8332ULL: goto x86_l_208c;
	case 8340ULL: goto x86_l_2094;
	case 8347ULL: goto x86_l_209b;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8365ULL: goto x86_l_20ad;
	case 8369ULL: goto x86_l_20b1;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8380ULL: goto x86_l_20bc;
	case 8383ULL: goto x86_l_20bf;
	case 8386ULL: goto x86_l_20c2;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8401ULL: goto x86_l_20d1;
	case 8405ULL: goto x86_l_20d5;
	case 8410ULL: goto x86_l_20da;
	case 8415ULL: goto x86_l_20df;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8427ULL: goto x86_l_20eb;
	case 8430ULL: goto x86_l_20ee;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8444ULL: goto x86_l_20fc;
	case 8450ULL: goto x86_l_2102;
	case 8452ULL: goto x86_l_2104;
	case 8458ULL: goto x86_l_210a;
	case 8461ULL: goto x86_l_210d;
	case 8467ULL: goto x86_l_2113;
	case 8470ULL: goto x86_l_2116;
	case 8476ULL: goto x86_l_211c;
	case 8483ULL: goto x86_l_2123;
	case 8487ULL: goto x86_l_2127;
	case 8492ULL: goto x86_l_212c;
	case 8496ULL: goto x86_l_2130;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
	case 8509ULL: goto x86_l_213d;
	case 8514ULL: goto x86_l_2142;
	case 8516ULL: goto x86_l_2144;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8530ULL: goto x86_l_2152;
	case 8533ULL: goto x86_l_2155;
	case 8538ULL: goto x86_l_215a;
	case 8540ULL: goto x86_l_215c;
	case 8544ULL: goto x86_l_2160;
	case 8548ULL: goto x86_l_2164;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8562ULL: goto x86_l_2172;
	case 8567ULL: goto x86_l_2177;
	case 8570ULL: goto x86_l_217a;
	case 8572ULL: goto x86_l_217c;
	case 8576ULL: goto x86_l_2180;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8594ULL: goto x86_l_2192;
	case 8596ULL: goto x86_l_2194;
	case 8601ULL: goto x86_l_2199;
	case 8608ULL: goto x86_l_21a0;
	case 8613ULL: goto x86_l_21a5;
	case 8618ULL: goto x86_l_21aa;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8637ULL: goto x86_l_21bd;
	case 8640ULL: goto x86_l_21c0;
	case 8646ULL: goto x86_l_21c6;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8656ULL: goto x86_l_21d0;
	case 8660ULL: goto x86_l_21d4;
	case 8664ULL: goto x86_l_21d8;
	case 8667ULL: goto x86_l_21db;
	case 8670ULL: goto x86_l_21de;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8686ULL: goto x86_l_21ee;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8714ULL: goto x86_l_220a;
	case 8716ULL: goto x86_l_220c;
	case 8720ULL: goto x86_l_2210;
	case 8722ULL: goto x86_l_2212;
	case 8727ULL: goto x86_l_2217;
	case 8731ULL: goto x86_l_221b;
	case 8735ULL: goto x86_l_221f;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8763ULL: goto x86_l_223b;
	case 8771ULL: goto x86_l_2243;
	case 8779ULL: goto x86_l_224b;
	case 8786ULL: goto x86_l_2252;
	case 8788ULL: goto x86_l_2254;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8806ULL: goto x86_l_2266;
	case 8808ULL: goto x86_l_2268;
	case 8810ULL: goto x86_l_226a;
	case 8813ULL: goto x86_l_226d;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8833ULL: goto x86_l_2281;
	case 8843ULL: goto x86_l_228b;
	case 8848ULL: goto x86_l_2290;
	case 8855ULL: goto x86_l_2297;
	case 8860ULL: goto x86_l_229c;
	case 8865ULL: goto x86_l_22a1;
	case 8867ULL: goto x86_l_22a3;
	case 8870ULL: goto x86_l_22a6;
	case 8876ULL: goto x86_l_22ac;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8886ULL: goto x86_l_22b6;
	case 8892ULL: goto x86_l_22bc;
	case 8895ULL: goto x86_l_22bf;
	case 8901ULL: goto x86_l_22c5;
	case 8906ULL: goto x86_l_22ca;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8946ULL: goto x86_l_22f2;
	case 8948ULL: goto x86_l_22f4;
	case 8953ULL: goto x86_l_22f9;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8975ULL: goto x86_l_230f;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8986ULL: goto x86_l_231a;
	case 8992ULL: goto x86_l_2320;
	case 8997ULL: goto x86_l_2325;
	case 9002ULL: goto x86_l_232a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c43:
	/* 0x1c43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c48:
	/* 0x1c48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c4d:
	/* 0x1c4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4f:
	/* 0x1c4f: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c54:
	/* 0x1c54: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c59:
	/* 0x1c59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c5e:
	/* 0x1c5e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1c61:
	/* 0x1c61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c66:
	/* 0x1c66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c68:
	/* 0x1c68: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1c6f:
	/* 0x1c6f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c74:
	/* 0x1c74: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c79:
	/* 0x1c79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c83:
	/* 0x1c83: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c86:
	/* 0x1c86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c88:
	/* 0x1c88: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c8d:
	/* 0x1c8d: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c95:
	/* 0x1c95: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ca9:
	/* 0x1ca9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cab:
	/* 0x1cab: lea    rdi,[r15+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1caf:
	/* 0x1caf: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cbc:
	/* 0x1cbc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cc1:
	/* 0x1cc1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cc6:
	/* 0x1cc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc8:
	/* 0x1cc8: lea    rdi,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ccc:
	/* 0x1ccc: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1cd4:
	/* 0x1cd4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cde:
	/* 0x1cde: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ce3:
	/* 0x1ce3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce5:
	/* 0x1ce5: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1ce9:
	/* 0x1ce9: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cf5:
	/* 0x1cf5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1cfd:
	/* 0x1cfd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d02:
	/* 0x1d02: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d05:
	/* 0x1d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d07:
	/* 0x1d07: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1d0d:
	/* 0x1d0d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d12:
	/* 0x1d12: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1d15:
	/* 0x1d15: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d1a:
	/* 0x1d1a: jmp    ccb <generic_kprobe_process_event+0xccb> */
	return 3275ULL;
x86_l_1d1f:
	/* 0x1d1f: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d24:
	/* 0x1d24: lea    rdx,[r15+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1d2b:
	/* 0x1d2b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d30:
	/* 0x1d30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d35:
	/* 0x1d35: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d3a:
	/* 0x1d3a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d3d:
	/* 0x1d3d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d42:
	/* 0x1d42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d44:
	/* 0x1d44: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d48:
	/* 0x1d48: lea    rdx,[r15+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d54:
	/* 0x1d54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d59:
	/* 0x1d59: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d5e:
	/* 0x1d5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d60:
	/* 0x1d60: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d64:
	/* 0x1d64: lea    rdx,[r15+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d70:
	/* 0x1d70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d75:
	/* 0x1d75: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d7a:
	/* 0x1d7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7c:
	/* 0x1d7c: add    rbx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1d80:
	/* 0x1d80: add    r15,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1d87:
	/* 0x1d87: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d8c:
	/* 0x1d8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d91:
	/* 0x1d91: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d94:
	/* 0x1d94: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d99:
	/* 0x1d99: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d9c:
	/* 0x1d9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9e:
	/* 0x1d9e: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1da4:
	/* 0x1da4: jmp    1e9c <generic_kprobe_process_event+0x1e9c> */
	goto x86_l_1e9c;
x86_l_1da9:
	/* 0x1da9: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dae:
	/* 0x1dae: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1db2:
	/* 0x1db2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1db7:
	/* 0x1db7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dbc:
	/* 0x1dbc: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dc1:
	/* 0x1dc1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1dc4:
	/* 0x1dc4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dc9:
	/* 0x1dc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcb:
	/* 0x1dcb: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dcf:
	/* 0x1dcf: lea    rdx,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1dd3:
	/* 0x1dd3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dd8:
	/* 0x1dd8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ddd:
	/* 0x1ddd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1de2:
	/* 0x1de2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de4:
	/* 0x1de4: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de8:
	/* 0x1de8: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dec:
	/* 0x1dec: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1df1:
	/* 0x1df1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1df6:
	/* 0x1df6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dfb:
	/* 0x1dfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dfd:
	/* 0x1dfd: lea    rdi,[rbx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e01:
	/* 0x1e01: lea    rdx,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e05:
	/* 0x1e05: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e0a:
	/* 0x1e0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e14:
	/* 0x1e14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e16:
	/* 0x1e16: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e1a:
	/* 0x1e1a: add    r15,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1e1e:
	/* 0x1e1e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1e23:
	/* 0x1e23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e28:
	/* 0x1e28: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e2b:
	/* 0x1e2b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e30:
	/* 0x1e30: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e33:
	/* 0x1e33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e35:
	/* 0x1e35: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1e3b:
	/* 0x1e3b: jmp    1e9c <generic_kprobe_process_event+0x1e9c> */
	goto x86_l_1e9c;
x86_l_1e3d:
	/* 0x1e3d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e42:
	/* 0x1e42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e47:
	/* 0x1e47: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e51:
	/* 0x1e51: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e54:
	/* 0x1e54: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e59:
	/* 0x1e59: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e5c:
	/* 0x1e5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5e:
	/* 0x1e5e: lea    rdi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e62:
	/* 0x1e62: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e66:
	/* 0x1e66: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e6b:
	/* 0x1e6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e70:
	/* 0x1e70: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e75:
	/* 0x1e75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e77:
	/* 0x1e77: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e7b:
	/* 0x1e7b: add    r15,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1e7f:
	/* 0x1e7f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1e84:
	/* 0x1e84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e89:
	/* 0x1e89: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e8c:
	/* 0x1e8c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e91:
	/* 0x1e91: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e94:
	/* 0x1e94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e96:
	/* 0x1e96: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea1:
	/* 0x1ea1: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ea6:
	/* 0x1ea6: jmp    ccb <generic_kprobe_process_event+0xccb> */
	return 3275ULL;
x86_l_1eab:
	/* 0x1eab: lea    rdx,[r8+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1eaf:
	/* 0x1eaf: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1eb4:
	/* 0x1eb4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1eb9:
	/* 0x1eb9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_1ec6:
	/* 0x1ec6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec8:
	/* 0x1ec8: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ed4:
	/* 0x1ed4: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ed8:
	/* 0x1ed8: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1edd:
	/* 0x1edd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ee2:
	/* 0x1ee2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ee7:
	/* 0x1ee7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eec:
	/* 0x1eec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eee:
	/* 0x1eee: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ef2:
	/* 0x1ef2: mov    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ef6:
	/* 0x1ef6: add    r13,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1efa:
	/* 0x1efa: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1eff:
	/* 0x1eff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f04:
	/* 0x1f04: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f09:
	/* 0x1f09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f0e:
	/* 0x1f0e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1f11:
	/* 0x1f11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f13:
	/* 0x1f13: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f17:
	/* 0x1f17: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1f1c:
	/* 0x1f1c: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f21:
	/* 0x1f21: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f24:
	/* 0x1f24: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f29:
	/* 0x1f29: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f2e:
	/* 0x1f2e: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_1f33:
	/* 0x1f33: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f36:
	/* 0x1f36: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f3b:
	/* 0x1f3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3d:
	/* 0x1f3d: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1f43:
	/* 0x1f43: jmp    1059 <generic_kprobe_process_event+0x1059> */
	return 4185ULL;
x86_l_1f48:
	/* 0x1f48: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f4d:
	/* 0x1f4d: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1f55:
	/* 0x1f55: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1f5d:
	/* 0x1f5d: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1f65:
	/* 0x1f65: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1f75:
	/* 0x1f75: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1f7d:
	/* 0x1f7d: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1f85:
	/* 0x1f85: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f8d:
	/* 0x1f8d: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1f95:
	/* 0x1f95: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f9c:
	/* 0x1f9c: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1fa1:
	/* 0x1fa1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fab:
	/* 0x1fab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb0:
	/* 0x1fb0: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1fb3:
	/* 0x1fb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb5:
	/* 0x1fb5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb8:
	/* 0x1fb8: je     233a <generic_kprobe_process_event+0x233a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9018ULL;
	}
x86_l_1fbe:
	/* 0x1fbe: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fc1:
	/* 0x1fc1: jmp    cc1 <generic_kprobe_process_event+0xcc1> */
	return 3265ULL;
x86_l_1fc6:
	/* 0x1fc6: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1fcd:
	/* 0x1fcd: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_1fd2:
	/* 0x1fd2: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd7:
	/* 0x1fd7: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1fdf:
	/* 0x1fdf: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1fe4:
	/* 0x1fe4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fe9:
	/* 0x1fe9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fee:
	/* 0x1fee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ff3:
	/* 0x1ff3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ff8:
	/* 0x1ff8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ffa:
	/* 0x1ffa: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1ffe:
	/* 0x1ffe: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2003:
	/* 0x2003: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2008:
	/* 0x2008: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_200d:
	/* 0x200d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2012:
	/* 0x2012: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2015:
	/* 0x2015: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2017:
	/* 0x2017: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_201f:
	/* 0x201f: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2024:
	/* 0x2024: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2029:
	/* 0x2029: lea    r12,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_202d:
	/* 0x202d: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2034:
	/* 0x2034: test   BYTE PTR [rsp+0x50],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383712ULL);
x86_l_2039:
	/* 0x2039: je     2b37 <generic_kprobe_process_event+0x2b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11063ULL;
	}
x86_l_203f:
	/* 0x203f: cmp    rbx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4096ULL);
x86_l_2046:
	/* 0x2046: jb     2b0b <generic_kprobe_process_event+0x2b0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11019ULL;
	}
x86_l_204c:
	/* 0x204c: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2054:
	/* 0x2054: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2058:
	/* 0x2058: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_205d:
	/* 0x205d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2060:
	/* 0x2060: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_2063:
	/* 0x2063: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2066:
	/* 0x2066: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8299ULL);
	__x86_sim_call_depth++;
	return 14249ULL;
x86_l_206b:
	/* 0x206b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_206e:
	/* 0x206e: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2072:
	/* 0x2072: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2077:
	/* 0x2077: jmp    ced <generic_kprobe_process_event+0xced> */
	return 3309ULL;
x86_l_207c:
	/* 0x207c: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2081:
	/* 0x2081: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_208c:
	/* 0x208c: movzx  ebp,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_2094:
	/* 0x2094: mov    rdi,QWORD PTR [rip+0x256] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_209b:
	/* 0x209b: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_20a3:
	/* 0x20a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20a8:
	/* 0x20a8: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20ad:
	/* 0x20ad: lea    r13,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_20b1:
	/* 0x20b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b3:
	/* 0x20b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20b6:
	/* 0x20b6: je     3288 <generic_kprobe_process_event+0x3288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12936ULL;
	}
x86_l_20bc:
	/* 0x20bc: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_20bf:
	/* 0x20bf: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20c2:
	/* 0x20c2: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_20c6:
	/* 0x20c6: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_20ca:
	/* 0x20ca: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_20cd:
	/* 0x20cd: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_20d1:
	/* 0x20d1: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_20d5:
	/* 0x20d5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_20da:
	/* 0x20da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20df:
	/* 0x20df: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20e4:
	/* 0x20e4: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_20e9:
	/* 0x20e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20eb:
	/* 0x20eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20ee:
	/* 0x20ee: js     3288 <generic_kprobe_process_event+0x3288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12936ULL;
	}
x86_l_20f4:
	/* 0x20f4: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_20f9:
	/* 0x20f9: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_20fc:
	/* 0x20fc: jg     2b84 <generic_kprobe_process_event+0x2b84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11140ULL;
	}
x86_l_2102:
	/* 0x2102: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2104:
	/* 0x2104: je     2c35 <generic_kprobe_process_event+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_210a:
	/* 0x210a: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_210d:
	/* 0x210d: je     2c35 <generic_kprobe_process_event+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2113:
	/* 0x2113: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2116:
	/* 0x2116: jne    2e09 <generic_kprobe_process_event+0x2e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11785ULL;
	}
x86_l_211c:
	/* 0x211c: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2123:
	/* 0x2123: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2127:
	/* 0x2127: jmp    2d53 <generic_kprobe_process_event+0x2d53> */
	return 11603ULL;
x86_l_212c:
	/* 0x212c: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2130:
	/* 0x2130: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2135:
	/* 0x2135: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_213a:
	/* 0x213a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_213d:
	/* 0x213d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2142:
	/* 0x2142: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2144:
	/* 0x2144: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2148:
	/* 0x2148: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_214d:
	/* 0x214d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2152:
	/* 0x2152: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2155:
	/* 0x2155: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_215a:
	/* 0x215a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_215c:
	/* 0x215c: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2160:
	/* 0x2160: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2164:
	/* 0x2164: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2168:
	/* 0x2168: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_216d:
	/* 0x216d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2172:
	/* 0x2172: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2177:
	/* 0x2177: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_217a:
	/* 0x217a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217c:
	/* 0x217c: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2180:
	/* 0x2180: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2185:
	/* 0x2185: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_218a:
	/* 0x218a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_218f:
	/* 0x218f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2192:
	/* 0x2192: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2194:
	/* 0x2194: movzx  eax,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2199:
	/* 0x2199: movbe  WORD PTR [r13+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_21a0:
	/* 0x21a0: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21a5:
	/* 0x21a5: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_21aa:
	/* 0x21aa: mov    rdi,QWORD PTR [rip+0x256] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_21b1:
	/* 0x21b1: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_21b6:
	/* 0x21b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21bb:
	/* 0x21bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21bd:
	/* 0x21bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21c0:
	/* 0x21c0: je     3449 <generic_kprobe_process_event+0x3449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13385ULL;
	}
x86_l_21c6:
	/* 0x21c6: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c8:
	/* 0x21c8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21cd:
	/* 0x21cd: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d0:
	/* 0x21d0: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d4:
	/* 0x21d4: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21d8:
	/* 0x21d8: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21db:
	/* 0x21db: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_21de:
	/* 0x21de: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_21e4:
	/* 0x21e4: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_21e9:
	/* 0x21e9: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21ee:
	/* 0x21ee: mov    QWORD PTR [rbp+rax*1+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 618475290624ULL);
x86_l_21fa:
	/* 0x21fa: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_2200:
	/* 0x2200: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_2205:
	/* 0x2205: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_220a:
	/* 0x220a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220c:
	/* 0x220c: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2210:
	/* 0x2210: jne    221b <generic_kprobe_process_event+0x221b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_221b;
	}
x86_l_2212:
	/* 0x2212: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2217:
	/* 0x2217: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_221b:
	/* 0x221b: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_221f:
	/* 0x221f: mov    rdx,QWORD PTR [rbx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2223:
	/* 0x2223: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2228:
	/* 0x2228: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_222d:
	/* 0x222d: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2232:
	/* 0x2232: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_223b:
	/* 0x223b: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2243:
	/* 0x2243: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_224b:
	/* 0x224b: mov    rdi,QWORD PTR [rip+0x256] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2252:
	/* 0x2252: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2254:
	/* 0x2254: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_225c:
	/* 0x225c: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2261:
	/* 0x2261: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2266:
	/* 0x2266: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2268:
	/* 0x2268: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226a:
	/* 0x226a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_226d:
	/* 0x226d: je     2bdb <generic_kprobe_process_event+0x2bdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11227ULL;
	}
x86_l_2273:
	/* 0x2273: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2275:
	/* 0x2275: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_227a:
	/* 0x227a: mov    WORD PTR [rsp+0x5a],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 386547056645ULL);
x86_l_2281:
	/* 0x2281: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_228b:
	/* 0x228b: mov    QWORD PTR [rsp+0x5c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2290:
	/* 0x2290: mov    rdi,QWORD PTR [rip+0x256] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2297:
	/* 0x2297: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_229c:
	/* 0x229c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22a1:
	/* 0x22a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a3:
	/* 0x22a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22a6:
	/* 0x22a6: je     2bb1 <generic_kprobe_process_event+0x2bb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11185ULL;
	}
x86_l_22ac:
	/* 0x22ac: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_22ae:
	/* 0x22ae: jmp    2bdb <generic_kprobe_process_event+0x2bdb> */
	return 11227ULL;
x86_l_22b3:
	/* 0x22b3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22b6:
	/* 0x22b6: je     2557 <generic_kprobe_process_event+0x2557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9559ULL;
	}
x86_l_22bc:
	/* 0x22bc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22bf:
	/* 0x22bf: jne    29be <generic_kprobe_process_event+0x29be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10686ULL;
	}
x86_l_22c5:
	/* 0x22c5: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22ca:
	/* 0x22ca: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_22d0:
	/* 0x22d0: jmp    2562 <generic_kprobe_process_event+0x2562> */
	return 9570ULL;
x86_l_22d5:
	/* 0x22d5: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22da:
	/* 0x22da: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22df:
	/* 0x22df: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22e3:
	/* 0x22e3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_22e8:
	/* 0x22e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22ed:
	/* 0x22ed: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22f2:
	/* 0x22f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f4:
	/* 0x22f4: lea    rdi,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_22f9:
	/* 0x22f9: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_22fd:
	/* 0x22fd: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2302:
	/* 0x2302: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2307:
	/* 0x2307: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_230c:
	/* 0x230c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_230f:
	/* 0x230f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2311:
	/* 0x2311: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2316:
	/* 0x2316: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_231a:
	/* 0x231a: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2320:
	/* 0x2320: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2325:
	/* 0x2325: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_232a:
	/* 0x232a: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
	return 9008ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9008ULL: goto x86_l_2330;
	case 9013ULL: goto x86_l_2335;
	case 9018ULL: goto x86_l_233a;
	case 9023ULL: goto x86_l_233f;
	case 9027ULL: goto x86_l_2343;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	case 9042ULL: goto x86_l_2352;
	case 9047ULL: goto x86_l_2357;
	case 9052ULL: goto x86_l_235c;
	case 9054ULL: goto x86_l_235e;
	case 9057ULL: goto x86_l_2361;
	case 9063ULL: goto x86_l_2367;
	case 9068ULL: goto x86_l_236c;
	case 9072ULL: goto x86_l_2370;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9090ULL: goto x86_l_2382;
	case 9095ULL: goto x86_l_2387;
	case 9097ULL: goto x86_l_2389;
	case 9102ULL: goto x86_l_238e;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9147ULL: goto x86_l_23bb;
	case 9151ULL: goto x86_l_23bf;
	case 9159ULL: goto x86_l_23c7;
	case 9164ULL: goto x86_l_23cc;
	case 9169ULL: goto x86_l_23d1;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9179ULL: goto x86_l_23db;
	case 9185ULL: goto x86_l_23e1;
	case 9188ULL: goto x86_l_23e4;
	case 9194ULL: goto x86_l_23ea;
	case 9196ULL: goto x86_l_23ec;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	case 9212ULL: goto x86_l_23fc;
	case 9214ULL: goto x86_l_23fe;
	case 9219ULL: goto x86_l_2403;
	case 9222ULL: goto x86_l_2406;
	case 9225ULL: goto x86_l_2409;
	case 9228ULL: goto x86_l_240c;
	case 9231ULL: goto x86_l_240f;
	case 9236ULL: goto x86_l_2414;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9282ULL: goto x86_l_2442;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9312ULL: goto x86_l_2460;
	case 9315ULL: goto x86_l_2463;
	case 9321ULL: goto x86_l_2469;
	case 9328ULL: goto x86_l_2470;
	case 9333ULL: goto x86_l_2475;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9352ULL: goto x86_l_2488;
	case 9357ULL: goto x86_l_248d;
	case 9359ULL: goto x86_l_248f;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9383ULL: goto x86_l_24a7;
	case 9388ULL: goto x86_l_24ac;
	case 9392ULL: goto x86_l_24b0;
	case 9396ULL: goto x86_l_24b4;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9418ULL: goto x86_l_24ca;
	case 9420ULL: goto x86_l_24cc;
	case 9424ULL: goto x86_l_24d0;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9439ULL: goto x86_l_24df;
	case 9442ULL: goto x86_l_24e2;
	case 9444ULL: goto x86_l_24e4;
	case 9448ULL: goto x86_l_24e8;
	case 9454ULL: goto x86_l_24ee;
	case 9459ULL: goto x86_l_24f3;
	case 9463ULL: goto x86_l_24f7;
	case 9468ULL: goto x86_l_24fc;
	case 9475ULL: goto x86_l_2503;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9487ULL: goto x86_l_250f;
	case 9490ULL: goto x86_l_2512;
	case 9492ULL: goto x86_l_2514;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9502ULL: goto x86_l_251e;
	case 9506ULL: goto x86_l_2522;
	case 9510ULL: goto x86_l_2526;
	case 9513ULL: goto x86_l_2529;
	case 9516ULL: goto x86_l_252c;
	case 9522ULL: goto x86_l_2532;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9551ULL: goto x86_l_254f;
	case 9557ULL: goto x86_l_2555;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9570ULL: goto x86_l_2562;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9584ULL: goto x86_l_2570;
	case 9587ULL: goto x86_l_2573;
	case 9593ULL: goto x86_l_2579;
	case 9598ULL: goto x86_l_257e;
	case 9604ULL: goto x86_l_2584;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9626ULL: goto x86_l_259a;
	case 9631ULL: goto x86_l_259f;
	case 9633ULL: goto x86_l_25a1;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9664ULL: goto x86_l_25c0;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9690ULL: goto x86_l_25da;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9703ULL: goto x86_l_25e7;
	case 9708ULL: goto x86_l_25ec;
	case 9713ULL: goto x86_l_25f1;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9722ULL: goto x86_l_25fa;
	case 9728ULL: goto x86_l_2600;
	case 9732ULL: goto x86_l_2604;
	case 9738ULL: goto x86_l_260a;
	case 9743ULL: goto x86_l_260f;
	case 9747ULL: goto x86_l_2613;
	case 9752ULL: goto x86_l_2618;
	case 9758ULL: goto x86_l_261e;
	case 9763ULL: goto x86_l_2623;
	case 9768ULL: goto x86_l_2628;
	case 9773ULL: goto x86_l_262d;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9782ULL: goto x86_l_2636;
	case 9788ULL: goto x86_l_263c;
	case 9793ULL: goto x86_l_2641;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9809ULL: goto x86_l_2651;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9825ULL: goto x86_l_2661;
	case 9830ULL: goto x86_l_2666;
	case 9836ULL: goto x86_l_266c;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9859ULL: goto x86_l_2683;
	case 9861ULL: goto x86_l_2685;
	case 9866ULL: goto x86_l_268a;
	case 9868ULL: goto x86_l_268c;
	case 9874ULL: goto x86_l_2692;
	case 9879ULL: goto x86_l_2697;
	case 9884ULL: goto x86_l_269c;
	case 9888ULL: goto x86_l_26a0;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9903ULL: goto x86_l_26af;
	case 9908ULL: goto x86_l_26b4;
	case 9914ULL: goto x86_l_26ba;
	case 9919ULL: goto x86_l_26bf;
	case 9924ULL: goto x86_l_26c4;
	case 9929ULL: goto x86_l_26c9;
	case 9931ULL: goto x86_l_26cb;
	case 9936ULL: goto x86_l_26d0;
	case 9938ULL: goto x86_l_26d2;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9962ULL: goto x86_l_26ea;
	case 9968ULL: goto x86_l_26f0;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9995ULL: goto x86_l_270b;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10008ULL: goto x86_l_2718;
	case 10016ULL: goto x86_l_2720;
	case 10021ULL: goto x86_l_2725;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10030ULL: goto x86_l_272e;
	case 10036ULL: goto x86_l_2734;
	case 10044ULL: goto x86_l_273c;
	case 10049ULL: goto x86_l_2741;
	case 10053ULL: goto x86_l_2745;
	case 10059ULL: goto x86_l_274b;
	case 10064ULL: goto x86_l_2750;
	case 10068ULL: goto x86_l_2754;
	case 10073ULL: goto x86_l_2759;
	case 10079ULL: goto x86_l_275f;
	case 10084ULL: goto x86_l_2764;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10103ULL: goto x86_l_2777;
	case 10109ULL: goto x86_l_277d;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10130ULL: goto x86_l_2792;
	case 10136ULL: goto x86_l_2798;
	case 10144ULL: goto x86_l_27a0;
	case 10149ULL: goto x86_l_27a5;
	case 10157ULL: goto x86_l_27ad;
	case 10163ULL: goto x86_l_27b3;
	case 10166ULL: goto x86_l_27b6;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10181ULL: goto x86_l_27c5;
	case 10186ULL: goto x86_l_27ca;
	case 10188ULL: goto x86_l_27cc;
	case 10193ULL: goto x86_l_27d1;
	case 10195ULL: goto x86_l_27d3;
	case 10201ULL: goto x86_l_27d9;
	case 10206ULL: goto x86_l_27de;
	case 10211ULL: goto x86_l_27e3;
	case 10215ULL: goto x86_l_27e7;
	case 10221ULL: goto x86_l_27ed;
	case 10226ULL: goto x86_l_27f2;
	case 10230ULL: goto x86_l_27f6;
	case 10235ULL: goto x86_l_27fb;
	case 10241ULL: goto x86_l_2801;
	case 10246ULL: goto x86_l_2806;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10258ULL: goto x86_l_2812;
	case 10263ULL: goto x86_l_2817;
	case 10265ULL: goto x86_l_2819;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10292ULL: goto x86_l_2834;
	case 10298ULL: goto x86_l_283a;
	case 10303ULL: goto x86_l_283f;
	case 10311ULL: goto x86_l_2847;
	case 10316ULL: goto x86_l_284c;
	case 10322ULL: goto x86_l_2852;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10347ULL: goto x86_l_286b;
	case 10352ULL: goto x86_l_2870;
	case 10354ULL: goto x86_l_2872;
	case 10360ULL: goto x86_l_2878;
	case 10365ULL: goto x86_l_287d;
	case 10370ULL: goto x86_l_2882;
	case 10374ULL: goto x86_l_2886;
	case 10380ULL: goto x86_l_288c;
	case 10385ULL: goto x86_l_2891;
	case 10389ULL: goto x86_l_2895;
	case 10394ULL: goto x86_l_289a;
	case 10400ULL: goto x86_l_28a0;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10424ULL: goto x86_l_28b8;
	case 10430ULL: goto x86_l_28be;
	case 10435ULL: goto x86_l_28c3;
	case 10440ULL: goto x86_l_28c8;
	case 10448ULL: goto x86_l_28d0;
	case 10454ULL: goto x86_l_28d6;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10475ULL: goto x86_l_28eb;
	case 10481ULL: goto x86_l_28f1;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10502ULL: goto x86_l_2906;
	case 10507ULL: goto x86_l_290b;
	case 10509ULL: goto x86_l_290d;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10522ULL: goto x86_l_291a;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10539ULL: goto x86_l_292b;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10554ULL: goto x86_l_293a;
	case 10559ULL: goto x86_l_293f;
	case 10565ULL: goto x86_l_2945;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10589ULL: goto x86_l_295d;
	case 10591ULL: goto x86_l_295f;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10608ULL: goto x86_l_2970;
	case 10610ULL: goto x86_l_2972;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10629ULL: goto x86_l_2985;
	case 10632ULL: goto x86_l_2988;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10650ULL: goto x86_l_299a;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10659ULL: goto x86_l_29a3;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10689ULL: goto x86_l_29c1;
	case 10694ULL: goto x86_l_29c6;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10717ULL: goto x86_l_29dd;
	case 10721ULL: goto x86_l_29e1;
	case 10723ULL: goto x86_l_29e3;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10736ULL: goto x86_l_29f0;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10750ULL: goto x86_l_29fe;
	case 10755ULL: goto x86_l_2a03;
	case 10760ULL: goto x86_l_2a08;
	case 10768ULL: goto x86_l_2a10;
	case 10776ULL: goto x86_l_2a18;
	case 10783ULL: goto x86_l_2a1f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2330:
	/* 0x2330: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2335:
	/* 0x2335: jmp    cf2 <generic_kprobe_process_event+0xcf2> */
	return 3314ULL;
x86_l_233a:
	/* 0x233a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_233f:
	/* 0x233f: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2343:
	/* 0x2343: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2348:
	/* 0x2348: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_234d:
	/* 0x234d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2352:
	/* 0x2352: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2357:
	/* 0x2357: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_235c:
	/* 0x235c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235e:
	/* 0x235e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2361:
	/* 0x2361: js     1fbe <generic_kprobe_process_event+0x1fbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8126ULL;
	}
x86_l_2367:
	/* 0x2367: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_236c:
	/* 0x236c: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2370:
	/* 0x2370: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2378:
	/* 0x2378: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_237d:
	/* 0x237d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2382:
	/* 0x2382: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2387:
	/* 0x2387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2389:
	/* 0x2389: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_238e:
	/* 0x238e: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2392:
	/* 0x2392: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_2397:
	/* 0x2397: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_239f:
	/* 0x239f: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23a2:
	/* 0x23a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a7:
	/* 0x23a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ac:
	/* 0x23ac: add    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_23b4:
	/* 0x23b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b9:
	/* 0x23b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23bb:
	/* 0x23bb: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_23bf:
	/* 0x23bf: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_23c7:
	/* 0x23c7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_23cc:
	/* 0x23cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23d1:
	/* 0x23d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23d6:
	/* 0x23d6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23d9:
	/* 0x23d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23db:
	/* 0x23db: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_23e1:
	/* 0x23e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23e4:
	/* 0x23e4: jne    cc1 <generic_kprobe_process_event+0xcc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3265ULL;
	}
x86_l_23ea:
	/* 0x23ea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23ec:
	/* 0x23ec: cmp    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_23f4:
	/* 0x23f4: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_23f7:
	/* 0x23f7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23fc:
	/* 0x23fc: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23fe:
	/* 0x23fe: jmp    cc1 <generic_kprobe_process_event+0xcc1> */
	return 3265ULL;
x86_l_2403:
	/* 0x2403: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2406:
	/* 0x2406: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2409:
	/* 0x2409: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_240c:
	/* 0x240c: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_240f:
	/* 0x240f: jmp    cc6 <generic_kprobe_process_event+0xcc6> */
	return 3270ULL;
x86_l_2414:
	/* 0x2414: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_2418:
	/* 0x2418: mov    ecx,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 107ULL);
x86_l_241d:
	/* 0x241d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2422:
	/* 0x2422: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_2427:
	/* 0x2427: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_242a:
	/* 0x242a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242c:
	/* 0x242c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_242f:
	/* 0x242f: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_2431:
	/* 0x2431: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2433:
	/* 0x2433: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2438:
	/* 0x2438: js     2442 <generic_kprobe_process_event+0x2442> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2442;
	}
x86_l_243a:
	/* 0x243a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_243f:
	/* 0x243f: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_2442:
	/* 0x2442: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_2448:
	/* 0x2448: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_244d:
	/* 0x244d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2452:
	/* 0x2452: jmp    cf2 <generic_kprobe_process_event+0xcf2> */
	return 3314ULL;
x86_l_2457:
	/* 0x2457: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_245a:
	/* 0x245a: je     2c58 <generic_kprobe_process_event+0x2c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11352ULL;
	}
x86_l_2460:
	/* 0x2460: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2463:
	/* 0x2463: jne    2c62 <generic_kprobe_process_event+0x2c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11362ULL;
	}
x86_l_2469:
	/* 0x2469: lea    rax,[rbx+0x5e58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_2470:
	/* 0x2470: jmp    2c5f <generic_kprobe_process_event+0x2c5f> */
	return 11359ULL;
x86_l_2475:
	/* 0x2475: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2479:
	/* 0x2479: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_247e:
	/* 0x247e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2483:
	/* 0x2483: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2488:
	/* 0x2488: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_248d:
	/* 0x248d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248f:
	/* 0x248f: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2493:
	/* 0x2493: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2498:
	/* 0x2498: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_249d:
	/* 0x249d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_24a0:
	/* 0x24a0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24a5:
	/* 0x24a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a7:
	/* 0x24a7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ac:
	/* 0x24ac: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24b0:
	/* 0x24b0: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_24b4:
	/* 0x24b4: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_24b8:
	/* 0x24b8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_24bd:
	/* 0x24bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24c2:
	/* 0x24c2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24c7:
	/* 0x24c7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_24ca:
	/* 0x24ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24cc:
	/* 0x24cc: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_24d0:
	/* 0x24d0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_24d5:
	/* 0x24d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24da:
	/* 0x24da: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24df:
	/* 0x24df: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24e2:
	/* 0x24e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e4:
	/* 0x24e4: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_24e8:
	/* 0x24e8: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_24ee:
	/* 0x24ee: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24f3:
	/* 0x24f3: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24f7:
	/* 0x24f7: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24fc:
	/* 0x24fc: mov    rdi,QWORD PTR [rip+0x256] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2503:
	/* 0x2503: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2508:
	/* 0x2508: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_250d:
	/* 0x250d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250f:
	/* 0x250f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2512:
	/* 0x2512: je     252c <generic_kprobe_process_event+0x252c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_252c;
	}
x86_l_2514:
	/* 0x2514: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2516:
	/* 0x2516: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_251b:
	/* 0x251b: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_251e:
	/* 0x251e: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2522:
	/* 0x2522: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2526:
	/* 0x2526: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2529:
	/* 0x2529: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_252c:
	/* 0x252c: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_2532:
	/* 0x2532: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2535:
	/* 0x2535: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_2538:
	/* 0x2538: jmp    f54 <generic_kprobe_process_event+0xf54> */
	return 3924ULL;
x86_l_253d:
	/* 0x253d: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2542:
	/* 0x2542: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_2548:
	/* 0x2548: jmp    2562 <generic_kprobe_process_event+0x2562> */
	goto x86_l_2562;
x86_l_254a:
	/* 0x254a: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_254f:
	/* 0x254f: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2555:
	/* 0x2555: jmp    2562 <generic_kprobe_process_event+0x2562> */
	goto x86_l_2562;
x86_l_2557:
	/* 0x2557: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_255c:
	/* 0x255c: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_2562:
	/* 0x2562: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2565:
	/* 0x2565: test   BYTE PTR [rsp+0x50],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383696ULL);
x86_l_256a:
	/* 0x256a: jne    29d6 <generic_kprobe_process_event+0x29d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29d6;
	}
x86_l_2570:
	/* 0x2570: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_2573:
	/* 0x2573: je     2a80 <generic_kprobe_process_event+0x2a80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10880ULL;
	}
x86_l_2579:
	/* 0x2579: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_257e:
	/* 0x257e: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2584:
	/* 0x2584: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2589:
	/* 0x2589: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_258e:
	/* 0x258e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2593:
	/* 0x2593: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2598:
	/* 0x2598: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259a:
	/* 0x259a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_259f:
	/* 0x259f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25a1:
	/* 0x25a1: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_25a7:
	/* 0x25a7: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25ac:
	/* 0x25ac: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_25b1:
	/* 0x25b1: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_25b4:
	/* 0x25b4: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25b9:
	/* 0x25b9: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_25c0:
	/* 0x25c0: ja     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29af;
	}
x86_l_25c6:
	/* 0x25c6: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25cb:
	/* 0x25cb: lea    rdi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_25cf:
	/* 0x25cf: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25d4:
	/* 0x25d4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25da:
	/* 0x25da: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25dd:
	/* 0x25dd: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25e2:
	/* 0x25e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e7:
	/* 0x25e7: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ec:
	/* 0x25ec: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25f1:
	/* 0x25f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f3:
	/* 0x25f3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25f8:
	/* 0x25f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25fa:
	/* 0x25fa: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_2600:
	/* 0x2600: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_2604:
	/* 0x2604: je     2a87 <generic_kprobe_process_event+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10887ULL;
	}
x86_l_260a:
	/* 0x260a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_260f:
	/* 0x260f: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2613:
	/* 0x2613: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2618:
	/* 0x2618: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_261e:
	/* 0x261e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2623:
	/* 0x2623: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2628:
	/* 0x2628: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_262d:
	/* 0x262d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_262f:
	/* 0x262f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2634:
	/* 0x2634: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2636:
	/* 0x2636: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_263c:
	/* 0x263c: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2641:
	/* 0x2641: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2646:
	/* 0x2646: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_264b:
	/* 0x264b: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2651:
	/* 0x2651: ja     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29af;
	}
x86_l_2657:
	/* 0x2657: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_265c:
	/* 0x265c: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2661:
	/* 0x2661: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2666:
	/* 0x2666: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_266c:
	/* 0x266c: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_266f:
	/* 0x266f: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2674:
	/* 0x2674: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2679:
	/* 0x2679: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_267e:
	/* 0x267e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2683:
	/* 0x2683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2685:
	/* 0x2685: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_268a:
	/* 0x268a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_268c:
	/* 0x268c: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_2692:
	/* 0x2692: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2697:
	/* 0x2697: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_269c:
	/* 0x269c: cmp    r12,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 3ULL);
x86_l_26a0:
	/* 0x26a0: jb     2a87 <generic_kprobe_process_event+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10887ULL;
	}
x86_l_26a6:
	/* 0x26a6: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26ab:
	/* 0x26ab: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26af:
	/* 0x26af: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_26b4:
	/* 0x26b4: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_26ba:
	/* 0x26ba: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_26bf:
	/* 0x26bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26c4:
	/* 0x26c4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26c9:
	/* 0x26c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26cb:
	/* 0x26cb: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_26d0:
	/* 0x26d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26d2:
	/* 0x26d2: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_26d8:
	/* 0x26d8: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26dd:
	/* 0x26dd: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_26e2:
	/* 0x26e2: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26ea:
	/* 0x26ea: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_26f0:
	/* 0x26f0: ja     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29af;
	}
x86_l_26f6:
	/* 0x26f6: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26fb:
	/* 0x26fb: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2700:
	/* 0x2700: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2705:
	/* 0x2705: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_270b:
	/* 0x270b: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_270e:
	/* 0x270e: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2713:
	/* 0x2713: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2718:
	/* 0x2718: mov    rsi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2720:
	/* 0x2720: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2725:
	/* 0x2725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2727:
	/* 0x2727: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_272c:
	/* 0x272c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_272e:
	/* 0x272e: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_2734:
	/* 0x2734: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_273c:
	/* 0x273c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2741:
	/* 0x2741: cmp    r12,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 3ULL);
x86_l_2745:
	/* 0x2745: je     2a87 <generic_kprobe_process_event+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10887ULL;
	}
x86_l_274b:
	/* 0x274b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2750:
	/* 0x2750: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2754:
	/* 0x2754: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2759:
	/* 0x2759: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_275f:
	/* 0x275f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2764:
	/* 0x2764: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2769:
	/* 0x2769: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_276e:
	/* 0x276e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2770:
	/* 0x2770: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2775:
	/* 0x2775: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2777:
	/* 0x2777: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_277d:
	/* 0x277d: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2782:
	/* 0x2782: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2787:
	/* 0x2787: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_278c:
	/* 0x278c: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2792:
	/* 0x2792: ja     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29af;
	}
x86_l_2798:
	/* 0x2798: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_27a0:
	/* 0x27a0: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_27a5:
	/* 0x27a5: mov    QWORD PTR [rsp+0xc0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_27ad:
	/* 0x27ad: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27b3:
	/* 0x27b3: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27b6:
	/* 0x27b6: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27bb:
	/* 0x27bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27c0:
	/* 0x27c0: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27c5:
	/* 0x27c5: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27ca:
	/* 0x27ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cc:
	/* 0x27cc: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27d1:
	/* 0x27d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27d3:
	/* 0x27d3: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_27d9:
	/* 0x27d9: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27de:
	/* 0x27de: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_27e3:
	/* 0x27e3: cmp    r12,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 5ULL);
x86_l_27e7:
	/* 0x27e7: jb     2a87 <generic_kprobe_process_event+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10887ULL;
	}
x86_l_27ed:
	/* 0x27ed: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27f2:
	/* 0x27f2: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27f6:
	/* 0x27f6: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27fb:
	/* 0x27fb: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2801:
	/* 0x2801: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2806:
	/* 0x2806: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_280b:
	/* 0x280b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2810:
	/* 0x2810: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2812:
	/* 0x2812: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2817:
	/* 0x2817: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2819:
	/* 0x2819: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_281f:
	/* 0x281f: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2824:
	/* 0x2824: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2829:
	/* 0x2829: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_282e:
	/* 0x282e: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2834:
	/* 0x2834: ja     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29af;
	}
x86_l_283a:
	/* 0x283a: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_283f:
	/* 0x283f: add    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 192ULL);
x86_l_2847:
	/* 0x2847: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_284c:
	/* 0x284c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2852:
	/* 0x2852: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2855:
	/* 0x2855: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_285a:
	/* 0x285a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_285f:
	/* 0x285f: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2864:
	/* 0x2864: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2869:
	/* 0x2869: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_286b:
	/* 0x286b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2870:
	/* 0x2870: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2872:
	/* 0x2872: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_2878:
	/* 0x2878: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_287d:
	/* 0x287d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2882:
	/* 0x2882: cmp    r12,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 5ULL);
x86_l_2886:
	/* 0x2886: je     2a87 <generic_kprobe_process_event+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10887ULL;
	}
x86_l_288c:
	/* 0x288c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2891:
	/* 0x2891: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2895:
	/* 0x2895: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_289a:
	/* 0x289a: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_28a0:
	/* 0x28a0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_28a5:
	/* 0x28a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28aa:
	/* 0x28aa: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28af:
	/* 0x28af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b1:
	/* 0x28b1: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28b6:
	/* 0x28b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28b8:
	/* 0x28b8: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_28be:
	/* 0x28be: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_28c3:
	/* 0x28c3: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_28c8:
	/* 0x28c8: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_28d0:
	/* 0x28d0: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_28d6:
	/* 0x28d6: ja     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29af;
	}
x86_l_28dc:
	/* 0x28dc: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28e1:
	/* 0x28e1: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_28e6:
	/* 0x28e6: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28eb:
	/* 0x28eb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_28f1:
	/* 0x28f1: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28f4:
	/* 0x28f4: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28f9:
	/* 0x28f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28fe:
	/* 0x28fe: mov    rsi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2906:
	/* 0x2906: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_290b:
	/* 0x290b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290d:
	/* 0x290d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2912:
	/* 0x2912: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2914:
	/* 0x2914: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_291a:
	/* 0x291a: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2922:
	/* 0x2922: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2927:
	/* 0x2927: cmp    r12,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 7ULL);
x86_l_292b:
	/* 0x292b: jb     2a87 <generic_kprobe_process_event+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10887ULL;
	}
x86_l_2931:
	/* 0x2931: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2936:
	/* 0x2936: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_293a:
	/* 0x293a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_293f:
	/* 0x293f: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2945:
	/* 0x2945: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_294a:
	/* 0x294a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_294f:
	/* 0x294f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2954:
	/* 0x2954: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2956:
	/* 0x2956: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_295b:
	/* 0x295b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_295d:
	/* 0x295d: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_295f:
	/* 0x295f: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2964:
	/* 0x2964: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2969:
	/* 0x2969: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_2970:
	/* 0x2970: ja     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29af;
	}
x86_l_2972:
	/* 0x2972: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_297a:
	/* 0x297a: add    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_297f:
	/* 0x297f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2985:
	/* 0x2985: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2988:
	/* 0x2988: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_298d:
	/* 0x298d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2992:
	/* 0x2992: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2997:
	/* 0x2997: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_299a:
	/* 0x299a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299c:
	/* 0x299c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_29a1:
	/* 0x29a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29a3:
	/* 0x29a3: js     29af <generic_kprobe_process_event+0x29af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29af;
	}
x86_l_29a5:
	/* 0x29a5: add    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_29aa:
	/* 0x29aa: jmp    2a87 <generic_kprobe_process_event+0x2a87> */
	return 10887ULL;
x86_l_29af:
	/* 0x29af: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29b4:
	/* 0x29b4: mov    DWORD PTR [r13+rax*1+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_29b9:
	/* 0x29b9: jmp    2c25 <generic_kprobe_process_event+0x2c25> */
	return 11301ULL;
x86_l_29be:
	/* 0x29be: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29c1:
	/* 0x29c1: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_29c6:
	/* 0x29c6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29cb:
	/* 0x29cb: test   BYTE PTR [rsp+0x50],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383696ULL);
x86_l_29d0:
	/* 0x29d0: je     2a87 <generic_kprobe_process_event+0x2a87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10887ULL;
	}
x86_l_29d6:
	/* 0x29d6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_29db:
	/* 0x29db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29dd:
	/* 0x29dd: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_29e1:
	/* 0x29e1: jne    29e7 <generic_kprobe_process_event+0x29e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29e7;
	}
x86_l_29e3:
	/* 0x29e3: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29e7:
	/* 0x29e7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29ec:
	/* 0x29ec: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29f0:
	/* 0x29f0: mov    rdx,QWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_29f4:
	/* 0x29f4: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_29f9:
	/* 0x29f9: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29fe:
	/* 0x29fe: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a03:
	/* 0x2a03: mov    QWORD PTR [rsp+0x78],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2a08:
	/* 0x2a08: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a10:
	/* 0x2a10: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2a18:
	/* 0x2a18: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2a1f:
	/* 0x2a1f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
	return 10785ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10785ULL: goto x86_l_2a21;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10805ULL: goto x86_l_2a35;
	case 10807ULL: goto x86_l_2a37;
	case 10810ULL: goto x86_l_2a3a;
	case 10816ULL: goto x86_l_2a40;
	case 10818ULL: goto x86_l_2a42;
	case 10823ULL: goto x86_l_2a47;
	case 10830ULL: goto x86_l_2a4e;
	case 10840ULL: goto x86_l_2a58;
	case 10845ULL: goto x86_l_2a5d;
	case 10852ULL: goto x86_l_2a64;
	case 10857ULL: goto x86_l_2a69;
	case 10862ULL: goto x86_l_2a6e;
	case 10864ULL: goto x86_l_2a70;
	case 10867ULL: goto x86_l_2a73;
	case 10873ULL: goto x86_l_2a79;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10907ULL: goto x86_l_2a9b;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10923ULL: goto x86_l_2aab;
	case 10929ULL: goto x86_l_2ab1;
	case 10934ULL: goto x86_l_2ab6;
	case 10937ULL: goto x86_l_2ab9;
	case 10943ULL: goto x86_l_2abf;
	case 10946ULL: goto x86_l_2ac2;
	case 10952ULL: goto x86_l_2ac8;
	case 10959ULL: goto x86_l_2acf;
	case 10965ULL: goto x86_l_2ad5;
	case 10969ULL: goto x86_l_2ad9;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10981ULL: goto x86_l_2ae5;
	case 10983ULL: goto x86_l_2ae7;
	case 10985ULL: goto x86_l_2ae9;
	case 10987ULL: goto x86_l_2aeb;
	case 10990ULL: goto x86_l_2aee;
	case 10994ULL: goto x86_l_2af2;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11008ULL: goto x86_l_2b00;
	case 11014ULL: goto x86_l_2b06;
	case 11019ULL: goto x86_l_2b0b;
	case 11026ULL: goto x86_l_2b12;
	case 11034ULL: goto x86_l_2b1a;
	case 11039ULL: goto x86_l_2b1f;
	case 11043ULL: goto x86_l_2b23;
	case 11050ULL: goto x86_l_2b2a;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11063ULL: goto x86_l_2b37;
	case 11070ULL: goto x86_l_2b3e;
	case 11076ULL: goto x86_l_2b44;
	case 11080ULL: goto x86_l_2b48;
	case 11085ULL: goto x86_l_2b4d;
	case 11090ULL: goto x86_l_2b52;
	case 11096ULL: goto x86_l_2b58;
	case 11099ULL: goto x86_l_2b5b;
	case 11101ULL: goto x86_l_2b5d;
	case 11103ULL: goto x86_l_2b5f;
	case 11105ULL: goto x86_l_2b61;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11119ULL: goto x86_l_2b6f;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11143ULL: goto x86_l_2b87;
	case 11149ULL: goto x86_l_2b8d;
	case 11152ULL: goto x86_l_2b90;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11169ULL: goto x86_l_2ba1;
	case 11176ULL: goto x86_l_2ba8;
	case 11180ULL: goto x86_l_2bac;
	case 11185ULL: goto x86_l_2bb1;
	case 11196ULL: goto x86_l_2bbc;
	case 11203ULL: goto x86_l_2bc3;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11218ULL: goto x86_l_2bd2;
	case 11223ULL: goto x86_l_2bd7;
	case 11225ULL: goto x86_l_2bd9;
	case 11227ULL: goto x86_l_2bdb;
	case 11234ULL: goto x86_l_2be2;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11253ULL: goto x86_l_2bf5;
	case 11260ULL: goto x86_l_2bfc;
	case 11262ULL: goto x86_l_2bfe;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11279ULL: goto x86_l_2c0f;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11295ULL: goto x86_l_2c1f;
	case 11301ULL: goto x86_l_2c25;
	case 11306ULL: goto x86_l_2c2a;
	case 11309ULL: goto x86_l_2c2d;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11329ULL: goto x86_l_2c41;
	case 11334ULL: goto x86_l_2c46;
	case 11341ULL: goto x86_l_2c4d;
	case 11343ULL: goto x86_l_2c4f;
	case 11350ULL: goto x86_l_2c56;
	case 11352ULL: goto x86_l_2c58;
	case 11359ULL: goto x86_l_2c5f;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11375ULL: goto x86_l_2c6f;
	case 11380ULL: goto x86_l_2c74;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11396ULL: goto x86_l_2c84;
	case 11401ULL: goto x86_l_2c89;
	case 11403ULL: goto x86_l_2c8b;
	case 11411ULL: goto x86_l_2c93;
	case 11415ULL: goto x86_l_2c97;
	case 11417ULL: goto x86_l_2c99;
	case 11424ULL: goto x86_l_2ca0;
	case 11426ULL: goto x86_l_2ca2;
	case 11433ULL: goto x86_l_2ca9;
	case 11437ULL: goto x86_l_2cad;
	case 11442ULL: goto x86_l_2cb2;
	case 11445ULL: goto x86_l_2cb5;
	case 11448ULL: goto x86_l_2cb8;
	case 11453ULL: goto x86_l_2cbd;
	case 11456ULL: goto x86_l_2cc0;
	case 11461ULL: goto x86_l_2cc5;
	case 11464ULL: goto x86_l_2cc8;
	case 11468ULL: goto x86_l_2ccc;
	case 11473ULL: goto x86_l_2cd1;
	case 11478ULL: goto x86_l_2cd6;
	case 11485ULL: goto x86_l_2cdd;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11500ULL: goto x86_l_2cec;
	case 11506ULL: goto x86_l_2cf2;
	case 11509ULL: goto x86_l_2cf5;
	case 11515ULL: goto x86_l_2cfb;
	case 11522ULL: goto x86_l_2d02;
	case 11527ULL: goto x86_l_2d07;
	case 11531ULL: goto x86_l_2d0b;
	case 11535ULL: goto x86_l_2d0f;
	case 11540ULL: goto x86_l_2d14;
	case 11545ULL: goto x86_l_2d19;
	case 11547ULL: goto x86_l_2d1b;
	case 11549ULL: goto x86_l_2d1d;
	case 11551ULL: goto x86_l_2d1f;
	case 11553ULL: goto x86_l_2d21;
	case 11557ULL: goto x86_l_2d25;
	case 11560ULL: goto x86_l_2d28;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11575ULL: goto x86_l_2d37;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11591ULL: goto x86_l_2d47;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11607ULL: goto x86_l_2d57;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11620ULL: goto x86_l_2d64;
	case 11626ULL: goto x86_l_2d6a;
	case 11636ULL: goto x86_l_2d74;
	case 11640ULL: goto x86_l_2d78;
	case 11646ULL: goto x86_l_2d7e;
	case 11650ULL: goto x86_l_2d82;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11676ULL: goto x86_l_2d9c;
	case 11680ULL: goto x86_l_2da0;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11690ULL: goto x86_l_2daa;
	case 11693ULL: goto x86_l_2dad;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11711ULL: goto x86_l_2dbf;
	case 11713ULL: goto x86_l_2dc1;
	case 11716ULL: goto x86_l_2dc4;
	case 11718ULL: goto x86_l_2dc6;
	case 11721ULL: goto x86_l_2dc9;
	case 11723ULL: goto x86_l_2dcb;
	case 11730ULL: goto x86_l_2dd2;
	case 11734ULL: goto x86_l_2dd6;
	case 11736ULL: goto x86_l_2dd8;
	case 11739ULL: goto x86_l_2ddb;
	case 11741ULL: goto x86_l_2ddd;
	case 11744ULL: goto x86_l_2de0;
	case 11746ULL: goto x86_l_2de2;
	case 11751ULL: goto x86_l_2de7;
	case 11753ULL: goto x86_l_2de9;
	case 11760ULL: goto x86_l_2df0;
	case 11764ULL: goto x86_l_2df4;
	case 11766ULL: goto x86_l_2df6;
	case 11771ULL: goto x86_l_2dfb;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11795ULL: goto x86_l_2e13;
	case 11800ULL: goto x86_l_2e18;
	case 11807ULL: goto x86_l_2e1f;
	case 11812ULL: goto x86_l_2e24;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11823ULL: goto x86_l_2e2f;
	case 11827ULL: goto x86_l_2e33;
	case 11832ULL: goto x86_l_2e38;
	case 11836ULL: goto x86_l_2e3c;
	case 11842ULL: goto x86_l_2e42;
	case 11852ULL: goto x86_l_2e4c;
	case 11856ULL: goto x86_l_2e50;
	case 11862ULL: goto x86_l_2e56;
	case 11866ULL: goto x86_l_2e5a;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11877ULL: goto x86_l_2e65;
	case 11882ULL: goto x86_l_2e6a;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11896ULL: goto x86_l_2e78;
	case 11899ULL: goto x86_l_2e7b;
	case 11904ULL: goto x86_l_2e80;
	case 11906ULL: goto x86_l_2e82;
	case 11909ULL: goto x86_l_2e85;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11923ULL: goto x86_l_2e93;
	case 11925ULL: goto x86_l_2e95;
	case 11927ULL: goto x86_l_2e97;
	case 11929ULL: goto x86_l_2e99;
	case 11932ULL: goto x86_l_2e9c;
	case 11934ULL: goto x86_l_2e9e;
	case 11937ULL: goto x86_l_2ea1;
	case 11939ULL: goto x86_l_2ea3;
	case 11946ULL: goto x86_l_2eaa;
	case 11950ULL: goto x86_l_2eae;
	case 11952ULL: goto x86_l_2eb0;
	case 11955ULL: goto x86_l_2eb3;
	case 11957ULL: goto x86_l_2eb5;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11967ULL: goto x86_l_2ebf;
	case 11969ULL: goto x86_l_2ec1;
	case 11976ULL: goto x86_l_2ec8;
	case 11980ULL: goto x86_l_2ecc;
	case 11982ULL: goto x86_l_2ece;
	case 11987ULL: goto x86_l_2ed3;
	case 11994ULL: goto x86_l_2eda;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12006ULL: goto x86_l_2ee6;
	case 12013ULL: goto x86_l_2eed;
	case 12018ULL: goto x86_l_2ef2;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12029ULL: goto x86_l_2efd;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12042ULL: goto x86_l_2f0a;
	case 12048ULL: goto x86_l_2f10;
	case 12058ULL: goto x86_l_2f1a;
	case 12062ULL: goto x86_l_2f1e;
	case 12068ULL: goto x86_l_2f24;
	case 12072ULL: goto x86_l_2f28;
	case 12075ULL: goto x86_l_2f2b;
	case 12080ULL: goto x86_l_2f30;
	case 12083ULL: goto x86_l_2f33;
	case 12088ULL: goto x86_l_2f38;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12102ULL: goto x86_l_2f46;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12112ULL: goto x86_l_2f50;
	case 12115ULL: goto x86_l_2f53;
	case 12121ULL: goto x86_l_2f59;
	case 12126ULL: goto x86_l_2f5e;
	case 12129ULL: goto x86_l_2f61;
	case 12131ULL: goto x86_l_2f63;
	case 12133ULL: goto x86_l_2f65;
	case 12135ULL: goto x86_l_2f67;
	case 12138ULL: goto x86_l_2f6a;
	case 12140ULL: goto x86_l_2f6c;
	case 12143ULL: goto x86_l_2f6f;
	case 12145ULL: goto x86_l_2f71;
	case 12152ULL: goto x86_l_2f78;
	case 12156ULL: goto x86_l_2f7c;
	case 12158ULL: goto x86_l_2f7e;
	case 12161ULL: goto x86_l_2f81;
	case 12163ULL: goto x86_l_2f83;
	case 12166ULL: goto x86_l_2f86;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12175ULL: goto x86_l_2f8f;
	case 12182ULL: goto x86_l_2f96;
	case 12186ULL: goto x86_l_2f9a;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12200ULL: goto x86_l_2fa8;
	case 12205ULL: goto x86_l_2fad;
	case 12207ULL: goto x86_l_2faf;
	case 12212ULL: goto x86_l_2fb4;
	case 12219ULL: goto x86_l_2fbb;
	case 12224ULL: goto x86_l_2fc0;
	case 12226ULL: goto x86_l_2fc2;
	case 12231ULL: goto x86_l_2fc7;
	case 12235ULL: goto x86_l_2fcb;
	case 12239ULL: goto x86_l_2fcf;
	case 12244ULL: goto x86_l_2fd4;
	case 12248ULL: goto x86_l_2fd8;
	case 12254ULL: goto x86_l_2fde;
	case 12264ULL: goto x86_l_2fe8;
	case 12268ULL: goto x86_l_2fec;
	case 12274ULL: goto x86_l_2ff2;
	case 12278ULL: goto x86_l_2ff6;
	case 12281ULL: goto x86_l_2ff9;
	case 12286ULL: goto x86_l_2ffe;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12304ULL: goto x86_l_3010;
	case 12308ULL: goto x86_l_3014;
	case 12311ULL: goto x86_l_3017;
	case 12316ULL: goto x86_l_301c;
	case 12318ULL: goto x86_l_301e;
	case 12321ULL: goto x86_l_3021;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12335ULL: goto x86_l_302f;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12341ULL: goto x86_l_3035;
	case 12344ULL: goto x86_l_3038;
	case 12346ULL: goto x86_l_303a;
	case 12349ULL: goto x86_l_303d;
	case 12351ULL: goto x86_l_303f;
	case 12358ULL: goto x86_l_3046;
	case 12362ULL: goto x86_l_304a;
	case 12364ULL: goto x86_l_304c;
	case 12367ULL: goto x86_l_304f;
	case 12369ULL: goto x86_l_3051;
	case 12372ULL: goto x86_l_3054;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12381ULL: goto x86_l_305d;
	case 12388ULL: goto x86_l_3064;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12399ULL: goto x86_l_306f;
	case 12406ULL: goto x86_l_3076;
	case 12411ULL: goto x86_l_307b;
	case 12413ULL: goto x86_l_307d;
	case 12418ULL: goto x86_l_3082;
	case 12425ULL: goto x86_l_3089;
	case 12430ULL: goto x86_l_308e;
	case 12432ULL: goto x86_l_3090;
	case 12437ULL: goto x86_l_3095;
	case 12441ULL: goto x86_l_3099;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12454ULL: goto x86_l_30a6;
	case 12460ULL: goto x86_l_30ac;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a21:
	/* 0x2a21: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a29:
	/* 0x2a29: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2a2e:
	/* 0x2a2e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a33:
	/* 0x2a33: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a35:
	/* 0x2a35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a37:
	/* 0x2a37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a3a:
	/* 0x2a3a: je     2c11 <generic_kprobe_process_event+0x2c11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c11;
	}
x86_l_2a40:
	/* 0x2a40: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2a42:
	/* 0x2a42: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a47:
	/* 0x2a47: mov    WORD PTR [rsp+0x5a],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 386547056645ULL);
x86_l_2a4e:
	/* 0x2a4e: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2a58:
	/* 0x2a58: mov    QWORD PTR [rsp+0x5c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2a5d:
	/* 0x2a5d: mov    rdi,QWORD PTR [rip+0x256] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2a64:
	/* 0x2a64: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a69:
	/* 0x2a69: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a6e:
	/* 0x2a6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a70:
	/* 0x2a70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a73:
	/* 0x2a73: je     2bed <generic_kprobe_process_event+0x2bed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bed;
	}
x86_l_2a79:
	/* 0x2a79: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2a7b:
	/* 0x2a7b: jmp    2c11 <generic_kprobe_process_event+0x2c11> */
	goto x86_l_2c11;
x86_l_2a80:
	/* 0x2a80: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a82:
	/* 0x2a82: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a87:
	/* 0x2a87: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a8c:
	/* 0x2a8c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a91:
	/* 0x2a91: mov    DWORD PTR [r13+rax*1+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a96:
	/* 0x2a96: mov    DWORD PTR [r13+rax*1+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_2a9b:
	/* 0x2a9b: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a9f:
	/* 0x2a9f: jmp    2c25 <generic_kprobe_process_event+0x2c25> */
	goto x86_l_2c25;
x86_l_2aa4:
	/* 0x2aa4: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2aab:
	/* 0x2aab: mov    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ab1:
	/* 0x2ab1: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ab6:
	/* 0x2ab6: lea    ebx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ab9:
	/* 0x2ab9: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2abf:
	/* 0x2abf: add    rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ac2:
	/* 0x2ac2: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_2ac8:
	/* 0x2ac8: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_2acf:
	/* 0x2acf: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_2ad5:
	/* 0x2ad5: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2ad9:
	/* 0x2ad9: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2add:
	/* 0x2add: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ae2:
	/* 0x2ae2: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2ae5:
	/* 0x2ae5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae7:
	/* 0x2ae7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ae9:
	/* 0x2ae9: js     2afa <generic_kprobe_process_event+0x2afa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2afa;
	}
x86_l_2aeb:
	/* 0x2aeb: mov    DWORD PTR [rbx],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aee:
	/* 0x2aee: mov    DWORD PTR [rbx+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2af2:
	/* 0x2af2: add    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2af5:
	/* 0x2af5: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_2afa:
	/* 0x2afa: mov    DWORD PTR [rbx],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2b00:
	/* 0x2b00: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2b06:
	/* 0x2b06: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_2b0b:
	/* 0x2b0b: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2b12:
	/* 0x2b12: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b1f:
	/* 0x2b1f: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b23:
	/* 0x2b23: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b2a:
	/* 0x2b2a: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b2d:
	/* 0x2b2d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b32:
	/* 0x2b32: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b37:
	/* 0x2b37: cmp    rbx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4095ULL);
x86_l_2b3e:
	/* 0x2b3e: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_2b44:
	/* 0x2b44: cmovb  r13,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBX, X86_WIDTH_64, X86_CC_B);
x86_l_2b48:
	/* 0x2b48: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b4d:
	/* 0x2b4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b52:
	/* 0x2b52: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2b58:
	/* 0x2b58: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2b5b:
	/* 0x2b5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5d:
	/* 0x2b5d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b5f:
	/* 0x2b5f: js     2b77 <generic_kprobe_process_event+0x2b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b77;
	}
x86_l_2b61:
	/* 0x2b61: mov    DWORD PTR [r12],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b65:
	/* 0x2b65: mov    DWORD PTR [r12+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b6f:
	/* 0x2b6f: add    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b72:
	/* 0x2b72: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_2b77:
	/* 0x2b77: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2b7f:
	/* 0x2b7f: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_2b84:
	/* 0x2b84: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2b87:
	/* 0x2b87: je     2d42 <generic_kprobe_process_event+0x2d42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d42;
	}
x86_l_2b8d:
	/* 0x2b8d: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2b90:
	/* 0x2b90: je     2c35 <generic_kprobe_process_event+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2b96:
	/* 0x2b96: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2b9b:
	/* 0x2b9b: jne    2e09 <generic_kprobe_process_event+0x2e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e09;
	}
x86_l_2ba1:
	/* 0x2ba1: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2ba8:
	/* 0x2ba8: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2bac:
	/* 0x2bac: jmp    2d53 <generic_kprobe_process_event+0x2d53> */
	goto x86_l_2d53;
x86_l_2bb1:
	/* 0x2bb1: mov    DWORD PTR [rsp+0xc8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459201ULL);
x86_l_2bbc:
	/* 0x2bbc: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2bc3:
	/* 0x2bc3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bc5:
	/* 0x2bc5: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2bca:
	/* 0x2bca: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2bd2:
	/* 0x2bd2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bd7:
	/* 0x2bd7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bd9:
	/* 0x2bd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdb:
	/* 0x2bdb: mov    DWORD PTR [rbp+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_2be2:
	/* 0x2be2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2be8:
	/* 0x2be8: jmp    f4a <generic_kprobe_process_event+0xf4a> */
	return 3914ULL;
x86_l_2bed:
	/* 0x2bed: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_2bf5:
	/* 0x2bf5: mov    rdi,QWORD PTR [rip+0x250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2bfc:
	/* 0x2bfc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bfe:
	/* 0x2bfe: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c03:
	/* 0x2c03: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c08:
	/* 0x2c08: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c0d:
	/* 0x2c0d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c0f:
	/* 0x2c0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c11:
	/* 0x2c11: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c16:
	/* 0x2c16: mov    DWORD PTR [r13+rax*1+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2c25:
	/* 0x2c25: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c2a:
	/* 0x2c2a: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_2c2d:
	/* 0x2c2d: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_2c30:
	/* 0x2c30: jmp    cc6 <generic_kprobe_process_event+0xcc6> */
	return 3270ULL;
x86_l_2c35:
	/* 0x2c35: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c3a:
	/* 0x2c3a: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2c41:
	/* 0x2c41: jmp    2d4e <generic_kprobe_process_event+0x2d4e> */
	goto x86_l_2d4e;
x86_l_2c46:
	/* 0x2c46: lea    rax,[rbx+0x5e60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_2c4d:
	/* 0x2c4d: jmp    2c5f <generic_kprobe_process_event+0x2c5f> */
	goto x86_l_2c5f;
x86_l_2c4f:
	/* 0x2c4f: lea    rax,[rbx+0x5e68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2c56:
	/* 0x2c56: jmp    2c5f <generic_kprobe_process_event+0x2c5f> */
	goto x86_l_2c5f;
x86_l_2c58:
	/* 0x2c58: lea    rax,[rbx+0x5e50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_2c5f:
	/* 0x2c5f: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c62:
	/* 0x2c62: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c67:
	/* 0x2c67: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c6f:
	/* 0x2c6f: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c74:
	/* 0x2c74: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c79:
	/* 0x2c79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c7e:
	/* 0x2c7e: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_2c84:
	/* 0x2c84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c89:
	/* 0x2c89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8b:
	/* 0x2c8b: mov    r13,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c93:
	/* 0x2c93: test   r12b,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 32ULL);
x86_l_2c97:
	/* 0x2c97: je     2cfb <generic_kprobe_process_event+0x2cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cfb;
	}
x86_l_2c99:
	/* 0x2c99: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_2ca0:
	/* 0x2ca0: jb     2cd6 <generic_kprobe_process_event+0x2cd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2cd6;
	}
x86_l_2ca2:
	/* 0x2ca2: mov    DWORD PTR [rbp+0x0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ca9:
	/* 0x2ca9: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2cad:
	/* 0x2cad: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cb2:
	/* 0x2cb2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2cb5:
	/* 0x2cb5: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_2cb8:
	/* 0x2cb8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cbd:
	/* 0x2cbd: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2cc0:
	/* 0x2cc0: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 11461ULL);
	__x86_sim_call_depth++;
	return 14249ULL;
x86_l_2cc5:
	/* 0x2cc5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2cc8:
	/* 0x2cc8: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd1:
	/* 0x2cd1: jmp    f54 <generic_kprobe_process_event+0xf54> */
	return 3924ULL;
x86_l_2cd6:
	/* 0x2cd6: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2cdd:
	/* 0x2cdd: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce4:
	/* 0x2ce4: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ce9:
	/* 0x2ce9: lea    ebp,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cec:
	/* 0x2cec: and    ebp,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2cf2:
	/* 0x2cf2: add    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cf5:
	/* 0x2cf5: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_2cfb:
	/* 0x2cfb: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_2d02:
	/* 0x2d02: mov    ebx,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4095ULL);
x86_l_2d07:
	/* 0x2d07: cmovb  rbx,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2d0b:
	/* 0x2d0b: lea    rdi,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d14:
	/* 0x2d14: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d19:
	/* 0x2d19: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2d1b:
	/* 0x2d1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1d:
	/* 0x2d1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d1f:
	/* 0x2d1f: js     2d30 <generic_kprobe_process_event+0x2d30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2d30;
	}
x86_l_2d21:
	/* 0x2d21: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d25:
	/* 0x2d25: mov    DWORD PTR [rbp+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d28:
	/* 0x2d28: add    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d2b:
	/* 0x2d2b: jmp    f4a <generic_kprobe_process_event+0xf4a> */
	return 3914ULL;
x86_l_2d30:
	/* 0x2d30: mov    DWORD PTR [rbp+0x0],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2d37:
	/* 0x2d37: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2d3d:
	/* 0x2d3d: jmp    f4a <generic_kprobe_process_event+0xf4a> */
	return 3914ULL;
x86_l_2d42:
	/* 0x2d42: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d47:
	/* 0x2d47: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2d4e:
	/* 0x2d4e: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d53:
	/* 0x2d53: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d57:
	/* 0x2d57: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d5b:
	/* 0x2d5b: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2d60:
	/* 0x2d60: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2d64:
	/* 0x2d64: ja     3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13396ULL;
	}
x86_l_2d6a:
	/* 0x2d6a: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2d74:
	/* 0x2d74: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2d78:
	/* 0x2d78: jae    3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13396ULL;
	}
x86_l_2d7e:
	/* 0x2d7e: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2d82:
	/* 0x2d82: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d85:
	/* 0x2d85: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d8a:
	/* 0x2d8a: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d8d:
	/* 0x2d8d: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2d92:
	/* 0x2d92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d97:
	/* 0x2d97: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d9c:
	/* 0x2d9c: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2da0:
	/* 0x2da0: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2da3:
	/* 0x2da3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2da8:
	/* 0x2da8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2daa:
	/* 0x2daa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2dad:
	/* 0x2dad: js     3288 <generic_kprobe_process_event+0x3288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12936ULL;
	}
x86_l_2db3:
	/* 0x2db3: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2db8:
	/* 0x2db8: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2dbb:
	/* 0x2dbb: jg     2dd8 <generic_kprobe_process_event+0x2dd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2dd8;
	}
x86_l_2dbd:
	/* 0x2dbd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dbf:
	/* 0x2dbf: je     2df6 <generic_kprobe_process_event+0x2df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df6;
	}
x86_l_2dc1:
	/* 0x2dc1: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2dc4:
	/* 0x2dc4: je     2df6 <generic_kprobe_process_event+0x2df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df6;
	}
x86_l_2dc6:
	/* 0x2dc6: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2dc9:
	/* 0x2dc9: jne    2e26 <generic_kprobe_process_event+0x2e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e26;
	}
x86_l_2dcb:
	/* 0x2dcb: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2dd2:
	/* 0x2dd2: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2dd6:
	/* 0x2dd6: jmp    2e2b <generic_kprobe_process_event+0x2e2b> */
	goto x86_l_2e2b;
x86_l_2dd8:
	/* 0x2dd8: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2ddb:
	/* 0x2ddb: je     2e13 <generic_kprobe_process_event+0x2e13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e13;
	}
x86_l_2ddd:
	/* 0x2ddd: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2de0:
	/* 0x2de0: je     2df6 <generic_kprobe_process_event+0x2df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df6;
	}
x86_l_2de2:
	/* 0x2de2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2de7:
	/* 0x2de7: jne    2e26 <generic_kprobe_process_event+0x2e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e26;
	}
x86_l_2de9:
	/* 0x2de9: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2df0:
	/* 0x2df0: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2df4:
	/* 0x2df4: jmp    2e2b <generic_kprobe_process_event+0x2e2b> */
	goto x86_l_2e2b;
x86_l_2df6:
	/* 0x2df6: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2dfb:
	/* 0x2dfb: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2e02:
	/* 0x2e02: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2e07:
	/* 0x2e07: jmp    2e2b <generic_kprobe_process_event+0x2e2b> */
	goto x86_l_2e2b;
x86_l_2e09:
	/* 0x2e09: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2e0e:
	/* 0x2e0e: jmp    2d53 <generic_kprobe_process_event+0x2d53> */
	goto x86_l_2d53;
x86_l_2e13:
	/* 0x2e13: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e18:
	/* 0x2e18: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2e1f:
	/* 0x2e1f: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2e24:
	/* 0x2e24: jmp    2e2b <generic_kprobe_process_event+0x2e2b> */
	goto x86_l_2e2b;
x86_l_2e26:
	/* 0x2e26: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2e2b:
	/* 0x2e2b: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e2f:
	/* 0x2e2f: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e33:
	/* 0x2e33: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2e38:
	/* 0x2e38: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2e3c:
	/* 0x2e3c: ja     3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13396ULL;
	}
x86_l_2e42:
	/* 0x2e42: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2e4c:
	/* 0x2e4c: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2e50:
	/* 0x2e50: jae    3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13396ULL;
	}
x86_l_2e56:
	/* 0x2e56: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2e5a:
	/* 0x2e5a: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e5d:
	/* 0x2e5d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e62:
	/* 0x2e62: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e65:
	/* 0x2e65: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2e6a:
	/* 0x2e6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e6f:
	/* 0x2e6f: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e74:
	/* 0x2e74: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e78:
	/* 0x2e78: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e7b:
	/* 0x2e7b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2e80:
	/* 0x2e80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e82:
	/* 0x2e82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e85:
	/* 0x2e85: js     3288 <generic_kprobe_process_event+0x3288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12936ULL;
	}
x86_l_2e8b:
	/* 0x2e8b: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2e90:
	/* 0x2e90: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2e93:
	/* 0x2e93: jg     2eb0 <generic_kprobe_process_event+0x2eb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2eb0;
	}
x86_l_2e95:
	/* 0x2e95: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e97:
	/* 0x2e97: je     2ece <generic_kprobe_process_event+0x2ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ece;
	}
x86_l_2e99:
	/* 0x2e99: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2e9c:
	/* 0x2e9c: je     2ece <generic_kprobe_process_event+0x2ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ece;
	}
x86_l_2e9e:
	/* 0x2e9e: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2ea1:
	/* 0x2ea1: jne    2ef4 <generic_kprobe_process_event+0x2ef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ef4;
	}
x86_l_2ea3:
	/* 0x2ea3: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2eaa:
	/* 0x2eaa: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2eae:
	/* 0x2eae: jmp    2ef9 <generic_kprobe_process_event+0x2ef9> */
	goto x86_l_2ef9;
x86_l_2eb0:
	/* 0x2eb0: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2eb3:
	/* 0x2eb3: je     2ee1 <generic_kprobe_process_event+0x2ee1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee1;
	}
x86_l_2eb5:
	/* 0x2eb5: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2eb8:
	/* 0x2eb8: je     2ece <generic_kprobe_process_event+0x2ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ece;
	}
x86_l_2eba:
	/* 0x2eba: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2ebf:
	/* 0x2ebf: jne    2ef4 <generic_kprobe_process_event+0x2ef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ef4;
	}
x86_l_2ec1:
	/* 0x2ec1: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2ec8:
	/* 0x2ec8: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2ecc:
	/* 0x2ecc: jmp    2ef9 <generic_kprobe_process_event+0x2ef9> */
	goto x86_l_2ef9;
x86_l_2ece:
	/* 0x2ece: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ed3:
	/* 0x2ed3: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2eda:
	/* 0x2eda: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2edf:
	/* 0x2edf: jmp    2ef9 <generic_kprobe_process_event+0x2ef9> */
	goto x86_l_2ef9;
x86_l_2ee1:
	/* 0x2ee1: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ee6:
	/* 0x2ee6: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2eed:
	/* 0x2eed: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ef2:
	/* 0x2ef2: jmp    2ef9 <generic_kprobe_process_event+0x2ef9> */
	goto x86_l_2ef9;
x86_l_2ef4:
	/* 0x2ef4: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2ef9:
	/* 0x2ef9: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2efd:
	/* 0x2efd: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f01:
	/* 0x2f01: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2f06:
	/* 0x2f06: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2f0a:
	/* 0x2f0a: ja     3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13396ULL;
	}
x86_l_2f10:
	/* 0x2f10: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2f1a:
	/* 0x2f1a: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2f1e:
	/* 0x2f1e: jae    3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13396ULL;
	}
x86_l_2f24:
	/* 0x2f24: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2f28:
	/* 0x2f28: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f2b:
	/* 0x2f2b: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f30:
	/* 0x2f30: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f33:
	/* 0x2f33: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2f38:
	/* 0x2f38: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f3d:
	/* 0x2f3d: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f42:
	/* 0x2f42: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f46:
	/* 0x2f46: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f49:
	/* 0x2f49: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f4e:
	/* 0x2f4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f50:
	/* 0x2f50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f53:
	/* 0x2f53: js     3288 <generic_kprobe_process_event+0x3288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12936ULL;
	}
x86_l_2f59:
	/* 0x2f59: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2f5e:
	/* 0x2f5e: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2f61:
	/* 0x2f61: jg     2f7e <generic_kprobe_process_event+0x2f7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f7e;
	}
x86_l_2f63:
	/* 0x2f63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f65:
	/* 0x2f65: je     2f9c <generic_kprobe_process_event+0x2f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9c;
	}
x86_l_2f67:
	/* 0x2f67: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2f6a:
	/* 0x2f6a: je     2f9c <generic_kprobe_process_event+0x2f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9c;
	}
x86_l_2f6c:
	/* 0x2f6c: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2f6f:
	/* 0x2f6f: jne    2fc2 <generic_kprobe_process_event+0x2fc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fc2;
	}
x86_l_2f71:
	/* 0x2f71: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2f78:
	/* 0x2f78: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2f7c:
	/* 0x2f7c: jmp    2fc7 <generic_kprobe_process_event+0x2fc7> */
	goto x86_l_2fc7;
x86_l_2f7e:
	/* 0x2f7e: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2f81:
	/* 0x2f81: je     2faf <generic_kprobe_process_event+0x2faf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2faf;
	}
x86_l_2f83:
	/* 0x2f83: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2f86:
	/* 0x2f86: je     2f9c <generic_kprobe_process_event+0x2f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9c;
	}
x86_l_2f88:
	/* 0x2f88: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2f8d:
	/* 0x2f8d: jne    2fc2 <generic_kprobe_process_event+0x2fc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fc2;
	}
x86_l_2f8f:
	/* 0x2f8f: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2f96:
	/* 0x2f96: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2f9a:
	/* 0x2f9a: jmp    2fc7 <generic_kprobe_process_event+0x2fc7> */
	goto x86_l_2fc7;
x86_l_2f9c:
	/* 0x2f9c: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2fa1:
	/* 0x2fa1: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2fa8:
	/* 0x2fa8: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2fad:
	/* 0x2fad: jmp    2fc7 <generic_kprobe_process_event+0x2fc7> */
	goto x86_l_2fc7;
x86_l_2faf:
	/* 0x2faf: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2fb4:
	/* 0x2fb4: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2fbb:
	/* 0x2fbb: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2fc0:
	/* 0x2fc0: jmp    2fc7 <generic_kprobe_process_event+0x2fc7> */
	goto x86_l_2fc7;
x86_l_2fc2:
	/* 0x2fc2: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2fc7:
	/* 0x2fc7: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2fcb:
	/* 0x2fcb: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fcf:
	/* 0x2fcf: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2fd4:
	/* 0x2fd4: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2fd8:
	/* 0x2fd8: ja     3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13396ULL;
	}
x86_l_2fde:
	/* 0x2fde: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2fe8:
	/* 0x2fe8: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2fec:
	/* 0x2fec: jae    3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13396ULL;
	}
x86_l_2ff2:
	/* 0x2ff2: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2ff6:
	/* 0x2ff6: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2ff9:
	/* 0x2ff9: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ffe:
	/* 0x2ffe: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3001:
	/* 0x3001: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3006:
	/* 0x3006: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_300b:
	/* 0x300b: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3010:
	/* 0x3010: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3014:
	/* 0x3014: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3017:
	/* 0x3017: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_301c:
	/* 0x301c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301e:
	/* 0x301e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3021:
	/* 0x3021: js     3288 <generic_kprobe_process_event+0x3288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12936ULL;
	}
x86_l_3027:
	/* 0x3027: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_302c:
	/* 0x302c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_302f:
	/* 0x302f: jg     304c <generic_kprobe_process_event+0x304c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_304c;
	}
x86_l_3031:
	/* 0x3031: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3033:
	/* 0x3033: je     306a <generic_kprobe_process_event+0x306a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_306a;
	}
x86_l_3035:
	/* 0x3035: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3038:
	/* 0x3038: je     306a <generic_kprobe_process_event+0x306a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_306a;
	}
x86_l_303a:
	/* 0x303a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_303d:
	/* 0x303d: jne    3090 <generic_kprobe_process_event+0x3090> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3090;
	}
x86_l_303f:
	/* 0x303f: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_3046:
	/* 0x3046: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_304a:
	/* 0x304a: jmp    3095 <generic_kprobe_process_event+0x3095> */
	goto x86_l_3095;
x86_l_304c:
	/* 0x304c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_304f:
	/* 0x304f: je     307d <generic_kprobe_process_event+0x307d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_307d;
	}
x86_l_3051:
	/* 0x3051: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3054:
	/* 0x3054: je     306a <generic_kprobe_process_event+0x306a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_306a;
	}
x86_l_3056:
	/* 0x3056: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_305b:
	/* 0x305b: jne    3090 <generic_kprobe_process_event+0x3090> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3090;
	}
x86_l_305d:
	/* 0x305d: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3064:
	/* 0x3064: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3068:
	/* 0x3068: jmp    3095 <generic_kprobe_process_event+0x3095> */
	goto x86_l_3095;
x86_l_306a:
	/* 0x306a: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_306f:
	/* 0x306f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3076:
	/* 0x3076: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_307b:
	/* 0x307b: jmp    3095 <generic_kprobe_process_event+0x3095> */
	goto x86_l_3095;
x86_l_307d:
	/* 0x307d: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3082:
	/* 0x3082: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3089:
	/* 0x3089: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_308e:
	/* 0x308e: jmp    3095 <generic_kprobe_process_event+0x3095> */
	goto x86_l_3095;
x86_l_3090:
	/* 0x3090: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3095:
	/* 0x3095: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3099:
	/* 0x3099: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_309d:
	/* 0x309d: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_30a2:
	/* 0x30a2: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_30a6:
	/* 0x30a6: ja     3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13396ULL;
	}
x86_l_30ac:
	/* 0x30ac: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
	return 12470ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12470ULL: goto x86_l_30b6;
	case 12474ULL: goto x86_l_30ba;
	case 12480ULL: goto x86_l_30c0;
	case 12484ULL: goto x86_l_30c4;
	case 12487ULL: goto x86_l_30c7;
	case 12492ULL: goto x86_l_30cc;
	case 12495ULL: goto x86_l_30cf;
	case 12500ULL: goto x86_l_30d4;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12514ULL: goto x86_l_30e2;
	case 12517ULL: goto x86_l_30e5;
	case 12522ULL: goto x86_l_30ea;
	case 12524ULL: goto x86_l_30ec;
	case 12527ULL: goto x86_l_30ef;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12541ULL: goto x86_l_30fd;
	case 12543ULL: goto x86_l_30ff;
	case 12545ULL: goto x86_l_3101;
	case 12547ULL: goto x86_l_3103;
	case 12550ULL: goto x86_l_3106;
	case 12552ULL: goto x86_l_3108;
	case 12555ULL: goto x86_l_310b;
	case 12557ULL: goto x86_l_310d;
	case 12564ULL: goto x86_l_3114;
	case 12568ULL: goto x86_l_3118;
	case 12570ULL: goto x86_l_311a;
	case 12573ULL: goto x86_l_311d;
	case 12575ULL: goto x86_l_311f;
	case 12578ULL: goto x86_l_3122;
	case 12580ULL: goto x86_l_3124;
	case 12585ULL: goto x86_l_3129;
	case 12587ULL: goto x86_l_312b;
	case 12594ULL: goto x86_l_3132;
	case 12598ULL: goto x86_l_3136;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	case 12612ULL: goto x86_l_3144;
	case 12617ULL: goto x86_l_3149;
	case 12619ULL: goto x86_l_314b;
	case 12624ULL: goto x86_l_3150;
	case 12631ULL: goto x86_l_3157;
	case 12636ULL: goto x86_l_315c;
	case 12638ULL: goto x86_l_315e;
	case 12643ULL: goto x86_l_3163;
	case 12647ULL: goto x86_l_3167;
	case 12651ULL: goto x86_l_316b;
	case 12656ULL: goto x86_l_3170;
	case 12660ULL: goto x86_l_3174;
	case 12666ULL: goto x86_l_317a;
	case 12676ULL: goto x86_l_3184;
	case 12680ULL: goto x86_l_3188;
	case 12686ULL: goto x86_l_318e;
	case 12690ULL: goto x86_l_3192;
	case 12693ULL: goto x86_l_3195;
	case 12698ULL: goto x86_l_319a;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12720ULL: goto x86_l_31b0;
	case 12723ULL: goto x86_l_31b3;
	case 12728ULL: goto x86_l_31b8;
	case 12730ULL: goto x86_l_31ba;
	case 12733ULL: goto x86_l_31bd;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12747ULL: goto x86_l_31cb;
	case 12749ULL: goto x86_l_31cd;
	case 12751ULL: goto x86_l_31cf;
	case 12753ULL: goto x86_l_31d1;
	case 12756ULL: goto x86_l_31d4;
	case 12758ULL: goto x86_l_31d6;
	case 12761ULL: goto x86_l_31d9;
	case 12763ULL: goto x86_l_31db;
	case 12770ULL: goto x86_l_31e2;
	case 12774ULL: goto x86_l_31e6;
	case 12776ULL: goto x86_l_31e8;
	case 12779ULL: goto x86_l_31eb;
	case 12781ULL: goto x86_l_31ed;
	case 12784ULL: goto x86_l_31f0;
	case 12786ULL: goto x86_l_31f2;
	case 12791ULL: goto x86_l_31f7;
	case 12793ULL: goto x86_l_31f9;
	case 12800ULL: goto x86_l_3200;
	case 12804ULL: goto x86_l_3204;
	case 12806ULL: goto x86_l_3206;
	case 12811ULL: goto x86_l_320b;
	case 12818ULL: goto x86_l_3212;
	case 12823ULL: goto x86_l_3217;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12844ULL: goto x86_l_322c;
	case 12849ULL: goto x86_l_3231;
	case 12853ULL: goto x86_l_3235;
	case 12857ULL: goto x86_l_3239;
	case 12862ULL: goto x86_l_323e;
	case 12866ULL: goto x86_l_3242;
	case 12872ULL: goto x86_l_3248;
	case 12882ULL: goto x86_l_3252;
	case 12886ULL: goto x86_l_3256;
	case 12892ULL: goto x86_l_325c;
	case 12896ULL: goto x86_l_3260;
	case 12899ULL: goto x86_l_3263;
	case 12904ULL: goto x86_l_3268;
	case 12907ULL: goto x86_l_326b;
	case 12912ULL: goto x86_l_3270;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12926ULL: goto x86_l_327e;
	case 12929ULL: goto x86_l_3281;
	case 12934ULL: goto x86_l_3286;
	case 12936ULL: goto x86_l_3288;
	case 12938ULL: goto x86_l_328a;
	case 12946ULL: goto x86_l_3292;
	case 12950ULL: goto x86_l_3296;
	case 12955ULL: goto x86_l_329b;
	case 12960ULL: goto x86_l_32a0;
	case 12967ULL: goto x86_l_32a7;
	case 12971ULL: goto x86_l_32ab;
	case 12976ULL: goto x86_l_32b0;
	case 12981ULL: goto x86_l_32b5;
	case 12984ULL: goto x86_l_32b8;
	case 12989ULL: goto x86_l_32bd;
	case 12991ULL: goto x86_l_32bf;
	case 12995ULL: goto x86_l_32c3;
	case 12999ULL: goto x86_l_32c7;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13017ULL: goto x86_l_32d9;
	case 13019ULL: goto x86_l_32db;
	case 13023ULL: goto x86_l_32df;
	case 13025ULL: goto x86_l_32e1;
	case 13029ULL: goto x86_l_32e5;
	case 13032ULL: goto x86_l_32e8;
	case 13038ULL: goto x86_l_32ee;
	case 13043ULL: goto x86_l_32f3;
	case 13052ULL: goto x86_l_32fc;
	case 13056ULL: goto x86_l_3300;
	case 13061ULL: goto x86_l_3305;
	case 13065ULL: goto x86_l_3309;
	case 13070ULL: goto x86_l_330e;
	case 13075ULL: goto x86_l_3313;
	case 13080ULL: goto x86_l_3318;
	case 13082ULL: goto x86_l_331a;
	case 13086ULL: goto x86_l_331e;
	case 13090ULL: goto x86_l_3322;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13104ULL: goto x86_l_3330;
	case 13106ULL: goto x86_l_3332;
	case 13111ULL: goto x86_l_3337;
	case 13120ULL: goto x86_l_3340;
	case 13124ULL: goto x86_l_3344;
	case 13129ULL: goto x86_l_3349;
	case 13133ULL: goto x86_l_334d;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13150ULL: goto x86_l_335e;
	case 13154ULL: goto x86_l_3362;
	case 13158ULL: goto x86_l_3366;
	case 13162ULL: goto x86_l_336a;
	case 13167ULL: goto x86_l_336f;
	case 13172ULL: goto x86_l_3374;
	case 13177ULL: goto x86_l_3379;
	case 13179ULL: goto x86_l_337b;
	case 13181ULL: goto x86_l_337d;
	case 13186ULL: goto x86_l_3382;
	case 13193ULL: goto x86_l_3389;
	case 13198ULL: goto x86_l_338e;
	case 13202ULL: goto x86_l_3392;
	case 13206ULL: goto x86_l_3396;
	case 13212ULL: goto x86_l_339c;
	case 13218ULL: goto x86_l_33a2;
	case 13225ULL: goto x86_l_33a9;
	case 13233ULL: goto x86_l_33b1;
	case 13238ULL: goto x86_l_33b6;
	case 13243ULL: goto x86_l_33bb;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13257ULL: goto x86_l_33c9;
	case 13259ULL: goto x86_l_33cb;
	case 13267ULL: goto x86_l_33d3;
	case 13270ULL: goto x86_l_33d6;
	case 13272ULL: goto x86_l_33d8;
	case 13276ULL: goto x86_l_33dc;
	case 13281ULL: goto x86_l_33e1;
	case 13286ULL: goto x86_l_33e6;
	case 13291ULL: goto x86_l_33eb;
	case 13299ULL: goto x86_l_33f3;
	case 13303ULL: goto x86_l_33f7;
	case 13308ULL: goto x86_l_33fc;
	case 13310ULL: goto x86_l_33fe;
	case 13318ULL: goto x86_l_3406;
	case 13323ULL: goto x86_l_340b;
	case 13331ULL: goto x86_l_3413;
	case 13334ULL: goto x86_l_3416;
	case 13339ULL: goto x86_l_341b;
	case 13343ULL: goto x86_l_341f;
	case 13348ULL: goto x86_l_3424;
	case 13353ULL: goto x86_l_3429;
	case 13355ULL: goto x86_l_342b;
	case 13359ULL: goto x86_l_342f;
	case 13367ULL: goto x86_l_3437;
	case 13370ULL: goto x86_l_343a;
	case 13375ULL: goto x86_l_343f;
	case 13378ULL: goto x86_l_3442;
	case 13383ULL: goto x86_l_3447;
	case 13385ULL: goto x86_l_3449;
	case 13391ULL: goto x86_l_344f;
	case 13396ULL: goto x86_l_3454;
	case 13404ULL: goto x86_l_345c;
	case 13409ULL: goto x86_l_3461;
	case 13415ULL: goto x86_l_3467;
	case 13417ULL: goto x86_l_3469;
	case 13420ULL: goto x86_l_346c;
	case 13422ULL: goto x86_l_346e;
	case 13425ULL: goto x86_l_3471;
	case 13427ULL: goto x86_l_3473;
	case 13430ULL: goto x86_l_3476;
	case 13436ULL: goto x86_l_347c;
	case 13439ULL: goto x86_l_347f;
	case 13445ULL: goto x86_l_3485;
	case 13448ULL: goto x86_l_3488;
	case 13454ULL: goto x86_l_348e;
	case 13457ULL: goto x86_l_3491;
	case 13463ULL: goto x86_l_3497;
	case 13470ULL: goto x86_l_349e;
	case 13475ULL: goto x86_l_34a3;
	case 13478ULL: goto x86_l_34a6;
	case 13480ULL: goto x86_l_34a8;
	case 13483ULL: goto x86_l_34ab;
	case 13485ULL: goto x86_l_34ad;
	case 13487ULL: goto x86_l_34af;
	case 13493ULL: goto x86_l_34b5;
	case 13496ULL: goto x86_l_34b8;
	case 13502ULL: goto x86_l_34be;
	case 13506ULL: goto x86_l_34c2;
	case 13511ULL: goto x86_l_34c7;
	case 13514ULL: goto x86_l_34ca;
	case 13516ULL: goto x86_l_34cc;
	case 13519ULL: goto x86_l_34cf;
	case 13521ULL: goto x86_l_34d1;
	case 13524ULL: goto x86_l_34d4;
	case 13530ULL: goto x86_l_34da;
	case 13534ULL: goto x86_l_34de;
	case 13539ULL: goto x86_l_34e3;
	case 13542ULL: goto x86_l_34e6;
	case 13544ULL: goto x86_l_34e8;
	case 13547ULL: goto x86_l_34eb;
	case 13549ULL: goto x86_l_34ed;
	case 13552ULL: goto x86_l_34f0;
	case 13558ULL: goto x86_l_34f6;
	case 13562ULL: goto x86_l_34fa;
	case 13564ULL: goto x86_l_34fc;
	case 13567ULL: goto x86_l_34ff;
	case 13569ULL: goto x86_l_3501;
	case 13572ULL: goto x86_l_3504;
	case 13574ULL: goto x86_l_3506;
	case 13578ULL: goto x86_l_350a;
	case 13580ULL: goto x86_l_350c;
	case 13583ULL: goto x86_l_350f;
	case 13585ULL: goto x86_l_3511;
	case 13588ULL: goto x86_l_3514;
	case 13590ULL: goto x86_l_3516;
	case 13594ULL: goto x86_l_351a;
	case 13596ULL: goto x86_l_351c;
	case 13599ULL: goto x86_l_351f;
	case 13601ULL: goto x86_l_3521;
	case 13604ULL: goto x86_l_3524;
	case 13606ULL: goto x86_l_3526;
	case 13610ULL: goto x86_l_352a;
	case 13612ULL: goto x86_l_352c;
	case 13615ULL: goto x86_l_352f;
	case 13617ULL: goto x86_l_3531;
	case 13620ULL: goto x86_l_3534;
	case 13622ULL: goto x86_l_3536;
	case 13626ULL: goto x86_l_353a;
	case 13628ULL: goto x86_l_353c;
	case 13632ULL: goto x86_l_3540;
	case 13634ULL: goto x86_l_3542;
	case 13638ULL: goto x86_l_3546;
	case 13640ULL: goto x86_l_3548;
	case 13644ULL: goto x86_l_354c;
	case 13646ULL: goto x86_l_354e;
	case 13650ULL: goto x86_l_3552;
	case 13652ULL: goto x86_l_3554;
	case 13656ULL: goto x86_l_3558;
	case 13658ULL: goto x86_l_355a;
	case 13662ULL: goto x86_l_355e;
	case 13664ULL: goto x86_l_3560;
	case 13668ULL: goto x86_l_3564;
	case 13670ULL: goto x86_l_3566;
	case 13674ULL: goto x86_l_356a;
	case 13679ULL: goto x86_l_356f;
	case 13681ULL: goto x86_l_3571;
	case 13686ULL: goto x86_l_3576;
	case 13687ULL: goto x86_l_3577;
	case 13692ULL: goto x86_l_357c;
	case 13695ULL: goto x86_l_357f;
	case 13697ULL: goto x86_l_3581;
	case 13699ULL: goto x86_l_3583;
	case 13700ULL: goto x86_l_3584;
	case 13701ULL: goto x86_l_3585;
	case 13704ULL: goto x86_l_3588;
	case 13707ULL: goto x86_l_358b;
	case 13714ULL: goto x86_l_3592;
	case 13716ULL: goto x86_l_3594;
	case 13720ULL: goto x86_l_3598;
	case 13724ULL: goto x86_l_359c;
	case 13727ULL: goto x86_l_359f;
	case 13730ULL: goto x86_l_35a2;
	case 13732ULL: goto x86_l_35a4;
	case 13739ULL: goto x86_l_35ab;
	case 13741ULL: goto x86_l_35ad;
	case 13743ULL: goto x86_l_35af;
	case 13747ULL: goto x86_l_35b3;
	case 13749ULL: goto x86_l_35b5;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13761ULL: goto x86_l_35c1;
	case 13766ULL: goto x86_l_35c6;
	case 13771ULL: goto x86_l_35cb;
	case 13774ULL: goto x86_l_35ce;
	case 13778ULL: goto x86_l_35d2;
	case 13781ULL: goto x86_l_35d5;
	case 13786ULL: goto x86_l_35da;
	case 13788ULL: goto x86_l_35dc;
	case 13790ULL: goto x86_l_35de;
	case 13795ULL: goto x86_l_35e3;
	case 13797ULL: goto x86_l_35e5;
	case 13799ULL: goto x86_l_35e7;
	case 13803ULL: goto x86_l_35eb;
	case 13805ULL: goto x86_l_35ed;
	case 13810ULL: goto x86_l_35f2;
	case 13814ULL: goto x86_l_35f6;
	case 13815ULL: goto x86_l_35f7;
	case 13817ULL: goto x86_l_35f9;
	case 13818ULL: goto x86_l_35fa;
	case 13819ULL: goto x86_l_35fb;
	case 13821ULL: goto x86_l_35fd;
	case 13823ULL: goto x86_l_35ff;
	case 13825ULL: goto x86_l_3601;
	case 13827ULL: goto x86_l_3603;
	case 13828ULL: goto x86_l_3604;
	case 13832ULL: goto x86_l_3608;
	case 13835ULL: goto x86_l_360b;
	case 13839ULL: goto x86_l_360f;
	case 13843ULL: goto x86_l_3613;
	case 13847ULL: goto x86_l_3617;
	case 13850ULL: goto x86_l_361a;
	case 13852ULL: goto x86_l_361c;
	case 13856ULL: goto x86_l_3620;
	case 13862ULL: goto x86_l_3626;
	case 13866ULL: goto x86_l_362a;
	case 13871ULL: goto x86_l_362f;
	case 13876ULL: goto x86_l_3634;
	case 13881ULL: goto x86_l_3639;
	case 13886ULL: goto x86_l_363e;
	case 13888ULL: goto x86_l_3640;
	case 13893ULL: goto x86_l_3645;
	case 13899ULL: goto x86_l_364b;
	case 13904ULL: goto x86_l_3650;
	case 13909ULL: goto x86_l_3655;
	case 13914ULL: goto x86_l_365a;
	case 13919ULL: goto x86_l_365f;
	case 13924ULL: goto x86_l_3664;
	case 13927ULL: goto x86_l_3667;
	case 13929ULL: goto x86_l_3669;
	case 13934ULL: goto x86_l_366e;
	case 13940ULL: goto x86_l_3674;
	case 13945ULL: goto x86_l_3679;
	case 13950ULL: goto x86_l_367e;
	case 13955ULL: goto x86_l_3683;
	case 13960ULL: goto x86_l_3688;
	case 13963ULL: goto x86_l_368b;
	case 13965ULL: goto x86_l_368d;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30b6:
	/* 0x30b6: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_30ba:
	/* 0x30ba: jae    3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3454;
	}
x86_l_30c0:
	/* 0x30c0: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_30c4:
	/* 0x30c4: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_30c7:
	/* 0x30c7: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30cc:
	/* 0x30cc: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30cf:
	/* 0x30cf: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_30d4:
	/* 0x30d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30d9:
	/* 0x30d9: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30de:
	/* 0x30de: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30e2:
	/* 0x30e2: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30e5:
	/* 0x30e5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_30ea:
	/* 0x30ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ec:
	/* 0x30ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30ef:
	/* 0x30ef: js     3288 <generic_kprobe_process_event+0x3288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3288;
	}
x86_l_30f5:
	/* 0x30f5: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_30fa:
	/* 0x30fa: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_30fd:
	/* 0x30fd: jg     311a <generic_kprobe_process_event+0x311a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_311a;
	}
x86_l_30ff:
	/* 0x30ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3101:
	/* 0x3101: je     3138 <generic_kprobe_process_event+0x3138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3138;
	}
x86_l_3103:
	/* 0x3103: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3106:
	/* 0x3106: je     3138 <generic_kprobe_process_event+0x3138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3138;
	}
x86_l_3108:
	/* 0x3108: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_310b:
	/* 0x310b: jne    315e <generic_kprobe_process_event+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_315e;
	}
x86_l_310d:
	/* 0x310d: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_3114:
	/* 0x3114: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_3118:
	/* 0x3118: jmp    3163 <generic_kprobe_process_event+0x3163> */
	goto x86_l_3163;
x86_l_311a:
	/* 0x311a: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_311d:
	/* 0x311d: je     314b <generic_kprobe_process_event+0x314b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314b;
	}
x86_l_311f:
	/* 0x311f: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3122:
	/* 0x3122: je     3138 <generic_kprobe_process_event+0x3138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3138;
	}
x86_l_3124:
	/* 0x3124: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_3129:
	/* 0x3129: jne    315e <generic_kprobe_process_event+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_315e;
	}
x86_l_312b:
	/* 0x312b: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3132:
	/* 0x3132: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3136:
	/* 0x3136: jmp    3163 <generic_kprobe_process_event+0x3163> */
	goto x86_l_3163;
x86_l_3138:
	/* 0x3138: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_313d:
	/* 0x313d: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3144:
	/* 0x3144: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3149:
	/* 0x3149: jmp    3163 <generic_kprobe_process_event+0x3163> */
	goto x86_l_3163;
x86_l_314b:
	/* 0x314b: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3150:
	/* 0x3150: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3157:
	/* 0x3157: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_315c:
	/* 0x315c: jmp    3163 <generic_kprobe_process_event+0x3163> */
	goto x86_l_3163;
x86_l_315e:
	/* 0x315e: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3163:
	/* 0x3163: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3167:
	/* 0x3167: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_316b:
	/* 0x316b: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3170:
	/* 0x3170: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_3174:
	/* 0x3174: ja     3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3454;
	}
x86_l_317a:
	/* 0x317a: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3184:
	/* 0x3184: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_3188:
	/* 0x3188: jae    3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3454;
	}
x86_l_318e:
	/* 0x318e: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3192:
	/* 0x3192: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3195:
	/* 0x3195: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_319a:
	/* 0x319a: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_319d:
	/* 0x319d: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_31a2:
	/* 0x31a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31a7:
	/* 0x31a7: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31ac:
	/* 0x31ac: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31b0:
	/* 0x31b0: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31b3:
	/* 0x31b3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_31b8:
	/* 0x31b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ba:
	/* 0x31ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31bd:
	/* 0x31bd: js     3288 <generic_kprobe_process_event+0x3288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3288;
	}
x86_l_31c3:
	/* 0x31c3: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_31c8:
	/* 0x31c8: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_31cb:
	/* 0x31cb: jg     31e8 <generic_kprobe_process_event+0x31e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_31e8;
	}
x86_l_31cd:
	/* 0x31cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31cf:
	/* 0x31cf: je     3206 <generic_kprobe_process_event+0x3206> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3206;
	}
x86_l_31d1:
	/* 0x31d1: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_31d4:
	/* 0x31d4: je     3206 <generic_kprobe_process_event+0x3206> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3206;
	}
x86_l_31d6:
	/* 0x31d6: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_31d9:
	/* 0x31d9: jne    322c <generic_kprobe_process_event+0x322c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_322c;
	}
x86_l_31db:
	/* 0x31db: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_31e2:
	/* 0x31e2: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_31e6:
	/* 0x31e6: jmp    3231 <generic_kprobe_process_event+0x3231> */
	goto x86_l_3231;
x86_l_31e8:
	/* 0x31e8: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_31eb:
	/* 0x31eb: je     3219 <generic_kprobe_process_event+0x3219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3219;
	}
x86_l_31ed:
	/* 0x31ed: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_31f0:
	/* 0x31f0: je     3206 <generic_kprobe_process_event+0x3206> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3206;
	}
x86_l_31f2:
	/* 0x31f2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_31f7:
	/* 0x31f7: jne    322c <generic_kprobe_process_event+0x322c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_322c;
	}
x86_l_31f9:
	/* 0x31f9: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3200:
	/* 0x3200: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_3204:
	/* 0x3204: jmp    3231 <generic_kprobe_process_event+0x3231> */
	goto x86_l_3231;
x86_l_3206:
	/* 0x3206: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_320b:
	/* 0x320b: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3212:
	/* 0x3212: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3217:
	/* 0x3217: jmp    3231 <generic_kprobe_process_event+0x3231> */
	goto x86_l_3231;
x86_l_3219:
	/* 0x3219: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_321e:
	/* 0x321e: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3225:
	/* 0x3225: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_322a:
	/* 0x322a: jmp    3231 <generic_kprobe_process_event+0x3231> */
	goto x86_l_3231;
x86_l_322c:
	/* 0x322c: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3231:
	/* 0x3231: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3235:
	/* 0x3235: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3239:
	/* 0x3239: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_323e:
	/* 0x323e: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_3242:
	/* 0x3242: ja     3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3454;
	}
x86_l_3248:
	/* 0x3248: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3252:
	/* 0x3252: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_3256:
	/* 0x3256: jae    3454 <generic_kprobe_process_event+0x3454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3454;
	}
x86_l_325c:
	/* 0x325c: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3260:
	/* 0x3260: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3263:
	/* 0x3263: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3268:
	/* 0x3268: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_326b:
	/* 0x326b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3270:
	/* 0x3270: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3275:
	/* 0x3275: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_327a:
	/* 0x327a: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_327e:
	/* 0x327e: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3281:
	/* 0x3281: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3286:
	/* 0x3286: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3288:
	/* 0x3288: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_328a:
	/* 0x328a: mov    BYTE PTR [rsp+0xbc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_3292:
	/* 0x3292: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3296:
	/* 0x3296: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_329b:
	/* 0x329b: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_32a0:
	/* 0x32a0: mov    WORD PTR [r15+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_32a7:
	/* 0x32a7: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32ab:
	/* 0x32ab: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32b0:
	/* 0x32b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32b5:
	/* 0x32b5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_32b8:
	/* 0x32b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_32bd:
	/* 0x32bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32bf:
	/* 0x32bf: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32c3:
	/* 0x32c3: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_32c7:
	/* 0x32c7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32cc:
	/* 0x32cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32d1:
	/* 0x32d1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_32d6:
	/* 0x32d6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_32d9:
	/* 0x32d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32db:
	/* 0x32db: cmp    bpl,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 17ULL);
x86_l_32df:
	/* 0x32df: je     3332 <generic_kprobe_process_event+0x3332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3332;
	}
x86_l_32e1:
	/* 0x32e1: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32e5:
	/* 0x32e5: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_32e8:
	/* 0x32e8: jne    337d <generic_kprobe_process_event+0x337d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_337d;
	}
x86_l_32ee:
	/* 0x32ee: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_32f3:
	/* 0x32f3: movzx  r15d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_32fc:
	/* 0x32fc: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3300:
	/* 0x3300: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3305:
	/* 0x3305: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3309:
	/* 0x3309: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_330e:
	/* 0x330e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3313:
	/* 0x3313: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3318:
	/* 0x3318: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331a:
	/* 0x331a: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_331e:
	/* 0x331e: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3322:
	/* 0x3322: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3326:
	/* 0x3326: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_332b:
	/* 0x332b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3330:
	/* 0x3330: jmp    3374 <generic_kprobe_process_event+0x3374> */
	goto x86_l_3374;
x86_l_3332:
	/* 0x3332: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3337:
	/* 0x3337: movzx  r15d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_3340:
	/* 0x3340: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3344:
	/* 0x3344: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3349:
	/* 0x3349: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_334d:
	/* 0x334d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3352:
	/* 0x3352: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3357:
	/* 0x3357: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_335c:
	/* 0x335c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335e:
	/* 0x335e: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3362:
	/* 0x3362: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3366:
	/* 0x3366: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_336a:
	/* 0x336a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_336f:
	/* 0x336f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3374:
	/* 0x3374: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3379:
	/* 0x3379: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337b:
	/* 0x337b: jmp    3389 <generic_kprobe_process_event+0x3389> */
	goto x86_l_3389;
x86_l_337d:
	/* 0x337d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3382:
	/* 0x3382: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3389:
	/* 0x3389: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_338e:
	/* 0x338e: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3392:
	/* 0x3392: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_3396:
	/* 0x3396: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_339c:
	/* 0x339c: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_33a2:
	/* 0x33a2: add    r12,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_33a9:
	/* 0x33a9: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_33b1:
	/* 0x33b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33b6:
	/* 0x33b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33bb:
	/* 0x33bb: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_33c1:
	/* 0x33c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c6:
	/* 0x33c6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_33c9:
	/* 0x33c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33cb:
	/* 0x33cb: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_33d3:
	/* 0x33d3: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_33d6:
	/* 0x33d6: je     3449 <generic_kprobe_process_event+0x3449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3449;
	}
x86_l_33d8:
	/* 0x33d8: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_33dc:
	/* 0x33dc: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_33e1:
	/* 0x33e1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33e6:
	/* 0x33e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33eb:
	/* 0x33eb: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_33f3:
	/* 0x33f3: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_33f7:
	/* 0x33f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33fc:
	/* 0x33fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33fe:
	/* 0x33fe: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3406:
	/* 0x3406: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_340b:
	/* 0x340b: lea    rdx,[r12*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_3413:
	/* 0x3413: add    rdx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3416:
	/* 0x3416: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_341b:
	/* 0x341b: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_341f:
	/* 0x341f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3424:
	/* 0x3424: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3429:
	/* 0x3429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_342b:
	/* 0x342b: add    rbp,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_342f:
	/* 0x342f: lea    rdx,[r12*8+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 4ULL);
x86_l_3437:
	/* 0x3437: add    rdx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_343a:
	/* 0x343a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_343f:
	/* 0x343f: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3442:
	/* 0x3442: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3447:
	/* 0x3447: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3449:
	/* 0x3449: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_344f:
	/* 0x344f: jmp    ce3 <generic_kprobe_process_event+0xce3> */
	return 3299ULL;
x86_l_3454:
	/* 0x3454: mov    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_345c:
	/* 0x345c: jmp    328a <generic_kprobe_process_event+0x328a> */
	goto x86_l_328a;
x86_l_3461:
	/* 0x3461: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_3467:
	/* 0x3467: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3469:
	/* 0x3469: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_346c:
	/* 0x346c: jle    34a3 <read_reg+0x42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_34a3;
	}
x86_l_346e:
	/* 0x346e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3471:
	/* 0x3471: jle    34c7 <read_reg+0x66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_34c7;
	}
x86_l_3473:
	/* 0x3473: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3476:
	/* 0x3476: jle    352c <read_reg+0xcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_352c;
	}
x86_l_347c:
	/* 0x347c: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_347f:
	/* 0x347f: je     3560 <read_reg+0xff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3560;
	}
x86_l_3485:
	/* 0x3485: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3488:
	/* 0x3488: je     3548 <read_reg+0xe7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3548;
	}
x86_l_348e:
	/* 0x348e: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_3491:
	/* 0x3491: jne    3576 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3576;
	}
x86_l_3497:
	/* 0x3497: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_349e:
	/* 0x349e: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_34a3:
	/* 0x34a3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_34a6:
	/* 0x34a6: jg     34e3 <read_reg+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_34e3;
	}
x86_l_34a8:
	/* 0x34a8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_34ab:
	/* 0x34ab: jg     350c <read_reg+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_350c;
	}
x86_l_34ad:
	/* 0x34ad: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_34af:
	/* 0x34af: je     356a <read_reg+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_356a;
	}
x86_l_34b5:
	/* 0x34b5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_34b8:
	/* 0x34b8: jne    3576 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3576;
	}
x86_l_34be:
	/* 0x34be: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34c2:
	/* 0x34c2: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_34c7:
	/* 0x34c7: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_34ca:
	/* 0x34ca: jg     34fc <read_reg+0x9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_34fc;
	}
x86_l_34cc:
	/* 0x34cc: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34cf:
	/* 0x34cf: je     353c <read_reg+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_353c;
	}
x86_l_34d1:
	/* 0x34d1: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_34d4:
	/* 0x34d4: jne    3576 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3576;
	}
x86_l_34da:
	/* 0x34da: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_34de:
	/* 0x34de: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_34e3:
	/* 0x34e3: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_34e6:
	/* 0x34e6: jg     351c <read_reg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_351c;
	}
x86_l_34e8:
	/* 0x34e8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_34eb:
	/* 0x34eb: je     354e <read_reg+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354e;
	}
x86_l_34ed:
	/* 0x34ed: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_34f0:
	/* 0x34f0: jne    3576 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3576;
	}
x86_l_34f6:
	/* 0x34f6: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_34fa:
	/* 0x34fa: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_34fc:
	/* 0x34fc: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_34ff:
	/* 0x34ff: je     3542 <read_reg+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3542;
	}
x86_l_3501:
	/* 0x3501: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3504:
	/* 0x3504: jne    3576 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3576;
	}
x86_l_3506:
	/* 0x3506: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_350a:
	/* 0x350a: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_350c:
	/* 0x350c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_350f:
	/* 0x350f: je     3554 <read_reg+0xf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3554;
	}
x86_l_3511:
	/* 0x3511: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3514:
	/* 0x3514: jne    3576 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3576;
	}
x86_l_3516:
	/* 0x3516: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_351a:
	/* 0x351a: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_351c:
	/* 0x351c: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_351f:
	/* 0x351f: je     355a <read_reg+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355a;
	}
x86_l_3521:
	/* 0x3521: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_3524:
	/* 0x3524: jne    3576 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3576;
	}
x86_l_3526:
	/* 0x3526: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_352a:
	/* 0x352a: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_352c:
	/* 0x352c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_352f:
	/* 0x352f: je     3566 <read_reg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3566;
	}
x86_l_3531:
	/* 0x3531: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3534:
	/* 0x3534: jne    3576 <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3576;
	}
x86_l_3536:
	/* 0x3536: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_353a:
	/* 0x353a: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_353c:
	/* 0x353c: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3540:
	/* 0x3540: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_3542:
	/* 0x3542: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3546:
	/* 0x3546: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_3548:
	/* 0x3548: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_354c:
	/* 0x354c: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_354e:
	/* 0x354e: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3552:
	/* 0x3552: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_3554:
	/* 0x3554: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3558:
	/* 0x3558: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_355a:
	/* 0x355a: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_355e:
	/* 0x355e: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_3560:
	/* 0x3560: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_3564:
	/* 0x3564: jmp    356a <read_reg+0x109> */
	goto x86_l_356a;
x86_l_3566:
	/* 0x3566: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_356a:
	/* 0x356a: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_356f:
	/* 0x356f: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3571:
	/* 0x3571: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_3576:
	/* 0x3576: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3577:
	/* 0x3577: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_357c:
	/* 0x357c: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_357f:
	/* 0x357f: ja     35f9 <extract_arg_depth+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_35f9;
	}
x86_l_3581:
	/* 0x3581: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3583:
	/* 0x3583: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3584:
	/* 0x3584: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3585:
	/* 0x3585: mov    r8,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3588:
	/* 0x3588: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_358b:
	/* 0x358b: cmp    WORD PTR [r8+r9*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 25769803776ULL);
x86_l_3592:
	/* 0x3592: je     35f2 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35f2;
	}
x86_l_3594:
	/* 0x3594: mov    rcx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3598:
	/* 0x3598: mov    edx,DWORD PTR [r8+r9*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 3), 0ULL);
x86_l_359c:
	/* 0x359c: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_359f:
	/* 0x359f: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35a2:
	/* 0x35a2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35a4:
	/* 0x35a4: cmp    WORD PTR [r8+r9*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 17179869184ULL);
x86_l_35ab:
	/* 0x35ab: je     35f2 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35f2;
	}
x86_l_35ad:
	/* 0x35ad: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_35af:
	/* 0x35af: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_35b3:
	/* 0x35b3: je     35c1 <extract_arg_depth+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c1;
	}
x86_l_35b5:
	/* 0x35b5: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_35ba:
	/* 0x35ba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35bf:
	/* 0x35bf: jmp    35cb <extract_arg_depth+0x54> */
	goto x86_l_35cb;
x86_l_35c1:
	/* 0x35c1: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_35c6:
	/* 0x35c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35cb:
	/* 0x35cb: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_35ce:
	/* 0x35ce: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35d2:
	/* 0x35d2: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35d5:
	/* 0x35d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35da:
	/* 0x35da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35dc:
	/* 0x35dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35de:
	/* 0x35de: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_35e3:
	/* 0x35e3: jns    35f2 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_35f2;
	}
x86_l_35e5:
	/* 0x35e5: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_35e7:
	/* 0x35e7: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35eb:
	/* 0x35eb: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ed:
	/* 0x35ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35f2:
	/* 0x35f2: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35f6:
	/* 0x35f6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_35f7:
	/* 0x35f7: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_35f9:
	/* 0x35f9: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_35fa:
	/* 0x35fa: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_35fb:
	/* 0x35fb: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_35fd:
	/* 0x35fd: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_35ff:
	/* 0x35ff: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_3601:
	/* 0x3601: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3603:
	/* 0x3603: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3604:
	/* 0x3604: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_3608:
	/* 0x3608: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_360b:
	/* 0x360b: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_360f:
	/* 0x360f: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3613:
	/* 0x3613: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3617:
	/* 0x3617: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_361a:
	/* 0x361a: jne    3626 <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3626;
	}
x86_l_361c:
	/* 0x361c: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3620:
	/* 0x3620: je     3791 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14225ULL;
	}
x86_l_3626:
	/* 0x3626: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_362a:
	/* 0x362a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_362f:
	/* 0x362f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3634:
	/* 0x3634: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3639:
	/* 0x3639: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_363e:
	/* 0x363e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3640:
	/* 0x3640: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3645:
	/* 0x3645: je     373c <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14140ULL;
	}
x86_l_364b:
	/* 0x364b: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3650:
	/* 0x3650: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3655:
	/* 0x3655: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_365a:
	/* 0x365a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_365f:
	/* 0x365f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3664:
	/* 0x3664: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3667:
	/* 0x3667: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3669:
	/* 0x3669: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_366e:
	/* 0x366e: je     373c <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14140ULL;
	}
x86_l_3674:
	/* 0x3674: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3679:
	/* 0x3679: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_367e:
	/* 0x367e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3683:
	/* 0x3683: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3688:
	/* 0x3688: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_368b:
	/* 0x368b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_368d:
	/* 0x368d: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3691:
	/* 0x3691: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3696:
	/* 0x3696: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
	return 13979ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13979ULL: goto x86_l_369b;
	case 13984ULL: goto x86_l_36a0;
	case 13989ULL: goto x86_l_36a5;
	case 13992ULL: goto x86_l_36a8;
	case 13994ULL: goto x86_l_36aa;
	case 13998ULL: goto x86_l_36ae;
	case 14002ULL: goto x86_l_36b2;
	case 14006ULL: goto x86_l_36b6;
	case 14009ULL: goto x86_l_36b9;
	case 14013ULL: goto x86_l_36bd;
	case 14015ULL: goto x86_l_36bf;
	case 14017ULL: goto x86_l_36c1;
	case 14020ULL: goto x86_l_36c4;
	case 14023ULL: goto x86_l_36c7;
	case 14028ULL: goto x86_l_36cc;
	case 14030ULL: goto x86_l_36ce;
	case 14033ULL: goto x86_l_36d1;
	case 14037ULL: goto x86_l_36d5;
	case 14039ULL: goto x86_l_36d7;
	case 14043ULL: goto x86_l_36db;
	case 14045ULL: goto x86_l_36dd;
	case 14048ULL: goto x86_l_36e0;
	case 14050ULL: goto x86_l_36e2;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14061ULL: goto x86_l_36ed;
	case 14067ULL: goto x86_l_36f3;
	case 14074ULL: goto x86_l_36fa;
	case 14080ULL: goto x86_l_3700;
	case 14083ULL: goto x86_l_3703;
	case 14085ULL: goto x86_l_3705;
	case 14090ULL: goto x86_l_370a;
	case 14092ULL: goto x86_l_370c;
	case 14095ULL: goto x86_l_370f;
	case 14099ULL: goto x86_l_3713;
	case 14103ULL: goto x86_l_3717;
	case 14106ULL: goto x86_l_371a;
	case 14109ULL: goto x86_l_371d;
	case 14114ULL: goto x86_l_3722;
	case 14116ULL: goto x86_l_3724;
	case 14120ULL: goto x86_l_3728;
	case 14123ULL: goto x86_l_372b;
	case 14128ULL: goto x86_l_3730;
	case 14130ULL: goto x86_l_3732;
	case 14135ULL: goto x86_l_3737;
	case 14138ULL: goto x86_l_373a;
	case 14140ULL: goto x86_l_373c;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14154ULL: goto x86_l_374a;
	case 14159ULL: goto x86_l_374f;
	case 14164ULL: goto x86_l_3754;
	case 14166ULL: goto x86_l_3756;
	case 14170ULL: goto x86_l_375a;
	case 14175ULL: goto x86_l_375f;
	case 14177ULL: goto x86_l_3761;
	case 14181ULL: goto x86_l_3765;
	case 14186ULL: goto x86_l_376a;
	case 14191ULL: goto x86_l_376f;
	case 14194ULL: goto x86_l_3772;
	case 14199ULL: goto x86_l_3777;
	case 14202ULL: goto x86_l_377a;
	case 14204ULL: goto x86_l_377c;
	case 14209ULL: goto x86_l_3781;
	case 14213ULL: goto x86_l_3785;
	case 14217ULL: goto x86_l_3789;
	case 14221ULL: goto x86_l_378d;
	case 14223ULL: goto x86_l_378f;
	case 14225ULL: goto x86_l_3791;
	case 14229ULL: goto x86_l_3795;
	case 14234ULL: goto x86_l_379a;
	case 14238ULL: goto x86_l_379e;
	case 14239ULL: goto x86_l_379f;
	case 14241ULL: goto x86_l_37a1;
	case 14243ULL: goto x86_l_37a3;
	case 14245ULL: goto x86_l_37a5;
	case 14247ULL: goto x86_l_37a7;
	case 14248ULL: goto x86_l_37a8;
	case 14249ULL: goto x86_l_37a9;
	case 14250ULL: goto x86_l_37aa;
	case 14252ULL: goto x86_l_37ac;
	case 14254ULL: goto x86_l_37ae;
	case 14256ULL: goto x86_l_37b0;
	case 14258ULL: goto x86_l_37b2;
	case 14259ULL: goto x86_l_37b3;
	case 14260ULL: goto x86_l_37b4;
	case 14263ULL: goto x86_l_37b7;
	case 14266ULL: goto x86_l_37ba;
	case 14269ULL: goto x86_l_37bd;
	case 14272ULL: goto x86_l_37c0;
	case 14280ULL: goto x86_l_37c8;
	case 14287ULL: goto x86_l_37cf;
	case 14292ULL: goto x86_l_37d4;
	case 14297ULL: goto x86_l_37d9;
	case 14299ULL: goto x86_l_37db;
	case 14302ULL: goto x86_l_37de;
	case 14304ULL: goto x86_l_37e0;
	case 14307ULL: goto x86_l_37e3;
	case 14313ULL: goto x86_l_37e9;
	case 14318ULL: goto x86_l_37ee;
	case 14320ULL: goto x86_l_37f0;
	case 14323ULL: goto x86_l_37f3;
	case 14327ULL: goto x86_l_37f7;
	case 14331ULL: goto x86_l_37fb;
	case 14335ULL: goto x86_l_37ff;
	case 14337ULL: goto x86_l_3801;
	case 14342ULL: goto x86_l_3806;
	case 14346ULL: goto x86_l_380a;
	case 14351ULL: goto x86_l_380f;
	case 14353ULL: goto x86_l_3811;
	case 14357ULL: goto x86_l_3815;
	case 14361ULL: goto x86_l_3819;
	case 14365ULL: goto x86_l_381d;
	case 14369ULL: goto x86_l_3821;
	case 14373ULL: goto x86_l_3825;
	case 14376ULL: goto x86_l_3828;
	case 14379ULL: goto x86_l_382b;
	case 14382ULL: goto x86_l_382e;
	case 14385ULL: goto x86_l_3831;
	case 14390ULL: goto x86_l_3836;
	case 14392ULL: goto x86_l_3838;
	case 14394ULL: goto x86_l_383a;
	case 14401ULL: goto x86_l_3841;
	case 14404ULL: goto x86_l_3844;
	case 14406ULL: goto x86_l_3846;
	case 14408ULL: goto x86_l_3848;
	case 14412ULL: goto x86_l_384c;
	case 14415ULL: goto x86_l_384f;
	case 14417ULL: goto x86_l_3851;
	case 14419ULL: goto x86_l_3853;
	case 14421ULL: goto x86_l_3855;
	case 14423ULL: goto x86_l_3857;
	case 14430ULL: goto x86_l_385e;
	case 14432ULL: goto x86_l_3860;
	case 14434ULL: goto x86_l_3862;
	case 14437ULL: goto x86_l_3865;
	case 14440ULL: goto x86_l_3868;
	case 14445ULL: goto x86_l_386d;
	case 14449ULL: goto x86_l_3871;
	case 14450ULL: goto x86_l_3872;
	case 14452ULL: goto x86_l_3874;
	case 14454ULL: goto x86_l_3876;
	case 14456ULL: goto x86_l_3878;
	case 14458ULL: goto x86_l_387a;
	case 14459ULL: goto x86_l_387b;
	case 14460ULL: goto x86_l_387c;
	case 14461ULL: goto x86_l_387d;
	case 14463ULL: goto x86_l_387f;
	case 14465ULL: goto x86_l_3881;
	case 14467ULL: goto x86_l_3883;
	case 14469ULL: goto x86_l_3885;
	case 14470ULL: goto x86_l_3886;
	case 14471ULL: goto x86_l_3887;
	case 14474ULL: goto x86_l_388a;
	case 14477ULL: goto x86_l_388d;
	case 14480ULL: goto x86_l_3890;
	case 14483ULL: goto x86_l_3893;
	case 14488ULL: goto x86_l_3898;
	case 14490ULL: goto x86_l_389a;
	case 14496ULL: goto x86_l_38a0;
	case 14499ULL: goto x86_l_38a3;
	case 14506ULL: goto x86_l_38aa;
	case 14509ULL: goto x86_l_38ad;
	case 14512ULL: goto x86_l_38b0;
	case 14518ULL: goto x86_l_38b6;
	case 14522ULL: goto x86_l_38ba;
	case 14525ULL: goto x86_l_38bd;
	case 14528ULL: goto x86_l_38c0;
	case 14533ULL: goto x86_l_38c5;
	case 14535ULL: goto x86_l_38c7;
	case 14541ULL: goto x86_l_38cd;
	case 14546ULL: goto x86_l_38d2;
	case 14549ULL: goto x86_l_38d5;
	case 14552ULL: goto x86_l_38d8;
	case 14555ULL: goto x86_l_38db;
	case 14558ULL: goto x86_l_38de;
	case 14564ULL: goto x86_l_38e4;
	case 14568ULL: goto x86_l_38e8;
	case 14571ULL: goto x86_l_38eb;
	case 14574ULL: goto x86_l_38ee;
	case 14579ULL: goto x86_l_38f3;
	case 14581ULL: goto x86_l_38f5;
	case 14587ULL: goto x86_l_38fb;
	case 14592ULL: goto x86_l_3900;
	case 14595ULL: goto x86_l_3903;
	case 14598ULL: goto x86_l_3906;
	case 14601ULL: goto x86_l_3909;
	case 14604ULL: goto x86_l_390c;
	case 14610ULL: goto x86_l_3912;
	case 14614ULL: goto x86_l_3916;
	case 14617ULL: goto x86_l_3919;
	case 14620ULL: goto x86_l_391c;
	case 14625ULL: goto x86_l_3921;
	case 14627ULL: goto x86_l_3923;
	case 14633ULL: goto x86_l_3929;
	case 14638ULL: goto x86_l_392e;
	case 14641ULL: goto x86_l_3931;
	case 14644ULL: goto x86_l_3934;
	case 14647ULL: goto x86_l_3937;
	case 14650ULL: goto x86_l_393a;
	case 14656ULL: goto x86_l_3940;
	case 14660ULL: goto x86_l_3944;
	case 14663ULL: goto x86_l_3947;
	case 14666ULL: goto x86_l_394a;
	case 14671ULL: goto x86_l_394f;
	case 14673ULL: goto x86_l_3951;
	case 14679ULL: goto x86_l_3957;
	case 14684ULL: goto x86_l_395c;
	case 14687ULL: goto x86_l_395f;
	case 14690ULL: goto x86_l_3962;
	case 14693ULL: goto x86_l_3965;
	case 14696ULL: goto x86_l_3968;
	case 14702ULL: goto x86_l_396e;
	case 14706ULL: goto x86_l_3972;
	case 14709ULL: goto x86_l_3975;
	case 14712ULL: goto x86_l_3978;
	case 14717ULL: goto x86_l_397d;
	case 14719ULL: goto x86_l_397f;
	case 14725ULL: goto x86_l_3985;
	case 14730ULL: goto x86_l_398a;
	case 14733ULL: goto x86_l_398d;
	case 14736ULL: goto x86_l_3990;
	case 14739ULL: goto x86_l_3993;
	case 14742ULL: goto x86_l_3996;
	case 14748ULL: goto x86_l_399c;
	case 14752ULL: goto x86_l_39a0;
	case 14755ULL: goto x86_l_39a3;
	case 14758ULL: goto x86_l_39a6;
	case 14763ULL: goto x86_l_39ab;
	case 14765ULL: goto x86_l_39ad;
	case 14771ULL: goto x86_l_39b3;
	case 14776ULL: goto x86_l_39b8;
	case 14779ULL: goto x86_l_39bb;
	case 14782ULL: goto x86_l_39be;
	case 14785ULL: goto x86_l_39c1;
	case 14788ULL: goto x86_l_39c4;
	case 14794ULL: goto x86_l_39ca;
	case 14798ULL: goto x86_l_39ce;
	case 14801ULL: goto x86_l_39d1;
	case 14804ULL: goto x86_l_39d4;
	case 14809ULL: goto x86_l_39d9;
	case 14811ULL: goto x86_l_39db;
	case 14813ULL: goto x86_l_39dd;
	case 14818ULL: goto x86_l_39e2;
	case 14821ULL: goto x86_l_39e5;
	case 14824ULL: goto x86_l_39e8;
	case 14827ULL: goto x86_l_39eb;
	case 14830ULL: goto x86_l_39ee;
	case 14836ULL: goto x86_l_39f4;
	case 14840ULL: goto x86_l_39f8;
	case 14843ULL: goto x86_l_39fb;
	case 14846ULL: goto x86_l_39fe;
	case 14851ULL: goto x86_l_3a03;
	case 14853ULL: goto x86_l_3a05;
	case 14855ULL: goto x86_l_3a07;
	case 14860ULL: goto x86_l_3a0c;
	case 14863ULL: goto x86_l_3a0f;
	case 14866ULL: goto x86_l_3a12;
	case 14869ULL: goto x86_l_3a15;
	case 14872ULL: goto x86_l_3a18;
	case 14878ULL: goto x86_l_3a1e;
	case 14881ULL: goto x86_l_3a21;
	case 14884ULL: goto x86_l_3a24;
	case 14887ULL: goto x86_l_3a27;
	case 14890ULL: goto x86_l_3a2a;
	case 14895ULL: goto x86_l_3a2f;
	case 14897ULL: goto x86_l_3a31;
	case 14899ULL: goto x86_l_3a33;
	case 14904ULL: goto x86_l_3a38;
	case 14907ULL: goto x86_l_3a3b;
	case 14910ULL: goto x86_l_3a3e;
	case 14915ULL: goto x86_l_3a43;
	case 14918ULL: goto x86_l_3a46;
	case 14926ULL: goto x86_l_3a4e;
	case 14933ULL: goto x86_l_3a55;
	case 14938ULL: goto x86_l_3a5a;
	case 14943ULL: goto x86_l_3a5f;
	case 14945ULL: goto x86_l_3a61;
	case 14948ULL: goto x86_l_3a64;
	case 14950ULL: goto x86_l_3a66;
	case 14954ULL: goto x86_l_3a6a;
	case 14956ULL: goto x86_l_3a6c;
	case 14960ULL: goto x86_l_3a70;
	case 14962ULL: goto x86_l_3a72;
	case 14966ULL: goto x86_l_3a76;
	case 14968ULL: goto x86_l_3a78;
	case 14972ULL: goto x86_l_3a7c;
	case 14974ULL: goto x86_l_3a7e;
	case 14980ULL: goto x86_l_3a84;
	case 14982ULL: goto x86_l_3a86;
	case 14986ULL: goto x86_l_3a8a;
	case 14988ULL: goto x86_l_3a8c;
	case 14992ULL: goto x86_l_3a90;
	case 14994ULL: goto x86_l_3a92;
	case 14998ULL: goto x86_l_3a96;
	case 15000ULL: goto x86_l_3a98;
	case 15006ULL: goto x86_l_3a9e;
	case 15008ULL: goto x86_l_3aa0;
	case 15014ULL: goto x86_l_3aa6;
	case 15016ULL: goto x86_l_3aa8;
	case 15022ULL: goto x86_l_3aae;
	case 15024ULL: goto x86_l_3ab0;
	case 15030ULL: goto x86_l_3ab6;
	case 15032ULL: goto x86_l_3ab8;
	case 15038ULL: goto x86_l_3abe;
	case 15040ULL: goto x86_l_3ac0;
	case 15046ULL: goto x86_l_3ac6;
	case 15050ULL: goto x86_l_3aca;
	case 15053ULL: goto x86_l_3acd;
	case 15057ULL: goto x86_l_3ad1;
	case 15058ULL: goto x86_l_3ad2;
	case 15060ULL: goto x86_l_3ad4;
	case 15062ULL: goto x86_l_3ad6;
	case 15064ULL: goto x86_l_3ad8;
	case 15066ULL: goto x86_l_3ada;
	case 15067ULL: goto x86_l_3adb;
	case 15068ULL: goto x86_l_3adc;
	case 15070ULL: goto x86_l_3ade;
	case 15072ULL: goto x86_l_3ae0;
	case 15074ULL: goto x86_l_3ae2;
	case 15075ULL: goto x86_l_3ae3;
	case 15076ULL: goto x86_l_3ae4;
	case 15079ULL: goto x86_l_3ae7;
	case 15085ULL: goto x86_l_3aed;
	case 15088ULL: goto x86_l_3af0;
	case 15091ULL: goto x86_l_3af3;
	case 15098ULL: goto x86_l_3afa;
	case 15103ULL: goto x86_l_3aff;
	case 15107ULL: goto x86_l_3b03;
	case 15111ULL: goto x86_l_3b07;
	case 15116ULL: goto x86_l_3b0c;
	case 15118ULL: goto x86_l_3b0e;
	case 15120ULL: goto x86_l_3b10;
	case 15122ULL: goto x86_l_3b12;
	case 15124ULL: goto x86_l_3b14;
	case 15128ULL: goto x86_l_3b18;
	case 15132ULL: goto x86_l_3b1c;
	case 15140ULL: goto x86_l_3b24;
	case 15147ULL: goto x86_l_3b2b;
	case 15152ULL: goto x86_l_3b30;
	case 15157ULL: goto x86_l_3b35;
	case 15159ULL: goto x86_l_3b37;
	case 15162ULL: goto x86_l_3b3a;
	case 15164ULL: goto x86_l_3b3c;
	case 15168ULL: goto x86_l_3b40;
	case 15170ULL: goto x86_l_3b42;
	case 15177ULL: goto x86_l_3b49;
	case 15182ULL: goto x86_l_3b4e;
	case 15187ULL: goto x86_l_3b53;
	case 15190ULL: goto x86_l_3b56;
	case 15195ULL: goto x86_l_3b5b;
	case 15198ULL: goto x86_l_3b5e;
	case 15201ULL: goto x86_l_3b61;
	case 15203ULL: goto x86_l_3b63;
	case 15205ULL: goto x86_l_3b65;
	case 15207ULL: goto x86_l_3b67;
	case 15209ULL: goto x86_l_3b69;
	case 15216ULL: goto x86_l_3b70;
	case 15218ULL: goto x86_l_3b72;
	case 15225ULL: goto x86_l_3b79;
	case 15227ULL: goto x86_l_3b7b;
	case 15232ULL: goto x86_l_3b80;
	case 15235ULL: goto x86_l_3b83;
	case 15238ULL: goto x86_l_3b86;
	case 15240ULL: goto x86_l_3b88;
	case 15242ULL: goto x86_l_3b8a;
	case 15244ULL: goto x86_l_3b8c;
	case 15246ULL: goto x86_l_3b8e;
	case 15249ULL: goto x86_l_3b91;
	case 15252ULL: goto x86_l_3b94;
	case 15256ULL: goto x86_l_3b98;
	case 15257ULL: goto x86_l_3b99;
	case 15259ULL: goto x86_l_3b9b;
	case 15261ULL: goto x86_l_3b9d;
	case 15263ULL: goto x86_l_3b9f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_369b:
	/* 0x369b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36a0:
	/* 0x36a0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_36a5:
	/* 0x36a5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_36a8:
	/* 0x36a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36aa:
	/* 0x36aa: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36ae:
	/* 0x36ae: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36b2:
	/* 0x36b2: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_36b6:
	/* 0x36b6: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36b9:
	/* 0x36b9: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36bd:
	/* 0x36bd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36bf:
	/* 0x36bf: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_36c1:
	/* 0x36c1: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_36c4:
	/* 0x36c4: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_36c7:
	/* 0x36c7: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36cc:
	/* 0x36cc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36ce:
	/* 0x36ce: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_36d1:
	/* 0x36d1: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_36d5:
	/* 0x36d5: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_36d7:
	/* 0x36d7: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_36db:
	/* 0x36db: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_36dd:
	/* 0x36dd: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_36e0:
	/* 0x36e0: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_36e2:
	/* 0x36e2: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36e5:
	/* 0x36e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36ea:
	/* 0x36ea: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36ed:
	/* 0x36ed: jb     379a <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_379a;
	}
x86_l_36f3:
	/* 0x36f3: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_36fa:
	/* 0x36fa: ja     379a <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_379a;
	}
x86_l_3700:
	/* 0x3700: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3703:
	/* 0x3703: jbe    370a <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_370a;
	}
x86_l_3705:
	/* 0x3705: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_370a:
	/* 0x370a: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_370c:
	/* 0x370c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_370f:
	/* 0x370f: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3713:
	/* 0x3713: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3717:
	/* 0x3717: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_371a:
	/* 0x371a: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_371d:
	/* 0x371d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3722:
	/* 0x3722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3724:
	/* 0x3724: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3728:
	/* 0x3728: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_372b:
	/* 0x372b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3730:
	/* 0x3730: jbe    379a <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_379a;
	}
x86_l_3732:
	/* 0x3732: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3737:
	/* 0x3737: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_373a:
	/* 0x373a: jmp    378d <cwd_read_v61+0x193> */
	goto x86_l_378d;
x86_l_373c:
	/* 0x373c: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3740:
	/* 0x3740: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3745:
	/* 0x3745: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_374a:
	/* 0x374a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_374f:
	/* 0x374f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3754:
	/* 0x3754: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3756:
	/* 0x3756: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_375a:
	/* 0x375a: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_375f:
	/* 0x375f: je     3791 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3791;
	}
x86_l_3761:
	/* 0x3761: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3765:
	/* 0x3765: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_376a:
	/* 0x376a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_376f:
	/* 0x376f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3772:
	/* 0x3772: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3777:
	/* 0x3777: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_377a:
	/* 0x377a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_377c:
	/* 0x377c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3781:
	/* 0x3781: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3785:
	/* 0x3785: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3789:
	/* 0x3789: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_378d:
	/* 0x378d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_378f:
	/* 0x378f: jmp    379a <cwd_read_v61+0x1a0> */
	goto x86_l_379a;
x86_l_3791:
	/* 0x3791: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_3795:
	/* 0x3795: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_379a:
	/* 0x379a: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_379e:
	/* 0x379e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_379f:
	/* 0x379f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_37a1:
	/* 0x37a1: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_37a3:
	/* 0x37a3: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_37a5:
	/* 0x37a5: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_37a7:
	/* 0x37a7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_37a8:
	/* 0x37a8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_37a9:
	/* 0x37a9: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_37aa:
	/* 0x37aa: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_37ac:
	/* 0x37ac: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_37ae:
	/* 0x37ae: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_37b0:
	/* 0x37b0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_37b2:
	/* 0x37b2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_37b3:
	/* 0x37b3: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_37b4:
	/* 0x37b4: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_37b7:
	/* 0x37b7: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_37ba:
	/* 0x37ba: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_37bd:
	/* 0x37bd: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_37c0:
	/* 0x37c0: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_37c8:
	/* 0x37c8: mov    rdi,QWORD PTR [rip+0x360] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_37cf:
	/* 0x37cf: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37d4:
	/* 0x37d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37d9:
	/* 0x37d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37db:
	/* 0x37db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37de:
	/* 0x37de: je     3851 <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3851;
	}
x86_l_37e0:
	/* 0x37e0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_37e3:
	/* 0x37e3: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_37e9:
	/* 0x37e9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_37ee:
	/* 0x37ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f0:
	/* 0x37f0: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_37f3:
	/* 0x37f3: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_37f7:
	/* 0x37f7: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37fb:
	/* 0x37fb: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_37ff:
	/* 0x37ff: jne    380a <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_380a;
	}
x86_l_3801:
	/* 0x3801: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3806:
	/* 0x3806: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_380a:
	/* 0x380a: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_380f:
	/* 0x380f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3811:
	/* 0x3811: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3815:
	/* 0x3815: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3819:
	/* 0x3819: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_381d:
	/* 0x381d: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3821:
	/* 0x3821: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3825:
	/* 0x3825: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3828:
	/* 0x3828: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_382b:
	/* 0x382b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_382e:
	/* 0x382e: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3831:
	/* 0x3831: call   387c <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14390ULL);
	__x86_sim_call_depth++;
	goto x86_l_387c;
x86_l_3836:
	/* 0x3836: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3838:
	/* 0x3838: js     3855 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3855;
	}
x86_l_383a:
	/* 0x383a: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3841:
	/* 0x3841: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_3844:
	/* 0x3844: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3846:
	/* 0x3846: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3848:
	/* 0x3848: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_384c:
	/* 0x384c: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_384f:
	/* 0x384f: jmp    3862 <data_event_bytes+0xb9> */
	goto x86_l_3862;
x86_l_3851:
	/* 0x3851: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3853:
	/* 0x3853: jmp    386d <data_event_bytes+0xc4> */
	goto x86_l_386d;
x86_l_3855:
	/* 0x3855: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3857:
	/* 0x3857: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_385e:
	/* 0x385e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3860:
	/* 0x3860: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3862:
	/* 0x3862: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3865:
	/* 0x3865: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3868:
	/* 0x3868: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_386d:
	/* 0x386d: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3871:
	/* 0x3871: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3872:
	/* 0x3872: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3874:
	/* 0x3874: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3876:
	/* 0x3876: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3878:
	/* 0x3878: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_387a:
	/* 0x387a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_387b:
	/* 0x387b: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_387c:
	/* 0x387c: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_387d:
	/* 0x387d: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_387f:
	/* 0x387f: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3881:
	/* 0x3881: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_3883:
	/* 0x3883: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3885:
	/* 0x3885: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3886:
	/* 0x3886: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3887:
	/* 0x3887: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_388a:
	/* 0x388a: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_388d:
	/* 0x388d: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_3890:
	/* 0x3890: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_3893:
	/* 0x3893: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14488ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_3898:
	/* 0x3898: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_389a:
	/* 0x389a: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_38a0:
	/* 0x38a0: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_38a3:
	/* 0x38a3: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_38aa:
	/* 0x38aa: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_38ad:
	/* 0x38ad: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_38b0:
	/* 0x38b0: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_38b6:
	/* 0x38b6: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_38ba:
	/* 0x38ba: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_38bd:
	/* 0x38bd: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_38c0:
	/* 0x38c0: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14533ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_38c5:
	/* 0x38c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38c7:
	/* 0x38c7: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_38cd:
	/* 0x38cd: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_38d2:
	/* 0x38d2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_38d5:
	/* 0x38d5: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38d8:
	/* 0x38d8: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_38db:
	/* 0x38db: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_38de:
	/* 0x38de: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_38e4:
	/* 0x38e4: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_38e8:
	/* 0x38e8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_38eb:
	/* 0x38eb: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_38ee:
	/* 0x38ee: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14579ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_38f3:
	/* 0x38f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38f5:
	/* 0x38f5: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_38fb:
	/* 0x38fb: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3900:
	/* 0x3900: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3903:
	/* 0x3903: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3906:
	/* 0x3906: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3909:
	/* 0x3909: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_390c:
	/* 0x390c: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_3912:
	/* 0x3912: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3916:
	/* 0x3916: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3919:
	/* 0x3919: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_391c:
	/* 0x391c: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14625ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_3921:
	/* 0x3921: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3923:
	/* 0x3923: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_3929:
	/* 0x3929: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_392e:
	/* 0x392e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3931:
	/* 0x3931: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3934:
	/* 0x3934: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3937:
	/* 0x3937: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_393a:
	/* 0x393a: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_3940:
	/* 0x3940: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3944:
	/* 0x3944: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3947:
	/* 0x3947: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_394a:
	/* 0x394a: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14671ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_394f:
	/* 0x394f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3951:
	/* 0x3951: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_3957:
	/* 0x3957: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_395c:
	/* 0x395c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_395f:
	/* 0x395f: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3962:
	/* 0x3962: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3965:
	/* 0x3965: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3968:
	/* 0x3968: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_396e:
	/* 0x396e: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3972:
	/* 0x3972: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3975:
	/* 0x3975: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3978:
	/* 0x3978: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14717ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_397d:
	/* 0x397d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_397f:
	/* 0x397f: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_3985:
	/* 0x3985: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_398a:
	/* 0x398a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_398d:
	/* 0x398d: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3990:
	/* 0x3990: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3993:
	/* 0x3993: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3996:
	/* 0x3996: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_399c:
	/* 0x399c: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_39a0:
	/* 0x39a0: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_39a3:
	/* 0x39a3: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_39a6:
	/* 0x39a6: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14763ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_39ab:
	/* 0x39ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39ad:
	/* 0x39ad: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_39b3:
	/* 0x39b3: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_39b8:
	/* 0x39b8: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_39bb:
	/* 0x39bb: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39be:
	/* 0x39be: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_39c1:
	/* 0x39c1: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_39c4:
	/* 0x39c4: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_39ca:
	/* 0x39ca: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_39ce:
	/* 0x39ce: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_39d1:
	/* 0x39d1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_39d4:
	/* 0x39d4: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14809ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_39d9:
	/* 0x39d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39db:
	/* 0x39db: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_39dd:
	/* 0x39dd: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_39e2:
	/* 0x39e2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_39e5:
	/* 0x39e5: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39e8:
	/* 0x39e8: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_39eb:
	/* 0x39eb: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_39ee:
	/* 0x39ee: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_39f4:
	/* 0x39f4: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_39f8:
	/* 0x39f8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_39fb:
	/* 0x39fb: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_39fe:
	/* 0x39fe: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14851ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_3a03:
	/* 0x3a03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a05:
	/* 0x3a05: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_3a07:
	/* 0x3a07: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3a0c:
	/* 0x3a0c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3a0f:
	/* 0x3a0f: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a12:
	/* 0x3a12: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3a15:
	/* 0x3a15: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3a18:
	/* 0x3a18: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_3a1e:
	/* 0x3a1e: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a21:
	/* 0x3a21: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3a24:
	/* 0x3a24: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3a27:
	/* 0x3a27: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3a2a:
	/* 0x3a2a: call   3adc <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14895ULL);
	__x86_sim_call_depth++;
	goto x86_l_3adc;
x86_l_3a2f:
	/* 0x3a2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a31:
	/* 0x3a31: js     3a43 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3a43;
	}
x86_l_3a33:
	/* 0x3a33: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3a38:
	/* 0x3a38: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a3b:
	/* 0x3a3b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3a3e:
	/* 0x3a3e: jmp    3aca <do_bytes+0x24e> */
	goto x86_l_3aca;
x86_l_3a43:
	/* 0x3a43: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3a46:
	/* 0x3a46: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3a4e:
	/* 0x3a4e: mov    rdi,QWORD PTR [rip+0x440] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_3a55:
	/* 0x3a55: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a5a:
	/* 0x3a5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a5f:
	/* 0x3a5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a61:
	/* 0x3a61: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a64:
	/* 0x3a64: je     3aca <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aca;
	}
x86_l_3a66:
	/* 0x3a66: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_3a6a:
	/* 0x3a6a: jg     3a86 <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a86;
	}
x86_l_3a6c:
	/* 0x3a6c: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_3a70:
	/* 0x3a70: je     3aa0 <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aa0;
	}
x86_l_3a72:
	/* 0x3a72: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_3a76:
	/* 0x3a76: je     3ab8 <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ab8;
	}
x86_l_3a78:
	/* 0x3a78: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_3a7c:
	/* 0x3a7c: jne    3ab0 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3ab0;
	}
x86_l_3a7e:
	/* 0x3a7e: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_3a84:
	/* 0x3a84: jmp    3ac6 <do_bytes+0x24a> */
	goto x86_l_3ac6;
x86_l_3a86:
	/* 0x3a86: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_3a8a:
	/* 0x3a8a: je     3aa8 <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aa8;
	}
x86_l_3a8c:
	/* 0x3a8c: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_3a90:
	/* 0x3a90: je     3ac0 <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ac0;
	}
x86_l_3a92:
	/* 0x3a92: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3a96:
	/* 0x3a96: jne    3ab0 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3ab0;
	}
x86_l_3a98:
	/* 0x3a98: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_3a9e:
	/* 0x3a9e: jmp    3ac6 <do_bytes+0x24a> */
	goto x86_l_3ac6;
x86_l_3aa0:
	/* 0x3aa0: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_3aa6:
	/* 0x3aa6: jmp    3ac6 <do_bytes+0x24a> */
	goto x86_l_3ac6;
x86_l_3aa8:
	/* 0x3aa8: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_3aae:
	/* 0x3aae: jmp    3ac6 <do_bytes+0x24a> */
	goto x86_l_3ac6;
x86_l_3ab0:
	/* 0x3ab0: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_3ab6:
	/* 0x3ab6: jmp    3ac6 <do_bytes+0x24a> */
	goto x86_l_3ac6;
x86_l_3ab8:
	/* 0x3ab8: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_3abe:
	/* 0x3abe: jmp    3ac6 <do_bytes+0x24a> */
	goto x86_l_3ac6;
x86_l_3ac0:
	/* 0x3ac0: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_3ac6:
	/* 0x3ac6: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3aca:
	/* 0x3aca: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3acd:
	/* 0x3acd: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3ad1:
	/* 0x3ad1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3ad2:
	/* 0x3ad2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3ad4:
	/* 0x3ad4: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3ad6:
	/* 0x3ad6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3ad8:
	/* 0x3ad8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3ada:
	/* 0x3ada: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3adb:
	/* 0x3adb: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3adc:
	/* 0x3adc: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3ade:
	/* 0x3ade: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3ae0:
	/* 0x3ae0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3ae2:
	/* 0x3ae2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3ae3:
	/* 0x3ae3: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3ae4:
	/* 0x3ae4: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3ae7:
	/* 0x3ae7: js     3b69 <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b69;
	}
x86_l_3aed:
	/* 0x3aed: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_3af0:
	/* 0x3af0: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_3af3:
	/* 0x3af3: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_3afa:
	/* 0x3afa: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_3aff:
	/* 0x3aff: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_3b03:
	/* 0x3b03: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b07:
	/* 0x3b07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b0c:
	/* 0x3b0c: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_3b0e:
	/* 0x3b0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b10:
	/* 0x3b10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b12:
	/* 0x3b12: js     3b8e <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b8e;
	}
x86_l_3b14:
	/* 0x3b14: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b18:
	/* 0x3b18: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b1c:
	/* 0x3b1c: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3b24:
	/* 0x3b24: mov    rdi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_3b2b:
	/* 0x3b2b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b30:
	/* 0x3b30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b35:
	/* 0x3b35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b37:
	/* 0x3b37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b3a:
	/* 0x3b3a: je     3b72 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b72;
	}
x86_l_3b3c:
	/* 0x3b3c: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3b40:
	/* 0x3b40: je     3b72 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b72;
	}
x86_l_3b42:
	/* 0x3b42: mov    rsi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_3b49:
	/* 0x3b49: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3b4e:
	/* 0x3b4e: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3b53:
	/* 0x3b53: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3b56:
	/* 0x3b56: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3b5b:
	/* 0x3b5b: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3b5e:
	/* 0x3b5e: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_3b61:
	/* 0x3b61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b63:
	/* 0x3b63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b65:
	/* 0x3b65: js     3b8e <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b8e;
	}
x86_l_3b67:
	/* 0x3b67: jmp    3b91 <__do_bytes+0xb5> */
	goto x86_l_3b91;
x86_l_3b69:
	/* 0x3b69: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3b70:
	/* 0x3b70: jmp    3b91 <__do_bytes+0xb5> */
	goto x86_l_3b91;
x86_l_3b72:
	/* 0x3b72: mov    rdi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_3b79:
	/* 0x3b79: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b7b:
	/* 0x3b7b: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_3b80:
	/* 0x3b80: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3b83:
	/* 0x3b83: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3b86:
	/* 0x3b86: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b88:
	/* 0x3b88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b8a:
	/* 0x3b8a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b8c:
	/* 0x3b8c: jns    3b91 <__do_bytes+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3b91;
	}
x86_l_3b8e:
	/* 0x3b8e: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3b91:
	/* 0x3b91: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3b94:
	/* 0x3b94: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3b98:
	/* 0x3b98: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3b99:
	/* 0x3b99: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3b9b:
	/* 0x3b9b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3b9d:
	/* 0x3b9d: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3b9f:
	/* 0x3b9f: ret */
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
	for (__u32 __x86_iter = 0; __x86_iter < 13788U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1735ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1737ULL && __x86_pc <= 3586ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3592ULL && __x86_pc <= 5421ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5425ULL && __x86_pc <= 7230ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7235ULL && __x86_pc <= 9002ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9008ULL && __x86_pc <= 10783ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10785ULL && __x86_pc <= 12460ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12470ULL && __x86_pc <= 13974ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13979ULL && __x86_pc <= 15263ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

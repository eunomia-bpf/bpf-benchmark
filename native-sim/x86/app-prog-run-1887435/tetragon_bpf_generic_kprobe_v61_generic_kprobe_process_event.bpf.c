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
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
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
	case 96ULL: goto x86_l_60;
	case 103ULL: goto x86_l_67;
	case 111ULL: goto x86_l_6f;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 122ULL: goto x86_l_7a;
	case 125ULL: goto x86_l_7d;
	case 132ULL: goto x86_l_84;
	case 137ULL: goto x86_l_89;
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
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 346ULL: goto x86_l_15a;
	case 349ULL: goto x86_l_15d;
	case 354ULL: goto x86_l_162;
	case 361ULL: goto x86_l_169;
	case 366ULL: goto x86_l_16e;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 383ULL: goto x86_l_17f;
	case 387ULL: goto x86_l_183;
	case 390ULL: goto x86_l_186;
	case 393ULL: goto x86_l_189;
	case 398ULL: goto x86_l_18e;
	case 400ULL: goto x86_l_190;
	case 403ULL: goto x86_l_193;
	case 406ULL: goto x86_l_196;
	case 408ULL: goto x86_l_198;
	case 410ULL: goto x86_l_19a;
	case 413ULL: goto x86_l_19d;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 424ULL: goto x86_l_1a8;
	case 432ULL: goto x86_l_1b0;
	case 437ULL: goto x86_l_1b5;
	case 441ULL: goto x86_l_1b9;
	case 443ULL: goto x86_l_1bb;
	case 445ULL: goto x86_l_1bd;
	case 450ULL: goto x86_l_1c2;
	case 454ULL: goto x86_l_1c6;
	case 462ULL: goto x86_l_1ce;
	case 465ULL: goto x86_l_1d1;
	case 471ULL: goto x86_l_1d7;
	case 475ULL: goto x86_l_1db;
	case 478ULL: goto x86_l_1de;
	case 484ULL: goto x86_l_1e4;
	case 490ULL: goto x86_l_1ea;
	case 493ULL: goto x86_l_1ed;
	case 497ULL: goto x86_l_1f1;
	case 502ULL: goto x86_l_1f6;
	case 510ULL: goto x86_l_1fe;
	case 515ULL: goto x86_l_203;
	case 520ULL: goto x86_l_208;
	case 524ULL: goto x86_l_20c;
	case 530ULL: goto x86_l_212;
	case 535ULL: goto x86_l_217;
	case 542ULL: goto x86_l_21e;
	case 545ULL: goto x86_l_221;
	case 547ULL: goto x86_l_223;
	case 550ULL: goto x86_l_226;
	case 552ULL: goto x86_l_228;
	case 557ULL: goto x86_l_22d;
	case 562ULL: goto x86_l_232;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 572ULL: goto x86_l_23c;
	case 574ULL: goto x86_l_23e;
	case 576ULL: goto x86_l_240;
	case 579ULL: goto x86_l_243;
	case 583ULL: goto x86_l_247;
	case 585ULL: goto x86_l_249;
	case 590ULL: goto x86_l_24e;
	case 597ULL: goto x86_l_255;
	case 599ULL: goto x86_l_257;
	case 604ULL: goto x86_l_25c;
	case 608ULL: goto x86_l_260;
	case 611ULL: goto x86_l_263;
	case 618ULL: goto x86_l_26a;
	case 620ULL: goto x86_l_26c;
	case 625ULL: goto x86_l_271;
	case 627ULL: goto x86_l_273;
	case 632ULL: goto x86_l_278;
	case 634ULL: goto x86_l_27a;
	case 639ULL: goto x86_l_27f;
	case 646ULL: goto x86_l_286;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 658ULL: goto x86_l_292;
	case 660ULL: goto x86_l_294;
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 681ULL: goto x86_l_2a9;
	case 687ULL: goto x86_l_2af;
	case 691ULL: goto x86_l_2b3;
	case 693ULL: goto x86_l_2b5;
	case 697ULL: goto x86_l_2b9;
	case 702ULL: goto x86_l_2be;
	case 704ULL: goto x86_l_2c0;
	case 708ULL: goto x86_l_2c4;
	case 714ULL: goto x86_l_2ca;
	case 718ULL: goto x86_l_2ce;
	case 724ULL: goto x86_l_2d4;
	case 729ULL: goto x86_l_2d9;
	case 732ULL: goto x86_l_2dc;
	case 738ULL: goto x86_l_2e2;
	case 742ULL: goto x86_l_2e6;
	case 748ULL: goto x86_l_2ec;
	case 753ULL: goto x86_l_2f1;
	case 757ULL: goto x86_l_2f5;
	case 762ULL: goto x86_l_2fa;
	case 764ULL: goto x86_l_2fc;
	case 768ULL: goto x86_l_300;
	case 774ULL: goto x86_l_306;
	case 779ULL: goto x86_l_30b;
	case 782ULL: goto x86_l_30e;
	case 788ULL: goto x86_l_314;
	case 792ULL: goto x86_l_318;
	case 798ULL: goto x86_l_31e;
	case 802ULL: goto x86_l_322;
	case 808ULL: goto x86_l_328;
	case 813ULL: goto x86_l_32d;
	case 817ULL: goto x86_l_331;
	case 823ULL: goto x86_l_337;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 837ULL: goto x86_l_345;
	case 842ULL: goto x86_l_34a;
	case 845ULL: goto x86_l_34d;
	case 851ULL: goto x86_l_353;
	case 856ULL: goto x86_l_358;
	case 860ULL: goto x86_l_35c;
	case 866ULL: goto x86_l_362;
	case 870ULL: goto x86_l_366;
	case 876ULL: goto x86_l_36c;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 890ULL: goto x86_l_37a;
	case 896ULL: goto x86_l_380;
	case 901ULL: goto x86_l_385;
	case 905ULL: goto x86_l_389;
	case 911ULL: goto x86_l_38f;
	case 915ULL: goto x86_l_393;
	case 921ULL: goto x86_l_399;
	case 925ULL: goto x86_l_39d;
	case 931ULL: goto x86_l_3a3;
	case 935ULL: goto x86_l_3a7;
	case 941ULL: goto x86_l_3ad;
	case 947ULL: goto x86_l_3b3;
	case 952ULL: goto x86_l_3b8;
	case 956ULL: goto x86_l_3bc;
	case 962ULL: goto x86_l_3c2;
	case 966ULL: goto x86_l_3c6;
	case 972ULL: goto x86_l_3cc;
	case 976ULL: goto x86_l_3d0;
	case 982ULL: goto x86_l_3d6;
	case 986ULL: goto x86_l_3da;
	case 992ULL: goto x86_l_3e0;
	case 997ULL: goto x86_l_3e5;
	case 1001ULL: goto x86_l_3e9;
	case 1003ULL: goto x86_l_3eb;
	case 1008ULL: goto x86_l_3f0;
	case 1012ULL: goto x86_l_3f4;
	case 1018ULL: goto x86_l_3fa;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1026ULL: goto x86_l_402;
	case 1031ULL: goto x86_l_407;
	case 1034ULL: goto x86_l_40a;
	case 1036ULL: goto x86_l_40c;
	case 1042ULL: goto x86_l_412;
	case 1044ULL: goto x86_l_414;
	case 1050ULL: goto x86_l_41a;
	case 1052ULL: goto x86_l_41c;
	case 1056ULL: goto x86_l_420;
	case 1058ULL: goto x86_l_422;
	case 1062ULL: goto x86_l_426;
	case 1064ULL: goto x86_l_428;
	case 1070ULL: goto x86_l_42e;
	case 1072ULL: goto x86_l_430;
	case 1076ULL: goto x86_l_434;
	case 1078ULL: goto x86_l_436;
	case 1082ULL: goto x86_l_43a;
	case 1084ULL: goto x86_l_43c;
	case 1086ULL: goto x86_l_43e;
	case 1092ULL: goto x86_l_444;
	case 1094ULL: goto x86_l_446;
	case 1098ULL: goto x86_l_44a;
	case 1100ULL: goto x86_l_44c;
	case 1104ULL: goto x86_l_450;
	case 1106ULL: goto x86_l_452;
	case 1112ULL: goto x86_l_458;
	case 1114ULL: goto x86_l_45a;
	case 1120ULL: goto x86_l_460;
	case 1122ULL: goto x86_l_462;
	case 1128ULL: goto x86_l_468;
	case 1130ULL: goto x86_l_46a;
	case 1134ULL: goto x86_l_46e;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1144ULL: goto x86_l_478;
	case 1147ULL: goto x86_l_47b;
	case 1152ULL: goto x86_l_480;
	case 1163ULL: goto x86_l_48b;
	case 1168ULL: goto x86_l_490;
	case 1175ULL: goto x86_l_497;
	case 1183ULL: goto x86_l_49f;
	case 1185ULL: goto x86_l_4a1;
	case 1188ULL: goto x86_l_4a4;
	case 1194ULL: goto x86_l_4aa;
	case 1199ULL: goto x86_l_4af;
	case 1202ULL: goto x86_l_4b2;
	case 1205ULL: goto x86_l_4b5;
	case 1211ULL: goto x86_l_4bb;
	case 1215ULL: goto x86_l_4bf;
	case 1222ULL: goto x86_l_4c6;
	case 1229ULL: goto x86_l_4cd;
	case 1233ULL: goto x86_l_4d1;
	case 1241ULL: goto x86_l_4d9;
	case 1246ULL: goto x86_l_4de;
	case 1248ULL: goto x86_l_4e0;
	case 1254ULL: goto x86_l_4e6;
	case 1257ULL: goto x86_l_4e9;
	case 1264ULL: goto x86_l_4f0;
	case 1270ULL: goto x86_l_4f6;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1283ULL: goto x86_l_503;
	case 1295ULL: goto x86_l_50f;
	case 1299ULL: goto x86_l_513;
	case 1304ULL: goto x86_l_518;
	case 1309ULL: goto x86_l_51d;
	case 1314ULL: goto x86_l_522;
	case 1316ULL: goto x86_l_524;
	case 1320ULL: goto x86_l_528;
	case 1322ULL: goto x86_l_52a;
	case 1326ULL: goto x86_l_52e;
	case 1328ULL: goto x86_l_530;
	case 1332ULL: goto x86_l_534;
	case 1338ULL: goto x86_l_53a;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1372ULL: goto x86_l_55c;
	case 1376ULL: goto x86_l_560;
	case 1382ULL: goto x86_l_566;
	case 1386ULL: goto x86_l_56a;
	case 1392ULL: goto x86_l_570;
	case 1397ULL: goto x86_l_575;
	case 1402ULL: goto x86_l_57a;
	case 1407ULL: goto x86_l_57f;
	case 1409ULL: goto x86_l_581;
	case 1421ULL: goto x86_l_58d;
	case 1429ULL: goto x86_l_595;
	case 1437ULL: goto x86_l_59d;
	case 1439ULL: goto x86_l_59f;
	case 1443ULL: goto x86_l_5a3;
	case 1448ULL: goto x86_l_5a8;
	case 1453ULL: goto x86_l_5ad;
	case 1458ULL: goto x86_l_5b2;
	case 1463ULL: goto x86_l_5b7;
	case 1468ULL: goto x86_l_5bc;
	case 1470ULL: goto x86_l_5be;
	case 1475ULL: goto x86_l_5c3;
	case 1479ULL: goto x86_l_5c7;
	case 1490ULL: goto x86_l_5d2;
	case 1495ULL: goto x86_l_5d7;
	case 1502ULL: goto x86_l_5de;
	case 1510ULL: goto x86_l_5e6;
	case 1512ULL: goto x86_l_5e8;
	case 1515ULL: goto x86_l_5eb;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1547ULL: goto x86_l_60b;
	case 1554ULL: goto x86_l_612;
	case 1559ULL: goto x86_l_617;
	case 1567ULL: goto x86_l_61f;
	case 1572ULL: goto x86_l_624;
	case 1574ULL: goto x86_l_626;
	case 1582ULL: goto x86_l_62e;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1618ULL: goto x86_l_652;
	case 1620ULL: goto x86_l_654;
	case 1628ULL: goto x86_l_65c;
	case 1632ULL: goto x86_l_660;
	case 1637ULL: goto x86_l_665;
	case 1642ULL: goto x86_l_66a;
	case 1647ULL: goto x86_l_66f;
	case 1649ULL: goto x86_l_671;
	case 1655ULL: goto x86_l_677;
	case 1661ULL: goto x86_l_67d;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1670ULL: goto x86_l_686;
	case 1673ULL: goto x86_l_689;
	case 1678ULL: goto x86_l_68e;
	case 1683ULL: goto x86_l_693;
	case 1688ULL: goto x86_l_698;
	case 1692ULL: goto x86_l_69c;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1709ULL: goto x86_l_6ad;
	case 1714ULL: goto x86_l_6b2;
	case 1719ULL: goto x86_l_6b7;
	case 1721ULL: goto x86_l_6b9;
	case 1724ULL: goto x86_l_6bc;
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
	/* 0xa: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x247] */
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
	/* 0x31: je     1124 <generic_kprobe_process_event+0x1124> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4388ULL;
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
	/* 0x4a: ja     1093 <generic_kprobe_process_event+0x1093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 4243ULL;
	}
x86_l_50:
	/* 0x50: mov    DWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_5b:
	/* 0x5b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60:
	/* 0x60: mov    rdi,QWORD PTR [rip+0x247] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_67:
	/* 0x67: lea    rsi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_6f:
	/* 0x6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71:
	/* 0x71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: je     1093 <generic_kprobe_process_event+0x1093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4243ULL;
	}
x86_l_7a:
	/* 0x7a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_84:
	/* 0x84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_89:
	/* 0x89: mov    rdi,QWORD PTR [rip+0x244] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_90:
	/* 0x90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92:
	/* 0x92: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_95:
	/* 0x95: jg     1093 <generic_kprobe_process_event+0x1093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4243ULL;
	}
x86_l_9b:
	/* 0x9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e:
	/* 0x9e: je     1093 <generic_kprobe_process_event+0x1093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4243ULL;
	}
x86_l_a4:
	/* 0xa4: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
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
	/* 0xb0: mov    r12d,DWORD PTR [rax+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
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
	/* 0xd2: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
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
	/* 0xe6: jne    170 <generic_kprobe_process_event+0x170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_170;
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
	/* 0xfb: jmp    1c6 <generic_kprobe_process_event+0x1c6> */
	goto x86_l_1c6;
x86_l_100:
	/* 0x100: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_10c:
	/* 0x10c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e:
	/* 0x10e: jmp    2a9 <generic_kprobe_process_event+0x2a9> */
	goto x86_l_2a9;
x86_l_113:
	/* 0x113: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
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
	/* 0x133: je     190 <generic_kprobe_process_event+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_190;
	}
x86_l_135:
	/* 0x135: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_138:
	/* 0x138: je     1bb <generic_kprobe_process_event+0x1bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb;
	}
x86_l_13e:
	/* 0x13e: add    rdx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_141:
	/* 0x141: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_146:
	/* 0x146: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_14b:
	/* 0x14b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_150:
	/* 0x150: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_155:
	/* 0x155: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_158:
	/* 0x158: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15a:
	/* 0x15a: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_15d:
	/* 0x15d: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_162:
	/* 0x162: shlx   rcx,QWORD PTR [rsp+0x60],rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RBX)), ((96ULL << 32) | X86_ALU_SHL));
x86_l_169:
	/* 0x169: sarx   rsi,rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RCX, X86_WIDTH_64, X86_RBX, X86_ALU_SAR);
x86_l_16e:
	/* 0x16e: jmp    1bd <generic_kprobe_process_event+0x1bd> */
	goto x86_l_1bd;
x86_l_170:
	/* 0x170: mov    ecx,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 35ULL);
x86_l_175:
	/* 0x175: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17a:
	/* 0x17a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_17d:
	/* 0x17d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_17f:
	/* 0x17f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_183:
	/* 0x183: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_186:
	/* 0x186: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_189:
	/* 0x189: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18e:
	/* 0x18e: jmp    1c6 <generic_kprobe_process_event+0x1c6> */
	goto x86_l_1c6;
x86_l_190:
	/* 0x190: movzx  ecx,bl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_193:
	/* 0x193: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_196:
	/* 0x196: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_198:
	/* 0x198: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_19a:
	/* 0x19a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_19d:
	/* 0x19d: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 418ULL);
	__x86_sim_call_depth++;
	return 12233ULL;
x86_l_1a2:
	/* 0x1a2: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_1a8:
	/* 0x1a8: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1b0:
	/* 0x1b0: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b5:
	/* 0x1b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9:
	/* 0x1b9: jmp    1ce <generic_kprobe_process_event+0x1ce> */
	goto x86_l_1ce;
x86_l_1bb:
	/* 0x1bb: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd:
	/* 0x1bd: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c2:
	/* 0x1c2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1ce:
	/* 0x1ce: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1d1:
	/* 0x1d1: ja     2a9 <generic_kprobe_process_event+0x2a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a9;
	}
x86_l_1d7:
	/* 0x1d7: lea    rcx,[rdx+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_1db:
	/* 0x1db: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_1de:
	/* 0x1de: cmp    WORD PTR [rax+rcx*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 506806140928ULL);
x86_l_1e4:
	/* 0x1e4: je     2a9 <generic_kprobe_process_event+0x2a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a9;
	}
x86_l_1ea:
	/* 0x1ea: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ed:
	/* 0x1ed: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_1f1:
	/* 0x1f1: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f6:
	/* 0x1f6: lea    rax,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1fe:
	/* 0x1fe: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_203:
	/* 0x203: mov    BYTE PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_208:
	/* 0x208: lea    rax,[r15+rbp*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 2), 0ULL);
x86_l_20c:
	/* 0x20c: add    rax,0x5ea0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24224ULL);
x86_l_212:
	/* 0x212: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_217:
	/* 0x217: mov    rax,QWORD PTR [rip+0x243] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_21e:
	/* 0x21e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_221:
	/* 0x221: je     27a <generic_kprobe_process_event+0x27a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a;
	}
x86_l_223:
	/* 0x223: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_226:
	/* 0x226: jmp    249 <generic_kprobe_process_event+0x249> */
	goto x86_l_249;
x86_l_228:
	/* 0x228: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22d:
	/* 0x22d: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_232:
	/* 0x232: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_235:
	/* 0x235: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a:
	/* 0x23a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c:
	/* 0x23c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23e:
	/* 0x23e: js     296 <generic_kprobe_process_event+0x296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_296;
	}
x86_l_240:
	/* 0x240: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_243:
	/* 0x243: cmp    r15,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 10ULL);
x86_l_247:
	/* 0x247: je     2a1 <generic_kprobe_process_event+0x2a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1;
	}
x86_l_249:
	/* 0x249: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24e:
	/* 0x24e: cmp    WORD PTR [rax+r15*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 25769803776ULL);
x86_l_255:
	/* 0x255: je     2a1 <generic_kprobe_process_event+0x2a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1;
	}
x86_l_257:
	/* 0x257: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25c:
	/* 0x25c: mov    edx,DWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_260:
	/* 0x260: add    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_263:
	/* 0x263: cmp    WORD PTR [rax+r15*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 17179869184ULL);
x86_l_26a:
	/* 0x26a: je     240 <generic_kprobe_process_event+0x240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240;
	}
x86_l_26c:
	/* 0x26c: cmp    BYTE PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_271:
	/* 0x271: je     228 <generic_kprobe_process_event+0x228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228;
	}
x86_l_273:
	/* 0x273: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_278:
	/* 0x278: jmp    22d <generic_kprobe_process_event+0x22d> */
	goto x86_l_22d;
x86_l_27a:
	/* 0x27a: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_27f:
	/* 0x27f: lea    rsi,[rip+0x243] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 579ULL);
x86_l_286:
	/* 0x286: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28b:
	/* 0x28b: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_290:
	/* 0x290: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_292:
	/* 0x292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294:
	/* 0x294: jmp    2a1 <generic_kprobe_process_event+0x2a1> */
	goto x86_l_2a1;
x86_l_296:
	/* 0x296: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_299:
	/* 0x299: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_29e:
	/* 0x29e: mov    DWORD PTR [rax],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a1:
	/* 0x2a1: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2a9:
	/* 0x2a9: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_2af:
	/* 0x2af: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_2b3:
	/* 0x2b3: jg     2f1 <generic_kprobe_process_event+0x2f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f1;
	}
x86_l_2b5:
	/* 0x2b5: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_2b9:
	/* 0x2b9: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2be:
	/* 0x2be: jg     32d <generic_kprobe_process_event+0x32d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_32d;
	}
x86_l_2c0:
	/* 0x2c0: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_2c4:
	/* 0x2c4: jg     3b8 <generic_kprobe_process_event+0x3b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3b8;
	}
x86_l_2ca:
	/* 0x2ca: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2ce:
	/* 0x2ce: jg     446 <generic_kprobe_process_event+0x446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_446;
	}
x86_l_2d4:
	/* 0x2d4: lea    eax,[r12-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_2d9:
	/* 0x2d9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dc:
	/* 0x2dc: jb     40c <generic_kprobe_process_event+0x40c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_40c;
	}
x86_l_2e2:
	/* 0x2e2: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2e6:
	/* 0x2e6: je     40c <generic_kprobe_process_event+0x40c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c;
	}
x86_l_2ec:
	/* 0x2ec: jmp    478 <generic_kprobe_process_event+0x478> */
	goto x86_l_478;
x86_l_2f1:
	/* 0x2f1: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_2f5:
	/* 0x2f5: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fa:
	/* 0x2fa: jle    358 <generic_kprobe_process_event+0x358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_358;
	}
x86_l_2fc:
	/* 0x2fc: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_300:
	/* 0x300: jg     385 <generic_kprobe_process_event+0x385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_385;
	}
x86_l_306:
	/* 0x306: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_30b:
	/* 0x30b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30e:
	/* 0x30e: jb     45a <generic_kprobe_process_event+0x45a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_45a;
	}
x86_l_314:
	/* 0x314: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_318:
	/* 0x318: je     47b <generic_kprobe_process_event+0x47b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47b;
	}
x86_l_31e:
	/* 0x31e: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_322:
	/* 0x322: je     414 <generic_kprobe_process_event+0x414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_414;
	}
x86_l_328:
	/* 0x328: jmp    478 <generic_kprobe_process_event+0x478> */
	goto x86_l_478;
x86_l_32d:
	/* 0x32d: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_331:
	/* 0x331: jg     3e5 <generic_kprobe_process_event+0x3e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3e5;
	}
x86_l_337:
	/* 0x337: lea    eax,[r12-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_33c:
	/* 0x33c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_33f:
	/* 0x33f: jb     47b <generic_kprobe_process_event+0x47b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_47b;
	}
x86_l_345:
	/* 0x345: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_34a:
	/* 0x34a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34d:
	/* 0x34d: jb     40c <generic_kprobe_process_event+0x40c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_40c;
	}
x86_l_353:
	/* 0x353: jmp    478 <generic_kprobe_process_event+0x478> */
	goto x86_l_478;
x86_l_358:
	/* 0x358: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_35c:
	/* 0x35c: jg     402 <generic_kprobe_process_event+0x402> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_402;
	}
x86_l_362:
	/* 0x362: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_366:
	/* 0x366: je     414 <generic_kprobe_process_event+0x414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_414;
	}
x86_l_36c:
	/* 0x36c: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_370:
	/* 0x370: je     45a <generic_kprobe_process_event+0x45a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45a;
	}
x86_l_376:
	/* 0x376: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_37a:
	/* 0x37a: je     470 <generic_kprobe_process_event+0x470> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_470;
	}
x86_l_380:
	/* 0x380: jmp    478 <generic_kprobe_process_event+0x478> */
	goto x86_l_478;
x86_l_385:
	/* 0x385: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_389:
	/* 0x389: jle    430 <generic_kprobe_process_event+0x430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_430;
	}
x86_l_38f:
	/* 0x38f: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_393:
	/* 0x393: je     47b <generic_kprobe_process_event+0x47b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47b;
	}
x86_l_399:
	/* 0x399: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_39d:
	/* 0x39d: je     43e <generic_kprobe_process_event+0x43e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e;
	}
x86_l_3a3:
	/* 0x3a3: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_3a7:
	/* 0x3a7: jne    478 <generic_kprobe_process_event+0x478> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_478;
	}
x86_l_3ad:
	/* 0x3ad: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_3b3:
	/* 0x3b3: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_3b8:
	/* 0x3b8: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_3bc:
	/* 0x3bc: jg     45a <generic_kprobe_process_event+0x45a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_45a;
	}
x86_l_3c2:
	/* 0x3c2: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_3c6:
	/* 0x3c6: je     47b <generic_kprobe_process_event+0x47b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47b;
	}
x86_l_3cc:
	/* 0x3cc: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_3d0:
	/* 0x3d0: je     452 <generic_kprobe_process_event+0x452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_452;
	}
x86_l_3d6:
	/* 0x3d6: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_3da:
	/* 0x3da: je     470 <generic_kprobe_process_event+0x470> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_470;
	}
x86_l_3e0:
	/* 0x3e0: jmp    478 <generic_kprobe_process_event+0x478> */
	goto x86_l_478;
x86_l_3e5:
	/* 0x3e5: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_3e9:
	/* 0x3e9: jg     41c <generic_kprobe_process_event+0x41c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_41c;
	}
x86_l_3eb:
	/* 0x3eb: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f0:
	/* 0x3f0: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_3f4:
	/* 0x3f4: je     47b <generic_kprobe_process_event+0x47b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47b;
	}
x86_l_3fa:
	/* 0x3fa: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_3fe:
	/* 0x3fe: je     43e <generic_kprobe_process_event+0x43e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e;
	}
x86_l_400:
	/* 0x400: jmp    478 <generic_kprobe_process_event+0x478> */
	goto x86_l_478;
x86_l_402:
	/* 0x402: lea    eax,[r12-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_407:
	/* 0x407: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40a:
	/* 0x40a: jae    46a <generic_kprobe_process_event+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_46a;
	}
x86_l_40c:
	/* 0x40c: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_412:
	/* 0x412: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_414:
	/* 0x414: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_41a:
	/* 0x41a: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_41c:
	/* 0x41c: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_420:
	/* 0x420: je     462 <generic_kprobe_process_event+0x462> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_462;
	}
x86_l_422:
	/* 0x422: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_426:
	/* 0x426: jne    478 <generic_kprobe_process_event+0x478> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_478;
	}
x86_l_428:
	/* 0x428: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_42e:
	/* 0x42e: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_430:
	/* 0x430: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_434:
	/* 0x434: je     43e <generic_kprobe_process_event+0x43e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e;
	}
x86_l_436:
	/* 0x436: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_43a:
	/* 0x43a: je     452 <generic_kprobe_process_event+0x452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_452;
	}
x86_l_43c:
	/* 0x43c: jmp    478 <generic_kprobe_process_event+0x478> */
	goto x86_l_478;
x86_l_43e:
	/* 0x43e: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_444:
	/* 0x444: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_446:
	/* 0x446: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_44a:
	/* 0x44a: je     45a <generic_kprobe_process_event+0x45a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45a;
	}
x86_l_44c:
	/* 0x44c: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_450:
	/* 0x450: jne    478 <generic_kprobe_process_event+0x478> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_478;
	}
x86_l_452:
	/* 0x452: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_458:
	/* 0x458: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_45a:
	/* 0x45a: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_460:
	/* 0x460: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_462:
	/* 0x462: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_468:
	/* 0x468: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_46a:
	/* 0x46a: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_46e:
	/* 0x46e: jne    478 <generic_kprobe_process_event+0x478> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_478;
	}
x86_l_470:
	/* 0x470: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_476:
	/* 0x476: jmp    47b <generic_kprobe_process_event+0x47b> */
	goto x86_l_47b;
x86_l_478:
	/* 0x478: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47b:
	/* 0x47b: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_480:
	/* 0x480: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_48b:
	/* 0x48b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_490:
	/* 0x490: mov    rdi,QWORD PTR [rip+0x23b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_497:
	/* 0x497: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_49f:
	/* 0x49f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a1:
	/* 0x4a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a4:
	/* 0x4a4: je     1093 <generic_kprobe_process_event+0x1093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4243ULL;
	}
x86_l_4aa:
	/* 0x4aa: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_4af:
	/* 0x4af: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4b2:
	/* 0x4b2: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_4b5:
	/* 0x4b5: jbe    1093 <generic_kprobe_process_event+0x1093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4243ULL;
	}
x86_l_4bb:
	/* 0x4bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bf:
	/* 0x4bf: mov    ecx,DWORD PTR [rax+rdx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_4c6:
	/* 0x4c6: mov    DWORD PTR [rax+rbp*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_4cd:
	/* 0x4cd: lea    rsi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d1:
	/* 0x4d1: mov    QWORD PTR [rax+rdx*8+0x5e78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_4d9:
	/* 0x4d9: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4de:
	/* 0x4de: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4e0:
	/* 0x4e0: jne    108f <generic_kprobe_process_event+0x108f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4239ULL;
	}
x86_l_4e6:
	/* 0x4e6: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_4e9:
	/* 0x4e9: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_4f0:
	/* 0x4f0: and    esi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4f6:
	/* 0x4f6: add    rbp,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f9:
	/* 0x4f9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fe:
	/* 0x4fe: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_503:
	/* 0x503: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_50f:
	/* 0x50f: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_518:
	/* 0x518: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_51d:
	/* 0x51d: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_522:
	/* 0x522: jle    55c <generic_kprobe_process_event+0x55c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_55c;
	}
x86_l_524:
	/* 0x524: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_528:
	/* 0x528: je     581 <generic_kprobe_process_event+0x581> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_581;
	}
x86_l_52a:
	/* 0x52a: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_52e:
	/* 0x52e: je     59f <generic_kprobe_process_event+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59f;
	}
x86_l_530:
	/* 0x530: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_534:
	/* 0x534: jne    a7c <generic_kprobe_process_event+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2684ULL;
	}
x86_l_53a:
	/* 0x53a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53f:
	/* 0x53f: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_544:
	/* 0x544: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_549:
	/* 0x549: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54e:
	/* 0x54e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_550:
	/* 0x550: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_555:
	/* 0x555: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_55a:
	/* 0x55a: jmp    570 <generic_kprobe_process_event+0x570> */
	goto x86_l_570;
x86_l_55c:
	/* 0x55c: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_560:
	/* 0x560: je     9a6 <generic_kprobe_process_event+0x9a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2470ULL;
	}
x86_l_566:
	/* 0x566: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_56a:
	/* 0x56a: jne    a7c <generic_kprobe_process_event+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2684ULL;
	}
x86_l_570:
	/* 0x570: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_575:
	/* 0x575: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_57a:
	/* 0x57a: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_57f:
	/* 0x57f: jmp    5b7 <generic_kprobe_process_event+0x5b7> */
	goto x86_l_5b7;
x86_l_581:
	/* 0x581: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_58d:
	/* 0x58d: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_595:
	/* 0x595: lea    r15,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_59d:
	/* 0x59d: jmp    5c7 <generic_kprobe_process_event+0x5c7> */
	goto x86_l_5c7;
x86_l_59f:
	/* 0x59f: add    rdx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_5a3:
	/* 0x5a3: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5a8:
	/* 0x5a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5ad:
	/* 0x5ad: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5b2:
	/* 0x5b2: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5b7:
	/* 0x5b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bc:
	/* 0x5bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5be:
	/* 0x5be: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5c3:
	/* 0x5c3: add    r15,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_5c7:
	/* 0x5c7: mov    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_5d2:
	/* 0x5d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d7:
	/* 0x5d7: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_5de:
	/* 0x5de: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_5e6:
	/* 0x5e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e8:
	/* 0x5e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5eb:
	/* 0x5eb: je     686 <generic_kprobe_process_event+0x686> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_686;
	}
x86_l_5f1:
	/* 0x5f1: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5f4:
	/* 0x5f4: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f9:
	/* 0x5f9: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_5ff:
	/* 0x5ff: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_604:
	/* 0x604: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_609:
	/* 0x609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60b:
	/* 0x60b: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_612:
	/* 0x612: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_617:
	/* 0x617: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_61f:
	/* 0x61f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_624:
	/* 0x624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_626:
	/* 0x626: mov    rbp,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_62e:
	/* 0x62e: lea    rax,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_632:
	/* 0x632: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_637:
	/* 0x637: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63b:
	/* 0x63b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_640:
	/* 0x640: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_648:
	/* 0x648: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64d:
	/* 0x64d: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_652:
	/* 0x652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_654:
	/* 0x654: mov    rbx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_65c:
	/* 0x65c: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_660:
	/* 0x660: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_665:
	/* 0x665: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_66a:
	/* 0x66a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66f:
	/* 0x66f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_671:
	/* 0x671: cmp    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_677:
	/* 0x677: mov    r12d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4096ULL);
x86_l_67d:
	/* 0x67d: je     698 <generic_kprobe_process_event+0x698> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_698;
	}
x86_l_67f:
	/* 0x67f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_684:
	/* 0x684: jmp    6e4 <generic_kprobe_process_event+0x6e4> */
	return 1764ULL;
x86_l_686:
	/* 0x686: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_689:
	/* 0x689: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_68e:
	/* 0x68e: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_693:
	/* 0x693: jmp    c12 <generic_kprobe_process_event+0xc12> */
	return 3090ULL;
x86_l_698:
	/* 0x698: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_69c:
	/* 0x69c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6a1:
	/* 0x6a1: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6a6:
	/* 0x6a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ab:
	/* 0x6ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ad:
	/* 0x6ad: cmp    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6b2:
	/* 0x6b2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b7:
	/* 0x6b7: je     6e4 <generic_kprobe_process_event+0x6e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1764ULL;
	}
x86_l_6b9:
	/* 0x6b9: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_6bc:
	/* 0x6bc: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
	return 1731ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1731ULL: goto x86_l_6c3;
	case 1741ULL: goto x86_l_6cd;
	case 1748ULL: goto x86_l_6d4;
	case 1758ULL: goto x86_l_6de;
	case 1764ULL: goto x86_l_6e4;
	case 1773ULL: goto x86_l_6ed;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1806ULL: goto x86_l_70e;
	case 1818ULL: goto x86_l_71a;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1843ULL: goto x86_l_733;
	case 1851ULL: goto x86_l_73b;
	case 1859ULL: goto x86_l_743;
	case 1867ULL: goto x86_l_74b;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1891ULL: goto x86_l_763;
	case 1896ULL: goto x86_l_768;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1919ULL: goto x86_l_77f;
	case 1924ULL: goto x86_l_784;
	case 1929ULL: goto x86_l_789;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1944ULL: goto x86_l_798;
	case 1947ULL: goto x86_l_79b;
	case 1949ULL: goto x86_l_79d;
	case 1957ULL: goto x86_l_7a5;
	case 1961ULL: goto x86_l_7a9;
	case 1969ULL: goto x86_l_7b1;
	case 1976ULL: goto x86_l_7b8;
	case 1979ULL: goto x86_l_7bb;
	case 1984ULL: goto x86_l_7c0;
	case 1990ULL: goto x86_l_7c6;
	case 1996ULL: goto x86_l_7cc;
	case 2001ULL: goto x86_l_7d1;
	case 2009ULL: goto x86_l_7d9;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2035ULL: goto x86_l_7f3;
	case 2040ULL: goto x86_l_7f8;
	case 2048ULL: goto x86_l_800;
	case 2053ULL: goto x86_l_805;
	case 2055ULL: goto x86_l_807;
	case 2063ULL: goto x86_l_80f;
	case 2069ULL: goto x86_l_815;
	case 2073ULL: goto x86_l_819;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2091ULL: goto x86_l_82b;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2104ULL: goto x86_l_838;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2122ULL: goto x86_l_84a;
	case 2124ULL: goto x86_l_84c;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2141ULL: goto x86_l_85d;
	case 2146ULL: goto x86_l_862;
	case 2149ULL: goto x86_l_865;
	case 2151ULL: goto x86_l_867;
	case 2156ULL: goto x86_l_86c;
	case 2164ULL: goto x86_l_874;
	case 2171ULL: goto x86_l_87b;
	case 2174ULL: goto x86_l_87e;
	case 2181ULL: goto x86_l_885;
	case 2183ULL: goto x86_l_887;
	case 2185ULL: goto x86_l_889;
	case 2190ULL: goto x86_l_88e;
	case 2193ULL: goto x86_l_891;
	case 2201ULL: goto x86_l_899;
	case 2204ULL: goto x86_l_89c;
	case 2206ULL: goto x86_l_89e;
	case 2210ULL: goto x86_l_8a2;
	case 2212ULL: goto x86_l_8a4;
	case 2215ULL: goto x86_l_8a7;
	case 2218ULL: goto x86_l_8aa;
	case 2221ULL: goto x86_l_8ad;
	case 2224ULL: goto x86_l_8b0;
	case 2232ULL: goto x86_l_8b8;
	case 2235ULL: goto x86_l_8bb;
	case 2241ULL: goto x86_l_8c1;
	case 2247ULL: goto x86_l_8c7;
	case 2253ULL: goto x86_l_8cd;
	case 2255ULL: goto x86_l_8cf;
	case 2261ULL: goto x86_l_8d5;
	case 2264ULL: goto x86_l_8d8;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2277ULL: goto x86_l_8e5;
	case 2281ULL: goto x86_l_8e9;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2291ULL: goto x86_l_8f3;
	case 2299ULL: goto x86_l_8fb;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2312ULL: goto x86_l_908;
	case 2317ULL: goto x86_l_90d;
	case 2320ULL: goto x86_l_910;
	case 2326ULL: goto x86_l_916;
	case 2331ULL: goto x86_l_91b;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2350ULL: goto x86_l_92e;
	case 2352ULL: goto x86_l_930;
	case 2360ULL: goto x86_l_938;
	case 2365ULL: goto x86_l_93d;
	case 2371ULL: goto x86_l_943;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2393ULL: goto x86_l_959;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2408ULL: goto x86_l_968;
	case 2412ULL: goto x86_l_96c;
	case 2420ULL: goto x86_l_974;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2434ULL: goto x86_l_982;
	case 2439ULL: goto x86_l_987;
	case 2444ULL: goto x86_l_98c;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2463ULL: goto x86_l_99f;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2478ULL: goto x86_l_9ae;
	case 2483ULL: goto x86_l_9b3;
	case 2491ULL: goto x86_l_9bb;
	case 2496ULL: goto x86_l_9c0;
	case 2501ULL: goto x86_l_9c5;
	case 2503ULL: goto x86_l_9c7;
	case 2511ULL: goto x86_l_9cf;
	case 2514ULL: goto x86_l_9d2;
	case 2520ULL: goto x86_l_9d8;
	case 2531ULL: goto x86_l_9e3;
	case 2536ULL: goto x86_l_9e8;
	case 2543ULL: goto x86_l_9ef;
	case 2551ULL: goto x86_l_9f7;
	case 2553ULL: goto x86_l_9f9;
	case 2556ULL: goto x86_l_9fc;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2570ULL: goto x86_l_a0a;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2589ULL: goto x86_l_a1d;
	case 2595ULL: goto x86_l_a23;
	case 2599ULL: goto x86_l_a27;
	case 2605ULL: goto x86_l_a2d;
	case 2609ULL: goto x86_l_a31;
	case 2615ULL: goto x86_l_a37;
	case 2619ULL: goto x86_l_a3b;
	case 2625ULL: goto x86_l_a41;
	case 2629ULL: goto x86_l_a45;
	case 2635ULL: goto x86_l_a4b;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2648ULL: goto x86_l_a58;
	case 2654ULL: goto x86_l_a5e;
	case 2659ULL: goto x86_l_a63;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2673ULL: goto x86_l_a71;
	case 2679ULL: goto x86_l_a77;
	case 2684ULL: goto x86_l_a7c;
	case 2692ULL: goto x86_l_a84;
	case 2696ULL: goto x86_l_a88;
	case 2702ULL: goto x86_l_a8e;
	case 2705ULL: goto x86_l_a91;
	case 2715ULL: goto x86_l_a9b;
	case 2719ULL: goto x86_l_a9f;
	case 2725ULL: goto x86_l_aa5;
	case 2730ULL: goto x86_l_aaa;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2753ULL: goto x86_l_ac1;
	case 2761ULL: goto x86_l_ac9;
	case 2763ULL: goto x86_l_acb;
	case 2766ULL: goto x86_l_ace;
	case 2769ULL: goto x86_l_ad1;
	case 2775ULL: goto x86_l_ad7;
	case 2779ULL: goto x86_l_adb;
	case 2784ULL: goto x86_l_ae0;
	case 2790ULL: goto x86_l_ae6;
	case 2794ULL: goto x86_l_aea;
	case 2800ULL: goto x86_l_af0;
	case 2804ULL: goto x86_l_af4;
	case 2810ULL: goto x86_l_afa;
	case 2815ULL: goto x86_l_aff;
	case 2818ULL: goto x86_l_b02;
	case 2824ULL: goto x86_l_b08;
	case 2830ULL: goto x86_l_b0e;
	case 2835ULL: goto x86_l_b13;
	case 2840ULL: goto x86_l_b18;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2874ULL: goto x86_l_b3a;
	case 2879ULL: goto x86_l_b3f;
	case 2881ULL: goto x86_l_b41;
	case 2884ULL: goto x86_l_b44;
	case 2886ULL: goto x86_l_b46;
	case 2894ULL: goto x86_l_b4e;
	case 2897ULL: goto x86_l_b51;
	case 2904ULL: goto x86_l_b58;
	case 2910ULL: goto x86_l_b5e;
	case 2913ULL: goto x86_l_b61;
	case 2915ULL: goto x86_l_b63;
	case 2919ULL: goto x86_l_b67;
	case 2922ULL: goto x86_l_b6a;
	case 2928ULL: goto x86_l_b70;
	case 2931ULL: goto x86_l_b73;
	case 2933ULL: goto x86_l_b75;
	case 2936ULL: goto x86_l_b78;
	case 2938ULL: goto x86_l_b7a;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2966ULL: goto x86_l_b96;
	case 2968ULL: goto x86_l_b98;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2994ULL: goto x86_l_bb2;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3008ULL: goto x86_l_bc0;
	case 3016ULL: goto x86_l_bc8;
	case 3021ULL: goto x86_l_bcd;
	case 3023ULL: goto x86_l_bcf;
	case 3028ULL: goto x86_l_bd4;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3058ULL: goto x86_l_bf2;
	case 3064ULL: goto x86_l_bf8;
	case 3068ULL: goto x86_l_bfc;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3082ULL: goto x86_l_c0a;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3095ULL: goto x86_l_c17;
	case 3100ULL: goto x86_l_c1c;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3123ULL: goto x86_l_c33;
	case 3129ULL: goto x86_l_c39;
	case 3133ULL: goto x86_l_c3d;
	case 3139ULL: goto x86_l_c43;
	case 3143ULL: goto x86_l_c47;
	case 3149ULL: goto x86_l_c4d;
	case 3152ULL: goto x86_l_c50;
	case 3156ULL: goto x86_l_c54;
	case 3162ULL: goto x86_l_c5a;
	case 3167ULL: goto x86_l_c5f;
	case 3172ULL: goto x86_l_c64;
	case 3176ULL: goto x86_l_c68;
	case 3179ULL: goto x86_l_c6b;
	case 3183ULL: goto x86_l_c6f;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3221ULL: goto x86_l_c95;
	case 3223ULL: goto x86_l_c97;
	case 3227ULL: goto x86_l_c9b;
	case 3231ULL: goto x86_l_c9f;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3243ULL: goto x86_l_cab;
	case 3247ULL: goto x86_l_caf;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3266ULL: goto x86_l_cc2;
	case 3270ULL: goto x86_l_cc6;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3289ULL: goto x86_l_cd9;
	case 3293ULL: goto x86_l_cdd;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3310ULL: goto x86_l_cee;
	case 3312ULL: goto x86_l_cf0;
	case 3316ULL: goto x86_l_cf4;
	case 3323ULL: goto x86_l_cfb;
	case 3328ULL: goto x86_l_d00;
	case 3333ULL: goto x86_l_d05;
	case 3335ULL: goto x86_l_d07;
	case 3339ULL: goto x86_l_d0b;
	case 3347ULL: goto x86_l_d13;
	case 3355ULL: goto x86_l_d1b;
	case 3363ULL: goto x86_l_d23;
	case 3371ULL: goto x86_l_d2b;
	case 3375ULL: goto x86_l_d2f;
	case 3378ULL: goto x86_l_d32;
	case 3384ULL: goto x86_l_d38;
	case 3387ULL: goto x86_l_d3b;
	case 3393ULL: goto x86_l_d41;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3430ULL: goto x86_l_d66;
	case 3435ULL: goto x86_l_d6b;
	case 3439ULL: goto x86_l_d6f;
	case 3442ULL: goto x86_l_d72;
	case 3447ULL: goto x86_l_d77;
	case 3450ULL: goto x86_l_d7a;
	case 3452ULL: goto x86_l_d7c;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3468ULL: goto x86_l_d8c;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3492ULL: goto x86_l_da4;
	case 3498ULL: goto x86_l_daa;
	case 3502ULL: goto x86_l_dae;
	case 3508ULL: goto x86_l_db4;
	case 3512ULL: goto x86_l_db8;
	case 3518ULL: goto x86_l_dbe;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3531ULL: goto x86_l_dcb;
	case 3537ULL: goto x86_l_dd1;
	case 3542ULL: goto x86_l_dd6;
	case 3547ULL: goto x86_l_ddb;
	case 3550ULL: goto x86_l_dde;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3570ULL: goto x86_l_df2;
	case 3574ULL: goto x86_l_df6;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3593ULL: goto x86_l_e09;
	case 3598ULL: goto x86_l_e0e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c3:
	/* 0x6c3: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_6cd:
	/* 0x6cd: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_6d4:
	/* 0x6d4: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_6de:
	/* 0x6de: mov    r12d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4086ULL);
x86_l_6e4:
	/* 0x6e4: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6ed:
	/* 0x6ed: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_6f6:
	/* 0x6f6: mov    QWORD PTR [rsp+0x70],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6fb:
	/* 0x6fb: lea    r13,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_700:
	/* 0x700: lea    rbx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_705:
	/* 0x705: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_70e:
	/* 0x70e: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_71a:
	/* 0x71a: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_726:
	/* 0x726: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_72b:
	/* 0x72b: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_733:
	/* 0x733: mov    DWORD PTR [rsp+0x98],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_73b:
	/* 0x73b: lea    r12,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_743:
	/* 0x743: mov    BYTE PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_74b:
	/* 0x74b: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_74f:
	/* 0x74f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_754:
	/* 0x754: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_759:
	/* 0x759: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_75e:
	/* 0x75e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_761:
	/* 0x761: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_763:
	/* 0x763: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_768:
	/* 0x768: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_76b:
	/* 0x76b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_770:
	/* 0x770: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_775:
	/* 0x775: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_777:
	/* 0x777: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_77c:
	/* 0x77c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_77f:
	/* 0x77f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_784:
	/* 0x784: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_789:
	/* 0x789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78b:
	/* 0x78b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_790:
	/* 0x790: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_793:
	/* 0x793: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_798:
	/* 0x798: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_79b:
	/* 0x79b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79d:
	/* 0x79d: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7a5:
	/* 0x7a5: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_7a9:
	/* 0x7a9: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7b1:
	/* 0x7b1: mov    rax,QWORD PTR [rip+0x23b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_7b8:
	/* 0x7b8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bb:
	/* 0x7bb: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7c0:
	/* 0x7c0: je     987 <generic_kprobe_process_event+0x987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_987;
	}
x86_l_7c6:
	/* 0x7c6: mov    r12d,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2048ULL);
x86_l_7cc:
	/* 0x7cc: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7d1:
	/* 0x7d1: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7d9:
	/* 0x7d9: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7e1:
	/* 0x7e1: cmp    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_7e6:
	/* 0x7e6: jne    7f3 <generic_kprobe_process_event+0x7f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7f3;
	}
x86_l_7e8:
	/* 0x7e8: cmp    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 104ULL);
x86_l_7ed:
	/* 0x7ed: je     b25 <generic_kprobe_process_event+0xb25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b25;
	}
x86_l_7f3:
	/* 0x7f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7f8:
	/* 0x7f8: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_800:
	/* 0x800: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_805:
	/* 0x805: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_807:
	/* 0x807: cmp    r13,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 224ULL);
x86_l_80f:
	/* 0x80f: je     91b <generic_kprobe_process_event+0x91b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_91b;
	}
x86_l_815:
	/* 0x815: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_819:
	/* 0x819: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_81e:
	/* 0x81e: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_823:
	/* 0x823: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_828:
	/* 0x828: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_82b:
	/* 0x82b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82d:
	/* 0x82d: cmp    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_832:
	/* 0x832: je     91b <generic_kprobe_process_event+0x91b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_91b;
	}
x86_l_838:
	/* 0x838: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_83d:
	/* 0x83d: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_842:
	/* 0x842: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_847:
	/* 0x847: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_84a:
	/* 0x84a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84c:
	/* 0x84c: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_850:
	/* 0x850: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_855:
	/* 0x855: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_85d:
	/* 0x85d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_862:
	/* 0x862: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_865:
	/* 0x865: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_867:
	/* 0x867: mov    rbp,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_86c:
	/* 0x86c: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_874:
	/* 0x874: mov    ecx,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_87b:
	/* 0x87b: sub    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_87e:
	/* 0x87e: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_885:
	/* 0x885: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_887:
	/* 0x887: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_889:
	/* 0x889: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_88e:
	/* 0x88e: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_891:
	/* 0x891: add    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 176ULL);
x86_l_899:
	/* 0x899: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_89c:
	/* 0x89c: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_89e:
	/* 0x89e: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_8a2:
	/* 0x8a2: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_8a4:
	/* 0x8a4: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_8a7:
	/* 0x8a7: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8aa:
	/* 0x8aa: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_8ad:
	/* 0x8ad: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8b0:
	/* 0x8b0: mov    DWORD PTR [rsp+0x98],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8b8:
	/* 0x8b8: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8bb:
	/* 0x8bb: jb     b2d <generic_kprobe_process_event+0xb2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b2d;
	}
x86_l_8c1:
	/* 0x8c1: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_8c7:
	/* 0x8c7: ja     b2d <generic_kprobe_process_event+0xb2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b2d;
	}
x86_l_8cd:
	/* 0x8cd: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_8cf:
	/* 0x8cf: jbe    d6b <generic_kprobe_process_event+0xd6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d6b;
	}
x86_l_8d5:
	/* 0x8d5: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_8d8:
	/* 0x8d8: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_8dc:
	/* 0x8dc: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_8e1:
	/* 0x8e1: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8e5:
	/* 0x8e5: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_8e9:
	/* 0x8e9: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_8ec:
	/* 0x8ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8f1:
	/* 0x8f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f3:
	/* 0x8f3: mov    QWORD PTR [rsp+0x90],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8fb:
	/* 0x8fb: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_8fe:
	/* 0x8fe: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_903:
	/* 0x903: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_908:
	/* 0x908: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_90d:
	/* 0x90d: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_910:
	/* 0x910: jne    7cc <generic_kprobe_process_event+0x7cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7cc;
	}
x86_l_916:
	/* 0x916: jmp    b32 <generic_kprobe_process_event+0xb32> */
	goto x86_l_b32;
x86_l_91b:
	/* 0x91b: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91f:
	/* 0x91f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_924:
	/* 0x924: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_929:
	/* 0x929: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_92e:
	/* 0x92e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_930:
	/* 0x930: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_938:
	/* 0x938: cmp    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 80ULL);
x86_l_93d:
	/* 0x93d: je     b25 <generic_kprobe_process_event+0xb25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b25;
	}
x86_l_943:
	/* 0x943: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_947:
	/* 0x947: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_94c:
	/* 0x94c: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_951:
	/* 0x951: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_956:
	/* 0x956: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_959:
	/* 0x959: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95b:
	/* 0x95b: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_960:
	/* 0x960: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_968:
	/* 0x968: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_96c:
	/* 0x96c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_974:
	/* 0x974: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_979:
	/* 0x979: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_97c:
	/* 0x97c: jne    7cc <generic_kprobe_process_event+0x7cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7cc;
	}
x86_l_982:
	/* 0x982: jmp    b32 <generic_kprobe_process_event+0xb32> */
	goto x86_l_b32;
x86_l_987:
	/* 0x987: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_98c:
	/* 0x98c: lea    rsi,[rip+0x23b] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 571ULL);
x86_l_993:
	/* 0x993: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_998:
	/* 0x998: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_99d:
	/* 0x99d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_99f:
	/* 0x99f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a1:
	/* 0x9a1: jmp    b2d <generic_kprobe_process_event+0xb2d> */
	goto x86_l_b2d;
x86_l_9a6:
	/* 0x9a6: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_9ae:
	/* 0x9ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9b3:
	/* 0x9b3: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9bb:
	/* 0x9bb: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9c0:
	/* 0x9c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c5:
	/* 0x9c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c7:
	/* 0x9c7: mov    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9cf:
	/* 0x9cf: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_9d2:
	/* 0x9d2: jne    5c7 <generic_kprobe_process_event+0x5c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1479ULL;
	}
x86_l_9d8:
	/* 0x9d8: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_9e3:
	/* 0x9e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9e8:
	/* 0x9e8: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_9ef:
	/* 0x9ef: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_9f7:
	/* 0x9f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f9:
	/* 0x9f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9fc:
	/* 0x9fc: je     d89 <generic_kprobe_process_event+0xd89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d89;
	}
x86_l_a02:
	/* 0xa02: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a07:
	/* 0xa07: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0a:
	/* 0xa0a: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_a0e:
	/* 0xa0e: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a13:
	/* 0xa13: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a18:
	/* 0xa18: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a1d:
	/* 0xa1d: jg     e60 <generic_kprobe_process_event+0xe60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3680ULL;
	}
x86_l_a23:
	/* 0xa23: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_a27:
	/* 0xa27: jle    fad <generic_kprobe_process_event+0xfad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4013ULL;
	}
x86_l_a2d:
	/* 0xa2d: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_a31:
	/* 0xa31: jle    13fe <generic_kprobe_process_event+0x13fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5118ULL;
	}
x86_l_a37:
	/* 0xa37: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_a3b:
	/* 0xa3b: je     1ba9 <generic_kprobe_process_event+0x1ba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7081ULL;
	}
x86_l_a41:
	/* 0xa41: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_a45:
	/* 0xa45: je     1b30 <generic_kprobe_process_event+0x1b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6960ULL;
	}
x86_l_a4b:
	/* 0xa4b: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_a4f:
	/* 0xa4f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a54:
	/* 0xa54: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a58:
	/* 0xa58: jne    105f <generic_kprobe_process_event+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4191ULL;
	}
x86_l_a5e:
	/* 0xa5e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a63:
	/* 0xa63: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_a6a:
	/* 0xa6a: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6f:
	/* 0xa6f: mov    DWORD PTR [rax],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a71:
	/* 0xa71: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_a77:
	/* 0xa77: jmp    105f <generic_kprobe_process_event+0x105f> */
	return 4191ULL;
x86_l_a7c:
	/* 0xa7c: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a84:
	/* 0xa84: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_a88:
	/* 0xa88: ja     9d8 <generic_kprobe_process_event+0x9d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9d8;
	}
x86_l_a8e:
	/* 0xa8e: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_a91:
	/* 0xa91: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_a9b:
	/* 0xa9b: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_a9f:
	/* 0xa9f: jae    9d8 <generic_kprobe_process_event+0x9d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9d8;
	}
x86_l_aa5:
	/* 0xaa5: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_aaa:
	/* 0xaaa: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_ab5:
	/* 0xab5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aba:
	/* 0xaba: mov    rdi,QWORD PTR [rip+0x23b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_ac1:
	/* 0xac1: lea    rsi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_ac9:
	/* 0xac9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acb:
	/* 0xacb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ace:
	/* 0xace: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad1:
	/* 0xad1: je     c1c <generic_kprobe_process_event+0xc1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1c;
	}
x86_l_ad7:
	/* 0xad7: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_adb:
	/* 0xadb: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ae0:
	/* 0xae0: jle    c26 <generic_kprobe_process_event+0xc26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c26;
	}
x86_l_ae6:
	/* 0xae6: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_aea:
	/* 0xaea: jle    da0 <generic_kprobe_process_event+0xda0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_da0;
	}
x86_l_af0:
	/* 0xaf0: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_af4:
	/* 0xaf4: jg     e9c <generic_kprobe_process_event+0xe9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3740ULL;
	}
x86_l_afa:
	/* 0xafa: lea    eax,[r12-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_aff:
	/* 0xaff: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b02:
	/* 0xb02: jae    14ce <generic_kprobe_process_event+0x14ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5326ULL;
	}
x86_l_b08:
	/* 0xb08: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_b0e:
	/* 0xb0e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b13:
	/* 0xb13: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b18:
	/* 0xb18: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_b1b:
	/* 0xb1b: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b20:
	/* 0xb20: jmp    1044 <generic_kprobe_process_event+0x1044> */
	return 4164ULL;
x86_l_b25:
	/* 0xb25: mov    BYTE PTR [rsp+0x9c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898177ULL);
x86_l_b2d:
	/* 0xb2d: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b32:
	/* 0xb32: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b3a:
	/* 0xb3a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b3f:
	/* 0xb3f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b41:
	/* 0xb41: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_b44:
	/* 0xb44: je     b7a <generic_kprobe_process_event+0xb7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7a;
	}
x86_l_b46:
	/* 0xb46: cmp    BYTE PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_b4e:
	/* 0xb4e: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_b51:
	/* 0xb51: mov    edx,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b58:
	/* 0xb58: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_b5e:
	/* 0xb5e: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b61:
	/* 0xb61: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b63:
	/* 0xb63: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_b67:
	/* 0xb67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b6a:
	/* 0xb6a: je     c0f <generic_kprobe_process_event+0xc0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c0f;
	}
x86_l_b70:
	/* 0xb70: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_b73:
	/* 0xb73: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b75:
	/* 0xb75: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_b78:
	/* 0xb78: jmp    b7d <generic_kprobe_process_event+0xb7d> */
	goto x86_l_b7d;
x86_l_b7a:
	/* 0xb7a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b7d:
	/* 0xb7d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b82:
	/* 0xb82: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b87:
	/* 0xb87: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b8e:
	/* 0xb8e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b93:
	/* 0xb93: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_b96:
	/* 0xb96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b98:
	/* 0xb98: mov    DWORD PTR [r12],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9c:
	/* 0xb9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ba1:
	/* 0xba1: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ba6:
	/* 0xba6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bab:
	/* 0xbab: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bb0:
	/* 0xbb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb2:
	/* 0xbb2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bb7:
	/* 0xbb7: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bbc:
	/* 0xbbc: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_bc0:
	/* 0xbc0: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bc8:
	/* 0xbc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bcd:
	/* 0xbcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcf:
	/* 0xbcf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bd4:
	/* 0xbd4: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bdc:
	/* 0xbdc: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_be1:
	/* 0xbe1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_be6:
	/* 0xbe6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be8:
	/* 0xbe8: mov    DWORD PTR [r12+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_bed:
	/* 0xbed: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_bf2:
	/* 0xbf2: mov    WORD PTR [r12+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_bf8:
	/* 0xbf8: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_bfc:
	/* 0xbfc: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c01:
	/* 0xc01: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c06:
	/* 0xc06: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0a:
	/* 0xc0a: jmp    105f <generic_kprobe_process_event+0x105f> */
	return 4191ULL;
x86_l_c0f:
	/* 0xc0f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c12:
	/* 0xc12: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c17:
	/* 0xc17: jmp    1064 <generic_kprobe_process_event+0x1064> */
	return 4196ULL;
x86_l_c1c:
	/* 0xc1c: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c21:
	/* 0xc21: jmp    104c <generic_kprobe_process_event+0x104c> */
	return 4172ULL;
x86_l_c26:
	/* 0xc26: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_c2a:
	/* 0xc2a: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c2f:
	/* 0xc2f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c33:
	/* 0xc33: jg     dd6 <generic_kprobe_process_event+0xdd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dd6;
	}
x86_l_c39:
	/* 0xc39: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_c3d:
	/* 0xc3d: jle    1135 <generic_kprobe_process_event+0x1135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4405ULL;
	}
x86_l_c43:
	/* 0xc43: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_c47:
	/* 0xc47: je     16f2 <generic_kprobe_process_event+0x16f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5874ULL;
	}
x86_l_c4d:
	/* 0xc4d: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_c50:
	/* 0xc50: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_c54:
	/* 0xc54: je     e2c <generic_kprobe_process_event+0xe2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3628ULL;
	}
x86_l_c5a:
	/* 0xc5a: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5f:
	/* 0xc5f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c64:
	/* 0xc64: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_c68:
	/* 0xc68: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_c6b:
	/* 0xc6b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6f:
	/* 0xc6f: jne    1055 <generic_kprobe_process_event+0x1055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4181ULL;
	}
x86_l_c75:
	/* 0xc75: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c7a:
	/* 0xc7a: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c7f:
	/* 0xc7f: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c83:
	/* 0xc83: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_c87:
	/* 0xc87: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c8b:
	/* 0xc8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c90:
	/* 0xc90: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c95:
	/* 0xc95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c97:
	/* 0xc97: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_c9b:
	/* 0xc9b: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_c9f:
	/* 0xc9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ca4:
	/* 0xca4: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_ca9:
	/* 0xca9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cab:
	/* 0xcab: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_caf:
	/* 0xcaf: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_cb6:
	/* 0xcb6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cbb:
	/* 0xcbb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_cc0:
	/* 0xcc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc2:
	/* 0xcc2: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cc6:
	/* 0xcc6: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_ccd:
	/* 0xccd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd2:
	/* 0xcd2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_cd7:
	/* 0xcd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd9:
	/* 0xcd9: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cdd:
	/* 0xcdd: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_ce4:
	/* 0xce4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ce9:
	/* 0xce9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cee:
	/* 0xcee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf0:
	/* 0xcf0: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_cf4:
	/* 0xcf4: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_cfb:
	/* 0xcfb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d00:
	/* 0xd00: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d05:
	/* 0xd05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d07:
	/* 0xd07: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d0b:
	/* 0xd0b: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d13:
	/* 0xd13: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d1b:
	/* 0xd1b: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d23:
	/* 0xd23: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_d2b:
	/* 0xd2b: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_d2f:
	/* 0xd2f: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_d32:
	/* 0xd32: je     1ed8 <generic_kprobe_process_event+0x1ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7896ULL;
	}
x86_l_d38:
	/* 0xd38: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d3b:
	/* 0xd3b: jne    1f00 <generic_kprobe_process_event+0x1f00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7936ULL;
	}
x86_l_d41:
	/* 0xd41: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d45:
	/* 0xd45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d4a:
	/* 0xd4a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d4f:
	/* 0xd4f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d54:
	/* 0xd54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d56:
	/* 0xd56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d5b:
	/* 0xd5b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d5e:
	/* 0xd5e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d63:
	/* 0xd63: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d66:
	/* 0xd66: jmp    1efe <generic_kprobe_process_event+0x1efe> */
	return 7934ULL;
x86_l_d6b:
	/* 0xd6b: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d6f:
	/* 0xd6f: add    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d72:
	/* 0xd72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d77:
	/* 0xd77: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d7a:
	/* 0xd7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7c:
	/* 0xd7c: mov    QWORD PTR [rsp+0x90],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d84:
	/* 0xd84: jmp    b2d <generic_kprobe_process_event+0xb2d> */
	goto x86_l_b2d;
x86_l_d89:
	/* 0xd89: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8c:
	/* 0xd8c: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d91:
	/* 0xd91: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d96:
	/* 0xd96: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d9b:
	/* 0xd9b: jmp    c01 <generic_kprobe_process_event+0xc01> */
	goto x86_l_c01;
x86_l_da0:
	/* 0xda0: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_da4:
	/* 0xda4: jg     102c <generic_kprobe_process_event+0x102c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4140ULL;
	}
x86_l_daa:
	/* 0xdaa: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_dae:
	/* 0xdae: je     1526 <generic_kprobe_process_event+0x1526> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5414ULL;
	}
x86_l_db4:
	/* 0xdb4: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_db8:
	/* 0xdb8: je     15dd <generic_kprobe_process_event+0x15dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5597ULL;
	}
x86_l_dbe:
	/* 0xdbe: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_dc2:
	/* 0xdc2: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dc7:
	/* 0xdc7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dcb:
	/* 0xdcb: je     1145 <generic_kprobe_process_event+0x1145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4421ULL;
	}
x86_l_dd1:
	/* 0xdd1: jmp    1055 <generic_kprobe_process_event+0x1055> */
	return 4181ULL;
x86_l_dd6:
	/* 0xdd6: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_ddb:
	/* 0xddb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_dde:
	/* 0xdde: jb     1145 <generic_kprobe_process_event+0x1145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4421ULL;
	}
x86_l_de4:
	/* 0xde4: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_de9:
	/* 0xde9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_dec:
	/* 0xdec: jb     1174 <generic_kprobe_process_event+0x1174> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4468ULL;
	}
x86_l_df2:
	/* 0xdf2: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_df6:
	/* 0xdf6: jne    1055 <generic_kprobe_process_event+0x1055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4181ULL;
	}
x86_l_dfc:
	/* 0xdfc: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_dff:
	/* 0xdff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e04:
	/* 0xe04: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e09:
	/* 0xe09: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e0e:
	/* 0xe0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 3603ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3603ULL: goto x86_l_e13;
	case 3606ULL: goto x86_l_e16;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3621ULL: goto x86_l_e25;
	case 3626ULL: goto x86_l_e2a;
	case 3628ULL: goto x86_l_e2c;
	case 3633ULL: goto x86_l_e31;
	case 3637ULL: goto x86_l_e35;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3649ULL: goto x86_l_e41;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3661ULL: goto x86_l_e4d;
	case 3665ULL: goto x86_l_e51;
	case 3668ULL: goto x86_l_e54;
	case 3672ULL: goto x86_l_e58;
	case 3675ULL: goto x86_l_e5b;
	case 3680ULL: goto x86_l_e60;
	case 3684ULL: goto x86_l_e64;
	case 3690ULL: goto x86_l_e6a;
	case 3693ULL: goto x86_l_e6d;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3707ULL: goto x86_l_e7b;
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3727ULL: goto x86_l_e8f;
	case 3729ULL: goto x86_l_e91;
	case 3735ULL: goto x86_l_e97;
	case 3740ULL: goto x86_l_e9c;
	case 3744ULL: goto x86_l_ea0;
	case 3750ULL: goto x86_l_ea6;
	case 3754ULL: goto x86_l_eaa;
	case 3760ULL: goto x86_l_eb0;
	case 3764ULL: goto x86_l_eb4;
	case 3769ULL: goto x86_l_eb9;
	case 3773ULL: goto x86_l_ebd;
	case 3779ULL: goto x86_l_ec3;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3800ULL: goto x86_l_ed8;
	case 3808ULL: goto x86_l_ee0;
	case 3816ULL: goto x86_l_ee8;
	case 3824ULL: goto x86_l_ef0;
	case 3832ULL: goto x86_l_ef8;
	case 3840ULL: goto x86_l_f00;
	case 3848ULL: goto x86_l_f08;
	case 3856ULL: goto x86_l_f10;
	case 3864ULL: goto x86_l_f18;
	case 3872ULL: goto x86_l_f20;
	case 3880ULL: goto x86_l_f28;
	case 3888ULL: goto x86_l_f30;
	case 3896ULL: goto x86_l_f38;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3912ULL: goto x86_l_f48;
	case 3917ULL: goto x86_l_f4d;
	case 3920ULL: goto x86_l_f50;
	case 3922ULL: goto x86_l_f52;
	case 3925ULL: goto x86_l_f55;
	case 3931ULL: goto x86_l_f5b;
	case 3935ULL: goto x86_l_f5f;
	case 3940ULL: goto x86_l_f64;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3953ULL: goto x86_l_f71;
	case 3955ULL: goto x86_l_f73;
	case 3958ULL: goto x86_l_f76;
	case 3964ULL: goto x86_l_f7c;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3977ULL: goto x86_l_f89;
	case 3983ULL: goto x86_l_f8f;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4000ULL: goto x86_l_fa0;
	case 4006ULL: goto x86_l_fa6;
	case 4008ULL: goto x86_l_fa8;
	case 4013ULL: goto x86_l_fad;
	case 4017ULL: goto x86_l_fb1;
	case 4023ULL: goto x86_l_fb7;
	case 4026ULL: goto x86_l_fba;
	case 4030ULL: goto x86_l_fbe;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4055ULL: goto x86_l_fd7;
	case 4059ULL: goto x86_l_fdb;
	case 4065ULL: goto x86_l_fe1;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4097ULL: goto x86_l_1001;
	case 4100ULL: goto x86_l_1004;
	case 4106ULL: goto x86_l_100a;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	case 4118ULL: goto x86_l_1016;
	case 4124ULL: goto x86_l_101c;
	case 4129ULL: goto x86_l_1021;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4159ULL: goto x86_l_103f;
	case 4164ULL: goto x86_l_1044;
	case 4167ULL: goto x86_l_1047;
	case 4169ULL: goto x86_l_1049;
	case 4172ULL: goto x86_l_104c;
	case 4177ULL: goto x86_l_1051;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4194ULL: goto x86_l_1062;
	case 4196ULL: goto x86_l_1064;
	case 4203ULL: goto x86_l_106b;
	case 4207ULL: goto x86_l_106f;
	case 4210ULL: goto x86_l_1072;
	case 4212ULL: goto x86_l_1074;
	case 4223ULL: goto x86_l_107f;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4241ULL: goto x86_l_1091;
	case 4243ULL: goto x86_l_1093;
	case 4247ULL: goto x86_l_1097;
	case 4250ULL: goto x86_l_109a;
	case 4252ULL: goto x86_l_109c;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4279ULL: goto x86_l_10b7;
	case 4282ULL: goto x86_l_10ba;
	case 4284ULL: goto x86_l_10bc;
	case 4290ULL: goto x86_l_10c2;
	case 4295ULL: goto x86_l_10c7;
	case 4302ULL: goto x86_l_10ce;
	case 4305ULL: goto x86_l_10d1;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4314ULL: goto x86_l_10da;
	case 4316ULL: goto x86_l_10dc;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4326ULL: goto x86_l_10e6;
	case 4333ULL: goto x86_l_10ed;
	case 4338ULL: goto x86_l_10f2;
	case 4345ULL: goto x86_l_10f9;
	case 4348ULL: goto x86_l_10fc;
	case 4353ULL: goto x86_l_1101;
	case 4355ULL: goto x86_l_1103;
	case 4366ULL: goto x86_l_110e;
	case 4371ULL: goto x86_l_1113;
	case 4378ULL: goto x86_l_111a;
	case 4381ULL: goto x86_l_111d;
	case 4386ULL: goto x86_l_1122;
	case 4388ULL: goto x86_l_1124;
	case 4390ULL: goto x86_l_1126;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4400ULL: goto x86_l_1130;
	case 4405ULL: goto x86_l_1135;
	case 4409ULL: goto x86_l_1139;
	case 4411ULL: goto x86_l_113b;
	case 4415ULL: goto x86_l_113f;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4434ULL: goto x86_l_1152;
	case 4439ULL: goto x86_l_1157;
	case 4442ULL: goto x86_l_115a;
	case 4445ULL: goto x86_l_115d;
	case 4447ULL: goto x86_l_115f;
	case 4451ULL: goto x86_l_1163;
	case 4454ULL: goto x86_l_1166;
	case 4457ULL: goto x86_l_1169;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4474ULL: goto x86_l_117a;
	case 4479ULL: goto x86_l_117f;
	case 4484ULL: goto x86_l_1184;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4495ULL: goto x86_l_118f;
	case 4498ULL: goto x86_l_1192;
	case 4500ULL: goto x86_l_1194;
	case 4504ULL: goto x86_l_1198;
	case 4507ULL: goto x86_l_119b;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4524ULL: goto x86_l_11ac;
	case 4530ULL: goto x86_l_11b2;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4543ULL: goto x86_l_11bf;
	case 4549ULL: goto x86_l_11c5;
	case 4552ULL: goto x86_l_11c8;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4581ULL: goto x86_l_11e5;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4595ULL: goto x86_l_11f3;
	case 4600ULL: goto x86_l_11f8;
	case 4604ULL: goto x86_l_11fc;
	case 4608ULL: goto x86_l_1200;
	case 4612ULL: goto x86_l_1204;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4624ULL: goto x86_l_1210;
	case 4628ULL: goto x86_l_1214;
	case 4632ULL: goto x86_l_1218;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4644ULL: goto x86_l_1224;
	case 4648ULL: goto x86_l_1228;
	case 4655ULL: goto x86_l_122f;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4671ULL: goto x86_l_123f;
	case 4678ULL: goto x86_l_1246;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4690ULL: goto x86_l_1252;
	case 4694ULL: goto x86_l_1256;
	case 4701ULL: goto x86_l_125d;
	case 4706ULL: goto x86_l_1262;
	case 4711ULL: goto x86_l_1267;
	case 4713ULL: goto x86_l_1269;
	case 4717ULL: goto x86_l_126d;
	case 4724ULL: goto x86_l_1274;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4736ULL: goto x86_l_1280;
	case 4740ULL: goto x86_l_1284;
	case 4748ULL: goto x86_l_128c;
	case 4756ULL: goto x86_l_1294;
	case 4764ULL: goto x86_l_129c;
	case 4772ULL: goto x86_l_12a4;
	case 4776ULL: goto x86_l_12a8;
	case 4779ULL: goto x86_l_12ab;
	case 4785ULL: goto x86_l_12b1;
	case 4788ULL: goto x86_l_12b4;
	case 4794ULL: goto x86_l_12ba;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4840ULL: goto x86_l_12e8;
	case 4846ULL: goto x86_l_12ee;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4859ULL: goto x86_l_12fb;
	case 4865ULL: goto x86_l_1301;
	case 4868ULL: goto x86_l_1304;
	case 4873ULL: goto x86_l_1309;
	case 4881ULL: goto x86_l_1311;
	case 4889ULL: goto x86_l_1319;
	case 4897ULL: goto x86_l_1321;
	case 4905ULL: goto x86_l_1329;
	case 4913ULL: goto x86_l_1331;
	case 4921ULL: goto x86_l_1339;
	case 4929ULL: goto x86_l_1341;
	case 4937ULL: goto x86_l_1349;
	case 4945ULL: goto x86_l_1351;
	case 4952ULL: goto x86_l_1358;
	case 4956ULL: goto x86_l_135c;
	case 4961ULL: goto x86_l_1361;
	case 4965ULL: goto x86_l_1365;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4986ULL: goto x86_l_137a;
	case 4991ULL: goto x86_l_137f;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5019ULL: goto x86_l_139b;
	case 5025ULL: goto x86_l_13a1;
	case 5028ULL: goto x86_l_13a4;
	case 5033ULL: goto x86_l_13a9;
	case 5037ULL: goto x86_l_13ad;
	case 5043ULL: goto x86_l_13b3;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5056ULL: goto x86_l_13c0;
	case 5062ULL: goto x86_l_13c6;
	case 5067ULL: goto x86_l_13cb;
	case 5074ULL: goto x86_l_13d2;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5087ULL: goto x86_l_13df;
	case 5092ULL: goto x86_l_13e4;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5104ULL: goto x86_l_13f0;
	case 5107ULL: goto x86_l_13f3;
	case 5110ULL: goto x86_l_13f6;
	case 5113ULL: goto x86_l_13f9;
	case 5118ULL: goto x86_l_13fe;
	case 5122ULL: goto x86_l_1402;
	case 5128ULL: goto x86_l_1408;
	case 5132ULL: goto x86_l_140c;
	case 5137ULL: goto x86_l_1411;
	case 5141ULL: goto x86_l_1415;
	case 5147ULL: goto x86_l_141b;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5168ULL: goto x86_l_1430;
	case 5173ULL: goto x86_l_1435;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5190ULL: goto x86_l_1446;
	case 5195ULL: goto x86_l_144b;
	case 5197ULL: goto x86_l_144d;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5222ULL: goto x86_l_1466;
	case 5230ULL: goto x86_l_146e;
	case 5235ULL: goto x86_l_1473;
	case 5240ULL: goto x86_l_1478;
	case 5245ULL: goto x86_l_147d;
	case 5247ULL: goto x86_l_147f;
	case 5255ULL: goto x86_l_1487;
	case 5262ULL: goto x86_l_148e;
	case 5267ULL: goto x86_l_1493;
	case 5272ULL: goto x86_l_1498;
	case 5274ULL: goto x86_l_149a;
	case 5281ULL: goto x86_l_14a1;
	case 5288ULL: goto x86_l_14a8;
	case 5293ULL: goto x86_l_14ad;
	case 5296ULL: goto x86_l_14b0;
	case 5301ULL: goto x86_l_14b5;
	case 5304ULL: goto x86_l_14b8;
	case 5306ULL: goto x86_l_14ba;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5330ULL: goto x86_l_14d2;
	case 5335ULL: goto x86_l_14d7;
	case 5339ULL: goto x86_l_14db;
	case 5345ULL: goto x86_l_14e1;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5356ULL: goto x86_l_14ec;
	case 5361ULL: goto x86_l_14f1;
	case 5364ULL: goto x86_l_14f4;
	case 5370ULL: goto x86_l_14fa;
	case 5374ULL: goto x86_l_14fe;
	case 5376ULL: goto x86_l_1500;
	case 5381ULL: goto x86_l_1505;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e13:
	/* 0xe13: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e16:
	/* 0xe16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e18:
	/* 0xe18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e1d:
	/* 0xe1d: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e22:
	/* 0xe22: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_e25:
	/* 0xe25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e2a:
	/* 0xe2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2c:
	/* 0xe2c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e31:
	/* 0xe31: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e35:
	/* 0xe35: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_e3a:
	/* 0xe3a: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_e3f:
	/* 0xe3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e41:
	/* 0xe41: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_e44:
	/* 0xe44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e47:
	/* 0xe47: js     1937 <generic_kprobe_process_event+0x1937> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6455ULL;
	}
x86_l_e4d:
	/* 0xe4d: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_e51:
	/* 0xe51: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e54:
	/* 0xe54: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_e58:
	/* 0xe58: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_e5b:
	/* 0xe5b: jmp    1051 <generic_kprobe_process_event+0x1051> */
	goto x86_l_1051;
x86_l_e60:
	/* 0xe60: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_e64:
	/* 0xe64: jle    12e4 <generic_kprobe_process_event+0x12e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_12e4;
	}
x86_l_e6a:
	/* 0xe6a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e6d:
	/* 0xe6d: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_e72:
	/* 0xe72: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e75:
	/* 0xe75: jae    11a3 <generic_kprobe_process_event+0x11a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_11a3;
	}
x86_l_e7b:
	/* 0xe7b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e80:
	/* 0xe80: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e85:
	/* 0xe85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e8a:
	/* 0xe8a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8f:
	/* 0xe8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e91:
	/* 0xe91: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_e97:
	/* 0xe97: jmp    1cf6 <generic_kprobe_process_event+0x1cf6> */
	return 7414ULL;
x86_l_e9c:
	/* 0xe9c: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_ea0:
	/* 0xea0: je     187b <generic_kprobe_process_event+0x187b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6267ULL;
	}
x86_l_ea6:
	/* 0xea6: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_eaa:
	/* 0xeaa: je     18b4 <generic_kprobe_process_event+0x18b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6324ULL;
	}
x86_l_eb0:
	/* 0xeb0: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_eb4:
	/* 0xeb4: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eb9:
	/* 0xeb9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ebd:
	/* 0xebd: jne    1055 <generic_kprobe_process_event+0x1055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1055;
	}
x86_l_ec3:
	/* 0xec3: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_ec6:
	/* 0xec6: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ecb:
	/* 0xecb: mov    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_ed0:
	/* 0xed0: mov    QWORD PTR [r13+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_ed8:
	/* 0xed8: mov    QWORD PTR [r13+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_ee0:
	/* 0xee0: mov    QWORD PTR [r13+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_ee8:
	/* 0xee8: mov    QWORD PTR [r13+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_ef0:
	/* 0xef0: mov    QWORD PTR [r13+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_ef8:
	/* 0xef8: mov    QWORD PTR [r13+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_f00:
	/* 0xf00: mov    QWORD PTR [r13+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_f08:
	/* 0xf08: mov    QWORD PTR [r13+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_f10:
	/* 0xf10: mov    QWORD PTR [r13+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_f18:
	/* 0xf18: mov    QWORD PTR [r13+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_f20:
	/* 0xf20: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_f28:
	/* 0xf28: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f30:
	/* 0xf30: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f38:
	/* 0xf38: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f40:
	/* 0xf40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f45:
	/* 0xf45: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_f48:
	/* 0xf48: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f4d:
	/* 0xf4d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f50:
	/* 0xf50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f52:
	/* 0xf52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f55:
	/* 0xf55: js     218f <generic_kprobe_process_event+0x218f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8591ULL;
	}
x86_l_f5b:
	/* 0xf5b: lea    r12,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_f5f:
	/* 0xf5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f64:
	/* 0xf64: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f69:
	/* 0xf69: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_f6e:
	/* 0xf6e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f71:
	/* 0xf71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f73:
	/* 0xf73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f76:
	/* 0xf76: js     218f <generic_kprobe_process_event+0x218f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8591ULL;
	}
x86_l_f7c:
	/* 0xf7c: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f80:
	/* 0xf80: cmp    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_f85:
	/* 0xf85: sete   BYTE PTR [rbp+0x2] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RBP, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_f89:
	/* 0xf89: je     216f <generic_kprobe_process_event+0x216f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8559ULL;
	}
x86_l_f8f:
	/* 0xf8f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_f94:
	/* 0xf94: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_f99:
	/* 0xf99: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f9c:
	/* 0xf9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9e:
	/* 0xf9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fa0:
	/* 0xfa0: js     218f <generic_kprobe_process_event+0x218f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8591ULL;
	}
x86_l_fa6:
	/* 0xfa6: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_fa8:
	/* 0xfa8: jmp    218b <generic_kprobe_process_event+0x218b> */
	return 8587ULL;
x86_l_fad:
	/* 0xfad: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_fb1:
	/* 0xfb1: jg     13a9 <generic_kprobe_process_event+0x13a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_13a9;
	}
x86_l_fb7:
	/* 0xfb7: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_fba:
	/* 0xfba: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_fbe:
	/* 0xfbe: je     193f <generic_kprobe_process_event+0x193f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6463ULL;
	}
x86_l_fc4:
	/* 0xfc4: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fc9:
	/* 0xfc9: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_fcd:
	/* 0xfcd: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd2:
	/* 0xfd2: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fd7:
	/* 0xfd7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fdb:
	/* 0xfdb: jne    105f <generic_kprobe_process_event+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_105f;
	}
x86_l_fe1:
	/* 0xfe1: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_fe4:
	/* 0xfe4: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fe9:
	/* 0xfe9: lea    rbp,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ff0:
	/* 0xff0: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ff5:
	/* 0xff5: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_ff8:
	/* 0xff8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ffb:
	/* 0xffb: jle    2057 <generic_kprobe_process_event+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8279ULL;
	}
x86_l_1001:
	/* 0x1001: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1004:
	/* 0x1004: je     226f <generic_kprobe_process_event+0x226f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8815ULL;
	}
x86_l_100a:
	/* 0x100a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_100d:
	/* 0x100d: je     227c <generic_kprobe_process_event+0x227c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8828ULL;
	}
x86_l_1013:
	/* 0x1013: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1016:
	/* 0x1016: jne    2667 <generic_kprobe_process_event+0x2667> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9831ULL;
	}
x86_l_101c:
	/* 0x101c: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1021:
	/* 0x1021: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_1027:
	/* 0x1027: jmp    2294 <generic_kprobe_process_event+0x2294> */
	return 8852ULL;
x86_l_102c:
	/* 0x102c: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1032:
	/* 0x1032: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1037:
	/* 0x1037: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_103c:
	/* 0x103c: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_103f:
	/* 0x103f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1044:
	/* 0x1044: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1047:
	/* 0x1047: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1049:
	/* 0x1049: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_104c:
	/* 0x104c: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1051:
	/* 0x1051: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1055:
	/* 0x1055: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_105a:
	/* 0x105a: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_105f:
	/* 0x105f: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1062:
	/* 0x1062: js     1074 <generic_kprobe_process_event+0x1074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1074;
	}
x86_l_1064:
	/* 0x1064: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_106b:
	/* 0x106b: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_106f:
	/* 0x106f: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_1072:
	/* 0x1072: jmp    108f <generic_kprobe_process_event+0x108f> */
	goto x86_l_108f;
x86_l_1074:
	/* 0x1074: mov    DWORD PTR [rcx+rdx*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104045582745599ULL);
x86_l_107f:
	/* 0x107f: mov    DWORD PTR [rcx+rbp*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 622770257919ULL);
x86_l_108a:
	/* 0x108a: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_108f:
	/* 0x108f: add    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1091:
	/* 0x1091: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1093:
	/* 0x1093: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1097:
	/* 0x1097: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_109a:
	/* 0x109a: jg     1103 <generic_kprobe_process_event+0x1103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1103;
	}
x86_l_109c:
	/* 0x109c: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_10a4:
	/* 0x10a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10a9:
	/* 0x10a9: mov    rdi,QWORD PTR [rip+0x237] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_10b0:
	/* 0x10b0: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10b5:
	/* 0x10b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b7:
	/* 0x10b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10ba:
	/* 0x10ba: je     1103 <generic_kprobe_process_event+0x1103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1103;
	}
x86_l_10bc:
	/* 0x10bc: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_10c2:
	/* 0x10c2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10c7:
	/* 0x10c7: mov    rdi,QWORD PTR [rip+0x237] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_10ce:
	/* 0x10ce: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10d1:
	/* 0x10d1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10d3:
	/* 0x10d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d6:
	/* 0x10d6: je     1103 <generic_kprobe_process_event+0x1103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1103;
	}
x86_l_10d8:
	/* 0x10d8: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10da:
	/* 0x10da: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_10dc:
	/* 0x10dc: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_10df:
	/* 0x10df: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_10e4:
	/* 0x10e4: je     1103 <generic_kprobe_process_event+0x1103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1103;
	}
x86_l_10e6:
	/* 0x10e6: mov    DWORD PTR [r14+0x5efc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_10ed:
	/* 0x10ed: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_10f2:
	/* 0x10f2: mov    rsi,QWORD PTR [rip+0x237] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_10f9:
	/* 0x10f9: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_10fc:
	/* 0x10fc: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1101:
	/* 0x1101: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1103:
	/* 0x1103: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_110e:
	/* 0x110e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1113:
	/* 0x1113: mov    rsi,QWORD PTR [rip+0x237] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_111a:
	/* 0x111a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_111d:
	/* 0x111d: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1122:
	/* 0x1122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1124:
	/* 0x1124: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1126:
	/* 0x1126: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_112d:
	/* 0x112d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_112f:
	/* 0x112f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1130:
	/* 0x1130: jmp    36d9 <__do_bytes+0xb9> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1135:
	/* 0x1135: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1139:
	/* 0x1139: je     1174 <generic_kprobe_process_event+0x1174> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1174;
	}
x86_l_113b:
	/* 0x113b: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_113f:
	/* 0x113f: jne    1055 <generic_kprobe_process_event+0x1055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1055;
	}
x86_l_1145:
	/* 0x1145: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_114a:
	/* 0x114a: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_114f:
	/* 0x114f: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1152:
	/* 0x1152: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1157:
	/* 0x1157: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_115a:
	/* 0x115a: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_115d:
	/* 0x115d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115f:
	/* 0x115f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1163:
	/* 0x1163: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1166:
	/* 0x1166: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1169:
	/* 0x1169: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_116f:
	/* 0x116f: jmp    1055 <generic_kprobe_process_event+0x1055> */
	goto x86_l_1055;
x86_l_1174:
	/* 0x1174: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_117a:
	/* 0x117a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_117f:
	/* 0x117f: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1184:
	/* 0x1184: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1187:
	/* 0x1187: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_118c:
	/* 0x118c: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_118f:
	/* 0x118f: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1192:
	/* 0x1192: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1194:
	/* 0x1194: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1198:
	/* 0x1198: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_119b:
	/* 0x119b: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_119e:
	/* 0x119e: jmp    1055 <generic_kprobe_process_event+0x1055> */
	goto x86_l_1055;
x86_l_11a3:
	/* 0x11a3: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11a8:
	/* 0x11a8: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_11ac:
	/* 0x11ac: je     1c76 <generic_kprobe_process_event+0x1c76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7286ULL;
	}
x86_l_11b2:
	/* 0x11b2: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_11b6:
	/* 0x11b6: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11bb:
	/* 0x11bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11bf:
	/* 0x11bf: jne    105f <generic_kprobe_process_event+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_105f;
	}
x86_l_11c5:
	/* 0x11c5: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_11c8:
	/* 0x11c8: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_11cb:
	/* 0x11cb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d0:
	/* 0x11d0: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_11d4:
	/* 0x11d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11d9:
	/* 0x11d9: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11de:
	/* 0x11de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11e3:
	/* 0x11e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e5:
	/* 0x11e5: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11ea:
	/* 0x11ea: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_11ed:
	/* 0x11ed: je     2223 <generic_kprobe_process_event+0x2223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8739ULL;
	}
x86_l_11f3:
	/* 0x11f3: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11f8:
	/* 0x11f8: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11fc:
	/* 0x11fc: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1200:
	/* 0x1200: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1204:
	/* 0x1204: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1209:
	/* 0x1209: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_120e:
	/* 0x120e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1210:
	/* 0x1210: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1214:
	/* 0x1214: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1218:
	/* 0x1218: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_121d:
	/* 0x121d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1222:
	/* 0x1222: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1224:
	/* 0x1224: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1228:
	/* 0x1228: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_122f:
	/* 0x122f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1234:
	/* 0x1234: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1239:
	/* 0x1239: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123b:
	/* 0x123b: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_123f:
	/* 0x123f: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1246:
	/* 0x1246: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_124b:
	/* 0x124b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1250:
	/* 0x1250: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1252:
	/* 0x1252: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1256:
	/* 0x1256: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_125d:
	/* 0x125d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1262:
	/* 0x1262: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1267:
	/* 0x1267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1269:
	/* 0x1269: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_126d:
	/* 0x126d: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1274:
	/* 0x1274: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1279:
	/* 0x1279: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_127e:
	/* 0x127e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1280:
	/* 0x1280: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1284:
	/* 0x1284: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_128c:
	/* 0x128c: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1294:
	/* 0x1294: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_129c:
	/* 0x129c: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_12a4:
	/* 0x12a4: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_12a8:
	/* 0x12a8: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_12ab:
	/* 0x12ab: je     21be <generic_kprobe_process_event+0x21be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8638ULL;
	}
x86_l_12b1:
	/* 0x12b1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12b4:
	/* 0x12b4: jne    21e6 <generic_kprobe_process_event+0x21e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8678ULL;
	}
x86_l_12ba:
	/* 0x12ba: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12be:
	/* 0x12be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12c3:
	/* 0x12c3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12c8:
	/* 0x12c8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12cd:
	/* 0x12cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cf:
	/* 0x12cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12d4:
	/* 0x12d4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_12d7:
	/* 0x12d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12dc:
	/* 0x12dc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_12df:
	/* 0x12df: jmp    21e4 <generic_kprobe_process_event+0x21e4> */
	return 8676ULL;
x86_l_12e4:
	/* 0x12e4: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_12e8:
	/* 0x12e8: je     1d00 <generic_kprobe_process_event+0x1d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7424ULL;
	}
x86_l_12ee:
	/* 0x12ee: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_12f2:
	/* 0x12f2: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12f7:
	/* 0x12f7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12fb:
	/* 0x12fb: jne    105f <generic_kprobe_process_event+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_105f;
	}
x86_l_1301:
	/* 0x1301: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1304:
	/* 0x1304: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1309:
	/* 0x1309: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1311:
	/* 0x1311: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1319:
	/* 0x1319: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1321:
	/* 0x1321: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1329:
	/* 0x1329: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1331:
	/* 0x1331: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1339:
	/* 0x1339: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1341:
	/* 0x1341: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1349:
	/* 0x1349: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1351:
	/* 0x1351: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1358:
	/* 0x1358: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_135c:
	/* 0x135c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1361:
	/* 0x1361: lea    rdx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1365:
	/* 0x1365: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_136a:
	/* 0x136a: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_136f:
	/* 0x136f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1371:
	/* 0x1371: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1374:
	/* 0x1374: js     2164 <generic_kprobe_process_event+0x2164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8548ULL;
	}
x86_l_137a:
	/* 0x137a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_137f:
	/* 0x137f: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1383:
	/* 0x1383: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1388:
	/* 0x1388: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_138f:
	/* 0x138f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1394:
	/* 0x1394: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1399:
	/* 0x1399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139b:
	/* 0x139b: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_13a1:
	/* 0x13a1: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_13a4:
	/* 0x13a4: jmp    c01 <generic_kprobe_process_event+0xc01> */
	return 3073ULL;
x86_l_13a9:
	/* 0x13a9: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_13ad:
	/* 0x13ad: je     19ad <generic_kprobe_process_event+0x19ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6573ULL;
	}
x86_l_13b3:
	/* 0x13b3: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_13b7:
	/* 0x13b7: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13bc:
	/* 0x13bc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c0:
	/* 0x13c0: jne    105f <generic_kprobe_process_event+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_105f;
	}
x86_l_13c6:
	/* 0x13c6: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13cb:
	/* 0x13cb: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_13d2:
	/* 0x13d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13d7:
	/* 0x13d7: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13dc:
	/* 0x13dc: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_13df:
	/* 0x13df: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e4:
	/* 0x13e4: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_13e7:
	/* 0x13e7: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ec:
	/* 0x13ec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f0:
	/* 0x13f0: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_13f3:
	/* 0x13f3: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_13f6:
	/* 0x13f6: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_13f9:
	/* 0x13f9: jmp    105f <generic_kprobe_process_event+0x105f> */
	goto x86_l_105f;
x86_l_13fe:
	/* 0x13fe: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_1402:
	/* 0x1402: je     1c2b <generic_kprobe_process_event+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7211ULL;
	}
x86_l_1408:
	/* 0x1408: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_140c:
	/* 0x140c: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1411:
	/* 0x1411: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1415:
	/* 0x1415: jne    105f <generic_kprobe_process_event+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_105f;
	}
x86_l_141b:
	/* 0x141b: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1424:
	/* 0x1424: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1429:
	/* 0x1429: lea    rax,[r15+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1430:
	/* 0x1430: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1435:
	/* 0x1435: lea    rdx,[r15+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_143c:
	/* 0x143c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1441:
	/* 0x1441: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1446:
	/* 0x1446: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_144b:
	/* 0x144b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144d:
	/* 0x144d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1452:
	/* 0x1452: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1457:
	/* 0x1457: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_145c:
	/* 0x145c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_145f:
	/* 0x145f: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1464:
	/* 0x1464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1466:
	/* 0x1466: lea    rdi,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_146e:
	/* 0x146e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1473:
	/* 0x1473: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1478:
	/* 0x1478: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_147d:
	/* 0x147d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147f:
	/* 0x147f: lea    rdi,[r12+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1487:
	/* 0x1487: lea    rdx,[r15+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_148e:
	/* 0x148e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1493:
	/* 0x1493: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1498:
	/* 0x1498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149a:
	/* 0x149a: add    r12,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_14a1:
	/* 0x14a1: add    r15,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_14a8:
	/* 0x14a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ad:
	/* 0x14ad: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_14b0:
	/* 0x14b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14b5:
	/* 0x14b5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14b8:
	/* 0x14b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ba:
	/* 0x14ba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14be:
	/* 0x14be: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14c3:
	/* 0x14c3: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_14c9:
	/* 0x14c9: jmp    105f <generic_kprobe_process_event+0x105f> */
	goto x86_l_105f;
x86_l_14ce:
	/* 0x14ce: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_14d2:
	/* 0x14d2: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14d7:
	/* 0x14d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14db:
	/* 0x14db: jne    1055 <generic_kprobe_process_event+0x1055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1055;
	}
x86_l_14e1:
	/* 0x14e1: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_14e4:
	/* 0x14e4: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14e9:
	/* 0x14e9: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_14ec:
	/* 0x14ec: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_14f1:
	/* 0x14f1: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_14f4:
	/* 0x14f4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14fa:
	/* 0x14fa: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14fe:
	/* 0x14fe: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1500:
	/* 0x1500: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1505:
	/* 0x1505: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 5383ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5383ULL: goto x86_l_1507;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5395ULL: goto x86_l_1513;
	case 5399ULL: goto x86_l_1517;
	case 5402ULL: goto x86_l_151a;
	case 5406ULL: goto x86_l_151e;
	case 5409ULL: goto x86_l_1521;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5426ULL: goto x86_l_1532;
	case 5431ULL: goto x86_l_1537;
	case 5433ULL: goto x86_l_1539;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5447ULL: goto x86_l_1547;
	case 5455ULL: goto x86_l_154f;
	case 5460ULL: goto x86_l_1554;
	case 5465ULL: goto x86_l_1559;
	case 5467ULL: goto x86_l_155b;
	case 5474ULL: goto x86_l_1562;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5497ULL: goto x86_l_1579;
	case 5500ULL: goto x86_l_157c;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5514ULL: goto x86_l_158a;
	case 5522ULL: goto x86_l_1592;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5533ULL: goto x86_l_159d;
	case 5535ULL: goto x86_l_159f;
	case 5542ULL: goto x86_l_15a6;
	case 5546ULL: goto x86_l_15aa;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5558ULL: goto x86_l_15b6;
	case 5560ULL: goto x86_l_15b8;
	case 5564ULL: goto x86_l_15bc;
	case 5568ULL: goto x86_l_15c0;
	case 5572ULL: goto x86_l_15c4;
	case 5576ULL: goto x86_l_15c8;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5588ULL: goto x86_l_15d4;
	case 5592ULL: goto x86_l_15d8;
	case 5597ULL: goto x86_l_15dd;
	case 5600ULL: goto x86_l_15e0;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5636ULL: goto x86_l_1604;
	case 5638ULL: goto x86_l_1606;
	case 5644ULL: goto x86_l_160c;
	case 5647ULL: goto x86_l_160f;
	case 5653ULL: goto x86_l_1615;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5675ULL: goto x86_l_162b;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5695ULL: goto x86_l_163f;
	case 5700ULL: goto x86_l_1644;
	case 5702ULL: goto x86_l_1646;
	case 5707ULL: goto x86_l_164b;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5736ULL: goto x86_l_1668;
	case 5741ULL: goto x86_l_166d;
	case 5749ULL: goto x86_l_1675;
	case 5753ULL: goto x86_l_1679;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5777ULL: goto x86_l_1691;
	case 5784ULL: goto x86_l_1698;
	case 5790ULL: goto x86_l_169e;
	case 5793ULL: goto x86_l_16a1;
	case 5800ULL: goto x86_l_16a8;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5817ULL: goto x86_l_16b9;
	case 5824ULL: goto x86_l_16c0;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5837ULL: goto x86_l_16cd;
	case 5844ULL: goto x86_l_16d4;
	case 5849ULL: goto x86_l_16d9;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5864ULL: goto x86_l_16e8;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5879ULL: goto x86_l_16f7;
	case 5883ULL: goto x86_l_16fb;
	case 5891ULL: goto x86_l_1703;
	case 5896ULL: goto x86_l_1708;
	case 5901ULL: goto x86_l_170d;
	case 5903ULL: goto x86_l_170f;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5917ULL: goto x86_l_171d;
	case 5922ULL: goto x86_l_1722;
	case 5924ULL: goto x86_l_1724;
	case 5928ULL: goto x86_l_1728;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5948ULL: goto x86_l_173c;
	case 5953ULL: goto x86_l_1741;
	case 5957ULL: goto x86_l_1745;
	case 5965ULL: goto x86_l_174d;
	case 5970ULL: goto x86_l_1752;
	case 5975ULL: goto x86_l_1757;
	case 5977ULL: goto x86_l_1759;
	case 5986ULL: goto x86_l_1762;
	case 5994ULL: goto x86_l_176a;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6009ULL: goto x86_l_1779;
	case 6011ULL: goto x86_l_177b;
	case 6019ULL: goto x86_l_1783;
	case 6024ULL: goto x86_l_1788;
	case 6032ULL: goto x86_l_1790;
	case 6037ULL: goto x86_l_1795;
	case 6039ULL: goto x86_l_1797;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6074ULL: goto x86_l_17ba;
	case 6076ULL: goto x86_l_17bc;
	case 6084ULL: goto x86_l_17c4;
	case 6087ULL: goto x86_l_17c7;
	case 6090ULL: goto x86_l_17ca;
	case 6096ULL: goto x86_l_17d0;
	case 6099ULL: goto x86_l_17d3;
	case 6105ULL: goto x86_l_17d9;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6122ULL: goto x86_l_17ea;
	case 6127ULL: goto x86_l_17ef;
	case 6129ULL: goto x86_l_17f1;
	case 6137ULL: goto x86_l_17f9;
	case 6142ULL: goto x86_l_17fe;
	case 6146ULL: goto x86_l_1802;
	case 6152ULL: goto x86_l_1808;
	case 6156ULL: goto x86_l_180c;
	case 6160ULL: goto x86_l_1810;
	case 6167ULL: goto x86_l_1817;
	case 6175ULL: goto x86_l_181f;
	case 6183ULL: goto x86_l_1827;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6201ULL: goto x86_l_1839;
	case 6203ULL: goto x86_l_183b;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6215ULL: goto x86_l_1847;
	case 6220ULL: goto x86_l_184c;
	case 6223ULL: goto x86_l_184f;
	case 6225ULL: goto x86_l_1851;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6253ULL: goto x86_l_186d;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6294ULL: goto x86_l_1896;
	case 6296ULL: goto x86_l_1898;
	case 6299ULL: goto x86_l_189b;
	case 6302ULL: goto x86_l_189e;
	case 6308ULL: goto x86_l_18a4;
	case 6312ULL: goto x86_l_18a8;
	case 6315ULL: goto x86_l_18ab;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6340ULL: goto x86_l_18c4;
	case 6348ULL: goto x86_l_18cc;
	case 6356ULL: goto x86_l_18d4;
	case 6361ULL: goto x86_l_18d9;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6377ULL: goto x86_l_18e9;
	case 6383ULL: goto x86_l_18ef;
	case 6386ULL: goto x86_l_18f2;
	case 6390ULL: goto x86_l_18f6;
	case 6393ULL: goto x86_l_18f9;
	case 6399ULL: goto x86_l_18ff;
	case 6402ULL: goto x86_l_1902;
	case 6408ULL: goto x86_l_1908;
	case 6412ULL: goto x86_l_190c;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6427ULL: goto x86_l_191b;
	case 6429ULL: goto x86_l_191d;
	case 6433ULL: goto x86_l_1921;
	case 6437ULL: goto x86_l_1925;
	case 6441ULL: goto x86_l_1929;
	case 6445ULL: goto x86_l_192d;
	case 6450ULL: goto x86_l_1932;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6471ULL: goto x86_l_1947;
	case 6474ULL: goto x86_l_194a;
	case 6478ULL: goto x86_l_194e;
	case 6485ULL: goto x86_l_1955;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6508ULL: goto x86_l_196c;
	case 6513ULL: goto x86_l_1971;
	case 6516ULL: goto x86_l_1974;
	case 6519ULL: goto x86_l_1977;
	case 6521ULL: goto x86_l_1979;
	case 6524ULL: goto x86_l_197c;
	case 6527ULL: goto x86_l_197f;
	case 6533ULL: goto x86_l_1985;
	case 6536ULL: goto x86_l_1988;
	case 6542ULL: goto x86_l_198e;
	case 6545ULL: goto x86_l_1991;
	case 6551ULL: goto x86_l_1997;
	case 6554ULL: goto x86_l_199a;
	case 6560ULL: goto x86_l_19a0;
	case 6568ULL: goto x86_l_19a8;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6582ULL: goto x86_l_19b6;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6605ULL: goto x86_l_19cd;
	case 6610ULL: goto x86_l_19d2;
	case 6612ULL: goto x86_l_19d4;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6631ULL: goto x86_l_19e7;
	case 6633ULL: goto x86_l_19e9;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6652ULL: goto x86_l_19fc;
	case 6654ULL: goto x86_l_19fe;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6668ULL: goto x86_l_1a0c;
	case 6673ULL: goto x86_l_1a11;
	case 6675ULL: goto x86_l_1a13;
	case 6679ULL: goto x86_l_1a17;
	case 6684ULL: goto x86_l_1a1c;
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6696ULL: goto x86_l_1a28;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6717ULL: goto x86_l_1a3d;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6738ULL: goto x86_l_1a52;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6759ULL: goto x86_l_1a67;
	case 6767ULL: goto x86_l_1a6f;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6815ULL: goto x86_l_1a9f;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6842ULL: goto x86_l_1aba;
	case 6847ULL: goto x86_l_1abf;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6865ULL: goto x86_l_1ad1;
	case 6870ULL: goto x86_l_1ad6;
	case 6872ULL: goto x86_l_1ad8;
	case 6876ULL: goto x86_l_1adc;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6894ULL: goto x86_l_1aee;
	case 6896ULL: goto x86_l_1af0;
	case 6900ULL: goto x86_l_1af4;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6918ULL: goto x86_l_1b06;
	case 6920ULL: goto x86_l_1b08;
	case 6924ULL: goto x86_l_1b0c;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6949ULL: goto x86_l_1b25;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6997ULL: goto x86_l_1b55;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7017ULL: goto x86_l_1b69;
	case 7021ULL: goto x86_l_1b6d;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7041ULL: goto x86_l_1b81;
	case 7045ULL: goto x86_l_1b85;
	case 7052ULL: goto x86_l_1b8c;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7065ULL: goto x86_l_1b99;
	case 7068ULL: goto x86_l_1b9c;
	case 7070ULL: goto x86_l_1b9e;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7086ULL: goto x86_l_1bae;
	case 7091ULL: goto x86_l_1bb3;
	case 7096ULL: goto x86_l_1bb8;
	case 7101ULL: goto x86_l_1bbd;
	case 7104ULL: goto x86_l_1bc0;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7130ULL: goto x86_l_1bda;
	case 7132ULL: goto x86_l_1bdc;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7153ULL: goto x86_l_1bf1;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1507:
	/* 0x1507: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_150a:
	/* 0x150a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_150d:
	/* 0x150d: js     1d8a <generic_kprobe_process_event+0x1d8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7562ULL;
	}
x86_l_1513:
	/* 0x1513: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1517:
	/* 0x1517: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151a:
	/* 0x151a: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_151e:
	/* 0x151e: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1521:
	/* 0x1521: jmp    1051 <generic_kprobe_process_event+0x1051> */
	return 4177ULL;
x86_l_1526:
	/* 0x1526: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1529:
	/* 0x1529: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1532:
	/* 0x1532: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1537:
	/* 0x1537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1539:
	/* 0x1539: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_153d:
	/* 0x153d: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1542:
	/* 0x1542: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1547:
	/* 0x1547: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_154f:
	/* 0x154f: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1554:
	/* 0x1554: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1559:
	/* 0x1559: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155b:
	/* 0x155b: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1562:
	/* 0x1562: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1566:
	/* 0x1566: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_156b:
	/* 0x156b: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1572:
	/* 0x1572: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1577:
	/* 0x1577: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1579:
	/* 0x1579: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_157c:
	/* 0x157c: je     1d7b <generic_kprobe_process_event+0x1d7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7547ULL;
	}
x86_l_1582:
	/* 0x1582: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1585:
	/* 0x1585: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_158a:
	/* 0x158a: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1592:
	/* 0x1592: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1595:
	/* 0x1595: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_159a:
	/* 0x159a: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_159d:
	/* 0x159d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_159f:
	/* 0x159f: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15a6:
	/* 0x15a6: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15aa:
	/* 0x15aa: lea    esi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15ae:
	/* 0x15ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15b3:
	/* 0x15b3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15b6:
	/* 0x15b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b8:
	/* 0x15b8: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_15bc:
	/* 0x15bc: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_15c0:
	/* 0x15c0: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_15c4:
	/* 0x15c4: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_15c8:
	/* 0x15c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15cd:
	/* 0x15cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15d2:
	/* 0x15d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d4:
	/* 0x15d4: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_15d8:
	/* 0x15d8: jmp    1d82 <generic_kprobe_process_event+0x1d82> */
	return 7554ULL;
x86_l_15dd:
	/* 0x15dd: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_15e0:
	/* 0x15e0: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15e5:
	/* 0x15e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15ea:
	/* 0x15ea: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_15f2:
	/* 0x15f2: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_15f7:
	/* 0x15f7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15fa:
	/* 0x15fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15fc:
	/* 0x15fc: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_1604:
	/* 0x1604: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1606:
	/* 0x1606: je     1d92 <generic_kprobe_process_event+0x1d92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7570ULL;
	}
x86_l_160c:
	/* 0x160c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_160f:
	/* 0x160f: jne    1f85 <generic_kprobe_process_event+0x1f85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8069ULL;
	}
x86_l_1615:
	/* 0x1615: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1619:
	/* 0x1619: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_161e:
	/* 0x161e: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1623:
	/* 0x1623: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1628:
	/* 0x1628: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_162b:
	/* 0x162b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162d:
	/* 0x162d: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1632:
	/* 0x1632: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1637:
	/* 0x1637: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_163f:
	/* 0x163f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1644:
	/* 0x1644: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1646:
	/* 0x1646: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_164b:
	/* 0x164b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_164f:
	/* 0x164f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1654:
	/* 0x1654: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1659:
	/* 0x1659: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_165e:
	/* 0x165e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1660:
	/* 0x1660: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1668:
	/* 0x1668: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_166d:
	/* 0x166d: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1675:
	/* 0x1675: lea    r12,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1679:
	/* 0x1679: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1680:
	/* 0x1680: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1685:
	/* 0x1685: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_168a:
	/* 0x168a: test   BYTE PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_168f:
	/* 0x168f: je     16cd <generic_kprobe_process_event+0x16cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16cd;
	}
x86_l_1691:
	/* 0x1691: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_1698:
	/* 0x1698: jae    1e04 <generic_kprobe_process_event+0x1e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7684ULL;
	}
x86_l_169e:
	/* 0x169e: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_16a1:
	/* 0x16a1: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_16a8:
	/* 0x16a8: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b0:
	/* 0x16b0: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16b5:
	/* 0x16b5: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16b9:
	/* 0x16b9: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_16c0:
	/* 0x16c0: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16c3:
	/* 0x16c3: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_16c8:
	/* 0x16c8: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16cd:
	/* 0x16cd: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_16d4:
	/* 0x16d4: mov    ebp,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4095ULL);
x86_l_16d9:
	/* 0x16d9: cmovb  rbp,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_16dd:
	/* 0x16dd: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e2:
	/* 0x16e2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_16e8:
	/* 0x16e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16ed:
	/* 0x16ed: jmp    2793 <generic_kprobe_process_event+0x2793> */
	return 10131ULL;
x86_l_16f2:
	/* 0x16f2: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16f7:
	/* 0x16f7: lea    rdi,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16fb:
	/* 0x16fb: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1703:
	/* 0x1703: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1708:
	/* 0x1708: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_170d:
	/* 0x170d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170f:
	/* 0x170f: lea    rdi,[rbp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1713:
	/* 0x1713: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1718:
	/* 0x1718: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_171d:
	/* 0x171d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1722:
	/* 0x1722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1724:
	/* 0x1724: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1728:
	/* 0x1728: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1730:
	/* 0x1730: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1735:
	/* 0x1735: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_173a:
	/* 0x173a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173c:
	/* 0x173c: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1741:
	/* 0x1741: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1745:
	/* 0x1745: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_174d:
	/* 0x174d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1752:
	/* 0x1752: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1757:
	/* 0x1757: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1759:
	/* 0x1759: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1762:
	/* 0x1762: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_176a:
	/* 0x176a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_176f:
	/* 0x176f: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1774:
	/* 0x1774: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1779:
	/* 0x1779: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177b:
	/* 0x177b: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1783:
	/* 0x1783: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1788:
	/* 0x1788: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1790:
	/* 0x1790: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1795:
	/* 0x1795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1797:
	/* 0x1797: movzx  r15d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_17a0:
	/* 0x17a0: add    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_17a5:
	/* 0x17a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17aa:
	/* 0x17aa: lea    rdi,[rsp+0xa7] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 167ULL);
x86_l_17b2:
	/* 0x17b2: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_17b7:
	/* 0x17b7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_17ba:
	/* 0x17ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bc:
	/* 0x17bc: movzx  eax,BYTE PTR [rsp+0xa7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 167ULL);
x86_l_17c4:
	/* 0x17c4: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_17c7:
	/* 0x17c7: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_17ca:
	/* 0x17ca: je     1e31 <generic_kprobe_process_event+0x1e31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7729ULL;
	}
x86_l_17d0:
	/* 0x17d0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d3:
	/* 0x17d3: jne    2fac <generic_kprobe_process_event+0x2fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12204ULL;
	}
x86_l_17d9:
	/* 0x17d9: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_17dd:
	/* 0x17dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17e2:
	/* 0x17e2: lea    rdi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_17ea:
	/* 0x17ea: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_17ef:
	/* 0x17ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f1:
	/* 0x17f1: movzx  eax,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_17f9:
	/* 0x17f9: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17fe:
	/* 0x17fe: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1802:
	/* 0x1802: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_1808:
	/* 0x1808: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180c:
	/* 0x180c: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1810:
	/* 0x1810: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1817:
	/* 0x1817: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_181f:
	/* 0x181f: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1827:
	/* 0x1827: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_182f:
	/* 0x182f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1834:
	/* 0x1834: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1839:
	/* 0x1839: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183b:
	/* 0x183b: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_183f:
	/* 0x183f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1844:
	/* 0x1844: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1847:
	/* 0x1847: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_184c:
	/* 0x184c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_184f:
	/* 0x184f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1851:
	/* 0x1851: lea    rdx,[r12+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1859:
	/* 0x1859: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_185e:
	/* 0x185e: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1866:
	/* 0x1866: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_186b:
	/* 0x186b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186d:
	/* 0x186d: movzx  r15d,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_1876:
	/* 0x1876: jmp    2e75 <generic_kprobe_process_event+0x2e75> */
	return 11893ULL;
x86_l_187b:
	/* 0x187b: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_187e:
	/* 0x187e: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1883:
	/* 0x1883: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1888:
	/* 0x1888: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_188c:
	/* 0x188c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1891:
	/* 0x1891: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1896:
	/* 0x1896: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1898:
	/* 0x1898: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_189b:
	/* 0x189b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_189e:
	/* 0x189e: js     1049 <generic_kprobe_process_event+0x1049> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4169ULL;
	}
x86_l_18a4:
	/* 0x18a4: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_18a8:
	/* 0x18a8: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ab:
	/* 0x18ab: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_18af:
	/* 0x18af: jmp    1049 <generic_kprobe_process_event+0x1049> */
	return 4169ULL;
x86_l_18b4:
	/* 0x18b4: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_18b7:
	/* 0x18b7: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18bc:
	/* 0x18bc: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18c4:
	/* 0x18c4: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_18cc:
	/* 0x18cc: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d4:
	/* 0x18d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d9:
	/* 0x18d9: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_18dc:
	/* 0x18dc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_18e1:
	/* 0x18e1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18e4:
	/* 0x18e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e6:
	/* 0x18e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18e9:
	/* 0x18e9: js     20b1 <generic_kprobe_process_event+0x20b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8369ULL;
	}
x86_l_18ef:
	/* 0x18ef: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_18f2:
	/* 0x18f2: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18f6:
	/* 0x18f6: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_18f9:
	/* 0x18f9: je     2079 <generic_kprobe_process_event+0x2079> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8313ULL;
	}
x86_l_18ff:
	/* 0x18ff: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1902:
	/* 0x1902: jne    20a7 <generic_kprobe_process_event+0x20a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8359ULL;
	}
x86_l_1908:
	/* 0x1908: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_190c:
	/* 0x190c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1911:
	/* 0x1911: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1916:
	/* 0x1916: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_191b:
	/* 0x191b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191d:
	/* 0x191d: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1921:
	/* 0x1921: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1925:
	/* 0x1925: lea    rdi,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1929:
	/* 0x1929: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_192d:
	/* 0x192d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1932:
	/* 0x1932: jmp    209d <generic_kprobe_process_event+0x209d> */
	return 8349ULL;
x86_l_1937:
	/* 0x1937: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_193a:
	/* 0x193a: jmp    1051 <generic_kprobe_process_event+0x1051> */
	return 4177ULL;
x86_l_193f:
	/* 0x193f: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1947:
	/* 0x1947: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_194a:
	/* 0x194a: lea    rbx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_194e:
	/* 0x194e: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1955:
	/* 0x1955: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_1961:
	/* 0x1961: test   BYTE PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691856ULL);
x86_l_1966:
	/* 0x1966: jne    1fa9 <generic_kprobe_process_event+0x1fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8105ULL;
	}
x86_l_196c:
	/* 0x196c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1971:
	/* 0x1971: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_1974:
	/* 0x1974: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1977:
	/* 0x1977: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1979:
	/* 0x1979: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_197c:
	/* 0x197c: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_197f:
	/* 0x197f: jle    219f <generic_kprobe_process_event+0x219f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8607ULL;
	}
x86_l_1985:
	/* 0x1985: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1988:
	/* 0x1988: je     2887 <generic_kprobe_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10375ULL;
	}
x86_l_198e:
	/* 0x198e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1991:
	/* 0x1991: je     2891 <generic_kprobe_process_event+0x2891> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10385ULL;
	}
x86_l_1997:
	/* 0x1997: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_199a:
	/* 0x199a: jne    28a6 <generic_kprobe_process_event+0x28a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10406ULL;
	}
x86_l_19a0:
	/* 0x19a0: lea    rax,[r12+0x5e70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_19a8:
	/* 0x19a8: jmp    28a3 <generic_kprobe_process_event+0x28a3> */
	return 10403ULL;
x86_l_19ad:
	/* 0x19ad: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19b2:
	/* 0x19b2: lea    rax,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19b6:
	/* 0x19b6: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19bb:
	/* 0x19bb: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c0:
	/* 0x19c0: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c5:
	/* 0x19c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19ca:
	/* 0x19ca: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19cd:
	/* 0x19cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19d2:
	/* 0x19d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d4:
	/* 0x19d4: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19d8:
	/* 0x19d8: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19dd:
	/* 0x19dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e2:
	/* 0x19e2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19e7:
	/* 0x19e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e9:
	/* 0x19e9: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ed:
	/* 0x19ed: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19f2:
	/* 0x19f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f7:
	/* 0x19f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19fc:
	/* 0x19fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fe:
	/* 0x19fe: lea    rdi,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a02:
	/* 0x1a02: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a07:
	/* 0x1a07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a11:
	/* 0x1a11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a13:
	/* 0x1a13: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a17:
	/* 0x1a17: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a1c:
	/* 0x1a1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a21:
	/* 0x1a21: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a26:
	/* 0x1a26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a28:
	/* 0x1a28: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a2c:
	/* 0x1a2c: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a31:
	/* 0x1a31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a36:
	/* 0x1a36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a3b:
	/* 0x1a3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3d:
	/* 0x1a3d: lea    rdi,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a41:
	/* 0x1a41: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a46:
	/* 0x1a46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a50:
	/* 0x1a50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a52:
	/* 0x1a52: lea    rdi,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a56:
	/* 0x1a56: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a60:
	/* 0x1a60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a65:
	/* 0x1a65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a67:
	/* 0x1a67: mov    DWORD PTR [r15+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1a6f:
	/* 0x1a6f: lea    rdi,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a73:
	/* 0x1a73: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a78:
	/* 0x1a78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a82:
	/* 0x1a82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a84:
	/* 0x1a84: mov    rax,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a89:
	/* 0x1a89: mov    QWORD PTR [r15+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    rax,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a92:
	/* 0x1a92: mov    QWORD PTR [r15+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a96:
	/* 0x1a96: mov    rax,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    QWORD PTR [r15+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a9f:
	/* 0x1a9f: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aab:
	/* 0x1aab: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ab8:
	/* 0x1ab8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aba:
	/* 0x1aba: mov    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1abf:
	/* 0x1abf: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1acc:
	/* 0x1acc: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ad1:
	/* 0x1ad1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ad6:
	/* 0x1ad6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad8:
	/* 0x1ad8: lea    rdi,[r15+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1adc:
	/* 0x1adc: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae9:
	/* 0x1ae9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aee:
	/* 0x1aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af0:
	/* 0x1af0: lea    rdi,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1af4:
	/* 0x1af4: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1afc:
	/* 0x1afc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b01:
	/* 0x1b01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b06:
	/* 0x1b06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b08:
	/* 0x1b08: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1b0c:
	/* 0x1b0c: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1b13:
	/* 0x1b13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b18:
	/* 0x1b18: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1b1b:
	/* 0x1b1b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b20:
	/* 0x1b20: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b23:
	/* 0x1b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b25:
	/* 0x1b25: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1b2b:
	/* 0x1b2b: jmp    1cf6 <generic_kprobe_process_event+0x1cf6> */
	return 7414ULL;
x86_l_1b30:
	/* 0x1b30: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b35:
	/* 0x1b35: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b42:
	/* 0x1b42: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x1b55: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b62:
	/* 0x1b62: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b67:
	/* 0x1b67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b69:
	/* 0x1b69: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b6d:
	/* 0x1b6d: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1b75:
	/* 0x1b75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b7f:
	/* 0x1b7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b81:
	/* 0x1b81: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1b85:
	/* 0x1b85: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1b8c:
	/* 0x1b8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b91:
	/* 0x1b91: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1b94:
	/* 0x1b94: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b99:
	/* 0x1b99: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b9c:
	/* 0x1b9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9e:
	/* 0x1b9e: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1ba4:
	/* 0x1ba4: jmp    1cf6 <generic_kprobe_process_event+0x1cf6> */
	return 7414ULL;
x86_l_1ba9:
	/* 0x1ba9: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bae:
	/* 0x1bae: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bb3:
	/* 0x1bb3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bb8:
	/* 0x1bb8: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bbd:
	/* 0x1bbd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1bc0:
	/* 0x1bc0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bc5:
	/* 0x1bc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc7:
	/* 0x1bc7: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bcb:
	/* 0x1bcb: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bd5:
	/* 0x1bd5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bda:
	/* 0x1bda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bdc:
	/* 0x1bdc: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1be0:
	/* 0x1be0: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1be5:
	/* 0x1be5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bea:
	/* 0x1bea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bef:
	/* 0x1bef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf1:
	/* 0x1bf1: lea    rdi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bf5:
	/* 0x1bf5: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bff:
	/* 0x1bff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c04:
	/* 0x1c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 7174ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7174ULL: goto x86_l_1c06;
	case 7178ULL: goto x86_l_1c0a;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7190ULL: goto x86_l_1c16;
	case 7195ULL: goto x86_l_1c1b;
	case 7198ULL: goto x86_l_1c1e;
	case 7200ULL: goto x86_l_1c20;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7224ULL: goto x86_l_1c38;
	case 7229ULL: goto x86_l_1c3d;
	case 7234ULL: goto x86_l_1c42;
	case 7237ULL: goto x86_l_1c45;
	case 7239ULL: goto x86_l_1c47;
	case 7243ULL: goto x86_l_1c4b;
	case 7248ULL: goto x86_l_1c50;
	case 7253ULL: goto x86_l_1c55;
	case 7258ULL: goto x86_l_1c5a;
	case 7260ULL: goto x86_l_1c5c;
	case 7264ULL: goto x86_l_1c60;
	case 7268ULL: goto x86_l_1c64;
	case 7273ULL: goto x86_l_1c69;
	case 7276ULL: goto x86_l_1c6c;
	case 7281ULL: goto x86_l_1c71;
	case 7284ULL: goto x86_l_1c74;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7301ULL: goto x86_l_1c85;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	case 7313ULL: goto x86_l_1c91;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7330ULL: goto x86_l_1ca2;
	case 7335ULL: goto x86_l_1ca7;
	case 7340ULL: goto x86_l_1cac;
	case 7345ULL: goto x86_l_1cb1;
	case 7347ULL: goto x86_l_1cb3;
	case 7351ULL: goto x86_l_1cb7;
	case 7355ULL: goto x86_l_1cbb;
	case 7359ULL: goto x86_l_1cbf;
	case 7364ULL: goto x86_l_1cc4;
	case 7369ULL: goto x86_l_1cc9;
	case 7374ULL: goto x86_l_1cce;
	case 7377ULL: goto x86_l_1cd1;
	case 7379ULL: goto x86_l_1cd3;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7401ULL: goto x86_l_1ce9;
	case 7406ULL: goto x86_l_1cee;
	case 7408ULL: goto x86_l_1cf0;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7429ULL: goto x86_l_1d05;
	case 7437ULL: goto x86_l_1d0d;
	case 7445ULL: goto x86_l_1d15;
	case 7453ULL: goto x86_l_1d1d;
	case 7461ULL: goto x86_l_1d25;
	case 7469ULL: goto x86_l_1d2d;
	case 7477ULL: goto x86_l_1d35;
	case 7485ULL: goto x86_l_1d3d;
	case 7493ULL: goto x86_l_1d45;
	case 7501ULL: goto x86_l_1d4d;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7518ULL: goto x86_l_1d5e;
	case 7523ULL: goto x86_l_1d63;
	case 7528ULL: goto x86_l_1d68;
	case 7530ULL: goto x86_l_1d6a;
	case 7533ULL: goto x86_l_1d6d;
	case 7539ULL: goto x86_l_1d73;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7554ULL: goto x86_l_1d82;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7594ULL: goto x86_l_1daa;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7618ULL: goto x86_l_1dc2;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7639ULL: goto x86_l_1dd7;
	case 7643ULL: goto x86_l_1ddb;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7671ULL: goto x86_l_1df7;
	case 7678ULL: goto x86_l_1dfe;
	case 7684ULL: goto x86_l_1e04;
	case 7692ULL: goto x86_l_1e0c;
	case 7696ULL: goto x86_l_1e10;
	case 7701ULL: goto x86_l_1e15;
	case 7704ULL: goto x86_l_1e18;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7715ULL: goto x86_l_1e23;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7751ULL: goto x86_l_1e47;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7774ULL: goto x86_l_1e5e;
	case 7782ULL: goto x86_l_1e66;
	case 7784ULL: goto x86_l_1e68;
	case 7787ULL: goto x86_l_1e6b;
	case 7793ULL: goto x86_l_1e71;
	case 7796ULL: goto x86_l_1e74;
	case 7799ULL: goto x86_l_1e77;
	case 7803ULL: goto x86_l_1e7b;
	case 7807ULL: goto x86_l_1e7f;
	case 7810ULL: goto x86_l_1e82;
	case 7814ULL: goto x86_l_1e86;
	case 7818ULL: goto x86_l_1e8a;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7833ULL: goto x86_l_1e99;
	case 7836ULL: goto x86_l_1e9c;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7849ULL: goto x86_l_1ea9;
	case 7855ULL: goto x86_l_1eaf;
	case 7857ULL: goto x86_l_1eb1;
	case 7863ULL: goto x86_l_1eb7;
	case 7866ULL: goto x86_l_1eba;
	case 7872ULL: goto x86_l_1ec0;
	case 7875ULL: goto x86_l_1ec3;
	case 7881ULL: goto x86_l_1ec9;
	case 7887ULL: goto x86_l_1ecf;
	case 7891ULL: goto x86_l_1ed3;
	case 7896ULL: goto x86_l_1ed8;
	case 7900ULL: goto x86_l_1edc;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7917ULL: goto x86_l_1eed;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7929ULL: goto x86_l_1ef9;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7945ULL: goto x86_l_1f09;
	case 7949ULL: goto x86_l_1f0d;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7963ULL: goto x86_l_1f1b;
	case 7966ULL: goto x86_l_1f1e;
	case 7968ULL: goto x86_l_1f20;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7985ULL: goto x86_l_1f31;
	case 7987ULL: goto x86_l_1f33;
	case 7991ULL: goto x86_l_1f37;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8012ULL: goto x86_l_1f4c;
	case 8019ULL: goto x86_l_1f53;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8031ULL: goto x86_l_1f5f;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8041ULL: goto x86_l_1f69;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8052ULL: goto x86_l_1f74;
	case 8055ULL: goto x86_l_1f77;
	case 8061ULL: goto x86_l_1f7d;
	case 8064ULL: goto x86_l_1f80;
	case 8069ULL: goto x86_l_1f85;
	case 8077ULL: goto x86_l_1f8d;
	case 8089ULL: goto x86_l_1f99;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8112ULL: goto x86_l_1fb0;
	case 8116ULL: goto x86_l_1fb4;
	case 8118ULL: goto x86_l_1fb6;
	case 8123ULL: goto x86_l_1fbb;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8161ULL: goto x86_l_1fe1;
	case 8169ULL: goto x86_l_1fe9;
	case 8177ULL: goto x86_l_1ff1;
	case 8182ULL: goto x86_l_1ff6;
	case 8189ULL: goto x86_l_1ffd;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8204ULL: goto x86_l_200c;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8215ULL: goto x86_l_2017;
	case 8217ULL: goto x86_l_2019;
	case 8222ULL: goto x86_l_201e;
	case 8229ULL: goto x86_l_2025;
	case 8239ULL: goto x86_l_202f;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8263ULL: goto x86_l_2047;
	case 8266ULL: goto x86_l_204a;
	case 8272ULL: goto x86_l_2050;
	case 8274ULL: goto x86_l_2052;
	case 8279ULL: goto x86_l_2057;
	case 8282ULL: goto x86_l_205a;
	case 8288ULL: goto x86_l_2060;
	case 8291ULL: goto x86_l_2063;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8316ULL: goto x86_l_207c;
	case 8320ULL: goto x86_l_2080;
	case 8324ULL: goto x86_l_2084;
	case 8329ULL: goto x86_l_2089;
	case 8334ULL: goto x86_l_208e;
	case 8336ULL: goto x86_l_2090;
	case 8340ULL: goto x86_l_2094;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8354ULL: goto x86_l_20a2;
	case 8357ULL: goto x86_l_20a5;
	case 8359ULL: goto x86_l_20a7;
	case 8363ULL: goto x86_l_20ab;
	case 8369ULL: goto x86_l_20b1;
	case 8375ULL: goto x86_l_20b7;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8392ULL: goto x86_l_20c8;
	case 8397ULL: goto x86_l_20cd;
	case 8402ULL: goto x86_l_20d2;
	case 8407ULL: goto x86_l_20d7;
	case 8409ULL: goto x86_l_20d9;
	case 8412ULL: goto x86_l_20dc;
	case 8418ULL: goto x86_l_20e2;
	case 8423ULL: goto x86_l_20e7;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8456ULL: goto x86_l_2108;
	case 8461ULL: goto x86_l_210d;
	case 8466ULL: goto x86_l_2112;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8498ULL: goto x86_l_2132;
	case 8503ULL: goto x86_l_2137;
	case 8506ULL: goto x86_l_213a;
	case 8508ULL: goto x86_l_213c;
	case 8514ULL: goto x86_l_2142;
	case 8517ULL: goto x86_l_2145;
	case 8523ULL: goto x86_l_214b;
	case 8525ULL: goto x86_l_214d;
	case 8533ULL: goto x86_l_2155;
	case 8536ULL: goto x86_l_2158;
	case 8541ULL: goto x86_l_215d;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8551ULL: goto x86_l_2167;
	case 8554ULL: goto x86_l_216a;
	case 8559ULL: goto x86_l_216f;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8576ULL: goto x86_l_2180;
	case 8578ULL: goto x86_l_2182;
	case 8581ULL: goto x86_l_2185;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8587ULL: goto x86_l_218b;
	case 8591ULL: goto x86_l_218f;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8607ULL: goto x86_l_219f;
	case 8610ULL: goto x86_l_21a2;
	case 8616ULL: goto x86_l_21a8;
	case 8619ULL: goto x86_l_21ab;
	case 8625ULL: goto x86_l_21b1;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8652ULL: goto x86_l_21cc;
	case 8657ULL: goto x86_l_21d1;
	case 8659ULL: goto x86_l_21d3;
	case 8663ULL: goto x86_l_21d7;
	case 8668ULL: goto x86_l_21dc;
	case 8671ULL: goto x86_l_21df;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8683ULL: goto x86_l_21eb;
	case 8687ULL: goto x86_l_21ef;
	case 8691ULL: goto x86_l_21f3;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8705ULL: goto x86_l_2201;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8727ULL: goto x86_l_2217;
	case 8729ULL: goto x86_l_2219;
	case 8733ULL: goto x86_l_221d;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8772ULL: goto x86_l_2244;
	case 8775ULL: goto x86_l_2247;
	case 8777ULL: goto x86_l_2249;
	case 8779ULL: goto x86_l_224b;
	case 8784ULL: goto x86_l_2250;
	case 8787ULL: goto x86_l_2253;
	case 8791ULL: goto x86_l_2257;
	case 8795ULL: goto x86_l_225b;
	case 8798ULL: goto x86_l_225e;
	case 8801ULL: goto x86_l_2261;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8826ULL: goto x86_l_227a;
	case 8828ULL: goto x86_l_227c;
	case 8833ULL: goto x86_l_2281;
	case 8839ULL: goto x86_l_2287;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8852ULL: goto x86_l_2294;
	case 8855ULL: goto x86_l_2297;
	case 8860ULL: goto x86_l_229c;
	case 8866ULL: goto x86_l_22a2;
	case 8869ULL: goto x86_l_22a5;
	case 8875ULL: goto x86_l_22ab;
	case 8881ULL: goto x86_l_22b1;
	case 8886ULL: goto x86_l_22b6;
	case 8891ULL: goto x86_l_22bb;
	case 8896ULL: goto x86_l_22c0;
	case 8901ULL: goto x86_l_22c5;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8910ULL: goto x86_l_22ce;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c06:
	/* 0x1c06: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c0a:
	/* 0x1c0a: add    r12,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1c0e:
	/* 0x1c0e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c13:
	/* 0x1c13: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c16:
	/* 0x1c16: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c1e:
	/* 0x1c1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c20:
	/* 0x1c20: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1c26:
	/* 0x1c26: jmp    1cf6 <generic_kprobe_process_event+0x1cf6> */
	goto x86_l_1cf6;
x86_l_1c2b:
	/* 0x1c2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c30:
	/* 0x1c30: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c35:
	/* 0x1c35: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c38:
	/* 0x1c38: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c42:
	/* 0x1c42: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c45:
	/* 0x1c45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c47:
	/* 0x1c47: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c4b:
	/* 0x1c4b: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c50:
	/* 0x1c50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c55:
	/* 0x1c55: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c5a:
	/* 0x1c5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c5c:
	/* 0x1c5c: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c60:
	/* 0x1c60: add    r12,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1c64:
	/* 0x1c64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c69:
	/* 0x1c69: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c6c:
	/* 0x1c6c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c71:
	/* 0x1c71: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c74:
	/* 0x1c74: jmp    1cee <generic_kprobe_process_event+0x1cee> */
	goto x86_l_1cee;
x86_l_1c76:
	/* 0x1c76: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c7b:
	/* 0x1c7b: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c80:
	/* 0x1c80: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c85:
	/* 0x1c85: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c8a:
	/* 0x1c8a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c8f:
	/* 0x1c8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c91:
	/* 0x1c91: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c95:
	/* 0x1c95: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c9d:
	/* 0x1c9d: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ca2:
	/* 0x1ca2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ca7:
	/* 0x1ca7: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1cac:
	/* 0x1cac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cb1:
	/* 0x1cb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb3:
	/* 0x1cb3: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cbb:
	/* 0x1cbb: add    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cc4:
	/* 0x1cc4: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1cc9:
	/* 0x1cc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cce:
	/* 0x1cce: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1cd1:
	/* 0x1cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd3:
	/* 0x1cd3: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1ce1:
	/* 0x1ce1: add    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1ce9:
	/* 0x1ce9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1cee:
	/* 0x1cee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf0:
	/* 0x1cf0: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1cf6:
	/* 0x1cf6: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cfb:
	/* 0x1cfb: jmp    c06 <generic_kprobe_process_event+0xc06> */
	return 3078ULL;
x86_l_1d00:
	/* 0x1d00: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d05:
	/* 0x1d05: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1d0d:
	/* 0x1d0d: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1d15:
	/* 0x1d15: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1d25:
	/* 0x1d25: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1d35:
	/* 0x1d35: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1d3d:
	/* 0x1d3d: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d45:
	/* 0x1d45: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d54:
	/* 0x1d54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d59:
	/* 0x1d59: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d63:
	/* 0x1d63: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d68:
	/* 0x1d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6a:
	/* 0x1d6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d6d:
	/* 0x1d6d: je     20bf <generic_kprobe_process_event+0x20bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20bf;
	}
x86_l_1d73:
	/* 0x1d73: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d76:
	/* 0x1d76: jmp    bfc <generic_kprobe_process_event+0xbfc> */
	return 3068ULL;
x86_l_1d7b:
	/* 0x1d7b: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1d82:
	/* 0x1d82: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1d85:
	/* 0x1d85: jmp    104c <generic_kprobe_process_event+0x104c> */
	return 4172ULL;
x86_l_1d8a:
	/* 0x1d8a: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1d8d:
	/* 0x1d8d: jmp    1051 <generic_kprobe_process_event+0x1051> */
	return 4177ULL;
x86_l_1d92:
	/* 0x1d92: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d96:
	/* 0x1d96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d9b:
	/* 0x1d9b: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1da3:
	/* 0x1da3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da8:
	/* 0x1da8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1daa:
	/* 0x1daa: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1dae:
	/* 0x1dae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1db3:
	/* 0x1db3: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1db8:
	/* 0x1db8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dbd:
	/* 0x1dbd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1dc0:
	/* 0x1dc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc2:
	/* 0x1dc2: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1dca:
	/* 0x1dca: mov    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1dd7:
	/* 0x1dd7: lea    r12,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ddb:
	/* 0x1ddb: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1de2:
	/* 0x1de2: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1de7:
	/* 0x1de7: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dec:
	/* 0x1dec: test   BYTE PTR [rsp+0x40],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906976ULL);
x86_l_1df1:
	/* 0x1df1: je     2773 <generic_kprobe_process_event+0x2773> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10099ULL;
	}
x86_l_1df7:
	/* 0x1df7: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_1dfe:
	/* 0x1dfe: jb     2744 <generic_kprobe_process_event+0x2744> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10052ULL;
	}
x86_l_1e04:
	/* 0x1e04: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1e0c:
	/* 0x1e0c: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1e10:
	/* 0x1e10: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e15:
	/* 0x1e15: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1e18:
	/* 0x1e18: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1e1b:
	/* 0x1e1b: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 7712ULL);
	__x86_sim_call_depth++;
	return 13037ULL;
x86_l_1e20:
	/* 0x1e20: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1e23:
	/* 0x1e23: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1e27:
	/* 0x1e27: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e2c:
	/* 0x1e2c: jmp    104c <generic_kprobe_process_event+0x104c> */
	return 4172ULL;
x86_l_1e31:
	/* 0x1e31: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e36:
	/* 0x1e36: movzx  ebx,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e43:
	/* 0x1e43: lea    r13,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1e47:
	/* 0x1e47: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_1e52:
	/* 0x1e52: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e57:
	/* 0x1e57: mov    rdi,QWORD PTR [rip+0x23a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1e5e:
	/* 0x1e5e: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1e66:
	/* 0x1e66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e68:
	/* 0x1e68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e6b:
	/* 0x1e6b: je     2e2d <generic_kprobe_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11821ULL;
	}
x86_l_1e71:
	/* 0x1e71: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1e74:
	/* 0x1e74: mov    WORD PTR [rax],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e77:
	/* 0x1e77: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1e7b:
	/* 0x1e7b: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1e7f:
	/* 0x1e7f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1e82:
	/* 0x1e82: add    rbx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1e86:
	/* 0x1e86: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1e8a:
	/* 0x1e8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e8f:
	/* 0x1e8f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e92:
	/* 0x1e92: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1e97:
	/* 0x1e97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e99:
	/* 0x1e99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e9c:
	/* 0x1e9c: js     2e2d <generic_kprobe_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11821ULL;
	}
x86_l_1ea2:
	/* 0x1ea2: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1ea6:
	/* 0x1ea6: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1ea9:
	/* 0x1ea9: jg     27c8 <generic_kprobe_process_event+0x27c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10184ULL;
	}
x86_l_1eaf:
	/* 0x1eaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eb1:
	/* 0x1eb1: je     2877 <generic_kprobe_process_event+0x2877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10359ULL;
	}
x86_l_1eb7:
	/* 0x1eb7: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1eba:
	/* 0x1eba: je     2877 <generic_kprobe_process_event+0x2877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10359ULL;
	}
x86_l_1ec0:
	/* 0x1ec0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1ec3:
	/* 0x1ec3: jne    2a37 <generic_kprobe_process_event+0x2a37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10807ULL;
	}
x86_l_1ec9:
	/* 0x1ec9: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1ecf:
	/* 0x1ecf: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1ed3:
	/* 0x1ed3: jmp    2996 <generic_kprobe_process_event+0x2996> */
	return 10646ULL;
x86_l_1ed8:
	/* 0x1ed8: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1edc:
	/* 0x1edc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ee1:
	/* 0x1ee1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ee6:
	/* 0x1ee6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1eeb:
	/* 0x1eeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eed:
	/* 0x1eed: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1ef9:
	/* 0x1ef9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1efe:
	/* 0x1efe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f00:
	/* 0x1f00: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f05:
	/* 0x1f05: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f09:
	/* 0x1f09: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f0d:
	/* 0x1f0d: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1f11:
	/* 0x1f11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f16:
	/* 0x1f16: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f1e:
	/* 0x1f1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f20:
	/* 0x1f20: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1f24:
	/* 0x1f24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f29:
	/* 0x1f29: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f2e:
	/* 0x1f2e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f31:
	/* 0x1f31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f33:
	/* 0x1f33: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1f37:
	/* 0x1f37: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1f3d:
	/* 0x1f3d: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f42:
	/* 0x1f42: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f47:
	/* 0x1f47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f4c:
	/* 0x1f4c: mov    rdi,QWORD PTR [rip+0x23a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1f53:
	/* 0x1f53: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f58:
	/* 0x1f58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f5a:
	/* 0x1f5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f5d:
	/* 0x1f5d: je     1f77 <generic_kprobe_process_event+0x1f77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f77;
	}
x86_l_1f5f:
	/* 0x1f5f: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f61:
	/* 0x1f61: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f66:
	/* 0x1f66: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f69:
	/* 0x1f69: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f71:
	/* 0x1f71: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f74:
	/* 0x1f74: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1f77:
	/* 0x1f77: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_1f7d:
	/* 0x1f7d: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1f80:
	/* 0x1f80: jmp    1051 <generic_kprobe_process_event+0x1051> */
	return 4177ULL;
x86_l_1f85:
	/* 0x1f85: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1f8d:
	/* 0x1f8d: mov    QWORD PTR [rbx+rax*1+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 618475290624ULL);
x86_l_1f99:
	/* 0x1f99: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1f9f:
	/* 0x1f9f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fa4:
	/* 0x1fa4: jmp    104c <generic_kprobe_process_event+0x104c> */
	return 4172ULL;
x86_l_1fa9:
	/* 0x1fa9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1fae:
	/* 0x1fae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb0:
	/* 0x1fb0: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1fb4:
	/* 0x1fb4: jne    1fbf <generic_kprobe_process_event+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fbf;
	}
x86_l_1fb6:
	/* 0x1fb6: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1fbb:
	/* 0x1fbb: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    rcx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    rdx,QWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1fce:
	/* 0x1fce: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fd3:
	/* 0x1fd3: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1fe1:
	/* 0x1fe1: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1fe9:
	/* 0x1fe9: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1ff1:
	/* 0x1ff1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ff6:
	/* 0x1ff6: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_1ffd:
	/* 0x1ffd: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2005:
	/* 0x2005: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_200a:
	/* 0x200a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_200c:
	/* 0x200c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200e:
	/* 0x200e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2011:
	/* 0x2011: je     281c <generic_kprobe_process_event+0x281c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10268ULL;
	}
x86_l_2017:
	/* 0x2017: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2019:
	/* 0x2019: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_201e:
	/* 0x201e: mov    WORD PTR [rsp+0x52],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 352187318277ULL);
x86_l_2025:
	/* 0x2025: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_202f:
	/* 0x202f: mov    QWORD PTR [rsp+0x54],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2034:
	/* 0x2034: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2039:
	/* 0x2039: mov    rdi,QWORD PTR [rip+0x23a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2040:
	/* 0x2040: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2045:
	/* 0x2045: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2047:
	/* 0x2047: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_204a:
	/* 0x204a: je     27f4 <generic_kprobe_process_event+0x27f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10228ULL;
	}
x86_l_2050:
	/* 0x2050: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2052:
	/* 0x2052: jmp    281c <generic_kprobe_process_event+0x281c> */
	return 10268ULL;
x86_l_2057:
	/* 0x2057: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_205a:
	/* 0x205a: je     2289 <generic_kprobe_process_event+0x2289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2289;
	}
x86_l_2060:
	/* 0x2060: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2063:
	/* 0x2063: jne    2667 <generic_kprobe_process_event+0x2667> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9831ULL;
	}
x86_l_2069:
	/* 0x2069: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_206e:
	/* 0x206e: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_2074:
	/* 0x2074: jmp    2294 <generic_kprobe_process_event+0x2294> */
	goto x86_l_2294;
x86_l_2079:
	/* 0x2079: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_207c:
	/* 0x207c: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2080:
	/* 0x2080: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2084:
	/* 0x2084: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2089:
	/* 0x2089: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_208e:
	/* 0x208e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2090:
	/* 0x2090: lea    rdi,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2094:
	/* 0x2094: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2098:
	/* 0x2098: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_209d:
	/* 0x209d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20a2:
	/* 0x20a2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20a5:
	/* 0x20a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a7:
	/* 0x20a7: movzx  eax,WORD PTR [rbx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_20ab:
	/* 0x20ab: movbe  WORD PTR [rbx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_20b1:
	/* 0x20b1: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_20b7:
	/* 0x20b7: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_20ba:
	/* 0x20ba: jmp    104c <generic_kprobe_process_event+0x104c> */
	return 4172ULL;
x86_l_20bf:
	/* 0x20bf: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c4:
	/* 0x20c4: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c8:
	/* 0x20c8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_20cd:
	/* 0x20cd: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_20d2:
	/* 0x20d2: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_20d7:
	/* 0x20d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d9:
	/* 0x20d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20dc:
	/* 0x20dc: js     1d73 <generic_kprobe_process_event+0x1d73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d73;
	}
x86_l_20e2:
	/* 0x20e2: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e7:
	/* 0x20e7: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20eb:
	/* 0x20eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20f0:
	/* 0x20f0: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_20f8:
	/* 0x20f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20fd:
	/* 0x20fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ff:
	/* 0x20ff: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2104:
	/* 0x2104: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2108:
	/* 0x2108: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_210d:
	/* 0x210d: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_2112:
	/* 0x2112: add    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_211a:
	/* 0x211a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_211f:
	/* 0x211f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2121:
	/* 0x2121: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_2125:
	/* 0x2125: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_212a:
	/* 0x212a: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2132:
	/* 0x2132: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2137:
	/* 0x2137: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_213a:
	/* 0x213a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213c:
	/* 0x213c: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_2142:
	/* 0x2142: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2145:
	/* 0x2145: jne    bfc <generic_kprobe_process_event+0xbfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3068ULL;
	}
x86_l_214b:
	/* 0x214b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_214d:
	/* 0x214d: cmp    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2155:
	/* 0x2155: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2158:
	/* 0x2158: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_215d:
	/* 0x215d: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215f:
	/* 0x215f: jmp    bfc <generic_kprobe_process_event+0xbfc> */
	return 3068ULL;
x86_l_2164:
	/* 0x2164: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2167:
	/* 0x2167: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_216a:
	/* 0x216a: jmp    c01 <generic_kprobe_process_event+0xc01> */
	return 3073ULL;
x86_l_216f:
	/* 0x216f: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_2173:
	/* 0x2173: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2178:
	/* 0x2178: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_217d:
	/* 0x217d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2180:
	/* 0x2180: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2182:
	/* 0x2182: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2185:
	/* 0x2185: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_2187:
	/* 0x2187: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2189:
	/* 0x2189: js     218f <generic_kprobe_process_event+0x218f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_218f;
	}
x86_l_218b:
	/* 0x218b: mov    BYTE PTR [r13+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_218f:
	/* 0x218f: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_2195:
	/* 0x2195: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_219a:
	/* 0x219a: jmp    1051 <generic_kprobe_process_event+0x1051> */
	return 4177ULL;
x86_l_219f:
	/* 0x219f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_21a2:
	/* 0x21a2: je     289b <generic_kprobe_process_event+0x289b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10395ULL;
	}
x86_l_21a8:
	/* 0x21a8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_21ab:
	/* 0x21ab: jne    28a6 <generic_kprobe_process_event+0x28a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10406ULL;
	}
x86_l_21b1:
	/* 0x21b1: lea    rax,[r12+0x5e58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_21b9:
	/* 0x21b9: jmp    28a3 <generic_kprobe_process_event+0x28a3> */
	return 10403ULL;
x86_l_21be:
	/* 0x21be: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21c2:
	/* 0x21c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21c7:
	/* 0x21c7: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21cc:
	/* 0x21cc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21d1:
	/* 0x21d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d3:
	/* 0x21d3: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21d7:
	/* 0x21d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21dc:
	/* 0x21dc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_21df:
	/* 0x21df: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21e4:
	/* 0x21e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e6:
	/* 0x21e6: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21eb:
	/* 0x21eb: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21ef:
	/* 0x21ef: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21f3:
	/* 0x21f3: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_21f7:
	/* 0x21f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21fc:
	/* 0x21fc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2201:
	/* 0x2201: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2204:
	/* 0x2204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2206:
	/* 0x2206: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_220a:
	/* 0x220a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_220f:
	/* 0x220f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2214:
	/* 0x2214: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2217:
	/* 0x2217: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2219:
	/* 0x2219: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_221d:
	/* 0x221d: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2223:
	/* 0x2223: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2228:
	/* 0x2228: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_222c:
	/* 0x222c: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2231:
	/* 0x2231: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2236:
	/* 0x2236: mov    rdi,QWORD PTR [rip+0x23a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_223d:
	/* 0x223d: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2242:
	/* 0x2242: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2244:
	/* 0x2244: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2247:
	/* 0x2247: je     2261 <generic_kprobe_process_event+0x2261> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2261;
	}
x86_l_2249:
	/* 0x2249: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_224b:
	/* 0x224b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2250:
	/* 0x2250: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2253:
	/* 0x2253: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2257:
	/* 0x2257: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_225b:
	/* 0x225b: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_225e:
	/* 0x225e: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2261:
	/* 0x2261: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_2267:
	/* 0x2267: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_226a:
	/* 0x226a: jmp    286a <generic_kprobe_process_event+0x286a> */
	return 10346ULL;
x86_l_226f:
	/* 0x226f: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2274:
	/* 0x2274: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_227a:
	/* 0x227a: jmp    2294 <generic_kprobe_process_event+0x2294> */
	goto x86_l_2294;
x86_l_227c:
	/* 0x227c: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2281:
	/* 0x2281: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2287:
	/* 0x2287: jmp    2294 <generic_kprobe_process_event+0x2294> */
	goto x86_l_2294;
x86_l_2289:
	/* 0x2289: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_228e:
	/* 0x228e: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_2294:
	/* 0x2294: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2297:
	/* 0x2297: test   BYTE PTR [rsp+0x40],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906960ULL);
x86_l_229c:
	/* 0x229c: jne    267b <generic_kprobe_process_event+0x267b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9851ULL;
	}
x86_l_22a2:
	/* 0x22a2: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_22a5:
	/* 0x22a5: je     2723 <generic_kprobe_process_event+0x2723> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10019ULL;
	}
x86_l_22ab:
	/* 0x22ab: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_22b1:
	/* 0x22b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22b6:
	/* 0x22b6: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_22bb:
	/* 0x22bb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22c0:
	/* 0x22c0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c5:
	/* 0x22c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c7:
	/* 0x22c7: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_22cc:
	/* 0x22cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22ce:
	/* 0x22ce: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9814ULL;
	}
	return 8916ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8933ULL: goto x86_l_22e5;
	case 8939ULL: goto x86_l_22eb;
	case 8944ULL: goto x86_l_22f0;
	case 8948ULL: goto x86_l_22f4;
	case 8953ULL: goto x86_l_22f9;
	case 8959ULL: goto x86_l_22ff;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8975ULL: goto x86_l_230f;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8984ULL: goto x86_l_2318;
	case 8990ULL: goto x86_l_231e;
	case 8994ULL: goto x86_l_2322;
	case 9000ULL: goto x86_l_2328;
	case 9005ULL: goto x86_l_232d;
	case 9009ULL: goto x86_l_2331;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9045ULL: goto x86_l_2355;
	case 9050ULL: goto x86_l_235a;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9066ULL: goto x86_l_236a;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9091ULL: goto x86_l_2383;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9109ULL: goto x86_l_2395;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9118ULL: goto x86_l_239e;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9133ULL: goto x86_l_23ad;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9148ULL: goto x86_l_23bc;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9164ULL: goto x86_l_23cc;
	case 9169ULL: goto x86_l_23d1;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9178ULL: goto x86_l_23da;
	case 9184ULL: goto x86_l_23e0;
	case 9189ULL: goto x86_l_23e5;
	case 9194ULL: goto x86_l_23ea;
	case 9199ULL: goto x86_l_23ef;
	case 9205ULL: goto x86_l_23f5;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9232ULL: goto x86_l_2410;
	case 9235ULL: goto x86_l_2413;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9250ULL: goto x86_l_2422;
	case 9252ULL: goto x86_l_2424;
	case 9257ULL: goto x86_l_2429;
	case 9259ULL: goto x86_l_242b;
	case 9265ULL: goto x86_l_2431;
	case 9270ULL: goto x86_l_2436;
	case 9274ULL: goto x86_l_243a;
	case 9280ULL: goto x86_l_2440;
	case 9285ULL: goto x86_l_2445;
	case 9289ULL: goto x86_l_2449;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9319ULL: goto x86_l_2467;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9335ULL: goto x86_l_2477;
	case 9340ULL: goto x86_l_247c;
	case 9346ULL: goto x86_l_2482;
	case 9352ULL: goto x86_l_2488;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9367ULL: goto x86_l_2497;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9400ULL: goto x86_l_24b8;
	case 9406ULL: goto x86_l_24be;
	case 9411ULL: goto x86_l_24c3;
	case 9415ULL: goto x86_l_24c7;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9430ULL: goto x86_l_24d6;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9446ULL: goto x86_l_24e6;
	case 9451ULL: goto x86_l_24eb;
	case 9453ULL: goto x86_l_24ed;
	case 9458ULL: goto x86_l_24f2;
	case 9460ULL: goto x86_l_24f4;
	case 9466ULL: goto x86_l_24fa;
	case 9471ULL: goto x86_l_24ff;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9487ULL: goto x86_l_250f;
	case 9493ULL: goto x86_l_2515;
	case 9498ULL: goto x86_l_251a;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9514ULL: goto x86_l_252a;
	case 9517ULL: goto x86_l_252d;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9532ULL: goto x86_l_253c;
	case 9534ULL: goto x86_l_253e;
	case 9539ULL: goto x86_l_2543;
	case 9541ULL: goto x86_l_2545;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9556ULL: goto x86_l_2554;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9571ULL: goto x86_l_2563;
	case 9577ULL: goto x86_l_2569;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9601ULL: goto x86_l_2581;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9628ULL: goto x86_l_259c;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9655ULL: goto x86_l_25b7;
	case 9658ULL: goto x86_l_25ba;
	case 9663ULL: goto x86_l_25bf;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9675ULL: goto x86_l_25cb;
	case 9680ULL: goto x86_l_25d0;
	case 9682ULL: goto x86_l_25d2;
	case 9688ULL: goto x86_l_25d8;
	case 9693ULL: goto x86_l_25dd;
	case 9697ULL: goto x86_l_25e1;
	case 9703ULL: goto x86_l_25e7;
	case 9708ULL: goto x86_l_25ec;
	case 9712ULL: goto x86_l_25f0;
	case 9718ULL: goto x86_l_25f6;
	case 9723ULL: goto x86_l_25fb;
	case 9728ULL: goto x86_l_2600;
	case 9733ULL: goto x86_l_2605;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9742ULL: goto x86_l_260e;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9754ULL: goto x86_l_261a;
	case 9761ULL: goto x86_l_2621;
	case 9763ULL: goto x86_l_2623;
	case 9768ULL: goto x86_l_2628;
	case 9773ULL: goto x86_l_262d;
	case 9779ULL: goto x86_l_2633;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9792ULL: goto x86_l_2640;
	case 9795ULL: goto x86_l_2643;
	case 9797ULL: goto x86_l_2645;
	case 9802ULL: goto x86_l_264a;
	case 9804ULL: goto x86_l_264c;
	case 9806ULL: goto x86_l_264e;
	case 9809ULL: goto x86_l_2651;
	case 9814ULL: goto x86_l_2656;
	case 9822ULL: goto x86_l_265e;
	case 9826ULL: goto x86_l_2662;
	case 9831ULL: goto x86_l_2667;
	case 9834ULL: goto x86_l_266a;
	case 9840ULL: goto x86_l_2670;
	case 9845ULL: goto x86_l_2675;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9858ULL: goto x86_l_2682;
	case 9862ULL: goto x86_l_2686;
	case 9864ULL: goto x86_l_2688;
	case 9868ULL: goto x86_l_268c;
	case 9873ULL: goto x86_l_2691;
	case 9877ULL: goto x86_l_2695;
	case 9881ULL: goto x86_l_2699;
	case 9886ULL: goto x86_l_269e;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9909ULL: goto x86_l_26b5;
	case 9917ULL: goto x86_l_26bd;
	case 9922ULL: goto x86_l_26c2;
	case 9929ULL: goto x86_l_26c9;
	case 9937ULL: goto x86_l_26d1;
	case 9942ULL: goto x86_l_26d6;
	case 9944ULL: goto x86_l_26d8;
	case 9946ULL: goto x86_l_26da;
	case 9949ULL: goto x86_l_26dd;
	case 9955ULL: goto x86_l_26e3;
	case 9957ULL: goto x86_l_26e5;
	case 9962ULL: goto x86_l_26ea;
	case 9969ULL: goto x86_l_26f1;
	case 9979ULL: goto x86_l_26fb;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9996ULL: goto x86_l_270c;
	case 10001ULL: goto x86_l_2711;
	case 10003ULL: goto x86_l_2713;
	case 10006ULL: goto x86_l_2716;
	case 10012ULL: goto x86_l_271c;
	case 10014ULL: goto x86_l_271e;
	case 10019ULL: goto x86_l_2723;
	case 10022ULL: goto x86_l_2726;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10044ULL: goto x86_l_273c;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10055ULL: goto x86_l_2747;
	case 10062ULL: goto x86_l_274e;
	case 10070ULL: goto x86_l_2756;
	case 10075ULL: goto x86_l_275b;
	case 10079ULL: goto x86_l_275f;
	case 10086ULL: goto x86_l_2766;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10106ULL: goto x86_l_277a;
	case 10111ULL: goto x86_l_277f;
	case 10115ULL: goto x86_l_2783;
	case 10120ULL: goto x86_l_2788;
	case 10126ULL: goto x86_l_278e;
	case 10131ULL: goto x86_l_2793;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10139ULL: goto x86_l_279b;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10153ULL: goto x86_l_27a9;
	case 10156ULL: goto x86_l_27ac;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10184ULL: goto x86_l_27c8;
	case 10187ULL: goto x86_l_27cb;
	case 10193ULL: goto x86_l_27d1;
	case 10196ULL: goto x86_l_27d4;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10213ULL: goto x86_l_27e5;
	case 10219ULL: goto x86_l_27eb;
	case 10223ULL: goto x86_l_27ef;
	case 10228ULL: goto x86_l_27f4;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10264ULL: goto x86_l_2818;
	case 10266ULL: goto x86_l_281a;
	case 10268ULL: goto x86_l_281c;
	case 10274ULL: goto x86_l_2822;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10293ULL: goto x86_l_2835;
	case 10298ULL: goto x86_l_283a;
	case 10305ULL: goto x86_l_2841;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10317ULL: goto x86_l_284d;
	case 10319ULL: goto x86_l_284f;
	case 10327ULL: goto x86_l_2857;
	case 10335ULL: goto x86_l_285f;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10363ULL: goto x86_l_287b;
	case 10370ULL: goto x86_l_2882;
	case 10375ULL: goto x86_l_2887;
	case 10383ULL: goto x86_l_288f;
	case 10385ULL: goto x86_l_2891;
	case 10393ULL: goto x86_l_2899;
	case 10395ULL: goto x86_l_289b;
	case 10403ULL: goto x86_l_28a3;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10416ULL: goto x86_l_28b0;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10436ULL: goto x86_l_28c4;
	case 10444ULL: goto x86_l_28cc;
	case 10450ULL: goto x86_l_28d2;
	case 10454ULL: goto x86_l_28d6;
	case 10456ULL: goto x86_l_28d8;
	case 10463ULL: goto x86_l_28df;
	case 10465ULL: goto x86_l_28e1;
	case 10471ULL: goto x86_l_28e7;
	case 10475ULL: goto x86_l_28eb;
	case 10480ULL: goto x86_l_28f0;
	case 10483ULL: goto x86_l_28f3;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10494ULL: goto x86_l_28fe;
	case 10499ULL: goto x86_l_2903;
	case 10502ULL: goto x86_l_2906;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10521ULL: goto x86_l_2919;
	case 10528ULL: goto x86_l_2920;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10542ULL: goto x86_l_292e;
	case 10548ULL: goto x86_l_2934;
	case 10551ULL: goto x86_l_2937;
	case 10557ULL: goto x86_l_293d;
	case 10564ULL: goto x86_l_2944;
	case 10570ULL: goto x86_l_294a;
	case 10574ULL: goto x86_l_294e;
	case 10578ULL: goto x86_l_2952;
	case 10584ULL: goto x86_l_2958;
	case 10589ULL: goto x86_l_295d;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10599ULL: goto x86_l_2967;
	case 10601ULL: goto x86_l_2969;
	case 10603ULL: goto x86_l_296b;
	case 10605ULL: goto x86_l_296d;
	case 10609ULL: goto x86_l_2971;
	case 10612ULL: goto x86_l_2974;
	case 10615ULL: goto x86_l_2977;
	case 10620ULL: goto x86_l_297c;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10635ULL: goto x86_l_298b;
	case 10642ULL: goto x86_l_2992;
	case 10646ULL: goto x86_l_2996;
	case 10650ULL: goto x86_l_299a;
	case 10654ULL: goto x86_l_299e;
	case 10659ULL: goto x86_l_29a3;
	case 10663ULL: goto x86_l_29a7;
	case 10669ULL: goto x86_l_29ad;
	case 10679ULL: goto x86_l_29b7;
	case 10683ULL: goto x86_l_29bb;
	case 10689ULL: goto x86_l_29c1;
	case 10693ULL: goto x86_l_29c5;
	case 10698ULL: goto x86_l_29ca;
	case 10702ULL: goto x86_l_29ce;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10717ULL: goto x86_l_29dd;
	case 10720ULL: goto x86_l_29e0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22d4:
	/* 0x22d4: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_22d9:
	/* 0x22d9: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_22de:
	/* 0x22de: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_22e5:
	/* 0x22e5: ja     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2656;
	}
x86_l_22eb:
	/* 0x22eb: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22f0:
	/* 0x22f0: lea    rdi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_22f4:
	/* 0x22f4: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22f9:
	/* 0x22f9: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_22ff:
	/* 0x22ff: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2302:
	/* 0x2302: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2307:
	/* 0x2307: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_230c:
	/* 0x230c: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_230f:
	/* 0x230f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2311:
	/* 0x2311: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2316:
	/* 0x2316: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2318:
	/* 0x2318: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_231e:
	/* 0x231e: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_2322:
	/* 0x2322: je     2726 <generic_kprobe_process_event+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2726;
	}
x86_l_2328:
	/* 0x2328: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_232d:
	/* 0x232d: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2331:
	/* 0x2331: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2337:
	/* 0x2337: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_233c:
	/* 0x233c: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2341:
	/* 0x2341: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2346:
	/* 0x2346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2348:
	/* 0x2348: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_234d:
	/* 0x234d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_234f:
	/* 0x234f: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_2355:
	/* 0x2355: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_235a:
	/* 0x235a: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_235f:
	/* 0x235f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2364:
	/* 0x2364: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_236a:
	/* 0x236a: ja     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2656;
	}
x86_l_2370:
	/* 0x2370: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2375:
	/* 0x2375: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2378:
	/* 0x2378: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_237d:
	/* 0x237d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2383:
	/* 0x2383: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2386:
	/* 0x2386: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_238b:
	/* 0x238b: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2390:
	/* 0x2390: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2395:
	/* 0x2395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2397:
	/* 0x2397: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_239c:
	/* 0x239c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_239e:
	/* 0x239e: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_23a4:
	/* 0x23a4: add    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_23a9:
	/* 0x23a9: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_23ad:
	/* 0x23ad: jb     2726 <generic_kprobe_process_event+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2726;
	}
x86_l_23b3:
	/* 0x23b3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23b8:
	/* 0x23b8: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23bc:
	/* 0x23bc: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_23c2:
	/* 0x23c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23c7:
	/* 0x23c7: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23cc:
	/* 0x23cc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23d1:
	/* 0x23d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d3:
	/* 0x23d3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_23d8:
	/* 0x23d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23da:
	/* 0x23da: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_23e0:
	/* 0x23e0: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_23e5:
	/* 0x23e5: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_23ea:
	/* 0x23ea: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ef:
	/* 0x23ef: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_23f5:
	/* 0x23f5: ja     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2656;
	}
x86_l_23fb:
	/* 0x23fb: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2400:
	/* 0x2400: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2405:
	/* 0x2405: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_240a:
	/* 0x240a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2410:
	/* 0x2410: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2413:
	/* 0x2413: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2418:
	/* 0x2418: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_241d:
	/* 0x241d: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2422:
	/* 0x2422: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2424:
	/* 0x2424: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2429:
	/* 0x2429: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_242b:
	/* 0x242b: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_2431:
	/* 0x2431: add    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2436:
	/* 0x2436: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_243a:
	/* 0x243a: je     2726 <generic_kprobe_process_event+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2726;
	}
x86_l_2440:
	/* 0x2440: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2445:
	/* 0x2445: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2449:
	/* 0x2449: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_244f:
	/* 0x244f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2454:
	/* 0x2454: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2459:
	/* 0x2459: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_245e:
	/* 0x245e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2460:
	/* 0x2460: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2465:
	/* 0x2465: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2467:
	/* 0x2467: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_246d:
	/* 0x246d: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2472:
	/* 0x2472: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2477:
	/* 0x2477: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_247c:
	/* 0x247c: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2482:
	/* 0x2482: ja     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2656;
	}
x86_l_2488:
	/* 0x2488: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_248d:
	/* 0x248d: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2492:
	/* 0x2492: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2497:
	/* 0x2497: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_249d:
	/* 0x249d: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24a0:
	/* 0x24a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24a5:
	/* 0x24a5: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24aa:
	/* 0x24aa: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24af:
	/* 0x24af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b1:
	/* 0x24b1: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24b6:
	/* 0x24b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b8:
	/* 0x24b8: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_24be:
	/* 0x24be: add    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_24c3:
	/* 0x24c3: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_24c7:
	/* 0x24c7: jb     2726 <generic_kprobe_process_event+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2726;
	}
x86_l_24cd:
	/* 0x24cd: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d2:
	/* 0x24d2: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24d6:
	/* 0x24d6: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_24dc:
	/* 0x24dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24e1:
	/* 0x24e1: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24e6:
	/* 0x24e6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24eb:
	/* 0x24eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ed:
	/* 0x24ed: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24f2:
	/* 0x24f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24f4:
	/* 0x24f4: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_24fa:
	/* 0x24fa: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24ff:
	/* 0x24ff: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2504:
	/* 0x2504: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2509:
	/* 0x2509: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_250f:
	/* 0x250f: ja     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2656;
	}
x86_l_2515:
	/* 0x2515: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_251a:
	/* 0x251a: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_251f:
	/* 0x251f: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2524:
	/* 0x2524: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_252a:
	/* 0x252a: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_252d:
	/* 0x252d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2532:
	/* 0x2532: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2537:
	/* 0x2537: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_253c:
	/* 0x253c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253e:
	/* 0x253e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2543:
	/* 0x2543: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2545:
	/* 0x2545: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_254b:
	/* 0x254b: add    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2550:
	/* 0x2550: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2554:
	/* 0x2554: je     2726 <generic_kprobe_process_event+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2726;
	}
x86_l_255a:
	/* 0x255a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255f:
	/* 0x255f: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2563:
	/* 0x2563: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2569:
	/* 0x2569: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_256e:
	/* 0x256e: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2573:
	/* 0x2573: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2578:
	/* 0x2578: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257a:
	/* 0x257a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_257f:
	/* 0x257f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2581:
	/* 0x2581: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_2587:
	/* 0x2587: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_258c:
	/* 0x258c: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2591:
	/* 0x2591: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2596:
	/* 0x2596: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_259c:
	/* 0x259c: ja     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2656;
	}
x86_l_25a2:
	/* 0x25a2: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25a7:
	/* 0x25a7: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_25ac:
	/* 0x25ac: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25b1:
	/* 0x25b1: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25b7:
	/* 0x25b7: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25ba:
	/* 0x25ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25bf:
	/* 0x25bf: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25c4:
	/* 0x25c4: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c9:
	/* 0x25c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cb:
	/* 0x25cb: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25d0:
	/* 0x25d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25d2:
	/* 0x25d2: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_25d8:
	/* 0x25d8: add    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25dd:
	/* 0x25dd: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_25e1:
	/* 0x25e1: jb     2726 <generic_kprobe_process_event+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2726;
	}
x86_l_25e7:
	/* 0x25e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ec:
	/* 0x25ec: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_25f0:
	/* 0x25f0: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_25f6:
	/* 0x25f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25fb:
	/* 0x25fb: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2600:
	/* 0x2600: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2605:
	/* 0x2605: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2607:
	/* 0x2607: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_260c:
	/* 0x260c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_260e:
	/* 0x260e: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_2610:
	/* 0x2610: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2615:
	/* 0x2615: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_261a:
	/* 0x261a: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_2621:
	/* 0x2621: ja     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2656;
	}
x86_l_2623:
	/* 0x2623: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2628:
	/* 0x2628: add    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_262d:
	/* 0x262d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2633:
	/* 0x2633: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2636:
	/* 0x2636: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_263b:
	/* 0x263b: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2640:
	/* 0x2640: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2643:
	/* 0x2643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2645:
	/* 0x2645: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_264a:
	/* 0x264a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_264c:
	/* 0x264c: js     2656 <generic_kprobe_process_event+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2656;
	}
x86_l_264e:
	/* 0x264e: add    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2651:
	/* 0x2651: jmp    2726 <generic_kprobe_process_event+0x2726> */
	goto x86_l_2726;
x86_l_2656:
	/* 0x2656: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_265e:
	/* 0x265e: mov    DWORD PTR [rbp+rax*1+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2662:
	/* 0x2662: jmp    2865 <generic_kprobe_process_event+0x2865> */
	goto x86_l_2865;
x86_l_2667:
	/* 0x2667: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_266a:
	/* 0x266a: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_2670:
	/* 0x2670: test   BYTE PTR [rsp+0x40],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906960ULL);
x86_l_2675:
	/* 0x2675: je     2726 <generic_kprobe_process_event+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2726;
	}
x86_l_267b:
	/* 0x267b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2680:
	/* 0x2680: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2682:
	/* 0x2682: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2686:
	/* 0x2686: jne    268c <generic_kprobe_process_event+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_268c;
	}
x86_l_2688:
	/* 0x2688: mov    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_268c:
	/* 0x268c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2691:
	/* 0x2691: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2695:
	/* 0x2695: mov    rdx,QWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2699:
	/* 0x2699: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_269e:
	/* 0x269e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a3:
	/* 0x26a3: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_26a8:
	/* 0x26a8: mov    QWORD PTR [rsp+0x70],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26ad:
	/* 0x26ad: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_26b5:
	/* 0x26b5: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_26bd:
	/* 0x26bd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26c2:
	/* 0x26c2: mov    rdi,QWORD PTR [rip+0x236] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_26c9:
	/* 0x26c9: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_26d1:
	/* 0x26d1: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26d6:
	/* 0x26d6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26d8:
	/* 0x26d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26da:
	/* 0x26da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26dd:
	/* 0x26dd: je     284f <generic_kprobe_process_event+0x284f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_284f;
	}
x86_l_26e3:
	/* 0x26e3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_26e5:
	/* 0x26e5: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26ea:
	/* 0x26ea: mov    WORD PTR [rsp+0x52],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 352187318277ULL);
x86_l_26f1:
	/* 0x26f1: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_26fb:
	/* 0x26fb: mov    QWORD PTR [rsp+0x54],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2700:
	/* 0x2700: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2705:
	/* 0x2705: mov    rdi,QWORD PTR [rip+0x236] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_270c:
	/* 0x270c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2711:
	/* 0x2711: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2713:
	/* 0x2713: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2716:
	/* 0x2716: je     282d <generic_kprobe_process_event+0x282d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_282d;
	}
x86_l_271c:
	/* 0x271c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_271e:
	/* 0x271e: jmp    284f <generic_kprobe_process_event+0x284f> */
	goto x86_l_284f;
x86_l_2723:
	/* 0x2723: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2726:
	/* 0x2726: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_272e:
	/* 0x272e: mov    DWORD PTR [rbp+rax*1+0x0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2733:
	/* 0x2733: mov    DWORD PTR [rbp+rax*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_2738:
	/* 0x2738: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_273c:
	/* 0x273c: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_273f:
	/* 0x273f: jmp    2865 <generic_kprobe_process_event+0x2865> */
	goto x86_l_2865;
x86_l_2744:
	/* 0x2744: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_2747:
	/* 0x2747: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_274e:
	/* 0x274e: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2756:
	/* 0x2756: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_275b:
	/* 0x275b: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_275f:
	/* 0x275f: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2766:
	/* 0x2766: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2769:
	/* 0x2769: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_276e:
	/* 0x276e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2773:
	/* 0x2773: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_277a:
	/* 0x277a: mov    ebp,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4095ULL);
x86_l_277f:
	/* 0x277f: cmovb  rbp,r13 */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_2783:
	/* 0x2783: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2788:
	/* 0x2788: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_278e:
	/* 0x278e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2793:
	/* 0x2793: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2795:
	/* 0x2795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2797:
	/* 0x2797: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2799:
	/* 0x2799: js     27b6 <generic_kprobe_process_event+0x27b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27b6;
	}
x86_l_279b:
	/* 0x279b: mov    DWORD PTR [r12],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_279f:
	/* 0x279f: mov    DWORD PTR [r12+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_27a4:
	/* 0x27a4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a9:
	/* 0x27a9: add    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27ac:
	/* 0x27ac: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27b1:
	/* 0x27b1: jmp    104c <generic_kprobe_process_event+0x104c> */
	return 4172ULL;
x86_l_27b6:
	/* 0x27b6: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_27be:
	/* 0x27be: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27c3:
	/* 0x27c3: jmp    104c <generic_kprobe_process_event+0x104c> */
	return 4172ULL;
x86_l_27c8:
	/* 0x27c8: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_27cb:
	/* 0x27cb: je     2987 <generic_kprobe_process_event+0x2987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2987;
	}
x86_l_27d1:
	/* 0x27d1: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_27d4:
	/* 0x27d4: je     2877 <generic_kprobe_process_event+0x2877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2877;
	}
x86_l_27da:
	/* 0x27da: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_27df:
	/* 0x27df: jne    2a37 <generic_kprobe_process_event+0x2a37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10807ULL;
	}
x86_l_27e5:
	/* 0x27e5: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_27eb:
	/* 0x27eb: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_27ef:
	/* 0x27ef: jmp    2996 <generic_kprobe_process_event+0x2996> */
	goto x86_l_2996;
x86_l_27f4:
	/* 0x27f4: mov    DWORD PTR [rsp+0xc8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459201ULL);
x86_l_27ff:
	/* 0x27ff: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2804:
	/* 0x2804: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_280b:
	/* 0x280b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2810:
	/* 0x2810: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2818:
	/* 0x2818: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_281a:
	/* 0x281a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281c:
	/* 0x281c: mov    DWORD PTR [rbx],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_2822:
	/* 0x2822: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2828:
	/* 0x2828: jmp    d8c <generic_kprobe_process_event+0xd8c> */
	return 3468ULL;
x86_l_282d:
	/* 0x282d: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_2835:
	/* 0x2835: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_283a:
	/* 0x283a: mov    rdi,QWORD PTR [rip+0x236] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2841:
	/* 0x2841: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2846:
	/* 0x2846: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_284b:
	/* 0x284b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284d:
	/* 0x284d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284f:
	/* 0x284f: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2857:
	/* 0x2857: mov    DWORD PTR [rbp+rax*1+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_285f:
	/* 0x285f: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2865:
	/* 0x2865: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_286a:
	/* 0x286a: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_286d:
	/* 0x286d: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2872:
	/* 0x2872: jmp    c01 <generic_kprobe_process_event+0xc01> */
	return 3073ULL;
x86_l_2877:
	/* 0x2877: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_287b:
	/* 0x287b: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2882:
	/* 0x2882: jmp    2992 <generic_kprobe_process_event+0x2992> */
	goto x86_l_2992;
x86_l_2887:
	/* 0x2887: lea    rax,[r12+0x5e60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_288f:
	/* 0x288f: jmp    28a3 <generic_kprobe_process_event+0x28a3> */
	goto x86_l_28a3;
x86_l_2891:
	/* 0x2891: lea    rax,[r12+0x5e68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2899:
	/* 0x2899: jmp    28a3 <generic_kprobe_process_event+0x28a3> */
	goto x86_l_28a3;
x86_l_289b:
	/* 0x289b: lea    rax,[r12+0x5e50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_28a3:
	/* 0x28a3: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a6:
	/* 0x28a6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28ab:
	/* 0x28ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28b0:
	/* 0x28b0: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_28b8:
	/* 0x28b8: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28bd:
	/* 0x28bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c2:
	/* 0x28c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c4:
	/* 0x28c4: mov    rbp,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_28cc:
	/* 0x28cc: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_28d2:
	/* 0x28d2: test   r15b,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_8, 32ULL);
x86_l_28d6:
	/* 0x28d6: je     293d <generic_kprobe_process_event+0x293d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_293d;
	}
x86_l_28d8:
	/* 0x28d8: cmp    rbp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4096ULL);
x86_l_28df:
	/* 0x28df: jb     2919 <generic_kprobe_process_event+0x2919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2919;
	}
x86_l_28e1:
	/* 0x28e1: mov    DWORD PTR [rbx],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_28e7:
	/* 0x28e7: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_28eb:
	/* 0x28eb: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_28f0:
	/* 0x28f0: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_28f3:
	/* 0x28f3: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_28f6:
	/* 0x28f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fb:
	/* 0x28fb: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_28fe:
	/* 0x28fe: call   0 <generic_kprobe_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 10499ULL);
	__x86_sim_call_depth++;
	return 13037ULL;
x86_l_2903:
	/* 0x2903: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2906:
	/* 0x2906: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_290a:
	/* 0x290a: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_290f:
	/* 0x290f: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2914:
	/* 0x2914: jmp    c01 <generic_kprobe_process_event+0xc01> */
	return 3073ULL;
x86_l_2919:
	/* 0x2919: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2920:
	/* 0x2920: mov    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2926:
	/* 0x2926: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_292b:
	/* 0x292b: lea    ebx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_292e:
	/* 0x292e: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2934:
	/* 0x2934: add    rbx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2937:
	/* 0x2937: mov    r13d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 12ULL);
x86_l_293d:
	/* 0x293d: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2944:
	/* 0x2944: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_294a:
	/* 0x294a: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_294e:
	/* 0x294e: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2952:
	/* 0x2952: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2958:
	/* 0x2958: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_295d:
	/* 0x295d: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2960:
	/* 0x2960: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2965:
	/* 0x2965: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2967:
	/* 0x2967: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2969:
	/* 0x2969: js     297c <generic_kprobe_process_event+0x297c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_297c;
	}
x86_l_296b:
	/* 0x296b: mov    DWORD PTR [rbx],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_296d:
	/* 0x296d: mov    DWORD PTR [rbx+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2971:
	/* 0x2971: add    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2974:
	/* 0x2974: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2977:
	/* 0x2977: jmp    d8c <generic_kprobe_process_event+0xd8c> */
	return 3468ULL;
x86_l_297c:
	/* 0x297c: mov    DWORD PTR [rbx],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2982:
	/* 0x2982: jmp    d8c <generic_kprobe_process_event+0xd8c> */
	return 3468ULL;
x86_l_2987:
	/* 0x2987: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_298b:
	/* 0x298b: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2992:
	/* 0x2992: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2996:
	/* 0x2996: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_299a:
	/* 0x299a: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_299e:
	/* 0x299e: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_29a3:
	/* 0x29a3: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_29a7:
	/* 0x29a7: ja     2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12220ULL;
	}
x86_l_29ad:
	/* 0x29ad: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_29b7:
	/* 0x29b7: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_29bb:
	/* 0x29bb: jae    2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12220ULL;
	}
x86_l_29c1:
	/* 0x29c1: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_29c5:
	/* 0x29c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29ca:
	/* 0x29ca: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29ce:
	/* 0x29ce: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_29d3:
	/* 0x29d3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29d6:
	/* 0x29d6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29db:
	/* 0x29db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29dd:
	/* 0x29dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29e0:
	/* 0x29e0: js     2e2d <generic_kprobe_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11821ULL;
	}
	return 10726ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10726ULL: goto x86_l_29e6;
	case 10730ULL: goto x86_l_29ea;
	case 10733ULL: goto x86_l_29ed;
	case 10735ULL: goto x86_l_29ef;
	case 10737ULL: goto x86_l_29f1;
	case 10739ULL: goto x86_l_29f3;
	case 10742ULL: goto x86_l_29f6;
	case 10744ULL: goto x86_l_29f8;
	case 10747ULL: goto x86_l_29fb;
	case 10749ULL: goto x86_l_29fd;
	case 10755ULL: goto x86_l_2a03;
	case 10759ULL: goto x86_l_2a07;
	case 10761ULL: goto x86_l_2a09;
	case 10764ULL: goto x86_l_2a0c;
	case 10766ULL: goto x86_l_2a0e;
	case 10769ULL: goto x86_l_2a11;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10778ULL: goto x86_l_2a1a;
	case 10784ULL: goto x86_l_2a20;
	case 10788ULL: goto x86_l_2a24;
	case 10790ULL: goto x86_l_2a26;
	case 10794ULL: goto x86_l_2a2a;
	case 10801ULL: goto x86_l_2a31;
	case 10805ULL: goto x86_l_2a35;
	case 10807ULL: goto x86_l_2a37;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10820ULL: goto x86_l_2a44;
	case 10827ULL: goto x86_l_2a4b;
	case 10831ULL: goto x86_l_2a4f;
	case 10833ULL: goto x86_l_2a51;
	case 10837ULL: goto x86_l_2a55;
	case 10841ULL: goto x86_l_2a59;
	case 10845ULL: goto x86_l_2a5d;
	case 10850ULL: goto x86_l_2a62;
	case 10854ULL: goto x86_l_2a66;
	case 10860ULL: goto x86_l_2a6c;
	case 10870ULL: goto x86_l_2a76;
	case 10874ULL: goto x86_l_2a7a;
	case 10880ULL: goto x86_l_2a80;
	case 10884ULL: goto x86_l_2a84;
	case 10889ULL: goto x86_l_2a89;
	case 10893ULL: goto x86_l_2a8d;
	case 10898ULL: goto x86_l_2a92;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10908ULL: goto x86_l_2a9c;
	case 10911ULL: goto x86_l_2a9f;
	case 10917ULL: goto x86_l_2aa5;
	case 10921ULL: goto x86_l_2aa9;
	case 10924ULL: goto x86_l_2aac;
	case 10926ULL: goto x86_l_2aae;
	case 10928ULL: goto x86_l_2ab0;
	case 10930ULL: goto x86_l_2ab2;
	case 10933ULL: goto x86_l_2ab5;
	case 10935ULL: goto x86_l_2ab7;
	case 10938ULL: goto x86_l_2aba;
	case 10940ULL: goto x86_l_2abc;
	case 10946ULL: goto x86_l_2ac2;
	case 10950ULL: goto x86_l_2ac6;
	case 10952ULL: goto x86_l_2ac8;
	case 10955ULL: goto x86_l_2acb;
	case 10957ULL: goto x86_l_2acd;
	case 10960ULL: goto x86_l_2ad0;
	case 10962ULL: goto x86_l_2ad2;
	case 10967ULL: goto x86_l_2ad7;
	case 10969ULL: goto x86_l_2ad9;
	case 10975ULL: goto x86_l_2adf;
	case 10979ULL: goto x86_l_2ae3;
	case 10981ULL: goto x86_l_2ae5;
	case 10985ULL: goto x86_l_2ae9;
	case 10992ULL: goto x86_l_2af0;
	case 10996ULL: goto x86_l_2af4;
	case 10998ULL: goto x86_l_2af6;
	case 11002ULL: goto x86_l_2afa;
	case 11009ULL: goto x86_l_2b01;
	case 11013ULL: goto x86_l_2b05;
	case 11015ULL: goto x86_l_2b07;
	case 11019ULL: goto x86_l_2b0b;
	case 11023ULL: goto x86_l_2b0f;
	case 11027ULL: goto x86_l_2b13;
	case 11032ULL: goto x86_l_2b18;
	case 11036ULL: goto x86_l_2b1c;
	case 11042ULL: goto x86_l_2b22;
	case 11052ULL: goto x86_l_2b2c;
	case 11056ULL: goto x86_l_2b30;
	case 11062ULL: goto x86_l_2b36;
	case 11066ULL: goto x86_l_2b3a;
	case 11071ULL: goto x86_l_2b3f;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11083ULL: goto x86_l_2b4b;
	case 11088ULL: goto x86_l_2b50;
	case 11090ULL: goto x86_l_2b52;
	case 11093ULL: goto x86_l_2b55;
	case 11099ULL: goto x86_l_2b5b;
	case 11103ULL: goto x86_l_2b5f;
	case 11106ULL: goto x86_l_2b62;
	case 11108ULL: goto x86_l_2b64;
	case 11110ULL: goto x86_l_2b66;
	case 11112ULL: goto x86_l_2b68;
	case 11115ULL: goto x86_l_2b6b;
	case 11117ULL: goto x86_l_2b6d;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11128ULL: goto x86_l_2b78;
	case 11132ULL: goto x86_l_2b7c;
	case 11134ULL: goto x86_l_2b7e;
	case 11137ULL: goto x86_l_2b81;
	case 11139ULL: goto x86_l_2b83;
	case 11142ULL: goto x86_l_2b86;
	case 11144ULL: goto x86_l_2b88;
	case 11149ULL: goto x86_l_2b8d;
	case 11151ULL: goto x86_l_2b8f;
	case 11157ULL: goto x86_l_2b95;
	case 11161ULL: goto x86_l_2b99;
	case 11163ULL: goto x86_l_2b9b;
	case 11167ULL: goto x86_l_2b9f;
	case 11174ULL: goto x86_l_2ba6;
	case 11178ULL: goto x86_l_2baa;
	case 11180ULL: goto x86_l_2bac;
	case 11184ULL: goto x86_l_2bb0;
	case 11191ULL: goto x86_l_2bb7;
	case 11195ULL: goto x86_l_2bbb;
	case 11197ULL: goto x86_l_2bbd;
	case 11201ULL: goto x86_l_2bc1;
	case 11205ULL: goto x86_l_2bc5;
	case 11209ULL: goto x86_l_2bc9;
	case 11214ULL: goto x86_l_2bce;
	case 11218ULL: goto x86_l_2bd2;
	case 11224ULL: goto x86_l_2bd8;
	case 11234ULL: goto x86_l_2be2;
	case 11238ULL: goto x86_l_2be6;
	case 11244ULL: goto x86_l_2bec;
	case 11248ULL: goto x86_l_2bf0;
	case 11253ULL: goto x86_l_2bf5;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11272ULL: goto x86_l_2c08;
	case 11275ULL: goto x86_l_2c0b;
	case 11281ULL: goto x86_l_2c11;
	case 11285ULL: goto x86_l_2c15;
	case 11288ULL: goto x86_l_2c18;
	case 11290ULL: goto x86_l_2c1a;
	case 11292ULL: goto x86_l_2c1c;
	case 11294ULL: goto x86_l_2c1e;
	case 11297ULL: goto x86_l_2c21;
	case 11299ULL: goto x86_l_2c23;
	case 11302ULL: goto x86_l_2c26;
	case 11304ULL: goto x86_l_2c28;
	case 11310ULL: goto x86_l_2c2e;
	case 11314ULL: goto x86_l_2c32;
	case 11316ULL: goto x86_l_2c34;
	case 11319ULL: goto x86_l_2c37;
	case 11321ULL: goto x86_l_2c39;
	case 11324ULL: goto x86_l_2c3c;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11333ULL: goto x86_l_2c45;
	case 11339ULL: goto x86_l_2c4b;
	case 11343ULL: goto x86_l_2c4f;
	case 11345ULL: goto x86_l_2c51;
	case 11349ULL: goto x86_l_2c55;
	case 11356ULL: goto x86_l_2c5c;
	case 11360ULL: goto x86_l_2c60;
	case 11362ULL: goto x86_l_2c62;
	case 11366ULL: goto x86_l_2c66;
	case 11373ULL: goto x86_l_2c6d;
	case 11377ULL: goto x86_l_2c71;
	case 11379ULL: goto x86_l_2c73;
	case 11383ULL: goto x86_l_2c77;
	case 11387ULL: goto x86_l_2c7b;
	case 11391ULL: goto x86_l_2c7f;
	case 11396ULL: goto x86_l_2c84;
	case 11400ULL: goto x86_l_2c88;
	case 11406ULL: goto x86_l_2c8e;
	case 11416ULL: goto x86_l_2c98;
	case 11420ULL: goto x86_l_2c9c;
	case 11426ULL: goto x86_l_2ca2;
	case 11430ULL: goto x86_l_2ca6;
	case 11435ULL: goto x86_l_2cab;
	case 11439ULL: goto x86_l_2caf;
	case 11444ULL: goto x86_l_2cb4;
	case 11447ULL: goto x86_l_2cb7;
	case 11452ULL: goto x86_l_2cbc;
	case 11454ULL: goto x86_l_2cbe;
	case 11457ULL: goto x86_l_2cc1;
	case 11463ULL: goto x86_l_2cc7;
	case 11467ULL: goto x86_l_2ccb;
	case 11470ULL: goto x86_l_2cce;
	case 11472ULL: goto x86_l_2cd0;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11479ULL: goto x86_l_2cd7;
	case 11481ULL: goto x86_l_2cd9;
	case 11484ULL: goto x86_l_2cdc;
	case 11486ULL: goto x86_l_2cde;
	case 11492ULL: goto x86_l_2ce4;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11501ULL: goto x86_l_2ced;
	case 11503ULL: goto x86_l_2cef;
	case 11506ULL: goto x86_l_2cf2;
	case 11508ULL: goto x86_l_2cf4;
	case 11513ULL: goto x86_l_2cf9;
	case 11515ULL: goto x86_l_2cfb;
	case 11521ULL: goto x86_l_2d01;
	case 11525ULL: goto x86_l_2d05;
	case 11527ULL: goto x86_l_2d07;
	case 11531ULL: goto x86_l_2d0b;
	case 11538ULL: goto x86_l_2d12;
	case 11542ULL: goto x86_l_2d16;
	case 11544ULL: goto x86_l_2d18;
	case 11548ULL: goto x86_l_2d1c;
	case 11555ULL: goto x86_l_2d23;
	case 11559ULL: goto x86_l_2d27;
	case 11561ULL: goto x86_l_2d29;
	case 11565ULL: goto x86_l_2d2d;
	case 11569ULL: goto x86_l_2d31;
	case 11573ULL: goto x86_l_2d35;
	case 11578ULL: goto x86_l_2d3a;
	case 11582ULL: goto x86_l_2d3e;
	case 11588ULL: goto x86_l_2d44;
	case 11598ULL: goto x86_l_2d4e;
	case 11602ULL: goto x86_l_2d52;
	case 11608ULL: goto x86_l_2d58;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11636ULL: goto x86_l_2d74;
	case 11639ULL: goto x86_l_2d77;
	case 11645ULL: goto x86_l_2d7d;
	case 11649ULL: goto x86_l_2d81;
	case 11652ULL: goto x86_l_2d84;
	case 11654ULL: goto x86_l_2d86;
	case 11656ULL: goto x86_l_2d88;
	case 11658ULL: goto x86_l_2d8a;
	case 11661ULL: goto x86_l_2d8d;
	case 11663ULL: goto x86_l_2d8f;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11674ULL: goto x86_l_2d9a;
	case 11678ULL: goto x86_l_2d9e;
	case 11680ULL: goto x86_l_2da0;
	case 11683ULL: goto x86_l_2da3;
	case 11685ULL: goto x86_l_2da5;
	case 11688ULL: goto x86_l_2da8;
	case 11690ULL: goto x86_l_2daa;
	case 11695ULL: goto x86_l_2daf;
	case 11697ULL: goto x86_l_2db1;
	case 11703ULL: goto x86_l_2db7;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11713ULL: goto x86_l_2dc1;
	case 11720ULL: goto x86_l_2dc8;
	case 11724ULL: goto x86_l_2dcc;
	case 11726ULL: goto x86_l_2dce;
	case 11730ULL: goto x86_l_2dd2;
	case 11737ULL: goto x86_l_2dd9;
	case 11741ULL: goto x86_l_2ddd;
	case 11743ULL: goto x86_l_2ddf;
	case 11747ULL: goto x86_l_2de3;
	case 11751ULL: goto x86_l_2de7;
	case 11755ULL: goto x86_l_2deb;
	case 11760ULL: goto x86_l_2df0;
	case 11764ULL: goto x86_l_2df4;
	case 11770ULL: goto x86_l_2dfa;
	case 11780ULL: goto x86_l_2e04;
	case 11784ULL: goto x86_l_2e08;
	case 11790ULL: goto x86_l_2e0e;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11821ULL: goto x86_l_2e2d;
	case 11824ULL: goto x86_l_2e30;
	case 11832ULL: goto x86_l_2e38;
	case 11836ULL: goto x86_l_2e3c;
	case 11841ULL: goto x86_l_2e41;
	case 11845ULL: goto x86_l_2e45;
	case 11851ULL: goto x86_l_2e4b;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11863ULL: goto x86_l_2e57;
	case 11868ULL: goto x86_l_2e5c;
	case 11870ULL: goto x86_l_2e5e;
	case 11874ULL: goto x86_l_2e62;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11891ULL: goto x86_l_2e73;
	case 11893ULL: goto x86_l_2e75;
	case 11897ULL: goto x86_l_2e79;
	case 11899ULL: goto x86_l_2e7b;
	case 11903ULL: goto x86_l_2e7f;
	case 11906ULL: goto x86_l_2e82;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11922ULL: goto x86_l_2e92;
	case 11926ULL: goto x86_l_2e96;
	case 11931ULL: goto x86_l_2e9b;
	case 11935ULL: goto x86_l_2e9f;
	case 11940ULL: goto x86_l_2ea4;
	case 11945ULL: goto x86_l_2ea9;
	case 11947ULL: goto x86_l_2eab;
	case 11951ULL: goto x86_l_2eaf;
	case 11955ULL: goto x86_l_2eb3;
	case 11959ULL: goto x86_l_2eb7;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11971ULL: goto x86_l_2ec3;
	case 11980ULL: goto x86_l_2ecc;
	case 11984ULL: goto x86_l_2ed0;
	case 11989ULL: goto x86_l_2ed5;
	case 11993ULL: goto x86_l_2ed9;
	case 11998ULL: goto x86_l_2ede;
	case 12003ULL: goto x86_l_2ee3;
	case 12005ULL: goto x86_l_2ee5;
	case 12009ULL: goto x86_l_2ee9;
	case 12013ULL: goto x86_l_2eed;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12027ULL: goto x86_l_2efb;
	case 12029ULL: goto x86_l_2efd;
	case 12031ULL: goto x86_l_2eff;
	case 12036ULL: goto x86_l_2f04;
	case 12043ULL: goto x86_l_2f0b;
	case 12048ULL: goto x86_l_2f10;
	case 12052ULL: goto x86_l_2f14;
	case 12056ULL: goto x86_l_2f18;
	case 12062ULL: goto x86_l_2f1e;
	case 12068ULL: goto x86_l_2f24;
	case 12075ULL: goto x86_l_2f2b;
	case 12080ULL: goto x86_l_2f30;
	case 12088ULL: goto x86_l_2f38;
	case 12093ULL: goto x86_l_2f3d;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12107ULL: goto x86_l_2f4b;
	case 12109ULL: goto x86_l_2f4d;
	case 12114ULL: goto x86_l_2f52;
	case 12122ULL: goto x86_l_2f5a;
	case 12126ULL: goto x86_l_2f5e;
	case 12131ULL: goto x86_l_2f63;
	case 12136ULL: goto x86_l_2f68;
	case 12138ULL: goto x86_l_2f6a;
	case 12146ULL: goto x86_l_2f72;
	case 12151ULL: goto x86_l_2f77;
	case 12155ULL: goto x86_l_2f7b;
	case 12160ULL: goto x86_l_2f80;
	case 12165ULL: goto x86_l_2f85;
	case 12170ULL: goto x86_l_2f8a;
	case 12175ULL: goto x86_l_2f8f;
	case 12177ULL: goto x86_l_2f91;
	case 12181ULL: goto x86_l_2f95;
	case 12185ULL: goto x86_l_2f99;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12197ULL: goto x86_l_2fa5;
	case 12202ULL: goto x86_l_2faa;
	case 12204ULL: goto x86_l_2fac;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12228ULL: goto x86_l_2fc4;
	case 12233ULL: goto x86_l_2fc9;
	case 12239ULL: goto x86_l_2fcf;
	case 12241ULL: goto x86_l_2fd1;
	case 12244ULL: goto x86_l_2fd4;
	case 12246ULL: goto x86_l_2fd6;
	case 12249ULL: goto x86_l_2fd9;
	case 12251ULL: goto x86_l_2fdb;
	case 12254ULL: goto x86_l_2fde;
	case 12260ULL: goto x86_l_2fe4;
	case 12263ULL: goto x86_l_2fe7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29e6:
	/* 0x29e6: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_29ea:
	/* 0x29ea: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_29ed:
	/* 0x29ed: jg     2a09 <generic_kprobe_process_event+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2a09;
	}
x86_l_29ef:
	/* 0x29ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29f1:
	/* 0x29f1: je     2a26 <generic_kprobe_process_event+0x2a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a26;
	}
x86_l_29f3:
	/* 0x29f3: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_29f6:
	/* 0x29f6: je     2a26 <generic_kprobe_process_event+0x2a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a26;
	}
x86_l_29f8:
	/* 0x29f8: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_29fb:
	/* 0x29fb: jne    2a51 <generic_kprobe_process_event+0x2a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a51;
	}
x86_l_29fd:
	/* 0x29fd: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2a03:
	/* 0x2a03: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2a07:
	/* 0x2a07: jmp    2a55 <generic_kprobe_process_event+0x2a55> */
	goto x86_l_2a55;
x86_l_2a09:
	/* 0x2a09: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2a0c:
	/* 0x2a0c: je     2a40 <generic_kprobe_process_event+0x2a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a40;
	}
x86_l_2a0e:
	/* 0x2a0e: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2a11:
	/* 0x2a11: je     2a26 <generic_kprobe_process_event+0x2a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a26;
	}
x86_l_2a13:
	/* 0x2a13: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2a18:
	/* 0x2a18: jne    2a51 <generic_kprobe_process_event+0x2a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a51;
	}
x86_l_2a1a:
	/* 0x2a1a: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2a20:
	/* 0x2a20: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2a24:
	/* 0x2a24: jmp    2a55 <generic_kprobe_process_event+0x2a55> */
	goto x86_l_2a55;
x86_l_2a26:
	/* 0x2a26: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2a2a:
	/* 0x2a2a: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2a31:
	/* 0x2a31: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2a35:
	/* 0x2a35: jmp    2a55 <generic_kprobe_process_event+0x2a55> */
	goto x86_l_2a55;
x86_l_2a37:
	/* 0x2a37: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2a3b:
	/* 0x2a3b: jmp    2996 <generic_kprobe_process_event+0x2996> */
	return 10646ULL;
x86_l_2a40:
	/* 0x2a40: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2a44:
	/* 0x2a44: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2a4b:
	/* 0x2a4b: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2a4f:
	/* 0x2a4f: jmp    2a55 <generic_kprobe_process_event+0x2a55> */
	goto x86_l_2a55;
x86_l_2a51:
	/* 0x2a51: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2a55:
	/* 0x2a55: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a59:
	/* 0x2a59: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a5d:
	/* 0x2a5d: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2a62:
	/* 0x2a62: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2a66:
	/* 0x2a66: ja     2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fbc;
	}
x86_l_2a6c:
	/* 0x2a6c: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2a76:
	/* 0x2a76: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2a7a:
	/* 0x2a7a: jae    2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fbc;
	}
x86_l_2a80:
	/* 0x2a80: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2a84:
	/* 0x2a84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a89:
	/* 0x2a89: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a8d:
	/* 0x2a8d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2a92:
	/* 0x2a92: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2a95:
	/* 0x2a95: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2a9a:
	/* 0x2a9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a9c:
	/* 0x2a9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a9f:
	/* 0x2a9f: js     2e2d <generic_kprobe_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e2d;
	}
x86_l_2aa5:
	/* 0x2aa5: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2aa9:
	/* 0x2aa9: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2aac:
	/* 0x2aac: jg     2ac8 <generic_kprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ac8;
	}
x86_l_2aae:
	/* 0x2aae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ab0:
	/* 0x2ab0: je     2ae5 <generic_kprobe_process_event+0x2ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae5;
	}
x86_l_2ab2:
	/* 0x2ab2: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2ab5:
	/* 0x2ab5: je     2ae5 <generic_kprobe_process_event+0x2ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae5;
	}
x86_l_2ab7:
	/* 0x2ab7: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2aba:
	/* 0x2aba: jne    2b07 <generic_kprobe_process_event+0x2b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b07;
	}
x86_l_2abc:
	/* 0x2abc: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2ac2:
	/* 0x2ac2: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2ac6:
	/* 0x2ac6: jmp    2b0b <generic_kprobe_process_event+0x2b0b> */
	goto x86_l_2b0b;
x86_l_2ac8:
	/* 0x2ac8: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2acb:
	/* 0x2acb: je     2af6 <generic_kprobe_process_event+0x2af6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2af6;
	}
x86_l_2acd:
	/* 0x2acd: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2ad0:
	/* 0x2ad0: je     2ae5 <generic_kprobe_process_event+0x2ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae5;
	}
x86_l_2ad2:
	/* 0x2ad2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2ad7:
	/* 0x2ad7: jne    2b07 <generic_kprobe_process_event+0x2b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b07;
	}
x86_l_2ad9:
	/* 0x2ad9: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2adf:
	/* 0x2adf: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2ae3:
	/* 0x2ae3: jmp    2b0b <generic_kprobe_process_event+0x2b0b> */
	goto x86_l_2b0b;
x86_l_2ae5:
	/* 0x2ae5: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ae9:
	/* 0x2ae9: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2af0:
	/* 0x2af0: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2af4:
	/* 0x2af4: jmp    2b0b <generic_kprobe_process_event+0x2b0b> */
	goto x86_l_2b0b;
x86_l_2af6:
	/* 0x2af6: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2afa:
	/* 0x2afa: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2b01:
	/* 0x2b01: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2b05:
	/* 0x2b05: jmp    2b0b <generic_kprobe_process_event+0x2b0b> */
	goto x86_l_2b0b;
x86_l_2b07:
	/* 0x2b07: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2b0b:
	/* 0x2b0b: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b0f:
	/* 0x2b0f: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b13:
	/* 0x2b13: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2b18:
	/* 0x2b18: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2b1c:
	/* 0x2b1c: ja     2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fbc;
	}
x86_l_2b22:
	/* 0x2b22: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2b2c:
	/* 0x2b2c: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2b30:
	/* 0x2b30: jae    2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fbc;
	}
x86_l_2b36:
	/* 0x2b36: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2b3a:
	/* 0x2b3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b3f:
	/* 0x2b3f: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b43:
	/* 0x2b43: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b48:
	/* 0x2b48: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b4b:
	/* 0x2b4b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2b50:
	/* 0x2b50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b52:
	/* 0x2b52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b55:
	/* 0x2b55: js     2e2d <generic_kprobe_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e2d;
	}
x86_l_2b5b:
	/* 0x2b5b: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2b5f:
	/* 0x2b5f: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2b62:
	/* 0x2b62: jg     2b7e <generic_kprobe_process_event+0x2b7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b7e;
	}
x86_l_2b64:
	/* 0x2b64: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b66:
	/* 0x2b66: je     2b9b <generic_kprobe_process_event+0x2b9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9b;
	}
x86_l_2b68:
	/* 0x2b68: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2b6b:
	/* 0x2b6b: je     2b9b <generic_kprobe_process_event+0x2b9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9b;
	}
x86_l_2b6d:
	/* 0x2b6d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2b70:
	/* 0x2b70: jne    2bbd <generic_kprobe_process_event+0x2bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bbd;
	}
x86_l_2b72:
	/* 0x2b72: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2b78:
	/* 0x2b78: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2b7c:
	/* 0x2b7c: jmp    2bc1 <generic_kprobe_process_event+0x2bc1> */
	goto x86_l_2bc1;
x86_l_2b7e:
	/* 0x2b7e: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2b81:
	/* 0x2b81: je     2bac <generic_kprobe_process_event+0x2bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bac;
	}
x86_l_2b83:
	/* 0x2b83: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2b86:
	/* 0x2b86: je     2b9b <generic_kprobe_process_event+0x2b9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9b;
	}
x86_l_2b88:
	/* 0x2b88: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2b8d:
	/* 0x2b8d: jne    2bbd <generic_kprobe_process_event+0x2bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bbd;
	}
x86_l_2b8f:
	/* 0x2b8f: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2b95:
	/* 0x2b95: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2b99:
	/* 0x2b99: jmp    2bc1 <generic_kprobe_process_event+0x2bc1> */
	goto x86_l_2bc1;
x86_l_2b9b:
	/* 0x2b9b: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b9f:
	/* 0x2b9f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2ba6:
	/* 0x2ba6: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2baa:
	/* 0x2baa: jmp    2bc1 <generic_kprobe_process_event+0x2bc1> */
	goto x86_l_2bc1;
x86_l_2bac:
	/* 0x2bac: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2bb0:
	/* 0x2bb0: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2bb7:
	/* 0x2bb7: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2bbb:
	/* 0x2bbb: jmp    2bc1 <generic_kprobe_process_event+0x2bc1> */
	goto x86_l_2bc1;
x86_l_2bbd:
	/* 0x2bbd: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2bc1:
	/* 0x2bc1: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bc5:
	/* 0x2bc5: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc9:
	/* 0x2bc9: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2bce:
	/* 0x2bce: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2bd2:
	/* 0x2bd2: ja     2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fbc;
	}
x86_l_2bd8:
	/* 0x2bd8: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2be2:
	/* 0x2be2: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2be6:
	/* 0x2be6: jae    2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fbc;
	}
x86_l_2bec:
	/* 0x2bec: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2bf0:
	/* 0x2bf0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bf5:
	/* 0x2bf5: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bf9:
	/* 0x2bf9: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2bfe:
	/* 0x2bfe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2c01:
	/* 0x2c01: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2c06:
	/* 0x2c06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c08:
	/* 0x2c08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c0b:
	/* 0x2c0b: js     2e2d <generic_kprobe_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e2d;
	}
x86_l_2c11:
	/* 0x2c11: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2c15:
	/* 0x2c15: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2c18:
	/* 0x2c18: jg     2c34 <generic_kprobe_process_event+0x2c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c34;
	}
x86_l_2c1a:
	/* 0x2c1a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c1c:
	/* 0x2c1c: je     2c51 <generic_kprobe_process_event+0x2c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c51;
	}
x86_l_2c1e:
	/* 0x2c1e: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2c21:
	/* 0x2c21: je     2c51 <generic_kprobe_process_event+0x2c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c51;
	}
x86_l_2c23:
	/* 0x2c23: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2c26:
	/* 0x2c26: jne    2c73 <generic_kprobe_process_event+0x2c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c73;
	}
x86_l_2c28:
	/* 0x2c28: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2c2e:
	/* 0x2c2e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2c32:
	/* 0x2c32: jmp    2c77 <generic_kprobe_process_event+0x2c77> */
	goto x86_l_2c77;
x86_l_2c34:
	/* 0x2c34: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2c37:
	/* 0x2c37: je     2c62 <generic_kprobe_process_event+0x2c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c62;
	}
x86_l_2c39:
	/* 0x2c39: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2c3c:
	/* 0x2c3c: je     2c51 <generic_kprobe_process_event+0x2c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c51;
	}
x86_l_2c3e:
	/* 0x2c3e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2c43:
	/* 0x2c43: jne    2c73 <generic_kprobe_process_event+0x2c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c73;
	}
x86_l_2c45:
	/* 0x2c45: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2c4b:
	/* 0x2c4b: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2c4f:
	/* 0x2c4f: jmp    2c77 <generic_kprobe_process_event+0x2c77> */
	goto x86_l_2c77;
x86_l_2c51:
	/* 0x2c51: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c55:
	/* 0x2c55: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c60:
	/* 0x2c60: jmp    2c77 <generic_kprobe_process_event+0x2c77> */
	goto x86_l_2c77;
x86_l_2c62:
	/* 0x2c62: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c66:
	/* 0x2c66: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c71:
	/* 0x2c71: jmp    2c77 <generic_kprobe_process_event+0x2c77> */
	goto x86_l_2c77;
x86_l_2c73:
	/* 0x2c73: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2c77:
	/* 0x2c77: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c7b:
	/* 0x2c7b: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c7f:
	/* 0x2c7f: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2c84:
	/* 0x2c84: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2c88:
	/* 0x2c88: ja     2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fbc;
	}
x86_l_2c8e:
	/* 0x2c8e: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2c98:
	/* 0x2c98: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2c9c:
	/* 0x2c9c: jae    2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fbc;
	}
x86_l_2ca2:
	/* 0x2ca2: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2ca6:
	/* 0x2ca6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cab:
	/* 0x2cab: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2caf:
	/* 0x2caf: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2cb4:
	/* 0x2cb4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2cb7:
	/* 0x2cb7: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2cbc:
	/* 0x2cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbe:
	/* 0x2cbe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cc1:
	/* 0x2cc1: js     2e2d <generic_kprobe_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e2d;
	}
x86_l_2cc7:
	/* 0x2cc7: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2ccb:
	/* 0x2ccb: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2cce:
	/* 0x2cce: jg     2cea <generic_kprobe_process_event+0x2cea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2cea;
	}
x86_l_2cd0:
	/* 0x2cd0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cd2:
	/* 0x2cd2: je     2d07 <generic_kprobe_process_event+0x2d07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d07;
	}
x86_l_2cd4:
	/* 0x2cd4: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2cd7:
	/* 0x2cd7: je     2d07 <generic_kprobe_process_event+0x2d07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d07;
	}
x86_l_2cd9:
	/* 0x2cd9: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2cdc:
	/* 0x2cdc: jne    2d29 <generic_kprobe_process_event+0x2d29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d29;
	}
x86_l_2cde:
	/* 0x2cde: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2ce4:
	/* 0x2ce4: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2ce8:
	/* 0x2ce8: jmp    2d2d <generic_kprobe_process_event+0x2d2d> */
	goto x86_l_2d2d;
x86_l_2cea:
	/* 0x2cea: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2ced:
	/* 0x2ced: je     2d18 <generic_kprobe_process_event+0x2d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d18;
	}
x86_l_2cef:
	/* 0x2cef: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2cf2:
	/* 0x2cf2: je     2d07 <generic_kprobe_process_event+0x2d07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d07;
	}
x86_l_2cf4:
	/* 0x2cf4: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2cf9:
	/* 0x2cf9: jne    2d29 <generic_kprobe_process_event+0x2d29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d29;
	}
x86_l_2cfb:
	/* 0x2cfb: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2d01:
	/* 0x2d01: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2d05:
	/* 0x2d05: jmp    2d2d <generic_kprobe_process_event+0x2d2d> */
	goto x86_l_2d2d;
x86_l_2d07:
	/* 0x2d07: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d0b:
	/* 0x2d0b: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2d12:
	/* 0x2d12: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d16:
	/* 0x2d16: jmp    2d2d <generic_kprobe_process_event+0x2d2d> */
	goto x86_l_2d2d;
x86_l_2d18:
	/* 0x2d18: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d1c:
	/* 0x2d1c: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2d23:
	/* 0x2d23: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d27:
	/* 0x2d27: jmp    2d2d <generic_kprobe_process_event+0x2d2d> */
	goto x86_l_2d2d;
x86_l_2d29:
	/* 0x2d29: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d2d:
	/* 0x2d2d: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d31:
	/* 0x2d31: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d35:
	/* 0x2d35: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2d3a:
	/* 0x2d3a: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2d3e:
	/* 0x2d3e: ja     2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fbc;
	}
x86_l_2d44:
	/* 0x2d44: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2d4e:
	/* 0x2d4e: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2d52:
	/* 0x2d52: jae    2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fbc;
	}
x86_l_2d58:
	/* 0x2d58: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d61:
	/* 0x2d61: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d65:
	/* 0x2d65: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2d6d:
	/* 0x2d6d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d72:
	/* 0x2d72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d74:
	/* 0x2d74: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d77:
	/* 0x2d77: js     2e2d <generic_kprobe_process_event+0x2e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e2d;
	}
x86_l_2d7d:
	/* 0x2d7d: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2d81:
	/* 0x2d81: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2d84:
	/* 0x2d84: jg     2da0 <generic_kprobe_process_event+0x2da0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2da0;
	}
x86_l_2d86:
	/* 0x2d86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d88:
	/* 0x2d88: je     2dbd <generic_kprobe_process_event+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dbd;
	}
x86_l_2d8a:
	/* 0x2d8a: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2d8d:
	/* 0x2d8d: je     2dbd <generic_kprobe_process_event+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dbd;
	}
x86_l_2d8f:
	/* 0x2d8f: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2d92:
	/* 0x2d92: jne    2ddf <generic_kprobe_process_event+0x2ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ddf;
	}
x86_l_2d94:
	/* 0x2d94: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2d9a:
	/* 0x2d9a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2d9e:
	/* 0x2d9e: jmp    2de3 <generic_kprobe_process_event+0x2de3> */
	goto x86_l_2de3;
x86_l_2da0:
	/* 0x2da0: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2da3:
	/* 0x2da3: je     2dce <generic_kprobe_process_event+0x2dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dce;
	}
x86_l_2da5:
	/* 0x2da5: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2da8:
	/* 0x2da8: je     2dbd <generic_kprobe_process_event+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dbd;
	}
x86_l_2daa:
	/* 0x2daa: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2daf:
	/* 0x2daf: jne    2ddf <generic_kprobe_process_event+0x2ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ddf;
	}
x86_l_2db1:
	/* 0x2db1: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2db7:
	/* 0x2db7: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2dbb:
	/* 0x2dbb: jmp    2de3 <generic_kprobe_process_event+0x2de3> */
	goto x86_l_2de3;
x86_l_2dbd:
	/* 0x2dbd: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2dc1:
	/* 0x2dc1: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2dc8:
	/* 0x2dc8: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2dcc:
	/* 0x2dcc: jmp    2de3 <generic_kprobe_process_event+0x2de3> */
	goto x86_l_2de3;
x86_l_2dce:
	/* 0x2dce: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2dd2:
	/* 0x2dd2: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ddd:
	/* 0x2ddd: jmp    2de3 <generic_kprobe_process_event+0x2de3> */
	goto x86_l_2de3;
x86_l_2ddf:
	/* 0x2ddf: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2de3:
	/* 0x2de3: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2de7:
	/* 0x2de7: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2deb:
	/* 0x2deb: movzx  r15d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2df0:
	/* 0x2df0: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2df4:
	/* 0x2df4: ja     2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fbc;
	}
x86_l_2dfa:
	/* 0x2dfa: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2e04:
	/* 0x2e04: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2e08:
	/* 0x2e08: jae    2fbc <generic_kprobe_process_event+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fbc;
	}
x86_l_2e0e:
	/* 0x2e0e: mov    BYTE PTR [rbp+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2e12:
	/* 0x2e12: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e17:
	/* 0x2e17: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e1b:
	/* 0x2e1b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e20:
	/* 0x2e20: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e23:
	/* 0x2e23: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e26:
	/* 0x2e26: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2e2b:
	/* 0x2e2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2d:
	/* 0x2e2d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e30:
	/* 0x2e30: mov    BYTE PTR [rsp+0xc4],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_2e38:
	/* 0x2e38: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e3c:
	/* 0x2e3c: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e41:
	/* 0x2e41: mov    WORD PTR [rbx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2e45:
	/* 0x2e45: mov    WORD PTR [rbx+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_2e4b:
	/* 0x2e4b: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e4f:
	/* 0x2e4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e54:
	/* 0x2e54: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e57:
	/* 0x2e57: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e5c:
	/* 0x2e5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5e:
	/* 0x2e5e: lea    rdi,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e62:
	/* 0x2e62: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2e66:
	/* 0x2e66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e6b:
	/* 0x2e6b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e70:
	/* 0x2e70: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2e73:
	/* 0x2e73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e75:
	/* 0x2e75: cmp    r15b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 17ULL);
x86_l_2e79:
	/* 0x2e79: je     2ebe <generic_kprobe_process_event+0x2ebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ebe;
	}
x86_l_2e7b:
	/* 0x2e7b: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e7f:
	/* 0x2e7f: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2e82:
	/* 0x2e82: jne    2eff <generic_kprobe_process_event+0x2eff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eff;
	}
x86_l_2e84:
	/* 0x2e84: mov    rbx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e89:
	/* 0x2e89: movzx  r15d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_2e92:
	/* 0x2e92: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2e96:
	/* 0x2e96: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9b:
	/* 0x2e9b: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e9f:
	/* 0x2e9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea4:
	/* 0x2ea4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2ea9:
	/* 0x2ea9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eab:
	/* 0x2eab: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2eaf:
	/* 0x2eaf: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2eb3:
	/* 0x2eb3: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2eb7:
	/* 0x2eb7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ebc:
	/* 0x2ebc: jmp    2ef6 <generic_kprobe_process_event+0x2ef6> */
	goto x86_l_2ef6;
x86_l_2ebe:
	/* 0x2ebe: mov    rbx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ec3:
	/* 0x2ec3: movzx  r15d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_2ecc:
	/* 0x2ecc: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed5:
	/* 0x2ed5: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ed9:
	/* 0x2ed9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ede:
	/* 0x2ede: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2ee3:
	/* 0x2ee3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee5:
	/* 0x2ee5: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2ee9:
	/* 0x2ee9: lea    rdx,[rbx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2eed:
	/* 0x2eed: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ef6:
	/* 0x2ef6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2efb:
	/* 0x2efb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2efd:
	/* 0x2efd: jmp    2f0b <generic_kprobe_process_event+0x2f0b> */
	goto x86_l_2f0b;
x86_l_2eff:
	/* 0x2eff: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f04:
	/* 0x2f04: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2f0b:
	/* 0x2f0b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f10:
	/* 0x2f10: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2f14:
	/* 0x2f14: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2f18:
	/* 0x2f18: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2f1e:
	/* 0x2f1e: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2f24:
	/* 0x2f24: add    r12,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2f2b:
	/* 0x2f2b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f30:
	/* 0x2f30: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2f38:
	/* 0x2f38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f3d:
	/* 0x2f3d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f40:
	/* 0x2f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f42:
	/* 0x2f42: cmp    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2f4b:
	/* 0x2f4b: je     2fac <generic_kprobe_process_event+0x2fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fac;
	}
x86_l_2f4d:
	/* 0x2f4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f52:
	/* 0x2f52: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2f5a:
	/* 0x2f5a: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2f5e:
	/* 0x2f5e: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f63:
	/* 0x2f63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f68:
	/* 0x2f68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f6a:
	/* 0x2f6a: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2f72:
	/* 0x2f72: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f77:
	/* 0x2f77: lea    rdx,[rbx+r15*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_2f7b:
	/* 0x2f7b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f80:
	/* 0x2f80: lea    rdi,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f85:
	/* 0x2f85: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f8a:
	/* 0x2f8a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f8f:
	/* 0x2f8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f91:
	/* 0x2f91: add    r12,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_2f95:
	/* 0x2f95: lea    rdx,[rbx+r15*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_2f99:
	/* 0x2f99: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2f9d:
	/* 0x2f9d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fa2:
	/* 0x2fa2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2fa5:
	/* 0x2fa5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2faa:
	/* 0x2faa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fac:
	/* 0x2fac: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_2fb2:
	/* 0x2fb2: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fb7:
	/* 0x2fb7: jmp    104c <generic_kprobe_process_event+0x104c> */
	return 4172ULL;
x86_l_2fbc:
	/* 0x2fbc: mov    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2fc4:
	/* 0x2fc4: jmp    2e30 <generic_kprobe_process_event+0x2e30> */
	goto x86_l_2e30;
x86_l_2fc9:
	/* 0x2fc9: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_2fcf:
	/* 0x2fcf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fd1:
	/* 0x2fd1: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2fd4:
	/* 0x2fd4: jle    300b <read_reg+0x42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12299ULL;
	}
x86_l_2fd6:
	/* 0x2fd6: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2fd9:
	/* 0x2fd9: jle    302f <read_reg+0x66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12335ULL;
	}
x86_l_2fdb:
	/* 0x2fdb: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2fde:
	/* 0x2fde: jle    3094 <read_reg+0xcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12436ULL;
	}
x86_l_2fe4:
	/* 0x2fe4: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_2fe7:
	/* 0x2fe7: je     30c8 <read_reg+0xff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12488ULL;
	}
	return 12269ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12269ULL: goto x86_l_2fed;
	case 12272ULL: goto x86_l_2ff0;
	case 12278ULL: goto x86_l_2ff6;
	case 12281ULL: goto x86_l_2ff9;
	case 12287ULL: goto x86_l_2fff;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12302ULL: goto x86_l_300e;
	case 12304ULL: goto x86_l_3010;
	case 12307ULL: goto x86_l_3013;
	case 12309ULL: goto x86_l_3015;
	case 12311ULL: goto x86_l_3017;
	case 12317ULL: goto x86_l_301d;
	case 12320ULL: goto x86_l_3020;
	case 12326ULL: goto x86_l_3026;
	case 12330ULL: goto x86_l_302a;
	case 12335ULL: goto x86_l_302f;
	case 12338ULL: goto x86_l_3032;
	case 12340ULL: goto x86_l_3034;
	case 12343ULL: goto x86_l_3037;
	case 12345ULL: goto x86_l_3039;
	case 12348ULL: goto x86_l_303c;
	case 12354ULL: goto x86_l_3042;
	case 12358ULL: goto x86_l_3046;
	case 12363ULL: goto x86_l_304b;
	case 12366ULL: goto x86_l_304e;
	case 12368ULL: goto x86_l_3050;
	case 12371ULL: goto x86_l_3053;
	case 12373ULL: goto x86_l_3055;
	case 12376ULL: goto x86_l_3058;
	case 12382ULL: goto x86_l_305e;
	case 12386ULL: goto x86_l_3062;
	case 12388ULL: goto x86_l_3064;
	case 12391ULL: goto x86_l_3067;
	case 12393ULL: goto x86_l_3069;
	case 12396ULL: goto x86_l_306c;
	case 12398ULL: goto x86_l_306e;
	case 12402ULL: goto x86_l_3072;
	case 12404ULL: goto x86_l_3074;
	case 12407ULL: goto x86_l_3077;
	case 12409ULL: goto x86_l_3079;
	case 12412ULL: goto x86_l_307c;
	case 12414ULL: goto x86_l_307e;
	case 12418ULL: goto x86_l_3082;
	case 12420ULL: goto x86_l_3084;
	case 12423ULL: goto x86_l_3087;
	case 12425ULL: goto x86_l_3089;
	case 12428ULL: goto x86_l_308c;
	case 12430ULL: goto x86_l_308e;
	case 12434ULL: goto x86_l_3092;
	case 12436ULL: goto x86_l_3094;
	case 12439ULL: goto x86_l_3097;
	case 12441ULL: goto x86_l_3099;
	case 12444ULL: goto x86_l_309c;
	case 12446ULL: goto x86_l_309e;
	case 12450ULL: goto x86_l_30a2;
	case 12452ULL: goto x86_l_30a4;
	case 12456ULL: goto x86_l_30a8;
	case 12458ULL: goto x86_l_30aa;
	case 12462ULL: goto x86_l_30ae;
	case 12464ULL: goto x86_l_30b0;
	case 12468ULL: goto x86_l_30b4;
	case 12470ULL: goto x86_l_30b6;
	case 12474ULL: goto x86_l_30ba;
	case 12476ULL: goto x86_l_30bc;
	case 12480ULL: goto x86_l_30c0;
	case 12482ULL: goto x86_l_30c2;
	case 12486ULL: goto x86_l_30c6;
	case 12488ULL: goto x86_l_30c8;
	case 12492ULL: goto x86_l_30cc;
	case 12494ULL: goto x86_l_30ce;
	case 12498ULL: goto x86_l_30d2;
	case 12503ULL: goto x86_l_30d7;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12511ULL: goto x86_l_30df;
	case 12516ULL: goto x86_l_30e4;
	case 12519ULL: goto x86_l_30e7;
	case 12521ULL: goto x86_l_30e9;
	case 12523ULL: goto x86_l_30eb;
	case 12524ULL: goto x86_l_30ec;
	case 12525ULL: goto x86_l_30ed;
	case 12528ULL: goto x86_l_30f0;
	case 12530ULL: goto x86_l_30f2;
	case 12536ULL: goto x86_l_30f8;
	case 12538ULL: goto x86_l_30fa;
	case 12542ULL: goto x86_l_30fe;
	case 12546ULL: goto x86_l_3102;
	case 12549ULL: goto x86_l_3105;
	case 12551ULL: goto x86_l_3107;
	case 12557ULL: goto x86_l_310d;
	case 12559ULL: goto x86_l_310f;
	case 12561ULL: goto x86_l_3111;
	case 12565ULL: goto x86_l_3115;
	case 12567ULL: goto x86_l_3117;
	case 12572ULL: goto x86_l_311c;
	case 12574ULL: goto x86_l_311e;
	case 12579ULL: goto x86_l_3123;
	case 12582ULL: goto x86_l_3126;
	case 12586ULL: goto x86_l_312a;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12596ULL: goto x86_l_3134;
	case 12598ULL: goto x86_l_3136;
	case 12603ULL: goto x86_l_313b;
	case 12605ULL: goto x86_l_313d;
	case 12607ULL: goto x86_l_313f;
	case 12611ULL: goto x86_l_3143;
	case 12613ULL: goto x86_l_3145;
	case 12618ULL: goto x86_l_314a;
	case 12622ULL: goto x86_l_314e;
	case 12623ULL: goto x86_l_314f;
	case 12625ULL: goto x86_l_3151;
	case 12626ULL: goto x86_l_3152;
	case 12628ULL: goto x86_l_3154;
	case 12630ULL: goto x86_l_3156;
	case 12632ULL: goto x86_l_3158;
	case 12633ULL: goto x86_l_3159;
	case 12637ULL: goto x86_l_315d;
	case 12640ULL: goto x86_l_3160;
	case 12644ULL: goto x86_l_3164;
	case 12648ULL: goto x86_l_3168;
	case 12652ULL: goto x86_l_316c;
	case 12655ULL: goto x86_l_316f;
	case 12657ULL: goto x86_l_3171;
	case 12661ULL: goto x86_l_3175;
	case 12667ULL: goto x86_l_317b;
	case 12672ULL: goto x86_l_3180;
	case 12677ULL: goto x86_l_3185;
	case 12682ULL: goto x86_l_318a;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12695ULL: goto x86_l_3197;
	case 12699ULL: goto x86_l_319b;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12714ULL: goto x86_l_31aa;
	case 12717ULL: goto x86_l_31ad;
	case 12719ULL: goto x86_l_31af;
	case 12724ULL: goto x86_l_31b4;
	case 12730ULL: goto x86_l_31ba;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12745ULL: goto x86_l_31c9;
	case 12748ULL: goto x86_l_31cc;
	case 12750ULL: goto x86_l_31ce;
	case 12754ULL: goto x86_l_31d2;
	case 12759ULL: goto x86_l_31d7;
	case 12764ULL: goto x86_l_31dc;
	case 12769ULL: goto x86_l_31e1;
	case 12772ULL: goto x86_l_31e4;
	case 12774ULL: goto x86_l_31e6;
	case 12778ULL: goto x86_l_31ea;
	case 12782ULL: goto x86_l_31ee;
	case 12786ULL: goto x86_l_31f2;
	case 12789ULL: goto x86_l_31f5;
	case 12792ULL: goto x86_l_31f8;
	case 12794ULL: goto x86_l_31fa;
	case 12796ULL: goto x86_l_31fc;
	case 12798ULL: goto x86_l_31fe;
	case 12801ULL: goto x86_l_3201;
	case 12806ULL: goto x86_l_3206;
	case 12809ULL: goto x86_l_3209;
	case 12811ULL: goto x86_l_320b;
	case 12815ULL: goto x86_l_320f;
	case 12818ULL: goto x86_l_3212;
	case 12822ULL: goto x86_l_3216;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12830ULL: goto x86_l_321e;
	case 12833ULL: goto x86_l_3221;
	case 12838ULL: goto x86_l_3226;
	case 12841ULL: goto x86_l_3229;
	case 12847ULL: goto x86_l_322f;
	case 12854ULL: goto x86_l_3236;
	case 12860ULL: goto x86_l_323c;
	case 12862ULL: goto x86_l_323e;
	case 12868ULL: goto x86_l_3244;
	case 12872ULL: goto x86_l_3248;
	case 12877ULL: goto x86_l_324d;
	case 12881ULL: goto x86_l_3251;
	case 12885ULL: goto x86_l_3255;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12895ULL: goto x86_l_325f;
	case 12899ULL: goto x86_l_3263;
	case 12904ULL: goto x86_l_3268;
	case 12908ULL: goto x86_l_326c;
	case 12910ULL: goto x86_l_326e;
	case 12912ULL: goto x86_l_3270;
	case 12916ULL: goto x86_l_3274;
	case 12921ULL: goto x86_l_3279;
	case 12926ULL: goto x86_l_327e;
	case 12931ULL: goto x86_l_3283;
	case 12933ULL: goto x86_l_3285;
	case 12937ULL: goto x86_l_3289;
	case 12942ULL: goto x86_l_328e;
	case 12944ULL: goto x86_l_3290;
	case 12948ULL: goto x86_l_3294;
	case 12952ULL: goto x86_l_3298;
	case 12957ULL: goto x86_l_329d;
	case 12962ULL: goto x86_l_32a2;
	case 12965ULL: goto x86_l_32a5;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12976ULL: goto x86_l_32b0;
	case 12980ULL: goto x86_l_32b4;
	case 12984ULL: goto x86_l_32b8;
	case 12986ULL: goto x86_l_32ba;
	case 12988ULL: goto x86_l_32bc;
	case 12992ULL: goto x86_l_32c0;
	case 12997ULL: goto x86_l_32c5;
	case 13001ULL: goto x86_l_32c9;
	case 13002ULL: goto x86_l_32ca;
	case 13004ULL: goto x86_l_32cc;
	case 13006ULL: goto x86_l_32ce;
	case 13008ULL: goto x86_l_32d0;
	case 13009ULL: goto x86_l_32d1;
	case 13013ULL: goto x86_l_32d5;
	case 13016ULL: goto x86_l_32d8;
	case 13021ULL: goto x86_l_32dd;
	case 13024ULL: goto x86_l_32e0;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13035ULL: goto x86_l_32eb;
	case 13037ULL: goto x86_l_32ed;
	case 13038ULL: goto x86_l_32ee;
	case 13040ULL: goto x86_l_32f0;
	case 13042ULL: goto x86_l_32f2;
	case 13044ULL: goto x86_l_32f4;
	case 13046ULL: goto x86_l_32f6;
	case 13047ULL: goto x86_l_32f7;
	case 13048ULL: goto x86_l_32f8;
	case 13051ULL: goto x86_l_32fb;
	case 13054ULL: goto x86_l_32fe;
	case 13057ULL: goto x86_l_3301;
	case 13060ULL: goto x86_l_3304;
	case 13068ULL: goto x86_l_330c;
	case 13073ULL: goto x86_l_3311;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13087ULL: goto x86_l_331f;
	case 13090ULL: goto x86_l_3322;
	case 13092ULL: goto x86_l_3324;
	case 13095ULL: goto x86_l_3327;
	case 13101ULL: goto x86_l_332d;
	case 13106ULL: goto x86_l_3332;
	case 13108ULL: goto x86_l_3334;
	case 13111ULL: goto x86_l_3337;
	case 13115ULL: goto x86_l_333b;
	case 13119ULL: goto x86_l_333f;
	case 13123ULL: goto x86_l_3343;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13134ULL: goto x86_l_334e;
	case 13139ULL: goto x86_l_3353;
	case 13141ULL: goto x86_l_3355;
	case 13145ULL: goto x86_l_3359;
	case 13149ULL: goto x86_l_335d;
	case 13153ULL: goto x86_l_3361;
	case 13157ULL: goto x86_l_3365;
	case 13161ULL: goto x86_l_3369;
	case 13164ULL: goto x86_l_336c;
	case 13167ULL: goto x86_l_336f;
	case 13170ULL: goto x86_l_3372;
	case 13173ULL: goto x86_l_3375;
	case 13178ULL: goto x86_l_337a;
	case 13180ULL: goto x86_l_337c;
	case 13182ULL: goto x86_l_337e;
	case 13189ULL: goto x86_l_3385;
	case 13192ULL: goto x86_l_3388;
	case 13194ULL: goto x86_l_338a;
	case 13196ULL: goto x86_l_338c;
	case 13200ULL: goto x86_l_3390;
	case 13203ULL: goto x86_l_3393;
	case 13205ULL: goto x86_l_3395;
	case 13207ULL: goto x86_l_3397;
	case 13209ULL: goto x86_l_3399;
	case 13211ULL: goto x86_l_339b;
	case 13218ULL: goto x86_l_33a2;
	case 13220ULL: goto x86_l_33a4;
	case 13222ULL: goto x86_l_33a6;
	case 13225ULL: goto x86_l_33a9;
	case 13228ULL: goto x86_l_33ac;
	case 13233ULL: goto x86_l_33b1;
	case 13237ULL: goto x86_l_33b5;
	case 13238ULL: goto x86_l_33b6;
	case 13240ULL: goto x86_l_33b8;
	case 13242ULL: goto x86_l_33ba;
	case 13244ULL: goto x86_l_33bc;
	case 13246ULL: goto x86_l_33be;
	case 13247ULL: goto x86_l_33bf;
	case 13248ULL: goto x86_l_33c0;
	case 13249ULL: goto x86_l_33c1;
	case 13251ULL: goto x86_l_33c3;
	case 13253ULL: goto x86_l_33c5;
	case 13255ULL: goto x86_l_33c7;
	case 13257ULL: goto x86_l_33c9;
	case 13258ULL: goto x86_l_33ca;
	case 13259ULL: goto x86_l_33cb;
	case 13262ULL: goto x86_l_33ce;
	case 13265ULL: goto x86_l_33d1;
	case 13268ULL: goto x86_l_33d4;
	case 13271ULL: goto x86_l_33d7;
	case 13276ULL: goto x86_l_33dc;
	case 13278ULL: goto x86_l_33de;
	case 13284ULL: goto x86_l_33e4;
	case 13287ULL: goto x86_l_33e7;
	case 13294ULL: goto x86_l_33ee;
	case 13297ULL: goto x86_l_33f1;
	case 13300ULL: goto x86_l_33f4;
	case 13306ULL: goto x86_l_33fa;
	case 13310ULL: goto x86_l_33fe;
	case 13313ULL: goto x86_l_3401;
	case 13316ULL: goto x86_l_3404;
	case 13321ULL: goto x86_l_3409;
	case 13323ULL: goto x86_l_340b;
	case 13329ULL: goto x86_l_3411;
	case 13334ULL: goto x86_l_3416;
	case 13337ULL: goto x86_l_3419;
	case 13340ULL: goto x86_l_341c;
	case 13343ULL: goto x86_l_341f;
	case 13346ULL: goto x86_l_3422;
	case 13352ULL: goto x86_l_3428;
	case 13356ULL: goto x86_l_342c;
	case 13359ULL: goto x86_l_342f;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13369ULL: goto x86_l_3439;
	case 13375ULL: goto x86_l_343f;
	case 13380ULL: goto x86_l_3444;
	case 13383ULL: goto x86_l_3447;
	case 13386ULL: goto x86_l_344a;
	case 13389ULL: goto x86_l_344d;
	case 13392ULL: goto x86_l_3450;
	case 13398ULL: goto x86_l_3456;
	case 13402ULL: goto x86_l_345a;
	case 13405ULL: goto x86_l_345d;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13415ULL: goto x86_l_3467;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13429ULL: goto x86_l_3475;
	case 13432ULL: goto x86_l_3478;
	case 13435ULL: goto x86_l_347b;
	case 13438ULL: goto x86_l_347e;
	case 13444ULL: goto x86_l_3484;
	case 13448ULL: goto x86_l_3488;
	case 13451ULL: goto x86_l_348b;
	case 13454ULL: goto x86_l_348e;
	case 13459ULL: goto x86_l_3493;
	case 13461ULL: goto x86_l_3495;
	case 13467ULL: goto x86_l_349b;
	case 13472ULL: goto x86_l_34a0;
	case 13475ULL: goto x86_l_34a3;
	case 13478ULL: goto x86_l_34a6;
	case 13481ULL: goto x86_l_34a9;
	case 13484ULL: goto x86_l_34ac;
	case 13490ULL: goto x86_l_34b2;
	case 13494ULL: goto x86_l_34b6;
	case 13497ULL: goto x86_l_34b9;
	case 13500ULL: goto x86_l_34bc;
	case 13505ULL: goto x86_l_34c1;
	case 13507ULL: goto x86_l_34c3;
	case 13513ULL: goto x86_l_34c9;
	case 13518ULL: goto x86_l_34ce;
	case 13521ULL: goto x86_l_34d1;
	case 13524ULL: goto x86_l_34d4;
	case 13527ULL: goto x86_l_34d7;
	case 13530ULL: goto x86_l_34da;
	case 13536ULL: goto x86_l_34e0;
	case 13540ULL: goto x86_l_34e4;
	case 13543ULL: goto x86_l_34e7;
	case 13546ULL: goto x86_l_34ea;
	case 13551ULL: goto x86_l_34ef;
	case 13553ULL: goto x86_l_34f1;
	case 13559ULL: goto x86_l_34f7;
	case 13564ULL: goto x86_l_34fc;
	case 13567ULL: goto x86_l_34ff;
	case 13570ULL: goto x86_l_3502;
	case 13573ULL: goto x86_l_3505;
	case 13576ULL: goto x86_l_3508;
	case 13582ULL: goto x86_l_350e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2fed:
	/* 0x2fed: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2ff0:
	/* 0x2ff0: je     30b0 <read_reg+0xe7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30b0;
	}
x86_l_2ff6:
	/* 0x2ff6: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_2ff9:
	/* 0x2ff9: jne    30de <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30de;
	}
x86_l_2fff:
	/* 0x2fff: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_3006:
	/* 0x3006: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_300b:
	/* 0x300b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_300e:
	/* 0x300e: jg     304b <read_reg+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_304b;
	}
x86_l_3010:
	/* 0x3010: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3013:
	/* 0x3013: jg     3074 <read_reg+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3074;
	}
x86_l_3015:
	/* 0x3015: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3017:
	/* 0x3017: je     30d2 <read_reg+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30d2;
	}
x86_l_301d:
	/* 0x301d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3020:
	/* 0x3020: jne    30de <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30de;
	}
x86_l_3026:
	/* 0x3026: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_302a:
	/* 0x302a: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_302f:
	/* 0x302f: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_3032:
	/* 0x3032: jg     3064 <read_reg+0x9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3064;
	}
x86_l_3034:
	/* 0x3034: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3037:
	/* 0x3037: je     30a4 <read_reg+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30a4;
	}
x86_l_3039:
	/* 0x3039: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_303c:
	/* 0x303c: jne    30de <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30de;
	}
x86_l_3042:
	/* 0x3042: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_3046:
	/* 0x3046: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_304b:
	/* 0x304b: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_304e:
	/* 0x304e: jg     3084 <read_reg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3084;
	}
x86_l_3050:
	/* 0x3050: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3053:
	/* 0x3053: je     30b6 <read_reg+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30b6;
	}
x86_l_3055:
	/* 0x3055: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_3058:
	/* 0x3058: jne    30de <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30de;
	}
x86_l_305e:
	/* 0x305e: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3062:
	/* 0x3062: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_3064:
	/* 0x3064: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_3067:
	/* 0x3067: je     30aa <read_reg+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30aa;
	}
x86_l_3069:
	/* 0x3069: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_306c:
	/* 0x306c: jne    30de <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30de;
	}
x86_l_306e:
	/* 0x306e: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_3072:
	/* 0x3072: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_3074:
	/* 0x3074: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3077:
	/* 0x3077: je     30bc <read_reg+0xf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30bc;
	}
x86_l_3079:
	/* 0x3079: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_307c:
	/* 0x307c: jne    30de <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30de;
	}
x86_l_307e:
	/* 0x307e: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3082:
	/* 0x3082: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_3084:
	/* 0x3084: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3087:
	/* 0x3087: je     30c2 <read_reg+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30c2;
	}
x86_l_3089:
	/* 0x3089: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_308c:
	/* 0x308c: jne    30de <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30de;
	}
x86_l_308e:
	/* 0x308e: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3092:
	/* 0x3092: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_3094:
	/* 0x3094: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3097:
	/* 0x3097: je     30ce <read_reg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30ce;
	}
x86_l_3099:
	/* 0x3099: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_309c:
	/* 0x309c: jne    30de <read_reg+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30de;
	}
x86_l_309e:
	/* 0x309e: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_30a2:
	/* 0x30a2: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_30a4:
	/* 0x30a4: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_30a8:
	/* 0x30a8: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_30aa:
	/* 0x30aa: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_30ae:
	/* 0x30ae: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_30b0:
	/* 0x30b0: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_30b4:
	/* 0x30b4: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_30b6:
	/* 0x30b6: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_30ba:
	/* 0x30ba: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_30bc:
	/* 0x30bc: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30c0:
	/* 0x30c0: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_30c2:
	/* 0x30c2: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_30c6:
	/* 0x30c6: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_30c8:
	/* 0x30c8: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_30cc:
	/* 0x30cc: jmp    30d2 <read_reg+0x109> */
	goto x86_l_30d2;
x86_l_30ce:
	/* 0x30ce: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_30d2:
	/* 0x30d2: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_30d7:
	/* 0x30d7: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30d9:
	/* 0x30d9: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_30de:
	/* 0x30de: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_30df:
	/* 0x30df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e4:
	/* 0x30e4: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_30e7:
	/* 0x30e7: ja     3151 <extract_arg_depth+0x72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3151;
	}
x86_l_30e9:
	/* 0x30e9: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_30eb:
	/* 0x30eb: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_30ec:
	/* 0x30ec: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_30ed:
	/* 0x30ed: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f0:
	/* 0x30f0: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_30f2:
	/* 0x30f2: cmp    WORD PTR [rcx+rdx*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 3), 25769803776ULL);
x86_l_30f8:
	/* 0x30f8: je     314a <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314a;
	}
x86_l_30fa:
	/* 0x30fa: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30fe:
	/* 0x30fe: mov    r8d,DWORD PTR [rcx+rdx*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_3102:
	/* 0x3102: add    QWORD PTR [rax],r8 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R8, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3105:
	/* 0x3105: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3107:
	/* 0x3107: cmp    WORD PTR [rcx+rdx*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 3), 17179869184ULL);
x86_l_310d:
	/* 0x310d: je     314a <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314a;
	}
x86_l_310f:
	/* 0x310f: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_3111:
	/* 0x3111: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3115:
	/* 0x3115: je     311e <extract_arg_depth+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_311e;
	}
x86_l_3117:
	/* 0x3117: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_311c:
	/* 0x311c: jmp    3123 <extract_arg_depth+0x44> */
	goto x86_l_3123;
x86_l_311e:
	/* 0x311e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3123:
	/* 0x3123: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_3126:
	/* 0x3126: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_312a:
	/* 0x312a: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_312d:
	/* 0x312d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3132:
	/* 0x3132: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3134:
	/* 0x3134: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3136:
	/* 0x3136: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_313b:
	/* 0x313b: jns    314a <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_314a;
	}
x86_l_313d:
	/* 0x313d: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_313f:
	/* 0x313f: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3143:
	/* 0x3143: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3145:
	/* 0x3145: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314a:
	/* 0x314a: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_314e:
	/* 0x314e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_314f:
	/* 0x314f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3151:
	/* 0x3151: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3152:
	/* 0x3152: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3154:
	/* 0x3154: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3156:
	/* 0x3156: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3158:
	/* 0x3158: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3159:
	/* 0x3159: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_315d:
	/* 0x315d: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_3160:
	/* 0x3160: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3164:
	/* 0x3164: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3168:
	/* 0x3168: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_316c:
	/* 0x316c: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_316f:
	/* 0x316f: jne    317b <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_317b;
	}
x86_l_3171:
	/* 0x3171: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3175:
	/* 0x3175: je     32bc <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32bc;
	}
x86_l_317b:
	/* 0x317b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3180:
	/* 0x3180: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3185:
	/* 0x3185: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_318a:
	/* 0x318a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_318c:
	/* 0x318c: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3191:
	/* 0x3191: je     3270 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3270;
	}
x86_l_3197:
	/* 0x3197: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_319b:
	/* 0x319b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31a0:
	/* 0x31a0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31a5:
	/* 0x31a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31aa:
	/* 0x31aa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31ad:
	/* 0x31ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31af:
	/* 0x31af: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31b4:
	/* 0x31b4: je     3270 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3270;
	}
x86_l_31ba:
	/* 0x31ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31bf:
	/* 0x31bf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31c4:
	/* 0x31c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31c9:
	/* 0x31c9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31cc:
	/* 0x31cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ce:
	/* 0x31ce: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_31d2:
	/* 0x31d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31d7:
	/* 0x31d7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31dc:
	/* 0x31dc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31e1:
	/* 0x31e1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31e4:
	/* 0x31e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e6:
	/* 0x31e6: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ea:
	/* 0x31ea: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31ee:
	/* 0x31ee: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_31f2:
	/* 0x31f2: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_31f5:
	/* 0x31f5: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_31f8:
	/* 0x31f8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31fa:
	/* 0x31fa: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_31fc:
	/* 0x31fc: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31fe:
	/* 0x31fe: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_3201:
	/* 0x3201: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3206:
	/* 0x3206: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3209:
	/* 0x3209: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_320b:
	/* 0x320b: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_320f:
	/* 0x320f: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_3212:
	/* 0x3212: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_3216:
	/* 0x3216: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3219:
	/* 0x3219: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_321b:
	/* 0x321b: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_321e:
	/* 0x321e: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3221:
	/* 0x3221: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3226:
	/* 0x3226: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3229:
	/* 0x3229: jb     32c5 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32c5;
	}
x86_l_322f:
	/* 0x322f: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_3236:
	/* 0x3236: ja     32c5 <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32c5;
	}
x86_l_323c:
	/* 0x323c: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_323e:
	/* 0x323e: jbe    32d1 <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_32d1;
	}
x86_l_3244:
	/* 0x3244: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3248:
	/* 0x3248: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_324d:
	/* 0x324d: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3251:
	/* 0x3251: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3255:
	/* 0x3255: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3258:
	/* 0x3258: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_325d:
	/* 0x325d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325f:
	/* 0x325f: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3263:
	/* 0x3263: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3268:
	/* 0x3268: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_326c:
	/* 0x326c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_326e:
	/* 0x326e: jmp    32c5 <cwd_read_v61+0x173> */
	goto x86_l_32c5;
x86_l_3270:
	/* 0x3270: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3274:
	/* 0x3274: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3279:
	/* 0x3279: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_327e:
	/* 0x327e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3283:
	/* 0x3283: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3285:
	/* 0x3285: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3289:
	/* 0x3289: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_328e:
	/* 0x328e: je     32bc <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32bc;
	}
x86_l_3290:
	/* 0x3290: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3294:
	/* 0x3294: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3298:
	/* 0x3298: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_329d:
	/* 0x329d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a2:
	/* 0x32a2: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_32a5:
	/* 0x32a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a7:
	/* 0x32a7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32ac:
	/* 0x32ac: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32b0:
	/* 0x32b0: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_32b4:
	/* 0x32b4: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32b8:
	/* 0x32b8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32ba:
	/* 0x32ba: jmp    32c5 <cwd_read_v61+0x173> */
	goto x86_l_32c5;
x86_l_32bc:
	/* 0x32bc: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_32c0:
	/* 0x32c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32c5:
	/* 0x32c5: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_32c9:
	/* 0x32c9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_32ca:
	/* 0x32ca: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_32cc:
	/* 0x32cc: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_32ce:
	/* 0x32ce: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_32d0:
	/* 0x32d0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_32d1:
	/* 0x32d1: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32d5:
	/* 0x32d5: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32d8:
	/* 0x32d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32dd:
	/* 0x32dd: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_32e0:
	/* 0x32e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e2:
	/* 0x32e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32e7:
	/* 0x32e7: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32eb:
	/* 0x32eb: jmp    32c5 <cwd_read_v61+0x173> */
	goto x86_l_32c5;
x86_l_32ed:
	/* 0x32ed: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_32ee:
	/* 0x32ee: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_32f0:
	/* 0x32f0: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_32f2:
	/* 0x32f2: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_32f4:
	/* 0x32f4: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_32f6:
	/* 0x32f6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_32f7:
	/* 0x32f7: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_32f8:
	/* 0x32f8: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_32fb:
	/* 0x32fb: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_32fe:
	/* 0x32fe: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_3301:
	/* 0x3301: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_3304:
	/* 0x3304: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_330c:
	/* 0x330c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3311:
	/* 0x3311: mov    rdi,QWORD PTR [rip+0x340] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_3318:
	/* 0x3318: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_331d:
	/* 0x331d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331f:
	/* 0x331f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3322:
	/* 0x3322: je     3395 <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3395;
	}
x86_l_3324:
	/* 0x3324: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3327:
	/* 0x3327: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_332d:
	/* 0x332d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3332:
	/* 0x3332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3334:
	/* 0x3334: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_3337:
	/* 0x3337: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_333b:
	/* 0x333b: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_333f:
	/* 0x333f: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_3343:
	/* 0x3343: jne    334e <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_334e;
	}
x86_l_3345:
	/* 0x3345: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_334a:
	/* 0x334a: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_334e:
	/* 0x334e: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_3353:
	/* 0x3353: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3355:
	/* 0x3355: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3359:
	/* 0x3359: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_335d:
	/* 0x335d: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3361:
	/* 0x3361: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3365:
	/* 0x3365: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3369:
	/* 0x3369: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_336c:
	/* 0x336c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_336f:
	/* 0x336f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3372:
	/* 0x3372: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3375:
	/* 0x3375: call   33c0 <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13178ULL);
	__x86_sim_call_depth++;
	goto x86_l_33c0;
x86_l_337a:
	/* 0x337a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_337c:
	/* 0x337c: js     3399 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3399;
	}
x86_l_337e:
	/* 0x337e: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3385:
	/* 0x3385: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_3388:
	/* 0x3388: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_338a:
	/* 0x338a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_338c:
	/* 0x338c: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3390:
	/* 0x3390: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_3393:
	/* 0x3393: jmp    33a6 <data_event_bytes+0xb9> */
	goto x86_l_33a6;
x86_l_3395:
	/* 0x3395: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3397:
	/* 0x3397: jmp    33b1 <data_event_bytes+0xc4> */
	goto x86_l_33b1;
x86_l_3399:
	/* 0x3399: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_339b:
	/* 0x339b: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_33a2:
	/* 0x33a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33a4:
	/* 0x33a4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33a6:
	/* 0x33a6: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33a9:
	/* 0x33a9: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_33ac:
	/* 0x33ac: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_33b1:
	/* 0x33b1: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33b5:
	/* 0x33b5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_33b6:
	/* 0x33b6: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_33b8:
	/* 0x33b8: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_33ba:
	/* 0x33ba: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_33bc:
	/* 0x33bc: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_33be:
	/* 0x33be: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_33bf:
	/* 0x33bf: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_33c0:
	/* 0x33c0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_33c1:
	/* 0x33c1: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_33c3:
	/* 0x33c3: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_33c5:
	/* 0x33c5: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_33c7:
	/* 0x33c7: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_33c9:
	/* 0x33c9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_33ca:
	/* 0x33ca: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_33cb:
	/* 0x33cb: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_33ce:
	/* 0x33ce: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_33d1:
	/* 0x33d1: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_33d4:
	/* 0x33d4: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_33d7:
	/* 0x33d7: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13276ULL);
	__x86_sim_call_depth++;
	return 13856ULL;
x86_l_33dc:
	/* 0x33dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33de:
	/* 0x33de: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13703ULL;
	}
x86_l_33e4:
	/* 0x33e4: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_33e7:
	/* 0x33e7: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_33ee:
	/* 0x33ee: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_33f1:
	/* 0x33f1: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_33f4:
	/* 0x33f4: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13838ULL;
	}
x86_l_33fa:
	/* 0x33fa: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_33fe:
	/* 0x33fe: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3401:
	/* 0x3401: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3404:
	/* 0x3404: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13321ULL);
	__x86_sim_call_depth++;
	return 13856ULL;
x86_l_3409:
	/* 0x3409: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_340b:
	/* 0x340b: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13703ULL;
	}
x86_l_3411:
	/* 0x3411: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3416:
	/* 0x3416: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3419:
	/* 0x3419: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_341c:
	/* 0x341c: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_341f:
	/* 0x341f: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3422:
	/* 0x3422: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13838ULL;
	}
x86_l_3428:
	/* 0x3428: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_342c:
	/* 0x342c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_342f:
	/* 0x342f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3432:
	/* 0x3432: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13367ULL);
	__x86_sim_call_depth++;
	return 13856ULL;
x86_l_3437:
	/* 0x3437: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3439:
	/* 0x3439: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13703ULL;
	}
x86_l_343f:
	/* 0x343f: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3444:
	/* 0x3444: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3447:
	/* 0x3447: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_344a:
	/* 0x344a: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_344d:
	/* 0x344d: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3450:
	/* 0x3450: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13838ULL;
	}
x86_l_3456:
	/* 0x3456: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_345a:
	/* 0x345a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_345d:
	/* 0x345d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3460:
	/* 0x3460: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13413ULL);
	__x86_sim_call_depth++;
	return 13856ULL;
x86_l_3465:
	/* 0x3465: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3467:
	/* 0x3467: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13703ULL;
	}
x86_l_346d:
	/* 0x346d: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3472:
	/* 0x3472: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3475:
	/* 0x3475: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3478:
	/* 0x3478: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_347b:
	/* 0x347b: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_347e:
	/* 0x347e: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13838ULL;
	}
x86_l_3484:
	/* 0x3484: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3488:
	/* 0x3488: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_348b:
	/* 0x348b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_348e:
	/* 0x348e: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13459ULL);
	__x86_sim_call_depth++;
	return 13856ULL;
x86_l_3493:
	/* 0x3493: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3495:
	/* 0x3495: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13703ULL;
	}
x86_l_349b:
	/* 0x349b: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_34a0:
	/* 0x34a0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_34a3:
	/* 0x34a3: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34a6:
	/* 0x34a6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_34a9:
	/* 0x34a9: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_34ac:
	/* 0x34ac: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13838ULL;
	}
x86_l_34b2:
	/* 0x34b2: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_34b6:
	/* 0x34b6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_34b9:
	/* 0x34b9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_34bc:
	/* 0x34bc: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13505ULL);
	__x86_sim_call_depth++;
	return 13856ULL;
x86_l_34c1:
	/* 0x34c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34c3:
	/* 0x34c3: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13703ULL;
	}
x86_l_34c9:
	/* 0x34c9: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_34ce:
	/* 0x34ce: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_34d1:
	/* 0x34d1: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34d4:
	/* 0x34d4: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_34d7:
	/* 0x34d7: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_34da:
	/* 0x34da: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13838ULL;
	}
x86_l_34e0:
	/* 0x34e0: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_34e4:
	/* 0x34e4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_34e7:
	/* 0x34e7: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_34ea:
	/* 0x34ea: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13551ULL);
	__x86_sim_call_depth++;
	return 13856ULL;
x86_l_34ef:
	/* 0x34ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34f1:
	/* 0x34f1: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13703ULL;
	}
x86_l_34f7:
	/* 0x34f7: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_34fc:
	/* 0x34fc: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_34ff:
	/* 0x34ff: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3502:
	/* 0x3502: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3505:
	/* 0x3505: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3508:
	/* 0x3508: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13838ULL;
	}
x86_l_350e:
	/* 0x350e: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
	return 13586ULL;
}

static __noinline __u64 tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13586ULL: goto x86_l_3512;
	case 13589ULL: goto x86_l_3515;
	case 13592ULL: goto x86_l_3518;
	case 13597ULL: goto x86_l_351d;
	case 13599ULL: goto x86_l_351f;
	case 13601ULL: goto x86_l_3521;
	case 13606ULL: goto x86_l_3526;
	case 13609ULL: goto x86_l_3529;
	case 13612ULL: goto x86_l_352c;
	case 13615ULL: goto x86_l_352f;
	case 13618ULL: goto x86_l_3532;
	case 13624ULL: goto x86_l_3538;
	case 13628ULL: goto x86_l_353c;
	case 13631ULL: goto x86_l_353f;
	case 13634ULL: goto x86_l_3542;
	case 13639ULL: goto x86_l_3547;
	case 13641ULL: goto x86_l_3549;
	case 13643ULL: goto x86_l_354b;
	case 13648ULL: goto x86_l_3550;
	case 13651ULL: goto x86_l_3553;
	case 13654ULL: goto x86_l_3556;
	case 13657ULL: goto x86_l_3559;
	case 13660ULL: goto x86_l_355c;
	case 13666ULL: goto x86_l_3562;
	case 13669ULL: goto x86_l_3565;
	case 13672ULL: goto x86_l_3568;
	case 13675ULL: goto x86_l_356b;
	case 13678ULL: goto x86_l_356e;
	case 13683ULL: goto x86_l_3573;
	case 13685ULL: goto x86_l_3575;
	case 13687ULL: goto x86_l_3577;
	case 13692ULL: goto x86_l_357c;
	case 13695ULL: goto x86_l_357f;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13706ULL: goto x86_l_358a;
	case 13714ULL: goto x86_l_3592;
	case 13719ULL: goto x86_l_3597;
	case 13726ULL: goto x86_l_359e;
	case 13731ULL: goto x86_l_35a3;
	case 13733ULL: goto x86_l_35a5;
	case 13736ULL: goto x86_l_35a8;
	case 13738ULL: goto x86_l_35aa;
	case 13742ULL: goto x86_l_35ae;
	case 13744ULL: goto x86_l_35b0;
	case 13748ULL: goto x86_l_35b4;
	case 13750ULL: goto x86_l_35b6;
	case 13754ULL: goto x86_l_35ba;
	case 13756ULL: goto x86_l_35bc;
	case 13760ULL: goto x86_l_35c0;
	case 13762ULL: goto x86_l_35c2;
	case 13768ULL: goto x86_l_35c8;
	case 13770ULL: goto x86_l_35ca;
	case 13774ULL: goto x86_l_35ce;
	case 13776ULL: goto x86_l_35d0;
	case 13780ULL: goto x86_l_35d4;
	case 13782ULL: goto x86_l_35d6;
	case 13786ULL: goto x86_l_35da;
	case 13788ULL: goto x86_l_35dc;
	case 13794ULL: goto x86_l_35e2;
	case 13796ULL: goto x86_l_35e4;
	case 13802ULL: goto x86_l_35ea;
	case 13804ULL: goto x86_l_35ec;
	case 13810ULL: goto x86_l_35f2;
	case 13812ULL: goto x86_l_35f4;
	case 13818ULL: goto x86_l_35fa;
	case 13820ULL: goto x86_l_35fc;
	case 13826ULL: goto x86_l_3602;
	case 13828ULL: goto x86_l_3604;
	case 13834ULL: goto x86_l_360a;
	case 13838ULL: goto x86_l_360e;
	case 13841ULL: goto x86_l_3611;
	case 13845ULL: goto x86_l_3615;
	case 13846ULL: goto x86_l_3616;
	case 13848ULL: goto x86_l_3618;
	case 13850ULL: goto x86_l_361a;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13855ULL: goto x86_l_361f;
	case 13856ULL: goto x86_l_3620;
	case 13858ULL: goto x86_l_3622;
	case 13860ULL: goto x86_l_3624;
	case 13862ULL: goto x86_l_3626;
	case 13863ULL: goto x86_l_3627;
	case 13864ULL: goto x86_l_3628;
	case 13867ULL: goto x86_l_362b;
	case 13869ULL: goto x86_l_362d;
	case 13872ULL: goto x86_l_3630;
	case 13875ULL: goto x86_l_3633;
	case 13882ULL: goto x86_l_363a;
	case 13887ULL: goto x86_l_363f;
	case 13891ULL: goto x86_l_3643;
	case 13895ULL: goto x86_l_3647;
	case 13900ULL: goto x86_l_364c;
	case 13902ULL: goto x86_l_364e;
	case 13904ULL: goto x86_l_3650;
	case 13906ULL: goto x86_l_3652;
	case 13908ULL: goto x86_l_3654;
	case 13912ULL: goto x86_l_3658;
	case 13916ULL: goto x86_l_365c;
	case 13924ULL: goto x86_l_3664;
	case 13929ULL: goto x86_l_3669;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13943ULL: goto x86_l_3677;
	case 13946ULL: goto x86_l_367a;
	case 13948ULL: goto x86_l_367c;
	case 13952ULL: goto x86_l_3680;
	case 13954ULL: goto x86_l_3682;
	case 13959ULL: goto x86_l_3687;
	case 13966ULL: goto x86_l_368e;
	case 13971ULL: goto x86_l_3693;
	case 13974ULL: goto x86_l_3696;
	case 13977ULL: goto x86_l_3699;
	case 13980ULL: goto x86_l_369c;
	case 13982ULL: goto x86_l_369e;
	case 13984ULL: goto x86_l_36a0;
	case 13986ULL: goto x86_l_36a2;
	case 13988ULL: goto x86_l_36a4;
	case 13995ULL: goto x86_l_36ab;
	case 13997ULL: goto x86_l_36ad;
	case 14002ULL: goto x86_l_36b2;
	case 14009ULL: goto x86_l_36b9;
	case 14012ULL: goto x86_l_36bc;
	case 14015ULL: goto x86_l_36bf;
	case 14017ULL: goto x86_l_36c1;
	case 14019ULL: goto x86_l_36c3;
	case 14021ULL: goto x86_l_36c5;
	case 14023ULL: goto x86_l_36c7;
	case 14026ULL: goto x86_l_36ca;
	case 14029ULL: goto x86_l_36cd;
	case 14033ULL: goto x86_l_36d1;
	case 14034ULL: goto x86_l_36d2;
	case 14036ULL: goto x86_l_36d4;
	case 14038ULL: goto x86_l_36d6;
	case 14040ULL: goto x86_l_36d8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3512:
	/* 0x3512: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3515:
	/* 0x3515: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3518:
	/* 0x3518: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13597ULL);
	__x86_sim_call_depth++;
	goto x86_l_3620;
x86_l_351d:
	/* 0x351d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_351f:
	/* 0x351f: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3587;
	}
x86_l_3521:
	/* 0x3521: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3526:
	/* 0x3526: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3529:
	/* 0x3529: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_352c:
	/* 0x352c: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_352f:
	/* 0x352f: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3532:
	/* 0x3532: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_360e;
	}
x86_l_3538:
	/* 0x3538: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_353c:
	/* 0x353c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_353f:
	/* 0x353f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3542:
	/* 0x3542: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13639ULL);
	__x86_sim_call_depth++;
	goto x86_l_3620;
x86_l_3547:
	/* 0x3547: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3549:
	/* 0x3549: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3587;
	}
x86_l_354b:
	/* 0x354b: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3550:
	/* 0x3550: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3553:
	/* 0x3553: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3556:
	/* 0x3556: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3559:
	/* 0x3559: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_355c:
	/* 0x355c: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_360e;
	}
x86_l_3562:
	/* 0x3562: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3565:
	/* 0x3565: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3568:
	/* 0x3568: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_356b:
	/* 0x356b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_356e:
	/* 0x356e: call   3620 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13683ULL);
	__x86_sim_call_depth++;
	goto x86_l_3620;
x86_l_3573:
	/* 0x3573: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3575:
	/* 0x3575: js     3587 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3587;
	}
x86_l_3577:
	/* 0x3577: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_357c:
	/* 0x357c: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_357f:
	/* 0x357f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3582:
	/* 0x3582: jmp    360e <do_bytes+0x24e> */
	goto x86_l_360e;
x86_l_3587:
	/* 0x3587: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_358a:
	/* 0x358a: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3592:
	/* 0x3592: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3597:
	/* 0x3597: mov    rdi,QWORD PTR [rip+0x420] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_359e:
	/* 0x359e: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35a3:
	/* 0x35a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a5:
	/* 0x35a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35a8:
	/* 0x35a8: je     360e <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_360e;
	}
x86_l_35aa:
	/* 0x35aa: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_35ae:
	/* 0x35ae: jg     35ca <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_35ca;
	}
x86_l_35b0:
	/* 0x35b0: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_35b4:
	/* 0x35b4: je     35e4 <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e4;
	}
x86_l_35b6:
	/* 0x35b6: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_35ba:
	/* 0x35ba: je     35fc <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35fc;
	}
x86_l_35bc:
	/* 0x35bc: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_35c0:
	/* 0x35c0: jne    35f4 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35f4;
	}
x86_l_35c2:
	/* 0x35c2: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_35c8:
	/* 0x35c8: jmp    360a <do_bytes+0x24a> */
	goto x86_l_360a;
x86_l_35ca:
	/* 0x35ca: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_35ce:
	/* 0x35ce: je     35ec <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35ec;
	}
x86_l_35d0:
	/* 0x35d0: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_35d4:
	/* 0x35d4: je     3604 <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3604;
	}
x86_l_35d6:
	/* 0x35d6: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_35da:
	/* 0x35da: jne    35f4 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35f4;
	}
x86_l_35dc:
	/* 0x35dc: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_35e2:
	/* 0x35e2: jmp    360a <do_bytes+0x24a> */
	goto x86_l_360a;
x86_l_35e4:
	/* 0x35e4: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_35ea:
	/* 0x35ea: jmp    360a <do_bytes+0x24a> */
	goto x86_l_360a;
x86_l_35ec:
	/* 0x35ec: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_35f2:
	/* 0x35f2: jmp    360a <do_bytes+0x24a> */
	goto x86_l_360a;
x86_l_35f4:
	/* 0x35f4: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_35fa:
	/* 0x35fa: jmp    360a <do_bytes+0x24a> */
	goto x86_l_360a;
x86_l_35fc:
	/* 0x35fc: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_3602:
	/* 0x3602: jmp    360a <do_bytes+0x24a> */
	goto x86_l_360a;
x86_l_3604:
	/* 0x3604: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_360a:
	/* 0x360a: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_360e:
	/* 0x360e: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3611:
	/* 0x3611: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3615:
	/* 0x3615: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3616:
	/* 0x3616: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3618:
	/* 0x3618: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_361a:
	/* 0x361a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_361c:
	/* 0x361c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_361e:
	/* 0x361e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_361f:
	/* 0x361f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3620:
	/* 0x3620: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3622:
	/* 0x3622: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3624:
	/* 0x3624: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3626:
	/* 0x3626: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3627:
	/* 0x3627: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3628:
	/* 0x3628: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_362b:
	/* 0x362b: js     36a4 <__do_bytes+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36a4;
	}
x86_l_362d:
	/* 0x362d: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_3630:
	/* 0x3630: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_3633:
	/* 0x3633: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_363a:
	/* 0x363a: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_363f:
	/* 0x363f: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_3643:
	/* 0x3643: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3647:
	/* 0x3647: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_364c:
	/* 0x364c: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_364e:
	/* 0x364e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3650:
	/* 0x3650: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3652:
	/* 0x3652: js     36c7 <__do_bytes+0xa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36c7;
	}
x86_l_3654:
	/* 0x3654: lea    r12d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3658:
	/* 0x3658: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_365c:
	/* 0x365c: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3664:
	/* 0x3664: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3669:
	/* 0x3669: mov    rdi,QWORD PTR [rip+0x680] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_3670:
	/* 0x3670: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3675:
	/* 0x3675: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3677:
	/* 0x3677: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_367a:
	/* 0x367a: je     36ad <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36ad;
	}
x86_l_367c:
	/* 0x367c: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3680:
	/* 0x3680: je     36ad <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36ad;
	}
x86_l_3682:
	/* 0x3682: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3687:
	/* 0x3687: mov    rsi,QWORD PTR [rip+0x680] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_368e:
	/* 0x368e: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3693:
	/* 0x3693: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3696:
	/* 0x3696: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3699:
	/* 0x3699: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_369c:
	/* 0x369c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_369e:
	/* 0x369e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36a0:
	/* 0x36a0: js     36c7 <__do_bytes+0xa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36c7;
	}
x86_l_36a2:
	/* 0x36a2: jmp    36ca <__do_bytes+0xaa> */
	goto x86_l_36ca;
x86_l_36a4:
	/* 0x36a4: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_36ab:
	/* 0x36ab: jmp    36ca <__do_bytes+0xaa> */
	goto x86_l_36ca;
x86_l_36ad:
	/* 0x36ad: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_36b2:
	/* 0x36b2: mov    rdi,QWORD PTR [rip+0x680] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_36b9:
	/* 0x36b9: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_36bc:
	/* 0x36bc: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_36bf:
	/* 0x36bf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36c1:
	/* 0x36c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c3:
	/* 0x36c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36c5:
	/* 0x36c5: jns    36ca <__do_bytes+0xaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_36ca;
	}
x86_l_36c7:
	/* 0x36c7: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_36ca:
	/* 0x36ca: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_36cd:
	/* 0x36cd: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_36d1:
	/* 0x36d1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_36d2:
	/* 0x36d2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_36d4:
	/* 0x36d4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_36d6:
	/* 0x36d6: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_36d8:
	/* 0x36d8: ret */
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
	for (__u32 __x86_iter = 0; __x86_iter < 12832U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1724ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1731ULL && __x86_pc <= 3598ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3603ULL && __x86_pc <= 5381ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5383ULL && __x86_pc <= 7172ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7174ULL && __x86_pc <= 8910ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8916ULL && __x86_pc <= 10720ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10726ULL && __x86_pc <= 12263ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12269ULL && __x86_pc <= 13582ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13586ULL && __x86_pc <= 14040ULL)
			__x86_pc = tetragon_bpf_generic_kprobe_v61_generic_kprobe_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

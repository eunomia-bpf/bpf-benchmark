extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 15ULL: goto x86_l_f;
	case 26ULL: goto x86_l_1a;
	case 33ULL: goto x86_l_21;
	case 41ULL: goto x86_l_29;
	case 46ULL: goto x86_l_2e;
	case 48ULL: goto x86_l_30;
	case 51ULL: goto x86_l_33;
	case 57ULL: goto x86_l_39;
	case 60ULL: goto x86_l_3c;
	case 67ULL: goto x86_l_43;
	case 72ULL: goto x86_l_48;
	case 79ULL: goto x86_l_4f;
	case 84ULL: goto x86_l_54;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 109ULL: goto x86_l_6d;
	case 114ULL: goto x86_l_72;
	case 118ULL: goto x86_l_76;
	case 123ULL: goto x86_l_7b;
	case 127ULL: goto x86_l_7f;
	case 132ULL: goto x86_l_84;
	case 136ULL: goto x86_l_88;
	case 144ULL: goto x86_l_90;
	case 148ULL: goto x86_l_94;
	case 153ULL: goto x86_l_99;
	case 157ULL: goto x86_l_9d;
	case 165ULL: goto x86_l_a5;
	case 169ULL: goto x86_l_a9;
	case 174ULL: goto x86_l_ae;
	case 178ULL: goto x86_l_b2;
	case 186ULL: goto x86_l_ba;
	case 190ULL: goto x86_l_be;
	case 195ULL: goto x86_l_c3;
	case 199ULL: goto x86_l_c7;
	case 207ULL: goto x86_l_cf;
	case 211ULL: goto x86_l_d3;
	case 216ULL: goto x86_l_d8;
	case 219ULL: goto x86_l_db;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 232ULL: goto x86_l_e8;
	case 237ULL: goto x86_l_ed;
	case 243ULL: goto x86_l_f3;
	case 251ULL: goto x86_l_fb;
	case 254ULL: goto x86_l_fe;
	case 261ULL: goto x86_l_105;
	case 264ULL: goto x86_l_108;
	case 266ULL: goto x86_l_10a;
	case 268ULL: goto x86_l_10c;
	case 273ULL: goto x86_l_111;
	case 276ULL: goto x86_l_114;
	case 280ULL: goto x86_l_118;
	case 284ULL: goto x86_l_11c;
	case 290ULL: goto x86_l_122;
	case 295ULL: goto x86_l_127;
	case 300ULL: goto x86_l_12c;
	case 302ULL: goto x86_l_12e;
	case 304ULL: goto x86_l_130;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 338ULL: goto x86_l_152;
	case 341ULL: goto x86_l_155;
	case 347ULL: goto x86_l_15b;
	case 352ULL: goto x86_l_160;
	case 357ULL: goto x86_l_165;
	case 366ULL: goto x86_l_16e;
	case 375ULL: goto x86_l_177;
	case 381ULL: goto x86_l_17d;
	case 384ULL: goto x86_l_180;
	case 386ULL: goto x86_l_182;
	case 389ULL: goto x86_l_185;
	case 395ULL: goto x86_l_18b;
	case 398ULL: goto x86_l_18e;
	case 404ULL: goto x86_l_194;
	case 409ULL: goto x86_l_199;
	case 412ULL: goto x86_l_19c;
	case 418ULL: goto x86_l_1a2;
	case 423ULL: goto x86_l_1a7;
	case 426ULL: goto x86_l_1aa;
	case 432ULL: goto x86_l_1b0;
	case 437ULL: goto x86_l_1b5;
	case 440ULL: goto x86_l_1b8;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 459ULL: goto x86_l_1cb;
	case 461ULL: goto x86_l_1cd;
	case 464ULL: goto x86_l_1d0;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 477ULL: goto x86_l_1dd;
	case 483ULL: goto x86_l_1e3;
	case 491ULL: goto x86_l_1eb;
	case 496ULL: goto x86_l_1f0;
	case 499ULL: goto x86_l_1f3;
	case 505ULL: goto x86_l_1f9;
	case 510ULL: goto x86_l_1fe;
	case 512ULL: goto x86_l_200;
	case 518ULL: goto x86_l_206;
	case 521ULL: goto x86_l_209;
	case 527ULL: goto x86_l_20f;
	case 532ULL: goto x86_l_214;
	case 534ULL: goto x86_l_216;
	case 537ULL: goto x86_l_219;
	case 543ULL: goto x86_l_21f;
	case 551ULL: goto x86_l_227;
	case 554ULL: goto x86_l_22a;
	case 560ULL: goto x86_l_230;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 573ULL: goto x86_l_23d;
	case 579ULL: goto x86_l_243;
	case 584ULL: goto x86_l_248;
	case 587ULL: goto x86_l_24b;
	case 593ULL: goto x86_l_251;
	case 601ULL: goto x86_l_259;
	case 604ULL: goto x86_l_25c;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 623ULL: goto x86_l_26f;
	case 629ULL: goto x86_l_275;
	case 634ULL: goto x86_l_27a;
	case 639ULL: goto x86_l_27f;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 648ULL: goto x86_l_288;
	case 653ULL: goto x86_l_28d;
	case 656ULL: goto x86_l_290;
	case 660ULL: goto x86_l_294;
	case 663ULL: goto x86_l_297;
	case 666ULL: goto x86_l_29a;
	case 671ULL: goto x86_l_29f;
	case 677ULL: goto x86_l_2a5;
	case 684ULL: goto x86_l_2ac;
	case 687ULL: goto x86_l_2af;
	case 690ULL: goto x86_l_2b2;
	case 693ULL: goto x86_l_2b5;
	case 697ULL: goto x86_l_2b9;
	case 701ULL: goto x86_l_2bd;
	case 703ULL: goto x86_l_2bf;
	case 709ULL: goto x86_l_2c5;
	case 712ULL: goto x86_l_2c8;
	case 714ULL: goto x86_l_2ca;
	case 719ULL: goto x86_l_2cf;
	case 724ULL: goto x86_l_2d4;
	case 727ULL: goto x86_l_2d7;
	case 731ULL: goto x86_l_2db;
	case 736ULL: goto x86_l_2e0;
	case 738ULL: goto x86_l_2e2;
	case 740ULL: goto x86_l_2e4;
	case 746ULL: goto x86_l_2ea;
	case 751ULL: goto x86_l_2ef;
	case 757ULL: goto x86_l_2f5;
	case 760ULL: goto x86_l_2f8;
	case 764ULL: goto x86_l_2fc;
	case 768ULL: goto x86_l_300;
	case 773ULL: goto x86_l_305;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 785ULL: goto x86_l_311;
	case 788ULL: goto x86_l_314;
	case 792ULL: goto x86_l_318;
	case 797ULL: goto x86_l_31d;
	case 799ULL: goto x86_l_31f;
	case 801ULL: goto x86_l_321;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 818ULL: goto x86_l_332;
	case 821ULL: goto x86_l_335;
	case 825ULL: goto x86_l_339;
	case 829ULL: goto x86_l_33d;
	case 834ULL: goto x86_l_342;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 846ULL: goto x86_l_34e;
	case 849ULL: goto x86_l_351;
	case 853ULL: goto x86_l_355;
	case 858ULL: goto x86_l_35a;
	case 860ULL: goto x86_l_35c;
	case 862ULL: goto x86_l_35e;
	case 868ULL: goto x86_l_364;
	case 873ULL: goto x86_l_369;
	case 879ULL: goto x86_l_36f;
	case 882ULL: goto x86_l_372;
	case 886ULL: goto x86_l_376;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 897ULL: goto x86_l_381;
	case 902ULL: goto x86_l_386;
	case 907ULL: goto x86_l_38b;
	case 910ULL: goto x86_l_38e;
	case 914ULL: goto x86_l_392;
	case 919ULL: goto x86_l_397;
	case 921ULL: goto x86_l_399;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 934ULL: goto x86_l_3a6;
	case 940ULL: goto x86_l_3ac;
	case 943ULL: goto x86_l_3af;
	case 947ULL: goto x86_l_3b3;
	case 951ULL: goto x86_l_3b7;
	case 956ULL: goto x86_l_3bc;
	case 958ULL: goto x86_l_3be;
	case 963ULL: goto x86_l_3c3;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 975ULL: goto x86_l_3cf;
	case 980ULL: goto x86_l_3d4;
	case 982ULL: goto x86_l_3d6;
	case 984ULL: goto x86_l_3d8;
	case 990ULL: goto x86_l_3de;
	case 995ULL: goto x86_l_3e3;
	case 1001ULL: goto x86_l_3e9;
	case 1004ULL: goto x86_l_3ec;
	case 1008ULL: goto x86_l_3f0;
	case 1012ULL: goto x86_l_3f4;
	case 1017ULL: goto x86_l_3f9;
	case 1019ULL: goto x86_l_3fb;
	case 1024ULL: goto x86_l_400;
	case 1029ULL: goto x86_l_405;
	case 1032ULL: goto x86_l_408;
	case 1036ULL: goto x86_l_40c;
	case 1041ULL: goto x86_l_411;
	case 1043ULL: goto x86_l_413;
	case 1045ULL: goto x86_l_415;
	case 1051ULL: goto x86_l_41b;
	case 1056ULL: goto x86_l_420;
	case 1062ULL: goto x86_l_426;
	case 1065ULL: goto x86_l_429;
	case 1069ULL: goto x86_l_42d;
	case 1073ULL: goto x86_l_431;
	case 1078ULL: goto x86_l_436;
	case 1080ULL: goto x86_l_438;
	case 1085ULL: goto x86_l_43d;
	case 1090ULL: goto x86_l_442;
	case 1093ULL: goto x86_l_445;
	case 1097ULL: goto x86_l_449;
	case 1102ULL: goto x86_l_44e;
	case 1104ULL: goto x86_l_450;
	case 1106ULL: goto x86_l_452;
	case 1112ULL: goto x86_l_458;
	case 1117ULL: goto x86_l_45d;
	case 1123ULL: goto x86_l_463;
	case 1126ULL: goto x86_l_466;
	case 1130ULL: goto x86_l_46a;
	case 1134ULL: goto x86_l_46e;
	case 1139ULL: goto x86_l_473;
	case 1141ULL: goto x86_l_475;
	case 1146ULL: goto x86_l_47a;
	case 1151ULL: goto x86_l_47f;
	case 1154ULL: goto x86_l_482;
	case 1158ULL: goto x86_l_486;
	case 1163ULL: goto x86_l_48b;
	case 1165ULL: goto x86_l_48d;
	case 1167ULL: goto x86_l_48f;
	case 1173ULL: goto x86_l_495;
	case 1178ULL: goto x86_l_49a;
	case 1184ULL: goto x86_l_4a0;
	case 1187ULL: goto x86_l_4a3;
	case 1191ULL: goto x86_l_4a7;
	case 1195ULL: goto x86_l_4ab;
	case 1200ULL: goto x86_l_4b0;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1212ULL: goto x86_l_4bc;
	case 1215ULL: goto x86_l_4bf;
	case 1219ULL: goto x86_l_4c3;
	case 1224ULL: goto x86_l_4c8;
	case 1226ULL: goto x86_l_4ca;
	case 1228ULL: goto x86_l_4cc;
	case 1234ULL: goto x86_l_4d2;
	case 1238ULL: goto x86_l_4d6;
	case 1244ULL: goto x86_l_4dc;
	case 1247ULL: goto x86_l_4df;
	case 1251ULL: goto x86_l_4e3;
	case 1255ULL: goto x86_l_4e7;
	case 1260ULL: goto x86_l_4ec;
	case 1266ULL: goto x86_l_4f2;
	case 1271ULL: goto x86_l_4f7;
	case 1276ULL: goto x86_l_4fc;
	case 1279ULL: goto x86_l_4ff;
	case 1284ULL: goto x86_l_504;
	case 1287ULL: goto x86_l_507;
	case 1289ULL: goto x86_l_509;
	case 1294ULL: goto x86_l_50e;
	case 1299ULL: goto x86_l_513;
	case 1302ULL: goto x86_l_516;
	case 1306ULL: goto x86_l_51a;
	case 1311ULL: goto x86_l_51f;
	case 1313ULL: goto x86_l_521;
	case 1315ULL: goto x86_l_523;
	case 1321ULL: goto x86_l_529;
	case 1326ULL: goto x86_l_52e;
	case 1332ULL: goto x86_l_534;
	case 1335ULL: goto x86_l_537;
	case 1339ULL: goto x86_l_53b;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1363ULL: goto x86_l_553;
	case 1367ULL: goto x86_l_557;
	case 1372ULL: goto x86_l_55c;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1393ULL: goto x86_l_571;
	case 1396ULL: goto x86_l_574;
	case 1400ULL: goto x86_l_578;
	case 1404ULL: goto x86_l_57c;
	case 1409ULL: goto x86_l_581;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1421ULL: goto x86_l_58d;
	case 1424ULL: goto x86_l_590;
	case 1428ULL: goto x86_l_594;
	case 1433ULL: goto x86_l_599;
	case 1435ULL: goto x86_l_59b;
	case 1437ULL: goto x86_l_59d;
	case 1443ULL: goto x86_l_5a3;
	case 1448ULL: goto x86_l_5a8;
	case 1454ULL: goto x86_l_5ae;
	case 1457ULL: goto x86_l_5b1;
	case 1461ULL: goto x86_l_5b5;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1472ULL: goto x86_l_5c0;
	case 1477ULL: goto x86_l_5c5;
	case 1482ULL: goto x86_l_5ca;
	case 1485ULL: goto x86_l_5cd;
	case 1489ULL: goto x86_l_5d1;
	case 1494ULL: goto x86_l_5d6;
	case 1496ULL: goto x86_l_5d8;
	case 1498ULL: goto x86_l_5da;
	case 1504ULL: goto x86_l_5e0;
	case 1509ULL: goto x86_l_5e5;
	case 1515ULL: goto x86_l_5eb;
	case 1518ULL: goto x86_l_5ee;
	case 1522ULL: goto x86_l_5f2;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1533ULL: goto x86_l_5fd;
	case 1538ULL: goto x86_l_602;
	case 1543ULL: goto x86_l_607;
	case 1546ULL: goto x86_l_60a;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1557ULL: goto x86_l_615;
	case 1559ULL: goto x86_l_617;
	case 1565ULL: goto x86_l_61d;
	case 1570ULL: goto x86_l_622;
	case 1576ULL: goto x86_l_628;
	case 1579ULL: goto x86_l_62b;
	case 1583ULL: goto x86_l_62f;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1604ULL: goto x86_l_644;
	case 1607ULL: goto x86_l_647;
	case 1611ULL: goto x86_l_64b;
	case 1616ULL: goto x86_l_650;
	case 1618ULL: goto x86_l_652;
	case 1620ULL: goto x86_l_654;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1637ULL: goto x86_l_665;
	case 1640ULL: goto x86_l_668;
	case 1644ULL: goto x86_l_66c;
	case 1648ULL: goto x86_l_670;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f:
	/* 0xf: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1a:
	/* 0x1a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_21:
	/* 0x21: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_29:
	/* 0x29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e:
	/* 0x2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30:
	/* 0x30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33:
	/* 0x33: je     4c70 <generic_sleepable_preload+0x4c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19568ULL;
	}
x86_l_39:
	/* 0x39: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_43:
	/* 0x43: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_48:
	/* 0x48: lea    rdx,[rcx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4f:
	/* 0x4f: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_54:
	/* 0x54: lea    rdx,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5b:
	/* 0x5b: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_60:
	/* 0x60: lea    rdx,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_69:
	/* 0x69: lea    rdx,[rcx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_72:
	/* 0x72: lea    rdx,[rcx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_76:
	/* 0x76: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7b:
	/* 0x7b: lea    rdx,[rcx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7f:
	/* 0x7f: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_84:
	/* 0x84: lea    rdx,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_88:
	/* 0x88: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_90:
	/* 0x90: lea    rdx,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_94:
	/* 0x94: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_99:
	/* 0x99: lea    rdx,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a5:
	/* 0xa5: lea    rdx,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a9:
	/* 0xa9: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ae:
	/* 0xae: lea    rdx,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b2:
	/* 0xb2: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ba:
	/* 0xba: lea    rdx,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_be:
	/* 0xbe: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c3:
	/* 0xc3: lea    rdx,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cf:
	/* 0xcf: lea    rdx,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d3:
	/* 0xd3: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d8:
	/* 0xd8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db:
	/* 0xdb: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df:
	/* 0xdf: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e4:
	/* 0xe4: lea    r14,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8:
	/* 0xe8: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed:
	/* 0xed: je     ef4 <generic_sleepable_preload+0xef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3828ULL;
	}
x86_l_f3:
	/* 0xf3: mov    QWORD PTR [rsp+0xb0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fb:
	/* 0xfb: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: add    rbx,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_105:
	/* 0x105: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_108:
	/* 0x108: jmp    122 <generic_sleepable_preload+0x122> */
	goto x86_l_122;
x86_l_10a:
	/* 0x10a: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c:
	/* 0x10c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_111:
	/* 0x111: inc    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_114:
	/* 0x114: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_118:
	/* 0x118: cmp    r14,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 5ULL);
x86_l_11c:
	/* 0x11c: je     4c70 <generic_sleepable_preload+0x4c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19568ULL;
	}
x86_l_122:
	/* 0x122: mov    eax,DWORD PTR [r12+r14*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 24ULL);
x86_l_127:
	/* 0x127: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_12c:
	/* 0x12c: je     111 <generic_sleepable_preload+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_111;
	}
x86_l_12e:
	/* 0x12e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_130:
	/* 0x130: js     165 <generic_sleepable_preload+0x165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_165;
	}
x86_l_132:
	/* 0x132: mov    eax,DWORD PTR [r12+r14*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 64ULL);
x86_l_137:
	/* 0x137: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13a:
	/* 0x13a: jle    1fe <generic_sleepable_preload+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1fe;
	}
x86_l_140:
	/* 0x140: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_143:
	/* 0x143: je     27a <generic_sleepable_preload+0x27a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a;
	}
x86_l_149:
	/* 0x149: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14c:
	/* 0x14c: je     281 <generic_sleepable_preload+0x281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_281;
	}
x86_l_152:
	/* 0x152: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_155:
	/* 0x155: jne    294 <generic_sleepable_preload+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_294;
	}
x86_l_15b:
	/* 0x15b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_160:
	/* 0x160: jmp    28d <generic_sleepable_preload+0x28d> */
	goto x86_l_28d;
x86_l_165:
	/* 0x165: movzx  eax,BYTE PTR [r12+r14*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_8), 706ULL);
x86_l_16e:
	/* 0x16e: movzx  ecx,WORD PTR [r12+r14*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_16), 704ULL);
x86_l_177:
	/* 0x177: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_17d:
	/* 0x17d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_180:
	/* 0x180: jle    1c8 <generic_sleepable_preload+0x1c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c8;
	}
x86_l_182:
	/* 0x182: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_185:
	/* 0x185: jle    216 <generic_sleepable_preload+0x216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_216;
	}
x86_l_18b:
	/* 0x18b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_18e:
	/* 0x18e: jle    7be <generic_sleepable_preload+0x7be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1982ULL;
	}
x86_l_194:
	/* 0x194: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_199:
	/* 0x199: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_19c:
	/* 0x19c: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2007ULL;
	}
x86_l_1a2:
	/* 0x1a2: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a7:
	/* 0x1a7: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1aa:
	/* 0x1aa: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2007ULL;
	}
x86_l_1b0:
	/* 0x1b0: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1b5:
	/* 0x1b5: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1b8:
	/* 0x1b8: jne    7ea <generic_sleepable_preload+0x7ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2026ULL;
	}
x86_l_1be:
	/* 0x1be: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c3:
	/* 0x1c3: jmp    7d7 <generic_sleepable_preload+0x7d7> */
	return 2007ULL;
x86_l_1c8:
	/* 0x1c8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1cb:
	/* 0x1cb: jg     248 <generic_sleepable_preload+0x248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_248;
	}
x86_l_1cd:
	/* 0x1cd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d0:
	/* 0x1d0: jg     785 <generic_sleepable_preload+0x785> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1925ULL;
	}
x86_l_1d6:
	/* 0x1d6: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1db:
	/* 0x1db: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1dd:
	/* 0x1dd: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2007ULL;
	}
x86_l_1e3:
	/* 0x1e3: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1eb:
	/* 0x1eb: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1f0:
	/* 0x1f0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f3:
	/* 0x1f3: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2007ULL;
	}
x86_l_1f9:
	/* 0x1f9: jmp    7ea <generic_sleepable_preload+0x7ea> */
	return 2026ULL;
x86_l_1fe:
	/* 0x1fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_200:
	/* 0x200: je     288 <generic_sleepable_preload+0x288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_288;
	}
x86_l_206:
	/* 0x206: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_209:
	/* 0x209: jne    294 <generic_sleepable_preload+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_294;
	}
x86_l_20f:
	/* 0x20f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_214:
	/* 0x214: jmp    28d <generic_sleepable_preload+0x28d> */
	goto x86_l_28d;
x86_l_216:
	/* 0x216: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_219:
	/* 0x219: jg     767 <generic_sleepable_preload+0x767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1895ULL;
	}
x86_l_21f:
	/* 0x21f: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_227:
	/* 0x227: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22a:
	/* 0x22a: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2007ULL;
	}
x86_l_230:
	/* 0x230: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_235:
	/* 0x235: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_23a:
	/* 0x23a: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_23d:
	/* 0x23d: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2007ULL;
	}
x86_l_243:
	/* 0x243: jmp    7ea <generic_sleepable_preload+0x7ea> */
	return 2026ULL;
x86_l_248:
	/* 0x248: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_24b:
	/* 0x24b: jg     7a0 <generic_sleepable_preload+0x7a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1952ULL;
	}
x86_l_251:
	/* 0x251: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_259:
	/* 0x259: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_25c:
	/* 0x25c: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2007ULL;
	}
x86_l_262:
	/* 0x262: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_267:
	/* 0x267: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_26c:
	/* 0x26c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_26f:
	/* 0x26f: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2007ULL;
	}
x86_l_275:
	/* 0x275: jmp    7ea <generic_sleepable_preload+0x7ea> */
	return 2026ULL;
x86_l_27a:
	/* 0x27a: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27f:
	/* 0x27f: jmp    28d <generic_sleepable_preload+0x28d> */
	goto x86_l_28d;
x86_l_281:
	/* 0x281: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_286:
	/* 0x286: jmp    28d <generic_sleepable_preload+0x28d> */
	goto x86_l_28d;
x86_l_288:
	/* 0x288: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28d:
	/* 0x28d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_290:
	/* 0x290: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294:
	/* 0x294: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_297:
	/* 0x297: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_29a:
	/* 0x29a: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_29f:
	/* 0x29f: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_2a5:
	/* 0x2a5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2ac:
	/* 0x2ac: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2af:
	/* 0x2af: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_2b2:
	/* 0x2b2: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b5:
	/* 0x2b5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9:
	/* 0x2b9: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_2bd:
	/* 0x2bd: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2bf:
	/* 0x2bf: je     504 <generic_sleepable_preload+0x504> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_504;
	}
x86_l_2c5:
	/* 0x2c5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2c8:
	/* 0x2c8: je     2ea <generic_sleepable_preload+0x2ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea;
	}
x86_l_2ca:
	/* 0x2ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cf:
	/* 0x2cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d4:
	/* 0x2d4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d7:
	/* 0x2d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2db:
	/* 0x2db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e0:
	/* 0x2e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2:
	/* 0x2e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e4:
	/* 0x2e4: js     75c <generic_sleepable_preload+0x75c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1884ULL;
	}
x86_l_2ea:
	/* 0x2ea: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_2ef:
	/* 0x2ef: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_2f5:
	/* 0x2f5: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_2f8:
	/* 0x2f8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2fc:
	/* 0x2fc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_300:
	/* 0x300: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_305:
	/* 0x305: je     327 <generic_sleepable_preload+0x327> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_327;
	}
x86_l_307:
	/* 0x307: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30c:
	/* 0x30c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_311:
	/* 0x311: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_314:
	/* 0x314: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_318:
	/* 0x318: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d:
	/* 0x31d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f:
	/* 0x31f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_321:
	/* 0x321: js     cc3 <generic_sleepable_preload+0xcc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3267ULL;
	}
x86_l_327:
	/* 0x327: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_32c:
	/* 0x32c: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_332:
	/* 0x332: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_335:
	/* 0x335: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_339:
	/* 0x339: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33d:
	/* 0x33d: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_342:
	/* 0x342: je     364 <generic_sleepable_preload+0x364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364;
	}
x86_l_344:
	/* 0x344: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_349:
	/* 0x349: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34e:
	/* 0x34e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_351:
	/* 0x351: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_355:
	/* 0x355: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35a:
	/* 0x35a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c:
	/* 0x35c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35e:
	/* 0x35e: js     cd5 <generic_sleepable_preload+0xcd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3285ULL;
	}
x86_l_364:
	/* 0x364: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_369:
	/* 0x369: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_36f:
	/* 0x36f: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_372:
	/* 0x372: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_376:
	/* 0x376: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37a:
	/* 0x37a: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_37f:
	/* 0x37f: je     3a1 <generic_sleepable_preload+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a1;
	}
x86_l_381:
	/* 0x381: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_386:
	/* 0x386: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38b:
	/* 0x38b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_38e:
	/* 0x38e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_392:
	/* 0x392: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_397:
	/* 0x397: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_399:
	/* 0x399: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39b:
	/* 0x39b: js     ce7 <generic_sleepable_preload+0xce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3303ULL;
	}
x86_l_3a1:
	/* 0x3a1: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_3a6:
	/* 0x3a6: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_3ac:
	/* 0x3ac: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_3af:
	/* 0x3af: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b3:
	/* 0x3b3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b7:
	/* 0x3b7: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_3bc:
	/* 0x3bc: je     3de <generic_sleepable_preload+0x3de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3de;
	}
x86_l_3be:
	/* 0x3be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c3:
	/* 0x3c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c8:
	/* 0x3c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3cb:
	/* 0x3cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cf:
	/* 0x3cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d4:
	/* 0x3d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d6:
	/* 0x3d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d8:
	/* 0x3d8: js     cf9 <generic_sleepable_preload+0xcf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3321ULL;
	}
x86_l_3de:
	/* 0x3de: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_3e3:
	/* 0x3e3: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_3e9:
	/* 0x3e9: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_3ec:
	/* 0x3ec: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f0:
	/* 0x3f0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f4:
	/* 0x3f4: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_3f9:
	/* 0x3f9: je     41b <generic_sleepable_preload+0x41b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41b;
	}
x86_l_3fb:
	/* 0x3fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_400:
	/* 0x400: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_405:
	/* 0x405: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_408:
	/* 0x408: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40c:
	/* 0x40c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_411:
	/* 0x411: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_413:
	/* 0x413: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_415:
	/* 0x415: js     d0b <generic_sleepable_preload+0xd0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3339ULL;
	}
x86_l_41b:
	/* 0x41b: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_420:
	/* 0x420: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_426:
	/* 0x426: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_429:
	/* 0x429: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42d:
	/* 0x42d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_431:
	/* 0x431: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_436:
	/* 0x436: je     458 <generic_sleepable_preload+0x458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_458;
	}
x86_l_438:
	/* 0x438: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43d:
	/* 0x43d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_442:
	/* 0x442: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_445:
	/* 0x445: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_449:
	/* 0x449: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44e:
	/* 0x44e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_450:
	/* 0x450: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_452:
	/* 0x452: js     d1d <generic_sleepable_preload+0xd1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3357ULL;
	}
x86_l_458:
	/* 0x458: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_45d:
	/* 0x45d: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_463:
	/* 0x463: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_466:
	/* 0x466: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_46a:
	/* 0x46a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e:
	/* 0x46e: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_473:
	/* 0x473: je     495 <generic_sleepable_preload+0x495> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_495;
	}
x86_l_475:
	/* 0x475: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47a:
	/* 0x47a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47f:
	/* 0x47f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_482:
	/* 0x482: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_486:
	/* 0x486: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48b:
	/* 0x48b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48d:
	/* 0x48d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48f:
	/* 0x48f: js     ebb <generic_sleepable_preload+0xebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3771ULL;
	}
x86_l_495:
	/* 0x495: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_49a:
	/* 0x49a: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_4a0:
	/* 0x4a0: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_4a3:
	/* 0x4a3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a7:
	/* 0x4a7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ab:
	/* 0x4ab: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_4b0:
	/* 0x4b0: je     4d2 <generic_sleepable_preload+0x4d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d2;
	}
x86_l_4b2:
	/* 0x4b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b7:
	/* 0x4b7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4bc:
	/* 0x4bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4bf:
	/* 0x4bf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c3:
	/* 0x4c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c8:
	/* 0x4c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca:
	/* 0x4ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cc:
	/* 0x4cc: js     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3807ULL;
	}
x86_l_4d2:
	/* 0x4d2: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d6:
	/* 0x4d6: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_4dc:
	/* 0x4dc: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_4df:
	/* 0x4df: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e3:
	/* 0x4e3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e7:
	/* 0x4e7: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_4ec:
	/* 0x4ec: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_4f2:
	/* 0x4f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f7:
	/* 0x4f7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fc:
	/* 0x4fc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ff:
	/* 0x4ff: jmp    73e <generic_sleepable_preload+0x73e> */
	return 1854ULL;
x86_l_504:
	/* 0x504: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_507:
	/* 0x507: je     529 <generic_sleepable_preload+0x529> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_529;
	}
x86_l_509:
	/* 0x509: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50e:
	/* 0x50e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_513:
	/* 0x513: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_516:
	/* 0x516: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51a:
	/* 0x51a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51f:
	/* 0x51f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_521:
	/* 0x521: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_523:
	/* 0x523: js     75c <generic_sleepable_preload+0x75c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1884ULL;
	}
x86_l_529:
	/* 0x529: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_52e:
	/* 0x52e: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_534:
	/* 0x534: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_537:
	/* 0x537: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_53b:
	/* 0x53b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53f:
	/* 0x53f: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_544:
	/* 0x544: je     566 <generic_sleepable_preload+0x566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_566;
	}
x86_l_546:
	/* 0x546: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54b:
	/* 0x54b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_550:
	/* 0x550: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_553:
	/* 0x553: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_557:
	/* 0x557: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55c:
	/* 0x55c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55e:
	/* 0x55e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_560:
	/* 0x560: js     cc3 <generic_sleepable_preload+0xcc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3267ULL;
	}
x86_l_566:
	/* 0x566: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_56b:
	/* 0x56b: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_571:
	/* 0x571: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_574:
	/* 0x574: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_578:
	/* 0x578: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57c:
	/* 0x57c: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_581:
	/* 0x581: je     5a3 <generic_sleepable_preload+0x5a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a3;
	}
x86_l_583:
	/* 0x583: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_588:
	/* 0x588: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58d:
	/* 0x58d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_590:
	/* 0x590: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_594:
	/* 0x594: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_599:
	/* 0x599: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59b:
	/* 0x59b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59d:
	/* 0x59d: js     cd5 <generic_sleepable_preload+0xcd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3285ULL;
	}
x86_l_5a3:
	/* 0x5a3: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_5a8:
	/* 0x5a8: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_5ae:
	/* 0x5ae: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_5b1:
	/* 0x5b1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5b5:
	/* 0x5b5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b9:
	/* 0x5b9: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_5be:
	/* 0x5be: je     5e0 <generic_sleepable_preload+0x5e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e0;
	}
x86_l_5c0:
	/* 0x5c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c5:
	/* 0x5c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ca:
	/* 0x5ca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5cd:
	/* 0x5cd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d1:
	/* 0x5d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d6:
	/* 0x5d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d8:
	/* 0x5d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5da:
	/* 0x5da: js     ce7 <generic_sleepable_preload+0xce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3303ULL;
	}
x86_l_5e0:
	/* 0x5e0: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_5e5:
	/* 0x5e5: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_5eb:
	/* 0x5eb: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_5ee:
	/* 0x5ee: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5f2:
	/* 0x5f2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f6:
	/* 0x5f6: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_5fb:
	/* 0x5fb: je     61d <generic_sleepable_preload+0x61d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d;
	}
x86_l_5fd:
	/* 0x5fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_602:
	/* 0x602: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_607:
	/* 0x607: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_60a:
	/* 0x60a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60e:
	/* 0x60e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_613:
	/* 0x613: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_615:
	/* 0x615: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_617:
	/* 0x617: js     cf9 <generic_sleepable_preload+0xcf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3321ULL;
	}
x86_l_61d:
	/* 0x61d: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_622:
	/* 0x622: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_628:
	/* 0x628: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_62b:
	/* 0x62b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_62f:
	/* 0x62f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_633:
	/* 0x633: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_638:
	/* 0x638: je     65a <generic_sleepable_preload+0x65a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65a;
	}
x86_l_63a:
	/* 0x63a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_63f:
	/* 0x63f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_644:
	/* 0x644: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_647:
	/* 0x647: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64b:
	/* 0x64b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_650:
	/* 0x650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_652:
	/* 0x652: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_654:
	/* 0x654: js     d0b <generic_sleepable_preload+0xd0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3339ULL;
	}
x86_l_65a:
	/* 0x65a: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_65f:
	/* 0x65f: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_665:
	/* 0x665: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_668:
	/* 0x668: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_66c:
	/* 0x66c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_670:
	/* 0x670: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
	return 1653ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1653ULL: goto x86_l_675;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1665ULL: goto x86_l_681;
	case 1668ULL: goto x86_l_684;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1679ULL: goto x86_l_68f;
	case 1681ULL: goto x86_l_691;
	case 1687ULL: goto x86_l_697;
	case 1692ULL: goto x86_l_69c;
	case 1698ULL: goto x86_l_6a2;
	case 1701ULL: goto x86_l_6a5;
	case 1705ULL: goto x86_l_6a9;
	case 1709ULL: goto x86_l_6ad;
	case 1714ULL: goto x86_l_6b2;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1726ULL: goto x86_l_6be;
	case 1729ULL: goto x86_l_6c1;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1740ULL: goto x86_l_6cc;
	case 1742ULL: goto x86_l_6ce;
	case 1748ULL: goto x86_l_6d4;
	case 1753ULL: goto x86_l_6d9;
	case 1759ULL: goto x86_l_6df;
	case 1762ULL: goto x86_l_6e2;
	case 1766ULL: goto x86_l_6e6;
	case 1770ULL: goto x86_l_6ea;
	case 1775ULL: goto x86_l_6ef;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1790ULL: goto x86_l_6fe;
	case 1794ULL: goto x86_l_702;
	case 1799ULL: goto x86_l_707;
	case 1801ULL: goto x86_l_709;
	case 1803ULL: goto x86_l_70b;
	case 1809ULL: goto x86_l_711;
	case 1813ULL: goto x86_l_715;
	case 1819ULL: goto x86_l_71b;
	case 1822ULL: goto x86_l_71e;
	case 1826ULL: goto x86_l_722;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1841ULL: goto x86_l_731;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1854ULL: goto x86_l_73e;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1865ULL: goto x86_l_749;
	case 1867ULL: goto x86_l_74b;
	case 1873ULL: goto x86_l_751;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1903ULL: goto x86_l_76f;
	case 1906ULL: goto x86_l_772;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1921ULL: goto x86_l_781;
	case 1923ULL: goto x86_l_783;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1933ULL: goto x86_l_78d;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1948ULL: goto x86_l_79c;
	case 1950ULL: goto x86_l_79e;
	case 1952ULL: goto x86_l_7a0;
	case 1960ULL: goto x86_l_7a8;
	case 1963ULL: goto x86_l_7ab;
	case 1965ULL: goto x86_l_7ad;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1978ULL: goto x86_l_7ba;
	case 1980ULL: goto x86_l_7bc;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1990ULL: goto x86_l_7c6;
	case 1992ULL: goto x86_l_7c8;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2005ULL: goto x86_l_7d5;
	case 2007ULL: goto x86_l_7d7;
	case 2010ULL: goto x86_l_7da;
	case 2012ULL: goto x86_l_7dc;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2030ULL: goto x86_l_7ee;
	case 2035ULL: goto x86_l_7f3;
	case 2037ULL: goto x86_l_7f5;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2051ULL: goto x86_l_803;
	case 2058ULL: goto x86_l_80a;
	case 2061ULL: goto x86_l_80d;
	case 2064ULL: goto x86_l_810;
	case 2067ULL: goto x86_l_813;
	case 2071ULL: goto x86_l_817;
	case 2075ULL: goto x86_l_81b;
	case 2077ULL: goto x86_l_81d;
	case 2083ULL: goto x86_l_823;
	case 2086ULL: goto x86_l_826;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2101ULL: goto x86_l_835;
	case 2105ULL: goto x86_l_839;
	case 2110ULL: goto x86_l_83e;
	case 2112ULL: goto x86_l_840;
	case 2114ULL: goto x86_l_842;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2131ULL: goto x86_l_853;
	case 2134ULL: goto x86_l_856;
	case 2138ULL: goto x86_l_85a;
	case 2142ULL: goto x86_l_85e;
	case 2147ULL: goto x86_l_863;
	case 2149ULL: goto x86_l_865;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2162ULL: goto x86_l_872;
	case 2166ULL: goto x86_l_876;
	case 2171ULL: goto x86_l_87b;
	case 2173ULL: goto x86_l_87d;
	case 2175ULL: goto x86_l_87f;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2199ULL: goto x86_l_897;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2223ULL: goto x86_l_8af;
	case 2227ULL: goto x86_l_8b3;
	case 2232ULL: goto x86_l_8b8;
	case 2234ULL: goto x86_l_8ba;
	case 2236ULL: goto x86_l_8bc;
	case 2242ULL: goto x86_l_8c2;
	case 2247ULL: goto x86_l_8c7;
	case 2253ULL: goto x86_l_8cd;
	case 2256ULL: goto x86_l_8d0;
	case 2260ULL: goto x86_l_8d4;
	case 2264ULL: goto x86_l_8d8;
	case 2269ULL: goto x86_l_8dd;
	case 2271ULL: goto x86_l_8df;
	case 2276ULL: goto x86_l_8e4;
	case 2281ULL: goto x86_l_8e9;
	case 2284ULL: goto x86_l_8ec;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2295ULL: goto x86_l_8f7;
	case 2297ULL: goto x86_l_8f9;
	case 2303ULL: goto x86_l_8ff;
	case 2308ULL: goto x86_l_904;
	case 2314ULL: goto x86_l_90a;
	case 2317ULL: goto x86_l_90d;
	case 2321ULL: goto x86_l_911;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2345ULL: goto x86_l_929;
	case 2349ULL: goto x86_l_92d;
	case 2354ULL: goto x86_l_932;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2375ULL: goto x86_l_947;
	case 2378ULL: goto x86_l_94a;
	case 2382ULL: goto x86_l_94e;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2403ULL: goto x86_l_963;
	case 2406ULL: goto x86_l_966;
	case 2410ULL: goto x86_l_96a;
	case 2415ULL: goto x86_l_96f;
	case 2417ULL: goto x86_l_971;
	case 2419ULL: goto x86_l_973;
	case 2425ULL: goto x86_l_979;
	case 2430ULL: goto x86_l_97e;
	case 2436ULL: goto x86_l_984;
	case 2439ULL: goto x86_l_987;
	case 2443ULL: goto x86_l_98b;
	case 2447ULL: goto x86_l_98f;
	case 2452ULL: goto x86_l_994;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2467ULL: goto x86_l_9a3;
	case 2471ULL: goto x86_l_9a7;
	case 2476ULL: goto x86_l_9ac;
	case 2478ULL: goto x86_l_9ae;
	case 2480ULL: goto x86_l_9b0;
	case 2486ULL: goto x86_l_9b6;
	case 2491ULL: goto x86_l_9bb;
	case 2497ULL: goto x86_l_9c1;
	case 2500ULL: goto x86_l_9c4;
	case 2504ULL: goto x86_l_9c8;
	case 2508ULL: goto x86_l_9cc;
	case 2513ULL: goto x86_l_9d1;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2528ULL: goto x86_l_9e0;
	case 2532ULL: goto x86_l_9e4;
	case 2537ULL: goto x86_l_9e9;
	case 2539ULL: goto x86_l_9eb;
	case 2541ULL: goto x86_l_9ed;
	case 2547ULL: goto x86_l_9f3;
	case 2552ULL: goto x86_l_9f8;
	case 2558ULL: goto x86_l_9fe;
	case 2561ULL: goto x86_l_a01;
	case 2565ULL: goto x86_l_a05;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2589ULL: goto x86_l_a1d;
	case 2593ULL: goto x86_l_a21;
	case 2598ULL: goto x86_l_a26;
	case 2600ULL: goto x86_l_a28;
	case 2602ULL: goto x86_l_a2a;
	case 2608ULL: goto x86_l_a30;
	case 2612ULL: goto x86_l_a34;
	case 2618ULL: goto x86_l_a3a;
	case 2621ULL: goto x86_l_a3d;
	case 2625ULL: goto x86_l_a41;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2640ULL: goto x86_l_a50;
	case 2645ULL: goto x86_l_a55;
	case 2650ULL: goto x86_l_a5a;
	case 2653ULL: goto x86_l_a5d;
	case 2658ULL: goto x86_l_a62;
	case 2661ULL: goto x86_l_a65;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2673ULL: goto x86_l_a71;
	case 2676ULL: goto x86_l_a74;
	case 2680ULL: goto x86_l_a78;
	case 2685ULL: goto x86_l_a7d;
	case 2687ULL: goto x86_l_a7f;
	case 2689ULL: goto x86_l_a81;
	case 2695ULL: goto x86_l_a87;
	case 2700ULL: goto x86_l_a8c;
	case 2706ULL: goto x86_l_a92;
	case 2709ULL: goto x86_l_a95;
	case 2713ULL: goto x86_l_a99;
	case 2717ULL: goto x86_l_a9d;
	case 2722ULL: goto x86_l_aa2;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2737ULL: goto x86_l_ab1;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2748ULL: goto x86_l_abc;
	case 2750ULL: goto x86_l_abe;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2767ULL: goto x86_l_acf;
	case 2770ULL: goto x86_l_ad2;
	case 2774ULL: goto x86_l_ad6;
	case 2778ULL: goto x86_l_ada;
	case 2783ULL: goto x86_l_adf;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2798ULL: goto x86_l_aee;
	case 2802ULL: goto x86_l_af2;
	case 2807ULL: goto x86_l_af7;
	case 2809ULL: goto x86_l_af9;
	case 2811ULL: goto x86_l_afb;
	case 2817ULL: goto x86_l_b01;
	case 2822ULL: goto x86_l_b06;
	case 2828ULL: goto x86_l_b0c;
	case 2831ULL: goto x86_l_b0f;
	case 2835ULL: goto x86_l_b13;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2859ULL: goto x86_l_b2b;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2870ULL: goto x86_l_b36;
	case 2872ULL: goto x86_l_b38;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2889ULL: goto x86_l_b49;
	case 2892ULL: goto x86_l_b4c;
	case 2896ULL: goto x86_l_b50;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2920ULL: goto x86_l_b68;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2931ULL: goto x86_l_b73;
	case 2933ULL: goto x86_l_b75;
	case 2939ULL: goto x86_l_b7b;
	case 2944ULL: goto x86_l_b80;
	case 2950ULL: goto x86_l_b86;
	case 2953ULL: goto x86_l_b89;
	case 2957ULL: goto x86_l_b8d;
	case 2961ULL: goto x86_l_b91;
	case 2966ULL: goto x86_l_b96;
	case 2968ULL: goto x86_l_b98;
	case 2973ULL: goto x86_l_b9d;
	case 2978ULL: goto x86_l_ba2;
	case 2981ULL: goto x86_l_ba5;
	case 2985ULL: goto x86_l_ba9;
	case 2990ULL: goto x86_l_bae;
	case 2992ULL: goto x86_l_bb0;
	case 2994ULL: goto x86_l_bb2;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3018ULL: goto x86_l_bca;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3042ULL: goto x86_l_be2;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3053ULL: goto x86_l_bed;
	case 3055ULL: goto x86_l_bef;
	case 3061ULL: goto x86_l_bf5;
	case 3066ULL: goto x86_l_bfa;
	case 3072ULL: goto x86_l_c00;
	case 3075ULL: goto x86_l_c03;
	case 3079ULL: goto x86_l_c07;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3090ULL: goto x86_l_c12;
	case 3095ULL: goto x86_l_c17;
	case 3100ULL: goto x86_l_c1c;
	case 3103ULL: goto x86_l_c1f;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3116ULL: goto x86_l_c2c;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3133ULL: goto x86_l_c3d;
	case 3136ULL: goto x86_l_c40;
	case 3140ULL: goto x86_l_c44;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3164ULL: goto x86_l_c5c;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3175ULL: goto x86_l_c67;
	case 3177ULL: goto x86_l_c69;
	case 3183ULL: goto x86_l_c6f;
	case 3187ULL: goto x86_l_c73;
	case 3193ULL: goto x86_l_c79;
	case 3196ULL: goto x86_l_c7c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_675:
	/* 0x675: je     697 <generic_sleepable_preload+0x697> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_697;
	}
x86_l_677:
	/* 0x677: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_67c:
	/* 0x67c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_681:
	/* 0x681: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_684:
	/* 0x684: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_688:
	/* 0x688: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68d:
	/* 0x68d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68f:
	/* 0x68f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_691:
	/* 0x691: js     d1d <generic_sleepable_preload+0xd1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3357ULL;
	}
x86_l_697:
	/* 0x697: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_69c:
	/* 0x69c: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_6a2:
	/* 0x6a2: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_6a5:
	/* 0x6a5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6a9:
	/* 0x6a9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ad:
	/* 0x6ad: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_6b2:
	/* 0x6b2: je     6d4 <generic_sleepable_preload+0x6d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6d4;
	}
x86_l_6b4:
	/* 0x6b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6b9:
	/* 0x6b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6be:
	/* 0x6be: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6c1:
	/* 0x6c1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c5:
	/* 0x6c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ca:
	/* 0x6ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cc:
	/* 0x6cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6ce:
	/* 0x6ce: js     ebb <generic_sleepable_preload+0xebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3771ULL;
	}
x86_l_6d4:
	/* 0x6d4: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_6d9:
	/* 0x6d9: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_6df:
	/* 0x6df: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_6e2:
	/* 0x6e2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6e6:
	/* 0x6e6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ea:
	/* 0x6ea: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_6ef:
	/* 0x6ef: je     711 <generic_sleepable_preload+0x711> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_711;
	}
x86_l_6f1:
	/* 0x6f1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6f6:
	/* 0x6f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6fb:
	/* 0x6fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6fe:
	/* 0x6fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_702:
	/* 0x702: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_707:
	/* 0x707: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_709:
	/* 0x709: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_70b:
	/* 0x70b: js     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3807ULL;
	}
x86_l_711:
	/* 0x711: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_715:
	/* 0x715: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_71b:
	/* 0x71b: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_71e:
	/* 0x71e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_722:
	/* 0x722: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_726:
	/* 0x726: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_72b:
	/* 0x72b: je     d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3365ULL;
	}
x86_l_731:
	/* 0x731: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_736:
	/* 0x736: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_73b:
	/* 0x73b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_73e:
	/* 0x73e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_742:
	/* 0x742: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_747:
	/* 0x747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_749:
	/* 0x749: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_74b:
	/* 0x74b: jns    d25 <generic_sleepable_preload+0xd25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3365ULL;
	}
x86_l_751:
	/* 0x751: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_757:
	/* 0x757: jmp    d23 <generic_sleepable_preload+0xd23> */
	return 3363ULL;
x86_l_75c:
	/* 0x75c: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_762:
	/* 0x762: jmp    d23 <generic_sleepable_preload+0xd23> */
	return 3363ULL;
x86_l_767:
	/* 0x767: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_76f:
	/* 0x76f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_772:
	/* 0x772: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d7;
	}
x86_l_774:
	/* 0x774: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_779:
	/* 0x779: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_77e:
	/* 0x77e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_781:
	/* 0x781: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d7;
	}
x86_l_783:
	/* 0x783: jmp    7ea <generic_sleepable_preload+0x7ea> */
	goto x86_l_7ea;
x86_l_785:
	/* 0x785: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_78a:
	/* 0x78a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_78d:
	/* 0x78d: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d7;
	}
x86_l_78f:
	/* 0x78f: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_794:
	/* 0x794: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_799:
	/* 0x799: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_79c:
	/* 0x79c: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d7;
	}
x86_l_79e:
	/* 0x79e: jmp    7ea <generic_sleepable_preload+0x7ea> */
	goto x86_l_7ea;
x86_l_7a0:
	/* 0x7a0: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7a8:
	/* 0x7a8: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7ab:
	/* 0x7ab: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d7;
	}
x86_l_7ad:
	/* 0x7ad: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7b2:
	/* 0x7b2: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7b7:
	/* 0x7b7: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_7ba:
	/* 0x7ba: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d7;
	}
x86_l_7bc:
	/* 0x7bc: jmp    7ea <generic_sleepable_preload+0x7ea> */
	goto x86_l_7ea;
x86_l_7be:
	/* 0x7be: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7c3:
	/* 0x7c3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_7c6:
	/* 0x7c6: je     7d7 <generic_sleepable_preload+0x7d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d7;
	}
x86_l_7c8:
	/* 0x7c8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7cd:
	/* 0x7cd: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_7d2:
	/* 0x7d2: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_7d5:
	/* 0x7d5: jne    7ea <generic_sleepable_preload+0x7ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7ea;
	}
x86_l_7d7:
	/* 0x7d7: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_7da:
	/* 0x7da: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_7dc:
	/* 0x7dc: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_7de:
	/* 0x7de: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_7e3:
	/* 0x7e3: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7e5:
	/* 0x7e5: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_7ea:
	/* 0x7ea: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ee:
	/* 0x7ee: mov    r12d,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_7f3:
	/* 0x7f3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f5:
	/* 0x7f5: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_7f8:
	/* 0x7f8: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_7fd:
	/* 0x7fd: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_803:
	/* 0x803: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_80a:
	/* 0x80a: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_80d:
	/* 0x80d: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_810:
	/* 0x810: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_813:
	/* 0x813: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_817:
	/* 0x817: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_81b:
	/* 0x81b: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_81d:
	/* 0x81d: je     a62 <generic_sleepable_preload+0xa62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a62;
	}
x86_l_823:
	/* 0x823: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_826:
	/* 0x826: je     848 <generic_sleepable_preload+0x848> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_848;
	}
x86_l_828:
	/* 0x828: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_82d:
	/* 0x82d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_832:
	/* 0x832: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_835:
	/* 0x835: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_839:
	/* 0x839: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_83e:
	/* 0x83e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_840:
	/* 0x840: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_842:
	/* 0x842: js     cb9 <generic_sleepable_preload+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3257ULL;
	}
x86_l_848:
	/* 0x848: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_84d:
	/* 0x84d: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_853:
	/* 0x853: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_856:
	/* 0x856: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_85a:
	/* 0x85a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_85e:
	/* 0x85e: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_863:
	/* 0x863: je     885 <generic_sleepable_preload+0x885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_885;
	}
x86_l_865:
	/* 0x865: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_86a:
	/* 0x86a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_86f:
	/* 0x86f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_872:
	/* 0x872: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_876:
	/* 0x876: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_87b:
	/* 0x87b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87d:
	/* 0x87d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_87f:
	/* 0x87f: js     ccb <generic_sleepable_preload+0xccb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3275ULL;
	}
x86_l_885:
	/* 0x885: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_88a:
	/* 0x88a: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_890:
	/* 0x890: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_893:
	/* 0x893: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_897:
	/* 0x897: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89b:
	/* 0x89b: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_8a0:
	/* 0x8a0: je     8c2 <generic_sleepable_preload+0x8c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c2;
	}
x86_l_8a2:
	/* 0x8a2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8a7:
	/* 0x8a7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8ac:
	/* 0x8ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8af:
	/* 0x8af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b3:
	/* 0x8b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b8:
	/* 0x8b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ba:
	/* 0x8ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8bc:
	/* 0x8bc: js     cdd <generic_sleepable_preload+0xcdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3293ULL;
	}
x86_l_8c2:
	/* 0x8c2: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_8c7:
	/* 0x8c7: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_8cd:
	/* 0x8cd: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_8d0:
	/* 0x8d0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8d4:
	/* 0x8d4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8d8:
	/* 0x8d8: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_8dd:
	/* 0x8dd: je     8ff <generic_sleepable_preload+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ff;
	}
x86_l_8df:
	/* 0x8df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8e4:
	/* 0x8e4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8e9:
	/* 0x8e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8ec:
	/* 0x8ec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f0:
	/* 0x8f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8f5:
	/* 0x8f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f7:
	/* 0x8f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8f9:
	/* 0x8f9: js     cef <generic_sleepable_preload+0xcef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3311ULL;
	}
x86_l_8ff:
	/* 0x8ff: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_904:
	/* 0x904: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_90a:
	/* 0x90a: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_90d:
	/* 0x90d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_911:
	/* 0x911: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_915:
	/* 0x915: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_91a:
	/* 0x91a: je     93c <generic_sleepable_preload+0x93c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93c;
	}
x86_l_91c:
	/* 0x91c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_921:
	/* 0x921: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_926:
	/* 0x926: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_929:
	/* 0x929: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92d:
	/* 0x92d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_932:
	/* 0x932: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_934:
	/* 0x934: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_936:
	/* 0x936: js     d01 <generic_sleepable_preload+0xd01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3329ULL;
	}
x86_l_93c:
	/* 0x93c: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_941:
	/* 0x941: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_947:
	/* 0x947: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_94a:
	/* 0x94a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_94e:
	/* 0x94e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_952:
	/* 0x952: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_957:
	/* 0x957: je     979 <generic_sleepable_preload+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_979;
	}
x86_l_959:
	/* 0x959: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_95e:
	/* 0x95e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_963:
	/* 0x963: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_966:
	/* 0x966: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96a:
	/* 0x96a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_96f:
	/* 0x96f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_971:
	/* 0x971: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_973:
	/* 0x973: js     d13 <generic_sleepable_preload+0xd13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3347ULL;
	}
x86_l_979:
	/* 0x979: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_97e:
	/* 0x97e: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_984:
	/* 0x984: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_987:
	/* 0x987: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_98b:
	/* 0x98b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98f:
	/* 0x98f: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_994:
	/* 0x994: je     9b6 <generic_sleepable_preload+0x9b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9b6;
	}
x86_l_996:
	/* 0x996: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_99b:
	/* 0x99b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9a0:
	/* 0x9a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9a3:
	/* 0x9a3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a7:
	/* 0x9a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ac:
	/* 0x9ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ae:
	/* 0x9ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9b0:
	/* 0x9b0: js     dfe <generic_sleepable_preload+0xdfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3582ULL;
	}
x86_l_9b6:
	/* 0x9b6: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_9bb:
	/* 0x9bb: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_9c1:
	/* 0x9c1: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_9c4:
	/* 0x9c4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9c8:
	/* 0x9c8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9cc:
	/* 0x9cc: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_9d1:
	/* 0x9d1: je     9f3 <generic_sleepable_preload+0x9f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f3;
	}
x86_l_9d3:
	/* 0x9d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9d8:
	/* 0x9d8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9dd:
	/* 0x9dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9e0:
	/* 0x9e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e4:
	/* 0x9e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e9:
	/* 0x9e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9eb:
	/* 0x9eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9ed:
	/* 0x9ed: js     ec8 <generic_sleepable_preload+0xec8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3784ULL;
	}
x86_l_9f3:
	/* 0x9f3: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_9f8:
	/* 0x9f8: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_9fe:
	/* 0x9fe: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_a01:
	/* 0xa01: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a05:
	/* 0xa05: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a09:
	/* 0xa09: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_a0e:
	/* 0xa0e: je     a30 <generic_sleepable_preload+0xa30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a30;
	}
x86_l_a10:
	/* 0xa10: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a15:
	/* 0xa15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a1a:
	/* 0xa1a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a1d:
	/* 0xa1d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a21:
	/* 0xa21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a26:
	/* 0xa26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a28:
	/* 0xa28: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a2a:
	/* 0xa2a: js     eea <generic_sleepable_preload+0xeea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3818ULL;
	}
x86_l_a30:
	/* 0xa30: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a34:
	/* 0xa34: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_a3a:
	/* 0xa3a: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_a3d:
	/* 0xa3d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a41:
	/* 0xa41: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a45:
	/* 0xa45: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_a4a:
	/* 0xa4a: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_a50:
	/* 0xa50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a55:
	/* 0xa55: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a5a:
	/* 0xa5a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a5d:
	/* 0xa5d: jmp    c9c <generic_sleepable_preload+0xc9c> */
	return 3228ULL;
x86_l_a62:
	/* 0xa62: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_a65:
	/* 0xa65: je     a87 <generic_sleepable_preload+0xa87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a87;
	}
x86_l_a67:
	/* 0xa67: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a6c:
	/* 0xa6c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a71:
	/* 0xa71: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a74:
	/* 0xa74: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a78:
	/* 0xa78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a7d:
	/* 0xa7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7f:
	/* 0xa7f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a81:
	/* 0xa81: js     cb9 <generic_sleepable_preload+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3257ULL;
	}
x86_l_a87:
	/* 0xa87: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_a8c:
	/* 0xa8c: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_a92:
	/* 0xa92: mov    ecx,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_a95:
	/* 0xa95: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a99:
	/* 0xa99: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9d:
	/* 0xa9d: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_aa2:
	/* 0xaa2: je     ac4 <generic_sleepable_preload+0xac4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac4;
	}
x86_l_aa4:
	/* 0xaa4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_aa9:
	/* 0xaa9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_aae:
	/* 0xaae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ab1:
	/* 0xab1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab5:
	/* 0xab5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aba:
	/* 0xaba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abc:
	/* 0xabc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_abe:
	/* 0xabe: js     ccb <generic_sleepable_preload+0xccb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3275ULL;
	}
x86_l_ac4:
	/* 0xac4: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_ac9:
	/* 0xac9: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_acf:
	/* 0xacf: mov    ecx,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_ad2:
	/* 0xad2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ad6:
	/* 0xad6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ada:
	/* 0xada: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_adf:
	/* 0xadf: je     b01 <generic_sleepable_preload+0xb01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b01;
	}
x86_l_ae1:
	/* 0xae1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ae6:
	/* 0xae6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_aeb:
	/* 0xaeb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_aee:
	/* 0xaee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af2:
	/* 0xaf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af7:
	/* 0xaf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af9:
	/* 0xaf9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_afb:
	/* 0xafb: js     cdd <generic_sleepable_preload+0xcdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3293ULL;
	}
x86_l_b01:
	/* 0xb01: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_b06:
	/* 0xb06: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_b0c:
	/* 0xb0c: mov    ecx,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_b0f:
	/* 0xb0f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b13:
	/* 0xb13: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b17:
	/* 0xb17: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_b1c:
	/* 0xb1c: je     b3e <generic_sleepable_preload+0xb3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3e;
	}
x86_l_b1e:
	/* 0xb1e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b23:
	/* 0xb23: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b28:
	/* 0xb28: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b2b:
	/* 0xb2b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2f:
	/* 0xb2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b34:
	/* 0xb34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b36:
	/* 0xb36: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b38:
	/* 0xb38: js     cef <generic_sleepable_preload+0xcef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3311ULL;
	}
x86_l_b3e:
	/* 0xb3e: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_b43:
	/* 0xb43: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_b49:
	/* 0xb49: mov    ecx,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_b4c:
	/* 0xb4c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b50:
	/* 0xb50: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b54:
	/* 0xb54: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_b59:
	/* 0xb59: je     b7b <generic_sleepable_preload+0xb7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7b;
	}
x86_l_b5b:
	/* 0xb5b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b60:
	/* 0xb60: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b65:
	/* 0xb65: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b68:
	/* 0xb68: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6c:
	/* 0xb6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b71:
	/* 0xb71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b73:
	/* 0xb73: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b75:
	/* 0xb75: js     d01 <generic_sleepable_preload+0xd01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3329ULL;
	}
x86_l_b7b:
	/* 0xb7b: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_b80:
	/* 0xb80: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_b86:
	/* 0xb86: mov    ecx,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_b89:
	/* 0xb89: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b8d:
	/* 0xb8d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b91:
	/* 0xb91: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_b96:
	/* 0xb96: je     bb8 <generic_sleepable_preload+0xbb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb8;
	}
x86_l_b98:
	/* 0xb98: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b9d:
	/* 0xb9d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ba2:
	/* 0xba2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ba5:
	/* 0xba5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba9:
	/* 0xba9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bae:
	/* 0xbae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb0:
	/* 0xbb0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bb2:
	/* 0xbb2: js     d13 <generic_sleepable_preload+0xd13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3347ULL;
	}
x86_l_bb8:
	/* 0xbb8: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_bbd:
	/* 0xbbd: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_bc3:
	/* 0xbc3: mov    ecx,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_bc6:
	/* 0xbc6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_bca:
	/* 0xbca: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bce:
	/* 0xbce: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_bd3:
	/* 0xbd3: je     bf5 <generic_sleepable_preload+0xbf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf5;
	}
x86_l_bd5:
	/* 0xbd5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bda:
	/* 0xbda: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bdf:
	/* 0xbdf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_be2:
	/* 0xbe2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be6:
	/* 0xbe6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_beb:
	/* 0xbeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bed:
	/* 0xbed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bef:
	/* 0xbef: js     dfe <generic_sleepable_preload+0xdfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3582ULL;
	}
x86_l_bf5:
	/* 0xbf5: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_bfa:
	/* 0xbfa: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_c00:
	/* 0xc00: mov    ecx,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_c03:
	/* 0xc03: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c07:
	/* 0xc07: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0b:
	/* 0xc0b: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_c10:
	/* 0xc10: je     c32 <generic_sleepable_preload+0xc32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c32;
	}
x86_l_c12:
	/* 0xc12: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c17:
	/* 0xc17: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c1c:
	/* 0xc1c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c1f:
	/* 0xc1f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c23:
	/* 0xc23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c28:
	/* 0xc28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2a:
	/* 0xc2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c2c:
	/* 0xc2c: js     ec8 <generic_sleepable_preload+0xec8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3784ULL;
	}
x86_l_c32:
	/* 0xc32: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_c37:
	/* 0xc37: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_c3d:
	/* 0xc3d: mov    ecx,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_c40:
	/* 0xc40: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c44:
	/* 0xc44: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c48:
	/* 0xc48: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_c4d:
	/* 0xc4d: je     c6f <generic_sleepable_preload+0xc6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c6f;
	}
x86_l_c4f:
	/* 0xc4f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c54:
	/* 0xc54: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c59:
	/* 0xc59: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c5c:
	/* 0xc5c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c60:
	/* 0xc60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c65:
	/* 0xc65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c67:
	/* 0xc67: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c69:
	/* 0xc69: js     eea <generic_sleepable_preload+0xeea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3818ULL;
	}
x86_l_c6f:
	/* 0xc6f: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c73:
	/* 0xc73: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_c79:
	/* 0xc79: mov    ecx,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_c7c:
	/* 0xc7c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
	return 3200ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3200ULL: goto x86_l_c80;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3215ULL: goto x86_l_c8f;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3228ULL: goto x86_l_c9c;
	case 3232ULL: goto x86_l_ca0;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3241ULL: goto x86_l_ca9;
	case 3247ULL: goto x86_l_caf;
	case 3252ULL: goto x86_l_cb4;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3267ULL: goto x86_l_cc3;
	case 3273ULL: goto x86_l_cc9;
	case 3275ULL: goto x86_l_ccb;
	case 3280ULL: goto x86_l_cd0;
	case 3285ULL: goto x86_l_cd5;
	case 3291ULL: goto x86_l_cdb;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3309ULL: goto x86_l_ced;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3329ULL: goto x86_l_d01;
	case 3334ULL: goto x86_l_d06;
	case 3339ULL: goto x86_l_d0b;
	case 3345ULL: goto x86_l_d11;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3363ULL: goto x86_l_d23;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3380ULL: goto x86_l_d34;
	case 3383ULL: goto x86_l_d37;
	case 3388ULL: goto x86_l_d3c;
	case 3391ULL: goto x86_l_d3f;
	case 3393ULL: goto x86_l_d41;
	case 3397ULL: goto x86_l_d45;
	case 3403ULL: goto x86_l_d4b;
	case 3407ULL: goto x86_l_d4f;
	case 3415ULL: goto x86_l_d57;
	case 3420ULL: goto x86_l_d5c;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3435ULL: goto x86_l_d6b;
	case 3440ULL: goto x86_l_d70;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3454ULL: goto x86_l_d7e;
	case 3457ULL: goto x86_l_d81;
	case 3463ULL: goto x86_l_d87;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3473ULL: goto x86_l_d91;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3494ULL: goto x86_l_da6;
	case 3497ULL: goto x86_l_da9;
	case 3499ULL: goto x86_l_dab;
	case 3501ULL: goto x86_l_dad;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3514ULL: goto x86_l_dba;
	case 3517ULL: goto x86_l_dbd;
	case 3523ULL: goto x86_l_dc3;
	case 3526ULL: goto x86_l_dc6;
	case 3532ULL: goto x86_l_dcc;
	case 3536ULL: goto x86_l_dd0;
	case 3541ULL: goto x86_l_dd5;
	case 3549ULL: goto x86_l_ddd;
	case 3551ULL: goto x86_l_ddf;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3566ULL: goto x86_l_dee;
	case 3572ULL: goto x86_l_df4;
	case 3577ULL: goto x86_l_df9;
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3590ULL: goto x86_l_e06;
	case 3594ULL: goto x86_l_e0a;
	case 3600ULL: goto x86_l_e10;
	case 3604ULL: goto x86_l_e14;
	case 3612ULL: goto x86_l_e1c;
	case 3617ULL: goto x86_l_e21;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3651ULL: goto x86_l_e43;
	case 3654ULL: goto x86_l_e46;
	case 3660ULL: goto x86_l_e4c;
	case 3663ULL: goto x86_l_e4f;
	case 3668ULL: goto x86_l_e54;
	case 3670ULL: goto x86_l_e56;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3691ULL: goto x86_l_e6b;
	case 3694ULL: goto x86_l_e6e;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3706ULL: goto x86_l_e7a;
	case 3709ULL: goto x86_l_e7d;
	case 3711ULL: goto x86_l_e7f;
	case 3714ULL: goto x86_l_e82;
	case 3720ULL: goto x86_l_e88;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3728ULL: goto x86_l_e90;
	case 3732ULL: goto x86_l_e94;
	case 3737ULL: goto x86_l_e99;
	case 3745ULL: goto x86_l_ea1;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3756ULL: goto x86_l_eac;
	case 3762ULL: goto x86_l_eb2;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3773ULL: goto x86_l_ebd;
	case 3779ULL: goto x86_l_ec3;
	case 3784ULL: goto x86_l_ec8;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3796ULL: goto x86_l_ed4;
	case 3802ULL: goto x86_l_eda;
	case 3807ULL: goto x86_l_edf;
	case 3813ULL: goto x86_l_ee5;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3844ULL: goto x86_l_f04;
	case 3846ULL: goto x86_l_f06;
	case 3848ULL: goto x86_l_f08;
	case 3853ULL: goto x86_l_f0d;
	case 3856ULL: goto x86_l_f10;
	case 3862ULL: goto x86_l_f16;
	case 3865ULL: goto x86_l_f19;
	case 3871ULL: goto x86_l_f1f;
	case 3874ULL: goto x86_l_f22;
	case 3880ULL: goto x86_l_f28;
	case 3883ULL: goto x86_l_f2b;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3899ULL: goto x86_l_f3b;
	case 3908ULL: goto x86_l_f44;
	case 3917ULL: goto x86_l_f4d;
	case 3923ULL: goto x86_l_f53;
	case 3925ULL: goto x86_l_f55;
	case 3928ULL: goto x86_l_f58;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3952ULL: goto x86_l_f70;
	case 3958ULL: goto x86_l_f76;
	case 3963ULL: goto x86_l_f7b;
	case 3966ULL: goto x86_l_f7e;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3994ULL: goto x86_l_f9a;
	case 3996ULL: goto x86_l_f9c;
	case 3999ULL: goto x86_l_f9f;
	case 4005ULL: goto x86_l_fa5;
	case 4010ULL: goto x86_l_faa;
	case 4012ULL: goto x86_l_fac;
	case 4018ULL: goto x86_l_fb2;
	case 4021ULL: goto x86_l_fb5;
	case 4024ULL: goto x86_l_fb8;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4037ULL: goto x86_l_fc5;
	case 4039ULL: goto x86_l_fc7;
	case 4042ULL: goto x86_l_fca;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4051ULL: goto x86_l_fd3;
	case 4054ULL: goto x86_l_fd6;
	case 4060ULL: goto x86_l_fdc;
	case 4068ULL: goto x86_l_fe4;
	case 4071ULL: goto x86_l_fe7;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4085ULL: goto x86_l_ff5;
	case 4091ULL: goto x86_l_ffb;
	case 4096ULL: goto x86_l_1000;
	case 4099ULL: goto x86_l_1003;
	case 4105ULL: goto x86_l_1009;
	case 4113ULL: goto x86_l_1011;
	case 4116ULL: goto x86_l_1014;
	case 4122ULL: goto x86_l_101a;
	case 4127ULL: goto x86_l_101f;
	case 4130ULL: goto x86_l_1022;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4155ULL: goto x86_l_103b;
	case 4160ULL: goto x86_l_1040;
	case 4163ULL: goto x86_l_1043;
	case 4167ULL: goto x86_l_1047;
	case 4169ULL: goto x86_l_1049;
	case 4172ULL: goto x86_l_104c;
	case 4179ULL: goto x86_l_1053;
	case 4185ULL: goto x86_l_1059;
	case 4192ULL: goto x86_l_1060;
	case 4195ULL: goto x86_l_1063;
	case 4200ULL: goto x86_l_1068;
	case 4203ULL: goto x86_l_106b;
	case 4207ULL: goto x86_l_106f;
	case 4213ULL: goto x86_l_1075;
	case 4215ULL: goto x86_l_1077;
	case 4221ULL: goto x86_l_107d;
	case 4224ULL: goto x86_l_1080;
	case 4226ULL: goto x86_l_1082;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4243ULL: goto x86_l_1093;
	case 4248ULL: goto x86_l_1098;
	case 4250ULL: goto x86_l_109a;
	case 4252ULL: goto x86_l_109c;
	case 4258ULL: goto x86_l_10a2;
	case 4265ULL: goto x86_l_10a9;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4280ULL: goto x86_l_10b8;
	case 4284ULL: goto x86_l_10bc;
	case 4291ULL: goto x86_l_10c3;
	case 4293ULL: goto x86_l_10c5;
	case 4296ULL: goto x86_l_10c8;
	case 4301ULL: goto x86_l_10cd;
	case 4306ULL: goto x86_l_10d2;
	case 4310ULL: goto x86_l_10d6;
	case 4315ULL: goto x86_l_10db;
	case 4317ULL: goto x86_l_10dd;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4335ULL: goto x86_l_10ef;
	case 4341ULL: goto x86_l_10f5;
	case 4349ULL: goto x86_l_10fd;
	case 4353ULL: goto x86_l_1101;
	case 4357ULL: goto x86_l_1105;
	case 4367ULL: goto x86_l_110f;
	case 4369ULL: goto x86_l_1111;
	case 4372ULL: goto x86_l_1114;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4386ULL: goto x86_l_1122;
	case 4391ULL: goto x86_l_1127;
	case 4393ULL: goto x86_l_1129;
	case 4395ULL: goto x86_l_112b;
	case 4401ULL: goto x86_l_1131;
	case 4411ULL: goto x86_l_113b;
	case 4417ULL: goto x86_l_1141;
	case 4425ULL: goto x86_l_1149;
	case 4429ULL: goto x86_l_114d;
	case 4433ULL: goto x86_l_1151;
	case 4443ULL: goto x86_l_115b;
	case 4445ULL: goto x86_l_115d;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4462ULL: goto x86_l_116e;
	case 4467ULL: goto x86_l_1173;
	case 4469ULL: goto x86_l_1175;
	case 4471ULL: goto x86_l_1177;
	case 4477ULL: goto x86_l_117d;
	case 4487ULL: goto x86_l_1187;
	case 4493ULL: goto x86_l_118d;
	case 4501ULL: goto x86_l_1195;
	case 4505ULL: goto x86_l_1199;
	case 4509ULL: goto x86_l_119d;
	case 4519ULL: goto x86_l_11a7;
	case 4521ULL: goto x86_l_11a9;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4538ULL: goto x86_l_11ba;
	case 4543ULL: goto x86_l_11bf;
	case 4545ULL: goto x86_l_11c1;
	case 4547ULL: goto x86_l_11c3;
	case 4553ULL: goto x86_l_11c9;
	case 4563ULL: goto x86_l_11d3;
	case 4569ULL: goto x86_l_11d9;
	case 4577ULL: goto x86_l_11e1;
	case 4581ULL: goto x86_l_11e5;
	case 4585ULL: goto x86_l_11e9;
	case 4595ULL: goto x86_l_11f3;
	case 4597ULL: goto x86_l_11f5;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4621ULL: goto x86_l_120d;
	case 4623ULL: goto x86_l_120f;
	case 4629ULL: goto x86_l_1215;
	case 4639ULL: goto x86_l_121f;
	case 4645ULL: goto x86_l_1225;
	case 4653ULL: goto x86_l_122d;
	case 4657ULL: goto x86_l_1231;
	case 4661ULL: goto x86_l_1235;
	case 4671ULL: goto x86_l_123f;
	case 4673ULL: goto x86_l_1241;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4690ULL: goto x86_l_1252;
	case 4695ULL: goto x86_l_1257;
	case 4697ULL: goto x86_l_1259;
	case 4699ULL: goto x86_l_125b;
	case 4705ULL: goto x86_l_1261;
	case 4715ULL: goto x86_l_126b;
	case 4721ULL: goto x86_l_1271;
	case 4729ULL: goto x86_l_1279;
	case 4733ULL: goto x86_l_127d;
	case 4737ULL: goto x86_l_1281;
	case 4747ULL: goto x86_l_128b;
	case 4749ULL: goto x86_l_128d;
	case 4752ULL: goto x86_l_1290;
	case 4757ULL: goto x86_l_1295;
	case 4762ULL: goto x86_l_129a;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4773ULL: goto x86_l_12a5;
	case 4775ULL: goto x86_l_12a7;
	case 4781ULL: goto x86_l_12ad;
	case 4791ULL: goto x86_l_12b7;
	case 4797ULL: goto x86_l_12bd;
	case 4805ULL: goto x86_l_12c5;
	case 4809ULL: goto x86_l_12c9;
	case 4813ULL: goto x86_l_12cd;
	case 4823ULL: goto x86_l_12d7;
	case 4825ULL: goto x86_l_12d9;
	case 4828ULL: goto x86_l_12dc;
	case 4833ULL: goto x86_l_12e1;
	case 4838ULL: goto x86_l_12e6;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4849ULL: goto x86_l_12f1;
	case 4851ULL: goto x86_l_12f3;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4872ULL: goto x86_l_1308;
	case 4878ULL: goto x86_l_130e;
	case 4886ULL: goto x86_l_1316;
	case 4890ULL: goto x86_l_131a;
	case 4894ULL: goto x86_l_131e;
	case 4904ULL: goto x86_l_1328;
	case 4910ULL: goto x86_l_132e;
	case 4913ULL: goto x86_l_1331;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4931ULL: goto x86_l_1343;
	case 4933ULL: goto x86_l_1345;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_c80:
	/* 0xc80: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c84:
	/* 0xc84: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_c89:
	/* 0xc89: je     e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e06;
	}
x86_l_c8f:
	/* 0xc8f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c94:
	/* 0xc94: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c99:
	/* 0xc99: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c9c:
	/* 0xc9c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca0:
	/* 0xca0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca5:
	/* 0xca5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca7:
	/* 0xca7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ca9:
	/* 0xca9: jns    e06 <generic_sleepable_preload+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_e06;
	}
x86_l_caf:
	/* 0xcaf: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_cb4:
	/* 0xcb4: jmp    e03 <generic_sleepable_preload+0xe03> */
	goto x86_l_e03;
x86_l_cb9:
	/* 0xcb9: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_cbe:
	/* 0xcbe: jmp    e03 <generic_sleepable_preload+0xe03> */
	goto x86_l_e03;
x86_l_cc3:
	/* 0xcc3: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_cc9:
	/* 0xcc9: jmp    d23 <generic_sleepable_preload+0xd23> */
	goto x86_l_d23;
x86_l_ccb:
	/* 0xccb: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_cd0:
	/* 0xcd0: jmp    e03 <generic_sleepable_preload+0xe03> */
	goto x86_l_e03;
x86_l_cd5:
	/* 0xcd5: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_cdb:
	/* 0xcdb: jmp    d23 <generic_sleepable_preload+0xd23> */
	goto x86_l_d23;
x86_l_cdd:
	/* 0xcdd: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_ce2:
	/* 0xce2: jmp    e03 <generic_sleepable_preload+0xe03> */
	goto x86_l_e03;
x86_l_ce7:
	/* 0xce7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_ced:
	/* 0xced: jmp    d23 <generic_sleepable_preload+0xd23> */
	goto x86_l_d23;
x86_l_cef:
	/* 0xcef: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_cf4:
	/* 0xcf4: jmp    e03 <generic_sleepable_preload+0xe03> */
	goto x86_l_e03;
x86_l_cf9:
	/* 0xcf9: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_cff:
	/* 0xcff: jmp    d23 <generic_sleepable_preload+0xd23> */
	goto x86_l_d23;
x86_l_d01:
	/* 0xd01: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_d06:
	/* 0xd06: jmp    e03 <generic_sleepable_preload+0xe03> */
	goto x86_l_e03;
x86_l_d0b:
	/* 0xd0b: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_d11:
	/* 0xd11: jmp    d23 <generic_sleepable_preload+0xd23> */
	goto x86_l_d23;
x86_l_d13:
	/* 0xd13: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_d18:
	/* 0xd18: jmp    e03 <generic_sleepable_preload+0xe03> */
	goto x86_l_e03;
x86_l_d1d:
	/* 0xd1d: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_d23:
	/* 0xd23: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d25:
	/* 0xd25: mov    r15d,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_d2a:
	/* 0xd2a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d2f:
	/* 0xd2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d34:
	/* 0xd34: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d37:
	/* 0xd37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_d3f:
	/* 0xd3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d41:
	/* 0xd41: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_d45:
	/* 0xd45: jne    111 <generic_sleepable_preload+0x111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 273ULL;
	}
x86_l_d4b:
	/* 0xd4b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4f:
	/* 0xd4f: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d57:
	/* 0xd57: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_d5c:
	/* 0xd5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5e:
	/* 0xd5e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d63:
	/* 0xd63: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_d6b:
	/* 0xd6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d70:
	/* 0xd70: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_d77:
	/* 0xd77: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d7c:
	/* 0xd7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7e:
	/* 0xd7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d81:
	/* 0xd81: je     10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 268ULL;
	}
x86_l_d87:
	/* 0xd87: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d8a:
	/* 0xd8a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d8f:
	/* 0xd8f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d91:
	/* 0xd91: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_d98:
	/* 0xd98: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_d9b:
	/* 0xd9b: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_d9e:
	/* 0xd9e: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_da3:
	/* 0xda3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_da6:
	/* 0xda6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_da9:
	/* 0xda9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dab:
	/* 0xdab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dad:
	/* 0xdad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db2:
	/* 0xdb2: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_db5:
	/* 0xdb5: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_db8:
	/* 0xdb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dba:
	/* 0xdba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dbd:
	/* 0xdbd: je     10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 268ULL;
	}
x86_l_dc3:
	/* 0xdc3: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_dc6:
	/* 0xdc6: je     10a <generic_sleepable_preload+0x10a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 266ULL;
	}
x86_l_dcc:
	/* 0xdcc: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dd0:
	/* 0xdd0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_dd5:
	/* 0xdd5: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ddd:
	/* 0xddd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ddf:
	/* 0xddf: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_de2:
	/* 0xde2: call   de7 <generic_sleepable_preload+0xde7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_de7:
	/* 0xde7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_de9:
	/* 0xde9: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_dec:
	/* 0xdec: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_dee:
	/* 0xdee: jns    10a <generic_sleepable_preload+0x10a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 266ULL;
	}
x86_l_df4:
	/* 0xdf4: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_df9:
	/* 0xdf9: jmp    10a <generic_sleepable_preload+0x10a> */
	return 266ULL;
x86_l_dfe:
	/* 0xdfe: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_e03:
	/* 0xe03: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e06:
	/* 0xe06: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_e0a:
	/* 0xe0a: jne    10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 268ULL;
	}
x86_l_e10:
	/* 0xe10: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e14:
	/* 0xe14: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e1c:
	/* 0xe1c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e21:
	/* 0xe21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e23:
	/* 0xe23: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e28:
	/* 0xe28: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_e30:
	/* 0xe30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e35:
	/* 0xe35: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_e3c:
	/* 0xe3c: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e41:
	/* 0xe41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e43:
	/* 0xe43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e46:
	/* 0xe46: je     10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 268ULL;
	}
x86_l_e4c:
	/* 0xe4c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e4f:
	/* 0xe4f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e54:
	/* 0xe54: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e56:
	/* 0xe56: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_e5d:
	/* 0xe5d: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_e60:
	/* 0xe60: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_e63:
	/* 0xe63: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e68:
	/* 0xe68: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e6b:
	/* 0xe6b: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e6e:
	/* 0xe6e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e70:
	/* 0xe70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e72:
	/* 0xe72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e77:
	/* 0xe77: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e7a:
	/* 0xe7a: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e7d:
	/* 0xe7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7f:
	/* 0xe7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e82:
	/* 0xe82: je     10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 268ULL;
	}
x86_l_e88:
	/* 0xe88: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e8b:
	/* 0xe8b: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_e8e:
	/* 0xe8e: je     eb2 <generic_sleepable_preload+0xeb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb2;
	}
x86_l_e90:
	/* 0xe90: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e94:
	/* 0xe94: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_e99:
	/* 0xe99: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ea1:
	/* 0xea1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea3:
	/* 0xea3: call   ea8 <generic_sleepable_preload+0xea8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_ea8:
	/* 0xea8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eaa:
	/* 0xeaa: jns    eb2 <generic_sleepable_preload+0xeb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_eb2;
	}
x86_l_eac:
	/* 0xeac: mov    r15d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_eb2:
	/* 0xeb2: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb6:
	/* 0xeb6: jmp    10c <generic_sleepable_preload+0x10c> */
	return 268ULL;
x86_l_ebb:
	/* 0xebb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ebd:
	/* 0xebd: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_ec3:
	/* 0xec3: jmp    d25 <generic_sleepable_preload+0xd25> */
	goto x86_l_d25;
x86_l_ec8:
	/* 0xec8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ecb:
	/* 0xecb: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_ed0:
	/* 0xed0: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_ed4:
	/* 0xed4: jne    10c <generic_sleepable_preload+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 268ULL;
	}
x86_l_eda:
	/* 0xeda: jmp    e10 <generic_sleepable_preload+0xe10> */
	goto x86_l_e10;
x86_l_edf:
	/* 0xedf: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_ee5:
	/* 0xee5: jmp    d23 <generic_sleepable_preload+0xd23> */
	goto x86_l_d23;
x86_l_eea:
	/* 0xeea: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_eef:
	/* 0xeef: jmp    e03 <generic_sleepable_preload+0xe03> */
	goto x86_l_e03;
x86_l_ef4:
	/* 0xef4: mov    eax,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ef9:
	/* 0xef9: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_efe:
	/* 0xefe: je     1e23 <generic_sleepable_preload+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7715ULL;
	}
x86_l_f04:
	/* 0xf04: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_f06:
	/* 0xf06: js     f3b <generic_sleepable_preload+0xf3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_f3b;
	}
x86_l_f08:
	/* 0xf08: mov    eax,DWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f0d:
	/* 0xf0d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f10:
	/* 0xf10: jle    fc3 <generic_sleepable_preload+0xfc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fc3;
	}
x86_l_f16:
	/* 0xf16: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f19:
	/* 0xf19: je     102d <generic_sleepable_preload+0x102d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102d;
	}
x86_l_f1f:
	/* 0xf1f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f22:
	/* 0xf22: je     1034 <generic_sleepable_preload+0x1034> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1034;
	}
x86_l_f28:
	/* 0xf28: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f2b:
	/* 0xf2b: jne    1047 <generic_sleepable_preload+0x1047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1047;
	}
x86_l_f31:
	/* 0xf31: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f36:
	/* 0xf36: jmp    1040 <generic_sleepable_preload+0x1040> */
	goto x86_l_1040;
x86_l_f3b:
	/* 0xf3b: movzx  eax,BYTE PTR [r12+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_f44:
	/* 0xf44: movzx  ecx,WORD PTR [r12+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_f4d:
	/* 0xf4d: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_f53:
	/* 0xf53: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f55:
	/* 0xf55: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_f58:
	/* 0xf58: jle    f97 <generic_sleepable_preload+0xf97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_f97;
	}
x86_l_f5a:
	/* 0xf5a: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_f5d:
	/* 0xf5d: jle    fd3 <generic_sleepable_preload+0xfd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fd3;
	}
x86_l_f5f:
	/* 0xf5f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_f62:
	/* 0xf62: jle    167b <generic_sleepable_preload+0x167b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5755ULL;
	}
x86_l_f68:
	/* 0xf68: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f6d:
	/* 0xf6d: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_f70:
	/* 0xf70: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5775ULL;
	}
x86_l_f76:
	/* 0xf76: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f7b:
	/* 0xf7b: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_f7e:
	/* 0xf7e: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5775ULL;
	}
x86_l_f84:
	/* 0xf84: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_f87:
	/* 0xf87: jne    16a2 <generic_sleepable_preload+0x16a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5794ULL;
	}
x86_l_f8d:
	/* 0xf8d: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f92:
	/* 0xf92: jmp    168f <generic_sleepable_preload+0x168f> */
	return 5775ULL;
x86_l_f97:
	/* 0xf97: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_f9a:
	/* 0xf9a: jg     1000 <generic_sleepable_preload+0x1000> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1000;
	}
x86_l_f9c:
	/* 0xf9c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_f9f:
	/* 0xf9f: jg     164c <generic_sleepable_preload+0x164c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5708ULL;
	}
x86_l_fa5:
	/* 0xfa5: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_faa:
	/* 0xfaa: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_fac:
	/* 0xfac: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5775ULL;
	}
x86_l_fb2:
	/* 0xfb2: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_fb5:
	/* 0xfb5: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_fb8:
	/* 0xfb8: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5775ULL;
	}
x86_l_fbe:
	/* 0xfbe: jmp    16a2 <generic_sleepable_preload+0x16a2> */
	return 5794ULL;
x86_l_fc3:
	/* 0xfc3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc5:
	/* 0xfc5: je     103b <generic_sleepable_preload+0x103b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103b;
	}
x86_l_fc7:
	/* 0xfc7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fca:
	/* 0xfca: jne    1047 <generic_sleepable_preload+0x1047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1047;
	}
x86_l_fcc:
	/* 0xfcc: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd1:
	/* 0xfd1: jmp    1040 <generic_sleepable_preload+0x1040> */
	goto x86_l_1040;
x86_l_fd3:
	/* 0xfd3: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_fd6:
	/* 0xfd6: jg     1633 <generic_sleepable_preload+0x1633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5683ULL;
	}
x86_l_fdc:
	/* 0xfdc: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fe4:
	/* 0xfe4: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fe7:
	/* 0xfe7: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5775ULL;
	}
x86_l_fed:
	/* 0xfed: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ff2:
	/* 0xff2: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_ff5:
	/* 0xff5: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5775ULL;
	}
x86_l_ffb:
	/* 0xffb: jmp    16a2 <generic_sleepable_preload+0x16a2> */
	return 5794ULL;
x86_l_1000:
	/* 0x1000: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1003:
	/* 0x1003: jg     1662 <generic_sleepable_preload+0x1662> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5730ULL;
	}
x86_l_1009:
	/* 0x1009: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1011:
	/* 0x1011: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1014:
	/* 0x1014: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5775ULL;
	}
x86_l_101a:
	/* 0x101a: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_101f:
	/* 0x101f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1022:
	/* 0x1022: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5775ULL;
	}
x86_l_1028:
	/* 0x1028: jmp    16a2 <generic_sleepable_preload+0x16a2> */
	return 5794ULL;
x86_l_102d:
	/* 0x102d: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1032:
	/* 0x1032: jmp    1040 <generic_sleepable_preload+0x1040> */
	goto x86_l_1040;
x86_l_1034:
	/* 0x1034: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1039:
	/* 0x1039: jmp    1040 <generic_sleepable_preload+0x1040> */
	goto x86_l_1040;
x86_l_103b:
	/* 0x103b: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1040:
	/* 0x1040: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1043:
	/* 0x1043: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1047:
	/* 0x1047: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1049:
	/* 0x1049: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_104c:
	/* 0x104c: cmp    WORD PTR [r12+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1053:
	/* 0x1053: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1059:
	/* 0x1059: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1060:
	/* 0x1060: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1063:
	/* 0x1063: mov    eax,DWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1068:
	/* 0x1068: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_106b:
	/* 0x106b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_106f:
	/* 0x106f: movzx  eax,WORD PTR [r12+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1075:
	/* 0x1075: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1077:
	/* 0x1077: je     1340 <generic_sleepable_preload+0x1340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1340;
	}
x86_l_107d:
	/* 0x107d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1080:
	/* 0x1080: je     10a2 <generic_sleepable_preload+0x10a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a2;
	}
x86_l_1082:
	/* 0x1082: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1085:
	/* 0x1085: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_108a:
	/* 0x108a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_108f:
	/* 0x108f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1093:
	/* 0x1093: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1098:
	/* 0x1098: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109a:
	/* 0x109a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_109c:
	/* 0x109c: js     1629 <generic_sleepable_preload+0x1629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5673ULL;
	}
x86_l_10a2:
	/* 0x10a2: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_10a9:
	/* 0x10a9: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_10af:
	/* 0x10af: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10b4:
	/* 0x10b4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10b8:
	/* 0x10b8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10bc:
	/* 0x10bc: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_10c3:
	/* 0x10c3: je     10e5 <generic_sleepable_preload+0x10e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10e5;
	}
x86_l_10c5:
	/* 0x10c5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10c8:
	/* 0x10c8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_10cd:
	/* 0x10cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10d2:
	/* 0x10d2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d6:
	/* 0x10d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10db:
	/* 0x10db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10dd:
	/* 0x10dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10df:
	/* 0x10df: js     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7319ULL;
	}
x86_l_10e5:
	/* 0x10e5: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_10ef:
	/* 0x10ef: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_10f5:
	/* 0x10f5: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10fd:
	/* 0x10fd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1101:
	/* 0x1101: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1105:
	/* 0x1105: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_110f:
	/* 0x110f: je     1131 <generic_sleepable_preload+0x1131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1131;
	}
x86_l_1111:
	/* 0x1111: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1114:
	/* 0x1114: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1119:
	/* 0x1119: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_111e:
	/* 0x111e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1122:
	/* 0x1122: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1127:
	/* 0x1127: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1129:
	/* 0x1129: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_112b:
	/* 0x112b: js     1ca8 <generic_sleepable_preload+0x1ca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7336ULL;
	}
x86_l_1131:
	/* 0x1131: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_113b:
	/* 0x113b: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1141:
	/* 0x1141: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1149:
	/* 0x1149: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_114d:
	/* 0x114d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1151:
	/* 0x1151: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_115b:
	/* 0x115b: je     117d <generic_sleepable_preload+0x117d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117d;
	}
x86_l_115d:
	/* 0x115d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1160:
	/* 0x1160: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1165:
	/* 0x1165: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_116a:
	/* 0x116a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116e:
	/* 0x116e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1173:
	/* 0x1173: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1175:
	/* 0x1175: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1177:
	/* 0x1177: js     1cb9 <generic_sleepable_preload+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7353ULL;
	}
x86_l_117d:
	/* 0x117d: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1187:
	/* 0x1187: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_118d:
	/* 0x118d: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1195:
	/* 0x1195: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1199:
	/* 0x1199: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_119d:
	/* 0x119d: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_11a7:
	/* 0x11a7: je     11c9 <generic_sleepable_preload+0x11c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11c9;
	}
x86_l_11a9:
	/* 0x11a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11ac:
	/* 0x11ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11b1:
	/* 0x11b1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11b6:
	/* 0x11b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ba:
	/* 0x11ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11bf:
	/* 0x11bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c1:
	/* 0x11c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11c3:
	/* 0x11c3: js     1cca <generic_sleepable_preload+0x1cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7370ULL;
	}
x86_l_11c9:
	/* 0x11c9: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_11d3:
	/* 0x11d3: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_11d9:
	/* 0x11d9: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_11e1:
	/* 0x11e1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11e5:
	/* 0x11e5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e9:
	/* 0x11e9: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_11f3:
	/* 0x11f3: je     1215 <generic_sleepable_preload+0x1215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1215;
	}
x86_l_11f5:
	/* 0x11f5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11f8:
	/* 0x11f8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11fd:
	/* 0x11fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1202:
	/* 0x1202: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1206:
	/* 0x1206: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_120b:
	/* 0x120b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120d:
	/* 0x120d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_120f:
	/* 0x120f: js     1cdb <generic_sleepable_preload+0x1cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7387ULL;
	}
x86_l_1215:
	/* 0x1215: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_121f:
	/* 0x121f: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1225:
	/* 0x1225: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_122d:
	/* 0x122d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1231:
	/* 0x1231: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1235:
	/* 0x1235: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_123f:
	/* 0x123f: je     1261 <generic_sleepable_preload+0x1261> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1261;
	}
x86_l_1241:
	/* 0x1241: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1244:
	/* 0x1244: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1249:
	/* 0x1249: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_124e:
	/* 0x124e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1252:
	/* 0x1252: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1257:
	/* 0x1257: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1259:
	/* 0x1259: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_125b:
	/* 0x125b: js     1cec <generic_sleepable_preload+0x1cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7404ULL;
	}
x86_l_1261:
	/* 0x1261: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_126b:
	/* 0x126b: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1271:
	/* 0x1271: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1279:
	/* 0x1279: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_127d:
	/* 0x127d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1281:
	/* 0x1281: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_128b:
	/* 0x128b: je     12ad <generic_sleepable_preload+0x12ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ad;
	}
x86_l_128d:
	/* 0x128d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1290:
	/* 0x1290: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1295:
	/* 0x1295: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_129a:
	/* 0x129a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129e:
	/* 0x129e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a3:
	/* 0x12a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a5:
	/* 0x12a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12a7:
	/* 0x12a7: js     5bbf <generic_sleepable_preload+0x5bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23487ULL;
	}
x86_l_12ad:
	/* 0x12ad: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_12b7:
	/* 0x12b7: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_12bd:
	/* 0x12bd: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12c5:
	/* 0x12c5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12c9:
	/* 0x12c9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12cd:
	/* 0x12cd: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_12d7:
	/* 0x12d7: je     12f9 <generic_sleepable_preload+0x12f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f9;
	}
x86_l_12d9:
	/* 0x12d9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12dc:
	/* 0x12dc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12e1:
	/* 0x12e1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12e6:
	/* 0x12e6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ea:
	/* 0x12ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ef:
	/* 0x12ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f1:
	/* 0x12f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12f3:
	/* 0x12f3: js     5ca5 <generic_sleepable_preload+0x5ca5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23717ULL;
	}
x86_l_12f9:
	/* 0x12f9: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12fe:
	/* 0x12fe: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1308:
	/* 0x1308: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_130e:
	/* 0x130e: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1316:
	/* 0x1316: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_131a:
	/* 0x131a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131e:
	/* 0x131e: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1328:
	/* 0x1328: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_132e:
	/* 0x132e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1331:
	/* 0x1331: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1336:
	/* 0x1336: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_133b:
	/* 0x133b: jmp    160c <generic_sleepable_preload+0x160c> */
	return 5644ULL;
x86_l_1340:
	/* 0x1340: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1343:
	/* 0x1343: je     1365 <generic_sleepable_preload+0x1365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4965ULL;
	}
x86_l_1345:
	/* 0x1345: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1348:
	/* 0x1348: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_134d:
	/* 0x134d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
	return 4946ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4946ULL: goto x86_l_1352;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4957ULL: goto x86_l_135d;
	case 4959ULL: goto x86_l_135f;
	case 4965ULL: goto x86_l_1365;
	case 4972ULL: goto x86_l_136c;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4987ULL: goto x86_l_137b;
	case 4991ULL: goto x86_l_137f;
	case 4998ULL: goto x86_l_1386;
	case 5000ULL: goto x86_l_1388;
	case 5003ULL: goto x86_l_138b;
	case 5008ULL: goto x86_l_1390;
	case 5013ULL: goto x86_l_1395;
	case 5017ULL: goto x86_l_1399;
	case 5022ULL: goto x86_l_139e;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5032ULL: goto x86_l_13a8;
	case 5042ULL: goto x86_l_13b2;
	case 5048ULL: goto x86_l_13b8;
	case 5056ULL: goto x86_l_13c0;
	case 5060ULL: goto x86_l_13c4;
	case 5064ULL: goto x86_l_13c8;
	case 5074ULL: goto x86_l_13d2;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5093ULL: goto x86_l_13e5;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5102ULL: goto x86_l_13ee;
	case 5108ULL: goto x86_l_13f4;
	case 5118ULL: goto x86_l_13fe;
	case 5124ULL: goto x86_l_1404;
	case 5132ULL: goto x86_l_140c;
	case 5136ULL: goto x86_l_1410;
	case 5140ULL: goto x86_l_1414;
	case 5150ULL: goto x86_l_141e;
	case 5152ULL: goto x86_l_1420;
	case 5155ULL: goto x86_l_1423;
	case 5160ULL: goto x86_l_1428;
	case 5165ULL: goto x86_l_142d;
	case 5169ULL: goto x86_l_1431;
	case 5174ULL: goto x86_l_1436;
	case 5176ULL: goto x86_l_1438;
	case 5178ULL: goto x86_l_143a;
	case 5184ULL: goto x86_l_1440;
	case 5194ULL: goto x86_l_144a;
	case 5200ULL: goto x86_l_1450;
	case 5208ULL: goto x86_l_1458;
	case 5212ULL: goto x86_l_145c;
	case 5216ULL: goto x86_l_1460;
	case 5226ULL: goto x86_l_146a;
	case 5228ULL: goto x86_l_146c;
	case 5231ULL: goto x86_l_146f;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5245ULL: goto x86_l_147d;
	case 5250ULL: goto x86_l_1482;
	case 5252ULL: goto x86_l_1484;
	case 5254ULL: goto x86_l_1486;
	case 5260ULL: goto x86_l_148c;
	case 5270ULL: goto x86_l_1496;
	case 5276ULL: goto x86_l_149c;
	case 5284ULL: goto x86_l_14a4;
	case 5288ULL: goto x86_l_14a8;
	case 5292ULL: goto x86_l_14ac;
	case 5302ULL: goto x86_l_14b6;
	case 5304ULL: goto x86_l_14b8;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5317ULL: goto x86_l_14c5;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5328ULL: goto x86_l_14d0;
	case 5330ULL: goto x86_l_14d2;
	case 5336ULL: goto x86_l_14d8;
	case 5346ULL: goto x86_l_14e2;
	case 5352ULL: goto x86_l_14e8;
	case 5360ULL: goto x86_l_14f0;
	case 5364ULL: goto x86_l_14f4;
	case 5368ULL: goto x86_l_14f8;
	case 5378ULL: goto x86_l_1502;
	case 5380ULL: goto x86_l_1504;
	case 5383ULL: goto x86_l_1507;
	case 5388ULL: goto x86_l_150c;
	case 5393ULL: goto x86_l_1511;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5412ULL: goto x86_l_1524;
	case 5422ULL: goto x86_l_152e;
	case 5428ULL: goto x86_l_1534;
	case 5431ULL: goto x86_l_1537;
	case 5439ULL: goto x86_l_153f;
	case 5443ULL: goto x86_l_1543;
	case 5447ULL: goto x86_l_1547;
	case 5457ULL: goto x86_l_1551;
	case 5459ULL: goto x86_l_1553;
	case 5462ULL: goto x86_l_1556;
	case 5467ULL: goto x86_l_155b;
	case 5472ULL: goto x86_l_1560;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5483ULL: goto x86_l_156b;
	case 5485ULL: goto x86_l_156d;
	case 5491ULL: goto x86_l_1573;
	case 5496ULL: goto x86_l_1578;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5515ULL: goto x86_l_158b;
	case 5523ULL: goto x86_l_1593;
	case 5527ULL: goto x86_l_1597;
	case 5531ULL: goto x86_l_159b;
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5546ULL: goto x86_l_15aa;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5560ULL: goto x86_l_15b8;
	case 5565ULL: goto x86_l_15bd;
	case 5567ULL: goto x86_l_15bf;
	case 5569ULL: goto x86_l_15c1;
	case 5575ULL: goto x86_l_15c7;
	case 5580ULL: goto x86_l_15cc;
	case 5590ULL: goto x86_l_15d6;
	case 5593ULL: goto x86_l_15d9;
	case 5599ULL: goto x86_l_15df;
	case 5607ULL: goto x86_l_15e7;
	case 5611ULL: goto x86_l_15eb;
	case 5615ULL: goto x86_l_15ef;
	case 5625ULL: goto x86_l_15f9;
	case 5631ULL: goto x86_l_15ff;
	case 5634ULL: goto x86_l_1602;
	case 5639ULL: goto x86_l_1607;
	case 5644ULL: goto x86_l_160c;
	case 5648ULL: goto x86_l_1610;
	case 5653ULL: goto x86_l_1615;
	case 5655ULL: goto x86_l_1617;
	case 5657ULL: goto x86_l_1619;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5691ULL: goto x86_l_163b;
	case 5694ULL: goto x86_l_163e;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5704ULL: goto x86_l_1648;
	case 5706ULL: goto x86_l_164a;
	case 5708ULL: goto x86_l_164c;
	case 5713ULL: goto x86_l_1651;
	case 5716ULL: goto x86_l_1654;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5730ULL: goto x86_l_1662;
	case 5738ULL: goto x86_l_166a;
	case 5741ULL: goto x86_l_166d;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5751ULL: goto x86_l_1677;
	case 5753ULL: goto x86_l_1679;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5763ULL: goto x86_l_1683;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5778ULL: goto x86_l_1692;
	case 5780ULL: goto x86_l_1694;
	case 5782ULL: goto x86_l_1696;
	case 5787ULL: goto x86_l_169b;
	case 5789ULL: goto x86_l_169d;
	case 5794ULL: goto x86_l_16a2;
	case 5798ULL: goto x86_l_16a6;
	case 5803ULL: goto x86_l_16ab;
	case 5805ULL: goto x86_l_16ad;
	case 5808ULL: goto x86_l_16b0;
	case 5815ULL: goto x86_l_16b7;
	case 5821ULL: goto x86_l_16bd;
	case 5828ULL: goto x86_l_16c4;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5839ULL: goto x86_l_16cf;
	case 5843ULL: goto x86_l_16d3;
	case 5849ULL: goto x86_l_16d9;
	case 5851ULL: goto x86_l_16db;
	case 5857ULL: goto x86_l_16e1;
	case 5860ULL: goto x86_l_16e4;
	case 5862ULL: goto x86_l_16e6;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5886ULL: goto x86_l_16fe;
	case 5888ULL: goto x86_l_1700;
	case 5894ULL: goto x86_l_1706;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5916ULL: goto x86_l_171c;
	case 5920ULL: goto x86_l_1720;
	case 5927ULL: goto x86_l_1727;
	case 5929ULL: goto x86_l_1729;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5953ULL: goto x86_l_1741;
	case 5955ULL: goto x86_l_1743;
	case 5961ULL: goto x86_l_1749;
	case 5971ULL: goto x86_l_1753;
	case 5977ULL: goto x86_l_1759;
	case 5985ULL: goto x86_l_1761;
	case 5989ULL: goto x86_l_1765;
	case 5993ULL: goto x86_l_1769;
	case 6003ULL: goto x86_l_1773;
	case 6005ULL: goto x86_l_1775;
	case 6008ULL: goto x86_l_1778;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6022ULL: goto x86_l_1786;
	case 6027ULL: goto x86_l_178b;
	case 6029ULL: goto x86_l_178d;
	case 6031ULL: goto x86_l_178f;
	case 6037ULL: goto x86_l_1795;
	case 6047ULL: goto x86_l_179f;
	case 6053ULL: goto x86_l_17a5;
	case 6061ULL: goto x86_l_17ad;
	case 6065ULL: goto x86_l_17b1;
	case 6069ULL: goto x86_l_17b5;
	case 6079ULL: goto x86_l_17bf;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6098ULL: goto x86_l_17d2;
	case 6103ULL: goto x86_l_17d7;
	case 6105ULL: goto x86_l_17d9;
	case 6107ULL: goto x86_l_17db;
	case 6113ULL: goto x86_l_17e1;
	case 6123ULL: goto x86_l_17eb;
	case 6129ULL: goto x86_l_17f1;
	case 6137ULL: goto x86_l_17f9;
	case 6141ULL: goto x86_l_17fd;
	case 6145ULL: goto x86_l_1801;
	case 6155ULL: goto x86_l_180b;
	case 6157ULL: goto x86_l_180d;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6181ULL: goto x86_l_1825;
	case 6183ULL: goto x86_l_1827;
	case 6189ULL: goto x86_l_182d;
	case 6199ULL: goto x86_l_1837;
	case 6205ULL: goto x86_l_183d;
	case 6213ULL: goto x86_l_1845;
	case 6217ULL: goto x86_l_1849;
	case 6221ULL: goto x86_l_184d;
	case 6231ULL: goto x86_l_1857;
	case 6233ULL: goto x86_l_1859;
	case 6236ULL: goto x86_l_185c;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6250ULL: goto x86_l_186a;
	case 6255ULL: goto x86_l_186f;
	case 6257ULL: goto x86_l_1871;
	case 6259ULL: goto x86_l_1873;
	case 6265ULL: goto x86_l_1879;
	case 6275ULL: goto x86_l_1883;
	case 6281ULL: goto x86_l_1889;
	case 6289ULL: goto x86_l_1891;
	case 6293ULL: goto x86_l_1895;
	case 6297ULL: goto x86_l_1899;
	case 6307ULL: goto x86_l_18a3;
	case 6309ULL: goto x86_l_18a5;
	case 6312ULL: goto x86_l_18a8;
	case 6317ULL: goto x86_l_18ad;
	case 6322ULL: goto x86_l_18b2;
	case 6326ULL: goto x86_l_18b6;
	case 6331ULL: goto x86_l_18bb;
	case 6333ULL: goto x86_l_18bd;
	case 6335ULL: goto x86_l_18bf;
	case 6341ULL: goto x86_l_18c5;
	case 6351ULL: goto x86_l_18cf;
	case 6357ULL: goto x86_l_18d5;
	case 6365ULL: goto x86_l_18dd;
	case 6369ULL: goto x86_l_18e1;
	case 6373ULL: goto x86_l_18e5;
	case 6383ULL: goto x86_l_18ef;
	case 6385ULL: goto x86_l_18f1;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6398ULL: goto x86_l_18fe;
	case 6402ULL: goto x86_l_1902;
	case 6407ULL: goto x86_l_1907;
	case 6409ULL: goto x86_l_1909;
	case 6411ULL: goto x86_l_190b;
	case 6417ULL: goto x86_l_1911;
	case 6427ULL: goto x86_l_191b;
	case 6433ULL: goto x86_l_1921;
	case 6441ULL: goto x86_l_1929;
	case 6445ULL: goto x86_l_192d;
	case 6449ULL: goto x86_l_1931;
	case 6459ULL: goto x86_l_193b;
	case 6461ULL: goto x86_l_193d;
	case 6464ULL: goto x86_l_1940;
	case 6469ULL: goto x86_l_1945;
	case 6474ULL: goto x86_l_194a;
	case 6478ULL: goto x86_l_194e;
	case 6483ULL: goto x86_l_1953;
	case 6485ULL: goto x86_l_1955;
	case 6487ULL: goto x86_l_1957;
	case 6493ULL: goto x86_l_195d;
	case 6498ULL: goto x86_l_1962;
	case 6508ULL: goto x86_l_196c;
	case 6514ULL: goto x86_l_1972;
	case 6522ULL: goto x86_l_197a;
	case 6526ULL: goto x86_l_197e;
	case 6530ULL: goto x86_l_1982;
	case 6540ULL: goto x86_l_198c;
	case 6546ULL: goto x86_l_1992;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6567ULL: goto x86_l_19a7;
	case 6569ULL: goto x86_l_19a9;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6586ULL: goto x86_l_19ba;
	case 6591ULL: goto x86_l_19bf;
	case 6593ULL: goto x86_l_19c1;
	case 6595ULL: goto x86_l_19c3;
	case 6601ULL: goto x86_l_19c9;
	case 6608ULL: goto x86_l_19d0;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6623ULL: goto x86_l_19df;
	case 6627ULL: goto x86_l_19e3;
	case 6634ULL: goto x86_l_19ea;
	case 6636ULL: goto x86_l_19ec;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6660ULL: goto x86_l_1a04;
	case 6662ULL: goto x86_l_1a06;
	case 6668ULL: goto x86_l_1a0c;
	case 6678ULL: goto x86_l_1a16;
	case 6684ULL: goto x86_l_1a1c;
	case 6692ULL: goto x86_l_1a24;
	case 6696ULL: goto x86_l_1a28;
	case 6700ULL: goto x86_l_1a2c;
	case 6710ULL: goto x86_l_1a36;
	case 6712ULL: goto x86_l_1a38;
	case 6715ULL: goto x86_l_1a3b;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6736ULL: goto x86_l_1a50;
	case 6738ULL: goto x86_l_1a52;
	case 6744ULL: goto x86_l_1a58;
	case 6754ULL: goto x86_l_1a62;
	case 6760ULL: goto x86_l_1a68;
	case 6768ULL: goto x86_l_1a70;
	case 6772ULL: goto x86_l_1a74;
	case 6776ULL: goto x86_l_1a78;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1352:
	/* 0x1352: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1356:
	/* 0x1356: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_135b:
	/* 0x135b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135d:
	/* 0x135d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_135f:
	/* 0x135f: js     1629 <generic_sleepable_preload+0x1629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1629;
	}
x86_l_1365:
	/* 0x1365: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_136c:
	/* 0x136c: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1372:
	/* 0x1372: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1377:
	/* 0x1377: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_137b:
	/* 0x137b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137f:
	/* 0x137f: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1386:
	/* 0x1386: je     13a8 <generic_sleepable_preload+0x13a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a8;
	}
x86_l_1388:
	/* 0x1388: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_138b:
	/* 0x138b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1390:
	/* 0x1390: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1395:
	/* 0x1395: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1399:
	/* 0x1399: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_139e:
	/* 0x139e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a0:
	/* 0x13a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a2:
	/* 0x13a2: js     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7319ULL;
	}
x86_l_13a8:
	/* 0x13a8: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_13b2:
	/* 0x13b2: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_13b8:
	/* 0x13b8: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13c0:
	/* 0x13c0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_13c4:
	/* 0x13c4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c8:
	/* 0x13c8: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_13d2:
	/* 0x13d2: je     13f4 <generic_sleepable_preload+0x13f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f4;
	}
x86_l_13d4:
	/* 0x13d4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13d7:
	/* 0x13d7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_13dc:
	/* 0x13dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13e1:
	/* 0x13e1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e5:
	/* 0x13e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13ea:
	/* 0x13ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ec:
	/* 0x13ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13ee:
	/* 0x13ee: js     1ca8 <generic_sleepable_preload+0x1ca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7336ULL;
	}
x86_l_13f4:
	/* 0x13f4: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_13fe:
	/* 0x13fe: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1404:
	/* 0x1404: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_140c:
	/* 0x140c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1410:
	/* 0x1410: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1414:
	/* 0x1414: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_141e:
	/* 0x141e: je     1440 <generic_sleepable_preload+0x1440> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1440;
	}
x86_l_1420:
	/* 0x1420: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1423:
	/* 0x1423: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1428:
	/* 0x1428: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_142d:
	/* 0x142d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1431:
	/* 0x1431: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1436:
	/* 0x1436: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1438:
	/* 0x1438: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_143a:
	/* 0x143a: js     1cb9 <generic_sleepable_preload+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7353ULL;
	}
x86_l_1440:
	/* 0x1440: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_144a:
	/* 0x144a: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1450:
	/* 0x1450: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1458:
	/* 0x1458: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_145c:
	/* 0x145c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1460:
	/* 0x1460: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_146a:
	/* 0x146a: je     148c <generic_sleepable_preload+0x148c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148c;
	}
x86_l_146c:
	/* 0x146c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_146f:
	/* 0x146f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1474:
	/* 0x1474: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1479:
	/* 0x1479: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147d:
	/* 0x147d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1482:
	/* 0x1482: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1484:
	/* 0x1484: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1486:
	/* 0x1486: js     1cca <generic_sleepable_preload+0x1cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7370ULL;
	}
x86_l_148c:
	/* 0x148c: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1496:
	/* 0x1496: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_149c:
	/* 0x149c: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14a4:
	/* 0x14a4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14a8:
	/* 0x14a8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ac:
	/* 0x14ac: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_14b6:
	/* 0x14b6: je     14d8 <generic_sleepable_preload+0x14d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14d8;
	}
x86_l_14b8:
	/* 0x14b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14bb:
	/* 0x14bb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14c0:
	/* 0x14c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14c5:
	/* 0x14c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c9:
	/* 0x14c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14ce:
	/* 0x14ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d0:
	/* 0x14d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d2:
	/* 0x14d2: js     1cdb <generic_sleepable_preload+0x1cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7387ULL;
	}
x86_l_14d8:
	/* 0x14d8: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_14e2:
	/* 0x14e2: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_14e8:
	/* 0x14e8: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14f0:
	/* 0x14f0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14f4:
	/* 0x14f4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f8:
	/* 0x14f8: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1502:
	/* 0x1502: je     1524 <generic_sleepable_preload+0x1524> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1524;
	}
x86_l_1504:
	/* 0x1504: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1507:
	/* 0x1507: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_150c:
	/* 0x150c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1511:
	/* 0x1511: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1515:
	/* 0x1515: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_151a:
	/* 0x151a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151c:
	/* 0x151c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_151e:
	/* 0x151e: js     1cec <generic_sleepable_preload+0x1cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7404ULL;
	}
x86_l_1524:
	/* 0x1524: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_152e:
	/* 0x152e: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1534:
	/* 0x1534: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_1537:
	/* 0x1537: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_153f:
	/* 0x153f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1543:
	/* 0x1543: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1547:
	/* 0x1547: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1551:
	/* 0x1551: je     1573 <generic_sleepable_preload+0x1573> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1573;
	}
x86_l_1553:
	/* 0x1553: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1556:
	/* 0x1556: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_155b:
	/* 0x155b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1560:
	/* 0x1560: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1564:
	/* 0x1564: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1569:
	/* 0x1569: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156b:
	/* 0x156b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_156d:
	/* 0x156d: js     5c3d <generic_sleepable_preload+0x5c3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23613ULL;
	}
x86_l_1573:
	/* 0x1573: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1578:
	/* 0x1578: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1582:
	/* 0x1582: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1585:
	/* 0x1585: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_158b:
	/* 0x158b: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1593:
	/* 0x1593: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1597:
	/* 0x1597: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_159b:
	/* 0x159b: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_15a5:
	/* 0x15a5: je     15c7 <generic_sleepable_preload+0x15c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15c7;
	}
x86_l_15a7:
	/* 0x15a7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15aa:
	/* 0x15aa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15af:
	/* 0x15af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15b4:
	/* 0x15b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b8:
	/* 0x15b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15bd:
	/* 0x15bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bf:
	/* 0x15bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15c1:
	/* 0x15c1: js     5d35 <generic_sleepable_preload+0x5d35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23861ULL;
	}
x86_l_15c7:
	/* 0x15c7: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15cc:
	/* 0x15cc: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_15d6:
	/* 0x15d6: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_15d9:
	/* 0x15d9: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_15df:
	/* 0x15df: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15e7:
	/* 0x15e7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15eb:
	/* 0x15eb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ef:
	/* 0x15ef: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_15f9:
	/* 0x15f9: je     1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_15ff:
	/* 0x15ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1602:
	/* 0x1602: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1607:
	/* 0x1607: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_160c:
	/* 0x160c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1610:
	/* 0x1610: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1615:
	/* 0x1615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1617:
	/* 0x1617: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1619:
	/* 0x1619: jns    1cf4 <generic_sleepable_preload+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7412ULL;
	}
x86_l_161f:
	/* 0x161f: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_1624:
	/* 0x1624: jmp    1cf1 <generic_sleepable_preload+0x1cf1> */
	return 7409ULL;
x86_l_1629:
	/* 0x1629: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_162e:
	/* 0x162e: jmp    1cf1 <generic_sleepable_preload+0x1cf1> */
	return 7409ULL;
x86_l_1633:
	/* 0x1633: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_163b:
	/* 0x163b: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_163e:
	/* 0x163e: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168f;
	}
x86_l_1640:
	/* 0x1640: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1645:
	/* 0x1645: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1648:
	/* 0x1648: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168f;
	}
x86_l_164a:
	/* 0x164a: jmp    16a2 <generic_sleepable_preload+0x16a2> */
	goto x86_l_16a2;
x86_l_164c:
	/* 0x164c: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1651:
	/* 0x1651: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1654:
	/* 0x1654: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168f;
	}
x86_l_1656:
	/* 0x1656: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_165b:
	/* 0x165b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_165e:
	/* 0x165e: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168f;
	}
x86_l_1660:
	/* 0x1660: jmp    16a2 <generic_sleepable_preload+0x16a2> */
	goto x86_l_16a2;
x86_l_1662:
	/* 0x1662: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_166a:
	/* 0x166a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_166d:
	/* 0x166d: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168f;
	}
x86_l_166f:
	/* 0x166f: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1674:
	/* 0x1674: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1677:
	/* 0x1677: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168f;
	}
x86_l_1679:
	/* 0x1679: jmp    16a2 <generic_sleepable_preload+0x16a2> */
	goto x86_l_16a2;
x86_l_167b:
	/* 0x167b: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1680:
	/* 0x1680: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1683:
	/* 0x1683: je     168f <generic_sleepable_preload+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168f;
	}
x86_l_1685:
	/* 0x1685: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_168a:
	/* 0x168a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_168d:
	/* 0x168d: jne    16a2 <generic_sleepable_preload+0x16a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16a2;
	}
x86_l_168f:
	/* 0x168f: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1692:
	/* 0x1692: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1694:
	/* 0x1694: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1696:
	/* 0x1696: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_169b:
	/* 0x169b: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_169d:
	/* 0x169d: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_16a2:
	/* 0x16a2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a6:
	/* 0x16a6: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16ab:
	/* 0x16ab: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ad:
	/* 0x16ad: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_16b0:
	/* 0x16b0: cmp    WORD PTR [r12+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_16b7:
	/* 0x16b7: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_16bd:
	/* 0x16bd: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_16c4:
	/* 0x16c4: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16c7:
	/* 0x16c7: mov    eax,DWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16cc:
	/* 0x16cc: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16cf:
	/* 0x16cf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d3:
	/* 0x16d3: movzx  eax,WORD PTR [r12+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_16d9:
	/* 0x16d9: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_16db:
	/* 0x16db: je     19a4 <generic_sleepable_preload+0x19a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a4;
	}
x86_l_16e1:
	/* 0x16e1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_16e4:
	/* 0x16e4: je     1706 <generic_sleepable_preload+0x1706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1706;
	}
x86_l_16e6:
	/* 0x16e6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16e9:
	/* 0x16e9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16ee:
	/* 0x16ee: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16f3:
	/* 0x16f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f7:
	/* 0x16f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16fc:
	/* 0x16fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fe:
	/* 0x16fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1700:
	/* 0x1700: js     1c8d <generic_sleepable_preload+0x1c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7309ULL;
	}
x86_l_1706:
	/* 0x1706: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_170d:
	/* 0x170d: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_1713:
	/* 0x1713: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1718:
	/* 0x1718: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_171c:
	/* 0x171c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1720:
	/* 0x1720: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1727:
	/* 0x1727: je     1749 <generic_sleepable_preload+0x1749> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1749;
	}
x86_l_1729:
	/* 0x1729: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_172c:
	/* 0x172c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1731:
	/* 0x1731: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1736:
	/* 0x1736: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173a:
	/* 0x173a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_173f:
	/* 0x173f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1741:
	/* 0x1741: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1743:
	/* 0x1743: js     1c9e <generic_sleepable_preload+0x1c9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7326ULL;
	}
x86_l_1749:
	/* 0x1749: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1753:
	/* 0x1753: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_1759:
	/* 0x1759: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1761:
	/* 0x1761: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1765:
	/* 0x1765: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1769:
	/* 0x1769: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1773:
	/* 0x1773: je     1795 <generic_sleepable_preload+0x1795> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1795;
	}
x86_l_1775:
	/* 0x1775: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1778:
	/* 0x1778: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_177d:
	/* 0x177d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1782:
	/* 0x1782: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1786:
	/* 0x1786: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_178b:
	/* 0x178b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178d:
	/* 0x178d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_178f:
	/* 0x178f: js     1caf <generic_sleepable_preload+0x1caf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7343ULL;
	}
x86_l_1795:
	/* 0x1795: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_179f:
	/* 0x179f: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_17a5:
	/* 0x17a5: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_17ad:
	/* 0x17ad: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17b1:
	/* 0x17b1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17b5:
	/* 0x17b5: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_17bf:
	/* 0x17bf: je     17e1 <generic_sleepable_preload+0x17e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17e1;
	}
x86_l_17c1:
	/* 0x17c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_17c4:
	/* 0x17c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17c9:
	/* 0x17c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17ce:
	/* 0x17ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d2:
	/* 0x17d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17d7:
	/* 0x17d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d9:
	/* 0x17d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17db:
	/* 0x17db: js     1cc0 <generic_sleepable_preload+0x1cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7360ULL;
	}
x86_l_17e1:
	/* 0x17e1: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_17eb:
	/* 0x17eb: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_17f1:
	/* 0x17f1: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17f9:
	/* 0x17f9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17fd:
	/* 0x17fd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1801:
	/* 0x1801: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_180b:
	/* 0x180b: je     182d <generic_sleepable_preload+0x182d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_182d;
	}
x86_l_180d:
	/* 0x180d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1810:
	/* 0x1810: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1815:
	/* 0x1815: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_181a:
	/* 0x181a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_181e:
	/* 0x181e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1823:
	/* 0x1823: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1825:
	/* 0x1825: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1827:
	/* 0x1827: js     1cd1 <generic_sleepable_preload+0x1cd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7377ULL;
	}
x86_l_182d:
	/* 0x182d: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1837:
	/* 0x1837: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_183d:
	/* 0x183d: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1845:
	/* 0x1845: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1849:
	/* 0x1849: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_184d:
	/* 0x184d: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1857:
	/* 0x1857: je     1879 <generic_sleepable_preload+0x1879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1879;
	}
x86_l_1859:
	/* 0x1859: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_185c:
	/* 0x185c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1861:
	/* 0x1861: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1866:
	/* 0x1866: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_186a:
	/* 0x186a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_186f:
	/* 0x186f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1871:
	/* 0x1871: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1873:
	/* 0x1873: js     1ce2 <generic_sleepable_preload+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7394ULL;
	}
x86_l_1879:
	/* 0x1879: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1883:
	/* 0x1883: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_1889:
	/* 0x1889: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1891:
	/* 0x1891: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1895:
	/* 0x1895: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1899:
	/* 0x1899: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_18a3:
	/* 0x18a3: je     18c5 <generic_sleepable_preload+0x18c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18c5;
	}
x86_l_18a5:
	/* 0x18a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18a8:
	/* 0x18a8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18ad:
	/* 0x18ad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18b2:
	/* 0x18b2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b6:
	/* 0x18b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18bb:
	/* 0x18bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18bd:
	/* 0x18bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18bf:
	/* 0x18bf: js     1d77 <generic_sleepable_preload+0x1d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7543ULL;
	}
x86_l_18c5:
	/* 0x18c5: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_18cf:
	/* 0x18cf: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_18d5:
	/* 0x18d5: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_18dd:
	/* 0x18dd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18e1:
	/* 0x18e1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e5:
	/* 0x18e5: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_18ef:
	/* 0x18ef: je     1911 <generic_sleepable_preload+0x1911> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1911;
	}
x86_l_18f1:
	/* 0x18f1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18f4:
	/* 0x18f4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18f9:
	/* 0x18f9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18fe:
	/* 0x18fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1902:
	/* 0x1902: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1907:
	/* 0x1907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1909:
	/* 0x1909: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_190b:
	/* 0x190b: js     5bcc <generic_sleepable_preload+0x5bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23500ULL;
	}
x86_l_1911:
	/* 0x1911: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_191b:
	/* 0x191b: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_1921:
	/* 0x1921: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1929:
	/* 0x1929: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_192d:
	/* 0x192d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1931:
	/* 0x1931: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_193b:
	/* 0x193b: je     195d <generic_sleepable_preload+0x195d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_195d;
	}
x86_l_193d:
	/* 0x193d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1940:
	/* 0x1940: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1945:
	/* 0x1945: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_194a:
	/* 0x194a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194e:
	/* 0x194e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1953:
	/* 0x1953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1955:
	/* 0x1955: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1957:
	/* 0x1957: js     5cb7 <generic_sleepable_preload+0x5cb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23735ULL;
	}
x86_l_195d:
	/* 0x195d: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1962:
	/* 0x1962: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_196c:
	/* 0x196c: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_1972:
	/* 0x1972: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_197a:
	/* 0x197a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_197e:
	/* 0x197e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1982:
	/* 0x1982: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_198c:
	/* 0x198c: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_1992:
	/* 0x1992: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1995:
	/* 0x1995: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_199a:
	/* 0x199a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_199f:
	/* 0x199f: jmp    1c70 <generic_sleepable_preload+0x1c70> */
	return 7280ULL;
x86_l_19a4:
	/* 0x19a4: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_19a7:
	/* 0x19a7: je     19c9 <generic_sleepable_preload+0x19c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19c9;
	}
x86_l_19a9:
	/* 0x19a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19ac:
	/* 0x19ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19b1:
	/* 0x19b1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19b6:
	/* 0x19b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ba:
	/* 0x19ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19bf:
	/* 0x19bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c1:
	/* 0x19c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19c3:
	/* 0x19c3: js     1c8d <generic_sleepable_preload+0x1c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7309ULL;
	}
x86_l_19c9:
	/* 0x19c9: cmp    WORD PTR [r12+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_19d0:
	/* 0x19d0: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_19d6:
	/* 0x19d6: mov    ecx,DWORD PTR [r12+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19db:
	/* 0x19db: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_19df:
	/* 0x19df: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e3:
	/* 0x19e3: cmp    WORD PTR [r12+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_19ea:
	/* 0x19ea: je     1a0c <generic_sleepable_preload+0x1a0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a0c;
	}
x86_l_19ec:
	/* 0x19ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19ef:
	/* 0x19ef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19f4:
	/* 0x19f4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19f9:
	/* 0x19f9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19fd:
	/* 0x19fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a02:
	/* 0x1a02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a04:
	/* 0x1a04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a06:
	/* 0x1a06: js     1c9e <generic_sleepable_preload+0x1c9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7326ULL;
	}
x86_l_1a0c:
	/* 0x1a0c: cmp    WORD PTR [r12+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1a16:
	/* 0x1a16: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_1a1c:
	/* 0x1a1c: mov    ecx,DWORD PTR [r12+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a24:
	/* 0x1a24: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a28:
	/* 0x1a28: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2c:
	/* 0x1a2c: cmp    WORD PTR [r12+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1a36:
	/* 0x1a36: je     1a58 <generic_sleepable_preload+0x1a58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a58;
	}
x86_l_1a38:
	/* 0x1a38: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a3b:
	/* 0x1a3b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a40:
	/* 0x1a40: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a45:
	/* 0x1a45: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a49:
	/* 0x1a49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a4e:
	/* 0x1a4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a50:
	/* 0x1a50: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a52:
	/* 0x1a52: js     1caf <generic_sleepable_preload+0x1caf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7343ULL;
	}
x86_l_1a58:
	/* 0x1a58: cmp    WORD PTR [r12+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1a62:
	/* 0x1a62: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7551ULL;
	}
x86_l_1a68:
	/* 0x1a68: mov    ecx,DWORD PTR [r12+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a70:
	/* 0x1a70: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a74:
	/* 0x1a74: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a78:
	/* 0x1a78: cmp    WORD PTR [r12+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
	return 6786ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6786ULL: goto x86_l_1a82;
	case 6788ULL: goto x86_l_1a84;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6801ULL: goto x86_l_1a91;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6812ULL: goto x86_l_1a9c;
	case 6814ULL: goto x86_l_1a9e;
	case 6820ULL: goto x86_l_1aa4;
	case 6830ULL: goto x86_l_1aae;
	case 6836ULL: goto x86_l_1ab4;
	case 6844ULL: goto x86_l_1abc;
	case 6848ULL: goto x86_l_1ac0;
	case 6852ULL: goto x86_l_1ac4;
	case 6862ULL: goto x86_l_1ace;
	case 6864ULL: goto x86_l_1ad0;
	case 6867ULL: goto x86_l_1ad3;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6888ULL: goto x86_l_1ae8;
	case 6890ULL: goto x86_l_1aea;
	case 6896ULL: goto x86_l_1af0;
	case 6906ULL: goto x86_l_1afa;
	case 6912ULL: goto x86_l_1b00;
	case 6920ULL: goto x86_l_1b08;
	case 6924ULL: goto x86_l_1b0c;
	case 6928ULL: goto x86_l_1b10;
	case 6938ULL: goto x86_l_1b1a;
	case 6940ULL: goto x86_l_1b1c;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6964ULL: goto x86_l_1b34;
	case 6966ULL: goto x86_l_1b36;
	case 6972ULL: goto x86_l_1b3c;
	case 6982ULL: goto x86_l_1b46;
	case 6988ULL: goto x86_l_1b4c;
	case 6996ULL: goto x86_l_1b54;
	case 7000ULL: goto x86_l_1b58;
	case 7004ULL: goto x86_l_1b5c;
	case 7014ULL: goto x86_l_1b66;
	case 7016ULL: goto x86_l_1b68;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7029ULL: goto x86_l_1b75;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7040ULL: goto x86_l_1b80;
	case 7042ULL: goto x86_l_1b82;
	case 7048ULL: goto x86_l_1b88;
	case 7058ULL: goto x86_l_1b92;
	case 7064ULL: goto x86_l_1b98;
	case 7067ULL: goto x86_l_1b9b;
	case 7075ULL: goto x86_l_1ba3;
	case 7079ULL: goto x86_l_1ba7;
	case 7083ULL: goto x86_l_1bab;
	case 7093ULL: goto x86_l_1bb5;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7112ULL: goto x86_l_1bc8;
	case 7117ULL: goto x86_l_1bcd;
	case 7119ULL: goto x86_l_1bcf;
	case 7121ULL: goto x86_l_1bd1;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7142ULL: goto x86_l_1be6;
	case 7145ULL: goto x86_l_1be9;
	case 7151ULL: goto x86_l_1bef;
	case 7159ULL: goto x86_l_1bf7;
	case 7163ULL: goto x86_l_1bfb;
	case 7167ULL: goto x86_l_1bff;
	case 7177ULL: goto x86_l_1c09;
	case 7179ULL: goto x86_l_1c0b;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7203ULL: goto x86_l_1c23;
	case 7205ULL: goto x86_l_1c25;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7226ULL: goto x86_l_1c3a;
	case 7229ULL: goto x86_l_1c3d;
	case 7235ULL: goto x86_l_1c43;
	case 7243ULL: goto x86_l_1c4b;
	case 7247ULL: goto x86_l_1c4f;
	case 7251ULL: goto x86_l_1c53;
	case 7261ULL: goto x86_l_1c5d;
	case 7267ULL: goto x86_l_1c63;
	case 7270ULL: goto x86_l_1c66;
	case 7275ULL: goto x86_l_1c6b;
	case 7280ULL: goto x86_l_1c70;
	case 7284ULL: goto x86_l_1c74;
	case 7289ULL: goto x86_l_1c79;
	case 7291ULL: goto x86_l_1c7b;
	case 7293ULL: goto x86_l_1c7d;
	case 7299ULL: goto x86_l_1c83;
	case 7304ULL: goto x86_l_1c88;
	case 7309ULL: goto x86_l_1c8d;
	case 7314ULL: goto x86_l_1c92;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7326ULL: goto x86_l_1c9e;
	case 7331ULL: goto x86_l_1ca3;
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7360ULL: goto x86_l_1cc0;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7387ULL: goto x86_l_1cdb;
	case 7392ULL: goto x86_l_1ce0;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7404ULL: goto x86_l_1cec;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7417ULL: goto x86_l_1cf9;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7430ULL: goto x86_l_1d06;
	case 7435ULL: goto x86_l_1d0b;
	case 7438ULL: goto x86_l_1d0e;
	case 7440ULL: goto x86_l_1d10;
	case 7443ULL: goto x86_l_1d13;
	case 7449ULL: goto x86_l_1d19;
	case 7452ULL: goto x86_l_1d1c;
	case 7456ULL: goto x86_l_1d20;
	case 7461ULL: goto x86_l_1d25;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7476ULL: goto x86_l_1d34;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7495ULL: goto x86_l_1d47;
	case 7498ULL: goto x86_l_1d4a;
	case 7504ULL: goto x86_l_1d50;
	case 7507ULL: goto x86_l_1d53;
	case 7514ULL: goto x86_l_1d5a;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7529ULL: goto x86_l_1d69;
	case 7532ULL: goto x86_l_1d6c;
	case 7534ULL: goto x86_l_1d6e;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7551ULL: goto x86_l_1d7f;
	case 7554ULL: goto x86_l_1d82;
	case 7560ULL: goto x86_l_1d88;
	case 7563ULL: goto x86_l_1d8b;
	case 7567ULL: goto x86_l_1d8f;
	case 7572ULL: goto x86_l_1d94;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7587ULL: goto x86_l_1da3;
	case 7594ULL: goto x86_l_1daa;
	case 7599ULL: goto x86_l_1daf;
	case 7604ULL: goto x86_l_1db4;
	case 7606ULL: goto x86_l_1db6;
	case 7609ULL: goto x86_l_1db9;
	case 7611ULL: goto x86_l_1dbb;
	case 7614ULL: goto x86_l_1dbe;
	case 7621ULL: goto x86_l_1dc5;
	case 7623ULL: goto x86_l_1dc7;
	case 7628ULL: goto x86_l_1dcc;
	case 7633ULL: goto x86_l_1dd1;
	case 7636ULL: goto x86_l_1dd4;
	case 7639ULL: goto x86_l_1dd7;
	case 7641ULL: goto x86_l_1dd9;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7651ULL: goto x86_l_1de3;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7666ULL: goto x86_l_1df2;
	case 7669ULL: goto x86_l_1df5;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7678ULL: goto x86_l_1dfe;
	case 7683ULL: goto x86_l_1e03;
	case 7686ULL: goto x86_l_1e06;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7698ULL: goto x86_l_1e12;
	case 7701ULL: goto x86_l_1e15;
	case 7703ULL: goto x86_l_1e17;
	case 7705ULL: goto x86_l_1e19;
	case 7710ULL: goto x86_l_1e1e;
	case 7712ULL: goto x86_l_1e20;
	case 7715ULL: goto x86_l_1e23;
	case 7720ULL: goto x86_l_1e28;
	case 7725ULL: goto x86_l_1e2d;
	case 7731ULL: goto x86_l_1e33;
	case 7733ULL: goto x86_l_1e35;
	case 7735ULL: goto x86_l_1e37;
	case 7740ULL: goto x86_l_1e3c;
	case 7743ULL: goto x86_l_1e3f;
	case 7749ULL: goto x86_l_1e45;
	case 7752ULL: goto x86_l_1e48;
	case 7758ULL: goto x86_l_1e4e;
	case 7761ULL: goto x86_l_1e51;
	case 7767ULL: goto x86_l_1e57;
	case 7770ULL: goto x86_l_1e5a;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7786ULL: goto x86_l_1e6a;
	case 7795ULL: goto x86_l_1e73;
	case 7804ULL: goto x86_l_1e7c;
	case 7810ULL: goto x86_l_1e82;
	case 7812ULL: goto x86_l_1e84;
	case 7815ULL: goto x86_l_1e87;
	case 7817ULL: goto x86_l_1e89;
	case 7820ULL: goto x86_l_1e8c;
	case 7822ULL: goto x86_l_1e8e;
	case 7825ULL: goto x86_l_1e91;
	case 7831ULL: goto x86_l_1e97;
	case 7836ULL: goto x86_l_1e9c;
	case 7839ULL: goto x86_l_1e9f;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7853ULL: goto x86_l_1ead;
	case 7859ULL: goto x86_l_1eb3;
	case 7864ULL: goto x86_l_1eb8;
	case 7867ULL: goto x86_l_1ebb;
	case 7873ULL: goto x86_l_1ec1;
	case 7878ULL: goto x86_l_1ec6;
	case 7881ULL: goto x86_l_1ec9;
	case 7883ULL: goto x86_l_1ecb;
	case 7886ULL: goto x86_l_1ece;
	case 7892ULL: goto x86_l_1ed4;
	case 7894ULL: goto x86_l_1ed6;
	case 7900ULL: goto x86_l_1edc;
	case 7903ULL: goto x86_l_1edf;
	case 7906ULL: goto x86_l_1ee2;
	case 7912ULL: goto x86_l_1ee8;
	case 7917ULL: goto x86_l_1eed;
	case 7919ULL: goto x86_l_1eef;
	case 7921ULL: goto x86_l_1ef1;
	case 7924ULL: goto x86_l_1ef4;
	case 7926ULL: goto x86_l_1ef6;
	case 7931ULL: goto x86_l_1efb;
	case 7933ULL: goto x86_l_1efd;
	case 7936ULL: goto x86_l_1f00;
	case 7942ULL: goto x86_l_1f06;
	case 7950ULL: goto x86_l_1f0e;
	case 7953ULL: goto x86_l_1f11;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7967ULL: goto x86_l_1f1f;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7981ULL: goto x86_l_1f2d;
	case 7987ULL: goto x86_l_1f33;
	case 7995ULL: goto x86_l_1f3b;
	case 7998ULL: goto x86_l_1f3e;
	case 8004ULL: goto x86_l_1f44;
	case 8009ULL: goto x86_l_1f49;
	case 8012ULL: goto x86_l_1f4c;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8037ULL: goto x86_l_1f65;
	case 8042ULL: goto x86_l_1f6a;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8051ULL: goto x86_l_1f73;
	case 8054ULL: goto x86_l_1f76;
	case 8064ULL: goto x86_l_1f80;
	case 8070ULL: goto x86_l_1f86;
	case 8077ULL: goto x86_l_1f8d;
	case 8080ULL: goto x86_l_1f90;
	case 8088ULL: goto x86_l_1f98;
	case 8091ULL: goto x86_l_1f9b;
	case 8095ULL: goto x86_l_1f9f;
	case 8104ULL: goto x86_l_1fa8;
	case 8106ULL: goto x86_l_1faa;
	case 8112ULL: goto x86_l_1fb0;
	case 8115ULL: goto x86_l_1fb3;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8134ULL: goto x86_l_1fc6;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8143ULL: goto x86_l_1fcf;
	case 8149ULL: goto x86_l_1fd5;
	case 8159ULL: goto x86_l_1fdf;
	case 8165ULL: goto x86_l_1fe5;
	case 8173ULL: goto x86_l_1fed;
	case 8177ULL: goto x86_l_1ff1;
	case 8181ULL: goto x86_l_1ff5;
	case 8191ULL: goto x86_l_1fff;
	case 8193ULL: goto x86_l_2001;
	case 8196ULL: goto x86_l_2004;
	case 8201ULL: goto x86_l_2009;
	case 8206ULL: goto x86_l_200e;
	case 8210ULL: goto x86_l_2012;
	case 8215ULL: goto x86_l_2017;
	case 8217ULL: goto x86_l_2019;
	case 8219ULL: goto x86_l_201b;
	case 8225ULL: goto x86_l_2021;
	case 8235ULL: goto x86_l_202b;
	case 8241ULL: goto x86_l_2031;
	case 8249ULL: goto x86_l_2039;
	case 8253ULL: goto x86_l_203d;
	case 8257ULL: goto x86_l_2041;
	case 8267ULL: goto x86_l_204b;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8286ULL: goto x86_l_205e;
	case 8291ULL: goto x86_l_2063;
	case 8293ULL: goto x86_l_2065;
	case 8295ULL: goto x86_l_2067;
	case 8301ULL: goto x86_l_206d;
	case 8311ULL: goto x86_l_2077;
	case 8317ULL: goto x86_l_207d;
	case 8325ULL: goto x86_l_2085;
	case 8329ULL: goto x86_l_2089;
	case 8333ULL: goto x86_l_208d;
	case 8343ULL: goto x86_l_2097;
	case 8345ULL: goto x86_l_2099;
	case 8348ULL: goto x86_l_209c;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8362ULL: goto x86_l_20aa;
	case 8367ULL: goto x86_l_20af;
	case 8369ULL: goto x86_l_20b1;
	case 8371ULL: goto x86_l_20b3;
	case 8377ULL: goto x86_l_20b9;
	case 8387ULL: goto x86_l_20c3;
	case 8393ULL: goto x86_l_20c9;
	case 8401ULL: goto x86_l_20d1;
	case 8405ULL: goto x86_l_20d5;
	case 8409ULL: goto x86_l_20d9;
	case 8419ULL: goto x86_l_20e3;
	case 8421ULL: goto x86_l_20e5;
	case 8424ULL: goto x86_l_20e8;
	case 8429ULL: goto x86_l_20ed;
	case 8434ULL: goto x86_l_20f2;
	case 8438ULL: goto x86_l_20f6;
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8447ULL: goto x86_l_20ff;
	case 8453ULL: goto x86_l_2105;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8477ULL: goto x86_l_211d;
	case 8481ULL: goto x86_l_2121;
	case 8485ULL: goto x86_l_2125;
	case 8495ULL: goto x86_l_212f;
	case 8497ULL: goto x86_l_2131;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8510ULL: goto x86_l_213e;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8523ULL: goto x86_l_214b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1a82:
	/* 0x1a82: je     1aa4 <generic_sleepable_preload+0x1aa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aa4;
	}
x86_l_1a84:
	/* 0x1a84: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a87:
	/* 0x1a87: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a91:
	/* 0x1a91: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a95:
	/* 0x1a95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a9a:
	/* 0x1a9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a9c:
	/* 0x1a9c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a9e:
	/* 0x1a9e: js     1cc0 <generic_sleepable_preload+0x1cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cc0;
	}
x86_l_1aa4:
	/* 0x1aa4: cmp    WORD PTR [r12+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1aae:
	/* 0x1aae: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7f;
	}
x86_l_1ab4:
	/* 0x1ab4: mov    ecx,DWORD PTR [r12+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1abc:
	/* 0x1abc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac4:
	/* 0x1ac4: cmp    WORD PTR [r12+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1ace:
	/* 0x1ace: je     1af0 <generic_sleepable_preload+0x1af0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af0;
	}
x86_l_1ad0:
	/* 0x1ad0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ad3:
	/* 0x1ad3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1add:
	/* 0x1add: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae6:
	/* 0x1ae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae8:
	/* 0x1ae8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aea:
	/* 0x1aea: js     1cd1 <generic_sleepable_preload+0x1cd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cd1;
	}
x86_l_1af0:
	/* 0x1af0: cmp    WORD PTR [r12+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1afa:
	/* 0x1afa: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7f;
	}
x86_l_1b00:
	/* 0x1b00: mov    ecx,DWORD PTR [r12+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b08:
	/* 0x1b08: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b10:
	/* 0x1b10: cmp    WORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1b1a:
	/* 0x1b1a: je     1b3c <generic_sleepable_preload+0x1b3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b3c;
	}
x86_l_1b1c:
	/* 0x1b1c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b1f:
	/* 0x1b1f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b24:
	/* 0x1b24: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b29:
	/* 0x1b29: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b32:
	/* 0x1b32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b34:
	/* 0x1b34: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b36:
	/* 0x1b36: js     1ce2 <generic_sleepable_preload+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ce2;
	}
x86_l_1b3c:
	/* 0x1b3c: cmp    WORD PTR [r12+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1b46:
	/* 0x1b46: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7f;
	}
x86_l_1b4c:
	/* 0x1b4c: mov    ecx,DWORD PTR [r12+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b54:
	/* 0x1b54: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b58:
	/* 0x1b58: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b5c:
	/* 0x1b5c: cmp    WORD PTR [r12+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1b66:
	/* 0x1b66: je     1b88 <generic_sleepable_preload+0x1b88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b88;
	}
x86_l_1b68:
	/* 0x1b68: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b6b:
	/* 0x1b6b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b70:
	/* 0x1b70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b75:
	/* 0x1b75: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b79:
	/* 0x1b79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b7e:
	/* 0x1b7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b80:
	/* 0x1b80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b82:
	/* 0x1b82: js     1d77 <generic_sleepable_preload+0x1d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d77;
	}
x86_l_1b88:
	/* 0x1b88: cmp    WORD PTR [r12+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1b92:
	/* 0x1b92: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7f;
	}
x86_l_1b98:
	/* 0x1b98: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_1b9b:
	/* 0x1b9b: mov    ecx,DWORD PTR [r12+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1ba3:
	/* 0x1ba3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ba7:
	/* 0x1ba7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bab:
	/* 0x1bab: cmp    WORD PTR [r12+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1bb5:
	/* 0x1bb5: je     1bd7 <generic_sleepable_preload+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd7;
	}
x86_l_1bb7:
	/* 0x1bb7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1bba:
	/* 0x1bba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bbf:
	/* 0x1bbf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bcd:
	/* 0x1bcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcf:
	/* 0x1bcf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bd1:
	/* 0x1bd1: js     5c4a <generic_sleepable_preload+0x5c4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23626ULL;
	}
x86_l_1bd7:
	/* 0x1bd7: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bdc:
	/* 0x1bdc: cmp    WORD PTR [r12+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1be6:
	/* 0x1be6: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1be9:
	/* 0x1be9: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7f;
	}
x86_l_1bef:
	/* 0x1bef: mov    ecx,DWORD PTR [r12+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1bf7:
	/* 0x1bf7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bff:
	/* 0x1bff: cmp    WORD PTR [r12+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1c09:
	/* 0x1c09: je     1c2b <generic_sleepable_preload+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2b;
	}
x86_l_1c0b:
	/* 0x1c0b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c0e:
	/* 0x1c0e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c13:
	/* 0x1c13: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c18:
	/* 0x1c18: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1c:
	/* 0x1c1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c21:
	/* 0x1c21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c23:
	/* 0x1c23: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c25:
	/* 0x1c25: js     5d4a <generic_sleepable_preload+0x5d4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23882ULL;
	}
x86_l_1c2b:
	/* 0x1c2b: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c30:
	/* 0x1c30: cmp    WORD PTR [r12+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1c3a:
	/* 0x1c3a: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1c3d:
	/* 0x1c3d: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7f;
	}
x86_l_1c43:
	/* 0x1c43: mov    ecx,DWORD PTR [r12+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1c4b:
	/* 0x1c4b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c4f:
	/* 0x1c4f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c53:
	/* 0x1c53: cmp    WORD PTR [r12+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1c5d:
	/* 0x1c5d: je     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7f;
	}
x86_l_1c63:
	/* 0x1c63: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c66:
	/* 0x1c66: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c6b:
	/* 0x1c6b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c70:
	/* 0x1c70: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c74:
	/* 0x1c74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c79:
	/* 0x1c79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7b:
	/* 0x1c7b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c7d:
	/* 0x1c7d: jns    1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1d7f;
	}
x86_l_1c83:
	/* 0x1c83: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_1c88:
	/* 0x1c88: jmp    1d7c <generic_sleepable_preload+0x1d7c> */
	goto x86_l_1d7c;
x86_l_1c8d:
	/* 0x1c8d: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1c92:
	/* 0x1c92: jmp    1d7c <generic_sleepable_preload+0x1d7c> */
	goto x86_l_1d7c;
x86_l_1c97:
	/* 0x1c97: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1c9c:
	/* 0x1c9c: jmp    1cf1 <generic_sleepable_preload+0x1cf1> */
	goto x86_l_1cf1;
x86_l_1c9e:
	/* 0x1c9e: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1ca3:
	/* 0x1ca3: jmp    1d7c <generic_sleepable_preload+0x1d7c> */
	goto x86_l_1d7c;
x86_l_1ca8:
	/* 0x1ca8: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cad:
	/* 0x1cad: jmp    1cf1 <generic_sleepable_preload+0x1cf1> */
	goto x86_l_1cf1;
x86_l_1caf:
	/* 0x1caf: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1cb4:
	/* 0x1cb4: jmp    1d7c <generic_sleepable_preload+0x1d7c> */
	goto x86_l_1d7c;
x86_l_1cb9:
	/* 0x1cb9: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1cbe:
	/* 0x1cbe: jmp    1cf1 <generic_sleepable_preload+0x1cf1> */
	goto x86_l_1cf1;
x86_l_1cc0:
	/* 0x1cc0: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1cc5:
	/* 0x1cc5: jmp    1d7c <generic_sleepable_preload+0x1d7c> */
	goto x86_l_1d7c;
x86_l_1cca:
	/* 0x1cca: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1ccf:
	/* 0x1ccf: jmp    1cf1 <generic_sleepable_preload+0x1cf1> */
	goto x86_l_1cf1;
x86_l_1cd1:
	/* 0x1cd1: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1cd6:
	/* 0x1cd6: jmp    1d7c <generic_sleepable_preload+0x1d7c> */
	goto x86_l_1d7c;
x86_l_1cdb:
	/* 0x1cdb: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1ce0:
	/* 0x1ce0: jmp    1cf1 <generic_sleepable_preload+0x1cf1> */
	goto x86_l_1cf1;
x86_l_1ce2:
	/* 0x1ce2: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1ce7:
	/* 0x1ce7: jmp    1d7c <generic_sleepable_preload+0x1d7c> */
	goto x86_l_1d7c;
x86_l_1cec:
	/* 0x1cec: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_1cf1:
	/* 0x1cf1: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cf4:
	/* 0x1cf4: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cf9:
	/* 0x1cf9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cfc:
	/* 0x1cfc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d01:
	/* 0x1d01: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d06:
	/* 0x1d06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1d0e:
	/* 0x1d0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d10:
	/* 0x1d10: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1d13:
	/* 0x1d13: jne    1e23 <generic_sleepable_preload+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e23;
	}
x86_l_1d19:
	/* 0x1d19: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1d1c:
	/* 0x1d1c: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d20:
	/* 0x1d20: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d25:
	/* 0x1d25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d27:
	/* 0x1d27: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d2c:
	/* 0x1d2c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1d34:
	/* 0x1d34: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1d3b:
	/* 0x1d3b: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d40:
	/* 0x1d40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d45:
	/* 0x1d45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d47:
	/* 0x1d47: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d4a:
	/* 0x1d4a: je     1e20 <generic_sleepable_preload+0x1e20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e20;
	}
x86_l_1d50:
	/* 0x1d50: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1d53:
	/* 0x1d53: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1d5a:
	/* 0x1d5a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d5c:
	/* 0x1d5c: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d61:
	/* 0x1d61: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d66:
	/* 0x1d66: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d69:
	/* 0x1d69: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1d6c:
	/* 0x1d6c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d6e:
	/* 0x1d6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d70:
	/* 0x1d70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d75:
	/* 0x1d75: jmp    1de0 <generic_sleepable_preload+0x1de0> */
	goto x86_l_1de0;
x86_l_1d77:
	/* 0x1d77: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_1d7c:
	/* 0x1d7c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d7f:
	/* 0x1d7f: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1d82:
	/* 0x1d82: jne    1e23 <generic_sleepable_preload+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e23;
	}
x86_l_1d88:
	/* 0x1d88: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1d8b:
	/* 0x1d8b: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8f:
	/* 0x1d8f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d94:
	/* 0x1d94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d96:
	/* 0x1d96: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1da3:
	/* 0x1da3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1daa:
	/* 0x1daa: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1daf:
	/* 0x1daf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db4:
	/* 0x1db4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db6:
	/* 0x1db6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1db9:
	/* 0x1db9: je     1e20 <generic_sleepable_preload+0x1e20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e20;
	}
x86_l_1dbb:
	/* 0x1dbb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1dbe:
	/* 0x1dbe: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1dc5:
	/* 0x1dc5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dc7:
	/* 0x1dc7: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dd1:
	/* 0x1dd1: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1dd4:
	/* 0x1dd4: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1dd7:
	/* 0x1dd7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dd9:
	/* 0x1dd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ddb:
	/* 0x1ddb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1de0:
	/* 0x1de0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1de3:
	/* 0x1de3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1de6:
	/* 0x1de6: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1deb:
	/* 0x1deb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ded:
	/* 0x1ded: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1df0:
	/* 0x1df0: je     1e20 <generic_sleepable_preload+0x1e20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e20;
	}
x86_l_1df2:
	/* 0x1df2: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1df5:
	/* 0x1df5: je     1e1e <generic_sleepable_preload+0x1e1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e1e;
	}
x86_l_1df7:
	/* 0x1df7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1dfa:
	/* 0x1dfa: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e03:
	/* 0x1e03: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1e06:
	/* 0x1e06: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e08:
	/* 0x1e08: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1e0b:
	/* 0x1e0b: call   1e10 <generic_sleepable_preload+0x1e10> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1e10:
	/* 0x1e10: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1e12:
	/* 0x1e12: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1e15:
	/* 0x1e15: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e17:
	/* 0x1e17: jns    1e1e <generic_sleepable_preload+0x1e1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1e1e;
	}
x86_l_1e19:
	/* 0x1e19: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_1e1e:
	/* 0x1e1e: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e20:
	/* 0x1e20: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_1e23:
	/* 0x1e23: mov    eax,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e28:
	/* 0x1e28: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1e2d:
	/* 0x1e2d: je     2d8e <generic_sleepable_preload+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11662ULL;
	}
x86_l_1e33:
	/* 0x1e33: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1e35:
	/* 0x1e35: js     1e6a <generic_sleepable_preload+0x1e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e6a;
	}
x86_l_1e37:
	/* 0x1e37: mov    eax,DWORD PTR [r12+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1e3c:
	/* 0x1e3c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e3f:
	/* 0x1e3f: jle    1eed <generic_sleepable_preload+0x1eed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1eed;
	}
x86_l_1e45:
	/* 0x1e45: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e48:
	/* 0x1e48: je     1f57 <generic_sleepable_preload+0x1f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f57;
	}
x86_l_1e4e:
	/* 0x1e4e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e51:
	/* 0x1e51: je     1f5e <generic_sleepable_preload+0x1f5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5e;
	}
x86_l_1e57:
	/* 0x1e57: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e5a:
	/* 0x1e5a: jne    1f71 <generic_sleepable_preload+0x1f71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f71;
	}
x86_l_1e60:
	/* 0x1e60: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e65:
	/* 0x1e65: jmp    1f6a <generic_sleepable_preload+0x1f6a> */
	goto x86_l_1f6a;
x86_l_1e6a:
	/* 0x1e6a: movzx  eax,BYTE PTR [r12+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_1e73:
	/* 0x1e73: movzx  ecx,WORD PTR [r12+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_1e7c:
	/* 0x1e7c: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1e82:
	/* 0x1e82: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e84:
	/* 0x1e84: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1e87:
	/* 0x1e87: jle    1ec6 <generic_sleepable_preload+0x1ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ec6;
	}
x86_l_1e89:
	/* 0x1e89: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e8c:
	/* 0x1e8c: jle    1efd <generic_sleepable_preload+0x1efd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1efd;
	}
x86_l_1e8e:
	/* 0x1e8e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1e91:
	/* 0x1e91: jle    25c0 <generic_sleepable_preload+0x25c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9664ULL;
	}
x86_l_1e97:
	/* 0x1e97: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e9c:
	/* 0x1e9c: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1e9f:
	/* 0x1e9f: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9701ULL;
	}
x86_l_1ea5:
	/* 0x1ea5: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1eaa:
	/* 0x1eaa: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1ead:
	/* 0x1ead: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9701ULL;
	}
x86_l_1eb3:
	/* 0x1eb3: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1eb8:
	/* 0x1eb8: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1ebb:
	/* 0x1ebb: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9701ULL;
	}
x86_l_1ec1:
	/* 0x1ec1: jmp    25f8 <generic_sleepable_preload+0x25f8> */
	return 9720ULL;
x86_l_1ec6:
	/* 0x1ec6: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ec9:
	/* 0x1ec9: jg     1f2a <generic_sleepable_preload+0x1f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f2a;
	}
x86_l_1ecb:
	/* 0x1ecb: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ece:
	/* 0x1ece: jg     2591 <generic_sleepable_preload+0x2591> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9617ULL;
	}
x86_l_1ed4:
	/* 0x1ed4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1ed6:
	/* 0x1ed6: je     25e0 <generic_sleepable_preload+0x25e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9696ULL;
	}
x86_l_1edc:
	/* 0x1edc: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1edf:
	/* 0x1edf: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ee2:
	/* 0x1ee2: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9701ULL;
	}
x86_l_1ee8:
	/* 0x1ee8: jmp    25f8 <generic_sleepable_preload+0x25f8> */
	return 9720ULL;
x86_l_1eed:
	/* 0x1eed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eef:
	/* 0x1eef: je     1f65 <generic_sleepable_preload+0x1f65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f65;
	}
x86_l_1ef1:
	/* 0x1ef1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ef4:
	/* 0x1ef4: jne    1f71 <generic_sleepable_preload+0x1f71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f71;
	}
x86_l_1ef6:
	/* 0x1ef6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1efb:
	/* 0x1efb: jmp    1f6a <generic_sleepable_preload+0x1f6a> */
	goto x86_l_1f6a;
x86_l_1efd:
	/* 0x1efd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1f00:
	/* 0x1f00: jg     2578 <generic_sleepable_preload+0x2578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9592ULL;
	}
x86_l_1f06:
	/* 0x1f06: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f0e:
	/* 0x1f0e: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f11:
	/* 0x1f11: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9701ULL;
	}
x86_l_1f17:
	/* 0x1f17: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f1c:
	/* 0x1f1c: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1f1f:
	/* 0x1f1f: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9701ULL;
	}
x86_l_1f25:
	/* 0x1f25: jmp    25f8 <generic_sleepable_preload+0x25f8> */
	return 9720ULL;
x86_l_1f2a:
	/* 0x1f2a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1f2d:
	/* 0x1f2d: jg     25a7 <generic_sleepable_preload+0x25a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9639ULL;
	}
x86_l_1f33:
	/* 0x1f33: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f3b:
	/* 0x1f3b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1f3e:
	/* 0x1f3e: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9701ULL;
	}
x86_l_1f44:
	/* 0x1f44: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f49:
	/* 0x1f49: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1f4c:
	/* 0x1f4c: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9701ULL;
	}
x86_l_1f52:
	/* 0x1f52: jmp    25f8 <generic_sleepable_preload+0x25f8> */
	return 9720ULL;
x86_l_1f57:
	/* 0x1f57: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f5c:
	/* 0x1f5c: jmp    1f6a <generic_sleepable_preload+0x1f6a> */
	goto x86_l_1f6a;
x86_l_1f5e:
	/* 0x1f5e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f63:
	/* 0x1f63: jmp    1f6a <generic_sleepable_preload+0x1f6a> */
	goto x86_l_1f6a;
x86_l_1f65:
	/* 0x1f65: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f71:
	/* 0x1f71: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f73:
	/* 0x1f73: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1f76:
	/* 0x1f76: cmp    WORD PTR [r12+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_1f80:
	/* 0x1f80: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_1f86:
	/* 0x1f86: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1f8d:
	/* 0x1f8d: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f90:
	/* 0x1f90: mov    eax,DWORD PTR [r12+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1f98:
	/* 0x1f98: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f9b:
	/* 0x1f9b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f9f:
	/* 0x1f9f: movzx  eax,WORD PTR [r12+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_1fa8:
	/* 0x1fa8: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1faa:
	/* 0x1faa: je     227c <generic_sleepable_preload+0x227c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8828ULL;
	}
x86_l_1fb0:
	/* 0x1fb0: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1fb3:
	/* 0x1fb3: je     1fd5 <generic_sleepable_preload+0x1fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd5;
	}
x86_l_1fb5:
	/* 0x1fb5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fb8:
	/* 0x1fb8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fbd:
	/* 0x1fbd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fc2:
	/* 0x1fc2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc6:
	/* 0x1fc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fcb:
	/* 0x1fcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fcd:
	/* 0x1fcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fcf:
	/* 0x1fcf: js     256e <generic_sleepable_preload+0x256e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9582ULL;
	}
x86_l_1fd5:
	/* 0x1fd5: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1fdf:
	/* 0x1fdf: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_1fe5:
	/* 0x1fe5: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1fed:
	/* 0x1fed: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ff1:
	/* 0x1ff1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff5:
	/* 0x1ff5: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_1fff:
	/* 0x1fff: je     2021 <generic_sleepable_preload+0x2021> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2021;
	}
x86_l_2001:
	/* 0x2001: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2004:
	/* 0x2004: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2009:
	/* 0x2009: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_200e:
	/* 0x200e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2012:
	/* 0x2012: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2017:
	/* 0x2017: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2019:
	/* 0x2019: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_201b:
	/* 0x201b: js     25d6 <generic_sleepable_preload+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9686ULL;
	}
x86_l_2021:
	/* 0x2021: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_202b:
	/* 0x202b: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_2031:
	/* 0x2031: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2039:
	/* 0x2039: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_203d:
	/* 0x203d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2041:
	/* 0x2041: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_204b:
	/* 0x204b: je     206d <generic_sleepable_preload+0x206d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_206d;
	}
x86_l_204d:
	/* 0x204d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2050:
	/* 0x2050: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2055:
	/* 0x2055: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_205a:
	/* 0x205a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_205e:
	/* 0x205e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2063:
	/* 0x2063: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2065:
	/* 0x2065: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2067:
	/* 0x2067: js     2c12 <generic_sleepable_preload+0x2c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11282ULL;
	}
x86_l_206d:
	/* 0x206d: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2077:
	/* 0x2077: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_207d:
	/* 0x207d: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2085:
	/* 0x2085: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2089:
	/* 0x2089: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_208d:
	/* 0x208d: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2097:
	/* 0x2097: je     20b9 <generic_sleepable_preload+0x20b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b9;
	}
x86_l_2099:
	/* 0x2099: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_209c:
	/* 0x209c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20a1:
	/* 0x20a1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20a6:
	/* 0x20a6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20aa:
	/* 0x20aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20af:
	/* 0x20af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b1:
	/* 0x20b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20b3:
	/* 0x20b3: js     2c23 <generic_sleepable_preload+0x2c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11299ULL;
	}
x86_l_20b9:
	/* 0x20b9: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_20c3:
	/* 0x20c3: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_20c9:
	/* 0x20c9: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_20d1:
	/* 0x20d1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20d5:
	/* 0x20d5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d9:
	/* 0x20d9: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_20e3:
	/* 0x20e3: je     2105 <generic_sleepable_preload+0x2105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2105;
	}
x86_l_20e5:
	/* 0x20e5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20e8:
	/* 0x20e8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20ed:
	/* 0x20ed: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20f2:
	/* 0x20f2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f6:
	/* 0x20f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20fb:
	/* 0x20fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20fd:
	/* 0x20fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ff:
	/* 0x20ff: js     2c34 <generic_sleepable_preload+0x2c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11316ULL;
	}
x86_l_2105:
	/* 0x2105: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_210f:
	/* 0x210f: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_2115:
	/* 0x2115: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_211d:
	/* 0x211d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2121:
	/* 0x2121: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2125:
	/* 0x2125: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_212f:
	/* 0x212f: je     2151 <generic_sleepable_preload+0x2151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8529ULL;
	}
x86_l_2131:
	/* 0x2131: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2134:
	/* 0x2134: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2139:
	/* 0x2139: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_213e:
	/* 0x213e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2142:
	/* 0x2142: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2147:
	/* 0x2147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2149:
	/* 0x2149: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_214b:
	/* 0x214b: js     2c45 <generic_sleepable_preload+0x2c45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11333ULL;
	}
	return 8529ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8529ULL: goto x86_l_2151;
	case 8539ULL: goto x86_l_215b;
	case 8545ULL: goto x86_l_2161;
	case 8553ULL: goto x86_l_2169;
	case 8557ULL: goto x86_l_216d;
	case 8561ULL: goto x86_l_2171;
	case 8571ULL: goto x86_l_217b;
	case 8573ULL: goto x86_l_217d;
	case 8576ULL: goto x86_l_2180;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8605ULL: goto x86_l_219d;
	case 8615ULL: goto x86_l_21a7;
	case 8621ULL: goto x86_l_21ad;
	case 8629ULL: goto x86_l_21b5;
	case 8633ULL: goto x86_l_21b9;
	case 8637ULL: goto x86_l_21bd;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8652ULL: goto x86_l_21cc;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8666ULL: goto x86_l_21da;
	case 8671ULL: goto x86_l_21df;
	case 8673ULL: goto x86_l_21e1;
	case 8675ULL: goto x86_l_21e3;
	case 8681ULL: goto x86_l_21e9;
	case 8691ULL: goto x86_l_21f3;
	case 8697ULL: goto x86_l_21f9;
	case 8705ULL: goto x86_l_2201;
	case 8709ULL: goto x86_l_2205;
	case 8713ULL: goto x86_l_2209;
	case 8723ULL: goto x86_l_2213;
	case 8725ULL: goto x86_l_2215;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8749ULL: goto x86_l_222d;
	case 8751ULL: goto x86_l_222f;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8772ULL: goto x86_l_2244;
	case 8778ULL: goto x86_l_224a;
	case 8786ULL: goto x86_l_2252;
	case 8790ULL: goto x86_l_2256;
	case 8794ULL: goto x86_l_225a;
	case 8804ULL: goto x86_l_2264;
	case 8810ULL: goto x86_l_226a;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8833ULL: goto x86_l_2281;
	case 8836ULL: goto x86_l_2284;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8857ULL: goto x86_l_2299;
	case 8859ULL: goto x86_l_229b;
	case 8865ULL: goto x86_l_22a1;
	case 8875ULL: goto x86_l_22ab;
	case 8881ULL: goto x86_l_22b1;
	case 8889ULL: goto x86_l_22b9;
	case 8893ULL: goto x86_l_22bd;
	case 8897ULL: goto x86_l_22c1;
	case 8907ULL: goto x86_l_22cb;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8933ULL: goto x86_l_22e5;
	case 8935ULL: goto x86_l_22e7;
	case 8941ULL: goto x86_l_22ed;
	case 8951ULL: goto x86_l_22f7;
	case 8957ULL: goto x86_l_22fd;
	case 8965ULL: goto x86_l_2305;
	case 8969ULL: goto x86_l_2309;
	case 8973ULL: goto x86_l_230d;
	case 8983ULL: goto x86_l_2317;
	case 8985ULL: goto x86_l_2319;
	case 8988ULL: goto x86_l_231c;
	case 8993ULL: goto x86_l_2321;
	case 8998ULL: goto x86_l_2326;
	case 9002ULL: goto x86_l_232a;
	case 9007ULL: goto x86_l_232f;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9017ULL: goto x86_l_2339;
	case 9027ULL: goto x86_l_2343;
	case 9033ULL: goto x86_l_2349;
	case 9041ULL: goto x86_l_2351;
	case 9045ULL: goto x86_l_2355;
	case 9049ULL: goto x86_l_2359;
	case 9059ULL: goto x86_l_2363;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9069ULL: goto x86_l_236d;
	case 9074ULL: goto x86_l_2372;
	case 9078ULL: goto x86_l_2376;
	case 9083ULL: goto x86_l_237b;
	case 9085ULL: goto x86_l_237d;
	case 9087ULL: goto x86_l_237f;
	case 9093ULL: goto x86_l_2385;
	case 9103ULL: goto x86_l_238f;
	case 9109ULL: goto x86_l_2395;
	case 9117ULL: goto x86_l_239d;
	case 9121ULL: goto x86_l_23a1;
	case 9125ULL: goto x86_l_23a5;
	case 9135ULL: goto x86_l_23af;
	case 9137ULL: goto x86_l_23b1;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9150ULL: goto x86_l_23be;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9161ULL: goto x86_l_23c9;
	case 9163ULL: goto x86_l_23cb;
	case 9169ULL: goto x86_l_23d1;
	case 9179ULL: goto x86_l_23db;
	case 9185ULL: goto x86_l_23e1;
	case 9193ULL: goto x86_l_23e9;
	case 9197ULL: goto x86_l_23ed;
	case 9201ULL: goto x86_l_23f1;
	case 9211ULL: goto x86_l_23fb;
	case 9213ULL: goto x86_l_23fd;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9230ULL: goto x86_l_240e;
	case 9235ULL: goto x86_l_2413;
	case 9237ULL: goto x86_l_2415;
	case 9239ULL: goto x86_l_2417;
	case 9245ULL: goto x86_l_241d;
	case 9255ULL: goto x86_l_2427;
	case 9261ULL: goto x86_l_242d;
	case 9269ULL: goto x86_l_2435;
	case 9273ULL: goto x86_l_2439;
	case 9277ULL: goto x86_l_243d;
	case 9287ULL: goto x86_l_2447;
	case 9289ULL: goto x86_l_2449;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9302ULL: goto x86_l_2456;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9313ULL: goto x86_l_2461;
	case 9315ULL: goto x86_l_2463;
	case 9321ULL: goto x86_l_2469;
	case 9331ULL: goto x86_l_2473;
	case 9337ULL: goto x86_l_2479;
	case 9340ULL: goto x86_l_247c;
	case 9348ULL: goto x86_l_2484;
	case 9352ULL: goto x86_l_2488;
	case 9356ULL: goto x86_l_248c;
	case 9366ULL: goto x86_l_2496;
	case 9368ULL: goto x86_l_2498;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9385ULL: goto x86_l_24a9;
	case 9390ULL: goto x86_l_24ae;
	case 9392ULL: goto x86_l_24b0;
	case 9394ULL: goto x86_l_24b2;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9415ULL: goto x86_l_24c7;
	case 9418ULL: goto x86_l_24ca;
	case 9424ULL: goto x86_l_24d0;
	case 9432ULL: goto x86_l_24d8;
	case 9436ULL: goto x86_l_24dc;
	case 9440ULL: goto x86_l_24e0;
	case 9450ULL: goto x86_l_24ea;
	case 9452ULL: goto x86_l_24ec;
	case 9455ULL: goto x86_l_24ef;
	case 9460ULL: goto x86_l_24f4;
	case 9465ULL: goto x86_l_24f9;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9476ULL: goto x86_l_2504;
	case 9478ULL: goto x86_l_2506;
	case 9484ULL: goto x86_l_250c;
	case 9489ULL: goto x86_l_2511;
	case 9499ULL: goto x86_l_251b;
	case 9502ULL: goto x86_l_251e;
	case 9508ULL: goto x86_l_2524;
	case 9516ULL: goto x86_l_252c;
	case 9520ULL: goto x86_l_2530;
	case 9524ULL: goto x86_l_2534;
	case 9534ULL: goto x86_l_253e;
	case 9540ULL: goto x86_l_2544;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9553ULL: goto x86_l_2551;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9564ULL: goto x86_l_255c;
	case 9566ULL: goto x86_l_255e;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9600ULL: goto x86_l_2580;
	case 9603ULL: goto x86_l_2583;
	case 9605ULL: goto x86_l_2585;
	case 9610ULL: goto x86_l_258a;
	case 9613ULL: goto x86_l_258d;
	case 9615ULL: goto x86_l_258f;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9625ULL: goto x86_l_2599;
	case 9627ULL: goto x86_l_259b;
	case 9632ULL: goto x86_l_25a0;
	case 9635ULL: goto x86_l_25a3;
	case 9637ULL: goto x86_l_25a5;
	case 9639ULL: goto x86_l_25a7;
	case 9647ULL: goto x86_l_25af;
	case 9650ULL: goto x86_l_25b2;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9660ULL: goto x86_l_25bc;
	case 9662ULL: goto x86_l_25be;
	case 9664ULL: goto x86_l_25c0;
	case 9669ULL: goto x86_l_25c5;
	case 9672ULL: goto x86_l_25c8;
	case 9674ULL: goto x86_l_25ca;
	case 9679ULL: goto x86_l_25cf;
	case 9682ULL: goto x86_l_25d2;
	case 9684ULL: goto x86_l_25d4;
	case 9686ULL: goto x86_l_25d6;
	case 9691ULL: goto x86_l_25db;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9704ULL: goto x86_l_25e8;
	case 9706ULL: goto x86_l_25ea;
	case 9708ULL: goto x86_l_25ec;
	case 9713ULL: goto x86_l_25f1;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9731ULL: goto x86_l_2603;
	case 9734ULL: goto x86_l_2606;
	case 9744ULL: goto x86_l_2610;
	case 9750ULL: goto x86_l_2616;
	case 9757ULL: goto x86_l_261d;
	case 9760ULL: goto x86_l_2620;
	case 9768ULL: goto x86_l_2628;
	case 9771ULL: goto x86_l_262b;
	case 9775ULL: goto x86_l_262f;
	case 9784ULL: goto x86_l_2638;
	case 9786ULL: goto x86_l_263a;
	case 9792ULL: goto x86_l_2640;
	case 9795ULL: goto x86_l_2643;
	case 9797ULL: goto x86_l_2645;
	case 9800ULL: goto x86_l_2648;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9814ULL: goto x86_l_2656;
	case 9819ULL: goto x86_l_265b;
	case 9821ULL: goto x86_l_265d;
	case 9823ULL: goto x86_l_265f;
	case 9829ULL: goto x86_l_2665;
	case 9839ULL: goto x86_l_266f;
	case 9845ULL: goto x86_l_2675;
	case 9853ULL: goto x86_l_267d;
	case 9857ULL: goto x86_l_2681;
	case 9861ULL: goto x86_l_2685;
	case 9871ULL: goto x86_l_268f;
	case 9873ULL: goto x86_l_2691;
	case 9876ULL: goto x86_l_2694;
	case 9881ULL: goto x86_l_2699;
	case 9886ULL: goto x86_l_269e;
	case 9890ULL: goto x86_l_26a2;
	case 9895ULL: goto x86_l_26a7;
	case 9897ULL: goto x86_l_26a9;
	case 9899ULL: goto x86_l_26ab;
	case 9905ULL: goto x86_l_26b1;
	case 9915ULL: goto x86_l_26bb;
	case 9921ULL: goto x86_l_26c1;
	case 9929ULL: goto x86_l_26c9;
	case 9933ULL: goto x86_l_26cd;
	case 9937ULL: goto x86_l_26d1;
	case 9947ULL: goto x86_l_26db;
	case 9949ULL: goto x86_l_26dd;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9962ULL: goto x86_l_26ea;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9973ULL: goto x86_l_26f5;
	case 9975ULL: goto x86_l_26f7;
	case 9981ULL: goto x86_l_26fd;
	case 9991ULL: goto x86_l_2707;
	case 9997ULL: goto x86_l_270d;
	case 10005ULL: goto x86_l_2715;
	case 10009ULL: goto x86_l_2719;
	case 10013ULL: goto x86_l_271d;
	case 10023ULL: goto x86_l_2727;
	case 10025ULL: goto x86_l_2729;
	case 10028ULL: goto x86_l_272c;
	case 10033ULL: goto x86_l_2731;
	case 10038ULL: goto x86_l_2736;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10049ULL: goto x86_l_2741;
	case 10051ULL: goto x86_l_2743;
	case 10057ULL: goto x86_l_2749;
	case 10067ULL: goto x86_l_2753;
	case 10073ULL: goto x86_l_2759;
	case 10081ULL: goto x86_l_2761;
	case 10085ULL: goto x86_l_2765;
	case 10089ULL: goto x86_l_2769;
	case 10099ULL: goto x86_l_2773;
	case 10101ULL: goto x86_l_2775;
	case 10104ULL: goto x86_l_2778;
	case 10109ULL: goto x86_l_277d;
	case 10114ULL: goto x86_l_2782;
	case 10118ULL: goto x86_l_2786;
	case 10123ULL: goto x86_l_278b;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10133ULL: goto x86_l_2795;
	case 10143ULL: goto x86_l_279f;
	case 10149ULL: goto x86_l_27a5;
	case 10157ULL: goto x86_l_27ad;
	case 10161ULL: goto x86_l_27b1;
	case 10165ULL: goto x86_l_27b5;
	case 10175ULL: goto x86_l_27bf;
	case 10177ULL: goto x86_l_27c1;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10201ULL: goto x86_l_27d9;
	case 10203ULL: goto x86_l_27db;
	case 10209ULL: goto x86_l_27e1;
	case 10219ULL: goto x86_l_27eb;
	case 10225ULL: goto x86_l_27f1;
	case 10233ULL: goto x86_l_27f9;
	case 10237ULL: goto x86_l_27fd;
	case 10241ULL: goto x86_l_2801;
	case 10251ULL: goto x86_l_280b;
	case 10253ULL: goto x86_l_280d;
	case 10256ULL: goto x86_l_2810;
	case 10261ULL: goto x86_l_2815;
	case 10266ULL: goto x86_l_281a;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10277ULL: goto x86_l_2825;
	case 10279ULL: goto x86_l_2827;
	case 10285ULL: goto x86_l_282d;
	case 10295ULL: goto x86_l_2837;
	case 10301ULL: goto x86_l_283d;
	case 10309ULL: goto x86_l_2845;
	case 10313ULL: goto x86_l_2849;
	case 10317ULL: goto x86_l_284d;
	case 10327ULL: goto x86_l_2857;
	case 10329ULL: goto x86_l_2859;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	case 10342ULL: goto x86_l_2866;
	case 10346ULL: goto x86_l_286a;
	case 10351ULL: goto x86_l_286f;
	case 10353ULL: goto x86_l_2871;
	case 10355ULL: goto x86_l_2873;
	case 10361ULL: goto x86_l_2879;
	case 10371ULL: goto x86_l_2883;
	case 10377ULL: goto x86_l_2889;
	case 10385ULL: goto x86_l_2891;
	case 10389ULL: goto x86_l_2895;
	case 10393ULL: goto x86_l_2899;
	case 10403ULL: goto x86_l_28a3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2151:
	/* 0x2151: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_215b:
	/* 0x215b: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_2161:
	/* 0x2161: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2169:
	/* 0x2169: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_216d:
	/* 0x216d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2171:
	/* 0x2171: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_217b:
	/* 0x217b: je     219d <generic_sleepable_preload+0x219d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_219d;
	}
x86_l_217d:
	/* 0x217d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2180:
	/* 0x2180: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2185:
	/* 0x2185: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_218a:
	/* 0x218a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_218e:
	/* 0x218e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2193:
	/* 0x2193: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2195:
	/* 0x2195: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2197:
	/* 0x2197: js     2c56 <generic_sleepable_preload+0x2c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11350ULL;
	}
x86_l_219d:
	/* 0x219d: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_21a7:
	/* 0x21a7: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_21ad:
	/* 0x21ad: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_21b5:
	/* 0x21b5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21b9:
	/* 0x21b9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21bd:
	/* 0x21bd: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_21c7:
	/* 0x21c7: je     21e9 <generic_sleepable_preload+0x21e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21e9;
	}
x86_l_21c9:
	/* 0x21c9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21cc:
	/* 0x21cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21d1:
	/* 0x21d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21d6:
	/* 0x21d6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21da:
	/* 0x21da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21df:
	/* 0x21df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e1:
	/* 0x21e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21e3:
	/* 0x21e3: js     5bd9 <generic_sleepable_preload+0x5bd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23513ULL;
	}
x86_l_21e9:
	/* 0x21e9: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_21f3:
	/* 0x21f3: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_21f9:
	/* 0x21f9: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2201:
	/* 0x2201: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2205:
	/* 0x2205: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2209:
	/* 0x2209: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2213:
	/* 0x2213: je     2235 <generic_sleepable_preload+0x2235> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2235;
	}
x86_l_2215:
	/* 0x2215: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2218:
	/* 0x2218: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_221d:
	/* 0x221d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2222:
	/* 0x2222: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2226:
	/* 0x2226: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_222b:
	/* 0x222b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_222d:
	/* 0x222d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_222f:
	/* 0x222f: js     5cc9 <generic_sleepable_preload+0x5cc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23753ULL;
	}
x86_l_2235:
	/* 0x2235: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223a:
	/* 0x223a: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2244:
	/* 0x2244: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_224a:
	/* 0x224a: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2252:
	/* 0x2252: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2256:
	/* 0x2256: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225a:
	/* 0x225a: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2264:
	/* 0x2264: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_226a:
	/* 0x226a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_226d:
	/* 0x226d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2272:
	/* 0x2272: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2277:
	/* 0x2277: jmp    2551 <generic_sleepable_preload+0x2551> */
	goto x86_l_2551;
x86_l_227c:
	/* 0x227c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_227f:
	/* 0x227f: je     22a1 <generic_sleepable_preload+0x22a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a1;
	}
x86_l_2281:
	/* 0x2281: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2284:
	/* 0x2284: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2289:
	/* 0x2289: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_228e:
	/* 0x228e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2292:
	/* 0x2292: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2297:
	/* 0x2297: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2299:
	/* 0x2299: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_229b:
	/* 0x229b: js     256e <generic_sleepable_preload+0x256e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_256e;
	}
x86_l_22a1:
	/* 0x22a1: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_22ab:
	/* 0x22ab: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_22b1:
	/* 0x22b1: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_22b9:
	/* 0x22b9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22bd:
	/* 0x22bd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c1:
	/* 0x22c1: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_22cb:
	/* 0x22cb: je     22ed <generic_sleepable_preload+0x22ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22ed;
	}
x86_l_22cd:
	/* 0x22cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22d0:
	/* 0x22d0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22d5:
	/* 0x22d5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22da:
	/* 0x22da: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22de:
	/* 0x22de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e3:
	/* 0x22e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e5:
	/* 0x22e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e7:
	/* 0x22e7: js     25d6 <generic_sleepable_preload+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25d6;
	}
x86_l_22ed:
	/* 0x22ed: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_22f7:
	/* 0x22f7: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_22fd:
	/* 0x22fd: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2305:
	/* 0x2305: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2309:
	/* 0x2309: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230d:
	/* 0x230d: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2317:
	/* 0x2317: je     2339 <generic_sleepable_preload+0x2339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2339;
	}
x86_l_2319:
	/* 0x2319: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_231c:
	/* 0x231c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2321:
	/* 0x2321: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2326:
	/* 0x2326: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232a:
	/* 0x232a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_232f:
	/* 0x232f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2331:
	/* 0x2331: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2333:
	/* 0x2333: js     2c12 <generic_sleepable_preload+0x2c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11282ULL;
	}
x86_l_2339:
	/* 0x2339: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2343:
	/* 0x2343: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_2349:
	/* 0x2349: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2351:
	/* 0x2351: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2355:
	/* 0x2355: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2359:
	/* 0x2359: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2363:
	/* 0x2363: je     2385 <generic_sleepable_preload+0x2385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2385;
	}
x86_l_2365:
	/* 0x2365: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2368:
	/* 0x2368: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_236d:
	/* 0x236d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2372:
	/* 0x2372: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2376:
	/* 0x2376: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_237b:
	/* 0x237b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237d:
	/* 0x237d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_237f:
	/* 0x237f: js     2c23 <generic_sleepable_preload+0x2c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11299ULL;
	}
x86_l_2385:
	/* 0x2385: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_238f:
	/* 0x238f: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_2395:
	/* 0x2395: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_239d:
	/* 0x239d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23a1:
	/* 0x23a1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a5:
	/* 0x23a5: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_23af:
	/* 0x23af: je     23d1 <generic_sleepable_preload+0x23d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23d1;
	}
x86_l_23b1:
	/* 0x23b1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23b4:
	/* 0x23b4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23b9:
	/* 0x23b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23be:
	/* 0x23be: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c2:
	/* 0x23c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23c7:
	/* 0x23c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c9:
	/* 0x23c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23cb:
	/* 0x23cb: js     2c34 <generic_sleepable_preload+0x2c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11316ULL;
	}
x86_l_23d1:
	/* 0x23d1: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_23db:
	/* 0x23db: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_23e1:
	/* 0x23e1: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_23e9:
	/* 0x23e9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23ed:
	/* 0x23ed: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f1:
	/* 0x23f1: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_23fb:
	/* 0x23fb: je     241d <generic_sleepable_preload+0x241d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_241d;
	}
x86_l_23fd:
	/* 0x23fd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2400:
	/* 0x2400: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2405:
	/* 0x2405: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_240a:
	/* 0x240a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240e:
	/* 0x240e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2413:
	/* 0x2413: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2415:
	/* 0x2415: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2417:
	/* 0x2417: js     2c45 <generic_sleepable_preload+0x2c45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11333ULL;
	}
x86_l_241d:
	/* 0x241d: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2427:
	/* 0x2427: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_242d:
	/* 0x242d: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2435:
	/* 0x2435: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2439:
	/* 0x2439: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243d:
	/* 0x243d: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2447:
	/* 0x2447: je     2469 <generic_sleepable_preload+0x2469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2469;
	}
x86_l_2449:
	/* 0x2449: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_244c:
	/* 0x244c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2451:
	/* 0x2451: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2456:
	/* 0x2456: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_245a:
	/* 0x245a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_245f:
	/* 0x245f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2461:
	/* 0x2461: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2463:
	/* 0x2463: js     2c56 <generic_sleepable_preload+0x2c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11350ULL;
	}
x86_l_2469:
	/* 0x2469: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2473:
	/* 0x2473: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_2479:
	/* 0x2479: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_247c:
	/* 0x247c: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2484:
	/* 0x2484: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2488:
	/* 0x2488: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_248c:
	/* 0x248c: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2496:
	/* 0x2496: je     24b8 <generic_sleepable_preload+0x24b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24b8;
	}
x86_l_2498:
	/* 0x2498: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_249b:
	/* 0x249b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24a0:
	/* 0x24a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24a5:
	/* 0x24a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a9:
	/* 0x24a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24ae:
	/* 0x24ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b0:
	/* 0x24b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b2:
	/* 0x24b2: js     5c57 <generic_sleepable_preload+0x5c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23639ULL;
	}
x86_l_24b8:
	/* 0x24b8: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24bd:
	/* 0x24bd: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_24c7:
	/* 0x24c7: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_24ca:
	/* 0x24ca: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_24d0:
	/* 0x24d0: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_24d8:
	/* 0x24d8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24dc:
	/* 0x24dc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e0:
	/* 0x24e0: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_24ea:
	/* 0x24ea: je     250c <generic_sleepable_preload+0x250c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250c;
	}
x86_l_24ec:
	/* 0x24ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24ef:
	/* 0x24ef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24f4:
	/* 0x24f4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24f9:
	/* 0x24f9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24fd:
	/* 0x24fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2502:
	/* 0x2502: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2504:
	/* 0x2504: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2506:
	/* 0x2506: js     5d5f <generic_sleepable_preload+0x5d5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23903ULL;
	}
x86_l_250c:
	/* 0x250c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2511:
	/* 0x2511: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_251b:
	/* 0x251b: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_251e:
	/* 0x251e: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_2524:
	/* 0x2524: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_252c:
	/* 0x252c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2530:
	/* 0x2530: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2534:
	/* 0x2534: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_253e:
	/* 0x253e: je     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11358ULL;
	}
x86_l_2544:
	/* 0x2544: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2547:
	/* 0x2547: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_254c:
	/* 0x254c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2551:
	/* 0x2551: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2555:
	/* 0x2555: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_255a:
	/* 0x255a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255c:
	/* 0x255c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_255e:
	/* 0x255e: jns    2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11358ULL;
	}
x86_l_2564:
	/* 0x2564: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2569:
	/* 0x2569: jmp    2c5b <generic_sleepable_preload+0x2c5b> */
	return 11355ULL;
x86_l_256e:
	/* 0x256e: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2573:
	/* 0x2573: jmp    2c5b <generic_sleepable_preload+0x2c5b> */
	return 11355ULL;
x86_l_2578:
	/* 0x2578: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2580:
	/* 0x2580: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_2583:
	/* 0x2583: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e5;
	}
x86_l_2585:
	/* 0x2585: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_258a:
	/* 0x258a: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_258d:
	/* 0x258d: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e5;
	}
x86_l_258f:
	/* 0x258f: jmp    25f8 <generic_sleepable_preload+0x25f8> */
	goto x86_l_25f8;
x86_l_2591:
	/* 0x2591: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2596:
	/* 0x2596: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2599:
	/* 0x2599: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e5;
	}
x86_l_259b:
	/* 0x259b: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25a0:
	/* 0x25a0: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_25a3:
	/* 0x25a3: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e5;
	}
x86_l_25a5:
	/* 0x25a5: jmp    25f8 <generic_sleepable_preload+0x25f8> */
	goto x86_l_25f8;
x86_l_25a7:
	/* 0x25a7: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_25af:
	/* 0x25af: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_25b2:
	/* 0x25b2: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e5;
	}
x86_l_25b4:
	/* 0x25b4: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25b9:
	/* 0x25b9: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_25bc:
	/* 0x25bc: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e5;
	}
x86_l_25be:
	/* 0x25be: jmp    25f8 <generic_sleepable_preload+0x25f8> */
	goto x86_l_25f8;
x86_l_25c0:
	/* 0x25c0: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25c5:
	/* 0x25c5: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_25c8:
	/* 0x25c8: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e5;
	}
x86_l_25ca:
	/* 0x25ca: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25cf:
	/* 0x25cf: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_25d2:
	/* 0x25d2: je     25e5 <generic_sleepable_preload+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e5;
	}
x86_l_25d4:
	/* 0x25d4: jmp    25f8 <generic_sleepable_preload+0x25f8> */
	goto x86_l_25f8;
x86_l_25d6:
	/* 0x25d6: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_25db:
	/* 0x25db: jmp    2c5b <generic_sleepable_preload+0x2c5b> */
	return 11355ULL;
x86_l_25e0:
	/* 0x25e0: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25e5:
	/* 0x25e5: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_25e8:
	/* 0x25e8: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_25ea:
	/* 0x25ea: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_25ec:
	/* 0x25ec: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_25f1:
	/* 0x25f1: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25f3:
	/* 0x25f3: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_25f8:
	/* 0x25f8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25fc:
	/* 0x25fc: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2601:
	/* 0x2601: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2603:
	/* 0x2603: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_2606:
	/* 0x2606: cmp    WORD PTR [r12+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_2610:
	/* 0x2610: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_2616:
	/* 0x2616: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_261d:
	/* 0x261d: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2620:
	/* 0x2620: mov    eax,DWORD PTR [r12+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2628:
	/* 0x2628: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_262b:
	/* 0x262b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_262f:
	/* 0x262f: movzx  eax,WORD PTR [r12+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_2638:
	/* 0x2638: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_263a:
	/* 0x263a: je     290c <generic_sleepable_preload+0x290c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10508ULL;
	}
x86_l_2640:
	/* 0x2640: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2643:
	/* 0x2643: je     2665 <generic_sleepable_preload+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2665;
	}
x86_l_2645:
	/* 0x2645: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2648:
	/* 0x2648: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_264d:
	/* 0x264d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2652:
	/* 0x2652: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2656:
	/* 0x2656: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_265b:
	/* 0x265b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265d:
	/* 0x265d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_265f:
	/* 0x265f: js     2bfe <generic_sleepable_preload+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11262ULL;
	}
x86_l_2665:
	/* 0x2665: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_266f:
	/* 0x266f: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_2675:
	/* 0x2675: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_267d:
	/* 0x267d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2681:
	/* 0x2681: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2685:
	/* 0x2685: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_268f:
	/* 0x268f: je     26b1 <generic_sleepable_preload+0x26b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b1;
	}
x86_l_2691:
	/* 0x2691: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2694:
	/* 0x2694: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2699:
	/* 0x2699: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_269e:
	/* 0x269e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a2:
	/* 0x26a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26a7:
	/* 0x26a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26a9:
	/* 0x26a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26ab:
	/* 0x26ab: js     2c08 <generic_sleepable_preload+0x2c08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11272ULL;
	}
x86_l_26b1:
	/* 0x26b1: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_26bb:
	/* 0x26bb: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_26c1:
	/* 0x26c1: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_26c9:
	/* 0x26c9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26cd:
	/* 0x26cd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d1:
	/* 0x26d1: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_26db:
	/* 0x26db: je     26fd <generic_sleepable_preload+0x26fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26fd;
	}
x86_l_26dd:
	/* 0x26dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26e0:
	/* 0x26e0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26e5:
	/* 0x26e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26ea:
	/* 0x26ea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ee:
	/* 0x26ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26f3:
	/* 0x26f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f5:
	/* 0x26f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26f7:
	/* 0x26f7: js     2c19 <generic_sleepable_preload+0x2c19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11289ULL;
	}
x86_l_26fd:
	/* 0x26fd: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2707:
	/* 0x2707: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_270d:
	/* 0x270d: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2715:
	/* 0x2715: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2719:
	/* 0x2719: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271d:
	/* 0x271d: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2727:
	/* 0x2727: je     2749 <generic_sleepable_preload+0x2749> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2749;
	}
x86_l_2729:
	/* 0x2729: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_272c:
	/* 0x272c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2731:
	/* 0x2731: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2736:
	/* 0x2736: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273a:
	/* 0x273a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_273f:
	/* 0x273f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2741:
	/* 0x2741: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2743:
	/* 0x2743: js     2c2a <generic_sleepable_preload+0x2c2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11306ULL;
	}
x86_l_2749:
	/* 0x2749: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2753:
	/* 0x2753: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_2759:
	/* 0x2759: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2761:
	/* 0x2761: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2765:
	/* 0x2765: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2769:
	/* 0x2769: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2773:
	/* 0x2773: je     2795 <generic_sleepable_preload+0x2795> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2795;
	}
x86_l_2775:
	/* 0x2775: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2778:
	/* 0x2778: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_277d:
	/* 0x277d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2782:
	/* 0x2782: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2786:
	/* 0x2786: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_278b:
	/* 0x278b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278d:
	/* 0x278d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_278f:
	/* 0x278f: js     2c3b <generic_sleepable_preload+0x2c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11323ULL;
	}
x86_l_2795:
	/* 0x2795: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_279f:
	/* 0x279f: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_27a5:
	/* 0x27a5: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_27ad:
	/* 0x27ad: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27b1:
	/* 0x27b1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b5:
	/* 0x27b5: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_27bf:
	/* 0x27bf: je     27e1 <generic_sleepable_preload+0x27e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e1;
	}
x86_l_27c1:
	/* 0x27c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27c4:
	/* 0x27c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27c9:
	/* 0x27c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27ce:
	/* 0x27ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d2:
	/* 0x27d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27d7:
	/* 0x27d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d9:
	/* 0x27d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27db:
	/* 0x27db: js     2c4c <generic_sleepable_preload+0x2c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11340ULL;
	}
x86_l_27e1:
	/* 0x27e1: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_27eb:
	/* 0x27eb: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_27f1:
	/* 0x27f1: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_27f9:
	/* 0x27f9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27fd:
	/* 0x27fd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2801:
	/* 0x2801: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_280b:
	/* 0x280b: je     282d <generic_sleepable_preload+0x282d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_282d;
	}
x86_l_280d:
	/* 0x280d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2810:
	/* 0x2810: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2815:
	/* 0x2815: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_281a:
	/* 0x281a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_281e:
	/* 0x281e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2823:
	/* 0x2823: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2825:
	/* 0x2825: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2827:
	/* 0x2827: js     2ce1 <generic_sleepable_preload+0x2ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11489ULL;
	}
x86_l_282d:
	/* 0x282d: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2837:
	/* 0x2837: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_283d:
	/* 0x283d: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2845:
	/* 0x2845: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2849:
	/* 0x2849: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_284d:
	/* 0x284d: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2857:
	/* 0x2857: je     2879 <generic_sleepable_preload+0x2879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2879;
	}
x86_l_2859:
	/* 0x2859: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_285c:
	/* 0x285c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2861:
	/* 0x2861: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2866:
	/* 0x2866: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286a:
	/* 0x286a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_286f:
	/* 0x286f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2871:
	/* 0x2871: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2873:
	/* 0x2873: js     5be6 <generic_sleepable_preload+0x5be6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23526ULL;
	}
x86_l_2879:
	/* 0x2879: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2883:
	/* 0x2883: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_2889:
	/* 0x2889: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2891:
	/* 0x2891: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2895:
	/* 0x2895: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2899:
	/* 0x2899: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_28a3:
	/* 0x28a3: je     28c5 <generic_sleepable_preload+0x28c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10437ULL;
	}
	return 10405ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10405ULL: goto x86_l_28a5;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10418ULL: goto x86_l_28b2;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10429ULL: goto x86_l_28bd;
	case 10431ULL: goto x86_l_28bf;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10452ULL: goto x86_l_28d4;
	case 10458ULL: goto x86_l_28da;
	case 10466ULL: goto x86_l_28e2;
	case 10470ULL: goto x86_l_28e6;
	case 10474ULL: goto x86_l_28ea;
	case 10484ULL: goto x86_l_28f4;
	case 10490ULL: goto x86_l_28fa;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10503ULL: goto x86_l_2907;
	case 10508ULL: goto x86_l_290c;
	case 10511ULL: goto x86_l_290f;
	case 10513ULL: goto x86_l_2911;
	case 10516ULL: goto x86_l_2914;
	case 10521ULL: goto x86_l_2919;
	case 10526ULL: goto x86_l_291e;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10537ULL: goto x86_l_2929;
	case 10539ULL: goto x86_l_292b;
	case 10545ULL: goto x86_l_2931;
	case 10555ULL: goto x86_l_293b;
	case 10561ULL: goto x86_l_2941;
	case 10569ULL: goto x86_l_2949;
	case 10573ULL: goto x86_l_294d;
	case 10577ULL: goto x86_l_2951;
	case 10587ULL: goto x86_l_295b;
	case 10589ULL: goto x86_l_295d;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10606ULL: goto x86_l_296e;
	case 10611ULL: goto x86_l_2973;
	case 10613ULL: goto x86_l_2975;
	case 10615ULL: goto x86_l_2977;
	case 10621ULL: goto x86_l_297d;
	case 10631ULL: goto x86_l_2987;
	case 10637ULL: goto x86_l_298d;
	case 10645ULL: goto x86_l_2995;
	case 10649ULL: goto x86_l_2999;
	case 10653ULL: goto x86_l_299d;
	case 10663ULL: goto x86_l_29a7;
	case 10665ULL: goto x86_l_29a9;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	case 10678ULL: goto x86_l_29b6;
	case 10682ULL: goto x86_l_29ba;
	case 10687ULL: goto x86_l_29bf;
	case 10689ULL: goto x86_l_29c1;
	case 10691ULL: goto x86_l_29c3;
	case 10697ULL: goto x86_l_29c9;
	case 10707ULL: goto x86_l_29d3;
	case 10713ULL: goto x86_l_29d9;
	case 10721ULL: goto x86_l_29e1;
	case 10725ULL: goto x86_l_29e5;
	case 10729ULL: goto x86_l_29e9;
	case 10739ULL: goto x86_l_29f3;
	case 10741ULL: goto x86_l_29f5;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10758ULL: goto x86_l_2a06;
	case 10763ULL: goto x86_l_2a0b;
	case 10765ULL: goto x86_l_2a0d;
	case 10767ULL: goto x86_l_2a0f;
	case 10773ULL: goto x86_l_2a15;
	case 10783ULL: goto x86_l_2a1f;
	case 10789ULL: goto x86_l_2a25;
	case 10797ULL: goto x86_l_2a2d;
	case 10801ULL: goto x86_l_2a31;
	case 10805ULL: goto x86_l_2a35;
	case 10815ULL: goto x86_l_2a3f;
	case 10817ULL: goto x86_l_2a41;
	case 10820ULL: goto x86_l_2a44;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10834ULL: goto x86_l_2a52;
	case 10839ULL: goto x86_l_2a57;
	case 10841ULL: goto x86_l_2a59;
	case 10843ULL: goto x86_l_2a5b;
	case 10849ULL: goto x86_l_2a61;
	case 10859ULL: goto x86_l_2a6b;
	case 10865ULL: goto x86_l_2a71;
	case 10873ULL: goto x86_l_2a79;
	case 10877ULL: goto x86_l_2a7d;
	case 10881ULL: goto x86_l_2a81;
	case 10891ULL: goto x86_l_2a8b;
	case 10893ULL: goto x86_l_2a8d;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10910ULL: goto x86_l_2a9e;
	case 10915ULL: goto x86_l_2aa3;
	case 10917ULL: goto x86_l_2aa5;
	case 10919ULL: goto x86_l_2aa7;
	case 10925ULL: goto x86_l_2aad;
	case 10935ULL: goto x86_l_2ab7;
	case 10941ULL: goto x86_l_2abd;
	case 10949ULL: goto x86_l_2ac5;
	case 10953ULL: goto x86_l_2ac9;
	case 10957ULL: goto x86_l_2acd;
	case 10967ULL: goto x86_l_2ad7;
	case 10969ULL: goto x86_l_2ad9;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10982ULL: goto x86_l_2ae6;
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10993ULL: goto x86_l_2af1;
	case 10995ULL: goto x86_l_2af3;
	case 11001ULL: goto x86_l_2af9;
	case 11011ULL: goto x86_l_2b03;
	case 11017ULL: goto x86_l_2b09;
	case 11020ULL: goto x86_l_2b0c;
	case 11028ULL: goto x86_l_2b14;
	case 11032ULL: goto x86_l_2b18;
	case 11036ULL: goto x86_l_2b1c;
	case 11046ULL: goto x86_l_2b26;
	case 11048ULL: goto x86_l_2b28;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11061ULL: goto x86_l_2b35;
	case 11065ULL: goto x86_l_2b39;
	case 11070ULL: goto x86_l_2b3e;
	case 11072ULL: goto x86_l_2b40;
	case 11074ULL: goto x86_l_2b42;
	case 11080ULL: goto x86_l_2b48;
	case 11085ULL: goto x86_l_2b4d;
	case 11095ULL: goto x86_l_2b57;
	case 11098ULL: goto x86_l_2b5a;
	case 11104ULL: goto x86_l_2b60;
	case 11112ULL: goto x86_l_2b68;
	case 11116ULL: goto x86_l_2b6c;
	case 11120ULL: goto x86_l_2b70;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11149ULL: goto x86_l_2b8d;
	case 11154ULL: goto x86_l_2b92;
	case 11156ULL: goto x86_l_2b94;
	case 11158ULL: goto x86_l_2b96;
	case 11164ULL: goto x86_l_2b9c;
	case 11169ULL: goto x86_l_2ba1;
	case 11179ULL: goto x86_l_2bab;
	case 11182ULL: goto x86_l_2bae;
	case 11188ULL: goto x86_l_2bb4;
	case 11196ULL: goto x86_l_2bbc;
	case 11200ULL: goto x86_l_2bc0;
	case 11204ULL: goto x86_l_2bc4;
	case 11214ULL: goto x86_l_2bce;
	case 11220ULL: goto x86_l_2bd4;
	case 11223ULL: goto x86_l_2bd7;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11237ULL: goto x86_l_2be5;
	case 11242ULL: goto x86_l_2bea;
	case 11244ULL: goto x86_l_2bec;
	case 11246ULL: goto x86_l_2bee;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11282ULL: goto x86_l_2c12;
	case 11287ULL: goto x86_l_2c17;
	case 11289ULL: goto x86_l_2c19;
	case 11294ULL: goto x86_l_2c1e;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11316ULL: goto x86_l_2c34;
	case 11321ULL: goto x86_l_2c39;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11366ULL: goto x86_l_2c66;
	case 11371ULL: goto x86_l_2c6b;
	case 11376ULL: goto x86_l_2c70;
	case 11381ULL: goto x86_l_2c75;
	case 11384ULL: goto x86_l_2c78;
	case 11386ULL: goto x86_l_2c7a;
	case 11389ULL: goto x86_l_2c7d;
	case 11395ULL: goto x86_l_2c83;
	case 11398ULL: goto x86_l_2c86;
	case 11402ULL: goto x86_l_2c8a;
	case 11407ULL: goto x86_l_2c8f;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11422ULL: goto x86_l_2c9e;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11441ULL: goto x86_l_2cb1;
	case 11444ULL: goto x86_l_2cb4;
	case 11450ULL: goto x86_l_2cba;
	case 11453ULL: goto x86_l_2cbd;
	case 11460ULL: goto x86_l_2cc4;
	case 11462ULL: goto x86_l_2cc6;
	case 11467ULL: goto x86_l_2ccb;
	case 11472ULL: goto x86_l_2cd0;
	case 11475ULL: goto x86_l_2cd3;
	case 11478ULL: goto x86_l_2cd6;
	case 11480ULL: goto x86_l_2cd8;
	case 11482ULL: goto x86_l_2cda;
	case 11487ULL: goto x86_l_2cdf;
	case 11489ULL: goto x86_l_2ce1;
	case 11494ULL: goto x86_l_2ce6;
	case 11497ULL: goto x86_l_2ce9;
	case 11500ULL: goto x86_l_2cec;
	case 11506ULL: goto x86_l_2cf2;
	case 11509ULL: goto x86_l_2cf5;
	case 11513ULL: goto x86_l_2cf9;
	case 11518ULL: goto x86_l_2cfe;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11533ULL: goto x86_l_2d0d;
	case 11540ULL: goto x86_l_2d14;
	case 11545ULL: goto x86_l_2d19;
	case 11550ULL: goto x86_l_2d1e;
	case 11552ULL: goto x86_l_2d20;
	case 11555ULL: goto x86_l_2d23;
	case 11557ULL: goto x86_l_2d25;
	case 11560ULL: goto x86_l_2d28;
	case 11567ULL: goto x86_l_2d2f;
	case 11569ULL: goto x86_l_2d31;
	case 11574ULL: goto x86_l_2d36;
	case 11579ULL: goto x86_l_2d3b;
	case 11582ULL: goto x86_l_2d3e;
	case 11585ULL: goto x86_l_2d41;
	case 11587ULL: goto x86_l_2d43;
	case 11589ULL: goto x86_l_2d45;
	case 11594ULL: goto x86_l_2d4a;
	case 11597ULL: goto x86_l_2d4d;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11607ULL: goto x86_l_2d57;
	case 11610ULL: goto x86_l_2d5a;
	case 11612ULL: goto x86_l_2d5c;
	case 11615ULL: goto x86_l_2d5f;
	case 11617ULL: goto x86_l_2d61;
	case 11620ULL: goto x86_l_2d64;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11632ULL: goto x86_l_2d70;
	case 11634ULL: goto x86_l_2d72;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11644ULL: goto x86_l_2d7c;
	case 11647ULL: goto x86_l_2d7f;
	case 11649ULL: goto x86_l_2d81;
	case 11654ULL: goto x86_l_2d86;
	case 11657ULL: goto x86_l_2d89;
	case 11659ULL: goto x86_l_2d8b;
	case 11662ULL: goto x86_l_2d8e;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11678ULL: goto x86_l_2d9e;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11690ULL: goto x86_l_2daa;
	case 11696ULL: goto x86_l_2db0;
	case 11699ULL: goto x86_l_2db3;
	case 11705ULL: goto x86_l_2db9;
	case 11708ULL: goto x86_l_2dbc;
	case 11714ULL: goto x86_l_2dc2;
	case 11717ULL: goto x86_l_2dc5;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11742ULL: goto x86_l_2dde;
	case 11751ULL: goto x86_l_2de7;
	case 11757ULL: goto x86_l_2ded;
	case 11759ULL: goto x86_l_2def;
	case 11762ULL: goto x86_l_2df2;
	case 11764ULL: goto x86_l_2df4;
	case 11767ULL: goto x86_l_2df7;
	case 11769ULL: goto x86_l_2df9;
	case 11772ULL: goto x86_l_2dfc;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11786ULL: goto x86_l_2e0a;
	case 11792ULL: goto x86_l_2e10;
	case 11797ULL: goto x86_l_2e15;
	case 11800ULL: goto x86_l_2e18;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11820ULL: goto x86_l_2e2c;
	case 11825ULL: goto x86_l_2e31;
	case 11828ULL: goto x86_l_2e34;
	case 11830ULL: goto x86_l_2e36;
	case 11833ULL: goto x86_l_2e39;
	case 11839ULL: goto x86_l_2e3f;
	case 11841ULL: goto x86_l_2e41;
	case 11847ULL: goto x86_l_2e47;
	case 11850ULL: goto x86_l_2e4a;
	case 11853ULL: goto x86_l_2e4d;
	case 11859ULL: goto x86_l_2e53;
	case 11864ULL: goto x86_l_2e58;
	case 11866ULL: goto x86_l_2e5a;
	case 11868ULL: goto x86_l_2e5c;
	case 11871ULL: goto x86_l_2e5f;
	case 11873ULL: goto x86_l_2e61;
	case 11878ULL: goto x86_l_2e66;
	case 11880ULL: goto x86_l_2e68;
	case 11883ULL: goto x86_l_2e6b;
	case 11889ULL: goto x86_l_2e71;
	case 11897ULL: goto x86_l_2e79;
	case 11900ULL: goto x86_l_2e7c;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11914ULL: goto x86_l_2e8a;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11928ULL: goto x86_l_2e98;
	case 11934ULL: goto x86_l_2e9e;
	case 11942ULL: goto x86_l_2ea6;
	case 11945ULL: goto x86_l_2ea9;
	case 11951ULL: goto x86_l_2eaf;
	case 11956ULL: goto x86_l_2eb4;
	case 11959ULL: goto x86_l_2eb7;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11977ULL: goto x86_l_2ec9;
	case 11982ULL: goto x86_l_2ece;
	case 11984ULL: goto x86_l_2ed0;
	case 11989ULL: goto x86_l_2ed5;
	case 11992ULL: goto x86_l_2ed8;
	case 11996ULL: goto x86_l_2edc;
	case 11998ULL: goto x86_l_2ede;
	case 12001ULL: goto x86_l_2ee1;
	case 12011ULL: goto x86_l_2eeb;
	case 12017ULL: goto x86_l_2ef1;
	case 12024ULL: goto x86_l_2ef8;
	case 12027ULL: goto x86_l_2efb;
	case 12035ULL: goto x86_l_2f03;
	case 12038ULL: goto x86_l_2f06;
	case 12042ULL: goto x86_l_2f0a;
	case 12051ULL: goto x86_l_2f13;
	case 12053ULL: goto x86_l_2f15;
	case 12059ULL: goto x86_l_2f1b;
	case 12062ULL: goto x86_l_2f1e;
	case 12064ULL: goto x86_l_2f20;
	case 12067ULL: goto x86_l_2f23;
	case 12072ULL: goto x86_l_2f28;
	case 12077ULL: goto x86_l_2f2d;
	case 12081ULL: goto x86_l_2f31;
	case 12086ULL: goto x86_l_2f36;
	case 12088ULL: goto x86_l_2f38;
	case 12090ULL: goto x86_l_2f3a;
	case 12096ULL: goto x86_l_2f40;
	case 12106ULL: goto x86_l_2f4a;
	case 12112ULL: goto x86_l_2f50;
	case 12120ULL: goto x86_l_2f58;
	case 12124ULL: goto x86_l_2f5c;
	case 12128ULL: goto x86_l_2f60;
	case 12138ULL: goto x86_l_2f6a;
	case 12140ULL: goto x86_l_2f6c;
	case 12143ULL: goto x86_l_2f6f;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	default: return 0xffffffffffffffffULL;
	}
x86_l_28a5:
	/* 0x28a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28a8:
	/* 0x28a8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28ad:
	/* 0x28ad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28b2:
	/* 0x28b2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b6:
	/* 0x28b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28bb:
	/* 0x28bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28bd:
	/* 0x28bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28bf:
	/* 0x28bf: js     5cdb <generic_sleepable_preload+0x5cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23771ULL;
	}
x86_l_28c5:
	/* 0x28c5: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ca:
	/* 0x28ca: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_28d4:
	/* 0x28d4: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_28da:
	/* 0x28da: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_28e2:
	/* 0x28e2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28e6:
	/* 0x28e6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28ea:
	/* 0x28ea: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_28f4:
	/* 0x28f4: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_28fa:
	/* 0x28fa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28fd:
	/* 0x28fd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2902:
	/* 0x2902: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2907:
	/* 0x2907: jmp    2be1 <generic_sleepable_preload+0x2be1> */
	goto x86_l_2be1;
x86_l_290c:
	/* 0x290c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_290f:
	/* 0x290f: je     2931 <generic_sleepable_preload+0x2931> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2931;
	}
x86_l_2911:
	/* 0x2911: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2914:
	/* 0x2914: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2919:
	/* 0x2919: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_291e:
	/* 0x291e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2922:
	/* 0x2922: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2927:
	/* 0x2927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2929:
	/* 0x2929: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_292b:
	/* 0x292b: js     2bfe <generic_sleepable_preload+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2bfe;
	}
x86_l_2931:
	/* 0x2931: cmp    WORD PTR [r12+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_293b:
	/* 0x293b: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2941:
	/* 0x2941: mov    ecx,DWORD PTR [r12+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2949:
	/* 0x2949: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_294d:
	/* 0x294d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2951:
	/* 0x2951: cmp    WORD PTR [r12+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_295b:
	/* 0x295b: je     297d <generic_sleepable_preload+0x297d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_297d;
	}
x86_l_295d:
	/* 0x295d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2960:
	/* 0x2960: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2965:
	/* 0x2965: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_296a:
	/* 0x296a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_296e:
	/* 0x296e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2973:
	/* 0x2973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2975:
	/* 0x2975: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2977:
	/* 0x2977: js     2c08 <generic_sleepable_preload+0x2c08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c08;
	}
x86_l_297d:
	/* 0x297d: cmp    WORD PTR [r12+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2987:
	/* 0x2987: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_298d:
	/* 0x298d: mov    ecx,DWORD PTR [r12+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2995:
	/* 0x2995: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2999:
	/* 0x2999: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_299d:
	/* 0x299d: cmp    WORD PTR [r12+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_29a7:
	/* 0x29a7: je     29c9 <generic_sleepable_preload+0x29c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29c9;
	}
x86_l_29a9:
	/* 0x29a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29ac:
	/* 0x29ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29b1:
	/* 0x29b1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29b6:
	/* 0x29b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ba:
	/* 0x29ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29bf:
	/* 0x29bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c1:
	/* 0x29c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29c3:
	/* 0x29c3: js     2c19 <generic_sleepable_preload+0x2c19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c19;
	}
x86_l_29c9:
	/* 0x29c9: cmp    WORD PTR [r12+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_29d3:
	/* 0x29d3: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_29d9:
	/* 0x29d9: mov    ecx,DWORD PTR [r12+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_29e1:
	/* 0x29e1: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29e5:
	/* 0x29e5: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29e9:
	/* 0x29e9: cmp    WORD PTR [r12+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_29f3:
	/* 0x29f3: je     2a15 <generic_sleepable_preload+0x2a15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a15;
	}
x86_l_29f5:
	/* 0x29f5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29f8:
	/* 0x29f8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29fd:
	/* 0x29fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a02:
	/* 0x2a02: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a06:
	/* 0x2a06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a0b:
	/* 0x2a0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0d:
	/* 0x2a0d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a0f:
	/* 0x2a0f: js     2c2a <generic_sleepable_preload+0x2c2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c2a;
	}
x86_l_2a15:
	/* 0x2a15: cmp    WORD PTR [r12+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2a1f:
	/* 0x2a1f: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2a25:
	/* 0x2a25: mov    ecx,DWORD PTR [r12+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2a2d:
	/* 0x2a2d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a31:
	/* 0x2a31: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a35:
	/* 0x2a35: cmp    WORD PTR [r12+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2a3f:
	/* 0x2a3f: je     2a61 <generic_sleepable_preload+0x2a61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a61;
	}
x86_l_2a41:
	/* 0x2a41: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a44:
	/* 0x2a44: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a49:
	/* 0x2a49: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a52:
	/* 0x2a52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a57:
	/* 0x2a57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a59:
	/* 0x2a59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a5b:
	/* 0x2a5b: js     2c3b <generic_sleepable_preload+0x2c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c3b;
	}
x86_l_2a61:
	/* 0x2a61: cmp    WORD PTR [r12+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2a6b:
	/* 0x2a6b: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2a71:
	/* 0x2a71: mov    ecx,DWORD PTR [r12+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2a79:
	/* 0x2a79: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a7d:
	/* 0x2a7d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a81:
	/* 0x2a81: cmp    WORD PTR [r12+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2a8b:
	/* 0x2a8b: je     2aad <generic_sleepable_preload+0x2aad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aad;
	}
x86_l_2a8d:
	/* 0x2a8d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a90:
	/* 0x2a90: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a95:
	/* 0x2a95: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a9a:
	/* 0x2a9a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9e:
	/* 0x2a9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aa3:
	/* 0x2aa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa5:
	/* 0x2aa5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2aa7:
	/* 0x2aa7: js     2c4c <generic_sleepable_preload+0x2c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c4c;
	}
x86_l_2aad:
	/* 0x2aad: cmp    WORD PTR [r12+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2ab7:
	/* 0x2ab7: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2abd:
	/* 0x2abd: mov    ecx,DWORD PTR [r12+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2ac5:
	/* 0x2ac5: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ac9:
	/* 0x2ac9: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2acd:
	/* 0x2acd: cmp    WORD PTR [r12+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2ad7:
	/* 0x2ad7: je     2af9 <generic_sleepable_preload+0x2af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2af9;
	}
x86_l_2ad9:
	/* 0x2ad9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2adc:
	/* 0x2adc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ae1:
	/* 0x2ae1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ae6:
	/* 0x2ae6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aea:
	/* 0x2aea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aef:
	/* 0x2aef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af1:
	/* 0x2af1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2af3:
	/* 0x2af3: js     2ce1 <generic_sleepable_preload+0x2ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ce1;
	}
x86_l_2af9:
	/* 0x2af9: cmp    WORD PTR [r12+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2b03:
	/* 0x2b03: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2b09:
	/* 0x2b09: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_2b0c:
	/* 0x2b0c: mov    ecx,DWORD PTR [r12+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2b14:
	/* 0x2b14: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b18:
	/* 0x2b18: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b1c:
	/* 0x2b1c: cmp    WORD PTR [r12+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2b26:
	/* 0x2b26: je     2b48 <generic_sleepable_preload+0x2b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b48;
	}
x86_l_2b28:
	/* 0x2b28: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b2b:
	/* 0x2b2b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b30:
	/* 0x2b30: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b35:
	/* 0x2b35: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b39:
	/* 0x2b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b3e:
	/* 0x2b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b40:
	/* 0x2b40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b42:
	/* 0x2b42: js     5c64 <generic_sleepable_preload+0x5c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23652ULL;
	}
x86_l_2b48:
	/* 0x2b48: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b4d:
	/* 0x2b4d: cmp    WORD PTR [r12+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2b57:
	/* 0x2b57: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2b5a:
	/* 0x2b5a: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2b60:
	/* 0x2b60: mov    ecx,DWORD PTR [r12+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2b68:
	/* 0x2b68: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b6c:
	/* 0x2b6c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b70:
	/* 0x2b70: cmp    WORD PTR [r12+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2b7a:
	/* 0x2b7a: je     2b9c <generic_sleepable_preload+0x2b9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9c;
	}
x86_l_2b7c:
	/* 0x2b7c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b7f:
	/* 0x2b7f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b84:
	/* 0x2b84: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b89:
	/* 0x2b89: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b8d:
	/* 0x2b8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b92:
	/* 0x2b92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b94:
	/* 0x2b94: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b96:
	/* 0x2b96: js     5d74 <generic_sleepable_preload+0x5d74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23924ULL;
	}
x86_l_2b9c:
	/* 0x2b9c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ba1:
	/* 0x2ba1: cmp    WORD PTR [r12+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2bab:
	/* 0x2bab: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_2bae:
	/* 0x2bae: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2bb4:
	/* 0x2bb4: mov    ecx,DWORD PTR [r12+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2bbc:
	/* 0x2bbc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bc0:
	/* 0x2bc0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc4:
	/* 0x2bc4: cmp    WORD PTR [r12+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2bce:
	/* 0x2bce: je     2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2bd4:
	/* 0x2bd4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bd7:
	/* 0x2bd7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bdc:
	/* 0x2bdc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2be1:
	/* 0x2be1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be5:
	/* 0x2be5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bea:
	/* 0x2bea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bec:
	/* 0x2bec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bee:
	/* 0x2bee: jns    2ce9 <generic_sleepable_preload+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2ce9;
	}
x86_l_2bf4:
	/* 0x2bf4: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2bf9:
	/* 0x2bf9: jmp    2ce6 <generic_sleepable_preload+0x2ce6> */
	goto x86_l_2ce6;
x86_l_2bfe:
	/* 0x2bfe: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2c03:
	/* 0x2c03: jmp    2ce6 <generic_sleepable_preload+0x2ce6> */
	goto x86_l_2ce6;
x86_l_2c08:
	/* 0x2c08: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2c0d:
	/* 0x2c0d: jmp    2ce6 <generic_sleepable_preload+0x2ce6> */
	goto x86_l_2ce6;
x86_l_2c12:
	/* 0x2c12: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2c17:
	/* 0x2c17: jmp    2c5b <generic_sleepable_preload+0x2c5b> */
	goto x86_l_2c5b;
x86_l_2c19:
	/* 0x2c19: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2c1e:
	/* 0x2c1e: jmp    2ce6 <generic_sleepable_preload+0x2ce6> */
	goto x86_l_2ce6;
x86_l_2c23:
	/* 0x2c23: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c28:
	/* 0x2c28: jmp    2c5b <generic_sleepable_preload+0x2c5b> */
	goto x86_l_2c5b;
x86_l_2c2a:
	/* 0x2c2a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c2f:
	/* 0x2c2f: jmp    2ce6 <generic_sleepable_preload+0x2ce6> */
	goto x86_l_2ce6;
x86_l_2c34:
	/* 0x2c34: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c39:
	/* 0x2c39: jmp    2c5b <generic_sleepable_preload+0x2c5b> */
	goto x86_l_2c5b;
x86_l_2c3b:
	/* 0x2c3b: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c40:
	/* 0x2c40: jmp    2ce6 <generic_sleepable_preload+0x2ce6> */
	goto x86_l_2ce6;
x86_l_2c45:
	/* 0x2c45: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2c4a:
	/* 0x2c4a: jmp    2c5b <generic_sleepable_preload+0x2c5b> */
	goto x86_l_2c5b;
x86_l_2c4c:
	/* 0x2c4c: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2c51:
	/* 0x2c51: jmp    2ce6 <generic_sleepable_preload+0x2ce6> */
	goto x86_l_2ce6;
x86_l_2c56:
	/* 0x2c56: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2c5b:
	/* 0x2c5b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c5e:
	/* 0x2c5e: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c63:
	/* 0x2c63: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c66:
	/* 0x2c66: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c6b:
	/* 0x2c6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c70:
	/* 0x2c70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c75:
	/* 0x2c75: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2c78:
	/* 0x2c78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7a:
	/* 0x2c7a: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2c7d:
	/* 0x2c7d: jne    2d8e <generic_sleepable_preload+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d8e;
	}
x86_l_2c83:
	/* 0x2c83: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2c86:
	/* 0x2c86: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c8f:
	/* 0x2c8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c91:
	/* 0x2c91: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c96:
	/* 0x2c96: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2c9e:
	/* 0x2c9e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ca5:
	/* 0x2ca5: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2caa:
	/* 0x2caa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2caf:
	/* 0x2caf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb1:
	/* 0x2cb1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cb4:
	/* 0x2cb4: je     2d8b <generic_sleepable_preload+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8b;
	}
x86_l_2cba:
	/* 0x2cba: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2cbd:
	/* 0x2cbd: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2cc4:
	/* 0x2cc4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cc6:
	/* 0x2cc6: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ccb:
	/* 0x2ccb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cd0:
	/* 0x2cd0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2cd3:
	/* 0x2cd3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2cd6:
	/* 0x2cd6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cd8:
	/* 0x2cd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cda:
	/* 0x2cda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cdf:
	/* 0x2cdf: jmp    2d4a <generic_sleepable_preload+0x2d4a> */
	goto x86_l_2d4a;
x86_l_2ce1:
	/* 0x2ce1: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2ce6:
	/* 0x2ce6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ce9:
	/* 0x2ce9: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2cec:
	/* 0x2cec: jne    2d8e <generic_sleepable_preload+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d8e;
	}
x86_l_2cf2:
	/* 0x2cf2: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2cf5:
	/* 0x2cf5: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf9:
	/* 0x2cf9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2cfe:
	/* 0x2cfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d00:
	/* 0x2d00: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d05:
	/* 0x2d05: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2d0d:
	/* 0x2d0d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d14:
	/* 0x2d14: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d19:
	/* 0x2d19: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d1e:
	/* 0x2d1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d20:
	/* 0x2d20: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d23:
	/* 0x2d23: je     2d8b <generic_sleepable_preload+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8b;
	}
x86_l_2d25:
	/* 0x2d25: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d28:
	/* 0x2d28: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2d2f:
	/* 0x2d2f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d31:
	/* 0x2d31: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d36:
	/* 0x2d36: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d3b:
	/* 0x2d3b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d3e:
	/* 0x2d3e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d41:
	/* 0x2d41: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d43:
	/* 0x2d43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d45:
	/* 0x2d45: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d4a:
	/* 0x2d4a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2d4d:
	/* 0x2d4d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d50:
	/* 0x2d50: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d55:
	/* 0x2d55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d57:
	/* 0x2d57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d5a:
	/* 0x2d5a: je     2d8b <generic_sleepable_preload+0x2d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8b;
	}
x86_l_2d5c:
	/* 0x2d5c: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_2d5f:
	/* 0x2d5f: je     2d89 <generic_sleepable_preload+0x2d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d89;
	}
x86_l_2d61:
	/* 0x2d61: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d64:
	/* 0x2d64: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d68:
	/* 0x2d68: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d6d:
	/* 0x2d6d: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2d70:
	/* 0x2d70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d72:
	/* 0x2d72: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2d75:
	/* 0x2d75: call   2d7a <generic_sleepable_preload+0x2d7a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2d7a:
	/* 0x2d7a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2d7c:
	/* 0x2d7c: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_2d7f:
	/* 0x2d7f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2d81:
	/* 0x2d81: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d86:
	/* 0x2d86: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2d89:
	/* 0x2d89: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d8b:
	/* 0x2d8b: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_2d8e:
	/* 0x2d8e: mov    eax,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d93:
	/* 0x2d93: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_2d98:
	/* 0x2d98: je     3cf9 <generic_sleepable_preload+0x3cf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15609ULL;
	}
x86_l_2d9e:
	/* 0x2d9e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2da0:
	/* 0x2da0: js     2dd5 <generic_sleepable_preload+0x2dd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2dd5;
	}
x86_l_2da2:
	/* 0x2da2: mov    eax,DWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2da7:
	/* 0x2da7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2daa:
	/* 0x2daa: jle    2e58 <generic_sleepable_preload+0x2e58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e58;
	}
x86_l_2db0:
	/* 0x2db0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2db3:
	/* 0x2db3: je     2ec2 <generic_sleepable_preload+0x2ec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ec2;
	}
x86_l_2db9:
	/* 0x2db9: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2dbc:
	/* 0x2dbc: je     2ec9 <generic_sleepable_preload+0x2ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ec9;
	}
x86_l_2dc2:
	/* 0x2dc2: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dc5:
	/* 0x2dc5: jne    2edc <generic_sleepable_preload+0x2edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2edc;
	}
x86_l_2dcb:
	/* 0x2dcb: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dd0:
	/* 0x2dd0: jmp    2ed5 <generic_sleepable_preload+0x2ed5> */
	goto x86_l_2ed5;
x86_l_2dd5:
	/* 0x2dd5: movzx  eax,BYTE PTR [r12+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_2dde:
	/* 0x2dde: movzx  ecx,WORD PTR [r12+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_2de7:
	/* 0x2de7: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2ded:
	/* 0x2ded: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2def:
	/* 0x2def: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2df2:
	/* 0x2df2: jle    2e31 <generic_sleepable_preload+0x2e31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e31;
	}
x86_l_2df4:
	/* 0x2df4: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2df7:
	/* 0x2df7: jle    2e68 <generic_sleepable_preload+0x2e68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e68;
	}
x86_l_2df9:
	/* 0x2df9: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2dfc:
	/* 0x2dfc: jle    352b <generic_sleepable_preload+0x352b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13611ULL;
	}
x86_l_2e02:
	/* 0x2e02: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e07:
	/* 0x2e07: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2e0a:
	/* 0x2e0a: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13648ULL;
	}
x86_l_2e10:
	/* 0x2e10: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e15:
	/* 0x2e15: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2e18:
	/* 0x2e18: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13648ULL;
	}
x86_l_2e1e:
	/* 0x2e1e: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e23:
	/* 0x2e23: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2e26:
	/* 0x2e26: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13648ULL;
	}
x86_l_2e2c:
	/* 0x2e2c: jmp    3563 <generic_sleepable_preload+0x3563> */
	return 13667ULL;
x86_l_2e31:
	/* 0x2e31: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2e34:
	/* 0x2e34: jg     2e95 <generic_sleepable_preload+0x2e95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e95;
	}
x86_l_2e36:
	/* 0x2e36: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e39:
	/* 0x2e39: jg     34fc <generic_sleepable_preload+0x34fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13564ULL;
	}
x86_l_2e3f:
	/* 0x2e3f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2e41:
	/* 0x2e41: je     354b <generic_sleepable_preload+0x354b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13643ULL;
	}
x86_l_2e47:
	/* 0x2e47: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2e4a:
	/* 0x2e4a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e4d:
	/* 0x2e4d: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13648ULL;
	}
x86_l_2e53:
	/* 0x2e53: jmp    3563 <generic_sleepable_preload+0x3563> */
	return 13667ULL;
x86_l_2e58:
	/* 0x2e58: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e5a:
	/* 0x2e5a: je     2ed0 <generic_sleepable_preload+0x2ed0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed0;
	}
x86_l_2e5c:
	/* 0x2e5c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e5f:
	/* 0x2e5f: jne    2edc <generic_sleepable_preload+0x2edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2edc;
	}
x86_l_2e61:
	/* 0x2e61: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e66:
	/* 0x2e66: jmp    2ed5 <generic_sleepable_preload+0x2ed5> */
	goto x86_l_2ed5;
x86_l_2e68:
	/* 0x2e68: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e6b:
	/* 0x2e6b: jg     34e3 <generic_sleepable_preload+0x34e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13539ULL;
	}
x86_l_2e71:
	/* 0x2e71: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e79:
	/* 0x2e79: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e7c:
	/* 0x2e7c: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13648ULL;
	}
x86_l_2e82:
	/* 0x2e82: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e87:
	/* 0x2e87: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e8a:
	/* 0x2e8a: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13648ULL;
	}
x86_l_2e90:
	/* 0x2e90: jmp    3563 <generic_sleepable_preload+0x3563> */
	return 13667ULL;
x86_l_2e95:
	/* 0x2e95: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2e98:
	/* 0x2e98: jg     3512 <generic_sleepable_preload+0x3512> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13586ULL;
	}
x86_l_2e9e:
	/* 0x2e9e: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ea6:
	/* 0x2ea6: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2ea9:
	/* 0x2ea9: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13648ULL;
	}
x86_l_2eaf:
	/* 0x2eaf: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2eb4:
	/* 0x2eb4: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2eb7:
	/* 0x2eb7: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13648ULL;
	}
x86_l_2ebd:
	/* 0x2ebd: jmp    3563 <generic_sleepable_preload+0x3563> */
	return 13667ULL;
x86_l_2ec2:
	/* 0x2ec2: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ec7:
	/* 0x2ec7: jmp    2ed5 <generic_sleepable_preload+0x2ed5> */
	goto x86_l_2ed5;
x86_l_2ec9:
	/* 0x2ec9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ece:
	/* 0x2ece: jmp    2ed5 <generic_sleepable_preload+0x2ed5> */
	goto x86_l_2ed5;
x86_l_2ed0:
	/* 0x2ed0: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ed5:
	/* 0x2ed5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed8:
	/* 0x2ed8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2edc:
	/* 0x2edc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ede:
	/* 0x2ede: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_2ee1:
	/* 0x2ee1: cmp    WORD PTR [r12+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2eeb:
	/* 0x2eeb: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_2ef1:
	/* 0x2ef1: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2ef8:
	/* 0x2ef8: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2efb:
	/* 0x2efb: mov    eax,DWORD PTR [r12+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2f03:
	/* 0x2f03: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f06:
	/* 0x2f06: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f0a:
	/* 0x2f0a: movzx  eax,WORD PTR [r12+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2f13:
	/* 0x2f13: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2f15:
	/* 0x2f15: je     31e7 <generic_sleepable_preload+0x31e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12775ULL;
	}
x86_l_2f1b:
	/* 0x2f1b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2f1e:
	/* 0x2f1e: je     2f40 <generic_sleepable_preload+0x2f40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f40;
	}
x86_l_2f20:
	/* 0x2f20: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f23:
	/* 0x2f23: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f28:
	/* 0x2f28: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f2d:
	/* 0x2f2d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f31:
	/* 0x2f31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f36:
	/* 0x2f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f38:
	/* 0x2f38: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f3a:
	/* 0x2f3a: js     34d9 <generic_sleepable_preload+0x34d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13529ULL;
	}
x86_l_2f40:
	/* 0x2f40: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2f4a:
	/* 0x2f4a: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_2f50:
	/* 0x2f50: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2f58:
	/* 0x2f58: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f5c:
	/* 0x2f5c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f60:
	/* 0x2f60: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2f6a:
	/* 0x2f6a: je     2f8c <generic_sleepable_preload+0x2f8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12172ULL;
	}
x86_l_2f6c:
	/* 0x2f6c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f6f:
	/* 0x2f6f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f74:
	/* 0x2f74: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f79:
	/* 0x2f79: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 12157ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12157ULL: goto x86_l_2f7d;
	case 12162ULL: goto x86_l_2f82;
	case 12164ULL: goto x86_l_2f84;
	case 12166ULL: goto x86_l_2f86;
	case 12172ULL: goto x86_l_2f8c;
	case 12182ULL: goto x86_l_2f96;
	case 12188ULL: goto x86_l_2f9c;
	case 12196ULL: goto x86_l_2fa4;
	case 12200ULL: goto x86_l_2fa8;
	case 12204ULL: goto x86_l_2fac;
	case 12214ULL: goto x86_l_2fb6;
	case 12216ULL: goto x86_l_2fb8;
	case 12219ULL: goto x86_l_2fbb;
	case 12224ULL: goto x86_l_2fc0;
	case 12229ULL: goto x86_l_2fc5;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12240ULL: goto x86_l_2fd0;
	case 12242ULL: goto x86_l_2fd2;
	case 12248ULL: goto x86_l_2fd8;
	case 12258ULL: goto x86_l_2fe2;
	case 12264ULL: goto x86_l_2fe8;
	case 12272ULL: goto x86_l_2ff0;
	case 12276ULL: goto x86_l_2ff4;
	case 12280ULL: goto x86_l_2ff8;
	case 12290ULL: goto x86_l_3002;
	case 12292ULL: goto x86_l_3004;
	case 12295ULL: goto x86_l_3007;
	case 12300ULL: goto x86_l_300c;
	case 12305ULL: goto x86_l_3011;
	case 12309ULL: goto x86_l_3015;
	case 12314ULL: goto x86_l_301a;
	case 12316ULL: goto x86_l_301c;
	case 12318ULL: goto x86_l_301e;
	case 12324ULL: goto x86_l_3024;
	case 12334ULL: goto x86_l_302e;
	case 12340ULL: goto x86_l_3034;
	case 12348ULL: goto x86_l_303c;
	case 12352ULL: goto x86_l_3040;
	case 12356ULL: goto x86_l_3044;
	case 12366ULL: goto x86_l_304e;
	case 12368ULL: goto x86_l_3050;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12381ULL: goto x86_l_305d;
	case 12385ULL: goto x86_l_3061;
	case 12390ULL: goto x86_l_3066;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12400ULL: goto x86_l_3070;
	case 12410ULL: goto x86_l_307a;
	case 12416ULL: goto x86_l_3080;
	case 12424ULL: goto x86_l_3088;
	case 12428ULL: goto x86_l_308c;
	case 12432ULL: goto x86_l_3090;
	case 12442ULL: goto x86_l_309a;
	case 12444ULL: goto x86_l_309c;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12461ULL: goto x86_l_30ad;
	case 12466ULL: goto x86_l_30b2;
	case 12468ULL: goto x86_l_30b4;
	case 12470ULL: goto x86_l_30b6;
	case 12476ULL: goto x86_l_30bc;
	case 12486ULL: goto x86_l_30c6;
	case 12492ULL: goto x86_l_30cc;
	case 12500ULL: goto x86_l_30d4;
	case 12504ULL: goto x86_l_30d8;
	case 12508ULL: goto x86_l_30dc;
	case 12518ULL: goto x86_l_30e6;
	case 12520ULL: goto x86_l_30e8;
	case 12523ULL: goto x86_l_30eb;
	case 12528ULL: goto x86_l_30f0;
	case 12533ULL: goto x86_l_30f5;
	case 12537ULL: goto x86_l_30f9;
	case 12542ULL: goto x86_l_30fe;
	case 12544ULL: goto x86_l_3100;
	case 12546ULL: goto x86_l_3102;
	case 12552ULL: goto x86_l_3108;
	case 12562ULL: goto x86_l_3112;
	case 12568ULL: goto x86_l_3118;
	case 12576ULL: goto x86_l_3120;
	case 12580ULL: goto x86_l_3124;
	case 12584ULL: goto x86_l_3128;
	case 12594ULL: goto x86_l_3132;
	case 12596ULL: goto x86_l_3134;
	case 12599ULL: goto x86_l_3137;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12613ULL: goto x86_l_3145;
	case 12618ULL: goto x86_l_314a;
	case 12620ULL: goto x86_l_314c;
	case 12622ULL: goto x86_l_314e;
	case 12628ULL: goto x86_l_3154;
	case 12638ULL: goto x86_l_315e;
	case 12644ULL: goto x86_l_3164;
	case 12652ULL: goto x86_l_316c;
	case 12656ULL: goto x86_l_3170;
	case 12660ULL: goto x86_l_3174;
	case 12670ULL: goto x86_l_317e;
	case 12672ULL: goto x86_l_3180;
	case 12675ULL: goto x86_l_3183;
	case 12680ULL: goto x86_l_3188;
	case 12685ULL: goto x86_l_318d;
	case 12689ULL: goto x86_l_3191;
	case 12694ULL: goto x86_l_3196;
	case 12696ULL: goto x86_l_3198;
	case 12698ULL: goto x86_l_319a;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12719ULL: goto x86_l_31af;
	case 12725ULL: goto x86_l_31b5;
	case 12733ULL: goto x86_l_31bd;
	case 12737ULL: goto x86_l_31c1;
	case 12741ULL: goto x86_l_31c5;
	case 12751ULL: goto x86_l_31cf;
	case 12757ULL: goto x86_l_31d5;
	case 12760ULL: goto x86_l_31d8;
	case 12765ULL: goto x86_l_31dd;
	case 12770ULL: goto x86_l_31e2;
	case 12775ULL: goto x86_l_31e7;
	case 12778ULL: goto x86_l_31ea;
	case 12780ULL: goto x86_l_31ec;
	case 12783ULL: goto x86_l_31ef;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12797ULL: goto x86_l_31fd;
	case 12802ULL: goto x86_l_3202;
	case 12804ULL: goto x86_l_3204;
	case 12806ULL: goto x86_l_3206;
	case 12812ULL: goto x86_l_320c;
	case 12822ULL: goto x86_l_3216;
	case 12828ULL: goto x86_l_321c;
	case 12836ULL: goto x86_l_3224;
	case 12840ULL: goto x86_l_3228;
	case 12844ULL: goto x86_l_322c;
	case 12854ULL: goto x86_l_3236;
	case 12856ULL: goto x86_l_3238;
	case 12859ULL: goto x86_l_323b;
	case 12864ULL: goto x86_l_3240;
	case 12869ULL: goto x86_l_3245;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12880ULL: goto x86_l_3250;
	case 12882ULL: goto x86_l_3252;
	case 12888ULL: goto x86_l_3258;
	case 12898ULL: goto x86_l_3262;
	case 12904ULL: goto x86_l_3268;
	case 12912ULL: goto x86_l_3270;
	case 12916ULL: goto x86_l_3274;
	case 12920ULL: goto x86_l_3278;
	case 12930ULL: goto x86_l_3282;
	case 12932ULL: goto x86_l_3284;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12945ULL: goto x86_l_3291;
	case 12949ULL: goto x86_l_3295;
	case 12954ULL: goto x86_l_329a;
	case 12956ULL: goto x86_l_329c;
	case 12958ULL: goto x86_l_329e;
	case 12964ULL: goto x86_l_32a4;
	case 12974ULL: goto x86_l_32ae;
	case 12980ULL: goto x86_l_32b4;
	case 12988ULL: goto x86_l_32bc;
	case 12992ULL: goto x86_l_32c0;
	case 12996ULL: goto x86_l_32c4;
	case 13006ULL: goto x86_l_32ce;
	case 13008ULL: goto x86_l_32d0;
	case 13011ULL: goto x86_l_32d3;
	case 13016ULL: goto x86_l_32d8;
	case 13021ULL: goto x86_l_32dd;
	case 13025ULL: goto x86_l_32e1;
	case 13030ULL: goto x86_l_32e6;
	case 13032ULL: goto x86_l_32e8;
	case 13034ULL: goto x86_l_32ea;
	case 13040ULL: goto x86_l_32f0;
	case 13050ULL: goto x86_l_32fa;
	case 13056ULL: goto x86_l_3300;
	case 13064ULL: goto x86_l_3308;
	case 13068ULL: goto x86_l_330c;
	case 13072ULL: goto x86_l_3310;
	case 13082ULL: goto x86_l_331a;
	case 13084ULL: goto x86_l_331c;
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13101ULL: goto x86_l_332d;
	case 13106ULL: goto x86_l_3332;
	case 13108ULL: goto x86_l_3334;
	case 13110ULL: goto x86_l_3336;
	case 13116ULL: goto x86_l_333c;
	case 13126ULL: goto x86_l_3346;
	case 13132ULL: goto x86_l_334c;
	case 13140ULL: goto x86_l_3354;
	case 13144ULL: goto x86_l_3358;
	case 13148ULL: goto x86_l_335c;
	case 13158ULL: goto x86_l_3366;
	case 13160ULL: goto x86_l_3368;
	case 13163ULL: goto x86_l_336b;
	case 13168ULL: goto x86_l_3370;
	case 13173ULL: goto x86_l_3375;
	case 13177ULL: goto x86_l_3379;
	case 13182ULL: goto x86_l_337e;
	case 13184ULL: goto x86_l_3380;
	case 13186ULL: goto x86_l_3382;
	case 13192ULL: goto x86_l_3388;
	case 13202ULL: goto x86_l_3392;
	case 13208ULL: goto x86_l_3398;
	case 13216ULL: goto x86_l_33a0;
	case 13220ULL: goto x86_l_33a4;
	case 13224ULL: goto x86_l_33a8;
	case 13234ULL: goto x86_l_33b2;
	case 13236ULL: goto x86_l_33b4;
	case 13239ULL: goto x86_l_33b7;
	case 13244ULL: goto x86_l_33bc;
	case 13249ULL: goto x86_l_33c1;
	case 13253ULL: goto x86_l_33c5;
	case 13258ULL: goto x86_l_33ca;
	case 13260ULL: goto x86_l_33cc;
	case 13262ULL: goto x86_l_33ce;
	case 13268ULL: goto x86_l_33d4;
	case 13278ULL: goto x86_l_33de;
	case 13284ULL: goto x86_l_33e4;
	case 13287ULL: goto x86_l_33e7;
	case 13295ULL: goto x86_l_33ef;
	case 13299ULL: goto x86_l_33f3;
	case 13303ULL: goto x86_l_33f7;
	case 13313ULL: goto x86_l_3401;
	case 13315ULL: goto x86_l_3403;
	case 13318ULL: goto x86_l_3406;
	case 13323ULL: goto x86_l_340b;
	case 13328ULL: goto x86_l_3410;
	case 13332ULL: goto x86_l_3414;
	case 13337ULL: goto x86_l_3419;
	case 13339ULL: goto x86_l_341b;
	case 13341ULL: goto x86_l_341d;
	case 13347ULL: goto x86_l_3423;
	case 13352ULL: goto x86_l_3428;
	case 13362ULL: goto x86_l_3432;
	case 13365ULL: goto x86_l_3435;
	case 13371ULL: goto x86_l_343b;
	case 13379ULL: goto x86_l_3443;
	case 13383ULL: goto x86_l_3447;
	case 13387ULL: goto x86_l_344b;
	case 13397ULL: goto x86_l_3455;
	case 13399ULL: goto x86_l_3457;
	case 13402ULL: goto x86_l_345a;
	case 13407ULL: goto x86_l_345f;
	case 13412ULL: goto x86_l_3464;
	case 13416ULL: goto x86_l_3468;
	case 13421ULL: goto x86_l_346d;
	case 13423ULL: goto x86_l_346f;
	case 13425ULL: goto x86_l_3471;
	case 13431ULL: goto x86_l_3477;
	case 13436ULL: goto x86_l_347c;
	case 13446ULL: goto x86_l_3486;
	case 13449ULL: goto x86_l_3489;
	case 13455ULL: goto x86_l_348f;
	case 13463ULL: goto x86_l_3497;
	case 13467ULL: goto x86_l_349b;
	case 13471ULL: goto x86_l_349f;
	case 13481ULL: goto x86_l_34a9;
	case 13487ULL: goto x86_l_34af;
	case 13490ULL: goto x86_l_34b2;
	case 13495ULL: goto x86_l_34b7;
	case 13500ULL: goto x86_l_34bc;
	case 13504ULL: goto x86_l_34c0;
	case 13509ULL: goto x86_l_34c5;
	case 13511ULL: goto x86_l_34c7;
	case 13513ULL: goto x86_l_34c9;
	case 13519ULL: goto x86_l_34cf;
	case 13524ULL: goto x86_l_34d4;
	case 13529ULL: goto x86_l_34d9;
	case 13534ULL: goto x86_l_34de;
	case 13539ULL: goto x86_l_34e3;
	case 13547ULL: goto x86_l_34eb;
	case 13550ULL: goto x86_l_34ee;
	case 13552ULL: goto x86_l_34f0;
	case 13557ULL: goto x86_l_34f5;
	case 13560ULL: goto x86_l_34f8;
	case 13562ULL: goto x86_l_34fa;
	case 13564ULL: goto x86_l_34fc;
	case 13569ULL: goto x86_l_3501;
	case 13572ULL: goto x86_l_3504;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13582ULL: goto x86_l_350e;
	case 13584ULL: goto x86_l_3510;
	case 13586ULL: goto x86_l_3512;
	case 13594ULL: goto x86_l_351a;
	case 13597ULL: goto x86_l_351d;
	case 13599ULL: goto x86_l_351f;
	case 13604ULL: goto x86_l_3524;
	case 13607ULL: goto x86_l_3527;
	case 13609ULL: goto x86_l_3529;
	case 13611ULL: goto x86_l_352b;
	case 13616ULL: goto x86_l_3530;
	case 13619ULL: goto x86_l_3533;
	case 13621ULL: goto x86_l_3535;
	case 13626ULL: goto x86_l_353a;
	case 13629ULL: goto x86_l_353d;
	case 13631ULL: goto x86_l_353f;
	case 13633ULL: goto x86_l_3541;
	case 13638ULL: goto x86_l_3546;
	case 13643ULL: goto x86_l_354b;
	case 13648ULL: goto x86_l_3550;
	case 13651ULL: goto x86_l_3553;
	case 13653ULL: goto x86_l_3555;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13671ULL: goto x86_l_3567;
	case 13676ULL: goto x86_l_356c;
	case 13678ULL: goto x86_l_356e;
	case 13681ULL: goto x86_l_3571;
	case 13691ULL: goto x86_l_357b;
	case 13697ULL: goto x86_l_3581;
	case 13704ULL: goto x86_l_3588;
	case 13707ULL: goto x86_l_358b;
	case 13715ULL: goto x86_l_3593;
	case 13718ULL: goto x86_l_3596;
	case 13722ULL: goto x86_l_359a;
	case 13731ULL: goto x86_l_35a3;
	case 13733ULL: goto x86_l_35a5;
	case 13739ULL: goto x86_l_35ab;
	case 13742ULL: goto x86_l_35ae;
	case 13744ULL: goto x86_l_35b0;
	case 13747ULL: goto x86_l_35b3;
	case 13752ULL: goto x86_l_35b8;
	case 13757ULL: goto x86_l_35bd;
	case 13761ULL: goto x86_l_35c1;
	case 13766ULL: goto x86_l_35c6;
	case 13768ULL: goto x86_l_35c8;
	case 13770ULL: goto x86_l_35ca;
	case 13776ULL: goto x86_l_35d0;
	case 13786ULL: goto x86_l_35da;
	case 13792ULL: goto x86_l_35e0;
	case 13800ULL: goto x86_l_35e8;
	case 13804ULL: goto x86_l_35ec;
	case 13808ULL: goto x86_l_35f0;
	case 13818ULL: goto x86_l_35fa;
	case 13820ULL: goto x86_l_35fc;
	case 13823ULL: goto x86_l_35ff;
	case 13828ULL: goto x86_l_3604;
	case 13833ULL: goto x86_l_3609;
	case 13837ULL: goto x86_l_360d;
	case 13842ULL: goto x86_l_3612;
	case 13844ULL: goto x86_l_3614;
	case 13846ULL: goto x86_l_3616;
	case 13852ULL: goto x86_l_361c;
	case 13862ULL: goto x86_l_3626;
	case 13868ULL: goto x86_l_362c;
	case 13876ULL: goto x86_l_3634;
	case 13880ULL: goto x86_l_3638;
	case 13884ULL: goto x86_l_363c;
	case 13894ULL: goto x86_l_3646;
	case 13896ULL: goto x86_l_3648;
	case 13899ULL: goto x86_l_364b;
	case 13904ULL: goto x86_l_3650;
	case 13909ULL: goto x86_l_3655;
	case 13913ULL: goto x86_l_3659;
	case 13918ULL: goto x86_l_365e;
	case 13920ULL: goto x86_l_3660;
	case 13922ULL: goto x86_l_3662;
	case 13928ULL: goto x86_l_3668;
	case 13938ULL: goto x86_l_3672;
	case 13944ULL: goto x86_l_3678;
	case 13952ULL: goto x86_l_3680;
	case 13956ULL: goto x86_l_3684;
	case 13960ULL: goto x86_l_3688;
	case 13970ULL: goto x86_l_3692;
	case 13972ULL: goto x86_l_3694;
	case 13975ULL: goto x86_l_3697;
	case 13980ULL: goto x86_l_369c;
	case 13985ULL: goto x86_l_36a1;
	case 13989ULL: goto x86_l_36a5;
	case 13994ULL: goto x86_l_36aa;
	case 13996ULL: goto x86_l_36ac;
	case 13998ULL: goto x86_l_36ae;
	case 14004ULL: goto x86_l_36b4;
	case 14014ULL: goto x86_l_36be;
	case 14020ULL: goto x86_l_36c4;
	default: return 0xffffffffffffffffULL;
	}
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
	/* 0x2f86: js     3541 <generic_sleepable_preload+0x3541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3541;
	}
x86_l_2f8c:
	/* 0x2f8c: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2f96:
	/* 0x2f96: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_2f9c:
	/* 0x2f9c: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2fa4:
	/* 0x2fa4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2fa8:
	/* 0x2fa8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fac:
	/* 0x2fac: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2fb6:
	/* 0x2fb6: je     2fd8 <generic_sleepable_preload+0x2fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd8;
	}
x86_l_2fb8:
	/* 0x2fb8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fbb:
	/* 0x2fbb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fc0:
	/* 0x2fc0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fc5:
	/* 0x2fc5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fce:
	/* 0x2fce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd0:
	/* 0x2fd0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fd2:
	/* 0x2fd2: js     3b7d <generic_sleepable_preload+0x3b7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15229ULL;
	}
x86_l_2fd8:
	/* 0x2fd8: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2fe2:
	/* 0x2fe2: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_2fe8:
	/* 0x2fe8: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2ff0:
	/* 0x2ff0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ff4:
	/* 0x2ff4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ff8:
	/* 0x2ff8: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3002:
	/* 0x3002: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3024;
	}
x86_l_3004:
	/* 0x3004: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3007:
	/* 0x3007: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_300c:
	/* 0x300c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3011:
	/* 0x3011: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3015:
	/* 0x3015: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_301a:
	/* 0x301a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301c:
	/* 0x301c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_301e:
	/* 0x301e: js     3b8e <generic_sleepable_preload+0x3b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15246ULL;
	}
x86_l_3024:
	/* 0x3024: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_302e:
	/* 0x302e: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_3034:
	/* 0x3034: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_303c:
	/* 0x303c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3040:
	/* 0x3040: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3044:
	/* 0x3044: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_304e:
	/* 0x304e: je     3070 <generic_sleepable_preload+0x3070> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3070;
	}
x86_l_3050:
	/* 0x3050: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3053:
	/* 0x3053: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3058:
	/* 0x3058: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_305d:
	/* 0x305d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3061:
	/* 0x3061: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3066:
	/* 0x3066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3068:
	/* 0x3068: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_306a:
	/* 0x306a: js     3b9f <generic_sleepable_preload+0x3b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15263ULL;
	}
x86_l_3070:
	/* 0x3070: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_307a:
	/* 0x307a: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_3080:
	/* 0x3080: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3088:
	/* 0x3088: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_308c:
	/* 0x308c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3090:
	/* 0x3090: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_309a:
	/* 0x309a: je     30bc <generic_sleepable_preload+0x30bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30bc;
	}
x86_l_309c:
	/* 0x309c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_309f:
	/* 0x309f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30a4:
	/* 0x30a4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30a9:
	/* 0x30a9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30ad:
	/* 0x30ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b2:
	/* 0x30b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b4:
	/* 0x30b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30b6:
	/* 0x30b6: js     3bb0 <generic_sleepable_preload+0x3bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15280ULL;
	}
x86_l_30bc:
	/* 0x30bc: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_30c6:
	/* 0x30c6: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_30cc:
	/* 0x30cc: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_30d4:
	/* 0x30d4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_30d8:
	/* 0x30d8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30dc:
	/* 0x30dc: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_30e6:
	/* 0x30e6: je     3108 <generic_sleepable_preload+0x3108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3108;
	}
x86_l_30e8:
	/* 0x30e8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30eb:
	/* 0x30eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_30f0:
	/* 0x30f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30f5:
	/* 0x30f5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f9:
	/* 0x30f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30fe:
	/* 0x30fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3100:
	/* 0x3100: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3102:
	/* 0x3102: js     3bc1 <generic_sleepable_preload+0x3bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15297ULL;
	}
x86_l_3108:
	/* 0x3108: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3112:
	/* 0x3112: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_3118:
	/* 0x3118: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3120:
	/* 0x3120: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3124:
	/* 0x3124: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3128:
	/* 0x3128: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3132:
	/* 0x3132: je     3154 <generic_sleepable_preload+0x3154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3154;
	}
x86_l_3134:
	/* 0x3134: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3137:
	/* 0x3137: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_313c:
	/* 0x313c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3141:
	/* 0x3141: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3145:
	/* 0x3145: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_314a:
	/* 0x314a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314c:
	/* 0x314c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_314e:
	/* 0x314e: js     5bf3 <generic_sleepable_preload+0x5bf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23539ULL;
	}
x86_l_3154:
	/* 0x3154: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_315e:
	/* 0x315e: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_3164:
	/* 0x3164: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_316c:
	/* 0x316c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3170:
	/* 0x3170: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3174:
	/* 0x3174: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_317e:
	/* 0x317e: je     31a0 <generic_sleepable_preload+0x31a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a0;
	}
x86_l_3180:
	/* 0x3180: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3183:
	/* 0x3183: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3188:
	/* 0x3188: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_318d:
	/* 0x318d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3191:
	/* 0x3191: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3196:
	/* 0x3196: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3198:
	/* 0x3198: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_319a:
	/* 0x319a: js     5ced <generic_sleepable_preload+0x5ced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23789ULL;
	}
x86_l_31a0:
	/* 0x31a0: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31a5:
	/* 0x31a5: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_31af:
	/* 0x31af: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_31b5:
	/* 0x31b5: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_31bd:
	/* 0x31bd: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_31c1:
	/* 0x31c1: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31c5:
	/* 0x31c5: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_31cf:
	/* 0x31cf: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_31d5:
	/* 0x31d5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31d8:
	/* 0x31d8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31dd:
	/* 0x31dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31e2:
	/* 0x31e2: jmp    34bc <generic_sleepable_preload+0x34bc> */
	goto x86_l_34bc;
x86_l_31e7:
	/* 0x31e7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31ea:
	/* 0x31ea: je     320c <generic_sleepable_preload+0x320c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_320c;
	}
x86_l_31ec:
	/* 0x31ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31ef:
	/* 0x31ef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31f4:
	/* 0x31f4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31f9:
	/* 0x31f9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31fd:
	/* 0x31fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3202:
	/* 0x3202: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3204:
	/* 0x3204: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3206:
	/* 0x3206: js     34d9 <generic_sleepable_preload+0x34d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34d9;
	}
x86_l_320c:
	/* 0x320c: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_3216:
	/* 0x3216: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_321c:
	/* 0x321c: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3224:
	/* 0x3224: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3228:
	/* 0x3228: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_322c:
	/* 0x322c: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3236:
	/* 0x3236: je     3258 <generic_sleepable_preload+0x3258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3258;
	}
x86_l_3238:
	/* 0x3238: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_323b:
	/* 0x323b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3240:
	/* 0x3240: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3245:
	/* 0x3245: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3249:
	/* 0x3249: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_324e:
	/* 0x324e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3250:
	/* 0x3250: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3252:
	/* 0x3252: js     3541 <generic_sleepable_preload+0x3541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3541;
	}
x86_l_3258:
	/* 0x3258: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3262:
	/* 0x3262: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_3268:
	/* 0x3268: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3270:
	/* 0x3270: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3274:
	/* 0x3274: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3278:
	/* 0x3278: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3282:
	/* 0x3282: je     32a4 <generic_sleepable_preload+0x32a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a4;
	}
x86_l_3284:
	/* 0x3284: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3287:
	/* 0x3287: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_328c:
	/* 0x328c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3291:
	/* 0x3291: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3295:
	/* 0x3295: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_329a:
	/* 0x329a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_329c:
	/* 0x329c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_329e:
	/* 0x329e: js     3b7d <generic_sleepable_preload+0x3b7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15229ULL;
	}
x86_l_32a4:
	/* 0x32a4: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_32ae:
	/* 0x32ae: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_32b4:
	/* 0x32b4: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_32bc:
	/* 0x32bc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32c0:
	/* 0x32c0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c4:
	/* 0x32c4: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_32ce:
	/* 0x32ce: je     32f0 <generic_sleepable_preload+0x32f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f0;
	}
x86_l_32d0:
	/* 0x32d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32d3:
	/* 0x32d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32d8:
	/* 0x32d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32dd:
	/* 0x32dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32e1:
	/* 0x32e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e6:
	/* 0x32e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e8:
	/* 0x32e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32ea:
	/* 0x32ea: js     3b8e <generic_sleepable_preload+0x3b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15246ULL;
	}
x86_l_32f0:
	/* 0x32f0: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_32fa:
	/* 0x32fa: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_3300:
	/* 0x3300: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3308:
	/* 0x3308: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_330c:
	/* 0x330c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3310:
	/* 0x3310: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_331a:
	/* 0x331a: je     333c <generic_sleepable_preload+0x333c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_333c;
	}
x86_l_331c:
	/* 0x331c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_331f:
	/* 0x331f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3324:
	/* 0x3324: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3329:
	/* 0x3329: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_332d:
	/* 0x332d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3332:
	/* 0x3332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3334:
	/* 0x3334: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3336:
	/* 0x3336: js     3b9f <generic_sleepable_preload+0x3b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15263ULL;
	}
x86_l_333c:
	/* 0x333c: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3346:
	/* 0x3346: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_334c:
	/* 0x334c: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3354:
	/* 0x3354: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3358:
	/* 0x3358: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_335c:
	/* 0x335c: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3366:
	/* 0x3366: je     3388 <generic_sleepable_preload+0x3388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3388;
	}
x86_l_3368:
	/* 0x3368: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_336b:
	/* 0x336b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3370:
	/* 0x3370: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3375:
	/* 0x3375: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3379:
	/* 0x3379: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_337e:
	/* 0x337e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3380:
	/* 0x3380: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3382:
	/* 0x3382: js     3bb0 <generic_sleepable_preload+0x3bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15280ULL;
	}
x86_l_3388:
	/* 0x3388: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3392:
	/* 0x3392: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_3398:
	/* 0x3398: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_33a0:
	/* 0x33a0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33a4:
	/* 0x33a4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a8:
	/* 0x33a8: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_33b2:
	/* 0x33b2: je     33d4 <generic_sleepable_preload+0x33d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d4;
	}
x86_l_33b4:
	/* 0x33b4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33b7:
	/* 0x33b7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33bc:
	/* 0x33bc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33c1:
	/* 0x33c1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c5:
	/* 0x33c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33ca:
	/* 0x33ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33cc:
	/* 0x33cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33ce:
	/* 0x33ce: js     3bc1 <generic_sleepable_preload+0x3bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15297ULL;
	}
x86_l_33d4:
	/* 0x33d4: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_33de:
	/* 0x33de: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_33e4:
	/* 0x33e4: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_33e7:
	/* 0x33e7: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_33ef:
	/* 0x33ef: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33f3:
	/* 0x33f3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33f7:
	/* 0x33f7: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3401:
	/* 0x3401: je     3423 <generic_sleepable_preload+0x3423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3423;
	}
x86_l_3403:
	/* 0x3403: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3406:
	/* 0x3406: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_340b:
	/* 0x340b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3410:
	/* 0x3410: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3414:
	/* 0x3414: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3419:
	/* 0x3419: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341b:
	/* 0x341b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_341d:
	/* 0x341d: js     5c71 <generic_sleepable_preload+0x5c71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23665ULL;
	}
x86_l_3423:
	/* 0x3423: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3428:
	/* 0x3428: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3432:
	/* 0x3432: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3435:
	/* 0x3435: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_343b:
	/* 0x343b: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3443:
	/* 0x3443: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3447:
	/* 0x3447: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_344b:
	/* 0x344b: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3455:
	/* 0x3455: je     3477 <generic_sleepable_preload+0x3477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3477;
	}
x86_l_3457:
	/* 0x3457: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_345a:
	/* 0x345a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_345f:
	/* 0x345f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3464:
	/* 0x3464: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3468:
	/* 0x3468: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_346d:
	/* 0x346d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_346f:
	/* 0x346f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3471:
	/* 0x3471: js     5d89 <generic_sleepable_preload+0x5d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23945ULL;
	}
x86_l_3477:
	/* 0x3477: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_347c:
	/* 0x347c: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3486:
	/* 0x3486: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3489:
	/* 0x3489: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_348f:
	/* 0x348f: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3497:
	/* 0x3497: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_349b:
	/* 0x349b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_349f:
	/* 0x349f: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_34a9:
	/* 0x34a9: je     3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15305ULL;
	}
x86_l_34af:
	/* 0x34af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_34b2:
	/* 0x34b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34b7:
	/* 0x34b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34bc:
	/* 0x34bc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c0:
	/* 0x34c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34c5:
	/* 0x34c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34c7:
	/* 0x34c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34c9:
	/* 0x34c9: jns    3bc9 <generic_sleepable_preload+0x3bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 15305ULL;
	}
x86_l_34cf:
	/* 0x34cf: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_34d4:
	/* 0x34d4: jmp    3bc6 <generic_sleepable_preload+0x3bc6> */
	return 15302ULL;
x86_l_34d9:
	/* 0x34d9: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_34de:
	/* 0x34de: jmp    3bc6 <generic_sleepable_preload+0x3bc6> */
	return 15302ULL;
x86_l_34e3:
	/* 0x34e3: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_34eb:
	/* 0x34eb: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_34ee:
	/* 0x34ee: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_34f0:
	/* 0x34f0: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34f5:
	/* 0x34f5: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_34f8:
	/* 0x34f8: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_34fa:
	/* 0x34fa: jmp    3563 <generic_sleepable_preload+0x3563> */
	goto x86_l_3563;
x86_l_34fc:
	/* 0x34fc: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3501:
	/* 0x3501: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3504:
	/* 0x3504: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_3506:
	/* 0x3506: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_350b:
	/* 0x350b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_350e:
	/* 0x350e: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_3510:
	/* 0x3510: jmp    3563 <generic_sleepable_preload+0x3563> */
	goto x86_l_3563;
x86_l_3512:
	/* 0x3512: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_351a:
	/* 0x351a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_351d:
	/* 0x351d: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_351f:
	/* 0x351f: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3524:
	/* 0x3524: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3527:
	/* 0x3527: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_3529:
	/* 0x3529: jmp    3563 <generic_sleepable_preload+0x3563> */
	goto x86_l_3563;
x86_l_352b:
	/* 0x352b: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3530:
	/* 0x3530: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_3533:
	/* 0x3533: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_3535:
	/* 0x3535: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_353a:
	/* 0x353a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_353d:
	/* 0x353d: je     3550 <generic_sleepable_preload+0x3550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3550;
	}
x86_l_353f:
	/* 0x353f: jmp    3563 <generic_sleepable_preload+0x3563> */
	goto x86_l_3563;
x86_l_3541:
	/* 0x3541: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3546:
	/* 0x3546: jmp    3bc6 <generic_sleepable_preload+0x3bc6> */
	return 15302ULL;
x86_l_354b:
	/* 0x354b: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3550:
	/* 0x3550: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_3553:
	/* 0x3553: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_3555:
	/* 0x3555: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_3557:
	/* 0x3557: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_355c:
	/* 0x355c: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_355e:
	/* 0x355e: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_3563:
	/* 0x3563: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3567:
	/* 0x3567: mov    ebp,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_356c:
	/* 0x356c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_356e:
	/* 0x356e: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3571:
	/* 0x3571: cmp    WORD PTR [r12+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_357b:
	/* 0x357b: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15444ULL;
	}
x86_l_3581:
	/* 0x3581: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3588:
	/* 0x3588: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_358b:
	/* 0x358b: mov    eax,DWORD PTR [r12+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3593:
	/* 0x3593: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3596:
	/* 0x3596: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_359a:
	/* 0x359a: movzx  eax,WORD PTR [r12+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_35a3:
	/* 0x35a3: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_35a5:
	/* 0x35a5: je     3877 <generic_sleepable_preload+0x3877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14455ULL;
	}
x86_l_35ab:
	/* 0x35ab: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_35ae:
	/* 0x35ae: je     35d0 <generic_sleepable_preload+0x35d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d0;
	}
x86_l_35b0:
	/* 0x35b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_35b3:
	/* 0x35b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35b8:
	/* 0x35b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35bd:
	/* 0x35bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c1:
	/* 0x35c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35c6:
	/* 0x35c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c8:
	/* 0x35c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35ca:
	/* 0x35ca: js     3b69 <generic_sleepable_preload+0x3b69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15209ULL;
	}
x86_l_35d0:
	/* 0x35d0: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_35da:
	/* 0x35da: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15444ULL;
	}
x86_l_35e0:
	/* 0x35e0: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_35e8:
	/* 0x35e8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35ec:
	/* 0x35ec: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f0:
	/* 0x35f0: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_35fa:
	/* 0x35fa: je     361c <generic_sleepable_preload+0x361c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_361c;
	}
x86_l_35fc:
	/* 0x35fc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_35ff:
	/* 0x35ff: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3604:
	/* 0x3604: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3609:
	/* 0x3609: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_360d:
	/* 0x360d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3612:
	/* 0x3612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3614:
	/* 0x3614: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3616:
	/* 0x3616: js     3b73 <generic_sleepable_preload+0x3b73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15219ULL;
	}
x86_l_361c:
	/* 0x361c: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3626:
	/* 0x3626: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15444ULL;
	}
x86_l_362c:
	/* 0x362c: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3634:
	/* 0x3634: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3638:
	/* 0x3638: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_363c:
	/* 0x363c: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3646:
	/* 0x3646: je     3668 <generic_sleepable_preload+0x3668> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3668;
	}
x86_l_3648:
	/* 0x3648: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_364b:
	/* 0x364b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3650:
	/* 0x3650: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3655:
	/* 0x3655: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3659:
	/* 0x3659: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_365e:
	/* 0x365e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3660:
	/* 0x3660: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3662:
	/* 0x3662: js     3b84 <generic_sleepable_preload+0x3b84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15236ULL;
	}
x86_l_3668:
	/* 0x3668: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3672:
	/* 0x3672: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15444ULL;
	}
x86_l_3678:
	/* 0x3678: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3680:
	/* 0x3680: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3684:
	/* 0x3684: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3688:
	/* 0x3688: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3692:
	/* 0x3692: je     36b4 <generic_sleepable_preload+0x36b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36b4;
	}
x86_l_3694:
	/* 0x3694: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3697:
	/* 0x3697: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_369c:
	/* 0x369c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36a1:
	/* 0x36a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36a5:
	/* 0x36a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36aa:
	/* 0x36aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36ac:
	/* 0x36ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36ae:
	/* 0x36ae: js     3b95 <generic_sleepable_preload+0x3b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15253ULL;
	}
x86_l_36b4:
	/* 0x36b4: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_36be:
	/* 0x36be: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15444ULL;
	}
x86_l_36c4:
	/* 0x36c4: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
	return 14028ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14028ULL: goto x86_l_36cc;
	case 14032ULL: goto x86_l_36d0;
	case 14036ULL: goto x86_l_36d4;
	case 14046ULL: goto x86_l_36de;
	case 14048ULL: goto x86_l_36e0;
	case 14051ULL: goto x86_l_36e3;
	case 14056ULL: goto x86_l_36e8;
	case 14061ULL: goto x86_l_36ed;
	case 14065ULL: goto x86_l_36f1;
	case 14070ULL: goto x86_l_36f6;
	case 14072ULL: goto x86_l_36f8;
	case 14074ULL: goto x86_l_36fa;
	case 14080ULL: goto x86_l_3700;
	case 14090ULL: goto x86_l_370a;
	case 14096ULL: goto x86_l_3710;
	case 14104ULL: goto x86_l_3718;
	case 14108ULL: goto x86_l_371c;
	case 14112ULL: goto x86_l_3720;
	case 14122ULL: goto x86_l_372a;
	case 14124ULL: goto x86_l_372c;
	case 14127ULL: goto x86_l_372f;
	case 14132ULL: goto x86_l_3734;
	case 14137ULL: goto x86_l_3739;
	case 14141ULL: goto x86_l_373d;
	case 14146ULL: goto x86_l_3742;
	case 14148ULL: goto x86_l_3744;
	case 14150ULL: goto x86_l_3746;
	case 14156ULL: goto x86_l_374c;
	case 14166ULL: goto x86_l_3756;
	case 14172ULL: goto x86_l_375c;
	case 14180ULL: goto x86_l_3764;
	case 14184ULL: goto x86_l_3768;
	case 14188ULL: goto x86_l_376c;
	case 14198ULL: goto x86_l_3776;
	case 14200ULL: goto x86_l_3778;
	case 14203ULL: goto x86_l_377b;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14217ULL: goto x86_l_3789;
	case 14222ULL: goto x86_l_378e;
	case 14224ULL: goto x86_l_3790;
	case 14226ULL: goto x86_l_3792;
	case 14232ULL: goto x86_l_3798;
	case 14242ULL: goto x86_l_37a2;
	case 14248ULL: goto x86_l_37a8;
	case 14256ULL: goto x86_l_37b0;
	case 14260ULL: goto x86_l_37b4;
	case 14264ULL: goto x86_l_37b8;
	case 14274ULL: goto x86_l_37c2;
	case 14276ULL: goto x86_l_37c4;
	case 14279ULL: goto x86_l_37c7;
	case 14284ULL: goto x86_l_37cc;
	case 14289ULL: goto x86_l_37d1;
	case 14293ULL: goto x86_l_37d5;
	case 14298ULL: goto x86_l_37da;
	case 14300ULL: goto x86_l_37dc;
	case 14302ULL: goto x86_l_37de;
	case 14308ULL: goto x86_l_37e4;
	case 14318ULL: goto x86_l_37ee;
	case 14324ULL: goto x86_l_37f4;
	case 14332ULL: goto x86_l_37fc;
	case 14336ULL: goto x86_l_3800;
	case 14340ULL: goto x86_l_3804;
	case 14350ULL: goto x86_l_380e;
	case 14352ULL: goto x86_l_3810;
	case 14355ULL: goto x86_l_3813;
	case 14360ULL: goto x86_l_3818;
	case 14365ULL: goto x86_l_381d;
	case 14369ULL: goto x86_l_3821;
	case 14374ULL: goto x86_l_3826;
	case 14376ULL: goto x86_l_3828;
	case 14378ULL: goto x86_l_382a;
	case 14384ULL: goto x86_l_3830;
	case 14389ULL: goto x86_l_3835;
	case 14399ULL: goto x86_l_383f;
	case 14405ULL: goto x86_l_3845;
	case 14413ULL: goto x86_l_384d;
	case 14417ULL: goto x86_l_3851;
	case 14421ULL: goto x86_l_3855;
	case 14431ULL: goto x86_l_385f;
	case 14437ULL: goto x86_l_3865;
	case 14440ULL: goto x86_l_3868;
	case 14445ULL: goto x86_l_386d;
	case 14450ULL: goto x86_l_3872;
	case 14455ULL: goto x86_l_3877;
	case 14458ULL: goto x86_l_387a;
	case 14460ULL: goto x86_l_387c;
	case 14463ULL: goto x86_l_387f;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14477ULL: goto x86_l_388d;
	case 14482ULL: goto x86_l_3892;
	case 14484ULL: goto x86_l_3894;
	case 14486ULL: goto x86_l_3896;
	case 14492ULL: goto x86_l_389c;
	case 14502ULL: goto x86_l_38a6;
	case 14508ULL: goto x86_l_38ac;
	case 14516ULL: goto x86_l_38b4;
	case 14520ULL: goto x86_l_38b8;
	case 14524ULL: goto x86_l_38bc;
	case 14534ULL: goto x86_l_38c6;
	case 14536ULL: goto x86_l_38c8;
	case 14539ULL: goto x86_l_38cb;
	case 14544ULL: goto x86_l_38d0;
	case 14549ULL: goto x86_l_38d5;
	case 14553ULL: goto x86_l_38d9;
	case 14558ULL: goto x86_l_38de;
	case 14560ULL: goto x86_l_38e0;
	case 14562ULL: goto x86_l_38e2;
	case 14568ULL: goto x86_l_38e8;
	case 14578ULL: goto x86_l_38f2;
	case 14584ULL: goto x86_l_38f8;
	case 14592ULL: goto x86_l_3900;
	case 14596ULL: goto x86_l_3904;
	case 14600ULL: goto x86_l_3908;
	case 14610ULL: goto x86_l_3912;
	case 14612ULL: goto x86_l_3914;
	case 14615ULL: goto x86_l_3917;
	case 14620ULL: goto x86_l_391c;
	case 14625ULL: goto x86_l_3921;
	case 14629ULL: goto x86_l_3925;
	case 14634ULL: goto x86_l_392a;
	case 14636ULL: goto x86_l_392c;
	case 14638ULL: goto x86_l_392e;
	case 14644ULL: goto x86_l_3934;
	case 14654ULL: goto x86_l_393e;
	case 14660ULL: goto x86_l_3944;
	case 14668ULL: goto x86_l_394c;
	case 14672ULL: goto x86_l_3950;
	case 14676ULL: goto x86_l_3954;
	case 14686ULL: goto x86_l_395e;
	case 14688ULL: goto x86_l_3960;
	case 14691ULL: goto x86_l_3963;
	case 14696ULL: goto x86_l_3968;
	case 14701ULL: goto x86_l_396d;
	case 14705ULL: goto x86_l_3971;
	case 14710ULL: goto x86_l_3976;
	case 14712ULL: goto x86_l_3978;
	case 14714ULL: goto x86_l_397a;
	case 14720ULL: goto x86_l_3980;
	case 14730ULL: goto x86_l_398a;
	case 14736ULL: goto x86_l_3990;
	case 14744ULL: goto x86_l_3998;
	case 14748ULL: goto x86_l_399c;
	case 14752ULL: goto x86_l_39a0;
	case 14762ULL: goto x86_l_39aa;
	case 14764ULL: goto x86_l_39ac;
	case 14767ULL: goto x86_l_39af;
	case 14772ULL: goto x86_l_39b4;
	case 14777ULL: goto x86_l_39b9;
	case 14781ULL: goto x86_l_39bd;
	case 14786ULL: goto x86_l_39c2;
	case 14788ULL: goto x86_l_39c4;
	case 14790ULL: goto x86_l_39c6;
	case 14796ULL: goto x86_l_39cc;
	case 14806ULL: goto x86_l_39d6;
	case 14812ULL: goto x86_l_39dc;
	case 14820ULL: goto x86_l_39e4;
	case 14824ULL: goto x86_l_39e8;
	case 14828ULL: goto x86_l_39ec;
	case 14838ULL: goto x86_l_39f6;
	case 14840ULL: goto x86_l_39f8;
	case 14843ULL: goto x86_l_39fb;
	case 14848ULL: goto x86_l_3a00;
	case 14853ULL: goto x86_l_3a05;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14864ULL: goto x86_l_3a10;
	case 14866ULL: goto x86_l_3a12;
	case 14872ULL: goto x86_l_3a18;
	case 14882ULL: goto x86_l_3a22;
	case 14888ULL: goto x86_l_3a28;
	case 14896ULL: goto x86_l_3a30;
	case 14900ULL: goto x86_l_3a34;
	case 14904ULL: goto x86_l_3a38;
	case 14914ULL: goto x86_l_3a42;
	case 14916ULL: goto x86_l_3a44;
	case 14919ULL: goto x86_l_3a47;
	case 14924ULL: goto x86_l_3a4c;
	case 14929ULL: goto x86_l_3a51;
	case 14933ULL: goto x86_l_3a55;
	case 14938ULL: goto x86_l_3a5a;
	case 14940ULL: goto x86_l_3a5c;
	case 14942ULL: goto x86_l_3a5e;
	case 14948ULL: goto x86_l_3a64;
	case 14958ULL: goto x86_l_3a6e;
	case 14964ULL: goto x86_l_3a74;
	case 14967ULL: goto x86_l_3a77;
	case 14975ULL: goto x86_l_3a7f;
	case 14979ULL: goto x86_l_3a83;
	case 14983ULL: goto x86_l_3a87;
	case 14993ULL: goto x86_l_3a91;
	case 14995ULL: goto x86_l_3a93;
	case 14998ULL: goto x86_l_3a96;
	case 15003ULL: goto x86_l_3a9b;
	case 15008ULL: goto x86_l_3aa0;
	case 15012ULL: goto x86_l_3aa4;
	case 15017ULL: goto x86_l_3aa9;
	case 15019ULL: goto x86_l_3aab;
	case 15021ULL: goto x86_l_3aad;
	case 15027ULL: goto x86_l_3ab3;
	case 15032ULL: goto x86_l_3ab8;
	case 15042ULL: goto x86_l_3ac2;
	case 15045ULL: goto x86_l_3ac5;
	case 15051ULL: goto x86_l_3acb;
	case 15059ULL: goto x86_l_3ad3;
	case 15063ULL: goto x86_l_3ad7;
	case 15067ULL: goto x86_l_3adb;
	case 15077ULL: goto x86_l_3ae5;
	case 15079ULL: goto x86_l_3ae7;
	case 15082ULL: goto x86_l_3aea;
	case 15087ULL: goto x86_l_3aef;
	case 15092ULL: goto x86_l_3af4;
	case 15096ULL: goto x86_l_3af8;
	case 15101ULL: goto x86_l_3afd;
	case 15103ULL: goto x86_l_3aff;
	case 15105ULL: goto x86_l_3b01;
	case 15111ULL: goto x86_l_3b07;
	case 15116ULL: goto x86_l_3b0c;
	case 15126ULL: goto x86_l_3b16;
	case 15129ULL: goto x86_l_3b19;
	case 15135ULL: goto x86_l_3b1f;
	case 15143ULL: goto x86_l_3b27;
	case 15147ULL: goto x86_l_3b2b;
	case 15151ULL: goto x86_l_3b2f;
	case 15161ULL: goto x86_l_3b39;
	case 15167ULL: goto x86_l_3b3f;
	case 15170ULL: goto x86_l_3b42;
	case 15175ULL: goto x86_l_3b47;
	case 15180ULL: goto x86_l_3b4c;
	case 15184ULL: goto x86_l_3b50;
	case 15189ULL: goto x86_l_3b55;
	case 15191ULL: goto x86_l_3b57;
	case 15193ULL: goto x86_l_3b59;
	case 15199ULL: goto x86_l_3b5f;
	case 15204ULL: goto x86_l_3b64;
	case 15209ULL: goto x86_l_3b69;
	case 15214ULL: goto x86_l_3b6e;
	case 15219ULL: goto x86_l_3b73;
	case 15224ULL: goto x86_l_3b78;
	case 15229ULL: goto x86_l_3b7d;
	case 15234ULL: goto x86_l_3b82;
	case 15236ULL: goto x86_l_3b84;
	case 15241ULL: goto x86_l_3b89;
	case 15246ULL: goto x86_l_3b8e;
	case 15251ULL: goto x86_l_3b93;
	case 15253ULL: goto x86_l_3b95;
	case 15258ULL: goto x86_l_3b9a;
	case 15263ULL: goto x86_l_3b9f;
	case 15268ULL: goto x86_l_3ba4;
	case 15270ULL: goto x86_l_3ba6;
	case 15275ULL: goto x86_l_3bab;
	case 15280ULL: goto x86_l_3bb0;
	case 15285ULL: goto x86_l_3bb5;
	case 15287ULL: goto x86_l_3bb7;
	case 15292ULL: goto x86_l_3bbc;
	case 15297ULL: goto x86_l_3bc1;
	case 15302ULL: goto x86_l_3bc6;
	case 15305ULL: goto x86_l_3bc9;
	case 15310ULL: goto x86_l_3bce;
	case 15313ULL: goto x86_l_3bd1;
	case 15318ULL: goto x86_l_3bd6;
	case 15323ULL: goto x86_l_3bdb;
	case 15328ULL: goto x86_l_3be0;
	case 15331ULL: goto x86_l_3be3;
	case 15333ULL: goto x86_l_3be5;
	case 15336ULL: goto x86_l_3be8;
	case 15342ULL: goto x86_l_3bee;
	case 15345ULL: goto x86_l_3bf1;
	case 15349ULL: goto x86_l_3bf5;
	case 15354ULL: goto x86_l_3bfa;
	case 15356ULL: goto x86_l_3bfc;
	case 15361ULL: goto x86_l_3c01;
	case 15369ULL: goto x86_l_3c09;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15386ULL: goto x86_l_3c1a;
	case 15388ULL: goto x86_l_3c1c;
	case 15391ULL: goto x86_l_3c1f;
	case 15397ULL: goto x86_l_3c25;
	case 15400ULL: goto x86_l_3c28;
	case 15407ULL: goto x86_l_3c2f;
	case 15409ULL: goto x86_l_3c31;
	case 15414ULL: goto x86_l_3c36;
	case 15419ULL: goto x86_l_3c3b;
	case 15422ULL: goto x86_l_3c3e;
	case 15425ULL: goto x86_l_3c41;
	case 15427ULL: goto x86_l_3c43;
	case 15429ULL: goto x86_l_3c45;
	case 15434ULL: goto x86_l_3c4a;
	case 15436ULL: goto x86_l_3c4c;
	case 15441ULL: goto x86_l_3c51;
	case 15444ULL: goto x86_l_3c54;
	case 15447ULL: goto x86_l_3c57;
	case 15453ULL: goto x86_l_3c5d;
	case 15456ULL: goto x86_l_3c60;
	case 15460ULL: goto x86_l_3c64;
	case 15465ULL: goto x86_l_3c69;
	case 15467ULL: goto x86_l_3c6b;
	case 15472ULL: goto x86_l_3c70;
	case 15480ULL: goto x86_l_3c78;
	case 15487ULL: goto x86_l_3c7f;
	case 15492ULL: goto x86_l_3c84;
	case 15497ULL: goto x86_l_3c89;
	case 15499ULL: goto x86_l_3c8b;
	case 15502ULL: goto x86_l_3c8e;
	case 15504ULL: goto x86_l_3c90;
	case 15507ULL: goto x86_l_3c93;
	case 15514ULL: goto x86_l_3c9a;
	case 15516ULL: goto x86_l_3c9c;
	case 15521ULL: goto x86_l_3ca1;
	case 15526ULL: goto x86_l_3ca6;
	case 15529ULL: goto x86_l_3ca9;
	case 15532ULL: goto x86_l_3cac;
	case 15534ULL: goto x86_l_3cae;
	case 15536ULL: goto x86_l_3cb0;
	case 15541ULL: goto x86_l_3cb5;
	case 15544ULL: goto x86_l_3cb8;
	case 15547ULL: goto x86_l_3cbb;
	case 15552ULL: goto x86_l_3cc0;
	case 15554ULL: goto x86_l_3cc2;
	case 15557ULL: goto x86_l_3cc5;
	case 15559ULL: goto x86_l_3cc7;
	case 15562ULL: goto x86_l_3cca;
	case 15564ULL: goto x86_l_3ccc;
	case 15567ULL: goto x86_l_3ccf;
	case 15571ULL: goto x86_l_3cd3;
	case 15576ULL: goto x86_l_3cd8;
	case 15579ULL: goto x86_l_3cdb;
	case 15581ULL: goto x86_l_3cdd;
	case 15584ULL: goto x86_l_3ce0;
	case 15589ULL: goto x86_l_3ce5;
	case 15591ULL: goto x86_l_3ce7;
	case 15594ULL: goto x86_l_3cea;
	case 15596ULL: goto x86_l_3cec;
	case 15601ULL: goto x86_l_3cf1;
	case 15604ULL: goto x86_l_3cf4;
	case 15606ULL: goto x86_l_3cf6;
	case 15609ULL: goto x86_l_3cf9;
	case 15614ULL: goto x86_l_3cfe;
	case 15619ULL: goto x86_l_3d03;
	case 15625ULL: goto x86_l_3d09;
	case 15627ULL: goto x86_l_3d0b;
	case 15629ULL: goto x86_l_3d0d;
	case 15634ULL: goto x86_l_3d12;
	case 15637ULL: goto x86_l_3d15;
	case 15643ULL: goto x86_l_3d1b;
	case 15646ULL: goto x86_l_3d1e;
	case 15652ULL: goto x86_l_3d24;
	case 15655ULL: goto x86_l_3d27;
	case 15661ULL: goto x86_l_3d2d;
	case 15664ULL: goto x86_l_3d30;
	case 15670ULL: goto x86_l_3d36;
	case 15675ULL: goto x86_l_3d3b;
	case 15680ULL: goto x86_l_3d40;
	case 15689ULL: goto x86_l_3d49;
	case 15698ULL: goto x86_l_3d52;
	case 15704ULL: goto x86_l_3d58;
	case 15706ULL: goto x86_l_3d5a;
	case 15709ULL: goto x86_l_3d5d;
	case 15711ULL: goto x86_l_3d5f;
	case 15714ULL: goto x86_l_3d62;
	case 15716ULL: goto x86_l_3d64;
	case 15719ULL: goto x86_l_3d67;
	case 15725ULL: goto x86_l_3d6d;
	case 15730ULL: goto x86_l_3d72;
	case 15733ULL: goto x86_l_3d75;
	case 15739ULL: goto x86_l_3d7b;
	case 15744ULL: goto x86_l_3d80;
	case 15747ULL: goto x86_l_3d83;
	case 15753ULL: goto x86_l_3d89;
	case 15758ULL: goto x86_l_3d8e;
	case 15761ULL: goto x86_l_3d91;
	case 15767ULL: goto x86_l_3d97;
	case 15772ULL: goto x86_l_3d9c;
	case 15775ULL: goto x86_l_3d9f;
	case 15777ULL: goto x86_l_3da1;
	case 15780ULL: goto x86_l_3da4;
	case 15786ULL: goto x86_l_3daa;
	case 15788ULL: goto x86_l_3dac;
	case 15794ULL: goto x86_l_3db2;
	case 15797ULL: goto x86_l_3db5;
	case 15800ULL: goto x86_l_3db8;
	case 15806ULL: goto x86_l_3dbe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_36cc:
	/* 0x36cc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_36d0:
	/* 0x36d0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36d4:
	/* 0x36d4: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_36de:
	/* 0x36de: je     3700 <generic_sleepable_preload+0x3700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3700;
	}
x86_l_36e0:
	/* 0x36e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_36e3:
	/* 0x36e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36e8:
	/* 0x36e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36ed:
	/* 0x36ed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36f1:
	/* 0x36f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36f6:
	/* 0x36f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36f8:
	/* 0x36f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36fa:
	/* 0x36fa: js     3ba6 <generic_sleepable_preload+0x3ba6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba6;
	}
x86_l_3700:
	/* 0x3700: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_370a:
	/* 0x370a: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3710:
	/* 0x3710: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3718:
	/* 0x3718: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_371c:
	/* 0x371c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3720:
	/* 0x3720: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_372a:
	/* 0x372a: je     374c <generic_sleepable_preload+0x374c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_374c;
	}
x86_l_372c:
	/* 0x372c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_372f:
	/* 0x372f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3734:
	/* 0x3734: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3739:
	/* 0x3739: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_373d:
	/* 0x373d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3742:
	/* 0x3742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3744:
	/* 0x3744: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3746:
	/* 0x3746: js     3bb7 <generic_sleepable_preload+0x3bb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bb7;
	}
x86_l_374c:
	/* 0x374c: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3756:
	/* 0x3756: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_375c:
	/* 0x375c: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3764:
	/* 0x3764: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3768:
	/* 0x3768: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_376c:
	/* 0x376c: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3776:
	/* 0x3776: je     3798 <generic_sleepable_preload+0x3798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3798;
	}
x86_l_3778:
	/* 0x3778: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_377b:
	/* 0x377b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3780:
	/* 0x3780: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3785:
	/* 0x3785: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3789:
	/* 0x3789: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_378e:
	/* 0x378e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3790:
	/* 0x3790: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3792:
	/* 0x3792: js     3c4c <generic_sleepable_preload+0x3c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c4c;
	}
x86_l_3798:
	/* 0x3798: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_37a2:
	/* 0x37a2: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_37a8:
	/* 0x37a8: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_37b0:
	/* 0x37b0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_37b4:
	/* 0x37b4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37b8:
	/* 0x37b8: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_37c2:
	/* 0x37c2: je     37e4 <generic_sleepable_preload+0x37e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e4;
	}
x86_l_37c4:
	/* 0x37c4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_37c7:
	/* 0x37c7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37cc:
	/* 0x37cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_37d1:
	/* 0x37d1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d5:
	/* 0x37d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37da:
	/* 0x37da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37dc:
	/* 0x37dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37de:
	/* 0x37de: js     5c00 <generic_sleepable_preload+0x5c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23552ULL;
	}
x86_l_37e4:
	/* 0x37e4: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_37ee:
	/* 0x37ee: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_37f4:
	/* 0x37f4: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_37fc:
	/* 0x37fc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3800:
	/* 0x3800: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3804:
	/* 0x3804: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_380e:
	/* 0x380e: je     3830 <generic_sleepable_preload+0x3830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3830;
	}
x86_l_3810:
	/* 0x3810: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3813:
	/* 0x3813: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3818:
	/* 0x3818: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_381d:
	/* 0x381d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3821:
	/* 0x3821: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3826:
	/* 0x3826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3828:
	/* 0x3828: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_382a:
	/* 0x382a: js     5cff <generic_sleepable_preload+0x5cff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23807ULL;
	}
x86_l_3830:
	/* 0x3830: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3835:
	/* 0x3835: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_383f:
	/* 0x383f: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3845:
	/* 0x3845: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_384d:
	/* 0x384d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3851:
	/* 0x3851: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3855:
	/* 0x3855: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_385f:
	/* 0x385f: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3865:
	/* 0x3865: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3868:
	/* 0x3868: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_386d:
	/* 0x386d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3872:
	/* 0x3872: jmp    3b4c <generic_sleepable_preload+0x3b4c> */
	goto x86_l_3b4c;
x86_l_3877:
	/* 0x3877: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_387a:
	/* 0x387a: je     389c <generic_sleepable_preload+0x389c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389c;
	}
x86_l_387c:
	/* 0x387c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_387f:
	/* 0x387f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3884:
	/* 0x3884: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3889:
	/* 0x3889: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_388d:
	/* 0x388d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3892:
	/* 0x3892: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3894:
	/* 0x3894: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3896:
	/* 0x3896: js     3b69 <generic_sleepable_preload+0x3b69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b69;
	}
x86_l_389c:
	/* 0x389c: cmp    WORD PTR [r12+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_38a6:
	/* 0x38a6: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_38ac:
	/* 0x38ac: mov    ecx,DWORD PTR [r12+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_38b4:
	/* 0x38b4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_38b8:
	/* 0x38b8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38bc:
	/* 0x38bc: cmp    WORD PTR [r12+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_38c6:
	/* 0x38c6: je     38e8 <generic_sleepable_preload+0x38e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38e8;
	}
x86_l_38c8:
	/* 0x38c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_38cb:
	/* 0x38cb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38d0:
	/* 0x38d0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38d5:
	/* 0x38d5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38d9:
	/* 0x38d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38de:
	/* 0x38de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e0:
	/* 0x38e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38e2:
	/* 0x38e2: js     3b73 <generic_sleepable_preload+0x3b73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b73;
	}
x86_l_38e8:
	/* 0x38e8: cmp    WORD PTR [r12+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_38f2:
	/* 0x38f2: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_38f8:
	/* 0x38f8: mov    ecx,DWORD PTR [r12+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3900:
	/* 0x3900: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3904:
	/* 0x3904: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3908:
	/* 0x3908: cmp    WORD PTR [r12+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3912:
	/* 0x3912: je     3934 <generic_sleepable_preload+0x3934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3934;
	}
x86_l_3914:
	/* 0x3914: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3917:
	/* 0x3917: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_391c:
	/* 0x391c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3921:
	/* 0x3921: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3925:
	/* 0x3925: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_392a:
	/* 0x392a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_392c:
	/* 0x392c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_392e:
	/* 0x392e: js     3b84 <generic_sleepable_preload+0x3b84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b84;
	}
x86_l_3934:
	/* 0x3934: cmp    WORD PTR [r12+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_393e:
	/* 0x393e: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3944:
	/* 0x3944: mov    ecx,DWORD PTR [r12+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_394c:
	/* 0x394c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3950:
	/* 0x3950: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3954:
	/* 0x3954: cmp    WORD PTR [r12+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_395e:
	/* 0x395e: je     3980 <generic_sleepable_preload+0x3980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3980;
	}
x86_l_3960:
	/* 0x3960: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3963:
	/* 0x3963: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3968:
	/* 0x3968: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_396d:
	/* 0x396d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3971:
	/* 0x3971: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3976:
	/* 0x3976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3978:
	/* 0x3978: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_397a:
	/* 0x397a: js     3b95 <generic_sleepable_preload+0x3b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b95;
	}
x86_l_3980:
	/* 0x3980: cmp    WORD PTR [r12+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_398a:
	/* 0x398a: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3990:
	/* 0x3990: mov    ecx,DWORD PTR [r12+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3998:
	/* 0x3998: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_399c:
	/* 0x399c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39a0:
	/* 0x39a0: cmp    WORD PTR [r12+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_39aa:
	/* 0x39aa: je     39cc <generic_sleepable_preload+0x39cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39cc;
	}
x86_l_39ac:
	/* 0x39ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39af:
	/* 0x39af: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39b4:
	/* 0x39b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39b9:
	/* 0x39b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39bd:
	/* 0x39bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39c2:
	/* 0x39c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c4:
	/* 0x39c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39c6:
	/* 0x39c6: js     3ba6 <generic_sleepable_preload+0x3ba6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ba6;
	}
x86_l_39cc:
	/* 0x39cc: cmp    WORD PTR [r12+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_39d6:
	/* 0x39d6: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_39dc:
	/* 0x39dc: mov    ecx,DWORD PTR [r12+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_39e4:
	/* 0x39e4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39e8:
	/* 0x39e8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39ec:
	/* 0x39ec: cmp    WORD PTR [r12+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_39f6:
	/* 0x39f6: je     3a18 <generic_sleepable_preload+0x3a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a18;
	}
x86_l_39f8:
	/* 0x39f8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39fb:
	/* 0x39fb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a00:
	/* 0x3a00: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a05:
	/* 0x3a05: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a09:
	/* 0x3a09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a0e:
	/* 0x3a0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a10:
	/* 0x3a10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a12:
	/* 0x3a12: js     3bb7 <generic_sleepable_preload+0x3bb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bb7;
	}
x86_l_3a18:
	/* 0x3a18: cmp    WORD PTR [r12+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3a22:
	/* 0x3a22: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3a28:
	/* 0x3a28: mov    ecx,DWORD PTR [r12+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3a30:
	/* 0x3a30: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a34:
	/* 0x3a34: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a38:
	/* 0x3a38: cmp    WORD PTR [r12+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3a42:
	/* 0x3a42: je     3a64 <generic_sleepable_preload+0x3a64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a64;
	}
x86_l_3a44:
	/* 0x3a44: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a47:
	/* 0x3a47: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a4c:
	/* 0x3a4c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a51:
	/* 0x3a51: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a55:
	/* 0x3a55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a5a:
	/* 0x3a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a5c:
	/* 0x3a5c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a5e:
	/* 0x3a5e: js     3c4c <generic_sleepable_preload+0x3c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c4c;
	}
x86_l_3a64:
	/* 0x3a64: cmp    WORD PTR [r12+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3a6e:
	/* 0x3a6e: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3a74:
	/* 0x3a74: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_3a77:
	/* 0x3a77: mov    ecx,DWORD PTR [r12+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3a7f:
	/* 0x3a7f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a83:
	/* 0x3a83: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a87:
	/* 0x3a87: cmp    WORD PTR [r12+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3a91:
	/* 0x3a91: je     3ab3 <generic_sleepable_preload+0x3ab3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ab3;
	}
x86_l_3a93:
	/* 0x3a93: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a96:
	/* 0x3a96: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a9b:
	/* 0x3a9b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3aa0:
	/* 0x3aa0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aa4:
	/* 0x3aa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aa9:
	/* 0x3aa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aab:
	/* 0x3aab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3aad:
	/* 0x3aad: js     5c7e <generic_sleepable_preload+0x5c7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23678ULL;
	}
x86_l_3ab3:
	/* 0x3ab3: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ab8:
	/* 0x3ab8: cmp    WORD PTR [r12+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3ac2:
	/* 0x3ac2: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3ac5:
	/* 0x3ac5: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3acb:
	/* 0x3acb: mov    ecx,DWORD PTR [r12+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3ad3:
	/* 0x3ad3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ad7:
	/* 0x3ad7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3adb:
	/* 0x3adb: cmp    WORD PTR [r12+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3ae5:
	/* 0x3ae5: je     3b07 <generic_sleepable_preload+0x3b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b07;
	}
x86_l_3ae7:
	/* 0x3ae7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3aea:
	/* 0x3aea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3aef:
	/* 0x3aef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3af4:
	/* 0x3af4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3af8:
	/* 0x3af8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3afd:
	/* 0x3afd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aff:
	/* 0x3aff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b01:
	/* 0x3b01: js     5d9e <generic_sleepable_preload+0x5d9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23966ULL;
	}
x86_l_3b07:
	/* 0x3b07: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b0c:
	/* 0x3b0c: cmp    WORD PTR [r12+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3b16:
	/* 0x3b16: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_3b19:
	/* 0x3b19: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3b1f:
	/* 0x3b1f: mov    ecx,DWORD PTR [r12+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3b27:
	/* 0x3b27: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b2b:
	/* 0x3b2b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b2f:
	/* 0x3b2f: cmp    WORD PTR [r12+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3b39:
	/* 0x3b39: je     3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c54;
	}
x86_l_3b3f:
	/* 0x3b3f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b42:
	/* 0x3b42: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b47:
	/* 0x3b47: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b4c:
	/* 0x3b4c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b50:
	/* 0x3b50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b55:
	/* 0x3b55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b57:
	/* 0x3b57: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b59:
	/* 0x3b59: jns    3c54 <generic_sleepable_preload+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3c54;
	}
x86_l_3b5f:
	/* 0x3b5f: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3b64:
	/* 0x3b64: jmp    3c51 <generic_sleepable_preload+0x3c51> */
	goto x86_l_3c51;
x86_l_3b69:
	/* 0x3b69: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3b6e:
	/* 0x3b6e: jmp    3c51 <generic_sleepable_preload+0x3c51> */
	goto x86_l_3c51;
x86_l_3b73:
	/* 0x3b73: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3b78:
	/* 0x3b78: jmp    3c51 <generic_sleepable_preload+0x3c51> */
	goto x86_l_3c51;
x86_l_3b7d:
	/* 0x3b7d: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3b82:
	/* 0x3b82: jmp    3bc6 <generic_sleepable_preload+0x3bc6> */
	goto x86_l_3bc6;
x86_l_3b84:
	/* 0x3b84: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3b89:
	/* 0x3b89: jmp    3c51 <generic_sleepable_preload+0x3c51> */
	goto x86_l_3c51;
x86_l_3b8e:
	/* 0x3b8e: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3b93:
	/* 0x3b93: jmp    3bc6 <generic_sleepable_preload+0x3bc6> */
	goto x86_l_3bc6;
x86_l_3b95:
	/* 0x3b95: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3b9a:
	/* 0x3b9a: jmp    3c51 <generic_sleepable_preload+0x3c51> */
	goto x86_l_3c51;
x86_l_3b9f:
	/* 0x3b9f: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3ba4:
	/* 0x3ba4: jmp    3bc6 <generic_sleepable_preload+0x3bc6> */
	goto x86_l_3bc6;
x86_l_3ba6:
	/* 0x3ba6: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3bab:
	/* 0x3bab: jmp    3c51 <generic_sleepable_preload+0x3c51> */
	goto x86_l_3c51;
x86_l_3bb0:
	/* 0x3bb0: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3bb5:
	/* 0x3bb5: jmp    3bc6 <generic_sleepable_preload+0x3bc6> */
	goto x86_l_3bc6;
x86_l_3bb7:
	/* 0x3bb7: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3bbc:
	/* 0x3bbc: jmp    3c51 <generic_sleepable_preload+0x3c51> */
	goto x86_l_3c51;
x86_l_3bc1:
	/* 0x3bc1: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3bc6:
	/* 0x3bc6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3bc9:
	/* 0x3bc9: mov    ebp,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3bce:
	/* 0x3bce: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3bd1:
	/* 0x3bd1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bd6:
	/* 0x3bd6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bdb:
	/* 0x3bdb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3be0:
	/* 0x3be0: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3be3:
	/* 0x3be3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be5:
	/* 0x3be5: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3be8:
	/* 0x3be8: jne    3cf9 <generic_sleepable_preload+0x3cf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cf9;
	}
x86_l_3bee:
	/* 0x3bee: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_3bf1:
	/* 0x3bf1: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bf5:
	/* 0x3bf5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3bfa:
	/* 0x3bfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bfc:
	/* 0x3bfc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c01:
	/* 0x3c01: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3c09:
	/* 0x3c09: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3c10:
	/* 0x3c10: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c15:
	/* 0x3c15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c1a:
	/* 0x3c1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1c:
	/* 0x3c1c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c1f:
	/* 0x3c1f: je     3cf6 <generic_sleepable_preload+0x3cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf6;
	}
x86_l_3c25:
	/* 0x3c25: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3c28:
	/* 0x3c28: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3c2f:
	/* 0x3c2f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c31:
	/* 0x3c31: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c36:
	/* 0x3c36: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3c3b:
	/* 0x3c3b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3c3e:
	/* 0x3c3e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3c41:
	/* 0x3c41: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c43:
	/* 0x3c43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c45:
	/* 0x3c45: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c4a:
	/* 0x3c4a: jmp    3cb5 <generic_sleepable_preload+0x3cb5> */
	goto x86_l_3cb5;
x86_l_3c4c:
	/* 0x3c4c: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3c51:
	/* 0x3c51: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c54:
	/* 0x3c54: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3c57:
	/* 0x3c57: jne    3cf9 <generic_sleepable_preload+0x3cf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cf9;
	}
x86_l_3c5d:
	/* 0x3c5d: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_3c60:
	/* 0x3c60: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c64:
	/* 0x3c64: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c69:
	/* 0x3c69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c6b:
	/* 0x3c6b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c70:
	/* 0x3c70: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3c78:
	/* 0x3c78: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3c7f:
	/* 0x3c7f: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c84:
	/* 0x3c84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c89:
	/* 0x3c89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c8b:
	/* 0x3c8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c8e:
	/* 0x3c8e: je     3cf6 <generic_sleepable_preload+0x3cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf6;
	}
x86_l_3c90:
	/* 0x3c90: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3c93:
	/* 0x3c93: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3c9a:
	/* 0x3c9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c9c:
	/* 0x3c9c: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ca1:
	/* 0x3ca1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ca6:
	/* 0x3ca6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3ca9:
	/* 0x3ca9: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3cac:
	/* 0x3cac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cae:
	/* 0x3cae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cb0:
	/* 0x3cb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cb5:
	/* 0x3cb5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3cb8:
	/* 0x3cb8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3cbb:
	/* 0x3cbb: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cc0:
	/* 0x3cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc2:
	/* 0x3cc2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cc5:
	/* 0x3cc5: je     3cf6 <generic_sleepable_preload+0x3cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf6;
	}
x86_l_3cc7:
	/* 0x3cc7: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_3cca:
	/* 0x3cca: je     3cf4 <generic_sleepable_preload+0x3cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf4;
	}
x86_l_3ccc:
	/* 0x3ccc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3ccf:
	/* 0x3ccf: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3cd3:
	/* 0x3cd3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3cd8:
	/* 0x3cd8: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3cdb:
	/* 0x3cdb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cdd:
	/* 0x3cdd: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3ce0:
	/* 0x3ce0: call   3ce5 <generic_sleepable_preload+0x3ce5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3ce5:
	/* 0x3ce5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3ce7:
	/* 0x3ce7: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_3cea:
	/* 0x3cea: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3cec:
	/* 0x3cec: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3cf1:
	/* 0x3cf1: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3cf4:
	/* 0x3cf4: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cf6:
	/* 0x3cf6: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_3cf9:
	/* 0x3cf9: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3cfe:
	/* 0x3cfe: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_3d03:
	/* 0x3d03: je     4c64 <generic_sleepable_preload+0x4c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19556ULL;
	}
x86_l_3d09:
	/* 0x3d09: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3d0b:
	/* 0x3d0b: js     3d40 <generic_sleepable_preload+0x3d40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d40;
	}
x86_l_3d0d:
	/* 0x3d0d: mov    eax,DWORD PTR [r12+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3d12:
	/* 0x3d12: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d15:
	/* 0x3d15: jle    3dc3 <generic_sleepable_preload+0x3dc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 15811ULL;
	}
x86_l_3d1b:
	/* 0x3d1b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d1e:
	/* 0x3d1e: je     3e2d <generic_sleepable_preload+0x3e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15917ULL;
	}
x86_l_3d24:
	/* 0x3d24: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3d27:
	/* 0x3d27: je     3e34 <generic_sleepable_preload+0x3e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15924ULL;
	}
x86_l_3d2d:
	/* 0x3d2d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d30:
	/* 0x3d30: jne    3e47 <generic_sleepable_preload+0x3e47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15943ULL;
	}
x86_l_3d36:
	/* 0x3d36: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d3b:
	/* 0x3d3b: jmp    3e40 <generic_sleepable_preload+0x3e40> */
	return 15936ULL;
x86_l_3d40:
	/* 0x3d40: movzx  eax,BYTE PTR [r12+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_3d49:
	/* 0x3d49: movzx  ecx,WORD PTR [r12+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_3d52:
	/* 0x3d52: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3d58:
	/* 0x3d58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d5a:
	/* 0x3d5a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3d5d:
	/* 0x3d5d: jle    3d9c <generic_sleepable_preload+0x3d9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3d9c;
	}
x86_l_3d5f:
	/* 0x3d5f: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3d62:
	/* 0x3d62: jle    3dd3 <generic_sleepable_preload+0x3dd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 15827ULL;
	}
x86_l_3d64:
	/* 0x3d64: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3d67:
	/* 0x3d67: jle    4496 <generic_sleepable_preload+0x4496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 17558ULL;
	}
x86_l_3d6d:
	/* 0x3d6d: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d72:
	/* 0x3d72: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3d75:
	/* 0x3d75: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17595ULL;
	}
x86_l_3d7b:
	/* 0x3d7b: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3d80:
	/* 0x3d80: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3d83:
	/* 0x3d83: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17595ULL;
	}
x86_l_3d89:
	/* 0x3d89: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3d8e:
	/* 0x3d8e: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3d91:
	/* 0x3d91: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17595ULL;
	}
x86_l_3d97:
	/* 0x3d97: jmp    44ce <generic_sleepable_preload+0x44ce> */
	return 17614ULL;
x86_l_3d9c:
	/* 0x3d9c: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3d9f:
	/* 0x3d9f: jg     3e00 <generic_sleepable_preload+0x3e00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 15872ULL;
	}
x86_l_3da1:
	/* 0x3da1: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3da4:
	/* 0x3da4: jg     4467 <generic_sleepable_preload+0x4467> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17511ULL;
	}
x86_l_3daa:
	/* 0x3daa: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3dac:
	/* 0x3dac: je     44b6 <generic_sleepable_preload+0x44b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17590ULL;
	}
x86_l_3db2:
	/* 0x3db2: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3db5:
	/* 0x3db5: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3db8:
	/* 0x3db8: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17595ULL;
	}
x86_l_3dbe:
	/* 0x3dbe: jmp    44ce <generic_sleepable_preload+0x44ce> */
	return 17614ULL;
	return 15811ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15811ULL: goto x86_l_3dc3;
	case 15813ULL: goto x86_l_3dc5;
	case 15815ULL: goto x86_l_3dc7;
	case 15818ULL: goto x86_l_3dca;
	case 15820ULL: goto x86_l_3dcc;
	case 15825ULL: goto x86_l_3dd1;
	case 15827ULL: goto x86_l_3dd3;
	case 15830ULL: goto x86_l_3dd6;
	case 15836ULL: goto x86_l_3ddc;
	case 15844ULL: goto x86_l_3de4;
	case 15847ULL: goto x86_l_3de7;
	case 15853ULL: goto x86_l_3ded;
	case 15858ULL: goto x86_l_3df2;
	case 15861ULL: goto x86_l_3df5;
	case 15867ULL: goto x86_l_3dfb;
	case 15872ULL: goto x86_l_3e00;
	case 15875ULL: goto x86_l_3e03;
	case 15881ULL: goto x86_l_3e09;
	case 15889ULL: goto x86_l_3e11;
	case 15892ULL: goto x86_l_3e14;
	case 15898ULL: goto x86_l_3e1a;
	case 15903ULL: goto x86_l_3e1f;
	case 15906ULL: goto x86_l_3e22;
	case 15912ULL: goto x86_l_3e28;
	case 15917ULL: goto x86_l_3e2d;
	case 15922ULL: goto x86_l_3e32;
	case 15924ULL: goto x86_l_3e34;
	case 15929ULL: goto x86_l_3e39;
	case 15931ULL: goto x86_l_3e3b;
	case 15936ULL: goto x86_l_3e40;
	case 15939ULL: goto x86_l_3e43;
	case 15943ULL: goto x86_l_3e47;
	case 15945ULL: goto x86_l_3e49;
	case 15948ULL: goto x86_l_3e4c;
	case 15958ULL: goto x86_l_3e56;
	case 15964ULL: goto x86_l_3e5c;
	case 15971ULL: goto x86_l_3e63;
	case 15974ULL: goto x86_l_3e66;
	case 15982ULL: goto x86_l_3e6e;
	case 15985ULL: goto x86_l_3e71;
	case 15989ULL: goto x86_l_3e75;
	case 15998ULL: goto x86_l_3e7e;
	case 16000ULL: goto x86_l_3e80;
	case 16006ULL: goto x86_l_3e86;
	case 16009ULL: goto x86_l_3e89;
	case 16011ULL: goto x86_l_3e8b;
	case 16014ULL: goto x86_l_3e8e;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16028ULL: goto x86_l_3e9c;
	case 16033ULL: goto x86_l_3ea1;
	case 16035ULL: goto x86_l_3ea3;
	case 16037ULL: goto x86_l_3ea5;
	case 16043ULL: goto x86_l_3eab;
	case 16053ULL: goto x86_l_3eb5;
	case 16059ULL: goto x86_l_3ebb;
	case 16067ULL: goto x86_l_3ec3;
	case 16071ULL: goto x86_l_3ec7;
	case 16075ULL: goto x86_l_3ecb;
	case 16085ULL: goto x86_l_3ed5;
	case 16087ULL: goto x86_l_3ed7;
	case 16090ULL: goto x86_l_3eda;
	case 16095ULL: goto x86_l_3edf;
	case 16100ULL: goto x86_l_3ee4;
	case 16104ULL: goto x86_l_3ee8;
	case 16109ULL: goto x86_l_3eed;
	case 16111ULL: goto x86_l_3eef;
	case 16113ULL: goto x86_l_3ef1;
	case 16119ULL: goto x86_l_3ef7;
	case 16129ULL: goto x86_l_3f01;
	case 16135ULL: goto x86_l_3f07;
	case 16143ULL: goto x86_l_3f0f;
	case 16147ULL: goto x86_l_3f13;
	case 16151ULL: goto x86_l_3f17;
	case 16161ULL: goto x86_l_3f21;
	case 16163ULL: goto x86_l_3f23;
	case 16166ULL: goto x86_l_3f26;
	case 16171ULL: goto x86_l_3f2b;
	case 16176ULL: goto x86_l_3f30;
	case 16180ULL: goto x86_l_3f34;
	case 16185ULL: goto x86_l_3f39;
	case 16187ULL: goto x86_l_3f3b;
	case 16189ULL: goto x86_l_3f3d;
	case 16195ULL: goto x86_l_3f43;
	case 16205ULL: goto x86_l_3f4d;
	case 16211ULL: goto x86_l_3f53;
	case 16219ULL: goto x86_l_3f5b;
	case 16223ULL: goto x86_l_3f5f;
	case 16227ULL: goto x86_l_3f63;
	case 16237ULL: goto x86_l_3f6d;
	case 16239ULL: goto x86_l_3f6f;
	case 16242ULL: goto x86_l_3f72;
	case 16247ULL: goto x86_l_3f77;
	case 16252ULL: goto x86_l_3f7c;
	case 16256ULL: goto x86_l_3f80;
	case 16261ULL: goto x86_l_3f85;
	case 16263ULL: goto x86_l_3f87;
	case 16265ULL: goto x86_l_3f89;
	case 16271ULL: goto x86_l_3f8f;
	case 16281ULL: goto x86_l_3f99;
	case 16287ULL: goto x86_l_3f9f;
	case 16295ULL: goto x86_l_3fa7;
	case 16299ULL: goto x86_l_3fab;
	case 16303ULL: goto x86_l_3faf;
	case 16313ULL: goto x86_l_3fb9;
	case 16315ULL: goto x86_l_3fbb;
	case 16318ULL: goto x86_l_3fbe;
	case 16323ULL: goto x86_l_3fc3;
	case 16328ULL: goto x86_l_3fc8;
	case 16332ULL: goto x86_l_3fcc;
	case 16337ULL: goto x86_l_3fd1;
	case 16339ULL: goto x86_l_3fd3;
	case 16341ULL: goto x86_l_3fd5;
	case 16347ULL: goto x86_l_3fdb;
	case 16357ULL: goto x86_l_3fe5;
	case 16363ULL: goto x86_l_3feb;
	case 16371ULL: goto x86_l_3ff3;
	case 16375ULL: goto x86_l_3ff7;
	case 16379ULL: goto x86_l_3ffb;
	case 16389ULL: goto x86_l_4005;
	case 16391ULL: goto x86_l_4007;
	case 16394ULL: goto x86_l_400a;
	case 16399ULL: goto x86_l_400f;
	case 16404ULL: goto x86_l_4014;
	case 16408ULL: goto x86_l_4018;
	case 16413ULL: goto x86_l_401d;
	case 16415ULL: goto x86_l_401f;
	case 16417ULL: goto x86_l_4021;
	case 16423ULL: goto x86_l_4027;
	case 16433ULL: goto x86_l_4031;
	case 16439ULL: goto x86_l_4037;
	case 16447ULL: goto x86_l_403f;
	case 16451ULL: goto x86_l_4043;
	case 16455ULL: goto x86_l_4047;
	case 16465ULL: goto x86_l_4051;
	case 16467ULL: goto x86_l_4053;
	case 16470ULL: goto x86_l_4056;
	case 16475ULL: goto x86_l_405b;
	case 16480ULL: goto x86_l_4060;
	case 16484ULL: goto x86_l_4064;
	case 16489ULL: goto x86_l_4069;
	case 16491ULL: goto x86_l_406b;
	case 16493ULL: goto x86_l_406d;
	case 16499ULL: goto x86_l_4073;
	case 16509ULL: goto x86_l_407d;
	case 16515ULL: goto x86_l_4083;
	case 16523ULL: goto x86_l_408b;
	case 16527ULL: goto x86_l_408f;
	case 16531ULL: goto x86_l_4093;
	case 16541ULL: goto x86_l_409d;
	case 16543ULL: goto x86_l_409f;
	case 16546ULL: goto x86_l_40a2;
	case 16551ULL: goto x86_l_40a7;
	case 16556ULL: goto x86_l_40ac;
	case 16560ULL: goto x86_l_40b0;
	case 16565ULL: goto x86_l_40b5;
	case 16567ULL: goto x86_l_40b7;
	case 16569ULL: goto x86_l_40b9;
	case 16575ULL: goto x86_l_40bf;
	case 16585ULL: goto x86_l_40c9;
	case 16591ULL: goto x86_l_40cf;
	case 16599ULL: goto x86_l_40d7;
	case 16603ULL: goto x86_l_40db;
	case 16607ULL: goto x86_l_40df;
	case 16617ULL: goto x86_l_40e9;
	case 16619ULL: goto x86_l_40eb;
	case 16622ULL: goto x86_l_40ee;
	case 16627ULL: goto x86_l_40f3;
	case 16632ULL: goto x86_l_40f8;
	case 16636ULL: goto x86_l_40fc;
	case 16641ULL: goto x86_l_4101;
	case 16643ULL: goto x86_l_4103;
	case 16645ULL: goto x86_l_4105;
	case 16651ULL: goto x86_l_410b;
	case 16656ULL: goto x86_l_4110;
	case 16666ULL: goto x86_l_411a;
	case 16672ULL: goto x86_l_4120;
	case 16680ULL: goto x86_l_4128;
	case 16684ULL: goto x86_l_412c;
	case 16688ULL: goto x86_l_4130;
	case 16698ULL: goto x86_l_413a;
	case 16704ULL: goto x86_l_4140;
	case 16707ULL: goto x86_l_4143;
	case 16712ULL: goto x86_l_4148;
	case 16717ULL: goto x86_l_414d;
	case 16722ULL: goto x86_l_4152;
	case 16725ULL: goto x86_l_4155;
	case 16727ULL: goto x86_l_4157;
	case 16730ULL: goto x86_l_415a;
	case 16735ULL: goto x86_l_415f;
	case 16740ULL: goto x86_l_4164;
	case 16744ULL: goto x86_l_4168;
	case 16749ULL: goto x86_l_416d;
	case 16751ULL: goto x86_l_416f;
	case 16753ULL: goto x86_l_4171;
	case 16759ULL: goto x86_l_4177;
	case 16769ULL: goto x86_l_4181;
	case 16775ULL: goto x86_l_4187;
	case 16783ULL: goto x86_l_418f;
	case 16787ULL: goto x86_l_4193;
	case 16791ULL: goto x86_l_4197;
	case 16801ULL: goto x86_l_41a1;
	case 16803ULL: goto x86_l_41a3;
	case 16806ULL: goto x86_l_41a6;
	case 16811ULL: goto x86_l_41ab;
	case 16816ULL: goto x86_l_41b0;
	case 16820ULL: goto x86_l_41b4;
	case 16825ULL: goto x86_l_41b9;
	case 16827ULL: goto x86_l_41bb;
	case 16829ULL: goto x86_l_41bd;
	case 16835ULL: goto x86_l_41c3;
	case 16845ULL: goto x86_l_41cd;
	case 16851ULL: goto x86_l_41d3;
	case 16859ULL: goto x86_l_41db;
	case 16863ULL: goto x86_l_41df;
	case 16867ULL: goto x86_l_41e3;
	case 16877ULL: goto x86_l_41ed;
	case 16879ULL: goto x86_l_41ef;
	case 16882ULL: goto x86_l_41f2;
	case 16887ULL: goto x86_l_41f7;
	case 16892ULL: goto x86_l_41fc;
	case 16896ULL: goto x86_l_4200;
	case 16901ULL: goto x86_l_4205;
	case 16903ULL: goto x86_l_4207;
	case 16905ULL: goto x86_l_4209;
	case 16911ULL: goto x86_l_420f;
	case 16921ULL: goto x86_l_4219;
	case 16927ULL: goto x86_l_421f;
	case 16935ULL: goto x86_l_4227;
	case 16939ULL: goto x86_l_422b;
	case 16943ULL: goto x86_l_422f;
	case 16953ULL: goto x86_l_4239;
	case 16955ULL: goto x86_l_423b;
	case 16958ULL: goto x86_l_423e;
	case 16963ULL: goto x86_l_4243;
	case 16968ULL: goto x86_l_4248;
	case 16972ULL: goto x86_l_424c;
	case 16977ULL: goto x86_l_4251;
	case 16979ULL: goto x86_l_4253;
	case 16981ULL: goto x86_l_4255;
	case 16987ULL: goto x86_l_425b;
	case 16997ULL: goto x86_l_4265;
	case 17003ULL: goto x86_l_426b;
	case 17011ULL: goto x86_l_4273;
	case 17015ULL: goto x86_l_4277;
	case 17019ULL: goto x86_l_427b;
	case 17029ULL: goto x86_l_4285;
	case 17031ULL: goto x86_l_4287;
	case 17034ULL: goto x86_l_428a;
	case 17039ULL: goto x86_l_428f;
	case 17044ULL: goto x86_l_4294;
	case 17048ULL: goto x86_l_4298;
	case 17053ULL: goto x86_l_429d;
	case 17055ULL: goto x86_l_429f;
	case 17057ULL: goto x86_l_42a1;
	case 17063ULL: goto x86_l_42a7;
	case 17073ULL: goto x86_l_42b1;
	case 17079ULL: goto x86_l_42b7;
	case 17087ULL: goto x86_l_42bf;
	case 17091ULL: goto x86_l_42c3;
	case 17095ULL: goto x86_l_42c7;
	case 17105ULL: goto x86_l_42d1;
	case 17107ULL: goto x86_l_42d3;
	case 17110ULL: goto x86_l_42d6;
	case 17115ULL: goto x86_l_42db;
	case 17120ULL: goto x86_l_42e0;
	case 17124ULL: goto x86_l_42e4;
	case 17129ULL: goto x86_l_42e9;
	case 17131ULL: goto x86_l_42eb;
	case 17133ULL: goto x86_l_42ed;
	case 17139ULL: goto x86_l_42f3;
	case 17149ULL: goto x86_l_42fd;
	case 17155ULL: goto x86_l_4303;
	case 17163ULL: goto x86_l_430b;
	case 17167ULL: goto x86_l_430f;
	case 17171ULL: goto x86_l_4313;
	case 17181ULL: goto x86_l_431d;
	case 17183ULL: goto x86_l_431f;
	case 17186ULL: goto x86_l_4322;
	case 17191ULL: goto x86_l_4327;
	case 17196ULL: goto x86_l_432c;
	case 17200ULL: goto x86_l_4330;
	case 17205ULL: goto x86_l_4335;
	case 17207ULL: goto x86_l_4337;
	case 17209ULL: goto x86_l_4339;
	case 17215ULL: goto x86_l_433f;
	case 17225ULL: goto x86_l_4349;
	case 17231ULL: goto x86_l_434f;
	case 17234ULL: goto x86_l_4352;
	case 17242ULL: goto x86_l_435a;
	case 17246ULL: goto x86_l_435e;
	case 17250ULL: goto x86_l_4362;
	case 17260ULL: goto x86_l_436c;
	case 17262ULL: goto x86_l_436e;
	case 17265ULL: goto x86_l_4371;
	case 17270ULL: goto x86_l_4376;
	case 17275ULL: goto x86_l_437b;
	case 17279ULL: goto x86_l_437f;
	case 17284ULL: goto x86_l_4384;
	case 17286ULL: goto x86_l_4386;
	case 17288ULL: goto x86_l_4388;
	case 17294ULL: goto x86_l_438e;
	case 17299ULL: goto x86_l_4393;
	case 17309ULL: goto x86_l_439d;
	case 17312ULL: goto x86_l_43a0;
	case 17318ULL: goto x86_l_43a6;
	case 17326ULL: goto x86_l_43ae;
	case 17330ULL: goto x86_l_43b2;
	case 17334ULL: goto x86_l_43b6;
	case 17344ULL: goto x86_l_43c0;
	case 17346ULL: goto x86_l_43c2;
	case 17349ULL: goto x86_l_43c5;
	case 17354ULL: goto x86_l_43ca;
	case 17359ULL: goto x86_l_43cf;
	case 17363ULL: goto x86_l_43d3;
	case 17368ULL: goto x86_l_43d8;
	case 17370ULL: goto x86_l_43da;
	case 17372ULL: goto x86_l_43dc;
	case 17378ULL: goto x86_l_43e2;
	case 17383ULL: goto x86_l_43e7;
	case 17393ULL: goto x86_l_43f1;
	case 17396ULL: goto x86_l_43f4;
	case 17402ULL: goto x86_l_43fa;
	case 17410ULL: goto x86_l_4402;
	case 17414ULL: goto x86_l_4406;
	case 17418ULL: goto x86_l_440a;
	case 17428ULL: goto x86_l_4414;
	case 17434ULL: goto x86_l_441a;
	case 17437ULL: goto x86_l_441d;
	case 17442ULL: goto x86_l_4422;
	case 17447ULL: goto x86_l_4427;
	case 17451ULL: goto x86_l_442b;
	case 17456ULL: goto x86_l_4430;
	case 17458ULL: goto x86_l_4432;
	case 17460ULL: goto x86_l_4434;
	case 17466ULL: goto x86_l_443a;
	case 17471ULL: goto x86_l_443f;
	case 17476ULL: goto x86_l_4444;
	case 17481ULL: goto x86_l_4449;
	case 17486ULL: goto x86_l_444e;
	case 17494ULL: goto x86_l_4456;
	case 17497ULL: goto x86_l_4459;
	case 17499ULL: goto x86_l_445b;
	case 17504ULL: goto x86_l_4460;
	case 17507ULL: goto x86_l_4463;
	case 17509ULL: goto x86_l_4465;
	case 17511ULL: goto x86_l_4467;
	case 17516ULL: goto x86_l_446c;
	case 17519ULL: goto x86_l_446f;
	case 17521ULL: goto x86_l_4471;
	case 17526ULL: goto x86_l_4476;
	case 17529ULL: goto x86_l_4479;
	case 17531ULL: goto x86_l_447b;
	case 17533ULL: goto x86_l_447d;
	case 17541ULL: goto x86_l_4485;
	case 17544ULL: goto x86_l_4488;
	case 17546ULL: goto x86_l_448a;
	case 17551ULL: goto x86_l_448f;
	case 17554ULL: goto x86_l_4492;
	case 17556ULL: goto x86_l_4494;
	case 17558ULL: goto x86_l_4496;
	case 17563ULL: goto x86_l_449b;
	case 17566ULL: goto x86_l_449e;
	case 17568ULL: goto x86_l_44a0;
	case 17573ULL: goto x86_l_44a5;
	case 17576ULL: goto x86_l_44a8;
	case 17578ULL: goto x86_l_44aa;
	case 17580ULL: goto x86_l_44ac;
	case 17585ULL: goto x86_l_44b1;
	case 17590ULL: goto x86_l_44b6;
	case 17595ULL: goto x86_l_44bb;
	case 17598ULL: goto x86_l_44be;
	case 17600ULL: goto x86_l_44c0;
	case 17602ULL: goto x86_l_44c2;
	case 17607ULL: goto x86_l_44c7;
	case 17609ULL: goto x86_l_44c9;
	case 17614ULL: goto x86_l_44ce;
	case 17618ULL: goto x86_l_44d2;
	case 17623ULL: goto x86_l_44d7;
	case 17625ULL: goto x86_l_44d9;
	case 17628ULL: goto x86_l_44dc;
	case 17638ULL: goto x86_l_44e6;
	case 17644ULL: goto x86_l_44ec;
	case 17651ULL: goto x86_l_44f3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3dc3:
	/* 0x3dc3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3dc5:
	/* 0x3dc5: je     3e3b <generic_sleepable_preload+0x3e3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e3b;
	}
x86_l_3dc7:
	/* 0x3dc7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3dca:
	/* 0x3dca: jne    3e47 <generic_sleepable_preload+0x3e47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e47;
	}
x86_l_3dcc:
	/* 0x3dcc: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3dd1:
	/* 0x3dd1: jmp    3e40 <generic_sleepable_preload+0x3e40> */
	goto x86_l_3e40;
x86_l_3dd3:
	/* 0x3dd3: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3dd6:
	/* 0x3dd6: jg     444e <generic_sleepable_preload+0x444e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_444e;
	}
x86_l_3ddc:
	/* 0x3ddc: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3de4:
	/* 0x3de4: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3de7:
	/* 0x3de7: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_3ded:
	/* 0x3ded: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3df2:
	/* 0x3df2: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3df5:
	/* 0x3df5: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_3dfb:
	/* 0x3dfb: jmp    44ce <generic_sleepable_preload+0x44ce> */
	goto x86_l_44ce;
x86_l_3e00:
	/* 0x3e00: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e03:
	/* 0x3e03: jg     447d <generic_sleepable_preload+0x447d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_447d;
	}
x86_l_3e09:
	/* 0x3e09: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3e11:
	/* 0x3e11: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3e14:
	/* 0x3e14: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_3e1a:
	/* 0x3e1a: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3e1f:
	/* 0x3e1f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3e22:
	/* 0x3e22: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_3e28:
	/* 0x3e28: jmp    44ce <generic_sleepable_preload+0x44ce> */
	goto x86_l_44ce;
x86_l_3e2d:
	/* 0x3e2d: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3e32:
	/* 0x3e32: jmp    3e40 <generic_sleepable_preload+0x3e40> */
	goto x86_l_3e40;
x86_l_3e34:
	/* 0x3e34: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e39:
	/* 0x3e39: jmp    3e40 <generic_sleepable_preload+0x3e40> */
	goto x86_l_3e40;
x86_l_3e3b:
	/* 0x3e3b: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e40:
	/* 0x3e40: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e43:
	/* 0x3e43: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e47:
	/* 0x3e47: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e49:
	/* 0x3e49: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3e4c:
	/* 0x3e4c: cmp    WORD PTR [r12+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_3e56:
	/* 0x3e56: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_3e5c:
	/* 0x3e5c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3e63:
	/* 0x3e63: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3e66:
	/* 0x3e66: mov    eax,DWORD PTR [r12+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3e6e:
	/* 0x3e6e: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e71:
	/* 0x3e71: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e75:
	/* 0x3e75: movzx  eax,WORD PTR [r12+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_3e7e:
	/* 0x3e7e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3e80:
	/* 0x3e80: je     4152 <generic_sleepable_preload+0x4152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4152;
	}
x86_l_3e86:
	/* 0x3e86: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3e89:
	/* 0x3e89: je     3eab <generic_sleepable_preload+0x3eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eab;
	}
x86_l_3e8b:
	/* 0x3e8b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3e8e:
	/* 0x3e8e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e93:
	/* 0x3e93: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e98:
	/* 0x3e98: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e9c:
	/* 0x3e9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ea1:
	/* 0x3ea1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ea3:
	/* 0x3ea3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ea5:
	/* 0x3ea5: js     4444 <generic_sleepable_preload+0x4444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4444;
	}
x86_l_3eab:
	/* 0x3eab: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_3eb5:
	/* 0x3eb5: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_3ebb:
	/* 0x3ebb: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3ec3:
	/* 0x3ec3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ec7:
	/* 0x3ec7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ecb:
	/* 0x3ecb: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3ed5:
	/* 0x3ed5: je     3ef7 <generic_sleepable_preload+0x3ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ef7;
	}
x86_l_3ed7:
	/* 0x3ed7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3eda:
	/* 0x3eda: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3edf:
	/* 0x3edf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ee4:
	/* 0x3ee4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee8:
	/* 0x3ee8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3eed:
	/* 0x3eed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eef:
	/* 0x3eef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ef1:
	/* 0x3ef1: js     44ac <generic_sleepable_preload+0x44ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_44ac;
	}
x86_l_3ef7:
	/* 0x3ef7: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3f01:
	/* 0x3f01: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_3f07:
	/* 0x3f07: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3f0f:
	/* 0x3f0f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f13:
	/* 0x3f13: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f17:
	/* 0x3f17: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3f21:
	/* 0x3f21: je     3f43 <generic_sleepable_preload+0x3f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f43;
	}
x86_l_3f23:
	/* 0x3f23: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f26:
	/* 0x3f26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f2b:
	/* 0x3f2b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f30:
	/* 0x3f30: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f34:
	/* 0x3f34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f39:
	/* 0x3f39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f3b:
	/* 0x3f3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f3d:
	/* 0x3f3d: js     4ae8 <generic_sleepable_preload+0x4ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19176ULL;
	}
x86_l_3f43:
	/* 0x3f43: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3f4d:
	/* 0x3f4d: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_3f53:
	/* 0x3f53: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3f5b:
	/* 0x3f5b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f5f:
	/* 0x3f5f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f63:
	/* 0x3f63: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3f6d:
	/* 0x3f6d: je     3f8f <generic_sleepable_preload+0x3f8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f8f;
	}
x86_l_3f6f:
	/* 0x3f6f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f72:
	/* 0x3f72: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3f77:
	/* 0x3f77: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f7c:
	/* 0x3f7c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f80:
	/* 0x3f80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f85:
	/* 0x3f85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f87:
	/* 0x3f87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f89:
	/* 0x3f89: js     4af9 <generic_sleepable_preload+0x4af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19193ULL;
	}
x86_l_3f8f:
	/* 0x3f8f: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_3f99:
	/* 0x3f99: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_3f9f:
	/* 0x3f9f: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_3fa7:
	/* 0x3fa7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3fab:
	/* 0x3fab: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3faf:
	/* 0x3faf: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_3fb9:
	/* 0x3fb9: je     3fdb <generic_sleepable_preload+0x3fdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fdb;
	}
x86_l_3fbb:
	/* 0x3fbb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fbe:
	/* 0x3fbe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3fc3:
	/* 0x3fc3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3fc8:
	/* 0x3fc8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fcc:
	/* 0x3fcc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fd1:
	/* 0x3fd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fd3:
	/* 0x3fd3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fd5:
	/* 0x3fd5: js     4b0a <generic_sleepable_preload+0x4b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19210ULL;
	}
x86_l_3fdb:
	/* 0x3fdb: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3fe5:
	/* 0x3fe5: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_3feb:
	/* 0x3feb: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3ff3:
	/* 0x3ff3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ff7:
	/* 0x3ff7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ffb:
	/* 0x3ffb: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4005:
	/* 0x4005: je     4027 <generic_sleepable_preload+0x4027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4027;
	}
x86_l_4007:
	/* 0x4007: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_400a:
	/* 0x400a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_400f:
	/* 0x400f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4014:
	/* 0x4014: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4018:
	/* 0x4018: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_401d:
	/* 0x401d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_401f:
	/* 0x401f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4021:
	/* 0x4021: js     4b1b <generic_sleepable_preload+0x4b1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19227ULL;
	}
x86_l_4027:
	/* 0x4027: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4031:
	/* 0x4031: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_4037:
	/* 0x4037: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_403f:
	/* 0x403f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4043:
	/* 0x4043: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4047:
	/* 0x4047: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4051:
	/* 0x4051: je     4073 <generic_sleepable_preload+0x4073> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4073;
	}
x86_l_4053:
	/* 0x4053: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4056:
	/* 0x4056: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_405b:
	/* 0x405b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4060:
	/* 0x4060: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4064:
	/* 0x4064: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4069:
	/* 0x4069: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406b:
	/* 0x406b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_406d:
	/* 0x406d: js     4b2c <generic_sleepable_preload+0x4b2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19244ULL;
	}
x86_l_4073:
	/* 0x4073: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_407d:
	/* 0x407d: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_4083:
	/* 0x4083: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_408b:
	/* 0x408b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_408f:
	/* 0x408f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4093:
	/* 0x4093: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_409d:
	/* 0x409d: je     40bf <generic_sleepable_preload+0x40bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40bf;
	}
x86_l_409f:
	/* 0x409f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40a2:
	/* 0x40a2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40a7:
	/* 0x40a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40ac:
	/* 0x40ac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40b0:
	/* 0x40b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40b5:
	/* 0x40b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b7:
	/* 0x40b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40b9:
	/* 0x40b9: js     5c0d <generic_sleepable_preload+0x5c0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23565ULL;
	}
x86_l_40bf:
	/* 0x40bf: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_40c9:
	/* 0x40c9: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_40cf:
	/* 0x40cf: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_40d7:
	/* 0x40d7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_40db:
	/* 0x40db: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40df:
	/* 0x40df: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_40e9:
	/* 0x40e9: je     410b <generic_sleepable_preload+0x410b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_410b;
	}
x86_l_40eb:
	/* 0x40eb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40ee:
	/* 0x40ee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40f3:
	/* 0x40f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40f8:
	/* 0x40f8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40fc:
	/* 0x40fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4101:
	/* 0x4101: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4103:
	/* 0x4103: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4105:
	/* 0x4105: js     5d11 <generic_sleepable_preload+0x5d11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23825ULL;
	}
x86_l_410b:
	/* 0x410b: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4110:
	/* 0x4110: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_411a:
	/* 0x411a: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_4120:
	/* 0x4120: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4128:
	/* 0x4128: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_412c:
	/* 0x412c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4130:
	/* 0x4130: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_413a:
	/* 0x413a: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_4140:
	/* 0x4140: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4143:
	/* 0x4143: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4148:
	/* 0x4148: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_414d:
	/* 0x414d: jmp    4427 <generic_sleepable_preload+0x4427> */
	goto x86_l_4427;
x86_l_4152:
	/* 0x4152: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4155:
	/* 0x4155: je     4177 <generic_sleepable_preload+0x4177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4177;
	}
x86_l_4157:
	/* 0x4157: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_415a:
	/* 0x415a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_415f:
	/* 0x415f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4164:
	/* 0x4164: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4168:
	/* 0x4168: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_416d:
	/* 0x416d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_416f:
	/* 0x416f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4171:
	/* 0x4171: js     4444 <generic_sleepable_preload+0x4444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4444;
	}
x86_l_4177:
	/* 0x4177: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4181:
	/* 0x4181: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_4187:
	/* 0x4187: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_418f:
	/* 0x418f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4193:
	/* 0x4193: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4197:
	/* 0x4197: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_41a1:
	/* 0x41a1: je     41c3 <generic_sleepable_preload+0x41c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41c3;
	}
x86_l_41a3:
	/* 0x41a3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41a6:
	/* 0x41a6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41ab:
	/* 0x41ab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41b0:
	/* 0x41b0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41b4:
	/* 0x41b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41b9:
	/* 0x41b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41bb:
	/* 0x41bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41bd:
	/* 0x41bd: js     44ac <generic_sleepable_preload+0x44ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_44ac;
	}
x86_l_41c3:
	/* 0x41c3: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_41cd:
	/* 0x41cd: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_41d3:
	/* 0x41d3: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_41db:
	/* 0x41db: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_41df:
	/* 0x41df: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e3:
	/* 0x41e3: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_41ed:
	/* 0x41ed: je     420f <generic_sleepable_preload+0x420f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_420f;
	}
x86_l_41ef:
	/* 0x41ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41f2:
	/* 0x41f2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41f7:
	/* 0x41f7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41fc:
	/* 0x41fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4200:
	/* 0x4200: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4205:
	/* 0x4205: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4207:
	/* 0x4207: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4209:
	/* 0x4209: js     4ae8 <generic_sleepable_preload+0x4ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19176ULL;
	}
x86_l_420f:
	/* 0x420f: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4219:
	/* 0x4219: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_421f:
	/* 0x421f: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4227:
	/* 0x4227: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_422b:
	/* 0x422b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_422f:
	/* 0x422f: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4239:
	/* 0x4239: je     425b <generic_sleepable_preload+0x425b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_425b;
	}
x86_l_423b:
	/* 0x423b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_423e:
	/* 0x423e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4243:
	/* 0x4243: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4248:
	/* 0x4248: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_424c:
	/* 0x424c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4251:
	/* 0x4251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4253:
	/* 0x4253: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4255:
	/* 0x4255: js     4af9 <generic_sleepable_preload+0x4af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19193ULL;
	}
x86_l_425b:
	/* 0x425b: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4265:
	/* 0x4265: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_426b:
	/* 0x426b: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4273:
	/* 0x4273: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4277:
	/* 0x4277: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_427b:
	/* 0x427b: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4285:
	/* 0x4285: je     42a7 <generic_sleepable_preload+0x42a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a7;
	}
x86_l_4287:
	/* 0x4287: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_428a:
	/* 0x428a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_428f:
	/* 0x428f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4294:
	/* 0x4294: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4298:
	/* 0x4298: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_429d:
	/* 0x429d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_429f:
	/* 0x429f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a1:
	/* 0x42a1: js     4b0a <generic_sleepable_preload+0x4b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19210ULL;
	}
x86_l_42a7:
	/* 0x42a7: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_42b1:
	/* 0x42b1: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_42b7:
	/* 0x42b7: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_42bf:
	/* 0x42bf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42c3:
	/* 0x42c3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42c7:
	/* 0x42c7: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_42d1:
	/* 0x42d1: je     42f3 <generic_sleepable_preload+0x42f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42f3;
	}
x86_l_42d3:
	/* 0x42d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42d6:
	/* 0x42d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42db:
	/* 0x42db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42e0:
	/* 0x42e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42e4:
	/* 0x42e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42e9:
	/* 0x42e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42eb:
	/* 0x42eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42ed:
	/* 0x42ed: js     4b1b <generic_sleepable_preload+0x4b1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19227ULL;
	}
x86_l_42f3:
	/* 0x42f3: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_42fd:
	/* 0x42fd: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_4303:
	/* 0x4303: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_430b:
	/* 0x430b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_430f:
	/* 0x430f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4313:
	/* 0x4313: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_431d:
	/* 0x431d: je     433f <generic_sleepable_preload+0x433f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_433f;
	}
x86_l_431f:
	/* 0x431f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4322:
	/* 0x4322: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4327:
	/* 0x4327: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_432c:
	/* 0x432c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4330:
	/* 0x4330: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4335:
	/* 0x4335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4337:
	/* 0x4337: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4339:
	/* 0x4339: js     4b2c <generic_sleepable_preload+0x4b2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19244ULL;
	}
x86_l_433f:
	/* 0x433f: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4349:
	/* 0x4349: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_434f:
	/* 0x434f: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_4352:
	/* 0x4352: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_435a:
	/* 0x435a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_435e:
	/* 0x435e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4362:
	/* 0x4362: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_436c:
	/* 0x436c: je     438e <generic_sleepable_preload+0x438e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_438e;
	}
x86_l_436e:
	/* 0x436e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4371:
	/* 0x4371: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4376:
	/* 0x4376: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_437b:
	/* 0x437b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_437f:
	/* 0x437f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4384:
	/* 0x4384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4386:
	/* 0x4386: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4388:
	/* 0x4388: js     5c8b <generic_sleepable_preload+0x5c8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23691ULL;
	}
x86_l_438e:
	/* 0x438e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4393:
	/* 0x4393: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_439d:
	/* 0x439d: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_43a0:
	/* 0x43a0: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_43a6:
	/* 0x43a6: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_43ae:
	/* 0x43ae: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_43b2:
	/* 0x43b2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43b6:
	/* 0x43b6: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_43c0:
	/* 0x43c0: je     43e2 <generic_sleepable_preload+0x43e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e2;
	}
x86_l_43c2:
	/* 0x43c2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_43c5:
	/* 0x43c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43ca:
	/* 0x43ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43cf:
	/* 0x43cf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43d3:
	/* 0x43d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43d8:
	/* 0x43d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43da:
	/* 0x43da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43dc:
	/* 0x43dc: js     5db3 <generic_sleepable_preload+0x5db3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23987ULL;
	}
x86_l_43e2:
	/* 0x43e2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43e7:
	/* 0x43e7: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_43f1:
	/* 0x43f1: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_43f4:
	/* 0x43f4: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_43fa:
	/* 0x43fa: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4402:
	/* 0x4402: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4406:
	/* 0x4406: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_440a:
	/* 0x440a: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4414:
	/* 0x4414: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19252ULL;
	}
x86_l_441a:
	/* 0x441a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_441d:
	/* 0x441d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4422:
	/* 0x4422: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4427:
	/* 0x4427: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_442b:
	/* 0x442b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4430:
	/* 0x4430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4432:
	/* 0x4432: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4434:
	/* 0x4434: jns    4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 19252ULL;
	}
x86_l_443a:
	/* 0x443a: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_443f:
	/* 0x443f: jmp    4b31 <generic_sleepable_preload+0x4b31> */
	return 19249ULL;
x86_l_4444:
	/* 0x4444: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4449:
	/* 0x4449: jmp    4b31 <generic_sleepable_preload+0x4b31> */
	return 19249ULL;
x86_l_444e:
	/* 0x444e: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4456:
	/* 0x4456: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_4459:
	/* 0x4459: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_445b:
	/* 0x445b: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4460:
	/* 0x4460: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4463:
	/* 0x4463: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_4465:
	/* 0x4465: jmp    44ce <generic_sleepable_preload+0x44ce> */
	goto x86_l_44ce;
x86_l_4467:
	/* 0x4467: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_446c:
	/* 0x446c: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_446f:
	/* 0x446f: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_4471:
	/* 0x4471: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4476:
	/* 0x4476: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4479:
	/* 0x4479: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_447b:
	/* 0x447b: jmp    44ce <generic_sleepable_preload+0x44ce> */
	goto x86_l_44ce;
x86_l_447d:
	/* 0x447d: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4485:
	/* 0x4485: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4488:
	/* 0x4488: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_448a:
	/* 0x448a: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_448f:
	/* 0x448f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4492:
	/* 0x4492: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_4494:
	/* 0x4494: jmp    44ce <generic_sleepable_preload+0x44ce> */
	goto x86_l_44ce;
x86_l_4496:
	/* 0x4496: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_449b:
	/* 0x449b: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_449e:
	/* 0x449e: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_44a0:
	/* 0x44a0: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_44a5:
	/* 0x44a5: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_44a8:
	/* 0x44a8: je     44bb <generic_sleepable_preload+0x44bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44bb;
	}
x86_l_44aa:
	/* 0x44aa: jmp    44ce <generic_sleepable_preload+0x44ce> */
	goto x86_l_44ce;
x86_l_44ac:
	/* 0x44ac: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_44b1:
	/* 0x44b1: jmp    4b31 <generic_sleepable_preload+0x4b31> */
	return 19249ULL;
x86_l_44b6:
	/* 0x44b6: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_44bb:
	/* 0x44bb: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_44be:
	/* 0x44be: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_44c0:
	/* 0x44c0: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_44c2:
	/* 0x44c2: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_44c7:
	/* 0x44c7: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_44c9:
	/* 0x44c9: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_44ce:
	/* 0x44ce: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44d2:
	/* 0x44d2: mov    ebp,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d7:
	/* 0x44d7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44d9:
	/* 0x44d9: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_44dc:
	/* 0x44dc: cmp    WORD PTR [r12+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_44e6:
	/* 0x44e6: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19391ULL;
	}
x86_l_44ec:
	/* 0x44ec: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_44f3:
	/* 0x44f3: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
	return 17654ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17654ULL: goto x86_l_44f6;
	case 17662ULL: goto x86_l_44fe;
	case 17665ULL: goto x86_l_4501;
	case 17669ULL: goto x86_l_4505;
	case 17678ULL: goto x86_l_450e;
	case 17680ULL: goto x86_l_4510;
	case 17686ULL: goto x86_l_4516;
	case 17689ULL: goto x86_l_4519;
	case 17691ULL: goto x86_l_451b;
	case 17694ULL: goto x86_l_451e;
	case 17699ULL: goto x86_l_4523;
	case 17704ULL: goto x86_l_4528;
	case 17708ULL: goto x86_l_452c;
	case 17713ULL: goto x86_l_4531;
	case 17715ULL: goto x86_l_4533;
	case 17717ULL: goto x86_l_4535;
	case 17723ULL: goto x86_l_453b;
	case 17733ULL: goto x86_l_4545;
	case 17739ULL: goto x86_l_454b;
	case 17747ULL: goto x86_l_4553;
	case 17751ULL: goto x86_l_4557;
	case 17755ULL: goto x86_l_455b;
	case 17765ULL: goto x86_l_4565;
	case 17767ULL: goto x86_l_4567;
	case 17770ULL: goto x86_l_456a;
	case 17775ULL: goto x86_l_456f;
	case 17780ULL: goto x86_l_4574;
	case 17784ULL: goto x86_l_4578;
	case 17789ULL: goto x86_l_457d;
	case 17791ULL: goto x86_l_457f;
	case 17793ULL: goto x86_l_4581;
	case 17799ULL: goto x86_l_4587;
	case 17809ULL: goto x86_l_4591;
	case 17815ULL: goto x86_l_4597;
	case 17823ULL: goto x86_l_459f;
	case 17827ULL: goto x86_l_45a3;
	case 17831ULL: goto x86_l_45a7;
	case 17841ULL: goto x86_l_45b1;
	case 17843ULL: goto x86_l_45b3;
	case 17846ULL: goto x86_l_45b6;
	case 17851ULL: goto x86_l_45bb;
	case 17856ULL: goto x86_l_45c0;
	case 17860ULL: goto x86_l_45c4;
	case 17865ULL: goto x86_l_45c9;
	case 17867ULL: goto x86_l_45cb;
	case 17869ULL: goto x86_l_45cd;
	case 17875ULL: goto x86_l_45d3;
	case 17885ULL: goto x86_l_45dd;
	case 17891ULL: goto x86_l_45e3;
	case 17899ULL: goto x86_l_45eb;
	case 17903ULL: goto x86_l_45ef;
	case 17907ULL: goto x86_l_45f3;
	case 17917ULL: goto x86_l_45fd;
	case 17919ULL: goto x86_l_45ff;
	case 17922ULL: goto x86_l_4602;
	case 17927ULL: goto x86_l_4607;
	case 17932ULL: goto x86_l_460c;
	case 17936ULL: goto x86_l_4610;
	case 17941ULL: goto x86_l_4615;
	case 17943ULL: goto x86_l_4617;
	case 17945ULL: goto x86_l_4619;
	case 17951ULL: goto x86_l_461f;
	case 17961ULL: goto x86_l_4629;
	case 17967ULL: goto x86_l_462f;
	case 17975ULL: goto x86_l_4637;
	case 17979ULL: goto x86_l_463b;
	case 17983ULL: goto x86_l_463f;
	case 17993ULL: goto x86_l_4649;
	case 17995ULL: goto x86_l_464b;
	case 17998ULL: goto x86_l_464e;
	case 18003ULL: goto x86_l_4653;
	case 18008ULL: goto x86_l_4658;
	case 18012ULL: goto x86_l_465c;
	case 18017ULL: goto x86_l_4661;
	case 18019ULL: goto x86_l_4663;
	case 18021ULL: goto x86_l_4665;
	case 18027ULL: goto x86_l_466b;
	case 18037ULL: goto x86_l_4675;
	case 18043ULL: goto x86_l_467b;
	case 18051ULL: goto x86_l_4683;
	case 18055ULL: goto x86_l_4687;
	case 18059ULL: goto x86_l_468b;
	case 18069ULL: goto x86_l_4695;
	case 18071ULL: goto x86_l_4697;
	case 18074ULL: goto x86_l_469a;
	case 18079ULL: goto x86_l_469f;
	case 18084ULL: goto x86_l_46a4;
	case 18088ULL: goto x86_l_46a8;
	case 18093ULL: goto x86_l_46ad;
	case 18095ULL: goto x86_l_46af;
	case 18097ULL: goto x86_l_46b1;
	case 18103ULL: goto x86_l_46b7;
	case 18113ULL: goto x86_l_46c1;
	case 18119ULL: goto x86_l_46c7;
	case 18127ULL: goto x86_l_46cf;
	case 18131ULL: goto x86_l_46d3;
	case 18135ULL: goto x86_l_46d7;
	case 18145ULL: goto x86_l_46e1;
	case 18147ULL: goto x86_l_46e3;
	case 18150ULL: goto x86_l_46e6;
	case 18155ULL: goto x86_l_46eb;
	case 18160ULL: goto x86_l_46f0;
	case 18164ULL: goto x86_l_46f4;
	case 18169ULL: goto x86_l_46f9;
	case 18171ULL: goto x86_l_46fb;
	case 18173ULL: goto x86_l_46fd;
	case 18179ULL: goto x86_l_4703;
	case 18189ULL: goto x86_l_470d;
	case 18195ULL: goto x86_l_4713;
	case 18203ULL: goto x86_l_471b;
	case 18207ULL: goto x86_l_471f;
	case 18211ULL: goto x86_l_4723;
	case 18221ULL: goto x86_l_472d;
	case 18223ULL: goto x86_l_472f;
	case 18226ULL: goto x86_l_4732;
	case 18231ULL: goto x86_l_4737;
	case 18236ULL: goto x86_l_473c;
	case 18240ULL: goto x86_l_4740;
	case 18245ULL: goto x86_l_4745;
	case 18247ULL: goto x86_l_4747;
	case 18249ULL: goto x86_l_4749;
	case 18255ULL: goto x86_l_474f;
	case 18265ULL: goto x86_l_4759;
	case 18271ULL: goto x86_l_475f;
	case 18279ULL: goto x86_l_4767;
	case 18283ULL: goto x86_l_476b;
	case 18287ULL: goto x86_l_476f;
	case 18297ULL: goto x86_l_4779;
	case 18299ULL: goto x86_l_477b;
	case 18302ULL: goto x86_l_477e;
	case 18307ULL: goto x86_l_4783;
	case 18312ULL: goto x86_l_4788;
	case 18316ULL: goto x86_l_478c;
	case 18321ULL: goto x86_l_4791;
	case 18323ULL: goto x86_l_4793;
	case 18325ULL: goto x86_l_4795;
	case 18331ULL: goto x86_l_479b;
	case 18336ULL: goto x86_l_47a0;
	case 18346ULL: goto x86_l_47aa;
	case 18352ULL: goto x86_l_47b0;
	case 18360ULL: goto x86_l_47b8;
	case 18364ULL: goto x86_l_47bc;
	case 18368ULL: goto x86_l_47c0;
	case 18378ULL: goto x86_l_47ca;
	case 18384ULL: goto x86_l_47d0;
	case 18387ULL: goto x86_l_47d3;
	case 18392ULL: goto x86_l_47d8;
	case 18397ULL: goto x86_l_47dd;
	case 18402ULL: goto x86_l_47e2;
	case 18405ULL: goto x86_l_47e5;
	case 18407ULL: goto x86_l_47e7;
	case 18410ULL: goto x86_l_47ea;
	case 18415ULL: goto x86_l_47ef;
	case 18420ULL: goto x86_l_47f4;
	case 18424ULL: goto x86_l_47f8;
	case 18429ULL: goto x86_l_47fd;
	case 18431ULL: goto x86_l_47ff;
	case 18433ULL: goto x86_l_4801;
	case 18439ULL: goto x86_l_4807;
	case 18449ULL: goto x86_l_4811;
	case 18455ULL: goto x86_l_4817;
	case 18463ULL: goto x86_l_481f;
	case 18467ULL: goto x86_l_4823;
	case 18471ULL: goto x86_l_4827;
	case 18481ULL: goto x86_l_4831;
	case 18483ULL: goto x86_l_4833;
	case 18486ULL: goto x86_l_4836;
	case 18491ULL: goto x86_l_483b;
	case 18496ULL: goto x86_l_4840;
	case 18500ULL: goto x86_l_4844;
	case 18505ULL: goto x86_l_4849;
	case 18507ULL: goto x86_l_484b;
	case 18509ULL: goto x86_l_484d;
	case 18515ULL: goto x86_l_4853;
	case 18525ULL: goto x86_l_485d;
	case 18531ULL: goto x86_l_4863;
	case 18539ULL: goto x86_l_486b;
	case 18543ULL: goto x86_l_486f;
	case 18547ULL: goto x86_l_4873;
	case 18557ULL: goto x86_l_487d;
	case 18559ULL: goto x86_l_487f;
	case 18562ULL: goto x86_l_4882;
	case 18567ULL: goto x86_l_4887;
	case 18572ULL: goto x86_l_488c;
	case 18576ULL: goto x86_l_4890;
	case 18581ULL: goto x86_l_4895;
	case 18583ULL: goto x86_l_4897;
	case 18585ULL: goto x86_l_4899;
	case 18591ULL: goto x86_l_489f;
	case 18601ULL: goto x86_l_48a9;
	case 18607ULL: goto x86_l_48af;
	case 18615ULL: goto x86_l_48b7;
	case 18619ULL: goto x86_l_48bb;
	case 18623ULL: goto x86_l_48bf;
	case 18633ULL: goto x86_l_48c9;
	case 18635ULL: goto x86_l_48cb;
	case 18638ULL: goto x86_l_48ce;
	case 18643ULL: goto x86_l_48d3;
	case 18648ULL: goto x86_l_48d8;
	case 18652ULL: goto x86_l_48dc;
	case 18657ULL: goto x86_l_48e1;
	case 18659ULL: goto x86_l_48e3;
	case 18661ULL: goto x86_l_48e5;
	case 18667ULL: goto x86_l_48eb;
	case 18677ULL: goto x86_l_48f5;
	case 18683ULL: goto x86_l_48fb;
	case 18691ULL: goto x86_l_4903;
	case 18695ULL: goto x86_l_4907;
	case 18699ULL: goto x86_l_490b;
	case 18709ULL: goto x86_l_4915;
	case 18711ULL: goto x86_l_4917;
	case 18714ULL: goto x86_l_491a;
	case 18719ULL: goto x86_l_491f;
	case 18724ULL: goto x86_l_4924;
	case 18728ULL: goto x86_l_4928;
	case 18733ULL: goto x86_l_492d;
	case 18735ULL: goto x86_l_492f;
	case 18737ULL: goto x86_l_4931;
	case 18743ULL: goto x86_l_4937;
	case 18753ULL: goto x86_l_4941;
	case 18759ULL: goto x86_l_4947;
	case 18767ULL: goto x86_l_494f;
	case 18771ULL: goto x86_l_4953;
	case 18775ULL: goto x86_l_4957;
	case 18785ULL: goto x86_l_4961;
	case 18787ULL: goto x86_l_4963;
	case 18790ULL: goto x86_l_4966;
	case 18795ULL: goto x86_l_496b;
	case 18800ULL: goto x86_l_4970;
	case 18804ULL: goto x86_l_4974;
	case 18809ULL: goto x86_l_4979;
	case 18811ULL: goto x86_l_497b;
	case 18813ULL: goto x86_l_497d;
	case 18819ULL: goto x86_l_4983;
	case 18829ULL: goto x86_l_498d;
	case 18835ULL: goto x86_l_4993;
	case 18843ULL: goto x86_l_499b;
	case 18847ULL: goto x86_l_499f;
	case 18851ULL: goto x86_l_49a3;
	case 18861ULL: goto x86_l_49ad;
	case 18863ULL: goto x86_l_49af;
	case 18866ULL: goto x86_l_49b2;
	case 18871ULL: goto x86_l_49b7;
	case 18876ULL: goto x86_l_49bc;
	case 18880ULL: goto x86_l_49c0;
	case 18885ULL: goto x86_l_49c5;
	case 18887ULL: goto x86_l_49c7;
	case 18889ULL: goto x86_l_49c9;
	case 18895ULL: goto x86_l_49cf;
	case 18905ULL: goto x86_l_49d9;
	case 18911ULL: goto x86_l_49df;
	case 18914ULL: goto x86_l_49e2;
	case 18922ULL: goto x86_l_49ea;
	case 18926ULL: goto x86_l_49ee;
	case 18930ULL: goto x86_l_49f2;
	case 18940ULL: goto x86_l_49fc;
	case 18942ULL: goto x86_l_49fe;
	case 18945ULL: goto x86_l_4a01;
	case 18950ULL: goto x86_l_4a06;
	case 18955ULL: goto x86_l_4a0b;
	case 18959ULL: goto x86_l_4a0f;
	case 18964ULL: goto x86_l_4a14;
	case 18966ULL: goto x86_l_4a16;
	case 18968ULL: goto x86_l_4a18;
	case 18974ULL: goto x86_l_4a1e;
	case 18979ULL: goto x86_l_4a23;
	case 18989ULL: goto x86_l_4a2d;
	case 18992ULL: goto x86_l_4a30;
	case 18998ULL: goto x86_l_4a36;
	case 19006ULL: goto x86_l_4a3e;
	case 19010ULL: goto x86_l_4a42;
	case 19014ULL: goto x86_l_4a46;
	case 19024ULL: goto x86_l_4a50;
	case 19026ULL: goto x86_l_4a52;
	case 19029ULL: goto x86_l_4a55;
	case 19034ULL: goto x86_l_4a5a;
	case 19039ULL: goto x86_l_4a5f;
	case 19043ULL: goto x86_l_4a63;
	case 19048ULL: goto x86_l_4a68;
	case 19050ULL: goto x86_l_4a6a;
	case 19052ULL: goto x86_l_4a6c;
	case 19058ULL: goto x86_l_4a72;
	case 19063ULL: goto x86_l_4a77;
	case 19073ULL: goto x86_l_4a81;
	case 19076ULL: goto x86_l_4a84;
	case 19082ULL: goto x86_l_4a8a;
	case 19090ULL: goto x86_l_4a92;
	case 19094ULL: goto x86_l_4a96;
	case 19098ULL: goto x86_l_4a9a;
	case 19108ULL: goto x86_l_4aa4;
	case 19114ULL: goto x86_l_4aaa;
	case 19117ULL: goto x86_l_4aad;
	case 19122ULL: goto x86_l_4ab2;
	case 19127ULL: goto x86_l_4ab7;
	case 19131ULL: goto x86_l_4abb;
	case 19136ULL: goto x86_l_4ac0;
	case 19138ULL: goto x86_l_4ac2;
	case 19140ULL: goto x86_l_4ac4;
	case 19146ULL: goto x86_l_4aca;
	case 19151ULL: goto x86_l_4acf;
	case 19156ULL: goto x86_l_4ad4;
	case 19161ULL: goto x86_l_4ad9;
	case 19166ULL: goto x86_l_4ade;
	case 19171ULL: goto x86_l_4ae3;
	case 19176ULL: goto x86_l_4ae8;
	case 19181ULL: goto x86_l_4aed;
	case 19183ULL: goto x86_l_4aef;
	case 19188ULL: goto x86_l_4af4;
	case 19193ULL: goto x86_l_4af9;
	case 19198ULL: goto x86_l_4afe;
	case 19200ULL: goto x86_l_4b00;
	case 19205ULL: goto x86_l_4b05;
	case 19210ULL: goto x86_l_4b0a;
	case 19215ULL: goto x86_l_4b0f;
	case 19217ULL: goto x86_l_4b11;
	case 19222ULL: goto x86_l_4b16;
	case 19227ULL: goto x86_l_4b1b;
	case 19232ULL: goto x86_l_4b20;
	case 19234ULL: goto x86_l_4b22;
	case 19239ULL: goto x86_l_4b27;
	case 19244ULL: goto x86_l_4b2c;
	case 19249ULL: goto x86_l_4b31;
	case 19252ULL: goto x86_l_4b34;
	case 19257ULL: goto x86_l_4b39;
	case 19260ULL: goto x86_l_4b3c;
	case 19265ULL: goto x86_l_4b41;
	case 19270ULL: goto x86_l_4b46;
	case 19275ULL: goto x86_l_4b4b;
	case 19278ULL: goto x86_l_4b4e;
	case 19280ULL: goto x86_l_4b50;
	case 19283ULL: goto x86_l_4b53;
	case 19289ULL: goto x86_l_4b59;
	case 19292ULL: goto x86_l_4b5c;
	case 19296ULL: goto x86_l_4b60;
	case 19301ULL: goto x86_l_4b65;
	case 19303ULL: goto x86_l_4b67;
	case 19308ULL: goto x86_l_4b6c;
	case 19316ULL: goto x86_l_4b74;
	case 19323ULL: goto x86_l_4b7b;
	case 19328ULL: goto x86_l_4b80;
	case 19333ULL: goto x86_l_4b85;
	case 19335ULL: goto x86_l_4b87;
	case 19338ULL: goto x86_l_4b8a;
	case 19344ULL: goto x86_l_4b90;
	case 19347ULL: goto x86_l_4b93;
	case 19354ULL: goto x86_l_4b9a;
	case 19356ULL: goto x86_l_4b9c;
	case 19361ULL: goto x86_l_4ba1;
	case 19366ULL: goto x86_l_4ba6;
	case 19369ULL: goto x86_l_4ba9;
	case 19372ULL: goto x86_l_4bac;
	case 19374ULL: goto x86_l_4bae;
	case 19376ULL: goto x86_l_4bb0;
	case 19381ULL: goto x86_l_4bb5;
	case 19383ULL: goto x86_l_4bb7;
	case 19388ULL: goto x86_l_4bbc;
	case 19391ULL: goto x86_l_4bbf;
	case 19394ULL: goto x86_l_4bc2;
	case 19400ULL: goto x86_l_4bc8;
	case 19403ULL: goto x86_l_4bcb;
	case 19407ULL: goto x86_l_4bcf;
	case 19412ULL: goto x86_l_4bd4;
	case 19414ULL: goto x86_l_4bd6;
	case 19419ULL: goto x86_l_4bdb;
	case 19427ULL: goto x86_l_4be3;
	case 19434ULL: goto x86_l_4bea;
	case 19439ULL: goto x86_l_4bef;
	case 19444ULL: goto x86_l_4bf4;
	case 19446ULL: goto x86_l_4bf6;
	case 19449ULL: goto x86_l_4bf9;
	case 19451ULL: goto x86_l_4bfb;
	case 19454ULL: goto x86_l_4bfe;
	case 19461ULL: goto x86_l_4c05;
	case 19463ULL: goto x86_l_4c07;
	case 19468ULL: goto x86_l_4c0c;
	case 19473ULL: goto x86_l_4c11;
	case 19476ULL: goto x86_l_4c14;
	case 19479ULL: goto x86_l_4c17;
	case 19481ULL: goto x86_l_4c19;
	case 19483ULL: goto x86_l_4c1b;
	case 19488ULL: goto x86_l_4c20;
	case 19491ULL: goto x86_l_4c23;
	case 19494ULL: goto x86_l_4c26;
	case 19499ULL: goto x86_l_4c2b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_44f6:
	/* 0x44f6: mov    eax,DWORD PTR [r12+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_44fe:
	/* 0x44fe: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4501:
	/* 0x4501: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4505:
	/* 0x4505: movzx  eax,WORD PTR [r12+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_450e:
	/* 0x450e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4510:
	/* 0x4510: je     47e2 <generic_sleepable_preload+0x47e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47e2;
	}
x86_l_4516:
	/* 0x4516: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4519:
	/* 0x4519: je     453b <generic_sleepable_preload+0x453b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_453b;
	}
x86_l_451b:
	/* 0x451b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_451e:
	/* 0x451e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4523:
	/* 0x4523: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4528:
	/* 0x4528: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_452c:
	/* 0x452c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4531:
	/* 0x4531: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4533:
	/* 0x4533: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4535:
	/* 0x4535: js     4ad4 <generic_sleepable_preload+0x4ad4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ad4;
	}
x86_l_453b:
	/* 0x453b: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4545:
	/* 0x4545: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_454b:
	/* 0x454b: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4553:
	/* 0x4553: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4557:
	/* 0x4557: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_455b:
	/* 0x455b: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4565:
	/* 0x4565: je     4587 <generic_sleepable_preload+0x4587> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4587;
	}
x86_l_4567:
	/* 0x4567: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_456a:
	/* 0x456a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_456f:
	/* 0x456f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4574:
	/* 0x4574: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4578:
	/* 0x4578: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_457d:
	/* 0x457d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_457f:
	/* 0x457f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4581:
	/* 0x4581: js     4ade <generic_sleepable_preload+0x4ade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ade;
	}
x86_l_4587:
	/* 0x4587: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4591:
	/* 0x4591: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4597:
	/* 0x4597: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_459f:
	/* 0x459f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45a3:
	/* 0x45a3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45a7:
	/* 0x45a7: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_45b1:
	/* 0x45b1: je     45d3 <generic_sleepable_preload+0x45d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45d3;
	}
x86_l_45b3:
	/* 0x45b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_45b6:
	/* 0x45b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45bb:
	/* 0x45bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45c0:
	/* 0x45c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45c4:
	/* 0x45c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45c9:
	/* 0x45c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45cb:
	/* 0x45cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45cd:
	/* 0x45cd: js     4aef <generic_sleepable_preload+0x4aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4aef;
	}
x86_l_45d3:
	/* 0x45d3: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_45dd:
	/* 0x45dd: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_45e3:
	/* 0x45e3: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_45eb:
	/* 0x45eb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45ef:
	/* 0x45ef: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45f3:
	/* 0x45f3: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_45fd:
	/* 0x45fd: je     461f <generic_sleepable_preload+0x461f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_461f;
	}
x86_l_45ff:
	/* 0x45ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4602:
	/* 0x4602: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4607:
	/* 0x4607: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_460c:
	/* 0x460c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4610:
	/* 0x4610: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4615:
	/* 0x4615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4617:
	/* 0x4617: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4619:
	/* 0x4619: js     4b00 <generic_sleepable_preload+0x4b00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b00;
	}
x86_l_461f:
	/* 0x461f: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4629:
	/* 0x4629: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_462f:
	/* 0x462f: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4637:
	/* 0x4637: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_463b:
	/* 0x463b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_463f:
	/* 0x463f: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4649:
	/* 0x4649: je     466b <generic_sleepable_preload+0x466b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_466b;
	}
x86_l_464b:
	/* 0x464b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_464e:
	/* 0x464e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4653:
	/* 0x4653: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4658:
	/* 0x4658: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_465c:
	/* 0x465c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4661:
	/* 0x4661: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4663:
	/* 0x4663: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4665:
	/* 0x4665: js     4b11 <generic_sleepable_preload+0x4b11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b11;
	}
x86_l_466b:
	/* 0x466b: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4675:
	/* 0x4675: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_467b:
	/* 0x467b: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4683:
	/* 0x4683: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4687:
	/* 0x4687: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_468b:
	/* 0x468b: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4695:
	/* 0x4695: je     46b7 <generic_sleepable_preload+0x46b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46b7;
	}
x86_l_4697:
	/* 0x4697: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_469a:
	/* 0x469a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_469f:
	/* 0x469f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46a4:
	/* 0x46a4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46a8:
	/* 0x46a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46ad:
	/* 0x46ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46af:
	/* 0x46af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46b1:
	/* 0x46b1: js     4b22 <generic_sleepable_preload+0x4b22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b22;
	}
x86_l_46b7:
	/* 0x46b7: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_46c1:
	/* 0x46c1: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_46c7:
	/* 0x46c7: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_46cf:
	/* 0x46cf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_46d3:
	/* 0x46d3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46d7:
	/* 0x46d7: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_46e1:
	/* 0x46e1: je     4703 <generic_sleepable_preload+0x4703> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4703;
	}
x86_l_46e3:
	/* 0x46e3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46e6:
	/* 0x46e6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46eb:
	/* 0x46eb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46f0:
	/* 0x46f0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46f4:
	/* 0x46f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46f9:
	/* 0x46f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46fb:
	/* 0x46fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46fd:
	/* 0x46fd: js     4bb7 <generic_sleepable_preload+0x4bb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4bb7;
	}
x86_l_4703:
	/* 0x4703: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_470d:
	/* 0x470d: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4713:
	/* 0x4713: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_471b:
	/* 0x471b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_471f:
	/* 0x471f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4723:
	/* 0x4723: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_472d:
	/* 0x472d: je     474f <generic_sleepable_preload+0x474f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_474f;
	}
x86_l_472f:
	/* 0x472f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4732:
	/* 0x4732: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4737:
	/* 0x4737: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_473c:
	/* 0x473c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4740:
	/* 0x4740: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4745:
	/* 0x4745: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4747:
	/* 0x4747: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4749:
	/* 0x4749: js     5c1a <generic_sleepable_preload+0x5c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23578ULL;
	}
x86_l_474f:
	/* 0x474f: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4759:
	/* 0x4759: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_475f:
	/* 0x475f: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4767:
	/* 0x4767: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_476b:
	/* 0x476b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_476f:
	/* 0x476f: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4779:
	/* 0x4779: je     479b <generic_sleepable_preload+0x479b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_479b;
	}
x86_l_477b:
	/* 0x477b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_477e:
	/* 0x477e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4783:
	/* 0x4783: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4788:
	/* 0x4788: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_478c:
	/* 0x478c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4791:
	/* 0x4791: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4793:
	/* 0x4793: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4795:
	/* 0x4795: js     5d23 <generic_sleepable_preload+0x5d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23843ULL;
	}
x86_l_479b:
	/* 0x479b: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47a0:
	/* 0x47a0: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_47aa:
	/* 0x47aa: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_47b0:
	/* 0x47b0: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_47b8:
	/* 0x47b8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_47bc:
	/* 0x47bc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47c0:
	/* 0x47c0: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_47ca:
	/* 0x47ca: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_47d0:
	/* 0x47d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47d3:
	/* 0x47d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47d8:
	/* 0x47d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47dd:
	/* 0x47dd: jmp    4ab7 <generic_sleepable_preload+0x4ab7> */
	goto x86_l_4ab7;
x86_l_47e2:
	/* 0x47e2: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_47e5:
	/* 0x47e5: je     4807 <generic_sleepable_preload+0x4807> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4807;
	}
x86_l_47e7:
	/* 0x47e7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47ea:
	/* 0x47ea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47ef:
	/* 0x47ef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47f4:
	/* 0x47f4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47f8:
	/* 0x47f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47fd:
	/* 0x47fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ff:
	/* 0x47ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4801:
	/* 0x4801: js     4ad4 <generic_sleepable_preload+0x4ad4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ad4;
	}
x86_l_4807:
	/* 0x4807: cmp    WORD PTR [r12+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4811:
	/* 0x4811: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4817:
	/* 0x4817: mov    ecx,DWORD PTR [r12+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_481f:
	/* 0x481f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4823:
	/* 0x4823: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4827:
	/* 0x4827: cmp    WORD PTR [r12+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4831:
	/* 0x4831: je     4853 <generic_sleepable_preload+0x4853> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4853;
	}
x86_l_4833:
	/* 0x4833: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4836:
	/* 0x4836: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_483b:
	/* 0x483b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4840:
	/* 0x4840: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4844:
	/* 0x4844: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4849:
	/* 0x4849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_484b:
	/* 0x484b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_484d:
	/* 0x484d: js     4ade <generic_sleepable_preload+0x4ade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ade;
	}
x86_l_4853:
	/* 0x4853: cmp    WORD PTR [r12+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_485d:
	/* 0x485d: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4863:
	/* 0x4863: mov    ecx,DWORD PTR [r12+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_486b:
	/* 0x486b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_486f:
	/* 0x486f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4873:
	/* 0x4873: cmp    WORD PTR [r12+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_487d:
	/* 0x487d: je     489f <generic_sleepable_preload+0x489f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_489f;
	}
x86_l_487f:
	/* 0x487f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4882:
	/* 0x4882: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4887:
	/* 0x4887: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_488c:
	/* 0x488c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4890:
	/* 0x4890: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4895:
	/* 0x4895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4897:
	/* 0x4897: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4899:
	/* 0x4899: js     4aef <generic_sleepable_preload+0x4aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4aef;
	}
x86_l_489f:
	/* 0x489f: cmp    WORD PTR [r12+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_48a9:
	/* 0x48a9: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_48af:
	/* 0x48af: mov    ecx,DWORD PTR [r12+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_48b7:
	/* 0x48b7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_48bb:
	/* 0x48bb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48bf:
	/* 0x48bf: cmp    WORD PTR [r12+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_48c9:
	/* 0x48c9: je     48eb <generic_sleepable_preload+0x48eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48eb;
	}
x86_l_48cb:
	/* 0x48cb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48ce:
	/* 0x48ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48d3:
	/* 0x48d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48d8:
	/* 0x48d8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48dc:
	/* 0x48dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48e1:
	/* 0x48e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e3:
	/* 0x48e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48e5:
	/* 0x48e5: js     4b00 <generic_sleepable_preload+0x4b00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b00;
	}
x86_l_48eb:
	/* 0x48eb: cmp    WORD PTR [r12+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_48f5:
	/* 0x48f5: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_48fb:
	/* 0x48fb: mov    ecx,DWORD PTR [r12+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4903:
	/* 0x4903: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4907:
	/* 0x4907: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_490b:
	/* 0x490b: cmp    WORD PTR [r12+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4915:
	/* 0x4915: je     4937 <generic_sleepable_preload+0x4937> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4937;
	}
x86_l_4917:
	/* 0x4917: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_491a:
	/* 0x491a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_491f:
	/* 0x491f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4924:
	/* 0x4924: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4928:
	/* 0x4928: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_492d:
	/* 0x492d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_492f:
	/* 0x492f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4931:
	/* 0x4931: js     4b11 <generic_sleepable_preload+0x4b11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b11;
	}
x86_l_4937:
	/* 0x4937: cmp    WORD PTR [r12+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4941:
	/* 0x4941: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4947:
	/* 0x4947: mov    ecx,DWORD PTR [r12+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_494f:
	/* 0x494f: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4953:
	/* 0x4953: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4957:
	/* 0x4957: cmp    WORD PTR [r12+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4961:
	/* 0x4961: je     4983 <generic_sleepable_preload+0x4983> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4983;
	}
x86_l_4963:
	/* 0x4963: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4966:
	/* 0x4966: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_496b:
	/* 0x496b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4970:
	/* 0x4970: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4974:
	/* 0x4974: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4979:
	/* 0x4979: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497b:
	/* 0x497b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_497d:
	/* 0x497d: js     4b22 <generic_sleepable_preload+0x4b22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4b22;
	}
x86_l_4983:
	/* 0x4983: cmp    WORD PTR [r12+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_498d:
	/* 0x498d: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4993:
	/* 0x4993: mov    ecx,DWORD PTR [r12+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_499b:
	/* 0x499b: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_499f:
	/* 0x499f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49a3:
	/* 0x49a3: cmp    WORD PTR [r12+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_49ad:
	/* 0x49ad: je     49cf <generic_sleepable_preload+0x49cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49cf;
	}
x86_l_49af:
	/* 0x49af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49b2:
	/* 0x49b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49b7:
	/* 0x49b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49bc:
	/* 0x49bc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49c0:
	/* 0x49c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49c5:
	/* 0x49c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49c7:
	/* 0x49c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49c9:
	/* 0x49c9: js     4bb7 <generic_sleepable_preload+0x4bb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4bb7;
	}
x86_l_49cf:
	/* 0x49cf: cmp    WORD PTR [r12+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_49d9:
	/* 0x49d9: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_49df:
	/* 0x49df: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_49e2:
	/* 0x49e2: mov    ecx,DWORD PTR [r12+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_49ea:
	/* 0x49ea: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49ee:
	/* 0x49ee: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49f2:
	/* 0x49f2: cmp    WORD PTR [r12+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_49fc:
	/* 0x49fc: je     4a1e <generic_sleepable_preload+0x4a1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a1e;
	}
x86_l_49fe:
	/* 0x49fe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a01:
	/* 0x4a01: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a06:
	/* 0x4a06: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a0b:
	/* 0x4a0b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a0f:
	/* 0x4a0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a14:
	/* 0x4a14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a16:
	/* 0x4a16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a18:
	/* 0x4a18: js     5c98 <generic_sleepable_preload+0x5c98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23704ULL;
	}
x86_l_4a1e:
	/* 0x4a1e: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a23:
	/* 0x4a23: cmp    WORD PTR [r12+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4a2d:
	/* 0x4a2d: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_4a30:
	/* 0x4a30: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4a36:
	/* 0x4a36: mov    ecx,DWORD PTR [r12+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4a3e:
	/* 0x4a3e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a42:
	/* 0x4a42: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a46:
	/* 0x4a46: cmp    WORD PTR [r12+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4a50:
	/* 0x4a50: je     4a72 <generic_sleepable_preload+0x4a72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a72;
	}
x86_l_4a52:
	/* 0x4a52: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a55:
	/* 0x4a55: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a5a:
	/* 0x4a5a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a5f:
	/* 0x4a5f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a63:
	/* 0x4a63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a68:
	/* 0x4a68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a6a:
	/* 0x4a6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a6c:
	/* 0x4a6c: js     5dc8 <generic_sleepable_preload+0x5dc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24008ULL;
	}
x86_l_4a72:
	/* 0x4a72: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a77:
	/* 0x4a77: cmp    WORD PTR [r12+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4a81:
	/* 0x4a81: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_4a84:
	/* 0x4a84: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4a8a:
	/* 0x4a8a: mov    ecx,DWORD PTR [r12+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4a92:
	/* 0x4a92: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a96:
	/* 0x4a96: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a9a:
	/* 0x4a9a: cmp    WORD PTR [r12+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4aa4:
	/* 0x4aa4: je     4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bbf;
	}
x86_l_4aaa:
	/* 0x4aaa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4aad:
	/* 0x4aad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ab2:
	/* 0x4ab2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ab7:
	/* 0x4ab7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4abb:
	/* 0x4abb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ac0:
	/* 0x4ac0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ac2:
	/* 0x4ac2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ac4:
	/* 0x4ac4: jns    4bbf <generic_sleepable_preload+0x4bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4bbf;
	}
x86_l_4aca:
	/* 0x4aca: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4acf:
	/* 0x4acf: jmp    4bbc <generic_sleepable_preload+0x4bbc> */
	goto x86_l_4bbc;
x86_l_4ad4:
	/* 0x4ad4: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4ad9:
	/* 0x4ad9: jmp    4bbc <generic_sleepable_preload+0x4bbc> */
	goto x86_l_4bbc;
x86_l_4ade:
	/* 0x4ade: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_4ae3:
	/* 0x4ae3: jmp    4bbc <generic_sleepable_preload+0x4bbc> */
	goto x86_l_4bbc;
x86_l_4ae8:
	/* 0x4ae8: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_4aed:
	/* 0x4aed: jmp    4b31 <generic_sleepable_preload+0x4b31> */
	goto x86_l_4b31;
x86_l_4aef:
	/* 0x4aef: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_4af4:
	/* 0x4af4: jmp    4bbc <generic_sleepable_preload+0x4bbc> */
	goto x86_l_4bbc;
x86_l_4af9:
	/* 0x4af9: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_4afe:
	/* 0x4afe: jmp    4b31 <generic_sleepable_preload+0x4b31> */
	goto x86_l_4b31;
x86_l_4b00:
	/* 0x4b00: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_4b05:
	/* 0x4b05: jmp    4bbc <generic_sleepable_preload+0x4bbc> */
	goto x86_l_4bbc;
x86_l_4b0a:
	/* 0x4b0a: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_4b0f:
	/* 0x4b0f: jmp    4b31 <generic_sleepable_preload+0x4b31> */
	goto x86_l_4b31;
x86_l_4b11:
	/* 0x4b11: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_4b16:
	/* 0x4b16: jmp    4bbc <generic_sleepable_preload+0x4bbc> */
	goto x86_l_4bbc;
x86_l_4b1b:
	/* 0x4b1b: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4b20:
	/* 0x4b20: jmp    4b31 <generic_sleepable_preload+0x4b31> */
	goto x86_l_4b31;
x86_l_4b22:
	/* 0x4b22: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4b27:
	/* 0x4b27: jmp    4bbc <generic_sleepable_preload+0x4bbc> */
	goto x86_l_4bbc;
x86_l_4b2c:
	/* 0x4b2c: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_4b31:
	/* 0x4b31: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b34:
	/* 0x4b34: mov    ebp,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b39:
	/* 0x4b39: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b3c:
	/* 0x4b3c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b41:
	/* 0x4b41: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b46:
	/* 0x4b46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b4b:
	/* 0x4b4b: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4b4e:
	/* 0x4b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b50:
	/* 0x4b50: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4b53:
	/* 0x4b53: jne    4c64 <generic_sleepable_preload+0x4c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19556ULL;
	}
x86_l_4b59:
	/* 0x4b59: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_4b5c:
	/* 0x4b5c: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b60:
	/* 0x4b60: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4b65:
	/* 0x4b65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b67:
	/* 0x4b67: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b6c:
	/* 0x4b6c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4b74:
	/* 0x4b74: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4b7b:
	/* 0x4b7b: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4b80:
	/* 0x4b80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b85:
	/* 0x4b85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b87:
	/* 0x4b87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b8a:
	/* 0x4b8a: je     4c61 <generic_sleepable_preload+0x4c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19553ULL;
	}
x86_l_4b90:
	/* 0x4b90: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4b93:
	/* 0x4b93: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4b9a:
	/* 0x4b9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b9c:
	/* 0x4b9c: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ba1:
	/* 0x4ba1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ba6:
	/* 0x4ba6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4ba9:
	/* 0x4ba9: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4bac:
	/* 0x4bac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bae:
	/* 0x4bae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb0:
	/* 0x4bb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bb5:
	/* 0x4bb5: jmp    4c20 <generic_sleepable_preload+0x4c20> */
	goto x86_l_4c20;
x86_l_4bb7:
	/* 0x4bb7: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_4bbc:
	/* 0x4bbc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bbf:
	/* 0x4bbf: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4bc2:
	/* 0x4bc2: jne    4c64 <generic_sleepable_preload+0x4c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19556ULL;
	}
x86_l_4bc8:
	/* 0x4bc8: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_4bcb:
	/* 0x4bcb: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bcf:
	/* 0x4bcf: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4bd4:
	/* 0x4bd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bd6:
	/* 0x4bd6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bdb:
	/* 0x4bdb: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4be3:
	/* 0x4be3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4bea:
	/* 0x4bea: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4bef:
	/* 0x4bef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bf4:
	/* 0x4bf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf6:
	/* 0x4bf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4bf9:
	/* 0x4bf9: je     4c61 <generic_sleepable_preload+0x4c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19553ULL;
	}
x86_l_4bfb:
	/* 0x4bfb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4bfe:
	/* 0x4bfe: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4c05:
	/* 0x4c05: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c07:
	/* 0x4c07: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c0c:
	/* 0x4c0c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c11:
	/* 0x4c11: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c14:
	/* 0x4c14: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4c17:
	/* 0x4c17: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c19:
	/* 0x4c19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c1b:
	/* 0x4c1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c20:
	/* 0x4c20: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c23:
	/* 0x4c23: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4c26:
	/* 0x4c26: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c2b:
	/* 0x4c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 19501ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19501ULL: goto x86_l_4c2d;
	case 19504ULL: goto x86_l_4c30;
	case 19506ULL: goto x86_l_4c32;
	case 19509ULL: goto x86_l_4c35;
	case 19511ULL: goto x86_l_4c37;
	case 19514ULL: goto x86_l_4c3a;
	case 19518ULL: goto x86_l_4c3e;
	case 19523ULL: goto x86_l_4c43;
	case 19526ULL: goto x86_l_4c46;
	case 19528ULL: goto x86_l_4c48;
	case 19531ULL: goto x86_l_4c4b;
	case 19536ULL: goto x86_l_4c50;
	case 19538ULL: goto x86_l_4c52;
	case 19541ULL: goto x86_l_4c55;
	case 19543ULL: goto x86_l_4c57;
	case 19548ULL: goto x86_l_4c5c;
	case 19551ULL: goto x86_l_4c5f;
	case 19553ULL: goto x86_l_4c61;
	case 19556ULL: goto x86_l_4c64;
	case 19561ULL: goto x86_l_4c69;
	case 19566ULL: goto x86_l_4c6e;
	case 19568ULL: goto x86_l_4c70;
	case 19570ULL: goto x86_l_4c72;
	case 19577ULL: goto x86_l_4c79;
	case 19579ULL: goto x86_l_4c7b;
	case 19580ULL: goto x86_l_4c7c;
	case 19585ULL: goto x86_l_4c81;
	case 19587ULL: goto x86_l_4c83;
	case 19589ULL: goto x86_l_4c85;
	case 19594ULL: goto x86_l_4c8a;
	case 19597ULL: goto x86_l_4c8d;
	case 19603ULL: goto x86_l_4c93;
	case 19606ULL: goto x86_l_4c96;
	case 19612ULL: goto x86_l_4c9c;
	case 19615ULL: goto x86_l_4c9f;
	case 19621ULL: goto x86_l_4ca5;
	case 19624ULL: goto x86_l_4ca8;
	case 19630ULL: goto x86_l_4cae;
	case 19635ULL: goto x86_l_4cb3;
	case 19640ULL: goto x86_l_4cb8;
	case 19649ULL: goto x86_l_4cc1;
	case 19658ULL: goto x86_l_4cca;
	case 19664ULL: goto x86_l_4cd0;
	case 19666ULL: goto x86_l_4cd2;
	case 19669ULL: goto x86_l_4cd5;
	case 19671ULL: goto x86_l_4cd7;
	case 19674ULL: goto x86_l_4cda;
	case 19676ULL: goto x86_l_4cdc;
	case 19679ULL: goto x86_l_4cdf;
	case 19685ULL: goto x86_l_4ce5;
	case 19690ULL: goto x86_l_4cea;
	case 19693ULL: goto x86_l_4ced;
	case 19699ULL: goto x86_l_4cf3;
	case 19704ULL: goto x86_l_4cf8;
	case 19707ULL: goto x86_l_4cfb;
	case 19713ULL: goto x86_l_4d01;
	case 19718ULL: goto x86_l_4d06;
	case 19721ULL: goto x86_l_4d09;
	case 19727ULL: goto x86_l_4d0f;
	case 19732ULL: goto x86_l_4d14;
	case 19735ULL: goto x86_l_4d17;
	case 19737ULL: goto x86_l_4d19;
	case 19740ULL: goto x86_l_4d1c;
	case 19746ULL: goto x86_l_4d22;
	case 19748ULL: goto x86_l_4d24;
	case 19754ULL: goto x86_l_4d2a;
	case 19757ULL: goto x86_l_4d2d;
	case 19760ULL: goto x86_l_4d30;
	case 19766ULL: goto x86_l_4d36;
	case 19771ULL: goto x86_l_4d3b;
	case 19773ULL: goto x86_l_4d3d;
	case 19775ULL: goto x86_l_4d3f;
	case 19778ULL: goto x86_l_4d42;
	case 19780ULL: goto x86_l_4d44;
	case 19785ULL: goto x86_l_4d49;
	case 19787ULL: goto x86_l_4d4b;
	case 19790ULL: goto x86_l_4d4e;
	case 19796ULL: goto x86_l_4d54;
	case 19804ULL: goto x86_l_4d5c;
	case 19807ULL: goto x86_l_4d5f;
	case 19813ULL: goto x86_l_4d65;
	case 19818ULL: goto x86_l_4d6a;
	case 19821ULL: goto x86_l_4d6d;
	case 19827ULL: goto x86_l_4d73;
	case 19832ULL: goto x86_l_4d78;
	case 19835ULL: goto x86_l_4d7b;
	case 19841ULL: goto x86_l_4d81;
	case 19849ULL: goto x86_l_4d89;
	case 19852ULL: goto x86_l_4d8c;
	case 19858ULL: goto x86_l_4d92;
	case 19863ULL: goto x86_l_4d97;
	case 19866ULL: goto x86_l_4d9a;
	case 19872ULL: goto x86_l_4da0;
	case 19877ULL: goto x86_l_4da5;
	case 19882ULL: goto x86_l_4daa;
	case 19884ULL: goto x86_l_4dac;
	case 19889ULL: goto x86_l_4db1;
	case 19891ULL: goto x86_l_4db3;
	case 19896ULL: goto x86_l_4db8;
	case 19899ULL: goto x86_l_4dbb;
	case 19903ULL: goto x86_l_4dbf;
	case 19906ULL: goto x86_l_4dc2;
	case 19909ULL: goto x86_l_4dc5;
	case 19914ULL: goto x86_l_4dca;
	case 19922ULL: goto x86_l_4dd2;
	case 19928ULL: goto x86_l_4dd8;
	case 19935ULL: goto x86_l_4ddf;
	case 19938ULL: goto x86_l_4de2;
	case 19944ULL: goto x86_l_4de8;
	case 19947ULL: goto x86_l_4deb;
	case 19951ULL: goto x86_l_4def;
	case 19958ULL: goto x86_l_4df6;
	case 19960ULL: goto x86_l_4df8;
	case 19966ULL: goto x86_l_4dfe;
	case 19969ULL: goto x86_l_4e01;
	case 19971ULL: goto x86_l_4e03;
	case 19974ULL: goto x86_l_4e06;
	case 19979ULL: goto x86_l_4e0b;
	case 19984ULL: goto x86_l_4e10;
	case 19988ULL: goto x86_l_4e14;
	case 19993ULL: goto x86_l_4e19;
	case 19995ULL: goto x86_l_4e1b;
	case 19997ULL: goto x86_l_4e1d;
	case 20003ULL: goto x86_l_4e23;
	case 20008ULL: goto x86_l_4e28;
	case 20016ULL: goto x86_l_4e30;
	case 20022ULL: goto x86_l_4e36;
	case 20028ULL: goto x86_l_4e3c;
	case 20032ULL: goto x86_l_4e40;
	case 20036ULL: goto x86_l_4e44;
	case 20044ULL: goto x86_l_4e4c;
	case 20046ULL: goto x86_l_4e4e;
	case 20049ULL: goto x86_l_4e51;
	case 20054ULL: goto x86_l_4e56;
	case 20059ULL: goto x86_l_4e5b;
	case 20063ULL: goto x86_l_4e5f;
	case 20068ULL: goto x86_l_4e64;
	case 20070ULL: goto x86_l_4e66;
	case 20072ULL: goto x86_l_4e68;
	case 20078ULL: goto x86_l_4e6e;
	case 20083ULL: goto x86_l_4e73;
	case 20091ULL: goto x86_l_4e7b;
	case 20097ULL: goto x86_l_4e81;
	case 20103ULL: goto x86_l_4e87;
	case 20107ULL: goto x86_l_4e8b;
	case 20111ULL: goto x86_l_4e8f;
	case 20119ULL: goto x86_l_4e97;
	case 20121ULL: goto x86_l_4e99;
	case 20124ULL: goto x86_l_4e9c;
	case 20129ULL: goto x86_l_4ea1;
	case 20134ULL: goto x86_l_4ea6;
	case 20138ULL: goto x86_l_4eaa;
	case 20143ULL: goto x86_l_4eaf;
	case 20145ULL: goto x86_l_4eb1;
	case 20147ULL: goto x86_l_4eb3;
	case 20153ULL: goto x86_l_4eb9;
	case 20158ULL: goto x86_l_4ebe;
	case 20166ULL: goto x86_l_4ec6;
	case 20172ULL: goto x86_l_4ecc;
	case 20178ULL: goto x86_l_4ed2;
	case 20182ULL: goto x86_l_4ed6;
	case 20186ULL: goto x86_l_4eda;
	case 20194ULL: goto x86_l_4ee2;
	case 20196ULL: goto x86_l_4ee4;
	case 20199ULL: goto x86_l_4ee7;
	case 20204ULL: goto x86_l_4eec;
	case 20209ULL: goto x86_l_4ef1;
	case 20213ULL: goto x86_l_4ef5;
	case 20218ULL: goto x86_l_4efa;
	case 20220ULL: goto x86_l_4efc;
	case 20222ULL: goto x86_l_4efe;
	case 20228ULL: goto x86_l_4f04;
	case 20233ULL: goto x86_l_4f09;
	case 20241ULL: goto x86_l_4f11;
	case 20247ULL: goto x86_l_4f17;
	case 20253ULL: goto x86_l_4f1d;
	case 20257ULL: goto x86_l_4f21;
	case 20261ULL: goto x86_l_4f25;
	case 20269ULL: goto x86_l_4f2d;
	case 20271ULL: goto x86_l_4f2f;
	case 20274ULL: goto x86_l_4f32;
	case 20279ULL: goto x86_l_4f37;
	case 20284ULL: goto x86_l_4f3c;
	case 20288ULL: goto x86_l_4f40;
	case 20293ULL: goto x86_l_4f45;
	case 20295ULL: goto x86_l_4f47;
	case 20297ULL: goto x86_l_4f49;
	case 20303ULL: goto x86_l_4f4f;
	case 20308ULL: goto x86_l_4f54;
	case 20316ULL: goto x86_l_4f5c;
	case 20322ULL: goto x86_l_4f62;
	case 20328ULL: goto x86_l_4f68;
	case 20332ULL: goto x86_l_4f6c;
	case 20336ULL: goto x86_l_4f70;
	case 20344ULL: goto x86_l_4f78;
	case 20346ULL: goto x86_l_4f7a;
	case 20349ULL: goto x86_l_4f7d;
	case 20354ULL: goto x86_l_4f82;
	case 20359ULL: goto x86_l_4f87;
	case 20363ULL: goto x86_l_4f8b;
	case 20368ULL: goto x86_l_4f90;
	case 20370ULL: goto x86_l_4f92;
	case 20372ULL: goto x86_l_4f94;
	case 20378ULL: goto x86_l_4f9a;
	case 20383ULL: goto x86_l_4f9f;
	case 20391ULL: goto x86_l_4fa7;
	case 20397ULL: goto x86_l_4fad;
	case 20403ULL: goto x86_l_4fb3;
	case 20407ULL: goto x86_l_4fb7;
	case 20411ULL: goto x86_l_4fbb;
	case 20419ULL: goto x86_l_4fc3;
	case 20421ULL: goto x86_l_4fc5;
	case 20424ULL: goto x86_l_4fc8;
	case 20429ULL: goto x86_l_4fcd;
	case 20434ULL: goto x86_l_4fd2;
	case 20438ULL: goto x86_l_4fd6;
	case 20443ULL: goto x86_l_4fdb;
	case 20445ULL: goto x86_l_4fdd;
	case 20447ULL: goto x86_l_4fdf;
	case 20453ULL: goto x86_l_4fe5;
	case 20458ULL: goto x86_l_4fea;
	case 20466ULL: goto x86_l_4ff2;
	case 20472ULL: goto x86_l_4ff8;
	case 20478ULL: goto x86_l_4ffe;
	case 20482ULL: goto x86_l_5002;
	case 20486ULL: goto x86_l_5006;
	case 20494ULL: goto x86_l_500e;
	case 20496ULL: goto x86_l_5010;
	case 20499ULL: goto x86_l_5013;
	case 20504ULL: goto x86_l_5018;
	case 20509ULL: goto x86_l_501d;
	case 20513ULL: goto x86_l_5021;
	case 20518ULL: goto x86_l_5026;
	case 20520ULL: goto x86_l_5028;
	case 20522ULL: goto x86_l_502a;
	case 20528ULL: goto x86_l_5030;
	case 20533ULL: goto x86_l_5035;
	case 20541ULL: goto x86_l_503d;
	case 20547ULL: goto x86_l_5043;
	case 20553ULL: goto x86_l_5049;
	case 20557ULL: goto x86_l_504d;
	case 20561ULL: goto x86_l_5051;
	case 20569ULL: goto x86_l_5059;
	case 20571ULL: goto x86_l_505b;
	case 20574ULL: goto x86_l_505e;
	case 20579ULL: goto x86_l_5063;
	case 20584ULL: goto x86_l_5068;
	case 20588ULL: goto x86_l_506c;
	case 20593ULL: goto x86_l_5071;
	case 20595ULL: goto x86_l_5073;
	case 20597ULL: goto x86_l_5075;
	case 20603ULL: goto x86_l_507b;
	case 20608ULL: goto x86_l_5080;
	case 20616ULL: goto x86_l_5088;
	case 20622ULL: goto x86_l_508e;
	case 20628ULL: goto x86_l_5094;
	case 20632ULL: goto x86_l_5098;
	case 20636ULL: goto x86_l_509c;
	case 20644ULL: goto x86_l_50a4;
	case 20650ULL: goto x86_l_50aa;
	case 20653ULL: goto x86_l_50ad;
	case 20658ULL: goto x86_l_50b2;
	case 20663ULL: goto x86_l_50b7;
	case 20668ULL: goto x86_l_50bc;
	case 20671ULL: goto x86_l_50bf;
	case 20673ULL: goto x86_l_50c1;
	case 20676ULL: goto x86_l_50c4;
	case 20681ULL: goto x86_l_50c9;
	case 20686ULL: goto x86_l_50ce;
	case 20690ULL: goto x86_l_50d2;
	case 20695ULL: goto x86_l_50d7;
	case 20697ULL: goto x86_l_50d9;
	case 20699ULL: goto x86_l_50db;
	case 20705ULL: goto x86_l_50e1;
	case 20710ULL: goto x86_l_50e6;
	case 20718ULL: goto x86_l_50ee;
	case 20724ULL: goto x86_l_50f4;
	case 20730ULL: goto x86_l_50fa;
	case 20734ULL: goto x86_l_50fe;
	case 20738ULL: goto x86_l_5102;
	case 20746ULL: goto x86_l_510a;
	case 20748ULL: goto x86_l_510c;
	case 20751ULL: goto x86_l_510f;
	case 20756ULL: goto x86_l_5114;
	case 20761ULL: goto x86_l_5119;
	case 20765ULL: goto x86_l_511d;
	case 20770ULL: goto x86_l_5122;
	case 20772ULL: goto x86_l_5124;
	case 20774ULL: goto x86_l_5126;
	case 20780ULL: goto x86_l_512c;
	case 20785ULL: goto x86_l_5131;
	case 20793ULL: goto x86_l_5139;
	case 20799ULL: goto x86_l_513f;
	case 20805ULL: goto x86_l_5145;
	case 20809ULL: goto x86_l_5149;
	case 20813ULL: goto x86_l_514d;
	case 20821ULL: goto x86_l_5155;
	case 20823ULL: goto x86_l_5157;
	case 20826ULL: goto x86_l_515a;
	case 20831ULL: goto x86_l_515f;
	case 20836ULL: goto x86_l_5164;
	case 20840ULL: goto x86_l_5168;
	case 20845ULL: goto x86_l_516d;
	case 20847ULL: goto x86_l_516f;
	case 20849ULL: goto x86_l_5171;
	case 20855ULL: goto x86_l_5177;
	case 20860ULL: goto x86_l_517c;
	case 20868ULL: goto x86_l_5184;
	case 20874ULL: goto x86_l_518a;
	case 20880ULL: goto x86_l_5190;
	case 20884ULL: goto x86_l_5194;
	case 20888ULL: goto x86_l_5198;
	case 20896ULL: goto x86_l_51a0;
	case 20898ULL: goto x86_l_51a2;
	case 20901ULL: goto x86_l_51a5;
	case 20906ULL: goto x86_l_51aa;
	case 20911ULL: goto x86_l_51af;
	case 20915ULL: goto x86_l_51b3;
	case 20920ULL: goto x86_l_51b8;
	case 20922ULL: goto x86_l_51ba;
	case 20924ULL: goto x86_l_51bc;
	case 20930ULL: goto x86_l_51c2;
	case 20935ULL: goto x86_l_51c7;
	case 20943ULL: goto x86_l_51cf;
	case 20949ULL: goto x86_l_51d5;
	case 20955ULL: goto x86_l_51db;
	case 20959ULL: goto x86_l_51df;
	case 20963ULL: goto x86_l_51e3;
	case 20971ULL: goto x86_l_51eb;
	case 20973ULL: goto x86_l_51ed;
	case 20976ULL: goto x86_l_51f0;
	case 20981ULL: goto x86_l_51f5;
	case 20986ULL: goto x86_l_51fa;
	case 20990ULL: goto x86_l_51fe;
	case 20995ULL: goto x86_l_5203;
	case 20997ULL: goto x86_l_5205;
	case 20999ULL: goto x86_l_5207;
	case 21005ULL: goto x86_l_520d;
	case 21010ULL: goto x86_l_5212;
	case 21018ULL: goto x86_l_521a;
	case 21024ULL: goto x86_l_5220;
	case 21030ULL: goto x86_l_5226;
	case 21034ULL: goto x86_l_522a;
	case 21038ULL: goto x86_l_522e;
	case 21046ULL: goto x86_l_5236;
	case 21048ULL: goto x86_l_5238;
	case 21051ULL: goto x86_l_523b;
	case 21056ULL: goto x86_l_5240;
	case 21061ULL: goto x86_l_5245;
	case 21065ULL: goto x86_l_5249;
	case 21070ULL: goto x86_l_524e;
	case 21072ULL: goto x86_l_5250;
	case 21074ULL: goto x86_l_5252;
	case 21080ULL: goto x86_l_5258;
	case 21085ULL: goto x86_l_525d;
	case 21093ULL: goto x86_l_5265;
	case 21099ULL: goto x86_l_526b;
	case 21105ULL: goto x86_l_5271;
	case 21109ULL: goto x86_l_5275;
	case 21113ULL: goto x86_l_5279;
	case 21121ULL: goto x86_l_5281;
	case 21123ULL: goto x86_l_5283;
	case 21126ULL: goto x86_l_5286;
	case 21131ULL: goto x86_l_528b;
	case 21136ULL: goto x86_l_5290;
	case 21140ULL: goto x86_l_5294;
	case 21145ULL: goto x86_l_5299;
	case 21147ULL: goto x86_l_529b;
	case 21149ULL: goto x86_l_529d;
	case 21155ULL: goto x86_l_52a3;
	case 21160ULL: goto x86_l_52a8;
	case 21168ULL: goto x86_l_52b0;
	case 21174ULL: goto x86_l_52b6;
	case 21180ULL: goto x86_l_52bc;
	case 21184ULL: goto x86_l_52c0;
	case 21188ULL: goto x86_l_52c4;
	case 21196ULL: goto x86_l_52cc;
	case 21198ULL: goto x86_l_52ce;
	case 21201ULL: goto x86_l_52d1;
	case 21206ULL: goto x86_l_52d6;
	case 21211ULL: goto x86_l_52db;
	case 21215ULL: goto x86_l_52df;
	case 21220ULL: goto x86_l_52e4;
	case 21222ULL: goto x86_l_52e6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4c2d:
	/* 0x4c2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c30:
	/* 0x4c30: je     4c61 <generic_sleepable_preload+0x4c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c61;
	}
x86_l_4c32:
	/* 0x4c32: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_4c35:
	/* 0x4c35: je     4c5f <generic_sleepable_preload+0x4c5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c5f;
	}
x86_l_4c37:
	/* 0x4c37: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4c3a:
	/* 0x4c3a: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4c3e:
	/* 0x4c3e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c43:
	/* 0x4c43: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4c46:
	/* 0x4c46: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c48:
	/* 0x4c48: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4c4b:
	/* 0x4c4b: call   4c50 <generic_sleepable_preload+0x4c50> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_4c50:
	/* 0x4c50: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4c52:
	/* 0x4c52: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_4c55:
	/* 0x4c55: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4c57:
	/* 0x4c57: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_4c5c:
	/* 0x4c5c: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_4c5f:
	/* 0x4c5f: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c61:
	/* 0x4c61: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_4c64:
	/* 0x4c64: mov    eax,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4c69:
	/* 0x4c69: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_4c6e:
	/* 0x4c6e: jne    4c81 <generic_sleepable_preload+0x4c81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4c81;
	}
x86_l_4c70:
	/* 0x4c70: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c72:
	/* 0x4c72: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_4c79:
	/* 0x4c79: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4c7b:
	/* 0x4c7b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4c7c:
	/* 0x4c7c: jmp    5ddd <generic_sleepable_preload+0x5ddd> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_4c81:
	/* 0x4c81: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4c83:
	/* 0x4c83: js     4cb8 <generic_sleepable_preload+0x4cb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4cb8;
	}
x86_l_4c85:
	/* 0x4c85: mov    eax,DWORD PTR [r12+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c8a:
	/* 0x4c8a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c8d:
	/* 0x4c8d: jle    4d3b <generic_sleepable_preload+0x4d3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d3b;
	}
x86_l_4c93:
	/* 0x4c93: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c96:
	/* 0x4c96: je     4da5 <generic_sleepable_preload+0x4da5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4da5;
	}
x86_l_4c9c:
	/* 0x4c9c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4c9f:
	/* 0x4c9f: je     4dac <generic_sleepable_preload+0x4dac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dac;
	}
x86_l_4ca5:
	/* 0x4ca5: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ca8:
	/* 0x4ca8: jne    4dbf <generic_sleepable_preload+0x4dbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dbf;
	}
x86_l_4cae:
	/* 0x4cae: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cb3:
	/* 0x4cb3: jmp    4db8 <generic_sleepable_preload+0x4db8> */
	goto x86_l_4db8;
x86_l_4cb8:
	/* 0x4cb8: movzx  eax,BYTE PTR [r12+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4cc1:
	/* 0x4cc1: movzx  ecx,WORD PTR [r12+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4cca:
	/* 0x4cca: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_4cd0:
	/* 0x4cd0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cd2:
	/* 0x4cd2: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4cd5:
	/* 0x4cd5: jle    4d14 <generic_sleepable_preload+0x4d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d14;
	}
x86_l_4cd7:
	/* 0x4cd7: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4cda:
	/* 0x4cda: jle    4d4b <generic_sleepable_preload+0x4d4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d4b;
	}
x86_l_4cdc:
	/* 0x4cdc: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4cdf:
	/* 0x4cdf: jle    53e6 <generic_sleepable_preload+0x53e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 21478ULL;
	}
x86_l_4ce5:
	/* 0x4ce5: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4cea:
	/* 0x4cea: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_4ced:
	/* 0x4ced: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21516ULL;
	}
x86_l_4cf3:
	/* 0x4cf3: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4cf8:
	/* 0x4cf8: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4cfb:
	/* 0x4cfb: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21516ULL;
	}
x86_l_4d01:
	/* 0x4d01: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4d06:
	/* 0x4d06: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4d09:
	/* 0x4d09: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21516ULL;
	}
x86_l_4d0f:
	/* 0x4d0f: jmp    541f <generic_sleepable_preload+0x541f> */
	return 21535ULL;
x86_l_4d14:
	/* 0x4d14: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4d17:
	/* 0x4d17: jg     4d78 <generic_sleepable_preload+0x4d78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4d78;
	}
x86_l_4d19:
	/* 0x4d19: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d1c:
	/* 0x4d1c: jg     53b7 <generic_sleepable_preload+0x53b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21431ULL;
	}
x86_l_4d22:
	/* 0x4d22: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4d24:
	/* 0x4d24: je     5407 <generic_sleepable_preload+0x5407> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21511ULL;
	}
x86_l_4d2a:
	/* 0x4d2a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d2d:
	/* 0x4d2d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_4d30:
	/* 0x4d30: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21516ULL;
	}
x86_l_4d36:
	/* 0x4d36: jmp    541f <generic_sleepable_preload+0x541f> */
	return 21535ULL;
x86_l_4d3b:
	/* 0x4d3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d3d:
	/* 0x4d3d: je     4db3 <generic_sleepable_preload+0x4db3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4db3;
	}
x86_l_4d3f:
	/* 0x4d3f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d42:
	/* 0x4d42: jne    4dbf <generic_sleepable_preload+0x4dbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dbf;
	}
x86_l_4d44:
	/* 0x4d44: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d49:
	/* 0x4d49: jmp    4db8 <generic_sleepable_preload+0x4db8> */
	goto x86_l_4db8;
x86_l_4d4b:
	/* 0x4d4b: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4d4e:
	/* 0x4d4e: jg     539e <generic_sleepable_preload+0x539e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21406ULL;
	}
x86_l_4d54:
	/* 0x4d54: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4d5c:
	/* 0x4d5c: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d5f:
	/* 0x4d5f: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21516ULL;
	}
x86_l_4d65:
	/* 0x4d65: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d6a:
	/* 0x4d6a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4d6d:
	/* 0x4d6d: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21516ULL;
	}
x86_l_4d73:
	/* 0x4d73: jmp    541f <generic_sleepable_preload+0x541f> */
	return 21535ULL;
x86_l_4d78:
	/* 0x4d78: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4d7b:
	/* 0x4d7b: jg     53cd <generic_sleepable_preload+0x53cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 21453ULL;
	}
x86_l_4d81:
	/* 0x4d81: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d89:
	/* 0x4d89: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4d8c:
	/* 0x4d8c: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21516ULL;
	}
x86_l_4d92:
	/* 0x4d92: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4d97:
	/* 0x4d97: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4d9a:
	/* 0x4d9a: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21516ULL;
	}
x86_l_4da0:
	/* 0x4da0: jmp    541f <generic_sleepable_preload+0x541f> */
	return 21535ULL;
x86_l_4da5:
	/* 0x4da5: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4daa:
	/* 0x4daa: jmp    4db8 <generic_sleepable_preload+0x4db8> */
	goto x86_l_4db8;
x86_l_4dac:
	/* 0x4dac: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4db1:
	/* 0x4db1: jmp    4db8 <generic_sleepable_preload+0x4db8> */
	goto x86_l_4db8;
x86_l_4db3:
	/* 0x4db3: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4db8:
	/* 0x4db8: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dbb:
	/* 0x4dbb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dbf:
	/* 0x4dbf: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4dc2:
	/* 0x4dc2: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_4dc5:
	/* 0x4dc5: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dca:
	/* 0x4dca: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_4dd2:
	/* 0x4dd2: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_4dd8:
	/* 0x4dd8: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4ddf:
	/* 0x4ddf: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4de2:
	/* 0x4de2: mov    eax,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_4de8:
	/* 0x4de8: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4deb:
	/* 0x4deb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4def:
	/* 0x4def: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_4df6:
	/* 0x4df6: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4df8:
	/* 0x4df8: je     50bc <generic_sleepable_preload+0x50bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50bc;
	}
x86_l_4dfe:
	/* 0x4dfe: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4e01:
	/* 0x4e01: je     4e23 <generic_sleepable_preload+0x4e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e23;
	}
x86_l_4e03:
	/* 0x4e03: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e06:
	/* 0x4e06: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e0b:
	/* 0x4e0b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e10:
	/* 0x4e10: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e14:
	/* 0x4e14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e19:
	/* 0x4e19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e1b:
	/* 0x4e1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e1d:
	/* 0x4e1d: js     5393 <generic_sleepable_preload+0x5393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21395ULL;
	}
x86_l_4e23:
	/* 0x4e23: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e28:
	/* 0x4e28: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_4e30:
	/* 0x4e30: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_4e36:
	/* 0x4e36: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_4e3c:
	/* 0x4e3c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e40:
	/* 0x4e40: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e44:
	/* 0x4e44: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_4e4c:
	/* 0x4e4c: je     4e6e <generic_sleepable_preload+0x4e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e6e;
	}
x86_l_4e4e:
	/* 0x4e4e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e51:
	/* 0x4e51: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e56:
	/* 0x4e56: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e5b:
	/* 0x4e5b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e5f:
	/* 0x4e5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e64:
	/* 0x4e64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e66:
	/* 0x4e66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e68:
	/* 0x4e68: js     53fc <generic_sleepable_preload+0x53fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21500ULL;
	}
x86_l_4e6e:
	/* 0x4e6e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e73:
	/* 0x4e73: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_4e7b:
	/* 0x4e7b: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_4e81:
	/* 0x4e81: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_4e87:
	/* 0x4e87: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e8b:
	/* 0x4e8b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e8f:
	/* 0x4e8f: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4e97:
	/* 0x4e97: je     4eb9 <generic_sleepable_preload+0x4eb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4eb9;
	}
x86_l_4e99:
	/* 0x4e99: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e9c:
	/* 0x4e9c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ea1:
	/* 0x4ea1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ea6:
	/* 0x4ea6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eaa:
	/* 0x4eaa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4eaf:
	/* 0x4eaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eb1:
	/* 0x4eb1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4eb3:
	/* 0x4eb3: js     5a10 <generic_sleepable_preload+0x5a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23056ULL;
	}
x86_l_4eb9:
	/* 0x4eb9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ebe:
	/* 0x4ebe: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4ec6:
	/* 0x4ec6: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_4ecc:
	/* 0x4ecc: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4ed2:
	/* 0x4ed2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ed6:
	/* 0x4ed6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eda:
	/* 0x4eda: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4ee2:
	/* 0x4ee2: je     4f04 <generic_sleepable_preload+0x4f04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f04;
	}
x86_l_4ee4:
	/* 0x4ee4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ee7:
	/* 0x4ee7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4eec:
	/* 0x4eec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ef1:
	/* 0x4ef1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ef5:
	/* 0x4ef5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4efa:
	/* 0x4efa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4efc:
	/* 0x4efc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4efe:
	/* 0x4efe: js     5a23 <generic_sleepable_preload+0x5a23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23075ULL;
	}
x86_l_4f04:
	/* 0x4f04: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f09:
	/* 0x4f09: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_4f11:
	/* 0x4f11: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_4f17:
	/* 0x4f17: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4f1d:
	/* 0x4f1d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4f21:
	/* 0x4f21: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f25:
	/* 0x4f25: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4f2d:
	/* 0x4f2d: je     4f4f <generic_sleepable_preload+0x4f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f4f;
	}
x86_l_4f2f:
	/* 0x4f2f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f32:
	/* 0x4f32: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f37:
	/* 0x4f37: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f3c:
	/* 0x4f3c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f40:
	/* 0x4f40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f45:
	/* 0x4f45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f47:
	/* 0x4f47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f49:
	/* 0x4f49: js     5a36 <generic_sleepable_preload+0x5a36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23094ULL;
	}
x86_l_4f4f:
	/* 0x4f4f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f54:
	/* 0x4f54: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_4f5c:
	/* 0x4f5c: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_4f62:
	/* 0x4f62: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_4f68:
	/* 0x4f68: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4f6c:
	/* 0x4f6c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f70:
	/* 0x4f70: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_4f78:
	/* 0x4f78: je     4f9a <generic_sleepable_preload+0x4f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f9a;
	}
x86_l_4f7a:
	/* 0x4f7a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f7d:
	/* 0x4f7d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f82:
	/* 0x4f82: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f87:
	/* 0x4f87: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f8b:
	/* 0x4f8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f90:
	/* 0x4f90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f92:
	/* 0x4f92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f94:
	/* 0x4f94: js     5a49 <generic_sleepable_preload+0x5a49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23113ULL;
	}
x86_l_4f9a:
	/* 0x4f9a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f9f:
	/* 0x4f9f: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_4fa7:
	/* 0x4fa7: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_4fad:
	/* 0x4fad: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_4fb3:
	/* 0x4fb3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4fb7:
	/* 0x4fb7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fbb:
	/* 0x4fbb: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4fc3:
	/* 0x4fc3: je     4fe5 <generic_sleepable_preload+0x4fe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fe5;
	}
x86_l_4fc5:
	/* 0x4fc5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4fc8:
	/* 0x4fc8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fcd:
	/* 0x4fcd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fd2:
	/* 0x4fd2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fd6:
	/* 0x4fd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fdb:
	/* 0x4fdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fdd:
	/* 0x4fdd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fdf:
	/* 0x4fdf: js     5a5c <generic_sleepable_preload+0x5a5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23132ULL;
	}
x86_l_4fe5:
	/* 0x4fe5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fea:
	/* 0x4fea: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_4ff2:
	/* 0x4ff2: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_4ff8:
	/* 0x4ff8: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_4ffe:
	/* 0x4ffe: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5002:
	/* 0x5002: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5006:
	/* 0x5006: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_500e:
	/* 0x500e: je     5030 <generic_sleepable_preload+0x5030> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5030;
	}
x86_l_5010:
	/* 0x5010: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5013:
	/* 0x5013: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5018:
	/* 0x5018: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_501d:
	/* 0x501d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5021:
	/* 0x5021: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5026:
	/* 0x5026: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5028:
	/* 0x5028: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_502a:
	/* 0x502a: js     5b9a <generic_sleepable_preload+0x5b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23450ULL;
	}
x86_l_5030:
	/* 0x5030: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5035:
	/* 0x5035: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_503d:
	/* 0x503d: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_5043:
	/* 0x5043: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5049:
	/* 0x5049: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_504d:
	/* 0x504d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5051:
	/* 0x5051: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5059:
	/* 0x5059: je     507b <generic_sleepable_preload+0x507b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_507b;
	}
x86_l_505b:
	/* 0x505b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_505e:
	/* 0x505e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5063:
	/* 0x5063: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5068:
	/* 0x5068: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_506c:
	/* 0x506c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5071:
	/* 0x5071: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5073:
	/* 0x5073: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5075:
	/* 0x5075: js     5c27 <generic_sleepable_preload+0x5c27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23591ULL;
	}
x86_l_507b:
	/* 0x507b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5080:
	/* 0x5080: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5088:
	/* 0x5088: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_508e:
	/* 0x508e: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5094:
	/* 0x5094: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5098:
	/* 0x5098: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_509c:
	/* 0x509c: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_50a4:
	/* 0x50a4: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_50aa:
	/* 0x50aa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_50ad:
	/* 0x50ad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50b2:
	/* 0x50b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50b7:
	/* 0x50b7: jmp    5375 <generic_sleepable_preload+0x5375> */
	return 21365ULL;
x86_l_50bc:
	/* 0x50bc: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50bf:
	/* 0x50bf: je     50e1 <generic_sleepable_preload+0x50e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50e1;
	}
x86_l_50c1:
	/* 0x50c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_50c4:
	/* 0x50c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50c9:
	/* 0x50c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50ce:
	/* 0x50ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50d2:
	/* 0x50d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50d7:
	/* 0x50d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d9:
	/* 0x50d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50db:
	/* 0x50db: js     5393 <generic_sleepable_preload+0x5393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21395ULL;
	}
x86_l_50e1:
	/* 0x50e1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50e6:
	/* 0x50e6: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_50ee:
	/* 0x50ee: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_50f4:
	/* 0x50f4: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_50fa:
	/* 0x50fa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_50fe:
	/* 0x50fe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5102:
	/* 0x5102: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_510a:
	/* 0x510a: je     512c <generic_sleepable_preload+0x512c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_512c;
	}
x86_l_510c:
	/* 0x510c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_510f:
	/* 0x510f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5114:
	/* 0x5114: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5119:
	/* 0x5119: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_511d:
	/* 0x511d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5122:
	/* 0x5122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5124:
	/* 0x5124: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5126:
	/* 0x5126: js     53fc <generic_sleepable_preload+0x53fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21500ULL;
	}
x86_l_512c:
	/* 0x512c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5131:
	/* 0x5131: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5139:
	/* 0x5139: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_513f:
	/* 0x513f: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5145:
	/* 0x5145: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5149:
	/* 0x5149: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_514d:
	/* 0x514d: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5155:
	/* 0x5155: je     5177 <generic_sleepable_preload+0x5177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5177;
	}
x86_l_5157:
	/* 0x5157: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_515a:
	/* 0x515a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_515f:
	/* 0x515f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5164:
	/* 0x5164: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5168:
	/* 0x5168: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_516d:
	/* 0x516d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_516f:
	/* 0x516f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5171:
	/* 0x5171: js     5a10 <generic_sleepable_preload+0x5a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23056ULL;
	}
x86_l_5177:
	/* 0x5177: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_517c:
	/* 0x517c: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5184:
	/* 0x5184: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_518a:
	/* 0x518a: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5190:
	/* 0x5190: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5194:
	/* 0x5194: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5198:
	/* 0x5198: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_51a0:
	/* 0x51a0: je     51c2 <generic_sleepable_preload+0x51c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51c2;
	}
x86_l_51a2:
	/* 0x51a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51a5:
	/* 0x51a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51aa:
	/* 0x51aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51af:
	/* 0x51af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51b3:
	/* 0x51b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51b8:
	/* 0x51b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ba:
	/* 0x51ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51bc:
	/* 0x51bc: js     5a23 <generic_sleepable_preload+0x5a23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23075ULL;
	}
x86_l_51c2:
	/* 0x51c2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51c7:
	/* 0x51c7: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_51cf:
	/* 0x51cf: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_51d5:
	/* 0x51d5: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_51db:
	/* 0x51db: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_51df:
	/* 0x51df: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51e3:
	/* 0x51e3: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_51eb:
	/* 0x51eb: je     520d <generic_sleepable_preload+0x520d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_520d;
	}
x86_l_51ed:
	/* 0x51ed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51f0:
	/* 0x51f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51f5:
	/* 0x51f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51fa:
	/* 0x51fa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51fe:
	/* 0x51fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5203:
	/* 0x5203: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5205:
	/* 0x5205: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5207:
	/* 0x5207: js     5a36 <generic_sleepable_preload+0x5a36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23094ULL;
	}
x86_l_520d:
	/* 0x520d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5212:
	/* 0x5212: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_521a:
	/* 0x521a: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_5220:
	/* 0x5220: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5226:
	/* 0x5226: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_522a:
	/* 0x522a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_522e:
	/* 0x522e: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5236:
	/* 0x5236: je     5258 <generic_sleepable_preload+0x5258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5258;
	}
x86_l_5238:
	/* 0x5238: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_523b:
	/* 0x523b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5240:
	/* 0x5240: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5245:
	/* 0x5245: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5249:
	/* 0x5249: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_524e:
	/* 0x524e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5250:
	/* 0x5250: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5252:
	/* 0x5252: js     5a49 <generic_sleepable_preload+0x5a49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23113ULL;
	}
x86_l_5258:
	/* 0x5258: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_525d:
	/* 0x525d: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5265:
	/* 0x5265: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_526b:
	/* 0x526b: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5271:
	/* 0x5271: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5275:
	/* 0x5275: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5279:
	/* 0x5279: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5281:
	/* 0x5281: je     52a3 <generic_sleepable_preload+0x52a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52a3;
	}
x86_l_5283:
	/* 0x5283: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5286:
	/* 0x5286: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_528b:
	/* 0x528b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5290:
	/* 0x5290: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5294:
	/* 0x5294: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5299:
	/* 0x5299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_529b:
	/* 0x529b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_529d:
	/* 0x529d: js     5a5c <generic_sleepable_preload+0x5a5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23132ULL;
	}
x86_l_52a3:
	/* 0x52a3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a8:
	/* 0x52a8: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_52b0:
	/* 0x52b0: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_52b6:
	/* 0x52b6: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_52bc:
	/* 0x52bc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_52c0:
	/* 0x52c0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52c4:
	/* 0x52c4: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_52cc:
	/* 0x52cc: je     52ee <generic_sleepable_preload+0x52ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21230ULL;
	}
x86_l_52ce:
	/* 0x52ce: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_52d1:
	/* 0x52d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52d6:
	/* 0x52d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52db:
	/* 0x52db: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52df:
	/* 0x52df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52e4:
	/* 0x52e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52e6:
	/* 0x52e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 21224ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21224ULL: goto x86_l_52e8;
	case 21230ULL: goto x86_l_52ee;
	case 21235ULL: goto x86_l_52f3;
	case 21243ULL: goto x86_l_52fb;
	case 21249ULL: goto x86_l_5301;
	case 21255ULL: goto x86_l_5307;
	case 21259ULL: goto x86_l_530b;
	case 21263ULL: goto x86_l_530f;
	case 21271ULL: goto x86_l_5317;
	case 21273ULL: goto x86_l_5319;
	case 21276ULL: goto x86_l_531c;
	case 21281ULL: goto x86_l_5321;
	case 21286ULL: goto x86_l_5326;
	case 21290ULL: goto x86_l_532a;
	case 21295ULL: goto x86_l_532f;
	case 21297ULL: goto x86_l_5331;
	case 21299ULL: goto x86_l_5333;
	case 21305ULL: goto x86_l_5339;
	case 21310ULL: goto x86_l_533e;
	case 21318ULL: goto x86_l_5346;
	case 21324ULL: goto x86_l_534c;
	case 21330ULL: goto x86_l_5352;
	case 21334ULL: goto x86_l_5356;
	case 21338ULL: goto x86_l_535a;
	case 21346ULL: goto x86_l_5362;
	case 21352ULL: goto x86_l_5368;
	case 21355ULL: goto x86_l_536b;
	case 21360ULL: goto x86_l_5370;
	case 21365ULL: goto x86_l_5375;
	case 21369ULL: goto x86_l_5379;
	case 21374ULL: goto x86_l_537e;
	case 21376ULL: goto x86_l_5380;
	case 21378ULL: goto x86_l_5382;
	case 21384ULL: goto x86_l_5388;
	case 21390ULL: goto x86_l_538e;
	case 21395ULL: goto x86_l_5393;
	case 21401ULL: goto x86_l_5399;
	case 21406ULL: goto x86_l_539e;
	case 21414ULL: goto x86_l_53a6;
	case 21417ULL: goto x86_l_53a9;
	case 21419ULL: goto x86_l_53ab;
	case 21424ULL: goto x86_l_53b0;
	case 21427ULL: goto x86_l_53b3;
	case 21429ULL: goto x86_l_53b5;
	case 21431ULL: goto x86_l_53b7;
	case 21436ULL: goto x86_l_53bc;
	case 21439ULL: goto x86_l_53bf;
	case 21441ULL: goto x86_l_53c1;
	case 21446ULL: goto x86_l_53c6;
	case 21449ULL: goto x86_l_53c9;
	case 21451ULL: goto x86_l_53cb;
	case 21453ULL: goto x86_l_53cd;
	case 21461ULL: goto x86_l_53d5;
	case 21464ULL: goto x86_l_53d8;
	case 21466ULL: goto x86_l_53da;
	case 21471ULL: goto x86_l_53df;
	case 21474ULL: goto x86_l_53e2;
	case 21476ULL: goto x86_l_53e4;
	case 21478ULL: goto x86_l_53e6;
	case 21483ULL: goto x86_l_53eb;
	case 21486ULL: goto x86_l_53ee;
	case 21488ULL: goto x86_l_53f0;
	case 21493ULL: goto x86_l_53f5;
	case 21496ULL: goto x86_l_53f8;
	case 21498ULL: goto x86_l_53fa;
	case 21500ULL: goto x86_l_53fc;
	case 21506ULL: goto x86_l_5402;
	case 21511ULL: goto x86_l_5407;
	case 21516ULL: goto x86_l_540c;
	case 21519ULL: goto x86_l_540f;
	case 21521ULL: goto x86_l_5411;
	case 21523ULL: goto x86_l_5413;
	case 21528ULL: goto x86_l_5418;
	case 21530ULL: goto x86_l_541a;
	case 21535ULL: goto x86_l_541f;
	case 21539ULL: goto x86_l_5423;
	case 21544ULL: goto x86_l_5428;
	case 21547ULL: goto x86_l_542b;
	case 21550ULL: goto x86_l_542e;
	case 21553ULL: goto x86_l_5431;
	case 21561ULL: goto x86_l_5439;
	case 21567ULL: goto x86_l_543f;
	case 21574ULL: goto x86_l_5446;
	case 21577ULL: goto x86_l_5449;
	case 21583ULL: goto x86_l_544f;
	case 21586ULL: goto x86_l_5452;
	case 21590ULL: goto x86_l_5456;
	case 21597ULL: goto x86_l_545d;
	case 21599ULL: goto x86_l_545f;
	case 21605ULL: goto x86_l_5465;
	case 21608ULL: goto x86_l_5468;
	case 21610ULL: goto x86_l_546a;
	case 21613ULL: goto x86_l_546d;
	case 21618ULL: goto x86_l_5472;
	case 21623ULL: goto x86_l_5477;
	case 21627ULL: goto x86_l_547b;
	case 21632ULL: goto x86_l_5480;
	case 21634ULL: goto x86_l_5482;
	case 21636ULL: goto x86_l_5484;
	case 21642ULL: goto x86_l_548a;
	case 21647ULL: goto x86_l_548f;
	case 21655ULL: goto x86_l_5497;
	case 21661ULL: goto x86_l_549d;
	case 21667ULL: goto x86_l_54a3;
	case 21671ULL: goto x86_l_54a7;
	case 21675ULL: goto x86_l_54ab;
	case 21683ULL: goto x86_l_54b3;
	case 21685ULL: goto x86_l_54b5;
	case 21688ULL: goto x86_l_54b8;
	case 21693ULL: goto x86_l_54bd;
	case 21698ULL: goto x86_l_54c2;
	case 21702ULL: goto x86_l_54c6;
	case 21707ULL: goto x86_l_54cb;
	case 21709ULL: goto x86_l_54cd;
	case 21711ULL: goto x86_l_54cf;
	case 21717ULL: goto x86_l_54d5;
	case 21722ULL: goto x86_l_54da;
	case 21730ULL: goto x86_l_54e2;
	case 21736ULL: goto x86_l_54e8;
	case 21742ULL: goto x86_l_54ee;
	case 21746ULL: goto x86_l_54f2;
	case 21750ULL: goto x86_l_54f6;
	case 21758ULL: goto x86_l_54fe;
	case 21760ULL: goto x86_l_5500;
	case 21763ULL: goto x86_l_5503;
	case 21768ULL: goto x86_l_5508;
	case 21773ULL: goto x86_l_550d;
	case 21777ULL: goto x86_l_5511;
	case 21782ULL: goto x86_l_5516;
	case 21784ULL: goto x86_l_5518;
	case 21786ULL: goto x86_l_551a;
	case 21792ULL: goto x86_l_5520;
	case 21797ULL: goto x86_l_5525;
	case 21805ULL: goto x86_l_552d;
	case 21811ULL: goto x86_l_5533;
	case 21817ULL: goto x86_l_5539;
	case 21821ULL: goto x86_l_553d;
	case 21825ULL: goto x86_l_5541;
	case 21833ULL: goto x86_l_5549;
	case 21835ULL: goto x86_l_554b;
	case 21838ULL: goto x86_l_554e;
	case 21843ULL: goto x86_l_5553;
	case 21848ULL: goto x86_l_5558;
	case 21852ULL: goto x86_l_555c;
	case 21857ULL: goto x86_l_5561;
	case 21859ULL: goto x86_l_5563;
	case 21861ULL: goto x86_l_5565;
	case 21867ULL: goto x86_l_556b;
	case 21872ULL: goto x86_l_5570;
	case 21880ULL: goto x86_l_5578;
	case 21886ULL: goto x86_l_557e;
	case 21892ULL: goto x86_l_5584;
	case 21896ULL: goto x86_l_5588;
	case 21900ULL: goto x86_l_558c;
	case 21908ULL: goto x86_l_5594;
	case 21910ULL: goto x86_l_5596;
	case 21913ULL: goto x86_l_5599;
	case 21918ULL: goto x86_l_559e;
	case 21923ULL: goto x86_l_55a3;
	case 21927ULL: goto x86_l_55a7;
	case 21932ULL: goto x86_l_55ac;
	case 21934ULL: goto x86_l_55ae;
	case 21936ULL: goto x86_l_55b0;
	case 21942ULL: goto x86_l_55b6;
	case 21947ULL: goto x86_l_55bb;
	case 21955ULL: goto x86_l_55c3;
	case 21961ULL: goto x86_l_55c9;
	case 21967ULL: goto x86_l_55cf;
	case 21971ULL: goto x86_l_55d3;
	case 21975ULL: goto x86_l_55d7;
	case 21983ULL: goto x86_l_55df;
	case 21985ULL: goto x86_l_55e1;
	case 21988ULL: goto x86_l_55e4;
	case 21993ULL: goto x86_l_55e9;
	case 21998ULL: goto x86_l_55ee;
	case 22002ULL: goto x86_l_55f2;
	case 22007ULL: goto x86_l_55f7;
	case 22009ULL: goto x86_l_55f9;
	case 22011ULL: goto x86_l_55fb;
	case 22017ULL: goto x86_l_5601;
	case 22022ULL: goto x86_l_5606;
	case 22030ULL: goto x86_l_560e;
	case 22036ULL: goto x86_l_5614;
	case 22042ULL: goto x86_l_561a;
	case 22046ULL: goto x86_l_561e;
	case 22050ULL: goto x86_l_5622;
	case 22058ULL: goto x86_l_562a;
	case 22060ULL: goto x86_l_562c;
	case 22063ULL: goto x86_l_562f;
	case 22068ULL: goto x86_l_5634;
	case 22073ULL: goto x86_l_5639;
	case 22077ULL: goto x86_l_563d;
	case 22082ULL: goto x86_l_5642;
	case 22084ULL: goto x86_l_5644;
	case 22086ULL: goto x86_l_5646;
	case 22092ULL: goto x86_l_564c;
	case 22097ULL: goto x86_l_5651;
	case 22105ULL: goto x86_l_5659;
	case 22111ULL: goto x86_l_565f;
	case 22117ULL: goto x86_l_5665;
	case 22121ULL: goto x86_l_5669;
	case 22125ULL: goto x86_l_566d;
	case 22133ULL: goto x86_l_5675;
	case 22135ULL: goto x86_l_5677;
	case 22138ULL: goto x86_l_567a;
	case 22143ULL: goto x86_l_567f;
	case 22148ULL: goto x86_l_5684;
	case 22152ULL: goto x86_l_5688;
	case 22157ULL: goto x86_l_568d;
	case 22159ULL: goto x86_l_568f;
	case 22161ULL: goto x86_l_5691;
	case 22167ULL: goto x86_l_5697;
	case 22172ULL: goto x86_l_569c;
	case 22180ULL: goto x86_l_56a4;
	case 22186ULL: goto x86_l_56aa;
	case 22192ULL: goto x86_l_56b0;
	case 22196ULL: goto x86_l_56b4;
	case 22200ULL: goto x86_l_56b8;
	case 22208ULL: goto x86_l_56c0;
	case 22210ULL: goto x86_l_56c2;
	case 22213ULL: goto x86_l_56c5;
	case 22218ULL: goto x86_l_56ca;
	case 22223ULL: goto x86_l_56cf;
	case 22227ULL: goto x86_l_56d3;
	case 22232ULL: goto x86_l_56d8;
	case 22234ULL: goto x86_l_56da;
	case 22236ULL: goto x86_l_56dc;
	case 22242ULL: goto x86_l_56e2;
	case 22247ULL: goto x86_l_56e7;
	case 22255ULL: goto x86_l_56ef;
	case 22261ULL: goto x86_l_56f5;
	case 22267ULL: goto x86_l_56fb;
	case 22271ULL: goto x86_l_56ff;
	case 22275ULL: goto x86_l_5703;
	case 22283ULL: goto x86_l_570b;
	case 22289ULL: goto x86_l_5711;
	case 22292ULL: goto x86_l_5714;
	case 22297ULL: goto x86_l_5719;
	case 22302ULL: goto x86_l_571e;
	case 22307ULL: goto x86_l_5723;
	case 22310ULL: goto x86_l_5726;
	case 22312ULL: goto x86_l_5728;
	case 22315ULL: goto x86_l_572b;
	case 22320ULL: goto x86_l_5730;
	case 22325ULL: goto x86_l_5735;
	case 22329ULL: goto x86_l_5739;
	case 22334ULL: goto x86_l_573e;
	case 22336ULL: goto x86_l_5740;
	case 22338ULL: goto x86_l_5742;
	case 22344ULL: goto x86_l_5748;
	case 22349ULL: goto x86_l_574d;
	case 22357ULL: goto x86_l_5755;
	case 22363ULL: goto x86_l_575b;
	case 22369ULL: goto x86_l_5761;
	case 22373ULL: goto x86_l_5765;
	case 22377ULL: goto x86_l_5769;
	case 22385ULL: goto x86_l_5771;
	case 22387ULL: goto x86_l_5773;
	case 22390ULL: goto x86_l_5776;
	case 22395ULL: goto x86_l_577b;
	case 22400ULL: goto x86_l_5780;
	case 22404ULL: goto x86_l_5784;
	case 22409ULL: goto x86_l_5789;
	case 22411ULL: goto x86_l_578b;
	case 22413ULL: goto x86_l_578d;
	case 22419ULL: goto x86_l_5793;
	case 22424ULL: goto x86_l_5798;
	case 22432ULL: goto x86_l_57a0;
	case 22438ULL: goto x86_l_57a6;
	case 22444ULL: goto x86_l_57ac;
	case 22448ULL: goto x86_l_57b0;
	case 22452ULL: goto x86_l_57b4;
	case 22460ULL: goto x86_l_57bc;
	case 22462ULL: goto x86_l_57be;
	case 22465ULL: goto x86_l_57c1;
	case 22470ULL: goto x86_l_57c6;
	case 22475ULL: goto x86_l_57cb;
	case 22479ULL: goto x86_l_57cf;
	case 22484ULL: goto x86_l_57d4;
	case 22486ULL: goto x86_l_57d6;
	case 22488ULL: goto x86_l_57d8;
	case 22494ULL: goto x86_l_57de;
	case 22499ULL: goto x86_l_57e3;
	case 22507ULL: goto x86_l_57eb;
	case 22513ULL: goto x86_l_57f1;
	case 22519ULL: goto x86_l_57f7;
	case 22523ULL: goto x86_l_57fb;
	case 22527ULL: goto x86_l_57ff;
	case 22535ULL: goto x86_l_5807;
	case 22537ULL: goto x86_l_5809;
	case 22540ULL: goto x86_l_580c;
	case 22545ULL: goto x86_l_5811;
	case 22550ULL: goto x86_l_5816;
	case 22554ULL: goto x86_l_581a;
	case 22559ULL: goto x86_l_581f;
	case 22561ULL: goto x86_l_5821;
	case 22563ULL: goto x86_l_5823;
	case 22569ULL: goto x86_l_5829;
	case 22574ULL: goto x86_l_582e;
	case 22582ULL: goto x86_l_5836;
	case 22588ULL: goto x86_l_583c;
	case 22594ULL: goto x86_l_5842;
	case 22598ULL: goto x86_l_5846;
	case 22602ULL: goto x86_l_584a;
	case 22610ULL: goto x86_l_5852;
	case 22612ULL: goto x86_l_5854;
	case 22615ULL: goto x86_l_5857;
	case 22620ULL: goto x86_l_585c;
	case 22625ULL: goto x86_l_5861;
	case 22629ULL: goto x86_l_5865;
	case 22634ULL: goto x86_l_586a;
	case 22636ULL: goto x86_l_586c;
	case 22638ULL: goto x86_l_586e;
	case 22644ULL: goto x86_l_5874;
	case 22649ULL: goto x86_l_5879;
	case 22657ULL: goto x86_l_5881;
	case 22663ULL: goto x86_l_5887;
	case 22669ULL: goto x86_l_588d;
	case 22673ULL: goto x86_l_5891;
	case 22677ULL: goto x86_l_5895;
	case 22685ULL: goto x86_l_589d;
	case 22687ULL: goto x86_l_589f;
	case 22690ULL: goto x86_l_58a2;
	case 22695ULL: goto x86_l_58a7;
	case 22700ULL: goto x86_l_58ac;
	case 22704ULL: goto x86_l_58b0;
	case 22709ULL: goto x86_l_58b5;
	case 22711ULL: goto x86_l_58b7;
	case 22713ULL: goto x86_l_58b9;
	case 22719ULL: goto x86_l_58bf;
	case 22724ULL: goto x86_l_58c4;
	case 22732ULL: goto x86_l_58cc;
	case 22738ULL: goto x86_l_58d2;
	case 22744ULL: goto x86_l_58d8;
	case 22748ULL: goto x86_l_58dc;
	case 22752ULL: goto x86_l_58e0;
	case 22760ULL: goto x86_l_58e8;
	case 22762ULL: goto x86_l_58ea;
	case 22765ULL: goto x86_l_58ed;
	case 22770ULL: goto x86_l_58f2;
	case 22775ULL: goto x86_l_58f7;
	case 22779ULL: goto x86_l_58fb;
	case 22784ULL: goto x86_l_5900;
	case 22786ULL: goto x86_l_5902;
	case 22788ULL: goto x86_l_5904;
	case 22794ULL: goto x86_l_590a;
	case 22799ULL: goto x86_l_590f;
	case 22807ULL: goto x86_l_5917;
	case 22813ULL: goto x86_l_591d;
	case 22819ULL: goto x86_l_5923;
	case 22823ULL: goto x86_l_5927;
	case 22827ULL: goto x86_l_592b;
	case 22835ULL: goto x86_l_5933;
	case 22837ULL: goto x86_l_5935;
	case 22840ULL: goto x86_l_5938;
	case 22845ULL: goto x86_l_593d;
	case 22850ULL: goto x86_l_5942;
	case 22854ULL: goto x86_l_5946;
	case 22859ULL: goto x86_l_594b;
	case 22861ULL: goto x86_l_594d;
	case 22863ULL: goto x86_l_594f;
	case 22869ULL: goto x86_l_5955;
	case 22874ULL: goto x86_l_595a;
	case 22882ULL: goto x86_l_5962;
	case 22888ULL: goto x86_l_5968;
	case 22894ULL: goto x86_l_596e;
	case 22898ULL: goto x86_l_5972;
	case 22902ULL: goto x86_l_5976;
	case 22910ULL: goto x86_l_597e;
	case 22912ULL: goto x86_l_5980;
	case 22915ULL: goto x86_l_5983;
	case 22920ULL: goto x86_l_5988;
	case 22925ULL: goto x86_l_598d;
	case 22929ULL: goto x86_l_5991;
	case 22934ULL: goto x86_l_5996;
	case 22936ULL: goto x86_l_5998;
	case 22938ULL: goto x86_l_599a;
	case 22944ULL: goto x86_l_59a0;
	case 22949ULL: goto x86_l_59a5;
	case 22957ULL: goto x86_l_59ad;
	case 22963ULL: goto x86_l_59b3;
	case 22969ULL: goto x86_l_59b9;
	case 22973ULL: goto x86_l_59bd;
	case 22977ULL: goto x86_l_59c1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_52e8:
	/* 0x52e8: js     5b9a <generic_sleepable_preload+0x5b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23450ULL;
	}
x86_l_52ee:
	/* 0x52ee: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52f3:
	/* 0x52f3: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_52fb:
	/* 0x52fb: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_5301:
	/* 0x5301: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5307:
	/* 0x5307: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_530b:
	/* 0x530b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_530f:
	/* 0x530f: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5317:
	/* 0x5317: je     5339 <generic_sleepable_preload+0x5339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5339;
	}
x86_l_5319:
	/* 0x5319: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_531c:
	/* 0x531c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5321:
	/* 0x5321: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5326:
	/* 0x5326: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_532a:
	/* 0x532a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_532f:
	/* 0x532f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5331:
	/* 0x5331: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5333:
	/* 0x5333: js     5c27 <generic_sleepable_preload+0x5c27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23591ULL;
	}
x86_l_5339:
	/* 0x5339: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_533e:
	/* 0x533e: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5346:
	/* 0x5346: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_534c:
	/* 0x534c: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5352:
	/* 0x5352: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5356:
	/* 0x5356: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_535a:
	/* 0x535a: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5362:
	/* 0x5362: je     5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23141ULL;
	}
x86_l_5368:
	/* 0x5368: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_536b:
	/* 0x536b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5370:
	/* 0x5370: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5375:
	/* 0x5375: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5379:
	/* 0x5379: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_537e:
	/* 0x537e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5380:
	/* 0x5380: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5382:
	/* 0x5382: jns    5a65 <generic_sleepable_preload+0x5a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 23141ULL;
	}
x86_l_5388:
	/* 0x5388: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_538e:
	/* 0x538e: jmp    5a62 <generic_sleepable_preload+0x5a62> */
	return 23138ULL;
x86_l_5393:
	/* 0x5393: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5399:
	/* 0x5399: jmp    5a62 <generic_sleepable_preload+0x5a62> */
	return 23138ULL;
x86_l_539e:
	/* 0x539e: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_53a6:
	/* 0x53a6: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_53a9:
	/* 0x53a9: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540c;
	}
x86_l_53ab:
	/* 0x53ab: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53b0:
	/* 0x53b0: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_53b3:
	/* 0x53b3: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540c;
	}
x86_l_53b5:
	/* 0x53b5: jmp    541f <generic_sleepable_preload+0x541f> */
	goto x86_l_541f;
x86_l_53b7:
	/* 0x53b7: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_53bc:
	/* 0x53bc: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_53bf:
	/* 0x53bf: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540c;
	}
x86_l_53c1:
	/* 0x53c1: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_53c6:
	/* 0x53c6: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_53c9:
	/* 0x53c9: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540c;
	}
x86_l_53cb:
	/* 0x53cb: jmp    541f <generic_sleepable_preload+0x541f> */
	goto x86_l_541f;
x86_l_53cd:
	/* 0x53cd: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_53d5:
	/* 0x53d5: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_53d8:
	/* 0x53d8: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540c;
	}
x86_l_53da:
	/* 0x53da: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_53df:
	/* 0x53df: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_53e2:
	/* 0x53e2: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540c;
	}
x86_l_53e4:
	/* 0x53e4: jmp    541f <generic_sleepable_preload+0x541f> */
	goto x86_l_541f;
x86_l_53e6:
	/* 0x53e6: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_53eb:
	/* 0x53eb: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_53ee:
	/* 0x53ee: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540c;
	}
x86_l_53f0:
	/* 0x53f0: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_53f5:
	/* 0x53f5: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_53f8:
	/* 0x53f8: je     540c <generic_sleepable_preload+0x540c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540c;
	}
x86_l_53fa:
	/* 0x53fa: jmp    541f <generic_sleepable_preload+0x541f> */
	goto x86_l_541f;
x86_l_53fc:
	/* 0x53fc: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5402:
	/* 0x5402: jmp    5a62 <generic_sleepable_preload+0x5a62> */
	return 23138ULL;
x86_l_5407:
	/* 0x5407: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_540c:
	/* 0x540c: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_540f:
	/* 0x540f: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5411:
	/* 0x5411: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5413:
	/* 0x5413: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5418:
	/* 0x5418: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_541a:
	/* 0x541a: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_541f:
	/* 0x541f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5423:
	/* 0x5423: mov    ebx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5428:
	/* 0x5428: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_542b:
	/* 0x542b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_542e:
	/* 0x542e: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_5431:
	/* 0x5431: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5439:
	/* 0x5439: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_543f:
	/* 0x543f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5446:
	/* 0x5446: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5449:
	/* 0x5449: mov    eax,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_544f:
	/* 0x544f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5452:
	/* 0x5452: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5456:
	/* 0x5456: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_545d:
	/* 0x545d: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_545f:
	/* 0x545f: je     5723 <generic_sleepable_preload+0x5723> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5723;
	}
x86_l_5465:
	/* 0x5465: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5468:
	/* 0x5468: je     548a <generic_sleepable_preload+0x548a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_548a;
	}
x86_l_546a:
	/* 0x546a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_546d:
	/* 0x546d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5472:
	/* 0x5472: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5477:
	/* 0x5477: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_547b:
	/* 0x547b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5480:
	/* 0x5480: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5482:
	/* 0x5482: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5484:
	/* 0x5484: js     59fa <generic_sleepable_preload+0x59fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23034ULL;
	}
x86_l_548a:
	/* 0x548a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_548f:
	/* 0x548f: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5497:
	/* 0x5497: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_549d:
	/* 0x549d: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_54a3:
	/* 0x54a3: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_54a7:
	/* 0x54a7: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54ab:
	/* 0x54ab: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_54b3:
	/* 0x54b3: je     54d5 <generic_sleepable_preload+0x54d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54d5;
	}
x86_l_54b5:
	/* 0x54b5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_54b8:
	/* 0x54b8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54bd:
	/* 0x54bd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54c2:
	/* 0x54c2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54c6:
	/* 0x54c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54cb:
	/* 0x54cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54cd:
	/* 0x54cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54cf:
	/* 0x54cf: js     5a05 <generic_sleepable_preload+0x5a05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23045ULL;
	}
x86_l_54d5:
	/* 0x54d5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54da:
	/* 0x54da: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_54e2:
	/* 0x54e2: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_54e8:
	/* 0x54e8: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_54ee:
	/* 0x54ee: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_54f2:
	/* 0x54f2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54f6:
	/* 0x54f6: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_54fe:
	/* 0x54fe: je     5520 <generic_sleepable_preload+0x5520> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5520;
	}
x86_l_5500:
	/* 0x5500: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5503:
	/* 0x5503: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5508:
	/* 0x5508: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_550d:
	/* 0x550d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5511:
	/* 0x5511: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5516:
	/* 0x5516: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5518:
	/* 0x5518: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_551a:
	/* 0x551a: js     5a18 <generic_sleepable_preload+0x5a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23064ULL;
	}
x86_l_5520:
	/* 0x5520: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5525:
	/* 0x5525: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_552d:
	/* 0x552d: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_5533:
	/* 0x5533: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5539:
	/* 0x5539: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_553d:
	/* 0x553d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5541:
	/* 0x5541: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5549:
	/* 0x5549: je     556b <generic_sleepable_preload+0x556b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_556b;
	}
x86_l_554b:
	/* 0x554b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_554e:
	/* 0x554e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5553:
	/* 0x5553: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5558:
	/* 0x5558: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_555c:
	/* 0x555c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5561:
	/* 0x5561: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5563:
	/* 0x5563: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5565:
	/* 0x5565: js     5a2b <generic_sleepable_preload+0x5a2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23083ULL;
	}
x86_l_556b:
	/* 0x556b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5570:
	/* 0x5570: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5578:
	/* 0x5578: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_557e:
	/* 0x557e: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5584:
	/* 0x5584: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5588:
	/* 0x5588: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_558c:
	/* 0x558c: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5594:
	/* 0x5594: je     55b6 <generic_sleepable_preload+0x55b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55b6;
	}
x86_l_5596:
	/* 0x5596: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5599:
	/* 0x5599: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_559e:
	/* 0x559e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55a3:
	/* 0x55a3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55a7:
	/* 0x55a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55ac:
	/* 0x55ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55ae:
	/* 0x55ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55b0:
	/* 0x55b0: js     5a3e <generic_sleepable_preload+0x5a3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23102ULL;
	}
x86_l_55b6:
	/* 0x55b6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55bb:
	/* 0x55bb: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_55c3:
	/* 0x55c3: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_55c9:
	/* 0x55c9: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_55cf:
	/* 0x55cf: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_55d3:
	/* 0x55d3: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55d7:
	/* 0x55d7: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_55df:
	/* 0x55df: je     5601 <generic_sleepable_preload+0x5601> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5601;
	}
x86_l_55e1:
	/* 0x55e1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55e4:
	/* 0x55e4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55e9:
	/* 0x55e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55ee:
	/* 0x55ee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55f2:
	/* 0x55f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55f7:
	/* 0x55f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f9:
	/* 0x55f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55fb:
	/* 0x55fb: js     5a51 <generic_sleepable_preload+0x5a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23121ULL;
	}
x86_l_5601:
	/* 0x5601: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5606:
	/* 0x5606: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_560e:
	/* 0x560e: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_5614:
	/* 0x5614: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_561a:
	/* 0x561a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_561e:
	/* 0x561e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5622:
	/* 0x5622: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_562a:
	/* 0x562a: je     564c <generic_sleepable_preload+0x564c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_564c;
	}
x86_l_562c:
	/* 0x562c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_562f:
	/* 0x562f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5634:
	/* 0x5634: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5639:
	/* 0x5639: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_563d:
	/* 0x563d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5642:
	/* 0x5642: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5644:
	/* 0x5644: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5646:
	/* 0x5646: js     5ae8 <generic_sleepable_preload+0x5ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23272ULL;
	}
x86_l_564c:
	/* 0x564c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5651:
	/* 0x5651: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5659:
	/* 0x5659: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_565f:
	/* 0x565f: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5665:
	/* 0x5665: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5669:
	/* 0x5669: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_566d:
	/* 0x566d: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5675:
	/* 0x5675: je     5697 <generic_sleepable_preload+0x5697> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5697;
	}
x86_l_5677:
	/* 0x5677: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_567a:
	/* 0x567a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_567f:
	/* 0x567f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5684:
	/* 0x5684: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5688:
	/* 0x5688: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_568d:
	/* 0x568d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_568f:
	/* 0x568f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5691:
	/* 0x5691: js     5ba8 <generic_sleepable_preload+0x5ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23464ULL;
	}
x86_l_5697:
	/* 0x5697: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_569c:
	/* 0x569c: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_56a4:
	/* 0x56a4: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_56aa:
	/* 0x56aa: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_56b0:
	/* 0x56b0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_56b4:
	/* 0x56b4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56b8:
	/* 0x56b8: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_56c0:
	/* 0x56c0: je     56e2 <generic_sleepable_preload+0x56e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e2;
	}
x86_l_56c2:
	/* 0x56c2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_56c5:
	/* 0x56c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56ca:
	/* 0x56ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56cf:
	/* 0x56cf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56d3:
	/* 0x56d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56d8:
	/* 0x56d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56da:
	/* 0x56da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56dc:
	/* 0x56dc: js     5c32 <generic_sleepable_preload+0x5c32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23602ULL;
	}
x86_l_56e2:
	/* 0x56e2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e7:
	/* 0x56e7: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_56ef:
	/* 0x56ef: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_56f5:
	/* 0x56f5: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_56fb:
	/* 0x56fb: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_56ff:
	/* 0x56ff: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5703:
	/* 0x5703: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_570b:
	/* 0x570b: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_5711:
	/* 0x5711: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5714:
	/* 0x5714: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5719:
	/* 0x5719: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_571e:
	/* 0x571e: jmp    59dc <generic_sleepable_preload+0x59dc> */
	return 23004ULL;
x86_l_5723:
	/* 0x5723: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5726:
	/* 0x5726: je     5748 <generic_sleepable_preload+0x5748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5748;
	}
x86_l_5728:
	/* 0x5728: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_572b:
	/* 0x572b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5730:
	/* 0x5730: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5735:
	/* 0x5735: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5739:
	/* 0x5739: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_573e:
	/* 0x573e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5740:
	/* 0x5740: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5742:
	/* 0x5742: js     59fa <generic_sleepable_preload+0x59fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23034ULL;
	}
x86_l_5748:
	/* 0x5748: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_574d:
	/* 0x574d: cmp    WORD PTR [rax+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5755:
	/* 0x5755: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_575b:
	/* 0x575b: mov    ecx,DWORD PTR [rax+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5761:
	/* 0x5761: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5765:
	/* 0x5765: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5769:
	/* 0x5769: cmp    WORD PTR [rax+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5771:
	/* 0x5771: je     5793 <generic_sleepable_preload+0x5793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5793;
	}
x86_l_5773:
	/* 0x5773: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5776:
	/* 0x5776: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_577b:
	/* 0x577b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5780:
	/* 0x5780: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5784:
	/* 0x5784: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5789:
	/* 0x5789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_578b:
	/* 0x578b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_578d:
	/* 0x578d: js     5a05 <generic_sleepable_preload+0x5a05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23045ULL;
	}
x86_l_5793:
	/* 0x5793: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5798:
	/* 0x5798: cmp    WORD PTR [rax+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_57a0:
	/* 0x57a0: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_57a6:
	/* 0x57a6: mov    ecx,DWORD PTR [rax+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_57ac:
	/* 0x57ac: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_57b0:
	/* 0x57b0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57b4:
	/* 0x57b4: cmp    WORD PTR [rax+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_57bc:
	/* 0x57bc: je     57de <generic_sleepable_preload+0x57de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57de;
	}
x86_l_57be:
	/* 0x57be: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_57c1:
	/* 0x57c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57c6:
	/* 0x57c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57cb:
	/* 0x57cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57cf:
	/* 0x57cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57d4:
	/* 0x57d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57d6:
	/* 0x57d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57d8:
	/* 0x57d8: js     5a18 <generic_sleepable_preload+0x5a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23064ULL;
	}
x86_l_57de:
	/* 0x57de: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57e3:
	/* 0x57e3: cmp    WORD PTR [rax+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_57eb:
	/* 0x57eb: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_57f1:
	/* 0x57f1: mov    ecx,DWORD PTR [rax+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_57f7:
	/* 0x57f7: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_57fb:
	/* 0x57fb: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57ff:
	/* 0x57ff: cmp    WORD PTR [rax+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5807:
	/* 0x5807: je     5829 <generic_sleepable_preload+0x5829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5829;
	}
x86_l_5809:
	/* 0x5809: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_580c:
	/* 0x580c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5811:
	/* 0x5811: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5816:
	/* 0x5816: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_581a:
	/* 0x581a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_581f:
	/* 0x581f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5821:
	/* 0x5821: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5823:
	/* 0x5823: js     5a2b <generic_sleepable_preload+0x5a2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23083ULL;
	}
x86_l_5829:
	/* 0x5829: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_582e:
	/* 0x582e: cmp    WORD PTR [rax+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5836:
	/* 0x5836: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_583c:
	/* 0x583c: mov    ecx,DWORD PTR [rax+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5842:
	/* 0x5842: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5846:
	/* 0x5846: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_584a:
	/* 0x584a: cmp    WORD PTR [rax+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5852:
	/* 0x5852: je     5874 <generic_sleepable_preload+0x5874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5874;
	}
x86_l_5854:
	/* 0x5854: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5857:
	/* 0x5857: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_585c:
	/* 0x585c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5861:
	/* 0x5861: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5865:
	/* 0x5865: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_586a:
	/* 0x586a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_586c:
	/* 0x586c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_586e:
	/* 0x586e: js     5a3e <generic_sleepable_preload+0x5a3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23102ULL;
	}
x86_l_5874:
	/* 0x5874: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5879:
	/* 0x5879: cmp    WORD PTR [rax+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5881:
	/* 0x5881: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_5887:
	/* 0x5887: mov    ecx,DWORD PTR [rax+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_588d:
	/* 0x588d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5891:
	/* 0x5891: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5895:
	/* 0x5895: cmp    WORD PTR [rax+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_589d:
	/* 0x589d: je     58bf <generic_sleepable_preload+0x58bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58bf;
	}
x86_l_589f:
	/* 0x589f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58a2:
	/* 0x58a2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58a7:
	/* 0x58a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58ac:
	/* 0x58ac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58b0:
	/* 0x58b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58b5:
	/* 0x58b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58b7:
	/* 0x58b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58b9:
	/* 0x58b9: js     5a51 <generic_sleepable_preload+0x5a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23121ULL;
	}
x86_l_58bf:
	/* 0x58bf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58c4:
	/* 0x58c4: cmp    WORD PTR [rax+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_58cc:
	/* 0x58cc: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_58d2:
	/* 0x58d2: mov    ecx,DWORD PTR [rax+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_58d8:
	/* 0x58d8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_58dc:
	/* 0x58dc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58e0:
	/* 0x58e0: cmp    WORD PTR [rax+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_58e8:
	/* 0x58e8: je     590a <generic_sleepable_preload+0x590a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_590a;
	}
x86_l_58ea:
	/* 0x58ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58ed:
	/* 0x58ed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58f2:
	/* 0x58f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58f7:
	/* 0x58f7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58fb:
	/* 0x58fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5900:
	/* 0x5900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5902:
	/* 0x5902: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5904:
	/* 0x5904: js     5ae8 <generic_sleepable_preload+0x5ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23272ULL;
	}
x86_l_590a:
	/* 0x590a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_590f:
	/* 0x590f: cmp    WORD PTR [rax+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5917:
	/* 0x5917: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_591d:
	/* 0x591d: mov    ecx,DWORD PTR [rax+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5923:
	/* 0x5923: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5927:
	/* 0x5927: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_592b:
	/* 0x592b: cmp    WORD PTR [rax+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5933:
	/* 0x5933: je     5955 <generic_sleepable_preload+0x5955> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5955;
	}
x86_l_5935:
	/* 0x5935: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5938:
	/* 0x5938: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_593d:
	/* 0x593d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5942:
	/* 0x5942: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5946:
	/* 0x5946: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_594b:
	/* 0x594b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_594d:
	/* 0x594d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_594f:
	/* 0x594f: js     5ba8 <generic_sleepable_preload+0x5ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23464ULL;
	}
x86_l_5955:
	/* 0x5955: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_595a:
	/* 0x595a: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5962:
	/* 0x5962: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_5968:
	/* 0x5968: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_596e:
	/* 0x596e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5972:
	/* 0x5972: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5976:
	/* 0x5976: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_597e:
	/* 0x597e: je     59a0 <generic_sleepable_preload+0x59a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59a0;
	}
x86_l_5980:
	/* 0x5980: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5983:
	/* 0x5983: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5988:
	/* 0x5988: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_598d:
	/* 0x598d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5991:
	/* 0x5991: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5996:
	/* 0x5996: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5998:
	/* 0x5998: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_599a:
	/* 0x599a: js     5c32 <generic_sleepable_preload+0x5c32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23602ULL;
	}
x86_l_59a0:
	/* 0x59a0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a5:
	/* 0x59a5: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_59ad:
	/* 0x59ad: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23281ULL;
	}
x86_l_59b3:
	/* 0x59b3: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_59b9:
	/* 0x59b9: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_59bd:
	/* 0x59bd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59c1:
	/* 0x59c1: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
	return 22985ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22985ULL: goto x86_l_59c9;
	case 22991ULL: goto x86_l_59cf;
	case 22994ULL: goto x86_l_59d2;
	case 22999ULL: goto x86_l_59d7;
	case 23004ULL: goto x86_l_59dc;
	case 23008ULL: goto x86_l_59e0;
	case 23013ULL: goto x86_l_59e5;
	case 23015ULL: goto x86_l_59e7;
	case 23017ULL: goto x86_l_59e9;
	case 23023ULL: goto x86_l_59ef;
	case 23029ULL: goto x86_l_59f5;
	case 23034ULL: goto x86_l_59fa;
	case 23040ULL: goto x86_l_5a00;
	case 23045ULL: goto x86_l_5a05;
	case 23051ULL: goto x86_l_5a0b;
	case 23056ULL: goto x86_l_5a10;
	case 23062ULL: goto x86_l_5a16;
	case 23064ULL: goto x86_l_5a18;
	case 23070ULL: goto x86_l_5a1e;
	case 23075ULL: goto x86_l_5a23;
	case 23081ULL: goto x86_l_5a29;
	case 23083ULL: goto x86_l_5a2b;
	case 23089ULL: goto x86_l_5a31;
	case 23094ULL: goto x86_l_5a36;
	case 23100ULL: goto x86_l_5a3c;
	case 23102ULL: goto x86_l_5a3e;
	case 23108ULL: goto x86_l_5a44;
	case 23113ULL: goto x86_l_5a49;
	case 23119ULL: goto x86_l_5a4f;
	case 23121ULL: goto x86_l_5a51;
	case 23127ULL: goto x86_l_5a57;
	case 23132ULL: goto x86_l_5a5c;
	case 23138ULL: goto x86_l_5a62;
	case 23141ULL: goto x86_l_5a65;
	case 23146ULL: goto x86_l_5a6a;
	case 23149ULL: goto x86_l_5a6d;
	case 23152ULL: goto x86_l_5a70;
	case 23157ULL: goto x86_l_5a75;
	case 23162ULL: goto x86_l_5a7a;
	case 23167ULL: goto x86_l_5a7f;
	case 23170ULL: goto x86_l_5a82;
	case 23172ULL: goto x86_l_5a84;
	case 23175ULL: goto x86_l_5a87;
	case 23181ULL: goto x86_l_5a8d;
	case 23185ULL: goto x86_l_5a91;
	case 23190ULL: goto x86_l_5a96;
	case 23192ULL: goto x86_l_5a98;
	case 23197ULL: goto x86_l_5a9d;
	case 23205ULL: goto x86_l_5aa5;
	case 23212ULL: goto x86_l_5aac;
	case 23217ULL: goto x86_l_5ab1;
	case 23222ULL: goto x86_l_5ab6;
	case 23224ULL: goto x86_l_5ab8;
	case 23227ULL: goto x86_l_5abb;
	case 23233ULL: goto x86_l_5ac1;
	case 23236ULL: goto x86_l_5ac4;
	case 23243ULL: goto x86_l_5acb;
	case 23245ULL: goto x86_l_5acd;
	case 23250ULL: goto x86_l_5ad2;
	case 23255ULL: goto x86_l_5ad7;
	case 23258ULL: goto x86_l_5ada;
	case 23261ULL: goto x86_l_5add;
	case 23263ULL: goto x86_l_5adf;
	case 23265ULL: goto x86_l_5ae1;
	case 23270ULL: goto x86_l_5ae6;
	case 23272ULL: goto x86_l_5ae8;
	case 23278ULL: goto x86_l_5aee;
	case 23281ULL: goto x86_l_5af1;
	case 23284ULL: goto x86_l_5af4;
	case 23290ULL: goto x86_l_5afa;
	case 23294ULL: goto x86_l_5afe;
	case 23299ULL: goto x86_l_5b03;
	case 23301ULL: goto x86_l_5b05;
	case 23306ULL: goto x86_l_5b0a;
	case 23314ULL: goto x86_l_5b12;
	case 23321ULL: goto x86_l_5b19;
	case 23326ULL: goto x86_l_5b1e;
	case 23331ULL: goto x86_l_5b23;
	case 23333ULL: goto x86_l_5b25;
	case 23336ULL: goto x86_l_5b28;
	case 23342ULL: goto x86_l_5b2e;
	case 23345ULL: goto x86_l_5b31;
	case 23352ULL: goto x86_l_5b38;
	case 23354ULL: goto x86_l_5b3a;
	case 23359ULL: goto x86_l_5b3f;
	case 23364ULL: goto x86_l_5b44;
	case 23367ULL: goto x86_l_5b47;
	case 23370ULL: goto x86_l_5b4a;
	case 23372ULL: goto x86_l_5b4c;
	case 23374ULL: goto x86_l_5b4e;
	case 23379ULL: goto x86_l_5b53;
	case 23382ULL: goto x86_l_5b56;
	case 23385ULL: goto x86_l_5b59;
	case 23387ULL: goto x86_l_5b5b;
	case 23390ULL: goto x86_l_5b5e;
	case 23396ULL: goto x86_l_5b64;
	case 23399ULL: goto x86_l_5b67;
	case 23401ULL: goto x86_l_5b69;
	case 23404ULL: goto x86_l_5b6c;
	case 23408ULL: goto x86_l_5b70;
	case 23413ULL: goto x86_l_5b75;
	case 23416ULL: goto x86_l_5b78;
	case 23418ULL: goto x86_l_5b7a;
	case 23421ULL: goto x86_l_5b7d;
	case 23426ULL: goto x86_l_5b82;
	case 23428ULL: goto x86_l_5b84;
	case 23431ULL: goto x86_l_5b87;
	case 23433ULL: goto x86_l_5b89;
	case 23438ULL: goto x86_l_5b8e;
	case 23442ULL: goto x86_l_5b92;
	case 23445ULL: goto x86_l_5b95;
	case 23450ULL: goto x86_l_5b9a;
	case 23453ULL: goto x86_l_5b9d;
	case 23459ULL: goto x86_l_5ba3;
	case 23464ULL: goto x86_l_5ba8;
	case 23467ULL: goto x86_l_5bab;
	case 23473ULL: goto x86_l_5bb1;
	case 23476ULL: goto x86_l_5bb4;
	case 23482ULL: goto x86_l_5bba;
	case 23487ULL: goto x86_l_5bbf;
	case 23490ULL: goto x86_l_5bc2;
	case 23495ULL: goto x86_l_5bc7;
	case 23500ULL: goto x86_l_5bcc;
	case 23503ULL: goto x86_l_5bcf;
	case 23508ULL: goto x86_l_5bd4;
	case 23513ULL: goto x86_l_5bd9;
	case 23516ULL: goto x86_l_5bdc;
	case 23521ULL: goto x86_l_5be1;
	case 23526ULL: goto x86_l_5be6;
	case 23529ULL: goto x86_l_5be9;
	case 23534ULL: goto x86_l_5bee;
	case 23539ULL: goto x86_l_5bf3;
	case 23542ULL: goto x86_l_5bf6;
	case 23547ULL: goto x86_l_5bfb;
	case 23552ULL: goto x86_l_5c00;
	case 23555ULL: goto x86_l_5c03;
	case 23560ULL: goto x86_l_5c08;
	case 23565ULL: goto x86_l_5c0d;
	case 23568ULL: goto x86_l_5c10;
	case 23573ULL: goto x86_l_5c15;
	case 23578ULL: goto x86_l_5c1a;
	case 23581ULL: goto x86_l_5c1d;
	case 23586ULL: goto x86_l_5c22;
	case 23591ULL: goto x86_l_5c27;
	case 23597ULL: goto x86_l_5c2d;
	case 23602ULL: goto x86_l_5c32;
	case 23608ULL: goto x86_l_5c38;
	case 23613ULL: goto x86_l_5c3d;
	case 23616ULL: goto x86_l_5c40;
	case 23621ULL: goto x86_l_5c45;
	case 23626ULL: goto x86_l_5c4a;
	case 23629ULL: goto x86_l_5c4d;
	case 23634ULL: goto x86_l_5c52;
	case 23639ULL: goto x86_l_5c57;
	case 23642ULL: goto x86_l_5c5a;
	case 23647ULL: goto x86_l_5c5f;
	case 23652ULL: goto x86_l_5c64;
	case 23655ULL: goto x86_l_5c67;
	case 23660ULL: goto x86_l_5c6c;
	case 23665ULL: goto x86_l_5c71;
	case 23668ULL: goto x86_l_5c74;
	case 23673ULL: goto x86_l_5c79;
	case 23678ULL: goto x86_l_5c7e;
	case 23681ULL: goto x86_l_5c81;
	case 23686ULL: goto x86_l_5c86;
	case 23691ULL: goto x86_l_5c8b;
	case 23694ULL: goto x86_l_5c8e;
	case 23699ULL: goto x86_l_5c93;
	case 23704ULL: goto x86_l_5c98;
	case 23707ULL: goto x86_l_5c9b;
	case 23712ULL: goto x86_l_5ca0;
	case 23717ULL: goto x86_l_5ca5;
	case 23722ULL: goto x86_l_5caa;
	case 23725ULL: goto x86_l_5cad;
	case 23730ULL: goto x86_l_5cb2;
	case 23735ULL: goto x86_l_5cb7;
	case 23740ULL: goto x86_l_5cbc;
	case 23743ULL: goto x86_l_5cbf;
	case 23748ULL: goto x86_l_5cc4;
	case 23753ULL: goto x86_l_5cc9;
	case 23758ULL: goto x86_l_5cce;
	case 23761ULL: goto x86_l_5cd1;
	case 23766ULL: goto x86_l_5cd6;
	case 23771ULL: goto x86_l_5cdb;
	case 23776ULL: goto x86_l_5ce0;
	case 23779ULL: goto x86_l_5ce3;
	case 23784ULL: goto x86_l_5ce8;
	case 23789ULL: goto x86_l_5ced;
	case 23794ULL: goto x86_l_5cf2;
	case 23797ULL: goto x86_l_5cf5;
	case 23802ULL: goto x86_l_5cfa;
	case 23807ULL: goto x86_l_5cff;
	case 23812ULL: goto x86_l_5d04;
	case 23815ULL: goto x86_l_5d07;
	case 23820ULL: goto x86_l_5d0c;
	case 23825ULL: goto x86_l_5d11;
	case 23830ULL: goto x86_l_5d16;
	case 23833ULL: goto x86_l_5d19;
	case 23838ULL: goto x86_l_5d1e;
	case 23843ULL: goto x86_l_5d23;
	case 23848ULL: goto x86_l_5d28;
	case 23851ULL: goto x86_l_5d2b;
	case 23856ULL: goto x86_l_5d30;
	case 23861ULL: goto x86_l_5d35;
	case 23866ULL: goto x86_l_5d3a;
	case 23869ULL: goto x86_l_5d3d;
	case 23874ULL: goto x86_l_5d42;
	case 23877ULL: goto x86_l_5d45;
	case 23882ULL: goto x86_l_5d4a;
	case 23887ULL: goto x86_l_5d4f;
	case 23890ULL: goto x86_l_5d52;
	case 23895ULL: goto x86_l_5d57;
	case 23898ULL: goto x86_l_5d5a;
	case 23903ULL: goto x86_l_5d5f;
	case 23908ULL: goto x86_l_5d64;
	case 23911ULL: goto x86_l_5d67;
	case 23916ULL: goto x86_l_5d6c;
	case 23919ULL: goto x86_l_5d6f;
	case 23924ULL: goto x86_l_5d74;
	case 23929ULL: goto x86_l_5d79;
	case 23932ULL: goto x86_l_5d7c;
	case 23937ULL: goto x86_l_5d81;
	case 23940ULL: goto x86_l_5d84;
	case 23945ULL: goto x86_l_5d89;
	case 23950ULL: goto x86_l_5d8e;
	case 23953ULL: goto x86_l_5d91;
	case 23958ULL: goto x86_l_5d96;
	case 23961ULL: goto x86_l_5d99;
	case 23966ULL: goto x86_l_5d9e;
	case 23971ULL: goto x86_l_5da3;
	case 23974ULL: goto x86_l_5da6;
	case 23979ULL: goto x86_l_5dab;
	case 23982ULL: goto x86_l_5dae;
	case 23987ULL: goto x86_l_5db3;
	case 23992ULL: goto x86_l_5db8;
	case 23995ULL: goto x86_l_5dbb;
	case 24000ULL: goto x86_l_5dc0;
	case 24003ULL: goto x86_l_5dc3;
	case 24008ULL: goto x86_l_5dc8;
	case 24013ULL: goto x86_l_5dcd;
	case 24016ULL: goto x86_l_5dd0;
	case 24021ULL: goto x86_l_5dd5;
	case 24024ULL: goto x86_l_5dd8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_59c9:
	/* 0x59c9: je     5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5af1;
	}
x86_l_59cf:
	/* 0x59cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_59d2:
	/* 0x59d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59d7:
	/* 0x59d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59dc:
	/* 0x59dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59e0:
	/* 0x59e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59e5:
	/* 0x59e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59e7:
	/* 0x59e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59e9:
	/* 0x59e9: jns    5af1 <generic_sleepable_preload+0x5af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5af1;
	}
x86_l_59ef:
	/* 0x59ef: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_59f5:
	/* 0x59f5: jmp    5aee <generic_sleepable_preload+0x5aee> */
	goto x86_l_5aee;
x86_l_59fa:
	/* 0x59fa: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5a00:
	/* 0x5a00: jmp    5aee <generic_sleepable_preload+0x5aee> */
	goto x86_l_5aee;
x86_l_5a05:
	/* 0x5a05: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5a0b:
	/* 0x5a0b: jmp    5aee <generic_sleepable_preload+0x5aee> */
	goto x86_l_5aee;
x86_l_5a10:
	/* 0x5a10: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5a16:
	/* 0x5a16: jmp    5a62 <generic_sleepable_preload+0x5a62> */
	goto x86_l_5a62;
x86_l_5a18:
	/* 0x5a18: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5a1e:
	/* 0x5a1e: jmp    5aee <generic_sleepable_preload+0x5aee> */
	goto x86_l_5aee;
x86_l_5a23:
	/* 0x5a23: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_5a29:
	/* 0x5a29: jmp    5a62 <generic_sleepable_preload+0x5a62> */
	goto x86_l_5a62;
x86_l_5a2b:
	/* 0x5a2b: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_5a31:
	/* 0x5a31: jmp    5aee <generic_sleepable_preload+0x5aee> */
	goto x86_l_5aee;
x86_l_5a36:
	/* 0x5a36: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_5a3c:
	/* 0x5a3c: jmp    5a62 <generic_sleepable_preload+0x5a62> */
	goto x86_l_5a62;
x86_l_5a3e:
	/* 0x5a3e: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_5a44:
	/* 0x5a44: jmp    5aee <generic_sleepable_preload+0x5aee> */
	goto x86_l_5aee;
x86_l_5a49:
	/* 0x5a49: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_5a4f:
	/* 0x5a4f: jmp    5a62 <generic_sleepable_preload+0x5a62> */
	goto x86_l_5a62;
x86_l_5a51:
	/* 0x5a51: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_5a57:
	/* 0x5a57: jmp    5aee <generic_sleepable_preload+0x5aee> */
	goto x86_l_5aee;
x86_l_5a5c:
	/* 0x5a5c: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_5a62:
	/* 0x5a62: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a65:
	/* 0x5a65: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a6a:
	/* 0x5a6a: mov    ebx,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5a6d:
	/* 0x5a6d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5a70:
	/* 0x5a70: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a75:
	/* 0x5a75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a7a:
	/* 0x5a7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a7f:
	/* 0x5a7f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_5a82:
	/* 0x5a82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a84:
	/* 0x5a84: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5a87:
	/* 0x5a87: jne    4c70 <generic_sleepable_preload+0x4c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19568ULL;
	}
x86_l_5a8d:
	/* 0x5a8d: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a91:
	/* 0x5a91: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5a96:
	/* 0x5a96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a98:
	/* 0x5a98: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a9d:
	/* 0x5a9d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5aa5:
	/* 0x5aa5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5aac:
	/* 0x5aac: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5ab1:
	/* 0x5ab1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ab6:
	/* 0x5ab6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ab8:
	/* 0x5ab8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5abb:
	/* 0x5abb: je     4c70 <generic_sleepable_preload+0x4c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19568ULL;
	}
x86_l_5ac1:
	/* 0x5ac1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ac4:
	/* 0x5ac4: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5acb:
	/* 0x5acb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5acd:
	/* 0x5acd: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ad2:
	/* 0x5ad2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ad7:
	/* 0x5ad7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5ada:
	/* 0x5ada: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5add:
	/* 0x5add: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5adf:
	/* 0x5adf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ae1:
	/* 0x5ae1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ae6:
	/* 0x5ae6: jmp    5b53 <generic_sleepable_preload+0x5b53> */
	goto x86_l_5b53;
x86_l_5ae8:
	/* 0x5ae8: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_5aee:
	/* 0x5aee: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5af1:
	/* 0x5af1: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5af4:
	/* 0x5af4: jne    4c70 <generic_sleepable_preload+0x4c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19568ULL;
	}
x86_l_5afa:
	/* 0x5afa: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5afe:
	/* 0x5afe: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5b03:
	/* 0x5b03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b05:
	/* 0x5b05: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b0a:
	/* 0x5b0a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5b12:
	/* 0x5b12: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5b19:
	/* 0x5b19: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5b1e:
	/* 0x5b1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b23:
	/* 0x5b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b25:
	/* 0x5b25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b28:
	/* 0x5b28: je     4c70 <generic_sleepable_preload+0x4c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19568ULL;
	}
x86_l_5b2e:
	/* 0x5b2e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5b31:
	/* 0x5b31: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5b38:
	/* 0x5b38: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b3a:
	/* 0x5b3a: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b3f:
	/* 0x5b3f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b44:
	/* 0x5b44: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5b47:
	/* 0x5b47: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5b4a:
	/* 0x5b4a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b4c:
	/* 0x5b4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b4e:
	/* 0x5b4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b53:
	/* 0x5b53: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5b56:
	/* 0x5b56: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5b59:
	/* 0x5b59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b5b:
	/* 0x5b5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b5e:
	/* 0x5b5e: je     4c70 <generic_sleepable_preload+0x4c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19568ULL;
	}
x86_l_5b64:
	/* 0x5b64: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_5b67:
	/* 0x5b67: je     5b92 <generic_sleepable_preload+0x5b92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b92;
	}
x86_l_5b69:
	/* 0x5b69: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5b6c:
	/* 0x5b6c: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_5b70:
	/* 0x5b70: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5b75:
	/* 0x5b75: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5b78:
	/* 0x5b78: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b7a:
	/* 0x5b7a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5b7d:
	/* 0x5b7d: call   5b82 <generic_sleepable_preload+0x5b82> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_5b82:
	/* 0x5b82: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5b84:
	/* 0x5b84: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5b87:
	/* 0x5b87: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5b89:
	/* 0x5b89: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_5b8e:
	/* 0x5b8e: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5b92:
	/* 0x5b92: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b95:
	/* 0x5b95: jmp    4c70 <generic_sleepable_preload+0x4c70> */
	return 19568ULL;
x86_l_5b9a:
	/* 0x5b9a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b9d:
	/* 0x5b9d: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_5ba3:
	/* 0x5ba3: jmp    5a65 <generic_sleepable_preload+0x5a65> */
	goto x86_l_5a65;
x86_l_5ba8:
	/* 0x5ba8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bab:
	/* 0x5bab: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_5bb1:
	/* 0x5bb1: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5bb4:
	/* 0x5bb4: jne    4c70 <generic_sleepable_preload+0x4c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19568ULL;
	}
x86_l_5bba:
	/* 0x5bba: jmp    5afa <generic_sleepable_preload+0x5afa> */
	goto x86_l_5afa;
x86_l_5bbf:
	/* 0x5bbf: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bc2:
	/* 0x5bc2: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bc7:
	/* 0x5bc7: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	return 7412ULL;
x86_l_5bcc:
	/* 0x5bcc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bcf:
	/* 0x5bcf: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bd4:
	/* 0x5bd4: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	return 7551ULL;
x86_l_5bd9:
	/* 0x5bd9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bdc:
	/* 0x5bdc: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5be1:
	/* 0x5be1: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	return 11358ULL;
x86_l_5be6:
	/* 0x5be6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5be9:
	/* 0x5be9: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bee:
	/* 0x5bee: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	return 11497ULL;
x86_l_5bf3:
	/* 0x5bf3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bf6:
	/* 0x5bf6: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5bfb:
	/* 0x5bfb: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	return 15305ULL;
x86_l_5c00:
	/* 0x5c00: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c03:
	/* 0x5c03: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c08:
	/* 0x5c08: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	return 15444ULL;
x86_l_5c0d:
	/* 0x5c0d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c10:
	/* 0x5c10: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c15:
	/* 0x5c15: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	return 19252ULL;
x86_l_5c1a:
	/* 0x5c1a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c1d:
	/* 0x5c1d: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c22:
	/* 0x5c22: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	return 19391ULL;
x86_l_5c27:
	/* 0x5c27: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_5c2d:
	/* 0x5c2d: jmp    5a62 <generic_sleepable_preload+0x5a62> */
	goto x86_l_5a62;
x86_l_5c32:
	/* 0x5c32: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_5c38:
	/* 0x5c38: jmp    5aee <generic_sleepable_preload+0x5aee> */
	goto x86_l_5aee;
x86_l_5c3d:
	/* 0x5c3d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c40:
	/* 0x5c40: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c45:
	/* 0x5c45: jmp    5d3d <generic_sleepable_preload+0x5d3d> */
	goto x86_l_5d3d;
x86_l_5c4a:
	/* 0x5c4a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c4d:
	/* 0x5c4d: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c52:
	/* 0x5c52: jmp    5d52 <generic_sleepable_preload+0x5d52> */
	goto x86_l_5d52;
x86_l_5c57:
	/* 0x5c57: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c5a:
	/* 0x5c5a: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c5f:
	/* 0x5c5f: jmp    5d67 <generic_sleepable_preload+0x5d67> */
	goto x86_l_5d67;
x86_l_5c64:
	/* 0x5c64: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c67:
	/* 0x5c67: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c6c:
	/* 0x5c6c: jmp    5d7c <generic_sleepable_preload+0x5d7c> */
	goto x86_l_5d7c;
x86_l_5c71:
	/* 0x5c71: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c74:
	/* 0x5c74: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c79:
	/* 0x5c79: jmp    5d91 <generic_sleepable_preload+0x5d91> */
	goto x86_l_5d91;
x86_l_5c7e:
	/* 0x5c7e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c81:
	/* 0x5c81: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c86:
	/* 0x5c86: jmp    5da6 <generic_sleepable_preload+0x5da6> */
	goto x86_l_5da6;
x86_l_5c8b:
	/* 0x5c8b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c8e:
	/* 0x5c8e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5c93:
	/* 0x5c93: jmp    5dbb <generic_sleepable_preload+0x5dbb> */
	goto x86_l_5dbb;
x86_l_5c98:
	/* 0x5c98: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c9b:
	/* 0x5c9b: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_5ca0:
	/* 0x5ca0: jmp    5dd0 <generic_sleepable_preload+0x5dd0> */
	goto x86_l_5dd0;
x86_l_5ca5:
	/* 0x5ca5: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5caa:
	/* 0x5caa: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cad:
	/* 0x5cad: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cb2:
	/* 0x5cb2: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	return 7412ULL;
x86_l_5cb7:
	/* 0x5cb7: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cbc:
	/* 0x5cbc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cbf:
	/* 0x5cbf: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc4:
	/* 0x5cc4: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	return 7551ULL;
x86_l_5cc9:
	/* 0x5cc9: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cce:
	/* 0x5cce: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cd1:
	/* 0x5cd1: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cd6:
	/* 0x5cd6: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	return 11358ULL;
x86_l_5cdb:
	/* 0x5cdb: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5ce0:
	/* 0x5ce0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ce3:
	/* 0x5ce3: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ce8:
	/* 0x5ce8: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	return 11497ULL;
x86_l_5ced:
	/* 0x5ced: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5cf2:
	/* 0x5cf2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cf5:
	/* 0x5cf5: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cfa:
	/* 0x5cfa: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	return 15305ULL;
x86_l_5cff:
	/* 0x5cff: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d04:
	/* 0x5d04: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d07:
	/* 0x5d07: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d0c:
	/* 0x5d0c: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	return 15444ULL;
x86_l_5d11:
	/* 0x5d11: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d16:
	/* 0x5d16: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d19:
	/* 0x5d19: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d1e:
	/* 0x5d1e: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	return 19252ULL;
x86_l_5d23:
	/* 0x5d23: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d28:
	/* 0x5d28: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d2b:
	/* 0x5d2b: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d30:
	/* 0x5d30: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	return 19391ULL;
x86_l_5d35:
	/* 0x5d35: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d3a:
	/* 0x5d3a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d3d:
	/* 0x5d3d: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d42:
	/* 0x5d42: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d45:
	/* 0x5d45: jmp    1cf4 <generic_sleepable_preload+0x1cf4> */
	return 7412ULL;
x86_l_5d4a:
	/* 0x5d4a: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d4f:
	/* 0x5d4f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d52:
	/* 0x5d52: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d57:
	/* 0x5d57: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d5a:
	/* 0x5d5a: jmp    1d7f <generic_sleepable_preload+0x1d7f> */
	return 7551ULL;
x86_l_5d5f:
	/* 0x5d5f: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d64:
	/* 0x5d64: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d67:
	/* 0x5d67: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d6c:
	/* 0x5d6c: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d6f:
	/* 0x5d6f: jmp    2c5e <generic_sleepable_preload+0x2c5e> */
	return 11358ULL;
x86_l_5d74:
	/* 0x5d74: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d79:
	/* 0x5d79: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d7c:
	/* 0x5d7c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d81:
	/* 0x5d81: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d84:
	/* 0x5d84: jmp    2ce9 <generic_sleepable_preload+0x2ce9> */
	return 11497ULL;
x86_l_5d89:
	/* 0x5d89: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5d8e:
	/* 0x5d8e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d91:
	/* 0x5d91: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d96:
	/* 0x5d96: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5d99:
	/* 0x5d99: jmp    3bc9 <generic_sleepable_preload+0x3bc9> */
	return 15305ULL;
x86_l_5d9e:
	/* 0x5d9e: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5da3:
	/* 0x5da3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5da6:
	/* 0x5da6: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dab:
	/* 0x5dab: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5dae:
	/* 0x5dae: jmp    3c54 <generic_sleepable_preload+0x3c54> */
	return 15444ULL;
x86_l_5db3:
	/* 0x5db3: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5db8:
	/* 0x5db8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dbb:
	/* 0x5dbb: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dc0:
	/* 0x5dc0: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5dc3:
	/* 0x5dc3: jmp    4b34 <generic_sleepable_preload+0x4b34> */
	return 19252ULL;
x86_l_5dc8:
	/* 0x5dc8: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_5dcd:
	/* 0x5dcd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dd0:
	/* 0x5dd0: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dd5:
	/* 0x5dd5: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_5dd8:
	/* 0x5dd8: jmp    4bbf <generic_sleepable_preload+0x4bbf> */
	return 19391ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 20940U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1648ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1653ULL && __x86_pc <= 3196ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3200ULL && __x86_pc <= 4941ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4946ULL && __x86_pc <= 6776ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6786ULL && __x86_pc <= 8523ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8529ULL && __x86_pc <= 10403ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10405ULL && __x86_pc <= 12153ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12157ULL && __x86_pc <= 14020ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14028ULL && __x86_pc <= 15806ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15811ULL && __x86_pc <= 17651ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17654ULL && __x86_pc <= 19499ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19501ULL && __x86_pc <= 21222ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21224ULL && __x86_pc <= 22977ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22985ULL && __x86_pc <= 24024ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

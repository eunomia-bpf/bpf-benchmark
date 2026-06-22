extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_0(
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
	case 70ULL: goto x86_l_46;
	case 77ULL: goto x86_l_4d;
	case 82ULL: goto x86_l_52;
	case 86ULL: goto x86_l_56;
	case 91ULL: goto x86_l_5b;
	case 95ULL: goto x86_l_5f;
	case 99ULL: goto x86_l_63;
	case 104ULL: goto x86_l_68;
	case 108ULL: goto x86_l_6c;
	case 112ULL: goto x86_l_70;
	case 120ULL: goto x86_l_78;
	case 124ULL: goto x86_l_7c;
	case 128ULL: goto x86_l_80;
	case 136ULL: goto x86_l_88;
	case 140ULL: goto x86_l_8c;
	case 145ULL: goto x86_l_91;
	case 149ULL: goto x86_l_95;
	case 154ULL: goto x86_l_9a;
	case 158ULL: goto x86_l_9e;
	case 163ULL: goto x86_l_a3;
	case 167ULL: goto x86_l_a7;
	case 172ULL: goto x86_l_ac;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 207ULL: goto x86_l_cf;
	case 209ULL: goto x86_l_d1;
	case 212ULL: goto x86_l_d4;
	case 217ULL: goto x86_l_d9;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 227ULL: goto x86_l_e3;
	case 233ULL: goto x86_l_e9;
	case 236ULL: goto x86_l_ec;
	case 241ULL: goto x86_l_f1;
	case 247ULL: goto x86_l_f7;
	case 250ULL: goto x86_l_fa;
	case 255ULL: goto x86_l_ff;
	case 261ULL: goto x86_l_105;
	case 263ULL: goto x86_l_107;
	case 270ULL: goto x86_l_10e;
	case 272ULL: goto x86_l_110;
	case 273ULL: goto x86_l_111;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 286ULL: goto x86_l_11e;
	case 289ULL: goto x86_l_121;
	case 292ULL: goto x86_l_124;
	case 298ULL: goto x86_l_12a;
	case 301ULL: goto x86_l_12d;
	case 307ULL: goto x86_l_133;
	case 310ULL: goto x86_l_136;
	case 316ULL: goto x86_l_13c;
	case 319ULL: goto x86_l_13f;
	case 325ULL: goto x86_l_145;
	case 329ULL: goto x86_l_149;
	case 334ULL: goto x86_l_14e;
	case 336ULL: goto x86_l_150;
	case 342ULL: goto x86_l_156;
	case 345ULL: goto x86_l_159;
	case 348ULL: goto x86_l_15c;
	case 354ULL: goto x86_l_162;
	case 357ULL: goto x86_l_165;
	case 363ULL: goto x86_l_16b;
	case 366ULL: goto x86_l_16e;
	case 372ULL: goto x86_l_174;
	case 375ULL: goto x86_l_177;
	case 381ULL: goto x86_l_17d;
	case 385ULL: goto x86_l_181;
	case 390ULL: goto x86_l_186;
	case 392ULL: goto x86_l_188;
	case 398ULL: goto x86_l_18e;
	case 401ULL: goto x86_l_191;
	case 404ULL: goto x86_l_194;
	case 410ULL: goto x86_l_19a;
	case 413ULL: goto x86_l_19d;
	case 419ULL: goto x86_l_1a3;
	case 422ULL: goto x86_l_1a6;
	case 428ULL: goto x86_l_1ac;
	case 431ULL: goto x86_l_1af;
	case 437ULL: goto x86_l_1b5;
	case 441ULL: goto x86_l_1b9;
	case 446ULL: goto x86_l_1be;
	case 448ULL: goto x86_l_1c0;
	case 454ULL: goto x86_l_1c6;
	case 457ULL: goto x86_l_1c9;
	case 460ULL: goto x86_l_1cc;
	case 466ULL: goto x86_l_1d2;
	case 469ULL: goto x86_l_1d5;
	case 475ULL: goto x86_l_1db;
	case 478ULL: goto x86_l_1de;
	case 484ULL: goto x86_l_1e4;
	case 487ULL: goto x86_l_1e7;
	case 493ULL: goto x86_l_1ed;
	case 497ULL: goto x86_l_1f1;
	case 502ULL: goto x86_l_1f6;
	case 504ULL: goto x86_l_1f8;
	case 510ULL: goto x86_l_1fe;
	case 513ULL: goto x86_l_201;
	case 516ULL: goto x86_l_204;
	case 522ULL: goto x86_l_20a;
	case 525ULL: goto x86_l_20d;
	case 531ULL: goto x86_l_213;
	case 534ULL: goto x86_l_216;
	case 540ULL: goto x86_l_21c;
	case 543ULL: goto x86_l_21f;
	case 549ULL: goto x86_l_225;
	case 553ULL: goto x86_l_229;
	case 558ULL: goto x86_l_22e;
	case 565ULL: goto x86_l_235;
	case 572ULL: goto x86_l_23c;
	case 578ULL: goto x86_l_242;
	case 580ULL: goto x86_l_244;
	case 583ULL: goto x86_l_247;
	case 589ULL: goto x86_l_24d;
	case 592ULL: goto x86_l_250;
	case 598ULL: goto x86_l_256;
	case 601ULL: goto x86_l_259;
	case 607ULL: goto x86_l_25f;
	case 612ULL: goto x86_l_264;
	case 615ULL: goto x86_l_267;
	case 621ULL: goto x86_l_26d;
	case 626ULL: goto x86_l_272;
	case 629ULL: goto x86_l_275;
	case 635ULL: goto x86_l_27b;
	case 638ULL: goto x86_l_27e;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 654ULL: goto x86_l_28e;
	case 661ULL: goto x86_l_295;
	case 668ULL: goto x86_l_29c;
	case 674ULL: goto x86_l_2a2;
	case 676ULL: goto x86_l_2a4;
	case 679ULL: goto x86_l_2a7;
	case 685ULL: goto x86_l_2ad;
	case 688ULL: goto x86_l_2b0;
	case 694ULL: goto x86_l_2b6;
	case 697ULL: goto x86_l_2b9;
	case 703ULL: goto x86_l_2bf;
	case 708ULL: goto x86_l_2c4;
	case 711ULL: goto x86_l_2c7;
	case 717ULL: goto x86_l_2cd;
	case 722ULL: goto x86_l_2d2;
	case 725ULL: goto x86_l_2d5;
	case 731ULL: goto x86_l_2db;
	case 736ULL: goto x86_l_2e0;
	case 739ULL: goto x86_l_2e3;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 757ULL: goto x86_l_2f5;
	case 764ULL: goto x86_l_2fc;
	case 770ULL: goto x86_l_302;
	case 772ULL: goto x86_l_304;
	case 775ULL: goto x86_l_307;
	case 781ULL: goto x86_l_30d;
	case 784ULL: goto x86_l_310;
	case 790ULL: goto x86_l_316;
	case 793ULL: goto x86_l_319;
	case 799ULL: goto x86_l_31f;
	case 804ULL: goto x86_l_324;
	case 807ULL: goto x86_l_327;
	case 813ULL: goto x86_l_32d;
	case 818ULL: goto x86_l_332;
	case 821ULL: goto x86_l_335;
	case 827ULL: goto x86_l_33b;
	case 832ULL: goto x86_l_340;
	case 835ULL: goto x86_l_343;
	case 841ULL: goto x86_l_349;
	case 846ULL: goto x86_l_34e;
	case 853ULL: goto x86_l_355;
	case 860ULL: goto x86_l_35c;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 871ULL: goto x86_l_367;
	case 877ULL: goto x86_l_36d;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 889ULL: goto x86_l_379;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 903ULL: goto x86_l_387;
	case 909ULL: goto x86_l_38d;
	case 914ULL: goto x86_l_392;
	case 917ULL: goto x86_l_395;
	case 923ULL: goto x86_l_39b;
	case 928ULL: goto x86_l_3a0;
	case 931ULL: goto x86_l_3a3;
	case 937ULL: goto x86_l_3a9;
	case 942ULL: goto x86_l_3ae;
	case 949ULL: goto x86_l_3b5;
	case 956ULL: goto x86_l_3bc;
	case 962ULL: goto x86_l_3c2;
	case 964ULL: goto x86_l_3c4;
	case 967ULL: goto x86_l_3c7;
	case 973ULL: goto x86_l_3cd;
	case 976ULL: goto x86_l_3d0;
	case 982ULL: goto x86_l_3d6;
	case 985ULL: goto x86_l_3d9;
	case 991ULL: goto x86_l_3df;
	case 996ULL: goto x86_l_3e4;
	case 999ULL: goto x86_l_3e7;
	case 1005ULL: goto x86_l_3ed;
	case 1010ULL: goto x86_l_3f2;
	case 1013ULL: goto x86_l_3f5;
	case 1019ULL: goto x86_l_3fb;
	case 1024ULL: goto x86_l_400;
	case 1027ULL: goto x86_l_403;
	case 1033ULL: goto x86_l_409;
	case 1038ULL: goto x86_l_40e;
	case 1041ULL: goto x86_l_411;
	case 1047ULL: goto x86_l_417;
	case 1050ULL: goto x86_l_41a;
	case 1056ULL: goto x86_l_420;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1067ULL: goto x86_l_42b;
	case 1072ULL: goto x86_l_430;
	case 1075ULL: goto x86_l_433;
	case 1081ULL: goto x86_l_439;
	case 1086ULL: goto x86_l_43e;
	case 1089ULL: goto x86_l_441;
	case 1095ULL: goto x86_l_447;
	case 1098ULL: goto x86_l_44a;
	case 1104ULL: goto x86_l_450;
	case 1106ULL: goto x86_l_452;
	case 1112ULL: goto x86_l_458;
	case 1117ULL: goto x86_l_45d;
	case 1120ULL: goto x86_l_460;
	case 1126ULL: goto x86_l_466;
	case 1131ULL: goto x86_l_46b;
	case 1134ULL: goto x86_l_46e;
	case 1140ULL: goto x86_l_474;
	case 1143ULL: goto x86_l_477;
	case 1149ULL: goto x86_l_47d;
	case 1151ULL: goto x86_l_47f;
	case 1157ULL: goto x86_l_485;
	case 1162ULL: goto x86_l_48a;
	case 1165ULL: goto x86_l_48d;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1179ULL: goto x86_l_49b;
	case 1185ULL: goto x86_l_4a1;
	case 1188ULL: goto x86_l_4a4;
	case 1194ULL: goto x86_l_4aa;
	case 1196ULL: goto x86_l_4ac;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1210ULL: goto x86_l_4ba;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1224ULL: goto x86_l_4c8;
	case 1230ULL: goto x86_l_4ce;
	case 1233ULL: goto x86_l_4d1;
	case 1239ULL: goto x86_l_4d7;
	case 1241ULL: goto x86_l_4d9;
	case 1247ULL: goto x86_l_4df;
	case 1250ULL: goto x86_l_4e2;
	case 1255ULL: goto x86_l_4e7;
	case 1261ULL: goto x86_l_4ed;
	case 1266ULL: goto x86_l_4f2;
	case 1268ULL: goto x86_l_4f4;
	case 1274ULL: goto x86_l_4fa;
	case 1277ULL: goto x86_l_4fd;
	case 1283ULL: goto x86_l_503;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1294ULL: goto x86_l_50e;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1309ULL: goto x86_l_51d;
	case 1313ULL: goto x86_l_521;
	case 1318ULL: goto x86_l_526;
	case 1320ULL: goto x86_l_528;
	case 1326ULL: goto x86_l_52e;
	case 1329ULL: goto x86_l_531;
	case 1335ULL: goto x86_l_537;
	case 1339ULL: goto x86_l_53b;
	case 1344ULL: goto x86_l_540;
	case 1346ULL: goto x86_l_542;
	case 1352ULL: goto x86_l_548;
	case 1355ULL: goto x86_l_54b;
	case 1361ULL: goto x86_l_551;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1372ULL: goto x86_l_55c;
	case 1378ULL: goto x86_l_562;
	case 1381ULL: goto x86_l_565;
	case 1387ULL: goto x86_l_56b;
	case 1391ULL: goto x86_l_56f;
	case 1396ULL: goto x86_l_574;
	case 1399ULL: goto x86_l_577;
	case 1405ULL: goto x86_l_57d;
	case 1413ULL: goto x86_l_585;
	case 1416ULL: goto x86_l_588;
	case 1422ULL: goto x86_l_58e;
	case 1425ULL: goto x86_l_591;
	case 1428ULL: goto x86_l_594;
	case 1434ULL: goto x86_l_59a;
	case 1439ULL: goto x86_l_59f;
	case 1442ULL: goto x86_l_5a2;
	case 1448ULL: goto x86_l_5a8;
	case 1456ULL: goto x86_l_5b0;
	case 1459ULL: goto x86_l_5b3;
	case 1465ULL: goto x86_l_5b9;
	case 1468ULL: goto x86_l_5bc;
	case 1471ULL: goto x86_l_5bf;
	case 1477ULL: goto x86_l_5c5;
	case 1482ULL: goto x86_l_5ca;
	case 1485ULL: goto x86_l_5cd;
	case 1491ULL: goto x86_l_5d3;
	case 1499ULL: goto x86_l_5db;
	case 1502ULL: goto x86_l_5de;
	case 1508ULL: goto x86_l_5e4;
	case 1511ULL: goto x86_l_5e7;
	case 1514ULL: goto x86_l_5ea;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1528ULL: goto x86_l_5f8;
	case 1534ULL: goto x86_l_5fe;
	case 1542ULL: goto x86_l_606;
	case 1545ULL: goto x86_l_609;
	case 1551ULL: goto x86_l_60f;
	case 1554ULL: goto x86_l_612;
	case 1557ULL: goto x86_l_615;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1571ULL: goto x86_l_623;
	case 1577ULL: goto x86_l_629;
	case 1585ULL: goto x86_l_631;
	case 1588ULL: goto x86_l_634;
	case 1594ULL: goto x86_l_63a;
	case 1597ULL: goto x86_l_63d;
	case 1600ULL: goto x86_l_640;
	case 1606ULL: goto x86_l_646;
	case 1611ULL: goto x86_l_64b;
	case 1614ULL: goto x86_l_64e;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1628ULL: goto x86_l_65c;
	case 1634ULL: goto x86_l_662;
	case 1639ULL: goto x86_l_667;
	case 1642ULL: goto x86_l_66a;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1656ULL: goto x86_l_678;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1670ULL: goto x86_l_686;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1684ULL: goto x86_l_694;
	case 1690ULL: goto x86_l_69a;
	case 1695ULL: goto x86_l_69f;
	case 1698ULL: goto x86_l_6a2;
	case 1704ULL: goto x86_l_6a8;
	case 1709ULL: goto x86_l_6ad;
	case 1712ULL: goto x86_l_6b0;
	case 1718ULL: goto x86_l_6b6;
	case 1723ULL: goto x86_l_6bb;
	case 1726ULL: goto x86_l_6be;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1754ULL: goto x86_l_6da;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_a:
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     105 <generic_sleepable_preload+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105;
	}
x86_l_37:
	/* 0x37: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_41:
	/* 0x41: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_46:
	/* 0x46: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d:
	/* 0x4d: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_52:
	/* 0x52: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5b:
	/* 0x5b: lea    r12,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f:
	/* 0x5f: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_63:
	/* 0x63: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_68:
	/* 0x68: lea    rbp,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6c:
	/* 0x6c: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_78:
	/* 0x78: lea    r13,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7c:
	/* 0x7c: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_80:
	/* 0x80: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_88:
	/* 0x88: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8c:
	/* 0x8c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_91:
	/* 0x91: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95:
	/* 0x95: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9a:
	/* 0x9a: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9e:
	/* 0x9e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a3:
	/* 0xa3: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a7:
	/* 0xa7: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ac:
	/* 0xac: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b0:
	/* 0xb0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b5:
	/* 0xb5: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b9:
	/* 0xb9: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_be:
	/* 0xbe: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2:
	/* 0xc2: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c7:
	/* 0xc7: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca:
	/* 0xca: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_cf:
	/* 0xcf: jne    116 <generic_sleepable_preload+0x116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_116;
	}
x86_l_d1:
	/* 0xd1: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_d4:
	/* 0xd4: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_d9:
	/* 0xd9: jne    14e <generic_sleepable_preload+0x14e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14e;
	}
x86_l_db:
	/* 0xdb: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_de:
	/* 0xde: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e3:
	/* 0xe3: jne    186 <generic_sleepable_preload+0x186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_186;
	}
x86_l_e9:
	/* 0xe9: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ec:
	/* 0xec: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f1:
	/* 0xf1: jne    1be <generic_sleepable_preload+0x1be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1be;
	}
x86_l_f7:
	/* 0xf7: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fa:
	/* 0xfa: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_ff:
	/* 0xff: jne    1f6 <generic_sleepable_preload+0x1f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f6;
	}
x86_l_105:
	/* 0x105: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107:
	/* 0x107: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_10e:
	/* 0x10e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_110:
	/* 0x110: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_111:
	/* 0x111: jmp    2f01 <generic_sleepable_preload+0x2f01> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_116:
	/* 0x116: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_118:
	/* 0x118: js     22e <generic_sleepable_preload+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_22e;
	}
x86_l_11e:
	/* 0x11e: mov    ecx,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_121:
	/* 0x121: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_124:
	/* 0x124: jle    4f2 <generic_sleepable_preload+0x4f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4f2;
	}
x86_l_12a:
	/* 0x12a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12d:
	/* 0x12d: je     71d <generic_sleepable_preload+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1821ULL;
	}
x86_l_133:
	/* 0x133: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_136:
	/* 0x136: je     74c <generic_sleepable_preload+0x74c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1868ULL;
	}
x86_l_13c:
	/* 0x13c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13f:
	/* 0x13f: jne    782 <generic_sleepable_preload+0x782> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1922ULL;
	}
x86_l_145:
	/* 0x145: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149:
	/* 0x149: jmp    77e <generic_sleepable_preload+0x77e> */
	return 1918ULL;
x86_l_14e:
	/* 0x14e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_150:
	/* 0x150: js     28e <generic_sleepable_preload+0x28e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28e;
	}
x86_l_156:
	/* 0x156: mov    ecx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_159:
	/* 0x159: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15c:
	/* 0x15c: jle    50c <generic_sleepable_preload+0x50c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_50c;
	}
x86_l_162:
	/* 0x162: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_165:
	/* 0x165: je     724 <generic_sleepable_preload+0x724> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1828ULL;
	}
x86_l_16b:
	/* 0x16b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_16e:
	/* 0x16e: je     752 <generic_sleepable_preload+0x752> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1874ULL;
	}
x86_l_174:
	/* 0x174: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_177:
	/* 0x177: jne    9f9 <generic_sleepable_preload+0x9f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2553ULL;
	}
x86_l_17d:
	/* 0x17d: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_181:
	/* 0x181: jmp    9f5 <generic_sleepable_preload+0x9f5> */
	return 2549ULL;
x86_l_186:
	/* 0x186: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_188:
	/* 0x188: js     2ee <generic_sleepable_preload+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ee;
	}
x86_l_18e:
	/* 0x18e: mov    ecx,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_191:
	/* 0x191: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_194:
	/* 0x194: jle    526 <generic_sleepable_preload+0x526> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_526;
	}
x86_l_19a:
	/* 0x19a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19d:
	/* 0x19d: je     72e <generic_sleepable_preload+0x72e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1838ULL;
	}
x86_l_1a3:
	/* 0x1a3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1a6:
	/* 0x1a6: je     75b <generic_sleepable_preload+0x75b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1883ULL;
	}
x86_l_1ac:
	/* 0x1ac: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1af:
	/* 0x1af: jne    c82 <generic_sleepable_preload+0xc82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3202ULL;
	}
x86_l_1b5:
	/* 0x1b5: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9:
	/* 0x1b9: jmp    c7e <generic_sleepable_preload+0xc7e> */
	return 3198ULL;
x86_l_1be:
	/* 0x1be: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1c0:
	/* 0x1c0: js     34e <generic_sleepable_preload+0x34e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34e;
	}
x86_l_1c6:
	/* 0x1c6: mov    ecx,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1c9:
	/* 0x1c9: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1cc:
	/* 0x1cc: jle    540 <generic_sleepable_preload+0x540> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_540;
	}
x86_l_1d2:
	/* 0x1d2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d5:
	/* 0x1d5: je     738 <generic_sleepable_preload+0x738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1848ULL;
	}
x86_l_1db:
	/* 0x1db: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1de:
	/* 0x1de: je     764 <generic_sleepable_preload+0x764> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1892ULL;
	}
x86_l_1e4:
	/* 0x1e4: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e7:
	/* 0x1e7: jne    f0b <generic_sleepable_preload+0xf0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3851ULL;
	}
x86_l_1ed:
	/* 0x1ed: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f1:
	/* 0x1f1: jmp    f07 <generic_sleepable_preload+0xf07> */
	return 3847ULL;
x86_l_1f6:
	/* 0x1f6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1f8:
	/* 0x1f8: js     3ae <generic_sleepable_preload+0x3ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3ae;
	}
x86_l_1fe:
	/* 0x1fe: mov    ecx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_201:
	/* 0x201: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_204:
	/* 0x204: jle    55a <generic_sleepable_preload+0x55a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_55a;
	}
x86_l_20a:
	/* 0x20a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_20d:
	/* 0x20d: je     742 <generic_sleepable_preload+0x742> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1858ULL;
	}
x86_l_213:
	/* 0x213: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_216:
	/* 0x216: je     76d <generic_sleepable_preload+0x76d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1901ULL;
	}
x86_l_21c:
	/* 0x21c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21f:
	/* 0x21f: jne    1194 <generic_sleepable_preload+0x1194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4500ULL;
	}
x86_l_225:
	/* 0x225: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_229:
	/* 0x229: jmp    1190 <generic_sleepable_preload+0x1190> */
	return 4496ULL;
x86_l_22e:
	/* 0x22e: movzx  ecx,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_235:
	/* 0x235: movzx  eax,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_23c:
	/* 0x23c: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_242:
	/* 0x242: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_244:
	/* 0x244: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_247:
	/* 0x247: jle    40e <generic_sleepable_preload+0x40e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_40e;
	}
x86_l_24d:
	/* 0x24d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_250:
	/* 0x250: jle    574 <generic_sleepable_preload+0x574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_574;
	}
x86_l_256:
	/* 0x256: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_259:
	/* 0x259: jle    160a <generic_sleepable_preload+0x160a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5642ULL;
	}
x86_l_25f:
	/* 0x25f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_264:
	/* 0x264: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_267:
	/* 0x267: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_26d:
	/* 0x26d: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_272:
	/* 0x272: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_275:
	/* 0x275: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_27b:
	/* 0x27b: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_27e:
	/* 0x27e: jne    162f <generic_sleepable_preload+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5679ULL;
	}
x86_l_284:
	/* 0x284: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_289:
	/* 0x289: jmp    161c <generic_sleepable_preload+0x161c> */
	return 5660ULL;
x86_l_28e:
	/* 0x28e: movzx  ecx,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_295:
	/* 0x295: movzx  eax,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_29c:
	/* 0x29c: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_2a2:
	/* 0x2a2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a4:
	/* 0x2a4: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2a7:
	/* 0x2a7: jle    43e <generic_sleepable_preload+0x43e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_43e;
	}
x86_l_2ad:
	/* 0x2ad: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2b0:
	/* 0x2b0: jle    59f <generic_sleepable_preload+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_59f;
	}
x86_l_2b6:
	/* 0x2b6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2b9:
	/* 0x2b9: jle    18b6 <generic_sleepable_preload+0x18b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6326ULL;
	}
x86_l_2bf:
	/* 0x2bf: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c4:
	/* 0x2c4: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2c7:
	/* 0x2c7: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_2cd:
	/* 0x2cd: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d2:
	/* 0x2d2: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2d5:
	/* 0x2d5: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_2db:
	/* 0x2db: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2e0:
	/* 0x2e0: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2e3:
	/* 0x2e3: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_2e9:
	/* 0x2e9: jmp    1c2d <generic_sleepable_preload+0x1c2d> */
	return 7213ULL;
x86_l_2ee:
	/* 0x2ee: movzx  ecx,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_2f5:
	/* 0x2f5: movzx  eax,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_2fc:
	/* 0x2fc: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_302:
	/* 0x302: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_304:
	/* 0x304: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_307:
	/* 0x307: jle    46b <generic_sleepable_preload+0x46b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_46b;
	}
x86_l_30d:
	/* 0x30d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_310:
	/* 0x310: jle    5ca <generic_sleepable_preload+0x5ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5ca;
	}
x86_l_316:
	/* 0x316: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_319:
	/* 0x319: jle    18d5 <generic_sleepable_preload+0x18d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6357ULL;
	}
x86_l_31f:
	/* 0x31f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_324:
	/* 0x324: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_327:
	/* 0x327: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_32d:
	/* 0x32d: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_332:
	/* 0x332: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_335:
	/* 0x335: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_33b:
	/* 0x33b: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_340:
	/* 0x340: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_343:
	/* 0x343: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_349:
	/* 0x349: jmp    1ee9 <generic_sleepable_preload+0x1ee9> */
	return 7913ULL;
x86_l_34e:
	/* 0x34e: movzx  ecx,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_355:
	/* 0x355: movzx  eax,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_35c:
	/* 0x35c: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_362:
	/* 0x362: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_364:
	/* 0x364: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_367:
	/* 0x367: jle    498 <generic_sleepable_preload+0x498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_498;
	}
x86_l_36d:
	/* 0x36d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_370:
	/* 0x370: jle    5f5 <generic_sleepable_preload+0x5f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5f5;
	}
x86_l_376:
	/* 0x376: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_379:
	/* 0x379: jle    18f4 <generic_sleepable_preload+0x18f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6388ULL;
	}
x86_l_37f:
	/* 0x37f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_384:
	/* 0x384: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_387:
	/* 0x387: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_38d:
	/* 0x38d: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_392:
	/* 0x392: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_395:
	/* 0x395: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_39b:
	/* 0x39b: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3a0:
	/* 0x3a0: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3a3:
	/* 0x3a3: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_3a9:
	/* 0x3a9: jmp    21a5 <generic_sleepable_preload+0x21a5> */
	return 8613ULL;
x86_l_3ae:
	/* 0x3ae: movzx  ecx,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_3b5:
	/* 0x3b5: movzx  eax,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_3bc:
	/* 0x3bc: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_3c2:
	/* 0x3c2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c4:
	/* 0x3c4: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3c7:
	/* 0x3c7: jle    4c5 <generic_sleepable_preload+0x4c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4c5;
	}
x86_l_3cd:
	/* 0x3cd: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3d0:
	/* 0x3d0: jle    620 <generic_sleepable_preload+0x620> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_620;
	}
x86_l_3d6:
	/* 0x3d6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3d9:
	/* 0x3d9: jle    1913 <generic_sleepable_preload+0x1913> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6419ULL;
	}
x86_l_3df:
	/* 0x3df: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e4:
	/* 0x3e4: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3e7:
	/* 0x3e7: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_3ed:
	/* 0x3ed: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3f2:
	/* 0x3f2: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3f5:
	/* 0x3f5: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_3fb:
	/* 0x3fb: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_400:
	/* 0x400: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_403:
	/* 0x403: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_409:
	/* 0x409: jmp    1938 <generic_sleepable_preload+0x1938> */
	return 6456ULL;
x86_l_40e:
	/* 0x40e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_411:
	/* 0x411: jg     64b <generic_sleepable_preload+0x64b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_64b;
	}
x86_l_417:
	/* 0x417: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_41a:
	/* 0x41a: jg     14c0 <generic_sleepable_preload+0x14c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5312ULL;
	}
x86_l_420:
	/* 0x420: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_423:
	/* 0x423: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_425:
	/* 0x425: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_42b:
	/* 0x42b: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_430:
	/* 0x430: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_433:
	/* 0x433: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_439:
	/* 0x439: jmp    162f <generic_sleepable_preload+0x162f> */
	return 5679ULL;
x86_l_43e:
	/* 0x43e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_441:
	/* 0x441: jg     675 <generic_sleepable_preload+0x675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_675;
	}
x86_l_447:
	/* 0x447: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_44a:
	/* 0x44a: jg     14e1 <generic_sleepable_preload+0x14e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5345ULL;
	}
x86_l_450:
	/* 0x450: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_452:
	/* 0x452: je     1c17 <generic_sleepable_preload+0x1c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7191ULL;
	}
x86_l_458:
	/* 0x458: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_45d:
	/* 0x45d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_460:
	/* 0x460: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_466:
	/* 0x466: jmp    1c2d <generic_sleepable_preload+0x1c2d> */
	return 7213ULL;
x86_l_46b:
	/* 0x46b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_46e:
	/* 0x46e: jg     69f <generic_sleepable_preload+0x69f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_69f;
	}
x86_l_474:
	/* 0x474: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_477:
	/* 0x477: jg     1502 <generic_sleepable_preload+0x1502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5378ULL;
	}
x86_l_47d:
	/* 0x47d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_47f:
	/* 0x47f: je     1ed3 <generic_sleepable_preload+0x1ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7891ULL;
	}
x86_l_485:
	/* 0x485: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_48a:
	/* 0x48a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_48d:
	/* 0x48d: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_493:
	/* 0x493: jmp    1ee9 <generic_sleepable_preload+0x1ee9> */
	return 7913ULL;
x86_l_498:
	/* 0x498: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_49b:
	/* 0x49b: jg     6c9 <generic_sleepable_preload+0x6c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6c9;
	}
x86_l_4a1:
	/* 0x4a1: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4a4:
	/* 0x4a4: jg     1523 <generic_sleepable_preload+0x1523> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5411ULL;
	}
x86_l_4aa:
	/* 0x4aa: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4ac:
	/* 0x4ac: je     218f <generic_sleepable_preload+0x218f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8591ULL;
	}
x86_l_4b2:
	/* 0x4b2: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4b7:
	/* 0x4b7: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4ba:
	/* 0x4ba: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_4c0:
	/* 0x4c0: jmp    21a5 <generic_sleepable_preload+0x21a5> */
	return 8613ULL;
x86_l_4c5:
	/* 0x4c5: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4c8:
	/* 0x4c8: jg     6f3 <generic_sleepable_preload+0x6f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1779ULL;
	}
x86_l_4ce:
	/* 0x4ce: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d1:
	/* 0x4d1: jg     1544 <generic_sleepable_preload+0x1544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5444ULL;
	}
x86_l_4d7:
	/* 0x4d7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4d9:
	/* 0x4d9: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_4df:
	/* 0x4df: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4e2:
	/* 0x4e2: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4e7:
	/* 0x4e7: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_4ed:
	/* 0x4ed: jmp    1938 <generic_sleepable_preload+0x1938> */
	return 6456ULL;
x86_l_4f2:
	/* 0x4f2: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4f4:
	/* 0x4f4: je     776 <generic_sleepable_preload+0x776> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1910ULL;
	}
x86_l_4fa:
	/* 0x4fa: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4fd:
	/* 0x4fd: jne    782 <generic_sleepable_preload+0x782> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1922ULL;
	}
x86_l_503:
	/* 0x503: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_507:
	/* 0x507: jmp    77e <generic_sleepable_preload+0x77e> */
	return 1918ULL;
x86_l_50c:
	/* 0x50c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_50e:
	/* 0x50e: je     9ed <generic_sleepable_preload+0x9ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2541ULL;
	}
x86_l_514:
	/* 0x514: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_517:
	/* 0x517: jne    9f9 <generic_sleepable_preload+0x9f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2553ULL;
	}
x86_l_51d:
	/* 0x51d: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_521:
	/* 0x521: jmp    9f5 <generic_sleepable_preload+0x9f5> */
	return 2549ULL;
x86_l_526:
	/* 0x526: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_528:
	/* 0x528: je     c76 <generic_sleepable_preload+0xc76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3190ULL;
	}
x86_l_52e:
	/* 0x52e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_531:
	/* 0x531: jne    c82 <generic_sleepable_preload+0xc82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3202ULL;
	}
x86_l_537:
	/* 0x537: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53b:
	/* 0x53b: jmp    c7e <generic_sleepable_preload+0xc7e> */
	return 3198ULL;
x86_l_540:
	/* 0x540: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_542:
	/* 0x542: je     eff <generic_sleepable_preload+0xeff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3839ULL;
	}
x86_l_548:
	/* 0x548: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_54b:
	/* 0x54b: jne    f0b <generic_sleepable_preload+0xf0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3851ULL;
	}
x86_l_551:
	/* 0x551: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_555:
	/* 0x555: jmp    f07 <generic_sleepable_preload+0xf07> */
	return 3847ULL;
x86_l_55a:
	/* 0x55a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_55c:
	/* 0x55c: je     1188 <generic_sleepable_preload+0x1188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4488ULL;
	}
x86_l_562:
	/* 0x562: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_565:
	/* 0x565: jne    1194 <generic_sleepable_preload+0x1194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4500ULL;
	}
x86_l_56b:
	/* 0x56b: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56f:
	/* 0x56f: jmp    1190 <generic_sleepable_preload+0x1190> */
	return 4496ULL;
x86_l_574:
	/* 0x574: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_577:
	/* 0x577: jg     1416 <generic_sleepable_preload+0x1416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5142ULL;
	}
x86_l_57d:
	/* 0x57d: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_585:
	/* 0x585: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_588:
	/* 0x588: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_58e:
	/* 0x58e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_591:
	/* 0x591: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_594:
	/* 0x594: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_59a:
	/* 0x59a: jmp    162f <generic_sleepable_preload+0x162f> */
	return 5679ULL;
x86_l_59f:
	/* 0x59f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5a2:
	/* 0x5a2: jg     1438 <generic_sleepable_preload+0x1438> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5176ULL;
	}
x86_l_5a8:
	/* 0x5a8: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5b0:
	/* 0x5b0: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b3:
	/* 0x5b3: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_5b9:
	/* 0x5b9: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_5bc:
	/* 0x5bc: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5bf:
	/* 0x5bf: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_5c5:
	/* 0x5c5: jmp    1c2d <generic_sleepable_preload+0x1c2d> */
	return 7213ULL;
x86_l_5ca:
	/* 0x5ca: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5cd:
	/* 0x5cd: jg     145a <generic_sleepable_preload+0x145a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5210ULL;
	}
x86_l_5d3:
	/* 0x5d3: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5db:
	/* 0x5db: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5de:
	/* 0x5de: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_5e4:
	/* 0x5e4: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_5e7:
	/* 0x5e7: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5ea:
	/* 0x5ea: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_5f0:
	/* 0x5f0: jmp    1ee9 <generic_sleepable_preload+0x1ee9> */
	return 7913ULL;
x86_l_5f5:
	/* 0x5f5: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5f8:
	/* 0x5f8: jg     147c <generic_sleepable_preload+0x147c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5244ULL;
	}
x86_l_5fe:
	/* 0x5fe: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_606:
	/* 0x606: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_609:
	/* 0x609: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_60f:
	/* 0x60f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_612:
	/* 0x612: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_615:
	/* 0x615: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_61b:
	/* 0x61b: jmp    21a5 <generic_sleepable_preload+0x21a5> */
	return 8613ULL;
x86_l_620:
	/* 0x620: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_623:
	/* 0x623: jg     149e <generic_sleepable_preload+0x149e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5278ULL;
	}
x86_l_629:
	/* 0x629: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_631:
	/* 0x631: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_634:
	/* 0x634: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_63a:
	/* 0x63a: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_63d:
	/* 0x63d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_640:
	/* 0x640: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_646:
	/* 0x646: jmp    1938 <generic_sleepable_preload+0x1938> */
	return 6456ULL;
x86_l_64b:
	/* 0x64b: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_64e:
	/* 0x64e: jg     1565 <generic_sleepable_preload+0x1565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5477ULL;
	}
x86_l_654:
	/* 0x654: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_659:
	/* 0x659: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_65c:
	/* 0x65c: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_662:
	/* 0x662: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_667:
	/* 0x667: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_66a:
	/* 0x66a: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_670:
	/* 0x670: jmp    162f <generic_sleepable_preload+0x162f> */
	return 5679ULL;
x86_l_675:
	/* 0x675: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_678:
	/* 0x678: jg     1586 <generic_sleepable_preload+0x1586> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5510ULL;
	}
x86_l_67e:
	/* 0x67e: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_683:
	/* 0x683: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_686:
	/* 0x686: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_68c:
	/* 0x68c: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_691:
	/* 0x691: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_694:
	/* 0x694: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_69a:
	/* 0x69a: jmp    1c2d <generic_sleepable_preload+0x1c2d> */
	return 7213ULL;
x86_l_69f:
	/* 0x69f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6a2:
	/* 0x6a2: jg     15a7 <generic_sleepable_preload+0x15a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5543ULL;
	}
x86_l_6a8:
	/* 0x6a8: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6ad:
	/* 0x6ad: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_6b0:
	/* 0x6b0: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_6b6:
	/* 0x6b6: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6bb:
	/* 0x6bb: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6be:
	/* 0x6be: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_6c4:
	/* 0x6c4: jmp    1ee9 <generic_sleepable_preload+0x1ee9> */
	return 7913ULL;
x86_l_6c9:
	/* 0x6c9: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6cc:
	/* 0x6cc: jg     15c8 <generic_sleepable_preload+0x15c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5576ULL;
	}
x86_l_6d2:
	/* 0x6d2: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6d7:
	/* 0x6d7: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_6da:
	/* 0x6da: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
	return 1760ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1760ULL: goto x86_l_6e0;
	case 1765ULL: goto x86_l_6e5;
	case 1768ULL: goto x86_l_6e8;
	case 1774ULL: goto x86_l_6ee;
	case 1779ULL: goto x86_l_6f3;
	case 1782ULL: goto x86_l_6f6;
	case 1788ULL: goto x86_l_6fc;
	case 1793ULL: goto x86_l_701;
	case 1796ULL: goto x86_l_704;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1810ULL: goto x86_l_712;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1848ULL: goto x86_l_738;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1872ULL: goto x86_l_750;
	case 1874ULL: goto x86_l_752;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1896ULL: goto x86_l_768;
	case 1901ULL: goto x86_l_76d;
	case 1905ULL: goto x86_l_771;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1918ULL: goto x86_l_77e;
	case 1922ULL: goto x86_l_782;
	case 1927ULL: goto x86_l_787;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1943ULL: goto x86_l_797;
	case 1948ULL: goto x86_l_79c;
	case 1950ULL: goto x86_l_79e;
	case 1955ULL: goto x86_l_7a3;
	case 1959ULL: goto x86_l_7a7;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1969ULL: goto x86_l_7b1;
	case 1971ULL: goto x86_l_7b3;
	case 1977ULL: goto x86_l_7b9;
	case 1982ULL: goto x86_l_7be;
	case 1988ULL: goto x86_l_7c4;
	case 1991ULL: goto x86_l_7c7;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2011ULL: goto x86_l_7db;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2021ULL: goto x86_l_7e5;
	case 2023ULL: goto x86_l_7e7;
	case 2029ULL: goto x86_l_7ed;
	case 2037ULL: goto x86_l_7f5;
	case 2043ULL: goto x86_l_7fb;
	case 2049ULL: goto x86_l_801;
	case 2053ULL: goto x86_l_805;
	case 2061ULL: goto x86_l_80d;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2072ULL: goto x86_l_818;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2082ULL: goto x86_l_822;
	case 2084ULL: goto x86_l_824;
	case 2090ULL: goto x86_l_82a;
	case 2098ULL: goto x86_l_832;
	case 2104ULL: goto x86_l_838;
	case 2110ULL: goto x86_l_83e;
	case 2114ULL: goto x86_l_842;
	case 2122ULL: goto x86_l_84a;
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2133ULL: goto x86_l_855;
	case 2136ULL: goto x86_l_858;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2145ULL: goto x86_l_861;
	case 2151ULL: goto x86_l_867;
	case 2159ULL: goto x86_l_86f;
	case 2165ULL: goto x86_l_875;
	case 2171ULL: goto x86_l_87b;
	case 2175ULL: goto x86_l_87f;
	case 2183ULL: goto x86_l_887;
	case 2185ULL: goto x86_l_889;
	case 2190ULL: goto x86_l_88e;
	case 2194ULL: goto x86_l_892;
	case 2197ULL: goto x86_l_895;
	case 2202ULL: goto x86_l_89a;
	case 2204ULL: goto x86_l_89c;
	case 2206ULL: goto x86_l_89e;
	case 2212ULL: goto x86_l_8a4;
	case 2220ULL: goto x86_l_8ac;
	case 2226ULL: goto x86_l_8b2;
	case 2232ULL: goto x86_l_8b8;
	case 2236ULL: goto x86_l_8bc;
	case 2244ULL: goto x86_l_8c4;
	case 2246ULL: goto x86_l_8c6;
	case 2251ULL: goto x86_l_8cb;
	case 2255ULL: goto x86_l_8cf;
	case 2258ULL: goto x86_l_8d2;
	case 2263ULL: goto x86_l_8d7;
	case 2265ULL: goto x86_l_8d9;
	case 2267ULL: goto x86_l_8db;
	case 2273ULL: goto x86_l_8e1;
	case 2281ULL: goto x86_l_8e9;
	case 2287ULL: goto x86_l_8ef;
	case 2293ULL: goto x86_l_8f5;
	case 2297ULL: goto x86_l_8f9;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2312ULL: goto x86_l_908;
	case 2316ULL: goto x86_l_90c;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2326ULL: goto x86_l_916;
	case 2328ULL: goto x86_l_918;
	case 2334ULL: goto x86_l_91e;
	case 2342ULL: goto x86_l_926;
	case 2348ULL: goto x86_l_92c;
	case 2354ULL: goto x86_l_932;
	case 2358ULL: goto x86_l_936;
	case 2366ULL: goto x86_l_93e;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2377ULL: goto x86_l_949;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2387ULL: goto x86_l_953;
	case 2389ULL: goto x86_l_955;
	case 2395ULL: goto x86_l_95b;
	case 2403ULL: goto x86_l_963;
	case 2405ULL: goto x86_l_965;
	case 2411ULL: goto x86_l_96b;
	case 2415ULL: goto x86_l_96f;
	case 2423ULL: goto x86_l_977;
	case 2425ULL: goto x86_l_979;
	case 2430ULL: goto x86_l_97e;
	case 2434ULL: goto x86_l_982;
	case 2437ULL: goto x86_l_985;
	case 2442ULL: goto x86_l_98a;
	case 2444ULL: goto x86_l_98c;
	case 2446ULL: goto x86_l_98e;
	case 2452ULL: goto x86_l_994;
	case 2460ULL: goto x86_l_99c;
	case 2462ULL: goto x86_l_99e;
	case 2468ULL: goto x86_l_9a4;
	case 2472ULL: goto x86_l_9a8;
	case 2480ULL: goto x86_l_9b0;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2491ULL: goto x86_l_9bb;
	case 2494ULL: goto x86_l_9be;
	case 2499ULL: goto x86_l_9c3;
	case 2501ULL: goto x86_l_9c5;
	case 2503ULL: goto x86_l_9c7;
	case 2509ULL: goto x86_l_9cd;
	case 2511ULL: goto x86_l_9cf;
	case 2515ULL: goto x86_l_9d3;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2536ULL: goto x86_l_9e8;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2549ULL: goto x86_l_9f5;
	case 2553ULL: goto x86_l_9f9;
	case 2561ULL: goto x86_l_a01;
	case 2567ULL: goto x86_l_a07;
	case 2573ULL: goto x86_l_a0d;
	case 2576ULL: goto x86_l_a10;
	case 2580ULL: goto x86_l_a14;
	case 2588ULL: goto x86_l_a1c;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2599ULL: goto x86_l_a27;
	case 2602ULL: goto x86_l_a2a;
	case 2607ULL: goto x86_l_a2f;
	case 2609ULL: goto x86_l_a31;
	case 2611ULL: goto x86_l_a33;
	case 2617ULL: goto x86_l_a39;
	case 2625ULL: goto x86_l_a41;
	case 2631ULL: goto x86_l_a47;
	case 2637ULL: goto x86_l_a4d;
	case 2641ULL: goto x86_l_a51;
	case 2649ULL: goto x86_l_a59;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2678ULL: goto x86_l_a76;
	case 2686ULL: goto x86_l_a7e;
	case 2692ULL: goto x86_l_a84;
	case 2698ULL: goto x86_l_a8a;
	case 2702ULL: goto x86_l_a8e;
	case 2710ULL: goto x86_l_a96;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2721ULL: goto x86_l_aa1;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2731ULL: goto x86_l_aab;
	case 2733ULL: goto x86_l_aad;
	case 2739ULL: goto x86_l_ab3;
	case 2747ULL: goto x86_l_abb;
	case 2753ULL: goto x86_l_ac1;
	case 2759ULL: goto x86_l_ac7;
	case 2763ULL: goto x86_l_acb;
	case 2771ULL: goto x86_l_ad3;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2782ULL: goto x86_l_ade;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2792ULL: goto x86_l_ae8;
	case 2794ULL: goto x86_l_aea;
	case 2800ULL: goto x86_l_af0;
	case 2808ULL: goto x86_l_af8;
	case 2814ULL: goto x86_l_afe;
	case 2820ULL: goto x86_l_b04;
	case 2824ULL: goto x86_l_b08;
	case 2832ULL: goto x86_l_b10;
	case 2834ULL: goto x86_l_b12;
	case 2839ULL: goto x86_l_b17;
	case 2843ULL: goto x86_l_b1b;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2853ULL: goto x86_l_b25;
	case 2855ULL: goto x86_l_b27;
	case 2861ULL: goto x86_l_b2d;
	case 2869ULL: goto x86_l_b35;
	case 2875ULL: goto x86_l_b3b;
	case 2881ULL: goto x86_l_b41;
	case 2885ULL: goto x86_l_b45;
	case 2893ULL: goto x86_l_b4d;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2904ULL: goto x86_l_b58;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2914ULL: goto x86_l_b62;
	case 2916ULL: goto x86_l_b64;
	case 2922ULL: goto x86_l_b6a;
	case 2930ULL: goto x86_l_b72;
	case 2936ULL: goto x86_l_b78;
	case 2942ULL: goto x86_l_b7e;
	case 2946ULL: goto x86_l_b82;
	case 2954ULL: goto x86_l_b8a;
	case 2956ULL: goto x86_l_b8c;
	case 2961ULL: goto x86_l_b91;
	case 2965ULL: goto x86_l_b95;
	case 2968ULL: goto x86_l_b98;
	case 2973ULL: goto x86_l_b9d;
	case 2975ULL: goto x86_l_b9f;
	case 2977ULL: goto x86_l_ba1;
	case 2983ULL: goto x86_l_ba7;
	case 2991ULL: goto x86_l_baf;
	case 2997ULL: goto x86_l_bb5;
	case 3003ULL: goto x86_l_bbb;
	case 3007ULL: goto x86_l_bbf;
	case 3015ULL: goto x86_l_bc7;
	case 3017ULL: goto x86_l_bc9;
	case 3022ULL: goto x86_l_bce;
	case 3026ULL: goto x86_l_bd2;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3036ULL: goto x86_l_bdc;
	case 3038ULL: goto x86_l_bde;
	case 3044ULL: goto x86_l_be4;
	case 3052ULL: goto x86_l_bec;
	case 3054ULL: goto x86_l_bee;
	case 3060ULL: goto x86_l_bf4;
	case 3064ULL: goto x86_l_bf8;
	case 3072ULL: goto x86_l_c00;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3093ULL: goto x86_l_c15;
	case 3095ULL: goto x86_l_c17;
	case 3101ULL: goto x86_l_c1d;
	case 3109ULL: goto x86_l_c25;
	case 3111ULL: goto x86_l_c27;
	case 3117ULL: goto x86_l_c2d;
	case 3121ULL: goto x86_l_c31;
	case 3129ULL: goto x86_l_c39;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3140ULL: goto x86_l_c44;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3150ULL: goto x86_l_c4e;
	case 3152ULL: goto x86_l_c50;
	case 3158ULL: goto x86_l_c56;
	case 3160ULL: goto x86_l_c58;
	case 3164ULL: goto x86_l_c5c;
	case 3172ULL: goto x86_l_c64;
	case 3177ULL: goto x86_l_c69;
	case 3185ULL: goto x86_l_c71;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3198ULL: goto x86_l_c7e;
	case 3202ULL: goto x86_l_c82;
	case 3210ULL: goto x86_l_c8a;
	case 3216ULL: goto x86_l_c90;
	case 3222ULL: goto x86_l_c96;
	case 3225ULL: goto x86_l_c99;
	case 3229ULL: goto x86_l_c9d;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3244ULL: goto x86_l_cac;
	case 3248ULL: goto x86_l_cb0;
	case 3251ULL: goto x86_l_cb3;
	case 3256ULL: goto x86_l_cb8;
	case 3258ULL: goto x86_l_cba;
	case 3260ULL: goto x86_l_cbc;
	case 3266ULL: goto x86_l_cc2;
	case 3274ULL: goto x86_l_cca;
	case 3280ULL: goto x86_l_cd0;
	case 3286ULL: goto x86_l_cd6;
	case 3290ULL: goto x86_l_cda;
	case 3298ULL: goto x86_l_ce2;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3309ULL: goto x86_l_ced;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3335ULL: goto x86_l_d07;
	case 3341ULL: goto x86_l_d0d;
	case 3347ULL: goto x86_l_d13;
	case 3351ULL: goto x86_l_d17;
	case 3359ULL: goto x86_l_d1f;
	case 3361ULL: goto x86_l_d21;
	case 3366ULL: goto x86_l_d26;
	case 3370ULL: goto x86_l_d2a;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3380ULL: goto x86_l_d34;
	case 3382ULL: goto x86_l_d36;
	case 3388ULL: goto x86_l_d3c;
	case 3396ULL: goto x86_l_d44;
	case 3402ULL: goto x86_l_d4a;
	case 3408ULL: goto x86_l_d50;
	case 3412ULL: goto x86_l_d54;
	case 3420ULL: goto x86_l_d5c;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3431ULL: goto x86_l_d67;
	case 3434ULL: goto x86_l_d6a;
	case 3439ULL: goto x86_l_d6f;
	case 3441ULL: goto x86_l_d71;
	case 3443ULL: goto x86_l_d73;
	case 3449ULL: goto x86_l_d79;
	case 3457ULL: goto x86_l_d81;
	case 3463ULL: goto x86_l_d87;
	case 3469ULL: goto x86_l_d8d;
	case 3473ULL: goto x86_l_d91;
	case 3481ULL: goto x86_l_d99;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3492ULL: goto x86_l_da4;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3502ULL: goto x86_l_dae;
	case 3504ULL: goto x86_l_db0;
	case 3510ULL: goto x86_l_db6;
	case 3518ULL: goto x86_l_dbe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6e0:
	/* 0x6e0: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6e5:
	/* 0x6e5: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6e8:
	/* 0x6e8: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_6ee:
	/* 0x6ee: jmp    21a5 <generic_sleepable_preload+0x21a5> */
	return 8613ULL;
x86_l_6f3:
	/* 0x6f3: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6f6:
	/* 0x6f6: jg     15e9 <generic_sleepable_preload+0x15e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5609ULL;
	}
x86_l_6fc:
	/* 0x6fc: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_701:
	/* 0x701: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_704:
	/* 0x704: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_70a:
	/* 0x70a: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_70f:
	/* 0x70f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_712:
	/* 0x712: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_718:
	/* 0x718: jmp    1938 <generic_sleepable_preload+0x1938> */
	return 6456ULL;
x86_l_71d:
	/* 0x71d: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_722:
	/* 0x722: jmp    77b <generic_sleepable_preload+0x77b> */
	goto x86_l_77b;
x86_l_724:
	/* 0x724: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_729:
	/* 0x729: jmp    9f2 <generic_sleepable_preload+0x9f2> */
	goto x86_l_9f2;
x86_l_72e:
	/* 0x72e: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_733:
	/* 0x733: jmp    c7b <generic_sleepable_preload+0xc7b> */
	goto x86_l_c7b;
x86_l_738:
	/* 0x738: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_73d:
	/* 0x73d: jmp    f04 <generic_sleepable_preload+0xf04> */
	return 3844ULL;
x86_l_742:
	/* 0x742: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_747:
	/* 0x747: jmp    118d <generic_sleepable_preload+0x118d> */
	return 4493ULL;
x86_l_74c:
	/* 0x74c: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_750:
	/* 0x750: jmp    77e <generic_sleepable_preload+0x77e> */
	goto x86_l_77e;
x86_l_752:
	/* 0x752: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_756:
	/* 0x756: jmp    9f5 <generic_sleepable_preload+0x9f5> */
	goto x86_l_9f5;
x86_l_75b:
	/* 0x75b: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_75f:
	/* 0x75f: jmp    c7e <generic_sleepable_preload+0xc7e> */
	goto x86_l_c7e;
x86_l_764:
	/* 0x764: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_768:
	/* 0x768: jmp    f07 <generic_sleepable_preload+0xf07> */
	return 3847ULL;
x86_l_76d:
	/* 0x76d: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_771:
	/* 0x771: jmp    1190 <generic_sleepable_preload+0x1190> */
	return 4496ULL;
x86_l_776:
	/* 0x776: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_77b:
	/* 0x77b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77e:
	/* 0x77e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_782:
	/* 0x782: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_787:
	/* 0x787: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_78d:
	/* 0x78d: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_790:
	/* 0x790: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_793:
	/* 0x793: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_797:
	/* 0x797: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_79c:
	/* 0x79c: je     7b9 <generic_sleepable_preload+0x7b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7b9;
	}
x86_l_79e:
	/* 0x79e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7a3:
	/* 0x7a3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a7:
	/* 0x7a7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7aa:
	/* 0x7aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7af:
	/* 0x7af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b1:
	/* 0x7b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7b3:
	/* 0x7b3: js     9e0 <generic_sleepable_preload+0x9e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_9e0;
	}
x86_l_7b9:
	/* 0x7b9: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_7be:
	/* 0x7be: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_7c4:
	/* 0x7c4: mov    eax,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7c7:
	/* 0x7c7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7cb:
	/* 0x7cb: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_7d0:
	/* 0x7d0: je     7ed <generic_sleepable_preload+0x7ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7ed;
	}
x86_l_7d2:
	/* 0x7d2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7d7:
	/* 0x7d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7db:
	/* 0x7db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7de:
	/* 0x7de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e3:
	/* 0x7e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e5:
	/* 0x7e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7e7:
	/* 0x7e7: js     1bc2 <generic_sleepable_preload+0x1bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7106ULL;
	}
x86_l_7ed:
	/* 0x7ed: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_7f5:
	/* 0x7f5: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_7fb:
	/* 0x7fb: mov    eax,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_801:
	/* 0x801: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_805:
	/* 0x805: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_80d:
	/* 0x80d: je     82a <generic_sleepable_preload+0x82a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82a;
	}
x86_l_80f:
	/* 0x80f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_814:
	/* 0x814: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_818:
	/* 0x818: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_81b:
	/* 0x81b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_820:
	/* 0x820: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_822:
	/* 0x822: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_824:
	/* 0x824: js     244b <generic_sleepable_preload+0x244b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9291ULL;
	}
x86_l_82a:
	/* 0x82a: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_832:
	/* 0x832: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_838:
	/* 0x838: mov    eax,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_83e:
	/* 0x83e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_842:
	/* 0x842: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_84a:
	/* 0x84a: je     867 <generic_sleepable_preload+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_867;
	}
x86_l_84c:
	/* 0x84c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_851:
	/* 0x851: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_855:
	/* 0x855: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_858:
	/* 0x858: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_85d:
	/* 0x85d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85f:
	/* 0x85f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_861:
	/* 0x861: js     24c7 <generic_sleepable_preload+0x24c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9415ULL;
	}
x86_l_867:
	/* 0x867: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_86f:
	/* 0x86f: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_875:
	/* 0x875: mov    eax,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_87b:
	/* 0x87b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_87f:
	/* 0x87f: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_887:
	/* 0x887: je     8a4 <generic_sleepable_preload+0x8a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a4;
	}
x86_l_889:
	/* 0x889: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_88e:
	/* 0x88e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_892:
	/* 0x892: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_895:
	/* 0x895: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_89a:
	/* 0x89a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89c:
	/* 0x89c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_89e:
	/* 0x89e: js     2543 <generic_sleepable_preload+0x2543> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9539ULL;
	}
x86_l_8a4:
	/* 0x8a4: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_8ac:
	/* 0x8ac: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_8b2:
	/* 0x8b2: mov    eax,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8b8:
	/* 0x8b8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8bc:
	/* 0x8bc: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_8c4:
	/* 0x8c4: je     8e1 <generic_sleepable_preload+0x8e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8e1;
	}
x86_l_8c6:
	/* 0x8c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8cb:
	/* 0x8cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8cf:
	/* 0x8cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8d2:
	/* 0x8d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d7:
	/* 0x8d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d9:
	/* 0x8d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8db:
	/* 0x8db: js     25bf <generic_sleepable_preload+0x25bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9663ULL;
	}
x86_l_8e1:
	/* 0x8e1: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_8e9:
	/* 0x8e9: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_8ef:
	/* 0x8ef: mov    eax,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8f5:
	/* 0x8f5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8f9:
	/* 0x8f9: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_901:
	/* 0x901: je     91e <generic_sleepable_preload+0x91e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_91e;
	}
x86_l_903:
	/* 0x903: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_908:
	/* 0x908: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90c:
	/* 0x90c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_90f:
	/* 0x90f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_914:
	/* 0x914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_916:
	/* 0x916: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_918:
	/* 0x918: js     2638 <generic_sleepable_preload+0x2638> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9784ULL;
	}
x86_l_91e:
	/* 0x91e: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_926:
	/* 0x926: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_92c:
	/* 0x92c: mov    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_932:
	/* 0x932: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_936:
	/* 0x936: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_93e:
	/* 0x93e: je     95b <generic_sleepable_preload+0x95b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_95b;
	}
x86_l_940:
	/* 0x940: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_945:
	/* 0x945: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_949:
	/* 0x949: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_94c:
	/* 0x94c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_951:
	/* 0x951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_953:
	/* 0x953: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_955:
	/* 0x955: js     2d5d <generic_sleepable_preload+0x2d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11613ULL;
	}
x86_l_95b:
	/* 0x95b: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_963:
	/* 0x963: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_965:
	/* 0x965: mov    eax,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_96b:
	/* 0x96b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_96f:
	/* 0x96f: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_977:
	/* 0x977: je     994 <generic_sleepable_preload+0x994> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_994;
	}
x86_l_979:
	/* 0x979: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_97e:
	/* 0x97e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_982:
	/* 0x982: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_985:
	/* 0x985: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_98a:
	/* 0x98a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98c:
	/* 0x98c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_98e:
	/* 0x98e: js     2e51 <generic_sleepable_preload+0x2e51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11857ULL;
	}
x86_l_994:
	/* 0x994: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_99c:
	/* 0x99c: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_99e:
	/* 0x99e: mov    eax,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_9a4:
	/* 0x9a4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9a8:
	/* 0x9a8: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_9b0:
	/* 0x9b0: je     9cd <generic_sleepable_preload+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cd;
	}
x86_l_9b2:
	/* 0x9b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9b7:
	/* 0x9b7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9bb:
	/* 0x9bb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9be:
	/* 0x9be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c3:
	/* 0x9c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c5:
	/* 0x9c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9c7:
	/* 0x9c7: js     2ecd <generic_sleepable_preload+0x2ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11981ULL;
	}
x86_l_9cd:
	/* 0x9cd: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_9cf:
	/* 0x9cf: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9d3:
	/* 0x9d3: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_9db:
	/* 0x9db: jmp    2648 <generic_sleepable_preload+0x2648> */
	return 9800ULL;
x86_l_9e0:
	/* 0x9e0: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_9e8:
	/* 0x9e8: jmp    2640 <generic_sleepable_preload+0x2640> */
	return 9792ULL;
x86_l_9ed:
	/* 0x9ed: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9f2:
	/* 0x9f2: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f5:
	/* 0x9f5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f9:
	/* 0x9f9: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_a01:
	/* 0xa01: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_a07:
	/* 0xa07: mov    ecx,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_a0d:
	/* 0xa0d: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a10:
	/* 0xa10: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a14:
	/* 0xa14: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_a1c:
	/* 0xa1c: je     a39 <generic_sleepable_preload+0xa39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a39;
	}
x86_l_a1e:
	/* 0xa1e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a23:
	/* 0xa23: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a27:
	/* 0xa27: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a2a:
	/* 0xa2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2f:
	/* 0xa2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a31:
	/* 0xa31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a33:
	/* 0xa33: js     c69 <generic_sleepable_preload+0xc69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_c69;
	}
x86_l_a39:
	/* 0xa39: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_a41:
	/* 0xa41: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_a47:
	/* 0xa47: mov    eax,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_a4d:
	/* 0xa4d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a51:
	/* 0xa51: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_a59:
	/* 0xa59: je     a76 <generic_sleepable_preload+0xa76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a76;
	}
x86_l_a5b:
	/* 0xa5b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a60:
	/* 0xa60: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a64:
	/* 0xa64: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a6c:
	/* 0xa6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6e:
	/* 0xa6e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a70:
	/* 0xa70: js     1bcf <generic_sleepable_preload+0x1bcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7119ULL;
	}
x86_l_a76:
	/* 0xa76: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_a7e:
	/* 0xa7e: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_a84:
	/* 0xa84: mov    eax,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_a8a:
	/* 0xa8a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a8e:
	/* 0xa8e: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_a96:
	/* 0xa96: je     ab3 <generic_sleepable_preload+0xab3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab3;
	}
x86_l_a98:
	/* 0xa98: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a9d:
	/* 0xa9d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa1:
	/* 0xaa1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_aa4:
	/* 0xaa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aa9:
	/* 0xaa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aab:
	/* 0xaab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aad:
	/* 0xaad: js     2458 <generic_sleepable_preload+0x2458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9304ULL;
	}
x86_l_ab3:
	/* 0xab3: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_abb:
	/* 0xabb: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_ac1:
	/* 0xac1: mov    eax,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_ac7:
	/* 0xac7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_acb:
	/* 0xacb: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_ad3:
	/* 0xad3: je     af0 <generic_sleepable_preload+0xaf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af0;
	}
x86_l_ad5:
	/* 0xad5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ada:
	/* 0xada: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ade:
	/* 0xade: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ae1:
	/* 0xae1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae6:
	/* 0xae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae8:
	/* 0xae8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aea:
	/* 0xaea: js     24d4 <generic_sleepable_preload+0x24d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9428ULL;
	}
x86_l_af0:
	/* 0xaf0: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_af8:
	/* 0xaf8: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_afe:
	/* 0xafe: mov    eax,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_b04:
	/* 0xb04: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b08:
	/* 0xb08: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_b10:
	/* 0xb10: je     b2d <generic_sleepable_preload+0xb2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b2d;
	}
x86_l_b12:
	/* 0xb12: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b17:
	/* 0xb17: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1b:
	/* 0xb1b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b1e:
	/* 0xb1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b23:
	/* 0xb23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b25:
	/* 0xb25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b27:
	/* 0xb27: js     2550 <generic_sleepable_preload+0x2550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9552ULL;
	}
x86_l_b2d:
	/* 0xb2d: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_b35:
	/* 0xb35: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_b3b:
	/* 0xb3b: mov    eax,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_b41:
	/* 0xb41: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b45:
	/* 0xb45: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_b4d:
	/* 0xb4d: je     b6a <generic_sleepable_preload+0xb6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b6a;
	}
x86_l_b4f:
	/* 0xb4f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b54:
	/* 0xb54: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b58:
	/* 0xb58: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b5b:
	/* 0xb5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b60:
	/* 0xb60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b62:
	/* 0xb62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b64:
	/* 0xb64: js     25c9 <generic_sleepable_preload+0x25c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9673ULL;
	}
x86_l_b6a:
	/* 0xb6a: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_b72:
	/* 0xb72: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_b78:
	/* 0xb78: mov    eax,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_b7e:
	/* 0xb7e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b82:
	/* 0xb82: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_b8a:
	/* 0xb8a: je     ba7 <generic_sleepable_preload+0xba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ba7;
	}
x86_l_b8c:
	/* 0xb8c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b91:
	/* 0xb91: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b95:
	/* 0xb95: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b98:
	/* 0xb98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b9d:
	/* 0xb9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9f:
	/* 0xb9f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ba1:
	/* 0xba1: js     26e8 <generic_sleepable_preload+0x26e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9960ULL;
	}
x86_l_ba7:
	/* 0xba7: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_baf:
	/* 0xbaf: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_bb5:
	/* 0xbb5: mov    eax,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_bbb:
	/* 0xbbb: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_bbf:
	/* 0xbbf: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_bc7:
	/* 0xbc7: je     be4 <generic_sleepable_preload+0xbe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_be4;
	}
x86_l_bc9:
	/* 0xbc9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bce:
	/* 0xbce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd2:
	/* 0xbd2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bd5:
	/* 0xbd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bda:
	/* 0xbda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bdc:
	/* 0xbdc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bde:
	/* 0xbde: js     2d72 <generic_sleepable_preload+0x2d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11634ULL;
	}
x86_l_be4:
	/* 0xbe4: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_bec:
	/* 0xbec: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_bee:
	/* 0xbee: mov    eax,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_bf4:
	/* 0xbf4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_bf8:
	/* 0xbf8: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_c00:
	/* 0xc00: je     c1d <generic_sleepable_preload+0xc1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1d;
	}
x86_l_c02:
	/* 0xc02: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c07:
	/* 0xc07: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0b:
	/* 0xc0b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c0e:
	/* 0xc0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c13:
	/* 0xc13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c15:
	/* 0xc15: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c17:
	/* 0xc17: js     2e5e <generic_sleepable_preload+0x2e5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11870ULL;
	}
x86_l_c1d:
	/* 0xc1d: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_c25:
	/* 0xc25: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_c27:
	/* 0xc27: mov    eax,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_c2d:
	/* 0xc2d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c31:
	/* 0xc31: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_c39:
	/* 0xc39: je     c56 <generic_sleepable_preload+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c56;
	}
x86_l_c3b:
	/* 0xc3b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c40:
	/* 0xc40: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c44:
	/* 0xc44: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c47:
	/* 0xc47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c4c:
	/* 0xc4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4e:
	/* 0xc4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c50:
	/* 0xc50: js     2eda <generic_sleepable_preload+0x2eda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11994ULL;
	}
x86_l_c56:
	/* 0xc56: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_c58:
	/* 0xc58: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5c:
	/* 0xc5c: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_c64:
	/* 0xc64: jmp    26f8 <generic_sleepable_preload+0x26f8> */
	return 9976ULL;
x86_l_c69:
	/* 0xc69: mov    DWORD PTR [rsp+0xc],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607553ULL);
x86_l_c71:
	/* 0xc71: jmp    26f0 <generic_sleepable_preload+0x26f0> */
	return 9968ULL;
x86_l_c76:
	/* 0xc76: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c7b:
	/* 0xc7b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7e:
	/* 0xc7e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c82:
	/* 0xc82: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_c8a:
	/* 0xc8a: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3807ULL;
	}
x86_l_c90:
	/* 0xc90: mov    ecx,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_c96:
	/* 0xc96: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c99:
	/* 0xc99: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9d:
	/* 0xc9d: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_ca5:
	/* 0xca5: je     cc2 <generic_sleepable_preload+0xcc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc2;
	}
x86_l_ca7:
	/* 0xca7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_cac:
	/* 0xcac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb0:
	/* 0xcb0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_cb3:
	/* 0xcb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cb8:
	/* 0xcb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cba:
	/* 0xcba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cbc:
	/* 0xcbc: js     ef2 <generic_sleepable_preload+0xef2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3826ULL;
	}
x86_l_cc2:
	/* 0xcc2: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_cca:
	/* 0xcca: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3807ULL;
	}
x86_l_cd0:
	/* 0xcd0: mov    eax,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_cd6:
	/* 0xcd6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_cda:
	/* 0xcda: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_ce2:
	/* 0xce2: je     cff <generic_sleepable_preload+0xcff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cff;
	}
x86_l_ce4:
	/* 0xce4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ce9:
	/* 0xce9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ced:
	/* 0xced: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_cf0:
	/* 0xcf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf5:
	/* 0xcf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf7:
	/* 0xcf7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cf9:
	/* 0xcf9: js     1bdc <generic_sleepable_preload+0x1bdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7132ULL;
	}
x86_l_cff:
	/* 0xcff: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_d07:
	/* 0xd07: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3807ULL;
	}
x86_l_d0d:
	/* 0xd0d: mov    eax,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_d13:
	/* 0xd13: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d17:
	/* 0xd17: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_d1f:
	/* 0xd1f: je     d3c <generic_sleepable_preload+0xd3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d3c;
	}
x86_l_d21:
	/* 0xd21: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d26:
	/* 0xd26: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d2a:
	/* 0xd2a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d2d:
	/* 0xd2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d32:
	/* 0xd32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d34:
	/* 0xd34: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d36:
	/* 0xd36: js     2465 <generic_sleepable_preload+0x2465> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9317ULL;
	}
x86_l_d3c:
	/* 0xd3c: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_d44:
	/* 0xd44: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3807ULL;
	}
x86_l_d4a:
	/* 0xd4a: mov    eax,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_d50:
	/* 0xd50: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d54:
	/* 0xd54: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_d5c:
	/* 0xd5c: je     d79 <generic_sleepable_preload+0xd79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d79;
	}
x86_l_d5e:
	/* 0xd5e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d63:
	/* 0xd63: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d67:
	/* 0xd67: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d6a:
	/* 0xd6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d6f:
	/* 0xd6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d71:
	/* 0xd71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d73:
	/* 0xd73: js     24e1 <generic_sleepable_preload+0x24e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9441ULL;
	}
x86_l_d79:
	/* 0xd79: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_d81:
	/* 0xd81: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3807ULL;
	}
x86_l_d87:
	/* 0xd87: mov    eax,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_d8d:
	/* 0xd8d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d91:
	/* 0xd91: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_d99:
	/* 0xd99: je     db6 <generic_sleepable_preload+0xdb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db6;
	}
x86_l_d9b:
	/* 0xd9b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_da0:
	/* 0xda0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da4:
	/* 0xda4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_da7:
	/* 0xda7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dac:
	/* 0xdac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dae:
	/* 0xdae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_db0:
	/* 0xdb0: js     255d <generic_sleepable_preload+0x255d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9565ULL;
	}
x86_l_db6:
	/* 0xdb6: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_dbe:
	/* 0xdbe: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3807ULL;
	}
	return 3524ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3524ULL: goto x86_l_dc4;
	case 3530ULL: goto x86_l_dca;
	case 3534ULL: goto x86_l_dce;
	case 3542ULL: goto x86_l_dd6;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3553ULL: goto x86_l_de1;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3563ULL: goto x86_l_deb;
	case 3565ULL: goto x86_l_ded;
	case 3571ULL: goto x86_l_df3;
	case 3579ULL: goto x86_l_dfb;
	case 3585ULL: goto x86_l_e01;
	case 3591ULL: goto x86_l_e07;
	case 3595ULL: goto x86_l_e0b;
	case 3603ULL: goto x86_l_e13;
	case 3605ULL: goto x86_l_e15;
	case 3610ULL: goto x86_l_e1a;
	case 3614ULL: goto x86_l_e1e;
	case 3617ULL: goto x86_l_e21;
	case 3622ULL: goto x86_l_e26;
	case 3624ULL: goto x86_l_e28;
	case 3626ULL: goto x86_l_e2a;
	case 3632ULL: goto x86_l_e30;
	case 3640ULL: goto x86_l_e38;
	case 3646ULL: goto x86_l_e3e;
	case 3652ULL: goto x86_l_e44;
	case 3656ULL: goto x86_l_e48;
	case 3664ULL: goto x86_l_e50;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3675ULL: goto x86_l_e5b;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3685ULL: goto x86_l_e65;
	case 3687ULL: goto x86_l_e67;
	case 3693ULL: goto x86_l_e6d;
	case 3701ULL: goto x86_l_e75;
	case 3703ULL: goto x86_l_e77;
	case 3709ULL: goto x86_l_e7d;
	case 3713ULL: goto x86_l_e81;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	case 3728ULL: goto x86_l_e90;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3740ULL: goto x86_l_e9c;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3750ULL: goto x86_l_ea6;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3766ULL: goto x86_l_eb6;
	case 3770ULL: goto x86_l_eba;
	case 3778ULL: goto x86_l_ec2;
	case 3780ULL: goto x86_l_ec4;
	case 3785ULL: goto x86_l_ec9;
	case 3789ULL: goto x86_l_ecd;
	case 3792ULL: goto x86_l_ed0;
	case 3797ULL: goto x86_l_ed5;
	case 3799ULL: goto x86_l_ed7;
	case 3801ULL: goto x86_l_ed9;
	case 3807ULL: goto x86_l_edf;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3834ULL: goto x86_l_efa;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3851ULL: goto x86_l_f0b;
	case 3859ULL: goto x86_l_f13;
	case 3865ULL: goto x86_l_f19;
	case 3871ULL: goto x86_l_f1f;
	case 3874ULL: goto x86_l_f22;
	case 3878ULL: goto x86_l_f26;
	case 3886ULL: goto x86_l_f2e;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	case 3897ULL: goto x86_l_f39;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3907ULL: goto x86_l_f43;
	case 3909ULL: goto x86_l_f45;
	case 3915ULL: goto x86_l_f4b;
	case 3923ULL: goto x86_l_f53;
	case 3929ULL: goto x86_l_f59;
	case 3935ULL: goto x86_l_f5f;
	case 3939ULL: goto x86_l_f63;
	case 3947ULL: goto x86_l_f6b;
	case 3949ULL: goto x86_l_f6d;
	case 3954ULL: goto x86_l_f72;
	case 3958ULL: goto x86_l_f76;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3968ULL: goto x86_l_f80;
	case 3970ULL: goto x86_l_f82;
	case 3976ULL: goto x86_l_f88;
	case 3984ULL: goto x86_l_f90;
	case 3990ULL: goto x86_l_f96;
	case 3996ULL: goto x86_l_f9c;
	case 4000ULL: goto x86_l_fa0;
	case 4008ULL: goto x86_l_fa8;
	case 4010ULL: goto x86_l_faa;
	case 4015ULL: goto x86_l_faf;
	case 4019ULL: goto x86_l_fb3;
	case 4022ULL: goto x86_l_fb6;
	case 4027ULL: goto x86_l_fbb;
	case 4029ULL: goto x86_l_fbd;
	case 4031ULL: goto x86_l_fbf;
	case 4037ULL: goto x86_l_fc5;
	case 4045ULL: goto x86_l_fcd;
	case 4051ULL: goto x86_l_fd3;
	case 4057ULL: goto x86_l_fd9;
	case 4061ULL: goto x86_l_fdd;
	case 4069ULL: goto x86_l_fe5;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4080ULL: goto x86_l_ff0;
	case 4083ULL: goto x86_l_ff3;
	case 4088ULL: goto x86_l_ff8;
	case 4090ULL: goto x86_l_ffa;
	case 4092ULL: goto x86_l_ffc;
	case 4098ULL: goto x86_l_1002;
	case 4106ULL: goto x86_l_100a;
	case 4112ULL: goto x86_l_1010;
	case 4118ULL: goto x86_l_1016;
	case 4122ULL: goto x86_l_101a;
	case 4130ULL: goto x86_l_1022;
	case 4132ULL: goto x86_l_1024;
	case 4137ULL: goto x86_l_1029;
	case 4141ULL: goto x86_l_102d;
	case 4144ULL: goto x86_l_1030;
	case 4149ULL: goto x86_l_1035;
	case 4151ULL: goto x86_l_1037;
	case 4153ULL: goto x86_l_1039;
	case 4159ULL: goto x86_l_103f;
	case 4167ULL: goto x86_l_1047;
	case 4173ULL: goto x86_l_104d;
	case 4179ULL: goto x86_l_1053;
	case 4183ULL: goto x86_l_1057;
	case 4191ULL: goto x86_l_105f;
	case 4193ULL: goto x86_l_1061;
	case 4198ULL: goto x86_l_1066;
	case 4202ULL: goto x86_l_106a;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4212ULL: goto x86_l_1074;
	case 4214ULL: goto x86_l_1076;
	case 4220ULL: goto x86_l_107c;
	case 4228ULL: goto x86_l_1084;
	case 4234ULL: goto x86_l_108a;
	case 4240ULL: goto x86_l_1090;
	case 4244ULL: goto x86_l_1094;
	case 4252ULL: goto x86_l_109c;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4263ULL: goto x86_l_10a7;
	case 4266ULL: goto x86_l_10aa;
	case 4271ULL: goto x86_l_10af;
	case 4273ULL: goto x86_l_10b1;
	case 4275ULL: goto x86_l_10b3;
	case 4281ULL: goto x86_l_10b9;
	case 4289ULL: goto x86_l_10c1;
	case 4295ULL: goto x86_l_10c7;
	case 4301ULL: goto x86_l_10cd;
	case 4305ULL: goto x86_l_10d1;
	case 4313ULL: goto x86_l_10d9;
	case 4315ULL: goto x86_l_10db;
	case 4320ULL: goto x86_l_10e0;
	case 4324ULL: goto x86_l_10e4;
	case 4327ULL: goto x86_l_10e7;
	case 4332ULL: goto x86_l_10ec;
	case 4334ULL: goto x86_l_10ee;
	case 4336ULL: goto x86_l_10f0;
	case 4342ULL: goto x86_l_10f6;
	case 4350ULL: goto x86_l_10fe;
	case 4352ULL: goto x86_l_1100;
	case 4358ULL: goto x86_l_1106;
	case 4362ULL: goto x86_l_110a;
	case 4370ULL: goto x86_l_1112;
	case 4372ULL: goto x86_l_1114;
	case 4377ULL: goto x86_l_1119;
	case 4381ULL: goto x86_l_111d;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4391ULL: goto x86_l_1127;
	case 4393ULL: goto x86_l_1129;
	case 4399ULL: goto x86_l_112f;
	case 4407ULL: goto x86_l_1137;
	case 4409ULL: goto x86_l_1139;
	case 4415ULL: goto x86_l_113f;
	case 4419ULL: goto x86_l_1143;
	case 4427ULL: goto x86_l_114b;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4438ULL: goto x86_l_1156;
	case 4441ULL: goto x86_l_1159;
	case 4446ULL: goto x86_l_115e;
	case 4448ULL: goto x86_l_1160;
	case 4450ULL: goto x86_l_1162;
	case 4456ULL: goto x86_l_1168;
	case 4458ULL: goto x86_l_116a;
	case 4462ULL: goto x86_l_116e;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4483ULL: goto x86_l_1183;
	case 4488ULL: goto x86_l_1188;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4500ULL: goto x86_l_1194;
	case 4502ULL: goto x86_l_1196;
	case 4505ULL: goto x86_l_1199;
	case 4513ULL: goto x86_l_11a1;
	case 4519ULL: goto x86_l_11a7;
	case 4525ULL: goto x86_l_11ad;
	case 4528ULL: goto x86_l_11b0;
	case 4532ULL: goto x86_l_11b4;
	case 4540ULL: goto x86_l_11bc;
	case 4542ULL: goto x86_l_11be;
	case 4547ULL: goto x86_l_11c3;
	case 4551ULL: goto x86_l_11c7;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4561ULL: goto x86_l_11d1;
	case 4563ULL: goto x86_l_11d3;
	case 4569ULL: goto x86_l_11d9;
	case 4577ULL: goto x86_l_11e1;
	case 4583ULL: goto x86_l_11e7;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4601ULL: goto x86_l_11f9;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4612ULL: goto x86_l_1204;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4622ULL: goto x86_l_120e;
	case 4624ULL: goto x86_l_1210;
	case 4630ULL: goto x86_l_1216;
	case 4638ULL: goto x86_l_121e;
	case 4644ULL: goto x86_l_1224;
	case 4650ULL: goto x86_l_122a;
	case 4654ULL: goto x86_l_122e;
	case 4662ULL: goto x86_l_1236;
	case 4664ULL: goto x86_l_1238;
	case 4669ULL: goto x86_l_123d;
	case 4673ULL: goto x86_l_1241;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4683ULL: goto x86_l_124b;
	case 4685ULL: goto x86_l_124d;
	case 4691ULL: goto x86_l_1253;
	case 4699ULL: goto x86_l_125b;
	case 4705ULL: goto x86_l_1261;
	case 4711ULL: goto x86_l_1267;
	case 4715ULL: goto x86_l_126b;
	case 4723ULL: goto x86_l_1273;
	case 4725ULL: goto x86_l_1275;
	case 4730ULL: goto x86_l_127a;
	case 4734ULL: goto x86_l_127e;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4744ULL: goto x86_l_1288;
	case 4746ULL: goto x86_l_128a;
	case 4752ULL: goto x86_l_1290;
	case 4760ULL: goto x86_l_1298;
	case 4766ULL: goto x86_l_129e;
	case 4772ULL: goto x86_l_12a4;
	case 4776ULL: goto x86_l_12a8;
	case 4784ULL: goto x86_l_12b0;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4795ULL: goto x86_l_12bb;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4805ULL: goto x86_l_12c5;
	case 4807ULL: goto x86_l_12c7;
	case 4813ULL: goto x86_l_12cd;
	case 4821ULL: goto x86_l_12d5;
	case 4827ULL: goto x86_l_12db;
	case 4833ULL: goto x86_l_12e1;
	case 4837ULL: goto x86_l_12e5;
	case 4845ULL: goto x86_l_12ed;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4864ULL: goto x86_l_1300;
	case 4866ULL: goto x86_l_1302;
	case 4868ULL: goto x86_l_1304;
	case 4874ULL: goto x86_l_130a;
	case 4882ULL: goto x86_l_1312;
	case 4888ULL: goto x86_l_1318;
	case 4894ULL: goto x86_l_131e;
	case 4898ULL: goto x86_l_1322;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4917ULL: goto x86_l_1335;
	case 4920ULL: goto x86_l_1338;
	case 4925ULL: goto x86_l_133d;
	case 4927ULL: goto x86_l_133f;
	case 4929ULL: goto x86_l_1341;
	case 4935ULL: goto x86_l_1347;
	case 4943ULL: goto x86_l_134f;
	case 4949ULL: goto x86_l_1355;
	case 4955ULL: goto x86_l_135b;
	case 4959ULL: goto x86_l_135f;
	case 4967ULL: goto x86_l_1367;
	case 4969ULL: goto x86_l_1369;
	case 4974ULL: goto x86_l_136e;
	case 4978ULL: goto x86_l_1372;
	case 4981ULL: goto x86_l_1375;
	case 4986ULL: goto x86_l_137a;
	case 4988ULL: goto x86_l_137c;
	case 4990ULL: goto x86_l_137e;
	case 4996ULL: goto x86_l_1384;
	case 5004ULL: goto x86_l_138c;
	case 5010ULL: goto x86_l_1392;
	case 5016ULL: goto x86_l_1398;
	case 5020ULL: goto x86_l_139c;
	case 5028ULL: goto x86_l_13a4;
	case 5030ULL: goto x86_l_13a6;
	case 5035ULL: goto x86_l_13ab;
	case 5039ULL: goto x86_l_13af;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5049ULL: goto x86_l_13b9;
	case 5051ULL: goto x86_l_13bb;
	case 5057ULL: goto x86_l_13c1;
	case 5065ULL: goto x86_l_13c9;
	case 5071ULL: goto x86_l_13cf;
	case 5077ULL: goto x86_l_13d5;
	case 5081ULL: goto x86_l_13d9;
	case 5089ULL: goto x86_l_13e1;
	case 5095ULL: goto x86_l_13e7;
	case 5100ULL: goto x86_l_13ec;
	case 5104ULL: goto x86_l_13f0;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5114ULL: goto x86_l_13fa;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5127ULL: goto x86_l_1407;
	case 5132ULL: goto x86_l_140c;
	case 5137ULL: goto x86_l_1411;
	case 5142ULL: goto x86_l_1416;
	case 5150ULL: goto x86_l_141e;
	case 5153ULL: goto x86_l_1421;
	case 5159ULL: goto x86_l_1427;
	case 5162ULL: goto x86_l_142a;
	case 5165ULL: goto x86_l_142d;
	case 5171ULL: goto x86_l_1433;
	case 5176ULL: goto x86_l_1438;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5199ULL: goto x86_l_144f;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5227ULL: goto x86_l_146b;
	case 5230ULL: goto x86_l_146e;
	case 5233ULL: goto x86_l_1471;
	case 5239ULL: goto x86_l_1477;
	case 5244ULL: goto x86_l_147c;
	case 5252ULL: goto x86_l_1484;
	case 5255ULL: goto x86_l_1487;
	case 5261ULL: goto x86_l_148d;
	case 5264ULL: goto x86_l_1490;
	case 5267ULL: goto x86_l_1493;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5295ULL: goto x86_l_14af;
	case 5298ULL: goto x86_l_14b2;
	case 5301ULL: goto x86_l_14b5;
	case 5307ULL: goto x86_l_14bb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_dc4:
	/* 0xdc4: mov    eax,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_dca:
	/* 0xdca: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_dce:
	/* 0xdce: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_dd6:
	/* 0xdd6: je     df3 <generic_sleepable_preload+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df3;
	}
x86_l_dd8:
	/* 0xdd8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ddd:
	/* 0xddd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de1:
	/* 0xde1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_de4:
	/* 0xde4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_de9:
	/* 0xde9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_deb:
	/* 0xdeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ded:
	/* 0xded: js     25d6 <generic_sleepable_preload+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9686ULL;
	}
x86_l_df3:
	/* 0xdf3: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_dfb:
	/* 0xdfb: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_edf;
	}
x86_l_e01:
	/* 0xe01: mov    eax,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_e07:
	/* 0xe07: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_e0b:
	/* 0xe0b: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_e13:
	/* 0xe13: je     e30 <generic_sleepable_preload+0xe30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e30;
	}
x86_l_e15:
	/* 0xe15: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e1a:
	/* 0xe1a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1e:
	/* 0xe1e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e21:
	/* 0xe21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e26:
	/* 0xe26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e28:
	/* 0xe28: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e2a:
	/* 0xe2a: js     27c6 <generic_sleepable_preload+0x27c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10182ULL;
	}
x86_l_e30:
	/* 0xe30: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_e38:
	/* 0xe38: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_edf;
	}
x86_l_e3e:
	/* 0xe3e: mov    eax,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_e44:
	/* 0xe44: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_e48:
	/* 0xe48: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_e50:
	/* 0xe50: je     e6d <generic_sleepable_preload+0xe6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e6d;
	}
x86_l_e52:
	/* 0xe52: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e57:
	/* 0xe57: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5b:
	/* 0xe5b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e5e:
	/* 0xe5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e63:
	/* 0xe63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e65:
	/* 0xe65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e67:
	/* 0xe67: js     2d87 <generic_sleepable_preload+0x2d87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11655ULL;
	}
x86_l_e6d:
	/* 0xe6d: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_e75:
	/* 0xe75: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_edf;
	}
x86_l_e77:
	/* 0xe77: mov    eax,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_e7d:
	/* 0xe7d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_e81:
	/* 0xe81: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_e89:
	/* 0xe89: je     ea6 <generic_sleepable_preload+0xea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea6;
	}
x86_l_e8b:
	/* 0xe8b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e90:
	/* 0xe90: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e94:
	/* 0xe94: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e97:
	/* 0xe97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e9c:
	/* 0xe9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9e:
	/* 0xe9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ea0:
	/* 0xea0: js     2e6b <generic_sleepable_preload+0x2e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11883ULL;
	}
x86_l_ea6:
	/* 0xea6: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_eae:
	/* 0xeae: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_edf;
	}
x86_l_eb0:
	/* 0xeb0: mov    eax,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_eb6:
	/* 0xeb6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_eba:
	/* 0xeba: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_ec2:
	/* 0xec2: je     edf <generic_sleepable_preload+0xedf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_edf;
	}
x86_l_ec4:
	/* 0xec4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ec9:
	/* 0xec9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ecd:
	/* 0xecd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ed0:
	/* 0xed0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ed5:
	/* 0xed5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed7:
	/* 0xed7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ed9:
	/* 0xed9: js     2ee7 <generic_sleepable_preload+0x2ee7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12007ULL;
	}
x86_l_edf:
	/* 0xedf: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_ee1:
	/* 0xee1: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee5:
	/* 0xee5: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_eed:
	/* 0xeed: jmp    27d6 <generic_sleepable_preload+0x27d6> */
	return 10198ULL;
x86_l_ef2:
	/* 0xef2: mov    DWORD PTR [rsp+0xc],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607553ULL);
x86_l_efa:
	/* 0xefa: jmp    27ce <generic_sleepable_preload+0x27ce> */
	return 10190ULL;
x86_l_eff:
	/* 0xeff: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f04:
	/* 0xf04: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f07:
	/* 0xf07: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f0b:
	/* 0xf0b: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_f13:
	/* 0xf13: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_f19:
	/* 0xf19: mov    ecx,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_f1f:
	/* 0xf1f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f22:
	/* 0xf22: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f26:
	/* 0xf26: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_f2e:
	/* 0xf2e: je     f4b <generic_sleepable_preload+0xf4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f4b;
	}
x86_l_f30:
	/* 0xf30: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f35:
	/* 0xf35: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f39:
	/* 0xf39: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f3c:
	/* 0xf3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f41:
	/* 0xf41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f43:
	/* 0xf43: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f45:
	/* 0xf45: js     117b <generic_sleepable_preload+0x117b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_117b;
	}
x86_l_f4b:
	/* 0xf4b: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_f53:
	/* 0xf53: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_f59:
	/* 0xf59: mov    eax,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_f5f:
	/* 0xf5f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_f63:
	/* 0xf63: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_f6b:
	/* 0xf6b: je     f88 <generic_sleepable_preload+0xf88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f88;
	}
x86_l_f6d:
	/* 0xf6d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f72:
	/* 0xf72: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f76:
	/* 0xf76: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f79:
	/* 0xf79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f7e:
	/* 0xf7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f80:
	/* 0xf80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f82:
	/* 0xf82: js     1be9 <generic_sleepable_preload+0x1be9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7145ULL;
	}
x86_l_f88:
	/* 0xf88: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_f90:
	/* 0xf90: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_f96:
	/* 0xf96: mov    eax,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_f9c:
	/* 0xf9c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_fa0:
	/* 0xfa0: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_fa8:
	/* 0xfa8: je     fc5 <generic_sleepable_preload+0xfc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fc5;
	}
x86_l_faa:
	/* 0xfaa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_faf:
	/* 0xfaf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb3:
	/* 0xfb3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fb6:
	/* 0xfb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fbb:
	/* 0xfbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbd:
	/* 0xfbd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fbf:
	/* 0xfbf: js     2472 <generic_sleepable_preload+0x2472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9330ULL;
	}
x86_l_fc5:
	/* 0xfc5: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_fcd:
	/* 0xfcd: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_fd3:
	/* 0xfd3: mov    eax,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_fd9:
	/* 0xfd9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_fdd:
	/* 0xfdd: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_fe5:
	/* 0xfe5: je     1002 <generic_sleepable_preload+0x1002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1002;
	}
x86_l_fe7:
	/* 0xfe7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_fec:
	/* 0xfec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff0:
	/* 0xff0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ff3:
	/* 0xff3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff8:
	/* 0xff8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffa:
	/* 0xffa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ffc:
	/* 0xffc: js     24ee <generic_sleepable_preload+0x24ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9454ULL;
	}
x86_l_1002:
	/* 0x1002: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_100a:
	/* 0x100a: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_1010:
	/* 0x1010: mov    eax,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_1016:
	/* 0x1016: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_101a:
	/* 0x101a: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_1022:
	/* 0x1022: je     103f <generic_sleepable_preload+0x103f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103f;
	}
x86_l_1024:
	/* 0x1024: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1029:
	/* 0x1029: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_102d:
	/* 0x102d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1030:
	/* 0x1030: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1035:
	/* 0x1035: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1037:
	/* 0x1037: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1039:
	/* 0x1039: js     256a <generic_sleepable_preload+0x256a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9578ULL;
	}
x86_l_103f:
	/* 0x103f: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_1047:
	/* 0x1047: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_104d:
	/* 0x104d: mov    eax,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_1053:
	/* 0x1053: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1057:
	/* 0x1057: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_105f:
	/* 0x105f: je     107c <generic_sleepable_preload+0x107c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107c;
	}
x86_l_1061:
	/* 0x1061: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1066:
	/* 0x1066: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_106a:
	/* 0x106a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_106d:
	/* 0x106d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1072:
	/* 0x1072: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1074:
	/* 0x1074: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1076:
	/* 0x1076: js     25e3 <generic_sleepable_preload+0x25e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9699ULL;
	}
x86_l_107c:
	/* 0x107c: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_1084:
	/* 0x1084: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_108a:
	/* 0x108a: mov    eax,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_1090:
	/* 0x1090: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1094:
	/* 0x1094: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_109c:
	/* 0x109c: je     10b9 <generic_sleepable_preload+0x10b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b9;
	}
x86_l_109e:
	/* 0x109e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10a3:
	/* 0x10a3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a7:
	/* 0x10a7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10aa:
	/* 0x10aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10af:
	/* 0x10af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b1:
	/* 0x10b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10b3:
	/* 0x10b3: js     28a4 <generic_sleepable_preload+0x28a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10404ULL;
	}
x86_l_10b9:
	/* 0x10b9: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_10c1:
	/* 0x10c1: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_10c7:
	/* 0x10c7: mov    eax,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_10cd:
	/* 0x10cd: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10d1:
	/* 0x10d1: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_10d9:
	/* 0x10d9: je     10f6 <generic_sleepable_preload+0x10f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10f6;
	}
x86_l_10db:
	/* 0x10db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10e0:
	/* 0x10e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e4:
	/* 0x10e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10e7:
	/* 0x10e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10ec:
	/* 0x10ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ee:
	/* 0x10ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10f0:
	/* 0x10f0: js     2d9c <generic_sleepable_preload+0x2d9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11676ULL;
	}
x86_l_10f6:
	/* 0x10f6: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_10fe:
	/* 0x10fe: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_1100:
	/* 0x1100: mov    eax,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_1106:
	/* 0x1106: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_110a:
	/* 0x110a: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_1112:
	/* 0x1112: je     112f <generic_sleepable_preload+0x112f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112f;
	}
x86_l_1114:
	/* 0x1114: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1119:
	/* 0x1119: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111d:
	/* 0x111d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1120:
	/* 0x1120: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1125:
	/* 0x1125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1127:
	/* 0x1127: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1129:
	/* 0x1129: js     2e78 <generic_sleepable_preload+0x2e78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11896ULL;
	}
x86_l_112f:
	/* 0x112f: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_1137:
	/* 0x1137: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_1139:
	/* 0x1139: mov    eax,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_113f:
	/* 0x113f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1143:
	/* 0x1143: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_114b:
	/* 0x114b: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_114d:
	/* 0x114d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1152:
	/* 0x1152: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1156:
	/* 0x1156: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1159:
	/* 0x1159: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_115e:
	/* 0x115e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1160:
	/* 0x1160: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1162:
	/* 0x1162: js     2ef4 <generic_sleepable_preload+0x2ef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12020ULL;
	}
x86_l_1168:
	/* 0x1168: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_116a:
	/* 0x116a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_116e:
	/* 0x116e: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1176:
	/* 0x1176: jmp    28b4 <generic_sleepable_preload+0x28b4> */
	return 10420ULL;
x86_l_117b:
	/* 0x117b: mov    DWORD PTR [rsp+0xc],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607553ULL);
x86_l_1183:
	/* 0x1183: jmp    28ac <generic_sleepable_preload+0x28ac> */
	return 10412ULL;
x86_l_1188:
	/* 0x1188: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_118d:
	/* 0x118d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1190:
	/* 0x1190: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1194:
	/* 0x1194: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1196:
	/* 0x1196: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1199:
	/* 0x1199: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_11a1:
	/* 0x11a1: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_11a7:
	/* 0x11a7: mov    ecx,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_11ad:
	/* 0x11ad: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_11b0:
	/* 0x11b0: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b4:
	/* 0x11b4: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_11bc:
	/* 0x11bc: je     11d9 <generic_sleepable_preload+0x11d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d9;
	}
x86_l_11be:
	/* 0x11be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11c3:
	/* 0x11c3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c7:
	/* 0x11c7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11ca:
	/* 0x11ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11cf:
	/* 0x11cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d1:
	/* 0x11d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11d3:
	/* 0x11d3: js     140c <generic_sleepable_preload+0x140c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_140c;
	}
x86_l_11d9:
	/* 0x11d9: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_11e1:
	/* 0x11e1: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_11e7:
	/* 0x11e7: mov    eax,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_11ed:
	/* 0x11ed: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11f1:
	/* 0x11f1: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_11f9:
	/* 0x11f9: je     1216 <generic_sleepable_preload+0x1216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1216;
	}
x86_l_11fb:
	/* 0x11fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1200:
	/* 0x1200: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1204:
	/* 0x1204: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1207:
	/* 0x1207: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_120c:
	/* 0x120c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120e:
	/* 0x120e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1210:
	/* 0x1210: js     1bf6 <generic_sleepable_preload+0x1bf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7158ULL;
	}
x86_l_1216:
	/* 0x1216: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_121e:
	/* 0x121e: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_1224:
	/* 0x1224: mov    eax,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_122a:
	/* 0x122a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_122e:
	/* 0x122e: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_1236:
	/* 0x1236: je     1253 <generic_sleepable_preload+0x1253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1253;
	}
x86_l_1238:
	/* 0x1238: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_123d:
	/* 0x123d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1241:
	/* 0x1241: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1244:
	/* 0x1244: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1249:
	/* 0x1249: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124b:
	/* 0x124b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_124d:
	/* 0x124d: js     247f <generic_sleepable_preload+0x247f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9343ULL;
	}
x86_l_1253:
	/* 0x1253: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_125b:
	/* 0x125b: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_1261:
	/* 0x1261: mov    eax,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_1267:
	/* 0x1267: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_126b:
	/* 0x126b: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_1273:
	/* 0x1273: je     1290 <generic_sleepable_preload+0x1290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1290;
	}
x86_l_1275:
	/* 0x1275: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_127a:
	/* 0x127a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_127e:
	/* 0x127e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1281:
	/* 0x1281: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1286:
	/* 0x1286: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1288:
	/* 0x1288: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_128a:
	/* 0x128a: js     24fb <generic_sleepable_preload+0x24fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9467ULL;
	}
x86_l_1290:
	/* 0x1290: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_1298:
	/* 0x1298: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_129e:
	/* 0x129e: mov    eax,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_12a4:
	/* 0x12a4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12a8:
	/* 0x12a8: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_12b0:
	/* 0x12b0: je     12cd <generic_sleepable_preload+0x12cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cd;
	}
x86_l_12b2:
	/* 0x12b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12b7:
	/* 0x12b7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12bb:
	/* 0x12bb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12be:
	/* 0x12be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12c3:
	/* 0x12c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c5:
	/* 0x12c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12c7:
	/* 0x12c7: js     2577 <generic_sleepable_preload+0x2577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9591ULL;
	}
x86_l_12cd:
	/* 0x12cd: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_12d5:
	/* 0x12d5: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_12db:
	/* 0x12db: mov    eax,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_12e1:
	/* 0x12e1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12e5:
	/* 0x12e5: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_12ed:
	/* 0x12ed: je     130a <generic_sleepable_preload+0x130a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_130a;
	}
x86_l_12ef:
	/* 0x12ef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12f4:
	/* 0x12f4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f8:
	/* 0x12f8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12fb:
	/* 0x12fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1300:
	/* 0x1300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1302:
	/* 0x1302: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1304:
	/* 0x1304: js     25f0 <generic_sleepable_preload+0x25f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9712ULL;
	}
x86_l_130a:
	/* 0x130a: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_1312:
	/* 0x1312: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_1318:
	/* 0x1318: mov    eax,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_131e:
	/* 0x131e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1322:
	/* 0x1322: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_132a:
	/* 0x132a: je     1347 <generic_sleepable_preload+0x1347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1347;
	}
x86_l_132c:
	/* 0x132c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1331:
	/* 0x1331: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1335:
	/* 0x1335: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1338:
	/* 0x1338: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_133d:
	/* 0x133d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133f:
	/* 0x133f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1341:
	/* 0x1341: js     2982 <generic_sleepable_preload+0x2982> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10626ULL;
	}
x86_l_1347:
	/* 0x1347: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_134f:
	/* 0x134f: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_1355:
	/* 0x1355: mov    eax,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_135b:
	/* 0x135b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_135f:
	/* 0x135f: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_1367:
	/* 0x1367: je     1384 <generic_sleepable_preload+0x1384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1384;
	}
x86_l_1369:
	/* 0x1369: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_136e:
	/* 0x136e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1372:
	/* 0x1372: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1375:
	/* 0x1375: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_137a:
	/* 0x137a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137c:
	/* 0x137c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_137e:
	/* 0x137e: js     2db1 <generic_sleepable_preload+0x2db1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11697ULL;
	}
x86_l_1384:
	/* 0x1384: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_138c:
	/* 0x138c: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_1392:
	/* 0x1392: mov    eax,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1398:
	/* 0x1398: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_139c:
	/* 0x139c: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_13a4:
	/* 0x13a4: je     13c1 <generic_sleepable_preload+0x13c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13c1;
	}
x86_l_13a6:
	/* 0x13a6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13ab:
	/* 0x13ab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13af:
	/* 0x13af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13b2:
	/* 0x13b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13b7:
	/* 0x13b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b9:
	/* 0x13b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13bb:
	/* 0x13bb: js     2e85 <generic_sleepable_preload+0x2e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11909ULL;
	}
x86_l_13c1:
	/* 0x13c1: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_13c9:
	/* 0x13c9: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_13cf:
	/* 0x13cf: mov    eax,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_13d5:
	/* 0x13d5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_13d9:
	/* 0x13d9: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_13e1:
	/* 0x13e1: je     298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10634ULL;
	}
x86_l_13e7:
	/* 0x13e7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13ec:
	/* 0x13ec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f0:
	/* 0x13f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13f3:
	/* 0x13f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13f8:
	/* 0x13f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fa:
	/* 0x13fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13fc:
	/* 0x13fc: jns    298a <generic_sleepable_preload+0x298a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10634ULL;
	}
x86_l_1402:
	/* 0x1402: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1407:
	/* 0x1407: jmp    2987 <generic_sleepable_preload+0x2987> */
	return 10631ULL;
x86_l_140c:
	/* 0x140c: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1411:
	/* 0x1411: jmp    2987 <generic_sleepable_preload+0x2987> */
	return 10631ULL;
x86_l_1416:
	/* 0x1416: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_141e:
	/* 0x141e: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1421:
	/* 0x1421: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_1427:
	/* 0x1427: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_142a:
	/* 0x142a: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_142d:
	/* 0x142d: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5660ULL;
	}
x86_l_1433:
	/* 0x1433: jmp    162f <generic_sleepable_preload+0x162f> */
	return 5679ULL;
x86_l_1438:
	/* 0x1438: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1440:
	/* 0x1440: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1443:
	/* 0x1443: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_1449:
	/* 0x1449: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_144c:
	/* 0x144c: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_144f:
	/* 0x144f: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_1455:
	/* 0x1455: jmp    1c2d <generic_sleepable_preload+0x1c2d> */
	return 7213ULL;
x86_l_145a:
	/* 0x145a: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1462:
	/* 0x1462: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1465:
	/* 0x1465: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_146b:
	/* 0x146b: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_146e:
	/* 0x146e: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1471:
	/* 0x1471: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_1477:
	/* 0x1477: jmp    1ee9 <generic_sleepable_preload+0x1ee9> */
	return 7913ULL;
x86_l_147c:
	/* 0x147c: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1484:
	/* 0x1484: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1487:
	/* 0x1487: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_148d:
	/* 0x148d: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1490:
	/* 0x1490: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1493:
	/* 0x1493: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_1499:
	/* 0x1499: jmp    21a5 <generic_sleepable_preload+0x21a5> */
	return 8613ULL;
x86_l_149e:
	/* 0x149e: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_14a6:
	/* 0x14a6: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_14a9:
	/* 0x14a9: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_14af:
	/* 0x14af: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_14b2:
	/* 0x14b2: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_14b5:
	/* 0x14b5: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6437ULL;
	}
x86_l_14bb:
	/* 0x14bb: jmp    1938 <generic_sleepable_preload+0x1938> */
	return 6456ULL;
	return 5312ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5312ULL: goto x86_l_14c0;
	case 5317ULL: goto x86_l_14c5;
	case 5320ULL: goto x86_l_14c8;
	case 5326ULL: goto x86_l_14ce;
	case 5331ULL: goto x86_l_14d3;
	case 5334ULL: goto x86_l_14d6;
	case 5340ULL: goto x86_l_14dc;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5353ULL: goto x86_l_14e9;
	case 5359ULL: goto x86_l_14ef;
	case 5364ULL: goto x86_l_14f4;
	case 5367ULL: goto x86_l_14f7;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5383ULL: goto x86_l_1507;
	case 5386ULL: goto x86_l_150a;
	case 5392ULL: goto x86_l_1510;
	case 5397ULL: goto x86_l_1515;
	case 5400ULL: goto x86_l_1518;
	case 5406ULL: goto x86_l_151e;
	case 5411ULL: goto x86_l_1523;
	case 5416ULL: goto x86_l_1528;
	case 5419ULL: goto x86_l_152b;
	case 5425ULL: goto x86_l_1531;
	case 5430ULL: goto x86_l_1536;
	case 5433ULL: goto x86_l_1539;
	case 5439ULL: goto x86_l_153f;
	case 5444ULL: goto x86_l_1544;
	case 5449ULL: goto x86_l_1549;
	case 5452ULL: goto x86_l_154c;
	case 5458ULL: goto x86_l_1552;
	case 5463ULL: goto x86_l_1557;
	case 5466ULL: goto x86_l_155a;
	case 5472ULL: goto x86_l_1560;
	case 5477ULL: goto x86_l_1565;
	case 5482ULL: goto x86_l_156a;
	case 5485ULL: goto x86_l_156d;
	case 5491ULL: goto x86_l_1573;
	case 5496ULL: goto x86_l_1578;
	case 5499ULL: goto x86_l_157b;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5518ULL: goto x86_l_158e;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5532ULL: goto x86_l_159c;
	case 5538ULL: goto x86_l_15a2;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5557ULL: goto x86_l_15b5;
	case 5562ULL: goto x86_l_15ba;
	case 5565ULL: goto x86_l_15bd;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5581ULL: goto x86_l_15cd;
	case 5584ULL: goto x86_l_15d0;
	case 5590ULL: goto x86_l_15d6;
	case 5595ULL: goto x86_l_15db;
	case 5598ULL: goto x86_l_15de;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5617ULL: goto x86_l_15f1;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5631ULL: goto x86_l_15ff;
	case 5637ULL: goto x86_l_1605;
	case 5642ULL: goto x86_l_160a;
	case 5647ULL: goto x86_l_160f;
	case 5650ULL: goto x86_l_1612;
	case 5652ULL: goto x86_l_1614;
	case 5655ULL: goto x86_l_1617;
	case 5658ULL: goto x86_l_161a;
	case 5660ULL: goto x86_l_161c;
	case 5663ULL: goto x86_l_161f;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5683ULL: goto x86_l_1633;
	case 5687ULL: goto x86_l_1637;
	case 5695ULL: goto x86_l_163f;
	case 5697ULL: goto x86_l_1641;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5712ULL: goto x86_l_1650;
	case 5715ULL: goto x86_l_1653;
	case 5718ULL: goto x86_l_1656;
	case 5722ULL: goto x86_l_165a;
	case 5727ULL: goto x86_l_165f;
	case 5729ULL: goto x86_l_1661;
	case 5734ULL: goto x86_l_1666;
	case 5738ULL: goto x86_l_166a;
	case 5741ULL: goto x86_l_166d;
	case 5746ULL: goto x86_l_1672;
	case 5748ULL: goto x86_l_1674;
	case 5750ULL: goto x86_l_1676;
	case 5756ULL: goto x86_l_167c;
	case 5761ULL: goto x86_l_1681;
	case 5767ULL: goto x86_l_1687;
	case 5770ULL: goto x86_l_168a;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5781ULL: goto x86_l_1695;
	case 5786ULL: goto x86_l_169a;
	case 5790ULL: goto x86_l_169e;
	case 5793ULL: goto x86_l_16a1;
	case 5798ULL: goto x86_l_16a6;
	case 5800ULL: goto x86_l_16a8;
	case 5802ULL: goto x86_l_16aa;
	case 5808ULL: goto x86_l_16b0;
	case 5816ULL: goto x86_l_16b8;
	case 5822ULL: goto x86_l_16be;
	case 5828ULL: goto x86_l_16c4;
	case 5832ULL: goto x86_l_16c8;
	case 5840ULL: goto x86_l_16d0;
	case 5842ULL: goto x86_l_16d2;
	case 5847ULL: goto x86_l_16d7;
	case 5851ULL: goto x86_l_16db;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5861ULL: goto x86_l_16e5;
	case 5863ULL: goto x86_l_16e7;
	case 5869ULL: goto x86_l_16ed;
	case 5877ULL: goto x86_l_16f5;
	case 5883ULL: goto x86_l_16fb;
	case 5889ULL: goto x86_l_1701;
	case 5893ULL: goto x86_l_1705;
	case 5901ULL: goto x86_l_170d;
	case 5903ULL: goto x86_l_170f;
	case 5908ULL: goto x86_l_1714;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5922ULL: goto x86_l_1722;
	case 5924ULL: goto x86_l_1724;
	case 5930ULL: goto x86_l_172a;
	case 5938ULL: goto x86_l_1732;
	case 5944ULL: goto x86_l_1738;
	case 5950ULL: goto x86_l_173e;
	case 5954ULL: goto x86_l_1742;
	case 5962ULL: goto x86_l_174a;
	case 5964ULL: goto x86_l_174c;
	case 5969ULL: goto x86_l_1751;
	case 5973ULL: goto x86_l_1755;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5983ULL: goto x86_l_175f;
	case 5985ULL: goto x86_l_1761;
	case 5991ULL: goto x86_l_1767;
	case 5999ULL: goto x86_l_176f;
	case 6005ULL: goto x86_l_1775;
	case 6011ULL: goto x86_l_177b;
	case 6015ULL: goto x86_l_177f;
	case 6023ULL: goto x86_l_1787;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6034ULL: goto x86_l_1792;
	case 6037ULL: goto x86_l_1795;
	case 6042ULL: goto x86_l_179a;
	case 6044ULL: goto x86_l_179c;
	case 6046ULL: goto x86_l_179e;
	case 6052ULL: goto x86_l_17a4;
	case 6060ULL: goto x86_l_17ac;
	case 6066ULL: goto x86_l_17b2;
	case 6072ULL: goto x86_l_17b8;
	case 6076ULL: goto x86_l_17bc;
	case 6084ULL: goto x86_l_17c4;
	case 6086ULL: goto x86_l_17c6;
	case 6091ULL: goto x86_l_17cb;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6103ULL: goto x86_l_17d7;
	case 6105ULL: goto x86_l_17d9;
	case 6107ULL: goto x86_l_17db;
	case 6113ULL: goto x86_l_17e1;
	case 6121ULL: goto x86_l_17e9;
	case 6127ULL: goto x86_l_17ef;
	case 6133ULL: goto x86_l_17f5;
	case 6137ULL: goto x86_l_17f9;
	case 6145ULL: goto x86_l_1801;
	case 6147ULL: goto x86_l_1803;
	case 6152ULL: goto x86_l_1808;
	case 6156ULL: goto x86_l_180c;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6166ULL: goto x86_l_1816;
	case 6168ULL: goto x86_l_1818;
	case 6174ULL: goto x86_l_181e;
	case 6182ULL: goto x86_l_1826;
	case 6188ULL: goto x86_l_182c;
	case 6194ULL: goto x86_l_1832;
	case 6198ULL: goto x86_l_1836;
	case 6206ULL: goto x86_l_183e;
	case 6208ULL: goto x86_l_1840;
	case 6213ULL: goto x86_l_1845;
	case 6217ULL: goto x86_l_1849;
	case 6220ULL: goto x86_l_184c;
	case 6225ULL: goto x86_l_1851;
	case 6227ULL: goto x86_l_1853;
	case 6229ULL: goto x86_l_1855;
	case 6235ULL: goto x86_l_185b;
	case 6243ULL: goto x86_l_1863;
	case 6249ULL: goto x86_l_1869;
	case 6255ULL: goto x86_l_186f;
	case 6259ULL: goto x86_l_1873;
	case 6267ULL: goto x86_l_187b;
	case 6273ULL: goto x86_l_1881;
	case 6278ULL: goto x86_l_1886;
	case 6282ULL: goto x86_l_188a;
	case 6285ULL: goto x86_l_188d;
	case 6290ULL: goto x86_l_1892;
	case 6292ULL: goto x86_l_1894;
	case 6294ULL: goto x86_l_1896;
	case 6300ULL: goto x86_l_189c;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6321ULL: goto x86_l_18b1;
	case 6326ULL: goto x86_l_18b6;
	case 6331ULL: goto x86_l_18bb;
	case 6334ULL: goto x86_l_18be;
	case 6340ULL: goto x86_l_18c4;
	case 6343ULL: goto x86_l_18c7;
	case 6346ULL: goto x86_l_18ca;
	case 6352ULL: goto x86_l_18d0;
	case 6357ULL: goto x86_l_18d5;
	case 6362ULL: goto x86_l_18da;
	case 6365ULL: goto x86_l_18dd;
	case 6371ULL: goto x86_l_18e3;
	case 6374ULL: goto x86_l_18e6;
	case 6377ULL: goto x86_l_18e9;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6396ULL: goto x86_l_18fc;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6408ULL: goto x86_l_1908;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6427ULL: goto x86_l_191b;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6437ULL: goto x86_l_1925;
	case 6440ULL: goto x86_l_1928;
	case 6442ULL: goto x86_l_192a;
	case 6444ULL: goto x86_l_192c;
	case 6449ULL: goto x86_l_1931;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6460ULL: goto x86_l_193c;
	case 6464ULL: goto x86_l_1940;
	case 6466ULL: goto x86_l_1942;
	case 6469ULL: goto x86_l_1945;
	case 6477ULL: goto x86_l_194d;
	case 6483ULL: goto x86_l_1953;
	case 6489ULL: goto x86_l_1959;
	case 6492ULL: goto x86_l_195c;
	case 6496ULL: goto x86_l_1960;
	case 6504ULL: goto x86_l_1968;
	case 6506ULL: goto x86_l_196a;
	case 6511ULL: goto x86_l_196f;
	case 6515ULL: goto x86_l_1973;
	case 6518ULL: goto x86_l_1976;
	case 6523ULL: goto x86_l_197b;
	case 6525ULL: goto x86_l_197d;
	case 6527ULL: goto x86_l_197f;
	case 6533ULL: goto x86_l_1985;
	case 6541ULL: goto x86_l_198d;
	case 6547ULL: goto x86_l_1993;
	case 6553ULL: goto x86_l_1999;
	case 6557ULL: goto x86_l_199d;
	case 6565ULL: goto x86_l_19a5;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6576ULL: goto x86_l_19b0;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6586ULL: goto x86_l_19ba;
	case 6588ULL: goto x86_l_19bc;
	case 6594ULL: goto x86_l_19c2;
	case 6602ULL: goto x86_l_19ca;
	case 6608ULL: goto x86_l_19d0;
	case 6614ULL: goto x86_l_19d6;
	case 6618ULL: goto x86_l_19da;
	case 6626ULL: goto x86_l_19e2;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6637ULL: goto x86_l_19ed;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6647ULL: goto x86_l_19f7;
	case 6649ULL: goto x86_l_19f9;
	case 6655ULL: goto x86_l_19ff;
	case 6663ULL: goto x86_l_1a07;
	case 6669ULL: goto x86_l_1a0d;
	case 6675ULL: goto x86_l_1a13;
	case 6679ULL: goto x86_l_1a17;
	case 6687ULL: goto x86_l_1a1f;
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6698ULL: goto x86_l_1a2a;
	case 6701ULL: goto x86_l_1a2d;
	case 6706ULL: goto x86_l_1a32;
	case 6708ULL: goto x86_l_1a34;
	case 6710ULL: goto x86_l_1a36;
	case 6716ULL: goto x86_l_1a3c;
	case 6724ULL: goto x86_l_1a44;
	case 6730ULL: goto x86_l_1a4a;
	case 6736ULL: goto x86_l_1a50;
	case 6740ULL: goto x86_l_1a54;
	case 6748ULL: goto x86_l_1a5c;
	case 6750ULL: goto x86_l_1a5e;
	case 6755ULL: goto x86_l_1a63;
	case 6759ULL: goto x86_l_1a67;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6769ULL: goto x86_l_1a71;
	case 6771ULL: goto x86_l_1a73;
	case 6777ULL: goto x86_l_1a79;
	case 6785ULL: goto x86_l_1a81;
	case 6791ULL: goto x86_l_1a87;
	case 6797ULL: goto x86_l_1a8d;
	case 6801ULL: goto x86_l_1a91;
	case 6809ULL: goto x86_l_1a99;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6820ULL: goto x86_l_1aa4;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6830ULL: goto x86_l_1aae;
	case 6832ULL: goto x86_l_1ab0;
	case 6838ULL: goto x86_l_1ab6;
	case 6846ULL: goto x86_l_1abe;
	case 6852ULL: goto x86_l_1ac4;
	case 6858ULL: goto x86_l_1aca;
	case 6862ULL: goto x86_l_1ace;
	case 6870ULL: goto x86_l_1ad6;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6899ULL: goto x86_l_1af3;
	case 6907ULL: goto x86_l_1afb;
	case 6913ULL: goto x86_l_1b01;
	case 6919ULL: goto x86_l_1b07;
	case 6923ULL: goto x86_l_1b0b;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6942ULL: goto x86_l_1b1e;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6952ULL: goto x86_l_1b28;
	case 6954ULL: goto x86_l_1b2a;
	case 6960ULL: goto x86_l_1b30;
	case 6968ULL: goto x86_l_1b38;
	case 6974ULL: goto x86_l_1b3e;
	case 6980ULL: goto x86_l_1b44;
	case 6984ULL: goto x86_l_1b48;
	case 6992ULL: goto x86_l_1b50;
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7011ULL: goto x86_l_1b63;
	case 7013ULL: goto x86_l_1b65;
	case 7015ULL: goto x86_l_1b67;
	case 7021ULL: goto x86_l_1b6d;
	case 7029ULL: goto x86_l_1b75;
	case 7035ULL: goto x86_l_1b7b;
	case 7041ULL: goto x86_l_1b81;
	case 7045ULL: goto x86_l_1b85;
	case 7053ULL: goto x86_l_1b8d;
	case 7059ULL: goto x86_l_1b93;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14c0:
	/* 0x14c0: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14c5:
	/* 0x14c5: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_14c8:
	/* 0x14c8: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_161c;
	}
x86_l_14ce:
	/* 0x14ce: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14d3:
	/* 0x14d3: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_14d6:
	/* 0x14d6: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_161c;
	}
x86_l_14dc:
	/* 0x14dc: jmp    162f <generic_sleepable_preload+0x162f> */
	goto x86_l_162f;
x86_l_14e1:
	/* 0x14e1: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14e6:
	/* 0x14e6: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_14e9:
	/* 0x14e9: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_14ef:
	/* 0x14ef: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14f4:
	/* 0x14f4: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_14f7:
	/* 0x14f7: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_14fd:
	/* 0x14fd: jmp    1c2d <generic_sleepable_preload+0x1c2d> */
	return 7213ULL;
x86_l_1502:
	/* 0x1502: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1507:
	/* 0x1507: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_150a:
	/* 0x150a: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_1510:
	/* 0x1510: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1515:
	/* 0x1515: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1518:
	/* 0x1518: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_151e:
	/* 0x151e: jmp    1ee9 <generic_sleepable_preload+0x1ee9> */
	return 7913ULL;
x86_l_1523:
	/* 0x1523: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1528:
	/* 0x1528: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_152b:
	/* 0x152b: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_1531:
	/* 0x1531: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1536:
	/* 0x1536: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1539:
	/* 0x1539: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_153f:
	/* 0x153f: jmp    21a5 <generic_sleepable_preload+0x21a5> */
	return 8613ULL;
x86_l_1544:
	/* 0x1544: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1549:
	/* 0x1549: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_154c:
	/* 0x154c: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1925;
	}
x86_l_1552:
	/* 0x1552: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1557:
	/* 0x1557: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_155a:
	/* 0x155a: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1925;
	}
x86_l_1560:
	/* 0x1560: jmp    1938 <generic_sleepable_preload+0x1938> */
	goto x86_l_1938;
x86_l_1565:
	/* 0x1565: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_156a:
	/* 0x156a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_156d:
	/* 0x156d: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_161c;
	}
x86_l_1573:
	/* 0x1573: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1578:
	/* 0x1578: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_157b:
	/* 0x157b: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_161c;
	}
x86_l_1581:
	/* 0x1581: jmp    162f <generic_sleepable_preload+0x162f> */
	goto x86_l_162f;
x86_l_1586:
	/* 0x1586: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_158b:
	/* 0x158b: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_158e:
	/* 0x158e: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_1594:
	/* 0x1594: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1599:
	/* 0x1599: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_159c:
	/* 0x159c: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_15a2:
	/* 0x15a2: jmp    1c2d <generic_sleepable_preload+0x1c2d> */
	return 7213ULL;
x86_l_15a7:
	/* 0x15a7: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15ac:
	/* 0x15ac: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_15af:
	/* 0x15af: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_15b5:
	/* 0x15b5: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15ba:
	/* 0x15ba: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_15bd:
	/* 0x15bd: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_15c3:
	/* 0x15c3: jmp    1ee9 <generic_sleepable_preload+0x1ee9> */
	return 7913ULL;
x86_l_15c8:
	/* 0x15c8: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15cd:
	/* 0x15cd: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_15d0:
	/* 0x15d0: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_15d6:
	/* 0x15d6: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15db:
	/* 0x15db: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_15de:
	/* 0x15de: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_15e4:
	/* 0x15e4: jmp    21a5 <generic_sleepable_preload+0x21a5> */
	return 8613ULL;
x86_l_15e9:
	/* 0x15e9: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15ee:
	/* 0x15ee: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_15f1:
	/* 0x15f1: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1925;
	}
x86_l_15f7:
	/* 0x15f7: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15fc:
	/* 0x15fc: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_15ff:
	/* 0x15ff: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1925;
	}
x86_l_1605:
	/* 0x1605: jmp    1938 <generic_sleepable_preload+0x1938> */
	goto x86_l_1938;
x86_l_160a:
	/* 0x160a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_160f:
	/* 0x160f: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1612:
	/* 0x1612: je     161c <generic_sleepable_preload+0x161c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_161c;
	}
x86_l_1614:
	/* 0x1614: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1617:
	/* 0x1617: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_161a:
	/* 0x161a: jne    162f <generic_sleepable_preload+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_162f;
	}
x86_l_161c:
	/* 0x161c: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_161f:
	/* 0x161f: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_1621:
	/* 0x1621: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1623:
	/* 0x1623: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_1628:
	/* 0x1628: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_162a:
	/* 0x162a: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_162f:
	/* 0x162f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1633:
	/* 0x1633: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1637:
	/* 0x1637: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_163f:
	/* 0x163f: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1641:
	/* 0x1641: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1645:
	/* 0x1645: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_164a:
	/* 0x164a: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_1650:
	/* 0x1650: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1653:
	/* 0x1653: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1656:
	/* 0x1656: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165a:
	/* 0x165a: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_165f:
	/* 0x165f: je     167c <generic_sleepable_preload+0x167c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_167c;
	}
x86_l_1661:
	/* 0x1661: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1666:
	/* 0x1666: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166a:
	/* 0x166a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_166d:
	/* 0x166d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1672:
	/* 0x1672: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1674:
	/* 0x1674: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1676:
	/* 0x1676: js     18a9 <generic_sleepable_preload+0x18a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18a9;
	}
x86_l_167c:
	/* 0x167c: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1681:
	/* 0x1681: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_1687:
	/* 0x1687: mov    eax,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_168a:
	/* 0x168a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_168e:
	/* 0x168e: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1693:
	/* 0x1693: je     16b0 <generic_sleepable_preload+0x16b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b0;
	}
x86_l_1695:
	/* 0x1695: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_169a:
	/* 0x169a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_169e:
	/* 0x169e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16a1:
	/* 0x16a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a6:
	/* 0x16a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a8:
	/* 0x16a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16aa:
	/* 0x16aa: js     1c00 <generic_sleepable_preload+0x1c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7168ULL;
	}
x86_l_16b0:
	/* 0x16b0: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_16b8:
	/* 0x16b8: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_16be:
	/* 0x16be: mov    eax,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16c4:
	/* 0x16c4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_16c8:
	/* 0x16c8: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_16d0:
	/* 0x16d0: je     16ed <generic_sleepable_preload+0x16ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16ed;
	}
x86_l_16d2:
	/* 0x16d2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16d7:
	/* 0x16d7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16db:
	/* 0x16db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16de:
	/* 0x16de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16e3:
	/* 0x16e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e5:
	/* 0x16e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16e7:
	/* 0x16e7: js     2489 <generic_sleepable_preload+0x2489> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9353ULL;
	}
x86_l_16ed:
	/* 0x16ed: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_16f5:
	/* 0x16f5: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_16fb:
	/* 0x16fb: mov    eax,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1701:
	/* 0x1701: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1705:
	/* 0x1705: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_170d:
	/* 0x170d: je     172a <generic_sleepable_preload+0x172a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172a;
	}
x86_l_170f:
	/* 0x170f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1714:
	/* 0x1714: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1718:
	/* 0x1718: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_171b:
	/* 0x171b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1720:
	/* 0x1720: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1722:
	/* 0x1722: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1724:
	/* 0x1724: js     2505 <generic_sleepable_preload+0x2505> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9477ULL;
	}
x86_l_172a:
	/* 0x172a: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1732:
	/* 0x1732: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_1738:
	/* 0x1738: mov    eax,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_173e:
	/* 0x173e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1742:
	/* 0x1742: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_174a:
	/* 0x174a: je     1767 <generic_sleepable_preload+0x1767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1767;
	}
x86_l_174c:
	/* 0x174c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1751:
	/* 0x1751: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1755:
	/* 0x1755: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1758:
	/* 0x1758: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_175d:
	/* 0x175d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175f:
	/* 0x175f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1761:
	/* 0x1761: js     2581 <generic_sleepable_preload+0x2581> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9601ULL;
	}
x86_l_1767:
	/* 0x1767: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_176f:
	/* 0x176f: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_1775:
	/* 0x1775: mov    eax,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_177b:
	/* 0x177b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_177f:
	/* 0x177f: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1787:
	/* 0x1787: je     17a4 <generic_sleepable_preload+0x17a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17a4;
	}
x86_l_1789:
	/* 0x1789: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_178e:
	/* 0x178e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1792:
	/* 0x1792: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1795:
	/* 0x1795: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_179a:
	/* 0x179a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179c:
	/* 0x179c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_179e:
	/* 0x179e: js     25fa <generic_sleepable_preload+0x25fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9722ULL;
	}
x86_l_17a4:
	/* 0x17a4: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_17ac:
	/* 0x17ac: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_17b2:
	/* 0x17b2: mov    eax,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_17b8:
	/* 0x17b8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17bc:
	/* 0x17bc: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_17c4:
	/* 0x17c4: je     17e1 <generic_sleepable_preload+0x17e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17e1;
	}
x86_l_17c6:
	/* 0x17c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17cb:
	/* 0x17cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17cf:
	/* 0x17cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x17db: js     2a06 <generic_sleepable_preload+0x2a06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10758ULL;
	}
x86_l_17e1:
	/* 0x17e1: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_17e9:
	/* 0x17e9: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_17ef:
	/* 0x17ef: mov    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17f5:
	/* 0x17f5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17f9:
	/* 0x17f9: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1801:
	/* 0x1801: je     181e <generic_sleepable_preload+0x181e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_181e;
	}
x86_l_1803:
	/* 0x1803: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1808:
	/* 0x1808: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_180c:
	/* 0x180c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_180f:
	/* 0x180f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1814:
	/* 0x1814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1816:
	/* 0x1816: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1818:
	/* 0x1818: js     2dbe <generic_sleepable_preload+0x2dbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11710ULL;
	}
x86_l_181e:
	/* 0x181e: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1826:
	/* 0x1826: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_182c:
	/* 0x182c: mov    eax,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1832:
	/* 0x1832: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1836:
	/* 0x1836: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_183e:
	/* 0x183e: je     185b <generic_sleepable_preload+0x185b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_185b;
	}
x86_l_1840:
	/* 0x1840: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1845:
	/* 0x1845: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1849:
	/* 0x1849: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_184c:
	/* 0x184c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1851:
	/* 0x1851: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1853:
	/* 0x1853: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1855:
	/* 0x1855: js     2e8f <generic_sleepable_preload+0x2e8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11919ULL;
	}
x86_l_185b:
	/* 0x185b: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1863:
	/* 0x1863: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_1869:
	/* 0x1869: mov    eax,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_186f:
	/* 0x186f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1873:
	/* 0x1873: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_187b:
	/* 0x187b: je     2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10774ULL;
	}
x86_l_1881:
	/* 0x1881: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1886:
	/* 0x1886: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_188a:
	/* 0x188a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_188d:
	/* 0x188d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1892:
	/* 0x1892: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1894:
	/* 0x1894: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1896:
	/* 0x1896: jns    2a16 <generic_sleepable_preload+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10774ULL;
	}
x86_l_189c:
	/* 0x189c: mov    DWORD PTR [rsp+0x10],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476746ULL);
x86_l_18a4:
	/* 0x18a4: jmp    2a0e <generic_sleepable_preload+0x2a0e> */
	return 10766ULL;
x86_l_18a9:
	/* 0x18a9: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_18b1:
	/* 0x18b1: jmp    2a0e <generic_sleepable_preload+0x2a0e> */
	return 10766ULL;
x86_l_18b6:
	/* 0x18b6: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18bb:
	/* 0x18bb: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_18be:
	/* 0x18be: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_18c4:
	/* 0x18c4: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_18c7:
	/* 0x18c7: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_18ca:
	/* 0x18ca: je     1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7194ULL;
	}
x86_l_18d0:
	/* 0x18d0: jmp    1c2d <generic_sleepable_preload+0x1c2d> */
	return 7213ULL;
x86_l_18d5:
	/* 0x18d5: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18da:
	/* 0x18da: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_18dd:
	/* 0x18dd: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_18e3:
	/* 0x18e3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_18e6:
	/* 0x18e6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_18e9:
	/* 0x18e9: je     1ed6 <generic_sleepable_preload+0x1ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7894ULL;
	}
x86_l_18ef:
	/* 0x18ef: jmp    1ee9 <generic_sleepable_preload+0x1ee9> */
	return 7913ULL;
x86_l_18f4:
	/* 0x18f4: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18f9:
	/* 0x18f9: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_18fc:
	/* 0x18fc: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_1902:
	/* 0x1902: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1905:
	/* 0x1905: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1908:
	/* 0x1908: je     2192 <generic_sleepable_preload+0x2192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8594ULL;
	}
x86_l_190e:
	/* 0x190e: jmp    21a5 <generic_sleepable_preload+0x21a5> */
	return 8613ULL;
x86_l_1913:
	/* 0x1913: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1918:
	/* 0x1918: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_191b:
	/* 0x191b: je     1925 <generic_sleepable_preload+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1925;
	}
x86_l_191d:
	/* 0x191d: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1920:
	/* 0x1920: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1923:
	/* 0x1923: jne    1938 <generic_sleepable_preload+0x1938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1938;
	}
x86_l_1925:
	/* 0x1925: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1928:
	/* 0x1928: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_192a:
	/* 0x192a: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_192c:
	/* 0x192c: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_1931:
	/* 0x1931: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1933:
	/* 0x1933: bzhi   rax,QWORD PTR [r14],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_1938:
	/* 0x1938: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_193c:
	/* 0x193c: mov    r14d,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1940:
	/* 0x1940: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1942:
	/* 0x1942: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1945:
	/* 0x1945: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_194d:
	/* 0x194d: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1953:
	/* 0x1953: mov    ecx,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_1959:
	/* 0x1959: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_195c:
	/* 0x195c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1960:
	/* 0x1960: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_1968:
	/* 0x1968: je     1985 <generic_sleepable_preload+0x1985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1985;
	}
x86_l_196a:
	/* 0x196a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_196f:
	/* 0x196f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1973:
	/* 0x1973: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1976:
	/* 0x1976: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_197b:
	/* 0x197b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197d:
	/* 0x197d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_197f:
	/* 0x197f: js     1bb8 <generic_sleepable_preload+0x1bb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7096ULL;
	}
x86_l_1985:
	/* 0x1985: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_198d:
	/* 0x198d: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1993:
	/* 0x1993: mov    eax,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_1999:
	/* 0x1999: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_199d:
	/* 0x199d: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_19a5:
	/* 0x19a5: je     19c2 <generic_sleepable_preload+0x19c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19c2;
	}
x86_l_19a7:
	/* 0x19a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19ac:
	/* 0x19ac: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b0:
	/* 0x19b0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19b3:
	/* 0x19b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19b8:
	/* 0x19b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ba:
	/* 0x19ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19bc:
	/* 0x19bc: js     1c0d <generic_sleepable_preload+0x1c0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7181ULL;
	}
x86_l_19c2:
	/* 0x19c2: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_19ca:
	/* 0x19ca: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_19d0:
	/* 0x19d0: mov    eax,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_19d6:
	/* 0x19d6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_19da:
	/* 0x19da: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_19e2:
	/* 0x19e2: je     19ff <generic_sleepable_preload+0x19ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ff;
	}
x86_l_19e4:
	/* 0x19e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19e9:
	/* 0x19e9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ed:
	/* 0x19ed: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19f0:
	/* 0x19f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f5:
	/* 0x19f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f7:
	/* 0x19f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19f9:
	/* 0x19f9: js     2496 <generic_sleepable_preload+0x2496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9366ULL;
	}
x86_l_19ff:
	/* 0x19ff: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_1a07:
	/* 0x1a07: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1a0d:
	/* 0x1a0d: mov    eax,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_1a13:
	/* 0x1a13: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a17:
	/* 0x1a17: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_1a1f:
	/* 0x1a1f: je     1a3c <generic_sleepable_preload+0x1a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a3c;
	}
x86_l_1a21:
	/* 0x1a21: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a26:
	/* 0x1a26: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a2d:
	/* 0x1a2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a32:
	/* 0x1a32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a34:
	/* 0x1a34: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a36:
	/* 0x1a36: js     2512 <generic_sleepable_preload+0x2512> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9490ULL;
	}
x86_l_1a3c:
	/* 0x1a3c: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_1a44:
	/* 0x1a44: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1a4a:
	/* 0x1a4a: mov    eax,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_1a50:
	/* 0x1a50: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a54:
	/* 0x1a54: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_1a5c:
	/* 0x1a5c: je     1a79 <generic_sleepable_preload+0x1a79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a79;
	}
x86_l_1a5e:
	/* 0x1a5e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a63:
	/* 0x1a63: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a67:
	/* 0x1a67: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a6a:
	/* 0x1a6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a6f:
	/* 0x1a6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a71:
	/* 0x1a71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a73:
	/* 0x1a73: js     258e <generic_sleepable_preload+0x258e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9614ULL;
	}
x86_l_1a79:
	/* 0x1a79: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_1a81:
	/* 0x1a81: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1a87:
	/* 0x1a87: mov    eax,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_1a8d:
	/* 0x1a8d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a91:
	/* 0x1a91: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_1a99:
	/* 0x1a99: je     1ab6 <generic_sleepable_preload+0x1ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ab6;
	}
x86_l_1a9b:
	/* 0x1a9b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1aa0:
	/* 0x1aa0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1aa7:
	/* 0x1aa7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aac:
	/* 0x1aac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aae:
	/* 0x1aae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ab0:
	/* 0x1ab0: js     2607 <generic_sleepable_preload+0x2607> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9735ULL;
	}
x86_l_1ab6:
	/* 0x1ab6: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_1abe:
	/* 0x1abe: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1ac4:
	/* 0x1ac4: mov    eax,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_1aca:
	/* 0x1aca: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ace:
	/* 0x1ace: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_1ad6:
	/* 0x1ad6: je     1af3 <generic_sleepable_preload+0x1af3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af3;
	}
x86_l_1ad8:
	/* 0x1ad8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1add:
	/* 0x1add: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ae4:
	/* 0x1ae4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae9:
	/* 0x1ae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aeb:
	/* 0x1aeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aed:
	/* 0x1aed: js     2acd <generic_sleepable_preload+0x2acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10957ULL;
	}
x86_l_1af3:
	/* 0x1af3: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_1afb:
	/* 0x1afb: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1b01:
	/* 0x1b01: mov    eax,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_1b07:
	/* 0x1b07: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b0b:
	/* 0x1b0b: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_1b13:
	/* 0x1b13: je     1b30 <generic_sleepable_preload+0x1b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b30;
	}
x86_l_1b15:
	/* 0x1b15: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b1a:
	/* 0x1b1a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b21:
	/* 0x1b21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b26:
	/* 0x1b26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b28:
	/* 0x1b28: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b2a:
	/* 0x1b2a: js     2ddd <generic_sleepable_preload+0x2ddd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11741ULL;
	}
x86_l_1b30:
	/* 0x1b30: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_1b38:
	/* 0x1b38: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1b3e:
	/* 0x1b3e: mov    eax,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1b44:
	/* 0x1b44: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b48:
	/* 0x1b48: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_1b50:
	/* 0x1b50: je     1b6d <generic_sleepable_preload+0x1b6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b6d;
	}
x86_l_1b52:
	/* 0x1b52: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b57:
	/* 0x1b57: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b5e:
	/* 0x1b5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b63:
	/* 0x1b63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b65:
	/* 0x1b65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b67:
	/* 0x1b67: js     2e9c <generic_sleepable_preload+0x2e9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11932ULL;
	}
x86_l_1b6d:
	/* 0x1b6d: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_1b75:
	/* 0x1b75: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1b7b:
	/* 0x1b7b: mov    eax,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_1b81:
	/* 0x1b81: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1b85:
	/* 0x1b85: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_1b8d:
	/* 0x1b8d: je     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_1b93:
	/* 0x1b93: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
	return 7064ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7064ULL: goto x86_l_1b98;
	case 7068ULL: goto x86_l_1b9c;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7078ULL: goto x86_l_1ba6;
	case 7080ULL: goto x86_l_1ba8;
	case 7086ULL: goto x86_l_1bae;
	case 7091ULL: goto x86_l_1bb3;
	case 7096ULL: goto x86_l_1bb8;
	case 7101ULL: goto x86_l_1bbd;
	case 7106ULL: goto x86_l_1bc2;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7194ULL: goto x86_l_1c1a;
	case 7197ULL: goto x86_l_1c1d;
	case 7199ULL: goto x86_l_1c1f;
	case 7201ULL: goto x86_l_1c21;
	case 7206ULL: goto x86_l_1c26;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7217ULL: goto x86_l_1c31;
	case 7221ULL: goto x86_l_1c35;
	case 7229ULL: goto x86_l_1c3d;
	case 7231ULL: goto x86_l_1c3f;
	case 7235ULL: goto x86_l_1c43;
	case 7243ULL: goto x86_l_1c4b;
	case 7249ULL: goto x86_l_1c51;
	case 7255ULL: goto x86_l_1c57;
	case 7258ULL: goto x86_l_1c5a;
	case 7262ULL: goto x86_l_1c5e;
	case 7270ULL: goto x86_l_1c66;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7281ULL: goto x86_l_1c71;
	case 7284ULL: goto x86_l_1c74;
	case 7289ULL: goto x86_l_1c79;
	case 7291ULL: goto x86_l_1c7b;
	case 7293ULL: goto x86_l_1c7d;
	case 7299ULL: goto x86_l_1c83;
	case 7307ULL: goto x86_l_1c8b;
	case 7313ULL: goto x86_l_1c91;
	case 7319ULL: goto x86_l_1c97;
	case 7323ULL: goto x86_l_1c9b;
	case 7331ULL: goto x86_l_1ca3;
	case 7333ULL: goto x86_l_1ca5;
	case 7338ULL: goto x86_l_1caa;
	case 7342ULL: goto x86_l_1cae;
	case 7345ULL: goto x86_l_1cb1;
	case 7350ULL: goto x86_l_1cb6;
	case 7352ULL: goto x86_l_1cb8;
	case 7354ULL: goto x86_l_1cba;
	case 7360ULL: goto x86_l_1cc0;
	case 7368ULL: goto x86_l_1cc8;
	case 7374ULL: goto x86_l_1cce;
	case 7380ULL: goto x86_l_1cd4;
	case 7384ULL: goto x86_l_1cd8;
	case 7392ULL: goto x86_l_1ce0;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7403ULL: goto x86_l_1ceb;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7413ULL: goto x86_l_1cf5;
	case 7415ULL: goto x86_l_1cf7;
	case 7421ULL: goto x86_l_1cfd;
	case 7429ULL: goto x86_l_1d05;
	case 7435ULL: goto x86_l_1d0b;
	case 7441ULL: goto x86_l_1d11;
	case 7445ULL: goto x86_l_1d15;
	case 7453ULL: goto x86_l_1d1d;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7464ULL: goto x86_l_1d28;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7474ULL: goto x86_l_1d32;
	case 7476ULL: goto x86_l_1d34;
	case 7482ULL: goto x86_l_1d3a;
	case 7490ULL: goto x86_l_1d42;
	case 7496ULL: goto x86_l_1d48;
	case 7502ULL: goto x86_l_1d4e;
	case 7506ULL: goto x86_l_1d52;
	case 7514ULL: goto x86_l_1d5a;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7525ULL: goto x86_l_1d65;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7543ULL: goto x86_l_1d77;
	case 7551ULL: goto x86_l_1d7f;
	case 7557ULL: goto x86_l_1d85;
	case 7563ULL: goto x86_l_1d8b;
	case 7567ULL: goto x86_l_1d8f;
	case 7575ULL: goto x86_l_1d97;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7586ULL: goto x86_l_1da2;
	case 7589ULL: goto x86_l_1da5;
	case 7594ULL: goto x86_l_1daa;
	case 7596ULL: goto x86_l_1dac;
	case 7598ULL: goto x86_l_1dae;
	case 7604ULL: goto x86_l_1db4;
	case 7612ULL: goto x86_l_1dbc;
	case 7618ULL: goto x86_l_1dc2;
	case 7624ULL: goto x86_l_1dc8;
	case 7628ULL: goto x86_l_1dcc;
	case 7636ULL: goto x86_l_1dd4;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7647ULL: goto x86_l_1ddf;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7657ULL: goto x86_l_1de9;
	case 7659ULL: goto x86_l_1deb;
	case 7665ULL: goto x86_l_1df1;
	case 7673ULL: goto x86_l_1df9;
	case 7679ULL: goto x86_l_1dff;
	case 7685ULL: goto x86_l_1e05;
	case 7689ULL: goto x86_l_1e09;
	case 7697ULL: goto x86_l_1e11;
	case 7699ULL: goto x86_l_1e13;
	case 7704ULL: goto x86_l_1e18;
	case 7708ULL: goto x86_l_1e1c;
	case 7711ULL: goto x86_l_1e1f;
	case 7716ULL: goto x86_l_1e24;
	case 7718ULL: goto x86_l_1e26;
	case 7720ULL: goto x86_l_1e28;
	case 7726ULL: goto x86_l_1e2e;
	case 7734ULL: goto x86_l_1e36;
	case 7740ULL: goto x86_l_1e3c;
	case 7746ULL: goto x86_l_1e42;
	case 7750ULL: goto x86_l_1e46;
	case 7758ULL: goto x86_l_1e4e;
	case 7760ULL: goto x86_l_1e50;
	case 7765ULL: goto x86_l_1e55;
	case 7769ULL: goto x86_l_1e59;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7779ULL: goto x86_l_1e63;
	case 7781ULL: goto x86_l_1e65;
	case 7787ULL: goto x86_l_1e6b;
	case 7795ULL: goto x86_l_1e73;
	case 7801ULL: goto x86_l_1e79;
	case 7807ULL: goto x86_l_1e7f;
	case 7811ULL: goto x86_l_1e83;
	case 7819ULL: goto x86_l_1e8b;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7834ULL: goto x86_l_1e9a;
	case 7837ULL: goto x86_l_1e9d;
	case 7842ULL: goto x86_l_1ea2;
	case 7844ULL: goto x86_l_1ea4;
	case 7846ULL: goto x86_l_1ea6;
	case 7852ULL: goto x86_l_1eac;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7873ULL: goto x86_l_1ec1;
	case 7878ULL: goto x86_l_1ec6;
	case 7886ULL: goto x86_l_1ece;
	case 7891ULL: goto x86_l_1ed3;
	case 7894ULL: goto x86_l_1ed6;
	case 7897ULL: goto x86_l_1ed9;
	case 7899ULL: goto x86_l_1edb;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7917ULL: goto x86_l_1eed;
	case 7921ULL: goto x86_l_1ef1;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7935ULL: goto x86_l_1eff;
	case 7943ULL: goto x86_l_1f07;
	case 7949ULL: goto x86_l_1f0d;
	case 7955ULL: goto x86_l_1f13;
	case 7958ULL: goto x86_l_1f16;
	case 7962ULL: goto x86_l_1f1a;
	case 7970ULL: goto x86_l_1f22;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7981ULL: goto x86_l_1f2d;
	case 7984ULL: goto x86_l_1f30;
	case 7989ULL: goto x86_l_1f35;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 7999ULL: goto x86_l_1f3f;
	case 8007ULL: goto x86_l_1f47;
	case 8013ULL: goto x86_l_1f4d;
	case 8019ULL: goto x86_l_1f53;
	case 8023ULL: goto x86_l_1f57;
	case 8031ULL: goto x86_l_1f5f;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8042ULL: goto x86_l_1f6a;
	case 8045ULL: goto x86_l_1f6d;
	case 8050ULL: goto x86_l_1f72;
	case 8052ULL: goto x86_l_1f74;
	case 8054ULL: goto x86_l_1f76;
	case 8060ULL: goto x86_l_1f7c;
	case 8068ULL: goto x86_l_1f84;
	case 8074ULL: goto x86_l_1f8a;
	case 8080ULL: goto x86_l_1f90;
	case 8084ULL: goto x86_l_1f94;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8099ULL: goto x86_l_1fa3;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8111ULL: goto x86_l_1faf;
	case 8113ULL: goto x86_l_1fb1;
	case 8115ULL: goto x86_l_1fb3;
	case 8121ULL: goto x86_l_1fb9;
	case 8129ULL: goto x86_l_1fc1;
	case 8135ULL: goto x86_l_1fc7;
	case 8141ULL: goto x86_l_1fcd;
	case 8145ULL: goto x86_l_1fd1;
	case 8153ULL: goto x86_l_1fd9;
	case 8155ULL: goto x86_l_1fdb;
	case 8160ULL: goto x86_l_1fe0;
	case 8164ULL: goto x86_l_1fe4;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8174ULL: goto x86_l_1fee;
	case 8176ULL: goto x86_l_1ff0;
	case 8182ULL: goto x86_l_1ff6;
	case 8190ULL: goto x86_l_1ffe;
	case 8196ULL: goto x86_l_2004;
	case 8202ULL: goto x86_l_200a;
	case 8206ULL: goto x86_l_200e;
	case 8214ULL: goto x86_l_2016;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8225ULL: goto x86_l_2021;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8235ULL: goto x86_l_202b;
	case 8237ULL: goto x86_l_202d;
	case 8243ULL: goto x86_l_2033;
	case 8251ULL: goto x86_l_203b;
	case 8257ULL: goto x86_l_2041;
	case 8263ULL: goto x86_l_2047;
	case 8267ULL: goto x86_l_204b;
	case 8275ULL: goto x86_l_2053;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8286ULL: goto x86_l_205e;
	case 8289ULL: goto x86_l_2061;
	case 8294ULL: goto x86_l_2066;
	case 8296ULL: goto x86_l_2068;
	case 8298ULL: goto x86_l_206a;
	case 8304ULL: goto x86_l_2070;
	case 8312ULL: goto x86_l_2078;
	case 8318ULL: goto x86_l_207e;
	case 8324ULL: goto x86_l_2084;
	case 8328ULL: goto x86_l_2088;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8347ULL: goto x86_l_209b;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8357ULL: goto x86_l_20a5;
	case 8359ULL: goto x86_l_20a7;
	case 8365ULL: goto x86_l_20ad;
	case 8373ULL: goto x86_l_20b5;
	case 8379ULL: goto x86_l_20bb;
	case 8385ULL: goto x86_l_20c1;
	case 8389ULL: goto x86_l_20c5;
	case 8397ULL: goto x86_l_20cd;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8420ULL: goto x86_l_20e4;
	case 8426ULL: goto x86_l_20ea;
	case 8434ULL: goto x86_l_20f2;
	case 8440ULL: goto x86_l_20f8;
	case 8446ULL: goto x86_l_20fe;
	case 8450ULL: goto x86_l_2102;
	case 8458ULL: goto x86_l_210a;
	case 8460ULL: goto x86_l_210c;
	case 8465ULL: goto x86_l_2111;
	case 8469ULL: goto x86_l_2115;
	case 8472ULL: goto x86_l_2118;
	case 8477ULL: goto x86_l_211d;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8487ULL: goto x86_l_2127;
	case 8495ULL: goto x86_l_212f;
	case 8501ULL: goto x86_l_2135;
	case 8507ULL: goto x86_l_213b;
	case 8511ULL: goto x86_l_213f;
	case 8519ULL: goto x86_l_2147;
	case 8525ULL: goto x86_l_214d;
	case 8530ULL: goto x86_l_2152;
	case 8534ULL: goto x86_l_2156;
	case 8537ULL: goto x86_l_2159;
	case 8542ULL: goto x86_l_215e;
	case 8544ULL: goto x86_l_2160;
	case 8546ULL: goto x86_l_2162;
	case 8552ULL: goto x86_l_2168;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8594ULL: goto x86_l_2192;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8606ULL: goto x86_l_219e;
	case 8608ULL: goto x86_l_21a0;
	case 8613ULL: goto x86_l_21a5;
	case 8617ULL: goto x86_l_21a9;
	case 8621ULL: goto x86_l_21ad;
	case 8629ULL: goto x86_l_21b5;
	case 8631ULL: goto x86_l_21b7;
	case 8635ULL: goto x86_l_21bb;
	case 8643ULL: goto x86_l_21c3;
	case 8649ULL: goto x86_l_21c9;
	case 8655ULL: goto x86_l_21cf;
	case 8658ULL: goto x86_l_21d2;
	case 8662ULL: goto x86_l_21d6;
	case 8670ULL: goto x86_l_21de;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8681ULL: goto x86_l_21e9;
	case 8684ULL: goto x86_l_21ec;
	case 8689ULL: goto x86_l_21f1;
	case 8691ULL: goto x86_l_21f3;
	case 8693ULL: goto x86_l_21f5;
	case 8699ULL: goto x86_l_21fb;
	case 8707ULL: goto x86_l_2203;
	case 8713ULL: goto x86_l_2209;
	case 8719ULL: goto x86_l_220f;
	case 8723ULL: goto x86_l_2213;
	case 8731ULL: goto x86_l_221b;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8752ULL: goto x86_l_2230;
	case 8754ULL: goto x86_l_2232;
	case 8760ULL: goto x86_l_2238;
	case 8768ULL: goto x86_l_2240;
	case 8774ULL: goto x86_l_2246;
	case 8780ULL: goto x86_l_224c;
	case 8784ULL: goto x86_l_2250;
	case 8792ULL: goto x86_l_2258;
	case 8794ULL: goto x86_l_225a;
	case 8799ULL: goto x86_l_225f;
	case 8803ULL: goto x86_l_2263;
	case 8806ULL: goto x86_l_2266;
	case 8811ULL: goto x86_l_226b;
	case 8813ULL: goto x86_l_226d;
	case 8815ULL: goto x86_l_226f;
	case 8821ULL: goto x86_l_2275;
	case 8829ULL: goto x86_l_227d;
	case 8835ULL: goto x86_l_2283;
	case 8841ULL: goto x86_l_2289;
	case 8845ULL: goto x86_l_228d;
	case 8853ULL: goto x86_l_2295;
	case 8855ULL: goto x86_l_2297;
	case 8860ULL: goto x86_l_229c;
	case 8864ULL: goto x86_l_22a0;
	case 8867ULL: goto x86_l_22a3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b98:
	/* 0x1b98: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9c:
	/* 0x1b9c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b9f:
	/* 0x1b9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ba4:
	/* 0x1ba4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba6:
	/* 0x1ba6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ba8:
	/* 0x1ba8: jns    2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10965ULL;
	}
x86_l_1bae:
	/* 0x1bae: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1bb3:
	/* 0x1bb3: jmp    2ad2 <generic_sleepable_preload+0x2ad2> */
	return 10962ULL;
x86_l_1bb8:
	/* 0x1bb8: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1bbd:
	/* 0x1bbd: jmp    2ad2 <generic_sleepable_preload+0x2ad2> */
	return 10962ULL;
x86_l_1bc2:
	/* 0x1bc2: mov    DWORD PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1bca:
	/* 0x1bca: jmp    2640 <generic_sleepable_preload+0x2640> */
	return 9792ULL;
x86_l_1bcf:
	/* 0x1bcf: mov    DWORD PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_1bd7:
	/* 0x1bd7: jmp    26f0 <generic_sleepable_preload+0x26f0> */
	return 9968ULL;
x86_l_1bdc:
	/* 0x1bdc: mov    DWORD PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_1be4:
	/* 0x1be4: jmp    27ce <generic_sleepable_preload+0x27ce> */
	return 10190ULL;
x86_l_1be9:
	/* 0x1be9: mov    DWORD PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_1bf1:
	/* 0x1bf1: jmp    28ac <generic_sleepable_preload+0x28ac> */
	return 10412ULL;
x86_l_1bf6:
	/* 0x1bf6: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1bfb:
	/* 0x1bfb: jmp    2987 <generic_sleepable_preload+0x2987> */
	return 10631ULL;
x86_l_1c00:
	/* 0x1c00: mov    DWORD PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1c08:
	/* 0x1c08: jmp    2a0e <generic_sleepable_preload+0x2a0e> */
	return 10766ULL;
x86_l_1c0d:
	/* 0x1c0d: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1c12:
	/* 0x1c12: jmp    2ad2 <generic_sleepable_preload+0x2ad2> */
	return 10962ULL;
x86_l_1c17:
	/* 0x1c17: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1c1a:
	/* 0x1c1a: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_1c1f:
	/* 0x1c1f: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1c21:
	/* 0x1c21: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_1c26:
	/* 0x1c26: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c28:
	/* 0x1c28: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_1c2d:
	/* 0x1c2d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c31:
	/* 0x1c31: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c35:
	/* 0x1c35: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1c3f:
	/* 0x1c3f: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c43:
	/* 0x1c43: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_1c4b:
	/* 0x1c4b: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1c51:
	/* 0x1c51: mov    ecx,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c57:
	/* 0x1c57: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c5a:
	/* 0x1c5a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c5e:
	/* 0x1c5e: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_1c66:
	/* 0x1c66: je     1c83 <generic_sleepable_preload+0x1c83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c83;
	}
x86_l_1c68:
	/* 0x1c68: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c6d:
	/* 0x1c6d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c71:
	/* 0x1c71: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x1c7d: js     1eb9 <generic_sleepable_preload+0x1eb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1eb9;
	}
x86_l_1c83:
	/* 0x1c83: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1c8b:
	/* 0x1c8b: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1c91:
	/* 0x1c91: mov    eax,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c97:
	/* 0x1c97: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1c9b:
	/* 0x1c9b: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_1ca3:
	/* 0x1ca3: je     1cc0 <generic_sleepable_preload+0x1cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cc0;
	}
x86_l_1ca5:
	/* 0x1ca5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1caa:
	/* 0x1caa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cae:
	/* 0x1cae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cb1:
	/* 0x1cb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cb6:
	/* 0x1cb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb8:
	/* 0x1cb8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cba:
	/* 0x1cba: js     1ec6 <generic_sleepable_preload+0x1ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ec6;
	}
x86_l_1cc0:
	/* 0x1cc0: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_1cc8:
	/* 0x1cc8: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1cce:
	/* 0x1cce: mov    eax,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1cd4:
	/* 0x1cd4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1cd8:
	/* 0x1cd8: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_1ce0:
	/* 0x1ce0: je     1cfd <generic_sleepable_preload+0x1cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cfd;
	}
x86_l_1ce2:
	/* 0x1ce2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ce7:
	/* 0x1ce7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ceb:
	/* 0x1ceb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cee:
	/* 0x1cee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cf3:
	/* 0x1cf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf5:
	/* 0x1cf5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cf7:
	/* 0x1cf7: js     24a0 <generic_sleepable_preload+0x24a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9376ULL;
	}
x86_l_1cfd:
	/* 0x1cfd: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_1d05:
	/* 0x1d05: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1d0b:
	/* 0x1d0b: mov    eax,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1d11:
	/* 0x1d11: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d15:
	/* 0x1d15: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_1d1d:
	/* 0x1d1d: je     1d3a <generic_sleepable_preload+0x1d3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3a;
	}
x86_l_1d1f:
	/* 0x1d1f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d24:
	/* 0x1d24: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d28:
	/* 0x1d28: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d2b:
	/* 0x1d2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d30:
	/* 0x1d30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d32:
	/* 0x1d32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d34:
	/* 0x1d34: js     251c <generic_sleepable_preload+0x251c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9500ULL;
	}
x86_l_1d3a:
	/* 0x1d3a: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_1d42:
	/* 0x1d42: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1d48:
	/* 0x1d48: mov    eax,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1d4e:
	/* 0x1d4e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d52:
	/* 0x1d52: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_1d5a:
	/* 0x1d5a: je     1d77 <generic_sleepable_preload+0x1d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d77;
	}
x86_l_1d5c:
	/* 0x1d5c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d61:
	/* 0x1d61: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d65:
	/* 0x1d65: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d68:
	/* 0x1d68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d6d:
	/* 0x1d6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6f:
	/* 0x1d6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d71:
	/* 0x1d71: js     2598 <generic_sleepable_preload+0x2598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9624ULL;
	}
x86_l_1d77:
	/* 0x1d77: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_1d7f:
	/* 0x1d7f: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1d85:
	/* 0x1d85: mov    eax,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1d8b:
	/* 0x1d8b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d8f:
	/* 0x1d8f: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_1d97:
	/* 0x1d97: je     1db4 <generic_sleepable_preload+0x1db4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1db4;
	}
x86_l_1d99:
	/* 0x1d99: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1da2:
	/* 0x1da2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1da5:
	/* 0x1da5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1daa:
	/* 0x1daa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dac:
	/* 0x1dac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dae:
	/* 0x1dae: js     2611 <generic_sleepable_preload+0x2611> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9745ULL;
	}
x86_l_1db4:
	/* 0x1db4: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_1dbc:
	/* 0x1dbc: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1dc2:
	/* 0x1dc2: mov    eax,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1dc8:
	/* 0x1dc8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1dcc:
	/* 0x1dcc: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_1dd4:
	/* 0x1dd4: je     1df1 <generic_sleepable_preload+0x1df1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df1;
	}
x86_l_1dd6:
	/* 0x1dd6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1de2:
	/* 0x1de2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1de7:
	/* 0x1de7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de9:
	/* 0x1de9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1deb:
	/* 0x1deb: js     2b7d <generic_sleepable_preload+0x2b7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11133ULL;
	}
x86_l_1df1:
	/* 0x1df1: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_1df9:
	/* 0x1df9: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1dff:
	/* 0x1dff: mov    eax,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1e05:
	/* 0x1e05: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e09:
	/* 0x1e09: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_1e11:
	/* 0x1e11: je     1e2e <generic_sleepable_preload+0x1e2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e2e;
	}
x86_l_1e13:
	/* 0x1e13: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e18:
	/* 0x1e18: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e1c:
	/* 0x1e1c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e1f:
	/* 0x1e1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e24:
	/* 0x1e24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e26:
	/* 0x1e26: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e28:
	/* 0x1e28: js     2df4 <generic_sleepable_preload+0x2df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11764ULL;
	}
x86_l_1e2e:
	/* 0x1e2e: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_1e36:
	/* 0x1e36: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1e3c:
	/* 0x1e3c: mov    eax,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1e42:
	/* 0x1e42: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e46:
	/* 0x1e46: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_1e4e:
	/* 0x1e4e: je     1e6b <generic_sleepable_preload+0x1e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e6b;
	}
x86_l_1e50:
	/* 0x1e50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e55:
	/* 0x1e55: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e59:
	/* 0x1e59: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e5c:
	/* 0x1e5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e61:
	/* 0x1e61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e63:
	/* 0x1e63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e65:
	/* 0x1e65: js     2ea6 <generic_sleepable_preload+0x2ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11942ULL;
	}
x86_l_1e6b:
	/* 0x1e6b: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_1e73:
	/* 0x1e73: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1e79:
	/* 0x1e79: mov    eax,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1e7f:
	/* 0x1e7f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e83:
	/* 0x1e83: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_1e8b:
	/* 0x1e8b: je     2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11149ULL;
	}
x86_l_1e91:
	/* 0x1e91: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e96:
	/* 0x1e96: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e9d:
	/* 0x1e9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ea2:
	/* 0x1ea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea4:
	/* 0x1ea4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ea6:
	/* 0x1ea6: jns    2b8d <generic_sleepable_preload+0x2b8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11149ULL;
	}
x86_l_1eac:
	/* 0x1eac: mov    DWORD PTR [rsp+0xc],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607562ULL);
x86_l_1eb4:
	/* 0x1eb4: jmp    2b85 <generic_sleepable_preload+0x2b85> */
	return 11141ULL;
x86_l_1eb9:
	/* 0x1eb9: mov    DWORD PTR [rsp+0xc],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607553ULL);
x86_l_1ec1:
	/* 0x1ec1: jmp    2b85 <generic_sleepable_preload+0x2b85> */
	return 11141ULL;
x86_l_1ec6:
	/* 0x1ec6: mov    DWORD PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_1ece:
	/* 0x1ece: jmp    2b85 <generic_sleepable_preload+0x2b85> */
	return 11141ULL;
x86_l_1ed3:
	/* 0x1ed3: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1ed6:
	/* 0x1ed6: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1ed9:
	/* 0x1ed9: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_1edb:
	/* 0x1edb: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1edd:
	/* 0x1edd: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_1ee2:
	/* 0x1ee2: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ee4:
	/* 0x1ee4: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eed:
	/* 0x1eed: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1ef9:
	/* 0x1ef9: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1efb:
	/* 0x1efb: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eff:
	/* 0x1eff: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_1f07:
	/* 0x1f07: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_1f0d:
	/* 0x1f0d: mov    ecx,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1f13:
	/* 0x1f13: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f16:
	/* 0x1f16: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f1a:
	/* 0x1f1a: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_1f22:
	/* 0x1f22: je     1f3f <generic_sleepable_preload+0x1f3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f3f;
	}
x86_l_1f24:
	/* 0x1f24: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f29:
	/* 0x1f29: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f30:
	/* 0x1f30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f35:
	/* 0x1f35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f37:
	/* 0x1f37: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f39:
	/* 0x1f39: js     2175 <generic_sleepable_preload+0x2175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2175;
	}
x86_l_1f3f:
	/* 0x1f3f: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_1f47:
	/* 0x1f47: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_1f4d:
	/* 0x1f4d: mov    eax,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1f53:
	/* 0x1f53: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1f57:
	/* 0x1f57: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_1f5f:
	/* 0x1f5f: je     1f7c <generic_sleepable_preload+0x1f7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f7c;
	}
x86_l_1f61:
	/* 0x1f61: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f66:
	/* 0x1f66: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f6d:
	/* 0x1f6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f72:
	/* 0x1f72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f74:
	/* 0x1f74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f76:
	/* 0x1f76: js     2182 <generic_sleepable_preload+0x2182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2182;
	}
x86_l_1f7c:
	/* 0x1f7c: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_1f84:
	/* 0x1f84: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_1f8a:
	/* 0x1f8a: mov    eax,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1f90:
	/* 0x1f90: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1f94:
	/* 0x1f94: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_1f9c:
	/* 0x1f9c: je     1fb9 <generic_sleepable_preload+0x1fb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb9;
	}
x86_l_1f9e:
	/* 0x1f9e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fa3:
	/* 0x1fa3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa7:
	/* 0x1fa7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1faa:
	/* 0x1faa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1faf:
	/* 0x1faf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb1:
	/* 0x1fb1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fb3:
	/* 0x1fb3: js     24ad <generic_sleepable_preload+0x24ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9389ULL;
	}
x86_l_1fb9:
	/* 0x1fb9: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_1fc1:
	/* 0x1fc1: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_1fc7:
	/* 0x1fc7: mov    eax,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1fcd:
	/* 0x1fcd: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1fd1:
	/* 0x1fd1: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_1fd9:
	/* 0x1fd9: je     1ff6 <generic_sleepable_preload+0x1ff6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff6;
	}
x86_l_1fdb:
	/* 0x1fdb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fe0:
	/* 0x1fe0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe4:
	/* 0x1fe4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fe7:
	/* 0x1fe7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fec:
	/* 0x1fec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fee:
	/* 0x1fee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ff0:
	/* 0x1ff0: js     2529 <generic_sleepable_preload+0x2529> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9513ULL;
	}
x86_l_1ff6:
	/* 0x1ff6: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_1ffe:
	/* 0x1ffe: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_2004:
	/* 0x2004: mov    eax,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_200a:
	/* 0x200a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_200e:
	/* 0x200e: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2016:
	/* 0x2016: je     2033 <generic_sleepable_preload+0x2033> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2033;
	}
x86_l_2018:
	/* 0x2018: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_201d:
	/* 0x201d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2021:
	/* 0x2021: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2024:
	/* 0x2024: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2029:
	/* 0x2029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202b:
	/* 0x202b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_202d:
	/* 0x202d: js     25a5 <generic_sleepable_preload+0x25a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9637ULL;
	}
x86_l_2033:
	/* 0x2033: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_203b:
	/* 0x203b: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_2041:
	/* 0x2041: mov    eax,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2047:
	/* 0x2047: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_204b:
	/* 0x204b: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2053:
	/* 0x2053: je     2070 <generic_sleepable_preload+0x2070> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2070;
	}
x86_l_2055:
	/* 0x2055: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_205a:
	/* 0x205a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_205e:
	/* 0x205e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2061:
	/* 0x2061: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2066:
	/* 0x2066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2068:
	/* 0x2068: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_206a:
	/* 0x206a: js     261e <generic_sleepable_preload+0x261e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9758ULL;
	}
x86_l_2070:
	/* 0x2070: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2078:
	/* 0x2078: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_207e:
	/* 0x207e: mov    eax,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2084:
	/* 0x2084: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2088:
	/* 0x2088: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2090:
	/* 0x2090: je     20ad <generic_sleepable_preload+0x20ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20ad;
	}
x86_l_2092:
	/* 0x2092: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2097:
	/* 0x2097: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_209b:
	/* 0x209b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_209e:
	/* 0x209e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20a3:
	/* 0x20a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a5:
	/* 0x20a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20a7:
	/* 0x20a7: js     2c1d <generic_sleepable_preload+0x2c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11293ULL;
	}
x86_l_20ad:
	/* 0x20ad: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_20b5:
	/* 0x20b5: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_20bb:
	/* 0x20bb: mov    eax,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_20c1:
	/* 0x20c1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20c5:
	/* 0x20c5: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_20cd:
	/* 0x20cd: je     20ea <generic_sleepable_preload+0x20ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20ea;
	}
x86_l_20cf:
	/* 0x20cf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20d4:
	/* 0x20d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d8:
	/* 0x20d8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20db:
	/* 0x20db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20e0:
	/* 0x20e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e2:
	/* 0x20e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20e4:
	/* 0x20e4: js     2e13 <generic_sleepable_preload+0x2e13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11795ULL;
	}
x86_l_20ea:
	/* 0x20ea: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_20f2:
	/* 0x20f2: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_20f8:
	/* 0x20f8: mov    eax,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_20fe:
	/* 0x20fe: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2102:
	/* 0x2102: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_210a:
	/* 0x210a: je     2127 <generic_sleepable_preload+0x2127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2127;
	}
x86_l_210c:
	/* 0x210c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2111:
	/* 0x2111: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2115:
	/* 0x2115: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2118:
	/* 0x2118: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_211d:
	/* 0x211d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211f:
	/* 0x211f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2121:
	/* 0x2121: js     2eb3 <generic_sleepable_preload+0x2eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11955ULL;
	}
x86_l_2127:
	/* 0x2127: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_212f:
	/* 0x212f: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_2135:
	/* 0x2135: mov    eax,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_213b:
	/* 0x213b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_213f:
	/* 0x213f: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2147:
	/* 0x2147: je     2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11309ULL;
	}
x86_l_214d:
	/* 0x214d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2152:
	/* 0x2152: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2156:
	/* 0x2156: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2159:
	/* 0x2159: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_215e:
	/* 0x215e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2160:
	/* 0x2160: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2162:
	/* 0x2162: jns    2c2d <generic_sleepable_preload+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11309ULL;
	}
x86_l_2168:
	/* 0x2168: mov    DWORD PTR [rsp+0xc],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607562ULL);
x86_l_2170:
	/* 0x2170: jmp    2c25 <generic_sleepable_preload+0x2c25> */
	return 11301ULL;
x86_l_2175:
	/* 0x2175: mov    DWORD PTR [rsp+0xc],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607553ULL);
x86_l_217d:
	/* 0x217d: jmp    2c25 <generic_sleepable_preload+0x2c25> */
	return 11301ULL;
x86_l_2182:
	/* 0x2182: mov    DWORD PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_218a:
	/* 0x218a: jmp    2c25 <generic_sleepable_preload+0x2c25> */
	return 11301ULL;
x86_l_218f:
	/* 0x218f: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2192:
	/* 0x2192: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2195:
	/* 0x2195: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_2197:
	/* 0x2197: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2199:
	/* 0x2199: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_219e:
	/* 0x219e: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21a0:
	/* 0x21a0: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_21a5:
	/* 0x21a5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a9:
	/* 0x21a9: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21ad:
	/* 0x21ad: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_21b5:
	/* 0x21b5: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_21b7:
	/* 0x21b7: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21bb:
	/* 0x21bb: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_21c3:
	/* 0x21c3: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_21c9:
	/* 0x21c9: mov    ecx,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_21cf:
	/* 0x21cf: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21d2:
	/* 0x21d2: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21d6:
	/* 0x21d6: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_21de:
	/* 0x21de: je     21fb <generic_sleepable_preload+0x21fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21fb;
	}
x86_l_21e0:
	/* 0x21e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21e5:
	/* 0x21e5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e9:
	/* 0x21e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21ec:
	/* 0x21ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f1:
	/* 0x21f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f3:
	/* 0x21f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21f5:
	/* 0x21f5: js     2431 <generic_sleepable_preload+0x2431> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9265ULL;
	}
x86_l_21fb:
	/* 0x21fb: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_2203:
	/* 0x2203: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_2209:
	/* 0x2209: mov    eax,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_220f:
	/* 0x220f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2213:
	/* 0x2213: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_221b:
	/* 0x221b: je     2238 <generic_sleepable_preload+0x2238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2238;
	}
x86_l_221d:
	/* 0x221d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2222:
	/* 0x2222: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2226:
	/* 0x2226: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2229:
	/* 0x2229: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_222e:
	/* 0x222e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2230:
	/* 0x2230: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2232:
	/* 0x2232: js     243e <generic_sleepable_preload+0x243e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9278ULL;
	}
x86_l_2238:
	/* 0x2238: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_2240:
	/* 0x2240: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_2246:
	/* 0x2246: mov    eax,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_224c:
	/* 0x224c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2250:
	/* 0x2250: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_2258:
	/* 0x2258: je     2275 <generic_sleepable_preload+0x2275> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2275;
	}
x86_l_225a:
	/* 0x225a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_225f:
	/* 0x225f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2263:
	/* 0x2263: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2266:
	/* 0x2266: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_226b:
	/* 0x226b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226d:
	/* 0x226d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_226f:
	/* 0x226f: js     24ba <generic_sleepable_preload+0x24ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9402ULL;
	}
x86_l_2275:
	/* 0x2275: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_227d:
	/* 0x227d: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_2283:
	/* 0x2283: mov    eax,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_2289:
	/* 0x2289: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_228d:
	/* 0x228d: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_2295:
	/* 0x2295: je     22b2 <generic_sleepable_preload+0x22b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8882ULL;
	}
x86_l_2297:
	/* 0x2297: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_229c:
	/* 0x229c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a0:
	/* 0x22a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22a3:
	/* 0x22a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 8872ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8872ULL: goto x86_l_22a8;
	case 8874ULL: goto x86_l_22aa;
	case 8876ULL: goto x86_l_22ac;
	case 8882ULL: goto x86_l_22b2;
	case 8890ULL: goto x86_l_22ba;
	case 8896ULL: goto x86_l_22c0;
	case 8902ULL: goto x86_l_22c6;
	case 8906ULL: goto x86_l_22ca;
	case 8914ULL: goto x86_l_22d2;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8925ULL: goto x86_l_22dd;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8935ULL: goto x86_l_22e7;
	case 8937ULL: goto x86_l_22e9;
	case 8943ULL: goto x86_l_22ef;
	case 8951ULL: goto x86_l_22f7;
	case 8957ULL: goto x86_l_22fd;
	case 8963ULL: goto x86_l_2303;
	case 8967ULL: goto x86_l_2307;
	case 8975ULL: goto x86_l_230f;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8986ULL: goto x86_l_231a;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8996ULL: goto x86_l_2324;
	case 8998ULL: goto x86_l_2326;
	case 9004ULL: goto x86_l_232c;
	case 9012ULL: goto x86_l_2334;
	case 9018ULL: goto x86_l_233a;
	case 9024ULL: goto x86_l_2340;
	case 9028ULL: goto x86_l_2344;
	case 9036ULL: goto x86_l_234c;
	case 9038ULL: goto x86_l_234e;
	case 9043ULL: goto x86_l_2353;
	case 9047ULL: goto x86_l_2357;
	case 9050ULL: goto x86_l_235a;
	case 9055ULL: goto x86_l_235f;
	case 9057ULL: goto x86_l_2361;
	case 9059ULL: goto x86_l_2363;
	case 9065ULL: goto x86_l_2369;
	case 9073ULL: goto x86_l_2371;
	case 9079ULL: goto x86_l_2377;
	case 9085ULL: goto x86_l_237d;
	case 9089ULL: goto x86_l_2381;
	case 9097ULL: goto x86_l_2389;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9108ULL: goto x86_l_2394;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9118ULL: goto x86_l_239e;
	case 9120ULL: goto x86_l_23a0;
	case 9126ULL: goto x86_l_23a6;
	case 9134ULL: goto x86_l_23ae;
	case 9140ULL: goto x86_l_23b4;
	case 9146ULL: goto x86_l_23ba;
	case 9150ULL: goto x86_l_23be;
	case 9158ULL: goto x86_l_23c6;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9169ULL: goto x86_l_23d1;
	case 9172ULL: goto x86_l_23d4;
	case 9177ULL: goto x86_l_23d9;
	case 9179ULL: goto x86_l_23db;
	case 9181ULL: goto x86_l_23dd;
	case 9187ULL: goto x86_l_23e3;
	case 9195ULL: goto x86_l_23eb;
	case 9201ULL: goto x86_l_23f1;
	case 9207ULL: goto x86_l_23f7;
	case 9211ULL: goto x86_l_23fb;
	case 9219ULL: goto x86_l_2403;
	case 9225ULL: goto x86_l_2409;
	case 9230ULL: goto x86_l_240e;
	case 9234ULL: goto x86_l_2412;
	case 9237ULL: goto x86_l_2415;
	case 9242ULL: goto x86_l_241a;
	case 9244ULL: goto x86_l_241c;
	case 9246ULL: goto x86_l_241e;
	case 9252ULL: goto x86_l_2424;
	case 9260ULL: goto x86_l_242c;
	case 9265ULL: goto x86_l_2431;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9338ULL: goto x86_l_247a;
	case 9343ULL: goto x86_l_247f;
	case 9348ULL: goto x86_l_2484;
	case 9353ULL: goto x86_l_2489;
	case 9361ULL: goto x86_l_2491;
	case 9366ULL: goto x86_l_2496;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9384ULL: goto x86_l_24a8;
	case 9389ULL: goto x86_l_24ad;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9462ULL: goto x86_l_24f6;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9485ULL: goto x86_l_250d;
	case 9490ULL: goto x86_l_2512;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9534ULL: goto x86_l_253e;
	case 9539ULL: goto x86_l_2543;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9645ULL: goto x86_l_25ad;
	case 9650ULL: goto x86_l_25b2;
	case 9658ULL: goto x86_l_25ba;
	case 9663ULL: goto x86_l_25bf;
	case 9671ULL: goto x86_l_25c7;
	case 9673ULL: goto x86_l_25c9;
	case 9681ULL: goto x86_l_25d1;
	case 9686ULL: goto x86_l_25d6;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9707ULL: goto x86_l_25eb;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9745ULL: goto x86_l_2611;
	case 9753ULL: goto x86_l_2619;
	case 9758ULL: goto x86_l_261e;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9779ULL: goto x86_l_2633;
	case 9784ULL: goto x86_l_2638;
	case 9792ULL: goto x86_l_2640;
	case 9800ULL: goto x86_l_2648;
	case 9804ULL: goto x86_l_264c;
	case 9809ULL: goto x86_l_2651;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9820ULL: goto x86_l_265c;
	case 9822ULL: goto x86_l_265e;
	case 9826ULL: goto x86_l_2662;
	case 9832ULL: goto x86_l_2668;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9846ULL: goto x86_l_2676;
	case 9848ULL: goto x86_l_2678;
	case 9853ULL: goto x86_l_267d;
	case 9861ULL: goto x86_l_2685;
	case 9866ULL: goto x86_l_268a;
	case 9873ULL: goto x86_l_2691;
	case 9878ULL: goto x86_l_2696;
	case 9880ULL: goto x86_l_2698;
	case 9883ULL: goto x86_l_269b;
	case 9889ULL: goto x86_l_26a1;
	case 9895ULL: goto x86_l_26a7;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9910ULL: goto x86_l_26b6;
	case 9913ULL: goto x86_l_26b9;
	case 9915ULL: goto x86_l_26bb;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9930ULL: goto x86_l_26ca;
	case 9933ULL: goto x86_l_26cd;
	case 9935ULL: goto x86_l_26cf;
	case 9938ULL: goto x86_l_26d2;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9968ULL: goto x86_l_26f0;
	case 9976ULL: goto x86_l_26f8;
	case 9980ULL: goto x86_l_26fc;
	case 9985ULL: goto x86_l_2701;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 9996ULL: goto x86_l_270c;
	case 9998ULL: goto x86_l_270e;
	case 10002ULL: goto x86_l_2712;
	case 10008ULL: goto x86_l_2718;
	case 10012ULL: goto x86_l_271c;
	case 10017ULL: goto x86_l_2721;
	case 10022ULL: goto x86_l_2726;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10037ULL: goto x86_l_2735;
	case 10042ULL: goto x86_l_273a;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10056ULL: goto x86_l_2748;
	case 10059ULL: goto x86_l_274b;
	case 10065ULL: goto x86_l_2751;
	case 10071ULL: goto x86_l_2757;
	case 10078ULL: goto x86_l_275e;
	case 10083ULL: goto x86_l_2763;
	case 10086ULL: goto x86_l_2766;
	case 10089ULL: goto x86_l_2769;
	case 10091ULL: goto x86_l_276b;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10106ULL: goto x86_l_277a;
	case 10109ULL: goto x86_l_277d;
	case 10111ULL: goto x86_l_277f;
	case 10114ULL: goto x86_l_2782;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10131ULL: goto x86_l_2793;
	case 10134ULL: goto x86_l_2796;
	case 10138ULL: goto x86_l_279a;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10150ULL: goto x86_l_27a6;
	case 10153ULL: goto x86_l_27a9;
	case 10158ULL: goto x86_l_27ae;
	case 10160ULL: goto x86_l_27b0;
	case 10163ULL: goto x86_l_27b3;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10174ULL: goto x86_l_27be;
	case 10177ULL: goto x86_l_27c1;
	case 10182ULL: goto x86_l_27c6;
	case 10190ULL: goto x86_l_27ce;
	case 10198ULL: goto x86_l_27d6;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10210ULL: goto x86_l_27e2;
	case 10215ULL: goto x86_l_27e7;
	case 10218ULL: goto x86_l_27ea;
	case 10220ULL: goto x86_l_27ec;
	case 10224ULL: goto x86_l_27f0;
	case 10230ULL: goto x86_l_27f6;
	case 10234ULL: goto x86_l_27fa;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10246ULL: goto x86_l_2806;
	case 10251ULL: goto x86_l_280b;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10278ULL: goto x86_l_2826;
	case 10281ULL: goto x86_l_2829;
	case 10287ULL: goto x86_l_282f;
	case 10293ULL: goto x86_l_2835;
	case 10300ULL: goto x86_l_283c;
	case 10305ULL: goto x86_l_2841;
	case 10308ULL: goto x86_l_2844;
	case 10311ULL: goto x86_l_2847;
	case 10313ULL: goto x86_l_2849;
	case 10316ULL: goto x86_l_284c;
	case 10321ULL: goto x86_l_2851;
	case 10328ULL: goto x86_l_2858;
	case 10331ULL: goto x86_l_285b;
	case 10333ULL: goto x86_l_285d;
	case 10336ULL: goto x86_l_2860;
	case 10342ULL: goto x86_l_2866;
	case 10347ULL: goto x86_l_286b;
	case 10353ULL: goto x86_l_2871;
	case 10356ULL: goto x86_l_2874;
	case 10360ULL: goto x86_l_2878;
	case 10365ULL: goto x86_l_287d;
	case 10370ULL: goto x86_l_2882;
	case 10372ULL: goto x86_l_2884;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10382ULL: goto x86_l_288e;
	case 10385ULL: goto x86_l_2891;
	case 10387ULL: goto x86_l_2893;
	case 10392ULL: goto x86_l_2898;
	case 10396ULL: goto x86_l_289c;
	case 10399ULL: goto x86_l_289f;
	case 10404ULL: goto x86_l_28a4;
	case 10412ULL: goto x86_l_28ac;
	case 10420ULL: goto x86_l_28b4;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10440ULL: goto x86_l_28c8;
	case 10442ULL: goto x86_l_28ca;
	case 10446ULL: goto x86_l_28ce;
	case 10452ULL: goto x86_l_28d4;
	case 10456ULL: goto x86_l_28d8;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10468ULL: goto x86_l_28e4;
	case 10473ULL: goto x86_l_28e9;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10500ULL: goto x86_l_2904;
	case 10503ULL: goto x86_l_2907;
	case 10509ULL: goto x86_l_290d;
	case 10515ULL: goto x86_l_2913;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10530ULL: goto x86_l_2922;
	case 10533ULL: goto x86_l_2925;
	case 10535ULL: goto x86_l_2927;
	case 10538ULL: goto x86_l_292a;
	case 10543ULL: goto x86_l_292f;
	case 10550ULL: goto x86_l_2936;
	case 10553ULL: goto x86_l_2939;
	case 10555ULL: goto x86_l_293b;
	case 10558ULL: goto x86_l_293e;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10575ULL: goto x86_l_294f;
	case 10578ULL: goto x86_l_2952;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10592ULL: goto x86_l_2960;
	case 10594ULL: goto x86_l_2962;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10604ULL: goto x86_l_296c;
	case 10607ULL: goto x86_l_296f;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10618ULL: goto x86_l_297a;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10634ULL: goto x86_l_298a;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10645ULL: goto x86_l_2995;
	case 10650ULL: goto x86_l_299a;
	case 10653ULL: goto x86_l_299d;
	case 10655ULL: goto x86_l_299f;
	case 10658ULL: goto x86_l_29a2;
	case 10664ULL: goto x86_l_29a8;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10688ULL: goto x86_l_29c0;
	case 10693ULL: goto x86_l_29c5;
	case 10700ULL: goto x86_l_29cc;
	case 10705ULL: goto x86_l_29d1;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10716ULL: goto x86_l_29dc;
	case 10722ULL: goto x86_l_29e2;
	case 10729ULL: goto x86_l_29e9;
	case 10734ULL: goto x86_l_29ee;
	case 10737ULL: goto x86_l_29f1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22a8:
	/* 0x22a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22aa:
	/* 0x22aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22ac:
	/* 0x22ac: js     2536 <generic_sleepable_preload+0x2536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2536;
	}
x86_l_22b2:
	/* 0x22b2: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_22ba:
	/* 0x22ba: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_22c0:
	/* 0x22c0: mov    eax,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_22c6:
	/* 0x22c6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22ca:
	/* 0x22ca: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_22d2:
	/* 0x22d2: je     22ef <generic_sleepable_preload+0x22ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22ef;
	}
x86_l_22d4:
	/* 0x22d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22d9:
	/* 0x22d9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22dd:
	/* 0x22dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22e0:
	/* 0x22e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e5:
	/* 0x22e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e7:
	/* 0x22e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e9:
	/* 0x22e9: js     25b2 <generic_sleepable_preload+0x25b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25b2;
	}
x86_l_22ef:
	/* 0x22ef: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_22f7:
	/* 0x22f7: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_22fd:
	/* 0x22fd: mov    eax,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_2303:
	/* 0x2303: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2307:
	/* 0x2307: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_230f:
	/* 0x230f: je     232c <generic_sleepable_preload+0x232c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232c;
	}
x86_l_2311:
	/* 0x2311: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2316:
	/* 0x2316: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231a:
	/* 0x231a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_231d:
	/* 0x231d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2322:
	/* 0x2322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2324:
	/* 0x2324: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2326:
	/* 0x2326: js     262b <generic_sleepable_preload+0x262b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_262b;
	}
x86_l_232c:
	/* 0x232c: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_2334:
	/* 0x2334: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_233a:
	/* 0x233a: mov    eax,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_2340:
	/* 0x2340: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2344:
	/* 0x2344: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_234c:
	/* 0x234c: je     2369 <generic_sleepable_preload+0x2369> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2369;
	}
x86_l_234e:
	/* 0x234e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2353:
	/* 0x2353: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2357:
	/* 0x2357: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_235a:
	/* 0x235a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_235f:
	/* 0x235f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2361:
	/* 0x2361: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2363:
	/* 0x2363: js     2cbd <generic_sleepable_preload+0x2cbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11453ULL;
	}
x86_l_2369:
	/* 0x2369: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_2371:
	/* 0x2371: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_2377:
	/* 0x2377: mov    eax,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_237d:
	/* 0x237d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2381:
	/* 0x2381: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_2389:
	/* 0x2389: je     23a6 <generic_sleepable_preload+0x23a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23a6;
	}
x86_l_238b:
	/* 0x238b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2390:
	/* 0x2390: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2394:
	/* 0x2394: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2397:
	/* 0x2397: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_239c:
	/* 0x239c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_239e:
	/* 0x239e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23a0:
	/* 0x23a0: js     2e32 <generic_sleepable_preload+0x2e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11826ULL;
	}
x86_l_23a6:
	/* 0x23a6: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_23ae:
	/* 0x23ae: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_23b4:
	/* 0x23b4: mov    eax,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_23ba:
	/* 0x23ba: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23be:
	/* 0x23be: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_23c6:
	/* 0x23c6: je     23e3 <generic_sleepable_preload+0x23e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23e3;
	}
x86_l_23c8:
	/* 0x23c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23cd:
	/* 0x23cd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d1:
	/* 0x23d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23d4:
	/* 0x23d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23d9:
	/* 0x23d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23db:
	/* 0x23db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23dd:
	/* 0x23dd: js     2ec0 <generic_sleepable_preload+0x2ec0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11968ULL;
	}
x86_l_23e3:
	/* 0x23e3: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_23eb:
	/* 0x23eb: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_23f1:
	/* 0x23f1: mov    eax,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_23f7:
	/* 0x23f7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23fb:
	/* 0x23fb: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_2403:
	/* 0x2403: je     2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11469ULL;
	}
x86_l_2409:
	/* 0x2409: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_240e:
	/* 0x240e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2412:
	/* 0x2412: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2415:
	/* 0x2415: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_241a:
	/* 0x241a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241c:
	/* 0x241c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_241e:
	/* 0x241e: jns    2ccd <generic_sleepable_preload+0x2ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11469ULL;
	}
x86_l_2424:
	/* 0x2424: mov    DWORD PTR [rsp+0xc],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607562ULL);
x86_l_242c:
	/* 0x242c: jmp    2cc5 <generic_sleepable_preload+0x2cc5> */
	return 11461ULL;
x86_l_2431:
	/* 0x2431: mov    DWORD PTR [rsp+0xc],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607553ULL);
x86_l_2439:
	/* 0x2439: jmp    2cc5 <generic_sleepable_preload+0x2cc5> */
	return 11461ULL;
x86_l_243e:
	/* 0x243e: mov    DWORD PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_2446:
	/* 0x2446: jmp    2cc5 <generic_sleepable_preload+0x2cc5> */
	return 11461ULL;
x86_l_244b:
	/* 0x244b: mov    DWORD PTR [rsp+0x10],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476739ULL);
x86_l_2453:
	/* 0x2453: jmp    2640 <generic_sleepable_preload+0x2640> */
	goto x86_l_2640;
x86_l_2458:
	/* 0x2458: mov    DWORD PTR [rsp+0xc],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607555ULL);
x86_l_2460:
	/* 0x2460: jmp    26f0 <generic_sleepable_preload+0x26f0> */
	goto x86_l_26f0;
x86_l_2465:
	/* 0x2465: mov    DWORD PTR [rsp+0xc],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607555ULL);
x86_l_246d:
	/* 0x246d: jmp    27ce <generic_sleepable_preload+0x27ce> */
	goto x86_l_27ce;
x86_l_2472:
	/* 0x2472: mov    DWORD PTR [rsp+0xc],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607555ULL);
x86_l_247a:
	/* 0x247a: jmp    28ac <generic_sleepable_preload+0x28ac> */
	goto x86_l_28ac;
x86_l_247f:
	/* 0x247f: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2484:
	/* 0x2484: jmp    2987 <generic_sleepable_preload+0x2987> */
	goto x86_l_2987;
x86_l_2489:
	/* 0x2489: mov    DWORD PTR [rsp+0x10],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476739ULL);
x86_l_2491:
	/* 0x2491: jmp    2a0e <generic_sleepable_preload+0x2a0e> */
	return 10766ULL;
x86_l_2496:
	/* 0x2496: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_249b:
	/* 0x249b: jmp    2ad2 <generic_sleepable_preload+0x2ad2> */
	return 10962ULL;
x86_l_24a0:
	/* 0x24a0: mov    DWORD PTR [rsp+0xc],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607555ULL);
x86_l_24a8:
	/* 0x24a8: jmp    2b85 <generic_sleepable_preload+0x2b85> */
	return 11141ULL;
x86_l_24ad:
	/* 0x24ad: mov    DWORD PTR [rsp+0xc],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607555ULL);
x86_l_24b5:
	/* 0x24b5: jmp    2c25 <generic_sleepable_preload+0x2c25> */
	return 11301ULL;
x86_l_24ba:
	/* 0x24ba: mov    DWORD PTR [rsp+0xc],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607555ULL);
x86_l_24c2:
	/* 0x24c2: jmp    2cc5 <generic_sleepable_preload+0x2cc5> */
	return 11461ULL;
x86_l_24c7:
	/* 0x24c7: mov    DWORD PTR [rsp+0x10],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476740ULL);
x86_l_24cf:
	/* 0x24cf: jmp    2640 <generic_sleepable_preload+0x2640> */
	goto x86_l_2640;
x86_l_24d4:
	/* 0x24d4: mov    DWORD PTR [rsp+0xc],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607556ULL);
x86_l_24dc:
	/* 0x24dc: jmp    26f0 <generic_sleepable_preload+0x26f0> */
	goto x86_l_26f0;
x86_l_24e1:
	/* 0x24e1: mov    DWORD PTR [rsp+0xc],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607556ULL);
x86_l_24e9:
	/* 0x24e9: jmp    27ce <generic_sleepable_preload+0x27ce> */
	goto x86_l_27ce;
x86_l_24ee:
	/* 0x24ee: mov    DWORD PTR [rsp+0xc],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607556ULL);
x86_l_24f6:
	/* 0x24f6: jmp    28ac <generic_sleepable_preload+0x28ac> */
	goto x86_l_28ac;
x86_l_24fb:
	/* 0x24fb: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2500:
	/* 0x2500: jmp    2987 <generic_sleepable_preload+0x2987> */
	goto x86_l_2987;
x86_l_2505:
	/* 0x2505: mov    DWORD PTR [rsp+0x10],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476740ULL);
x86_l_250d:
	/* 0x250d: jmp    2a0e <generic_sleepable_preload+0x2a0e> */
	return 10766ULL;
x86_l_2512:
	/* 0x2512: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2517:
	/* 0x2517: jmp    2ad2 <generic_sleepable_preload+0x2ad2> */
	return 10962ULL;
x86_l_251c:
	/* 0x251c: mov    DWORD PTR [rsp+0xc],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607556ULL);
x86_l_2524:
	/* 0x2524: jmp    2b85 <generic_sleepable_preload+0x2b85> */
	return 11141ULL;
x86_l_2529:
	/* 0x2529: mov    DWORD PTR [rsp+0xc],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607556ULL);
x86_l_2531:
	/* 0x2531: jmp    2c25 <generic_sleepable_preload+0x2c25> */
	return 11301ULL;
x86_l_2536:
	/* 0x2536: mov    DWORD PTR [rsp+0xc],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607556ULL);
x86_l_253e:
	/* 0x253e: jmp    2cc5 <generic_sleepable_preload+0x2cc5> */
	return 11461ULL;
x86_l_2543:
	/* 0x2543: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_254b:
	/* 0x254b: jmp    2640 <generic_sleepable_preload+0x2640> */
	goto x86_l_2640;
x86_l_2550:
	/* 0x2550: mov    DWORD PTR [rsp+0xc],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607557ULL);
x86_l_2558:
	/* 0x2558: jmp    26f0 <generic_sleepable_preload+0x26f0> */
	goto x86_l_26f0;
x86_l_255d:
	/* 0x255d: mov    DWORD PTR [rsp+0xc],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607557ULL);
x86_l_2565:
	/* 0x2565: jmp    27ce <generic_sleepable_preload+0x27ce> */
	goto x86_l_27ce;
x86_l_256a:
	/* 0x256a: mov    DWORD PTR [rsp+0xc],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607557ULL);
x86_l_2572:
	/* 0x2572: jmp    28ac <generic_sleepable_preload+0x28ac> */
	goto x86_l_28ac;
x86_l_2577:
	/* 0x2577: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_257c:
	/* 0x257c: jmp    2987 <generic_sleepable_preload+0x2987> */
	goto x86_l_2987;
x86_l_2581:
	/* 0x2581: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_2589:
	/* 0x2589: jmp    2a0e <generic_sleepable_preload+0x2a0e> */
	return 10766ULL;
x86_l_258e:
	/* 0x258e: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2593:
	/* 0x2593: jmp    2ad2 <generic_sleepable_preload+0x2ad2> */
	return 10962ULL;
x86_l_2598:
	/* 0x2598: mov    DWORD PTR [rsp+0xc],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607557ULL);
x86_l_25a0:
	/* 0x25a0: jmp    2b85 <generic_sleepable_preload+0x2b85> */
	return 11141ULL;
x86_l_25a5:
	/* 0x25a5: mov    DWORD PTR [rsp+0xc],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607557ULL);
x86_l_25ad:
	/* 0x25ad: jmp    2c25 <generic_sleepable_preload+0x2c25> */
	return 11301ULL;
x86_l_25b2:
	/* 0x25b2: mov    DWORD PTR [rsp+0xc],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607557ULL);
x86_l_25ba:
	/* 0x25ba: jmp    2cc5 <generic_sleepable_preload+0x2cc5> */
	return 11461ULL;
x86_l_25bf:
	/* 0x25bf: mov    DWORD PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_25c7:
	/* 0x25c7: jmp    2640 <generic_sleepable_preload+0x2640> */
	goto x86_l_2640;
x86_l_25c9:
	/* 0x25c9: mov    DWORD PTR [rsp+0xc],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_25d1:
	/* 0x25d1: jmp    26f0 <generic_sleepable_preload+0x26f0> */
	goto x86_l_26f0;
x86_l_25d6:
	/* 0x25d6: mov    DWORD PTR [rsp+0xc],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_25de:
	/* 0x25de: jmp    27ce <generic_sleepable_preload+0x27ce> */
	goto x86_l_27ce;
x86_l_25e3:
	/* 0x25e3: mov    DWORD PTR [rsp+0xc],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_25eb:
	/* 0x25eb: jmp    28ac <generic_sleepable_preload+0x28ac> */
	goto x86_l_28ac;
x86_l_25f0:
	/* 0x25f0: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_25f5:
	/* 0x25f5: jmp    2987 <generic_sleepable_preload+0x2987> */
	goto x86_l_2987;
x86_l_25fa:
	/* 0x25fa: mov    DWORD PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_2602:
	/* 0x2602: jmp    2a0e <generic_sleepable_preload+0x2a0e> */
	return 10766ULL;
x86_l_2607:
	/* 0x2607: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_260c:
	/* 0x260c: jmp    2ad2 <generic_sleepable_preload+0x2ad2> */
	return 10962ULL;
x86_l_2611:
	/* 0x2611: mov    DWORD PTR [rsp+0xc],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_2619:
	/* 0x2619: jmp    2b85 <generic_sleepable_preload+0x2b85> */
	return 11141ULL;
x86_l_261e:
	/* 0x261e: mov    DWORD PTR [rsp+0xc],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_2626:
	/* 0x2626: jmp    2c25 <generic_sleepable_preload+0x2c25> */
	return 11301ULL;
x86_l_262b:
	/* 0x262b: mov    DWORD PTR [rsp+0xc],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_2633:
	/* 0x2633: jmp    2cc5 <generic_sleepable_preload+0x2cc5> */
	return 11461ULL;
x86_l_2638:
	/* 0x2638: mov    DWORD PTR [rsp+0x10],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476743ULL);
x86_l_2640:
	/* 0x2640: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2648:
	/* 0x2648: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_264c:
	/* 0x264c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2651:
	/* 0x2651: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2654:
	/* 0x2654: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2659:
	/* 0x2659: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_265c:
	/* 0x265c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265e:
	/* 0x265e: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2662:
	/* 0x2662: jne    d1 <generic_sleepable_preload+0xd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 209ULL;
	}
x86_l_2668:
	/* 0x2668: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_266c:
	/* 0x266c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2671:
	/* 0x2671: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2676:
	/* 0x2676: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2678:
	/* 0x2678: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_267d:
	/* 0x267d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2685:
	/* 0x2685: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_268a:
	/* 0x268a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2691:
	/* 0x2691: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2696:
	/* 0x2696: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2698:
	/* 0x2698: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_269b:
	/* 0x269b: je     d1 <generic_sleepable_preload+0xd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 209ULL;
	}
x86_l_26a1:
	/* 0x26a1: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_26a7:
	/* 0x26a7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_26ae:
	/* 0x26ae: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26b3:
	/* 0x26b3: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_26b6:
	/* 0x26b6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_26b9:
	/* 0x26b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26bb:
	/* 0x26bb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_26be:
	/* 0x26be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26c3:
	/* 0x26c3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_26ca:
	/* 0x26ca: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_26cd:
	/* 0x26cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26cf:
	/* 0x26cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26d2:
	/* 0x26d2: je     d1 <generic_sleepable_preload+0xd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 209ULL;
	}
x86_l_26d8:
	/* 0x26d8: cmp    BYTE PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_26dd:
	/* 0x26dd: jne    2a97 <generic_sleepable_preload+0x2a97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10903ULL;
	}
x86_l_26e3:
	/* 0x26e3: jmp    2abb <generic_sleepable_preload+0x2abb> */
	return 10939ULL;
x86_l_26e8:
	/* 0x26e8: mov    DWORD PTR [rsp+0xc],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607559ULL);
x86_l_26f0:
	/* 0x26f0: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_26f8:
	/* 0x26f8: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26fc:
	/* 0x26fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2701:
	/* 0x2701: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2704:
	/* 0x2704: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2709:
	/* 0x2709: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_270c:
	/* 0x270c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270e:
	/* 0x270e: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2712:
	/* 0x2712: jne    db <generic_sleepable_preload+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 219ULL;
	}
x86_l_2718:
	/* 0x2718: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271c:
	/* 0x271c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2721:
	/* 0x2721: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2726:
	/* 0x2726: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2728:
	/* 0x2728: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_272d:
	/* 0x272d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2735:
	/* 0x2735: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_273a:
	/* 0x273a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2741:
	/* 0x2741: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2746:
	/* 0x2746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2748:
	/* 0x2748: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_274b:
	/* 0x274b: je     db <generic_sleepable_preload+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 219ULL;
	}
x86_l_2751:
	/* 0x2751: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2757:
	/* 0x2757: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_275e:
	/* 0x275e: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2763:
	/* 0x2763: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2766:
	/* 0x2766: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2769:
	/* 0x2769: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_276b:
	/* 0x276b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_276e:
	/* 0x276e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2773:
	/* 0x2773: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_277a:
	/* 0x277a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_277d:
	/* 0x277d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277f:
	/* 0x277f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2782:
	/* 0x2782: je     db <generic_sleepable_preload+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 219ULL;
	}
x86_l_2788:
	/* 0x2788: cmp    BYTE PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_278d:
	/* 0x278d: je     2c12 <generic_sleepable_preload+0x2c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11282ULL;
	}
x86_l_2793:
	/* 0x2793: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2796:
	/* 0x2796: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_279a:
	/* 0x279a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_279f:
	/* 0x279f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27a4:
	/* 0x27a4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27a6:
	/* 0x27a6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_27a9:
	/* 0x27a9: call   27ae <generic_sleepable_preload+0x27ae> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_27ae:
	/* 0x27ae: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_27b0:
	/* 0x27b0: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_27b3:
	/* 0x27b3: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_27b5:
	/* 0x27b5: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_27ba:
	/* 0x27ba: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_27be:
	/* 0x27be: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_27c1:
	/* 0x27c1: jmp    2c16 <generic_sleepable_preload+0x2c16> */
	return 11286ULL;
x86_l_27c6:
	/* 0x27c6: mov    DWORD PTR [rsp+0xc],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607559ULL);
x86_l_27ce:
	/* 0x27ce: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_27d6:
	/* 0x27d6: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_27da:
	/* 0x27da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27df:
	/* 0x27df: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27e2:
	/* 0x27e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e7:
	/* 0x27e7: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_27ea:
	/* 0x27ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ec:
	/* 0x27ec: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_27f0:
	/* 0x27f0: jne    e9 <generic_sleepable_preload+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 233ULL;
	}
x86_l_27f6:
	/* 0x27f6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27fa:
	/* 0x27fa: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27ff:
	/* 0x27ff: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2804:
	/* 0x2804: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2806:
	/* 0x2806: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_280b:
	/* 0x280b: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2813:
	/* 0x2813: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2818:
	/* 0x2818: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_281f:
	/* 0x281f: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2824:
	/* 0x2824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2826:
	/* 0x2826: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2829:
	/* 0x2829: je     e9 <generic_sleepable_preload+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 233ULL;
	}
x86_l_282f:
	/* 0x282f: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2835:
	/* 0x2835: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_283c:
	/* 0x283c: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2841:
	/* 0x2841: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2844:
	/* 0x2844: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2847:
	/* 0x2847: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2849:
	/* 0x2849: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_284c:
	/* 0x284c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2851:
	/* 0x2851: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2858:
	/* 0x2858: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_285b:
	/* 0x285b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285d:
	/* 0x285d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2860:
	/* 0x2860: je     e9 <generic_sleepable_preload+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 233ULL;
	}
x86_l_2866:
	/* 0x2866: cmp    BYTE PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_286b:
	/* 0x286b: je     2cb2 <generic_sleepable_preload+0x2cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11442ULL;
	}
x86_l_2871:
	/* 0x2871: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2874:
	/* 0x2874: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2878:
	/* 0x2878: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_287d:
	/* 0x287d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2882:
	/* 0x2882: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2884:
	/* 0x2884: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2887:
	/* 0x2887: call   288c <generic_sleepable_preload+0x288c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_288c:
	/* 0x288c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_288e:
	/* 0x288e: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2891:
	/* 0x2891: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2893:
	/* 0x2893: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2898:
	/* 0x2898: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_289c:
	/* 0x289c: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_289f:
	/* 0x289f: jmp    2cb6 <generic_sleepable_preload+0x2cb6> */
	return 11446ULL;
x86_l_28a4:
	/* 0x28a4: mov    DWORD PTR [rsp+0xc],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607559ULL);
x86_l_28ac:
	/* 0x28ac: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_28b4:
	/* 0x28b4: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28b8:
	/* 0x28b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28bd:
	/* 0x28bd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28c0:
	/* 0x28c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c5:
	/* 0x28c5: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_28c8:
	/* 0x28c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ca:
	/* 0x28ca: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_28ce:
	/* 0x28ce: jne    f7 <generic_sleepable_preload+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 247ULL;
	}
x86_l_28d4:
	/* 0x28d4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d8:
	/* 0x28d8: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28dd:
	/* 0x28dd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_28e2:
	/* 0x28e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e4:
	/* 0x28e4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28e9:
	/* 0x28e9: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_28f1:
	/* 0x28f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28f6:
	/* 0x28f6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_28fd:
	/* 0x28fd: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2902:
	/* 0x2902: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2904:
	/* 0x2904: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2907:
	/* 0x2907: je     f7 <generic_sleepable_preload+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 247ULL;
	}
x86_l_290d:
	/* 0x290d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2913:
	/* 0x2913: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_291a:
	/* 0x291a: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_291f:
	/* 0x291f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2922:
	/* 0x2922: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2925:
	/* 0x2925: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2927:
	/* 0x2927: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_292a:
	/* 0x292a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_292f:
	/* 0x292f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2936:
	/* 0x2936: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2939:
	/* 0x2939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293b:
	/* 0x293b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_293e:
	/* 0x293e: je     f7 <generic_sleepable_preload+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 247ULL;
	}
x86_l_2944:
	/* 0x2944: cmp    BYTE PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2949:
	/* 0x2949: je     2d52 <generic_sleepable_preload+0x2d52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11602ULL;
	}
x86_l_294f:
	/* 0x294f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2952:
	/* 0x2952: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2956:
	/* 0x2956: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_295b:
	/* 0x295b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2960:
	/* 0x2960: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2962:
	/* 0x2962: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2965:
	/* 0x2965: call   296a <generic_sleepable_preload+0x296a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_296a:
	/* 0x296a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_296c:
	/* 0x296c: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_296f:
	/* 0x296f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2971:
	/* 0x2971: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2976:
	/* 0x2976: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_297a:
	/* 0x297a: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_297d:
	/* 0x297d: jmp    2d56 <generic_sleepable_preload+0x2d56> */
	return 11606ULL;
x86_l_2982:
	/* 0x2982: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_2987:
	/* 0x2987: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_298a:
	/* 0x298a: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_298d:
	/* 0x298d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2992:
	/* 0x2992: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2995:
	/* 0x2995: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_299a:
	/* 0x299a: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_299d:
	/* 0x299d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299f:
	/* 0x299f: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_29a2:
	/* 0x29a2: jne    105 <generic_sleepable_preload+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 261ULL;
	}
x86_l_29a8:
	/* 0x29a8: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ac:
	/* 0x29ac: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_29b1:
	/* 0x29b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b3:
	/* 0x29b3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29b8:
	/* 0x29b8: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_29c0:
	/* 0x29c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29c5:
	/* 0x29c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_29cc:
	/* 0x29cc: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_29d1:
	/* 0x29d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d3:
	/* 0x29d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29d6:
	/* 0x29d6: je     105 <generic_sleepable_preload+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 261ULL;
	}
x86_l_29dc:
	/* 0x29dc: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_29e2:
	/* 0x29e2: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_29e9:
	/* 0x29e9: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29ee:
	/* 0x29ee: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_29f1:
	/* 0x29f1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
	return 10740ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10740ULL: goto x86_l_29f4;
	case 10743ULL: goto x86_l_29f7;
	case 10745ULL: goto x86_l_29f9;
	case 10748ULL: goto x86_l_29fc;
	case 10753ULL: goto x86_l_2a01;
	case 10758ULL: goto x86_l_2a06;
	case 10766ULL: goto x86_l_2a0e;
	case 10774ULL: goto x86_l_2a16;
	case 10778ULL: goto x86_l_2a1a;
	case 10784ULL: goto x86_l_2a20;
	case 10788ULL: goto x86_l_2a24;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10813ULL: goto x86_l_2a3d;
	case 10818ULL: goto x86_l_2a42;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10832ULL: goto x86_l_2a50;
	case 10835ULL: goto x86_l_2a53;
	case 10841ULL: goto x86_l_2a59;
	case 10847ULL: goto x86_l_2a5f;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10862ULL: goto x86_l_2a6e;
	case 10865ULL: goto x86_l_2a71;
	case 10867ULL: goto x86_l_2a73;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10882ULL: goto x86_l_2a82;
	case 10885ULL: goto x86_l_2a85;
	case 10887ULL: goto x86_l_2a87;
	case 10890ULL: goto x86_l_2a8a;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10906ULL: goto x86_l_2a9a;
	case 10910ULL: goto x86_l_2a9e;
	case 10915ULL: goto x86_l_2aa3;
	case 10920ULL: goto x86_l_2aa8;
	case 10922ULL: goto x86_l_2aaa;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10932ULL: goto x86_l_2ab4;
	case 10935ULL: goto x86_l_2ab7;
	case 10937ULL: goto x86_l_2ab9;
	case 10939ULL: goto x86_l_2abb;
	case 10943ULL: goto x86_l_2abf;
	case 10945ULL: goto x86_l_2ac1;
	case 10950ULL: goto x86_l_2ac6;
	case 10955ULL: goto x86_l_2acb;
	case 10957ULL: goto x86_l_2acd;
	case 10962ULL: goto x86_l_2ad2;
	case 10965ULL: goto x86_l_2ad5;
	case 10969ULL: goto x86_l_2ad9;
	case 10975ULL: goto x86_l_2adf;
	case 10979ULL: goto x86_l_2ae3;
	case 10984ULL: goto x86_l_2ae8;
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10999ULL: goto x86_l_2af7;
	case 11004ULL: goto x86_l_2afc;
	case 11011ULL: goto x86_l_2b03;
	case 11016ULL: goto x86_l_2b08;
	case 11018ULL: goto x86_l_2b0a;
	case 11021ULL: goto x86_l_2b0d;
	case 11027ULL: goto x86_l_2b13;
	case 11033ULL: goto x86_l_2b19;
	case 11040ULL: goto x86_l_2b20;
	case 11045ULL: goto x86_l_2b25;
	case 11048ULL: goto x86_l_2b28;
	case 11051ULL: goto x86_l_2b2b;
	case 11054ULL: goto x86_l_2b2e;
	case 11056ULL: goto x86_l_2b30;
	case 11059ULL: goto x86_l_2b33;
	case 11064ULL: goto x86_l_2b38;
	case 11067ULL: goto x86_l_2b3b;
	case 11070ULL: goto x86_l_2b3e;
	case 11072ULL: goto x86_l_2b40;
	case 11075ULL: goto x86_l_2b43;
	case 11081ULL: goto x86_l_2b49;
	case 11084ULL: goto x86_l_2b4c;
	case 11086ULL: goto x86_l_2b4e;
	case 11089ULL: goto x86_l_2b51;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11101ULL: goto x86_l_2b5d;
	case 11103ULL: goto x86_l_2b5f;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11113ULL: goto x86_l_2b69;
	case 11116ULL: goto x86_l_2b6c;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11126ULL: goto x86_l_2b76;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11141ULL: goto x86_l_2b85;
	case 11149ULL: goto x86_l_2b8d;
	case 11153ULL: goto x86_l_2b91;
	case 11159ULL: goto x86_l_2b97;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11180ULL: goto x86_l_2bac;
	case 11188ULL: goto x86_l_2bb4;
	case 11193ULL: goto x86_l_2bb9;
	case 11200ULL: goto x86_l_2bc0;
	case 11205ULL: goto x86_l_2bc5;
	case 11207ULL: goto x86_l_2bc7;
	case 11210ULL: goto x86_l_2bca;
	case 11216ULL: goto x86_l_2bd0;
	case 11222ULL: goto x86_l_2bd6;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11237ULL: goto x86_l_2be5;
	case 11240ULL: goto x86_l_2be8;
	case 11242ULL: goto x86_l_2bea;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11257ULL: goto x86_l_2bf9;
	case 11260ULL: goto x86_l_2bfc;
	case 11262ULL: goto x86_l_2bfe;
	case 11265ULL: goto x86_l_2c01;
	case 11271ULL: goto x86_l_2c07;
	case 11276ULL: goto x86_l_2c0c;
	case 11282ULL: goto x86_l_2c12;
	case 11286ULL: goto x86_l_2c16;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11301ULL: goto x86_l_2c25;
	case 11309ULL: goto x86_l_2c2d;
	case 11313ULL: goto x86_l_2c31;
	case 11319ULL: goto x86_l_2c37;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11367ULL: goto x86_l_2c67;
	case 11370ULL: goto x86_l_2c6a;
	case 11376ULL: goto x86_l_2c70;
	case 11382ULL: goto x86_l_2c76;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11397ULL: goto x86_l_2c85;
	case 11400ULL: goto x86_l_2c88;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11410ULL: goto x86_l_2c92;
	case 11417ULL: goto x86_l_2c99;
	case 11420ULL: goto x86_l_2c9c;
	case 11422ULL: goto x86_l_2c9e;
	case 11425ULL: goto x86_l_2ca1;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11442ULL: goto x86_l_2cb2;
	case 11446ULL: goto x86_l_2cb6;
	case 11448ULL: goto x86_l_2cb8;
	case 11453ULL: goto x86_l_2cbd;
	case 11461ULL: goto x86_l_2cc5;
	case 11469ULL: goto x86_l_2ccd;
	case 11473ULL: goto x86_l_2cd1;
	case 11479ULL: goto x86_l_2cd7;
	case 11483ULL: goto x86_l_2cdb;
	case 11488ULL: goto x86_l_2ce0;
	case 11493ULL: goto x86_l_2ce5;
	case 11495ULL: goto x86_l_2ce7;
	case 11500ULL: goto x86_l_2cec;
	case 11508ULL: goto x86_l_2cf4;
	case 11513ULL: goto x86_l_2cf9;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11527ULL: goto x86_l_2d07;
	case 11530ULL: goto x86_l_2d0a;
	case 11536ULL: goto x86_l_2d10;
	case 11542ULL: goto x86_l_2d16;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11557ULL: goto x86_l_2d25;
	case 11560ULL: goto x86_l_2d28;
	case 11562ULL: goto x86_l_2d2a;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11577ULL: goto x86_l_2d39;
	case 11580ULL: goto x86_l_2d3c;
	case 11582ULL: goto x86_l_2d3e;
	case 11585ULL: goto x86_l_2d41;
	case 11591ULL: goto x86_l_2d47;
	case 11596ULL: goto x86_l_2d4c;
	case 11602ULL: goto x86_l_2d52;
	case 11606ULL: goto x86_l_2d56;
	case 11608ULL: goto x86_l_2d58;
	case 11613ULL: goto x86_l_2d5d;
	case 11621ULL: goto x86_l_2d65;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11642ULL: goto x86_l_2d7a;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11663ULL: goto x86_l_2d8f;
	case 11671ULL: goto x86_l_2d97;
	case 11676ULL: goto x86_l_2d9c;
	case 11684ULL: goto x86_l_2da4;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11700ULL: goto x86_l_2db4;
	case 11705ULL: goto x86_l_2db9;
	case 11710ULL: goto x86_l_2dbe;
	case 11718ULL: goto x86_l_2dc6;
	case 11726ULL: goto x86_l_2dce;
	case 11730ULL: goto x86_l_2dd2;
	case 11736ULL: goto x86_l_2dd8;
	case 11741ULL: goto x86_l_2ddd;
	case 11744ULL: goto x86_l_2de0;
	case 11749ULL: goto x86_l_2de5;
	case 11753ULL: goto x86_l_2de9;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11772ULL: goto x86_l_2dfc;
	case 11780ULL: goto x86_l_2e04;
	case 11784ULL: goto x86_l_2e08;
	case 11790ULL: goto x86_l_2e0e;
	case 11795ULL: goto x86_l_2e13;
	case 11803ULL: goto x86_l_2e1b;
	case 11811ULL: goto x86_l_2e23;
	case 11815ULL: goto x86_l_2e27;
	case 11821ULL: goto x86_l_2e2d;
	case 11826ULL: goto x86_l_2e32;
	case 11834ULL: goto x86_l_2e3a;
	case 11842ULL: goto x86_l_2e42;
	case 11846ULL: goto x86_l_2e46;
	case 11852ULL: goto x86_l_2e4c;
	case 11857ULL: goto x86_l_2e51;
	case 11865ULL: goto x86_l_2e59;
	case 11870ULL: goto x86_l_2e5e;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11904ULL: goto x86_l_2e80;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11919ULL: goto x86_l_2e8f;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11937ULL: goto x86_l_2ea1;
	case 11942ULL: goto x86_l_2ea6;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11963ULL: goto x86_l_2ebb;
	case 11968ULL: goto x86_l_2ec0;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11989ULL: goto x86_l_2ed5;
	case 11994ULL: goto x86_l_2eda;
	case 12002ULL: goto x86_l_2ee2;
	case 12007ULL: goto x86_l_2ee7;
	case 12015ULL: goto x86_l_2eef;
	case 12020ULL: goto x86_l_2ef4;
	case 12028ULL: goto x86_l_2efc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29f4:
	/* 0x29f4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_29f7:
	/* 0x29f7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29f9:
	/* 0x29f9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_29fc:
	/* 0x29fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a01:
	/* 0x2a01: jmp    2b38 <generic_sleepable_preload+0x2b38> */
	goto x86_l_2b38;
x86_l_2a06:
	/* 0x2a06: mov    DWORD PTR [rsp+0x10],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476743ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2a16:
	/* 0x2a16: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2a1a:
	/* 0x2a1a: jne    d1 <generic_sleepable_preload+0xd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 209ULL;
	}
x86_l_2a20:
	/* 0x2a20: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a24:
	/* 0x2a24: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a29:
	/* 0x2a29: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2a2e:
	/* 0x2a2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a30:
	/* 0x2a30: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a35:
	/* 0x2a35: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2a3d:
	/* 0x2a3d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a42:
	/* 0x2a42: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2a49:
	/* 0x2a49: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2a4e:
	/* 0x2a4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a50:
	/* 0x2a50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a53:
	/* 0x2a53: je     d1 <generic_sleepable_preload+0xd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 209ULL;
	}
x86_l_2a59:
	/* 0x2a59: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2a5f:
	/* 0x2a5f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2a66:
	/* 0x2a66: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2a6e:
	/* 0x2a6e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2a71:
	/* 0x2a71: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a73:
	/* 0x2a73: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2a76:
	/* 0x2a76: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a7b:
	/* 0x2a7b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2a82:
	/* 0x2a82: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2a85:
	/* 0x2a85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a87:
	/* 0x2a87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a8a:
	/* 0x2a8a: je     d1 <generic_sleepable_preload+0xd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 209ULL;
	}
x86_l_2a90:
	/* 0x2a90: cmp    BYTE PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2a95:
	/* 0x2a95: je     2abb <generic_sleepable_preload+0x2abb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2abb;
	}
x86_l_2a97:
	/* 0x2a97: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a9a:
	/* 0x2a9a: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2a9e:
	/* 0x2a9e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2aa3:
	/* 0x2aa3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aa8:
	/* 0x2aa8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aaa:
	/* 0x2aaa: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2aad:
	/* 0x2aad: call   2ab2 <generic_sleepable_preload+0x2ab2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2ab2:
	/* 0x2ab2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2ab4:
	/* 0x2ab4: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2ab7:
	/* 0x2ab7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2ab9:
	/* 0x2ab9: js     2ac6 <generic_sleepable_preload+0x2ac6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ac6;
	}
x86_l_2abb:
	/* 0x2abb: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2abf:
	/* 0x2abf: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac1:
	/* 0x2ac1: jmp    d1 <generic_sleepable_preload+0xd1> */
	return 209ULL;
x86_l_2ac6:
	/* 0x2ac6: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2acb:
	/* 0x2acb: jmp    2abf <generic_sleepable_preload+0x2abf> */
	goto x86_l_2abf;
x86_l_2acd:
	/* 0x2acd: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_2ad2:
	/* 0x2ad2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ad5:
	/* 0x2ad5: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_2ad9:
	/* 0x2ad9: jne    105 <generic_sleepable_preload+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 261ULL;
	}
x86_l_2adf:
	/* 0x2adf: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae3:
	/* 0x2ae3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ae8:
	/* 0x2ae8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aea:
	/* 0x2aea: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aef:
	/* 0x2aef: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2af7:
	/* 0x2af7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2afc:
	/* 0x2afc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2b03:
	/* 0x2b03: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2b08:
	/* 0x2b08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0a:
	/* 0x2b0a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b0d:
	/* 0x2b0d: je     105 <generic_sleepable_preload+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 261ULL;
	}
x86_l_2b13:
	/* 0x2b13: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2b19:
	/* 0x2b19: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2b20:
	/* 0x2b20: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b25:
	/* 0x2b25: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2b28:
	/* 0x2b28: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2b2b:
	/* 0x2b2b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2b2e:
	/* 0x2b2e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b30:
	/* 0x2b30: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2b33:
	/* 0x2b33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b38:
	/* 0x2b38: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2b3b:
	/* 0x2b3b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2b3e:
	/* 0x2b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b40:
	/* 0x2b40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b43:
	/* 0x2b43: je     105 <generic_sleepable_preload+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 261ULL;
	}
x86_l_2b49:
	/* 0x2b49: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_2b4c:
	/* 0x2b4c: je     2b76 <generic_sleepable_preload+0x2b76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b76;
	}
x86_l_2b4e:
	/* 0x2b4e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2b51:
	/* 0x2b51: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2b55:
	/* 0x2b55: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b5a:
	/* 0x2b5a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2b5d:
	/* 0x2b5d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b5f:
	/* 0x2b5f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2b62:
	/* 0x2b62: call   2b67 <generic_sleepable_preload+0x2b67> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2b67:
	/* 0x2b67: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2b69:
	/* 0x2b69: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_2b6c:
	/* 0x2b6c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2b6e:
	/* 0x2b6e: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2b73:
	/* 0x2b73: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2b76:
	/* 0x2b76: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b78:
	/* 0x2b78: jmp    105 <generic_sleepable_preload+0x105> */
	return 261ULL;
x86_l_2b7d:
	/* 0x2b7d: mov    DWORD PTR [rsp+0xc],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607559ULL);
x86_l_2b85:
	/* 0x2b85: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b8d:
	/* 0x2b8d: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2b91:
	/* 0x2b91: jne    db <generic_sleepable_preload+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 219ULL;
	}
x86_l_2b97:
	/* 0x2b97: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ba5:
	/* 0x2ba5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba7:
	/* 0x2ba7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bac:
	/* 0x2bac: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2bb4:
	/* 0x2bb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bb9:
	/* 0x2bb9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2bc0:
	/* 0x2bc0: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2bc5:
	/* 0x2bc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc7:
	/* 0x2bc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bca:
	/* 0x2bca: je     db <generic_sleepable_preload+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 219ULL;
	}
x86_l_2bd0:
	/* 0x2bd0: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2bdd:
	/* 0x2bdd: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2be2:
	/* 0x2be2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2be5:
	/* 0x2be5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2be8:
	/* 0x2be8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bea:
	/* 0x2bea: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2bed:
	/* 0x2bed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bf2:
	/* 0x2bf2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2bf9:
	/* 0x2bf9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2bfc:
	/* 0x2bfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bfe:
	/* 0x2bfe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c01:
	/* 0x2c01: je     db <generic_sleepable_preload+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 219ULL;
	}
x86_l_2c07:
	/* 0x2c07: cmp    BYTE PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c0c:
	/* 0x2c0c: jne    2793 <generic_sleepable_preload+0x2793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10131ULL;
	}
x86_l_2c12:
	/* 0x2c12: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c16:
	/* 0x2c16: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c18:
	/* 0x2c18: jmp    db <generic_sleepable_preload+0xdb> */
	return 219ULL;
x86_l_2c1d:
	/* 0x2c1d: mov    DWORD PTR [rsp+0xc],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607559ULL);
x86_l_2c25:
	/* 0x2c25: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c2d:
	/* 0x2c2d: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2c31:
	/* 0x2c31: jne    e9 <generic_sleepable_preload+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 233ULL;
	}
x86_l_2c37:
	/* 0x2c37: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c3b:
	/* 0x2c3b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c40:
	/* 0x2c40: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c45:
	/* 0x2c45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c47:
	/* 0x2c47: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2c54:
	/* 0x2c54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c59:
	/* 0x2c59: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2c60:
	/* 0x2c60: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2c65:
	/* 0x2c65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c67:
	/* 0x2c67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c6a:
	/* 0x2c6a: je     e9 <generic_sleepable_preload+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 233ULL;
	}
x86_l_2c70:
	/* 0x2c70: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2c76:
	/* 0x2c76: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2c7d:
	/* 0x2c7d: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c82:
	/* 0x2c82: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2c85:
	/* 0x2c85: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2c88:
	/* 0x2c88: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c8a:
	/* 0x2c8a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2c8d:
	/* 0x2c8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c92:
	/* 0x2c92: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2c99:
	/* 0x2c99: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2c9c:
	/* 0x2c9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9e:
	/* 0x2c9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca1:
	/* 0x2ca1: je     e9 <generic_sleepable_preload+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 233ULL;
	}
x86_l_2ca7:
	/* 0x2ca7: cmp    BYTE PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2cac:
	/* 0x2cac: jne    2871 <generic_sleepable_preload+0x2871> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10353ULL;
	}
x86_l_2cb2:
	/* 0x2cb2: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cb8:
	/* 0x2cb8: jmp    e9 <generic_sleepable_preload+0xe9> */
	return 233ULL;
x86_l_2cbd:
	/* 0x2cbd: mov    DWORD PTR [rsp+0xc],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607559ULL);
x86_l_2cc5:
	/* 0x2cc5: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ccd:
	/* 0x2ccd: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2cd1:
	/* 0x2cd1: jne    f7 <generic_sleepable_preload+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 247ULL;
	}
x86_l_2cd7:
	/* 0x2cd7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cdb:
	/* 0x2cdb: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ce0:
	/* 0x2ce0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ce5:
	/* 0x2ce5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce7:
	/* 0x2ce7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cec:
	/* 0x2cec: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cf9:
	/* 0x2cf9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d00:
	/* 0x2d00: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d05:
	/* 0x2d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d07:
	/* 0x2d07: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d0a:
	/* 0x2d0a: je     f7 <generic_sleepable_preload+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 247ULL;
	}
x86_l_2d10:
	/* 0x2d10: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2d16:
	/* 0x2d16: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2d1d:
	/* 0x2d1d: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d22:
	/* 0x2d22: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2d25:
	/* 0x2d25: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d28:
	/* 0x2d28: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d2a:
	/* 0x2d2a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2d2d:
	/* 0x2d2d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d32:
	/* 0x2d32: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2d39:
	/* 0x2d39: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2d3c:
	/* 0x2d3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3e:
	/* 0x2d3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d41:
	/* 0x2d41: je     f7 <generic_sleepable_preload+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 247ULL;
	}
x86_l_2d47:
	/* 0x2d47: cmp    BYTE PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d4c:
	/* 0x2d4c: jne    294f <generic_sleepable_preload+0x294f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10575ULL;
	}
x86_l_2d52:
	/* 0x2d52: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2d56:
	/* 0x2d56: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d58:
	/* 0x2d58: jmp    f7 <generic_sleepable_preload+0xf7> */
	return 247ULL;
x86_l_2d5d:
	/* 0x2d5d: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2d65:
	/* 0x2d65: mov    DWORD PTR [rsp+0x10],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476744ULL);
x86_l_2d6d:
	/* 0x2d6d: jmp    2648 <generic_sleepable_preload+0x2648> */
	return 9800ULL;
x86_l_2d72:
	/* 0x2d72: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d7a:
	/* 0x2d7a: mov    DWORD PTR [rsp+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_2d82:
	/* 0x2d82: jmp    26f8 <generic_sleepable_preload+0x26f8> */
	return 9976ULL;
x86_l_2d87:
	/* 0x2d87: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d8f:
	/* 0x2d8f: mov    DWORD PTR [rsp+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_2d97:
	/* 0x2d97: jmp    27d6 <generic_sleepable_preload+0x27d6> */
	return 10198ULL;
x86_l_2d9c:
	/* 0x2d9c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2da4:
	/* 0x2da4: mov    DWORD PTR [rsp+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_2dac:
	/* 0x2dac: jmp    28b4 <generic_sleepable_preload+0x28b4> */
	return 10420ULL;
x86_l_2db1:
	/* 0x2db1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2db4:
	/* 0x2db4: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_2db9:
	/* 0x2db9: jmp    298a <generic_sleepable_preload+0x298a> */
	return 10634ULL;
x86_l_2dbe:
	/* 0x2dbe: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2dc6:
	/* 0x2dc6: mov    DWORD PTR [rsp+0x10],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476744ULL);
x86_l_2dce:
	/* 0x2dce: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2dd2:
	/* 0x2dd2: jne    d1 <generic_sleepable_preload+0xd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 209ULL;
	}
x86_l_2dd8:
	/* 0x2dd8: jmp    2a20 <generic_sleepable_preload+0x2a20> */
	goto x86_l_2a20;
x86_l_2ddd:
	/* 0x2ddd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de0:
	/* 0x2de0: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_2de5:
	/* 0x2de5: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_2de9:
	/* 0x2de9: jne    105 <generic_sleepable_preload+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 261ULL;
	}
x86_l_2def:
	/* 0x2def: jmp    2adf <generic_sleepable_preload+0x2adf> */
	goto x86_l_2adf;
x86_l_2df4:
	/* 0x2df4: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    DWORD PTR [rsp+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_2e04:
	/* 0x2e04: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2e08:
	/* 0x2e08: jne    db <generic_sleepable_preload+0xdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 219ULL;
	}
x86_l_2e0e:
	/* 0x2e0e: jmp    2b97 <generic_sleepable_preload+0x2b97> */
	goto x86_l_2b97;
x86_l_2e13:
	/* 0x2e13: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e1b:
	/* 0x2e1b: mov    DWORD PTR [rsp+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_2e23:
	/* 0x2e23: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2e27:
	/* 0x2e27: jne    e9 <generic_sleepable_preload+0xe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 233ULL;
	}
x86_l_2e2d:
	/* 0x2e2d: jmp    2c37 <generic_sleepable_preload+0x2c37> */
	goto x86_l_2c37;
x86_l_2e32:
	/* 0x2e32: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e3a:
	/* 0x2e3a: mov    DWORD PTR [rsp+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_2e42:
	/* 0x2e42: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2e46:
	/* 0x2e46: jne    f7 <generic_sleepable_preload+0xf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 247ULL;
	}
x86_l_2e4c:
	/* 0x2e4c: jmp    2cd7 <generic_sleepable_preload+0x2cd7> */
	goto x86_l_2cd7;
x86_l_2e51:
	/* 0x2e51: mov    DWORD PTR [rsp+0x10],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476745ULL);
x86_l_2e59:
	/* 0x2e59: jmp    2640 <generic_sleepable_preload+0x2640> */
	return 9792ULL;
x86_l_2e5e:
	/* 0x2e5e: mov    DWORD PTR [rsp+0xc],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607561ULL);
x86_l_2e66:
	/* 0x2e66: jmp    26f0 <generic_sleepable_preload+0x26f0> */
	return 9968ULL;
x86_l_2e6b:
	/* 0x2e6b: mov    DWORD PTR [rsp+0xc],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607561ULL);
x86_l_2e73:
	/* 0x2e73: jmp    27ce <generic_sleepable_preload+0x27ce> */
	return 10190ULL;
x86_l_2e78:
	/* 0x2e78: mov    DWORD PTR [rsp+0xc],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607561ULL);
x86_l_2e80:
	/* 0x2e80: jmp    28ac <generic_sleepable_preload+0x28ac> */
	return 10412ULL;
x86_l_2e85:
	/* 0x2e85: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_2e8a:
	/* 0x2e8a: jmp    2987 <generic_sleepable_preload+0x2987> */
	return 10631ULL;
x86_l_2e8f:
	/* 0x2e8f: mov    DWORD PTR [rsp+0x10],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476745ULL);
x86_l_2e97:
	/* 0x2e97: jmp    2a0e <generic_sleepable_preload+0x2a0e> */
	goto x86_l_2a0e;
x86_l_2e9c:
	/* 0x2e9c: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_2ea1:
	/* 0x2ea1: jmp    2ad2 <generic_sleepable_preload+0x2ad2> */
	goto x86_l_2ad2;
x86_l_2ea6:
	/* 0x2ea6: mov    DWORD PTR [rsp+0xc],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607561ULL);
x86_l_2eae:
	/* 0x2eae: jmp    2b85 <generic_sleepable_preload+0x2b85> */
	goto x86_l_2b85;
x86_l_2eb3:
	/* 0x2eb3: mov    DWORD PTR [rsp+0xc],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607561ULL);
x86_l_2ebb:
	/* 0x2ebb: jmp    2c25 <generic_sleepable_preload+0x2c25> */
	goto x86_l_2c25;
x86_l_2ec0:
	/* 0x2ec0: mov    DWORD PTR [rsp+0xc],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607561ULL);
x86_l_2ec8:
	/* 0x2ec8: jmp    2cc5 <generic_sleepable_preload+0x2cc5> */
	goto x86_l_2cc5;
x86_l_2ecd:
	/* 0x2ecd: mov    DWORD PTR [rsp+0x10],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476746ULL);
x86_l_2ed5:
	/* 0x2ed5: jmp    2640 <generic_sleepable_preload+0x2640> */
	return 9792ULL;
x86_l_2eda:
	/* 0x2eda: mov    DWORD PTR [rsp+0xc],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607562ULL);
x86_l_2ee2:
	/* 0x2ee2: jmp    26f0 <generic_sleepable_preload+0x26f0> */
	return 9968ULL;
x86_l_2ee7:
	/* 0x2ee7: mov    DWORD PTR [rsp+0xc],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607562ULL);
x86_l_2eef:
	/* 0x2eef: jmp    27ce <generic_sleepable_preload+0x27ce> */
	return 10190ULL;
x86_l_2ef4:
	/* 0x2ef4: mov    DWORD PTR [rsp+0xc],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607562ULL);
x86_l_2efc:
	/* 0x2efc: jmp    28ac <generic_sleepable_preload+0x28ac> */
	return 10412ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10284U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1754ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1760ULL && __x86_pc <= 3518ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3524ULL && __x86_pc <= 5307ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5312ULL && __x86_pc <= 7059ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7064ULL && __x86_pc <= 8867ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8872ULL && __x86_pc <= 10737ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10740ULL && __x86_pc <= 12028ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

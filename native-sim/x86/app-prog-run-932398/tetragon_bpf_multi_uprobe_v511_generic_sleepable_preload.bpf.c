extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 15ULL: goto x86_l_f;
	case 20ULL: goto x86_l_14;
	case 22ULL: goto x86_l_16;
	case 29ULL: goto x86_l_1d;
	case 34ULL: goto x86_l_22;
	case 41ULL: goto x86_l_29;
	case 49ULL: goto x86_l_31;
	case 51ULL: goto x86_l_33;
	case 54ULL: goto x86_l_36;
	case 60ULL: goto x86_l_3c;
	case 63ULL: goto x86_l_3f;
	case 70ULL: goto x86_l_46;
	case 75ULL: goto x86_l_4b;
	case 82ULL: goto x86_l_52;
	case 87ULL: goto x86_l_57;
	case 94ULL: goto x86_l_5e;
	case 99ULL: goto x86_l_63;
	case 103ULL: goto x86_l_67;
	case 108ULL: goto x86_l_6c;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 121ULL: goto x86_l_79;
	case 126ULL: goto x86_l_7e;
	case 130ULL: goto x86_l_82;
	case 135ULL: goto x86_l_87;
	case 139ULL: goto x86_l_8b;
	case 147ULL: goto x86_l_93;
	case 151ULL: goto x86_l_97;
	case 156ULL: goto x86_l_9c;
	case 160ULL: goto x86_l_a0;
	case 168ULL: goto x86_l_a8;
	case 172ULL: goto x86_l_ac;
	case 177ULL: goto x86_l_b1;
	case 181ULL: goto x86_l_b5;
	case 189ULL: goto x86_l_bd;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 202ULL: goto x86_l_ca;
	case 210ULL: goto x86_l_d2;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 226ULL: goto x86_l_e2;
	case 234ULL: goto x86_l_ea;
	case 238ULL: goto x86_l_ee;
	case 243ULL: goto x86_l_f3;
	case 248ULL: goto x86_l_f8;
	case 254ULL: goto x86_l_fe;
	case 257ULL: goto x86_l_101;
	case 264ULL: goto x86_l_108;
	case 267ULL: goto x86_l_10b;
	case 269ULL: goto x86_l_10d;
	case 271ULL: goto x86_l_10f;
	case 276ULL: goto x86_l_114;
	case 279ULL: goto x86_l_117;
	case 283ULL: goto x86_l_11b;
	case 287ULL: goto x86_l_11f;
	case 293ULL: goto x86_l_125;
	case 298ULL: goto x86_l_12a;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 307ULL: goto x86_l_133;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 317ULL: goto x86_l_13d;
	case 323ULL: goto x86_l_143;
	case 326ULL: goto x86_l_146;
	case 332ULL: goto x86_l_14c;
	case 335ULL: goto x86_l_14f;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 350ULL: goto x86_l_15e;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 369ULL: goto x86_l_171;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 387ULL: goto x86_l_183;
	case 389ULL: goto x86_l_185;
	case 392ULL: goto x86_l_188;
	case 398ULL: goto x86_l_18e;
	case 401ULL: goto x86_l_191;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 435ULL: goto x86_l_1b3;
	case 440ULL: goto x86_l_1b8;
	case 443ULL: goto x86_l_1bb;
	case 449ULL: goto x86_l_1c1;
	case 454ULL: goto x86_l_1c6;
	case 459ULL: goto x86_l_1cb;
	case 462ULL: goto x86_l_1ce;
	case 464ULL: goto x86_l_1d0;
	case 467ULL: goto x86_l_1d3;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 480ULL: goto x86_l_1e0;
	case 486ULL: goto x86_l_1e6;
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
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 676ULL: goto x86_l_2a4;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 689ULL: goto x86_l_2b1;
	case 692ULL: goto x86_l_2b4;
	case 696ULL: goto x86_l_2b8;
	case 700ULL: goto x86_l_2bc;
	case 702ULL: goto x86_l_2be;
	case 708ULL: goto x86_l_2c4;
	case 711ULL: goto x86_l_2c7;
	case 713ULL: goto x86_l_2c9;
	case 718ULL: goto x86_l_2ce;
	case 722ULL: goto x86_l_2d2;
	case 725ULL: goto x86_l_2d5;
	case 730ULL: goto x86_l_2da;
	case 732ULL: goto x86_l_2dc;
	case 734ULL: goto x86_l_2de;
	case 740ULL: goto x86_l_2e4;
	case 745ULL: goto x86_l_2e9;
	case 751ULL: goto x86_l_2ef;
	case 754ULL: goto x86_l_2f2;
	case 758ULL: goto x86_l_2f6;
	case 763ULL: goto x86_l_2fb;
	case 765ULL: goto x86_l_2fd;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 777ULL: goto x86_l_309;
	case 782ULL: goto x86_l_30e;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 792ULL: goto x86_l_318;
	case 797ULL: goto x86_l_31d;
	case 803ULL: goto x86_l_323;
	case 806ULL: goto x86_l_326;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 817ULL: goto x86_l_331;
	case 822ULL: goto x86_l_336;
	case 826ULL: goto x86_l_33a;
	case 829ULL: goto x86_l_33d;
	case 834ULL: goto x86_l_342;
	case 836ULL: goto x86_l_344;
	case 838ULL: goto x86_l_346;
	case 844ULL: goto x86_l_34c;
	case 849ULL: goto x86_l_351;
	case 855ULL: goto x86_l_357;
	case 858ULL: goto x86_l_35a;
	case 862ULL: goto x86_l_35e;
	case 867ULL: goto x86_l_363;
	case 869ULL: goto x86_l_365;
	case 874ULL: goto x86_l_36a;
	case 878ULL: goto x86_l_36e;
	case 881ULL: goto x86_l_371;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 890ULL: goto x86_l_37a;
	case 896ULL: goto x86_l_380;
	case 901ULL: goto x86_l_385;
	case 907ULL: goto x86_l_38b;
	case 910ULL: goto x86_l_38e;
	case 914ULL: goto x86_l_392;
	case 919ULL: goto x86_l_397;
	case 921ULL: goto x86_l_399;
	case 926ULL: goto x86_l_39e;
	case 930ULL: goto x86_l_3a2;
	case 933ULL: goto x86_l_3a5;
	case 938ULL: goto x86_l_3aa;
	case 940ULL: goto x86_l_3ac;
	case 942ULL: goto x86_l_3ae;
	case 948ULL: goto x86_l_3b4;
	case 953ULL: goto x86_l_3b9;
	case 959ULL: goto x86_l_3bf;
	case 962ULL: goto x86_l_3c2;
	case 966ULL: goto x86_l_3c6;
	case 971ULL: goto x86_l_3cb;
	case 973ULL: goto x86_l_3cd;
	case 978ULL: goto x86_l_3d2;
	case 982ULL: goto x86_l_3d6;
	case 985ULL: goto x86_l_3d9;
	case 990ULL: goto x86_l_3de;
	case 992ULL: goto x86_l_3e0;
	case 994ULL: goto x86_l_3e2;
	case 1000ULL: goto x86_l_3e8;
	case 1005ULL: goto x86_l_3ed;
	case 1011ULL: goto x86_l_3f3;
	case 1014ULL: goto x86_l_3f6;
	case 1018ULL: goto x86_l_3fa;
	case 1023ULL: goto x86_l_3ff;
	case 1025ULL: goto x86_l_401;
	case 1030ULL: goto x86_l_406;
	case 1034ULL: goto x86_l_40a;
	case 1037ULL: goto x86_l_40d;
	case 1042ULL: goto x86_l_412;
	case 1044ULL: goto x86_l_414;
	case 1046ULL: goto x86_l_416;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1063ULL: goto x86_l_427;
	case 1066ULL: goto x86_l_42a;
	case 1070ULL: goto x86_l_42e;
	case 1075ULL: goto x86_l_433;
	case 1077ULL: goto x86_l_435;
	case 1082ULL: goto x86_l_43a;
	case 1086ULL: goto x86_l_43e;
	case 1089ULL: goto x86_l_441;
	case 1094ULL: goto x86_l_446;
	case 1096ULL: goto x86_l_448;
	case 1098ULL: goto x86_l_44a;
	case 1104ULL: goto x86_l_450;
	case 1109ULL: goto x86_l_455;
	case 1115ULL: goto x86_l_45b;
	case 1118ULL: goto x86_l_45e;
	case 1122ULL: goto x86_l_462;
	case 1127ULL: goto x86_l_467;
	case 1129ULL: goto x86_l_469;
	case 1134ULL: goto x86_l_46e;
	case 1138ULL: goto x86_l_472;
	case 1141ULL: goto x86_l_475;
	case 1146ULL: goto x86_l_47a;
	case 1148ULL: goto x86_l_47c;
	case 1150ULL: goto x86_l_47e;
	case 1156ULL: goto x86_l_484;
	case 1160ULL: goto x86_l_488;
	case 1166ULL: goto x86_l_48e;
	case 1169ULL: goto x86_l_491;
	case 1173ULL: goto x86_l_495;
	case 1178ULL: goto x86_l_49a;
	case 1184ULL: goto x86_l_4a0;
	case 1189ULL: goto x86_l_4a5;
	case 1194ULL: goto x86_l_4aa;
	case 1197ULL: goto x86_l_4ad;
	case 1199ULL: goto x86_l_4af;
	case 1204ULL: goto x86_l_4b4;
	case 1208ULL: goto x86_l_4b8;
	case 1211ULL: goto x86_l_4bb;
	case 1216ULL: goto x86_l_4c0;
	case 1218ULL: goto x86_l_4c2;
	case 1220ULL: goto x86_l_4c4;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1237ULL: goto x86_l_4d5;
	case 1240ULL: goto x86_l_4d8;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1251ULL: goto x86_l_4e3;
	case 1256ULL: goto x86_l_4e8;
	case 1260ULL: goto x86_l_4ec;
	case 1263ULL: goto x86_l_4ef;
	case 1268ULL: goto x86_l_4f4;
	case 1270ULL: goto x86_l_4f6;
	case 1272ULL: goto x86_l_4f8;
	case 1278ULL: goto x86_l_4fe;
	case 1283ULL: goto x86_l_503;
	case 1289ULL: goto x86_l_509;
	case 1292ULL: goto x86_l_50c;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1312ULL: goto x86_l_520;
	case 1315ULL: goto x86_l_523;
	case 1320ULL: goto x86_l_528;
	case 1322ULL: goto x86_l_52a;
	case 1324ULL: goto x86_l_52c;
	case 1330ULL: goto x86_l_532;
	case 1335ULL: goto x86_l_537;
	case 1341ULL: goto x86_l_53d;
	case 1344ULL: goto x86_l_540;
	case 1348ULL: goto x86_l_544;
	case 1353ULL: goto x86_l_549;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1364ULL: goto x86_l_554;
	case 1367ULL: goto x86_l_557;
	case 1372ULL: goto x86_l_55c;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1393ULL: goto x86_l_571;
	case 1396ULL: goto x86_l_574;
	case 1400ULL: goto x86_l_578;
	case 1405ULL: goto x86_l_57d;
	case 1407ULL: goto x86_l_57f;
	case 1412ULL: goto x86_l_584;
	case 1416ULL: goto x86_l_588;
	case 1419ULL: goto x86_l_58b;
	case 1424ULL: goto x86_l_590;
	case 1426ULL: goto x86_l_592;
	case 1428ULL: goto x86_l_594;
	case 1434ULL: goto x86_l_59a;
	case 1439ULL: goto x86_l_59f;
	case 1445ULL: goto x86_l_5a5;
	case 1448ULL: goto x86_l_5a8;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1459ULL: goto x86_l_5b3;
	case 1464ULL: goto x86_l_5b8;
	case 1468ULL: goto x86_l_5bc;
	case 1471ULL: goto x86_l_5bf;
	case 1476ULL: goto x86_l_5c4;
	case 1478ULL: goto x86_l_5c6;
	case 1480ULL: goto x86_l_5c8;
	case 1486ULL: goto x86_l_5ce;
	case 1491ULL: goto x86_l_5d3;
	case 1497ULL: goto x86_l_5d9;
	case 1500ULL: goto x86_l_5dc;
	case 1504ULL: goto x86_l_5e0;
	case 1509ULL: goto x86_l_5e5;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1520ULL: goto x86_l_5f0;
	case 1523ULL: goto x86_l_5f3;
	case 1528ULL: goto x86_l_5f8;
	case 1530ULL: goto x86_l_5fa;
	case 1532ULL: goto x86_l_5fc;
	case 1538ULL: goto x86_l_602;
	case 1543ULL: goto x86_l_607;
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1556ULL: goto x86_l_614;
	case 1561ULL: goto x86_l_619;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1572ULL: goto x86_l_624;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1582ULL: goto x86_l_62e;
	case 1584ULL: goto x86_l_630;
	case 1590ULL: goto x86_l_636;
	case 1595ULL: goto x86_l_63b;
	case 1601ULL: goto x86_l_641;
	case 1604ULL: goto x86_l_644;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1615ULL: goto x86_l_64f;
	case 1620ULL: goto x86_l_654;
	case 1624ULL: goto x86_l_658;
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
	/* 0xa: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_f:
	/* 0xf: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14:
	/* 0x14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0xb4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1d:
	/* 0x1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22:
	/* 0x22: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_29:
	/* 0x29: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_31:
	/* 0x31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33:
	/* 0x33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36:
	/* 0x36: je     3602 <generic_sleepable_preload+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13826ULL;
	}
x86_l_3c:
	/* 0x3c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_46:
	/* 0x46: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4b:
	/* 0x4b: lea    rdx,[rcx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_52:
	/* 0x52: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_57:
	/* 0x57: lea    rdx,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5e:
	/* 0x5e: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_63:
	/* 0x63: lea    rdx,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_67:
	/* 0x67: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6c:
	/* 0x6c: lea    rdx,[rcx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_75:
	/* 0x75: lea    rdx,[rcx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_79:
	/* 0x79: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e:
	/* 0x7e: lea    rdx,[rcx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_82:
	/* 0x82: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87:
	/* 0x87: lea    rdx,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8b:
	/* 0x8b: mov    QWORD PTR [rsp+0xa0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_93:
	/* 0x93: lea    rdx,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_97:
	/* 0x97: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9c:
	/* 0x9c: lea    rdx,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a0:
	/* 0xa0: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a8:
	/* 0xa8: lea    rdx,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ac:
	/* 0xac: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b1:
	/* 0xb1: lea    rdx,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_bd:
	/* 0xbd: lea    rdx,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c1:
	/* 0xc1: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c6:
	/* 0xc6: lea    rdx,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca:
	/* 0xca: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d2:
	/* 0xd2: lea    rdx,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6:
	/* 0xd6: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_db:
	/* 0xdb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de:
	/* 0xde: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ea:
	/* 0xea: lea    rdi,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee:
	/* 0xee: mov    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3:
	/* 0xf3: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f8:
	/* 0xf8: je     d97 <generic_sleepable_preload+0xd97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3479ULL;
	}
x86_l_fe:
	/* 0xfe: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_101:
	/* 0x101: add    rbx,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_108:
	/* 0x108: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b:
	/* 0x10b: jmp    125 <generic_sleepable_preload+0x125> */
	goto x86_l_125;
x86_l_10d:
	/* 0x10d: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f:
	/* 0x10f: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114:
	/* 0x114: inc    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_117:
	/* 0x117: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_11b:
	/* 0x11b: cmp    r14,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 5ULL);
x86_l_11f:
	/* 0x11f: je     3602 <generic_sleepable_preload+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13826ULL;
	}
x86_l_125:
	/* 0x125: mov    eax,DWORD PTR [r13+r14*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 24ULL);
x86_l_12a:
	/* 0x12a: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_12f:
	/* 0x12f: je     114 <generic_sleepable_preload+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_114;
	}
x86_l_131:
	/* 0x131: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_133:
	/* 0x133: js     168 <generic_sleepable_preload+0x168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_168;
	}
x86_l_135:
	/* 0x135: mov    ecx,DWORD PTR [r13+r14*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 64ULL);
x86_l_13a:
	/* 0x13a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13d:
	/* 0x13d: jle    1fe <generic_sleepable_preload+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1fe;
	}
x86_l_143:
	/* 0x143: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_146:
	/* 0x146: je     27a <generic_sleepable_preload+0x27a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a;
	}
x86_l_14c:
	/* 0x14c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_14f:
	/* 0x14f: je     281 <generic_sleepable_preload+0x281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_281;
	}
x86_l_155:
	/* 0x155: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_158:
	/* 0x158: jne    294 <generic_sleepable_preload+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_294;
	}
x86_l_15e:
	/* 0x15e: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_163:
	/* 0x163: jmp    28d <generic_sleepable_preload+0x28d> */
	goto x86_l_28d;
x86_l_168:
	/* 0x168: movzx  eax,BYTE PTR [r13+r14*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_8), 706ULL);
x86_l_171:
	/* 0x171: movzx  ecx,WORD PTR [r13+r14*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_16), 704ULL);
x86_l_17a:
	/* 0x17a: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_180:
	/* 0x180: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_183:
	/* 0x183: jle    1cb <generic_sleepable_preload+0x1cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1cb;
	}
x86_l_185:
	/* 0x185: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_188:
	/* 0x188: jle    216 <generic_sleepable_preload+0x216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_216;
	}
x86_l_18e:
	/* 0x18e: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_191:
	/* 0x191: jle    70f <generic_sleepable_preload+0x70f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1807ULL;
	}
x86_l_197:
	/* 0x197: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19c:
	/* 0x19c: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_19f:
	/* 0x19f: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1832ULL;
	}
x86_l_1a5:
	/* 0x1a5: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1aa:
	/* 0x1aa: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1ad:
	/* 0x1ad: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1832ULL;
	}
x86_l_1b3:
	/* 0x1b3: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1b8:
	/* 0x1b8: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1bb:
	/* 0x1bb: jne    73b <generic_sleepable_preload+0x73b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1851ULL;
	}
x86_l_1c1:
	/* 0x1c1: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c6:
	/* 0x1c6: jmp    728 <generic_sleepable_preload+0x728> */
	return 1832ULL;
x86_l_1cb:
	/* 0x1cb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1ce:
	/* 0x1ce: jg     248 <generic_sleepable_preload+0x248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_248;
	}
x86_l_1d0:
	/* 0x1d0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d3:
	/* 0x1d3: jg     6d3 <generic_sleepable_preload+0x6d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1747ULL;
	}
x86_l_1d9:
	/* 0x1d9: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1de:
	/* 0x1de: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e0:
	/* 0x1e0: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1832ULL;
	}
x86_l_1e6:
	/* 0x1e6: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1eb:
	/* 0x1eb: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1f0:
	/* 0x1f0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f3:
	/* 0x1f3: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1832ULL;
	}
x86_l_1f9:
	/* 0x1f9: jmp    73b <generic_sleepable_preload+0x73b> */
	return 1851ULL;
x86_l_1fe:
	/* 0x1fe: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_200:
	/* 0x200: je     288 <generic_sleepable_preload+0x288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_288;
	}
x86_l_206:
	/* 0x206: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
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
	/* 0x219: jg     6b5 <generic_sleepable_preload+0x6b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1717ULL;
	}
x86_l_21f:
	/* 0x21f: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_227:
	/* 0x227: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22a:
	/* 0x22a: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1832ULL;
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
	/* 0x23d: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1832ULL;
	}
x86_l_243:
	/* 0x243: jmp    73b <generic_sleepable_preload+0x73b> */
	return 1851ULL;
x86_l_248:
	/* 0x248: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_24b:
	/* 0x24b: jg     6f1 <generic_sleepable_preload+0x6f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1777ULL;
	}
x86_l_251:
	/* 0x251: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_259:
	/* 0x259: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_25c:
	/* 0x25c: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1832ULL;
	}
x86_l_262:
	/* 0x262: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_267:
	/* 0x267: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_26c:
	/* 0x26c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_26f:
	/* 0x26f: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1832ULL;
	}
x86_l_275:
	/* 0x275: jmp    73b <generic_sleepable_preload+0x73b> */
	return 1851ULL;
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
	/* 0x28d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_290:
	/* 0x290: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294:
	/* 0x294: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_296:
	/* 0x296: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_299:
	/* 0x299: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_29e:
	/* 0x29e: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_2a4:
	/* 0x2a4: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2ab:
	/* 0x2ab: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2ae:
	/* 0x2ae: mov    edx,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_2b1:
	/* 0x2b1: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b4:
	/* 0x2b4: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b8:
	/* 0x2b8: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_2bc:
	/* 0x2bc: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_2be:
	/* 0x2be: je     4aa <generic_sleepable_preload+0x4aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aa;
	}
x86_l_2c4:
	/* 0x2c4: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2c7:
	/* 0x2c7: je     2e4 <generic_sleepable_preload+0x2e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e4;
	}
x86_l_2c9:
	/* 0x2c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ce:
	/* 0x2ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d2:
	/* 0x2d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d5:
	/* 0x2d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2da:
	/* 0x2da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc:
	/* 0x2dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2de:
	/* 0x2de: js     6ab <generic_sleepable_preload+0x6ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1707ULL;
	}
x86_l_2e4:
	/* 0x2e4: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_2e9:
	/* 0x2e9: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_2ef:
	/* 0x2ef: mov    eax,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_2f2:
	/* 0x2f2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f6:
	/* 0x2f6: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_2fb:
	/* 0x2fb: je     318 <generic_sleepable_preload+0x318> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_318;
	}
x86_l_2fd:
	/* 0x2fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_302:
	/* 0x302: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_306:
	/* 0x306: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_309:
	/* 0x309: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30e:
	/* 0x30e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310:
	/* 0x310: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_312:
	/* 0x312: js     b68 <generic_sleepable_preload+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2920ULL;
	}
x86_l_318:
	/* 0x318: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_31d:
	/* 0x31d: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_323:
	/* 0x323: mov    eax,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_326:
	/* 0x326: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32a:
	/* 0x32a: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_32f:
	/* 0x32f: je     34c <generic_sleepable_preload+0x34c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34c;
	}
x86_l_331:
	/* 0x331: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_336:
	/* 0x336: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a:
	/* 0x33a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33d:
	/* 0x33d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_342:
	/* 0x342: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_344:
	/* 0x344: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_346:
	/* 0x346: js     b7a <generic_sleepable_preload+0xb7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2938ULL;
	}
x86_l_34c:
	/* 0x34c: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_351:
	/* 0x351: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_357:
	/* 0x357: mov    eax,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_35a:
	/* 0x35a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_35e:
	/* 0x35e: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_363:
	/* 0x363: je     380 <generic_sleepable_preload+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_380;
	}
x86_l_365:
	/* 0x365: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36a:
	/* 0x36a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36e:
	/* 0x36e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_371:
	/* 0x371: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_376:
	/* 0x376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_378:
	/* 0x378: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37a:
	/* 0x37a: js     b8c <generic_sleepable_preload+0xb8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2956ULL;
	}
x86_l_380:
	/* 0x380: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_385:
	/* 0x385: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_38b:
	/* 0x38b: mov    eax,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_38e:
	/* 0x38e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_392:
	/* 0x392: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_397:
	/* 0x397: je     3b4 <generic_sleepable_preload+0x3b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b4;
	}
x86_l_399:
	/* 0x399: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39e:
	/* 0x39e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a2:
	/* 0x3a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a5:
	/* 0x3a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aa:
	/* 0x3aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac:
	/* 0x3ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ae:
	/* 0x3ae: js     b9e <generic_sleepable_preload+0xb9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2974ULL;
	}
x86_l_3b4:
	/* 0x3b4: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_3b9:
	/* 0x3b9: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_3bf:
	/* 0x3bf: mov    eax,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_3c2:
	/* 0x3c2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3c6:
	/* 0x3c6: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_3cb:
	/* 0x3cb: je     3e8 <generic_sleepable_preload+0x3e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e8;
	}
x86_l_3cd:
	/* 0x3cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d2:
	/* 0x3d2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d6:
	/* 0x3d6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d9:
	/* 0x3d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3de:
	/* 0x3de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e0:
	/* 0x3e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e2:
	/* 0x3e2: js     bb0 <generic_sleepable_preload+0xbb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2992ULL;
	}
x86_l_3e8:
	/* 0x3e8: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_3ed:
	/* 0x3ed: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_3f3:
	/* 0x3f3: mov    eax,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_3f6:
	/* 0x3f6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3fa:
	/* 0x3fa: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_3ff:
	/* 0x3ff: je     41c <generic_sleepable_preload+0x41c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41c;
	}
x86_l_401:
	/* 0x401: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_406:
	/* 0x406: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40a:
	/* 0x40a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40d:
	/* 0x40d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_412:
	/* 0x412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414:
	/* 0x414: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_416:
	/* 0x416: js     bc2 <generic_sleepable_preload+0xbc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3010ULL;
	}
x86_l_41c:
	/* 0x41c: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_421:
	/* 0x421: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_427:
	/* 0x427: mov    eax,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_42a:
	/* 0x42a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42e:
	/* 0x42e: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_433:
	/* 0x433: je     450 <generic_sleepable_preload+0x450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_450;
	}
x86_l_435:
	/* 0x435: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43a:
	/* 0x43a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43e:
	/* 0x43e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_441:
	/* 0x441: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_446:
	/* 0x446: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_448:
	/* 0x448: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44a:
	/* 0x44a: js     d5e <generic_sleepable_preload+0xd5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3422ULL;
	}
x86_l_450:
	/* 0x450: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_455:
	/* 0x455: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_45b:
	/* 0x45b: mov    eax,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_45e:
	/* 0x45e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_462:
	/* 0x462: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_467:
	/* 0x467: je     484 <generic_sleepable_preload+0x484> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_484;
	}
x86_l_469:
	/* 0x469: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46e:
	/* 0x46e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_472:
	/* 0x472: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_475:
	/* 0x475: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47a:
	/* 0x47a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47c:
	/* 0x47c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47e:
	/* 0x47e: js     d82 <generic_sleepable_preload+0xd82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3458ULL;
	}
x86_l_484:
	/* 0x484: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_488:
	/* 0x488: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_48e:
	/* 0x48e: mov    eax,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_491:
	/* 0x491: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_495:
	/* 0x495: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_49a:
	/* 0x49a: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_4a0:
	/* 0x4a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a5:
	/* 0x4a5: jmp    68b <generic_sleepable_preload+0x68b> */
	return 1675ULL;
x86_l_4aa:
	/* 0x4aa: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4ad:
	/* 0x4ad: je     4ca <generic_sleepable_preload+0x4ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ca;
	}
x86_l_4af:
	/* 0x4af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b4:
	/* 0x4b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b8:
	/* 0x4b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4bb:
	/* 0x4bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c0:
	/* 0x4c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c2:
	/* 0x4c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c4:
	/* 0x4c4: js     6ab <generic_sleepable_preload+0x6ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1707ULL;
	}
x86_l_4ca:
	/* 0x4ca: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_4cf:
	/* 0x4cf: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_4d5:
	/* 0x4d5: mov    eax,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_4d8:
	/* 0x4d8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4dc:
	/* 0x4dc: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_4e1:
	/* 0x4e1: je     4fe <generic_sleepable_preload+0x4fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fe;
	}
x86_l_4e3:
	/* 0x4e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e8:
	/* 0x4e8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ec:
	/* 0x4ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ef:
	/* 0x4ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f4:
	/* 0x4f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f6:
	/* 0x4f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f8:
	/* 0x4f8: js     b68 <generic_sleepable_preload+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2920ULL;
	}
x86_l_4fe:
	/* 0x4fe: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_503:
	/* 0x503: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_509:
	/* 0x509: mov    eax,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_50c:
	/* 0x50c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_510:
	/* 0x510: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_515:
	/* 0x515: je     532 <generic_sleepable_preload+0x532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_532;
	}
x86_l_517:
	/* 0x517: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51c:
	/* 0x51c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_520:
	/* 0x520: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_523:
	/* 0x523: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_528:
	/* 0x528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52a:
	/* 0x52a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52c:
	/* 0x52c: js     b7a <generic_sleepable_preload+0xb7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2938ULL;
	}
x86_l_532:
	/* 0x532: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_537:
	/* 0x537: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_53d:
	/* 0x53d: mov    eax,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_540:
	/* 0x540: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_544:
	/* 0x544: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_549:
	/* 0x549: je     566 <generic_sleepable_preload+0x566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_566;
	}
x86_l_54b:
	/* 0x54b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_550:
	/* 0x550: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_554:
	/* 0x554: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x560: js     b8c <generic_sleepable_preload+0xb8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2956ULL;
	}
x86_l_566:
	/* 0x566: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_56b:
	/* 0x56b: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_571:
	/* 0x571: mov    eax,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_574:
	/* 0x574: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_578:
	/* 0x578: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_57d:
	/* 0x57d: je     59a <generic_sleepable_preload+0x59a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59a;
	}
x86_l_57f:
	/* 0x57f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_584:
	/* 0x584: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_588:
	/* 0x588: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58b:
	/* 0x58b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_590:
	/* 0x590: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_592:
	/* 0x592: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_594:
	/* 0x594: js     b9e <generic_sleepable_preload+0xb9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2974ULL;
	}
x86_l_59a:
	/* 0x59a: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_59f:
	/* 0x59f: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_5a5:
	/* 0x5a5: mov    eax,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_5a8:
	/* 0x5a8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5ac:
	/* 0x5ac: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_5b1:
	/* 0x5b1: je     5ce <generic_sleepable_preload+0x5ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ce;
	}
x86_l_5b3:
	/* 0x5b3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b8:
	/* 0x5b8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bc:
	/* 0x5bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5bf:
	/* 0x5bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c4:
	/* 0x5c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c6:
	/* 0x5c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c8:
	/* 0x5c8: js     bb0 <generic_sleepable_preload+0xbb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2992ULL;
	}
x86_l_5ce:
	/* 0x5ce: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_5d3:
	/* 0x5d3: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_5d9:
	/* 0x5d9: mov    eax,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_5dc:
	/* 0x5dc: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5e0:
	/* 0x5e0: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_5e5:
	/* 0x5e5: je     602 <generic_sleepable_preload+0x602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_602;
	}
x86_l_5e7:
	/* 0x5e7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ec:
	/* 0x5ec: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f0:
	/* 0x5f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f3:
	/* 0x5f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f8:
	/* 0x5f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fa:
	/* 0x5fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fc:
	/* 0x5fc: js     bc2 <generic_sleepable_preload+0xbc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3010ULL;
	}
x86_l_602:
	/* 0x602: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_607:
	/* 0x607: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_60d:
	/* 0x60d: mov    eax,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_610:
	/* 0x610: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_614:
	/* 0x614: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_619:
	/* 0x619: je     636 <generic_sleepable_preload+0x636> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_636;
	}
x86_l_61b:
	/* 0x61b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_620:
	/* 0x620: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_624:
	/* 0x624: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_627:
	/* 0x627: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62c:
	/* 0x62c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62e:
	/* 0x62e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_630:
	/* 0x630: js     d5e <generic_sleepable_preload+0xd5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3422ULL;
	}
x86_l_636:
	/* 0x636: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_63b:
	/* 0x63b: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3018ULL;
	}
x86_l_641:
	/* 0x641: mov    eax,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_644:
	/* 0x644: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_648:
	/* 0x648: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_64d:
	/* 0x64d: je     66a <generic_sleepable_preload+0x66a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1642ULL;
	}
x86_l_64f:
	/* 0x64f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_654:
	/* 0x654: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_658:
	/* 0x658: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
	return 1627ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1634ULL: goto x86_l_662;
	case 1636ULL: goto x86_l_664;
	case 1642ULL: goto x86_l_66a;
	case 1646ULL: goto x86_l_66e;
	case 1652ULL: goto x86_l_674;
	case 1655ULL: goto x86_l_677;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1679ULL: goto x86_l_68f;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1691ULL: goto x86_l_69b;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1725ULL: goto x86_l_6bd;
	case 1728ULL: goto x86_l_6c0;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1740ULL: goto x86_l_6cc;
	case 1743ULL: goto x86_l_6cf;
	case 1745ULL: goto x86_l_6d1;
	case 1747ULL: goto x86_l_6d3;
	case 1755ULL: goto x86_l_6db;
	case 1758ULL: goto x86_l_6de;
	case 1760ULL: goto x86_l_6e0;
	case 1765ULL: goto x86_l_6e5;
	case 1770ULL: goto x86_l_6ea;
	case 1773ULL: goto x86_l_6ed;
	case 1775ULL: goto x86_l_6ef;
	case 1777ULL: goto x86_l_6f1;
	case 1785ULL: goto x86_l_6f9;
	case 1788ULL: goto x86_l_6fc;
	case 1790ULL: goto x86_l_6fe;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1803ULL: goto x86_l_70b;
	case 1805ULL: goto x86_l_70d;
	case 1807ULL: goto x86_l_70f;
	case 1812ULL: goto x86_l_714;
	case 1815ULL: goto x86_l_717;
	case 1817ULL: goto x86_l_719;
	case 1822ULL: goto x86_l_71e;
	case 1827ULL: goto x86_l_723;
	case 1830ULL: goto x86_l_726;
	case 1832ULL: goto x86_l_728;
	case 1835ULL: goto x86_l_72b;
	case 1837ULL: goto x86_l_72d;
	case 1839ULL: goto x86_l_72f;
	case 1844ULL: goto x86_l_734;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1877ULL: goto x86_l_755;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1890ULL: goto x86_l_762;
	case 1893ULL: goto x86_l_765;
	case 1897ULL: goto x86_l_769;
	case 1901ULL: goto x86_l_76d;
	case 1903ULL: goto x86_l_76f;
	case 1909ULL: goto x86_l_775;
	case 1912ULL: goto x86_l_778;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1923ULL: goto x86_l_783;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1933ULL: goto x86_l_78d;
	case 1935ULL: goto x86_l_78f;
	case 1941ULL: goto x86_l_795;
	case 1946ULL: goto x86_l_79a;
	case 1952ULL: goto x86_l_7a0;
	case 1955ULL: goto x86_l_7a3;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1975ULL: goto x86_l_7b7;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1985ULL: goto x86_l_7c1;
	case 1987ULL: goto x86_l_7c3;
	case 1993ULL: goto x86_l_7c9;
	case 1998ULL: goto x86_l_7ce;
	case 2004ULL: goto x86_l_7d4;
	case 2007ULL: goto x86_l_7d7;
	case 2011ULL: goto x86_l_7db;
	case 2016ULL: goto x86_l_7e0;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2027ULL: goto x86_l_7eb;
	case 2030ULL: goto x86_l_7ee;
	case 2035ULL: goto x86_l_7f3;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2045ULL: goto x86_l_7fd;
	case 2050ULL: goto x86_l_802;
	case 2056ULL: goto x86_l_808;
	case 2059ULL: goto x86_l_80b;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2079ULL: goto x86_l_81f;
	case 2082ULL: goto x86_l_822;
	case 2087ULL: goto x86_l_827;
	case 2089ULL: goto x86_l_829;
	case 2091ULL: goto x86_l_82b;
	case 2097ULL: goto x86_l_831;
	case 2102ULL: goto x86_l_836;
	case 2108ULL: goto x86_l_83c;
	case 2111ULL: goto x86_l_83f;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2131ULL: goto x86_l_853;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2149ULL: goto x86_l_865;
	case 2154ULL: goto x86_l_86a;
	case 2160ULL: goto x86_l_870;
	case 2163ULL: goto x86_l_873;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2183ULL: goto x86_l_887;
	case 2186ULL: goto x86_l_88a;
	case 2191ULL: goto x86_l_88f;
	case 2193ULL: goto x86_l_891;
	case 2195ULL: goto x86_l_893;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2212ULL: goto x86_l_8a4;
	case 2215ULL: goto x86_l_8a7;
	case 2219ULL: goto x86_l_8ab;
	case 2224ULL: goto x86_l_8b0;
	case 2226ULL: goto x86_l_8b2;
	case 2231ULL: goto x86_l_8b7;
	case 2235ULL: goto x86_l_8bb;
	case 2238ULL: goto x86_l_8be;
	case 2243ULL: goto x86_l_8c3;
	case 2245ULL: goto x86_l_8c5;
	case 2247ULL: goto x86_l_8c7;
	case 2253ULL: goto x86_l_8cd;
	case 2258ULL: goto x86_l_8d2;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2271ULL: goto x86_l_8df;
	case 2276ULL: goto x86_l_8e4;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2287ULL: goto x86_l_8ef;
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2297ULL: goto x86_l_8f9;
	case 2299ULL: goto x86_l_8fb;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2316ULL: goto x86_l_90c;
	case 2319ULL: goto x86_l_90f;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2339ULL: goto x86_l_923;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2349ULL: goto x86_l_92d;
	case 2351ULL: goto x86_l_92f;
	case 2357ULL: goto x86_l_935;
	case 2361ULL: goto x86_l_939;
	case 2367ULL: goto x86_l_93f;
	case 2370ULL: goto x86_l_942;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2395ULL: goto x86_l_95b;
	case 2398ULL: goto x86_l_95e;
	case 2400ULL: goto x86_l_960;
	case 2405ULL: goto x86_l_965;
	case 2409ULL: goto x86_l_969;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2419ULL: goto x86_l_973;
	case 2421ULL: goto x86_l_975;
	case 2427ULL: goto x86_l_97b;
	case 2432ULL: goto x86_l_980;
	case 2438ULL: goto x86_l_986;
	case 2441ULL: goto x86_l_989;
	case 2445ULL: goto x86_l_98d;
	case 2450ULL: goto x86_l_992;
	case 2452ULL: goto x86_l_994;
	case 2457ULL: goto x86_l_999;
	case 2461ULL: goto x86_l_99d;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2479ULL: goto x86_l_9af;
	case 2484ULL: goto x86_l_9b4;
	case 2490ULL: goto x86_l_9ba;
	case 2493ULL: goto x86_l_9bd;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2513ULL: goto x86_l_9d1;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2523ULL: goto x86_l_9db;
	case 2525ULL: goto x86_l_9dd;
	case 2531ULL: goto x86_l_9e3;
	case 2536ULL: goto x86_l_9e8;
	case 2542ULL: goto x86_l_9ee;
	case 2545ULL: goto x86_l_9f1;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2556ULL: goto x86_l_9fc;
	case 2561ULL: goto x86_l_a01;
	case 2565ULL: goto x86_l_a05;
	case 2568ULL: goto x86_l_a08;
	case 2573ULL: goto x86_l_a0d;
	case 2575ULL: goto x86_l_a0f;
	case 2577ULL: goto x86_l_a11;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2594ULL: goto x86_l_a22;
	case 2597ULL: goto x86_l_a25;
	case 2601ULL: goto x86_l_a29;
	case 2606ULL: goto x86_l_a2e;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2617ULL: goto x86_l_a39;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2627ULL: goto x86_l_a43;
	case 2629ULL: goto x86_l_a45;
	case 2635ULL: goto x86_l_a4b;
	case 2640ULL: goto x86_l_a50;
	case 2646ULL: goto x86_l_a56;
	case 2649ULL: goto x86_l_a59;
	case 2653ULL: goto x86_l_a5d;
	case 2658ULL: goto x86_l_a62;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2669ULL: goto x86_l_a6d;
	case 2672ULL: goto x86_l_a70;
	case 2677ULL: goto x86_l_a75;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2687ULL: goto x86_l_a7f;
	case 2692ULL: goto x86_l_a84;
	case 2698ULL: goto x86_l_a8a;
	case 2701ULL: goto x86_l_a8d;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2721ULL: goto x86_l_aa1;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2731ULL: goto x86_l_aab;
	case 2733ULL: goto x86_l_aad;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2750ULL: goto x86_l_abe;
	case 2753ULL: goto x86_l_ac1;
	case 2757ULL: goto x86_l_ac5;
	case 2762ULL: goto x86_l_aca;
	case 2764ULL: goto x86_l_acc;
	case 2769ULL: goto x86_l_ad1;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2783ULL: goto x86_l_adf;
	case 2785ULL: goto x86_l_ae1;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2802ULL: goto x86_l_af2;
	case 2805ULL: goto x86_l_af5;
	case 2809ULL: goto x86_l_af9;
	case 2814ULL: goto x86_l_afe;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2825ULL: goto x86_l_b09;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2835ULL: goto x86_l_b13;
	case 2837ULL: goto x86_l_b15;
	case 2843ULL: goto x86_l_b1b;
	case 2847ULL: goto x86_l_b1f;
	case 2853ULL: goto x86_l_b25;
	case 2856ULL: goto x86_l_b28;
	case 2860ULL: goto x86_l_b2c;
	case 2865ULL: goto x86_l_b31;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2890ULL: goto x86_l_b4a;
	case 2892ULL: goto x86_l_b4c;
	case 2898ULL: goto x86_l_b52;
	case 2904ULL: goto x86_l_b58;
	case 2909ULL: goto x86_l_b5d;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2927ULL: goto x86_l_b6f;
	case 2933ULL: goto x86_l_b75;
	case 2938ULL: goto x86_l_b7a;
	case 2943ULL: goto x86_l_b7f;
	case 2945ULL: goto x86_l_b81;
	case 2951ULL: goto x86_l_b87;
	case 2956ULL: goto x86_l_b8c;
	case 2961ULL: goto x86_l_b91;
	case 2963ULL: goto x86_l_b93;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2981ULL: goto x86_l_ba5;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 2999ULL: goto x86_l_bb7;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3018ULL: goto x86_l_bca;
	case 3023ULL: goto x86_l_bcf;
	case 3028ULL: goto x86_l_bd4;
	case 3031ULL: goto x86_l_bd7;
	case 3036ULL: goto x86_l_bdc;
	case 3039ULL: goto x86_l_bdf;
	case 3041ULL: goto x86_l_be1;
	case 3045ULL: goto x86_l_be5;
	case 3051ULL: goto x86_l_beb;
	case 3055ULL: goto x86_l_bef;
	case 3063ULL: goto x86_l_bf7;
	case 3068ULL: goto x86_l_bfc;
	case 3070ULL: goto x86_l_bfe;
	case 3075ULL: goto x86_l_c03;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3095ULL: goto x86_l_c17;
	case 3100ULL: goto x86_l_c1c;
	case 3102ULL: goto x86_l_c1e;
	case 3105ULL: goto x86_l_c21;
	case 3111ULL: goto x86_l_c27;
	case 3117ULL: goto x86_l_c2d;
	case 3124ULL: goto x86_l_c34;
	case 3127ULL: goto x86_l_c37;
	case 3130ULL: goto x86_l_c3a;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3146ULL: goto x86_l_c4a;
	case 3149ULL: goto x86_l_c4d;
	case 3154ULL: goto x86_l_c52;
	case 3157ULL: goto x86_l_c55;
	case 3160ULL: goto x86_l_c58;
	case 3163ULL: goto x86_l_c5b;
	case 3165ULL: goto x86_l_c5d;
	case 3168ULL: goto x86_l_c60;
	case 3174ULL: goto x86_l_c66;
	case 3177ULL: goto x86_l_c69;
	default: return 0xffffffffffffffffULL;
	}
x86_l_65b:
	/* 0x65b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_660:
	/* 0x660: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_662:
	/* 0x662: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_664:
	/* 0x664: js     d82 <generic_sleepable_preload+0xd82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3458ULL;
	}
x86_l_66a:
	/* 0x66a: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66e:
	/* 0x66e: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bca;
	}
x86_l_674:
	/* 0x674: mov    eax,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_677:
	/* 0x677: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_67b:
	/* 0x67b: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_680:
	/* 0x680: je     bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bca;
	}
x86_l_686:
	/* 0x686: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_68b:
	/* 0x68b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68f:
	/* 0x68f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_692:
	/* 0x692: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_697:
	/* 0x697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_699:
	/* 0x699: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_69b:
	/* 0x69b: jns    bca <generic_sleepable_preload+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_bca;
	}
x86_l_6a1:
	/* 0x6a1: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_6a6:
	/* 0x6a6: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	goto x86_l_bc7;
x86_l_6ab:
	/* 0x6ab: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6b0:
	/* 0x6b0: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	goto x86_l_bc7;
x86_l_6b5:
	/* 0x6b5: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6bd:
	/* 0x6bd: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_6c0:
	/* 0x6c0: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_6c2:
	/* 0x6c2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c7:
	/* 0x6c7: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_6cc:
	/* 0x6cc: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_6cf:
	/* 0x6cf: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_6d1:
	/* 0x6d1: jmp    73b <generic_sleepable_preload+0x73b> */
	goto x86_l_73b;
x86_l_6d3:
	/* 0x6d3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6db:
	/* 0x6db: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6de:
	/* 0x6de: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_6e0:
	/* 0x6e0: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e5:
	/* 0x6e5: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_6ea:
	/* 0x6ea: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_6ed:
	/* 0x6ed: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_6ef:
	/* 0x6ef: jmp    73b <generic_sleepable_preload+0x73b> */
	goto x86_l_73b;
x86_l_6f1:
	/* 0x6f1: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6f9:
	/* 0x6f9: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6fc:
	/* 0x6fc: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_6fe:
	/* 0x6fe: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_703:
	/* 0x703: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_708:
	/* 0x708: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_70b:
	/* 0x70b: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_70d:
	/* 0x70d: jmp    73b <generic_sleepable_preload+0x73b> */
	goto x86_l_73b;
x86_l_70f:
	/* 0x70f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_714:
	/* 0x714: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_717:
	/* 0x717: je     728 <generic_sleepable_preload+0x728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_728;
	}
x86_l_719:
	/* 0x719: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_71e:
	/* 0x71e: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_723:
	/* 0x723: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_726:
	/* 0x726: jne    73b <generic_sleepable_preload+0x73b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_73b;
	}
x86_l_728:
	/* 0x728: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_72b:
	/* 0x72b: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_72d:
	/* 0x72d: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_72f:
	/* 0x72f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_734:
	/* 0x734: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_736:
	/* 0x736: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_73b:
	/* 0x73b: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73f:
	/* 0x73f: mov    ebp,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_744:
	/* 0x744: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_747:
	/* 0x747: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_74a:
	/* 0x74a: cmp    WORD PTR [rbx-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743764471906304ULL);
x86_l_74f:
	/* 0x74f: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_755:
	/* 0x755: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_75c:
	/* 0x75c: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_75f:
	/* 0x75f: mov    eax,DWORD PTR [rbx-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551538ULL);
x86_l_762:
	/* 0x762: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_765:
	/* 0x765: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_769:
	/* 0x769: movzx  eax,WORD PTR [rbx-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_76d:
	/* 0x76d: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_76f:
	/* 0x76f: je     95b <generic_sleepable_preload+0x95b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_95b;
	}
x86_l_775:
	/* 0x775: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_778:
	/* 0x778: je     795 <generic_sleepable_preload+0x795> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_795;
	}
x86_l_77a:
	/* 0x77a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_77f:
	/* 0x77f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_783:
	/* 0x783: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_786:
	/* 0x786: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_78b:
	/* 0x78b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78d:
	/* 0x78d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_78f:
	/* 0x78f: js     b5d <generic_sleepable_preload+0xb5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b5d;
	}
x86_l_795:
	/* 0x795: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_79a:
	/* 0x79a: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_7a0:
	/* 0x7a0: mov    eax,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_7a3:
	/* 0x7a3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7a7:
	/* 0x7a7: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_7ac:
	/* 0x7ac: je     7c9 <generic_sleepable_preload+0x7c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7c9;
	}
x86_l_7ae:
	/* 0x7ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7b3:
	/* 0x7b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7b7:
	/* 0x7b7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7ba:
	/* 0x7ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7bf:
	/* 0x7bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c1:
	/* 0x7c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7c3:
	/* 0x7c3: js     b6f <generic_sleepable_preload+0xb6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b6f;
	}
x86_l_7c9:
	/* 0x7c9: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_7ce:
	/* 0x7ce: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_7d4:
	/* 0x7d4: mov    eax,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_7d7:
	/* 0x7d7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7db:
	/* 0x7db: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_7e0:
	/* 0x7e0: je     7fd <generic_sleepable_preload+0x7fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7fd;
	}
x86_l_7e2:
	/* 0x7e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7e7:
	/* 0x7e7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7eb:
	/* 0x7eb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7ee:
	/* 0x7ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f3:
	/* 0x7f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f5:
	/* 0x7f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7f7:
	/* 0x7f7: js     b81 <generic_sleepable_preload+0xb81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b81;
	}
x86_l_7fd:
	/* 0x7fd: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_802:
	/* 0x802: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_808:
	/* 0x808: mov    eax,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_80b:
	/* 0x80b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_80f:
	/* 0x80f: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_814:
	/* 0x814: je     831 <generic_sleepable_preload+0x831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_831;
	}
x86_l_816:
	/* 0x816: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_81b:
	/* 0x81b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81f:
	/* 0x81f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_822:
	/* 0x822: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_827:
	/* 0x827: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_829:
	/* 0x829: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_82b:
	/* 0x82b: js     b93 <generic_sleepable_preload+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b93;
	}
x86_l_831:
	/* 0x831: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_836:
	/* 0x836: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_83c:
	/* 0x83c: mov    eax,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_83f:
	/* 0x83f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_843:
	/* 0x843: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_848:
	/* 0x848: je     865 <generic_sleepable_preload+0x865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_865;
	}
x86_l_84a:
	/* 0x84a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_84f:
	/* 0x84f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_853:
	/* 0x853: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_856:
	/* 0x856: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_85b:
	/* 0x85b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85d:
	/* 0x85d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_85f:
	/* 0x85f: js     ba5 <generic_sleepable_preload+0xba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ba5;
	}
x86_l_865:
	/* 0x865: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_86a:
	/* 0x86a: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_870:
	/* 0x870: mov    eax,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_873:
	/* 0x873: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_877:
	/* 0x877: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_87c:
	/* 0x87c: je     899 <generic_sleepable_preload+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_899;
	}
x86_l_87e:
	/* 0x87e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_883:
	/* 0x883: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_887:
	/* 0x887: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_88a:
	/* 0x88a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_88f:
	/* 0x88f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_891:
	/* 0x891: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_893:
	/* 0x893: js     bb7 <generic_sleepable_preload+0xbb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_bb7;
	}
x86_l_899:
	/* 0x899: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_89e:
	/* 0x89e: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_8a4:
	/* 0x8a4: mov    eax,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_8a7:
	/* 0x8a7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8ab:
	/* 0x8ab: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
x86_l_8b0:
	/* 0x8b0: je     8cd <generic_sleepable_preload+0x8cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8cd;
	}
x86_l_8b2:
	/* 0x8b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8b7:
	/* 0x8b7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8bb:
	/* 0x8bb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8be:
	/* 0x8be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8c3:
	/* 0x8c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c5:
	/* 0x8c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8c7:
	/* 0x8c7: js     ca1 <generic_sleepable_preload+0xca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3233ULL;
	}
x86_l_8cd:
	/* 0x8cd: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_8d2:
	/* 0x8d2: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_8d8:
	/* 0x8d8: mov    eax,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_8db:
	/* 0x8db: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8df:
	/* 0x8df: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_8e4:
	/* 0x8e4: je     901 <generic_sleepable_preload+0x901> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_901;
	}
x86_l_8e6:
	/* 0x8e6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8eb:
	/* 0x8eb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ef:
	/* 0x8ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8f2:
	/* 0x8f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8f7:
	/* 0x8f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f9:
	/* 0x8f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8fb:
	/* 0x8fb: js     d6b <generic_sleepable_preload+0xd6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3435ULL;
	}
x86_l_901:
	/* 0x901: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_906:
	/* 0x906: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_90c:
	/* 0x90c: mov    eax,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_90f:
	/* 0x90f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_913:
	/* 0x913: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_918:
	/* 0x918: je     935 <generic_sleepable_preload+0x935> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_935;
	}
x86_l_91a:
	/* 0x91a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_91f:
	/* 0x91f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_923:
	/* 0x923: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_926:
	/* 0x926: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_92b:
	/* 0x92b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92d:
	/* 0x92d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92f:
	/* 0x92f: js     d8c <generic_sleepable_preload+0xd8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3468ULL;
	}
x86_l_935:
	/* 0x935: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_939:
	/* 0x939: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_93f:
	/* 0x93f: mov    eax,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_942:
	/* 0x942: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_946:
	/* 0x946: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_94b:
	/* 0x94b: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_951:
	/* 0x951: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_956:
	/* 0x956: jmp    b3c <generic_sleepable_preload+0xb3c> */
	goto x86_l_b3c;
x86_l_95b:
	/* 0x95b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_95e:
	/* 0x95e: je     97b <generic_sleepable_preload+0x97b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97b;
	}
x86_l_960:
	/* 0x960: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_965:
	/* 0x965: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_969:
	/* 0x969: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_96c:
	/* 0x96c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_971:
	/* 0x971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_973:
	/* 0x973: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_975:
	/* 0x975: js     b5d <generic_sleepable_preload+0xb5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b5d;
	}
x86_l_97b:
	/* 0x97b: cmp    WORD PTR [rbx-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743798831644672ULL);
x86_l_980:
	/* 0x980: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_986:
	/* 0x986: mov    eax,DWORD PTR [rbx-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551546ULL);
x86_l_989:
	/* 0x989: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_98d:
	/* 0x98d: cmp    WORD PTR [rbx-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743790241710080ULL);
x86_l_992:
	/* 0x992: je     9af <generic_sleepable_preload+0x9af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9af;
	}
x86_l_994:
	/* 0x994: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_999:
	/* 0x999: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99d:
	/* 0x99d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9a0:
	/* 0x9a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a5:
	/* 0x9a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a7:
	/* 0x9a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9a9:
	/* 0x9a9: js     b6f <generic_sleepable_preload+0xb6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b6f;
	}
x86_l_9af:
	/* 0x9af: cmp    WORD PTR [rbx-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743833191383040ULL);
x86_l_9b4:
	/* 0x9b4: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_9ba:
	/* 0x9ba: mov    eax,DWORD PTR [rbx-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551554ULL);
x86_l_9bd:
	/* 0x9bd: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9c1:
	/* 0x9c1: cmp    WORD PTR [rbx-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743824601448448ULL);
x86_l_9c6:
	/* 0x9c6: je     9e3 <generic_sleepable_preload+0x9e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e3;
	}
x86_l_9c8:
	/* 0x9c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9cd:
	/* 0x9cd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d1:
	/* 0x9d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9d4:
	/* 0x9d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d9:
	/* 0x9d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9db:
	/* 0x9db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9dd:
	/* 0x9dd: js     b81 <generic_sleepable_preload+0xb81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b81;
	}
x86_l_9e3:
	/* 0x9e3: cmp    WORD PTR [rbx-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743867551121408ULL);
x86_l_9e8:
	/* 0x9e8: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_9ee:
	/* 0x9ee: mov    eax,DWORD PTR [rbx-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551562ULL);
x86_l_9f1:
	/* 0x9f1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9f5:
	/* 0x9f5: cmp    WORD PTR [rbx-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743858961186816ULL);
x86_l_9fa:
	/* 0x9fa: je     a17 <generic_sleepable_preload+0xa17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a17;
	}
x86_l_9fc:
	/* 0x9fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a01:
	/* 0xa01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a05:
	/* 0xa05: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a08:
	/* 0xa08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0d:
	/* 0xa0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0f:
	/* 0xa0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a11:
	/* 0xa11: js     b93 <generic_sleepable_preload+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b93;
	}
x86_l_a17:
	/* 0xa17: cmp    WORD PTR [rbx-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743901910859776ULL);
x86_l_a1c:
	/* 0xa1c: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_a22:
	/* 0xa22: mov    eax,DWORD PTR [rbx-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551570ULL);
x86_l_a25:
	/* 0xa25: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a29:
	/* 0xa29: cmp    WORD PTR [rbx-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743893320925184ULL);
x86_l_a2e:
	/* 0xa2e: je     a4b <generic_sleepable_preload+0xa4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a4b;
	}
x86_l_a30:
	/* 0xa30: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a35:
	/* 0xa35: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a39:
	/* 0xa39: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a3c:
	/* 0xa3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a41:
	/* 0xa41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a43:
	/* 0xa43: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a45:
	/* 0xa45: js     ba5 <generic_sleepable_preload+0xba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ba5;
	}
x86_l_a4b:
	/* 0xa4b: cmp    WORD PTR [rbx-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743936270598144ULL);
x86_l_a50:
	/* 0xa50: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_a56:
	/* 0xa56: mov    eax,DWORD PTR [rbx-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_a59:
	/* 0xa59: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a5d:
	/* 0xa5d: cmp    WORD PTR [rbx-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743927680663552ULL);
x86_l_a62:
	/* 0xa62: je     a7f <generic_sleepable_preload+0xa7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7f;
	}
x86_l_a64:
	/* 0xa64: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a69:
	/* 0xa69: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a6d:
	/* 0xa6d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a70:
	/* 0xa70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a75:
	/* 0xa75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a77:
	/* 0xa77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a79:
	/* 0xa79: js     bb7 <generic_sleepable_preload+0xbb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_bb7;
	}
x86_l_a7f:
	/* 0xa7f: cmp    WORD PTR [rbx-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743970630336512ULL);
x86_l_a84:
	/* 0xa84: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_a8a:
	/* 0xa8a: mov    eax,DWORD PTR [rbx-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551586ULL);
x86_l_a8d:
	/* 0xa8d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a91:
	/* 0xa91: cmp    WORD PTR [rbx-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743962040401920ULL);
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
	/* 0xaad: js     ca1 <generic_sleepable_preload+0xca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3233ULL;
	}
x86_l_ab3:
	/* 0xab3: cmp    WORD PTR [rbx-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744004990074880ULL);
x86_l_ab8:
	/* 0xab8: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_abe:
	/* 0xabe: mov    eax,DWORD PTR [rbx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_ac1:
	/* 0xac1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ac5:
	/* 0xac5: cmp    WORD PTR [rbx-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140288ULL);
x86_l_aca:
	/* 0xaca: je     ae7 <generic_sleepable_preload+0xae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ae7;
	}
x86_l_acc:
	/* 0xacc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ad1:
	/* 0xad1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad5:
	/* 0xad5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_add:
	/* 0xadd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_adf:
	/* 0xadf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ae1:
	/* 0xae1: js     d6b <generic_sleepable_preload+0xd6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3435ULL;
	}
x86_l_ae7:
	/* 0xae7: cmp    WORD PTR [rbx-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744039349813248ULL);
x86_l_aec:
	/* 0xaec: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_af2:
	/* 0xaf2: mov    eax,DWORD PTR [rbx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551602ULL);
x86_l_af5:
	/* 0xaf5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_af9:
	/* 0xaf9: cmp    WORD PTR [rbx-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744030759878656ULL);
x86_l_afe:
	/* 0xafe: je     b1b <generic_sleepable_preload+0xb1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b1b;
	}
x86_l_b00:
	/* 0xb00: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b05:
	/* 0xb05: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b09:
	/* 0xb09: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b0c:
	/* 0xb0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b11:
	/* 0xb11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b13:
	/* 0xb13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b15:
	/* 0xb15: js     d8c <generic_sleepable_preload+0xd8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3468ULL;
	}
x86_l_b1b:
	/* 0xb1b: cmp    WORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1f:
	/* 0xb1f: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_b25:
	/* 0xb25: mov    eax,DWORD PTR [rbx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_b28:
	/* 0xb28: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b2c:
	/* 0xb2c: cmp    WORD PTR [rbx-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617024ULL);
x86_l_b31:
	/* 0xb31: je     caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3242ULL;
	}
x86_l_b37:
	/* 0xb37: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b3c:
	/* 0xb3c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b40:
	/* 0xb40: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b48:
	/* 0xb48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4a:
	/* 0xb4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b4c:
	/* 0xb4c: jns    caa <generic_sleepable_preload+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3242ULL;
	}
x86_l_b52:
	/* 0xb52: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_b58:
	/* 0xb58: jmp    ca7 <generic_sleepable_preload+0xca7> */
	return 3239ULL;
x86_l_b5d:
	/* 0xb5d: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_b63:
	/* 0xb63: jmp    ca7 <generic_sleepable_preload+0xca7> */
	return 3239ULL;
x86_l_b68:
	/* 0xb68: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_b6d:
	/* 0xb6d: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	goto x86_l_bc7;
x86_l_b6f:
	/* 0xb6f: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_b75:
	/* 0xb75: jmp    ca7 <generic_sleepable_preload+0xca7> */
	return 3239ULL;
x86_l_b7a:
	/* 0xb7a: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_b7f:
	/* 0xb7f: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	goto x86_l_bc7;
x86_l_b81:
	/* 0xb81: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_b87:
	/* 0xb87: jmp    ca7 <generic_sleepable_preload+0xca7> */
	return 3239ULL;
x86_l_b8c:
	/* 0xb8c: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_b91:
	/* 0xb91: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	goto x86_l_bc7;
x86_l_b93:
	/* 0xb93: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_b99:
	/* 0xb99: jmp    ca7 <generic_sleepable_preload+0xca7> */
	return 3239ULL;
x86_l_b9e:
	/* 0xb9e: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_ba3:
	/* 0xba3: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	goto x86_l_bc7;
x86_l_ba5:
	/* 0xba5: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_bab:
	/* 0xbab: jmp    ca7 <generic_sleepable_preload+0xca7> */
	return 3239ULL;
x86_l_bb0:
	/* 0xbb0: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_bb5:
	/* 0xbb5: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	goto x86_l_bc7;
x86_l_bb7:
	/* 0xbb7: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_bbd:
	/* 0xbbd: jmp    ca7 <generic_sleepable_preload+0xca7> */
	return 3239ULL;
x86_l_bc2:
	/* 0xbc2: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_bc7:
	/* 0xbc7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bca:
	/* 0xbca: mov    r12d,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_bcf:
	/* 0xbcf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd4:
	/* 0xbd4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bd7:
	/* 0xbd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bdc:
	/* 0xbdc: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_bdf:
	/* 0xbdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be1:
	/* 0xbe1: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_be5:
	/* 0xbe5: jne    114 <generic_sleepable_preload+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 276ULL;
	}
x86_l_beb:
	/* 0xbeb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bef:
	/* 0xbef: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bf7:
	/* 0xbf7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_bfc:
	/* 0xbfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfe:
	/* 0xbfe: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c03:
	/* 0xc03: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_c0b:
	/* 0xc0b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c10:
	/* 0xc10: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_c17:
	/* 0xc17: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c1c:
	/* 0xc1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1e:
	/* 0xc1e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c21:
	/* 0xc21: je     10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 271ULL;
	}
x86_l_c27:
	/* 0xc27: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_c2d:
	/* 0xc2d: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_c34:
	/* 0xc34: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c37:
	/* 0xc37: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_c3a:
	/* 0xc3a: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_c3d:
	/* 0xc3d: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c42:
	/* 0xc42: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_c45:
	/* 0xc45: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c48:
	/* 0xc48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c4a:
	/* 0xc4a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_c4d:
	/* 0xc4d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c52:
	/* 0xc52: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c55:
	/* 0xc55: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_c58:
	/* 0xc58: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_c5b:
	/* 0xc5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5d:
	/* 0xc5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c60:
	/* 0xc60: je     10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 271ULL;
	}
x86_l_c66:
	/* 0xc66: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_c69:
	/* 0xc69: je     10d <generic_sleepable_preload+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 269ULL;
	}
	return 3183ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3183ULL: goto x86_l_c6f;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3200ULL: goto x86_l_c80;
	case 3202ULL: goto x86_l_c82;
	case 3205ULL: goto x86_l_c85;
	case 3210ULL: goto x86_l_c8a;
	case 3212ULL: goto x86_l_c8c;
	case 3215ULL: goto x86_l_c8f;
	case 3217ULL: goto x86_l_c91;
	case 3223ULL: goto x86_l_c97;
	case 3228ULL: goto x86_l_c9c;
	case 3233ULL: goto x86_l_ca1;
	case 3239ULL: goto x86_l_ca7;
	case 3242ULL: goto x86_l_caa;
	case 3245ULL: goto x86_l_cad;
	case 3251ULL: goto x86_l_cb3;
	case 3255ULL: goto x86_l_cb7;
	case 3263ULL: goto x86_l_cbf;
	case 3268ULL: goto x86_l_cc4;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3295ULL: goto x86_l_cdf;
	case 3300ULL: goto x86_l_ce4;
	case 3302ULL: goto x86_l_ce6;
	case 3305ULL: goto x86_l_ce9;
	case 3311ULL: goto x86_l_cef;
	case 3317ULL: goto x86_l_cf5;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3330ULL: goto x86_l_d02;
	case 3333ULL: goto x86_l_d05;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3344ULL: goto x86_l_d10;
	case 3346ULL: goto x86_l_d12;
	case 3349ULL: goto x86_l_d15;
	case 3354ULL: goto x86_l_d1a;
	case 3357ULL: goto x86_l_d1d;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3365ULL: goto x86_l_d25;
	case 3371ULL: goto x86_l_d2b;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3379ULL: goto x86_l_d33;
	case 3383ULL: goto x86_l_d37;
	case 3388ULL: goto x86_l_d3c;
	case 3396ULL: goto x86_l_d44;
	case 3398ULL: goto x86_l_d46;
	case 3403ULL: goto x86_l_d4b;
	case 3405ULL: goto x86_l_d4d;
	case 3407ULL: goto x86_l_d4f;
	case 3413ULL: goto x86_l_d55;
	case 3417ULL: goto x86_l_d59;
	case 3422ULL: goto x86_l_d5e;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3444ULL: goto x86_l_d74;
	case 3447ULL: goto x86_l_d77;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3490ULL: goto x86_l_da2;
	case 3494ULL: goto x86_l_da6;
	case 3499ULL: goto x86_l_dab;
	case 3505ULL: goto x86_l_db1;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3520ULL: goto x86_l_dc0;
	case 3525ULL: goto x86_l_dc5;
	case 3527ULL: goto x86_l_dc7;
	case 3529ULL: goto x86_l_dc9;
	case 3533ULL: goto x86_l_dcd;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3545ULL: goto x86_l_dd9;
	case 3551ULL: goto x86_l_ddf;
	case 3554ULL: goto x86_l_de2;
	case 3560ULL: goto x86_l_de8;
	case 3563ULL: goto x86_l_deb;
	case 3569ULL: goto x86_l_df1;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3587ULL: goto x86_l_e03;
	case 3595ULL: goto x86_l_e0b;
	case 3601ULL: goto x86_l_e11;
	case 3603ULL: goto x86_l_e13;
	case 3606ULL: goto x86_l_e16;
	case 3608ULL: goto x86_l_e18;
	case 3611ULL: goto x86_l_e1b;
	case 3613ULL: goto x86_l_e1d;
	case 3616ULL: goto x86_l_e20;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3630ULL: goto x86_l_e2e;
	case 3636ULL: goto x86_l_e34;
	case 3641ULL: goto x86_l_e39;
	case 3644ULL: goto x86_l_e3c;
	case 3650ULL: goto x86_l_e42;
	case 3653ULL: goto x86_l_e45;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3690ULL: goto x86_l_e6a;
	case 3696ULL: goto x86_l_e70;
	case 3699ULL: goto x86_l_e73;
	case 3702ULL: goto x86_l_e76;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3715ULL: goto x86_l_e83;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3722ULL: goto x86_l_e8a;
	case 3727ULL: goto x86_l_e8f;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3738ULL: goto x86_l_e9a;
	case 3746ULL: goto x86_l_ea2;
	case 3749ULL: goto x86_l_ea5;
	case 3755ULL: goto x86_l_eab;
	case 3760ULL: goto x86_l_eb0;
	case 3763ULL: goto x86_l_eb3;
	case 3769ULL: goto x86_l_eb9;
	case 3774ULL: goto x86_l_ebe;
	case 3777ULL: goto x86_l_ec1;
	case 3783ULL: goto x86_l_ec7;
	case 3791ULL: goto x86_l_ecf;
	case 3794ULL: goto x86_l_ed2;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3824ULL: goto x86_l_ef0;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3841ULL: goto x86_l_f01;
	case 3845ULL: goto x86_l_f05;
	case 3847ULL: goto x86_l_f07;
	case 3850ULL: goto x86_l_f0a;
	case 3856ULL: goto x86_l_f10;
	case 3862ULL: goto x86_l_f16;
	case 3869ULL: goto x86_l_f1d;
	case 3872ULL: goto x86_l_f20;
	case 3876ULL: goto x86_l_f24;
	case 3879ULL: goto x86_l_f27;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3896ULL: goto x86_l_f38;
	case 3899ULL: goto x86_l_f3b;
	case 3901ULL: goto x86_l_f3d;
	case 3906ULL: goto x86_l_f42;
	case 3910ULL: goto x86_l_f46;
	case 3913ULL: goto x86_l_f49;
	case 3918ULL: goto x86_l_f4e;
	case 3920ULL: goto x86_l_f50;
	case 3922ULL: goto x86_l_f52;
	case 3928ULL: goto x86_l_f58;
	case 3934ULL: goto x86_l_f5e;
	case 3940ULL: goto x86_l_f64;
	case 3944ULL: goto x86_l_f68;
	case 3948ULL: goto x86_l_f6c;
	case 3954ULL: goto x86_l_f72;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3965ULL: goto x86_l_f7d;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3983ULL: goto x86_l_f8f;
	case 3992ULL: goto x86_l_f98;
	case 3998ULL: goto x86_l_f9e;
	case 4005ULL: goto x86_l_fa5;
	case 4009ULL: goto x86_l_fa9;
	case 4018ULL: goto x86_l_fb2;
	case 4020ULL: goto x86_l_fb4;
	case 4025ULL: goto x86_l_fb9;
	case 4029ULL: goto x86_l_fbd;
	case 4032ULL: goto x86_l_fc0;
	case 4037ULL: goto x86_l_fc5;
	case 4039ULL: goto x86_l_fc7;
	case 4041ULL: goto x86_l_fc9;
	case 4047ULL: goto x86_l_fcf;
	case 4056ULL: goto x86_l_fd8;
	case 4062ULL: goto x86_l_fde;
	case 4069ULL: goto x86_l_fe5;
	case 4073ULL: goto x86_l_fe9;
	case 4082ULL: goto x86_l_ff2;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4093ULL: goto x86_l_ffd;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4103ULL: goto x86_l_1007;
	case 4105ULL: goto x86_l_1009;
	case 4111ULL: goto x86_l_100f;
	case 4120ULL: goto x86_l_1018;
	case 4126ULL: goto x86_l_101e;
	case 4133ULL: goto x86_l_1025;
	case 4137ULL: goto x86_l_1029;
	case 4146ULL: goto x86_l_1032;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4157ULL: goto x86_l_103d;
	case 4160ULL: goto x86_l_1040;
	case 4165ULL: goto x86_l_1045;
	case 4167ULL: goto x86_l_1047;
	case 4169ULL: goto x86_l_1049;
	case 4175ULL: goto x86_l_104f;
	case 4184ULL: goto x86_l_1058;
	case 4190ULL: goto x86_l_105e;
	case 4197ULL: goto x86_l_1065;
	case 4201ULL: goto x86_l_1069;
	case 4210ULL: goto x86_l_1072;
	case 4212ULL: goto x86_l_1074;
	case 4217ULL: goto x86_l_1079;
	case 4221ULL: goto x86_l_107d;
	case 4224ULL: goto x86_l_1080;
	case 4229ULL: goto x86_l_1085;
	case 4231ULL: goto x86_l_1087;
	case 4233ULL: goto x86_l_1089;
	case 4239ULL: goto x86_l_108f;
	case 4248ULL: goto x86_l_1098;
	case 4254ULL: goto x86_l_109e;
	case 4261ULL: goto x86_l_10a5;
	case 4265ULL: goto x86_l_10a9;
	case 4274ULL: goto x86_l_10b2;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4285ULL: goto x86_l_10bd;
	case 4288ULL: goto x86_l_10c0;
	case 4293ULL: goto x86_l_10c5;
	case 4295ULL: goto x86_l_10c7;
	case 4297ULL: goto x86_l_10c9;
	case 4303ULL: goto x86_l_10cf;
	case 4312ULL: goto x86_l_10d8;
	case 4318ULL: goto x86_l_10de;
	case 4325ULL: goto x86_l_10e5;
	case 4329ULL: goto x86_l_10e9;
	case 4338ULL: goto x86_l_10f2;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4349ULL: goto x86_l_10fd;
	case 4352ULL: goto x86_l_1100;
	case 4357ULL: goto x86_l_1105;
	case 4359ULL: goto x86_l_1107;
	case 4361ULL: goto x86_l_1109;
	case 4367ULL: goto x86_l_110f;
	case 4376ULL: goto x86_l_1118;
	case 4382ULL: goto x86_l_111e;
	case 4389ULL: goto x86_l_1125;
	case 4393ULL: goto x86_l_1129;
	case 4402ULL: goto x86_l_1132;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4413ULL: goto x86_l_113d;
	case 4416ULL: goto x86_l_1140;
	case 4421ULL: goto x86_l_1145;
	case 4423ULL: goto x86_l_1147;
	case 4425ULL: goto x86_l_1149;
	case 4431ULL: goto x86_l_114f;
	case 4436ULL: goto x86_l_1154;
	case 4445ULL: goto x86_l_115d;
	case 4451ULL: goto x86_l_1163;
	case 4458ULL: goto x86_l_116a;
	case 4462ULL: goto x86_l_116e;
	case 4471ULL: goto x86_l_1177;
	case 4477ULL: goto x86_l_117d;
	case 4482ULL: goto x86_l_1182;
	case 4487ULL: goto x86_l_1187;
	case 4490ULL: goto x86_l_118a;
	case 4492ULL: goto x86_l_118c;
	case 4497ULL: goto x86_l_1191;
	case 4501ULL: goto x86_l_1195;
	case 4504ULL: goto x86_l_1198;
	case 4509ULL: goto x86_l_119d;
	case 4511ULL: goto x86_l_119f;
	case 4513ULL: goto x86_l_11a1;
	case 4519ULL: goto x86_l_11a7;
	case 4525ULL: goto x86_l_11ad;
	case 4531ULL: goto x86_l_11b3;
	case 4535ULL: goto x86_l_11b7;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4547ULL: goto x86_l_11c3;
	case 4552ULL: goto x86_l_11c8;
	case 4556ULL: goto x86_l_11cc;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4566ULL: goto x86_l_11d6;
	case 4568ULL: goto x86_l_11d8;
	case 4574ULL: goto x86_l_11de;
	case 4583ULL: goto x86_l_11e7;
	case 4589ULL: goto x86_l_11ed;
	case 4596ULL: goto x86_l_11f4;
	case 4600ULL: goto x86_l_11f8;
	case 4609ULL: goto x86_l_1201;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4620ULL: goto x86_l_120c;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4630ULL: goto x86_l_1216;
	case 4632ULL: goto x86_l_1218;
	case 4638ULL: goto x86_l_121e;
	case 4647ULL: goto x86_l_1227;
	case 4653ULL: goto x86_l_122d;
	case 4660ULL: goto x86_l_1234;
	case 4664ULL: goto x86_l_1238;
	case 4673ULL: goto x86_l_1241;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4684ULL: goto x86_l_124c;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
	case 4696ULL: goto x86_l_1258;
	case 4702ULL: goto x86_l_125e;
	case 4711ULL: goto x86_l_1267;
	case 4717ULL: goto x86_l_126d;
	case 4724ULL: goto x86_l_1274;
	case 4728ULL: goto x86_l_1278;
	case 4737ULL: goto x86_l_1281;
	case 4739ULL: goto x86_l_1283;
	case 4744ULL: goto x86_l_1288;
	case 4748ULL: goto x86_l_128c;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4758ULL: goto x86_l_1296;
	case 4760ULL: goto x86_l_1298;
	case 4766ULL: goto x86_l_129e;
	case 4775ULL: goto x86_l_12a7;
	case 4781ULL: goto x86_l_12ad;
	case 4788ULL: goto x86_l_12b4;
	case 4792ULL: goto x86_l_12b8;
	case 4801ULL: goto x86_l_12c1;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4812ULL: goto x86_l_12cc;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4822ULL: goto x86_l_12d6;
	case 4824ULL: goto x86_l_12d8;
	case 4830ULL: goto x86_l_12de;
	case 4839ULL: goto x86_l_12e7;
	case 4845ULL: goto x86_l_12ed;
	case 4852ULL: goto x86_l_12f4;
	case 4856ULL: goto x86_l_12f8;
	case 4865ULL: goto x86_l_1301;
	case 4867ULL: goto x86_l_1303;
	case 4872ULL: goto x86_l_1308;
	case 4876ULL: goto x86_l_130c;
	case 4879ULL: goto x86_l_130f;
	case 4884ULL: goto x86_l_1314;
	case 4886ULL: goto x86_l_1316;
	case 4888ULL: goto x86_l_1318;
	case 4894ULL: goto x86_l_131e;
	case 4903ULL: goto x86_l_1327;
	case 4909ULL: goto x86_l_132d;
	case 4916ULL: goto x86_l_1334;
	case 4920ULL: goto x86_l_1338;
	case 4929ULL: goto x86_l_1341;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4940ULL: goto x86_l_134c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_c6f:
	/* 0xc6f: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c73:
	/* 0xc73: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c78:
	/* 0xc78: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c80:
	/* 0xc80: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c82:
	/* 0xc82: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_c85:
	/* 0xc85: call   c8a <generic_sleepable_preload+0xc8a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_c8a:
	/* 0xc8a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_c8c:
	/* 0xc8c: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_c8f:
	/* 0xc8f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_c91:
	/* 0xc91: jns    10d <generic_sleepable_preload+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 269ULL;
	}
x86_l_c97:
	/* 0xc97: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_c9c:
	/* 0xc9c: jmp    10d <generic_sleepable_preload+0x10d> */
	return 269ULL;
x86_l_ca1:
	/* 0xca1: mov    r15d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 7ULL);
x86_l_ca7:
	/* 0xca7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_caa:
	/* 0xcaa: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_cad:
	/* 0xcad: jne    114 <generic_sleepable_preload+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 276ULL;
	}
x86_l_cb3:
	/* 0xcb3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb7:
	/* 0xcb7: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cbf:
	/* 0xcbf: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_cc4:
	/* 0xcc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc6:
	/* 0xcc6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ccb:
	/* 0xccb: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_cd3:
	/* 0xcd3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd8:
	/* 0xcd8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_cdf:
	/* 0xcdf: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_ce4:
	/* 0xce4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce6:
	/* 0xce6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce9:
	/* 0xce9: je     10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 271ULL;
	}
x86_l_cef:
	/* 0xcef: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_cf5:
	/* 0xcf5: mov    rbp,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_cfc:
	/* 0xcfc: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_cff:
	/* 0xcff: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_d02:
	/* 0xd02: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_d05:
	/* 0xd05: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d0a:
	/* 0xd0a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_d0d:
	/* 0xd0d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d10:
	/* 0xd10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d12:
	/* 0xd12: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d15:
	/* 0xd15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d1a:
	/* 0xd1a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d1d:
	/* 0xd1d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_d20:
	/* 0xd20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d22:
	/* 0xd22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d25:
	/* 0xd25: je     10f <generic_sleepable_preload+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 271ULL;
	}
x86_l_d2b:
	/* 0xd2b: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_d2e:
	/* 0xd2e: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_d31:
	/* 0xd31: je     d55 <generic_sleepable_preload+0xd55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d55;
	}
x86_l_d33:
	/* 0xd33: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d37:
	/* 0xd37: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d44:
	/* 0xd44: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d46:
	/* 0xd46: call   d4b <generic_sleepable_preload+0xd4b> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_d4b:
	/* 0xd4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d4d:
	/* 0xd4d: jns    d55 <generic_sleepable_preload+0xd55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_d55;
	}
x86_l_d4f:
	/* 0xd4f: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_d55:
	/* 0xd55: mov    DWORD PTR [rbp+0x0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d59:
	/* 0xd59: jmp    10f <generic_sleepable_preload+0x10f> */
	return 271ULL;
x86_l_d5e:
	/* 0xd5e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d61:
	/* 0xd61: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_d66:
	/* 0xd66: jmp    bca <generic_sleepable_preload+0xbca> */
	return 3018ULL;
x86_l_d6b:
	/* 0xd6b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d6e:
	/* 0xd6e: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_d74:
	/* 0xd74: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_d77:
	/* 0xd77: jne    114 <generic_sleepable_preload+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 276ULL;
	}
x86_l_d7d:
	/* 0xd7d: jmp    cb3 <generic_sleepable_preload+0xcb3> */
	goto x86_l_cb3;
x86_l_d82:
	/* 0xd82: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_d87:
	/* 0xd87: jmp    bc7 <generic_sleepable_preload+0xbc7> */
	return 3015ULL;
x86_l_d8c:
	/* 0xd8c: mov    r15d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 9ULL);
x86_l_d92:
	/* 0xd92: jmp    ca7 <generic_sleepable_preload+0xca7> */
	goto x86_l_ca7;
x86_l_d97:
	/* 0xd97: mov    eax,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d9b:
	/* 0xd9b: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_da0:
	/* 0xda0: jne    dc5 <generic_sleepable_preload+0xdc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dc5;
	}
x86_l_da2:
	/* 0xda2: mov    eax,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_da6:
	/* 0xda6: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_dab:
	/* 0xdab: jne    1b06 <generic_sleepable_preload+0x1b06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6918ULL;
	}
x86_l_db1:
	/* 0xdb1: mov    eax,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db5:
	/* 0xdb5: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_dba:
	/* 0xdba: jne    2883 <generic_sleepable_preload+0x2883> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10371ULL;
	}
x86_l_dc0:
	/* 0xdc0: jmp    35ec <generic_sleepable_preload+0x35ec> */
	return 13804ULL;
x86_l_dc5:
	/* 0xdc5: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_dc7:
	/* 0xdc7: js     dfb <generic_sleepable_preload+0xdfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_dfb;
	}
x86_l_dc9:
	/* 0xdc9: mov    ecx,DWORD PTR [r13+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dcd:
	/* 0xdcd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dd0:
	/* 0xdd0: jle    e81 <generic_sleepable_preload+0xe81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e81;
	}
x86_l_dd6:
	/* 0xdd6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dd9:
	/* 0xdd9: je     eeb <generic_sleepable_preload+0xeeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eeb;
	}
x86_l_ddf:
	/* 0xddf: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_de2:
	/* 0xde2: je     ef2 <generic_sleepable_preload+0xef2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef2;
	}
x86_l_de8:
	/* 0xde8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_deb:
	/* 0xdeb: jne    f05 <generic_sleepable_preload+0xf05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f05;
	}
x86_l_df1:
	/* 0xdf1: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_df6:
	/* 0xdf6: jmp    efe <generic_sleepable_preload+0xefe> */
	goto x86_l_efe;
x86_l_dfb:
	/* 0xdfb: movzx  ecx,BYTE PTR [r13+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_e03:
	/* 0xe03: movzx  eax,WORD PTR [r13+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_e0b:
	/* 0xe0b: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_e11:
	/* 0xe11: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e13:
	/* 0xe13: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_e16:
	/* 0xe16: jle    e55 <generic_sleepable_preload+0xe55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e55;
	}
x86_l_e18:
	/* 0xe18: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_e1b:
	/* 0xe1b: jle    e91 <generic_sleepable_preload+0xe91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e91;
	}
x86_l_e1d:
	/* 0xe1d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_e20:
	/* 0xe20: jle    144b <generic_sleepable_preload+0x144b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5195ULL;
	}
x86_l_e26:
	/* 0xe26: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e2b:
	/* 0xe2b: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_e2e:
	/* 0xe2e: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_e34:
	/* 0xe34: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e39:
	/* 0xe39: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_e3c:
	/* 0xe3c: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_e42:
	/* 0xe42: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_e45:
	/* 0xe45: jne    1472 <generic_sleepable_preload+0x1472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5234ULL;
	}
x86_l_e4b:
	/* 0xe4b: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e50:
	/* 0xe50: jmp    145f <generic_sleepable_preload+0x145f> */
	return 5215ULL;
x86_l_e55:
	/* 0xe55: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_e58:
	/* 0xe58: jg     ebe <generic_sleepable_preload+0xebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ebe;
	}
x86_l_e5a:
	/* 0xe5a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_e5d:
	/* 0xe5d: jg     1419 <generic_sleepable_preload+0x1419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5145ULL;
	}
x86_l_e63:
	/* 0xe63: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e68:
	/* 0xe68: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e6a:
	/* 0xe6a: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_e70:
	/* 0xe70: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_e73:
	/* 0xe73: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_e76:
	/* 0xe76: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_e7c:
	/* 0xe7c: jmp    1472 <generic_sleepable_preload+0x1472> */
	return 5234ULL;
x86_l_e81:
	/* 0xe81: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e83:
	/* 0xe83: je     ef9 <generic_sleepable_preload+0xef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef9;
	}
x86_l_e85:
	/* 0xe85: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e88:
	/* 0xe88: jne    f05 <generic_sleepable_preload+0xf05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f05;
	}
x86_l_e8a:
	/* 0xe8a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e8f:
	/* 0xe8f: jmp    efe <generic_sleepable_preload+0xefe> */
	goto x86_l_efe;
x86_l_e91:
	/* 0xe91: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_e94:
	/* 0xe94: jg     1400 <generic_sleepable_preload+0x1400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5120ULL;
	}
x86_l_e9a:
	/* 0xe9a: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ea2:
	/* 0xea2: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ea5:
	/* 0xea5: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_eab:
	/* 0xeab: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_eb0:
	/* 0xeb0: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_eb3:
	/* 0xeb3: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_eb9:
	/* 0xeb9: jmp    1472 <generic_sleepable_preload+0x1472> */
	return 5234ULL;
x86_l_ebe:
	/* 0xebe: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_ec1:
	/* 0xec1: jg     1432 <generic_sleepable_preload+0x1432> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5170ULL;
	}
x86_l_ec7:
	/* 0xec7: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ecf:
	/* 0xecf: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_ed2:
	/* 0xed2: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_ed8:
	/* 0xed8: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_edd:
	/* 0xedd: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_ee0:
	/* 0xee0: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5215ULL;
	}
x86_l_ee6:
	/* 0xee6: jmp    1472 <generic_sleepable_preload+0x1472> */
	return 5234ULL;
x86_l_eeb:
	/* 0xeeb: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ef0:
	/* 0xef0: jmp    efe <generic_sleepable_preload+0xefe> */
	goto x86_l_efe;
x86_l_ef2:
	/* 0xef2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ef7:
	/* 0xef7: jmp    efe <generic_sleepable_preload+0xefe> */
	goto x86_l_efe;
x86_l_ef9:
	/* 0xef9: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_efe:
	/* 0xefe: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f01:
	/* 0xf01: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f05:
	/* 0xf05: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f07:
	/* 0xf07: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_f0a:
	/* 0xf0a: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_f10:
	/* 0xf10: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_f16:
	/* 0xf16: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_f1d:
	/* 0xf1d: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_f20:
	/* 0xf20: mov    edx,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f24:
	/* 0xf24: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f27:
	/* 0xf27: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2b:
	/* 0xf2b: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_f30:
	/* 0xf30: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_f32:
	/* 0xf32: je     1187 <generic_sleepable_preload+0x1187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1187;
	}
x86_l_f38:
	/* 0xf38: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_f3b:
	/* 0xf3b: je     f58 <generic_sleepable_preload+0xf58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f58;
	}
x86_l_f3d:
	/* 0xf3d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f42:
	/* 0xf42: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f46:
	/* 0xf46: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f49:
	/* 0xf49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f4e:
	/* 0xf4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f50:
	/* 0xf50: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f52:
	/* 0xf52: js     13f6 <generic_sleepable_preload+0x13f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5110ULL;
	}
x86_l_f58:
	/* 0xf58: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_f5e:
	/* 0xf5e: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_f64:
	/* 0xf64: mov    eax,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f68:
	/* 0xf68: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_f6c:
	/* 0xf6c: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_f72:
	/* 0xf72: je     f8f <generic_sleepable_preload+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_f74:
	/* 0xf74: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f79:
	/* 0xf79: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f7d:
	/* 0xf7d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f80:
	/* 0xf80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f85:
	/* 0xf85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f87:
	/* 0xf87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f89:
	/* 0xf89: js     1975 <generic_sleepable_preload+0x1975> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6517ULL;
	}
x86_l_f8f:
	/* 0xf8f: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_f98:
	/* 0xf98: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_f9e:
	/* 0xf9e: mov    eax,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fa5:
	/* 0xfa5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_fa9:
	/* 0xfa9: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_fb2:
	/* 0xfb2: je     fcf <generic_sleepable_preload+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fcf;
	}
x86_l_fb4:
	/* 0xfb4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_fb9:
	/* 0xfb9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fbd:
	/* 0xfbd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fc0:
	/* 0xfc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fc5:
	/* 0xfc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc7:
	/* 0xfc7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc9:
	/* 0xfc9: js     1986 <generic_sleepable_preload+0x1986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6534ULL;
	}
x86_l_fcf:
	/* 0xfcf: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_fd8:
	/* 0xfd8: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_fde:
	/* 0xfde: mov    eax,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fe5:
	/* 0xfe5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_fe9:
	/* 0xfe9: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_ff2:
	/* 0xff2: je     100f <generic_sleepable_preload+0x100f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_100f;
	}
x86_l_ff4:
	/* 0xff4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ff9:
	/* 0xff9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ffd:
	/* 0xffd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1000:
	/* 0x1000: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1005:
	/* 0x1005: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1007:
	/* 0x1007: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1009:
	/* 0x1009: js     1997 <generic_sleepable_preload+0x1997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6551ULL;
	}
x86_l_100f:
	/* 0x100f: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1018:
	/* 0x1018: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_101e:
	/* 0x101e: mov    eax,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1025:
	/* 0x1025: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1029:
	/* 0x1029: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1032:
	/* 0x1032: je     104f <generic_sleepable_preload+0x104f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_104f;
	}
x86_l_1034:
	/* 0x1034: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1039:
	/* 0x1039: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_103d:
	/* 0x103d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1040:
	/* 0x1040: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1045:
	/* 0x1045: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1047:
	/* 0x1047: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1049:
	/* 0x1049: js     19a8 <generic_sleepable_preload+0x19a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6568ULL;
	}
x86_l_104f:
	/* 0x104f: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1058:
	/* 0x1058: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_105e:
	/* 0x105e: mov    eax,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1065:
	/* 0x1065: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1069:
	/* 0x1069: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1072:
	/* 0x1072: je     108f <generic_sleepable_preload+0x108f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108f;
	}
x86_l_1074:
	/* 0x1074: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1079:
	/* 0x1079: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_107d:
	/* 0x107d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1080:
	/* 0x1080: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1085:
	/* 0x1085: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1087:
	/* 0x1087: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1089:
	/* 0x1089: js     19b9 <generic_sleepable_preload+0x19b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6585ULL;
	}
x86_l_108f:
	/* 0x108f: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1098:
	/* 0x1098: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_109e:
	/* 0x109e: mov    eax,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_10a5:
	/* 0x10a5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10a9:
	/* 0x10a9: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_10b2:
	/* 0x10b2: je     10cf <generic_sleepable_preload+0x10cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10cf;
	}
x86_l_10b4:
	/* 0x10b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10b9:
	/* 0x10b9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10bd:
	/* 0x10bd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_10c0:
	/* 0x10c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10c5:
	/* 0x10c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c7:
	/* 0x10c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10c9:
	/* 0x10c9: js     19ca <generic_sleepable_preload+0x19ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6602ULL;
	}
x86_l_10cf:
	/* 0x10cf: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_10d8:
	/* 0x10d8: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_10de:
	/* 0x10de: mov    eax,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_10e5:
	/* 0x10e5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10e9:
	/* 0x10e9: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_10f2:
	/* 0x10f2: je     110f <generic_sleepable_preload+0x110f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110f;
	}
x86_l_10f4:
	/* 0x10f4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10f9:
	/* 0x10f9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10fd:
	/* 0x10fd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1100:
	/* 0x1100: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1105:
	/* 0x1105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1107:
	/* 0x1107: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1109:
	/* 0x1109: js     51e3 <generic_sleepable_preload+0x51e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20963ULL;
	}
x86_l_110f:
	/* 0x110f: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1118:
	/* 0x1118: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_111e:
	/* 0x111e: mov    eax,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1125:
	/* 0x1125: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1129:
	/* 0x1129: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1132:
	/* 0x1132: je     114f <generic_sleepable_preload+0x114f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_114f;
	}
x86_l_1134:
	/* 0x1134: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1139:
	/* 0x1139: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113d:
	/* 0x113d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1140:
	/* 0x1140: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1145:
	/* 0x1145: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1147:
	/* 0x1147: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1149:
	/* 0x1149: js     524b <generic_sleepable_preload+0x524b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21067ULL;
	}
x86_l_114f:
	/* 0x114f: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1154:
	/* 0x1154: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_115d:
	/* 0x115d: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_1163:
	/* 0x1163: mov    eax,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_116a:
	/* 0x116a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_116e:
	/* 0x116e: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1177:
	/* 0x1177: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_117d:
	/* 0x117d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1182:
	/* 0x1182: jmp    13d6 <generic_sleepable_preload+0x13d6> */
	return 5078ULL;
x86_l_1187:
	/* 0x1187: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_118a:
	/* 0x118a: je     11a7 <generic_sleepable_preload+0x11a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a7;
	}
x86_l_118c:
	/* 0x118c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1191:
	/* 0x1191: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1195:
	/* 0x1195: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1198:
	/* 0x1198: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_119d:
	/* 0x119d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119f:
	/* 0x119f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11a1:
	/* 0x11a1: js     13f6 <generic_sleepable_preload+0x13f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5110ULL;
	}
x86_l_11a7:
	/* 0x11a7: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_11ad:
	/* 0x11ad: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_11b3:
	/* 0x11b3: mov    eax,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_11b7:
	/* 0x11b7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11bb:
	/* 0x11bb: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_11c1:
	/* 0x11c1: je     11de <generic_sleepable_preload+0x11de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11de;
	}
x86_l_11c3:
	/* 0x11c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11c8:
	/* 0x11c8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11cc:
	/* 0x11cc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11cf:
	/* 0x11cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11d4:
	/* 0x11d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d6:
	/* 0x11d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11d8:
	/* 0x11d8: js     1975 <generic_sleepable_preload+0x1975> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6517ULL;
	}
x86_l_11de:
	/* 0x11de: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_11e7:
	/* 0x11e7: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_11ed:
	/* 0x11ed: mov    eax,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11f4:
	/* 0x11f4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11f8:
	/* 0x11f8: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1201:
	/* 0x1201: je     121e <generic_sleepable_preload+0x121e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121e;
	}
x86_l_1203:
	/* 0x1203: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1208:
	/* 0x1208: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_120c:
	/* 0x120c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_120f:
	/* 0x120f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1214:
	/* 0x1214: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1216:
	/* 0x1216: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1218:
	/* 0x1218: js     1986 <generic_sleepable_preload+0x1986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6534ULL;
	}
x86_l_121e:
	/* 0x121e: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1227:
	/* 0x1227: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_122d:
	/* 0x122d: mov    eax,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1234:
	/* 0x1234: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1238:
	/* 0x1238: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1241:
	/* 0x1241: je     125e <generic_sleepable_preload+0x125e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125e;
	}
x86_l_1243:
	/* 0x1243: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1248:
	/* 0x1248: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124c:
	/* 0x124c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_124f:
	/* 0x124f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1254:
	/* 0x1254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1256:
	/* 0x1256: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1258:
	/* 0x1258: js     1997 <generic_sleepable_preload+0x1997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6551ULL;
	}
x86_l_125e:
	/* 0x125e: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1267:
	/* 0x1267: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_126d:
	/* 0x126d: mov    eax,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1274:
	/* 0x1274: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1278:
	/* 0x1278: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1281:
	/* 0x1281: je     129e <generic_sleepable_preload+0x129e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_129e;
	}
x86_l_1283:
	/* 0x1283: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1288:
	/* 0x1288: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_128c:
	/* 0x128c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_128f:
	/* 0x128f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1294:
	/* 0x1294: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1296:
	/* 0x1296: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1298:
	/* 0x1298: js     19a8 <generic_sleepable_preload+0x19a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6568ULL;
	}
x86_l_129e:
	/* 0x129e: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_12a7:
	/* 0x12a7: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_12ad:
	/* 0x12ad: mov    eax,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_12b4:
	/* 0x12b4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12b8:
	/* 0x12b8: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_12c1:
	/* 0x12c1: je     12de <generic_sleepable_preload+0x12de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12de;
	}
x86_l_12c3:
	/* 0x12c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12c8:
	/* 0x12c8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12cc:
	/* 0x12cc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12cf:
	/* 0x12cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12d4:
	/* 0x12d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d6:
	/* 0x12d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12d8:
	/* 0x12d8: js     19b9 <generic_sleepable_preload+0x19b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6585ULL;
	}
x86_l_12de:
	/* 0x12de: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_12e7:
	/* 0x12e7: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_12ed:
	/* 0x12ed: mov    eax,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_12f4:
	/* 0x12f4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12f8:
	/* 0x12f8: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1301:
	/* 0x1301: je     131e <generic_sleepable_preload+0x131e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131e;
	}
x86_l_1303:
	/* 0x1303: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1308:
	/* 0x1308: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_130c:
	/* 0x130c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_130f:
	/* 0x130f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1314:
	/* 0x1314: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1316:
	/* 0x1316: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1318:
	/* 0x1318: js     19ca <generic_sleepable_preload+0x19ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6602ULL;
	}
x86_l_131e:
	/* 0x131e: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1327:
	/* 0x1327: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6610ULL;
	}
x86_l_132d:
	/* 0x132d: mov    eax,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1334:
	/* 0x1334: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1338:
	/* 0x1338: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1341:
	/* 0x1341: je     135e <generic_sleepable_preload+0x135e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4958ULL;
	}
x86_l_1343:
	/* 0x1343: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1348:
	/* 0x1348: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_134c:
	/* 0x134c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
	return 4943ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4950ULL: goto x86_l_1356;
	case 4952ULL: goto x86_l_1358;
	case 4958ULL: goto x86_l_135e;
	case 4963ULL: goto x86_l_1363;
	case 4972ULL: goto x86_l_136c;
	case 4978ULL: goto x86_l_1372;
	case 4985ULL: goto x86_l_1379;
	case 4989ULL: goto x86_l_137d;
	case 4998ULL: goto x86_l_1386;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5009ULL: goto x86_l_1391;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5019ULL: goto x86_l_139b;
	case 5021ULL: goto x86_l_139d;
	case 5027ULL: goto x86_l_13a3;
	case 5032ULL: goto x86_l_13a8;
	case 5041ULL: goto x86_l_13b1;
	case 5047ULL: goto x86_l_13b7;
	case 5054ULL: goto x86_l_13be;
	case 5058ULL: goto x86_l_13c2;
	case 5067ULL: goto x86_l_13cb;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5090ULL: goto x86_l_13e2;
	case 5092ULL: goto x86_l_13e4;
	case 5094ULL: goto x86_l_13e6;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5110ULL: goto x86_l_13f6;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5128ULL: goto x86_l_1408;
	case 5131ULL: goto x86_l_140b;
	case 5133ULL: goto x86_l_140d;
	case 5138ULL: goto x86_l_1412;
	case 5141ULL: goto x86_l_1415;
	case 5143ULL: goto x86_l_1417;
	case 5145ULL: goto x86_l_1419;
	case 5153ULL: goto x86_l_1421;
	case 5156ULL: goto x86_l_1424;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5166ULL: goto x86_l_142e;
	case 5168ULL: goto x86_l_1430;
	case 5170ULL: goto x86_l_1432;
	case 5178ULL: goto x86_l_143a;
	case 5181ULL: goto x86_l_143d;
	case 5183ULL: goto x86_l_143f;
	case 5188ULL: goto x86_l_1444;
	case 5191ULL: goto x86_l_1447;
	case 5193ULL: goto x86_l_1449;
	case 5195ULL: goto x86_l_144b;
	case 5200ULL: goto x86_l_1450;
	case 5203ULL: goto x86_l_1453;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5213ULL: goto x86_l_145d;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5220ULL: goto x86_l_1464;
	case 5222ULL: goto x86_l_1466;
	case 5227ULL: goto x86_l_146b;
	case 5229ULL: goto x86_l_146d;
	case 5234ULL: goto x86_l_1472;
	case 5238ULL: goto x86_l_1476;
	case 5242ULL: goto x86_l_147a;
	case 5244ULL: goto x86_l_147c;
	case 5247ULL: goto x86_l_147f;
	case 5253ULL: goto x86_l_1485;
	case 5259ULL: goto x86_l_148b;
	case 5266ULL: goto x86_l_1492;
	case 5269ULL: goto x86_l_1495;
	case 5273ULL: goto x86_l_1499;
	case 5276ULL: goto x86_l_149c;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5287ULL: goto x86_l_14a7;
	case 5293ULL: goto x86_l_14ad;
	case 5296ULL: goto x86_l_14b0;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5307ULL: goto x86_l_14bb;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5317ULL: goto x86_l_14c5;
	case 5319ULL: goto x86_l_14c7;
	case 5325ULL: goto x86_l_14cd;
	case 5331ULL: goto x86_l_14d3;
	case 5337ULL: goto x86_l_14d9;
	case 5341ULL: goto x86_l_14dd;
	case 5345ULL: goto x86_l_14e1;
	case 5351ULL: goto x86_l_14e7;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5362ULL: goto x86_l_14f2;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5372ULL: goto x86_l_14fc;
	case 5374ULL: goto x86_l_14fe;
	case 5380ULL: goto x86_l_1504;
	case 5389ULL: goto x86_l_150d;
	case 5395ULL: goto x86_l_1513;
	case 5402ULL: goto x86_l_151a;
	case 5406ULL: goto x86_l_151e;
	case 5415ULL: goto x86_l_1527;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5426ULL: goto x86_l_1532;
	case 5429ULL: goto x86_l_1535;
	case 5434ULL: goto x86_l_153a;
	case 5436ULL: goto x86_l_153c;
	case 5438ULL: goto x86_l_153e;
	case 5444ULL: goto x86_l_1544;
	case 5453ULL: goto x86_l_154d;
	case 5459ULL: goto x86_l_1553;
	case 5466ULL: goto x86_l_155a;
	case 5470ULL: goto x86_l_155e;
	case 5479ULL: goto x86_l_1567;
	case 5481ULL: goto x86_l_1569;
	case 5486ULL: goto x86_l_156e;
	case 5490ULL: goto x86_l_1572;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5500ULL: goto x86_l_157c;
	case 5502ULL: goto x86_l_157e;
	case 5508ULL: goto x86_l_1584;
	case 5517ULL: goto x86_l_158d;
	case 5523ULL: goto x86_l_1593;
	case 5530ULL: goto x86_l_159a;
	case 5534ULL: goto x86_l_159e;
	case 5543ULL: goto x86_l_15a7;
	case 5545ULL: goto x86_l_15a9;
	case 5550ULL: goto x86_l_15ae;
	case 5554ULL: goto x86_l_15b2;
	case 5557ULL: goto x86_l_15b5;
	case 5562ULL: goto x86_l_15ba;
	case 5564ULL: goto x86_l_15bc;
	case 5566ULL: goto x86_l_15be;
	case 5572ULL: goto x86_l_15c4;
	case 5581ULL: goto x86_l_15cd;
	case 5587ULL: goto x86_l_15d3;
	case 5594ULL: goto x86_l_15da;
	case 5598ULL: goto x86_l_15de;
	case 5607ULL: goto x86_l_15e7;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5618ULL: goto x86_l_15f2;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5630ULL: goto x86_l_15fe;
	case 5636ULL: goto x86_l_1604;
	case 5645ULL: goto x86_l_160d;
	case 5651ULL: goto x86_l_1613;
	case 5658ULL: goto x86_l_161a;
	case 5662ULL: goto x86_l_161e;
	case 5671ULL: goto x86_l_1627;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5682ULL: goto x86_l_1632;
	case 5685ULL: goto x86_l_1635;
	case 5690ULL: goto x86_l_163a;
	case 5692ULL: goto x86_l_163c;
	case 5694ULL: goto x86_l_163e;
	case 5700ULL: goto x86_l_1644;
	case 5709ULL: goto x86_l_164d;
	case 5715ULL: goto x86_l_1653;
	case 5722ULL: goto x86_l_165a;
	case 5726ULL: goto x86_l_165e;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5742ULL: goto x86_l_166e;
	case 5746ULL: goto x86_l_1672;
	case 5749ULL: goto x86_l_1675;
	case 5754ULL: goto x86_l_167a;
	case 5756ULL: goto x86_l_167c;
	case 5758ULL: goto x86_l_167e;
	case 5764ULL: goto x86_l_1684;
	case 5773ULL: goto x86_l_168d;
	case 5779ULL: goto x86_l_1693;
	case 5786ULL: goto x86_l_169a;
	case 5790ULL: goto x86_l_169e;
	case 5799ULL: goto x86_l_16a7;
	case 5801ULL: goto x86_l_16a9;
	case 5806ULL: goto x86_l_16ae;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5820ULL: goto x86_l_16bc;
	case 5822ULL: goto x86_l_16be;
	case 5828ULL: goto x86_l_16c4;
	case 5833ULL: goto x86_l_16c9;
	case 5842ULL: goto x86_l_16d2;
	case 5848ULL: goto x86_l_16d8;
	case 5855ULL: goto x86_l_16df;
	case 5859ULL: goto x86_l_16e3;
	case 5868ULL: goto x86_l_16ec;
	case 5874ULL: goto x86_l_16f2;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5887ULL: goto x86_l_16ff;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5898ULL: goto x86_l_170a;
	case 5901ULL: goto x86_l_170d;
	case 5906ULL: goto x86_l_1712;
	case 5908ULL: goto x86_l_1714;
	case 5910ULL: goto x86_l_1716;
	case 5916ULL: goto x86_l_171c;
	case 5922ULL: goto x86_l_1722;
	case 5928ULL: goto x86_l_1728;
	case 5932ULL: goto x86_l_172c;
	case 5936ULL: goto x86_l_1730;
	case 5942ULL: goto x86_l_1736;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5953ULL: goto x86_l_1741;
	case 5956ULL: goto x86_l_1744;
	case 5961ULL: goto x86_l_1749;
	case 5963ULL: goto x86_l_174b;
	case 5965ULL: goto x86_l_174d;
	case 5971ULL: goto x86_l_1753;
	case 5980ULL: goto x86_l_175c;
	case 5986ULL: goto x86_l_1762;
	case 5993ULL: goto x86_l_1769;
	case 5997ULL: goto x86_l_176d;
	case 6006ULL: goto x86_l_1776;
	case 6008ULL: goto x86_l_1778;
	case 6013ULL: goto x86_l_177d;
	case 6017ULL: goto x86_l_1781;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6027ULL: goto x86_l_178b;
	case 6029ULL: goto x86_l_178d;
	case 6035ULL: goto x86_l_1793;
	case 6044ULL: goto x86_l_179c;
	case 6050ULL: goto x86_l_17a2;
	case 6057ULL: goto x86_l_17a9;
	case 6061ULL: goto x86_l_17ad;
	case 6070ULL: goto x86_l_17b6;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6091ULL: goto x86_l_17cb;
	case 6093ULL: goto x86_l_17cd;
	case 6099ULL: goto x86_l_17d3;
	case 6108ULL: goto x86_l_17dc;
	case 6114ULL: goto x86_l_17e2;
	case 6121ULL: goto x86_l_17e9;
	case 6125ULL: goto x86_l_17ed;
	case 6134ULL: goto x86_l_17f6;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6153ULL: goto x86_l_1809;
	case 6155ULL: goto x86_l_180b;
	case 6157ULL: goto x86_l_180d;
	case 6163ULL: goto x86_l_1813;
	case 6172ULL: goto x86_l_181c;
	case 6178ULL: goto x86_l_1822;
	case 6185ULL: goto x86_l_1829;
	case 6189ULL: goto x86_l_182d;
	case 6198ULL: goto x86_l_1836;
	case 6200ULL: goto x86_l_1838;
	case 6205ULL: goto x86_l_183d;
	case 6209ULL: goto x86_l_1841;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6219ULL: goto x86_l_184b;
	case 6221ULL: goto x86_l_184d;
	case 6227ULL: goto x86_l_1853;
	case 6236ULL: goto x86_l_185c;
	case 6242ULL: goto x86_l_1862;
	case 6249ULL: goto x86_l_1869;
	case 6253ULL: goto x86_l_186d;
	case 6262ULL: goto x86_l_1876;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6273ULL: goto x86_l_1881;
	case 6276ULL: goto x86_l_1884;
	case 6281ULL: goto x86_l_1889;
	case 6283ULL: goto x86_l_188b;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6300ULL: goto x86_l_189c;
	case 6306ULL: goto x86_l_18a2;
	case 6313ULL: goto x86_l_18a9;
	case 6317ULL: goto x86_l_18ad;
	case 6326ULL: goto x86_l_18b6;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6337ULL: goto x86_l_18c1;
	case 6340ULL: goto x86_l_18c4;
	case 6345ULL: goto x86_l_18c9;
	case 6347ULL: goto x86_l_18cb;
	case 6349ULL: goto x86_l_18cd;
	case 6355ULL: goto x86_l_18d3;
	case 6360ULL: goto x86_l_18d8;
	case 6369ULL: goto x86_l_18e1;
	case 6375ULL: goto x86_l_18e7;
	case 6382ULL: goto x86_l_18ee;
	case 6386ULL: goto x86_l_18f2;
	case 6395ULL: goto x86_l_18fb;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6406ULL: goto x86_l_1906;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6416ULL: goto x86_l_1910;
	case 6418ULL: goto x86_l_1912;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6438ULL: goto x86_l_1926;
	case 6444ULL: goto x86_l_192c;
	case 6451ULL: goto x86_l_1933;
	case 6455ULL: goto x86_l_1937;
	case 6464ULL: goto x86_l_1940;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6479ULL: goto x86_l_194f;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6489ULL: goto x86_l_1959;
	case 6491ULL: goto x86_l_195b;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6507ULL: goto x86_l_196b;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6524ULL: goto x86_l_197c;
	case 6529ULL: goto x86_l_1981;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6558ULL: goto x86_l_199e;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6573ULL: goto x86_l_19ad;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6610ULL: goto x86_l_19d2;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6622ULL: goto x86_l_19de;
	case 6627ULL: goto x86_l_19e3;
	case 6630ULL: goto x86_l_19e6;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6641ULL: goto x86_l_19f1;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6665ULL: goto x86_l_1a09;
	case 6670ULL: goto x86_l_1a0e;
	case 6677ULL: goto x86_l_1a15;
	case 6682ULL: goto x86_l_1a1a;
	case 6684ULL: goto x86_l_1a1c;
	case 6687ULL: goto x86_l_1a1f;
	case 6693ULL: goto x86_l_1a25;
	case 6699ULL: goto x86_l_1a2b;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_134f:
	/* 0x134f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1354:
	/* 0x1354: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1356:
	/* 0x1356: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1358:
	/* 0x1358: js     52ef <generic_sleepable_preload+0x52ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21231ULL;
	}
x86_l_135e:
	/* 0x135e: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1363:
	/* 0x1363: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_136c:
	/* 0x136c: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19d2;
	}
x86_l_1372:
	/* 0x1372: mov    eax,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1379:
	/* 0x1379: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_137d:
	/* 0x137d: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1386:
	/* 0x1386: je     13a3 <generic_sleepable_preload+0x13a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a3;
	}
x86_l_1388:
	/* 0x1388: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_138d:
	/* 0x138d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1391:
	/* 0x1391: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1394:
	/* 0x1394: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1399:
	/* 0x1399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139b:
	/* 0x139b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_139d:
	/* 0x139d: js     524b <generic_sleepable_preload+0x524b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21067ULL;
	}
x86_l_13a3:
	/* 0x13a3: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13a8:
	/* 0x13a8: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_13b1:
	/* 0x13b1: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19d2;
	}
x86_l_13b7:
	/* 0x13b7: mov    eax,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_13be:
	/* 0x13be: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_13c2:
	/* 0x13c2: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_13cb:
	/* 0x13cb: je     19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19d2;
	}
x86_l_13d1:
	/* 0x13d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13d6:
	/* 0x13d6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13da:
	/* 0x13da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13dd:
	/* 0x13dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13e2:
	/* 0x13e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e4:
	/* 0x13e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13e6:
	/* 0x13e6: jns    19d2 <generic_sleepable_preload+0x19d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_19d2;
	}
x86_l_13ec:
	/* 0x13ec: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_13f1:
	/* 0x13f1: jmp    19cf <generic_sleepable_preload+0x19cf> */
	goto x86_l_19cf;
x86_l_13f6:
	/* 0x13f6: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_13fb:
	/* 0x13fb: jmp    19cf <generic_sleepable_preload+0x19cf> */
	goto x86_l_19cf;
x86_l_1400:
	/* 0x1400: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1408:
	/* 0x1408: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_140b:
	/* 0x140b: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145f;
	}
x86_l_140d:
	/* 0x140d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1412:
	/* 0x1412: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1415:
	/* 0x1415: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145f;
	}
x86_l_1417:
	/* 0x1417: jmp    1472 <generic_sleepable_preload+0x1472> */
	goto x86_l_1472;
x86_l_1419:
	/* 0x1419: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1421:
	/* 0x1421: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1424:
	/* 0x1424: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145f;
	}
x86_l_1426:
	/* 0x1426: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_142b:
	/* 0x142b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_142e:
	/* 0x142e: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145f;
	}
x86_l_1430:
	/* 0x1430: jmp    1472 <generic_sleepable_preload+0x1472> */
	goto x86_l_1472;
x86_l_1432:
	/* 0x1432: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_143a:
	/* 0x143a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_143d:
	/* 0x143d: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145f;
	}
x86_l_143f:
	/* 0x143f: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1444:
	/* 0x1444: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1447:
	/* 0x1447: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145f;
	}
x86_l_1449:
	/* 0x1449: jmp    1472 <generic_sleepable_preload+0x1472> */
	goto x86_l_1472;
x86_l_144b:
	/* 0x144b: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1450:
	/* 0x1450: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1453:
	/* 0x1453: je     145f <generic_sleepable_preload+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145f;
	}
x86_l_1455:
	/* 0x1455: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_145a:
	/* 0x145a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_145d:
	/* 0x145d: jne    1472 <generic_sleepable_preload+0x1472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1472;
	}
x86_l_145f:
	/* 0x145f: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1462:
	/* 0x1462: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_1464:
	/* 0x1464: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1466:
	/* 0x1466: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_146b:
	/* 0x146b: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_146d:
	/* 0x146d: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_1472:
	/* 0x1472: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1476:
	/* 0x1476: mov    ebx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_147a:
	/* 0x147a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_147c:
	/* 0x147c: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_147f:
	/* 0x147f: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1485:
	/* 0x1485: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_148b:
	/* 0x148b: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1492:
	/* 0x1492: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1495:
	/* 0x1495: mov    edx,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1499:
	/* 0x1499: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_149c:
	/* 0x149c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a0:
	/* 0x14a0: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_14a5:
	/* 0x14a5: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_14a7:
	/* 0x14a7: je     16fc <generic_sleepable_preload+0x16fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16fc;
	}
x86_l_14ad:
	/* 0x14ad: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_14b0:
	/* 0x14b0: je     14cd <generic_sleepable_preload+0x14cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14cd;
	}
x86_l_14b2:
	/* 0x14b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14b7:
	/* 0x14b7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14bb:
	/* 0x14bb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14be:
	/* 0x14be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c3:
	/* 0x14c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c5:
	/* 0x14c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14c7:
	/* 0x14c7: js     196b <generic_sleepable_preload+0x196b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_196b;
	}
x86_l_14cd:
	/* 0x14cd: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_14d3:
	/* 0x14d3: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_14d9:
	/* 0x14d9: mov    eax,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14dd:
	/* 0x14dd: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14e1:
	/* 0x14e1: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_14e7:
	/* 0x14e7: je     1504 <generic_sleepable_preload+0x1504> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1504;
	}
x86_l_14e9:
	/* 0x14e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14ee:
	/* 0x14ee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f2:
	/* 0x14f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14f5:
	/* 0x14f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14fa:
	/* 0x14fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fc:
	/* 0x14fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14fe:
	/* 0x14fe: js     197c <generic_sleepable_preload+0x197c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_197c;
	}
x86_l_1504:
	/* 0x1504: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_150d:
	/* 0x150d: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1513:
	/* 0x1513: mov    eax,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_151a:
	/* 0x151a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_151e:
	/* 0x151e: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1527:
	/* 0x1527: je     1544 <generic_sleepable_preload+0x1544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1544;
	}
x86_l_1529:
	/* 0x1529: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_152e:
	/* 0x152e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1532:
	/* 0x1532: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1535:
	/* 0x1535: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_153a:
	/* 0x153a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153c:
	/* 0x153c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_153e:
	/* 0x153e: js     198d <generic_sleepable_preload+0x198d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_198d;
	}
x86_l_1544:
	/* 0x1544: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_154d:
	/* 0x154d: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1553:
	/* 0x1553: mov    eax,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_155a:
	/* 0x155a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_155e:
	/* 0x155e: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1567:
	/* 0x1567: je     1584 <generic_sleepable_preload+0x1584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1584;
	}
x86_l_1569:
	/* 0x1569: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_156e:
	/* 0x156e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1572:
	/* 0x1572: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1575:
	/* 0x1575: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_157a:
	/* 0x157a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157c:
	/* 0x157c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_157e:
	/* 0x157e: js     199e <generic_sleepable_preload+0x199e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_199e;
	}
x86_l_1584:
	/* 0x1584: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_158d:
	/* 0x158d: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1593:
	/* 0x1593: mov    eax,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_159a:
	/* 0x159a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_159e:
	/* 0x159e: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_15a7:
	/* 0x15a7: je     15c4 <generic_sleepable_preload+0x15c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15c4;
	}
x86_l_15a9:
	/* 0x15a9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15ae:
	/* 0x15ae: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b2:
	/* 0x15b2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15b5:
	/* 0x15b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15ba:
	/* 0x15ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bc:
	/* 0x15bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15be:
	/* 0x15be: js     19af <generic_sleepable_preload+0x19af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19af;
	}
x86_l_15c4:
	/* 0x15c4: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_15cd:
	/* 0x15cd: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_15d3:
	/* 0x15d3: mov    eax,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15da:
	/* 0x15da: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15de:
	/* 0x15de: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_15e7:
	/* 0x15e7: je     1604 <generic_sleepable_preload+0x1604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1604;
	}
x86_l_15e9:
	/* 0x15e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15ee:
	/* 0x15ee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f2:
	/* 0x15f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15f5:
	/* 0x15f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15fa:
	/* 0x15fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15fc:
	/* 0x15fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15fe:
	/* 0x15fe: js     19c0 <generic_sleepable_preload+0x19c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19c0;
	}
x86_l_1604:
	/* 0x1604: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_160d:
	/* 0x160d: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1613:
	/* 0x1613: mov    eax,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_161a:
	/* 0x161a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_161e:
	/* 0x161e: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1627:
	/* 0x1627: je     1644 <generic_sleepable_preload+0x1644> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1644;
	}
x86_l_1629:
	/* 0x1629: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_162e:
	/* 0x162e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1632:
	/* 0x1632: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1635:
	/* 0x1635: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_163a:
	/* 0x163a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163c:
	/* 0x163c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_163e:
	/* 0x163e: js     1a4c <generic_sleepable_preload+0x1a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6732ULL;
	}
x86_l_1644:
	/* 0x1644: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_164d:
	/* 0x164d: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1653:
	/* 0x1653: mov    eax,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_165a:
	/* 0x165a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_165e:
	/* 0x165e: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1667:
	/* 0x1667: je     1684 <generic_sleepable_preload+0x1684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1684;
	}
x86_l_1669:
	/* 0x1669: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_166e:
	/* 0x166e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1672:
	/* 0x1672: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1675:
	/* 0x1675: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_167a:
	/* 0x167a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_167c:
	/* 0x167c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_167e:
	/* 0x167e: js     51f0 <generic_sleepable_preload+0x51f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20976ULL;
	}
x86_l_1684:
	/* 0x1684: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_168d:
	/* 0x168d: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1693:
	/* 0x1693: mov    eax,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_169a:
	/* 0x169a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_169e:
	/* 0x169e: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_16a7:
	/* 0x16a7: je     16c4 <generic_sleepable_preload+0x16c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16c4;
	}
x86_l_16a9:
	/* 0x16a9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16ae:
	/* 0x16ae: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b2:
	/* 0x16b2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16b5:
	/* 0x16b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16ba:
	/* 0x16ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bc:
	/* 0x16bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16be:
	/* 0x16be: js     525d <generic_sleepable_preload+0x525d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21085ULL;
	}
x86_l_16c4:
	/* 0x16c4: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16c9:
	/* 0x16c9: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_16d2:
	/* 0x16d2: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_16d8:
	/* 0x16d8: mov    eax,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_16df:
	/* 0x16df: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_16e3:
	/* 0x16e3: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_16ec:
	/* 0x16ec: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_16f2:
	/* 0x16f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16f7:
	/* 0x16f7: jmp    194b <generic_sleepable_preload+0x194b> */
	goto x86_l_194b;
x86_l_16fc:
	/* 0x16fc: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_16ff:
	/* 0x16ff: je     171c <generic_sleepable_preload+0x171c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_171c;
	}
x86_l_1701:
	/* 0x1701: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1706:
	/* 0x1706: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_170a:
	/* 0x170a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_170d:
	/* 0x170d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1712:
	/* 0x1712: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1714:
	/* 0x1714: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1716:
	/* 0x1716: js     196b <generic_sleepable_preload+0x196b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_196b;
	}
x86_l_171c:
	/* 0x171c: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1722:
	/* 0x1722: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1728:
	/* 0x1728: mov    eax,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_172c:
	/* 0x172c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1730:
	/* 0x1730: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1736:
	/* 0x1736: je     1753 <generic_sleepable_preload+0x1753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1753;
	}
x86_l_1738:
	/* 0x1738: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_173d:
	/* 0x173d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1741:
	/* 0x1741: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1744:
	/* 0x1744: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1749:
	/* 0x1749: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174b:
	/* 0x174b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174d:
	/* 0x174d: js     197c <generic_sleepable_preload+0x197c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_197c;
	}
x86_l_1753:
	/* 0x1753: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_175c:
	/* 0x175c: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1762:
	/* 0x1762: mov    eax,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1769:
	/* 0x1769: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_176d:
	/* 0x176d: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1776:
	/* 0x1776: je     1793 <generic_sleepable_preload+0x1793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1793;
	}
x86_l_1778:
	/* 0x1778: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_177d:
	/* 0x177d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1781:
	/* 0x1781: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1784:
	/* 0x1784: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1789:
	/* 0x1789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178b:
	/* 0x178b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_178d:
	/* 0x178d: js     198d <generic_sleepable_preload+0x198d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_198d;
	}
x86_l_1793:
	/* 0x1793: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_179c:
	/* 0x179c: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_17a2:
	/* 0x17a2: mov    eax,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_17a9:
	/* 0x17a9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17ad:
	/* 0x17ad: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_17b6:
	/* 0x17b6: je     17d3 <generic_sleepable_preload+0x17d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17d3;
	}
x86_l_17b8:
	/* 0x17b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17bd:
	/* 0x17bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c1:
	/* 0x17c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_17c4:
	/* 0x17c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c9:
	/* 0x17c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17cb:
	/* 0x17cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17cd:
	/* 0x17cd: js     199e <generic_sleepable_preload+0x199e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_199e;
	}
x86_l_17d3:
	/* 0x17d3: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_17dc:
	/* 0x17dc: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_17e2:
	/* 0x17e2: mov    eax,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17e9:
	/* 0x17e9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17ed:
	/* 0x17ed: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_17f6:
	/* 0x17f6: je     1813 <generic_sleepable_preload+0x1813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1813;
	}
x86_l_17f8:
	/* 0x17f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17fd:
	/* 0x17fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1801:
	/* 0x1801: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1804:
	/* 0x1804: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1809:
	/* 0x1809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180b:
	/* 0x180b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_180d:
	/* 0x180d: js     19af <generic_sleepable_preload+0x19af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19af;
	}
x86_l_1813:
	/* 0x1813: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_181c:
	/* 0x181c: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1822:
	/* 0x1822: mov    eax,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1829:
	/* 0x1829: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_182d:
	/* 0x182d: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1836:
	/* 0x1836: je     1853 <generic_sleepable_preload+0x1853> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1853;
	}
x86_l_1838:
	/* 0x1838: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_183d:
	/* 0x183d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1841:
	/* 0x1841: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1844:
	/* 0x1844: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1849:
	/* 0x1849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184b:
	/* 0x184b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_184d:
	/* 0x184d: js     19c0 <generic_sleepable_preload+0x19c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19c0;
	}
x86_l_1853:
	/* 0x1853: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_185c:
	/* 0x185c: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1862:
	/* 0x1862: mov    eax,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1869:
	/* 0x1869: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_186d:
	/* 0x186d: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1876:
	/* 0x1876: je     1893 <generic_sleepable_preload+0x1893> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1893;
	}
x86_l_1878:
	/* 0x1878: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_187d:
	/* 0x187d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1881:
	/* 0x1881: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1884:
	/* 0x1884: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1889:
	/* 0x1889: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188b:
	/* 0x188b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_188d:
	/* 0x188d: js     1a4c <generic_sleepable_preload+0x1a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6732ULL;
	}
x86_l_1893:
	/* 0x1893: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_189c:
	/* 0x189c: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_18a2:
	/* 0x18a2: mov    eax,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_18a9:
	/* 0x18a9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18ad:
	/* 0x18ad: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_18b6:
	/* 0x18b6: je     18d3 <generic_sleepable_preload+0x18d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18d3;
	}
x86_l_18b8:
	/* 0x18b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18bd:
	/* 0x18bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18c1:
	/* 0x18c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18c4:
	/* 0x18c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c9:
	/* 0x18c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18cb:
	/* 0x18cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18cd:
	/* 0x18cd: js     5301 <generic_sleepable_preload+0x5301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21249ULL;
	}
x86_l_18d3:
	/* 0x18d3: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d8:
	/* 0x18d8: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_18e1:
	/* 0x18e1: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_18e7:
	/* 0x18e7: mov    eax,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18ee:
	/* 0x18ee: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18f2:
	/* 0x18f2: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_18fb:
	/* 0x18fb: je     1918 <generic_sleepable_preload+0x1918> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1918;
	}
x86_l_18fd:
	/* 0x18fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1902:
	/* 0x1902: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1906:
	/* 0x1906: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1909:
	/* 0x1909: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190e:
	/* 0x190e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1910:
	/* 0x1910: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1912:
	/* 0x1912: js     525d <generic_sleepable_preload+0x525d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21085ULL;
	}
x86_l_1918:
	/* 0x1918: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191d:
	/* 0x191d: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1926:
	/* 0x1926: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_192c:
	/* 0x192c: mov    eax,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1933:
	/* 0x1933: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1937:
	/* 0x1937: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1940:
	/* 0x1940: je     1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6740ULL;
	}
x86_l_1946:
	/* 0x1946: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_194b:
	/* 0x194b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194f:
	/* 0x194f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1952:
	/* 0x1952: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1957:
	/* 0x1957: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1959:
	/* 0x1959: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195b:
	/* 0x195b: jns    1a54 <generic_sleepable_preload+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 6740ULL;
	}
x86_l_1961:
	/* 0x1961: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1966:
	/* 0x1966: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_196b:
	/* 0x196b: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1970:
	/* 0x1970: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_1975:
	/* 0x1975: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_197a:
	/* 0x197a: jmp    19cf <generic_sleepable_preload+0x19cf> */
	goto x86_l_19cf;
x86_l_197c:
	/* 0x197c: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1981:
	/* 0x1981: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_1986:
	/* 0x1986: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_198b:
	/* 0x198b: jmp    19cf <generic_sleepable_preload+0x19cf> */
	goto x86_l_19cf;
x86_l_198d:
	/* 0x198d: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1992:
	/* 0x1992: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_1997:
	/* 0x1997: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_199c:
	/* 0x199c: jmp    19cf <generic_sleepable_preload+0x19cf> */
	goto x86_l_19cf;
x86_l_199e:
	/* 0x199e: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_19a3:
	/* 0x19a3: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_19a8:
	/* 0x19a8: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_19ad:
	/* 0x19ad: jmp    19cf <generic_sleepable_preload+0x19cf> */
	goto x86_l_19cf;
x86_l_19af:
	/* 0x19af: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_19b4:
	/* 0x19b4: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_19b9:
	/* 0x19b9: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_19be:
	/* 0x19be: jmp    19cf <generic_sleepable_preload+0x19cf> */
	goto x86_l_19cf;
x86_l_19c0:
	/* 0x19c0: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_19c5:
	/* 0x19c5: jmp    1a51 <generic_sleepable_preload+0x1a51> */
	return 6737ULL;
x86_l_19ca:
	/* 0x19ca: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_19cf:
	/* 0x19cf: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d2:
	/* 0x19d2: mov    ebx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19d6:
	/* 0x19d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19db:
	/* 0x19db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19de:
	/* 0x19de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19e3:
	/* 0x19e3: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_19e6:
	/* 0x19e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e8:
	/* 0x19e8: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_19eb:
	/* 0x19eb: jne    1af2 <generic_sleepable_preload+0x1af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6898ULL;
	}
x86_l_19f1:
	/* 0x19f1: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f5:
	/* 0x19f5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_19fa:
	/* 0x19fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fc:
	/* 0x19fc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a01:
	/* 0x1a01: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1a09:
	/* 0x1a09: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a0e:
	/* 0x1a0e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1a15:
	/* 0x1a15: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a1a:
	/* 0x1a1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1c:
	/* 0x1a1c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a1f:
	/* 0x1a1f: je     1af2 <generic_sleepable_preload+0x1af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6898ULL;
	}
x86_l_1a25:
	/* 0x1a25: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1a32:
	/* 0x1a32: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a37:
	/* 0x1a37: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a3a:
	/* 0x1a3a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1a3d:
	/* 0x1a3d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
	return 6720ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6720ULL: goto x86_l_1a40;
	case 6722ULL: goto x86_l_1a42;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6740ULL: goto x86_l_1a54;
	case 6743ULL: goto x86_l_1a57;
	case 6749ULL: goto x86_l_1a5d;
	case 6753ULL: goto x86_l_1a61;
	case 6758ULL: goto x86_l_1a66;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6792ULL: goto x86_l_1a88;
	case 6795ULL: goto x86_l_1a8b;
	case 6797ULL: goto x86_l_1a8d;
	case 6803ULL: goto x86_l_1a93;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6818ULL: goto x86_l_1aa2;
	case 6821ULL: goto x86_l_1aa5;
	case 6824ULL: goto x86_l_1aa8;
	case 6826ULL: goto x86_l_1aaa;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6845ULL: goto x86_l_1abd;
	case 6847ULL: goto x86_l_1abf;
	case 6850ULL: goto x86_l_1ac2;
	case 6852ULL: goto x86_l_1ac4;
	case 6855ULL: goto x86_l_1ac7;
	case 6857ULL: goto x86_l_1ac9;
	case 6860ULL: goto x86_l_1acc;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6872ULL: goto x86_l_1ad8;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6882ULL: goto x86_l_1ae2;
	case 6884ULL: goto x86_l_1ae4;
	case 6887ULL: goto x86_l_1ae7;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6918ULL: goto x86_l_1b06;
	case 6920ULL: goto x86_l_1b08;
	case 6922ULL: goto x86_l_1b0a;
	case 6926ULL: goto x86_l_1b0e;
	case 6929ULL: goto x86_l_1b11;
	case 6935ULL: goto x86_l_1b17;
	case 6938ULL: goto x86_l_1b1a;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6953ULL: goto x86_l_1b29;
	case 6956ULL: goto x86_l_1b2c;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6972ULL: goto x86_l_1b3c;
	case 6980ULL: goto x86_l_1b44;
	case 6988ULL: goto x86_l_1b4c;
	case 6994ULL: goto x86_l_1b52;
	case 6996ULL: goto x86_l_1b54;
	case 6999ULL: goto x86_l_1b57;
	case 7001ULL: goto x86_l_1b59;
	case 7004ULL: goto x86_l_1b5c;
	case 7006ULL: goto x86_l_1b5e;
	case 7009ULL: goto x86_l_1b61;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7023ULL: goto x86_l_1b6f;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7037ULL: goto x86_l_1b7d;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7067ULL: goto x86_l_1b9b;
	case 7070ULL: goto x86_l_1b9e;
	case 7076ULL: goto x86_l_1ba4;
	case 7078ULL: goto x86_l_1ba6;
	case 7084ULL: goto x86_l_1bac;
	case 7087ULL: goto x86_l_1baf;
	case 7090ULL: goto x86_l_1bb2;
	case 7096ULL: goto x86_l_1bb8;
	case 7101ULL: goto x86_l_1bbd;
	case 7103ULL: goto x86_l_1bbf;
	case 7105ULL: goto x86_l_1bc1;
	case 7108ULL: goto x86_l_1bc4;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7117ULL: goto x86_l_1bcd;
	case 7120ULL: goto x86_l_1bd0;
	case 7126ULL: goto x86_l_1bd6;
	case 7134ULL: goto x86_l_1bde;
	case 7137ULL: goto x86_l_1be1;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7151ULL: goto x86_l_1bef;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7165ULL: goto x86_l_1bfd;
	case 7171ULL: goto x86_l_1c03;
	case 7179ULL: goto x86_l_1c0b;
	case 7182ULL: goto x86_l_1c0e;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7196ULL: goto x86_l_1c1c;
	case 7202ULL: goto x86_l_1c22;
	case 7207ULL: goto x86_l_1c27;
	case 7212ULL: goto x86_l_1c2c;
	case 7214ULL: goto x86_l_1c2e;
	case 7219ULL: goto x86_l_1c33;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7229ULL: goto x86_l_1c3d;
	case 7233ULL: goto x86_l_1c41;
	case 7235ULL: goto x86_l_1c43;
	case 7238ULL: goto x86_l_1c46;
	case 7247ULL: goto x86_l_1c4f;
	case 7253ULL: goto x86_l_1c55;
	case 7260ULL: goto x86_l_1c5c;
	case 7263ULL: goto x86_l_1c5f;
	case 7270ULL: goto x86_l_1c66;
	case 7273ULL: goto x86_l_1c69;
	case 7277ULL: goto x86_l_1c6d;
	case 7285ULL: goto x86_l_1c75;
	case 7287ULL: goto x86_l_1c77;
	case 7293ULL: goto x86_l_1c7d;
	case 7296ULL: goto x86_l_1c80;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7307ULL: goto x86_l_1c8b;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7317ULL: goto x86_l_1c95;
	case 7319ULL: goto x86_l_1c97;
	case 7325ULL: goto x86_l_1c9d;
	case 7334ULL: goto x86_l_1ca6;
	case 7340ULL: goto x86_l_1cac;
	case 7347ULL: goto x86_l_1cb3;
	case 7351ULL: goto x86_l_1cb7;
	case 7360ULL: goto x86_l_1cc0;
	case 7362ULL: goto x86_l_1cc2;
	case 7367ULL: goto x86_l_1cc7;
	case 7371ULL: goto x86_l_1ccb;
	case 7374ULL: goto x86_l_1cce;
	case 7379ULL: goto x86_l_1cd3;
	case 7381ULL: goto x86_l_1cd5;
	case 7383ULL: goto x86_l_1cd7;
	case 7389ULL: goto x86_l_1cdd;
	case 7398ULL: goto x86_l_1ce6;
	case 7404ULL: goto x86_l_1cec;
	case 7411ULL: goto x86_l_1cf3;
	case 7415ULL: goto x86_l_1cf7;
	case 7424ULL: goto x86_l_1d00;
	case 7426ULL: goto x86_l_1d02;
	case 7431ULL: goto x86_l_1d07;
	case 7435ULL: goto x86_l_1d0b;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7445ULL: goto x86_l_1d15;
	case 7447ULL: goto x86_l_1d17;
	case 7453ULL: goto x86_l_1d1d;
	case 7462ULL: goto x86_l_1d26;
	case 7468ULL: goto x86_l_1d2c;
	case 7475ULL: goto x86_l_1d33;
	case 7479ULL: goto x86_l_1d37;
	case 7488ULL: goto x86_l_1d40;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7499ULL: goto x86_l_1d4b;
	case 7502ULL: goto x86_l_1d4e;
	case 7507ULL: goto x86_l_1d53;
	case 7509ULL: goto x86_l_1d55;
	case 7511ULL: goto x86_l_1d57;
	case 7517ULL: goto x86_l_1d5d;
	case 7526ULL: goto x86_l_1d66;
	case 7532ULL: goto x86_l_1d6c;
	case 7539ULL: goto x86_l_1d73;
	case 7543ULL: goto x86_l_1d77;
	case 7552ULL: goto x86_l_1d80;
	case 7554ULL: goto x86_l_1d82;
	case 7559ULL: goto x86_l_1d87;
	case 7563ULL: goto x86_l_1d8b;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7573ULL: goto x86_l_1d95;
	case 7575ULL: goto x86_l_1d97;
	case 7581ULL: goto x86_l_1d9d;
	case 7590ULL: goto x86_l_1da6;
	case 7596ULL: goto x86_l_1dac;
	case 7603ULL: goto x86_l_1db3;
	case 7607ULL: goto x86_l_1db7;
	case 7616ULL: goto x86_l_1dc0;
	case 7618ULL: goto x86_l_1dc2;
	case 7623ULL: goto x86_l_1dc7;
	case 7627ULL: goto x86_l_1dcb;
	case 7630ULL: goto x86_l_1dce;
	case 7635ULL: goto x86_l_1dd3;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	case 7645ULL: goto x86_l_1ddd;
	case 7654ULL: goto x86_l_1de6;
	case 7660ULL: goto x86_l_1dec;
	case 7667ULL: goto x86_l_1df3;
	case 7671ULL: goto x86_l_1df7;
	case 7680ULL: goto x86_l_1e00;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7701ULL: goto x86_l_1e15;
	case 7703ULL: goto x86_l_1e17;
	case 7709ULL: goto x86_l_1e1d;
	case 7718ULL: goto x86_l_1e26;
	case 7724ULL: goto x86_l_1e2c;
	case 7731ULL: goto x86_l_1e33;
	case 7735ULL: goto x86_l_1e37;
	case 7744ULL: goto x86_l_1e40;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7765ULL: goto x86_l_1e55;
	case 7767ULL: goto x86_l_1e57;
	case 7773ULL: goto x86_l_1e5d;
	case 7782ULL: goto x86_l_1e66;
	case 7788ULL: goto x86_l_1e6c;
	case 7795ULL: goto x86_l_1e73;
	case 7799ULL: goto x86_l_1e77;
	case 7808ULL: goto x86_l_1e80;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7819ULL: goto x86_l_1e8b;
	case 7822ULL: goto x86_l_1e8e;
	case 7827ULL: goto x86_l_1e93;
	case 7829ULL: goto x86_l_1e95;
	case 7831ULL: goto x86_l_1e97;
	case 7837ULL: goto x86_l_1e9d;
	case 7842ULL: goto x86_l_1ea2;
	case 7851ULL: goto x86_l_1eab;
	case 7857ULL: goto x86_l_1eb1;
	case 7864ULL: goto x86_l_1eb8;
	case 7868ULL: goto x86_l_1ebc;
	case 7877ULL: goto x86_l_1ec5;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7893ULL: goto x86_l_1ed5;
	case 7896ULL: goto x86_l_1ed8;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7907ULL: goto x86_l_1ee3;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7917ULL: goto x86_l_1eed;
	case 7919ULL: goto x86_l_1eef;
	case 7925ULL: goto x86_l_1ef5;
	case 7934ULL: goto x86_l_1efe;
	case 7940ULL: goto x86_l_1f04;
	case 7947ULL: goto x86_l_1f0b;
	case 7951ULL: goto x86_l_1f0f;
	case 7960ULL: goto x86_l_1f18;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7971ULL: goto x86_l_1f23;
	case 7974ULL: goto x86_l_1f26;
	case 7979ULL: goto x86_l_1f2b;
	case 7981ULL: goto x86_l_1f2d;
	case 7983ULL: goto x86_l_1f2f;
	case 7989ULL: goto x86_l_1f35;
	case 7998ULL: goto x86_l_1f3e;
	case 8004ULL: goto x86_l_1f44;
	case 8011ULL: goto x86_l_1f4b;
	case 8015ULL: goto x86_l_1f4f;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8031ULL: goto x86_l_1f5f;
	case 8035ULL: goto x86_l_1f63;
	case 8038ULL: goto x86_l_1f66;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8047ULL: goto x86_l_1f6f;
	case 8053ULL: goto x86_l_1f75;
	case 8062ULL: goto x86_l_1f7e;
	case 8068ULL: goto x86_l_1f84;
	case 8075ULL: goto x86_l_1f8b;
	case 8079ULL: goto x86_l_1f8f;
	case 8088ULL: goto x86_l_1f98;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8099ULL: goto x86_l_1fa3;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8109ULL: goto x86_l_1fad;
	case 8111ULL: goto x86_l_1faf;
	case 8117ULL: goto x86_l_1fb5;
	case 8126ULL: goto x86_l_1fbe;
	case 8132ULL: goto x86_l_1fc4;
	case 8139ULL: goto x86_l_1fcb;
	case 8143ULL: goto x86_l_1fcf;
	case 8152ULL: goto x86_l_1fd8;
	case 8154ULL: goto x86_l_1fda;
	case 8159ULL: goto x86_l_1fdf;
	case 8163ULL: goto x86_l_1fe3;
	case 8166ULL: goto x86_l_1fe6;
	case 8171ULL: goto x86_l_1feb;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8181ULL: goto x86_l_1ff5;
	case 8190ULL: goto x86_l_1ffe;
	case 8196ULL: goto x86_l_2004;
	case 8203ULL: goto x86_l_200b;
	case 8207ULL: goto x86_l_200f;
	case 8216ULL: goto x86_l_2018;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8235ULL: goto x86_l_202b;
	case 8237ULL: goto x86_l_202d;
	case 8239ULL: goto x86_l_202f;
	case 8245ULL: goto x86_l_2035;
	case 8254ULL: goto x86_l_203e;
	case 8260ULL: goto x86_l_2044;
	case 8267ULL: goto x86_l_204b;
	case 8271ULL: goto x86_l_204f;
	case 8280ULL: goto x86_l_2058;
	case 8282ULL: goto x86_l_205a;
	case 8287ULL: goto x86_l_205f;
	case 8291ULL: goto x86_l_2063;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8301ULL: goto x86_l_206d;
	case 8303ULL: goto x86_l_206f;
	case 8309ULL: goto x86_l_2075;
	case 8318ULL: goto x86_l_207e;
	case 8324ULL: goto x86_l_2084;
	case 8331ULL: goto x86_l_208b;
	case 8335ULL: goto x86_l_208f;
	case 8344ULL: goto x86_l_2098;
	case 8346ULL: goto x86_l_209a;
	case 8351ULL: goto x86_l_209f;
	case 8355ULL: goto x86_l_20a3;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8365ULL: goto x86_l_20ad;
	case 8367ULL: goto x86_l_20af;
	case 8373ULL: goto x86_l_20b5;
	case 8378ULL: goto x86_l_20ba;
	case 8387ULL: goto x86_l_20c3;
	case 8393ULL: goto x86_l_20c9;
	case 8400ULL: goto x86_l_20d0;
	case 8404ULL: goto x86_l_20d4;
	case 8413ULL: goto x86_l_20dd;
	case 8415ULL: goto x86_l_20df;
	case 8420ULL: goto x86_l_20e4;
	case 8424ULL: goto x86_l_20e8;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8434ULL: goto x86_l_20f2;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8447ULL: goto x86_l_20ff;
	case 8456ULL: goto x86_l_2108;
	case 8462ULL: goto x86_l_210e;
	case 8469ULL: goto x86_l_2115;
	case 8473ULL: goto x86_l_2119;
	case 8482ULL: goto x86_l_2122;
	case 8488ULL: goto x86_l_2128;
	case 8493ULL: goto x86_l_212d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1a40:
	/* 0x1a40: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a42:
	/* 0x1a42: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1a45:
	/* 0x1a45: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a4a:
	/* 0x1a4a: jmp    1ab2 <generic_sleepable_preload+0x1ab2> */
	goto x86_l_1ab2;
x86_l_1a4c:
	/* 0x1a4c: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_1a51:
	/* 0x1a51: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a54:
	/* 0x1a54: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1a57:
	/* 0x1a57: jne    1af2 <generic_sleepable_preload+0x1af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1af2;
	}
x86_l_1a5d:
	/* 0x1a5d: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a61:
	/* 0x1a61: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1a66:
	/* 0x1a66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a68:
	/* 0x1a68: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1a75:
	/* 0x1a75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a7a:
	/* 0x1a7a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1a81:
	/* 0x1a81: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a86:
	/* 0x1a86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a88:
	/* 0x1a88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a8b:
	/* 0x1a8b: je     1af2 <generic_sleepable_preload+0x1af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af2;
	}
x86_l_1a8d:
	/* 0x1a8d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1a93:
	/* 0x1a93: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1a9a:
	/* 0x1a9a: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1aa2:
	/* 0x1aa2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1aa5:
	/* 0x1aa5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1aa8:
	/* 0x1aa8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aaa:
	/* 0x1aaa: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1aad:
	/* 0x1aad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ab2:
	/* 0x1ab2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ab5:
	/* 0x1ab5: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1ab8:
	/* 0x1ab8: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1abd:
	/* 0x1abd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abf:
	/* 0x1abf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ac2:
	/* 0x1ac2: je     1af2 <generic_sleepable_preload+0x1af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af2;
	}
x86_l_1ac4:
	/* 0x1ac4: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_1ac7:
	/* 0x1ac7: je     1af0 <generic_sleepable_preload+0x1af0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af0;
	}
x86_l_1ac9:
	/* 0x1ac9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1acc:
	/* 0x1acc: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ad5:
	/* 0x1ad5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ad8:
	/* 0x1ad8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ada:
	/* 0x1ada: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1add:
	/* 0x1add: call   1ae2 <generic_sleepable_preload+0x1ae2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1ae2:
	/* 0x1ae2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1ae4:
	/* 0x1ae4: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_1ae7:
	/* 0x1ae7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1ae9:
	/* 0x1ae9: jns    1af0 <generic_sleepable_preload+0x1af0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1af0;
	}
x86_l_1aeb:
	/* 0x1aeb: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_1af0:
	/* 0x1af0: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af2:
	/* 0x1af2: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1af7:
	/* 0x1af7: mov    eax,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1afb:
	/* 0x1afb: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1b00:
	/* 0x1b00: je     db1 <generic_sleepable_preload+0xdb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3505ULL;
	}
x86_l_1b06:
	/* 0x1b06: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1b08:
	/* 0x1b08: js     1b3c <generic_sleepable_preload+0x1b3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b3c;
	}
x86_l_1b0a:
	/* 0x1b0a: mov    ecx,DWORD PTR [r13+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1b0e:
	/* 0x1b0e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1b11:
	/* 0x1b11: jle    1bbd <generic_sleepable_preload+0x1bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bbd;
	}
x86_l_1b17:
	/* 0x1b17: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b1a:
	/* 0x1b1a: je     1c27 <generic_sleepable_preload+0x1c27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c27;
	}
x86_l_1b20:
	/* 0x1b20: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1b23:
	/* 0x1b23: je     1c2e <generic_sleepable_preload+0x1c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2e;
	}
x86_l_1b29:
	/* 0x1b29: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b2c:
	/* 0x1b2c: jne    1c41 <generic_sleepable_preload+0x1c41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c41;
	}
x86_l_1b32:
	/* 0x1b32: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b37:
	/* 0x1b37: jmp    1c3a <generic_sleepable_preload+0x1c3a> */
	goto x86_l_1c3a;
x86_l_1b3c:
	/* 0x1b3c: movzx  ecx,BYTE PTR [r13+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_1b44:
	/* 0x1b44: movzx  eax,WORD PTR [r13+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_1b4c:
	/* 0x1b4c: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_1b52:
	/* 0x1b52: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b54:
	/* 0x1b54: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1b57:
	/* 0x1b57: jle    1b96 <generic_sleepable_preload+0x1b96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b96;
	}
x86_l_1b59:
	/* 0x1b59: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1b5c:
	/* 0x1b5c: jle    1bcd <generic_sleepable_preload+0x1bcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bcd;
	}
x86_l_1b5e:
	/* 0x1b5e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1b61:
	/* 0x1b61: jle    21a2 <generic_sleepable_preload+0x21a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8610ULL;
	}
x86_l_1b67:
	/* 0x1b67: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b6c:
	/* 0x1b6c: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1b6f:
	/* 0x1b6f: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8647ULL;
	}
x86_l_1b75:
	/* 0x1b75: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b7a:
	/* 0x1b7a: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1b7d:
	/* 0x1b7d: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8647ULL;
	}
x86_l_1b83:
	/* 0x1b83: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b88:
	/* 0x1b88: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1b8b:
	/* 0x1b8b: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8647ULL;
	}
x86_l_1b91:
	/* 0x1b91: jmp    21da <generic_sleepable_preload+0x21da> */
	return 8666ULL;
x86_l_1b96:
	/* 0x1b96: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1b99:
	/* 0x1b99: jg     1bfa <generic_sleepable_preload+0x1bfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1bfa;
	}
x86_l_1b9b:
	/* 0x1b9b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1b9e:
	/* 0x1b9e: jg     2170 <generic_sleepable_preload+0x2170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8560ULL;
	}
x86_l_1ba4:
	/* 0x1ba4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1ba6:
	/* 0x1ba6: je     21c2 <generic_sleepable_preload+0x21c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8642ULL;
	}
x86_l_1bac:
	/* 0x1bac: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_1baf:
	/* 0x1baf: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1bb2:
	/* 0x1bb2: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8647ULL;
	}
x86_l_1bb8:
	/* 0x1bb8: jmp    21da <generic_sleepable_preload+0x21da> */
	return 8666ULL;
x86_l_1bbd:
	/* 0x1bbd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1bbf:
	/* 0x1bbf: je     1c35 <generic_sleepable_preload+0x1c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c35;
	}
x86_l_1bc1:
	/* 0x1bc1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1bc4:
	/* 0x1bc4: jne    1c41 <generic_sleepable_preload+0x1c41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c41;
	}
x86_l_1bc6:
	/* 0x1bc6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bcb:
	/* 0x1bcb: jmp    1c3a <generic_sleepable_preload+0x1c3a> */
	goto x86_l_1c3a;
x86_l_1bcd:
	/* 0x1bcd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1bd0:
	/* 0x1bd0: jg     2157 <generic_sleepable_preload+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8535ULL;
	}
x86_l_1bd6:
	/* 0x1bd6: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1bde:
	/* 0x1bde: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1be1:
	/* 0x1be1: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8647ULL;
	}
x86_l_1be7:
	/* 0x1be7: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bec:
	/* 0x1bec: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1bef:
	/* 0x1bef: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8647ULL;
	}
x86_l_1bf5:
	/* 0x1bf5: jmp    21da <generic_sleepable_preload+0x21da> */
	return 8666ULL;
x86_l_1bfa:
	/* 0x1bfa: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1bfd:
	/* 0x1bfd: jg     2189 <generic_sleepable_preload+0x2189> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8585ULL;
	}
x86_l_1c03:
	/* 0x1c03: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c0b:
	/* 0x1c0b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1c0e:
	/* 0x1c0e: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8647ULL;
	}
x86_l_1c14:
	/* 0x1c14: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c19:
	/* 0x1c19: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1c1c:
	/* 0x1c1c: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8647ULL;
	}
x86_l_1c22:
	/* 0x1c22: jmp    21da <generic_sleepable_preload+0x21da> */
	return 8666ULL;
x86_l_1c27:
	/* 0x1c27: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c2c:
	/* 0x1c2c: jmp    1c3a <generic_sleepable_preload+0x1c3a> */
	goto x86_l_1c3a;
x86_l_1c2e:
	/* 0x1c2e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c33:
	/* 0x1c33: jmp    1c3a <generic_sleepable_preload+0x1c3a> */
	goto x86_l_1c3a;
x86_l_1c35:
	/* 0x1c35: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c3a:
	/* 0x1c3a: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c41:
	/* 0x1c41: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c43:
	/* 0x1c43: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_1c46:
	/* 0x1c46: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_1c4f:
	/* 0x1c4f: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1c55:
	/* 0x1c55: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1c5c:
	/* 0x1c5c: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    edx,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c66:
	/* 0x1c66: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c69:
	/* 0x1c69: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c6d:
	/* 0x1c6d: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_1c75:
	/* 0x1c75: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_1c77:
	/* 0x1c77: je     1ed5 <generic_sleepable_preload+0x1ed5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ed5;
	}
x86_l_1c7d:
	/* 0x1c7d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1c80:
	/* 0x1c80: je     1c9d <generic_sleepable_preload+0x1c9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c9d;
	}
x86_l_1c82:
	/* 0x1c82: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c87:
	/* 0x1c87: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c8e:
	/* 0x1c8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c93:
	/* 0x1c93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c95:
	/* 0x1c95: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c97:
	/* 0x1c97: js     214d <generic_sleepable_preload+0x214d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8525ULL;
	}
x86_l_1c9d:
	/* 0x1c9d: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1ca6:
	/* 0x1ca6: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1cac:
	/* 0x1cac: mov    eax,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1cb3:
	/* 0x1cb3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1cb7:
	/* 0x1cb7: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_1cc0:
	/* 0x1cc0: je     1cdd <generic_sleepable_preload+0x1cdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cdd;
	}
x86_l_1cc2:
	/* 0x1cc2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ccb:
	/* 0x1ccb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cce:
	/* 0x1cce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd3:
	/* 0x1cd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd5:
	/* 0x1cd5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cd7:
	/* 0x1cd7: js     21b8 <generic_sleepable_preload+0x21b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8632ULL;
	}
x86_l_1cdd:
	/* 0x1cdd: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_1ce6:
	/* 0x1ce6: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1cec:
	/* 0x1cec: mov    eax,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1cf3:
	/* 0x1cf3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1cf7:
	/* 0x1cf7: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_1d00:
	/* 0x1d00: je     1d1d <generic_sleepable_preload+0x1d1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d1d;
	}
x86_l_1d02:
	/* 0x1d02: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d07:
	/* 0x1d07: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d0e:
	/* 0x1d0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d13:
	/* 0x1d13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d15:
	/* 0x1d15: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d17:
	/* 0x1d17: js     2702 <generic_sleepable_preload+0x2702> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9986ULL;
	}
x86_l_1d1d:
	/* 0x1d1d: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_1d26:
	/* 0x1d26: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1d2c:
	/* 0x1d2c: mov    eax,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1d33:
	/* 0x1d33: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d37:
	/* 0x1d37: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_1d40:
	/* 0x1d40: je     1d5d <generic_sleepable_preload+0x1d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d5d;
	}
x86_l_1d42:
	/* 0x1d42: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d47:
	/* 0x1d47: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d4b:
	/* 0x1d4b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d4e:
	/* 0x1d4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d53:
	/* 0x1d53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d55:
	/* 0x1d55: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d57:
	/* 0x1d57: js     2713 <generic_sleepable_preload+0x2713> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10003ULL;
	}
x86_l_1d5d:
	/* 0x1d5d: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_1d66:
	/* 0x1d66: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1d6c:
	/* 0x1d6c: mov    eax,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1d73:
	/* 0x1d73: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1d77:
	/* 0x1d77: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_1d80:
	/* 0x1d80: je     1d9d <generic_sleepable_preload+0x1d9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d9d;
	}
x86_l_1d82:
	/* 0x1d82: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d87:
	/* 0x1d87: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d8e:
	/* 0x1d8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d93:
	/* 0x1d93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d95:
	/* 0x1d95: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d97:
	/* 0x1d97: js     2724 <generic_sleepable_preload+0x2724> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10020ULL;
	}
x86_l_1d9d:
	/* 0x1d9d: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_1da6:
	/* 0x1da6: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1dac:
	/* 0x1dac: mov    eax,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1db3:
	/* 0x1db3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1db7:
	/* 0x1db7: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_1dc0:
	/* 0x1dc0: je     1ddd <generic_sleepable_preload+0x1ddd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ddd;
	}
x86_l_1dc2:
	/* 0x1dc2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dcb:
	/* 0x1dcb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1dce:
	/* 0x1dce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dd3:
	/* 0x1dd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd5:
	/* 0x1dd5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd7:
	/* 0x1dd7: js     2735 <generic_sleepable_preload+0x2735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10037ULL;
	}
x86_l_1ddd:
	/* 0x1ddd: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_1de6:
	/* 0x1de6: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1dec:
	/* 0x1dec: mov    eax,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1df3:
	/* 0x1df3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1df7:
	/* 0x1df7: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_1e00:
	/* 0x1e00: je     1e1d <generic_sleepable_preload+0x1e1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e1d;
	}
x86_l_1e02:
	/* 0x1e02: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e07:
	/* 0x1e07: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e0e:
	/* 0x1e0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e13:
	/* 0x1e13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e15:
	/* 0x1e15: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e17:
	/* 0x1e17: js     2746 <generic_sleepable_preload+0x2746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10054ULL;
	}
x86_l_1e1d:
	/* 0x1e1d: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_1e26:
	/* 0x1e26: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1e2c:
	/* 0x1e2c: mov    eax,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1e33:
	/* 0x1e33: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e37:
	/* 0x1e37: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_1e40:
	/* 0x1e40: je     1e5d <generic_sleepable_preload+0x1e5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e5d;
	}
x86_l_1e42:
	/* 0x1e42: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e47:
	/* 0x1e47: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e4b:
	/* 0x1e4b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e4e:
	/* 0x1e4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e53:
	/* 0x1e53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e55:
	/* 0x1e55: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e57:
	/* 0x1e57: js     51fd <generic_sleepable_preload+0x51fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20989ULL;
	}
x86_l_1e5d:
	/* 0x1e5d: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_1e66:
	/* 0x1e66: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1e6c:
	/* 0x1e6c: mov    eax,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1e73:
	/* 0x1e73: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1e77:
	/* 0x1e77: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_1e80:
	/* 0x1e80: je     1e9d <generic_sleepable_preload+0x1e9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e9d;
	}
x86_l_1e82:
	/* 0x1e82: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e87:
	/* 0x1e87: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e8e:
	/* 0x1e8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e93:
	/* 0x1e93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e95:
	/* 0x1e95: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e97:
	/* 0x1e97: js     526f <generic_sleepable_preload+0x526f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21103ULL;
	}
x86_l_1e9d:
	/* 0x1e9d: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea2:
	/* 0x1ea2: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_1eab:
	/* 0x1eab: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1eb1:
	/* 0x1eb1: mov    eax,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1eb8:
	/* 0x1eb8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ebc:
	/* 0x1ebc: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_1ec5:
	/* 0x1ec5: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1ecb:
	/* 0x1ecb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ed0:
	/* 0x1ed0: jmp    212d <generic_sleepable_preload+0x212d> */
	goto x86_l_212d;
x86_l_1ed5:
	/* 0x1ed5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1ed8:
	/* 0x1ed8: je     1ef5 <generic_sleepable_preload+0x1ef5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ef5;
	}
x86_l_1eda:
	/* 0x1eda: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1edf:
	/* 0x1edf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ee6:
	/* 0x1ee6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eeb:
	/* 0x1eeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eed:
	/* 0x1eed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eef:
	/* 0x1eef: js     214d <generic_sleepable_preload+0x214d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8525ULL;
	}
x86_l_1ef5:
	/* 0x1ef5: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_1efe:
	/* 0x1efe: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1f04:
	/* 0x1f04: mov    eax,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1f0b:
	/* 0x1f0b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1f0f:
	/* 0x1f0f: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_1f18:
	/* 0x1f18: je     1f35 <generic_sleepable_preload+0x1f35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f35;
	}
x86_l_1f1a:
	/* 0x1f1a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f1f:
	/* 0x1f1f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f23:
	/* 0x1f23: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f26:
	/* 0x1f26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f2b:
	/* 0x1f2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2d:
	/* 0x1f2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f2f:
	/* 0x1f2f: js     21b8 <generic_sleepable_preload+0x21b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8632ULL;
	}
x86_l_1f35:
	/* 0x1f35: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_1f3e:
	/* 0x1f3e: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1f44:
	/* 0x1f44: mov    eax,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1f4b:
	/* 0x1f4b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1f4f:
	/* 0x1f4f: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_1f58:
	/* 0x1f58: je     1f75 <generic_sleepable_preload+0x1f75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f75;
	}
x86_l_1f5a:
	/* 0x1f5a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f5f:
	/* 0x1f5f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f63:
	/* 0x1f63: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f66:
	/* 0x1f66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f6b:
	/* 0x1f6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6d:
	/* 0x1f6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f6f:
	/* 0x1f6f: js     2702 <generic_sleepable_preload+0x2702> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9986ULL;
	}
x86_l_1f75:
	/* 0x1f75: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_1f7e:
	/* 0x1f7e: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1f84:
	/* 0x1f84: mov    eax,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1f8b:
	/* 0x1f8b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1f8f:
	/* 0x1f8f: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_1f98:
	/* 0x1f98: je     1fb5 <generic_sleepable_preload+0x1fb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb5;
	}
x86_l_1f9a:
	/* 0x1f9a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f9f:
	/* 0x1f9f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa3:
	/* 0x1fa3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fa6:
	/* 0x1fa6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fab:
	/* 0x1fab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fad:
	/* 0x1fad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1faf:
	/* 0x1faf: js     2713 <generic_sleepable_preload+0x2713> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10003ULL;
	}
x86_l_1fb5:
	/* 0x1fb5: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_1fbe:
	/* 0x1fbe: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_1fc4:
	/* 0x1fc4: mov    eax,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1fcb:
	/* 0x1fcb: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1fcf:
	/* 0x1fcf: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_1fd8:
	/* 0x1fd8: je     1ff5 <generic_sleepable_preload+0x1ff5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff5;
	}
x86_l_1fda:
	/* 0x1fda: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fdf:
	/* 0x1fdf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe3:
	/* 0x1fe3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1fe6:
	/* 0x1fe6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1feb:
	/* 0x1feb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fed:
	/* 0x1fed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fef:
	/* 0x1fef: js     2724 <generic_sleepable_preload+0x2724> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10020ULL;
	}
x86_l_1ff5:
	/* 0x1ff5: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_1ffe:
	/* 0x1ffe: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_2004:
	/* 0x2004: mov    eax,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_200b:
	/* 0x200b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_200f:
	/* 0x200f: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2018:
	/* 0x2018: je     2035 <generic_sleepable_preload+0x2035> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2035;
	}
x86_l_201a:
	/* 0x201a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_201f:
	/* 0x201f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2023:
	/* 0x2023: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2026:
	/* 0x2026: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_202b:
	/* 0x202b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202d:
	/* 0x202d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_202f:
	/* 0x202f: js     2735 <generic_sleepable_preload+0x2735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10037ULL;
	}
x86_l_2035:
	/* 0x2035: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_203e:
	/* 0x203e: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_2044:
	/* 0x2044: mov    eax,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_204b:
	/* 0x204b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_204f:
	/* 0x204f: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2058:
	/* 0x2058: je     2075 <generic_sleepable_preload+0x2075> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2075;
	}
x86_l_205a:
	/* 0x205a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_205f:
	/* 0x205f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2063:
	/* 0x2063: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2066:
	/* 0x2066: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_206b:
	/* 0x206b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206d:
	/* 0x206d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_206f:
	/* 0x206f: js     2746 <generic_sleepable_preload+0x2746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10054ULL;
	}
x86_l_2075:
	/* 0x2075: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_207e:
	/* 0x207e: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_2084:
	/* 0x2084: mov    eax,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_208b:
	/* 0x208b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_208f:
	/* 0x208f: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2098:
	/* 0x2098: je     20b5 <generic_sleepable_preload+0x20b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b5;
	}
x86_l_209a:
	/* 0x209a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_209f:
	/* 0x209f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a3:
	/* 0x20a3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20a6:
	/* 0x20a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20ab:
	/* 0x20ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ad:
	/* 0x20ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20af:
	/* 0x20af: js     5313 <generic_sleepable_preload+0x5313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21267ULL;
	}
x86_l_20b5:
	/* 0x20b5: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ba:
	/* 0x20ba: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_20c3:
	/* 0x20c3: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_20c9:
	/* 0x20c9: mov    eax,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_20d0:
	/* 0x20d0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20d4:
	/* 0x20d4: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_20dd:
	/* 0x20dd: je     20fa <generic_sleepable_preload+0x20fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20fa;
	}
x86_l_20df:
	/* 0x20df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20e4:
	/* 0x20e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e8:
	/* 0x20e8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20eb:
	/* 0x20eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20f0:
	/* 0x20f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f2:
	/* 0x20f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20f4:
	/* 0x20f4: js     526f <generic_sleepable_preload+0x526f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21103ULL;
	}
x86_l_20fa:
	/* 0x20fa: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ff:
	/* 0x20ff: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2108:
	/* 0x2108: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_210e:
	/* 0x210e: mov    eax,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2115:
	/* 0x2115: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2119:
	/* 0x2119: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2122:
	/* 0x2122: je     274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10062ULL;
	}
x86_l_2128:
	/* 0x2128: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_212d:
	/* 0x212d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 8497ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8497ULL: goto x86_l_2131;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8509ULL: goto x86_l_213d;
	case 8515ULL: goto x86_l_2143;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8543ULL: goto x86_l_215f;
	case 8546ULL: goto x86_l_2162;
	case 8548ULL: goto x86_l_2164;
	case 8553ULL: goto x86_l_2169;
	case 8556ULL: goto x86_l_216c;
	case 8558ULL: goto x86_l_216e;
	case 8560ULL: goto x86_l_2170;
	case 8568ULL: goto x86_l_2178;
	case 8571ULL: goto x86_l_217b;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8581ULL: goto x86_l_2185;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8593ULL: goto x86_l_2191;
	case 8596ULL: goto x86_l_2194;
	case 8598ULL: goto x86_l_2196;
	case 8603ULL: goto x86_l_219b;
	case 8606ULL: goto x86_l_219e;
	case 8608ULL: goto x86_l_21a0;
	case 8610ULL: goto x86_l_21a2;
	case 8615ULL: goto x86_l_21a7;
	case 8618ULL: goto x86_l_21aa;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8632ULL: goto x86_l_21b8;
	case 8637ULL: goto x86_l_21bd;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8650ULL: goto x86_l_21ca;
	case 8652ULL: goto x86_l_21cc;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8661ULL: goto x86_l_21d5;
	case 8666ULL: goto x86_l_21da;
	case 8670ULL: goto x86_l_21de;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8679ULL: goto x86_l_21e7;
	case 8688ULL: goto x86_l_21f0;
	case 8694ULL: goto x86_l_21f6;
	case 8701ULL: goto x86_l_21fd;
	case 8704ULL: goto x86_l_2200;
	case 8711ULL: goto x86_l_2207;
	case 8714ULL: goto x86_l_220a;
	case 8718ULL: goto x86_l_220e;
	case 8726ULL: goto x86_l_2216;
	case 8728ULL: goto x86_l_2218;
	case 8734ULL: goto x86_l_221e;
	case 8737ULL: goto x86_l_2221;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8748ULL: goto x86_l_222c;
	case 8751ULL: goto x86_l_222f;
	case 8756ULL: goto x86_l_2234;
	case 8758ULL: goto x86_l_2236;
	case 8760ULL: goto x86_l_2238;
	case 8766ULL: goto x86_l_223e;
	case 8775ULL: goto x86_l_2247;
	case 8781ULL: goto x86_l_224d;
	case 8788ULL: goto x86_l_2254;
	case 8792ULL: goto x86_l_2258;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8808ULL: goto x86_l_2268;
	case 8812ULL: goto x86_l_226c;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8822ULL: goto x86_l_2276;
	case 8824ULL: goto x86_l_2278;
	case 8830ULL: goto x86_l_227e;
	case 8839ULL: goto x86_l_2287;
	case 8845ULL: goto x86_l_228d;
	case 8852ULL: goto x86_l_2294;
	case 8856ULL: goto x86_l_2298;
	case 8865ULL: goto x86_l_22a1;
	case 8867ULL: goto x86_l_22a3;
	case 8872ULL: goto x86_l_22a8;
	case 8876ULL: goto x86_l_22ac;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8886ULL: goto x86_l_22b6;
	case 8888ULL: goto x86_l_22b8;
	case 8894ULL: goto x86_l_22be;
	case 8903ULL: goto x86_l_22c7;
	case 8909ULL: goto x86_l_22cd;
	case 8916ULL: goto x86_l_22d4;
	case 8920ULL: goto x86_l_22d8;
	case 8929ULL: goto x86_l_22e1;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8940ULL: goto x86_l_22ec;
	case 8943ULL: goto x86_l_22ef;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8952ULL: goto x86_l_22f8;
	case 8958ULL: goto x86_l_22fe;
	case 8967ULL: goto x86_l_2307;
	case 8973ULL: goto x86_l_230d;
	case 8980ULL: goto x86_l_2314;
	case 8984ULL: goto x86_l_2318;
	case 8993ULL: goto x86_l_2321;
	case 8995ULL: goto x86_l_2323;
	case 9000ULL: goto x86_l_2328;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9012ULL: goto x86_l_2334;
	case 9014ULL: goto x86_l_2336;
	case 9016ULL: goto x86_l_2338;
	case 9022ULL: goto x86_l_233e;
	case 9031ULL: goto x86_l_2347;
	case 9037ULL: goto x86_l_234d;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9057ULL: goto x86_l_2361;
	case 9059ULL: goto x86_l_2363;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9078ULL: goto x86_l_2376;
	case 9080ULL: goto x86_l_2378;
	case 9086ULL: goto x86_l_237e;
	case 9095ULL: goto x86_l_2387;
	case 9101ULL: goto x86_l_238d;
	case 9108ULL: goto x86_l_2394;
	case 9112ULL: goto x86_l_2398;
	case 9121ULL: goto x86_l_23a1;
	case 9123ULL: goto x86_l_23a3;
	case 9128ULL: goto x86_l_23a8;
	case 9132ULL: goto x86_l_23ac;
	case 9135ULL: goto x86_l_23af;
	case 9140ULL: goto x86_l_23b4;
	case 9142ULL: goto x86_l_23b6;
	case 9144ULL: goto x86_l_23b8;
	case 9150ULL: goto x86_l_23be;
	case 9159ULL: goto x86_l_23c7;
	case 9165ULL: goto x86_l_23cd;
	case 9172ULL: goto x86_l_23d4;
	case 9176ULL: goto x86_l_23d8;
	case 9185ULL: goto x86_l_23e1;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9196ULL: goto x86_l_23ec;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9206ULL: goto x86_l_23f6;
	case 9208ULL: goto x86_l_23f8;
	case 9214ULL: goto x86_l_23fe;
	case 9223ULL: goto x86_l_2407;
	case 9229ULL: goto x86_l_240d;
	case 9236ULL: goto x86_l_2414;
	case 9240ULL: goto x86_l_2418;
	case 9249ULL: goto x86_l_2421;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9268ULL: goto x86_l_2434;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9292ULL: goto x86_l_244c;
	case 9298ULL: goto x86_l_2452;
	case 9305ULL: goto x86_l_2459;
	case 9309ULL: goto x86_l_245d;
	case 9318ULL: goto x86_l_2466;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9334ULL: goto x86_l_2476;
	case 9337ULL: goto x86_l_2479;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9348ULL: goto x86_l_2484;
	case 9351ULL: goto x86_l_2487;
	case 9356ULL: goto x86_l_248c;
	case 9358ULL: goto x86_l_248e;
	case 9360ULL: goto x86_l_2490;
	case 9366ULL: goto x86_l_2496;
	case 9375ULL: goto x86_l_249f;
	case 9381ULL: goto x86_l_24a5;
	case 9388ULL: goto x86_l_24ac;
	case 9392ULL: goto x86_l_24b0;
	case 9401ULL: goto x86_l_24b9;
	case 9403ULL: goto x86_l_24bb;
	case 9408ULL: goto x86_l_24c0;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9420ULL: goto x86_l_24cc;
	case 9422ULL: goto x86_l_24ce;
	case 9424ULL: goto x86_l_24d0;
	case 9430ULL: goto x86_l_24d6;
	case 9439ULL: goto x86_l_24df;
	case 9445ULL: goto x86_l_24e5;
	case 9452ULL: goto x86_l_24ec;
	case 9456ULL: goto x86_l_24f0;
	case 9465ULL: goto x86_l_24f9;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9476ULL: goto x86_l_2504;
	case 9479ULL: goto x86_l_2507;
	case 9484ULL: goto x86_l_250c;
	case 9486ULL: goto x86_l_250e;
	case 9488ULL: goto x86_l_2510;
	case 9494ULL: goto x86_l_2516;
	case 9503ULL: goto x86_l_251f;
	case 9509ULL: goto x86_l_2525;
	case 9516ULL: goto x86_l_252c;
	case 9520ULL: goto x86_l_2530;
	case 9529ULL: goto x86_l_2539;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9540ULL: goto x86_l_2544;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9550ULL: goto x86_l_254e;
	case 9552ULL: goto x86_l_2550;
	case 9558ULL: goto x86_l_2556;
	case 9567ULL: goto x86_l_255f;
	case 9573ULL: goto x86_l_2565;
	case 9580ULL: goto x86_l_256c;
	case 9584ULL: goto x86_l_2570;
	case 9593ULL: goto x86_l_2579;
	case 9595ULL: goto x86_l_257b;
	case 9600ULL: goto x86_l_2580;
	case 9604ULL: goto x86_l_2584;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9614ULL: goto x86_l_258e;
	case 9616ULL: goto x86_l_2590;
	case 9622ULL: goto x86_l_2596;
	case 9631ULL: goto x86_l_259f;
	case 9637ULL: goto x86_l_25a5;
	case 9644ULL: goto x86_l_25ac;
	case 9648ULL: goto x86_l_25b0;
	case 9657ULL: goto x86_l_25b9;
	case 9659ULL: goto x86_l_25bb;
	case 9664ULL: goto x86_l_25c0;
	case 9668ULL: goto x86_l_25c4;
	case 9671ULL: goto x86_l_25c7;
	case 9676ULL: goto x86_l_25cc;
	case 9678ULL: goto x86_l_25ce;
	case 9680ULL: goto x86_l_25d0;
	case 9686ULL: goto x86_l_25d6;
	case 9695ULL: goto x86_l_25df;
	case 9701ULL: goto x86_l_25e5;
	case 9708ULL: goto x86_l_25ec;
	case 9712ULL: goto x86_l_25f0;
	case 9721ULL: goto x86_l_25f9;
	case 9723ULL: goto x86_l_25fb;
	case 9728ULL: goto x86_l_2600;
	case 9732ULL: goto x86_l_2604;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9742ULL: goto x86_l_260e;
	case 9744ULL: goto x86_l_2610;
	case 9750ULL: goto x86_l_2616;
	case 9759ULL: goto x86_l_261f;
	case 9765ULL: goto x86_l_2625;
	case 9772ULL: goto x86_l_262c;
	case 9776ULL: goto x86_l_2630;
	case 9785ULL: goto x86_l_2639;
	case 9787ULL: goto x86_l_263b;
	case 9792ULL: goto x86_l_2640;
	case 9796ULL: goto x86_l_2644;
	case 9799ULL: goto x86_l_2647;
	case 9804ULL: goto x86_l_264c;
	case 9806ULL: goto x86_l_264e;
	case 9808ULL: goto x86_l_2650;
	case 9814ULL: goto x86_l_2656;
	case 9819ULL: goto x86_l_265b;
	case 9828ULL: goto x86_l_2664;
	case 9834ULL: goto x86_l_266a;
	case 9841ULL: goto x86_l_2671;
	case 9845ULL: goto x86_l_2675;
	case 9854ULL: goto x86_l_267e;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9865ULL: goto x86_l_2689;
	case 9868ULL: goto x86_l_268c;
	case 9873ULL: goto x86_l_2691;
	case 9875ULL: goto x86_l_2693;
	case 9877ULL: goto x86_l_2695;
	case 9883ULL: goto x86_l_269b;
	case 9888ULL: goto x86_l_26a0;
	case 9897ULL: goto x86_l_26a9;
	case 9903ULL: goto x86_l_26af;
	case 9910ULL: goto x86_l_26b6;
	case 9914ULL: goto x86_l_26ba;
	case 9923ULL: goto x86_l_26c3;
	case 9929ULL: goto x86_l_26c9;
	case 9934ULL: goto x86_l_26ce;
	case 9938ULL: goto x86_l_26d2;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9948ULL: goto x86_l_26dc;
	case 9950ULL: goto x86_l_26de;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9993ULL: goto x86_l_2709;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10008ULL: goto x86_l_2718;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10020ULL: goto x86_l_2724;
	case 10025ULL: goto x86_l_2729;
	case 10027ULL: goto x86_l_272b;
	case 10032ULL: goto x86_l_2730;
	case 10037ULL: goto x86_l_2735;
	case 10042ULL: goto x86_l_273a;
	case 10044ULL: goto x86_l_273c;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10059ULL: goto x86_l_274b;
	case 10062ULL: goto x86_l_274e;
	case 10066ULL: goto x86_l_2752;
	case 10071ULL: goto x86_l_2757;
	case 10074ULL: goto x86_l_275a;
	case 10079ULL: goto x86_l_275f;
	case 10082ULL: goto x86_l_2762;
	case 10084ULL: goto x86_l_2764;
	case 10087ULL: goto x86_l_2767;
	case 10093ULL: goto x86_l_276d;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10104ULL: goto x86_l_2778;
	case 10109ULL: goto x86_l_277d;
	case 10117ULL: goto x86_l_2785;
	case 10122ULL: goto x86_l_278a;
	case 10129ULL: goto x86_l_2791;
	case 10134ULL: goto x86_l_2796;
	case 10136ULL: goto x86_l_2798;
	case 10139ULL: goto x86_l_279b;
	case 10145ULL: goto x86_l_27a1;
	case 10151ULL: goto x86_l_27a7;
	case 10158ULL: goto x86_l_27ae;
	case 10163ULL: goto x86_l_27b3;
	case 10166ULL: goto x86_l_27b6;
	case 10169ULL: goto x86_l_27b9;
	case 10172ULL: goto x86_l_27bc;
	case 10174ULL: goto x86_l_27be;
	case 10177ULL: goto x86_l_27c1;
	case 10182ULL: goto x86_l_27c6;
	case 10184ULL: goto x86_l_27c8;
	case 10189ULL: goto x86_l_27cd;
	case 10192ULL: goto x86_l_27d0;
	case 10195ULL: goto x86_l_27d3;
	case 10201ULL: goto x86_l_27d9;
	case 10205ULL: goto x86_l_27dd;
	case 10210ULL: goto x86_l_27e2;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10225ULL: goto x86_l_27f1;
	case 10230ULL: goto x86_l_27f6;
	case 10237ULL: goto x86_l_27fd;
	case 10242ULL: goto x86_l_2802;
	case 10244ULL: goto x86_l_2804;
	case 10247ULL: goto x86_l_2807;
	case 10249ULL: goto x86_l_2809;
	case 10255ULL: goto x86_l_280f;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10270ULL: goto x86_l_281e;
	case 10273ULL: goto x86_l_2821;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2131:
	/* 0x2131: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2134:
	/* 0x2134: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2139:
	/* 0x2139: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213b:
	/* 0x213b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_213d:
	/* 0x213d: jns    274e <generic_sleepable_preload+0x274e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_274e;
	}
x86_l_2143:
	/* 0x2143: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2148:
	/* 0x2148: jmp    274b <generic_sleepable_preload+0x274b> */
	goto x86_l_274b;
x86_l_214d:
	/* 0x214d: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2152:
	/* 0x2152: jmp    274b <generic_sleepable_preload+0x274b> */
	goto x86_l_274b;
x86_l_2157:
	/* 0x2157: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_215f:
	/* 0x215f: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_2162:
	/* 0x2162: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_2164:
	/* 0x2164: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2169:
	/* 0x2169: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_216c:
	/* 0x216c: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_216e:
	/* 0x216e: jmp    21da <generic_sleepable_preload+0x21da> */
	goto x86_l_21da;
x86_l_2170:
	/* 0x2170: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2178:
	/* 0x2178: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_217b:
	/* 0x217b: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_217d:
	/* 0x217d: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2182:
	/* 0x2182: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2185:
	/* 0x2185: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_2187:
	/* 0x2187: jmp    21da <generic_sleepable_preload+0x21da> */
	goto x86_l_21da;
x86_l_2189:
	/* 0x2189: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2191:
	/* 0x2191: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_2194:
	/* 0x2194: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_2196:
	/* 0x2196: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_219b:
	/* 0x219b: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_219e:
	/* 0x219e: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_21a0:
	/* 0x21a0: jmp    21da <generic_sleepable_preload+0x21da> */
	goto x86_l_21da;
x86_l_21a2:
	/* 0x21a2: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21a7:
	/* 0x21a7: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_21aa:
	/* 0x21aa: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_21ac:
	/* 0x21ac: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21b1:
	/* 0x21b1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_21b4:
	/* 0x21b4: je     21c7 <generic_sleepable_preload+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_21b6:
	/* 0x21b6: jmp    21da <generic_sleepable_preload+0x21da> */
	goto x86_l_21da;
x86_l_21b8:
	/* 0x21b8: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_21bd:
	/* 0x21bd: jmp    274b <generic_sleepable_preload+0x274b> */
	goto x86_l_274b;
x86_l_21c2:
	/* 0x21c2: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21c7:
	/* 0x21c7: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_21ca:
	/* 0x21ca: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_21cc:
	/* 0x21cc: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_21ce:
	/* 0x21ce: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_21d3:
	/* 0x21d3: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21d5:
	/* 0x21d5: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_21da:
	/* 0x21da: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21de:
	/* 0x21de: mov    ebx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e2:
	/* 0x21e2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21e4:
	/* 0x21e4: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_21e7:
	/* 0x21e7: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_21f0:
	/* 0x21f0: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_21f6:
	/* 0x21f6: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_21fd:
	/* 0x21fd: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2200:
	/* 0x2200: mov    edx,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2207:
	/* 0x2207: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_220a:
	/* 0x220a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_220e:
	/* 0x220e: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_2216:
	/* 0x2216: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_2218:
	/* 0x2218: je     2476 <generic_sleepable_preload+0x2476> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2476;
	}
x86_l_221e:
	/* 0x221e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2221:
	/* 0x2221: je     223e <generic_sleepable_preload+0x223e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223e;
	}
x86_l_2223:
	/* 0x2223: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2228:
	/* 0x2228: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_222c:
	/* 0x222c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_222f:
	/* 0x222f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2234:
	/* 0x2234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2236:
	/* 0x2236: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2238:
	/* 0x2238: js     26ee <generic_sleepable_preload+0x26ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26ee;
	}
x86_l_223e:
	/* 0x223e: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2247:
	/* 0x2247: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_224d:
	/* 0x224d: mov    eax,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2254:
	/* 0x2254: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2258:
	/* 0x2258: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2261:
	/* 0x2261: je     227e <generic_sleepable_preload+0x227e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_227e;
	}
x86_l_2263:
	/* 0x2263: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2268:
	/* 0x2268: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226c:
	/* 0x226c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_226f:
	/* 0x226f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2274:
	/* 0x2274: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2276:
	/* 0x2276: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2278:
	/* 0x2278: js     26f8 <generic_sleepable_preload+0x26f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26f8;
	}
x86_l_227e:
	/* 0x227e: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2287:
	/* 0x2287: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_228d:
	/* 0x228d: mov    eax,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2294:
	/* 0x2294: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2298:
	/* 0x2298: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_22a1:
	/* 0x22a1: je     22be <generic_sleepable_preload+0x22be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22be;
	}
x86_l_22a3:
	/* 0x22a3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22a8:
	/* 0x22a8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ac:
	/* 0x22ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22af:
	/* 0x22af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22b4:
	/* 0x22b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b6:
	/* 0x22b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22b8:
	/* 0x22b8: js     2709 <generic_sleepable_preload+0x2709> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2709;
	}
x86_l_22be:
	/* 0x22be: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_22c7:
	/* 0x22c7: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_22cd:
	/* 0x22cd: mov    eax,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_22d4:
	/* 0x22d4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22d8:
	/* 0x22d8: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_22e1:
	/* 0x22e1: je     22fe <generic_sleepable_preload+0x22fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22fe;
	}
x86_l_22e3:
	/* 0x22e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22e8:
	/* 0x22e8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ec:
	/* 0x22ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22ef:
	/* 0x22ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f4:
	/* 0x22f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f6:
	/* 0x22f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f8:
	/* 0x22f8: js     271a <generic_sleepable_preload+0x271a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_271a;
	}
x86_l_22fe:
	/* 0x22fe: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2307:
	/* 0x2307: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_230d:
	/* 0x230d: mov    eax,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2314:
	/* 0x2314: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2318:
	/* 0x2318: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2321:
	/* 0x2321: je     233e <generic_sleepable_preload+0x233e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233e;
	}
x86_l_2323:
	/* 0x2323: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2328:
	/* 0x2328: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232c:
	/* 0x232c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_232f:
	/* 0x232f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2334:
	/* 0x2334: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2336:
	/* 0x2336: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2338:
	/* 0x2338: js     272b <generic_sleepable_preload+0x272b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_272b;
	}
x86_l_233e:
	/* 0x233e: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2347:
	/* 0x2347: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_234d:
	/* 0x234d: mov    eax,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2354:
	/* 0x2354: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2358:
	/* 0x2358: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2361:
	/* 0x2361: je     237e <generic_sleepable_preload+0x237e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237e;
	}
x86_l_2363:
	/* 0x2363: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2368:
	/* 0x2368: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_236c:
	/* 0x236c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_236f:
	/* 0x236f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2374:
	/* 0x2374: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2376:
	/* 0x2376: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2378:
	/* 0x2378: js     273c <generic_sleepable_preload+0x273c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_273c;
	}
x86_l_237e:
	/* 0x237e: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2387:
	/* 0x2387: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_238d:
	/* 0x238d: mov    eax,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2394:
	/* 0x2394: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2398:
	/* 0x2398: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_23a1:
	/* 0x23a1: je     23be <generic_sleepable_preload+0x23be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23be;
	}
x86_l_23a3:
	/* 0x23a3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23a8:
	/* 0x23a8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ac:
	/* 0x23ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23af:
	/* 0x23af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b4:
	/* 0x23b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b6:
	/* 0x23b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23b8:
	/* 0x23b8: js     27c8 <generic_sleepable_preload+0x27c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27c8;
	}
x86_l_23be:
	/* 0x23be: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_23c7:
	/* 0x23c7: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_23cd:
	/* 0x23cd: mov    eax,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_23d4:
	/* 0x23d4: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23d8:
	/* 0x23d8: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_23e1:
	/* 0x23e1: je     23fe <generic_sleepable_preload+0x23fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23fe;
	}
x86_l_23e3:
	/* 0x23e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23e8:
	/* 0x23e8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ec:
	/* 0x23ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23ef:
	/* 0x23ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23f4:
	/* 0x23f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f6:
	/* 0x23f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23f8:
	/* 0x23f8: js     520a <generic_sleepable_preload+0x520a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21002ULL;
	}
x86_l_23fe:
	/* 0x23fe: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2407:
	/* 0x2407: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_240d:
	/* 0x240d: mov    eax,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2414:
	/* 0x2414: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2418:
	/* 0x2418: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2421:
	/* 0x2421: je     243e <generic_sleepable_preload+0x243e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_243e;
	}
x86_l_2423:
	/* 0x2423: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2428:
	/* 0x2428: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_242c:
	/* 0x242c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_242f:
	/* 0x242f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2434:
	/* 0x2434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2436:
	/* 0x2436: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2438:
	/* 0x2438: js     5281 <generic_sleepable_preload+0x5281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21121ULL;
	}
x86_l_243e:
	/* 0x243e: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2443:
	/* 0x2443: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_244c:
	/* 0x244c: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_2452:
	/* 0x2452: mov    eax,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2459:
	/* 0x2459: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_245d:
	/* 0x245d: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2466:
	/* 0x2466: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_246c:
	/* 0x246c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2471:
	/* 0x2471: jmp    26ce <generic_sleepable_preload+0x26ce> */
	goto x86_l_26ce;
x86_l_2476:
	/* 0x2476: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2479:
	/* 0x2479: je     2496 <generic_sleepable_preload+0x2496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2496;
	}
x86_l_247b:
	/* 0x247b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2480:
	/* 0x2480: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2484:
	/* 0x2484: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2487:
	/* 0x2487: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_248c:
	/* 0x248c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248e:
	/* 0x248e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2490:
	/* 0x2490: js     26ee <generic_sleepable_preload+0x26ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26ee;
	}
x86_l_2496:
	/* 0x2496: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_249f:
	/* 0x249f: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_24a5:
	/* 0x24a5: mov    eax,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_24ac:
	/* 0x24ac: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24b0:
	/* 0x24b0: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_24b9:
	/* 0x24b9: je     24d6 <generic_sleepable_preload+0x24d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d6;
	}
x86_l_24bb:
	/* 0x24bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24c0:
	/* 0x24c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24c4:
	/* 0x24c4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24c7:
	/* 0x24c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24cc:
	/* 0x24cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ce:
	/* 0x24ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24d0:
	/* 0x24d0: js     26f8 <generic_sleepable_preload+0x26f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26f8;
	}
x86_l_24d6:
	/* 0x24d6: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_24df:
	/* 0x24df: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_24e5:
	/* 0x24e5: mov    eax,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_24ec:
	/* 0x24ec: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24f0:
	/* 0x24f0: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_24f9:
	/* 0x24f9: je     2516 <generic_sleepable_preload+0x2516> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2516;
	}
x86_l_24fb:
	/* 0x24fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2500:
	/* 0x2500: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2504:
	/* 0x2504: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2507:
	/* 0x2507: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_250c:
	/* 0x250c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250e:
	/* 0x250e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2510:
	/* 0x2510: js     2709 <generic_sleepable_preload+0x2709> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2709;
	}
x86_l_2516:
	/* 0x2516: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_251f:
	/* 0x251f: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_2525:
	/* 0x2525: mov    eax,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_252c:
	/* 0x252c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2530:
	/* 0x2530: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2539:
	/* 0x2539: je     2556 <generic_sleepable_preload+0x2556> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2556;
	}
x86_l_253b:
	/* 0x253b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2540:
	/* 0x2540: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2544:
	/* 0x2544: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2547:
	/* 0x2547: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_254c:
	/* 0x254c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254e:
	/* 0x254e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2550:
	/* 0x2550: js     271a <generic_sleepable_preload+0x271a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_271a;
	}
x86_l_2556:
	/* 0x2556: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_255f:
	/* 0x255f: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_2565:
	/* 0x2565: mov    eax,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_256c:
	/* 0x256c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2570:
	/* 0x2570: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2579:
	/* 0x2579: je     2596 <generic_sleepable_preload+0x2596> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2596;
	}
x86_l_257b:
	/* 0x257b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2580:
	/* 0x2580: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2584:
	/* 0x2584: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2587:
	/* 0x2587: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_258c:
	/* 0x258c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_258e:
	/* 0x258e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2590:
	/* 0x2590: js     272b <generic_sleepable_preload+0x272b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_272b;
	}
x86_l_2596:
	/* 0x2596: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_259f:
	/* 0x259f: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_25a5:
	/* 0x25a5: mov    eax,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_25ac:
	/* 0x25ac: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25b0:
	/* 0x25b0: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_25b9:
	/* 0x25b9: je     25d6 <generic_sleepable_preload+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25d6;
	}
x86_l_25bb:
	/* 0x25bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25c0:
	/* 0x25c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25c4:
	/* 0x25c4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_25c7:
	/* 0x25c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25cc:
	/* 0x25cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ce:
	/* 0x25ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25d0:
	/* 0x25d0: js     273c <generic_sleepable_preload+0x273c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_273c;
	}
x86_l_25d6:
	/* 0x25d6: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_25df:
	/* 0x25df: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_25e5:
	/* 0x25e5: mov    eax,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_25ec:
	/* 0x25ec: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25f0:
	/* 0x25f0: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_25f9:
	/* 0x25f9: je     2616 <generic_sleepable_preload+0x2616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2616;
	}
x86_l_25fb:
	/* 0x25fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2600:
	/* 0x2600: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2604:
	/* 0x2604: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2607:
	/* 0x2607: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_260c:
	/* 0x260c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260e:
	/* 0x260e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2610:
	/* 0x2610: js     27c8 <generic_sleepable_preload+0x27c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27c8;
	}
x86_l_2616:
	/* 0x2616: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_261f:
	/* 0x261f: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_2625:
	/* 0x2625: mov    eax,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_262c:
	/* 0x262c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2630:
	/* 0x2630: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2639:
	/* 0x2639: je     2656 <generic_sleepable_preload+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2656;
	}
x86_l_263b:
	/* 0x263b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2640:
	/* 0x2640: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2644:
	/* 0x2644: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2647:
	/* 0x2647: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_264c:
	/* 0x264c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264e:
	/* 0x264e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2650:
	/* 0x2650: js     5325 <generic_sleepable_preload+0x5325> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21285ULL;
	}
x86_l_2656:
	/* 0x2656: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_265b:
	/* 0x265b: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2664:
	/* 0x2664: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_266a:
	/* 0x266a: mov    eax,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2671:
	/* 0x2671: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2675:
	/* 0x2675: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_267e:
	/* 0x267e: je     269b <generic_sleepable_preload+0x269b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_269b;
	}
x86_l_2680:
	/* 0x2680: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2685:
	/* 0x2685: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2689:
	/* 0x2689: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_268c:
	/* 0x268c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2691:
	/* 0x2691: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2693:
	/* 0x2693: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2695:
	/* 0x2695: js     5281 <generic_sleepable_preload+0x5281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21121ULL;
	}
x86_l_269b:
	/* 0x269b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a0:
	/* 0x26a0: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_26a9:
	/* 0x26a9: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_26af:
	/* 0x26af: mov    eax,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_26b6:
	/* 0x26b6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26ba:
	/* 0x26ba: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_26c3:
	/* 0x26c3: je     27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_26c9:
	/* 0x26c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26ce:
	/* 0x26ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d2:
	/* 0x26d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26d5:
	/* 0x26d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26da:
	/* 0x26da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26dc:
	/* 0x26dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26de:
	/* 0x26de: jns    27d0 <generic_sleepable_preload+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_27d0;
	}
x86_l_26e4:
	/* 0x26e4: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_26e9:
	/* 0x26e9: jmp    27cd <generic_sleepable_preload+0x27cd> */
	goto x86_l_27cd;
x86_l_26ee:
	/* 0x26ee: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_26f3:
	/* 0x26f3: jmp    27cd <generic_sleepable_preload+0x27cd> */
	goto x86_l_27cd;
x86_l_26f8:
	/* 0x26f8: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_26fd:
	/* 0x26fd: jmp    27cd <generic_sleepable_preload+0x27cd> */
	goto x86_l_27cd;
x86_l_2702:
	/* 0x2702: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2707:
	/* 0x2707: jmp    274b <generic_sleepable_preload+0x274b> */
	goto x86_l_274b;
x86_l_2709:
	/* 0x2709: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_270e:
	/* 0x270e: jmp    27cd <generic_sleepable_preload+0x27cd> */
	goto x86_l_27cd;
x86_l_2713:
	/* 0x2713: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2718:
	/* 0x2718: jmp    274b <generic_sleepable_preload+0x274b> */
	goto x86_l_274b;
x86_l_271a:
	/* 0x271a: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_271f:
	/* 0x271f: jmp    27cd <generic_sleepable_preload+0x27cd> */
	goto x86_l_27cd;
x86_l_2724:
	/* 0x2724: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2729:
	/* 0x2729: jmp    274b <generic_sleepable_preload+0x274b> */
	goto x86_l_274b;
x86_l_272b:
	/* 0x272b: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2730:
	/* 0x2730: jmp    27cd <generic_sleepable_preload+0x27cd> */
	goto x86_l_27cd;
x86_l_2735:
	/* 0x2735: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_273a:
	/* 0x273a: jmp    274b <generic_sleepable_preload+0x274b> */
	goto x86_l_274b;
x86_l_273c:
	/* 0x273c: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2741:
	/* 0x2741: jmp    27cd <generic_sleepable_preload+0x27cd> */
	goto x86_l_27cd;
x86_l_2746:
	/* 0x2746: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_274b:
	/* 0x274b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_274e:
	/* 0x274e: mov    ebx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2752:
	/* 0x2752: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2757:
	/* 0x2757: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_275a:
	/* 0x275a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_275f:
	/* 0x275f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2762:
	/* 0x2762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2764:
	/* 0x2764: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2767:
	/* 0x2767: jne    286f <generic_sleepable_preload+0x286f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10351ULL;
	}
x86_l_276d:
	/* 0x276d: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2771:
	/* 0x2771: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2776:
	/* 0x2776: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2778:
	/* 0x2778: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_277d:
	/* 0x277d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2785:
	/* 0x2785: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_278a:
	/* 0x278a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2791:
	/* 0x2791: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2796:
	/* 0x2796: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2798:
	/* 0x2798: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_279b:
	/* 0x279b: je     286f <generic_sleepable_preload+0x286f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10351ULL;
	}
x86_l_27a1:
	/* 0x27a1: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_27a7:
	/* 0x27a7: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_27ae:
	/* 0x27ae: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27b3:
	/* 0x27b3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_27b6:
	/* 0x27b6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_27b9:
	/* 0x27b9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_27bc:
	/* 0x27bc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27be:
	/* 0x27be: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_27c1:
	/* 0x27c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27c6:
	/* 0x27c6: jmp    282e <generic_sleepable_preload+0x282e> */
	return 10286ULL;
x86_l_27c8:
	/* 0x27c8: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_27cd:
	/* 0x27cd: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27d0:
	/* 0x27d0: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_27d3:
	/* 0x27d3: jne    286f <generic_sleepable_preload+0x286f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10351ULL;
	}
x86_l_27d9:
	/* 0x27d9: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27dd:
	/* 0x27dd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_27e2:
	/* 0x27e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e4:
	/* 0x27e4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27e9:
	/* 0x27e9: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_27f1:
	/* 0x27f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27f6:
	/* 0x27f6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_27fd:
	/* 0x27fd: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2802:
	/* 0x2802: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2804:
	/* 0x2804: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2807:
	/* 0x2807: je     286f <generic_sleepable_preload+0x286f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10351ULL;
	}
x86_l_2809:
	/* 0x2809: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_280f:
	/* 0x280f: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2816:
	/* 0x2816: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_281b:
	/* 0x281b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_281e:
	/* 0x281e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2821:
	/* 0x2821: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
	return 10276ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10276ULL: goto x86_l_2824;
	case 10278ULL: goto x86_l_2826;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10289ULL: goto x86_l_2831;
	case 10292ULL: goto x86_l_2834;
	case 10297ULL: goto x86_l_2839;
	case 10299ULL: goto x86_l_283b;
	case 10302ULL: goto x86_l_283e;
	case 10304ULL: goto x86_l_2840;
	case 10307ULL: goto x86_l_2843;
	case 10309ULL: goto x86_l_2845;
	case 10312ULL: goto x86_l_2848;
	case 10316ULL: goto x86_l_284c;
	case 10321ULL: goto x86_l_2851;
	case 10324ULL: goto x86_l_2854;
	case 10326ULL: goto x86_l_2856;
	case 10329ULL: goto x86_l_2859;
	case 10334ULL: goto x86_l_285e;
	case 10336ULL: goto x86_l_2860;
	case 10339ULL: goto x86_l_2863;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10349ULL: goto x86_l_286d;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10360ULL: goto x86_l_2878;
	case 10365ULL: goto x86_l_287d;
	case 10371ULL: goto x86_l_2883;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10379ULL: goto x86_l_288b;
	case 10382ULL: goto x86_l_288e;
	case 10388ULL: goto x86_l_2894;
	case 10391ULL: goto x86_l_2897;
	case 10397ULL: goto x86_l_289d;
	case 10400ULL: goto x86_l_28a0;
	case 10406ULL: goto x86_l_28a6;
	case 10409ULL: goto x86_l_28a9;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10433ULL: goto x86_l_28c1;
	case 10441ULL: goto x86_l_28c9;
	case 10447ULL: goto x86_l_28cf;
	case 10449ULL: goto x86_l_28d1;
	case 10452ULL: goto x86_l_28d4;
	case 10454ULL: goto x86_l_28d6;
	case 10457ULL: goto x86_l_28d9;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10468ULL: goto x86_l_28e4;
	case 10473ULL: goto x86_l_28e9;
	case 10476ULL: goto x86_l_28ec;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10490ULL: goto x86_l_28fa;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10504ULL: goto x86_l_2908;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10518ULL: goto x86_l_2916;
	case 10520ULL: goto x86_l_2918;
	case 10523ULL: goto x86_l_291b;
	case 10529ULL: goto x86_l_2921;
	case 10531ULL: goto x86_l_2923;
	case 10537ULL: goto x86_l_2929;
	case 10540ULL: goto x86_l_292c;
	case 10543ULL: goto x86_l_292f;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10556ULL: goto x86_l_293c;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10563ULL: goto x86_l_2943;
	case 10568ULL: goto x86_l_2948;
	case 10570ULL: goto x86_l_294a;
	case 10573ULL: goto x86_l_294d;
	case 10579ULL: goto x86_l_2953;
	case 10587ULL: goto x86_l_295b;
	case 10590ULL: goto x86_l_295e;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10604ULL: goto x86_l_296c;
	case 10610ULL: goto x86_l_2972;
	case 10615ULL: goto x86_l_2977;
	case 10618ULL: goto x86_l_297a;
	case 10624ULL: goto x86_l_2980;
	case 10632ULL: goto x86_l_2988;
	case 10635ULL: goto x86_l_298b;
	case 10641ULL: goto x86_l_2991;
	case 10646ULL: goto x86_l_2996;
	case 10649ULL: goto x86_l_2999;
	case 10655ULL: goto x86_l_299f;
	case 10660ULL: goto x86_l_29a4;
	case 10665ULL: goto x86_l_29a9;
	case 10667ULL: goto x86_l_29ab;
	case 10672ULL: goto x86_l_29b0;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10682ULL: goto x86_l_29ba;
	case 10686ULL: goto x86_l_29be;
	case 10688ULL: goto x86_l_29c0;
	case 10691ULL: goto x86_l_29c3;
	case 10700ULL: goto x86_l_29cc;
	case 10706ULL: goto x86_l_29d2;
	case 10713ULL: goto x86_l_29d9;
	case 10716ULL: goto x86_l_29dc;
	case 10723ULL: goto x86_l_29e3;
	case 10726ULL: goto x86_l_29e6;
	case 10730ULL: goto x86_l_29ea;
	case 10738ULL: goto x86_l_29f2;
	case 10740ULL: goto x86_l_29f4;
	case 10746ULL: goto x86_l_29fa;
	case 10749ULL: goto x86_l_29fd;
	case 10751ULL: goto x86_l_29ff;
	case 10756ULL: goto x86_l_2a04;
	case 10760ULL: goto x86_l_2a08;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10770ULL: goto x86_l_2a12;
	case 10772ULL: goto x86_l_2a14;
	case 10778ULL: goto x86_l_2a1a;
	case 10787ULL: goto x86_l_2a23;
	case 10793ULL: goto x86_l_2a29;
	case 10800ULL: goto x86_l_2a30;
	case 10804ULL: goto x86_l_2a34;
	case 10813ULL: goto x86_l_2a3d;
	case 10815ULL: goto x86_l_2a3f;
	case 10820ULL: goto x86_l_2a44;
	case 10824ULL: goto x86_l_2a48;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10834ULL: goto x86_l_2a52;
	case 10836ULL: goto x86_l_2a54;
	case 10842ULL: goto x86_l_2a5a;
	case 10851ULL: goto x86_l_2a63;
	case 10857ULL: goto x86_l_2a69;
	case 10864ULL: goto x86_l_2a70;
	case 10868ULL: goto x86_l_2a74;
	case 10877ULL: goto x86_l_2a7d;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10898ULL: goto x86_l_2a92;
	case 10900ULL: goto x86_l_2a94;
	case 10906ULL: goto x86_l_2a9a;
	case 10915ULL: goto x86_l_2aa3;
	case 10921ULL: goto x86_l_2aa9;
	case 10928ULL: goto x86_l_2ab0;
	case 10932ULL: goto x86_l_2ab4;
	case 10941ULL: goto x86_l_2abd;
	case 10943ULL: goto x86_l_2abf;
	case 10948ULL: goto x86_l_2ac4;
	case 10952ULL: goto x86_l_2ac8;
	case 10955ULL: goto x86_l_2acb;
	case 10960ULL: goto x86_l_2ad0;
	case 10962ULL: goto x86_l_2ad2;
	case 10964ULL: goto x86_l_2ad4;
	case 10970ULL: goto x86_l_2ada;
	case 10979ULL: goto x86_l_2ae3;
	case 10985ULL: goto x86_l_2ae9;
	case 10992ULL: goto x86_l_2af0;
	case 10996ULL: goto x86_l_2af4;
	case 11005ULL: goto x86_l_2afd;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11016ULL: goto x86_l_2b08;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11026ULL: goto x86_l_2b12;
	case 11028ULL: goto x86_l_2b14;
	case 11034ULL: goto x86_l_2b1a;
	case 11043ULL: goto x86_l_2b23;
	case 11049ULL: goto x86_l_2b29;
	case 11056ULL: goto x86_l_2b30;
	case 11060ULL: goto x86_l_2b34;
	case 11069ULL: goto x86_l_2b3d;
	case 11071ULL: goto x86_l_2b3f;
	case 11076ULL: goto x86_l_2b44;
	case 11080ULL: goto x86_l_2b48;
	case 11083ULL: goto x86_l_2b4b;
	case 11088ULL: goto x86_l_2b50;
	case 11090ULL: goto x86_l_2b52;
	case 11092ULL: goto x86_l_2b54;
	case 11098ULL: goto x86_l_2b5a;
	case 11107ULL: goto x86_l_2b63;
	case 11113ULL: goto x86_l_2b69;
	case 11120ULL: goto x86_l_2b70;
	case 11124ULL: goto x86_l_2b74;
	case 11133ULL: goto x86_l_2b7d;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11144ULL: goto x86_l_2b88;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11154ULL: goto x86_l_2b92;
	case 11156ULL: goto x86_l_2b94;
	case 11162ULL: goto x86_l_2b9a;
	case 11171ULL: goto x86_l_2ba3;
	case 11177ULL: goto x86_l_2ba9;
	case 11184ULL: goto x86_l_2bb0;
	case 11188ULL: goto x86_l_2bb4;
	case 11197ULL: goto x86_l_2bbd;
	case 11199ULL: goto x86_l_2bbf;
	case 11204ULL: goto x86_l_2bc4;
	case 11208ULL: goto x86_l_2bc8;
	case 11211ULL: goto x86_l_2bcb;
	case 11216ULL: goto x86_l_2bd0;
	case 11218ULL: goto x86_l_2bd2;
	case 11220ULL: goto x86_l_2bd4;
	case 11226ULL: goto x86_l_2bda;
	case 11235ULL: goto x86_l_2be3;
	case 11241ULL: goto x86_l_2be9;
	case 11248ULL: goto x86_l_2bf0;
	case 11252ULL: goto x86_l_2bf4;
	case 11261ULL: goto x86_l_2bfd;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11272ULL: goto x86_l_2c08;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11282ULL: goto x86_l_2c12;
	case 11284ULL: goto x86_l_2c14;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11304ULL: goto x86_l_2c28;
	case 11310ULL: goto x86_l_2c2e;
	case 11317ULL: goto x86_l_2c35;
	case 11321ULL: goto x86_l_2c39;
	case 11330ULL: goto x86_l_2c42;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11349ULL: goto x86_l_2c55;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11360ULL: goto x86_l_2c60;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11370ULL: goto x86_l_2c6a;
	case 11372ULL: goto x86_l_2c6c;
	case 11378ULL: goto x86_l_2c72;
	case 11387ULL: goto x86_l_2c7b;
	case 11393ULL: goto x86_l_2c81;
	case 11400ULL: goto x86_l_2c88;
	case 11404ULL: goto x86_l_2c8c;
	case 11413ULL: goto x86_l_2c95;
	case 11415ULL: goto x86_l_2c97;
	case 11420ULL: goto x86_l_2c9c;
	case 11424ULL: goto x86_l_2ca0;
	case 11427ULL: goto x86_l_2ca3;
	case 11432ULL: goto x86_l_2ca8;
	case 11434ULL: goto x86_l_2caa;
	case 11436ULL: goto x86_l_2cac;
	case 11442ULL: goto x86_l_2cb2;
	case 11451ULL: goto x86_l_2cbb;
	case 11457ULL: goto x86_l_2cc1;
	case 11464ULL: goto x86_l_2cc8;
	case 11468ULL: goto x86_l_2ccc;
	case 11477ULL: goto x86_l_2cd5;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11488ULL: goto x86_l_2ce0;
	case 11491ULL: goto x86_l_2ce3;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11500ULL: goto x86_l_2cec;
	case 11506ULL: goto x86_l_2cf2;
	case 11515ULL: goto x86_l_2cfb;
	case 11521ULL: goto x86_l_2d01;
	case 11528ULL: goto x86_l_2d08;
	case 11532ULL: goto x86_l_2d0c;
	case 11541ULL: goto x86_l_2d15;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11552ULL: goto x86_l_2d20;
	case 11555ULL: goto x86_l_2d23;
	case 11560ULL: goto x86_l_2d28;
	case 11562ULL: goto x86_l_2d2a;
	case 11564ULL: goto x86_l_2d2c;
	case 11570ULL: goto x86_l_2d32;
	case 11579ULL: goto x86_l_2d3b;
	case 11585ULL: goto x86_l_2d41;
	case 11592ULL: goto x86_l_2d48;
	case 11596ULL: goto x86_l_2d4c;
	case 11605ULL: goto x86_l_2d55;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11616ULL: goto x86_l_2d60;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11626ULL: goto x86_l_2d6a;
	case 11628ULL: goto x86_l_2d6c;
	case 11634ULL: goto x86_l_2d72;
	case 11643ULL: goto x86_l_2d7b;
	case 11649ULL: goto x86_l_2d81;
	case 11656ULL: goto x86_l_2d88;
	case 11660ULL: goto x86_l_2d8c;
	case 11669ULL: goto x86_l_2d95;
	case 11671ULL: goto x86_l_2d97;
	case 11676ULL: goto x86_l_2d9c;
	case 11680ULL: goto x86_l_2da0;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11690ULL: goto x86_l_2daa;
	case 11692ULL: goto x86_l_2dac;
	case 11698ULL: goto x86_l_2db2;
	case 11707ULL: goto x86_l_2dbb;
	case 11713ULL: goto x86_l_2dc1;
	case 11720ULL: goto x86_l_2dc8;
	case 11724ULL: goto x86_l_2dcc;
	case 11733ULL: goto x86_l_2dd5;
	case 11735ULL: goto x86_l_2dd7;
	case 11740ULL: goto x86_l_2ddc;
	case 11744ULL: goto x86_l_2de0;
	case 11747ULL: goto x86_l_2de3;
	case 11752ULL: goto x86_l_2de8;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11762ULL: goto x86_l_2df2;
	case 11771ULL: goto x86_l_2dfb;
	case 11777ULL: goto x86_l_2e01;
	case 11784ULL: goto x86_l_2e08;
	case 11788ULL: goto x86_l_2e0c;
	case 11797ULL: goto x86_l_2e15;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11808ULL: goto x86_l_2e20;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11820ULL: goto x86_l_2e2c;
	case 11826ULL: goto x86_l_2e32;
	case 11831ULL: goto x86_l_2e37;
	case 11840ULL: goto x86_l_2e40;
	case 11846ULL: goto x86_l_2e46;
	case 11853ULL: goto x86_l_2e4d;
	case 11857ULL: goto x86_l_2e51;
	case 11866ULL: goto x86_l_2e5a;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11877ULL: goto x86_l_2e65;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11889ULL: goto x86_l_2e71;
	case 11895ULL: goto x86_l_2e77;
	case 11900ULL: goto x86_l_2e7c;
	case 11909ULL: goto x86_l_2e85;
	case 11915ULL: goto x86_l_2e8b;
	case 11922ULL: goto x86_l_2e92;
	case 11926ULL: goto x86_l_2e96;
	case 11935ULL: goto x86_l_2e9f;
	case 11941ULL: goto x86_l_2ea5;
	case 11946ULL: goto x86_l_2eaa;
	case 11950ULL: goto x86_l_2eae;
	case 11953ULL: goto x86_l_2eb1;
	case 11958ULL: goto x86_l_2eb6;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11983ULL: goto x86_l_2ecf;
	case 11988ULL: goto x86_l_2ed4;
	case 11996ULL: goto x86_l_2edc;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12006ULL: goto x86_l_2ee6;
	case 12009ULL: goto x86_l_2ee9;
	case 12011ULL: goto x86_l_2eeb;
	case 12013ULL: goto x86_l_2eed;
	case 12021ULL: goto x86_l_2ef5;
	case 12024ULL: goto x86_l_2ef8;
	case 12026ULL: goto x86_l_2efa;
	case 12031ULL: goto x86_l_2eff;
	case 12034ULL: goto x86_l_2f02;
	case 12036ULL: goto x86_l_2f04;
	case 12038ULL: goto x86_l_2f06;
	case 12046ULL: goto x86_l_2f0e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2824:
	/* 0x2824: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2826:
	/* 0x2826: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2829:
	/* 0x2829: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_282e:
	/* 0x282e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2831:
	/* 0x2831: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2834:
	/* 0x2834: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2839:
	/* 0x2839: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283b:
	/* 0x283b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_283e:
	/* 0x283e: je     286f <generic_sleepable_preload+0x286f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_286f;
	}
x86_l_2840:
	/* 0x2840: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_2843:
	/* 0x2843: je     286d <generic_sleepable_preload+0x286d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_286d;
	}
x86_l_2845:
	/* 0x2845: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2848:
	/* 0x2848: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_284c:
	/* 0x284c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2851:
	/* 0x2851: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2854:
	/* 0x2854: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2856:
	/* 0x2856: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2859:
	/* 0x2859: call   285e <generic_sleepable_preload+0x285e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_285e:
	/* 0x285e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2860:
	/* 0x2860: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_2863:
	/* 0x2863: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2865:
	/* 0x2865: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_286a:
	/* 0x286a: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_286d:
	/* 0x286d: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286f:
	/* 0x286f: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2874:
	/* 0x2874: mov    eax,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2878:
	/* 0x2878: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_287d:
	/* 0x287d: je     35ec <generic_sleepable_preload+0x35ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13804ULL;
	}
x86_l_2883:
	/* 0x2883: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2885:
	/* 0x2885: js     28b9 <generic_sleepable_preload+0x28b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28b9;
	}
x86_l_2887:
	/* 0x2887: mov    ecx,DWORD PTR [r13+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_288b:
	/* 0x288b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_288e:
	/* 0x288e: jle    293a <generic_sleepable_preload+0x293a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_293a;
	}
x86_l_2894:
	/* 0x2894: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2897:
	/* 0x2897: je     29a4 <generic_sleepable_preload+0x29a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29a4;
	}
x86_l_289d:
	/* 0x289d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_28a0:
	/* 0x28a0: je     29ab <generic_sleepable_preload+0x29ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29ab;
	}
x86_l_28a6:
	/* 0x28a6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28a9:
	/* 0x28a9: jne    29be <generic_sleepable_preload+0x29be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29be;
	}
x86_l_28af:
	/* 0x28af: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28b4:
	/* 0x28b4: jmp    29b7 <generic_sleepable_preload+0x29b7> */
	goto x86_l_29b7;
x86_l_28b9:
	/* 0x28b9: movzx  ecx,BYTE PTR [r13+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_28c1:
	/* 0x28c1: movzx  eax,WORD PTR [r13+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_28c9:
	/* 0x28c9: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_28cf:
	/* 0x28cf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28d1:
	/* 0x28d1: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_28d4:
	/* 0x28d4: jle    2913 <generic_sleepable_preload+0x2913> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2913;
	}
x86_l_28d6:
	/* 0x28d6: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_28d9:
	/* 0x28d9: jle    294a <generic_sleepable_preload+0x294a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_294a;
	}
x86_l_28db:
	/* 0x28db: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_28de:
	/* 0x28de: jle    2f1f <generic_sleepable_preload+0x2f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12063ULL;
	}
x86_l_28e4:
	/* 0x28e4: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28e9:
	/* 0x28e9: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_28ec:
	/* 0x28ec: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_28f2:
	/* 0x28f2: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_28f7:
	/* 0x28f7: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_28fa:
	/* 0x28fa: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2900:
	/* 0x2900: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2905:
	/* 0x2905: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2908:
	/* 0x2908: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_290e:
	/* 0x290e: jmp    2f57 <generic_sleepable_preload+0x2f57> */
	return 12119ULL;
x86_l_2913:
	/* 0x2913: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2916:
	/* 0x2916: jg     2977 <generic_sleepable_preload+0x2977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2977;
	}
x86_l_2918:
	/* 0x2918: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_291b:
	/* 0x291b: jg     2eed <generic_sleepable_preload+0x2eed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2eed;
	}
x86_l_2921:
	/* 0x2921: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2923:
	/* 0x2923: je     2f3f <generic_sleepable_preload+0x2f3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12095ULL;
	}
x86_l_2929:
	/* 0x2929: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_292c:
	/* 0x292c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_292f:
	/* 0x292f: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2935:
	/* 0x2935: jmp    2f57 <generic_sleepable_preload+0x2f57> */
	return 12119ULL;
x86_l_293a:
	/* 0x293a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_293c:
	/* 0x293c: je     29b2 <generic_sleepable_preload+0x29b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29b2;
	}
x86_l_293e:
	/* 0x293e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2941:
	/* 0x2941: jne    29be <generic_sleepable_preload+0x29be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29be;
	}
x86_l_2943:
	/* 0x2943: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2948:
	/* 0x2948: jmp    29b7 <generic_sleepable_preload+0x29b7> */
	goto x86_l_29b7;
x86_l_294a:
	/* 0x294a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_294d:
	/* 0x294d: jg     2ed4 <generic_sleepable_preload+0x2ed4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ed4;
	}
x86_l_2953:
	/* 0x2953: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_295b:
	/* 0x295b: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_295e:
	/* 0x295e: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2964:
	/* 0x2964: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2969:
	/* 0x2969: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_296c:
	/* 0x296c: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2972:
	/* 0x2972: jmp    2f57 <generic_sleepable_preload+0x2f57> */
	return 12119ULL;
x86_l_2977:
	/* 0x2977: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_297a:
	/* 0x297a: jg     2f06 <generic_sleepable_preload+0x2f06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f06;
	}
x86_l_2980:
	/* 0x2980: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2988:
	/* 0x2988: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_298b:
	/* 0x298b: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2991:
	/* 0x2991: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2996:
	/* 0x2996: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2999:
	/* 0x2999: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_299f:
	/* 0x299f: jmp    2f57 <generic_sleepable_preload+0x2f57> */
	return 12119ULL;
x86_l_29a4:
	/* 0x29a4: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29a9:
	/* 0x29a9: jmp    29b7 <generic_sleepable_preload+0x29b7> */
	goto x86_l_29b7;
x86_l_29ab:
	/* 0x29ab: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29b0:
	/* 0x29b0: jmp    29b7 <generic_sleepable_preload+0x29b7> */
	goto x86_l_29b7;
x86_l_29b2:
	/* 0x29b2: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29b7:
	/* 0x29b7: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ba:
	/* 0x29ba: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29be:
	/* 0x29be: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29c0:
	/* 0x29c0: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_29c3:
	/* 0x29c3: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_29cc:
	/* 0x29cc: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_29d2:
	/* 0x29d2: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_29d9:
	/* 0x29d9: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_29dc:
	/* 0x29dc: mov    edx,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_29e3:
	/* 0x29e3: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29e6:
	/* 0x29e6: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ea:
	/* 0x29ea: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_29f2:
	/* 0x29f2: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_29f4:
	/* 0x29f4: je     2c52 <generic_sleepable_preload+0x2c52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c52;
	}
x86_l_29fa:
	/* 0x29fa: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_29fd:
	/* 0x29fd: je     2a1a <generic_sleepable_preload+0x2a1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1a;
	}
x86_l_29ff:
	/* 0x29ff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a04:
	/* 0x2a04: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a08:
	/* 0x2a08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a0b:
	/* 0x2a0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a10:
	/* 0x2a10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a12:
	/* 0x2a12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a14:
	/* 0x2a14: js     2eca <generic_sleepable_preload+0x2eca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2eca;
	}
x86_l_2a1a:
	/* 0x2a1a: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2a23:
	/* 0x2a23: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2a29:
	/* 0x2a29: mov    eax,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2a30:
	/* 0x2a30: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a34:
	/* 0x2a34: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2a3d:
	/* 0x2a3d: je     2a5a <generic_sleepable_preload+0x2a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a5a;
	}
x86_l_2a3f:
	/* 0x2a3f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a44:
	/* 0x2a44: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a48:
	/* 0x2a48: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a4b:
	/* 0x2a4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a50:
	/* 0x2a50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a52:
	/* 0x2a52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a54:
	/* 0x2a54: js     2f35 <generic_sleepable_preload+0x2f35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12085ULL;
	}
x86_l_2a5a:
	/* 0x2a5a: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2a63:
	/* 0x2a63: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2a69:
	/* 0x2a69: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2a70:
	/* 0x2a70: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a74:
	/* 0x2a74: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2a7d:
	/* 0x2a7d: je     2a9a <generic_sleepable_preload+0x2a9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a9a;
	}
x86_l_2a7f:
	/* 0x2a7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a84:
	/* 0x2a84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a88:
	/* 0x2a88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a8b:
	/* 0x2a8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a90:
	/* 0x2a90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a92:
	/* 0x2a92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a94:
	/* 0x2a94: js     347f <generic_sleepable_preload+0x347f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13439ULL;
	}
x86_l_2a9a:
	/* 0x2a9a: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2aa3:
	/* 0x2aa3: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2aa9:
	/* 0x2aa9: mov    eax,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2ab0:
	/* 0x2ab0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ab4:
	/* 0x2ab4: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2abd:
	/* 0x2abd: je     2ada <generic_sleepable_preload+0x2ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ada;
	}
x86_l_2abf:
	/* 0x2abf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ac4:
	/* 0x2ac4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac8:
	/* 0x2ac8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2acb:
	/* 0x2acb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ad0:
	/* 0x2ad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad2:
	/* 0x2ad2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ad4:
	/* 0x2ad4: js     3490 <generic_sleepable_preload+0x3490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13456ULL;
	}
x86_l_2ada:
	/* 0x2ada: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2ae3:
	/* 0x2ae3: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2ae9:
	/* 0x2ae9: mov    eax,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2af0:
	/* 0x2af0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2af4:
	/* 0x2af4: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2afd:
	/* 0x2afd: je     2b1a <generic_sleepable_preload+0x2b1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b1a;
	}
x86_l_2aff:
	/* 0x2aff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b04:
	/* 0x2b04: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b08:
	/* 0x2b08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b0b:
	/* 0x2b0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b10:
	/* 0x2b10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b12:
	/* 0x2b12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b14:
	/* 0x2b14: js     34a1 <generic_sleepable_preload+0x34a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13473ULL;
	}
x86_l_2b1a:
	/* 0x2b1a: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2b23:
	/* 0x2b23: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2b29:
	/* 0x2b29: mov    eax,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2b30:
	/* 0x2b30: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b34:
	/* 0x2b34: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2b3d:
	/* 0x2b3d: je     2b5a <generic_sleepable_preload+0x2b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b5a;
	}
x86_l_2b3f:
	/* 0x2b3f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b44:
	/* 0x2b44: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b48:
	/* 0x2b48: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b4b:
	/* 0x2b4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b50:
	/* 0x2b50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b52:
	/* 0x2b52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b54:
	/* 0x2b54: js     34b2 <generic_sleepable_preload+0x34b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13490ULL;
	}
x86_l_2b5a:
	/* 0x2b5a: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2b63:
	/* 0x2b63: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2b69:
	/* 0x2b69: mov    eax,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2b70:
	/* 0x2b70: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b74:
	/* 0x2b74: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2b7d:
	/* 0x2b7d: je     2b9a <generic_sleepable_preload+0x2b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9a;
	}
x86_l_2b7f:
	/* 0x2b7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b84:
	/* 0x2b84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b88:
	/* 0x2b88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b8b:
	/* 0x2b8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b90:
	/* 0x2b90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b92:
	/* 0x2b92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b94:
	/* 0x2b94: js     34c3 <generic_sleepable_preload+0x34c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13507ULL;
	}
x86_l_2b9a:
	/* 0x2b9a: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2ba3:
	/* 0x2ba3: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2ba9:
	/* 0x2ba9: mov    eax,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2bb0:
	/* 0x2bb0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bb4:
	/* 0x2bb4: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2bbd:
	/* 0x2bbd: je     2bda <generic_sleepable_preload+0x2bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bda;
	}
x86_l_2bbf:
	/* 0x2bbf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc8:
	/* 0x2bc8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bcb:
	/* 0x2bcb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bd0:
	/* 0x2bd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd2:
	/* 0x2bd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bd4:
	/* 0x2bd4: js     5217 <generic_sleepable_preload+0x5217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21015ULL;
	}
x86_l_2bda:
	/* 0x2bda: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2be3:
	/* 0x2be3: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2be9:
	/* 0x2be9: mov    eax,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2bf0:
	/* 0x2bf0: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bf4:
	/* 0x2bf4: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2bfd:
	/* 0x2bfd: je     2c1a <generic_sleepable_preload+0x2c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c1a;
	}
x86_l_2bff:
	/* 0x2bff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c04:
	/* 0x2c04: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c08:
	/* 0x2c08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c0b:
	/* 0x2c0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c10:
	/* 0x2c10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c12:
	/* 0x2c12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c14:
	/* 0x2c14: js     5293 <generic_sleepable_preload+0x5293> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21139ULL;
	}
x86_l_2c1a:
	/* 0x2c1a: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1f:
	/* 0x2c1f: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2c28:
	/* 0x2c28: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2c2e:
	/* 0x2c2e: mov    eax,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2c35:
	/* 0x2c35: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c39:
	/* 0x2c39: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2c42:
	/* 0x2c42: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2c48:
	/* 0x2c48: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c4d:
	/* 0x2c4d: jmp    2eaa <generic_sleepable_preload+0x2eaa> */
	goto x86_l_2eaa;
x86_l_2c52:
	/* 0x2c52: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2c55:
	/* 0x2c55: je     2c72 <generic_sleepable_preload+0x2c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c72;
	}
x86_l_2c57:
	/* 0x2c57: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c60:
	/* 0x2c60: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c63:
	/* 0x2c63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c68:
	/* 0x2c68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6a:
	/* 0x2c6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c6c:
	/* 0x2c6c: js     2eca <generic_sleepable_preload+0x2eca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2eca;
	}
x86_l_2c72:
	/* 0x2c72: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2c7b:
	/* 0x2c7b: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2c81:
	/* 0x2c81: mov    eax,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2c88:
	/* 0x2c88: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c8c:
	/* 0x2c8c: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2c95:
	/* 0x2c95: je     2cb2 <generic_sleepable_preload+0x2cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cb2;
	}
x86_l_2c97:
	/* 0x2c97: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c9c:
	/* 0x2c9c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ca3:
	/* 0x2ca3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ca8:
	/* 0x2ca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2caa:
	/* 0x2caa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cac:
	/* 0x2cac: js     2f35 <generic_sleepable_preload+0x2f35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12085ULL;
	}
x86_l_2cb2:
	/* 0x2cb2: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2cbb:
	/* 0x2cbb: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2cc1:
	/* 0x2cc1: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2cc8:
	/* 0x2cc8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ccc:
	/* 0x2ccc: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2cd5:
	/* 0x2cd5: je     2cf2 <generic_sleepable_preload+0x2cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf2;
	}
x86_l_2cd7:
	/* 0x2cd7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cdc:
	/* 0x2cdc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce0:
	/* 0x2ce0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ce3:
	/* 0x2ce3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ce8:
	/* 0x2ce8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cea:
	/* 0x2cea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cec:
	/* 0x2cec: js     347f <generic_sleepable_preload+0x347f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13439ULL;
	}
x86_l_2cf2:
	/* 0x2cf2: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2cfb:
	/* 0x2cfb: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2d01:
	/* 0x2d01: mov    eax,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2d08:
	/* 0x2d08: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d0c:
	/* 0x2d0c: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2d15:
	/* 0x2d15: je     2d32 <generic_sleepable_preload+0x2d32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d32;
	}
x86_l_2d17:
	/* 0x2d17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d1c:
	/* 0x2d1c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d20:
	/* 0x2d20: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d23:
	/* 0x2d23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d28:
	/* 0x2d28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2a:
	/* 0x2d2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d2c:
	/* 0x2d2c: js     3490 <generic_sleepable_preload+0x3490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13456ULL;
	}
x86_l_2d32:
	/* 0x2d32: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2d3b:
	/* 0x2d3b: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2d41:
	/* 0x2d41: mov    eax,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2d48:
	/* 0x2d48: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d4c:
	/* 0x2d4c: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2d55:
	/* 0x2d55: je     2d72 <generic_sleepable_preload+0x2d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d72;
	}
x86_l_2d57:
	/* 0x2d57: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d60:
	/* 0x2d60: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d63:
	/* 0x2d63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d68:
	/* 0x2d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6a:
	/* 0x2d6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d6c:
	/* 0x2d6c: js     34a1 <generic_sleepable_preload+0x34a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13473ULL;
	}
x86_l_2d72:
	/* 0x2d72: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2d7b:
	/* 0x2d7b: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2d81:
	/* 0x2d81: mov    eax,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2d88:
	/* 0x2d88: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d8c:
	/* 0x2d8c: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2d95:
	/* 0x2d95: je     2db2 <generic_sleepable_preload+0x2db2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db2;
	}
x86_l_2d97:
	/* 0x2d97: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d9c:
	/* 0x2d9c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2da0:
	/* 0x2da0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2da3:
	/* 0x2da3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2da8:
	/* 0x2da8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2daa:
	/* 0x2daa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dac:
	/* 0x2dac: js     34b2 <generic_sleepable_preload+0x34b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13490ULL;
	}
x86_l_2db2:
	/* 0x2db2: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2dbb:
	/* 0x2dbb: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2dc1:
	/* 0x2dc1: mov    eax,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2dc8:
	/* 0x2dc8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2dcc:
	/* 0x2dcc: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2dd5:
	/* 0x2dd5: je     2df2 <generic_sleepable_preload+0x2df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df2;
	}
x86_l_2dd7:
	/* 0x2dd7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ddc:
	/* 0x2ddc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de0:
	/* 0x2de0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2de3:
	/* 0x2de3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2de8:
	/* 0x2de8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dea:
	/* 0x2dea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dec:
	/* 0x2dec: js     34c3 <generic_sleepable_preload+0x34c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13507ULL;
	}
x86_l_2df2:
	/* 0x2df2: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2dfb:
	/* 0x2dfb: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2e01:
	/* 0x2e01: mov    eax,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2e08:
	/* 0x2e08: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e0c:
	/* 0x2e0c: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2e15:
	/* 0x2e15: je     2e32 <generic_sleepable_preload+0x2e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e32;
	}
x86_l_2e17:
	/* 0x2e17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e1c:
	/* 0x2e1c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e20:
	/* 0x2e20: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e23:
	/* 0x2e23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e28:
	/* 0x2e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2a:
	/* 0x2e2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e2c:
	/* 0x2e2c: js     5337 <generic_sleepable_preload+0x5337> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21303ULL;
	}
x86_l_2e32:
	/* 0x2e32: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e37:
	/* 0x2e37: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2e40:
	/* 0x2e40: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2e46:
	/* 0x2e46: mov    eax,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2e4d:
	/* 0x2e4d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e51:
	/* 0x2e51: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2e5a:
	/* 0x2e5a: je     2e77 <generic_sleepable_preload+0x2e77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e77;
	}
x86_l_2e5c:
	/* 0x2e5c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e61:
	/* 0x2e61: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e65:
	/* 0x2e65: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e68:
	/* 0x2e68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e6d:
	/* 0x2e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6f:
	/* 0x2e6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e71:
	/* 0x2e71: js     5293 <generic_sleepable_preload+0x5293> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21139ULL;
	}
x86_l_2e77:
	/* 0x2e77: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e7c:
	/* 0x2e7c: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2e85:
	/* 0x2e85: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2e8b:
	/* 0x2e8b: mov    eax,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2e92:
	/* 0x2e92: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e96:
	/* 0x2e96: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2e9f:
	/* 0x2e9f: je     34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13515ULL;
	}
x86_l_2ea5:
	/* 0x2ea5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2eaa:
	/* 0x2eaa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eae:
	/* 0x2eae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2eb1:
	/* 0x2eb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb6:
	/* 0x2eb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb8:
	/* 0x2eb8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2eba:
	/* 0x2eba: jns    34cb <generic_sleepable_preload+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13515ULL;
	}
x86_l_2ec0:
	/* 0x2ec0: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2ec5:
	/* 0x2ec5: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	return 13512ULL;
x86_l_2eca:
	/* 0x2eca: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2ecf:
	/* 0x2ecf: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	return 13512ULL;
x86_l_2ed4:
	/* 0x2ed4: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2edc:
	/* 0x2edc: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_2edf:
	/* 0x2edf: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2ee1:
	/* 0x2ee1: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee6:
	/* 0x2ee6: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2ee9:
	/* 0x2ee9: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2eeb:
	/* 0x2eeb: jmp    2f57 <generic_sleepable_preload+0x2f57> */
	return 12119ULL;
x86_l_2eed:
	/* 0x2eed: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ef5:
	/* 0x2ef5: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2ef8:
	/* 0x2ef8: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2efa:
	/* 0x2efa: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2eff:
	/* 0x2eff: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2f02:
	/* 0x2f02: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12100ULL;
	}
x86_l_2f04:
	/* 0x2f04: jmp    2f57 <generic_sleepable_preload+0x2f57> */
	return 12119ULL;
x86_l_2f06:
	/* 0x2f06: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2f0e:
	/* 0x2f0e: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
	return 12049ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12049ULL: goto x86_l_2f11;
	case 12051ULL: goto x86_l_2f13;
	case 12056ULL: goto x86_l_2f18;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12071ULL: goto x86_l_2f27;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12081ULL: goto x86_l_2f31;
	case 12083ULL: goto x86_l_2f33;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12095ULL: goto x86_l_2f3f;
	case 12100ULL: goto x86_l_2f44;
	case 12103ULL: goto x86_l_2f47;
	case 12105ULL: goto x86_l_2f49;
	case 12107ULL: goto x86_l_2f4b;
	case 12112ULL: goto x86_l_2f50;
	case 12114ULL: goto x86_l_2f52;
	case 12119ULL: goto x86_l_2f57;
	case 12123ULL: goto x86_l_2f5b;
	case 12127ULL: goto x86_l_2f5f;
	case 12129ULL: goto x86_l_2f61;
	case 12132ULL: goto x86_l_2f64;
	case 12141ULL: goto x86_l_2f6d;
	case 12147ULL: goto x86_l_2f73;
	case 12154ULL: goto x86_l_2f7a;
	case 12157ULL: goto x86_l_2f7d;
	case 12164ULL: goto x86_l_2f84;
	case 12167ULL: goto x86_l_2f87;
	case 12171ULL: goto x86_l_2f8b;
	case 12179ULL: goto x86_l_2f93;
	case 12181ULL: goto x86_l_2f95;
	case 12187ULL: goto x86_l_2f9b;
	case 12190ULL: goto x86_l_2f9e;
	case 12192ULL: goto x86_l_2fa0;
	case 12197ULL: goto x86_l_2fa5;
	case 12201ULL: goto x86_l_2fa9;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12211ULL: goto x86_l_2fb3;
	case 12213ULL: goto x86_l_2fb5;
	case 12219ULL: goto x86_l_2fbb;
	case 12228ULL: goto x86_l_2fc4;
	case 12234ULL: goto x86_l_2fca;
	case 12241ULL: goto x86_l_2fd1;
	case 12245ULL: goto x86_l_2fd5;
	case 12254ULL: goto x86_l_2fde;
	case 12256ULL: goto x86_l_2fe0;
	case 12261ULL: goto x86_l_2fe5;
	case 12265ULL: goto x86_l_2fe9;
	case 12268ULL: goto x86_l_2fec;
	case 12273ULL: goto x86_l_2ff1;
	case 12275ULL: goto x86_l_2ff3;
	case 12277ULL: goto x86_l_2ff5;
	case 12283ULL: goto x86_l_2ffb;
	case 12292ULL: goto x86_l_3004;
	case 12298ULL: goto x86_l_300a;
	case 12305ULL: goto x86_l_3011;
	case 12309ULL: goto x86_l_3015;
	case 12318ULL: goto x86_l_301e;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12329ULL: goto x86_l_3029;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12341ULL: goto x86_l_3035;
	case 12347ULL: goto x86_l_303b;
	case 12356ULL: goto x86_l_3044;
	case 12362ULL: goto x86_l_304a;
	case 12369ULL: goto x86_l_3051;
	case 12373ULL: goto x86_l_3055;
	case 12382ULL: goto x86_l_305e;
	case 12384ULL: goto x86_l_3060;
	case 12389ULL: goto x86_l_3065;
	case 12393ULL: goto x86_l_3069;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12403ULL: goto x86_l_3073;
	case 12405ULL: goto x86_l_3075;
	case 12411ULL: goto x86_l_307b;
	case 12420ULL: goto x86_l_3084;
	case 12426ULL: goto x86_l_308a;
	case 12433ULL: goto x86_l_3091;
	case 12437ULL: goto x86_l_3095;
	case 12446ULL: goto x86_l_309e;
	case 12448ULL: goto x86_l_30a0;
	case 12453ULL: goto x86_l_30a5;
	case 12457ULL: goto x86_l_30a9;
	case 12460ULL: goto x86_l_30ac;
	case 12465ULL: goto x86_l_30b1;
	case 12467ULL: goto x86_l_30b3;
	case 12469ULL: goto x86_l_30b5;
	case 12475ULL: goto x86_l_30bb;
	case 12484ULL: goto x86_l_30c4;
	case 12490ULL: goto x86_l_30ca;
	case 12497ULL: goto x86_l_30d1;
	case 12501ULL: goto x86_l_30d5;
	case 12510ULL: goto x86_l_30de;
	case 12512ULL: goto x86_l_30e0;
	case 12517ULL: goto x86_l_30e5;
	case 12521ULL: goto x86_l_30e9;
	case 12524ULL: goto x86_l_30ec;
	case 12529ULL: goto x86_l_30f1;
	case 12531ULL: goto x86_l_30f3;
	case 12533ULL: goto x86_l_30f5;
	case 12539ULL: goto x86_l_30fb;
	case 12548ULL: goto x86_l_3104;
	case 12554ULL: goto x86_l_310a;
	case 12561ULL: goto x86_l_3111;
	case 12565ULL: goto x86_l_3115;
	case 12574ULL: goto x86_l_311e;
	case 12576ULL: goto x86_l_3120;
	case 12581ULL: goto x86_l_3125;
	case 12585ULL: goto x86_l_3129;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12595ULL: goto x86_l_3133;
	case 12597ULL: goto x86_l_3135;
	case 12603ULL: goto x86_l_313b;
	case 12612ULL: goto x86_l_3144;
	case 12618ULL: goto x86_l_314a;
	case 12625ULL: goto x86_l_3151;
	case 12629ULL: goto x86_l_3155;
	case 12638ULL: goto x86_l_315e;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12649ULL: goto x86_l_3169;
	case 12652ULL: goto x86_l_316c;
	case 12657ULL: goto x86_l_3171;
	case 12659ULL: goto x86_l_3173;
	case 12661ULL: goto x86_l_3175;
	case 12667ULL: goto x86_l_317b;
	case 12676ULL: goto x86_l_3184;
	case 12682ULL: goto x86_l_318a;
	case 12689ULL: goto x86_l_3191;
	case 12693ULL: goto x86_l_3195;
	case 12702ULL: goto x86_l_319e;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12713ULL: goto x86_l_31a9;
	case 12716ULL: goto x86_l_31ac;
	case 12721ULL: goto x86_l_31b1;
	case 12723ULL: goto x86_l_31b3;
	case 12725ULL: goto x86_l_31b5;
	case 12731ULL: goto x86_l_31bb;
	case 12736ULL: goto x86_l_31c0;
	case 12745ULL: goto x86_l_31c9;
	case 12751ULL: goto x86_l_31cf;
	case 12758ULL: goto x86_l_31d6;
	case 12762ULL: goto x86_l_31da;
	case 12771ULL: goto x86_l_31e3;
	case 12777ULL: goto x86_l_31e9;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12790ULL: goto x86_l_31f6;
	case 12792ULL: goto x86_l_31f8;
	case 12797ULL: goto x86_l_31fd;
	case 12801ULL: goto x86_l_3201;
	case 12804ULL: goto x86_l_3204;
	case 12809ULL: goto x86_l_3209;
	case 12811ULL: goto x86_l_320b;
	case 12813ULL: goto x86_l_320d;
	case 12819ULL: goto x86_l_3213;
	case 12828ULL: goto x86_l_321c;
	case 12834ULL: goto x86_l_3222;
	case 12841ULL: goto x86_l_3229;
	case 12845ULL: goto x86_l_322d;
	case 12854ULL: goto x86_l_3236;
	case 12856ULL: goto x86_l_3238;
	case 12861ULL: goto x86_l_323d;
	case 12865ULL: goto x86_l_3241;
	case 12868ULL: goto x86_l_3244;
	case 12873ULL: goto x86_l_3249;
	case 12875ULL: goto x86_l_324b;
	case 12877ULL: goto x86_l_324d;
	case 12883ULL: goto x86_l_3253;
	case 12892ULL: goto x86_l_325c;
	case 12898ULL: goto x86_l_3262;
	case 12905ULL: goto x86_l_3269;
	case 12909ULL: goto x86_l_326d;
	case 12918ULL: goto x86_l_3276;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12929ULL: goto x86_l_3281;
	case 12932ULL: goto x86_l_3284;
	case 12937ULL: goto x86_l_3289;
	case 12939ULL: goto x86_l_328b;
	case 12941ULL: goto x86_l_328d;
	case 12947ULL: goto x86_l_3293;
	case 12956ULL: goto x86_l_329c;
	case 12962ULL: goto x86_l_32a2;
	case 12969ULL: goto x86_l_32a9;
	case 12973ULL: goto x86_l_32ad;
	case 12982ULL: goto x86_l_32b6;
	case 12984ULL: goto x86_l_32b8;
	case 12989ULL: goto x86_l_32bd;
	case 12993ULL: goto x86_l_32c1;
	case 12996ULL: goto x86_l_32c4;
	case 13001ULL: goto x86_l_32c9;
	case 13003ULL: goto x86_l_32cb;
	case 13005ULL: goto x86_l_32cd;
	case 13011ULL: goto x86_l_32d3;
	case 13020ULL: goto x86_l_32dc;
	case 13026ULL: goto x86_l_32e2;
	case 13033ULL: goto x86_l_32e9;
	case 13037ULL: goto x86_l_32ed;
	case 13046ULL: goto x86_l_32f6;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13057ULL: goto x86_l_3301;
	case 13060ULL: goto x86_l_3304;
	case 13065ULL: goto x86_l_3309;
	case 13067ULL: goto x86_l_330b;
	case 13069ULL: goto x86_l_330d;
	case 13075ULL: goto x86_l_3313;
	case 13084ULL: goto x86_l_331c;
	case 13090ULL: goto x86_l_3322;
	case 13097ULL: goto x86_l_3329;
	case 13101ULL: goto x86_l_332d;
	case 13110ULL: goto x86_l_3336;
	case 13112ULL: goto x86_l_3338;
	case 13117ULL: goto x86_l_333d;
	case 13121ULL: goto x86_l_3341;
	case 13124ULL: goto x86_l_3344;
	case 13129ULL: goto x86_l_3349;
	case 13131ULL: goto x86_l_334b;
	case 13133ULL: goto x86_l_334d;
	case 13139ULL: goto x86_l_3353;
	case 13148ULL: goto x86_l_335c;
	case 13154ULL: goto x86_l_3362;
	case 13161ULL: goto x86_l_3369;
	case 13165ULL: goto x86_l_336d;
	case 13174ULL: goto x86_l_3376;
	case 13176ULL: goto x86_l_3378;
	case 13181ULL: goto x86_l_337d;
	case 13185ULL: goto x86_l_3381;
	case 13188ULL: goto x86_l_3384;
	case 13193ULL: goto x86_l_3389;
	case 13195ULL: goto x86_l_338b;
	case 13197ULL: goto x86_l_338d;
	case 13203ULL: goto x86_l_3393;
	case 13212ULL: goto x86_l_339c;
	case 13218ULL: goto x86_l_33a2;
	case 13225ULL: goto x86_l_33a9;
	case 13229ULL: goto x86_l_33ad;
	case 13238ULL: goto x86_l_33b6;
	case 13240ULL: goto x86_l_33b8;
	case 13245ULL: goto x86_l_33bd;
	case 13249ULL: goto x86_l_33c1;
	case 13252ULL: goto x86_l_33c4;
	case 13257ULL: goto x86_l_33c9;
	case 13259ULL: goto x86_l_33cb;
	case 13261ULL: goto x86_l_33cd;
	case 13267ULL: goto x86_l_33d3;
	case 13272ULL: goto x86_l_33d8;
	case 13281ULL: goto x86_l_33e1;
	case 13287ULL: goto x86_l_33e7;
	case 13294ULL: goto x86_l_33ee;
	case 13298ULL: goto x86_l_33f2;
	case 13307ULL: goto x86_l_33fb;
	case 13309ULL: goto x86_l_33fd;
	case 13314ULL: goto x86_l_3402;
	case 13318ULL: goto x86_l_3406;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13328ULL: goto x86_l_3410;
	case 13330ULL: goto x86_l_3412;
	case 13336ULL: goto x86_l_3418;
	case 13341ULL: goto x86_l_341d;
	case 13350ULL: goto x86_l_3426;
	case 13356ULL: goto x86_l_342c;
	case 13363ULL: goto x86_l_3433;
	case 13367ULL: goto x86_l_3437;
	case 13376ULL: goto x86_l_3440;
	case 13382ULL: goto x86_l_3446;
	case 13387ULL: goto x86_l_344b;
	case 13391ULL: goto x86_l_344f;
	case 13394ULL: goto x86_l_3452;
	case 13399ULL: goto x86_l_3457;
	case 13401ULL: goto x86_l_3459;
	case 13403ULL: goto x86_l_345b;
	case 13409ULL: goto x86_l_3461;
	case 13414ULL: goto x86_l_3466;
	case 13419ULL: goto x86_l_346b;
	case 13424ULL: goto x86_l_3470;
	case 13429ULL: goto x86_l_3475;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13444ULL: goto x86_l_3484;
	case 13446ULL: goto x86_l_3486;
	case 13451ULL: goto x86_l_348b;
	case 13456ULL: goto x86_l_3490;
	case 13461ULL: goto x86_l_3495;
	case 13463ULL: goto x86_l_3497;
	case 13468ULL: goto x86_l_349c;
	case 13473ULL: goto x86_l_34a1;
	case 13478ULL: goto x86_l_34a6;
	case 13480ULL: goto x86_l_34a8;
	case 13485ULL: goto x86_l_34ad;
	case 13490ULL: goto x86_l_34b2;
	case 13495ULL: goto x86_l_34b7;
	case 13497ULL: goto x86_l_34b9;
	case 13502ULL: goto x86_l_34be;
	case 13507ULL: goto x86_l_34c3;
	case 13512ULL: goto x86_l_34c8;
	case 13515ULL: goto x86_l_34cb;
	case 13519ULL: goto x86_l_34cf;
	case 13524ULL: goto x86_l_34d4;
	case 13527ULL: goto x86_l_34d7;
	case 13532ULL: goto x86_l_34dc;
	case 13535ULL: goto x86_l_34df;
	case 13537ULL: goto x86_l_34e1;
	case 13540ULL: goto x86_l_34e4;
	case 13546ULL: goto x86_l_34ea;
	case 13550ULL: goto x86_l_34ee;
	case 13555ULL: goto x86_l_34f3;
	case 13557ULL: goto x86_l_34f5;
	case 13562ULL: goto x86_l_34fa;
	case 13570ULL: goto x86_l_3502;
	case 13575ULL: goto x86_l_3507;
	case 13582ULL: goto x86_l_350e;
	case 13587ULL: goto x86_l_3513;
	case 13589ULL: goto x86_l_3515;
	case 13592ULL: goto x86_l_3518;
	case 13598ULL: goto x86_l_351e;
	case 13604ULL: goto x86_l_3524;
	case 13611ULL: goto x86_l_352b;
	case 13616ULL: goto x86_l_3530;
	case 13619ULL: goto x86_l_3533;
	case 13622ULL: goto x86_l_3536;
	case 13625ULL: goto x86_l_3539;
	case 13627ULL: goto x86_l_353b;
	case 13630ULL: goto x86_l_353e;
	case 13635ULL: goto x86_l_3543;
	case 13637ULL: goto x86_l_3545;
	case 13642ULL: goto x86_l_354a;
	case 13645ULL: goto x86_l_354d;
	case 13648ULL: goto x86_l_3550;
	case 13654ULL: goto x86_l_3556;
	case 13658ULL: goto x86_l_355a;
	case 13663ULL: goto x86_l_355f;
	case 13665ULL: goto x86_l_3561;
	case 13670ULL: goto x86_l_3566;
	case 13678ULL: goto x86_l_356e;
	case 13683ULL: goto x86_l_3573;
	case 13690ULL: goto x86_l_357a;
	case 13695ULL: goto x86_l_357f;
	case 13697ULL: goto x86_l_3581;
	case 13700ULL: goto x86_l_3584;
	case 13702ULL: goto x86_l_3586;
	case 13708ULL: goto x86_l_358c;
	case 13715ULL: goto x86_l_3593;
	case 13720ULL: goto x86_l_3598;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13729ULL: goto x86_l_35a1;
	case 13731ULL: goto x86_l_35a3;
	case 13734ULL: goto x86_l_35a6;
	case 13739ULL: goto x86_l_35ab;
	case 13742ULL: goto x86_l_35ae;
	case 13745ULL: goto x86_l_35b1;
	case 13750ULL: goto x86_l_35b6;
	case 13752ULL: goto x86_l_35b8;
	case 13755ULL: goto x86_l_35bb;
	case 13757ULL: goto x86_l_35bd;
	case 13760ULL: goto x86_l_35c0;
	case 13762ULL: goto x86_l_35c2;
	case 13765ULL: goto x86_l_35c5;
	case 13769ULL: goto x86_l_35c9;
	case 13774ULL: goto x86_l_35ce;
	case 13777ULL: goto x86_l_35d1;
	case 13779ULL: goto x86_l_35d3;
	case 13782ULL: goto x86_l_35d6;
	case 13787ULL: goto x86_l_35db;
	case 13789ULL: goto x86_l_35dd;
	case 13792ULL: goto x86_l_35e0;
	case 13794ULL: goto x86_l_35e2;
	case 13799ULL: goto x86_l_35e7;
	case 13802ULL: goto x86_l_35ea;
	case 13804ULL: goto x86_l_35ec;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f11:
	/* 0x2f11: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f44;
	}
x86_l_2f13:
	/* 0x2f13: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f18:
	/* 0x2f18: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2f1b:
	/* 0x2f1b: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f44;
	}
x86_l_2f1d:
	/* 0x2f1d: jmp    2f57 <generic_sleepable_preload+0x2f57> */
	goto x86_l_2f57;
x86_l_2f1f:
	/* 0x2f1f: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f24:
	/* 0x2f24: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2f27:
	/* 0x2f27: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f44;
	}
x86_l_2f29:
	/* 0x2f29: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f2e:
	/* 0x2f2e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2f31:
	/* 0x2f31: je     2f44 <generic_sleepable_preload+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f44;
	}
x86_l_2f33:
	/* 0x2f33: jmp    2f57 <generic_sleepable_preload+0x2f57> */
	goto x86_l_2f57;
x86_l_2f35:
	/* 0x2f35: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2f3a:
	/* 0x2f3a: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	goto x86_l_34c8;
x86_l_2f3f:
	/* 0x2f3f: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f44:
	/* 0x2f44: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2f47:
	/* 0x2f47: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_2f49:
	/* 0x2f49: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2f4b:
	/* 0x2f4b: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_2f50:
	/* 0x2f50: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f52:
	/* 0x2f52: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_2f57:
	/* 0x2f57: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5b:
	/* 0x2f5b: mov    ebx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f5f:
	/* 0x2f5f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f61:
	/* 0x2f61: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_2f64:
	/* 0x2f64: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2f6d:
	/* 0x2f6d: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_2f73:
	/* 0x2f73: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2f7a:
	/* 0x2f7a: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f7d:
	/* 0x2f7d: mov    edx,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2f84:
	/* 0x2f84: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f87:
	/* 0x2f87: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f8b:
	/* 0x2f8b: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2f93:
	/* 0x2f93: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_2f95:
	/* 0x2f95: je     31f3 <generic_sleepable_preload+0x31f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31f3;
	}
x86_l_2f9b:
	/* 0x2f9b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2f9e:
	/* 0x2f9e: je     2fbb <generic_sleepable_preload+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fbb;
	}
x86_l_2fa0:
	/* 0x2fa0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fa5:
	/* 0x2fa5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa9:
	/* 0x2fa9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fac:
	/* 0x2fac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb1:
	/* 0x2fb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb3:
	/* 0x2fb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fb5:
	/* 0x2fb5: js     346b <generic_sleepable_preload+0x346b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_346b;
	}
x86_l_2fbb:
	/* 0x2fbb: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2fc4:
	/* 0x2fc4: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_2fca:
	/* 0x2fca: mov    eax,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2fd1:
	/* 0x2fd1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2fd5:
	/* 0x2fd5: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2fde:
	/* 0x2fde: je     2ffb <generic_sleepable_preload+0x2ffb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ffb;
	}
x86_l_2fe0:
	/* 0x2fe0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fe5:
	/* 0x2fe5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe9:
	/* 0x2fe9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fec:
	/* 0x2fec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ff1:
	/* 0x2ff1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff3:
	/* 0x2ff3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ff5:
	/* 0x2ff5: js     3475 <generic_sleepable_preload+0x3475> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3475;
	}
x86_l_2ffb:
	/* 0x2ffb: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3004:
	/* 0x3004: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_300a:
	/* 0x300a: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3011:
	/* 0x3011: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3015:
	/* 0x3015: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_301e:
	/* 0x301e: je     303b <generic_sleepable_preload+0x303b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303b;
	}
x86_l_3020:
	/* 0x3020: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3025:
	/* 0x3025: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3029:
	/* 0x3029: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_302c:
	/* 0x302c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3031:
	/* 0x3031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3033:
	/* 0x3033: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3035:
	/* 0x3035: js     3486 <generic_sleepable_preload+0x3486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3486;
	}
x86_l_303b:
	/* 0x303b: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3044:
	/* 0x3044: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_304a:
	/* 0x304a: mov    eax,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3051:
	/* 0x3051: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3055:
	/* 0x3055: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_305e:
	/* 0x305e: je     307b <generic_sleepable_preload+0x307b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_307b;
	}
x86_l_3060:
	/* 0x3060: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3065:
	/* 0x3065: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3069:
	/* 0x3069: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_306c:
	/* 0x306c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3071:
	/* 0x3071: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3073:
	/* 0x3073: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3075:
	/* 0x3075: js     3497 <generic_sleepable_preload+0x3497> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3497;
	}
x86_l_307b:
	/* 0x307b: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3084:
	/* 0x3084: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_308a:
	/* 0x308a: mov    eax,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3091:
	/* 0x3091: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3095:
	/* 0x3095: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_309e:
	/* 0x309e: je     30bb <generic_sleepable_preload+0x30bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30bb;
	}
x86_l_30a0:
	/* 0x30a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30a5:
	/* 0x30a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a9:
	/* 0x30a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30ac:
	/* 0x30ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b1:
	/* 0x30b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b3:
	/* 0x30b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30b5:
	/* 0x30b5: js     34a8 <generic_sleepable_preload+0x34a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34a8;
	}
x86_l_30bb:
	/* 0x30bb: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_30c4:
	/* 0x30c4: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_30ca:
	/* 0x30ca: mov    eax,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_30d1:
	/* 0x30d1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_30d5:
	/* 0x30d5: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_30de:
	/* 0x30de: je     30fb <generic_sleepable_preload+0x30fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30fb;
	}
x86_l_30e0:
	/* 0x30e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30e5:
	/* 0x30e5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e9:
	/* 0x30e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30ec:
	/* 0x30ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30f1:
	/* 0x30f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f3:
	/* 0x30f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30f5:
	/* 0x30f5: js     34b9 <generic_sleepable_preload+0x34b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34b9;
	}
x86_l_30fb:
	/* 0x30fb: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3104:
	/* 0x3104: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_310a:
	/* 0x310a: mov    eax,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3111:
	/* 0x3111: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3115:
	/* 0x3115: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_311e:
	/* 0x311e: je     313b <generic_sleepable_preload+0x313b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_313b;
	}
x86_l_3120:
	/* 0x3120: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3125:
	/* 0x3125: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3129:
	/* 0x3129: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_312c:
	/* 0x312c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3131:
	/* 0x3131: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3133:
	/* 0x3133: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3135:
	/* 0x3135: js     3545 <generic_sleepable_preload+0x3545> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3545;
	}
x86_l_313b:
	/* 0x313b: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3144:
	/* 0x3144: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_314a:
	/* 0x314a: mov    eax,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3151:
	/* 0x3151: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3155:
	/* 0x3155: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_315e:
	/* 0x315e: je     317b <generic_sleepable_preload+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_317b;
	}
x86_l_3160:
	/* 0x3160: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3165:
	/* 0x3165: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3169:
	/* 0x3169: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_316c:
	/* 0x316c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3171:
	/* 0x3171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3173:
	/* 0x3173: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3175:
	/* 0x3175: js     5224 <generic_sleepable_preload+0x5224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21028ULL;
	}
x86_l_317b:
	/* 0x317b: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3184:
	/* 0x3184: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_318a:
	/* 0x318a: mov    eax,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3191:
	/* 0x3191: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3195:
	/* 0x3195: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_319e:
	/* 0x319e: je     31bb <generic_sleepable_preload+0x31bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31bb;
	}
x86_l_31a0:
	/* 0x31a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31a5:
	/* 0x31a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31a9:
	/* 0x31a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31ac:
	/* 0x31ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31b1:
	/* 0x31b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b3:
	/* 0x31b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31b5:
	/* 0x31b5: js     52a5 <generic_sleepable_preload+0x52a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21157ULL;
	}
x86_l_31bb:
	/* 0x31bb: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c0:
	/* 0x31c0: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_31c9:
	/* 0x31c9: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_31cf:
	/* 0x31cf: mov    eax,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_31d6:
	/* 0x31d6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_31da:
	/* 0x31da: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_31e3:
	/* 0x31e3: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_31e9:
	/* 0x31e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31ee:
	/* 0x31ee: jmp    344b <generic_sleepable_preload+0x344b> */
	goto x86_l_344b;
x86_l_31f3:
	/* 0x31f3: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31f6:
	/* 0x31f6: je     3213 <generic_sleepable_preload+0x3213> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3213;
	}
x86_l_31f8:
	/* 0x31f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31fd:
	/* 0x31fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3201:
	/* 0x3201: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3204:
	/* 0x3204: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3209:
	/* 0x3209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320b:
	/* 0x320b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_320d:
	/* 0x320d: js     346b <generic_sleepable_preload+0x346b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_346b;
	}
x86_l_3213:
	/* 0x3213: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_321c:
	/* 0x321c: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_3222:
	/* 0x3222: mov    eax,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3229:
	/* 0x3229: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_322d:
	/* 0x322d: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3236:
	/* 0x3236: je     3253 <generic_sleepable_preload+0x3253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3253;
	}
x86_l_3238:
	/* 0x3238: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_323d:
	/* 0x323d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3241:
	/* 0x3241: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3244:
	/* 0x3244: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3249:
	/* 0x3249: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_324b:
	/* 0x324b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_324d:
	/* 0x324d: js     3475 <generic_sleepable_preload+0x3475> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3475;
	}
x86_l_3253:
	/* 0x3253: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_325c:
	/* 0x325c: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_3262:
	/* 0x3262: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3269:
	/* 0x3269: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_326d:
	/* 0x326d: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3276:
	/* 0x3276: je     3293 <generic_sleepable_preload+0x3293> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3293;
	}
x86_l_3278:
	/* 0x3278: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_327d:
	/* 0x327d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3281:
	/* 0x3281: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3284:
	/* 0x3284: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3289:
	/* 0x3289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_328b:
	/* 0x328b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_328d:
	/* 0x328d: js     3486 <generic_sleepable_preload+0x3486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3486;
	}
x86_l_3293:
	/* 0x3293: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_329c:
	/* 0x329c: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_32a2:
	/* 0x32a2: mov    eax,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_32a9:
	/* 0x32a9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32ad:
	/* 0x32ad: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_32b6:
	/* 0x32b6: je     32d3 <generic_sleepable_preload+0x32d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32d3;
	}
x86_l_32b8:
	/* 0x32b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32bd:
	/* 0x32bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c1:
	/* 0x32c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32c4:
	/* 0x32c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c9:
	/* 0x32c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32cb:
	/* 0x32cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32cd:
	/* 0x32cd: js     3497 <generic_sleepable_preload+0x3497> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3497;
	}
x86_l_32d3:
	/* 0x32d3: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_32dc:
	/* 0x32dc: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_32e2:
	/* 0x32e2: mov    eax,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_32e9:
	/* 0x32e9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_32ed:
	/* 0x32ed: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_32f6:
	/* 0x32f6: je     3313 <generic_sleepable_preload+0x3313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3313;
	}
x86_l_32f8:
	/* 0x32f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32fd:
	/* 0x32fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3301:
	/* 0x3301: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3304:
	/* 0x3304: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3309:
	/* 0x3309: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_330b:
	/* 0x330b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_330d:
	/* 0x330d: js     34a8 <generic_sleepable_preload+0x34a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34a8;
	}
x86_l_3313:
	/* 0x3313: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_331c:
	/* 0x331c: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_3322:
	/* 0x3322: mov    eax,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3329:
	/* 0x3329: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_332d:
	/* 0x332d: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3336:
	/* 0x3336: je     3353 <generic_sleepable_preload+0x3353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3353;
	}
x86_l_3338:
	/* 0x3338: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_333d:
	/* 0x333d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3341:
	/* 0x3341: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3344:
	/* 0x3344: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3349:
	/* 0x3349: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334b:
	/* 0x334b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_334d:
	/* 0x334d: js     34b9 <generic_sleepable_preload+0x34b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_34b9;
	}
x86_l_3353:
	/* 0x3353: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_335c:
	/* 0x335c: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_3362:
	/* 0x3362: mov    eax,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3369:
	/* 0x3369: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_336d:
	/* 0x336d: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3376:
	/* 0x3376: je     3393 <generic_sleepable_preload+0x3393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3393;
	}
x86_l_3378:
	/* 0x3378: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_337d:
	/* 0x337d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3381:
	/* 0x3381: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3384:
	/* 0x3384: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3389:
	/* 0x3389: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338b:
	/* 0x338b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_338d:
	/* 0x338d: js     3545 <generic_sleepable_preload+0x3545> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3545;
	}
x86_l_3393:
	/* 0x3393: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_339c:
	/* 0x339c: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_33a2:
	/* 0x33a2: mov    eax,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_33a9:
	/* 0x33a9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33ad:
	/* 0x33ad: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_33b6:
	/* 0x33b6: je     33d3 <generic_sleepable_preload+0x33d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d3;
	}
x86_l_33b8:
	/* 0x33b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33bd:
	/* 0x33bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c1:
	/* 0x33c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33c4:
	/* 0x33c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c9:
	/* 0x33c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33cb:
	/* 0x33cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33cd:
	/* 0x33cd: js     5349 <generic_sleepable_preload+0x5349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21321ULL;
	}
x86_l_33d3:
	/* 0x33d3: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33d8:
	/* 0x33d8: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_33e1:
	/* 0x33e1: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_33e7:
	/* 0x33e7: mov    eax,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_33ee:
	/* 0x33ee: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_33f2:
	/* 0x33f2: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_33fb:
	/* 0x33fb: je     3418 <generic_sleepable_preload+0x3418> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3418;
	}
x86_l_33fd:
	/* 0x33fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3402:
	/* 0x3402: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3406:
	/* 0x3406: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3409:
	/* 0x3409: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_340e:
	/* 0x340e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3410:
	/* 0x3410: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3412:
	/* 0x3412: js     52a5 <generic_sleepable_preload+0x52a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21157ULL;
	}
x86_l_3418:
	/* 0x3418: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_341d:
	/* 0x341d: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3426:
	/* 0x3426: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_342c:
	/* 0x342c: mov    eax,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3433:
	/* 0x3433: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3437:
	/* 0x3437: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3440:
	/* 0x3440: je     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354d;
	}
x86_l_3446:
	/* 0x3446: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_344b:
	/* 0x344b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_344f:
	/* 0x344f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3452:
	/* 0x3452: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3457:
	/* 0x3457: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3459:
	/* 0x3459: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_345b:
	/* 0x345b: jns    354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_354d;
	}
x86_l_3461:
	/* 0x3461: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3466:
	/* 0x3466: jmp    354a <generic_sleepable_preload+0x354a> */
	goto x86_l_354a;
x86_l_346b:
	/* 0x346b: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3470:
	/* 0x3470: jmp    354a <generic_sleepable_preload+0x354a> */
	goto x86_l_354a;
x86_l_3475:
	/* 0x3475: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_347a:
	/* 0x347a: jmp    354a <generic_sleepable_preload+0x354a> */
	goto x86_l_354a;
x86_l_347f:
	/* 0x347f: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_3484:
	/* 0x3484: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	goto x86_l_34c8;
x86_l_3486:
	/* 0x3486: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_348b:
	/* 0x348b: jmp    354a <generic_sleepable_preload+0x354a> */
	goto x86_l_354a;
x86_l_3490:
	/* 0x3490: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_3495:
	/* 0x3495: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	goto x86_l_34c8;
x86_l_3497:
	/* 0x3497: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_349c:
	/* 0x349c: jmp    354a <generic_sleepable_preload+0x354a> */
	goto x86_l_354a;
x86_l_34a1:
	/* 0x34a1: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_34a6:
	/* 0x34a6: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	goto x86_l_34c8;
x86_l_34a8:
	/* 0x34a8: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_34ad:
	/* 0x34ad: jmp    354a <generic_sleepable_preload+0x354a> */
	goto x86_l_354a;
x86_l_34b2:
	/* 0x34b2: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_34b7:
	/* 0x34b7: jmp    34c8 <generic_sleepable_preload+0x34c8> */
	goto x86_l_34c8;
x86_l_34b9:
	/* 0x34b9: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_34be:
	/* 0x34be: jmp    354a <generic_sleepable_preload+0x354a> */
	goto x86_l_354a;
x86_l_34c3:
	/* 0x34c3: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_34c8:
	/* 0x34c8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34cb:
	/* 0x34cb: mov    ebx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_34cf:
	/* 0x34cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34d4:
	/* 0x34d4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_34d7:
	/* 0x34d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34dc:
	/* 0x34dc: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_34df:
	/* 0x34df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e1:
	/* 0x34e1: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_34e4:
	/* 0x34e4: jne    35ec <generic_sleepable_preload+0x35ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35ec;
	}
x86_l_34ea:
	/* 0x34ea: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ee:
	/* 0x34ee: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_34f3:
	/* 0x34f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f5:
	/* 0x34f5: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34fa:
	/* 0x34fa: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3502:
	/* 0x3502: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3507:
	/* 0x3507: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_350e:
	/* 0x350e: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3513:
	/* 0x3513: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3515:
	/* 0x3515: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3518:
	/* 0x3518: je     35ec <generic_sleepable_preload+0x35ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35ec;
	}
x86_l_351e:
	/* 0x351e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_3524:
	/* 0x3524: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_352b:
	/* 0x352b: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3530:
	/* 0x3530: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3533:
	/* 0x3533: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3536:
	/* 0x3536: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3539:
	/* 0x3539: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_353b:
	/* 0x353b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_353e:
	/* 0x353e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3543:
	/* 0x3543: jmp    35ab <generic_sleepable_preload+0x35ab> */
	goto x86_l_35ab;
x86_l_3545:
	/* 0x3545: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_354a:
	/* 0x354a: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_354d:
	/* 0x354d: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3550:
	/* 0x3550: jne    35ec <generic_sleepable_preload+0x35ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35ec;
	}
x86_l_3556:
	/* 0x3556: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_355a:
	/* 0x355a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_355f:
	/* 0x355f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3561:
	/* 0x3561: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3566:
	/* 0x3566: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_356e:
	/* 0x356e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3573:
	/* 0x3573: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_357a:
	/* 0x357a: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_357f:
	/* 0x357f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3581:
	/* 0x3581: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3584:
	/* 0x3584: je     35ec <generic_sleepable_preload+0x35ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35ec;
	}
x86_l_3586:
	/* 0x3586: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_358c:
	/* 0x358c: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3593:
	/* 0x3593: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3598:
	/* 0x3598: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_359b:
	/* 0x359b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_359e:
	/* 0x359e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_35a1:
	/* 0x35a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35a3:
	/* 0x35a3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_35a6:
	/* 0x35a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35ab:
	/* 0x35ab: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_35ae:
	/* 0x35ae: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_35b1:
	/* 0x35b1: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35b6:
	/* 0x35b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b8:
	/* 0x35b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35bb:
	/* 0x35bb: je     35ec <generic_sleepable_preload+0x35ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35ec;
	}
x86_l_35bd:
	/* 0x35bd: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_35c0:
	/* 0x35c0: je     35ea <generic_sleepable_preload+0x35ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35ea;
	}
x86_l_35c2:
	/* 0x35c2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_35c5:
	/* 0x35c5: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_35c9:
	/* 0x35c9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35ce:
	/* 0x35ce: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_35d1:
	/* 0x35d1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35d3:
	/* 0x35d3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_35d6:
	/* 0x35d6: call   35db <generic_sleepable_preload+0x35db> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_35db:
	/* 0x35db: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_35dd:
	/* 0x35dd: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_35e0:
	/* 0x35e0: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_35e2:
	/* 0x35e2: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_35e7:
	/* 0x35e7: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_35ea:
	/* 0x35ea: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ec:
	/* 0x35ec: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
	return 13808ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13808ULL: goto x86_l_35f0;
	case 13813ULL: goto x86_l_35f5;
	case 13815ULL: goto x86_l_35f7;
	case 13819ULL: goto x86_l_35fb;
	case 13824ULL: goto x86_l_3600;
	case 13826ULL: goto x86_l_3602;
	case 13828ULL: goto x86_l_3604;
	case 13835ULL: goto x86_l_360b;
	case 13837ULL: goto x86_l_360d;
	case 13838ULL: goto x86_l_360e;
	case 13843ULL: goto x86_l_3613;
	case 13845ULL: goto x86_l_3615;
	case 13850ULL: goto x86_l_361a;
	case 13852ULL: goto x86_l_361c;
	case 13856ULL: goto x86_l_3620;
	case 13859ULL: goto x86_l_3623;
	case 13865ULL: goto x86_l_3629;
	case 13868ULL: goto x86_l_362c;
	case 13874ULL: goto x86_l_3632;
	case 13877ULL: goto x86_l_3635;
	case 13883ULL: goto x86_l_363b;
	case 13886ULL: goto x86_l_363e;
	case 13892ULL: goto x86_l_3644;
	case 13897ULL: goto x86_l_3649;
	case 13902ULL: goto x86_l_364e;
	case 13904ULL: goto x86_l_3650;
	case 13910ULL: goto x86_l_3656;
	case 13914ULL: goto x86_l_365a;
	case 13917ULL: goto x86_l_365d;
	case 13923ULL: goto x86_l_3663;
	case 13926ULL: goto x86_l_3666;
	case 13932ULL: goto x86_l_366c;
	case 13935ULL: goto x86_l_366f;
	case 13941ULL: goto x86_l_3675;
	case 13944ULL: goto x86_l_3678;
	case 13950ULL: goto x86_l_367e;
	case 13955ULL: goto x86_l_3683;
	case 13960ULL: goto x86_l_3688;
	case 13968ULL: goto x86_l_3690;
	case 13976ULL: goto x86_l_3698;
	case 13982ULL: goto x86_l_369e;
	case 13984ULL: goto x86_l_36a0;
	case 13987ULL: goto x86_l_36a3;
	case 13993ULL: goto x86_l_36a9;
	case 13996ULL: goto x86_l_36ac;
	case 14002ULL: goto x86_l_36b2;
	case 14005ULL: goto x86_l_36b5;
	case 14011ULL: goto x86_l_36bb;
	case 14016ULL: goto x86_l_36c0;
	case 14019ULL: goto x86_l_36c3;
	case 14025ULL: goto x86_l_36c9;
	case 14030ULL: goto x86_l_36ce;
	case 14033ULL: goto x86_l_36d1;
	case 14039ULL: goto x86_l_36d7;
	case 14044ULL: goto x86_l_36dc;
	case 14047ULL: goto x86_l_36df;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14066ULL: goto x86_l_36f2;
	case 14074ULL: goto x86_l_36fa;
	case 14080ULL: goto x86_l_3700;
	case 14082ULL: goto x86_l_3702;
	case 14085ULL: goto x86_l_3705;
	case 14087ULL: goto x86_l_3707;
	case 14090ULL: goto x86_l_370a;
	case 14096ULL: goto x86_l_3710;
	case 14099ULL: goto x86_l_3713;
	case 14105ULL: goto x86_l_3719;
	case 14110ULL: goto x86_l_371e;
	case 14113ULL: goto x86_l_3721;
	case 14119ULL: goto x86_l_3727;
	case 14124ULL: goto x86_l_372c;
	case 14127ULL: goto x86_l_372f;
	case 14133ULL: goto x86_l_3735;
	case 14138ULL: goto x86_l_373a;
	case 14141ULL: goto x86_l_373d;
	case 14147ULL: goto x86_l_3743;
	case 14152ULL: goto x86_l_3748;
	case 14155ULL: goto x86_l_374b;
	case 14161ULL: goto x86_l_3751;
	case 14164ULL: goto x86_l_3754;
	case 14170ULL: goto x86_l_375a;
	case 14172ULL: goto x86_l_375c;
	case 14178ULL: goto x86_l_3762;
	case 14181ULL: goto x86_l_3765;
	case 14187ULL: goto x86_l_376b;
	case 14192ULL: goto x86_l_3770;
	case 14195ULL: goto x86_l_3773;
	case 14201ULL: goto x86_l_3779;
	case 14204ULL: goto x86_l_377c;
	case 14210ULL: goto x86_l_3782;
	case 14212ULL: goto x86_l_3784;
	case 14218ULL: goto x86_l_378a;
	case 14221ULL: goto x86_l_378d;
	case 14226ULL: goto x86_l_3792;
	case 14232ULL: goto x86_l_3798;
	case 14237ULL: goto x86_l_379d;
	case 14239ULL: goto x86_l_379f;
	case 14245ULL: goto x86_l_37a5;
	case 14248ULL: goto x86_l_37a8;
	case 14254ULL: goto x86_l_37ae;
	case 14259ULL: goto x86_l_37b3;
	case 14264ULL: goto x86_l_37b8;
	case 14266ULL: goto x86_l_37ba;
	case 14272ULL: goto x86_l_37c0;
	case 14275ULL: goto x86_l_37c3;
	case 14281ULL: goto x86_l_37c9;
	case 14286ULL: goto x86_l_37ce;
	case 14291ULL: goto x86_l_37d3;
	case 14294ULL: goto x86_l_37d6;
	case 14300ULL: goto x86_l_37dc;
	case 14308ULL: goto x86_l_37e4;
	case 14311ULL: goto x86_l_37e7;
	case 14317ULL: goto x86_l_37ed;
	case 14322ULL: goto x86_l_37f2;
	case 14325ULL: goto x86_l_37f5;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14339ULL: goto x86_l_3803;
	case 14345ULL: goto x86_l_3809;
	case 14353ULL: goto x86_l_3811;
	case 14356ULL: goto x86_l_3814;
	case 14362ULL: goto x86_l_381a;
	case 14367ULL: goto x86_l_381f;
	case 14370ULL: goto x86_l_3822;
	case 14376ULL: goto x86_l_3828;
	case 14381ULL: goto x86_l_382d;
	case 14384ULL: goto x86_l_3830;
	case 14390ULL: goto x86_l_3836;
	case 14398ULL: goto x86_l_383e;
	case 14401ULL: goto x86_l_3841;
	case 14407ULL: goto x86_l_3847;
	case 14412ULL: goto x86_l_384c;
	case 14415ULL: goto x86_l_384f;
	case 14421ULL: goto x86_l_3855;
	case 14426ULL: goto x86_l_385a;
	case 14429ULL: goto x86_l_385d;
	case 14435ULL: goto x86_l_3863;
	case 14443ULL: goto x86_l_386b;
	case 14446ULL: goto x86_l_386e;
	case 14452ULL: goto x86_l_3874;
	case 14457ULL: goto x86_l_3879;
	case 14460ULL: goto x86_l_387c;
	case 14466ULL: goto x86_l_3882;
	case 14471ULL: goto x86_l_3887;
	case 14476ULL: goto x86_l_388c;
	case 14478ULL: goto x86_l_388e;
	case 14483ULL: goto x86_l_3893;
	case 14488ULL: goto x86_l_3898;
	case 14493ULL: goto x86_l_389d;
	case 14495ULL: goto x86_l_389f;
	case 14500ULL: goto x86_l_38a4;
	case 14505ULL: goto x86_l_38a9;
	case 14510ULL: goto x86_l_38ae;
	case 14513ULL: goto x86_l_38b1;
	case 14517ULL: goto x86_l_38b5;
	case 14519ULL: goto x86_l_38b7;
	case 14522ULL: goto x86_l_38ba;
	case 14531ULL: goto x86_l_38c3;
	case 14537ULL: goto x86_l_38c9;
	case 14544ULL: goto x86_l_38d0;
	case 14547ULL: goto x86_l_38d3;
	case 14554ULL: goto x86_l_38da;
	case 14557ULL: goto x86_l_38dd;
	case 14561ULL: goto x86_l_38e1;
	case 14569ULL: goto x86_l_38e9;
	case 14571ULL: goto x86_l_38eb;
	case 14577ULL: goto x86_l_38f1;
	case 14580ULL: goto x86_l_38f4;
	case 14582ULL: goto x86_l_38f6;
	case 14587ULL: goto x86_l_38fb;
	case 14591ULL: goto x86_l_38ff;
	case 14594ULL: goto x86_l_3902;
	case 14599ULL: goto x86_l_3907;
	case 14601ULL: goto x86_l_3909;
	case 14603ULL: goto x86_l_390b;
	case 14609ULL: goto x86_l_3911;
	case 14618ULL: goto x86_l_391a;
	case 14624ULL: goto x86_l_3920;
	case 14631ULL: goto x86_l_3927;
	case 14635ULL: goto x86_l_392b;
	case 14644ULL: goto x86_l_3934;
	case 14646ULL: goto x86_l_3936;
	case 14651ULL: goto x86_l_393b;
	case 14655ULL: goto x86_l_393f;
	case 14658ULL: goto x86_l_3942;
	case 14663ULL: goto x86_l_3947;
	case 14665ULL: goto x86_l_3949;
	case 14667ULL: goto x86_l_394b;
	case 14673ULL: goto x86_l_3951;
	case 14682ULL: goto x86_l_395a;
	case 14688ULL: goto x86_l_3960;
	case 14695ULL: goto x86_l_3967;
	case 14699ULL: goto x86_l_396b;
	case 14708ULL: goto x86_l_3974;
	case 14710ULL: goto x86_l_3976;
	case 14715ULL: goto x86_l_397b;
	case 14719ULL: goto x86_l_397f;
	case 14722ULL: goto x86_l_3982;
	case 14727ULL: goto x86_l_3987;
	case 14729ULL: goto x86_l_3989;
	case 14731ULL: goto x86_l_398b;
	case 14737ULL: goto x86_l_3991;
	case 14746ULL: goto x86_l_399a;
	case 14752ULL: goto x86_l_39a0;
	case 14759ULL: goto x86_l_39a7;
	case 14763ULL: goto x86_l_39ab;
	case 14772ULL: goto x86_l_39b4;
	case 14774ULL: goto x86_l_39b6;
	case 14779ULL: goto x86_l_39bb;
	case 14783ULL: goto x86_l_39bf;
	case 14786ULL: goto x86_l_39c2;
	case 14791ULL: goto x86_l_39c7;
	case 14793ULL: goto x86_l_39c9;
	case 14795ULL: goto x86_l_39cb;
	case 14801ULL: goto x86_l_39d1;
	case 14810ULL: goto x86_l_39da;
	case 14816ULL: goto x86_l_39e0;
	case 14823ULL: goto x86_l_39e7;
	case 14827ULL: goto x86_l_39eb;
	case 14836ULL: goto x86_l_39f4;
	case 14838ULL: goto x86_l_39f6;
	case 14843ULL: goto x86_l_39fb;
	case 14847ULL: goto x86_l_39ff;
	case 14850ULL: goto x86_l_3a02;
	case 14855ULL: goto x86_l_3a07;
	case 14857ULL: goto x86_l_3a09;
	case 14859ULL: goto x86_l_3a0b;
	case 14865ULL: goto x86_l_3a11;
	case 14874ULL: goto x86_l_3a1a;
	case 14880ULL: goto x86_l_3a20;
	case 14887ULL: goto x86_l_3a27;
	case 14891ULL: goto x86_l_3a2b;
	case 14900ULL: goto x86_l_3a34;
	case 14902ULL: goto x86_l_3a36;
	case 14907ULL: goto x86_l_3a3b;
	case 14911ULL: goto x86_l_3a3f;
	case 14914ULL: goto x86_l_3a42;
	case 14919ULL: goto x86_l_3a47;
	case 14921ULL: goto x86_l_3a49;
	case 14923ULL: goto x86_l_3a4b;
	case 14929ULL: goto x86_l_3a51;
	case 14938ULL: goto x86_l_3a5a;
	case 14944ULL: goto x86_l_3a60;
	case 14951ULL: goto x86_l_3a67;
	case 14955ULL: goto x86_l_3a6b;
	case 14964ULL: goto x86_l_3a74;
	case 14966ULL: goto x86_l_3a76;
	case 14971ULL: goto x86_l_3a7b;
	case 14975ULL: goto x86_l_3a7f;
	case 14978ULL: goto x86_l_3a82;
	case 14983ULL: goto x86_l_3a87;
	case 14985ULL: goto x86_l_3a89;
	case 14987ULL: goto x86_l_3a8b;
	case 14993ULL: goto x86_l_3a91;
	case 15002ULL: goto x86_l_3a9a;
	case 15008ULL: goto x86_l_3aa0;
	case 15015ULL: goto x86_l_3aa7;
	case 15019ULL: goto x86_l_3aab;
	case 15028ULL: goto x86_l_3ab4;
	case 15030ULL: goto x86_l_3ab6;
	case 15035ULL: goto x86_l_3abb;
	case 15039ULL: goto x86_l_3abf;
	case 15042ULL: goto x86_l_3ac2;
	case 15047ULL: goto x86_l_3ac7;
	case 15049ULL: goto x86_l_3ac9;
	case 15051ULL: goto x86_l_3acb;
	case 15057ULL: goto x86_l_3ad1;
	case 15066ULL: goto x86_l_3ada;
	case 15072ULL: goto x86_l_3ae0;
	case 15079ULL: goto x86_l_3ae7;
	case 15083ULL: goto x86_l_3aeb;
	case 15092ULL: goto x86_l_3af4;
	case 15094ULL: goto x86_l_3af6;
	case 15099ULL: goto x86_l_3afb;
	case 15103ULL: goto x86_l_3aff;
	case 15106ULL: goto x86_l_3b02;
	case 15111ULL: goto x86_l_3b07;
	case 15113ULL: goto x86_l_3b09;
	case 15115ULL: goto x86_l_3b0b;
	case 15121ULL: goto x86_l_3b11;
	case 15126ULL: goto x86_l_3b16;
	case 15135ULL: goto x86_l_3b1f;
	case 15141ULL: goto x86_l_3b25;
	case 15148ULL: goto x86_l_3b2c;
	case 15152ULL: goto x86_l_3b30;
	case 15161ULL: goto x86_l_3b39;
	case 15167ULL: goto x86_l_3b3f;
	case 15172ULL: goto x86_l_3b44;
	case 15177ULL: goto x86_l_3b49;
	case 15180ULL: goto x86_l_3b4c;
	case 15182ULL: goto x86_l_3b4e;
	case 15187ULL: goto x86_l_3b53;
	case 15191ULL: goto x86_l_3b57;
	case 15194ULL: goto x86_l_3b5a;
	case 15199ULL: goto x86_l_3b5f;
	case 15201ULL: goto x86_l_3b61;
	case 15203ULL: goto x86_l_3b63;
	case 15209ULL: goto x86_l_3b69;
	case 15218ULL: goto x86_l_3b72;
	case 15224ULL: goto x86_l_3b78;
	case 15231ULL: goto x86_l_3b7f;
	case 15235ULL: goto x86_l_3b83;
	case 15244ULL: goto x86_l_3b8c;
	case 15246ULL: goto x86_l_3b8e;
	case 15251ULL: goto x86_l_3b93;
	case 15255ULL: goto x86_l_3b97;
	case 15258ULL: goto x86_l_3b9a;
	case 15263ULL: goto x86_l_3b9f;
	case 15265ULL: goto x86_l_3ba1;
	case 15267ULL: goto x86_l_3ba3;
	case 15273ULL: goto x86_l_3ba9;
	case 15282ULL: goto x86_l_3bb2;
	case 15288ULL: goto x86_l_3bb8;
	case 15295ULL: goto x86_l_3bbf;
	case 15299ULL: goto x86_l_3bc3;
	case 15308ULL: goto x86_l_3bcc;
	case 15310ULL: goto x86_l_3bce;
	case 15315ULL: goto x86_l_3bd3;
	case 15319ULL: goto x86_l_3bd7;
	case 15322ULL: goto x86_l_3bda;
	case 15327ULL: goto x86_l_3bdf;
	case 15329ULL: goto x86_l_3be1;
	case 15331ULL: goto x86_l_3be3;
	case 15337ULL: goto x86_l_3be9;
	case 15346ULL: goto x86_l_3bf2;
	case 15352ULL: goto x86_l_3bf8;
	case 15359ULL: goto x86_l_3bff;
	case 15363ULL: goto x86_l_3c03;
	case 15372ULL: goto x86_l_3c0c;
	case 15374ULL: goto x86_l_3c0e;
	case 15379ULL: goto x86_l_3c13;
	case 15383ULL: goto x86_l_3c17;
	case 15386ULL: goto x86_l_3c1a;
	case 15391ULL: goto x86_l_3c1f;
	case 15393ULL: goto x86_l_3c21;
	case 15395ULL: goto x86_l_3c23;
	case 15401ULL: goto x86_l_3c29;
	case 15410ULL: goto x86_l_3c32;
	case 15416ULL: goto x86_l_3c38;
	case 15423ULL: goto x86_l_3c3f;
	case 15427ULL: goto x86_l_3c43;
	case 15436ULL: goto x86_l_3c4c;
	case 15438ULL: goto x86_l_3c4e;
	case 15443ULL: goto x86_l_3c53;
	case 15447ULL: goto x86_l_3c57;
	case 15450ULL: goto x86_l_3c5a;
	case 15455ULL: goto x86_l_3c5f;
	case 15457ULL: goto x86_l_3c61;
	case 15459ULL: goto x86_l_3c63;
	case 15465ULL: goto x86_l_3c69;
	case 15474ULL: goto x86_l_3c72;
	case 15480ULL: goto x86_l_3c78;
	case 15487ULL: goto x86_l_3c7f;
	case 15491ULL: goto x86_l_3c83;
	case 15500ULL: goto x86_l_3c8c;
	case 15502ULL: goto x86_l_3c8e;
	case 15507ULL: goto x86_l_3c93;
	case 15511ULL: goto x86_l_3c97;
	case 15514ULL: goto x86_l_3c9a;
	case 15519ULL: goto x86_l_3c9f;
	case 15521ULL: goto x86_l_3ca1;
	case 15523ULL: goto x86_l_3ca3;
	case 15529ULL: goto x86_l_3ca9;
	case 15538ULL: goto x86_l_3cb2;
	case 15544ULL: goto x86_l_3cb8;
	case 15551ULL: goto x86_l_3cbf;
	case 15555ULL: goto x86_l_3cc3;
	case 15564ULL: goto x86_l_3ccc;
	case 15566ULL: goto x86_l_3cce;
	case 15571ULL: goto x86_l_3cd3;
	case 15575ULL: goto x86_l_3cd7;
	case 15578ULL: goto x86_l_3cda;
	case 15583ULL: goto x86_l_3cdf;
	case 15585ULL: goto x86_l_3ce1;
	case 15587ULL: goto x86_l_3ce3;
	case 15593ULL: goto x86_l_3ce9;
	case 15602ULL: goto x86_l_3cf2;
	case 15608ULL: goto x86_l_3cf8;
	case 15615ULL: goto x86_l_3cff;
	case 15619ULL: goto x86_l_3d03;
	case 15628ULL: goto x86_l_3d0c;
	case 15630ULL: goto x86_l_3d0e;
	case 15635ULL: goto x86_l_3d13;
	default: return 0xffffffffffffffffULL;
	}
x86_l_35f0:
	/* 0x35f0: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_35f5:
	/* 0x35f5: jne    3613 <generic_sleepable_preload+0x3613> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3613;
	}
x86_l_35f7:
	/* 0x35f7: mov    eax,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_35fb:
	/* 0x35fb: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_3600:
	/* 0x3600: jne    364e <generic_sleepable_preload+0x364e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_364e;
	}
x86_l_3602:
	/* 0x3602: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3604:
	/* 0x3604: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_360b:
	/* 0x360b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_360d:
	/* 0x360d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_360e:
	/* 0x360e: jmp    537f <generic_sleepable_preload+0x537f> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_3613:
	/* 0x3613: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3615:
	/* 0x3615: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_361a:
	/* 0x361a: js     3688 <generic_sleepable_preload+0x3688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3688;
	}
x86_l_361c:
	/* 0x361c: mov    ecx,DWORD PTR [r13+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3620:
	/* 0x3620: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3623:
	/* 0x3623: jle    379d <generic_sleepable_preload+0x379d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_379d;
	}
x86_l_3629:
	/* 0x3629: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_362c:
	/* 0x362c: je     3887 <generic_sleepable_preload+0x3887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3887;
	}
x86_l_3632:
	/* 0x3632: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3635:
	/* 0x3635: je     3898 <generic_sleepable_preload+0x3898> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3898;
	}
x86_l_363b:
	/* 0x363b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_363e:
	/* 0x363e: jne    38b5 <generic_sleepable_preload+0x38b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38b5;
	}
x86_l_3644:
	/* 0x3644: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3649:
	/* 0x3649: jmp    38ae <generic_sleepable_preload+0x38ae> */
	goto x86_l_38ae;
x86_l_364e:
	/* 0x364e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3650:
	/* 0x3650: js     36ea <generic_sleepable_preload+0x36ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36ea;
	}
x86_l_3656:
	/* 0x3656: mov    ecx,DWORD PTR [r13+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_365a:
	/* 0x365a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_365d:
	/* 0x365d: jle    37b8 <generic_sleepable_preload+0x37b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_37b8;
	}
x86_l_3663:
	/* 0x3663: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3666:
	/* 0x3666: je     388e <generic_sleepable_preload+0x388e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388e;
	}
x86_l_366c:
	/* 0x366c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_366f:
	/* 0x366f: je     389f <generic_sleepable_preload+0x389f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389f;
	}
x86_l_3675:
	/* 0x3675: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3678:
	/* 0x3678: jne    3dd7 <generic_sleepable_preload+0x3dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15831ULL;
	}
x86_l_367e:
	/* 0x367e: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3683:
	/* 0x3683: jmp    3dd0 <generic_sleepable_preload+0x3dd0> */
	return 15824ULL;
x86_l_3688:
	/* 0x3688: movzx  ecx,BYTE PTR [r13+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_3690:
	/* 0x3690: movzx  eax,WORD PTR [r13+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_3698:
	/* 0x3698: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_369e:
	/* 0x369e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36a0:
	/* 0x36a0: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_36a3:
	/* 0x36a3: jle    3748 <generic_sleepable_preload+0x3748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3748;
	}
x86_l_36a9:
	/* 0x36a9: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_36ac:
	/* 0x36ac: jle    37d3 <generic_sleepable_preload+0x37d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_37d3;
	}
x86_l_36b2:
	/* 0x36b2: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_36b5:
	/* 0x36b5: jle    43d8 <generic_sleepable_preload+0x43d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 17368ULL;
	}
x86_l_36bb:
	/* 0x36bb: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36c0:
	/* 0x36c0: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_36c3:
	/* 0x36c3: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17448ULL;
	}
x86_l_36c9:
	/* 0x36c9: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_36ce:
	/* 0x36ce: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_36d1:
	/* 0x36d1: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17448ULL;
	}
x86_l_36d7:
	/* 0x36d7: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_36dc:
	/* 0x36dc: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_36df:
	/* 0x36df: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17448ULL;
	}
x86_l_36e5:
	/* 0x36e5: jmp    443b <generic_sleepable_preload+0x443b> */
	return 17467ULL;
x86_l_36ea:
	/* 0x36ea: movzx  ecx,BYTE PTR [r13+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_36f2:
	/* 0x36f2: movzx  eax,WORD PTR [r13+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_36fa:
	/* 0x36fa: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_3700:
	/* 0x3700: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3702:
	/* 0x3702: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3705:
	/* 0x3705: jle    3770 <generic_sleepable_preload+0x3770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3770;
	}
x86_l_3707:
	/* 0x3707: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_370a:
	/* 0x370a: jle    3800 <generic_sleepable_preload+0x3800> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3800;
	}
x86_l_3710:
	/* 0x3710: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3713:
	/* 0x3713: jle    43ee <generic_sleepable_preload+0x43ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 17390ULL;
	}
x86_l_3719:
	/* 0x3719: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_371e:
	/* 0x371e: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3721:
	/* 0x3721: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_3727:
	/* 0x3727: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_372c:
	/* 0x372c: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_372f:
	/* 0x372f: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_3735:
	/* 0x3735: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_373a:
	/* 0x373a: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_373d:
	/* 0x373d: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_3743:
	/* 0x3743: jmp    497b <generic_sleepable_preload+0x497b> */
	return 18811ULL;
x86_l_3748:
	/* 0x3748: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_374b:
	/* 0x374b: jg     382d <generic_sleepable_preload+0x382d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_382d;
	}
x86_l_3751:
	/* 0x3751: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3754:
	/* 0x3754: jg     434c <generic_sleepable_preload+0x434c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17228ULL;
	}
x86_l_375a:
	/* 0x375a: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_375c:
	/* 0x375c: je     4423 <generic_sleepable_preload+0x4423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17443ULL;
	}
x86_l_3762:
	/* 0x3762: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3765:
	/* 0x3765: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17448ULL;
	}
x86_l_376b:
	/* 0x376b: jmp    443b <generic_sleepable_preload+0x443b> */
	return 17467ULL;
x86_l_3770:
	/* 0x3770: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3773:
	/* 0x3773: jg     385a <generic_sleepable_preload+0x385a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_385a;
	}
x86_l_3779:
	/* 0x3779: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_377c:
	/* 0x377c: jg     4370 <generic_sleepable_preload+0x4370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17264ULL;
	}
x86_l_3782:
	/* 0x3782: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3784:
	/* 0x3784: je     4963 <generic_sleepable_preload+0x4963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18787ULL;
	}
x86_l_378a:
	/* 0x378a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_378d:
	/* 0x378d: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3792:
	/* 0x3792: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_3798:
	/* 0x3798: jmp    497b <generic_sleepable_preload+0x497b> */
	return 18811ULL;
x86_l_379d:
	/* 0x379d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_379f:
	/* 0x379f: je     38a9 <generic_sleepable_preload+0x38a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a9;
	}
x86_l_37a5:
	/* 0x37a5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_37a8:
	/* 0x37a8: jne    38b5 <generic_sleepable_preload+0x38b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38b5;
	}
x86_l_37ae:
	/* 0x37ae: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37b3:
	/* 0x37b3: jmp    38ae <generic_sleepable_preload+0x38ae> */
	goto x86_l_38ae;
x86_l_37b8:
	/* 0x37b8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_37ba:
	/* 0x37ba: je     3dcb <generic_sleepable_preload+0x3dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15819ULL;
	}
x86_l_37c0:
	/* 0x37c0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_37c3:
	/* 0x37c3: jne    3dd7 <generic_sleepable_preload+0x3dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15831ULL;
	}
x86_l_37c9:
	/* 0x37c9: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37ce:
	/* 0x37ce: jmp    3dd0 <generic_sleepable_preload+0x3dd0> */
	return 15824ULL;
x86_l_37d3:
	/* 0x37d3: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_37d6:
	/* 0x37d6: jg     4304 <generic_sleepable_preload+0x4304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17156ULL;
	}
x86_l_37dc:
	/* 0x37dc: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_37e4:
	/* 0x37e4: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37e7:
	/* 0x37e7: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17448ULL;
	}
x86_l_37ed:
	/* 0x37ed: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37f2:
	/* 0x37f2: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_37f5:
	/* 0x37f5: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17448ULL;
	}
x86_l_37fb:
	/* 0x37fb: jmp    443b <generic_sleepable_preload+0x443b> */
	return 17467ULL;
x86_l_3800:
	/* 0x3800: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3803:
	/* 0x3803: jg     4328 <generic_sleepable_preload+0x4328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17192ULL;
	}
x86_l_3809:
	/* 0x3809: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3811:
	/* 0x3811: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3814:
	/* 0x3814: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_381a:
	/* 0x381a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_381f:
	/* 0x381f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3822:
	/* 0x3822: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_3828:
	/* 0x3828: jmp    497b <generic_sleepable_preload+0x497b> */
	return 18811ULL;
x86_l_382d:
	/* 0x382d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3830:
	/* 0x3830: jg     4394 <generic_sleepable_preload+0x4394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17300ULL;
	}
x86_l_3836:
	/* 0x3836: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_383e:
	/* 0x383e: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3841:
	/* 0x3841: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17448ULL;
	}
x86_l_3847:
	/* 0x3847: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_384c:
	/* 0x384c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_384f:
	/* 0x384f: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17448ULL;
	}
x86_l_3855:
	/* 0x3855: jmp    443b <generic_sleepable_preload+0x443b> */
	return 17467ULL;
x86_l_385a:
	/* 0x385a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_385d:
	/* 0x385d: jg     43b4 <generic_sleepable_preload+0x43b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 17332ULL;
	}
x86_l_3863:
	/* 0x3863: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_386b:
	/* 0x386b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_386e:
	/* 0x386e: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_3874:
	/* 0x3874: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3879:
	/* 0x3879: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_387c:
	/* 0x387c: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_3882:
	/* 0x3882: jmp    497b <generic_sleepable_preload+0x497b> */
	return 18811ULL;
x86_l_3887:
	/* 0x3887: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_388c:
	/* 0x388c: jmp    38ae <generic_sleepable_preload+0x38ae> */
	goto x86_l_38ae;
x86_l_388e:
	/* 0x388e: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3893:
	/* 0x3893: jmp    3dd0 <generic_sleepable_preload+0x3dd0> */
	return 15824ULL;
x86_l_3898:
	/* 0x3898: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_389d:
	/* 0x389d: jmp    38ae <generic_sleepable_preload+0x38ae> */
	goto x86_l_38ae;
x86_l_389f:
	/* 0x389f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38a4:
	/* 0x38a4: jmp    3dd0 <generic_sleepable_preload+0x3dd0> */
	return 15824ULL;
x86_l_38a9:
	/* 0x38a9: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_38ae:
	/* 0x38ae: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38b1:
	/* 0x38b1: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38b5:
	/* 0x38b5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38b7:
	/* 0x38b7: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_38ba:
	/* 0x38ba: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_38c3:
	/* 0x38c3: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_38c9:
	/* 0x38c9: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_38d0:
	/* 0x38d0: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_38d3:
	/* 0x38d3: mov    edx,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_38da:
	/* 0x38da: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38dd:
	/* 0x38dd: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38e1:
	/* 0x38e1: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_38e9:
	/* 0x38e9: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_38eb:
	/* 0x38eb: je     3b49 <generic_sleepable_preload+0x3b49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b49;
	}
x86_l_38f1:
	/* 0x38f1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_38f4:
	/* 0x38f4: je     3911 <generic_sleepable_preload+0x3911> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3911;
	}
x86_l_38f6:
	/* 0x38f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38fb:
	/* 0x38fb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38ff:
	/* 0x38ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3902:
	/* 0x3902: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3907:
	/* 0x3907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3909:
	/* 0x3909: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_390b:
	/* 0x390b: js     3dc1 <generic_sleepable_preload+0x3dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15809ULL;
	}
x86_l_3911:
	/* 0x3911: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_391a:
	/* 0x391a: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3920:
	/* 0x3920: mov    eax,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3927:
	/* 0x3927: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_392b:
	/* 0x392b: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3934:
	/* 0x3934: je     3951 <generic_sleepable_preload+0x3951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3951;
	}
x86_l_3936:
	/* 0x3936: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_393b:
	/* 0x393b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_393f:
	/* 0x393f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3942:
	/* 0x3942: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3947:
	/* 0x3947: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3949:
	/* 0x3949: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_394b:
	/* 0x394b: js     440f <generic_sleepable_preload+0x440f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17423ULL;
	}
x86_l_3951:
	/* 0x3951: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_395a:
	/* 0x395a: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3960:
	/* 0x3960: mov    eax,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3967:
	/* 0x3967: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_396b:
	/* 0x396b: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3974:
	/* 0x3974: je     3991 <generic_sleepable_preload+0x3991> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3991;
	}
x86_l_3976:
	/* 0x3976: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_397b:
	/* 0x397b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_397f:
	/* 0x397f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3982:
	/* 0x3982: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3987:
	/* 0x3987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3989:
	/* 0x3989: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_398b:
	/* 0x398b: js     4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20152ULL;
	}
x86_l_3991:
	/* 0x3991: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_399a:
	/* 0x399a: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_39a0:
	/* 0x39a0: mov    eax,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_39a7:
	/* 0x39a7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39ab:
	/* 0x39ab: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_39b4:
	/* 0x39b4: je     39d1 <generic_sleepable_preload+0x39d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39d1;
	}
x86_l_39b6:
	/* 0x39b6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39bb:
	/* 0x39bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39bf:
	/* 0x39bf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_39c2:
	/* 0x39c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39c7:
	/* 0x39c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c9:
	/* 0x39c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39cb:
	/* 0x39cb: js     4ee0 <generic_sleepable_preload+0x4ee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20192ULL;
	}
x86_l_39d1:
	/* 0x39d1: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_39da:
	/* 0x39da: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_39e0:
	/* 0x39e0: mov    eax,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_39e7:
	/* 0x39e7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39eb:
	/* 0x39eb: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_39f4:
	/* 0x39f4: je     3a11 <generic_sleepable_preload+0x3a11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a11;
	}
x86_l_39f6:
	/* 0x39f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39fb:
	/* 0x39fb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39ff:
	/* 0x39ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a02:
	/* 0x3a02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a07:
	/* 0x3a07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a09:
	/* 0x3a09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a0b:
	/* 0x3a0b: js     4f05 <generic_sleepable_preload+0x4f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20229ULL;
	}
x86_l_3a11:
	/* 0x3a11: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3a1a:
	/* 0x3a1a: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3a20:
	/* 0x3a20: mov    eax,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3a27:
	/* 0x3a27: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a2b:
	/* 0x3a2b: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3a34:
	/* 0x3a34: je     3a51 <generic_sleepable_preload+0x3a51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a51;
	}
x86_l_3a36:
	/* 0x3a36: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a3b:
	/* 0x3a3b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a3f:
	/* 0x3a3f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a42:
	/* 0x3a42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a47:
	/* 0x3a47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a49:
	/* 0x3a49: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a4b:
	/* 0x3a4b: js     4f2a <generic_sleepable_preload+0x4f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20266ULL;
	}
x86_l_3a51:
	/* 0x3a51: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_3a5a:
	/* 0x3a5a: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3a60:
	/* 0x3a60: mov    eax,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_3a67:
	/* 0x3a67: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a6b:
	/* 0x3a6b: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_3a74:
	/* 0x3a74: je     3a91 <generic_sleepable_preload+0x3a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a91;
	}
x86_l_3a76:
	/* 0x3a76: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a7b:
	/* 0x3a7b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a7f:
	/* 0x3a7f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a82:
	/* 0x3a82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a87:
	/* 0x3a87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a89:
	/* 0x3a89: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a8b:
	/* 0x3a8b: js     4f4f <generic_sleepable_preload+0x4f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20303ULL;
	}
x86_l_3a91:
	/* 0x3a91: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_3a9a:
	/* 0x3a9a: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3aa0:
	/* 0x3aa0: mov    eax,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_3aa7:
	/* 0x3aa7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3aab:
	/* 0x3aab: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_3ab4:
	/* 0x3ab4: je     3ad1 <generic_sleepable_preload+0x3ad1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad1;
	}
x86_l_3ab6:
	/* 0x3ab6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3abb:
	/* 0x3abb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3abf:
	/* 0x3abf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ac2:
	/* 0x3ac2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ac7:
	/* 0x3ac7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac9:
	/* 0x3ac9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3acb:
	/* 0x3acb: js     5231 <generic_sleepable_preload+0x5231> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21041ULL;
	}
x86_l_3ad1:
	/* 0x3ad1: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_3ada:
	/* 0x3ada: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3ae0:
	/* 0x3ae0: mov    eax,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_3ae7:
	/* 0x3ae7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3aeb:
	/* 0x3aeb: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_3af4:
	/* 0x3af4: je     3b11 <generic_sleepable_preload+0x3b11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b11;
	}
x86_l_3af6:
	/* 0x3af6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3afb:
	/* 0x3afb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aff:
	/* 0x3aff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b02:
	/* 0x3b02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b07:
	/* 0x3b07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b09:
	/* 0x3b09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b0b:
	/* 0x3b0b: js     52b7 <generic_sleepable_preload+0x52b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21175ULL;
	}
x86_l_3b11:
	/* 0x3b11: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b16:
	/* 0x3b16: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3b1f:
	/* 0x3b1f: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3b25:
	/* 0x3b25: mov    eax,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_3b2c:
	/* 0x3b2c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b30:
	/* 0x3b30: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3b39:
	/* 0x3b39: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3b3f:
	/* 0x3b3f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b44:
	/* 0x3b44: jmp    3da1 <generic_sleepable_preload+0x3da1> */
	return 15777ULL;
x86_l_3b49:
	/* 0x3b49: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3b4c:
	/* 0x3b4c: je     3b69 <generic_sleepable_preload+0x3b69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b69;
	}
x86_l_3b4e:
	/* 0x3b4e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b53:
	/* 0x3b53: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b57:
	/* 0x3b57: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b5a:
	/* 0x3b5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b5f:
	/* 0x3b5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b61:
	/* 0x3b61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b63:
	/* 0x3b63: js     3dc1 <generic_sleepable_preload+0x3dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15809ULL;
	}
x86_l_3b69:
	/* 0x3b69: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_3b72:
	/* 0x3b72: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3b78:
	/* 0x3b78: mov    eax,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3b7f:
	/* 0x3b7f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b83:
	/* 0x3b83: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_3b8c:
	/* 0x3b8c: je     3ba9 <generic_sleepable_preload+0x3ba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ba9;
	}
x86_l_3b8e:
	/* 0x3b8e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b93:
	/* 0x3b93: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b97:
	/* 0x3b97: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3b9a:
	/* 0x3b9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b9f:
	/* 0x3b9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ba1:
	/* 0x3ba1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ba3:
	/* 0x3ba3: js     440f <generic_sleepable_preload+0x440f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17423ULL;
	}
x86_l_3ba9:
	/* 0x3ba9: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3bb2:
	/* 0x3bb2: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3bb8:
	/* 0x3bb8: mov    eax,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3bbf:
	/* 0x3bbf: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3bc3:
	/* 0x3bc3: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3bcc:
	/* 0x3bcc: je     3be9 <generic_sleepable_preload+0x3be9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3be9;
	}
x86_l_3bce:
	/* 0x3bce: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3bd3:
	/* 0x3bd3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bd7:
	/* 0x3bd7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3bda:
	/* 0x3bda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bdf:
	/* 0x3bdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be1:
	/* 0x3be1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3be3:
	/* 0x3be3: js     4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20152ULL;
	}
x86_l_3be9:
	/* 0x3be9: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3bf2:
	/* 0x3bf2: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3bf8:
	/* 0x3bf8: mov    eax,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3bff:
	/* 0x3bff: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3c03:
	/* 0x3c03: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3c0c:
	/* 0x3c0c: je     3c29 <generic_sleepable_preload+0x3c29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c29;
	}
x86_l_3c0e:
	/* 0x3c0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c13:
	/* 0x3c13: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c17:
	/* 0x3c17: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c1a:
	/* 0x3c1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c1f:
	/* 0x3c1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c21:
	/* 0x3c21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c23:
	/* 0x3c23: js     4ee0 <generic_sleepable_preload+0x4ee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20192ULL;
	}
x86_l_3c29:
	/* 0x3c29: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_3c32:
	/* 0x3c32: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3c38:
	/* 0x3c38: mov    eax,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_3c3f:
	/* 0x3c3f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3c43:
	/* 0x3c43: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_3c4c:
	/* 0x3c4c: je     3c69 <generic_sleepable_preload+0x3c69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c69;
	}
x86_l_3c4e:
	/* 0x3c4e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c53:
	/* 0x3c53: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c57:
	/* 0x3c57: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c5a:
	/* 0x3c5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c5f:
	/* 0x3c5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c61:
	/* 0x3c61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c63:
	/* 0x3c63: js     4f05 <generic_sleepable_preload+0x4f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20229ULL;
	}
x86_l_3c69:
	/* 0x3c69: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3c72:
	/* 0x3c72: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3c78:
	/* 0x3c78: mov    eax,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3c7f:
	/* 0x3c7f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3c83:
	/* 0x3c83: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3c8c:
	/* 0x3c8c: je     3ca9 <generic_sleepable_preload+0x3ca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ca9;
	}
x86_l_3c8e:
	/* 0x3c8e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c93:
	/* 0x3c93: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c97:
	/* 0x3c97: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c9a:
	/* 0x3c9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c9f:
	/* 0x3c9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ca1:
	/* 0x3ca1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ca3:
	/* 0x3ca3: js     4f2a <generic_sleepable_preload+0x4f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20266ULL;
	}
x86_l_3ca9:
	/* 0x3ca9: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_3cb2:
	/* 0x3cb2: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3cb8:
	/* 0x3cb8: mov    eax,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_3cbf:
	/* 0x3cbf: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3cc3:
	/* 0x3cc3: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_3ccc:
	/* 0x3ccc: je     3ce9 <generic_sleepable_preload+0x3ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ce9;
	}
x86_l_3cce:
	/* 0x3cce: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cd3:
	/* 0x3cd3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cd7:
	/* 0x3cd7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3cda:
	/* 0x3cda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cdf:
	/* 0x3cdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ce1:
	/* 0x3ce1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ce3:
	/* 0x3ce3: js     4f4f <generic_sleepable_preload+0x4f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20303ULL;
	}
x86_l_3ce9:
	/* 0x3ce9: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_3cf2:
	/* 0x3cf2: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3cf8:
	/* 0x3cf8: mov    eax,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_3cff:
	/* 0x3cff: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3d03:
	/* 0x3d03: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_3d0c:
	/* 0x3d0c: je     3d29 <generic_sleepable_preload+0x3d29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15657ULL;
	}
x86_l_3d0e:
	/* 0x3d0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d13:
	/* 0x3d13: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 15639ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15639ULL: goto x86_l_3d17;
	case 15642ULL: goto x86_l_3d1a;
	case 15647ULL: goto x86_l_3d1f;
	case 15649ULL: goto x86_l_3d21;
	case 15651ULL: goto x86_l_3d23;
	case 15657ULL: goto x86_l_3d29;
	case 15662ULL: goto x86_l_3d2e;
	case 15671ULL: goto x86_l_3d37;
	case 15677ULL: goto x86_l_3d3d;
	case 15684ULL: goto x86_l_3d44;
	case 15688ULL: goto x86_l_3d48;
	case 15697ULL: goto x86_l_3d51;
	case 15699ULL: goto x86_l_3d53;
	case 15704ULL: goto x86_l_3d58;
	case 15708ULL: goto x86_l_3d5c;
	case 15711ULL: goto x86_l_3d5f;
	case 15716ULL: goto x86_l_3d64;
	case 15718ULL: goto x86_l_3d66;
	case 15720ULL: goto x86_l_3d68;
	case 15726ULL: goto x86_l_3d6e;
	case 15731ULL: goto x86_l_3d73;
	case 15740ULL: goto x86_l_3d7c;
	case 15746ULL: goto x86_l_3d82;
	case 15753ULL: goto x86_l_3d89;
	case 15757ULL: goto x86_l_3d8d;
	case 15766ULL: goto x86_l_3d96;
	case 15772ULL: goto x86_l_3d9c;
	case 15777ULL: goto x86_l_3da1;
	case 15781ULL: goto x86_l_3da5;
	case 15784ULL: goto x86_l_3da8;
	case 15789ULL: goto x86_l_3dad;
	case 15791ULL: goto x86_l_3daf;
	case 15793ULL: goto x86_l_3db1;
	case 15799ULL: goto x86_l_3db7;
	case 15804ULL: goto x86_l_3dbc;
	case 15809ULL: goto x86_l_3dc1;
	case 15814ULL: goto x86_l_3dc6;
	case 15819ULL: goto x86_l_3dcb;
	case 15824ULL: goto x86_l_3dd0;
	case 15827ULL: goto x86_l_3dd3;
	case 15831ULL: goto x86_l_3dd7;
	case 15833ULL: goto x86_l_3dd9;
	case 15836ULL: goto x86_l_3ddc;
	case 15841ULL: goto x86_l_3de1;
	case 15849ULL: goto x86_l_3de9;
	case 15855ULL: goto x86_l_3def;
	case 15862ULL: goto x86_l_3df6;
	case 15865ULL: goto x86_l_3df9;
	case 15871ULL: goto x86_l_3dff;
	case 15874ULL: goto x86_l_3e02;
	case 15878ULL: goto x86_l_3e06;
	case 15885ULL: goto x86_l_3e0d;
	case 15887ULL: goto x86_l_3e0f;
	case 15893ULL: goto x86_l_3e15;
	case 15896ULL: goto x86_l_3e18;
	case 15898ULL: goto x86_l_3e1a;
	case 15903ULL: goto x86_l_3e1f;
	case 15907ULL: goto x86_l_3e23;
	case 15910ULL: goto x86_l_3e26;
	case 15915ULL: goto x86_l_3e2b;
	case 15917ULL: goto x86_l_3e2d;
	case 15919ULL: goto x86_l_3e2f;
	case 15925ULL: goto x86_l_3e35;
	case 15930ULL: goto x86_l_3e3a;
	case 15938ULL: goto x86_l_3e42;
	case 15944ULL: goto x86_l_3e48;
	case 15950ULL: goto x86_l_3e4e;
	case 15954ULL: goto x86_l_3e52;
	case 15962ULL: goto x86_l_3e5a;
	case 15964ULL: goto x86_l_3e5c;
	case 15969ULL: goto x86_l_3e61;
	case 15973ULL: goto x86_l_3e65;
	case 15976ULL: goto x86_l_3e68;
	case 15981ULL: goto x86_l_3e6d;
	case 15983ULL: goto x86_l_3e6f;
	case 15985ULL: goto x86_l_3e71;
	case 15991ULL: goto x86_l_3e77;
	case 15996ULL: goto x86_l_3e7c;
	case 16004ULL: goto x86_l_3e84;
	case 16010ULL: goto x86_l_3e8a;
	case 16016ULL: goto x86_l_3e90;
	case 16020ULL: goto x86_l_3e94;
	case 16028ULL: goto x86_l_3e9c;
	case 16030ULL: goto x86_l_3e9e;
	case 16035ULL: goto x86_l_3ea3;
	case 16039ULL: goto x86_l_3ea7;
	case 16042ULL: goto x86_l_3eaa;
	case 16047ULL: goto x86_l_3eaf;
	case 16049ULL: goto x86_l_3eb1;
	case 16051ULL: goto x86_l_3eb3;
	case 16057ULL: goto x86_l_3eb9;
	case 16062ULL: goto x86_l_3ebe;
	case 16070ULL: goto x86_l_3ec6;
	case 16076ULL: goto x86_l_3ecc;
	case 16082ULL: goto x86_l_3ed2;
	case 16086ULL: goto x86_l_3ed6;
	case 16094ULL: goto x86_l_3ede;
	case 16096ULL: goto x86_l_3ee0;
	case 16101ULL: goto x86_l_3ee5;
	case 16105ULL: goto x86_l_3ee9;
	case 16108ULL: goto x86_l_3eec;
	case 16113ULL: goto x86_l_3ef1;
	case 16115ULL: goto x86_l_3ef3;
	case 16117ULL: goto x86_l_3ef5;
	case 16123ULL: goto x86_l_3efb;
	case 16128ULL: goto x86_l_3f00;
	case 16136ULL: goto x86_l_3f08;
	case 16142ULL: goto x86_l_3f0e;
	case 16148ULL: goto x86_l_3f14;
	case 16152ULL: goto x86_l_3f18;
	case 16160ULL: goto x86_l_3f20;
	case 16162ULL: goto x86_l_3f22;
	case 16167ULL: goto x86_l_3f27;
	case 16171ULL: goto x86_l_3f2b;
	case 16174ULL: goto x86_l_3f2e;
	case 16179ULL: goto x86_l_3f33;
	case 16181ULL: goto x86_l_3f35;
	case 16183ULL: goto x86_l_3f37;
	case 16189ULL: goto x86_l_3f3d;
	case 16194ULL: goto x86_l_3f42;
	case 16202ULL: goto x86_l_3f4a;
	case 16208ULL: goto x86_l_3f50;
	case 16214ULL: goto x86_l_3f56;
	case 16218ULL: goto x86_l_3f5a;
	case 16226ULL: goto x86_l_3f62;
	case 16228ULL: goto x86_l_3f64;
	case 16233ULL: goto x86_l_3f69;
	case 16237ULL: goto x86_l_3f6d;
	case 16240ULL: goto x86_l_3f70;
	case 16245ULL: goto x86_l_3f75;
	case 16247ULL: goto x86_l_3f77;
	case 16249ULL: goto x86_l_3f79;
	case 16255ULL: goto x86_l_3f7f;
	case 16260ULL: goto x86_l_3f84;
	case 16268ULL: goto x86_l_3f8c;
	case 16274ULL: goto x86_l_3f92;
	case 16280ULL: goto x86_l_3f98;
	case 16284ULL: goto x86_l_3f9c;
	case 16292ULL: goto x86_l_3fa4;
	case 16294ULL: goto x86_l_3fa6;
	case 16299ULL: goto x86_l_3fab;
	case 16303ULL: goto x86_l_3faf;
	case 16306ULL: goto x86_l_3fb2;
	case 16311ULL: goto x86_l_3fb7;
	case 16313ULL: goto x86_l_3fb9;
	case 16315ULL: goto x86_l_3fbb;
	case 16321ULL: goto x86_l_3fc1;
	case 16326ULL: goto x86_l_3fc6;
	case 16334ULL: goto x86_l_3fce;
	case 16340ULL: goto x86_l_3fd4;
	case 16346ULL: goto x86_l_3fda;
	case 16350ULL: goto x86_l_3fde;
	case 16358ULL: goto x86_l_3fe6;
	case 16360ULL: goto x86_l_3fe8;
	case 16365ULL: goto x86_l_3fed;
	case 16369ULL: goto x86_l_3ff1;
	case 16372ULL: goto x86_l_3ff4;
	case 16377ULL: goto x86_l_3ff9;
	case 16379ULL: goto x86_l_3ffb;
	case 16381ULL: goto x86_l_3ffd;
	case 16387ULL: goto x86_l_4003;
	case 16392ULL: goto x86_l_4008;
	case 16400ULL: goto x86_l_4010;
	case 16406ULL: goto x86_l_4016;
	case 16412ULL: goto x86_l_401c;
	case 16416ULL: goto x86_l_4020;
	case 16424ULL: goto x86_l_4028;
	case 16426ULL: goto x86_l_402a;
	case 16431ULL: goto x86_l_402f;
	case 16435ULL: goto x86_l_4033;
	case 16438ULL: goto x86_l_4036;
	case 16443ULL: goto x86_l_403b;
	case 16445ULL: goto x86_l_403d;
	case 16447ULL: goto x86_l_403f;
	case 16453ULL: goto x86_l_4045;
	case 16458ULL: goto x86_l_404a;
	case 16466ULL: goto x86_l_4052;
	case 16472ULL: goto x86_l_4058;
	case 16478ULL: goto x86_l_405e;
	case 16482ULL: goto x86_l_4062;
	case 16490ULL: goto x86_l_406a;
	case 16496ULL: goto x86_l_4070;
	case 16501ULL: goto x86_l_4075;
	case 16506ULL: goto x86_l_407a;
	case 16509ULL: goto x86_l_407d;
	case 16511ULL: goto x86_l_407f;
	case 16516ULL: goto x86_l_4084;
	case 16520ULL: goto x86_l_4088;
	case 16523ULL: goto x86_l_408b;
	case 16528ULL: goto x86_l_4090;
	case 16530ULL: goto x86_l_4092;
	case 16532ULL: goto x86_l_4094;
	case 16538ULL: goto x86_l_409a;
	case 16543ULL: goto x86_l_409f;
	case 16551ULL: goto x86_l_40a7;
	case 16557ULL: goto x86_l_40ad;
	case 16563ULL: goto x86_l_40b3;
	case 16567ULL: goto x86_l_40b7;
	case 16575ULL: goto x86_l_40bf;
	case 16577ULL: goto x86_l_40c1;
	case 16582ULL: goto x86_l_40c6;
	case 16586ULL: goto x86_l_40ca;
	case 16589ULL: goto x86_l_40cd;
	case 16594ULL: goto x86_l_40d2;
	case 16596ULL: goto x86_l_40d4;
	case 16598ULL: goto x86_l_40d6;
	case 16604ULL: goto x86_l_40dc;
	case 16609ULL: goto x86_l_40e1;
	case 16617ULL: goto x86_l_40e9;
	case 16623ULL: goto x86_l_40ef;
	case 16629ULL: goto x86_l_40f5;
	case 16633ULL: goto x86_l_40f9;
	case 16641ULL: goto x86_l_4101;
	case 16643ULL: goto x86_l_4103;
	case 16648ULL: goto x86_l_4108;
	case 16652ULL: goto x86_l_410c;
	case 16655ULL: goto x86_l_410f;
	case 16660ULL: goto x86_l_4114;
	case 16662ULL: goto x86_l_4116;
	case 16664ULL: goto x86_l_4118;
	case 16670ULL: goto x86_l_411e;
	case 16675ULL: goto x86_l_4123;
	case 16683ULL: goto x86_l_412b;
	case 16689ULL: goto x86_l_4131;
	case 16695ULL: goto x86_l_4137;
	case 16699ULL: goto x86_l_413b;
	case 16707ULL: goto x86_l_4143;
	case 16709ULL: goto x86_l_4145;
	case 16714ULL: goto x86_l_414a;
	case 16718ULL: goto x86_l_414e;
	case 16721ULL: goto x86_l_4151;
	case 16726ULL: goto x86_l_4156;
	case 16728ULL: goto x86_l_4158;
	case 16730ULL: goto x86_l_415a;
	case 16736ULL: goto x86_l_4160;
	case 16741ULL: goto x86_l_4165;
	case 16749ULL: goto x86_l_416d;
	case 16755ULL: goto x86_l_4173;
	case 16761ULL: goto x86_l_4179;
	case 16765ULL: goto x86_l_417d;
	case 16773ULL: goto x86_l_4185;
	case 16775ULL: goto x86_l_4187;
	case 16780ULL: goto x86_l_418c;
	case 16784ULL: goto x86_l_4190;
	case 16787ULL: goto x86_l_4193;
	case 16792ULL: goto x86_l_4198;
	case 16794ULL: goto x86_l_419a;
	case 16796ULL: goto x86_l_419c;
	case 16802ULL: goto x86_l_41a2;
	case 16807ULL: goto x86_l_41a7;
	case 16815ULL: goto x86_l_41af;
	case 16821ULL: goto x86_l_41b5;
	case 16827ULL: goto x86_l_41bb;
	case 16831ULL: goto x86_l_41bf;
	case 16839ULL: goto x86_l_41c7;
	case 16841ULL: goto x86_l_41c9;
	case 16846ULL: goto x86_l_41ce;
	case 16850ULL: goto x86_l_41d2;
	case 16853ULL: goto x86_l_41d5;
	case 16858ULL: goto x86_l_41da;
	case 16860ULL: goto x86_l_41dc;
	case 16862ULL: goto x86_l_41de;
	case 16868ULL: goto x86_l_41e4;
	case 16873ULL: goto x86_l_41e9;
	case 16881ULL: goto x86_l_41f1;
	case 16887ULL: goto x86_l_41f7;
	case 16893ULL: goto x86_l_41fd;
	case 16897ULL: goto x86_l_4201;
	case 16905ULL: goto x86_l_4209;
	case 16907ULL: goto x86_l_420b;
	case 16912ULL: goto x86_l_4210;
	case 16916ULL: goto x86_l_4214;
	case 16919ULL: goto x86_l_4217;
	case 16924ULL: goto x86_l_421c;
	case 16926ULL: goto x86_l_421e;
	case 16928ULL: goto x86_l_4220;
	case 16934ULL: goto x86_l_4226;
	case 16939ULL: goto x86_l_422b;
	case 16947ULL: goto x86_l_4233;
	case 16953ULL: goto x86_l_4239;
	case 16959ULL: goto x86_l_423f;
	case 16963ULL: goto x86_l_4243;
	case 16971ULL: goto x86_l_424b;
	case 16973ULL: goto x86_l_424d;
	case 16978ULL: goto x86_l_4252;
	case 16982ULL: goto x86_l_4256;
	case 16985ULL: goto x86_l_4259;
	case 16990ULL: goto x86_l_425e;
	case 16992ULL: goto x86_l_4260;
	case 16994ULL: goto x86_l_4262;
	case 17000ULL: goto x86_l_4268;
	case 17005ULL: goto x86_l_426d;
	case 17013ULL: goto x86_l_4275;
	case 17019ULL: goto x86_l_427b;
	case 17025ULL: goto x86_l_4281;
	case 17029ULL: goto x86_l_4285;
	case 17037ULL: goto x86_l_428d;
	case 17039ULL: goto x86_l_428f;
	case 17044ULL: goto x86_l_4294;
	case 17048ULL: goto x86_l_4298;
	case 17051ULL: goto x86_l_429b;
	case 17056ULL: goto x86_l_42a0;
	case 17058ULL: goto x86_l_42a2;
	case 17060ULL: goto x86_l_42a4;
	case 17066ULL: goto x86_l_42aa;
	case 17071ULL: goto x86_l_42af;
	case 17079ULL: goto x86_l_42b7;
	case 17085ULL: goto x86_l_42bd;
	case 17091ULL: goto x86_l_42c3;
	case 17095ULL: goto x86_l_42c7;
	case 17103ULL: goto x86_l_42cf;
	case 17109ULL: goto x86_l_42d5;
	case 17114ULL: goto x86_l_42da;
	case 17118ULL: goto x86_l_42de;
	case 17121ULL: goto x86_l_42e1;
	case 17126ULL: goto x86_l_42e6;
	case 17128ULL: goto x86_l_42e8;
	case 17130ULL: goto x86_l_42ea;
	case 17136ULL: goto x86_l_42f0;
	case 17141ULL: goto x86_l_42f5;
	case 17146ULL: goto x86_l_42fa;
	case 17151ULL: goto x86_l_42ff;
	case 17156ULL: goto x86_l_4304;
	case 17164ULL: goto x86_l_430c;
	case 17167ULL: goto x86_l_430f;
	case 17173ULL: goto x86_l_4315;
	case 17178ULL: goto x86_l_431a;
	case 17181ULL: goto x86_l_431d;
	case 17187ULL: goto x86_l_4323;
	case 17192ULL: goto x86_l_4328;
	case 17200ULL: goto x86_l_4330;
	case 17203ULL: goto x86_l_4333;
	case 17209ULL: goto x86_l_4339;
	case 17214ULL: goto x86_l_433e;
	case 17217ULL: goto x86_l_4341;
	case 17223ULL: goto x86_l_4347;
	case 17228ULL: goto x86_l_434c;
	case 17236ULL: goto x86_l_4354;
	case 17239ULL: goto x86_l_4357;
	case 17245ULL: goto x86_l_435d;
	case 17250ULL: goto x86_l_4362;
	case 17253ULL: goto x86_l_4365;
	case 17259ULL: goto x86_l_436b;
	case 17264ULL: goto x86_l_4370;
	case 17272ULL: goto x86_l_4378;
	case 17275ULL: goto x86_l_437b;
	case 17281ULL: goto x86_l_4381;
	case 17286ULL: goto x86_l_4386;
	case 17289ULL: goto x86_l_4389;
	case 17295ULL: goto x86_l_438f;
	case 17300ULL: goto x86_l_4394;
	case 17308ULL: goto x86_l_439c;
	case 17311ULL: goto x86_l_439f;
	case 17317ULL: goto x86_l_43a5;
	case 17322ULL: goto x86_l_43aa;
	case 17325ULL: goto x86_l_43ad;
	case 17327ULL: goto x86_l_43af;
	case 17332ULL: goto x86_l_43b4;
	case 17340ULL: goto x86_l_43bc;
	case 17343ULL: goto x86_l_43bf;
	case 17349ULL: goto x86_l_43c5;
	case 17354ULL: goto x86_l_43ca;
	case 17357ULL: goto x86_l_43cd;
	case 17363ULL: goto x86_l_43d3;
	case 17368ULL: goto x86_l_43d8;
	case 17373ULL: goto x86_l_43dd;
	case 17376ULL: goto x86_l_43e0;
	case 17378ULL: goto x86_l_43e2;
	case 17383ULL: goto x86_l_43e7;
	case 17386ULL: goto x86_l_43ea;
	case 17388ULL: goto x86_l_43ec;
	case 17390ULL: goto x86_l_43ee;
	case 17395ULL: goto x86_l_43f3;
	case 17398ULL: goto x86_l_43f6;
	case 17404ULL: goto x86_l_43fc;
	case 17409ULL: goto x86_l_4401;
	case 17412ULL: goto x86_l_4404;
	case 17418ULL: goto x86_l_440a;
	case 17423ULL: goto x86_l_440f;
	case 17428ULL: goto x86_l_4414;
	case 17433ULL: goto x86_l_4419;
	case 17438ULL: goto x86_l_441e;
	case 17443ULL: goto x86_l_4423;
	case 17448ULL: goto x86_l_4428;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3d17:
	/* 0x3d17: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d1a:
	/* 0x3d1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d1f:
	/* 0x3d1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d21:
	/* 0x3d21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d23:
	/* 0x3d23: js     535b <generic_sleepable_preload+0x535b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21339ULL;
	}
x86_l_3d29:
	/* 0x3d29: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d2e:
	/* 0x3d2e: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_3d37:
	/* 0x3d37: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3d3d:
	/* 0x3d3d: mov    eax,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_3d44:
	/* 0x3d44: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3d48:
	/* 0x3d48: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_3d51:
	/* 0x3d51: je     3d6e <generic_sleepable_preload+0x3d6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d6e;
	}
x86_l_3d53:
	/* 0x3d53: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d58:
	/* 0x3d58: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d5c:
	/* 0x3d5c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3d5f:
	/* 0x3d5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d64:
	/* 0x3d64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d66:
	/* 0x3d66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d68:
	/* 0x3d68: js     52b7 <generic_sleepable_preload+0x52b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21175ULL;
	}
x86_l_3d6e:
	/* 0x3d6e: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d73:
	/* 0x3d73: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3d7c:
	/* 0x3d7c: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3d82:
	/* 0x3d82: mov    eax,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_3d89:
	/* 0x3d89: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3d8d:
	/* 0x3d8d: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3d96:
	/* 0x3d96: je     4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20311ULL;
	}
x86_l_3d9c:
	/* 0x3d9c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3da1:
	/* 0x3da1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3da5:
	/* 0x3da5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3da8:
	/* 0x3da8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dad:
	/* 0x3dad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3daf:
	/* 0x3daf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3db1:
	/* 0x3db1: jns    4f57 <generic_sleepable_preload+0x4f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 20311ULL;
	}
x86_l_3db7:
	/* 0x3db7: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3dbc:
	/* 0x3dbc: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	return 20308ULL;
x86_l_3dc1:
	/* 0x3dc1: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3dc6:
	/* 0x3dc6: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	return 20308ULL;
x86_l_3dcb:
	/* 0x3dcb: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3dd0:
	/* 0x3dd0: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dd3:
	/* 0x3dd3: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dd7:
	/* 0x3dd7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3dd9:
	/* 0x3dd9: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_3ddc:
	/* 0x3ddc: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3de1:
	/* 0x3de1: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_3de9:
	/* 0x3de9: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_3def:
	/* 0x3def: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3df6:
	/* 0x3df6: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3df9:
	/* 0x3df9: mov    edx,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_3dff:
	/* 0x3dff: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e02:
	/* 0x3e02: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e06:
	/* 0x3e06: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_3e0d:
	/* 0x3e0d: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3e0f:
	/* 0x3e0f: je     407a <generic_sleepable_preload+0x407a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_407a;
	}
x86_l_3e15:
	/* 0x3e15: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3e18:
	/* 0x3e18: je     3e35 <generic_sleepable_preload+0x3e35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e35;
	}
x86_l_3e1a:
	/* 0x3e1a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e1f:
	/* 0x3e1f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e23:
	/* 0x3e23: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3e26:
	/* 0x3e26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e2b:
	/* 0x3e2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e2d:
	/* 0x3e2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e2f:
	/* 0x3e2f: js     42fa <generic_sleepable_preload+0x42fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_42fa;
	}
x86_l_3e35:
	/* 0x3e35: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e3a:
	/* 0x3e3a: cmp    WORD PTR [rcx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_3e42:
	/* 0x3e42: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_3e48:
	/* 0x3e48: mov    eax,DWORD PTR [rcx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_3e4e:
	/* 0x3e4e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3e52:
	/* 0x3e52: cmp    WORD PTR [rcx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_3e5a:
	/* 0x3e5a: je     3e77 <generic_sleepable_preload+0x3e77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e77;
	}
x86_l_3e5c:
	/* 0x3e5c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e61:
	/* 0x3e61: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e65:
	/* 0x3e65: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3e68:
	/* 0x3e68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e6d:
	/* 0x3e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e6f:
	/* 0x3e6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e71:
	/* 0x3e71: js     4419 <generic_sleepable_preload+0x4419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4419;
	}
x86_l_3e77:
	/* 0x3e77: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e7c:
	/* 0x3e7c: cmp    WORD PTR [rcx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_3e84:
	/* 0x3e84: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_3e8a:
	/* 0x3e8a: mov    eax,DWORD PTR [rcx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_3e90:
	/* 0x3e90: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3e94:
	/* 0x3e94: cmp    WORD PTR [rcx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_3e9c:
	/* 0x3e9c: je     3eb9 <generic_sleepable_preload+0x3eb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eb9;
	}
x86_l_3e9e:
	/* 0x3e9e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ea3:
	/* 0x3ea3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ea7:
	/* 0x3ea7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3eaa:
	/* 0x3eaa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3eaf:
	/* 0x3eaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eb1:
	/* 0x3eb1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3eb3:
	/* 0x3eb3: js     4ec2 <generic_sleepable_preload+0x4ec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20162ULL;
	}
x86_l_3eb9:
	/* 0x3eb9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ebe:
	/* 0x3ebe: cmp    WORD PTR [rcx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_3ec6:
	/* 0x3ec6: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_3ecc:
	/* 0x3ecc: mov    eax,DWORD PTR [rcx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_3ed2:
	/* 0x3ed2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ed6:
	/* 0x3ed6: cmp    WORD PTR [rcx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_3ede:
	/* 0x3ede: je     3efb <generic_sleepable_preload+0x3efb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3efb;
	}
x86_l_3ee0:
	/* 0x3ee0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ee5:
	/* 0x3ee5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee9:
	/* 0x3ee9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3eec:
	/* 0x3eec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef1:
	/* 0x3ef1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef3:
	/* 0x3ef3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ef5:
	/* 0x3ef5: js     4ee7 <generic_sleepable_preload+0x4ee7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20199ULL;
	}
x86_l_3efb:
	/* 0x3efb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f00:
	/* 0x3f00: cmp    WORD PTR [rcx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_3f08:
	/* 0x3f08: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_3f0e:
	/* 0x3f0e: mov    eax,DWORD PTR [rcx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_3f14:
	/* 0x3f14: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f18:
	/* 0x3f18: cmp    WORD PTR [rcx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_3f20:
	/* 0x3f20: je     3f3d <generic_sleepable_preload+0x3f3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f3d;
	}
x86_l_3f22:
	/* 0x3f22: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f27:
	/* 0x3f27: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f2b:
	/* 0x3f2b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f2e:
	/* 0x3f2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f33:
	/* 0x3f33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f35:
	/* 0x3f35: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f37:
	/* 0x3f37: js     4f0c <generic_sleepable_preload+0x4f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20236ULL;
	}
x86_l_3f3d:
	/* 0x3f3d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f42:
	/* 0x3f42: cmp    WORD PTR [rcx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_3f4a:
	/* 0x3f4a: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_3f50:
	/* 0x3f50: mov    eax,DWORD PTR [rcx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_3f56:
	/* 0x3f56: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f5a:
	/* 0x3f5a: cmp    WORD PTR [rcx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3f62:
	/* 0x3f62: je     3f7f <generic_sleepable_preload+0x3f7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f7f;
	}
x86_l_3f64:
	/* 0x3f64: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3f69:
	/* 0x3f69: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f6d:
	/* 0x3f6d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3f70:
	/* 0x3f70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f75:
	/* 0x3f75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f77:
	/* 0x3f77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f79:
	/* 0x3f79: js     4f31 <generic_sleepable_preload+0x4f31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20273ULL;
	}
x86_l_3f7f:
	/* 0x3f7f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f84:
	/* 0x3f84: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3f8c:
	/* 0x3f8c: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_3f92:
	/* 0x3f92: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3f98:
	/* 0x3f98: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3f9c:
	/* 0x3f9c: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3fa4:
	/* 0x3fa4: je     3fc1 <generic_sleepable_preload+0x3fc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fc1;
	}
x86_l_3fa6:
	/* 0x3fa6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3fab:
	/* 0x3fab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3faf:
	/* 0x3faf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fb2:
	/* 0x3fb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fb7:
	/* 0x3fb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fb9:
	/* 0x3fb9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fbb:
	/* 0x3fbb: js     4fd4 <generic_sleepable_preload+0x4fd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20436ULL;
	}
x86_l_3fc1:
	/* 0x3fc1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fc6:
	/* 0x3fc6: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3fce:
	/* 0x3fce: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_3fd4:
	/* 0x3fd4: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3fda:
	/* 0x3fda: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3fde:
	/* 0x3fde: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3fe6:
	/* 0x3fe6: je     4003 <generic_sleepable_preload+0x4003> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4003;
	}
x86_l_3fe8:
	/* 0x3fe8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3fed:
	/* 0x3fed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff1:
	/* 0x3ff1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3ff4:
	/* 0x3ff4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ff9:
	/* 0x3ff9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ffb:
	/* 0x3ffb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ffd:
	/* 0x3ffd: js     51c0 <generic_sleepable_preload+0x51c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20928ULL;
	}
x86_l_4003:
	/* 0x4003: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4008:
	/* 0x4008: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_4010:
	/* 0x4010: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_4016:
	/* 0x4016: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_401c:
	/* 0x401c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4020:
	/* 0x4020: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_4028:
	/* 0x4028: je     4045 <generic_sleepable_preload+0x4045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4045;
	}
x86_l_402a:
	/* 0x402a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_402f:
	/* 0x402f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4033:
	/* 0x4033: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4036:
	/* 0x4036: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_403b:
	/* 0x403b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_403d:
	/* 0x403d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_403f:
	/* 0x403f: js     52c9 <generic_sleepable_preload+0x52c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21193ULL;
	}
x86_l_4045:
	/* 0x4045: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_404a:
	/* 0x404a: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_4052:
	/* 0x4052: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_4058:
	/* 0x4058: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_405e:
	/* 0x405e: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4062:
	/* 0x4062: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_406a:
	/* 0x406a: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_4070:
	/* 0x4070: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4075:
	/* 0x4075: jmp    42da <generic_sleepable_preload+0x42da> */
	goto x86_l_42da;
x86_l_407a:
	/* 0x407a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_407d:
	/* 0x407d: je     409a <generic_sleepable_preload+0x409a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_409a;
	}
x86_l_407f:
	/* 0x407f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4084:
	/* 0x4084: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4088:
	/* 0x4088: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_408b:
	/* 0x408b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4090:
	/* 0x4090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4092:
	/* 0x4092: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4094:
	/* 0x4094: js     42fa <generic_sleepable_preload+0x42fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_42fa;
	}
x86_l_409a:
	/* 0x409a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_409f:
	/* 0x409f: cmp    WORD PTR [rcx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_40a7:
	/* 0x40a7: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_40ad:
	/* 0x40ad: mov    eax,DWORD PTR [rcx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_40b3:
	/* 0x40b3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_40b7:
	/* 0x40b7: cmp    WORD PTR [rcx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_40bf:
	/* 0x40bf: je     40dc <generic_sleepable_preload+0x40dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40dc;
	}
x86_l_40c1:
	/* 0x40c1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40c6:
	/* 0x40c6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40ca:
	/* 0x40ca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40cd:
	/* 0x40cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40d2:
	/* 0x40d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40d4:
	/* 0x40d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40d6:
	/* 0x40d6: js     4419 <generic_sleepable_preload+0x4419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4419;
	}
x86_l_40dc:
	/* 0x40dc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40e1:
	/* 0x40e1: cmp    WORD PTR [rcx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_40e9:
	/* 0x40e9: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_40ef:
	/* 0x40ef: mov    eax,DWORD PTR [rcx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_40f5:
	/* 0x40f5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_40f9:
	/* 0x40f9: cmp    WORD PTR [rcx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4101:
	/* 0x4101: je     411e <generic_sleepable_preload+0x411e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_411e;
	}
x86_l_4103:
	/* 0x4103: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4108:
	/* 0x4108: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_410c:
	/* 0x410c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_410f:
	/* 0x410f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4114:
	/* 0x4114: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4116:
	/* 0x4116: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4118:
	/* 0x4118: js     4ec2 <generic_sleepable_preload+0x4ec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20162ULL;
	}
x86_l_411e:
	/* 0x411e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4123:
	/* 0x4123: cmp    WORD PTR [rcx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_412b:
	/* 0x412b: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_4131:
	/* 0x4131: mov    eax,DWORD PTR [rcx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4137:
	/* 0x4137: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_413b:
	/* 0x413b: cmp    WORD PTR [rcx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4143:
	/* 0x4143: je     4160 <generic_sleepable_preload+0x4160> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4160;
	}
x86_l_4145:
	/* 0x4145: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_414a:
	/* 0x414a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_414e:
	/* 0x414e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4151:
	/* 0x4151: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4156:
	/* 0x4156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4158:
	/* 0x4158: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_415a:
	/* 0x415a: js     4ee7 <generic_sleepable_preload+0x4ee7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20199ULL;
	}
x86_l_4160:
	/* 0x4160: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4165:
	/* 0x4165: cmp    WORD PTR [rcx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_416d:
	/* 0x416d: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_4173:
	/* 0x4173: mov    eax,DWORD PTR [rcx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4179:
	/* 0x4179: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_417d:
	/* 0x417d: cmp    WORD PTR [rcx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4185:
	/* 0x4185: je     41a2 <generic_sleepable_preload+0x41a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41a2;
	}
x86_l_4187:
	/* 0x4187: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_418c:
	/* 0x418c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4190:
	/* 0x4190: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4193:
	/* 0x4193: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4198:
	/* 0x4198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_419a:
	/* 0x419a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_419c:
	/* 0x419c: js     4f0c <generic_sleepable_preload+0x4f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20236ULL;
	}
x86_l_41a2:
	/* 0x41a2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41a7:
	/* 0x41a7: cmp    WORD PTR [rcx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_41af:
	/* 0x41af: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_41b5:
	/* 0x41b5: mov    eax,DWORD PTR [rcx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_41bb:
	/* 0x41bb: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_41bf:
	/* 0x41bf: cmp    WORD PTR [rcx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_41c7:
	/* 0x41c7: je     41e4 <generic_sleepable_preload+0x41e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41e4;
	}
x86_l_41c9:
	/* 0x41c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41ce:
	/* 0x41ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41d2:
	/* 0x41d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_41d5:
	/* 0x41d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41da:
	/* 0x41da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41dc:
	/* 0x41dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41de:
	/* 0x41de: js     4f31 <generic_sleepable_preload+0x4f31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20273ULL;
	}
x86_l_41e4:
	/* 0x41e4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41e9:
	/* 0x41e9: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_41f1:
	/* 0x41f1: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_41f7:
	/* 0x41f7: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_41fd:
	/* 0x41fd: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4201:
	/* 0x4201: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4209:
	/* 0x4209: je     4226 <generic_sleepable_preload+0x4226> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4226;
	}
x86_l_420b:
	/* 0x420b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4210:
	/* 0x4210: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4214:
	/* 0x4214: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4217:
	/* 0x4217: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_421c:
	/* 0x421c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_421e:
	/* 0x421e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4220:
	/* 0x4220: js     4fd4 <generic_sleepable_preload+0x4fd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20436ULL;
	}
x86_l_4226:
	/* 0x4226: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_422b:
	/* 0x422b: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_4233:
	/* 0x4233: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_4239:
	/* 0x4239: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_423f:
	/* 0x423f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4243:
	/* 0x4243: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_424b:
	/* 0x424b: je     4268 <generic_sleepable_preload+0x4268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4268;
	}
x86_l_424d:
	/* 0x424d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4252:
	/* 0x4252: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4256:
	/* 0x4256: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4259:
	/* 0x4259: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_425e:
	/* 0x425e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4260:
	/* 0x4260: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4262:
	/* 0x4262: js     51c0 <generic_sleepable_preload+0x51c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20928ULL;
	}
x86_l_4268:
	/* 0x4268: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_426d:
	/* 0x426d: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_4275:
	/* 0x4275: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_427b:
	/* 0x427b: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_4281:
	/* 0x4281: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4285:
	/* 0x4285: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_428d:
	/* 0x428d: je     42aa <generic_sleepable_preload+0x42aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42aa;
	}
x86_l_428f:
	/* 0x428f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4294:
	/* 0x4294: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4298:
	/* 0x4298: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_429b:
	/* 0x429b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42a0:
	/* 0x42a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a2:
	/* 0x42a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a4:
	/* 0x42a4: js     52c9 <generic_sleepable_preload+0x52c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21193ULL;
	}
x86_l_42aa:
	/* 0x42aa: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42af:
	/* 0x42af: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_42b7:
	/* 0x42b7: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_42bd:
	/* 0x42bd: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_42c3:
	/* 0x42c3: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_42c7:
	/* 0x42c7: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_42cf:
	/* 0x42cf: je     4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20444ULL;
	}
x86_l_42d5:
	/* 0x42d5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42da:
	/* 0x42da: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42de:
	/* 0x42de: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42e1:
	/* 0x42e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42e6:
	/* 0x42e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e8:
	/* 0x42e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42ea:
	/* 0x42ea: jns    4fdc <generic_sleepable_preload+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 20444ULL;
	}
x86_l_42f0:
	/* 0x42f0: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_42f5:
	/* 0x42f5: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	return 20441ULL;
x86_l_42fa:
	/* 0x42fa: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_42ff:
	/* 0x42ff: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	return 20441ULL;
x86_l_4304:
	/* 0x4304: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_430c:
	/* 0x430c: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_430f:
	/* 0x430f: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4428;
	}
x86_l_4315:
	/* 0x4315: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_431a:
	/* 0x431a: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_431d:
	/* 0x431d: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4428;
	}
x86_l_4323:
	/* 0x4323: jmp    443b <generic_sleepable_preload+0x443b> */
	return 17467ULL;
x86_l_4328:
	/* 0x4328: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4330:
	/* 0x4330: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_4333:
	/* 0x4333: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_4339:
	/* 0x4339: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_433e:
	/* 0x433e: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4341:
	/* 0x4341: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_4347:
	/* 0x4347: jmp    497b <generic_sleepable_preload+0x497b> */
	return 18811ULL;
x86_l_434c:
	/* 0x434c: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4354:
	/* 0x4354: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4357:
	/* 0x4357: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4428;
	}
x86_l_435d:
	/* 0x435d: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4362:
	/* 0x4362: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4365:
	/* 0x4365: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4428;
	}
x86_l_436b:
	/* 0x436b: jmp    443b <generic_sleepable_preload+0x443b> */
	return 17467ULL;
x86_l_4370:
	/* 0x4370: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4378:
	/* 0x4378: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_437b:
	/* 0x437b: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_4381:
	/* 0x4381: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4386:
	/* 0x4386: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4389:
	/* 0x4389: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_438f:
	/* 0x438f: jmp    497b <generic_sleepable_preload+0x497b> */
	return 18811ULL;
x86_l_4394:
	/* 0x4394: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_439c:
	/* 0x439c: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_439f:
	/* 0x439f: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4428;
	}
x86_l_43a5:
	/* 0x43a5: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43aa:
	/* 0x43aa: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_43ad:
	/* 0x43ad: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4428;
	}
x86_l_43af:
	/* 0x43af: jmp    443b <generic_sleepable_preload+0x443b> */
	return 17467ULL;
x86_l_43b4:
	/* 0x43b4: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_43bc:
	/* 0x43bc: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_43bf:
	/* 0x43bf: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_43c5:
	/* 0x43c5: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43ca:
	/* 0x43ca: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_43cd:
	/* 0x43cd: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_43d3:
	/* 0x43d3: jmp    497b <generic_sleepable_preload+0x497b> */
	return 18811ULL;
x86_l_43d8:
	/* 0x43d8: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43dd:
	/* 0x43dd: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_43e0:
	/* 0x43e0: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4428;
	}
x86_l_43e2:
	/* 0x43e2: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43e7:
	/* 0x43e7: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_43ea:
	/* 0x43ea: je     4428 <generic_sleepable_preload+0x4428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4428;
	}
x86_l_43ec:
	/* 0x43ec: jmp    443b <generic_sleepable_preload+0x443b> */
	return 17467ULL;
x86_l_43ee:
	/* 0x43ee: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43f3:
	/* 0x43f3: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_43f6:
	/* 0x43f6: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_43fc:
	/* 0x43fc: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4401:
	/* 0x4401: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4404:
	/* 0x4404: je     4968 <generic_sleepable_preload+0x4968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18792ULL;
	}
x86_l_440a:
	/* 0x440a: jmp    497b <generic_sleepable_preload+0x497b> */
	return 18811ULL;
x86_l_440f:
	/* 0x440f: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4414:
	/* 0x4414: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	return 20308ULL;
x86_l_4419:
	/* 0x4419: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_441e:
	/* 0x441e: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	return 20441ULL;
x86_l_4423:
	/* 0x4423: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4428:
	/* 0x4428: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
	return 17451ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17451ULL: goto x86_l_442b;
	case 17453ULL: goto x86_l_442d;
	case 17455ULL: goto x86_l_442f;
	case 17460ULL: goto x86_l_4434;
	case 17462ULL: goto x86_l_4436;
	case 17467ULL: goto x86_l_443b;
	case 17471ULL: goto x86_l_443f;
	case 17475ULL: goto x86_l_4443;
	case 17477ULL: goto x86_l_4445;
	case 17480ULL: goto x86_l_4448;
	case 17489ULL: goto x86_l_4451;
	case 17495ULL: goto x86_l_4457;
	case 17502ULL: goto x86_l_445e;
	case 17505ULL: goto x86_l_4461;
	case 17512ULL: goto x86_l_4468;
	case 17515ULL: goto x86_l_446b;
	case 17519ULL: goto x86_l_446f;
	case 17527ULL: goto x86_l_4477;
	case 17529ULL: goto x86_l_4479;
	case 17535ULL: goto x86_l_447f;
	case 17538ULL: goto x86_l_4482;
	case 17540ULL: goto x86_l_4484;
	case 17545ULL: goto x86_l_4489;
	case 17549ULL: goto x86_l_448d;
	case 17552ULL: goto x86_l_4490;
	case 17557ULL: goto x86_l_4495;
	case 17559ULL: goto x86_l_4497;
	case 17561ULL: goto x86_l_4499;
	case 17567ULL: goto x86_l_449f;
	case 17576ULL: goto x86_l_44a8;
	case 17582ULL: goto x86_l_44ae;
	case 17589ULL: goto x86_l_44b5;
	case 17593ULL: goto x86_l_44b9;
	case 17602ULL: goto x86_l_44c2;
	case 17604ULL: goto x86_l_44c4;
	case 17609ULL: goto x86_l_44c9;
	case 17613ULL: goto x86_l_44cd;
	case 17616ULL: goto x86_l_44d0;
	case 17621ULL: goto x86_l_44d5;
	case 17623ULL: goto x86_l_44d7;
	case 17625ULL: goto x86_l_44d9;
	case 17631ULL: goto x86_l_44df;
	case 17640ULL: goto x86_l_44e8;
	case 17646ULL: goto x86_l_44ee;
	case 17653ULL: goto x86_l_44f5;
	case 17657ULL: goto x86_l_44f9;
	case 17666ULL: goto x86_l_4502;
	case 17668ULL: goto x86_l_4504;
	case 17673ULL: goto x86_l_4509;
	case 17677ULL: goto x86_l_450d;
	case 17680ULL: goto x86_l_4510;
	case 17685ULL: goto x86_l_4515;
	case 17687ULL: goto x86_l_4517;
	case 17689ULL: goto x86_l_4519;
	case 17695ULL: goto x86_l_451f;
	case 17704ULL: goto x86_l_4528;
	case 17710ULL: goto x86_l_452e;
	case 17717ULL: goto x86_l_4535;
	case 17721ULL: goto x86_l_4539;
	case 17730ULL: goto x86_l_4542;
	case 17732ULL: goto x86_l_4544;
	case 17737ULL: goto x86_l_4549;
	case 17741ULL: goto x86_l_454d;
	case 17744ULL: goto x86_l_4550;
	case 17749ULL: goto x86_l_4555;
	case 17751ULL: goto x86_l_4557;
	case 17753ULL: goto x86_l_4559;
	case 17759ULL: goto x86_l_455f;
	case 17768ULL: goto x86_l_4568;
	case 17774ULL: goto x86_l_456e;
	case 17781ULL: goto x86_l_4575;
	case 17785ULL: goto x86_l_4579;
	case 17794ULL: goto x86_l_4582;
	case 17796ULL: goto x86_l_4584;
	case 17801ULL: goto x86_l_4589;
	case 17805ULL: goto x86_l_458d;
	case 17808ULL: goto x86_l_4590;
	case 17813ULL: goto x86_l_4595;
	case 17815ULL: goto x86_l_4597;
	case 17817ULL: goto x86_l_4599;
	case 17823ULL: goto x86_l_459f;
	case 17832ULL: goto x86_l_45a8;
	case 17838ULL: goto x86_l_45ae;
	case 17845ULL: goto x86_l_45b5;
	case 17849ULL: goto x86_l_45b9;
	case 17858ULL: goto x86_l_45c2;
	case 17860ULL: goto x86_l_45c4;
	case 17865ULL: goto x86_l_45c9;
	case 17869ULL: goto x86_l_45cd;
	case 17872ULL: goto x86_l_45d0;
	case 17877ULL: goto x86_l_45d5;
	case 17879ULL: goto x86_l_45d7;
	case 17881ULL: goto x86_l_45d9;
	case 17887ULL: goto x86_l_45df;
	case 17896ULL: goto x86_l_45e8;
	case 17902ULL: goto x86_l_45ee;
	case 17909ULL: goto x86_l_45f5;
	case 17913ULL: goto x86_l_45f9;
	case 17922ULL: goto x86_l_4602;
	case 17924ULL: goto x86_l_4604;
	case 17929ULL: goto x86_l_4609;
	case 17933ULL: goto x86_l_460d;
	case 17936ULL: goto x86_l_4610;
	case 17941ULL: goto x86_l_4615;
	case 17943ULL: goto x86_l_4617;
	case 17945ULL: goto x86_l_4619;
	case 17951ULL: goto x86_l_461f;
	case 17960ULL: goto x86_l_4628;
	case 17966ULL: goto x86_l_462e;
	case 17973ULL: goto x86_l_4635;
	case 17977ULL: goto x86_l_4639;
	case 17986ULL: goto x86_l_4642;
	case 17988ULL: goto x86_l_4644;
	case 17993ULL: goto x86_l_4649;
	case 17997ULL: goto x86_l_464d;
	case 18000ULL: goto x86_l_4650;
	case 18005ULL: goto x86_l_4655;
	case 18007ULL: goto x86_l_4657;
	case 18009ULL: goto x86_l_4659;
	case 18015ULL: goto x86_l_465f;
	case 18024ULL: goto x86_l_4668;
	case 18030ULL: goto x86_l_466e;
	case 18037ULL: goto x86_l_4675;
	case 18041ULL: goto x86_l_4679;
	case 18050ULL: goto x86_l_4682;
	case 18052ULL: goto x86_l_4684;
	case 18057ULL: goto x86_l_4689;
	case 18061ULL: goto x86_l_468d;
	case 18064ULL: goto x86_l_4690;
	case 18069ULL: goto x86_l_4695;
	case 18071ULL: goto x86_l_4697;
	case 18073ULL: goto x86_l_4699;
	case 18079ULL: goto x86_l_469f;
	case 18084ULL: goto x86_l_46a4;
	case 18093ULL: goto x86_l_46ad;
	case 18099ULL: goto x86_l_46b3;
	case 18106ULL: goto x86_l_46ba;
	case 18110ULL: goto x86_l_46be;
	case 18119ULL: goto x86_l_46c7;
	case 18125ULL: goto x86_l_46cd;
	case 18130ULL: goto x86_l_46d2;
	case 18135ULL: goto x86_l_46d7;
	case 18138ULL: goto x86_l_46da;
	case 18140ULL: goto x86_l_46dc;
	case 18145ULL: goto x86_l_46e1;
	case 18149ULL: goto x86_l_46e5;
	case 18152ULL: goto x86_l_46e8;
	case 18157ULL: goto x86_l_46ed;
	case 18159ULL: goto x86_l_46ef;
	case 18161ULL: goto x86_l_46f1;
	case 18167ULL: goto x86_l_46f7;
	case 18176ULL: goto x86_l_4700;
	case 18182ULL: goto x86_l_4706;
	case 18189ULL: goto x86_l_470d;
	case 18193ULL: goto x86_l_4711;
	case 18202ULL: goto x86_l_471a;
	case 18204ULL: goto x86_l_471c;
	case 18209ULL: goto x86_l_4721;
	case 18213ULL: goto x86_l_4725;
	case 18216ULL: goto x86_l_4728;
	case 18221ULL: goto x86_l_472d;
	case 18223ULL: goto x86_l_472f;
	case 18225ULL: goto x86_l_4731;
	case 18231ULL: goto x86_l_4737;
	case 18240ULL: goto x86_l_4740;
	case 18246ULL: goto x86_l_4746;
	case 18253ULL: goto x86_l_474d;
	case 18257ULL: goto x86_l_4751;
	case 18266ULL: goto x86_l_475a;
	case 18268ULL: goto x86_l_475c;
	case 18273ULL: goto x86_l_4761;
	case 18277ULL: goto x86_l_4765;
	case 18280ULL: goto x86_l_4768;
	case 18285ULL: goto x86_l_476d;
	case 18287ULL: goto x86_l_476f;
	case 18289ULL: goto x86_l_4771;
	case 18295ULL: goto x86_l_4777;
	case 18304ULL: goto x86_l_4780;
	case 18310ULL: goto x86_l_4786;
	case 18317ULL: goto x86_l_478d;
	case 18321ULL: goto x86_l_4791;
	case 18330ULL: goto x86_l_479a;
	case 18332ULL: goto x86_l_479c;
	case 18337ULL: goto x86_l_47a1;
	case 18341ULL: goto x86_l_47a5;
	case 18344ULL: goto x86_l_47a8;
	case 18349ULL: goto x86_l_47ad;
	case 18351ULL: goto x86_l_47af;
	case 18353ULL: goto x86_l_47b1;
	case 18359ULL: goto x86_l_47b7;
	case 18368ULL: goto x86_l_47c0;
	case 18374ULL: goto x86_l_47c6;
	case 18381ULL: goto x86_l_47cd;
	case 18385ULL: goto x86_l_47d1;
	case 18394ULL: goto x86_l_47da;
	case 18396ULL: goto x86_l_47dc;
	case 18401ULL: goto x86_l_47e1;
	case 18405ULL: goto x86_l_47e5;
	case 18408ULL: goto x86_l_47e8;
	case 18413ULL: goto x86_l_47ed;
	case 18415ULL: goto x86_l_47ef;
	case 18417ULL: goto x86_l_47f1;
	case 18423ULL: goto x86_l_47f7;
	case 18432ULL: goto x86_l_4800;
	case 18438ULL: goto x86_l_4806;
	case 18445ULL: goto x86_l_480d;
	case 18449ULL: goto x86_l_4811;
	case 18458ULL: goto x86_l_481a;
	case 18460ULL: goto x86_l_481c;
	case 18465ULL: goto x86_l_4821;
	case 18469ULL: goto x86_l_4825;
	case 18472ULL: goto x86_l_4828;
	case 18477ULL: goto x86_l_482d;
	case 18479ULL: goto x86_l_482f;
	case 18481ULL: goto x86_l_4831;
	case 18487ULL: goto x86_l_4837;
	case 18496ULL: goto x86_l_4840;
	case 18502ULL: goto x86_l_4846;
	case 18509ULL: goto x86_l_484d;
	case 18513ULL: goto x86_l_4851;
	case 18522ULL: goto x86_l_485a;
	case 18524ULL: goto x86_l_485c;
	case 18529ULL: goto x86_l_4861;
	case 18533ULL: goto x86_l_4865;
	case 18536ULL: goto x86_l_4868;
	case 18541ULL: goto x86_l_486d;
	case 18543ULL: goto x86_l_486f;
	case 18545ULL: goto x86_l_4871;
	case 18551ULL: goto x86_l_4877;
	case 18560ULL: goto x86_l_4880;
	case 18566ULL: goto x86_l_4886;
	case 18573ULL: goto x86_l_488d;
	case 18577ULL: goto x86_l_4891;
	case 18586ULL: goto x86_l_489a;
	case 18588ULL: goto x86_l_489c;
	case 18593ULL: goto x86_l_48a1;
	case 18597ULL: goto x86_l_48a5;
	case 18600ULL: goto x86_l_48a8;
	case 18605ULL: goto x86_l_48ad;
	case 18607ULL: goto x86_l_48af;
	case 18609ULL: goto x86_l_48b1;
	case 18615ULL: goto x86_l_48b7;
	case 18620ULL: goto x86_l_48bc;
	case 18629ULL: goto x86_l_48c5;
	case 18635ULL: goto x86_l_48cb;
	case 18642ULL: goto x86_l_48d2;
	case 18646ULL: goto x86_l_48d6;
	case 18655ULL: goto x86_l_48df;
	case 18657ULL: goto x86_l_48e1;
	case 18662ULL: goto x86_l_48e6;
	case 18666ULL: goto x86_l_48ea;
	case 18669ULL: goto x86_l_48ed;
	case 18674ULL: goto x86_l_48f2;
	case 18676ULL: goto x86_l_48f4;
	case 18678ULL: goto x86_l_48f6;
	case 18684ULL: goto x86_l_48fc;
	case 18689ULL: goto x86_l_4901;
	case 18698ULL: goto x86_l_490a;
	case 18704ULL: goto x86_l_4910;
	case 18711ULL: goto x86_l_4917;
	case 18715ULL: goto x86_l_491b;
	case 18724ULL: goto x86_l_4924;
	case 18730ULL: goto x86_l_492a;
	case 18735ULL: goto x86_l_492f;
	case 18739ULL: goto x86_l_4933;
	case 18742ULL: goto x86_l_4936;
	case 18747ULL: goto x86_l_493b;
	case 18749ULL: goto x86_l_493d;
	case 18751ULL: goto x86_l_493f;
	case 18757ULL: goto x86_l_4945;
	case 18762ULL: goto x86_l_494a;
	case 18767ULL: goto x86_l_494f;
	case 18772ULL: goto x86_l_4954;
	case 18777ULL: goto x86_l_4959;
	case 18782ULL: goto x86_l_495e;
	case 18787ULL: goto x86_l_4963;
	case 18792ULL: goto x86_l_4968;
	case 18795ULL: goto x86_l_496b;
	case 18797ULL: goto x86_l_496d;
	case 18799ULL: goto x86_l_496f;
	case 18804ULL: goto x86_l_4974;
	case 18806ULL: goto x86_l_4976;
	case 18811ULL: goto x86_l_497b;
	case 18815ULL: goto x86_l_497f;
	case 18819ULL: goto x86_l_4983;
	case 18821ULL: goto x86_l_4985;
	case 18824ULL: goto x86_l_4988;
	case 18827ULL: goto x86_l_498b;
	case 18835ULL: goto x86_l_4993;
	case 18841ULL: goto x86_l_4999;
	case 18848ULL: goto x86_l_49a0;
	case 18851ULL: goto x86_l_49a3;
	case 18857ULL: goto x86_l_49a9;
	case 18860ULL: goto x86_l_49ac;
	case 18864ULL: goto x86_l_49b0;
	case 18871ULL: goto x86_l_49b7;
	case 18873ULL: goto x86_l_49b9;
	case 18879ULL: goto x86_l_49bf;
	case 18882ULL: goto x86_l_49c2;
	case 18884ULL: goto x86_l_49c4;
	case 18889ULL: goto x86_l_49c9;
	case 18893ULL: goto x86_l_49cd;
	case 18896ULL: goto x86_l_49d0;
	case 18901ULL: goto x86_l_49d5;
	case 18903ULL: goto x86_l_49d7;
	case 18905ULL: goto x86_l_49d9;
	case 18911ULL: goto x86_l_49df;
	case 18916ULL: goto x86_l_49e4;
	case 18924ULL: goto x86_l_49ec;
	case 18930ULL: goto x86_l_49f2;
	case 18936ULL: goto x86_l_49f8;
	case 18940ULL: goto x86_l_49fc;
	case 18948ULL: goto x86_l_4a04;
	case 18950ULL: goto x86_l_4a06;
	case 18955ULL: goto x86_l_4a0b;
	case 18959ULL: goto x86_l_4a0f;
	case 18962ULL: goto x86_l_4a12;
	case 18967ULL: goto x86_l_4a17;
	case 18969ULL: goto x86_l_4a19;
	case 18971ULL: goto x86_l_4a1b;
	case 18977ULL: goto x86_l_4a21;
	case 18982ULL: goto x86_l_4a26;
	case 18990ULL: goto x86_l_4a2e;
	case 18996ULL: goto x86_l_4a34;
	case 19002ULL: goto x86_l_4a3a;
	case 19006ULL: goto x86_l_4a3e;
	case 19014ULL: goto x86_l_4a46;
	case 19016ULL: goto x86_l_4a48;
	case 19021ULL: goto x86_l_4a4d;
	case 19025ULL: goto x86_l_4a51;
	case 19028ULL: goto x86_l_4a54;
	case 19033ULL: goto x86_l_4a59;
	case 19035ULL: goto x86_l_4a5b;
	case 19037ULL: goto x86_l_4a5d;
	case 19043ULL: goto x86_l_4a63;
	case 19048ULL: goto x86_l_4a68;
	case 19056ULL: goto x86_l_4a70;
	case 19062ULL: goto x86_l_4a76;
	case 19068ULL: goto x86_l_4a7c;
	case 19072ULL: goto x86_l_4a80;
	case 19080ULL: goto x86_l_4a88;
	case 19082ULL: goto x86_l_4a8a;
	case 19087ULL: goto x86_l_4a8f;
	case 19091ULL: goto x86_l_4a93;
	case 19094ULL: goto x86_l_4a96;
	case 19099ULL: goto x86_l_4a9b;
	case 19101ULL: goto x86_l_4a9d;
	case 19103ULL: goto x86_l_4a9f;
	case 19109ULL: goto x86_l_4aa5;
	case 19114ULL: goto x86_l_4aaa;
	case 19122ULL: goto x86_l_4ab2;
	case 19128ULL: goto x86_l_4ab8;
	case 19134ULL: goto x86_l_4abe;
	case 19138ULL: goto x86_l_4ac2;
	case 19146ULL: goto x86_l_4aca;
	case 19148ULL: goto x86_l_4acc;
	case 19153ULL: goto x86_l_4ad1;
	case 19157ULL: goto x86_l_4ad5;
	case 19160ULL: goto x86_l_4ad8;
	case 19165ULL: goto x86_l_4add;
	case 19167ULL: goto x86_l_4adf;
	case 19169ULL: goto x86_l_4ae1;
	case 19175ULL: goto x86_l_4ae7;
	case 19180ULL: goto x86_l_4aec;
	case 19188ULL: goto x86_l_4af4;
	case 19194ULL: goto x86_l_4afa;
	case 19200ULL: goto x86_l_4b00;
	case 19204ULL: goto x86_l_4b04;
	case 19212ULL: goto x86_l_4b0c;
	case 19214ULL: goto x86_l_4b0e;
	case 19219ULL: goto x86_l_4b13;
	case 19223ULL: goto x86_l_4b17;
	case 19226ULL: goto x86_l_4b1a;
	case 19231ULL: goto x86_l_4b1f;
	case 19233ULL: goto x86_l_4b21;
	case 19235ULL: goto x86_l_4b23;
	case 19241ULL: goto x86_l_4b29;
	case 19246ULL: goto x86_l_4b2e;
	case 19254ULL: goto x86_l_4b36;
	case 19260ULL: goto x86_l_4b3c;
	case 19266ULL: goto x86_l_4b42;
	case 19270ULL: goto x86_l_4b46;
	case 19278ULL: goto x86_l_4b4e;
	case 19280ULL: goto x86_l_4b50;
	default: return 0xffffffffffffffffULL;
	}
x86_l_442b:
	/* 0x442b: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_442d:
	/* 0x442d: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_442f:
	/* 0x442f: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_4434:
	/* 0x4434: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4436:
	/* 0x4436: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_443b:
	/* 0x443b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_443f:
	/* 0x443f: mov    ebx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4443:
	/* 0x4443: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4445:
	/* 0x4445: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_4448:
	/* 0x4448: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_4451:
	/* 0x4451: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_4457:
	/* 0x4457: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_445e:
	/* 0x445e: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4461:
	/* 0x4461: mov    edx,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4468:
	/* 0x4468: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_446b:
	/* 0x446b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_446f:
	/* 0x446f: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4477:
	/* 0x4477: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_4479:
	/* 0x4479: je     46d7 <generic_sleepable_preload+0x46d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46d7;
	}
x86_l_447f:
	/* 0x447f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4482:
	/* 0x4482: je     449f <generic_sleepable_preload+0x449f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_449f;
	}
x86_l_4484:
	/* 0x4484: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4489:
	/* 0x4489: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448d:
	/* 0x448d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4490:
	/* 0x4490: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4495:
	/* 0x4495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4497:
	/* 0x4497: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4499:
	/* 0x4499: js     494f <generic_sleepable_preload+0x494f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_494f;
	}
x86_l_449f:
	/* 0x449f: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_44a8:
	/* 0x44a8: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_44ae:
	/* 0x44ae: mov    eax,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_44b5:
	/* 0x44b5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_44b9:
	/* 0x44b9: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_44c2:
	/* 0x44c2: je     44df <generic_sleepable_preload+0x44df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44df;
	}
x86_l_44c4:
	/* 0x44c4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44c9:
	/* 0x44c9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44cd:
	/* 0x44cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_44d0:
	/* 0x44d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44d5:
	/* 0x44d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d7:
	/* 0x44d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44d9:
	/* 0x44d9: js     4959 <generic_sleepable_preload+0x4959> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4959;
	}
x86_l_44df:
	/* 0x44df: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_44e8:
	/* 0x44e8: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_44ee:
	/* 0x44ee: mov    eax,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_44f5:
	/* 0x44f5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_44f9:
	/* 0x44f9: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4502:
	/* 0x4502: je     451f <generic_sleepable_preload+0x451f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_451f;
	}
x86_l_4504:
	/* 0x4504: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4509:
	/* 0x4509: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_450d:
	/* 0x450d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4510:
	/* 0x4510: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4515:
	/* 0x4515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4517:
	/* 0x4517: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4519:
	/* 0x4519: js     4ecc <generic_sleepable_preload+0x4ecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20172ULL;
	}
x86_l_451f:
	/* 0x451f: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4528:
	/* 0x4528: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_452e:
	/* 0x452e: mov    eax,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4535:
	/* 0x4535: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4539:
	/* 0x4539: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4542:
	/* 0x4542: je     455f <generic_sleepable_preload+0x455f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_455f;
	}
x86_l_4544:
	/* 0x4544: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4549:
	/* 0x4549: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_454d:
	/* 0x454d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4550:
	/* 0x4550: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4555:
	/* 0x4555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4557:
	/* 0x4557: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4559:
	/* 0x4559: js     4ef1 <generic_sleepable_preload+0x4ef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20209ULL;
	}
x86_l_455f:
	/* 0x455f: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4568:
	/* 0x4568: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_456e:
	/* 0x456e: mov    eax,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4575:
	/* 0x4575: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4579:
	/* 0x4579: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4582:
	/* 0x4582: je     459f <generic_sleepable_preload+0x459f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_459f;
	}
x86_l_4584:
	/* 0x4584: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4589:
	/* 0x4589: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_458d:
	/* 0x458d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4590:
	/* 0x4590: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4595:
	/* 0x4595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4597:
	/* 0x4597: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4599:
	/* 0x4599: js     4f16 <generic_sleepable_preload+0x4f16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20246ULL;
	}
x86_l_459f:
	/* 0x459f: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_45a8:
	/* 0x45a8: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_45ae:
	/* 0x45ae: mov    eax,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_45b5:
	/* 0x45b5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45b9:
	/* 0x45b9: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_45c2:
	/* 0x45c2: je     45df <generic_sleepable_preload+0x45df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45df;
	}
x86_l_45c4:
	/* 0x45c4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45c9:
	/* 0x45c9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45cd:
	/* 0x45cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_45d0:
	/* 0x45d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45d5:
	/* 0x45d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d7:
	/* 0x45d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45d9:
	/* 0x45d9: js     4f3b <generic_sleepable_preload+0x4f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20283ULL;
	}
x86_l_45df:
	/* 0x45df: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_45e8:
	/* 0x45e8: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_45ee:
	/* 0x45ee: mov    eax,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_45f5:
	/* 0x45f5: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_45f9:
	/* 0x45f9: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4602:
	/* 0x4602: je     461f <generic_sleepable_preload+0x461f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_461f;
	}
x86_l_4604:
	/* 0x4604: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4609:
	/* 0x4609: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_460d:
	/* 0x460d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0x4619: js     505d <generic_sleepable_preload+0x505d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20573ULL;
	}
x86_l_461f:
	/* 0x461f: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4628:
	/* 0x4628: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_462e:
	/* 0x462e: mov    eax,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4635:
	/* 0x4635: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4639:
	/* 0x4639: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4642:
	/* 0x4642: je     465f <generic_sleepable_preload+0x465f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_465f;
	}
x86_l_4644:
	/* 0x4644: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4649:
	/* 0x4649: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_464d:
	/* 0x464d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4650:
	/* 0x4650: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4655:
	/* 0x4655: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4657:
	/* 0x4657: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4659:
	/* 0x4659: js     523e <generic_sleepable_preload+0x523e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21054ULL;
	}
x86_l_465f:
	/* 0x465f: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4668:
	/* 0x4668: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_466e:
	/* 0x466e: mov    eax,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4675:
	/* 0x4675: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4679:
	/* 0x4679: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4682:
	/* 0x4682: je     469f <generic_sleepable_preload+0x469f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_469f;
	}
x86_l_4684:
	/* 0x4684: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4689:
	/* 0x4689: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_468d:
	/* 0x468d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4690:
	/* 0x4690: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4695:
	/* 0x4695: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4697:
	/* 0x4697: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4699:
	/* 0x4699: js     52d3 <generic_sleepable_preload+0x52d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21203ULL;
	}
x86_l_469f:
	/* 0x469f: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a4:
	/* 0x46a4: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_46ad:
	/* 0x46ad: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_46b3:
	/* 0x46b3: mov    eax,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_46ba:
	/* 0x46ba: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_46be:
	/* 0x46be: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_46c7:
	/* 0x46c7: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_46cd:
	/* 0x46cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46d2:
	/* 0x46d2: jmp    492f <generic_sleepable_preload+0x492f> */
	goto x86_l_492f;
x86_l_46d7:
	/* 0x46d7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_46da:
	/* 0x46da: je     46f7 <generic_sleepable_preload+0x46f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46f7;
	}
x86_l_46dc:
	/* 0x46dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46e1:
	/* 0x46e1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e5:
	/* 0x46e5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_46e8:
	/* 0x46e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46ed:
	/* 0x46ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ef:
	/* 0x46ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46f1:
	/* 0x46f1: js     494f <generic_sleepable_preload+0x494f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_494f;
	}
x86_l_46f7:
	/* 0x46f7: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4700:
	/* 0x4700: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_4706:
	/* 0x4706: mov    eax,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_470d:
	/* 0x470d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4711:
	/* 0x4711: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_471a:
	/* 0x471a: je     4737 <generic_sleepable_preload+0x4737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4737;
	}
x86_l_471c:
	/* 0x471c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4721:
	/* 0x4721: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4725:
	/* 0x4725: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4728:
	/* 0x4728: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_472d:
	/* 0x472d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_472f:
	/* 0x472f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4731:
	/* 0x4731: js     4959 <generic_sleepable_preload+0x4959> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4959;
	}
x86_l_4737:
	/* 0x4737: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4740:
	/* 0x4740: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_4746:
	/* 0x4746: mov    eax,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_474d:
	/* 0x474d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4751:
	/* 0x4751: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_475a:
	/* 0x475a: je     4777 <generic_sleepable_preload+0x4777> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4777;
	}
x86_l_475c:
	/* 0x475c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4761:
	/* 0x4761: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4765:
	/* 0x4765: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4768:
	/* 0x4768: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_476d:
	/* 0x476d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_476f:
	/* 0x476f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4771:
	/* 0x4771: js     4ecc <generic_sleepable_preload+0x4ecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20172ULL;
	}
x86_l_4777:
	/* 0x4777: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4780:
	/* 0x4780: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_4786:
	/* 0x4786: mov    eax,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_478d:
	/* 0x478d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4791:
	/* 0x4791: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_479a:
	/* 0x479a: je     47b7 <generic_sleepable_preload+0x47b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47b7;
	}
x86_l_479c:
	/* 0x479c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47a1:
	/* 0x47a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47a5:
	/* 0x47a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47a8:
	/* 0x47a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47ad:
	/* 0x47ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47af:
	/* 0x47af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47b1:
	/* 0x47b1: js     4ef1 <generic_sleepable_preload+0x4ef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20209ULL;
	}
x86_l_47b7:
	/* 0x47b7: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_47c0:
	/* 0x47c0: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_47c6:
	/* 0x47c6: mov    eax,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_47cd:
	/* 0x47cd: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_47d1:
	/* 0x47d1: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_47da:
	/* 0x47da: je     47f7 <generic_sleepable_preload+0x47f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47f7;
	}
x86_l_47dc:
	/* 0x47dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47e1:
	/* 0x47e1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47e5:
	/* 0x47e5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_47e8:
	/* 0x47e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47ed:
	/* 0x47ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ef:
	/* 0x47ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47f1:
	/* 0x47f1: js     4f16 <generic_sleepable_preload+0x4f16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20246ULL;
	}
x86_l_47f7:
	/* 0x47f7: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4800:
	/* 0x4800: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_4806:
	/* 0x4806: mov    eax,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_480d:
	/* 0x480d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4811:
	/* 0x4811: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_481a:
	/* 0x481a: je     4837 <generic_sleepable_preload+0x4837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4837;
	}
x86_l_481c:
	/* 0x481c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4821:
	/* 0x4821: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4825:
	/* 0x4825: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4828:
	/* 0x4828: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_482d:
	/* 0x482d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_482f:
	/* 0x482f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4831:
	/* 0x4831: js     4f3b <generic_sleepable_preload+0x4f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20283ULL;
	}
x86_l_4837:
	/* 0x4837: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4840:
	/* 0x4840: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_4846:
	/* 0x4846: mov    eax,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_484d:
	/* 0x484d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4851:
	/* 0x4851: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_485a:
	/* 0x485a: je     4877 <generic_sleepable_preload+0x4877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4877;
	}
x86_l_485c:
	/* 0x485c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4861:
	/* 0x4861: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4865:
	/* 0x4865: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4868:
	/* 0x4868: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_486d:
	/* 0x486d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_486f:
	/* 0x486f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4871:
	/* 0x4871: js     505d <generic_sleepable_preload+0x505d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20573ULL;
	}
x86_l_4877:
	/* 0x4877: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4880:
	/* 0x4880: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_4886:
	/* 0x4886: mov    eax,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_488d:
	/* 0x488d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4891:
	/* 0x4891: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_489a:
	/* 0x489a: je     48b7 <generic_sleepable_preload+0x48b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48b7;
	}
x86_l_489c:
	/* 0x489c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48a1:
	/* 0x48a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48a5:
	/* 0x48a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48a8:
	/* 0x48a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48ad:
	/* 0x48ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48af:
	/* 0x48af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48b1:
	/* 0x48b1: js     536d <generic_sleepable_preload+0x536d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21357ULL;
	}
x86_l_48b7:
	/* 0x48b7: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48bc:
	/* 0x48bc: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_48c5:
	/* 0x48c5: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_48cb:
	/* 0x48cb: mov    eax,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_48d2:
	/* 0x48d2: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_48d6:
	/* 0x48d6: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_48df:
	/* 0x48df: je     48fc <generic_sleepable_preload+0x48fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48fc;
	}
x86_l_48e1:
	/* 0x48e1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48e6:
	/* 0x48e6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48ea:
	/* 0x48ea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_48ed:
	/* 0x48ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48f2:
	/* 0x48f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f4:
	/* 0x48f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48f6:
	/* 0x48f6: js     52d3 <generic_sleepable_preload+0x52d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21203ULL;
	}
x86_l_48fc:
	/* 0x48fc: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4901:
	/* 0x4901: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_490a:
	/* 0x490a: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_4910:
	/* 0x4910: mov    eax,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4917:
	/* 0x4917: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_491b:
	/* 0x491b: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4924:
	/* 0x4924: je     5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20581ULL;
	}
x86_l_492a:
	/* 0x492a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_492f:
	/* 0x492f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4933:
	/* 0x4933: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4936:
	/* 0x4936: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_493b:
	/* 0x493b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_493d:
	/* 0x493d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_493f:
	/* 0x493f: jns    5065 <generic_sleepable_preload+0x5065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 20581ULL;
	}
x86_l_4945:
	/* 0x4945: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_494a:
	/* 0x494a: jmp    5062 <generic_sleepable_preload+0x5062> */
	return 20578ULL;
x86_l_494f:
	/* 0x494f: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_4954:
	/* 0x4954: jmp    5062 <generic_sleepable_preload+0x5062> */
	return 20578ULL;
x86_l_4959:
	/* 0x4959: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_495e:
	/* 0x495e: jmp    5062 <generic_sleepable_preload+0x5062> */
	return 20578ULL;
x86_l_4963:
	/* 0x4963: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4968:
	/* 0x4968: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_496b:
	/* 0x496b: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_496d:
	/* 0x496d: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_496f:
	/* 0x496f: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_4974:
	/* 0x4974: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4976:
	/* 0x4976: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_497b:
	/* 0x497b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_497f:
	/* 0x497f: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4983:
	/* 0x4983: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4985:
	/* 0x4985: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4988:
	/* 0x4988: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_498b:
	/* 0x498b: cmp    WORD PTR [rsi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_4993:
	/* 0x4993: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20761ULL;
	}
x86_l_4999:
	/* 0x4999: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_49a0:
	/* 0x49a0: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_49a3:
	/* 0x49a3: mov    edx,DWORD PTR [rsi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_49a9:
	/* 0x49a9: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_49ac:
	/* 0x49ac: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49b0:
	/* 0x49b0: movzx  eax,WORD PTR [rsi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_49b7:
	/* 0x49b7: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_49b9:
	/* 0x49b9: je     4c24 <generic_sleepable_preload+0x4c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19492ULL;
	}
x86_l_49bf:
	/* 0x49bf: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_49c2:
	/* 0x49c2: je     49df <generic_sleepable_preload+0x49df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49df;
	}
x86_l_49c4:
	/* 0x49c4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49c9:
	/* 0x49c9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49cd:
	/* 0x49cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49d0:
	/* 0x49d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49d5:
	/* 0x49d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d7:
	/* 0x49d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49d9:
	/* 0x49d9: js     4ea4 <generic_sleepable_preload+0x4ea4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20132ULL;
	}
x86_l_49df:
	/* 0x49df: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49e4:
	/* 0x49e4: cmp    WORD PTR [rcx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_49ec:
	/* 0x49ec: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20761ULL;
	}
x86_l_49f2:
	/* 0x49f2: mov    eax,DWORD PTR [rcx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_49f8:
	/* 0x49f8: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_49fc:
	/* 0x49fc: cmp    WORD PTR [rcx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_4a04:
	/* 0x4a04: je     4a21 <generic_sleepable_preload+0x4a21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a21;
	}
x86_l_4a06:
	/* 0x4a06: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a0b:
	/* 0x4a0b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a0f:
	/* 0x4a0f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a12:
	/* 0x4a12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a17:
	/* 0x4a17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a19:
	/* 0x4a19: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a1b:
	/* 0x4a1b: js     4eae <generic_sleepable_preload+0x4eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20142ULL;
	}
x86_l_4a21:
	/* 0x4a21: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a26:
	/* 0x4a26: cmp    WORD PTR [rcx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_4a2e:
	/* 0x4a2e: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20761ULL;
	}
x86_l_4a34:
	/* 0x4a34: mov    eax,DWORD PTR [rcx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_4a3a:
	/* 0x4a3a: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a3e:
	/* 0x4a3e: cmp    WORD PTR [rcx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4a46:
	/* 0x4a46: je     4a63 <generic_sleepable_preload+0x4a63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a63;
	}
x86_l_4a48:
	/* 0x4a48: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a4d:
	/* 0x4a4d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a51:
	/* 0x4a51: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a54:
	/* 0x4a54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a59:
	/* 0x4a59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a5b:
	/* 0x4a5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a5d:
	/* 0x4a5d: js     4ed6 <generic_sleepable_preload+0x4ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20182ULL;
	}
x86_l_4a63:
	/* 0x4a63: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a68:
	/* 0x4a68: cmp    WORD PTR [rcx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4a70:
	/* 0x4a70: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20761ULL;
	}
x86_l_4a76:
	/* 0x4a76: mov    eax,DWORD PTR [rcx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4a7c:
	/* 0x4a7c: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4a80:
	/* 0x4a80: cmp    WORD PTR [rcx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4a88:
	/* 0x4a88: je     4aa5 <generic_sleepable_preload+0x4aa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aa5;
	}
x86_l_4a8a:
	/* 0x4a8a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a8f:
	/* 0x4a8f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a93:
	/* 0x4a93: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4a96:
	/* 0x4a96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a9b:
	/* 0x4a9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a9d:
	/* 0x4a9d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a9f:
	/* 0x4a9f: js     4efb <generic_sleepable_preload+0x4efb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20219ULL;
	}
x86_l_4aa5:
	/* 0x4aa5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4aaa:
	/* 0x4aaa: cmp    WORD PTR [rcx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_4ab2:
	/* 0x4ab2: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20761ULL;
	}
x86_l_4ab8:
	/* 0x4ab8: mov    eax,DWORD PTR [rcx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4abe:
	/* 0x4abe: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ac2:
	/* 0x4ac2: cmp    WORD PTR [rcx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4aca:
	/* 0x4aca: je     4ae7 <generic_sleepable_preload+0x4ae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ae7;
	}
x86_l_4acc:
	/* 0x4acc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ad1:
	/* 0x4ad1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ad5:
	/* 0x4ad5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ad8:
	/* 0x4ad8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4add:
	/* 0x4add: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4adf:
	/* 0x4adf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ae1:
	/* 0x4ae1: js     4f20 <generic_sleepable_preload+0x4f20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20256ULL;
	}
x86_l_4ae7:
	/* 0x4ae7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4aec:
	/* 0x4aec: cmp    WORD PTR [rcx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_4af4:
	/* 0x4af4: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20761ULL;
	}
x86_l_4afa:
	/* 0x4afa: mov    eax,DWORD PTR [rcx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_4b00:
	/* 0x4b00: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4b04:
	/* 0x4b04: cmp    WORD PTR [rcx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_4b0c:
	/* 0x4b0c: je     4b29 <generic_sleepable_preload+0x4b29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b29;
	}
x86_l_4b0e:
	/* 0x4b0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b13:
	/* 0x4b13: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b17:
	/* 0x4b17: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b1a:
	/* 0x4b1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1f:
	/* 0x4b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b21:
	/* 0x4b21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b23:
	/* 0x4b23: js     4f45 <generic_sleepable_preload+0x4f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 20293ULL;
	}
x86_l_4b29:
	/* 0x4b29: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b2e:
	/* 0x4b2e: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_4b36:
	/* 0x4b36: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20761ULL;
	}
x86_l_4b3c:
	/* 0x4b3c: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_4b42:
	/* 0x4b42: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4b46:
	/* 0x4b46: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4b4e:
	/* 0x4b4e: je     4b6b <generic_sleepable_preload+0x4b6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19307ULL;
	}
x86_l_4b50:
	/* 0x4b50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
	return 19285ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19285ULL: goto x86_l_4b55;
	case 19289ULL: goto x86_l_4b59;
	case 19292ULL: goto x86_l_4b5c;
	case 19297ULL: goto x86_l_4b61;
	case 19299ULL: goto x86_l_4b63;
	case 19301ULL: goto x86_l_4b65;
	case 19307ULL: goto x86_l_4b6b;
	case 19312ULL: goto x86_l_4b70;
	case 19320ULL: goto x86_l_4b78;
	case 19326ULL: goto x86_l_4b7e;
	case 19332ULL: goto x86_l_4b84;
	case 19336ULL: goto x86_l_4b88;
	case 19344ULL: goto x86_l_4b90;
	case 19346ULL: goto x86_l_4b92;
	case 19351ULL: goto x86_l_4b97;
	case 19355ULL: goto x86_l_4b9b;
	case 19358ULL: goto x86_l_4b9e;
	case 19363ULL: goto x86_l_4ba3;
	case 19365ULL: goto x86_l_4ba5;
	case 19367ULL: goto x86_l_4ba7;
	case 19373ULL: goto x86_l_4bad;
	case 19378ULL: goto x86_l_4bb2;
	case 19386ULL: goto x86_l_4bba;
	case 19392ULL: goto x86_l_4bc0;
	case 19398ULL: goto x86_l_4bc6;
	case 19402ULL: goto x86_l_4bca;
	case 19410ULL: goto x86_l_4bd2;
	case 19412ULL: goto x86_l_4bd4;
	case 19417ULL: goto x86_l_4bd9;
	case 19421ULL: goto x86_l_4bdd;
	case 19424ULL: goto x86_l_4be0;
	case 19429ULL: goto x86_l_4be5;
	case 19431ULL: goto x86_l_4be7;
	case 19433ULL: goto x86_l_4be9;
	case 19439ULL: goto x86_l_4bef;
	case 19444ULL: goto x86_l_4bf4;
	case 19452ULL: goto x86_l_4bfc;
	case 19458ULL: goto x86_l_4c02;
	case 19464ULL: goto x86_l_4c08;
	case 19468ULL: goto x86_l_4c0c;
	case 19476ULL: goto x86_l_4c14;
	case 19482ULL: goto x86_l_4c1a;
	case 19487ULL: goto x86_l_4c1f;
	case 19492ULL: goto x86_l_4c24;
	case 19495ULL: goto x86_l_4c27;
	case 19497ULL: goto x86_l_4c29;
	case 19502ULL: goto x86_l_4c2e;
	case 19506ULL: goto x86_l_4c32;
	case 19509ULL: goto x86_l_4c35;
	case 19514ULL: goto x86_l_4c3a;
	case 19516ULL: goto x86_l_4c3c;
	case 19518ULL: goto x86_l_4c3e;
	case 19524ULL: goto x86_l_4c44;
	case 19529ULL: goto x86_l_4c49;
	case 19537ULL: goto x86_l_4c51;
	case 19543ULL: goto x86_l_4c57;
	case 19549ULL: goto x86_l_4c5d;
	case 19553ULL: goto x86_l_4c61;
	case 19561ULL: goto x86_l_4c69;
	case 19563ULL: goto x86_l_4c6b;
	case 19568ULL: goto x86_l_4c70;
	case 19572ULL: goto x86_l_4c74;
	case 19575ULL: goto x86_l_4c77;
	case 19580ULL: goto x86_l_4c7c;
	case 19582ULL: goto x86_l_4c7e;
	case 19584ULL: goto x86_l_4c80;
	case 19590ULL: goto x86_l_4c86;
	case 19595ULL: goto x86_l_4c8b;
	case 19603ULL: goto x86_l_4c93;
	case 19609ULL: goto x86_l_4c99;
	case 19615ULL: goto x86_l_4c9f;
	case 19619ULL: goto x86_l_4ca3;
	case 19627ULL: goto x86_l_4cab;
	case 19629ULL: goto x86_l_4cad;
	case 19634ULL: goto x86_l_4cb2;
	case 19638ULL: goto x86_l_4cb6;
	case 19641ULL: goto x86_l_4cb9;
	case 19646ULL: goto x86_l_4cbe;
	case 19648ULL: goto x86_l_4cc0;
	case 19650ULL: goto x86_l_4cc2;
	case 19656ULL: goto x86_l_4cc8;
	case 19661ULL: goto x86_l_4ccd;
	case 19669ULL: goto x86_l_4cd5;
	case 19675ULL: goto x86_l_4cdb;
	case 19681ULL: goto x86_l_4ce1;
	case 19685ULL: goto x86_l_4ce5;
	case 19693ULL: goto x86_l_4ced;
	case 19695ULL: goto x86_l_4cef;
	case 19700ULL: goto x86_l_4cf4;
	case 19704ULL: goto x86_l_4cf8;
	case 19707ULL: goto x86_l_4cfb;
	case 19712ULL: goto x86_l_4d00;
	case 19714ULL: goto x86_l_4d02;
	case 19716ULL: goto x86_l_4d04;
	case 19722ULL: goto x86_l_4d0a;
	case 19727ULL: goto x86_l_4d0f;
	case 19735ULL: goto x86_l_4d17;
	case 19741ULL: goto x86_l_4d1d;
	case 19747ULL: goto x86_l_4d23;
	case 19751ULL: goto x86_l_4d27;
	case 19759ULL: goto x86_l_4d2f;
	case 19761ULL: goto x86_l_4d31;
	case 19766ULL: goto x86_l_4d36;
	case 19770ULL: goto x86_l_4d3a;
	case 19773ULL: goto x86_l_4d3d;
	case 19778ULL: goto x86_l_4d42;
	case 19780ULL: goto x86_l_4d44;
	case 19782ULL: goto x86_l_4d46;
	case 19788ULL: goto x86_l_4d4c;
	case 19793ULL: goto x86_l_4d51;
	case 19801ULL: goto x86_l_4d59;
	case 19807ULL: goto x86_l_4d5f;
	case 19813ULL: goto x86_l_4d65;
	case 19817ULL: goto x86_l_4d69;
	case 19825ULL: goto x86_l_4d71;
	case 19827ULL: goto x86_l_4d73;
	case 19832ULL: goto x86_l_4d78;
	case 19836ULL: goto x86_l_4d7c;
	case 19839ULL: goto x86_l_4d7f;
	case 19844ULL: goto x86_l_4d84;
	case 19846ULL: goto x86_l_4d86;
	case 19848ULL: goto x86_l_4d88;
	case 19854ULL: goto x86_l_4d8e;
	case 19859ULL: goto x86_l_4d93;
	case 19867ULL: goto x86_l_4d9b;
	case 19873ULL: goto x86_l_4da1;
	case 19879ULL: goto x86_l_4da7;
	case 19883ULL: goto x86_l_4dab;
	case 19891ULL: goto x86_l_4db3;
	case 19893ULL: goto x86_l_4db5;
	case 19898ULL: goto x86_l_4dba;
	case 19902ULL: goto x86_l_4dbe;
	case 19905ULL: goto x86_l_4dc1;
	case 19910ULL: goto x86_l_4dc6;
	case 19912ULL: goto x86_l_4dc8;
	case 19914ULL: goto x86_l_4dca;
	case 19920ULL: goto x86_l_4dd0;
	case 19925ULL: goto x86_l_4dd5;
	case 19933ULL: goto x86_l_4ddd;
	case 19939ULL: goto x86_l_4de3;
	case 19945ULL: goto x86_l_4de9;
	case 19949ULL: goto x86_l_4ded;
	case 19957ULL: goto x86_l_4df5;
	case 19959ULL: goto x86_l_4df7;
	case 19964ULL: goto x86_l_4dfc;
	case 19968ULL: goto x86_l_4e00;
	case 19971ULL: goto x86_l_4e03;
	case 19976ULL: goto x86_l_4e08;
	case 19978ULL: goto x86_l_4e0a;
	case 19980ULL: goto x86_l_4e0c;
	case 19986ULL: goto x86_l_4e12;
	case 19991ULL: goto x86_l_4e17;
	case 19999ULL: goto x86_l_4e1f;
	case 20005ULL: goto x86_l_4e25;
	case 20011ULL: goto x86_l_4e2b;
	case 20015ULL: goto x86_l_4e2f;
	case 20023ULL: goto x86_l_4e37;
	case 20025ULL: goto x86_l_4e39;
	case 20030ULL: goto x86_l_4e3e;
	case 20034ULL: goto x86_l_4e42;
	case 20037ULL: goto x86_l_4e45;
	case 20042ULL: goto x86_l_4e4a;
	case 20044ULL: goto x86_l_4e4c;
	case 20046ULL: goto x86_l_4e4e;
	case 20052ULL: goto x86_l_4e54;
	case 20057ULL: goto x86_l_4e59;
	case 20065ULL: goto x86_l_4e61;
	case 20071ULL: goto x86_l_4e67;
	case 20077ULL: goto x86_l_4e6d;
	case 20081ULL: goto x86_l_4e71;
	case 20089ULL: goto x86_l_4e79;
	case 20095ULL: goto x86_l_4e7f;
	case 20100ULL: goto x86_l_4e84;
	case 20104ULL: goto x86_l_4e88;
	case 20107ULL: goto x86_l_4e8b;
	case 20112ULL: goto x86_l_4e90;
	case 20114ULL: goto x86_l_4e92;
	case 20116ULL: goto x86_l_4e94;
	case 20122ULL: goto x86_l_4e9a;
	case 20127ULL: goto x86_l_4e9f;
	case 20132ULL: goto x86_l_4ea4;
	case 20137ULL: goto x86_l_4ea9;
	case 20142ULL: goto x86_l_4eae;
	case 20147ULL: goto x86_l_4eb3;
	case 20152ULL: goto x86_l_4eb8;
	case 20157ULL: goto x86_l_4ebd;
	case 20162ULL: goto x86_l_4ec2;
	case 20167ULL: goto x86_l_4ec7;
	case 20172ULL: goto x86_l_4ecc;
	case 20177ULL: goto x86_l_4ed1;
	case 20182ULL: goto x86_l_4ed6;
	case 20187ULL: goto x86_l_4edb;
	case 20192ULL: goto x86_l_4ee0;
	case 20197ULL: goto x86_l_4ee5;
	case 20199ULL: goto x86_l_4ee7;
	case 20204ULL: goto x86_l_4eec;
	case 20209ULL: goto x86_l_4ef1;
	case 20214ULL: goto x86_l_4ef6;
	case 20219ULL: goto x86_l_4efb;
	case 20224ULL: goto x86_l_4f00;
	case 20229ULL: goto x86_l_4f05;
	case 20234ULL: goto x86_l_4f0a;
	case 20236ULL: goto x86_l_4f0c;
	case 20241ULL: goto x86_l_4f11;
	case 20246ULL: goto x86_l_4f16;
	case 20251ULL: goto x86_l_4f1b;
	case 20256ULL: goto x86_l_4f20;
	case 20261ULL: goto x86_l_4f25;
	case 20266ULL: goto x86_l_4f2a;
	case 20271ULL: goto x86_l_4f2f;
	case 20273ULL: goto x86_l_4f31;
	case 20278ULL: goto x86_l_4f36;
	case 20283ULL: goto x86_l_4f3b;
	case 20288ULL: goto x86_l_4f40;
	case 20293ULL: goto x86_l_4f45;
	case 20298ULL: goto x86_l_4f4a;
	case 20303ULL: goto x86_l_4f4f;
	case 20308ULL: goto x86_l_4f54;
	case 20311ULL: goto x86_l_4f57;
	case 20315ULL: goto x86_l_4f5b;
	case 20320ULL: goto x86_l_4f60;
	case 20323ULL: goto x86_l_4f63;
	case 20328ULL: goto x86_l_4f68;
	case 20331ULL: goto x86_l_4f6b;
	case 20333ULL: goto x86_l_4f6d;
	case 20336ULL: goto x86_l_4f70;
	case 20342ULL: goto x86_l_4f76;
	case 20346ULL: goto x86_l_4f7a;
	case 20351ULL: goto x86_l_4f7f;
	case 20353ULL: goto x86_l_4f81;
	case 20358ULL: goto x86_l_4f86;
	case 20366ULL: goto x86_l_4f8e;
	case 20371ULL: goto x86_l_4f93;
	case 20378ULL: goto x86_l_4f9a;
	case 20383ULL: goto x86_l_4f9f;
	case 20385ULL: goto x86_l_4fa1;
	case 20388ULL: goto x86_l_4fa4;
	case 20394ULL: goto x86_l_4faa;
	case 20400ULL: goto x86_l_4fb0;
	case 20407ULL: goto x86_l_4fb7;
	case 20412ULL: goto x86_l_4fbc;
	case 20415ULL: goto x86_l_4fbf;
	case 20418ULL: goto x86_l_4fc2;
	case 20421ULL: goto x86_l_4fc5;
	case 20423ULL: goto x86_l_4fc7;
	case 20426ULL: goto x86_l_4fca;
	case 20431ULL: goto x86_l_4fcf;
	case 20436ULL: goto x86_l_4fd4;
	case 20441ULL: goto x86_l_4fd9;
	case 20444ULL: goto x86_l_4fdc;
	case 20449ULL: goto x86_l_4fe1;
	case 20452ULL: goto x86_l_4fe4;
	case 20457ULL: goto x86_l_4fe9;
	case 20460ULL: goto x86_l_4fec;
	case 20465ULL: goto x86_l_4ff1;
	case 20468ULL: goto x86_l_4ff4;
	case 20470ULL: goto x86_l_4ff6;
	case 20473ULL: goto x86_l_4ff9;
	case 20479ULL: goto x86_l_4fff;
	case 20483ULL: goto x86_l_5003;
	case 20488ULL: goto x86_l_5008;
	case 20490ULL: goto x86_l_500a;
	case 20495ULL: goto x86_l_500f;
	case 20503ULL: goto x86_l_5017;
	case 20508ULL: goto x86_l_501c;
	case 20515ULL: goto x86_l_5023;
	case 20520ULL: goto x86_l_5028;
	case 20522ULL: goto x86_l_502a;
	case 20525ULL: goto x86_l_502d;
	case 20531ULL: goto x86_l_5033;
	case 20537ULL: goto x86_l_5039;
	case 20544ULL: goto x86_l_5040;
	case 20549ULL: goto x86_l_5045;
	case 20552ULL: goto x86_l_5048;
	case 20555ULL: goto x86_l_504b;
	case 20558ULL: goto x86_l_504e;
	case 20560ULL: goto x86_l_5050;
	case 20563ULL: goto x86_l_5053;
	case 20568ULL: goto x86_l_5058;
	case 20573ULL: goto x86_l_505d;
	case 20578ULL: goto x86_l_5062;
	case 20581ULL: goto x86_l_5065;
	case 20584ULL: goto x86_l_5068;
	case 20590ULL: goto x86_l_506e;
	case 20594ULL: goto x86_l_5072;
	case 20599ULL: goto x86_l_5077;
	case 20601ULL: goto x86_l_5079;
	case 20606ULL: goto x86_l_507e;
	case 20614ULL: goto x86_l_5086;
	case 20619ULL: goto x86_l_508b;
	case 20626ULL: goto x86_l_5092;
	case 20631ULL: goto x86_l_5097;
	case 20633ULL: goto x86_l_5099;
	case 20636ULL: goto x86_l_509c;
	case 20642ULL: goto x86_l_50a2;
	case 20648ULL: goto x86_l_50a8;
	case 20655ULL: goto x86_l_50af;
	case 20660ULL: goto x86_l_50b4;
	case 20663ULL: goto x86_l_50b7;
	case 20666ULL: goto x86_l_50ba;
	case 20669ULL: goto x86_l_50bd;
	case 20671ULL: goto x86_l_50bf;
	case 20674ULL: goto x86_l_50c2;
	case 20679ULL: goto x86_l_50c7;
	case 20682ULL: goto x86_l_50ca;
	case 20685ULL: goto x86_l_50cd;
	case 20690ULL: goto x86_l_50d2;
	case 20692ULL: goto x86_l_50d4;
	case 20695ULL: goto x86_l_50d7;
	case 20701ULL: goto x86_l_50dd;
	case 20704ULL: goto x86_l_50e0;
	case 20706ULL: goto x86_l_50e2;
	case 20709ULL: goto x86_l_50e5;
	case 20713ULL: goto x86_l_50e9;
	case 20718ULL: goto x86_l_50ee;
	case 20721ULL: goto x86_l_50f1;
	case 20723ULL: goto x86_l_50f3;
	case 20726ULL: goto x86_l_50f6;
	case 20731ULL: goto x86_l_50fb;
	case 20733ULL: goto x86_l_50fd;
	case 20736ULL: goto x86_l_5100;
	case 20738ULL: goto x86_l_5102;
	case 20743ULL: goto x86_l_5107;
	case 20746ULL: goto x86_l_510a;
	case 20748ULL: goto x86_l_510c;
	case 20753ULL: goto x86_l_5111;
	case 20758ULL: goto x86_l_5116;
	case 20761ULL: goto x86_l_5119;
	case 20764ULL: goto x86_l_511c;
	case 20770ULL: goto x86_l_5122;
	case 20774ULL: goto x86_l_5126;
	case 20779ULL: goto x86_l_512b;
	case 20781ULL: goto x86_l_512d;
	case 20786ULL: goto x86_l_5132;
	case 20794ULL: goto x86_l_513a;
	case 20799ULL: goto x86_l_513f;
	case 20806ULL: goto x86_l_5146;
	case 20811ULL: goto x86_l_514b;
	case 20813ULL: goto x86_l_514d;
	case 20816ULL: goto x86_l_5150;
	case 20822ULL: goto x86_l_5156;
	case 20828ULL: goto x86_l_515c;
	case 20835ULL: goto x86_l_5163;
	case 20840ULL: goto x86_l_5168;
	case 20843ULL: goto x86_l_516b;
	case 20846ULL: goto x86_l_516e;
	case 20849ULL: goto x86_l_5171;
	case 20851ULL: goto x86_l_5173;
	case 20854ULL: goto x86_l_5176;
	case 20859ULL: goto x86_l_517b;
	case 20862ULL: goto x86_l_517e;
	case 20865ULL: goto x86_l_5181;
	case 20867ULL: goto x86_l_5183;
	case 20870ULL: goto x86_l_5186;
	case 20876ULL: goto x86_l_518c;
	case 20879ULL: goto x86_l_518f;
	case 20881ULL: goto x86_l_5191;
	case 20884ULL: goto x86_l_5194;
	case 20888ULL: goto x86_l_5198;
	case 20893ULL: goto x86_l_519d;
	case 20896ULL: goto x86_l_51a0;
	case 20898ULL: goto x86_l_51a2;
	case 20901ULL: goto x86_l_51a5;
	case 20906ULL: goto x86_l_51aa;
	case 20908ULL: goto x86_l_51ac;
	case 20911ULL: goto x86_l_51af;
	case 20913ULL: goto x86_l_51b1;
	case 20918ULL: goto x86_l_51b6;
	case 20921ULL: goto x86_l_51b9;
	case 20923ULL: goto x86_l_51bb;
	case 20928ULL: goto x86_l_51c0;
	case 20931ULL: goto x86_l_51c3;
	case 20936ULL: goto x86_l_51c8;
	case 20941ULL: goto x86_l_51cd;
	case 20944ULL: goto x86_l_51d0;
	case 20949ULL: goto x86_l_51d5;
	case 20952ULL: goto x86_l_51d8;
	case 20958ULL: goto x86_l_51de;
	case 20963ULL: goto x86_l_51e3;
	case 20966ULL: goto x86_l_51e6;
	case 20971ULL: goto x86_l_51eb;
	case 20976ULL: goto x86_l_51f0;
	case 20979ULL: goto x86_l_51f3;
	case 20984ULL: goto x86_l_51f8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4b55:
	/* 0x4b55: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b59:
	/* 0x4b59: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b5c:
	/* 0x4b5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b61:
	/* 0x4b61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b63:
	/* 0x4b63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b65:
	/* 0x4b65: js     5111 <generic_sleepable_preload+0x5111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_5111;
	}
x86_l_4b6b:
	/* 0x4b6b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b70:
	/* 0x4b70: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_4b78:
	/* 0x4b78: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4b7e:
	/* 0x4b7e: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_4b84:
	/* 0x4b84: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4b88:
	/* 0x4b88: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_4b90:
	/* 0x4b90: je     4bad <generic_sleepable_preload+0x4bad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bad;
	}
x86_l_4b92:
	/* 0x4b92: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b97:
	/* 0x4b97: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b9b:
	/* 0x4b9b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b9e:
	/* 0x4b9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ba3:
	/* 0x4ba3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ba5:
	/* 0x4ba5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ba7:
	/* 0x4ba7: js     51cd <generic_sleepable_preload+0x51cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_51cd;
	}
x86_l_4bad:
	/* 0x4bad: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb2:
	/* 0x4bb2: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_4bba:
	/* 0x4bba: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4bc0:
	/* 0x4bc0: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_4bc6:
	/* 0x4bc6: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4bca:
	/* 0x4bca: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_4bd2:
	/* 0x4bd2: je     4bef <generic_sleepable_preload+0x4bef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bef;
	}
x86_l_4bd4:
	/* 0x4bd4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4bd9:
	/* 0x4bd9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bdd:
	/* 0x4bdd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4be0:
	/* 0x4be0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4be5:
	/* 0x4be5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4be7:
	/* 0x4be7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4be9:
	/* 0x4be9: js     52e5 <generic_sleepable_preload+0x52e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21221ULL;
	}
x86_l_4bef:
	/* 0x4bef: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf4:
	/* 0x4bf4: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_4bfc:
	/* 0x4bfc: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4c02:
	/* 0x4c02: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_4c08:
	/* 0x4c08: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4c0c:
	/* 0x4c0c: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_4c14:
	/* 0x4c14: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4c1a:
	/* 0x4c1a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c1f:
	/* 0x4c1f: jmp    4e84 <generic_sleepable_preload+0x4e84> */
	goto x86_l_4e84;
x86_l_4c24:
	/* 0x4c24: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4c27:
	/* 0x4c27: je     4c44 <generic_sleepable_preload+0x4c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c44;
	}
x86_l_4c29:
	/* 0x4c29: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c2e:
	/* 0x4c2e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c32:
	/* 0x4c32: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c35:
	/* 0x4c35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c3a:
	/* 0x4c3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c3c:
	/* 0x4c3c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c3e:
	/* 0x4c3e: js     4ea4 <generic_sleepable_preload+0x4ea4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ea4;
	}
x86_l_4c44:
	/* 0x4c44: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c49:
	/* 0x4c49: cmp    WORD PTR [rcx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_4c51:
	/* 0x4c51: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4c57:
	/* 0x4c57: mov    eax,DWORD PTR [rcx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_4c5d:
	/* 0x4c5d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4c61:
	/* 0x4c61: cmp    WORD PTR [rcx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_4c69:
	/* 0x4c69: je     4c86 <generic_sleepable_preload+0x4c86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c86;
	}
x86_l_4c6b:
	/* 0x4c6b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c70:
	/* 0x4c70: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c74:
	/* 0x4c74: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c77:
	/* 0x4c77: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c7c:
	/* 0x4c7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c7e:
	/* 0x4c7e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c80:
	/* 0x4c80: js     4eae <generic_sleepable_preload+0x4eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4eae;
	}
x86_l_4c86:
	/* 0x4c86: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c8b:
	/* 0x4c8b: cmp    WORD PTR [rcx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_4c93:
	/* 0x4c93: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4c99:
	/* 0x4c99: mov    eax,DWORD PTR [rcx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_4c9f:
	/* 0x4c9f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ca3:
	/* 0x4ca3: cmp    WORD PTR [rcx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_4cab:
	/* 0x4cab: je     4cc8 <generic_sleepable_preload+0x4cc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cc8;
	}
x86_l_4cad:
	/* 0x4cad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4cb2:
	/* 0x4cb2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cb6:
	/* 0x4cb6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4cb9:
	/* 0x4cb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cbe:
	/* 0x4cbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cc0:
	/* 0x4cc0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cc2:
	/* 0x4cc2: js     4ed6 <generic_sleepable_preload+0x4ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ed6;
	}
x86_l_4cc8:
	/* 0x4cc8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ccd:
	/* 0x4ccd: cmp    WORD PTR [rcx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_4cd5:
	/* 0x4cd5: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4cdb:
	/* 0x4cdb: mov    eax,DWORD PTR [rcx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_4ce1:
	/* 0x4ce1: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ce5:
	/* 0x4ce5: cmp    WORD PTR [rcx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_4ced:
	/* 0x4ced: je     4d0a <generic_sleepable_preload+0x4d0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d0a;
	}
x86_l_4cef:
	/* 0x4cef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4cf4:
	/* 0x4cf4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cf8:
	/* 0x4cf8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4cfb:
	/* 0x4cfb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d00:
	/* 0x4d00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d02:
	/* 0x4d02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d04:
	/* 0x4d04: js     4efb <generic_sleepable_preload+0x4efb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4efb;
	}
x86_l_4d0a:
	/* 0x4d0a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d0f:
	/* 0x4d0f: cmp    WORD PTR [rcx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_4d17:
	/* 0x4d17: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4d1d:
	/* 0x4d1d: mov    eax,DWORD PTR [rcx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_4d23:
	/* 0x4d23: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4d27:
	/* 0x4d27: cmp    WORD PTR [rcx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_4d2f:
	/* 0x4d2f: je     4d4c <generic_sleepable_preload+0x4d4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d4c;
	}
x86_l_4d31:
	/* 0x4d31: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d36:
	/* 0x4d36: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d3a:
	/* 0x4d3a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d3d:
	/* 0x4d3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d42:
	/* 0x4d42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d44:
	/* 0x4d44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d46:
	/* 0x4d46: js     4f20 <generic_sleepable_preload+0x4f20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4f20;
	}
x86_l_4d4c:
	/* 0x4d4c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d51:
	/* 0x4d51: cmp    WORD PTR [rcx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_4d59:
	/* 0x4d59: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4d5f:
	/* 0x4d5f: mov    eax,DWORD PTR [rcx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_4d65:
	/* 0x4d65: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4d69:
	/* 0x4d69: cmp    WORD PTR [rcx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_4d71:
	/* 0x4d71: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d8e;
	}
x86_l_4d73:
	/* 0x4d73: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d78:
	/* 0x4d78: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d7c:
	/* 0x4d7c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d7f:
	/* 0x4d7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d84:
	/* 0x4d84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d86:
	/* 0x4d86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d88:
	/* 0x4d88: js     4f45 <generic_sleepable_preload+0x4f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4f45;
	}
x86_l_4d8e:
	/* 0x4d8e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d93:
	/* 0x4d93: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_4d9b:
	/* 0x4d9b: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4da1:
	/* 0x4da1: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_4da7:
	/* 0x4da7: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4dab:
	/* 0x4dab: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_4db3:
	/* 0x4db3: je     4dd0 <generic_sleepable_preload+0x4dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dd0;
	}
x86_l_4db5:
	/* 0x4db5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4dba:
	/* 0x4dba: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dbe:
	/* 0x4dbe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4dc1:
	/* 0x4dc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dc6:
	/* 0x4dc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc8:
	/* 0x4dc8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4dca:
	/* 0x4dca: js     5111 <generic_sleepable_preload+0x5111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_5111;
	}
x86_l_4dd0:
	/* 0x4dd0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dd5:
	/* 0x4dd5: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_4ddd:
	/* 0x4ddd: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4de3:
	/* 0x4de3: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_4de9:
	/* 0x4de9: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4ded:
	/* 0x4ded: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_4df5:
	/* 0x4df5: je     4e12 <generic_sleepable_preload+0x4e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e12;
	}
x86_l_4df7:
	/* 0x4df7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4dfc:
	/* 0x4dfc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e00:
	/* 0x4e00: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e03:
	/* 0x4e03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e08:
	/* 0x4e08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e0a:
	/* 0x4e0a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e0c:
	/* 0x4e0c: js     51cd <generic_sleepable_preload+0x51cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_51cd;
	}
x86_l_4e12:
	/* 0x4e12: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e17:
	/* 0x4e17: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_4e1f:
	/* 0x4e1f: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4e25:
	/* 0x4e25: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_4e2b:
	/* 0x4e2b: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e2f:
	/* 0x4e2f: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_4e37:
	/* 0x4e37: je     4e54 <generic_sleepable_preload+0x4e54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e54;
	}
x86_l_4e39:
	/* 0x4e39: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e3e:
	/* 0x4e3e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e42:
	/* 0x4e42: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e45:
	/* 0x4e45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e4a:
	/* 0x4e4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e4c:
	/* 0x4e4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e4e:
	/* 0x4e4e: js     52e5 <generic_sleepable_preload+0x52e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21221ULL;
	}
x86_l_4e54:
	/* 0x4e54: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e59:
	/* 0x4e59: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_4e61:
	/* 0x4e61: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4e67:
	/* 0x4e67: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_4e6d:
	/* 0x4e6d: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4e71:
	/* 0x4e71: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_4e79:
	/* 0x4e79: je     5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5119;
	}
x86_l_4e7f:
	/* 0x4e7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e84:
	/* 0x4e84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e88:
	/* 0x4e88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4e8b:
	/* 0x4e8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e90:
	/* 0x4e90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e92:
	/* 0x4e92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e94:
	/* 0x4e94: jns    5119 <generic_sleepable_preload+0x5119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5119;
	}
x86_l_4e9a:
	/* 0x4e9a: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4e9f:
	/* 0x4e9f: jmp    5116 <generic_sleepable_preload+0x5116> */
	goto x86_l_5116;
x86_l_4ea4:
	/* 0x4ea4: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_4ea9:
	/* 0x4ea9: jmp    5116 <generic_sleepable_preload+0x5116> */
	goto x86_l_5116;
x86_l_4eae:
	/* 0x4eae: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4eb3:
	/* 0x4eb3: jmp    5116 <generic_sleepable_preload+0x5116> */
	goto x86_l_5116;
x86_l_4eb8:
	/* 0x4eb8: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4ebd:
	/* 0x4ebd: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	goto x86_l_4f54;
x86_l_4ec2:
	/* 0x4ec2: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4ec7:
	/* 0x4ec7: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	goto x86_l_4fd9;
x86_l_4ecc:
	/* 0x4ecc: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4ed1:
	/* 0x4ed1: jmp    5062 <generic_sleepable_preload+0x5062> */
	goto x86_l_5062;
x86_l_4ed6:
	/* 0x4ed6: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4edb:
	/* 0x4edb: jmp    5116 <generic_sleepable_preload+0x5116> */
	goto x86_l_5116;
x86_l_4ee0:
	/* 0x4ee0: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4ee5:
	/* 0x4ee5: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	goto x86_l_4f54;
x86_l_4ee7:
	/* 0x4ee7: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4eec:
	/* 0x4eec: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	goto x86_l_4fd9;
x86_l_4ef1:
	/* 0x4ef1: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4ef6:
	/* 0x4ef6: jmp    5062 <generic_sleepable_preload+0x5062> */
	goto x86_l_5062;
x86_l_4efb:
	/* 0x4efb: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4f00:
	/* 0x4f00: jmp    5116 <generic_sleepable_preload+0x5116> */
	goto x86_l_5116;
x86_l_4f05:
	/* 0x4f05: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4f0a:
	/* 0x4f0a: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	goto x86_l_4f54;
x86_l_4f0c:
	/* 0x4f0c: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4f11:
	/* 0x4f11: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	goto x86_l_4fd9;
x86_l_4f16:
	/* 0x4f16: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4f1b:
	/* 0x4f1b: jmp    5062 <generic_sleepable_preload+0x5062> */
	goto x86_l_5062;
x86_l_4f20:
	/* 0x4f20: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4f25:
	/* 0x4f25: jmp    5116 <generic_sleepable_preload+0x5116> */
	goto x86_l_5116;
x86_l_4f2a:
	/* 0x4f2a: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4f2f:
	/* 0x4f2f: jmp    4f54 <generic_sleepable_preload+0x4f54> */
	goto x86_l_4f54;
x86_l_4f31:
	/* 0x4f31: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4f36:
	/* 0x4f36: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	goto x86_l_4fd9;
x86_l_4f3b:
	/* 0x4f3b: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4f40:
	/* 0x4f40: jmp    5062 <generic_sleepable_preload+0x5062> */
	goto x86_l_5062;
x86_l_4f45:
	/* 0x4f45: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4f4a:
	/* 0x4f4a: jmp    5116 <generic_sleepable_preload+0x5116> */
	goto x86_l_5116;
x86_l_4f4f:
	/* 0x4f4f: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_4f54:
	/* 0x4f54: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f57:
	/* 0x4f57: mov    ebx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f5b:
	/* 0x4f5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f60:
	/* 0x4f60: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4f63:
	/* 0x4f63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f68:
	/* 0x4f68: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4f6b:
	/* 0x4f6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f6d:
	/* 0x4f6d: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4f70:
	/* 0x4f70: jne    35f7 <generic_sleepable_preload+0x35f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13815ULL;
	}
x86_l_4f76:
	/* 0x4f76: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f7a:
	/* 0x4f7a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4f7f:
	/* 0x4f7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f81:
	/* 0x4f81: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f86:
	/* 0x4f86: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4f8e:
	/* 0x4f8e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4f93:
	/* 0x4f93: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4f9a:
	/* 0x4f9a: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4f9f:
	/* 0x4f9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fa1:
	/* 0x4fa1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4fa4:
	/* 0x4fa4: je     35f7 <generic_sleepable_preload+0x35f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13815ULL;
	}
x86_l_4faa:
	/* 0x4faa: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4fb0:
	/* 0x4fb0: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4fb7:
	/* 0x4fb7: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fbc:
	/* 0x4fbc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4fbf:
	/* 0x4fbf: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4fc2:
	/* 0x4fc2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4fc5:
	/* 0x4fc5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fc7:
	/* 0x4fc7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4fca:
	/* 0x4fca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4fcf:
	/* 0x4fcf: jmp    50c7 <generic_sleepable_preload+0x50c7> */
	goto x86_l_50c7;
x86_l_4fd4:
	/* 0x4fd4: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_4fd9:
	/* 0x4fd9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fdc:
	/* 0x4fdc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fe1:
	/* 0x4fe1: mov    ebx,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4fe4:
	/* 0x4fe4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fe9:
	/* 0x4fe9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4fec:
	/* 0x4fec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ff1:
	/* 0x4ff1: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4ff4:
	/* 0x4ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ff6:
	/* 0x4ff6: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4ff9:
	/* 0x4ff9: jne    3602 <generic_sleepable_preload+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13826ULL;
	}
x86_l_4fff:
	/* 0x4fff: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5003:
	/* 0x5003: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5008:
	/* 0x5008: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_500a:
	/* 0x500a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_500f:
	/* 0x500f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5017:
	/* 0x5017: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_501c:
	/* 0x501c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5023:
	/* 0x5023: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5028:
	/* 0x5028: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_502a:
	/* 0x502a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_502d:
	/* 0x502d: je     3602 <generic_sleepable_preload+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13826ULL;
	}
x86_l_5033:
	/* 0x5033: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5039:
	/* 0x5039: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5040:
	/* 0x5040: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5045:
	/* 0x5045: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5048:
	/* 0x5048: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_504b:
	/* 0x504b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_504e:
	/* 0x504e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5050:
	/* 0x5050: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5053:
	/* 0x5053: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5058:
	/* 0x5058: jmp    517b <generic_sleepable_preload+0x517b> */
	goto x86_l_517b;
x86_l_505d:
	/* 0x505d: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5062:
	/* 0x5062: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5065:
	/* 0x5065: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5068:
	/* 0x5068: jne    35f7 <generic_sleepable_preload+0x35f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13815ULL;
	}
x86_l_506e:
	/* 0x506e: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5072:
	/* 0x5072: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5077:
	/* 0x5077: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5079:
	/* 0x5079: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_507e:
	/* 0x507e: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5086:
	/* 0x5086: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_508b:
	/* 0x508b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5092:
	/* 0x5092: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5097:
	/* 0x5097: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5099:
	/* 0x5099: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_509c:
	/* 0x509c: je     35f7 <generic_sleepable_preload+0x35f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13815ULL;
	}
x86_l_50a2:
	/* 0x50a2: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_50a8:
	/* 0x50a8: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_50af:
	/* 0x50af: lea    r13,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50b4:
	/* 0x50b4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50b7:
	/* 0x50b7: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_50ba:
	/* 0x50ba: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_50bd:
	/* 0x50bd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50bf:
	/* 0x50bf: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_50c2:
	/* 0x50c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_50c7:
	/* 0x50c7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50ca:
	/* 0x50ca: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_50cd:
	/* 0x50cd: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50d2:
	/* 0x50d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d4:
	/* 0x50d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50d7:
	/* 0x50d7: je     35f7 <generic_sleepable_preload+0x35f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13815ULL;
	}
x86_l_50dd:
	/* 0x50dd: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_50e0:
	/* 0x50e0: je     510a <generic_sleepable_preload+0x510a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_510a;
	}
x86_l_50e2:
	/* 0x50e2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_50e5:
	/* 0x50e5: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_50e9:
	/* 0x50e9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_50ee:
	/* 0x50ee: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_50f1:
	/* 0x50f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50f3:
	/* 0x50f3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_50f6:
	/* 0x50f6: call   50fb <generic_sleepable_preload+0x50fb> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_50fb:
	/* 0x50fb: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_50fd:
	/* 0x50fd: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5100:
	/* 0x5100: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5102:
	/* 0x5102: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_5107:
	/* 0x5107: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_510a:
	/* 0x510a: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_510c:
	/* 0x510c: jmp    35f7 <generic_sleepable_preload+0x35f7> */
	return 13815ULL;
x86_l_5111:
	/* 0x5111: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5116:
	/* 0x5116: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5119:
	/* 0x5119: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_511c:
	/* 0x511c: jne    3602 <generic_sleepable_preload+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13826ULL;
	}
x86_l_5122:
	/* 0x5122: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5126:
	/* 0x5126: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_512b:
	/* 0x512b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_512d:
	/* 0x512d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5132:
	/* 0x5132: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_513a:
	/* 0x513a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_513f:
	/* 0x513f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5146:
	/* 0x5146: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_514b:
	/* 0x514b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_514d:
	/* 0x514d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5150:
	/* 0x5150: je     3602 <generic_sleepable_preload+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13826ULL;
	}
x86_l_5156:
	/* 0x5156: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_515c:
	/* 0x515c: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5163:
	/* 0x5163: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5168:
	/* 0x5168: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_516b:
	/* 0x516b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_516e:
	/* 0x516e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5171:
	/* 0x5171: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5173:
	/* 0x5173: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5176:
	/* 0x5176: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_517b:
	/* 0x517b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_517e:
	/* 0x517e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5181:
	/* 0x5181: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5183:
	/* 0x5183: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5186:
	/* 0x5186: je     3602 <generic_sleepable_preload+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13826ULL;
	}
x86_l_518c:
	/* 0x518c: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_518f:
	/* 0x518f: je     51b9 <generic_sleepable_preload+0x51b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51b9;
	}
x86_l_5191:
	/* 0x5191: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5194:
	/* 0x5194: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_5198:
	/* 0x5198: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_519d:
	/* 0x519d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_51a0:
	/* 0x51a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51a2:
	/* 0x51a2: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_51a5:
	/* 0x51a5: call   51aa <generic_sleepable_preload+0x51aa> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_51aa:
	/* 0x51aa: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_51ac:
	/* 0x51ac: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_51af:
	/* 0x51af: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_51b1:
	/* 0x51b1: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_51b6:
	/* 0x51b6: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_51b9:
	/* 0x51b9: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51bb:
	/* 0x51bb: jmp    3602 <generic_sleepable_preload+0x3602> */
	return 13826ULL;
x86_l_51c0:
	/* 0x51c0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51c3:
	/* 0x51c3: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_51c8:
	/* 0x51c8: jmp    4fdc <generic_sleepable_preload+0x4fdc> */
	goto x86_l_4fdc;
x86_l_51cd:
	/* 0x51cd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51d0:
	/* 0x51d0: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_51d5:
	/* 0x51d5: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_51d8:
	/* 0x51d8: jne    3602 <generic_sleepable_preload+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13826ULL;
	}
x86_l_51de:
	/* 0x51de: jmp    5122 <generic_sleepable_preload+0x5122> */
	goto x86_l_5122;
x86_l_51e3:
	/* 0x51e3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51e6:
	/* 0x51e6: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_51eb:
	/* 0x51eb: jmp    19d2 <generic_sleepable_preload+0x19d2> */
	return 6610ULL;
x86_l_51f0:
	/* 0x51f0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51f3:
	/* 0x51f3: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_51f8:
	/* 0x51f8: jmp    1a54 <generic_sleepable_preload+0x1a54> */
	return 6740ULL;
	return 20989ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20989ULL: goto x86_l_51fd;
	case 20992ULL: goto x86_l_5200;
	case 20997ULL: goto x86_l_5205;
	case 21002ULL: goto x86_l_520a;
	case 21005ULL: goto x86_l_520d;
	case 21010ULL: goto x86_l_5212;
	case 21015ULL: goto x86_l_5217;
	case 21018ULL: goto x86_l_521a;
	case 21023ULL: goto x86_l_521f;
	case 21028ULL: goto x86_l_5224;
	case 21031ULL: goto x86_l_5227;
	case 21036ULL: goto x86_l_522c;
	case 21041ULL: goto x86_l_5231;
	case 21044ULL: goto x86_l_5234;
	case 21049ULL: goto x86_l_5239;
	case 21054ULL: goto x86_l_523e;
	case 21057ULL: goto x86_l_5241;
	case 21062ULL: goto x86_l_5246;
	case 21067ULL: goto x86_l_524b;
	case 21072ULL: goto x86_l_5250;
	case 21075ULL: goto x86_l_5253;
	case 21080ULL: goto x86_l_5258;
	case 21085ULL: goto x86_l_525d;
	case 21090ULL: goto x86_l_5262;
	case 21093ULL: goto x86_l_5265;
	case 21098ULL: goto x86_l_526a;
	case 21103ULL: goto x86_l_526f;
	case 21108ULL: goto x86_l_5274;
	case 21111ULL: goto x86_l_5277;
	case 21116ULL: goto x86_l_527c;
	case 21121ULL: goto x86_l_5281;
	case 21126ULL: goto x86_l_5286;
	case 21129ULL: goto x86_l_5289;
	case 21134ULL: goto x86_l_528e;
	case 21139ULL: goto x86_l_5293;
	case 21144ULL: goto x86_l_5298;
	case 21147ULL: goto x86_l_529b;
	case 21152ULL: goto x86_l_52a0;
	case 21157ULL: goto x86_l_52a5;
	case 21162ULL: goto x86_l_52aa;
	case 21165ULL: goto x86_l_52ad;
	case 21170ULL: goto x86_l_52b2;
	case 21175ULL: goto x86_l_52b7;
	case 21180ULL: goto x86_l_52bc;
	case 21183ULL: goto x86_l_52bf;
	case 21188ULL: goto x86_l_52c4;
	case 21193ULL: goto x86_l_52c9;
	case 21198ULL: goto x86_l_52ce;
	case 21203ULL: goto x86_l_52d3;
	case 21208ULL: goto x86_l_52d8;
	case 21211ULL: goto x86_l_52db;
	case 21216ULL: goto x86_l_52e0;
	case 21221ULL: goto x86_l_52e5;
	case 21226ULL: goto x86_l_52ea;
	case 21231ULL: goto x86_l_52ef;
	case 21234ULL: goto x86_l_52f2;
	case 21239ULL: goto x86_l_52f7;
	case 21244ULL: goto x86_l_52fc;
	case 21249ULL: goto x86_l_5301;
	case 21252ULL: goto x86_l_5304;
	case 21257ULL: goto x86_l_5309;
	case 21262ULL: goto x86_l_530e;
	case 21267ULL: goto x86_l_5313;
	case 21270ULL: goto x86_l_5316;
	case 21275ULL: goto x86_l_531b;
	case 21280ULL: goto x86_l_5320;
	case 21285ULL: goto x86_l_5325;
	case 21288ULL: goto x86_l_5328;
	case 21293ULL: goto x86_l_532d;
	case 21298ULL: goto x86_l_5332;
	case 21303ULL: goto x86_l_5337;
	case 21306ULL: goto x86_l_533a;
	case 21311ULL: goto x86_l_533f;
	case 21316ULL: goto x86_l_5344;
	case 21321ULL: goto x86_l_5349;
	case 21324ULL: goto x86_l_534c;
	case 21329ULL: goto x86_l_5351;
	case 21334ULL: goto x86_l_5356;
	case 21339ULL: goto x86_l_535b;
	case 21342ULL: goto x86_l_535e;
	case 21347ULL: goto x86_l_5363;
	case 21352ULL: goto x86_l_5368;
	case 21357ULL: goto x86_l_536d;
	case 21360ULL: goto x86_l_5370;
	case 21365ULL: goto x86_l_5375;
	case 21370ULL: goto x86_l_537a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_51fd:
	/* 0x51fd: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5200:
	/* 0x5200: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5205:
	/* 0x5205: jmp    274e <generic_sleepable_preload+0x274e> */
	return 10062ULL;
x86_l_520a:
	/* 0x520a: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_520d:
	/* 0x520d: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5212:
	/* 0x5212: jmp    27d0 <generic_sleepable_preload+0x27d0> */
	return 10192ULL;
x86_l_5217:
	/* 0x5217: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_521a:
	/* 0x521a: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_521f:
	/* 0x521f: jmp    34cb <generic_sleepable_preload+0x34cb> */
	return 13515ULL;
x86_l_5224:
	/* 0x5224: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5227:
	/* 0x5227: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_522c:
	/* 0x522c: jmp    354d <generic_sleepable_preload+0x354d> */
	return 13645ULL;
x86_l_5231:
	/* 0x5231: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5234:
	/* 0x5234: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5239:
	/* 0x5239: jmp    4f57 <generic_sleepable_preload+0x4f57> */
	return 20311ULL;
x86_l_523e:
	/* 0x523e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5241:
	/* 0x5241: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5246:
	/* 0x5246: jmp    5065 <generic_sleepable_preload+0x5065> */
	return 20581ULL;
x86_l_524b:
	/* 0x524b: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5250:
	/* 0x5250: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5253:
	/* 0x5253: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5258:
	/* 0x5258: jmp    19d2 <generic_sleepable_preload+0x19d2> */
	return 6610ULL;
x86_l_525d:
	/* 0x525d: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5262:
	/* 0x5262: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5265:
	/* 0x5265: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_526a:
	/* 0x526a: jmp    1a54 <generic_sleepable_preload+0x1a54> */
	return 6740ULL;
x86_l_526f:
	/* 0x526f: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5274:
	/* 0x5274: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5277:
	/* 0x5277: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_527c:
	/* 0x527c: jmp    274e <generic_sleepable_preload+0x274e> */
	return 10062ULL;
x86_l_5281:
	/* 0x5281: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5286:
	/* 0x5286: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5289:
	/* 0x5289: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_528e:
	/* 0x528e: jmp    27d0 <generic_sleepable_preload+0x27d0> */
	return 10192ULL;
x86_l_5293:
	/* 0x5293: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5298:
	/* 0x5298: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_529b:
	/* 0x529b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a0:
	/* 0x52a0: jmp    34cb <generic_sleepable_preload+0x34cb> */
	return 13515ULL;
x86_l_52a5:
	/* 0x52a5: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52aa:
	/* 0x52aa: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52ad:
	/* 0x52ad: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b2:
	/* 0x52b2: jmp    354d <generic_sleepable_preload+0x354d> */
	return 13645ULL;
x86_l_52b7:
	/* 0x52b7: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52bc:
	/* 0x52bc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52bf:
	/* 0x52bf: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52c4:
	/* 0x52c4: jmp    4f57 <generic_sleepable_preload+0x4f57> */
	return 20311ULL;
x86_l_52c9:
	/* 0x52c9: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52ce:
	/* 0x52ce: jmp    4fd9 <generic_sleepable_preload+0x4fd9> */
	return 20441ULL;
x86_l_52d3:
	/* 0x52d3: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52d8:
	/* 0x52d8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52db:
	/* 0x52db: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52e0:
	/* 0x52e0: jmp    5065 <generic_sleepable_preload+0x5065> */
	return 20581ULL;
x86_l_52e5:
	/* 0x52e5: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_52ea:
	/* 0x52ea: jmp    5116 <generic_sleepable_preload+0x5116> */
	return 20758ULL;
x86_l_52ef:
	/* 0x52ef: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52f2:
	/* 0x52f2: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_52f7:
	/* 0x52f7: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52fc:
	/* 0x52fc: jmp    19d2 <generic_sleepable_preload+0x19d2> */
	return 6610ULL;
x86_l_5301:
	/* 0x5301: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5304:
	/* 0x5304: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5309:
	/* 0x5309: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_530e:
	/* 0x530e: jmp    1a54 <generic_sleepable_preload+0x1a54> */
	return 6740ULL;
x86_l_5313:
	/* 0x5313: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5316:
	/* 0x5316: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_531b:
	/* 0x531b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5320:
	/* 0x5320: jmp    274e <generic_sleepable_preload+0x274e> */
	return 10062ULL;
x86_l_5325:
	/* 0x5325: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5328:
	/* 0x5328: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_532d:
	/* 0x532d: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5332:
	/* 0x5332: jmp    27d0 <generic_sleepable_preload+0x27d0> */
	return 10192ULL;
x86_l_5337:
	/* 0x5337: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_533a:
	/* 0x533a: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_533f:
	/* 0x533f: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5344:
	/* 0x5344: jmp    34cb <generic_sleepable_preload+0x34cb> */
	return 13515ULL;
x86_l_5349:
	/* 0x5349: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_534c:
	/* 0x534c: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5351:
	/* 0x5351: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5356:
	/* 0x5356: jmp    354d <generic_sleepable_preload+0x354d> */
	return 13645ULL;
x86_l_535b:
	/* 0x535b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_535e:
	/* 0x535e: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5363:
	/* 0x5363: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5368:
	/* 0x5368: jmp    4f57 <generic_sleepable_preload+0x4f57> */
	return 20311ULL;
x86_l_536d:
	/* 0x536d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5370:
	/* 0x5370: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5375:
	/* 0x5375: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_537a:
	/* 0x537a: jmp    5065 <generic_sleepable_preload+0x5065> */
	return 20581ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 18776U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1624ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1627ULL && __x86_pc <= 3177ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3183ULL && __x86_pc <= 4940ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4943ULL && __x86_pc <= 6717ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6720ULL && __x86_pc <= 8493ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8497ULL && __x86_pc <= 10273ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10276ULL && __x86_pc <= 12046ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12049ULL && __x86_pc <= 13804ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13808ULL && __x86_pc <= 15635ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15639ULL && __x86_pc <= 17448ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17451ULL && __x86_pc <= 19280ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19285ULL && __x86_pc <= 20984ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 20989ULL && __x86_pc <= 21370ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

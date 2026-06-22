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
	case 31ULL: goto x86_l_1f;
	case 39ULL: goto x86_l_27;
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
	case 157ULL: goto x86_l_9d;
	case 161ULL: goto x86_l_a1;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 178ULL: goto x86_l_b2;
	case 182ULL: goto x86_l_b6;
	case 187ULL: goto x86_l_bb;
	case 191ULL: goto x86_l_bf;
	case 196ULL: goto x86_l_c4;
	case 200ULL: goto x86_l_c8;
	case 205ULL: goto x86_l_cd;
	case 208ULL: goto x86_l_d0;
	case 213ULL: goto x86_l_d5;
	case 215ULL: goto x86_l_d7;
	case 218ULL: goto x86_l_da;
	case 223ULL: goto x86_l_df;
	case 225ULL: goto x86_l_e1;
	case 228ULL: goto x86_l_e4;
	case 233ULL: goto x86_l_e9;
	case 239ULL: goto x86_l_ef;
	case 242ULL: goto x86_l_f2;
	case 247ULL: goto x86_l_f7;
	case 253ULL: goto x86_l_fd;
	case 256ULL: goto x86_l_100;
	case 261ULL: goto x86_l_105;
	case 267ULL: goto x86_l_10b;
	case 269ULL: goto x86_l_10d;
	case 276ULL: goto x86_l_114;
	case 278ULL: goto x86_l_116;
	case 279ULL: goto x86_l_117;
	case 284ULL: goto x86_l_11c;
	case 286ULL: goto x86_l_11e;
	case 292ULL: goto x86_l_124;
	case 295ULL: goto x86_l_127;
	case 298ULL: goto x86_l_12a;
	case 304ULL: goto x86_l_130;
	case 307ULL: goto x86_l_133;
	case 313ULL: goto x86_l_139;
	case 316ULL: goto x86_l_13c;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 331ULL: goto x86_l_14b;
	case 335ULL: goto x86_l_14f;
	case 340ULL: goto x86_l_154;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 351ULL: goto x86_l_15f;
	case 354ULL: goto x86_l_162;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 369ULL: goto x86_l_171;
	case 372ULL: goto x86_l_174;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 387ULL: goto x86_l_183;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 398ULL: goto x86_l_18e;
	case 404ULL: goto x86_l_194;
	case 407ULL: goto x86_l_197;
	case 410ULL: goto x86_l_19a;
	case 416ULL: goto x86_l_1a0;
	case 419ULL: goto x86_l_1a3;
	case 425ULL: goto x86_l_1a9;
	case 428ULL: goto x86_l_1ac;
	case 434ULL: goto x86_l_1b2;
	case 437ULL: goto x86_l_1b5;
	case 443ULL: goto x86_l_1bb;
	case 447ULL: goto x86_l_1bf;
	case 452ULL: goto x86_l_1c4;
	case 454ULL: goto x86_l_1c6;
	case 460ULL: goto x86_l_1cc;
	case 463ULL: goto x86_l_1cf;
	case 466ULL: goto x86_l_1d2;
	case 472ULL: goto x86_l_1d8;
	case 475ULL: goto x86_l_1db;
	case 481ULL: goto x86_l_1e1;
	case 484ULL: goto x86_l_1e4;
	case 490ULL: goto x86_l_1ea;
	case 493ULL: goto x86_l_1ed;
	case 499ULL: goto x86_l_1f3;
	case 503ULL: goto x86_l_1f7;
	case 508ULL: goto x86_l_1fc;
	case 510ULL: goto x86_l_1fe;
	case 516ULL: goto x86_l_204;
	case 519ULL: goto x86_l_207;
	case 522ULL: goto x86_l_20a;
	case 528ULL: goto x86_l_210;
	case 531ULL: goto x86_l_213;
	case 537ULL: goto x86_l_219;
	case 540ULL: goto x86_l_21c;
	case 546ULL: goto x86_l_222;
	case 549ULL: goto x86_l_225;
	case 555ULL: goto x86_l_22b;
	case 559ULL: goto x86_l_22f;
	case 564ULL: goto x86_l_234;
	case 571ULL: goto x86_l_23b;
	case 578ULL: goto x86_l_242;
	case 584ULL: goto x86_l_248;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 595ULL: goto x86_l_253;
	case 598ULL: goto x86_l_256;
	case 604ULL: goto x86_l_25c;
	case 607ULL: goto x86_l_25f;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 621ULL: goto x86_l_26d;
	case 627ULL: goto x86_l_273;
	case 632ULL: goto x86_l_278;
	case 635ULL: goto x86_l_27b;
	case 641ULL: goto x86_l_281;
	case 644ULL: goto x86_l_284;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 660ULL: goto x86_l_294;
	case 667ULL: goto x86_l_29b;
	case 674ULL: goto x86_l_2a2;
	case 680ULL: goto x86_l_2a8;
	case 682ULL: goto x86_l_2aa;
	case 685ULL: goto x86_l_2ad;
	case 691ULL: goto x86_l_2b3;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 703ULL: goto x86_l_2bf;
	case 709ULL: goto x86_l_2c5;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 728ULL: goto x86_l_2d8;
	case 731ULL: goto x86_l_2db;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 751ULL: goto x86_l_2ef;
	case 756ULL: goto x86_l_2f4;
	case 763ULL: goto x86_l_2fb;
	case 770ULL: goto x86_l_302;
	case 776ULL: goto x86_l_308;
	case 778ULL: goto x86_l_30a;
	case 781ULL: goto x86_l_30d;
	case 787ULL: goto x86_l_313;
	case 790ULL: goto x86_l_316;
	case 796ULL: goto x86_l_31c;
	case 799ULL: goto x86_l_31f;
	case 805ULL: goto x86_l_325;
	case 810ULL: goto x86_l_32a;
	case 813ULL: goto x86_l_32d;
	case 819ULL: goto x86_l_333;
	case 824ULL: goto x86_l_338;
	case 827ULL: goto x86_l_33b;
	case 833ULL: goto x86_l_341;
	case 838ULL: goto x86_l_346;
	case 841ULL: goto x86_l_349;
	case 847ULL: goto x86_l_34f;
	case 852ULL: goto x86_l_354;
	case 859ULL: goto x86_l_35b;
	case 866ULL: goto x86_l_362;
	case 872ULL: goto x86_l_368;
	case 874ULL: goto x86_l_36a;
	case 877ULL: goto x86_l_36d;
	case 883ULL: goto x86_l_373;
	case 886ULL: goto x86_l_376;
	case 892ULL: goto x86_l_37c;
	case 895ULL: goto x86_l_37f;
	case 901ULL: goto x86_l_385;
	case 906ULL: goto x86_l_38a;
	case 909ULL: goto x86_l_38d;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 934ULL: goto x86_l_3a6;
	case 937ULL: goto x86_l_3a9;
	case 943ULL: goto x86_l_3af;
	case 948ULL: goto x86_l_3b4;
	case 955ULL: goto x86_l_3bb;
	case 962ULL: goto x86_l_3c2;
	case 968ULL: goto x86_l_3c8;
	case 970ULL: goto x86_l_3ca;
	case 973ULL: goto x86_l_3cd;
	case 979ULL: goto x86_l_3d3;
	case 982ULL: goto x86_l_3d6;
	case 988ULL: goto x86_l_3dc;
	case 991ULL: goto x86_l_3df;
	case 997ULL: goto x86_l_3e5;
	case 1002ULL: goto x86_l_3ea;
	case 1005ULL: goto x86_l_3ed;
	case 1011ULL: goto x86_l_3f3;
	case 1016ULL: goto x86_l_3f8;
	case 1019ULL: goto x86_l_3fb;
	case 1025ULL: goto x86_l_401;
	case 1030ULL: goto x86_l_406;
	case 1033ULL: goto x86_l_409;
	case 1039ULL: goto x86_l_40f;
	case 1044ULL: goto x86_l_414;
	case 1047ULL: goto x86_l_417;
	case 1053ULL: goto x86_l_41d;
	case 1056ULL: goto x86_l_420;
	case 1062ULL: goto x86_l_426;
	case 1065ULL: goto x86_l_429;
	case 1067ULL: goto x86_l_42b;
	case 1073ULL: goto x86_l_431;
	case 1078ULL: goto x86_l_436;
	case 1081ULL: goto x86_l_439;
	case 1087ULL: goto x86_l_43f;
	case 1092ULL: goto x86_l_444;
	case 1095ULL: goto x86_l_447;
	case 1101ULL: goto x86_l_44d;
	case 1104ULL: goto x86_l_450;
	case 1110ULL: goto x86_l_456;
	case 1112ULL: goto x86_l_458;
	case 1118ULL: goto x86_l_45e;
	case 1123ULL: goto x86_l_463;
	case 1126ULL: goto x86_l_466;
	case 1132ULL: goto x86_l_46c;
	case 1137ULL: goto x86_l_471;
	case 1140ULL: goto x86_l_474;
	case 1146ULL: goto x86_l_47a;
	case 1149ULL: goto x86_l_47d;
	case 1155ULL: goto x86_l_483;
	case 1157ULL: goto x86_l_485;
	case 1163ULL: goto x86_l_48b;
	case 1168ULL: goto x86_l_490;
	case 1171ULL: goto x86_l_493;
	case 1177ULL: goto x86_l_499;
	case 1182ULL: goto x86_l_49e;
	case 1185ULL: goto x86_l_4a1;
	case 1191ULL: goto x86_l_4a7;
	case 1194ULL: goto x86_l_4aa;
	case 1200ULL: goto x86_l_4b0;
	case 1202ULL: goto x86_l_4b2;
	case 1208ULL: goto x86_l_4b8;
	case 1213ULL: goto x86_l_4bd;
	case 1216ULL: goto x86_l_4c0;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1230ULL: goto x86_l_4ce;
	case 1236ULL: goto x86_l_4d4;
	case 1239ULL: goto x86_l_4d7;
	case 1245ULL: goto x86_l_4dd;
	case 1247ULL: goto x86_l_4df;
	case 1253ULL: goto x86_l_4e5;
	case 1256ULL: goto x86_l_4e8;
	case 1261ULL: goto x86_l_4ed;
	case 1267ULL: goto x86_l_4f3;
	case 1272ULL: goto x86_l_4f8;
	case 1274ULL: goto x86_l_4fa;
	case 1280ULL: goto x86_l_500;
	case 1283ULL: goto x86_l_503;
	case 1289ULL: goto x86_l_509;
	case 1293ULL: goto x86_l_50d;
	case 1298ULL: goto x86_l_512;
	case 1300ULL: goto x86_l_514;
	case 1306ULL: goto x86_l_51a;
	case 1309ULL: goto x86_l_51d;
	case 1315ULL: goto x86_l_523;
	case 1319ULL: goto x86_l_527;
	case 1324ULL: goto x86_l_52c;
	case 1326ULL: goto x86_l_52e;
	case 1332ULL: goto x86_l_534;
	case 1335ULL: goto x86_l_537;
	case 1341ULL: goto x86_l_53d;
	case 1345ULL: goto x86_l_541;
	case 1350ULL: goto x86_l_546;
	case 1352ULL: goto x86_l_548;
	case 1358ULL: goto x86_l_54e;
	case 1361ULL: goto x86_l_551;
	case 1367ULL: goto x86_l_557;
	case 1371ULL: goto x86_l_55b;
	case 1376ULL: goto x86_l_560;
	case 1378ULL: goto x86_l_562;
	case 1384ULL: goto x86_l_568;
	case 1387ULL: goto x86_l_56b;
	case 1393ULL: goto x86_l_571;
	case 1397ULL: goto x86_l_575;
	case 1402ULL: goto x86_l_57a;
	case 1405ULL: goto x86_l_57d;
	case 1411ULL: goto x86_l_583;
	case 1419ULL: goto x86_l_58b;
	case 1422ULL: goto x86_l_58e;
	case 1428ULL: goto x86_l_594;
	case 1431ULL: goto x86_l_597;
	case 1434ULL: goto x86_l_59a;
	case 1440ULL: goto x86_l_5a0;
	case 1445ULL: goto x86_l_5a5;
	case 1448ULL: goto x86_l_5a8;
	case 1454ULL: goto x86_l_5ae;
	case 1462ULL: goto x86_l_5b6;
	case 1465ULL: goto x86_l_5b9;
	case 1471ULL: goto x86_l_5bf;
	case 1474ULL: goto x86_l_5c2;
	case 1477ULL: goto x86_l_5c5;
	case 1483ULL: goto x86_l_5cb;
	case 1488ULL: goto x86_l_5d0;
	case 1491ULL: goto x86_l_5d3;
	case 1497ULL: goto x86_l_5d9;
	case 1505ULL: goto x86_l_5e1;
	case 1508ULL: goto x86_l_5e4;
	case 1514ULL: goto x86_l_5ea;
	case 1517ULL: goto x86_l_5ed;
	case 1520ULL: goto x86_l_5f0;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1534ULL: goto x86_l_5fe;
	case 1540ULL: goto x86_l_604;
	case 1548ULL: goto x86_l_60c;
	case 1551ULL: goto x86_l_60f;
	case 1557ULL: goto x86_l_615;
	case 1560ULL: goto x86_l_618;
	case 1563ULL: goto x86_l_61b;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1577ULL: goto x86_l_629;
	case 1583ULL: goto x86_l_62f;
	case 1591ULL: goto x86_l_637;
	case 1594ULL: goto x86_l_63a;
	case 1600ULL: goto x86_l_640;
	case 1603ULL: goto x86_l_643;
	case 1606ULL: goto x86_l_646;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1626ULL: goto x86_l_65a;
	case 1634ULL: goto x86_l_662;
	case 1637ULL: goto x86_l_665;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1651ULL: goto x86_l_673;
	case 1657ULL: goto x86_l_679;
	case 1662ULL: goto x86_l_67e;
	case 1665ULL: goto x86_l_681;
	case 1671ULL: goto x86_l_687;
	case 1679ULL: goto x86_l_68f;
	case 1682ULL: goto x86_l_692;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
	case 1716ULL: goto x86_l_6b4;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1741ULL: goto x86_l_6cd;
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1755ULL: goto x86_l_6db;
	case 1761ULL: goto x86_l_6e1;
	case 1769ULL: goto x86_l_6e9;
	case 1772ULL: goto x86_l_6ec;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_a:
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
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
	/* 0x31: je     10b <generic_sleepable_preload+0x10b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b;
	}
x86_l_37:
	/* 0x37: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_41:
	/* 0x41: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_46:
	/* 0x46: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d:
	/* 0x4d: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_52:
	/* 0x52: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5b:
	/* 0x5b: lea    r12,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f:
	/* 0x5f: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_63:
	/* 0x63: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_68:
	/* 0x68: lea    rbp,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6c:
	/* 0x6c: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_78:
	/* 0x78: lea    r13,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7c:
	/* 0x7c: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_80:
	/* 0x80: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_88:
	/* 0x88: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8c:
	/* 0x8c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_91:
	/* 0x91: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95:
	/* 0x95: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9d:
	/* 0x9d: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a1:
	/* 0xa1: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a6:
	/* 0xa6: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b2:
	/* 0xb2: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b6:
	/* 0xb6: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bb:
	/* 0xbb: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf:
	/* 0xbf: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c4:
	/* 0xc4: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c8:
	/* 0xc8: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cd:
	/* 0xcd: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d0:
	/* 0xd0: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_d5:
	/* 0xd5: jne    11c <generic_sleepable_preload+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11c;
	}
x86_l_d7:
	/* 0xd7: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_da:
	/* 0xda: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_df:
	/* 0xdf: jne    154 <generic_sleepable_preload+0x154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_154;
	}
x86_l_e1:
	/* 0xe1: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e4:
	/* 0xe4: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e9:
	/* 0xe9: jne    18c <generic_sleepable_preload+0x18c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18c;
	}
x86_l_ef:
	/* 0xef: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f2:
	/* 0xf2: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f7:
	/* 0xf7: jne    1c4 <generic_sleepable_preload+0x1c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c4;
	}
x86_l_fd:
	/* 0xfd: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_100:
	/* 0x100: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_105:
	/* 0x105: jne    1fc <generic_sleepable_preload+0x1fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fc;
	}
x86_l_10b:
	/* 0x10b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d:
	/* 0x10d: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_114:
	/* 0x114: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_116:
	/* 0x116: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_117:
	/* 0x117: jmp    355a <generic_sleepable_preload+0x355a> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_11c:
	/* 0x11c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_11e:
	/* 0x11e: js     234 <generic_sleepable_preload+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_234;
	}
x86_l_124:
	/* 0x124: mov    eax,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_127:
	/* 0x127: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12a:
	/* 0x12a: jle    4f8 <generic_sleepable_preload+0x4f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4f8;
	}
x86_l_130:
	/* 0x130: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_133:
	/* 0x133: je     732 <generic_sleepable_preload+0x732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1842ULL;
	}
x86_l_139:
	/* 0x139: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_13c:
	/* 0x13c: je     761 <generic_sleepable_preload+0x761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1889ULL;
	}
x86_l_142:
	/* 0x142: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_145:
	/* 0x145: jne    798 <generic_sleepable_preload+0x798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1944ULL;
	}
x86_l_14b:
	/* 0x14b: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f:
	/* 0x14f: jmp    793 <generic_sleepable_preload+0x793> */
	return 1939ULL;
x86_l_154:
	/* 0x154: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_156:
	/* 0x156: js     294 <generic_sleepable_preload+0x294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_294;
	}
x86_l_15c:
	/* 0x15c: mov    eax,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_15f:
	/* 0x15f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_162:
	/* 0x162: jle    512 <generic_sleepable_preload+0x512> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_512;
	}
x86_l_168:
	/* 0x168: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16b:
	/* 0x16b: je     739 <generic_sleepable_preload+0x739> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1849ULL;
	}
x86_l_171:
	/* 0x171: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_174:
	/* 0x174: je     767 <generic_sleepable_preload+0x767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1895ULL;
	}
x86_l_17a:
	/* 0x17a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d:
	/* 0x17d: jne    a9b <generic_sleepable_preload+0xa9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2715ULL;
	}
x86_l_183:
	/* 0x183: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187:
	/* 0x187: jmp    a96 <generic_sleepable_preload+0xa96> */
	return 2710ULL;
x86_l_18c:
	/* 0x18c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_18e:
	/* 0x18e: js     2f4 <generic_sleepable_preload+0x2f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f4;
	}
x86_l_194:
	/* 0x194: mov    eax,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_197:
	/* 0x197: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19a:
	/* 0x19a: jle    52c <generic_sleepable_preload+0x52c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_52c;
	}
x86_l_1a0:
	/* 0x1a0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a3:
	/* 0x1a3: je     743 <generic_sleepable_preload+0x743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1859ULL;
	}
x86_l_1a9:
	/* 0x1a9: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1ac:
	/* 0x1ac: je     770 <generic_sleepable_preload+0x770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1904ULL;
	}
x86_l_1b2:
	/* 0x1b2: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b5:
	/* 0x1b5: jne    db0 <generic_sleepable_preload+0xdb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3504ULL;
	}
x86_l_1bb:
	/* 0x1bb: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bf:
	/* 0x1bf: jmp    dab <generic_sleepable_preload+0xdab> */
	return 3499ULL;
x86_l_1c4:
	/* 0x1c4: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1c6:
	/* 0x1c6: js     354 <generic_sleepable_preload+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_354;
	}
x86_l_1cc:
	/* 0x1cc: mov    eax,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1cf:
	/* 0x1cf: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d2:
	/* 0x1d2: jle    546 <generic_sleepable_preload+0x546> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_546;
	}
x86_l_1d8:
	/* 0x1d8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1db:
	/* 0x1db: je     74d <generic_sleepable_preload+0x74d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1869ULL;
	}
x86_l_1e1:
	/* 0x1e1: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e4:
	/* 0x1e4: je     779 <generic_sleepable_preload+0x779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1913ULL;
	}
x86_l_1ea:
	/* 0x1ea: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ed:
	/* 0x1ed: jne    10c5 <generic_sleepable_preload+0x10c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4293ULL;
	}
x86_l_1f3:
	/* 0x1f3: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f7:
	/* 0x1f7: jmp    10c0 <generic_sleepable_preload+0x10c0> */
	return 4288ULL;
x86_l_1fc:
	/* 0x1fc: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1fe:
	/* 0x1fe: js     3b4 <generic_sleepable_preload+0x3b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3b4;
	}
x86_l_204:
	/* 0x204: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_207:
	/* 0x207: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20a:
	/* 0x20a: jle    560 <generic_sleepable_preload+0x560> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_560;
	}
x86_l_210:
	/* 0x210: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_213:
	/* 0x213: je     757 <generic_sleepable_preload+0x757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1879ULL;
	}
x86_l_219:
	/* 0x219: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_21c:
	/* 0x21c: je     782 <generic_sleepable_preload+0x782> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1922ULL;
	}
x86_l_222:
	/* 0x222: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_225:
	/* 0x225: jne    13da <generic_sleepable_preload+0x13da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5082ULL;
	}
x86_l_22b:
	/* 0x22b: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f:
	/* 0x22f: jmp    13d5 <generic_sleepable_preload+0x13d5> */
	return 5077ULL;
x86_l_234:
	/* 0x234: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_23b:
	/* 0x23b: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_242:
	/* 0x242: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_248:
	/* 0x248: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24a:
	/* 0x24a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_24d:
	/* 0x24d: jle    414 <generic_sleepable_preload+0x414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_414;
	}
x86_l_253:
	/* 0x253: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_256:
	/* 0x256: jle    57a <generic_sleepable_preload+0x57a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_57a;
	}
x86_l_25c:
	/* 0x25c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_25f:
	/* 0x25f: jle    18e6 <generic_sleepable_preload+0x18e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6374ULL;
	}
x86_l_265:
	/* 0x265: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26a:
	/* 0x26a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_26d:
	/* 0x26d: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6392ULL;
	}
x86_l_273:
	/* 0x273: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_278:
	/* 0x278: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_27b:
	/* 0x27b: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6392ULL;
	}
x86_l_281:
	/* 0x281: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_284:
	/* 0x284: jne    190b <generic_sleepable_preload+0x190b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6411ULL;
	}
x86_l_28a:
	/* 0x28a: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_28f:
	/* 0x28f: jmp    18f8 <generic_sleepable_preload+0x18f8> */
	return 6392ULL;
x86_l_294:
	/* 0x294: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_29b:
	/* 0x29b: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_2a2:
	/* 0x2a2: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2a8:
	/* 0x2a8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aa:
	/* 0x2aa: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2ad:
	/* 0x2ad: jle    444 <generic_sleepable_preload+0x444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_444;
	}
x86_l_2b3:
	/* 0x2b3: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2b6:
	/* 0x2b6: jle    5a5 <generic_sleepable_preload+0x5a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5a5;
	}
x86_l_2bc:
	/* 0x2bc: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2bf:
	/* 0x2bf: jle    1c1a <generic_sleepable_preload+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7194ULL;
	}
x86_l_2c5:
	/* 0x2c5: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ca:
	/* 0x2ca: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2cd:
	/* 0x2cd: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_2d3:
	/* 0x2d3: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d8:
	/* 0x2d8: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2db:
	/* 0x2db: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_2e1:
	/* 0x2e1: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2e6:
	/* 0x2e6: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2e9:
	/* 0x2e9: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_2ef:
	/* 0x2ef: jmp    2019 <generic_sleepable_preload+0x2019> */
	return 8217ULL;
x86_l_2f4:
	/* 0x2f4: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_2fb:
	/* 0x2fb: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_302:
	/* 0x302: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_308:
	/* 0x308: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30a:
	/* 0x30a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_30d:
	/* 0x30d: jle    471 <generic_sleepable_preload+0x471> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_471;
	}
x86_l_313:
	/* 0x313: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_316:
	/* 0x316: jle    5d0 <generic_sleepable_preload+0x5d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5d0;
	}
x86_l_31c:
	/* 0x31c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_31f:
	/* 0x31f: jle    1c39 <generic_sleepable_preload+0x1c39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7225ULL;
	}
x86_l_325:
	/* 0x325: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32a:
	/* 0x32a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_32d:
	/* 0x32d: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_333:
	/* 0x333: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_338:
	/* 0x338: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_33b:
	/* 0x33b: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_341:
	/* 0x341: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_346:
	/* 0x346: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_349:
	/* 0x349: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_34f:
	/* 0x34f: jmp    235d <generic_sleepable_preload+0x235d> */
	return 9053ULL;
x86_l_354:
	/* 0x354: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_35b:
	/* 0x35b: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_362:
	/* 0x362: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_368:
	/* 0x368: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36a:
	/* 0x36a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_36d:
	/* 0x36d: jle    49e <generic_sleepable_preload+0x49e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_49e;
	}
x86_l_373:
	/* 0x373: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_376:
	/* 0x376: jle    5fb <generic_sleepable_preload+0x5fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5fb;
	}
x86_l_37c:
	/* 0x37c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_37f:
	/* 0x37f: jle    1c58 <generic_sleepable_preload+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7256ULL;
	}
x86_l_385:
	/* 0x385: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_38a:
	/* 0x38a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_38d:
	/* 0x38d: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_393:
	/* 0x393: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_398:
	/* 0x398: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_39b:
	/* 0x39b: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_3a1:
	/* 0x3a1: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a6:
	/* 0x3a6: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3a9:
	/* 0x3a9: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_3af:
	/* 0x3af: jmp    26a1 <generic_sleepable_preload+0x26a1> */
	return 9889ULL;
x86_l_3b4:
	/* 0x3b4: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_3bb:
	/* 0x3bb: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_3c2:
	/* 0x3c2: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3c8:
	/* 0x3c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ca:
	/* 0x3ca: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3cd:
	/* 0x3cd: jle    4cb <generic_sleepable_preload+0x4cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4cb;
	}
x86_l_3d3:
	/* 0x3d3: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3d6:
	/* 0x3d6: jle    626 <generic_sleepable_preload+0x626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_626;
	}
x86_l_3dc:
	/* 0x3dc: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3df:
	/* 0x3df: jle    1c77 <generic_sleepable_preload+0x1c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7287ULL;
	}
x86_l_3e5:
	/* 0x3e5: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ea:
	/* 0x3ea: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3ed:
	/* 0x3ed: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_3f3:
	/* 0x3f3: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3f8:
	/* 0x3f8: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3fb:
	/* 0x3fb: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_401:
	/* 0x401: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_406:
	/* 0x406: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_409:
	/* 0x409: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_40f:
	/* 0x40f: jmp    1c9c <generic_sleepable_preload+0x1c9c> */
	return 7324ULL;
x86_l_414:
	/* 0x414: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_417:
	/* 0x417: jg     651 <generic_sleepable_preload+0x651> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_651;
	}
x86_l_41d:
	/* 0x41d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_420:
	/* 0x420: jg     178d <generic_sleepable_preload+0x178d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6029ULL;
	}
x86_l_426:
	/* 0x426: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_429:
	/* 0x429: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_42b:
	/* 0x42b: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6392ULL;
	}
x86_l_431:
	/* 0x431: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_436:
	/* 0x436: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_439:
	/* 0x439: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6392ULL;
	}
x86_l_43f:
	/* 0x43f: jmp    190b <generic_sleepable_preload+0x190b> */
	return 6411ULL;
x86_l_444:
	/* 0x444: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_447:
	/* 0x447: jg     67e <generic_sleepable_preload+0x67e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_67e;
	}
x86_l_44d:
	/* 0x44d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_450:
	/* 0x450: jg     17ae <generic_sleepable_preload+0x17ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6062ULL;
	}
x86_l_456:
	/* 0x456: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_458:
	/* 0x458: je     2003 <generic_sleepable_preload+0x2003> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8195ULL;
	}
x86_l_45e:
	/* 0x45e: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_463:
	/* 0x463: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_466:
	/* 0x466: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_46c:
	/* 0x46c: jmp    2019 <generic_sleepable_preload+0x2019> */
	return 8217ULL;
x86_l_471:
	/* 0x471: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_474:
	/* 0x474: jg     6ab <generic_sleepable_preload+0x6ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6ab;
	}
x86_l_47a:
	/* 0x47a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_47d:
	/* 0x47d: jg     17cf <generic_sleepable_preload+0x17cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6095ULL;
	}
x86_l_483:
	/* 0x483: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_485:
	/* 0x485: je     2347 <generic_sleepable_preload+0x2347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9031ULL;
	}
x86_l_48b:
	/* 0x48b: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_490:
	/* 0x490: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_493:
	/* 0x493: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_499:
	/* 0x499: jmp    235d <generic_sleepable_preload+0x235d> */
	return 9053ULL;
x86_l_49e:
	/* 0x49e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4a1:
	/* 0x4a1: jg     6d8 <generic_sleepable_preload+0x6d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6d8;
	}
x86_l_4a7:
	/* 0x4a7: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4aa:
	/* 0x4aa: jg     17f0 <generic_sleepable_preload+0x17f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6128ULL;
	}
x86_l_4b0:
	/* 0x4b0: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4b2:
	/* 0x4b2: je     268b <generic_sleepable_preload+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9867ULL;
	}
x86_l_4b8:
	/* 0x4b8: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4bd:
	/* 0x4bd: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4c0:
	/* 0x4c0: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_4c6:
	/* 0x4c6: jmp    26a1 <generic_sleepable_preload+0x26a1> */
	return 9889ULL;
x86_l_4cb:
	/* 0x4cb: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4ce:
	/* 0x4ce: jg     705 <generic_sleepable_preload+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1797ULL;
	}
x86_l_4d4:
	/* 0x4d4: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4d7:
	/* 0x4d7: jg     1811 <generic_sleepable_preload+0x1811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6161ULL;
	}
x86_l_4dd:
	/* 0x4dd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4df:
	/* 0x4df: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_4e5:
	/* 0x4e5: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4e8:
	/* 0x4e8: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4ed:
	/* 0x4ed: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_4f3:
	/* 0x4f3: jmp    1c9c <generic_sleepable_preload+0x1c9c> */
	return 7324ULL;
x86_l_4f8:
	/* 0x4f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fa:
	/* 0x4fa: je     78b <generic_sleepable_preload+0x78b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1931ULL;
	}
x86_l_500:
	/* 0x500: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_503:
	/* 0x503: jne    798 <generic_sleepable_preload+0x798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1944ULL;
	}
x86_l_509:
	/* 0x509: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50d:
	/* 0x50d: jmp    793 <generic_sleepable_preload+0x793> */
	return 1939ULL;
x86_l_512:
	/* 0x512: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_514:
	/* 0x514: je     a8e <generic_sleepable_preload+0xa8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2702ULL;
	}
x86_l_51a:
	/* 0x51a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_51d:
	/* 0x51d: jne    a9b <generic_sleepable_preload+0xa9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2715ULL;
	}
x86_l_523:
	/* 0x523: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_527:
	/* 0x527: jmp    a96 <generic_sleepable_preload+0xa96> */
	return 2710ULL;
x86_l_52c:
	/* 0x52c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52e:
	/* 0x52e: je     da3 <generic_sleepable_preload+0xda3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3491ULL;
	}
x86_l_534:
	/* 0x534: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_537:
	/* 0x537: jne    db0 <generic_sleepable_preload+0xdb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3504ULL;
	}
x86_l_53d:
	/* 0x53d: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_541:
	/* 0x541: jmp    dab <generic_sleepable_preload+0xdab> */
	return 3499ULL;
x86_l_546:
	/* 0x546: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_548:
	/* 0x548: je     10b8 <generic_sleepable_preload+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4280ULL;
	}
x86_l_54e:
	/* 0x54e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_551:
	/* 0x551: jne    10c5 <generic_sleepable_preload+0x10c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4293ULL;
	}
x86_l_557:
	/* 0x557: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55b:
	/* 0x55b: jmp    10c0 <generic_sleepable_preload+0x10c0> */
	return 4288ULL;
x86_l_560:
	/* 0x560: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_562:
	/* 0x562: je     13cd <generic_sleepable_preload+0x13cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5069ULL;
	}
x86_l_568:
	/* 0x568: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_56b:
	/* 0x56b: jne    13da <generic_sleepable_preload+0x13da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5082ULL;
	}
x86_l_571:
	/* 0x571: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_575:
	/* 0x575: jmp    13d5 <generic_sleepable_preload+0x13d5> */
	return 5077ULL;
x86_l_57a:
	/* 0x57a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_57d:
	/* 0x57d: jg     16e3 <generic_sleepable_preload+0x16e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5859ULL;
	}
x86_l_583:
	/* 0x583: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_58b:
	/* 0x58b: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58e:
	/* 0x58e: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6392ULL;
	}
x86_l_594:
	/* 0x594: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_597:
	/* 0x597: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_59a:
	/* 0x59a: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6392ULL;
	}
x86_l_5a0:
	/* 0x5a0: jmp    190b <generic_sleepable_preload+0x190b> */
	return 6411ULL;
x86_l_5a5:
	/* 0x5a5: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5a8:
	/* 0x5a8: jg     1705 <generic_sleepable_preload+0x1705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5893ULL;
	}
x86_l_5ae:
	/* 0x5ae: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5b6:
	/* 0x5b6: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b9:
	/* 0x5b9: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_5bf:
	/* 0x5bf: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_5c2:
	/* 0x5c2: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5c5:
	/* 0x5c5: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_5cb:
	/* 0x5cb: jmp    2019 <generic_sleepable_preload+0x2019> */
	return 8217ULL;
x86_l_5d0:
	/* 0x5d0: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5d3:
	/* 0x5d3: jg     1727 <generic_sleepable_preload+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5927ULL;
	}
x86_l_5d9:
	/* 0x5d9: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5e1:
	/* 0x5e1: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e4:
	/* 0x5e4: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_5ea:
	/* 0x5ea: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_5ed:
	/* 0x5ed: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5f0:
	/* 0x5f0: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_5f6:
	/* 0x5f6: jmp    235d <generic_sleepable_preload+0x235d> */
	return 9053ULL;
x86_l_5fb:
	/* 0x5fb: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5fe:
	/* 0x5fe: jg     1749 <generic_sleepable_preload+0x1749> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5961ULL;
	}
x86_l_604:
	/* 0x604: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_60c:
	/* 0x60c: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_60f:
	/* 0x60f: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_615:
	/* 0x615: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_618:
	/* 0x618: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_61b:
	/* 0x61b: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_621:
	/* 0x621: jmp    26a1 <generic_sleepable_preload+0x26a1> */
	return 9889ULL;
x86_l_626:
	/* 0x626: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_629:
	/* 0x629: jg     176b <generic_sleepable_preload+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5995ULL;
	}
x86_l_62f:
	/* 0x62f: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_637:
	/* 0x637: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_63a:
	/* 0x63a: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_640:
	/* 0x640: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_643:
	/* 0x643: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_646:
	/* 0x646: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_64c:
	/* 0x64c: jmp    1c9c <generic_sleepable_preload+0x1c9c> */
	return 7324ULL;
x86_l_651:
	/* 0x651: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_654:
	/* 0x654: jg     1832 <generic_sleepable_preload+0x1832> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6194ULL;
	}
x86_l_65a:
	/* 0x65a: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_662:
	/* 0x662: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_665:
	/* 0x665: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6392ULL;
	}
x86_l_66b:
	/* 0x66b: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_670:
	/* 0x670: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_673:
	/* 0x673: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6392ULL;
	}
x86_l_679:
	/* 0x679: jmp    190b <generic_sleepable_preload+0x190b> */
	return 6411ULL;
x86_l_67e:
	/* 0x67e: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_681:
	/* 0x681: jg     1856 <generic_sleepable_preload+0x1856> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6230ULL;
	}
x86_l_687:
	/* 0x687: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_68f:
	/* 0x68f: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_692:
	/* 0x692: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_698:
	/* 0x698: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_69d:
	/* 0x69d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6a0:
	/* 0x6a0: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_6a6:
	/* 0x6a6: jmp    2019 <generic_sleepable_preload+0x2019> */
	return 8217ULL;
x86_l_6ab:
	/* 0x6ab: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6ae:
	/* 0x6ae: jg     187a <generic_sleepable_preload+0x187a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6266ULL;
	}
x86_l_6b4:
	/* 0x6b4: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6bc:
	/* 0x6bc: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_6bf:
	/* 0x6bf: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_6c5:
	/* 0x6c5: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6ca:
	/* 0x6ca: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6cd:
	/* 0x6cd: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_6d3:
	/* 0x6d3: jmp    235d <generic_sleepable_preload+0x235d> */
	return 9053ULL;
x86_l_6d8:
	/* 0x6d8: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6db:
	/* 0x6db: jg     189e <generic_sleepable_preload+0x189e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6302ULL;
	}
x86_l_6e1:
	/* 0x6e1: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6e9:
	/* 0x6e9: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_6ec:
	/* 0x6ec: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
	return 1778ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1786ULL: goto x86_l_6fa;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1800ULL: goto x86_l_708;
	case 1806ULL: goto x86_l_70e;
	case 1814ULL: goto x86_l_716;
	case 1817ULL: goto x86_l_719;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1831ULL: goto x86_l_727;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1847ULL: goto x86_l_737;
	case 1849ULL: goto x86_l_739;
	case 1854ULL: goto x86_l_73e;
	case 1859ULL: goto x86_l_743;
	case 1864ULL: goto x86_l_748;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1893ULL: goto x86_l_765;
	case 1895ULL: goto x86_l_767;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1917ULL: goto x86_l_77d;
	case 1922ULL: goto x86_l_782;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1955ULL: goto x86_l_7a3;
	case 1958ULL: goto x86_l_7a6;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1973ULL: goto x86_l_7b5;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1993ULL: goto x86_l_7c9;
	case 1998ULL: goto x86_l_7ce;
	case 2000ULL: goto x86_l_7d0;
	case 2002ULL: goto x86_l_7d2;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2019ULL: goto x86_l_7e3;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2054ULL: goto x86_l_806;
	case 2059ULL: goto x86_l_80b;
	case 2064ULL: goto x86_l_810;
	case 2066ULL: goto x86_l_812;
	case 2068ULL: goto x86_l_814;
	case 2074ULL: goto x86_l_81a;
	case 2082ULL: goto x86_l_822;
	case 2088ULL: goto x86_l_828;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2104ULL: goto x86_l_838;
	case 2112ULL: goto x86_l_840;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2149ULL: goto x86_l_865;
	case 2157ULL: goto x86_l_86d;
	case 2163ULL: goto x86_l_873;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2187ULL: goto x86_l_88b;
	case 2189ULL: goto x86_l_88d;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2209ULL: goto x86_l_8a1;
	case 2214ULL: goto x86_l_8a6;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2224ULL: goto x86_l_8b0;
	case 2232ULL: goto x86_l_8b8;
	case 2238ULL: goto x86_l_8be;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2262ULL: goto x86_l_8d6;
	case 2264ULL: goto x86_l_8d8;
	case 2269ULL: goto x86_l_8dd;
	case 2274ULL: goto x86_l_8e2;
	case 2279ULL: goto x86_l_8e7;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2291ULL: goto x86_l_8f3;
	case 2293ULL: goto x86_l_8f5;
	case 2299ULL: goto x86_l_8fb;
	case 2307ULL: goto x86_l_903;
	case 2313ULL: goto x86_l_909;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2337ULL: goto x86_l_921;
	case 2339ULL: goto x86_l_923;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2354ULL: goto x86_l_932;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2366ULL: goto x86_l_93e;
	case 2368ULL: goto x86_l_940;
	case 2374ULL: goto x86_l_946;
	case 2382ULL: goto x86_l_94e;
	case 2388ULL: goto x86_l_954;
	case 2394ULL: goto x86_l_95a;
	case 2399ULL: goto x86_l_95f;
	case 2404ULL: goto x86_l_964;
	case 2412ULL: goto x86_l_96c;
	case 2414ULL: goto x86_l_96e;
	case 2419ULL: goto x86_l_973;
	case 2424ULL: goto x86_l_978;
	case 2429ULL: goto x86_l_97d;
	case 2434ULL: goto x86_l_982;
	case 2439ULL: goto x86_l_987;
	case 2441ULL: goto x86_l_989;
	case 2443ULL: goto x86_l_98b;
	case 2449ULL: goto x86_l_991;
	case 2457ULL: goto x86_l_999;
	case 2463ULL: goto x86_l_99f;
	case 2469ULL: goto x86_l_9a5;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2487ULL: goto x86_l_9b7;
	case 2489ULL: goto x86_l_9b9;
	case 2494ULL: goto x86_l_9be;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2516ULL: goto x86_l_9d4;
	case 2518ULL: goto x86_l_9d6;
	case 2524ULL: goto x86_l_9dc;
	case 2532ULL: goto x86_l_9e4;
	case 2538ULL: goto x86_l_9ea;
	case 2544ULL: goto x86_l_9f0;
	case 2549ULL: goto x86_l_9f5;
	case 2554ULL: goto x86_l_9fa;
	case 2562ULL: goto x86_l_a02;
	case 2564ULL: goto x86_l_a04;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2589ULL: goto x86_l_a1d;
	case 2591ULL: goto x86_l_a1f;
	case 2593ULL: goto x86_l_a21;
	case 2599ULL: goto x86_l_a27;
	case 2607ULL: goto x86_l_a2f;
	case 2609ULL: goto x86_l_a31;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2633ULL: goto x86_l_a49;
	case 2635ULL: goto x86_l_a4b;
	case 2640ULL: goto x86_l_a50;
	case 2645ULL: goto x86_l_a55;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2662ULL: goto x86_l_a66;
	case 2664ULL: goto x86_l_a68;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2676ULL: goto x86_l_a74;
	case 2684ULL: goto x86_l_a7c;
	case 2689ULL: goto x86_l_a81;
	case 2697ULL: goto x86_l_a89;
	case 2702ULL: goto x86_l_a8e;
	case 2707ULL: goto x86_l_a93;
	case 2710ULL: goto x86_l_a96;
	case 2715ULL: goto x86_l_a9b;
	case 2723ULL: goto x86_l_aa3;
	case 2729ULL: goto x86_l_aa9;
	case 2735ULL: goto x86_l_aaf;
	case 2738ULL: goto x86_l_ab2;
	case 2743ULL: goto x86_l_ab7;
	case 2751ULL: goto x86_l_abf;
	case 2753ULL: goto x86_l_ac1;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2780ULL: goto x86_l_adc;
	case 2782ULL: goto x86_l_ade;
	case 2788ULL: goto x86_l_ae4;
	case 2796ULL: goto x86_l_aec;
	case 2802ULL: goto x86_l_af2;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2826ULL: goto x86_l_b0a;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2855ULL: goto x86_l_b27;
	case 2857ULL: goto x86_l_b29;
	case 2863ULL: goto x86_l_b2f;
	case 2871ULL: goto x86_l_b37;
	case 2877ULL: goto x86_l_b3d;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2901ULL: goto x86_l_b55;
	case 2903ULL: goto x86_l_b57;
	case 2908ULL: goto x86_l_b5c;
	case 2913ULL: goto x86_l_b61;
	case 2918ULL: goto x86_l_b66;
	case 2923ULL: goto x86_l_b6b;
	case 2928ULL: goto x86_l_b70;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2938ULL: goto x86_l_b7a;
	case 2946ULL: goto x86_l_b82;
	case 2952ULL: goto x86_l_b88;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2976ULL: goto x86_l_ba0;
	case 2978ULL: goto x86_l_ba2;
	case 2983ULL: goto x86_l_ba7;
	case 2988ULL: goto x86_l_bac;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3003ULL: goto x86_l_bbb;
	case 3005ULL: goto x86_l_bbd;
	case 3007ULL: goto x86_l_bbf;
	case 3013ULL: goto x86_l_bc5;
	case 3021ULL: goto x86_l_bcd;
	case 3027ULL: goto x86_l_bd3;
	case 3033ULL: goto x86_l_bd9;
	case 3038ULL: goto x86_l_bde;
	case 3043ULL: goto x86_l_be3;
	case 3051ULL: goto x86_l_beb;
	case 3053ULL: goto x86_l_bed;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3068ULL: goto x86_l_bfc;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3080ULL: goto x86_l_c08;
	case 3082ULL: goto x86_l_c0a;
	case 3088ULL: goto x86_l_c10;
	case 3096ULL: goto x86_l_c18;
	case 3102ULL: goto x86_l_c1e;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3118ULL: goto x86_l_c2e;
	case 3126ULL: goto x86_l_c36;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3153ULL: goto x86_l_c51;
	case 3155ULL: goto x86_l_c53;
	case 3157ULL: goto x86_l_c55;
	case 3163ULL: goto x86_l_c5b;
	case 3171ULL: goto x86_l_c63;
	case 3177ULL: goto x86_l_c69;
	case 3183ULL: goto x86_l_c6f;
	case 3188ULL: goto x86_l_c74;
	case 3193ULL: goto x86_l_c79;
	case 3201ULL: goto x86_l_c81;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3218ULL: goto x86_l_c92;
	case 3223ULL: goto x86_l_c97;
	case 3228ULL: goto x86_l_c9c;
	case 3230ULL: goto x86_l_c9e;
	case 3232ULL: goto x86_l_ca0;
	case 3238ULL: goto x86_l_ca6;
	case 3246ULL: goto x86_l_cae;
	case 3252ULL: goto x86_l_cb4;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3268ULL: goto x86_l_cc4;
	case 3276ULL: goto x86_l_ccc;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3305ULL: goto x86_l_ce9;
	case 3307ULL: goto x86_l_ceb;
	case 3313ULL: goto x86_l_cf1;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3333ULL: goto x86_l_d05;
	case 3338ULL: goto x86_l_d0a;
	case 3343ULL: goto x86_l_d0f;
	case 3351ULL: goto x86_l_d17;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3380ULL: goto x86_l_d34;
	case 3382ULL: goto x86_l_d36;
	case 3388ULL: goto x86_l_d3c;
	case 3396ULL: goto x86_l_d44;
	case 3398ULL: goto x86_l_d46;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3414ULL: goto x86_l_d56;
	case 3422ULL: goto x86_l_d5e;
	case 3424ULL: goto x86_l_d60;
	case 3429ULL: goto x86_l_d65;
	case 3434ULL: goto x86_l_d6a;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3449ULL: goto x86_l_d79;
	case 3451ULL: goto x86_l_d7b;
	case 3453ULL: goto x86_l_d7d;
	case 3459ULL: goto x86_l_d83;
	case 3461ULL: goto x86_l_d85;
	case 3465ULL: goto x86_l_d89;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3496ULL: goto x86_l_da8;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3512ULL: goto x86_l_db8;
	case 3518ULL: goto x86_l_dbe;
	case 3524ULL: goto x86_l_dc4;
	case 3527ULL: goto x86_l_dc7;
	case 3532ULL: goto x86_l_dcc;
	case 3540ULL: goto x86_l_dd4;
	case 3542ULL: goto x86_l_dd6;
	case 3547ULL: goto x86_l_ddb;
	case 3552ULL: goto x86_l_de0;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3569ULL: goto x86_l_df1;
	case 3571ULL: goto x86_l_df3;
	case 3577ULL: goto x86_l_df9;
	case 3585ULL: goto x86_l_e01;
	case 3591ULL: goto x86_l_e07;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3615ULL: goto x86_l_e1f;
	case 3617ULL: goto x86_l_e21;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3642ULL: goto x86_l_e3a;
	case 3644ULL: goto x86_l_e3c;
	case 3646ULL: goto x86_l_e3e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6f2:
	/* 0x6f2: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6f7:
	/* 0x6f7: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6fa:
	/* 0x6fa: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_700:
	/* 0x700: jmp    26a1 <generic_sleepable_preload+0x26a1> */
	return 9889ULL;
x86_l_705:
	/* 0x705: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_708:
	/* 0x708: jg     18c2 <generic_sleepable_preload+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6338ULL;
	}
x86_l_70e:
	/* 0x70e: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_716:
	/* 0x716: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_719:
	/* 0x719: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_71f:
	/* 0x71f: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_724:
	/* 0x724: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_727:
	/* 0x727: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7305ULL;
	}
x86_l_72d:
	/* 0x72d: jmp    1c9c <generic_sleepable_preload+0x1c9c> */
	return 7324ULL;
x86_l_732:
	/* 0x732: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_737:
	/* 0x737: jmp    790 <generic_sleepable_preload+0x790> */
	goto x86_l_790;
x86_l_739:
	/* 0x739: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_73e:
	/* 0x73e: jmp    a93 <generic_sleepable_preload+0xa93> */
	goto x86_l_a93;
x86_l_743:
	/* 0x743: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_748:
	/* 0x748: jmp    da8 <generic_sleepable_preload+0xda8> */
	goto x86_l_da8;
x86_l_74d:
	/* 0x74d: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_752:
	/* 0x752: jmp    10bd <generic_sleepable_preload+0x10bd> */
	return 4285ULL;
x86_l_757:
	/* 0x757: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_75c:
	/* 0x75c: jmp    13d2 <generic_sleepable_preload+0x13d2> */
	return 5074ULL;
x86_l_761:
	/* 0x761: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_765:
	/* 0x765: jmp    793 <generic_sleepable_preload+0x793> */
	goto x86_l_793;
x86_l_767:
	/* 0x767: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76b:
	/* 0x76b: jmp    a96 <generic_sleepable_preload+0xa96> */
	goto x86_l_a96;
x86_l_770:
	/* 0x770: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_774:
	/* 0x774: jmp    dab <generic_sleepable_preload+0xdab> */
	goto x86_l_dab;
x86_l_779:
	/* 0x779: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77d:
	/* 0x77d: jmp    10c0 <generic_sleepable_preload+0x10c0> */
	return 4288ULL;
x86_l_782:
	/* 0x782: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_786:
	/* 0x786: jmp    13d5 <generic_sleepable_preload+0x13d5> */
	return 5077ULL;
x86_l_78b:
	/* 0x78b: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_790:
	/* 0x790: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_793:
	/* 0x793: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_798:
	/* 0x798: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_79d:
	/* 0x79d: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_7a3:
	/* 0x7a3: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7a6:
	/* 0x7a6: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_7a9:
	/* 0x7a9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ae:
	/* 0x7ae: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_7b3:
	/* 0x7b3: je     7d8 <generic_sleepable_preload+0x7d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d8;
	}
x86_l_7b5:
	/* 0x7b5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ba:
	/* 0x7ba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_7bf:
	/* 0x7bf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7c4:
	/* 0x7c4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c9:
	/* 0x7c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ce:
	/* 0x7ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d0:
	/* 0x7d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7d2:
	/* 0x7d2: js     a81 <generic_sleepable_preload+0xa81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a81;
	}
x86_l_7d8:
	/* 0x7d8: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_7dd:
	/* 0x7dd: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_7e3:
	/* 0x7e3: mov    ecx,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7e6:
	/* 0x7e6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7eb:
	/* 0x7eb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7f0:
	/* 0x7f0: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_7f5:
	/* 0x7f5: je     81a <generic_sleepable_preload+0x81a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_81a;
	}
x86_l_7f7:
	/* 0x7f7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7fc:
	/* 0x7fc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_801:
	/* 0x801: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_806:
	/* 0x806: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_80b:
	/* 0x80b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_810:
	/* 0x810: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_812:
	/* 0x812: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_814:
	/* 0x814: js     1fae <generic_sleepable_preload+0x1fae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8110ULL;
	}
x86_l_81a:
	/* 0x81a: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_822:
	/* 0x822: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_828:
	/* 0x828: mov    ecx,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_82e:
	/* 0x82e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_833:
	/* 0x833: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_838:
	/* 0x838: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_840:
	/* 0x840: je     865 <generic_sleepable_preload+0x865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_865;
	}
x86_l_842:
	/* 0x842: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_847:
	/* 0x847: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_84c:
	/* 0x84c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_851:
	/* 0x851: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x85f: js     29cf <generic_sleepable_preload+0x29cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10703ULL;
	}
x86_l_865:
	/* 0x865: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_86d:
	/* 0x86d: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_873:
	/* 0x873: mov    ecx,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_879:
	/* 0x879: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_87e:
	/* 0x87e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_883:
	/* 0x883: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_88b:
	/* 0x88b: je     8b0 <generic_sleepable_preload+0x8b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8b0;
	}
x86_l_88d:
	/* 0x88d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_892:
	/* 0x892: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_897:
	/* 0x897: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_89c:
	/* 0x89c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a1:
	/* 0x8a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8a6:
	/* 0x8a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a8:
	/* 0x8a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8aa:
	/* 0x8aa: js     2a4b <generic_sleepable_preload+0x2a4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10827ULL;
	}
x86_l_8b0:
	/* 0x8b0: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_8b8:
	/* 0x8b8: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_8be:
	/* 0x8be: mov    ecx,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8c4:
	/* 0x8c4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8c9:
	/* 0x8c9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ce:
	/* 0x8ce: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_8d6:
	/* 0x8d6: je     8fb <generic_sleepable_preload+0x8fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8fb;
	}
x86_l_8d8:
	/* 0x8d8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8dd:
	/* 0x8dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8e2:
	/* 0x8e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8e7:
	/* 0x8e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ec:
	/* 0x8ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8f1:
	/* 0x8f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f3:
	/* 0x8f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8f5:
	/* 0x8f5: js     2ac7 <generic_sleepable_preload+0x2ac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10951ULL;
	}
x86_l_8fb:
	/* 0x8fb: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_903:
	/* 0x903: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_909:
	/* 0x909: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_90f:
	/* 0x90f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_914:
	/* 0x914: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_919:
	/* 0x919: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_921:
	/* 0x921: je     946 <generic_sleepable_preload+0x946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_946;
	}
x86_l_923:
	/* 0x923: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_928:
	/* 0x928: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_92d:
	/* 0x92d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_932:
	/* 0x932: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_937:
	/* 0x937: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_93c:
	/* 0x93c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93e:
	/* 0x93e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_940:
	/* 0x940: js     2b43 <generic_sleepable_preload+0x2b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11075ULL;
	}
x86_l_946:
	/* 0x946: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_94e:
	/* 0x94e: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_954:
	/* 0x954: mov    ecx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_95a:
	/* 0x95a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_95f:
	/* 0x95f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_964:
	/* 0x964: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_96c:
	/* 0x96c: je     991 <generic_sleepable_preload+0x991> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_991;
	}
x86_l_96e:
	/* 0x96e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_973:
	/* 0x973: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_978:
	/* 0x978: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_97d:
	/* 0x97d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_982:
	/* 0x982: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_987:
	/* 0x987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_989:
	/* 0x989: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_98b:
	/* 0x98b: js     2bbc <generic_sleepable_preload+0x2bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11196ULL;
	}
x86_l_991:
	/* 0x991: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_999:
	/* 0x999: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_99f:
	/* 0x99f: mov    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9a5:
	/* 0x9a5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9aa:
	/* 0x9aa: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9af:
	/* 0x9af: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_9b7:
	/* 0x9b7: je     9dc <generic_sleepable_preload+0x9dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9dc;
	}
x86_l_9b9:
	/* 0x9b9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9be:
	/* 0x9be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9c3:
	/* 0x9c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9c8:
	/* 0x9c8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9cd:
	/* 0x9cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d2:
	/* 0x9d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d4:
	/* 0x9d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9d6:
	/* 0x9d6: js     33b6 <generic_sleepable_preload+0x33b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13238ULL;
	}
x86_l_9dc:
	/* 0x9dc: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_9e4:
	/* 0x9e4: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_9ea:
	/* 0x9ea: mov    ecx,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9f0:
	/* 0x9f0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9f5:
	/* 0x9f5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9fa:
	/* 0x9fa: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_a02:
	/* 0xa02: je     a27 <generic_sleepable_preload+0xa27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a27;
	}
x86_l_a04:
	/* 0xa04: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a09:
	/* 0xa09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a0e:
	/* 0xa0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a13:
	/* 0xa13: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a18:
	/* 0xa18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a1d:
	/* 0xa1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1f:
	/* 0xa1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a21:
	/* 0xa21: js     34aa <generic_sleepable_preload+0x34aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13482ULL;
	}
x86_l_a27:
	/* 0xa27: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_a2f:
	/* 0xa2f: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_a31:
	/* 0xa31: mov    ecx,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a37:
	/* 0xa37: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a3c:
	/* 0xa3c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a41:
	/* 0xa41: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_a49:
	/* 0xa49: je     a6e <generic_sleepable_preload+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_a4b:
	/* 0xa4b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a50:
	/* 0xa50: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a55:
	/* 0xa55: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a5a:
	/* 0xa5a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a5f:
	/* 0xa5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a64:
	/* 0xa64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a66:
	/* 0xa66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a68:
	/* 0xa68: js     3526 <generic_sleepable_preload+0x3526> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13606ULL;
	}
x86_l_a6e:
	/* 0xa6e: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_a70:
	/* 0xa70: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a74:
	/* 0xa74: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a7c:
	/* 0xa7c: jmp    2bcc <generic_sleepable_preload+0x2bcc> */
	return 11212ULL;
x86_l_a81:
	/* 0xa81: mov    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_a89:
	/* 0xa89: jmp    2bc4 <generic_sleepable_preload+0x2bc4> */
	return 11204ULL;
x86_l_a8e:
	/* 0xa8e: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a93:
	/* 0xa93: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a96:
	/* 0xa96: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a9b:
	/* 0xa9b: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_aa3:
	/* 0xaa3: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_aa9:
	/* 0xaa9: mov    eax,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_aaf:
	/* 0xaaf: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ab2:
	/* 0xab2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ab7:
	/* 0xab7: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_abf:
	/* 0xabf: je     ae4 <generic_sleepable_preload+0xae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ae4;
	}
x86_l_ac1:
	/* 0xac1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac6:
	/* 0xac6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_acb:
	/* 0xacb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ad0:
	/* 0xad0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad5:
	/* 0xad5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ada:
	/* 0xada: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_adc:
	/* 0xadc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ade:
	/* 0xade: js     d96 <generic_sleepable_preload+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_d96;
	}
x86_l_ae4:
	/* 0xae4: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_aec:
	/* 0xaec: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_af2:
	/* 0xaf2: mov    ecx,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_af8:
	/* 0xaf8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_afd:
	/* 0xafd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b02:
	/* 0xb02: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_b0a:
	/* 0xb0a: je     b2f <generic_sleepable_preload+0xb2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b2f;
	}
x86_l_b0c:
	/* 0xb0c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b11:
	/* 0xb11: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b16:
	/* 0xb16: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b1b:
	/* 0xb1b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b20:
	/* 0xb20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b25:
	/* 0xb25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b27:
	/* 0xb27: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b29:
	/* 0xb29: js     1fbb <generic_sleepable_preload+0x1fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8123ULL;
	}
x86_l_b2f:
	/* 0xb2f: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_b37:
	/* 0xb37: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_b3d:
	/* 0xb3d: mov    ecx,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b43:
	/* 0xb43: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b48:
	/* 0xb48: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b4d:
	/* 0xb4d: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_b55:
	/* 0xb55: je     b7a <generic_sleepable_preload+0xb7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7a;
	}
x86_l_b57:
	/* 0xb57: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b5c:
	/* 0xb5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b61:
	/* 0xb61: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b66:
	/* 0xb66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b6b:
	/* 0xb6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b70:
	/* 0xb70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b72:
	/* 0xb72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b74:
	/* 0xb74: js     29dc <generic_sleepable_preload+0x29dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10716ULL;
	}
x86_l_b7a:
	/* 0xb7a: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_b82:
	/* 0xb82: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_b88:
	/* 0xb88: mov    ecx,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_b8e:
	/* 0xb8e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b93:
	/* 0xb93: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b98:
	/* 0xb98: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_ba0:
	/* 0xba0: je     bc5 <generic_sleepable_preload+0xbc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc5;
	}
x86_l_ba2:
	/* 0xba2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba7:
	/* 0xba7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bac:
	/* 0xbac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bb1:
	/* 0xbb1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb6:
	/* 0xbb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bbb:
	/* 0xbbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbd:
	/* 0xbbd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bbf:
	/* 0xbbf: js     2a58 <generic_sleepable_preload+0x2a58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10840ULL;
	}
x86_l_bc5:
	/* 0xbc5: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_bcd:
	/* 0xbcd: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_bd3:
	/* 0xbd3: mov    ecx,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_bd9:
	/* 0xbd9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_bde:
	/* 0xbde: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be3:
	/* 0xbe3: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_beb:
	/* 0xbeb: je     c10 <generic_sleepable_preload+0xc10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c10;
	}
x86_l_bed:
	/* 0xbed: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf2:
	/* 0xbf2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bf7:
	/* 0xbf7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bfc:
	/* 0xbfc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c01:
	/* 0xc01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c06:
	/* 0xc06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c08:
	/* 0xc08: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c0a:
	/* 0xc0a: js     2ad4 <generic_sleepable_preload+0x2ad4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10964ULL;
	}
x86_l_c10:
	/* 0xc10: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_c18:
	/* 0xc18: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_c1e:
	/* 0xc1e: mov    ecx,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_c24:
	/* 0xc24: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c29:
	/* 0xc29: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2e:
	/* 0xc2e: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_c36:
	/* 0xc36: je     c5b <generic_sleepable_preload+0xc5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c5b;
	}
x86_l_c38:
	/* 0xc38: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3d:
	/* 0xc3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c42:
	/* 0xc42: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c47:
	/* 0xc47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c4c:
	/* 0xc4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c51:
	/* 0xc51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c53:
	/* 0xc53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c55:
	/* 0xc55: js     2b4d <generic_sleepable_preload+0x2b4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11085ULL;
	}
x86_l_c5b:
	/* 0xc5b: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_c63:
	/* 0xc63: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_c69:
	/* 0xc69: mov    ecx,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_c6f:
	/* 0xc6f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c74:
	/* 0xc74: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c79:
	/* 0xc79: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_c81:
	/* 0xc81: je     ca6 <generic_sleepable_preload+0xca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ca6;
	}
x86_l_c83:
	/* 0xc83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c88:
	/* 0xc88: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c8d:
	/* 0xc8d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c92:
	/* 0xc92: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c97:
	/* 0xc97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c9c:
	/* 0xc9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9e:
	/* 0xc9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ca0:
	/* 0xca0: js     2c89 <generic_sleepable_preload+0x2c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11401ULL;
	}
x86_l_ca6:
	/* 0xca6: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_cae:
	/* 0xcae: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_cb4:
	/* 0xcb4: mov    ecx,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_cba:
	/* 0xcba: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cbf:
	/* 0xcbf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc4:
	/* 0xcc4: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_ccc:
	/* 0xccc: je     cf1 <generic_sleepable_preload+0xcf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf1;
	}
x86_l_cce:
	/* 0xcce: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd3:
	/* 0xcd3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_cd8:
	/* 0xcd8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_cdd:
	/* 0xcdd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce2:
	/* 0xce2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ce7:
	/* 0xce7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce9:
	/* 0xce9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ceb:
	/* 0xceb: js     33cb <generic_sleepable_preload+0x33cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13259ULL;
	}
x86_l_cf1:
	/* 0xcf1: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_cf9:
	/* 0xcf9: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_cff:
	/* 0xcff: mov    ecx,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_d05:
	/* 0xd05: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d0a:
	/* 0xd0a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d0f:
	/* 0xd0f: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_d17:
	/* 0xd17: je     d3c <generic_sleepable_preload+0xd3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d3c;
	}
x86_l_d19:
	/* 0xd19: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1e:
	/* 0xd1e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d23:
	/* 0xd23: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d28:
	/* 0xd28: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0xd36: js     34b7 <generic_sleepable_preload+0x34b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13495ULL;
	}
x86_l_d3c:
	/* 0xd3c: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_d44:
	/* 0xd44: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_d46:
	/* 0xd46: mov    ecx,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_d4c:
	/* 0xd4c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d51:
	/* 0xd51: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d56:
	/* 0xd56: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_d5e:
	/* 0xd5e: je     d83 <generic_sleepable_preload+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d83;
	}
x86_l_d60:
	/* 0xd60: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d65:
	/* 0xd65: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d6a:
	/* 0xd6a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d6f:
	/* 0xd6f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d74:
	/* 0xd74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d79:
	/* 0xd79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7b:
	/* 0xd7b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d7d:
	/* 0xd7d: js     3533 <generic_sleepable_preload+0x3533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13619ULL;
	}
x86_l_d83:
	/* 0xd83: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_d85:
	/* 0xd85: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d89:
	/* 0xd89: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_d91:
	/* 0xd91: jmp    2c99 <generic_sleepable_preload+0x2c99> */
	return 11417ULL;
x86_l_d96:
	/* 0xd96: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_d9e:
	/* 0xd9e: jmp    2c91 <generic_sleepable_preload+0x2c91> */
	return 11409ULL;
x86_l_da3:
	/* 0xda3: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_da8:
	/* 0xda8: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dab:
	/* 0xdab: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db0:
	/* 0xdb0: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_db8:
	/* 0xdb8: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4248ULL;
	}
x86_l_dbe:
	/* 0xdbe: mov    eax,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_dc4:
	/* 0xdc4: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dc7:
	/* 0xdc7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dcc:
	/* 0xdcc: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_dd4:
	/* 0xdd4: je     df9 <generic_sleepable_preload+0xdf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df9;
	}
x86_l_dd6:
	/* 0xdd6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ddb:
	/* 0xddb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_de0:
	/* 0xde0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_de5:
	/* 0xde5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dea:
	/* 0xdea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_def:
	/* 0xdef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df1:
	/* 0xdf1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_df3:
	/* 0xdf3: js     10ab <generic_sleepable_preload+0x10ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4267ULL;
	}
x86_l_df9:
	/* 0xdf9: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_e01:
	/* 0xe01: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4248ULL;
	}
x86_l_e07:
	/* 0xe07: mov    ecx,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_e0d:
	/* 0xe0d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e12:
	/* 0xe12: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e17:
	/* 0xe17: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_e1f:
	/* 0xe1f: je     e44 <generic_sleepable_preload+0xe44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3652ULL;
	}
x86_l_e21:
	/* 0xe21: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e26:
	/* 0xe26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e2b:
	/* 0xe2b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e30:
	/* 0xe30: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e35:
	/* 0xe35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e3a:
	/* 0xe3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3c:
	/* 0xe3c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e3e:
	/* 0xe3e: js     1fc8 <generic_sleepable_preload+0x1fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8136ULL;
	}
	return 3652ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3652ULL: goto x86_l_e44;
	case 3660ULL: goto x86_l_e4c;
	case 3666ULL: goto x86_l_e52;
	case 3672ULL: goto x86_l_e58;
	case 3677ULL: goto x86_l_e5d;
	case 3682ULL: goto x86_l_e62;
	case 3690ULL: goto x86_l_e6a;
	case 3692ULL: goto x86_l_e6c;
	case 3697ULL: goto x86_l_e71;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3719ULL: goto x86_l_e87;
	case 3721ULL: goto x86_l_e89;
	case 3727ULL: goto x86_l_e8f;
	case 3735ULL: goto x86_l_e97;
	case 3741ULL: goto x86_l_e9d;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3765ULL: goto x86_l_eb5;
	case 3767ULL: goto x86_l_eb7;
	case 3772ULL: goto x86_l_ebc;
	case 3777ULL: goto x86_l_ec1;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3794ULL: goto x86_l_ed2;
	case 3796ULL: goto x86_l_ed4;
	case 3802ULL: goto x86_l_eda;
	case 3810ULL: goto x86_l_ee2;
	case 3816ULL: goto x86_l_ee8;
	case 3822ULL: goto x86_l_eee;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3840ULL: goto x86_l_f00;
	case 3842ULL: goto x86_l_f02;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3869ULL: goto x86_l_f1d;
	case 3871ULL: goto x86_l_f1f;
	case 3877ULL: goto x86_l_f25;
	case 3885ULL: goto x86_l_f2d;
	case 3891ULL: goto x86_l_f33;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3915ULL: goto x86_l_f4b;
	case 3917ULL: goto x86_l_f4d;
	case 3922ULL: goto x86_l_f52;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3952ULL: goto x86_l_f70;
	case 3960ULL: goto x86_l_f78;
	case 3966ULL: goto x86_l_f7e;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3990ULL: goto x86_l_f96;
	case 3992ULL: goto x86_l_f98;
	case 3997ULL: goto x86_l_f9d;
	case 4002ULL: goto x86_l_fa2;
	case 4007ULL: goto x86_l_fa7;
	case 4012ULL: goto x86_l_fac;
	case 4017ULL: goto x86_l_fb1;
	case 4019ULL: goto x86_l_fb3;
	case 4021ULL: goto x86_l_fb5;
	case 4027ULL: goto x86_l_fbb;
	case 4035ULL: goto x86_l_fc3;
	case 4041ULL: goto x86_l_fc9;
	case 4047ULL: goto x86_l_fcf;
	case 4052ULL: goto x86_l_fd4;
	case 4057ULL: goto x86_l_fd9;
	case 4065ULL: goto x86_l_fe1;
	case 4067ULL: goto x86_l_fe3;
	case 4072ULL: goto x86_l_fe8;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4094ULL: goto x86_l_ffe;
	case 4096ULL: goto x86_l_1000;
	case 4102ULL: goto x86_l_1006;
	case 4110ULL: goto x86_l_100e;
	case 4116ULL: goto x86_l_1014;
	case 4122ULL: goto x86_l_101a;
	case 4127ULL: goto x86_l_101f;
	case 4132ULL: goto x86_l_1024;
	case 4140ULL: goto x86_l_102c;
	case 4142ULL: goto x86_l_102e;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4169ULL: goto x86_l_1049;
	case 4171ULL: goto x86_l_104b;
	case 4177ULL: goto x86_l_1051;
	case 4185ULL: goto x86_l_1059;
	case 4187ULL: goto x86_l_105b;
	case 4193ULL: goto x86_l_1061;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4211ULL: goto x86_l_1073;
	case 4213ULL: goto x86_l_1075;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4228ULL: goto x86_l_1084;
	case 4233ULL: goto x86_l_1089;
	case 4238ULL: goto x86_l_108e;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4248ULL: goto x86_l_1098;
	case 4250ULL: goto x86_l_109a;
	case 4254ULL: goto x86_l_109e;
	case 4262ULL: goto x86_l_10a6;
	case 4267ULL: goto x86_l_10ab;
	case 4275ULL: goto x86_l_10b3;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4288ULL: goto x86_l_10c0;
	case 4293ULL: goto x86_l_10c5;
	case 4301ULL: goto x86_l_10cd;
	case 4307ULL: goto x86_l_10d3;
	case 4313ULL: goto x86_l_10d9;
	case 4316ULL: goto x86_l_10dc;
	case 4321ULL: goto x86_l_10e1;
	case 4329ULL: goto x86_l_10e9;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4341ULL: goto x86_l_10f5;
	case 4346ULL: goto x86_l_10fa;
	case 4351ULL: goto x86_l_10ff;
	case 4356ULL: goto x86_l_1104;
	case 4358ULL: goto x86_l_1106;
	case 4360ULL: goto x86_l_1108;
	case 4366ULL: goto x86_l_110e;
	case 4374ULL: goto x86_l_1116;
	case 4380ULL: goto x86_l_111c;
	case 4386ULL: goto x86_l_1122;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4404ULL: goto x86_l_1134;
	case 4406ULL: goto x86_l_1136;
	case 4411ULL: goto x86_l_113b;
	case 4416ULL: goto x86_l_1140;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4433ULL: goto x86_l_1151;
	case 4435ULL: goto x86_l_1153;
	case 4441ULL: goto x86_l_1159;
	case 4449ULL: goto x86_l_1161;
	case 4455ULL: goto x86_l_1167;
	case 4461ULL: goto x86_l_116d;
	case 4466ULL: goto x86_l_1172;
	case 4471ULL: goto x86_l_1177;
	case 4479ULL: goto x86_l_117f;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4491ULL: goto x86_l_118b;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4508ULL: goto x86_l_119c;
	case 4510ULL: goto x86_l_119e;
	case 4516ULL: goto x86_l_11a4;
	case 4524ULL: goto x86_l_11ac;
	case 4530ULL: goto x86_l_11b2;
	case 4536ULL: goto x86_l_11b8;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4554ULL: goto x86_l_11ca;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4585ULL: goto x86_l_11e9;
	case 4591ULL: goto x86_l_11ef;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4621ULL: goto x86_l_120d;
	case 4629ULL: goto x86_l_1215;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4658ULL: goto x86_l_1232;
	case 4660ULL: goto x86_l_1234;
	case 4666ULL: goto x86_l_123a;
	case 4674ULL: goto x86_l_1242;
	case 4680ULL: goto x86_l_1248;
	case 4686ULL: goto x86_l_124e;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4704ULL: goto x86_l_1260;
	case 4706ULL: goto x86_l_1262;
	case 4711ULL: goto x86_l_1267;
	case 4716ULL: goto x86_l_126c;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4735ULL: goto x86_l_127f;
	case 4741ULL: goto x86_l_1285;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4779ULL: goto x86_l_12ab;
	case 4781ULL: goto x86_l_12ad;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4796ULL: goto x86_l_12bc;
	case 4801ULL: goto x86_l_12c1;
	case 4806ULL: goto x86_l_12c6;
	case 4808ULL: goto x86_l_12c8;
	case 4810ULL: goto x86_l_12ca;
	case 4816ULL: goto x86_l_12d0;
	case 4824ULL: goto x86_l_12d8;
	case 4830ULL: goto x86_l_12de;
	case 4836ULL: goto x86_l_12e4;
	case 4841ULL: goto x86_l_12e9;
	case 4846ULL: goto x86_l_12ee;
	case 4854ULL: goto x86_l_12f6;
	case 4856ULL: goto x86_l_12f8;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4881ULL: goto x86_l_1311;
	case 4883ULL: goto x86_l_1313;
	case 4885ULL: goto x86_l_1315;
	case 4891ULL: goto x86_l_131b;
	case 4899ULL: goto x86_l_1323;
	case 4905ULL: goto x86_l_1329;
	case 4911ULL: goto x86_l_132f;
	case 4916ULL: goto x86_l_1334;
	case 4921ULL: goto x86_l_1339;
	case 4929ULL: goto x86_l_1341;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4946ULL: goto x86_l_1352;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4958ULL: goto x86_l_135e;
	case 4960ULL: goto x86_l_1360;
	case 4966ULL: goto x86_l_1366;
	case 4974ULL: goto x86_l_136e;
	case 4976ULL: goto x86_l_1370;
	case 4982ULL: goto x86_l_1376;
	case 4987ULL: goto x86_l_137b;
	case 4992ULL: goto x86_l_1380;
	case 5000ULL: goto x86_l_1388;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5022ULL: goto x86_l_139e;
	case 5027ULL: goto x86_l_13a3;
	case 5029ULL: goto x86_l_13a5;
	case 5031ULL: goto x86_l_13a7;
	case 5037ULL: goto x86_l_13ad;
	case 5039ULL: goto x86_l_13af;
	case 5043ULL: goto x86_l_13b3;
	case 5051ULL: goto x86_l_13bb;
	case 5056ULL: goto x86_l_13c0;
	case 5064ULL: goto x86_l_13c8;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5084ULL: goto x86_l_13dc;
	case 5087ULL: goto x86_l_13df;
	case 5095ULL: goto x86_l_13e7;
	case 5101ULL: goto x86_l_13ed;
	case 5107ULL: goto x86_l_13f3;
	case 5110ULL: goto x86_l_13f6;
	case 5115ULL: goto x86_l_13fb;
	case 5123ULL: goto x86_l_1403;
	case 5125ULL: goto x86_l_1405;
	case 5130ULL: goto x86_l_140a;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5152ULL: goto x86_l_1420;
	case 5154ULL: goto x86_l_1422;
	case 5160ULL: goto x86_l_1428;
	case 5168ULL: goto x86_l_1430;
	case 5174ULL: goto x86_l_1436;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5190ULL: goto x86_l_1446;
	case 5198ULL: goto x86_l_144e;
	case 5200ULL: goto x86_l_1450;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5225ULL: goto x86_l_1469;
	case 5227ULL: goto x86_l_146b;
	case 5229ULL: goto x86_l_146d;
	case 5235ULL: goto x86_l_1473;
	case 5243ULL: goto x86_l_147b;
	case 5249ULL: goto x86_l_1481;
	case 5255ULL: goto x86_l_1487;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5273ULL: goto x86_l_1499;
	case 5275ULL: goto x86_l_149b;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5290ULL: goto x86_l_14aa;
	case 5295ULL: goto x86_l_14af;
	case 5300ULL: goto x86_l_14b4;
	case 5302ULL: goto x86_l_14b6;
	case 5304ULL: goto x86_l_14b8;
	case 5310ULL: goto x86_l_14be;
	case 5318ULL: goto x86_l_14c6;
	case 5324ULL: goto x86_l_14cc;
	case 5330ULL: goto x86_l_14d2;
	case 5335ULL: goto x86_l_14d7;
	case 5340ULL: goto x86_l_14dc;
	case 5348ULL: goto x86_l_14e4;
	case 5350ULL: goto x86_l_14e6;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5377ULL: goto x86_l_1501;
	case 5379ULL: goto x86_l_1503;
	case 5385ULL: goto x86_l_1509;
	case 5393ULL: goto x86_l_1511;
	case 5399ULL: goto x86_l_1517;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5423ULL: goto x86_l_152f;
	case 5425ULL: goto x86_l_1531;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5450ULL: goto x86_l_154a;
	case 5452ULL: goto x86_l_154c;
	case 5454ULL: goto x86_l_154e;
	case 5460ULL: goto x86_l_1554;
	case 5468ULL: goto x86_l_155c;
	case 5474ULL: goto x86_l_1562;
	case 5480ULL: goto x86_l_1568;
	case 5485ULL: goto x86_l_156d;
	case 5490ULL: goto x86_l_1572;
	case 5498ULL: goto x86_l_157a;
	case 5500ULL: goto x86_l_157c;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5527ULL: goto x86_l_1597;
	case 5529ULL: goto x86_l_1599;
	case 5535ULL: goto x86_l_159f;
	case 5543ULL: goto x86_l_15a7;
	case 5549ULL: goto x86_l_15ad;
	case 5555ULL: goto x86_l_15b3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e44:
	/* 0xe44: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_e4c:
	/* 0xe4c: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_e52:
	/* 0xe52: mov    ecx,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_e58:
	/* 0xe58: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e5d:
	/* 0xe5d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e62:
	/* 0xe62: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_e6a:
	/* 0xe6a: je     e8f <generic_sleepable_preload+0xe8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e8f;
	}
x86_l_e6c:
	/* 0xe6c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e71:
	/* 0xe71: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e76:
	/* 0xe76: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e7b:
	/* 0xe7b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e80:
	/* 0xe80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e85:
	/* 0xe85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e87:
	/* 0xe87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e89:
	/* 0xe89: js     29e9 <generic_sleepable_preload+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10729ULL;
	}
x86_l_e8f:
	/* 0xe8f: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_e97:
	/* 0xe97: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_e9d:
	/* 0xe9d: mov    ecx,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_ea3:
	/* 0xea3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ea8:
	/* 0xea8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ead:
	/* 0xead: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_eb5:
	/* 0xeb5: je     eda <generic_sleepable_preload+0xeda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eda;
	}
x86_l_eb7:
	/* 0xeb7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ebc:
	/* 0xebc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ec1:
	/* 0xec1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ec6:
	/* 0xec6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ecb:
	/* 0xecb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ed0:
	/* 0xed0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed2:
	/* 0xed2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ed4:
	/* 0xed4: js     2a65 <generic_sleepable_preload+0x2a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10853ULL;
	}
x86_l_eda:
	/* 0xeda: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_ee2:
	/* 0xee2: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_ee8:
	/* 0xee8: mov    ecx,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_eee:
	/* 0xeee: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ef3:
	/* 0xef3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef8:
	/* 0xef8: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_f00:
	/* 0xf00: je     f25 <generic_sleepable_preload+0xf25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f25;
	}
x86_l_f02:
	/* 0xf02: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f07:
	/* 0xf07: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f0c:
	/* 0xf0c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f11:
	/* 0xf11: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f16:
	/* 0xf16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f1b:
	/* 0xf1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1d:
	/* 0xf1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f1f:
	/* 0xf1f: js     2ae1 <generic_sleepable_preload+0x2ae1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10977ULL;
	}
x86_l_f25:
	/* 0xf25: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_f2d:
	/* 0xf2d: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_f33:
	/* 0xf33: mov    ecx,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_f39:
	/* 0xf39: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f3e:
	/* 0xf3e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f43:
	/* 0xf43: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_f4b:
	/* 0xf4b: je     f70 <generic_sleepable_preload+0xf70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f70;
	}
x86_l_f4d:
	/* 0xf4d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f52:
	/* 0xf52: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f57:
	/* 0xf57: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f5c:
	/* 0xf5c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f61:
	/* 0xf61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f66:
	/* 0xf66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f68:
	/* 0xf68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f6a:
	/* 0xf6a: js     2b5a <generic_sleepable_preload+0x2b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11098ULL;
	}
x86_l_f70:
	/* 0xf70: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_f78:
	/* 0xf78: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_f7e:
	/* 0xf7e: mov    ecx,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_f84:
	/* 0xf84: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f89:
	/* 0xf89: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8e:
	/* 0xf8e: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_f96:
	/* 0xf96: je     fbb <generic_sleepable_preload+0xfbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fbb;
	}
x86_l_f98:
	/* 0xf98: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f9d:
	/* 0xf9d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fa2:
	/* 0xfa2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_fa7:
	/* 0xfa7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fac:
	/* 0xfac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fb1:
	/* 0xfb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb3:
	/* 0xfb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fb5:
	/* 0xfb5: js     2d84 <generic_sleepable_preload+0x2d84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11652ULL;
	}
x86_l_fbb:
	/* 0xfbb: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_fc3:
	/* 0xfc3: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_fc9:
	/* 0xfc9: mov    ecx,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_fcf:
	/* 0xfcf: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fd4:
	/* 0xfd4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd9:
	/* 0xfd9: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_fe1:
	/* 0xfe1: je     1006 <generic_sleepable_preload+0x1006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1006;
	}
x86_l_fe3:
	/* 0xfe3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe8:
	/* 0xfe8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fed:
	/* 0xfed: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ff2:
	/* 0xff2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff7:
	/* 0xff7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ffc:
	/* 0xffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffe:
	/* 0xffe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1000:
	/* 0x1000: js     33e0 <generic_sleepable_preload+0x33e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13280ULL;
	}
x86_l_1006:
	/* 0x1006: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_100e:
	/* 0x100e: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_1014:
	/* 0x1014: mov    ecx,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_101a:
	/* 0x101a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_101f:
	/* 0x101f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1024:
	/* 0x1024: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_102c:
	/* 0x102c: je     1051 <generic_sleepable_preload+0x1051> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1051;
	}
x86_l_102e:
	/* 0x102e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1033:
	/* 0x1033: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1038:
	/* 0x1038: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_103d:
	/* 0x103d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1042:
	/* 0x1042: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1047:
	/* 0x1047: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1049:
	/* 0x1049: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_104b:
	/* 0x104b: js     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13508ULL;
	}
x86_l_1051:
	/* 0x1051: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_1059:
	/* 0x1059: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_105b:
	/* 0x105b: mov    ecx,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_1061:
	/* 0x1061: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1066:
	/* 0x1066: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_106b:
	/* 0x106b: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_1073:
	/* 0x1073: je     1098 <generic_sleepable_preload+0x1098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1098;
	}
x86_l_1075:
	/* 0x1075: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_107a:
	/* 0x107a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_107f:
	/* 0x107f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1084:
	/* 0x1084: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1089:
	/* 0x1089: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_108e:
	/* 0x108e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1090:
	/* 0x1090: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1092:
	/* 0x1092: js     3540 <generic_sleepable_preload+0x3540> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13632ULL;
	}
x86_l_1098:
	/* 0x1098: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_109a:
	/* 0x109a: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_109e:
	/* 0x109e: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_10a6:
	/* 0x10a6: jmp    2d94 <generic_sleepable_preload+0x2d94> */
	return 11668ULL;
x86_l_10ab:
	/* 0x10ab: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_10b3:
	/* 0x10b3: jmp    2d8c <generic_sleepable_preload+0x2d8c> */
	return 11660ULL;
x86_l_10b8:
	/* 0x10b8: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10bd:
	/* 0x10bd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c0:
	/* 0x10c0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10c5:
	/* 0x10c5: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_10cd:
	/* 0x10cd: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_10d3:
	/* 0x10d3: mov    eax,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_10d9:
	/* 0x10d9: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_10dc:
	/* 0x10dc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e1:
	/* 0x10e1: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_10e9:
	/* 0x10e9: je     110e <generic_sleepable_preload+0x110e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110e;
	}
x86_l_10eb:
	/* 0x10eb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f0:
	/* 0x10f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_10f5:
	/* 0x10f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10fa:
	/* 0x10fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ff:
	/* 0x10ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1104:
	/* 0x1104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1106:
	/* 0x1106: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1108:
	/* 0x1108: js     13c0 <generic_sleepable_preload+0x13c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_13c0;
	}
x86_l_110e:
	/* 0x110e: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_1116:
	/* 0x1116: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_111c:
	/* 0x111c: mov    ecx,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_1122:
	/* 0x1122: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1127:
	/* 0x1127: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112c:
	/* 0x112c: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_1134:
	/* 0x1134: je     1159 <generic_sleepable_preload+0x1159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1159;
	}
x86_l_1136:
	/* 0x1136: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_113b:
	/* 0x113b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1140:
	/* 0x1140: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1145:
	/* 0x1145: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114a:
	/* 0x114a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_114f:
	/* 0x114f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1151:
	/* 0x1151: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1153:
	/* 0x1153: js     1fd5 <generic_sleepable_preload+0x1fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8149ULL;
	}
x86_l_1159:
	/* 0x1159: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_1161:
	/* 0x1161: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_1167:
	/* 0x1167: mov    ecx,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_116d:
	/* 0x116d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1172:
	/* 0x1172: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1177:
	/* 0x1177: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_117f:
	/* 0x117f: je     11a4 <generic_sleepable_preload+0x11a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a4;
	}
x86_l_1181:
	/* 0x1181: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1186:
	/* 0x1186: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_118b:
	/* 0x118b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1190:
	/* 0x1190: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1195:
	/* 0x1195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_119a:
	/* 0x119a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119c:
	/* 0x119c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_119e:
	/* 0x119e: js     29f6 <generic_sleepable_preload+0x29f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10742ULL;
	}
x86_l_11a4:
	/* 0x11a4: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_11ac:
	/* 0x11ac: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_11b2:
	/* 0x11b2: mov    ecx,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_11b8:
	/* 0x11b8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_11bd:
	/* 0x11bd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11c2:
	/* 0x11c2: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_11ca:
	/* 0x11ca: je     11ef <generic_sleepable_preload+0x11ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ef;
	}
x86_l_11cc:
	/* 0x11cc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d1:
	/* 0x11d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11d6:
	/* 0x11d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11db:
	/* 0x11db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11e0:
	/* 0x11e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11e5:
	/* 0x11e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e7:
	/* 0x11e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11e9:
	/* 0x11e9: js     2a72 <generic_sleepable_preload+0x2a72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10866ULL;
	}
x86_l_11ef:
	/* 0x11ef: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_11f7:
	/* 0x11f7: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_11fd:
	/* 0x11fd: mov    ecx,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_1203:
	/* 0x1203: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1208:
	/* 0x1208: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_120d:
	/* 0x120d: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_1215:
	/* 0x1215: je     123a <generic_sleepable_preload+0x123a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_123a;
	}
x86_l_1217:
	/* 0x1217: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_121c:
	/* 0x121c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1221:
	/* 0x1221: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1226:
	/* 0x1226: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122b:
	/* 0x122b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1230:
	/* 0x1230: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1232:
	/* 0x1232: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1234:
	/* 0x1234: js     2aee <generic_sleepable_preload+0x2aee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10990ULL;
	}
x86_l_123a:
	/* 0x123a: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_1242:
	/* 0x1242: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_1248:
	/* 0x1248: mov    ecx,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_124e:
	/* 0x124e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1253:
	/* 0x1253: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1258:
	/* 0x1258: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_1260:
	/* 0x1260: je     1285 <generic_sleepable_preload+0x1285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1285;
	}
x86_l_1262:
	/* 0x1262: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1267:
	/* 0x1267: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_126c:
	/* 0x126c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1271:
	/* 0x1271: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1276:
	/* 0x1276: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_127b:
	/* 0x127b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127d:
	/* 0x127d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_127f:
	/* 0x127f: js     2b67 <generic_sleepable_preload+0x2b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11111ULL;
	}
x86_l_1285:
	/* 0x1285: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_128d:
	/* 0x128d: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_1293:
	/* 0x1293: mov    ecx,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_1299:
	/* 0x1299: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_129e:
	/* 0x129e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12a3:
	/* 0x12a3: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_12ab:
	/* 0x12ab: je     12d0 <generic_sleepable_preload+0x12d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d0;
	}
x86_l_12ad:
	/* 0x12ad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b2:
	/* 0x12b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12b7:
	/* 0x12b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12bc:
	/* 0x12bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c1:
	/* 0x12c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12c6:
	/* 0x12c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c8:
	/* 0x12c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12ca:
	/* 0x12ca: js     2e7f <generic_sleepable_preload+0x2e7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11903ULL;
	}
x86_l_12d0:
	/* 0x12d0: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_12d8:
	/* 0x12d8: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_12de:
	/* 0x12de: mov    ecx,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_12e4:
	/* 0x12e4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_12e9:
	/* 0x12e9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ee:
	/* 0x12ee: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_12f6:
	/* 0x12f6: je     131b <generic_sleepable_preload+0x131b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131b;
	}
x86_l_12f8:
	/* 0x12f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12fd:
	/* 0x12fd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1302:
	/* 0x1302: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1307:
	/* 0x1307: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130c:
	/* 0x130c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1311:
	/* 0x1311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1313:
	/* 0x1313: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1315:
	/* 0x1315: js     33f5 <generic_sleepable_preload+0x33f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13301ULL;
	}
x86_l_131b:
	/* 0x131b: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_1323:
	/* 0x1323: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_1329:
	/* 0x1329: mov    ecx,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_132f:
	/* 0x132f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1334:
	/* 0x1334: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1339:
	/* 0x1339: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_1341:
	/* 0x1341: je     1366 <generic_sleepable_preload+0x1366> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1366;
	}
x86_l_1343:
	/* 0x1343: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1348:
	/* 0x1348: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_134d:
	/* 0x134d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1352:
	/* 0x1352: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1357:
	/* 0x1357: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_135c:
	/* 0x135c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135e:
	/* 0x135e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1360:
	/* 0x1360: js     34d1 <generic_sleepable_preload+0x34d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13521ULL;
	}
x86_l_1366:
	/* 0x1366: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_136e:
	/* 0x136e: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_1370:
	/* 0x1370: mov    ecx,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_1376:
	/* 0x1376: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_137b:
	/* 0x137b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1380:
	/* 0x1380: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_1388:
	/* 0x1388: je     13ad <generic_sleepable_preload+0x13ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ad;
	}
x86_l_138a:
	/* 0x138a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_138f:
	/* 0x138f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1394:
	/* 0x1394: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1399:
	/* 0x1399: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_139e:
	/* 0x139e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a3:
	/* 0x13a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a5:
	/* 0x13a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a7:
	/* 0x13a7: js     354d <generic_sleepable_preload+0x354d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13645ULL;
	}
x86_l_13ad:
	/* 0x13ad: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_13af:
	/* 0x13af: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13b3:
	/* 0x13b3: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_13bb:
	/* 0x13bb: jmp    2e8f <generic_sleepable_preload+0x2e8f> */
	return 11919ULL;
x86_l_13c0:
	/* 0x13c0: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_13c8:
	/* 0x13c8: jmp    2e87 <generic_sleepable_preload+0x2e87> */
	return 11911ULL;
x86_l_13cd:
	/* 0x13cd: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13d2:
	/* 0x13d2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d5:
	/* 0x13d5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13da:
	/* 0x13da: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13dc:
	/* 0x13dc: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_13df:
	/* 0x13df: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_13e7:
	/* 0x13e7: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_13ed:
	/* 0x13ed: mov    eax,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_13f3:
	/* 0x13f3: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13f6:
	/* 0x13f6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13fb:
	/* 0x13fb: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_1403:
	/* 0x1403: je     1428 <generic_sleepable_preload+0x1428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1428;
	}
x86_l_1405:
	/* 0x1405: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_140a:
	/* 0x140a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_140f:
	/* 0x140f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1414:
	/* 0x1414: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1419:
	/* 0x1419: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_141e:
	/* 0x141e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1420:
	/* 0x1420: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1422:
	/* 0x1422: js     16d9 <generic_sleepable_preload+0x16d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5849ULL;
	}
x86_l_1428:
	/* 0x1428: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_1430:
	/* 0x1430: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_1436:
	/* 0x1436: mov    ecx,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_143c:
	/* 0x143c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1441:
	/* 0x1441: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1446:
	/* 0x1446: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_144e:
	/* 0x144e: je     1473 <generic_sleepable_preload+0x1473> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1473;
	}
x86_l_1450:
	/* 0x1450: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1455:
	/* 0x1455: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_145a:
	/* 0x145a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_145f:
	/* 0x145f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1464:
	/* 0x1464: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1469:
	/* 0x1469: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146b:
	/* 0x146b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_146d:
	/* 0x146d: js     1fe2 <generic_sleepable_preload+0x1fe2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8162ULL;
	}
x86_l_1473:
	/* 0x1473: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_147b:
	/* 0x147b: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_1481:
	/* 0x1481: mov    ecx,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_1487:
	/* 0x1487: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_148c:
	/* 0x148c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1491:
	/* 0x1491: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_1499:
	/* 0x1499: je     14be <generic_sleepable_preload+0x14be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14be;
	}
x86_l_149b:
	/* 0x149b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a0:
	/* 0x14a0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14a5:
	/* 0x14a5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14aa:
	/* 0x14aa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14af:
	/* 0x14af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14b4:
	/* 0x14b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b6:
	/* 0x14b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14b8:
	/* 0x14b8: js     2a03 <generic_sleepable_preload+0x2a03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10755ULL;
	}
x86_l_14be:
	/* 0x14be: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_14c6:
	/* 0x14c6: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_14cc:
	/* 0x14cc: mov    ecx,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_14d2:
	/* 0x14d2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_14d7:
	/* 0x14d7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14dc:
	/* 0x14dc: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_14e4:
	/* 0x14e4: je     1509 <generic_sleepable_preload+0x1509> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1509;
	}
x86_l_14e6:
	/* 0x14e6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14eb:
	/* 0x14eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14f0:
	/* 0x14f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14f5:
	/* 0x14f5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14fa:
	/* 0x14fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14ff:
	/* 0x14ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1501:
	/* 0x1501: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1503:
	/* 0x1503: js     2a7f <generic_sleepable_preload+0x2a7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10879ULL;
	}
x86_l_1509:
	/* 0x1509: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_1511:
	/* 0x1511: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_1517:
	/* 0x1517: mov    ecx,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_151d:
	/* 0x151d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1522:
	/* 0x1522: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1527:
	/* 0x1527: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_152f:
	/* 0x152f: je     1554 <generic_sleepable_preload+0x1554> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1554;
	}
x86_l_1531:
	/* 0x1531: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1536:
	/* 0x1536: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_153b:
	/* 0x153b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1540:
	/* 0x1540: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1545:
	/* 0x1545: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_154a:
	/* 0x154a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154c:
	/* 0x154c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_154e:
	/* 0x154e: js     2afb <generic_sleepable_preload+0x2afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11003ULL;
	}
x86_l_1554:
	/* 0x1554: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_155c:
	/* 0x155c: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_1562:
	/* 0x1562: mov    ecx,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_1568:
	/* 0x1568: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_156d:
	/* 0x156d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1572:
	/* 0x1572: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_157a:
	/* 0x157a: je     159f <generic_sleepable_preload+0x159f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_159f;
	}
x86_l_157c:
	/* 0x157c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1581:
	/* 0x1581: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1586:
	/* 0x1586: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_158b:
	/* 0x158b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1590:
	/* 0x1590: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1595:
	/* 0x1595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1597:
	/* 0x1597: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1599:
	/* 0x1599: js     2b74 <generic_sleepable_preload+0x2b74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11124ULL;
	}
x86_l_159f:
	/* 0x159f: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_15a7:
	/* 0x15a7: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_15ad:
	/* 0x15ad: mov    ecx,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_15b3:
	/* 0x15b3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
	return 5560ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5560ULL: goto x86_l_15b8;
	case 5565ULL: goto x86_l_15bd;
	case 5573ULL: goto x86_l_15c5;
	case 5575ULL: goto x86_l_15c7;
	case 5580ULL: goto x86_l_15cc;
	case 5585ULL: goto x86_l_15d1;
	case 5590ULL: goto x86_l_15d6;
	case 5595ULL: goto x86_l_15db;
	case 5600ULL: goto x86_l_15e0;
	case 5602ULL: goto x86_l_15e2;
	case 5604ULL: goto x86_l_15e4;
	case 5610ULL: goto x86_l_15ea;
	case 5618ULL: goto x86_l_15f2;
	case 5624ULL: goto x86_l_15f8;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5648ULL: goto x86_l_1610;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5677ULL: goto x86_l_162d;
	case 5679ULL: goto x86_l_162f;
	case 5685ULL: goto x86_l_1635;
	case 5693ULL: goto x86_l_163d;
	case 5699ULL: goto x86_l_1643;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5723ULL: goto x86_l_165b;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5752ULL: goto x86_l_1678;
	case 5754ULL: goto x86_l_167a;
	case 5760ULL: goto x86_l_1680;
	case 5768ULL: goto x86_l_1688;
	case 5774ULL: goto x86_l_168e;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5790ULL: goto x86_l_169e;
	case 5798ULL: goto x86_l_16a6;
	case 5804ULL: goto x86_l_16ac;
	case 5809ULL: goto x86_l_16b1;
	case 5814ULL: goto x86_l_16b6;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5831ULL: goto x86_l_16c7;
	case 5833ULL: goto x86_l_16c9;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5849ULL: goto x86_l_16d9;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5867ULL: goto x86_l_16eb;
	case 5870ULL: goto x86_l_16ee;
	case 5876ULL: goto x86_l_16f4;
	case 5879ULL: goto x86_l_16f7;
	case 5882ULL: goto x86_l_16fa;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5901ULL: goto x86_l_170d;
	case 5904ULL: goto x86_l_1710;
	case 5910ULL: goto x86_l_1716;
	case 5913ULL: goto x86_l_1719;
	case 5916ULL: goto x86_l_171c;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5935ULL: goto x86_l_172f;
	case 5938ULL: goto x86_l_1732;
	case 5944ULL: goto x86_l_1738;
	case 5947ULL: goto x86_l_173b;
	case 5950ULL: goto x86_l_173e;
	case 5956ULL: goto x86_l_1744;
	case 5961ULL: goto x86_l_1749;
	case 5969ULL: goto x86_l_1751;
	case 5972ULL: goto x86_l_1754;
	case 5978ULL: goto x86_l_175a;
	case 5981ULL: goto x86_l_175d;
	case 5984ULL: goto x86_l_1760;
	case 5990ULL: goto x86_l_1766;
	case 5995ULL: goto x86_l_176b;
	case 6003ULL: goto x86_l_1773;
	case 6006ULL: goto x86_l_1776;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6018ULL: goto x86_l_1782;
	case 6024ULL: goto x86_l_1788;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6037ULL: goto x86_l_1795;
	case 6043ULL: goto x86_l_179b;
	case 6048ULL: goto x86_l_17a0;
	case 6051ULL: goto x86_l_17a3;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6070ULL: goto x86_l_17b6;
	case 6076ULL: goto x86_l_17bc;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6103ULL: goto x86_l_17d7;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6136ULL: goto x86_l_17f8;
	case 6142ULL: goto x86_l_17fe;
	case 6147ULL: goto x86_l_1803;
	case 6150ULL: goto x86_l_1806;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6169ULL: goto x86_l_1819;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6183ULL: goto x86_l_1827;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6202ULL: goto x86_l_183a;
	case 6205ULL: goto x86_l_183d;
	case 6211ULL: goto x86_l_1843;
	case 6216ULL: goto x86_l_1848;
	case 6219ULL: goto x86_l_184b;
	case 6225ULL: goto x86_l_1851;
	case 6230ULL: goto x86_l_1856;
	case 6238ULL: goto x86_l_185e;
	case 6241ULL: goto x86_l_1861;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6274ULL: goto x86_l_1882;
	case 6277ULL: goto x86_l_1885;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6291ULL: goto x86_l_1893;
	case 6297ULL: goto x86_l_1899;
	case 6302ULL: goto x86_l_189e;
	case 6310ULL: goto x86_l_18a6;
	case 6313ULL: goto x86_l_18a9;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6327ULL: goto x86_l_18b7;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6346ULL: goto x86_l_18ca;
	case 6349ULL: goto x86_l_18cd;
	case 6355ULL: goto x86_l_18d3;
	case 6360ULL: goto x86_l_18d8;
	case 6363ULL: goto x86_l_18db;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6382ULL: goto x86_l_18ee;
	case 6384ULL: goto x86_l_18f0;
	case 6387ULL: goto x86_l_18f3;
	case 6390ULL: goto x86_l_18f6;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6397ULL: goto x86_l_18fd;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6406ULL: goto x86_l_1906;
	case 6411ULL: goto x86_l_190b;
	case 6416ULL: goto x86_l_1910;
	case 6420ULL: goto x86_l_1914;
	case 6428ULL: goto x86_l_191c;
	case 6430ULL: goto x86_l_191e;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6445ULL: goto x86_l_192d;
	case 6448ULL: goto x86_l_1930;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6461ULL: goto x86_l_193d;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6478ULL: goto x86_l_194e;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6490ULL: goto x86_l_195a;
	case 6492ULL: goto x86_l_195c;
	case 6498ULL: goto x86_l_1962;
	case 6503ULL: goto x86_l_1967;
	case 6509ULL: goto x86_l_196d;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6529ULL: goto x86_l_1981;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6556ULL: goto x86_l_199c;
	case 6558ULL: goto x86_l_199e;
	case 6564ULL: goto x86_l_19a4;
	case 6572ULL: goto x86_l_19ac;
	case 6578ULL: goto x86_l_19b2;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6594ULL: goto x86_l_19c2;
	case 6602ULL: goto x86_l_19ca;
	case 6604ULL: goto x86_l_19cc;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6631ULL: goto x86_l_19e7;
	case 6633ULL: goto x86_l_19e9;
	case 6639ULL: goto x86_l_19ef;
	case 6647ULL: goto x86_l_19f7;
	case 6653ULL: goto x86_l_19fd;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6677ULL: goto x86_l_1a15;
	case 6679ULL: goto x86_l_1a17;
	case 6684ULL: goto x86_l_1a1c;
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6699ULL: goto x86_l_1a2b;
	case 6704ULL: goto x86_l_1a30;
	case 6706ULL: goto x86_l_1a32;
	case 6708ULL: goto x86_l_1a34;
	case 6714ULL: goto x86_l_1a3a;
	case 6722ULL: goto x86_l_1a42;
	case 6728ULL: goto x86_l_1a48;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6752ULL: goto x86_l_1a60;
	case 6754ULL: goto x86_l_1a62;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6769ULL: goto x86_l_1a71;
	case 6774ULL: goto x86_l_1a76;
	case 6779ULL: goto x86_l_1a7b;
	case 6781ULL: goto x86_l_1a7d;
	case 6783ULL: goto x86_l_1a7f;
	case 6789ULL: goto x86_l_1a85;
	case 6797ULL: goto x86_l_1a8d;
	case 6803ULL: goto x86_l_1a93;
	case 6809ULL: goto x86_l_1a99;
	case 6814ULL: goto x86_l_1a9e;
	case 6819ULL: goto x86_l_1aa3;
	case 6827ULL: goto x86_l_1aab;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6856ULL: goto x86_l_1ac8;
	case 6858ULL: goto x86_l_1aca;
	case 6864ULL: goto x86_l_1ad0;
	case 6872ULL: goto x86_l_1ad8;
	case 6878ULL: goto x86_l_1ade;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6894ULL: goto x86_l_1aee;
	case 6902ULL: goto x86_l_1af6;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6939ULL: goto x86_l_1b1b;
	case 6947ULL: goto x86_l_1b23;
	case 6953ULL: goto x86_l_1b29;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6977ULL: goto x86_l_1b41;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	case 7004ULL: goto x86_l_1b5c;
	case 7006ULL: goto x86_l_1b5e;
	case 7008ULL: goto x86_l_1b60;
	case 7014ULL: goto x86_l_1b66;
	case 7022ULL: goto x86_l_1b6e;
	case 7028ULL: goto x86_l_1b74;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7052ULL: goto x86_l_1b8c;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7074ULL: goto x86_l_1ba2;
	case 7079ULL: goto x86_l_1ba7;
	case 7081ULL: goto x86_l_1ba9;
	case 7083ULL: goto x86_l_1bab;
	case 7089ULL: goto x86_l_1bb1;
	case 7097ULL: goto x86_l_1bb9;
	case 7103ULL: goto x86_l_1bbf;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7127ULL: goto x86_l_1bd7;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7160ULL: goto x86_l_1bf8;
	case 7162ULL: goto x86_l_1bfa;
	case 7168ULL: goto x86_l_1c00;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7199ULL: goto x86_l_1c1f;
	case 7202ULL: goto x86_l_1c22;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7214ULL: goto x86_l_1c2e;
	case 7220ULL: goto x86_l_1c34;
	case 7225ULL: goto x86_l_1c39;
	case 7230ULL: goto x86_l_1c3e;
	case 7233ULL: goto x86_l_1c41;
	case 7239ULL: goto x86_l_1c47;
	case 7242ULL: goto x86_l_1c4a;
	case 7245ULL: goto x86_l_1c4d;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7261ULL: goto x86_l_1c5d;
	case 7264ULL: goto x86_l_1c60;
	case 7270ULL: goto x86_l_1c66;
	case 7273ULL: goto x86_l_1c69;
	case 7276ULL: goto x86_l_1c6c;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7295ULL: goto x86_l_1c7f;
	case 7297ULL: goto x86_l_1c81;
	case 7300ULL: goto x86_l_1c84;
	case 7303ULL: goto x86_l_1c87;
	case 7305ULL: goto x86_l_1c89;
	case 7308ULL: goto x86_l_1c8c;
	case 7310ULL: goto x86_l_1c8e;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7329ULL: goto x86_l_1ca1;
	case 7333ULL: goto x86_l_1ca5;
	case 7335ULL: goto x86_l_1ca7;
	case 7338ULL: goto x86_l_1caa;
	case 7346ULL: goto x86_l_1cb2;
	case 7352ULL: goto x86_l_1cb8;
	case 7358ULL: goto x86_l_1cbe;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7374ULL: goto x86_l_1cce;
	case 7376ULL: goto x86_l_1cd0;
	case 7381ULL: goto x86_l_1cd5;
	case 7386ULL: goto x86_l_1cda;
	case 7391ULL: goto x86_l_1cdf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15b8:
	/* 0x15b8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15bd:
	/* 0x15bd: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_15c5:
	/* 0x15c5: je     15ea <generic_sleepable_preload+0x15ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ea;
	}
x86_l_15c7:
	/* 0x15c7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15cc:
	/* 0x15cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15d1:
	/* 0x15d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15d6:
	/* 0x15d6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15db:
	/* 0x15db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15e0:
	/* 0x15e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e2:
	/* 0x15e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15e4:
	/* 0x15e4: js     2f7a <generic_sleepable_preload+0x2f7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12154ULL;
	}
x86_l_15ea:
	/* 0x15ea: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_15f2:
	/* 0x15f2: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_15f8:
	/* 0x15f8: mov    ecx,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_15fe:
	/* 0x15fe: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1603:
	/* 0x1603: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1608:
	/* 0x1608: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_1610:
	/* 0x1610: je     1635 <generic_sleepable_preload+0x1635> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1635;
	}
x86_l_1612:
	/* 0x1612: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1617:
	/* 0x1617: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_161c:
	/* 0x161c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1621:
	/* 0x1621: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1626:
	/* 0x1626: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_162b:
	/* 0x162b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162d:
	/* 0x162d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_162f:
	/* 0x162f: js     340a <generic_sleepable_preload+0x340a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13322ULL;
	}
x86_l_1635:
	/* 0x1635: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_163d:
	/* 0x163d: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_1643:
	/* 0x1643: mov    ecx,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1649:
	/* 0x1649: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_164e:
	/* 0x164e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1653:
	/* 0x1653: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_165b:
	/* 0x165b: je     1680 <generic_sleepable_preload+0x1680> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1680;
	}
x86_l_165d:
	/* 0x165d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1662:
	/* 0x1662: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1667:
	/* 0x1667: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_166c:
	/* 0x166c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1671:
	/* 0x1671: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1676:
	/* 0x1676: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1678:
	/* 0x1678: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_167a:
	/* 0x167a: js     34de <generic_sleepable_preload+0x34de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13534ULL;
	}
x86_l_1680:
	/* 0x1680: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_1688:
	/* 0x1688: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_168e:
	/* 0x168e: mov    ecx,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_1694:
	/* 0x1694: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1699:
	/* 0x1699: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_169e:
	/* 0x169e: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_16a6:
	/* 0x16a6: je     2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12162ULL;
	}
x86_l_16ac:
	/* 0x16ac: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16b1:
	/* 0x16b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16b6:
	/* 0x16b6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16bb:
	/* 0x16bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16c0:
	/* 0x16c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16c5:
	/* 0x16c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c7:
	/* 0x16c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16c9:
	/* 0x16c9: jns    2f82 <generic_sleepable_preload+0x2f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12162ULL;
	}
x86_l_16cf:
	/* 0x16cf: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_16d4:
	/* 0x16d4: jmp    2f7f <generic_sleepable_preload+0x2f7f> */
	return 12159ULL;
x86_l_16d9:
	/* 0x16d9: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_16de:
	/* 0x16de: jmp    2f7f <generic_sleepable_preload+0x2f7f> */
	return 12159ULL;
x86_l_16e3:
	/* 0x16e3: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16eb:
	/* 0x16eb: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_16ee:
	/* 0x16ee: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_16f4:
	/* 0x16f4: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_16f7:
	/* 0x16f7: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_16fa:
	/* 0x16fa: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_1700:
	/* 0x1700: jmp    190b <generic_sleepable_preload+0x190b> */
	goto x86_l_190b;
x86_l_1705:
	/* 0x1705: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_170d:
	/* 0x170d: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1710:
	/* 0x1710: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_1716:
	/* 0x1716: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1719:
	/* 0x1719: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_171c:
	/* 0x171c: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_1722:
	/* 0x1722: jmp    2019 <generic_sleepable_preload+0x2019> */
	return 8217ULL;
x86_l_1727:
	/* 0x1727: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_172f:
	/* 0x172f: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1732:
	/* 0x1732: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_1738:
	/* 0x1738: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_173b:
	/* 0x173b: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_173e:
	/* 0x173e: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_1744:
	/* 0x1744: jmp    235d <generic_sleepable_preload+0x235d> */
	return 9053ULL;
x86_l_1749:
	/* 0x1749: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1751:
	/* 0x1751: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1754:
	/* 0x1754: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_175a:
	/* 0x175a: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_175d:
	/* 0x175d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1760:
	/* 0x1760: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_1766:
	/* 0x1766: jmp    26a1 <generic_sleepable_preload+0x26a1> */
	return 9889ULL;
x86_l_176b:
	/* 0x176b: mov    r14,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1773:
	/* 0x1773: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1776:
	/* 0x1776: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c89;
	}
x86_l_177c:
	/* 0x177c: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_177f:
	/* 0x177f: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1782:
	/* 0x1782: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c89;
	}
x86_l_1788:
	/* 0x1788: jmp    1c9c <generic_sleepable_preload+0x1c9c> */
	goto x86_l_1c9c;
x86_l_178d:
	/* 0x178d: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1792:
	/* 0x1792: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1795:
	/* 0x1795: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_179b:
	/* 0x179b: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17a0:
	/* 0x17a0: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_17a3:
	/* 0x17a3: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_17a9:
	/* 0x17a9: jmp    190b <generic_sleepable_preload+0x190b> */
	goto x86_l_190b;
x86_l_17ae:
	/* 0x17ae: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17b3:
	/* 0x17b3: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_17b6:
	/* 0x17b6: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_17bc:
	/* 0x17bc: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17c1:
	/* 0x17c1: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_17c4:
	/* 0x17c4: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_17ca:
	/* 0x17ca: jmp    2019 <generic_sleepable_preload+0x2019> */
	return 8217ULL;
x86_l_17cf:
	/* 0x17cf: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17d4:
	/* 0x17d4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_17d7:
	/* 0x17d7: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_17dd:
	/* 0x17dd: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17e2:
	/* 0x17e2: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_17e5:
	/* 0x17e5: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_17eb:
	/* 0x17eb: jmp    235d <generic_sleepable_preload+0x235d> */
	return 9053ULL;
x86_l_17f0:
	/* 0x17f0: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17f5:
	/* 0x17f5: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_17f8:
	/* 0x17f8: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_17fe:
	/* 0x17fe: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1803:
	/* 0x1803: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1806:
	/* 0x1806: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_180c:
	/* 0x180c: jmp    26a1 <generic_sleepable_preload+0x26a1> */
	return 9889ULL;
x86_l_1811:
	/* 0x1811: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1816:
	/* 0x1816: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1819:
	/* 0x1819: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c89;
	}
x86_l_181f:
	/* 0x181f: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1824:
	/* 0x1824: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1827:
	/* 0x1827: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c89;
	}
x86_l_182d:
	/* 0x182d: jmp    1c9c <generic_sleepable_preload+0x1c9c> */
	goto x86_l_1c9c;
x86_l_1832:
	/* 0x1832: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_183a:
	/* 0x183a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_183d:
	/* 0x183d: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_1843:
	/* 0x1843: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1848:
	/* 0x1848: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_184b:
	/* 0x184b: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_1851:
	/* 0x1851: jmp    190b <generic_sleepable_preload+0x190b> */
	goto x86_l_190b;
x86_l_1856:
	/* 0x1856: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_185e:
	/* 0x185e: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1861:
	/* 0x1861: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_1867:
	/* 0x1867: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_186c:
	/* 0x186c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_186f:
	/* 0x186f: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_1875:
	/* 0x1875: jmp    2019 <generic_sleepable_preload+0x2019> */
	return 8217ULL;
x86_l_187a:
	/* 0x187a: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1882:
	/* 0x1882: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1885:
	/* 0x1885: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_188b:
	/* 0x188b: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1890:
	/* 0x1890: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1893:
	/* 0x1893: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_1899:
	/* 0x1899: jmp    235d <generic_sleepable_preload+0x235d> */
	return 9053ULL;
x86_l_189e:
	/* 0x189e: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18a6:
	/* 0x18a6: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_18a9:
	/* 0x18a9: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_18af:
	/* 0x18af: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18b4:
	/* 0x18b4: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_18b7:
	/* 0x18b7: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_18bd:
	/* 0x18bd: jmp    26a1 <generic_sleepable_preload+0x26a1> */
	return 9889ULL;
x86_l_18c2:
	/* 0x18c2: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18ca:
	/* 0x18ca: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_18cd:
	/* 0x18cd: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c89;
	}
x86_l_18d3:
	/* 0x18d3: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18d8:
	/* 0x18d8: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_18db:
	/* 0x18db: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c89;
	}
x86_l_18e1:
	/* 0x18e1: jmp    1c9c <generic_sleepable_preload+0x1c9c> */
	goto x86_l_1c9c;
x86_l_18e6:
	/* 0x18e6: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18eb:
	/* 0x18eb: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_18ee:
	/* 0x18ee: je     18f8 <generic_sleepable_preload+0x18f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18f8;
	}
x86_l_18f0:
	/* 0x18f0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_18f3:
	/* 0x18f3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_18f6:
	/* 0x18f6: jne    190b <generic_sleepable_preload+0x190b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_190b;
	}
x86_l_18f8:
	/* 0x18f8: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_18fb:
	/* 0x18fb: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_18fd:
	/* 0x18fd: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_18ff:
	/* 0x18ff: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1904:
	/* 0x1904: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1906:
	/* 0x1906: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_190b:
	/* 0x190b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1910:
	/* 0x1910: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1914:
	/* 0x1914: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_191c:
	/* 0x191c: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_191e:
	/* 0x191e: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1922:
	/* 0x1922: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1927:
	/* 0x1927: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_192d:
	/* 0x192d: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1930:
	/* 0x1930: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1933:
	/* 0x1933: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1938:
	/* 0x1938: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_193d:
	/* 0x193d: je     1962 <generic_sleepable_preload+0x1962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1962;
	}
x86_l_193f:
	/* 0x193f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1944:
	/* 0x1944: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1949:
	/* 0x1949: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_194e:
	/* 0x194e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1953:
	/* 0x1953: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1958:
	/* 0x1958: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195a:
	/* 0x195a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195c:
	/* 0x195c: js     1c0d <generic_sleepable_preload+0x1c0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c0d;
	}
x86_l_1962:
	/* 0x1962: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1967:
	/* 0x1967: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_196d:
	/* 0x196d: mov    ecx,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1970:
	/* 0x1970: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1975:
	/* 0x1975: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197a:
	/* 0x197a: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_197f:
	/* 0x197f: je     19a4 <generic_sleepable_preload+0x19a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a4;
	}
x86_l_1981:
	/* 0x1981: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1986:
	/* 0x1986: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_198b:
	/* 0x198b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1990:
	/* 0x1990: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1995:
	/* 0x1995: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_199a:
	/* 0x199a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199c:
	/* 0x199c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_199e:
	/* 0x199e: js     1fec <generic_sleepable_preload+0x1fec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8172ULL;
	}
x86_l_19a4:
	/* 0x19a4: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_19ac:
	/* 0x19ac: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_19b2:
	/* 0x19b2: mov    ecx,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19b8:
	/* 0x19b8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19bd:
	/* 0x19bd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c2:
	/* 0x19c2: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_19ca:
	/* 0x19ca: je     19ef <generic_sleepable_preload+0x19ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ef;
	}
x86_l_19cc:
	/* 0x19cc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d1:
	/* 0x19d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19d6:
	/* 0x19d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19db:
	/* 0x19db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e0:
	/* 0x19e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19e5:
	/* 0x19e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e7:
	/* 0x19e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19e9:
	/* 0x19e9: js     2a0d <generic_sleepable_preload+0x2a0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10765ULL;
	}
x86_l_19ef:
	/* 0x19ef: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_19f7:
	/* 0x19f7: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_19fd:
	/* 0x19fd: mov    ecx,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a03:
	/* 0x1a03: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a08:
	/* 0x1a08: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a0d:
	/* 0x1a0d: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1a15:
	/* 0x1a15: je     1a3a <generic_sleepable_preload+0x1a3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a3a;
	}
x86_l_1a17:
	/* 0x1a17: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a1c:
	/* 0x1a1c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a21:
	/* 0x1a21: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a26:
	/* 0x1a26: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a30:
	/* 0x1a30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a32:
	/* 0x1a32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a34:
	/* 0x1a34: js     2a89 <generic_sleepable_preload+0x2a89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10889ULL;
	}
x86_l_1a3a:
	/* 0x1a3a: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1a42:
	/* 0x1a42: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_1a48:
	/* 0x1a48: mov    ecx,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a4e:
	/* 0x1a4e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a53:
	/* 0x1a53: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a58:
	/* 0x1a58: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1a60:
	/* 0x1a60: je     1a85 <generic_sleepable_preload+0x1a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a85;
	}
x86_l_1a62:
	/* 0x1a62: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a67:
	/* 0x1a67: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a6c:
	/* 0x1a6c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a71:
	/* 0x1a71: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a76:
	/* 0x1a76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a7b:
	/* 0x1a7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7d:
	/* 0x1a7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a7f:
	/* 0x1a7f: js     2b05 <generic_sleepable_preload+0x2b05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11013ULL;
	}
x86_l_1a85:
	/* 0x1a85: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1a8d:
	/* 0x1a8d: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_1a93:
	/* 0x1a93: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a99:
	/* 0x1a99: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a9e:
	/* 0x1a9e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa3:
	/* 0x1aa3: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1aab:
	/* 0x1aab: je     1ad0 <generic_sleepable_preload+0x1ad0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ad0;
	}
x86_l_1aad:
	/* 0x1aad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab2:
	/* 0x1ab2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1abc:
	/* 0x1abc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ac6:
	/* 0x1ac6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac8:
	/* 0x1ac8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aca:
	/* 0x1aca: js     2b7e <generic_sleepable_preload+0x2b7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11134ULL;
	}
x86_l_1ad0:
	/* 0x1ad0: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1ad8:
	/* 0x1ad8: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_1ade:
	/* 0x1ade: mov    ecx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ae4:
	/* 0x1ae4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ae9:
	/* 0x1ae9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aee:
	/* 0x1aee: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1af6:
	/* 0x1af6: je     1b1b <generic_sleepable_preload+0x1b1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b1b;
	}
x86_l_1af8:
	/* 0x1af8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1afd:
	/* 0x1afd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b02:
	/* 0x1b02: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b07:
	/* 0x1b07: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b11:
	/* 0x1b11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b13:
	/* 0x1b13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b15:
	/* 0x1b15: js     3006 <generic_sleepable_preload+0x3006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12294ULL;
	}
x86_l_1b1b:
	/* 0x1b1b: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1b23:
	/* 0x1b23: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_1b29:
	/* 0x1b29: mov    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b2f:
	/* 0x1b2f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b34:
	/* 0x1b34: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b39:
	/* 0x1b39: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1b41:
	/* 0x1b41: je     1b66 <generic_sleepable_preload+0x1b66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b66;
	}
x86_l_1b43:
	/* 0x1b43: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b48:
	/* 0x1b48: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b52:
	/* 0x1b52: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b57:
	/* 0x1b57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b5c:
	/* 0x1b5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5e:
	/* 0x1b5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b60:
	/* 0x1b60: js     3417 <generic_sleepable_preload+0x3417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13335ULL;
	}
x86_l_1b66:
	/* 0x1b66: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1b6e:
	/* 0x1b6e: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_1b74:
	/* 0x1b74: mov    ecx,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b7a:
	/* 0x1b7a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b84:
	/* 0x1b84: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1b8c:
	/* 0x1b8c: je     1bb1 <generic_sleepable_preload+0x1bb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb1;
	}
x86_l_1b8e:
	/* 0x1b8e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b93:
	/* 0x1b93: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b98:
	/* 0x1b98: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b9d:
	/* 0x1b9d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba2:
	/* 0x1ba2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ba7:
	/* 0x1ba7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba9:
	/* 0x1ba9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bab:
	/* 0x1bab: js     34e8 <generic_sleepable_preload+0x34e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13544ULL;
	}
x86_l_1bb1:
	/* 0x1bb1: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1bb9:
	/* 0x1bb9: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_1bbf:
	/* 0x1bbf: mov    ecx,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1bc5:
	/* 0x1bc5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1bca:
	/* 0x1bca: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bcf:
	/* 0x1bcf: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1bd7:
	/* 0x1bd7: je     3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12310ULL;
	}
x86_l_1bdd:
	/* 0x1bdd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1be2:
	/* 0x1be2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1be7:
	/* 0x1be7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bec:
	/* 0x1bec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf1:
	/* 0x1bf1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bf6:
	/* 0x1bf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf8:
	/* 0x1bf8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bfa:
	/* 0x1bfa: jns    3016 <generic_sleepable_preload+0x3016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12310ULL;
	}
x86_l_1c00:
	/* 0x1c00: mov    DWORD PTR [rsp+0x18],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215114ULL);
x86_l_1c08:
	/* 0x1c08: jmp    300e <generic_sleepable_preload+0x300e> */
	return 12302ULL;
x86_l_1c0d:
	/* 0x1c0d: mov    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1c15:
	/* 0x1c15: jmp    300e <generic_sleepable_preload+0x300e> */
	return 12302ULL;
x86_l_1c1a:
	/* 0x1c1a: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c1f:
	/* 0x1c1f: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1c22:
	/* 0x1c22: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_1c28:
	/* 0x1c28: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1c2b:
	/* 0x1c2b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c2e:
	/* 0x1c2e: je     2006 <generic_sleepable_preload+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8198ULL;
	}
x86_l_1c34:
	/* 0x1c34: jmp    2019 <generic_sleepable_preload+0x2019> */
	return 8217ULL;
x86_l_1c39:
	/* 0x1c39: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c3e:
	/* 0x1c3e: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1c41:
	/* 0x1c41: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_1c47:
	/* 0x1c47: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1c4a:
	/* 0x1c4a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c4d:
	/* 0x1c4d: je     234a <generic_sleepable_preload+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9034ULL;
	}
x86_l_1c53:
	/* 0x1c53: jmp    235d <generic_sleepable_preload+0x235d> */
	return 9053ULL;
x86_l_1c58:
	/* 0x1c58: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c5d:
	/* 0x1c5d: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1c60:
	/* 0x1c60: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_1c66:
	/* 0x1c66: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1c69:
	/* 0x1c69: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c6c:
	/* 0x1c6c: je     268e <generic_sleepable_preload+0x268e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9870ULL;
	}
x86_l_1c72:
	/* 0x1c72: jmp    26a1 <generic_sleepable_preload+0x26a1> */
	return 9889ULL;
x86_l_1c77:
	/* 0x1c77: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c7c:
	/* 0x1c7c: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1c7f:
	/* 0x1c7f: je     1c89 <generic_sleepable_preload+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c89;
	}
x86_l_1c81:
	/* 0x1c81: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1c84:
	/* 0x1c84: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c87:
	/* 0x1c87: jne    1c9c <generic_sleepable_preload+0x1c9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c9c;
	}
x86_l_1c89:
	/* 0x1c89: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1c8e:
	/* 0x1c8e: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1c90:
	/* 0x1c90: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1c95:
	/* 0x1c95: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c97:
	/* 0x1c97: bzhi   rcx,QWORD PTR [r14],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1c9c:
	/* 0x1c9c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca1:
	/* 0x1ca1: mov    r14d,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ca5:
	/* 0x1ca5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca7:
	/* 0x1ca7: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1caa:
	/* 0x1caa: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_1cb2:
	/* 0x1cb2: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1cb8:
	/* 0x1cb8: mov    eax,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_1cbe:
	/* 0x1cbe: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1cc1:
	/* 0x1cc1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc6:
	/* 0x1cc6: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_1cce:
	/* 0x1cce: je     1cf3 <generic_sleepable_preload+0x1cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7411ULL;
	}
x86_l_1cd0:
	/* 0x1cd0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd5:
	/* 0x1cd5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cda:
	/* 0x1cda: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cdf:
	/* 0x1cdf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 7396ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7403ULL: goto x86_l_1ceb;
	case 7405ULL: goto x86_l_1ced;
	case 7411ULL: goto x86_l_1cf3;
	case 7419ULL: goto x86_l_1cfb;
	case 7425ULL: goto x86_l_1d01;
	case 7431ULL: goto x86_l_1d07;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7449ULL: goto x86_l_1d19;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7478ULL: goto x86_l_1d36;
	case 7480ULL: goto x86_l_1d38;
	case 7486ULL: goto x86_l_1d3e;
	case 7494ULL: goto x86_l_1d46;
	case 7500ULL: goto x86_l_1d4c;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7524ULL: goto x86_l_1d64;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7553ULL: goto x86_l_1d81;
	case 7555ULL: goto x86_l_1d83;
	case 7561ULL: goto x86_l_1d89;
	case 7569ULL: goto x86_l_1d91;
	case 7575ULL: goto x86_l_1d97;
	case 7581ULL: goto x86_l_1d9d;
	case 7586ULL: goto x86_l_1da2;
	case 7591ULL: goto x86_l_1da7;
	case 7599ULL: goto x86_l_1daf;
	case 7601ULL: goto x86_l_1db1;
	case 7606ULL: goto x86_l_1db6;
	case 7611ULL: goto x86_l_1dbb;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7628ULL: goto x86_l_1dcc;
	case 7630ULL: goto x86_l_1dce;
	case 7636ULL: goto x86_l_1dd4;
	case 7644ULL: goto x86_l_1ddc;
	case 7650ULL: goto x86_l_1de2;
	case 7656ULL: goto x86_l_1de8;
	case 7661ULL: goto x86_l_1ded;
	case 7666ULL: goto x86_l_1df2;
	case 7674ULL: goto x86_l_1dfa;
	case 7676ULL: goto x86_l_1dfc;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7701ULL: goto x86_l_1e15;
	case 7703ULL: goto x86_l_1e17;
	case 7705ULL: goto x86_l_1e19;
	case 7711ULL: goto x86_l_1e1f;
	case 7719ULL: goto x86_l_1e27;
	case 7725ULL: goto x86_l_1e2d;
	case 7731ULL: goto x86_l_1e33;
	case 7736ULL: goto x86_l_1e38;
	case 7741ULL: goto x86_l_1e3d;
	case 7749ULL: goto x86_l_1e45;
	case 7751ULL: goto x86_l_1e47;
	case 7756ULL: goto x86_l_1e4c;
	case 7761ULL: goto x86_l_1e51;
	case 7766ULL: goto x86_l_1e56;
	case 7771ULL: goto x86_l_1e5b;
	case 7776ULL: goto x86_l_1e60;
	case 7778ULL: goto x86_l_1e62;
	case 7780ULL: goto x86_l_1e64;
	case 7786ULL: goto x86_l_1e6a;
	case 7794ULL: goto x86_l_1e72;
	case 7800ULL: goto x86_l_1e78;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7816ULL: goto x86_l_1e88;
	case 7824ULL: goto x86_l_1e90;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7853ULL: goto x86_l_1ead;
	case 7855ULL: goto x86_l_1eaf;
	case 7861ULL: goto x86_l_1eb5;
	case 7869ULL: goto x86_l_1ebd;
	case 7875ULL: goto x86_l_1ec3;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7891ULL: goto x86_l_1ed3;
	case 7899ULL: goto x86_l_1edb;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7928ULL: goto x86_l_1ef8;
	case 7930ULL: goto x86_l_1efa;
	case 7936ULL: goto x86_l_1f00;
	case 7944ULL: goto x86_l_1f08;
	case 7950ULL: goto x86_l_1f0e;
	case 7956ULL: goto x86_l_1f14;
	case 7961ULL: goto x86_l_1f19;
	case 7966ULL: goto x86_l_1f1e;
	case 7974ULL: goto x86_l_1f26;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 8001ULL: goto x86_l_1f41;
	case 8003ULL: goto x86_l_1f43;
	case 8005ULL: goto x86_l_1f45;
	case 8011ULL: goto x86_l_1f4b;
	case 8019ULL: goto x86_l_1f53;
	case 8025ULL: goto x86_l_1f59;
	case 8031ULL: goto x86_l_1f5f;
	case 8036ULL: goto x86_l_1f64;
	case 8041ULL: goto x86_l_1f69;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8060ULL: goto x86_l_1f7c;
	case 8065ULL: goto x86_l_1f81;
	case 8070ULL: goto x86_l_1f86;
	case 8075ULL: goto x86_l_1f8b;
	case 8080ULL: goto x86_l_1f90;
	case 8082ULL: goto x86_l_1f92;
	case 8084ULL: goto x86_l_1f94;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8118ULL: goto x86_l_1fb6;
	case 8123ULL: goto x86_l_1fbb;
	case 8131ULL: goto x86_l_1fc3;
	case 8136ULL: goto x86_l_1fc8;
	case 8144ULL: goto x86_l_1fd0;
	case 8149ULL: goto x86_l_1fd5;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8180ULL: goto x86_l_1ff4;
	case 8185ULL: goto x86_l_1ff9;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8198ULL: goto x86_l_2006;
	case 8201ULL: goto x86_l_2009;
	case 8203ULL: goto x86_l_200b;
	case 8205ULL: goto x86_l_200d;
	case 8210ULL: goto x86_l_2012;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8222ULL: goto x86_l_201e;
	case 8226ULL: goto x86_l_2022;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8240ULL: goto x86_l_2030;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8260ULL: goto x86_l_2044;
	case 8263ULL: goto x86_l_2047;
	case 8268ULL: goto x86_l_204c;
	case 8276ULL: goto x86_l_2054;
	case 8278ULL: goto x86_l_2056;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8303ULL: goto x86_l_206f;
	case 8305ULL: goto x86_l_2071;
	case 8307ULL: goto x86_l_2073;
	case 8313ULL: goto x86_l_2079;
	case 8321ULL: goto x86_l_2081;
	case 8327ULL: goto x86_l_2087;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8351ULL: goto x86_l_209f;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8378ULL: goto x86_l_20ba;
	case 8380ULL: goto x86_l_20bc;
	case 8382ULL: goto x86_l_20be;
	case 8388ULL: goto x86_l_20c4;
	case 8396ULL: goto x86_l_20cc;
	case 8402ULL: goto x86_l_20d2;
	case 8408ULL: goto x86_l_20d8;
	case 8413ULL: goto x86_l_20dd;
	case 8418ULL: goto x86_l_20e2;
	case 8426ULL: goto x86_l_20ea;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8438ULL: goto x86_l_20f6;
	case 8443ULL: goto x86_l_20fb;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8455ULL: goto x86_l_2107;
	case 8457ULL: goto x86_l_2109;
	case 8463ULL: goto x86_l_210f;
	case 8471ULL: goto x86_l_2117;
	case 8477ULL: goto x86_l_211d;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8493ULL: goto x86_l_212d;
	case 8501ULL: goto x86_l_2135;
	case 8503ULL: goto x86_l_2137;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8518ULL: goto x86_l_2146;
	case 8523ULL: goto x86_l_214b;
	case 8528ULL: goto x86_l_2150;
	case 8530ULL: goto x86_l_2152;
	case 8532ULL: goto x86_l_2154;
	case 8538ULL: goto x86_l_215a;
	case 8546ULL: goto x86_l_2162;
	case 8552ULL: goto x86_l_2168;
	case 8558ULL: goto x86_l_216e;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8576ULL: goto x86_l_2180;
	case 8578ULL: goto x86_l_2182;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8603ULL: goto x86_l_219b;
	case 8605ULL: goto x86_l_219d;
	case 8607ULL: goto x86_l_219f;
	case 8613ULL: goto x86_l_21a5;
	case 8621ULL: goto x86_l_21ad;
	case 8627ULL: goto x86_l_21b3;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8643ULL: goto x86_l_21c3;
	case 8651ULL: goto x86_l_21cb;
	case 8653ULL: goto x86_l_21cd;
	case 8658ULL: goto x86_l_21d2;
	case 8663ULL: goto x86_l_21d7;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8678ULL: goto x86_l_21e6;
	case 8680ULL: goto x86_l_21e8;
	case 8682ULL: goto x86_l_21ea;
	case 8688ULL: goto x86_l_21f0;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8708ULL: goto x86_l_2204;
	case 8713ULL: goto x86_l_2209;
	case 8718ULL: goto x86_l_220e;
	case 8726ULL: goto x86_l_2216;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8757ULL: goto x86_l_2235;
	case 8763ULL: goto x86_l_223b;
	case 8771ULL: goto x86_l_2243;
	case 8777ULL: goto x86_l_2249;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8793ULL: goto x86_l_2259;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8830ULL: goto x86_l_227e;
	case 8832ULL: goto x86_l_2280;
	case 8838ULL: goto x86_l_2286;
	case 8846ULL: goto x86_l_228e;
	case 8852ULL: goto x86_l_2294;
	case 8858ULL: goto x86_l_229a;
	case 8863ULL: goto x86_l_229f;
	case 8868ULL: goto x86_l_22a4;
	case 8876ULL: goto x86_l_22ac;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8893ULL: goto x86_l_22bd;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8905ULL: goto x86_l_22c9;
	case 8907ULL: goto x86_l_22cb;
	case 8913ULL: goto x86_l_22d1;
	case 8921ULL: goto x86_l_22d9;
	case 8927ULL: goto x86_l_22df;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8943ULL: goto x86_l_22ef;
	case 8951ULL: goto x86_l_22f7;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8984ULL: goto x86_l_2318;
	case 8986ULL: goto x86_l_231a;
	case 8992ULL: goto x86_l_2320;
	case 9000ULL: goto x86_l_2328;
	case 9005ULL: goto x86_l_232d;
	case 9013ULL: goto x86_l_2335;
	case 9018ULL: goto x86_l_233a;
	case 9026ULL: goto x86_l_2342;
	case 9031ULL: goto x86_l_2347;
	case 9034ULL: goto x86_l_234a;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9062ULL: goto x86_l_2366;
	case 9070ULL: goto x86_l_236e;
	case 9072ULL: goto x86_l_2370;
	case 9076ULL: goto x86_l_2374;
	case 9084ULL: goto x86_l_237c;
	case 9090ULL: goto x86_l_2382;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9112ULL: goto x86_l_2398;
	case 9114ULL: goto x86_l_239a;
	case 9119ULL: goto x86_l_239f;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9139ULL: goto x86_l_23b3;
	case 9141ULL: goto x86_l_23b5;
	case 9143ULL: goto x86_l_23b7;
	case 9149ULL: goto x86_l_23bd;
	case 9157ULL: goto x86_l_23c5;
	case 9163ULL: goto x86_l_23cb;
	case 9169ULL: goto x86_l_23d1;
	case 9174ULL: goto x86_l_23d6;
	case 9179ULL: goto x86_l_23db;
	case 9187ULL: goto x86_l_23e3;
	case 9189ULL: goto x86_l_23e5;
	case 9194ULL: goto x86_l_23ea;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9224ULL: goto x86_l_2408;
	case 9232ULL: goto x86_l_2410;
	case 9238ULL: goto x86_l_2416;
	case 9244ULL: goto x86_l_241c;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9262ULL: goto x86_l_242e;
	case 9264ULL: goto x86_l_2430;
	case 9269ULL: goto x86_l_2435;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9284ULL: goto x86_l_2444;
	case 9289ULL: goto x86_l_2449;
	case 9291ULL: goto x86_l_244b;
	case 9293ULL: goto x86_l_244d;
	case 9299ULL: goto x86_l_2453;
	case 9307ULL: goto x86_l_245b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ce4:
	/* 0x1ce4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ce9:
	/* 0x1ce9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ceb:
	/* 0x1ceb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ced:
	/* 0x1ced: js     1fa4 <generic_sleepable_preload+0x1fa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1fa4;
	}
x86_l_1cf3:
	/* 0x1cf3: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_1cfb:
	/* 0x1cfb: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1d01:
	/* 0x1d01: mov    ecx,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_1d07:
	/* 0x1d07: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d0c:
	/* 0x1d0c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d11:
	/* 0x1d11: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_1d19:
	/* 0x1d19: je     1d3e <generic_sleepable_preload+0x1d3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3e;
	}
x86_l_1d1b:
	/* 0x1d1b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d20:
	/* 0x1d20: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d25:
	/* 0x1d25: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d2f:
	/* 0x1d2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d34:
	/* 0x1d34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d36:
	/* 0x1d36: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d38:
	/* 0x1d38: js     1ff9 <generic_sleepable_preload+0x1ff9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ff9;
	}
x86_l_1d3e:
	/* 0x1d3e: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_1d46:
	/* 0x1d46: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1d4c:
	/* 0x1d4c: mov    ecx,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_1d52:
	/* 0x1d52: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d57:
	/* 0x1d57: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d5c:
	/* 0x1d5c: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_1d64:
	/* 0x1d64: je     1d89 <generic_sleepable_preload+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d89;
	}
x86_l_1d66:
	/* 0x1d66: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d70:
	/* 0x1d70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d75:
	/* 0x1d75: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d7f:
	/* 0x1d7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d81:
	/* 0x1d81: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d83:
	/* 0x1d83: js     2a1a <generic_sleepable_preload+0x2a1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10778ULL;
	}
x86_l_1d89:
	/* 0x1d89: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_1d91:
	/* 0x1d91: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1d97:
	/* 0x1d97: mov    ecx,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_1d9d:
	/* 0x1d9d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1da2:
	/* 0x1da2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da7:
	/* 0x1da7: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_1daf:
	/* 0x1daf: je     1dd4 <generic_sleepable_preload+0x1dd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd4;
	}
x86_l_1db1:
	/* 0x1db1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1db6:
	/* 0x1db6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1dbb:
	/* 0x1dbb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dca:
	/* 0x1dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcc:
	/* 0x1dcc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dce:
	/* 0x1dce: js     2a96 <generic_sleepable_preload+0x2a96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10902ULL;
	}
x86_l_1dd4:
	/* 0x1dd4: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_1ddc:
	/* 0x1ddc: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1de2:
	/* 0x1de2: mov    ecx,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_1de8:
	/* 0x1de8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ded:
	/* 0x1ded: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df2:
	/* 0x1df2: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_1dfa:
	/* 0x1dfa: je     1e1f <generic_sleepable_preload+0x1e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e1f;
	}
x86_l_1dfc:
	/* 0x1dfc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e01:
	/* 0x1e01: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e06:
	/* 0x1e06: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e10:
	/* 0x1e10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e15:
	/* 0x1e15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e17:
	/* 0x1e17: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e19:
	/* 0x1e19: js     2b12 <generic_sleepable_preload+0x2b12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11026ULL;
	}
x86_l_1e1f:
	/* 0x1e1f: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_1e27:
	/* 0x1e27: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1e2d:
	/* 0x1e2d: mov    ecx,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_1e33:
	/* 0x1e33: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e38:
	/* 0x1e38: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e3d:
	/* 0x1e3d: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_1e45:
	/* 0x1e45: je     1e6a <generic_sleepable_preload+0x1e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e6a;
	}
x86_l_1e47:
	/* 0x1e47: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e51:
	/* 0x1e51: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e56:
	/* 0x1e56: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5b:
	/* 0x1e5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e60:
	/* 0x1e60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e62:
	/* 0x1e62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e64:
	/* 0x1e64: js     2b8b <generic_sleepable_preload+0x2b8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11147ULL;
	}
x86_l_1e6a:
	/* 0x1e6a: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_1e72:
	/* 0x1e72: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1e78:
	/* 0x1e78: mov    ecx,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_1e7e:
	/* 0x1e7e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e83:
	/* 0x1e83: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e88:
	/* 0x1e88: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_1e90:
	/* 0x1e90: je     1eb5 <generic_sleepable_preload+0x1eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eb5;
	}
x86_l_1e92:
	/* 0x1e92: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e97:
	/* 0x1e97: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ea1:
	/* 0x1ea1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eab:
	/* 0x1eab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ead:
	/* 0x1ead: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eaf:
	/* 0x1eaf: js     30e3 <generic_sleepable_preload+0x30e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12515ULL;
	}
x86_l_1eb5:
	/* 0x1eb5: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_1ebd:
	/* 0x1ebd: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1ec3:
	/* 0x1ec3: mov    ecx,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_1ec9:
	/* 0x1ec9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ece:
	/* 0x1ece: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ed3:
	/* 0x1ed3: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_1edb:
	/* 0x1edb: je     1f00 <generic_sleepable_preload+0x1f00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f00;
	}
x86_l_1edd:
	/* 0x1edd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ee2:
	/* 0x1ee2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ee7:
	/* 0x1ee7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1eec:
	/* 0x1eec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ef6:
	/* 0x1ef6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef8:
	/* 0x1ef8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1efa:
	/* 0x1efa: js     3436 <generic_sleepable_preload+0x3436> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13366ULL;
	}
x86_l_1f00:
	/* 0x1f00: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_1f08:
	/* 0x1f08: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1f0e:
	/* 0x1f0e: mov    ecx,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1f14:
	/* 0x1f14: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1f19:
	/* 0x1f19: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f1e:
	/* 0x1f1e: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_1f26:
	/* 0x1f26: je     1f4b <generic_sleepable_preload+0x1f4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f4b;
	}
x86_l_1f28:
	/* 0x1f28: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f32:
	/* 0x1f32: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f37:
	/* 0x1f37: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f3c:
	/* 0x1f3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f41:
	/* 0x1f41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f43:
	/* 0x1f43: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f45:
	/* 0x1f45: js     34f5 <generic_sleepable_preload+0x34f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13557ULL;
	}
x86_l_1f4b:
	/* 0x1f4b: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_1f53:
	/* 0x1f53: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1f59:
	/* 0x1f59: mov    ecx,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_1f5f:
	/* 0x1f5f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1f64:
	/* 0x1f64: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f69:
	/* 0x1f69: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_1f71:
	/* 0x1f71: je     30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_1f77:
	/* 0x1f77: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f7c:
	/* 0x1f7c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f81:
	/* 0x1f81: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f86:
	/* 0x1f86: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f90:
	/* 0x1f90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f92:
	/* 0x1f92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f94:
	/* 0x1f94: jns    30eb <generic_sleepable_preload+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12523ULL;
	}
x86_l_1f9a:
	/* 0x1f9a: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1f9f:
	/* 0x1f9f: jmp    30e8 <generic_sleepable_preload+0x30e8> */
	return 12520ULL;
x86_l_1fa4:
	/* 0x1fa4: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1fa9:
	/* 0x1fa9: jmp    30e8 <generic_sleepable_preload+0x30e8> */
	return 12520ULL;
x86_l_1fae:
	/* 0x1fae: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_1fb6:
	/* 0x1fb6: jmp    2bc4 <generic_sleepable_preload+0x2bc4> */
	return 11204ULL;
x86_l_1fbb:
	/* 0x1fbb: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_1fc3:
	/* 0x1fc3: jmp    2c91 <generic_sleepable_preload+0x2c91> */
	return 11409ULL;
x86_l_1fc8:
	/* 0x1fc8: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_1fd0:
	/* 0x1fd0: jmp    2d8c <generic_sleepable_preload+0x2d8c> */
	return 11660ULL;
x86_l_1fd5:
	/* 0x1fd5: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_1fdd:
	/* 0x1fdd: jmp    2e87 <generic_sleepable_preload+0x2e87> */
	return 11911ULL;
x86_l_1fe2:
	/* 0x1fe2: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1fe7:
	/* 0x1fe7: jmp    2f7f <generic_sleepable_preload+0x2f7f> */
	return 12159ULL;
x86_l_1fec:
	/* 0x1fec: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_1ff4:
	/* 0x1ff4: jmp    300e <generic_sleepable_preload+0x300e> */
	return 12302ULL;
x86_l_1ff9:
	/* 0x1ff9: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1ffe:
	/* 0x1ffe: jmp    30e8 <generic_sleepable_preload+0x30e8> */
	return 12520ULL;
x86_l_2003:
	/* 0x2003: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2006:
	/* 0x2006: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2009:
	/* 0x2009: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_200b:
	/* 0x200b: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_200d:
	/* 0x200d: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2012:
	/* 0x2012: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2014:
	/* 0x2014: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2019:
	/* 0x2019: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_201e:
	/* 0x201e: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2022:
	/* 0x2022: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_202a:
	/* 0x202a: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_202c:
	/* 0x202c: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2030:
	/* 0x2030: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_2038:
	/* 0x2038: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_203e:
	/* 0x203e: mov    eax,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2044:
	/* 0x2044: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2047:
	/* 0x2047: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_204c:
	/* 0x204c: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_2054:
	/* 0x2054: je     2079 <generic_sleepable_preload+0x2079> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2079;
	}
x86_l_2056:
	/* 0x2056: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_205b:
	/* 0x205b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2060:
	/* 0x2060: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2065:
	/* 0x2065: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_206a:
	/* 0x206a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_206f:
	/* 0x206f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2071:
	/* 0x2071: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2073:
	/* 0x2073: js     232d <generic_sleepable_preload+0x232d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_232d;
	}
x86_l_2079:
	/* 0x2079: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2081:
	/* 0x2081: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_2087:
	/* 0x2087: mov    ecx,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_208d:
	/* 0x208d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2092:
	/* 0x2092: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2097:
	/* 0x2097: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_209f:
	/* 0x209f: je     20c4 <generic_sleepable_preload+0x20c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c4;
	}
x86_l_20a1:
	/* 0x20a1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20a6:
	/* 0x20a6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20ab:
	/* 0x20ab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20b0:
	/* 0x20b0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b5:
	/* 0x20b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20ba:
	/* 0x20ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20bc:
	/* 0x20bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20be:
	/* 0x20be: js     233a <generic_sleepable_preload+0x233a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_233a;
	}
x86_l_20c4:
	/* 0x20c4: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_20cc:
	/* 0x20cc: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_20d2:
	/* 0x20d2: mov    ecx,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_20d8:
	/* 0x20d8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_20dd:
	/* 0x20dd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e2:
	/* 0x20e2: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_20ea:
	/* 0x20ea: je     210f <generic_sleepable_preload+0x210f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_210f;
	}
x86_l_20ec:
	/* 0x20ec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f1:
	/* 0x20f1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20f6:
	/* 0x20f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20fb:
	/* 0x20fb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2100:
	/* 0x2100: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2105:
	/* 0x2105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2107:
	/* 0x2107: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2109:
	/* 0x2109: js     2a24 <generic_sleepable_preload+0x2a24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10788ULL;
	}
x86_l_210f:
	/* 0x210f: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2117:
	/* 0x2117: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_211d:
	/* 0x211d: mov    ecx,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2123:
	/* 0x2123: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2128:
	/* 0x2128: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_212d:
	/* 0x212d: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2135:
	/* 0x2135: je     215a <generic_sleepable_preload+0x215a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_215a;
	}
x86_l_2137:
	/* 0x2137: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213c:
	/* 0x213c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2141:
	/* 0x2141: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2146:
	/* 0x2146: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_214b:
	/* 0x214b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2150:
	/* 0x2150: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2152:
	/* 0x2152: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2154:
	/* 0x2154: js     2aa0 <generic_sleepable_preload+0x2aa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10912ULL;
	}
x86_l_215a:
	/* 0x215a: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2162:
	/* 0x2162: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_2168:
	/* 0x2168: mov    ecx,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_216e:
	/* 0x216e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2173:
	/* 0x2173: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2178:
	/* 0x2178: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2180:
	/* 0x2180: je     21a5 <generic_sleepable_preload+0x21a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a5;
	}
x86_l_2182:
	/* 0x2182: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2187:
	/* 0x2187: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_218c:
	/* 0x218c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2191:
	/* 0x2191: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2196:
	/* 0x2196: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_219b:
	/* 0x219b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219d:
	/* 0x219d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_219f:
	/* 0x219f: js     2b1c <generic_sleepable_preload+0x2b1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11036ULL;
	}
x86_l_21a5:
	/* 0x21a5: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_21ad:
	/* 0x21ad: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_21b3:
	/* 0x21b3: mov    ecx,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_21b9:
	/* 0x21b9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_21be:
	/* 0x21be: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21c3:
	/* 0x21c3: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_21cb:
	/* 0x21cb: je     21f0 <generic_sleepable_preload+0x21f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f0;
	}
x86_l_21cd:
	/* 0x21cd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d2:
	/* 0x21d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21d7:
	/* 0x21d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21dc:
	/* 0x21dc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e1:
	/* 0x21e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e6:
	/* 0x21e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e8:
	/* 0x21e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21ea:
	/* 0x21ea: js     2b95 <generic_sleepable_preload+0x2b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11157ULL;
	}
x86_l_21f0:
	/* 0x21f0: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_21f8:
	/* 0x21f8: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_21fe:
	/* 0x21fe: mov    ecx,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2204:
	/* 0x2204: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2209:
	/* 0x2209: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_220e:
	/* 0x220e: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2216:
	/* 0x2216: je     223b <generic_sleepable_preload+0x223b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223b;
	}
x86_l_2218:
	/* 0x2218: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_221d:
	/* 0x221d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2222:
	/* 0x2222: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2227:
	/* 0x2227: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222c:
	/* 0x222c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2231:
	/* 0x2231: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2233:
	/* 0x2233: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2235:
	/* 0x2235: js     3194 <generic_sleepable_preload+0x3194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12692ULL;
	}
x86_l_223b:
	/* 0x223b: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2243:
	/* 0x2243: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_2249:
	/* 0x2249: mov    ecx,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_224f:
	/* 0x224f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2254:
	/* 0x2254: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2259:
	/* 0x2259: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2261:
	/* 0x2261: je     2286 <generic_sleepable_preload+0x2286> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2286;
	}
x86_l_2263:
	/* 0x2263: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2268:
	/* 0x2268: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_226d:
	/* 0x226d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2272:
	/* 0x2272: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2277:
	/* 0x2277: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_227c:
	/* 0x227c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227e:
	/* 0x227e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2280:
	/* 0x2280: js     344d <generic_sleepable_preload+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13389ULL;
	}
x86_l_2286:
	/* 0x2286: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_228e:
	/* 0x228e: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_2294:
	/* 0x2294: mov    ecx,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_229a:
	/* 0x229a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_229f:
	/* 0x229f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a4:
	/* 0x22a4: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_22ac:
	/* 0x22ac: je     22d1 <generic_sleepable_preload+0x22d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22d1;
	}
x86_l_22ae:
	/* 0x22ae: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22b3:
	/* 0x22b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22b8:
	/* 0x22b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22bd:
	/* 0x22bd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c2:
	/* 0x22c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22c7:
	/* 0x22c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c9:
	/* 0x22c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22cb:
	/* 0x22cb: js     34ff <generic_sleepable_preload+0x34ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13567ULL;
	}
x86_l_22d1:
	/* 0x22d1: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_22d9:
	/* 0x22d9: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_22df:
	/* 0x22df: mov    ecx,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_22e5:
	/* 0x22e5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_22ea:
	/* 0x22ea: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ef:
	/* 0x22ef: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_22f7:
	/* 0x22f7: je     31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12708ULL;
	}
x86_l_22fd:
	/* 0x22fd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2302:
	/* 0x2302: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2307:
	/* 0x2307: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_230c:
	/* 0x230c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2311:
	/* 0x2311: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2316:
	/* 0x2316: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2318:
	/* 0x2318: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_231a:
	/* 0x231a: jns    31a4 <generic_sleepable_preload+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12708ULL;
	}
x86_l_2320:
	/* 0x2320: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_2328:
	/* 0x2328: jmp    319c <generic_sleepable_preload+0x319c> */
	return 12700ULL;
x86_l_232d:
	/* 0x232d: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_2335:
	/* 0x2335: jmp    319c <generic_sleepable_preload+0x319c> */
	return 12700ULL;
x86_l_233a:
	/* 0x233a: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_2342:
	/* 0x2342: jmp    319c <generic_sleepable_preload+0x319c> */
	return 12700ULL;
x86_l_2347:
	/* 0x2347: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_234a:
	/* 0x234a: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_234d:
	/* 0x234d: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_234f:
	/* 0x234f: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2351:
	/* 0x2351: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2356:
	/* 0x2356: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2358:
	/* 0x2358: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_235d:
	/* 0x235d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2362:
	/* 0x2362: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2366:
	/* 0x2366: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_236e:
	/* 0x236e: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_2370:
	/* 0x2370: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2374:
	/* 0x2374: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_237c:
	/* 0x237c: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_2382:
	/* 0x2382: mov    eax,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2388:
	/* 0x2388: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_238b:
	/* 0x238b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2390:
	/* 0x2390: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_2398:
	/* 0x2398: je     23bd <generic_sleepable_preload+0x23bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23bd;
	}
x86_l_239a:
	/* 0x239a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239f:
	/* 0x239f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23a4:
	/* 0x23a4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23a9:
	/* 0x23a9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ae:
	/* 0x23ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b3:
	/* 0x23b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b5:
	/* 0x23b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23b7:
	/* 0x23b7: js     2671 <generic_sleepable_preload+0x2671> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9841ULL;
	}
x86_l_23bd:
	/* 0x23bd: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_23c5:
	/* 0x23c5: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_23cb:
	/* 0x23cb: mov    ecx,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_23d1:
	/* 0x23d1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_23d6:
	/* 0x23d6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23db:
	/* 0x23db: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_23e3:
	/* 0x23e3: je     2408 <generic_sleepable_preload+0x2408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2408;
	}
x86_l_23e5:
	/* 0x23e5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ea:
	/* 0x23ea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23ef:
	/* 0x23ef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23f4:
	/* 0x23f4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23f9:
	/* 0x23f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23fe:
	/* 0x23fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2400:
	/* 0x2400: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2402:
	/* 0x2402: js     267e <generic_sleepable_preload+0x267e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9854ULL;
	}
x86_l_2408:
	/* 0x2408: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2410:
	/* 0x2410: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_2416:
	/* 0x2416: mov    ecx,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_241c:
	/* 0x241c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2421:
	/* 0x2421: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2426:
	/* 0x2426: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_242e:
	/* 0x242e: je     2453 <generic_sleepable_preload+0x2453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2453;
	}
x86_l_2430:
	/* 0x2430: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2435:
	/* 0x2435: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_243a:
	/* 0x243a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_243f:
	/* 0x243f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2444:
	/* 0x2444: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2449:
	/* 0x2449: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244b:
	/* 0x244b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_244d:
	/* 0x244d: js     2a31 <generic_sleepable_preload+0x2a31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10801ULL;
	}
x86_l_2453:
	/* 0x2453: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_245b:
	/* 0x245b: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
	return 9313ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9313ULL: goto x86_l_2461;
	case 9319ULL: goto x86_l_2467;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9337ULL: goto x86_l_2479;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9366ULL: goto x86_l_2496;
	case 9368ULL: goto x86_l_2498;
	case 9374ULL: goto x86_l_249e;
	case 9382ULL: goto x86_l_24a6;
	case 9388ULL: goto x86_l_24ac;
	case 9394ULL: goto x86_l_24b2;
	case 9399ULL: goto x86_l_24b7;
	case 9404ULL: goto x86_l_24bc;
	case 9412ULL: goto x86_l_24c4;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9439ULL: goto x86_l_24df;
	case 9441ULL: goto x86_l_24e1;
	case 9443ULL: goto x86_l_24e3;
	case 9449ULL: goto x86_l_24e9;
	case 9457ULL: goto x86_l_24f1;
	case 9463ULL: goto x86_l_24f7;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9487ULL: goto x86_l_250f;
	case 9489ULL: goto x86_l_2511;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9516ULL: goto x86_l_252c;
	case 9518ULL: goto x86_l_252e;
	case 9524ULL: goto x86_l_2534;
	case 9532ULL: goto x86_l_253c;
	case 9538ULL: goto x86_l_2542;
	case 9544ULL: goto x86_l_2548;
	case 9549ULL: goto x86_l_254d;
	case 9554ULL: goto x86_l_2552;
	case 9562ULL: goto x86_l_255a;
	case 9564ULL: goto x86_l_255c;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9591ULL: goto x86_l_2577;
	case 9593ULL: goto x86_l_2579;
	case 9599ULL: goto x86_l_257f;
	case 9607ULL: goto x86_l_2587;
	case 9613ULL: goto x86_l_258d;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9629ULL: goto x86_l_259d;
	case 9637ULL: goto x86_l_25a5;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9664ULL: goto x86_l_25c0;
	case 9666ULL: goto x86_l_25c2;
	case 9668ULL: goto x86_l_25c4;
	case 9674ULL: goto x86_l_25ca;
	case 9682ULL: goto x86_l_25d2;
	case 9688ULL: goto x86_l_25d8;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9704ULL: goto x86_l_25e8;
	case 9712ULL: goto x86_l_25f0;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9741ULL: goto x86_l_260d;
	case 9743ULL: goto x86_l_260f;
	case 9749ULL: goto x86_l_2615;
	case 9757ULL: goto x86_l_261d;
	case 9763ULL: goto x86_l_2623;
	case 9769ULL: goto x86_l_2629;
	case 9774ULL: goto x86_l_262e;
	case 9779ULL: goto x86_l_2633;
	case 9787ULL: goto x86_l_263b;
	case 9793ULL: goto x86_l_2641;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9820ULL: goto x86_l_265c;
	case 9822ULL: goto x86_l_265e;
	case 9828ULL: goto x86_l_2664;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9862ULL: goto x86_l_2686;
	case 9867ULL: goto x86_l_268b;
	case 9870ULL: goto x86_l_268e;
	case 9873ULL: goto x86_l_2691;
	case 9875ULL: goto x86_l_2693;
	case 9877ULL: goto x86_l_2695;
	case 9882ULL: goto x86_l_269a;
	case 9884ULL: goto x86_l_269c;
	case 9889ULL: goto x86_l_26a1;
	case 9894ULL: goto x86_l_26a6;
	case 9898ULL: goto x86_l_26aa;
	case 9906ULL: goto x86_l_26b2;
	case 9908ULL: goto x86_l_26b4;
	case 9912ULL: goto x86_l_26b8;
	case 9920ULL: goto x86_l_26c0;
	case 9926ULL: goto x86_l_26c6;
	case 9932ULL: goto x86_l_26cc;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9948ULL: goto x86_l_26dc;
	case 9950ULL: goto x86_l_26de;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9970ULL: goto x86_l_26f2;
	case 9975ULL: goto x86_l_26f7;
	case 9977ULL: goto x86_l_26f9;
	case 9979ULL: goto x86_l_26fb;
	case 9985ULL: goto x86_l_2701;
	case 9993ULL: goto x86_l_2709;
	case 9999ULL: goto x86_l_270f;
	case 10005ULL: goto x86_l_2715;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10023ULL: goto x86_l_2727;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10052ULL: goto x86_l_2744;
	case 10054ULL: goto x86_l_2746;
	case 10060ULL: goto x86_l_274c;
	case 10068ULL: goto x86_l_2754;
	case 10074ULL: goto x86_l_275a;
	case 10080ULL: goto x86_l_2760;
	case 10085ULL: goto x86_l_2765;
	case 10090ULL: goto x86_l_276a;
	case 10098ULL: goto x86_l_2772;
	case 10100ULL: goto x86_l_2774;
	case 10105ULL: goto x86_l_2779;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10129ULL: goto x86_l_2791;
	case 10135ULL: goto x86_l_2797;
	case 10143ULL: goto x86_l_279f;
	case 10149ULL: goto x86_l_27a5;
	case 10155ULL: goto x86_l_27ab;
	case 10160ULL: goto x86_l_27b0;
	case 10165ULL: goto x86_l_27b5;
	case 10173ULL: goto x86_l_27bd;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10204ULL: goto x86_l_27dc;
	case 10210ULL: goto x86_l_27e2;
	case 10218ULL: goto x86_l_27ea;
	case 10224ULL: goto x86_l_27f0;
	case 10230ULL: goto x86_l_27f6;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10248ULL: goto x86_l_2808;
	case 10250ULL: goto x86_l_280a;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10277ULL: goto x86_l_2825;
	case 10279ULL: goto x86_l_2827;
	case 10285ULL: goto x86_l_282d;
	case 10293ULL: goto x86_l_2835;
	case 10299ULL: goto x86_l_283b;
	case 10305ULL: goto x86_l_2841;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10323ULL: goto x86_l_2853;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10350ULL: goto x86_l_286e;
	case 10352ULL: goto x86_l_2870;
	case 10354ULL: goto x86_l_2872;
	case 10360ULL: goto x86_l_2878;
	case 10368ULL: goto x86_l_2880;
	case 10374ULL: goto x86_l_2886;
	case 10380ULL: goto x86_l_288c;
	case 10385ULL: goto x86_l_2891;
	case 10390ULL: goto x86_l_2896;
	case 10398ULL: goto x86_l_289e;
	case 10400ULL: goto x86_l_28a0;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10427ULL: goto x86_l_28bb;
	case 10429ULL: goto x86_l_28bd;
	case 10435ULL: goto x86_l_28c3;
	case 10443ULL: goto x86_l_28cb;
	case 10449ULL: goto x86_l_28d1;
	case 10455ULL: goto x86_l_28d7;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10473ULL: goto x86_l_28e9;
	case 10475ULL: goto x86_l_28eb;
	case 10480ULL: goto x86_l_28f0;
	case 10485ULL: goto x86_l_28f5;
	case 10490ULL: goto x86_l_28fa;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10502ULL: goto x86_l_2906;
	case 10504ULL: goto x86_l_2908;
	case 10510ULL: goto x86_l_290e;
	case 10518ULL: goto x86_l_2916;
	case 10524ULL: goto x86_l_291c;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10548ULL: goto x86_l_2934;
	case 10550ULL: goto x86_l_2936;
	case 10555ULL: goto x86_l_293b;
	case 10560ULL: goto x86_l_2940;
	case 10565ULL: goto x86_l_2945;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10577ULL: goto x86_l_2951;
	case 10579ULL: goto x86_l_2953;
	case 10585ULL: goto x86_l_2959;
	case 10593ULL: goto x86_l_2961;
	case 10599ULL: goto x86_l_2967;
	case 10605ULL: goto x86_l_296d;
	case 10610ULL: goto x86_l_2972;
	case 10615ULL: goto x86_l_2977;
	case 10623ULL: goto x86_l_297f;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10644ULL: goto x86_l_2994;
	case 10649ULL: goto x86_l_2999;
	case 10654ULL: goto x86_l_299e;
	case 10656ULL: goto x86_l_29a0;
	case 10658ULL: goto x86_l_29a2;
	case 10664ULL: goto x86_l_29a8;
	case 10672ULL: goto x86_l_29b0;
	case 10677ULL: goto x86_l_29b5;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10698ULL: goto x86_l_29ca;
	case 10703ULL: goto x86_l_29cf;
	case 10711ULL: goto x86_l_29d7;
	case 10716ULL: goto x86_l_29dc;
	case 10724ULL: goto x86_l_29e4;
	case 10729ULL: goto x86_l_29e9;
	case 10737ULL: goto x86_l_29f1;
	case 10742ULL: goto x86_l_29f6;
	case 10750ULL: goto x86_l_29fe;
	case 10755ULL: goto x86_l_2a03;
	case 10760ULL: goto x86_l_2a08;
	case 10765ULL: goto x86_l_2a0d;
	case 10773ULL: goto x86_l_2a15;
	case 10778ULL: goto x86_l_2a1a;
	case 10783ULL: goto x86_l_2a1f;
	case 10788ULL: goto x86_l_2a24;
	case 10796ULL: goto x86_l_2a2c;
	case 10801ULL: goto x86_l_2a31;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10822ULL: goto x86_l_2a46;
	case 10827ULL: goto x86_l_2a4b;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10848ULL: goto x86_l_2a60;
	case 10853ULL: goto x86_l_2a65;
	case 10861ULL: goto x86_l_2a6d;
	case 10866ULL: goto x86_l_2a72;
	case 10874ULL: goto x86_l_2a7a;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10889ULL: goto x86_l_2a89;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10907ULL: goto x86_l_2a9b;
	case 10912ULL: goto x86_l_2aa0;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10933ULL: goto x86_l_2ab5;
	case 10938ULL: goto x86_l_2aba;
	case 10946ULL: goto x86_l_2ac2;
	case 10951ULL: goto x86_l_2ac7;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10985ULL: goto x86_l_2ae9;
	case 10990ULL: goto x86_l_2aee;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11013ULL: goto x86_l_2b05;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11031ULL: goto x86_l_2b17;
	case 11036ULL: goto x86_l_2b1c;
	case 11044ULL: goto x86_l_2b24;
	case 11049ULL: goto x86_l_2b29;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11070ULL: goto x86_l_2b3e;
	case 11075ULL: goto x86_l_2b43;
	case 11083ULL: goto x86_l_2b4b;
	case 11085ULL: goto x86_l_2b4d;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11119ULL: goto x86_l_2b6f;
	case 11124ULL: goto x86_l_2b74;
	case 11129ULL: goto x86_l_2b79;
	case 11134ULL: goto x86_l_2b7e;
	case 11142ULL: goto x86_l_2b86;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11157ULL: goto x86_l_2b95;
	case 11165ULL: goto x86_l_2b9d;
	case 11170ULL: goto x86_l_2ba2;
	case 11178ULL: goto x86_l_2baa;
	case 11183ULL: goto x86_l_2baf;
	case 11191ULL: goto x86_l_2bb7;
	case 11196ULL: goto x86_l_2bbc;
	case 11204ULL: goto x86_l_2bc4;
	case 11212ULL: goto x86_l_2bcc;
	case 11216ULL: goto x86_l_2bd0;
	case 11221ULL: goto x86_l_2bd5;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11236ULL: goto x86_l_2be4;
	case 11239ULL: goto x86_l_2be7;
	case 11241ULL: goto x86_l_2be9;
	case 11245ULL: goto x86_l_2bed;
	case 11251ULL: goto x86_l_2bf3;
	case 11256ULL: goto x86_l_2bf8;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11268ULL: goto x86_l_2c04;
	case 11273ULL: goto x86_l_2c09;
	case 11281ULL: goto x86_l_2c11;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11298ULL: goto x86_l_2c22;
	case 11300ULL: goto x86_l_2c24;
	case 11303ULL: goto x86_l_2c27;
	case 11309ULL: goto x86_l_2c2d;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11320ULL: goto x86_l_2c38;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2461:
	/* 0x2461: mov    ecx,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2467:
	/* 0x2467: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_246c:
	/* 0x246c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2471:
	/* 0x2471: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2479:
	/* 0x2479: je     249e <generic_sleepable_preload+0x249e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_249e;
	}
x86_l_247b:
	/* 0x247b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2480:
	/* 0x2480: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2485:
	/* 0x2485: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_248a:
	/* 0x248a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_248f:
	/* 0x248f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2494:
	/* 0x2494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2496:
	/* 0x2496: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2498:
	/* 0x2498: js     2aad <generic_sleepable_preload+0x2aad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2aad;
	}
x86_l_249e:
	/* 0x249e: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_24a6:
	/* 0x24a6: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_24ac:
	/* 0x24ac: mov    ecx,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_24b2:
	/* 0x24b2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_24b7:
	/* 0x24b7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24bc:
	/* 0x24bc: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_24c4:
	/* 0x24c4: je     24e9 <generic_sleepable_preload+0x24e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e9;
	}
x86_l_24c6:
	/* 0x24c6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24cb:
	/* 0x24cb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24d0:
	/* 0x24d0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24d5:
	/* 0x24d5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24da:
	/* 0x24da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24df:
	/* 0x24df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e1:
	/* 0x24e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24e3:
	/* 0x24e3: js     2b29 <generic_sleepable_preload+0x2b29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b29;
	}
x86_l_24e9:
	/* 0x24e9: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_24f1:
	/* 0x24f1: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_24f7:
	/* 0x24f7: mov    ecx,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_24fd:
	/* 0x24fd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2502:
	/* 0x2502: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2507:
	/* 0x2507: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_250f:
	/* 0x250f: je     2534 <generic_sleepable_preload+0x2534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2534;
	}
x86_l_2511:
	/* 0x2511: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2516:
	/* 0x2516: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_251b:
	/* 0x251b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2520:
	/* 0x2520: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2525:
	/* 0x2525: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_252a:
	/* 0x252a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252c:
	/* 0x252c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_252e:
	/* 0x252e: js     2ba2 <generic_sleepable_preload+0x2ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ba2;
	}
x86_l_2534:
	/* 0x2534: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_253c:
	/* 0x253c: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_2542:
	/* 0x2542: mov    ecx,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2548:
	/* 0x2548: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_254d:
	/* 0x254d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2552:
	/* 0x2552: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_255a:
	/* 0x255a: je     257f <generic_sleepable_preload+0x257f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257f;
	}
x86_l_255c:
	/* 0x255c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2561:
	/* 0x2561: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2566:
	/* 0x2566: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_256b:
	/* 0x256b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2570:
	/* 0x2570: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2575:
	/* 0x2575: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2577:
	/* 0x2577: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2579:
	/* 0x2579: js     324a <generic_sleepable_preload+0x324a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12874ULL;
	}
x86_l_257f:
	/* 0x257f: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2587:
	/* 0x2587: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_258d:
	/* 0x258d: mov    ecx,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2593:
	/* 0x2593: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2598:
	/* 0x2598: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_259d:
	/* 0x259d: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_25a5:
	/* 0x25a5: je     25ca <generic_sleepable_preload+0x25ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ca;
	}
x86_l_25a7:
	/* 0x25a7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ac:
	/* 0x25ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25b1:
	/* 0x25b1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25b6:
	/* 0x25b6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25bb:
	/* 0x25bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25c0:
	/* 0x25c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c2:
	/* 0x25c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25c4:
	/* 0x25c4: js     346c <generic_sleepable_preload+0x346c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13420ULL;
	}
x86_l_25ca:
	/* 0x25ca: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_25d2:
	/* 0x25d2: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_25d8:
	/* 0x25d8: mov    ecx,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_25de:
	/* 0x25de: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_25e3:
	/* 0x25e3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25e8:
	/* 0x25e8: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_25f0:
	/* 0x25f0: je     2615 <generic_sleepable_preload+0x2615> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2615;
	}
x86_l_25f2:
	/* 0x25f2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25f7:
	/* 0x25f7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25fc:
	/* 0x25fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2601:
	/* 0x2601: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2606:
	/* 0x2606: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_260b:
	/* 0x260b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260d:
	/* 0x260d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_260f:
	/* 0x260f: js     350c <generic_sleepable_preload+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13580ULL;
	}
x86_l_2615:
	/* 0x2615: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_261d:
	/* 0x261d: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_2623:
	/* 0x2623: mov    ecx,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2629:
	/* 0x2629: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_262e:
	/* 0x262e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2633:
	/* 0x2633: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_263b:
	/* 0x263b: je     325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12890ULL;
	}
x86_l_2641:
	/* 0x2641: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2646:
	/* 0x2646: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_264b:
	/* 0x264b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2650:
	/* 0x2650: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2655:
	/* 0x2655: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_265a:
	/* 0x265a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265c:
	/* 0x265c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_265e:
	/* 0x265e: jns    325a <generic_sleepable_preload+0x325a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12890ULL;
	}
x86_l_2664:
	/* 0x2664: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_266c:
	/* 0x266c: jmp    3252 <generic_sleepable_preload+0x3252> */
	return 12882ULL;
x86_l_2671:
	/* 0x2671: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_2679:
	/* 0x2679: jmp    3252 <generic_sleepable_preload+0x3252> */
	return 12882ULL;
x86_l_267e:
	/* 0x267e: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_2686:
	/* 0x2686: jmp    3252 <generic_sleepable_preload+0x3252> */
	return 12882ULL;
x86_l_268b:
	/* 0x268b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_268e:
	/* 0x268e: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2691:
	/* 0x2691: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_2693:
	/* 0x2693: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2695:
	/* 0x2695: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_269a:
	/* 0x269a: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_269c:
	/* 0x269c: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_26a1:
	/* 0x26a1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a6:
	/* 0x26a6: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26aa:
	/* 0x26aa: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_26b2:
	/* 0x26b2: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_26b4:
	/* 0x26b4: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26b8:
	/* 0x26b8: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_26c0:
	/* 0x26c0: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_26c6:
	/* 0x26c6: mov    eax,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_26cc:
	/* 0x26cc: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26cf:
	/* 0x26cf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26d4:
	/* 0x26d4: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_26dc:
	/* 0x26dc: je     2701 <generic_sleepable_preload+0x2701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2701;
	}
x86_l_26de:
	/* 0x26de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26e3:
	/* 0x26e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26e8:
	/* 0x26e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26ed:
	/* 0x26ed: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f2:
	/* 0x26f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26f7:
	/* 0x26f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f9:
	/* 0x26f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26fb:
	/* 0x26fb: js     29b5 <generic_sleepable_preload+0x29b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29b5;
	}
x86_l_2701:
	/* 0x2701: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_2709:
	/* 0x2709: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_270f:
	/* 0x270f: mov    ecx,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_2715:
	/* 0x2715: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_271a:
	/* 0x271a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_271f:
	/* 0x271f: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_2727:
	/* 0x2727: je     274c <generic_sleepable_preload+0x274c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_274c;
	}
x86_l_2729:
	/* 0x2729: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272e:
	/* 0x272e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2733:
	/* 0x2733: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2738:
	/* 0x2738: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_273d:
	/* 0x273d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2742:
	/* 0x2742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2744:
	/* 0x2744: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2746:
	/* 0x2746: js     29c2 <generic_sleepable_preload+0x29c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29c2;
	}
x86_l_274c:
	/* 0x274c: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_2754:
	/* 0x2754: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_275a:
	/* 0x275a: mov    ecx,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_2760:
	/* 0x2760: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2765:
	/* 0x2765: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_276a:
	/* 0x276a: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_2772:
	/* 0x2772: je     2797 <generic_sleepable_preload+0x2797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2797;
	}
x86_l_2774:
	/* 0x2774: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2779:
	/* 0x2779: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_277e:
	/* 0x277e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2783:
	/* 0x2783: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2788:
	/* 0x2788: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_278d:
	/* 0x278d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278f:
	/* 0x278f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2791:
	/* 0x2791: js     2a3e <generic_sleepable_preload+0x2a3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a3e;
	}
x86_l_2797:
	/* 0x2797: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_279f:
	/* 0x279f: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_27a5:
	/* 0x27a5: mov    ecx,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_27ab:
	/* 0x27ab: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_27b0:
	/* 0x27b0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b5:
	/* 0x27b5: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_27bd:
	/* 0x27bd: je     27e2 <generic_sleepable_preload+0x27e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e2;
	}
x86_l_27bf:
	/* 0x27bf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27c4:
	/* 0x27c4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27c9:
	/* 0x27c9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27ce:
	/* 0x27ce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d3:
	/* 0x27d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27d8:
	/* 0x27d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27da:
	/* 0x27da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27dc:
	/* 0x27dc: js     2aba <generic_sleepable_preload+0x2aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2aba;
	}
x86_l_27e2:
	/* 0x27e2: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_27ea:
	/* 0x27ea: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_27f0:
	/* 0x27f0: mov    ecx,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_27f6:
	/* 0x27f6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_27fb:
	/* 0x27fb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2800:
	/* 0x2800: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_2808:
	/* 0x2808: je     282d <generic_sleepable_preload+0x282d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_282d;
	}
x86_l_280a:
	/* 0x280a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_280f:
	/* 0x280f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2814:
	/* 0x2814: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2819:
	/* 0x2819: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x2827: js     2b36 <generic_sleepable_preload+0x2b36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b36;
	}
x86_l_282d:
	/* 0x282d: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_2835:
	/* 0x2835: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_283b:
	/* 0x283b: mov    ecx,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_2841:
	/* 0x2841: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2846:
	/* 0x2846: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_284b:
	/* 0x284b: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_2853:
	/* 0x2853: je     2878 <generic_sleepable_preload+0x2878> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2878;
	}
x86_l_2855:
	/* 0x2855: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_285a:
	/* 0x285a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_285f:
	/* 0x285f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2864:
	/* 0x2864: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2869:
	/* 0x2869: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_286e:
	/* 0x286e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2870:
	/* 0x2870: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2872:
	/* 0x2872: js     2baf <generic_sleepable_preload+0x2baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2baf;
	}
x86_l_2878:
	/* 0x2878: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_2880:
	/* 0x2880: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_2886:
	/* 0x2886: mov    ecx,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_288c:
	/* 0x288c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2891:
	/* 0x2891: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2896:
	/* 0x2896: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_289e:
	/* 0x289e: je     28c3 <generic_sleepable_preload+0x28c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c3;
	}
x86_l_28a0:
	/* 0x28a0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a5:
	/* 0x28a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28aa:
	/* 0x28aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28af:
	/* 0x28af: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28b4:
	/* 0x28b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28b9:
	/* 0x28b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28bb:
	/* 0x28bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28bd:
	/* 0x28bd: js     3300 <generic_sleepable_preload+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13056ULL;
	}
x86_l_28c3:
	/* 0x28c3: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_28cb:
	/* 0x28cb: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_28d1:
	/* 0x28d1: mov    ecx,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_28d7:
	/* 0x28d7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28dc:
	/* 0x28dc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e1:
	/* 0x28e1: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_28e9:
	/* 0x28e9: je     290e <generic_sleepable_preload+0x290e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_290e;
	}
x86_l_28eb:
	/* 0x28eb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28f0:
	/* 0x28f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28f5:
	/* 0x28f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28fa:
	/* 0x28fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ff:
	/* 0x28ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2904:
	/* 0x2904: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2906:
	/* 0x2906: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2908:
	/* 0x2908: js     348b <generic_sleepable_preload+0x348b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13451ULL;
	}
x86_l_290e:
	/* 0x290e: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_2916:
	/* 0x2916: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_291c:
	/* 0x291c: mov    ecx,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_2922:
	/* 0x2922: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2927:
	/* 0x2927: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_292c:
	/* 0x292c: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_2934:
	/* 0x2934: je     2959 <generic_sleepable_preload+0x2959> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2959;
	}
x86_l_2936:
	/* 0x2936: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_293b:
	/* 0x293b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2940:
	/* 0x2940: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2945:
	/* 0x2945: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_294a:
	/* 0x294a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_294f:
	/* 0x294f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2951:
	/* 0x2951: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2953:
	/* 0x2953: js     3519 <generic_sleepable_preload+0x3519> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13593ULL;
	}
x86_l_2959:
	/* 0x2959: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_2961:
	/* 0x2961: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_2967:
	/* 0x2967: mov    ecx,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_296d:
	/* 0x296d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2972:
	/* 0x2972: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2977:
	/* 0x2977: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_297f:
	/* 0x297f: je     3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_2985:
	/* 0x2985: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_298a:
	/* 0x298a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_298f:
	/* 0x298f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2994:
	/* 0x2994: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2999:
	/* 0x2999: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_299e:
	/* 0x299e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a0:
	/* 0x29a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29a2:
	/* 0x29a2: jns    3310 <generic_sleepable_preload+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13072ULL;
	}
x86_l_29a8:
	/* 0x29a8: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_29b0:
	/* 0x29b0: jmp    3308 <generic_sleepable_preload+0x3308> */
	return 13064ULL;
x86_l_29b5:
	/* 0x29b5: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_29bd:
	/* 0x29bd: jmp    3308 <generic_sleepable_preload+0x3308> */
	return 13064ULL;
x86_l_29c2:
	/* 0x29c2: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_29ca:
	/* 0x29ca: jmp    3308 <generic_sleepable_preload+0x3308> */
	return 13064ULL;
x86_l_29cf:
	/* 0x29cf: mov    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_29d7:
	/* 0x29d7: jmp    2bc4 <generic_sleepable_preload+0x2bc4> */
	goto x86_l_2bc4;
x86_l_29dc:
	/* 0x29dc: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_29e4:
	/* 0x29e4: jmp    2c91 <generic_sleepable_preload+0x2c91> */
	return 11409ULL;
x86_l_29e9:
	/* 0x29e9: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_29f1:
	/* 0x29f1: jmp    2d8c <generic_sleepable_preload+0x2d8c> */
	return 11660ULL;
x86_l_29f6:
	/* 0x29f6: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_29fe:
	/* 0x29fe: jmp    2e87 <generic_sleepable_preload+0x2e87> */
	return 11911ULL;
x86_l_2a03:
	/* 0x2a03: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2a08:
	/* 0x2a08: jmp    2f7f <generic_sleepable_preload+0x2f7f> */
	return 12159ULL;
x86_l_2a0d:
	/* 0x2a0d: mov    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_2a15:
	/* 0x2a15: jmp    300e <generic_sleepable_preload+0x300e> */
	return 12302ULL;
x86_l_2a1a:
	/* 0x2a1a: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2a1f:
	/* 0x2a1f: jmp    30e8 <generic_sleepable_preload+0x30e8> */
	return 12520ULL;
x86_l_2a24:
	/* 0x2a24: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_2a2c:
	/* 0x2a2c: jmp    319c <generic_sleepable_preload+0x319c> */
	return 12700ULL;
x86_l_2a31:
	/* 0x2a31: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_2a39:
	/* 0x2a39: jmp    3252 <generic_sleepable_preload+0x3252> */
	return 12882ULL;
x86_l_2a3e:
	/* 0x2a3e: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_2a46:
	/* 0x2a46: jmp    3308 <generic_sleepable_preload+0x3308> */
	return 13064ULL;
x86_l_2a4b:
	/* 0x2a4b: mov    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_2a53:
	/* 0x2a53: jmp    2bc4 <generic_sleepable_preload+0x2bc4> */
	goto x86_l_2bc4;
x86_l_2a58:
	/* 0x2a58: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2a60:
	/* 0x2a60: jmp    2c91 <generic_sleepable_preload+0x2c91> */
	return 11409ULL;
x86_l_2a65:
	/* 0x2a65: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2a6d:
	/* 0x2a6d: jmp    2d8c <generic_sleepable_preload+0x2d8c> */
	return 11660ULL;
x86_l_2a72:
	/* 0x2a72: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2a7a:
	/* 0x2a7a: jmp    2e87 <generic_sleepable_preload+0x2e87> */
	return 11911ULL;
x86_l_2a7f:
	/* 0x2a7f: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2a84:
	/* 0x2a84: jmp    2f7f <generic_sleepable_preload+0x2f7f> */
	return 12159ULL;
x86_l_2a89:
	/* 0x2a89: mov    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_2a91:
	/* 0x2a91: jmp    300e <generic_sleepable_preload+0x300e> */
	return 12302ULL;
x86_l_2a96:
	/* 0x2a96: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2a9b:
	/* 0x2a9b: jmp    30e8 <generic_sleepable_preload+0x30e8> */
	return 12520ULL;
x86_l_2aa0:
	/* 0x2aa0: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2aa8:
	/* 0x2aa8: jmp    319c <generic_sleepable_preload+0x319c> */
	return 12700ULL;
x86_l_2aad:
	/* 0x2aad: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2ab5:
	/* 0x2ab5: jmp    3252 <generic_sleepable_preload+0x3252> */
	return 12882ULL;
x86_l_2aba:
	/* 0x2aba: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2ac2:
	/* 0x2ac2: jmp    3308 <generic_sleepable_preload+0x3308> */
	return 13064ULL;
x86_l_2ac7:
	/* 0x2ac7: mov    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_2acf:
	/* 0x2acf: jmp    2bc4 <generic_sleepable_preload+0x2bc4> */
	goto x86_l_2bc4;
x86_l_2ad4:
	/* 0x2ad4: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2adc:
	/* 0x2adc: jmp    2c91 <generic_sleepable_preload+0x2c91> */
	return 11409ULL;
x86_l_2ae1:
	/* 0x2ae1: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2ae9:
	/* 0x2ae9: jmp    2d8c <generic_sleepable_preload+0x2d8c> */
	return 11660ULL;
x86_l_2aee:
	/* 0x2aee: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2af6:
	/* 0x2af6: jmp    2e87 <generic_sleepable_preload+0x2e87> */
	return 11911ULL;
x86_l_2afb:
	/* 0x2afb: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2b00:
	/* 0x2b00: jmp    2f7f <generic_sleepable_preload+0x2f7f> */
	return 12159ULL;
x86_l_2b05:
	/* 0x2b05: mov    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_2b0d:
	/* 0x2b0d: jmp    300e <generic_sleepable_preload+0x300e> */
	return 12302ULL;
x86_l_2b12:
	/* 0x2b12: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2b17:
	/* 0x2b17: jmp    30e8 <generic_sleepable_preload+0x30e8> */
	return 12520ULL;
x86_l_2b1c:
	/* 0x2b1c: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2b24:
	/* 0x2b24: jmp    319c <generic_sleepable_preload+0x319c> */
	return 12700ULL;
x86_l_2b29:
	/* 0x2b29: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2b31:
	/* 0x2b31: jmp    3252 <generic_sleepable_preload+0x3252> */
	return 12882ULL;
x86_l_2b36:
	/* 0x2b36: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2b3e:
	/* 0x2b3e: jmp    3308 <generic_sleepable_preload+0x3308> */
	return 13064ULL;
x86_l_2b43:
	/* 0x2b43: mov    DWORD PTR [rsp+0x18],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215110ULL);
x86_l_2b4b:
	/* 0x2b4b: jmp    2bc4 <generic_sleepable_preload+0x2bc4> */
	goto x86_l_2bc4;
x86_l_2b4d:
	/* 0x2b4d: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2b55:
	/* 0x2b55: jmp    2c91 <generic_sleepable_preload+0x2c91> */
	return 11409ULL;
x86_l_2b5a:
	/* 0x2b5a: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2b62:
	/* 0x2b62: jmp    2d8c <generic_sleepable_preload+0x2d8c> */
	return 11660ULL;
x86_l_2b67:
	/* 0x2b67: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2b6f:
	/* 0x2b6f: jmp    2e87 <generic_sleepable_preload+0x2e87> */
	return 11911ULL;
x86_l_2b74:
	/* 0x2b74: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2b79:
	/* 0x2b79: jmp    2f7f <generic_sleepable_preload+0x2f7f> */
	return 12159ULL;
x86_l_2b7e:
	/* 0x2b7e: mov    DWORD PTR [rsp+0x18],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215110ULL);
x86_l_2b86:
	/* 0x2b86: jmp    300e <generic_sleepable_preload+0x300e> */
	return 12302ULL;
x86_l_2b8b:
	/* 0x2b8b: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2b90:
	/* 0x2b90: jmp    30e8 <generic_sleepable_preload+0x30e8> */
	return 12520ULL;
x86_l_2b95:
	/* 0x2b95: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2b9d:
	/* 0x2b9d: jmp    319c <generic_sleepable_preload+0x319c> */
	return 12700ULL;
x86_l_2ba2:
	/* 0x2ba2: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2baa:
	/* 0x2baa: jmp    3252 <generic_sleepable_preload+0x3252> */
	return 12882ULL;
x86_l_2baf:
	/* 0x2baf: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2bb7:
	/* 0x2bb7: jmp    3308 <generic_sleepable_preload+0x3308> */
	return 13064ULL;
x86_l_2bbc:
	/* 0x2bbc: mov    DWORD PTR [rsp+0x18],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215111ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2bcc:
	/* 0x2bcc: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bd0:
	/* 0x2bd0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bd5:
	/* 0x2bd5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2bda:
	/* 0x2bda: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2be4:
	/* 0x2be4: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2be7:
	/* 0x2be7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be9:
	/* 0x2be9: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2bed:
	/* 0x2bed: jne    d7 <generic_sleepable_preload+0xd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 215ULL;
	}
x86_l_2bf3:
	/* 0x2bf3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bf8:
	/* 0x2bf8: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bfd:
	/* 0x2bfd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c02:
	/* 0x2c02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c04:
	/* 0x2c04: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c09:
	/* 0x2c09: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2c11:
	/* 0x2c11: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2c18:
	/* 0x2c18: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c1d:
	/* 0x2c1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c22:
	/* 0x2c22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c24:
	/* 0x2c24: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c27:
	/* 0x2c27: je     d7 <generic_sleepable_preload+0xd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 215ULL;
	}
x86_l_2c2d:
	/* 0x2c2d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2c30:
	/* 0x2c30: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c35:
	/* 0x2c35: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2c38:
	/* 0x2c38: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
	return 11327ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11327ULL: goto x86_l_2c3f;
	case 11329ULL: goto x86_l_2c41;
	case 11332ULL: goto x86_l_2c44;
	case 11337ULL: goto x86_l_2c49;
	case 11342ULL: goto x86_l_2c4e;
	case 11345ULL: goto x86_l_2c51;
	case 11348ULL: goto x86_l_2c54;
	case 11350ULL: goto x86_l_2c56;
	case 11352ULL: goto x86_l_2c58;
	case 11357ULL: goto x86_l_2c5d;
	case 11360ULL: goto x86_l_2c60;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11371ULL: goto x86_l_2c6b;
	case 11374ULL: goto x86_l_2c6e;
	case 11376ULL: goto x86_l_2c70;
	case 11379ULL: goto x86_l_2c73;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11396ULL: goto x86_l_2c84;
	case 11401ULL: goto x86_l_2c89;
	case 11409ULL: goto x86_l_2c91;
	case 11417ULL: goto x86_l_2c99;
	case 11421ULL: goto x86_l_2c9d;
	case 11426ULL: goto x86_l_2ca2;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11444ULL: goto x86_l_2cb4;
	case 11446ULL: goto x86_l_2cb6;
	case 11450ULL: goto x86_l_2cba;
	case 11456ULL: goto x86_l_2cc0;
	case 11461ULL: goto x86_l_2cc5;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11473ULL: goto x86_l_2cd1;
	case 11478ULL: goto x86_l_2cd6;
	case 11486ULL: goto x86_l_2cde;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11505ULL: goto x86_l_2cf1;
	case 11508ULL: goto x86_l_2cf4;
	case 11514ULL: goto x86_l_2cfa;
	case 11517ULL: goto x86_l_2cfd;
	case 11522ULL: goto x86_l_2d02;
	case 11525ULL: goto x86_l_2d05;
	case 11532ULL: goto x86_l_2d0c;
	case 11534ULL: goto x86_l_2d0e;
	case 11537ULL: goto x86_l_2d11;
	case 11542ULL: goto x86_l_2d16;
	case 11547ULL: goto x86_l_2d1b;
	case 11550ULL: goto x86_l_2d1e;
	case 11553ULL: goto x86_l_2d21;
	case 11555ULL: goto x86_l_2d23;
	case 11557ULL: goto x86_l_2d25;
	case 11562ULL: goto x86_l_2d2a;
	case 11565ULL: goto x86_l_2d2d;
	case 11568ULL: goto x86_l_2d30;
	case 11573ULL: goto x86_l_2d35;
	case 11576ULL: goto x86_l_2d38;
	case 11579ULL: goto x86_l_2d3b;
	case 11581ULL: goto x86_l_2d3d;
	case 11584ULL: goto x86_l_2d40;
	case 11590ULL: goto x86_l_2d46;
	case 11595ULL: goto x86_l_2d4b;
	case 11601ULL: goto x86_l_2d51;
	case 11604ULL: goto x86_l_2d54;
	case 11608ULL: goto x86_l_2d58;
	case 11613ULL: goto x86_l_2d5d;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11623ULL: goto x86_l_2d67;
	case 11628ULL: goto x86_l_2d6c;
	case 11630ULL: goto x86_l_2d6e;
	case 11633ULL: goto x86_l_2d71;
	case 11635ULL: goto x86_l_2d73;
	case 11640ULL: goto x86_l_2d78;
	case 11644ULL: goto x86_l_2d7c;
	case 11647ULL: goto x86_l_2d7f;
	case 11652ULL: goto x86_l_2d84;
	case 11660ULL: goto x86_l_2d8c;
	case 11668ULL: goto x86_l_2d94;
	case 11672ULL: goto x86_l_2d98;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11695ULL: goto x86_l_2daf;
	case 11697ULL: goto x86_l_2db1;
	case 11701ULL: goto x86_l_2db5;
	case 11707ULL: goto x86_l_2dbb;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11722ULL: goto x86_l_2dca;
	case 11724ULL: goto x86_l_2dcc;
	case 11729ULL: goto x86_l_2dd1;
	case 11737ULL: goto x86_l_2dd9;
	case 11744ULL: goto x86_l_2de0;
	case 11749ULL: goto x86_l_2de5;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11759ULL: goto x86_l_2def;
	case 11765ULL: goto x86_l_2df5;
	case 11768ULL: goto x86_l_2df8;
	case 11773ULL: goto x86_l_2dfd;
	case 11776ULL: goto x86_l_2e00;
	case 11783ULL: goto x86_l_2e07;
	case 11785ULL: goto x86_l_2e09;
	case 11788ULL: goto x86_l_2e0c;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11801ULL: goto x86_l_2e19;
	case 11804ULL: goto x86_l_2e1c;
	case 11806ULL: goto x86_l_2e1e;
	case 11808ULL: goto x86_l_2e20;
	case 11813ULL: goto x86_l_2e25;
	case 11816ULL: goto x86_l_2e28;
	case 11819ULL: goto x86_l_2e2b;
	case 11824ULL: goto x86_l_2e30;
	case 11827ULL: goto x86_l_2e33;
	case 11830ULL: goto x86_l_2e36;
	case 11832ULL: goto x86_l_2e38;
	case 11835ULL: goto x86_l_2e3b;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11852ULL: goto x86_l_2e4c;
	case 11855ULL: goto x86_l_2e4f;
	case 11859ULL: goto x86_l_2e53;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11871ULL: goto x86_l_2e5f;
	case 11874ULL: goto x86_l_2e62;
	case 11879ULL: goto x86_l_2e67;
	case 11881ULL: goto x86_l_2e69;
	case 11884ULL: goto x86_l_2e6c;
	case 11886ULL: goto x86_l_2e6e;
	case 11891ULL: goto x86_l_2e73;
	case 11895ULL: goto x86_l_2e77;
	case 11898ULL: goto x86_l_2e7a;
	case 11903ULL: goto x86_l_2e7f;
	case 11911ULL: goto x86_l_2e87;
	case 11919ULL: goto x86_l_2e8f;
	case 11923ULL: goto x86_l_2e93;
	case 11928ULL: goto x86_l_2e98;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11948ULL: goto x86_l_2eac;
	case 11952ULL: goto x86_l_2eb0;
	case 11958ULL: goto x86_l_2eb6;
	case 11963ULL: goto x86_l_2ebb;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11975ULL: goto x86_l_2ec7;
	case 11980ULL: goto x86_l_2ecc;
	case 11988ULL: goto x86_l_2ed4;
	case 11995ULL: goto x86_l_2edb;
	case 12000ULL: goto x86_l_2ee0;
	case 12005ULL: goto x86_l_2ee5;
	case 12007ULL: goto x86_l_2ee7;
	case 12010ULL: goto x86_l_2eea;
	case 12016ULL: goto x86_l_2ef0;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12027ULL: goto x86_l_2efb;
	case 12034ULL: goto x86_l_2f02;
	case 12036ULL: goto x86_l_2f04;
	case 12039ULL: goto x86_l_2f07;
	case 12044ULL: goto x86_l_2f0c;
	case 12049ULL: goto x86_l_2f11;
	case 12052ULL: goto x86_l_2f14;
	case 12055ULL: goto x86_l_2f17;
	case 12057ULL: goto x86_l_2f19;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12067ULL: goto x86_l_2f23;
	case 12070ULL: goto x86_l_2f26;
	case 12075ULL: goto x86_l_2f2b;
	case 12078ULL: goto x86_l_2f2e;
	case 12081ULL: goto x86_l_2f31;
	case 12083ULL: goto x86_l_2f33;
	case 12086ULL: goto x86_l_2f36;
	case 12092ULL: goto x86_l_2f3c;
	case 12097ULL: goto x86_l_2f41;
	case 12103ULL: goto x86_l_2f47;
	case 12106ULL: goto x86_l_2f4a;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12120ULL: goto x86_l_2f58;
	case 12122ULL: goto x86_l_2f5a;
	case 12125ULL: goto x86_l_2f5d;
	case 12130ULL: goto x86_l_2f62;
	case 12132ULL: goto x86_l_2f64;
	case 12135ULL: goto x86_l_2f67;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12146ULL: goto x86_l_2f72;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12162ULL: goto x86_l_2f82;
	case 12165ULL: goto x86_l_2f85;
	case 12170ULL: goto x86_l_2f8a;
	case 12175ULL: goto x86_l_2f8f;
	case 12180ULL: goto x86_l_2f94;
	case 12185ULL: goto x86_l_2f99;
	case 12188ULL: goto x86_l_2f9c;
	case 12190ULL: goto x86_l_2f9e;
	case 12193ULL: goto x86_l_2fa1;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12224ULL: goto x86_l_2fc0;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12241ULL: goto x86_l_2fd1;
	case 12243ULL: goto x86_l_2fd3;
	case 12246ULL: goto x86_l_2fd6;
	case 12252ULL: goto x86_l_2fdc;
	case 12255ULL: goto x86_l_2fdf;
	case 12262ULL: goto x86_l_2fe6;
	case 12264ULL: goto x86_l_2fe8;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12277ULL: goto x86_l_2ff5;
	case 12280ULL: goto x86_l_2ff8;
	case 12282ULL: goto x86_l_2ffa;
	case 12284ULL: goto x86_l_2ffc;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	case 12302ULL: goto x86_l_300e;
	case 12310ULL: goto x86_l_3016;
	case 12314ULL: goto x86_l_301a;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12330ULL: goto x86_l_302a;
	case 12335ULL: goto x86_l_302f;
	case 12337ULL: goto x86_l_3031;
	case 12342ULL: goto x86_l_3036;
	case 12350ULL: goto x86_l_303e;
	case 12357ULL: goto x86_l_3045;
	case 12362ULL: goto x86_l_304a;
	case 12367ULL: goto x86_l_304f;
	case 12369ULL: goto x86_l_3051;
	case 12372ULL: goto x86_l_3054;
	case 12378ULL: goto x86_l_305a;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12389ULL: goto x86_l_3065;
	case 12396ULL: goto x86_l_306c;
	case 12398ULL: goto x86_l_306e;
	case 12401ULL: goto x86_l_3071;
	case 12406ULL: goto x86_l_3076;
	case 12411ULL: goto x86_l_307b;
	case 12414ULL: goto x86_l_307e;
	case 12417ULL: goto x86_l_3081;
	case 12419ULL: goto x86_l_3083;
	case 12421ULL: goto x86_l_3085;
	case 12426ULL: goto x86_l_308a;
	case 12429ULL: goto x86_l_308d;
	case 12432ULL: goto x86_l_3090;
	case 12437ULL: goto x86_l_3095;
	case 12440ULL: goto x86_l_3098;
	case 12443ULL: goto x86_l_309b;
	case 12445ULL: goto x86_l_309d;
	case 12448ULL: goto x86_l_30a0;
	case 12454ULL: goto x86_l_30a6;
	case 12459ULL: goto x86_l_30ab;
	case 12461ULL: goto x86_l_30ad;
	case 12464ULL: goto x86_l_30b0;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12478ULL: goto x86_l_30be;
	case 12480ULL: goto x86_l_30c0;
	case 12483ULL: goto x86_l_30c3;
	case 12488ULL: goto x86_l_30c8;
	case 12490ULL: goto x86_l_30ca;
	case 12493ULL: goto x86_l_30cd;
	case 12495ULL: goto x86_l_30cf;
	case 12497ULL: goto x86_l_30d1;
	case 12501ULL: goto x86_l_30d5;
	case 12503ULL: goto x86_l_30d7;
	case 12508ULL: goto x86_l_30dc;
	case 12513ULL: goto x86_l_30e1;
	case 12515ULL: goto x86_l_30e3;
	case 12520ULL: goto x86_l_30e8;
	case 12523ULL: goto x86_l_30eb;
	case 12527ULL: goto x86_l_30ef;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12543ULL: goto x86_l_30ff;
	case 12545ULL: goto x86_l_3101;
	case 12550ULL: goto x86_l_3106;
	case 12558ULL: goto x86_l_310e;
	case 12565ULL: goto x86_l_3115;
	case 12570ULL: goto x86_l_311a;
	case 12575ULL: goto x86_l_311f;
	case 12577ULL: goto x86_l_3121;
	case 12580ULL: goto x86_l_3124;
	case 12586ULL: goto x86_l_312a;
	case 12589ULL: goto x86_l_312d;
	case 12596ULL: goto x86_l_3134;
	case 12598ULL: goto x86_l_3136;
	case 12603ULL: goto x86_l_313b;
	case 12608ULL: goto x86_l_3140;
	case 12611ULL: goto x86_l_3143;
	case 12614ULL: goto x86_l_3146;
	case 12616ULL: goto x86_l_3148;
	case 12618ULL: goto x86_l_314a;
	case 12623ULL: goto x86_l_314f;
	case 12626ULL: goto x86_l_3152;
	case 12629ULL: goto x86_l_3155;
	case 12631ULL: goto x86_l_3157;
	case 12634ULL: goto x86_l_315a;
	case 12640ULL: goto x86_l_3160;
	case 12643ULL: goto x86_l_3163;
	case 12645ULL: goto x86_l_3165;
	case 12648ULL: goto x86_l_3168;
	case 12652ULL: goto x86_l_316c;
	case 12657ULL: goto x86_l_3171;
	case 12660ULL: goto x86_l_3174;
	case 12662ULL: goto x86_l_3176;
	case 12665ULL: goto x86_l_3179;
	case 12670ULL: goto x86_l_317e;
	case 12672ULL: goto x86_l_3180;
	case 12675ULL: goto x86_l_3183;
	case 12677ULL: goto x86_l_3185;
	case 12682ULL: goto x86_l_318a;
	case 12685ULL: goto x86_l_318d;
	case 12687ULL: goto x86_l_318f;
	case 12692ULL: goto x86_l_3194;
	case 12700ULL: goto x86_l_319c;
	case 12708ULL: goto x86_l_31a4;
	case 12712ULL: goto x86_l_31a8;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12728ULL: goto x86_l_31b8;
	case 12733ULL: goto x86_l_31bd;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12748ULL: goto x86_l_31cc;
	case 12755ULL: goto x86_l_31d3;
	case 12760ULL: goto x86_l_31d8;
	case 12765ULL: goto x86_l_31dd;
	case 12767ULL: goto x86_l_31df;
	case 12770ULL: goto x86_l_31e2;
	case 12776ULL: goto x86_l_31e8;
	case 12779ULL: goto x86_l_31eb;
	case 12784ULL: goto x86_l_31f0;
	case 12787ULL: goto x86_l_31f3;
	case 12794ULL: goto x86_l_31fa;
	case 12796ULL: goto x86_l_31fc;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12809ULL: goto x86_l_3209;
	case 12812ULL: goto x86_l_320c;
	case 12815ULL: goto x86_l_320f;
	case 12817ULL: goto x86_l_3211;
	case 12819ULL: goto x86_l_3213;
	case 12824ULL: goto x86_l_3218;
	case 12827ULL: goto x86_l_321b;
	case 12830ULL: goto x86_l_321e;
	case 12835ULL: goto x86_l_3223;
	case 12838ULL: goto x86_l_3226;
	case 12841ULL: goto x86_l_3229;
	case 12843ULL: goto x86_l_322b;
	case 12846ULL: goto x86_l_322e;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12863ULL: goto x86_l_323f;
	case 12867ULL: goto x86_l_3243;
	case 12869ULL: goto x86_l_3245;
	case 12874ULL: goto x86_l_324a;
	case 12882ULL: goto x86_l_3252;
	case 12890ULL: goto x86_l_325a;
	case 12894ULL: goto x86_l_325e;
	case 12900ULL: goto x86_l_3264;
	case 12905ULL: goto x86_l_3269;
	case 12910ULL: goto x86_l_326e;
	case 12915ULL: goto x86_l_3273;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2c3f:
	/* 0x2c3f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c41:
	/* 0x2c41: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2c44:
	/* 0x2c44: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c49:
	/* 0x2c49: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c4e:
	/* 0x2c4e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2c51:
	/* 0x2c51: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2c54:
	/* 0x2c54: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c56:
	/* 0x2c56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c58:
	/* 0x2c58: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c5d:
	/* 0x2c5d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2c60:
	/* 0x2c60: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2c63:
	/* 0x2c63: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c68:
	/* 0x2c68: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2c6b:
	/* 0x2c6b: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2c6e:
	/* 0x2c6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c70:
	/* 0x2c70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c73:
	/* 0x2c73: je     d7 <generic_sleepable_preload+0xd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 215ULL;
	}
x86_l_2c79:
	/* 0x2c79: cmp    BYTE PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2c7e:
	/* 0x2c7e: jne    30ad <generic_sleepable_preload+0x30ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30ad;
	}
x86_l_2c84:
	/* 0x2c84: jmp    30d1 <generic_sleepable_preload+0x30d1> */
	goto x86_l_30d1;
x86_l_2c89:
	/* 0x2c89: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_2c91:
	/* 0x2c91: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2c99:
	/* 0x2c99: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c9d:
	/* 0x2c9d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ca2:
	/* 0x2ca2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ca7:
	/* 0x2ca7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cac:
	/* 0x2cac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cb1:
	/* 0x2cb1: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2cb4:
	/* 0x2cb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb6:
	/* 0x2cb6: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2cba:
	/* 0x2cba: jne    e1 <generic_sleepable_preload+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 225ULL;
	}
x86_l_2cc0:
	/* 0x2cc0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cc5:
	/* 0x2cc5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cca:
	/* 0x2cca: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ccf:
	/* 0x2ccf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd1:
	/* 0x2cd1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cd6:
	/* 0x2cd6: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2cde:
	/* 0x2cde: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ce5:
	/* 0x2ce5: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2cea:
	/* 0x2cea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cef:
	/* 0x2cef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf1:
	/* 0x2cf1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cf4:
	/* 0x2cf4: je     e1 <generic_sleepable_preload+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 225ULL;
	}
x86_l_2cfa:
	/* 0x2cfa: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2cfd:
	/* 0x2cfd: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d02:
	/* 0x2d02: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2d05:
	/* 0x2d05: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2d0c:
	/* 0x2d0c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d0e:
	/* 0x2d0e: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2d11:
	/* 0x2d11: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d16:
	/* 0x2d16: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d1b:
	/* 0x2d1b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2d1e:
	/* 0x2d1e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2d21:
	/* 0x2d21: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d23:
	/* 0x2d23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d25:
	/* 0x2d25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d2a:
	/* 0x2d2a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2d2d:
	/* 0x2d2d: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2d30:
	/* 0x2d30: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d35:
	/* 0x2d35: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2d38:
	/* 0x2d38: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2d3b:
	/* 0x2d3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3d:
	/* 0x2d3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d40:
	/* 0x2d40: je     e1 <generic_sleepable_preload+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 225ULL;
	}
x86_l_2d46:
	/* 0x2d46: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2d4b:
	/* 0x2d4b: je     323f <generic_sleepable_preload+0x323f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_323f;
	}
x86_l_2d51:
	/* 0x2d51: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d54:
	/* 0x2d54: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d58:
	/* 0x2d58: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d5d:
	/* 0x2d5d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d62:
	/* 0x2d62: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d64:
	/* 0x2d64: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2d67:
	/* 0x2d67: call   2d6c <generic_sleepable_preload+0x2d6c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2d6c:
	/* 0x2d6c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2d6e:
	/* 0x2d6e: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2d71:
	/* 0x2d71: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2d73:
	/* 0x2d73: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d78:
	/* 0x2d78: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d7c:
	/* 0x2d7c: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2d7f:
	/* 0x2d7f: jmp    3243 <generic_sleepable_preload+0x3243> */
	goto x86_l_3243;
x86_l_2d84:
	/* 0x2d84: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_2d8c:
	/* 0x2d8c: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2d94:
	/* 0x2d94: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2d98:
	/* 0x2d98: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d9d:
	/* 0x2d9d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2da2:
	/* 0x2da2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2da7:
	/* 0x2da7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dac:
	/* 0x2dac: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2daf:
	/* 0x2daf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db1:
	/* 0x2db1: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2db5:
	/* 0x2db5: jne    ef <generic_sleepable_preload+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 239ULL;
	}
x86_l_2dbb:
	/* 0x2dbb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dc5:
	/* 0x2dc5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2dca:
	/* 0x2dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dcc:
	/* 0x2dcc: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dd1:
	/* 0x2dd1: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2de0:
	/* 0x2de0: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2de5:
	/* 0x2de5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dea:
	/* 0x2dea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dec:
	/* 0x2dec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2def:
	/* 0x2def: je     ef <generic_sleepable_preload+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 239ULL;
	}
x86_l_2df5:
	/* 0x2df5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2df8:
	/* 0x2df8: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dfd:
	/* 0x2dfd: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2e00:
	/* 0x2e00: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2e07:
	/* 0x2e07: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e09:
	/* 0x2e09: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2e0c:
	/* 0x2e0c: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e11:
	/* 0x2e11: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e16:
	/* 0x2e16: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2e19:
	/* 0x2e19: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2e1c:
	/* 0x2e1c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e1e:
	/* 0x2e1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e20:
	/* 0x2e20: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e25:
	/* 0x2e25: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2e28:
	/* 0x2e28: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2e2b:
	/* 0x2e2b: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e30:
	/* 0x2e30: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2e33:
	/* 0x2e33: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2e36:
	/* 0x2e36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e38:
	/* 0x2e38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e3b:
	/* 0x2e3b: je     ef <generic_sleepable_preload+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 239ULL;
	}
x86_l_2e41:
	/* 0x2e41: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2e46:
	/* 0x2e46: je     32f5 <generic_sleepable_preload+0x32f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13045ULL;
	}
x86_l_2e4c:
	/* 0x2e4c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e4f:
	/* 0x2e4f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2e53:
	/* 0x2e53: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e58:
	/* 0x2e58: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e5d:
	/* 0x2e5d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e5f:
	/* 0x2e5f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2e62:
	/* 0x2e62: call   2e67 <generic_sleepable_preload+0x2e67> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2e67:
	/* 0x2e67: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2e69:
	/* 0x2e69: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2e6c:
	/* 0x2e6c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2e6e:
	/* 0x2e6e: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2e73:
	/* 0x2e73: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2e77:
	/* 0x2e77: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2e7a:
	/* 0x2e7a: jmp    32f9 <generic_sleepable_preload+0x32f9> */
	return 13049ULL;
x86_l_2e7f:
	/* 0x2e7f: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_2e87:
	/* 0x2e87: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2e8f:
	/* 0x2e8f: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e93:
	/* 0x2e93: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e98:
	/* 0x2e98: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea2:
	/* 0x2ea2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea7:
	/* 0x2ea7: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2eaa:
	/* 0x2eaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eac:
	/* 0x2eac: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2eb0:
	/* 0x2eb0: jne    fd <generic_sleepable_preload+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 253ULL;
	}
x86_l_2eb6:
	/* 0x2eb6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ebb:
	/* 0x2ebb: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ec0:
	/* 0x2ec0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ec5:
	/* 0x2ec5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec7:
	/* 0x2ec7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ecc:
	/* 0x2ecc: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2ed4:
	/* 0x2ed4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2edb:
	/* 0x2edb: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2ee0:
	/* 0x2ee0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ee5:
	/* 0x2ee5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee7:
	/* 0x2ee7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2eea:
	/* 0x2eea: je     fd <generic_sleepable_preload+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 253ULL;
	}
x86_l_2ef0:
	/* 0x2ef0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2ef3:
	/* 0x2ef3: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ef8:
	/* 0x2ef8: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2efb:
	/* 0x2efb: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2f02:
	/* 0x2f02: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f04:
	/* 0x2f04: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2f07:
	/* 0x2f07: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f0c:
	/* 0x2f0c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f11:
	/* 0x2f11: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f14:
	/* 0x2f14: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f17:
	/* 0x2f17: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f19:
	/* 0x2f19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1b:
	/* 0x2f1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f20:
	/* 0x2f20: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f23:
	/* 0x2f23: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2f26:
	/* 0x2f26: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f2b:
	/* 0x2f2b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f2e:
	/* 0x2f2e: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2f31:
	/* 0x2f31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f33:
	/* 0x2f33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f36:
	/* 0x2f36: je     fd <generic_sleepable_preload+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 253ULL;
	}
x86_l_2f3c:
	/* 0x2f3c: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2f41:
	/* 0x2f41: je     33ab <generic_sleepable_preload+0x33ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13227ULL;
	}
x86_l_2f47:
	/* 0x2f47: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2f4a:
	/* 0x2f4a: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f53:
	/* 0x2f53: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f58:
	/* 0x2f58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f5a:
	/* 0x2f5a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2f5d:
	/* 0x2f5d: call   2f62 <generic_sleepable_preload+0x2f62> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2f62:
	/* 0x2f62: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2f64:
	/* 0x2f64: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2f67:
	/* 0x2f67: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2f69:
	/* 0x2f69: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2f6e:
	/* 0x2f6e: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2f72:
	/* 0x2f72: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2f75:
	/* 0x2f75: jmp    33af <generic_sleepable_preload+0x33af> */
	return 13231ULL;
x86_l_2f7a:
	/* 0x2f7a: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_2f7f:
	/* 0x2f7f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f82:
	/* 0x2f82: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2f85:
	/* 0x2f85: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f8a:
	/* 0x2f8a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f8f:
	/* 0x2f8f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f94:
	/* 0x2f94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f99:
	/* 0x2f99: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2f9c:
	/* 0x2f9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9e:
	/* 0x2f9e: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2fa1:
	/* 0x2fa1: jne    10b <generic_sleepable_preload+0x10b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 267ULL;
	}
x86_l_2fa7:
	/* 0x2fa7: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fac:
	/* 0x2fac: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2fb1:
	/* 0x2fb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb3:
	/* 0x2fb3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fb8:
	/* 0x2fb8: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2fc0:
	/* 0x2fc0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2fc7:
	/* 0x2fc7: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2fcc:
	/* 0x2fcc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fd1:
	/* 0x2fd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd3:
	/* 0x2fd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fd6:
	/* 0x2fd6: je     10b <generic_sleepable_preload+0x10b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 267ULL;
	}
x86_l_2fdc:
	/* 0x2fdc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2fdf:
	/* 0x2fdf: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2fe6:
	/* 0x2fe6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fe8:
	/* 0x2fe8: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fed:
	/* 0x2fed: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ff2:
	/* 0x2ff2: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2ff5:
	/* 0x2ff5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2ff8:
	/* 0x2ff8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ffa:
	/* 0x2ffa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ffc:
	/* 0x2ffc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3001:
	/* 0x3001: jmp    314f <generic_sleepable_preload+0x314f> */
	goto x86_l_314f;
x86_l_3006:
	/* 0x3006: mov    DWORD PTR [rsp+0x18],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215111ULL);
x86_l_300e:
	/* 0x300e: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3016:
	/* 0x3016: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_301a:
	/* 0x301a: jne    d7 <generic_sleepable_preload+0xd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 215ULL;
	}
x86_l_3020:
	/* 0x3020: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3025:
	/* 0x3025: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_302a:
	/* 0x302a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_302f:
	/* 0x302f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3031:
	/* 0x3031: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3036:
	/* 0x3036: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_303e:
	/* 0x303e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3045:
	/* 0x3045: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_304a:
	/* 0x304a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_304f:
	/* 0x304f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3051:
	/* 0x3051: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3054:
	/* 0x3054: je     d7 <generic_sleepable_preload+0xd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 215ULL;
	}
x86_l_305a:
	/* 0x305a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_305d:
	/* 0x305d: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3062:
	/* 0x3062: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_3065:
	/* 0x3065: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_306c:
	/* 0x306c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_306e:
	/* 0x306e: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_3071:
	/* 0x3071: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3076:
	/* 0x3076: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_307b:
	/* 0x307b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_307e:
	/* 0x307e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3081:
	/* 0x3081: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3083:
	/* 0x3083: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3085:
	/* 0x3085: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_308a:
	/* 0x308a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_308d:
	/* 0x308d: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_3090:
	/* 0x3090: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3095:
	/* 0x3095: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3098:
	/* 0x3098: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_309b:
	/* 0x309b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_309d:
	/* 0x309d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30a0:
	/* 0x30a0: je     d7 <generic_sleepable_preload+0xd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 215ULL;
	}
x86_l_30a6:
	/* 0x30a6: cmp    BYTE PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_30ab:
	/* 0x30ab: je     30d1 <generic_sleepable_preload+0x30d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30d1;
	}
x86_l_30ad:
	/* 0x30ad: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_30b0:
	/* 0x30b0: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_30b4:
	/* 0x30b4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_30b9:
	/* 0x30b9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30be:
	/* 0x30be: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30c0:
	/* 0x30c0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_30c3:
	/* 0x30c3: call   30c8 <generic_sleepable_preload+0x30c8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_30c8:
	/* 0x30c8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_30ca:
	/* 0x30ca: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_30cd:
	/* 0x30cd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_30cf:
	/* 0x30cf: js     30dc <generic_sleepable_preload+0x30dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_30dc;
	}
x86_l_30d1:
	/* 0x30d1: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30d5:
	/* 0x30d5: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30d7:
	/* 0x30d7: jmp    d7 <generic_sleepable_preload+0xd7> */
	return 215ULL;
x86_l_30dc:
	/* 0x30dc: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_30e1:
	/* 0x30e1: jmp    30d5 <generic_sleepable_preload+0x30d5> */
	goto x86_l_30d5;
x86_l_30e3:
	/* 0x30e3: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_30e8:
	/* 0x30e8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30eb:
	/* 0x30eb: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_30ef:
	/* 0x30ef: jne    10b <generic_sleepable_preload+0x10b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 267ULL;
	}
x86_l_30f5:
	/* 0x30f5: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30fa:
	/* 0x30fa: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_30ff:
	/* 0x30ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3101:
	/* 0x3101: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3106:
	/* 0x3106: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_310e:
	/* 0x310e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3115:
	/* 0x3115: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_311a:
	/* 0x311a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_311f:
	/* 0x311f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3121:
	/* 0x3121: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3124:
	/* 0x3124: je     10b <generic_sleepable_preload+0x10b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 267ULL;
	}
x86_l_312a:
	/* 0x312a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_312d:
	/* 0x312d: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3134:
	/* 0x3134: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3136:
	/* 0x3136: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_313b:
	/* 0x313b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3140:
	/* 0x3140: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3143:
	/* 0x3143: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3146:
	/* 0x3146: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3148:
	/* 0x3148: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314a:
	/* 0x314a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314f:
	/* 0x314f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3152:
	/* 0x3152: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3155:
	/* 0x3155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3157:
	/* 0x3157: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_315a:
	/* 0x315a: je     10b <generic_sleepable_preload+0x10b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 267ULL;
	}
x86_l_3160:
	/* 0x3160: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_3163:
	/* 0x3163: je     318d <generic_sleepable_preload+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_318d;
	}
x86_l_3165:
	/* 0x3165: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3168:
	/* 0x3168: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_316c:
	/* 0x316c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3171:
	/* 0x3171: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3174:
	/* 0x3174: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3176:
	/* 0x3176: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3179:
	/* 0x3179: call   317e <generic_sleepable_preload+0x317e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_317e:
	/* 0x317e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3180:
	/* 0x3180: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3183:
	/* 0x3183: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3185:
	/* 0x3185: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_318a:
	/* 0x318a: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_318d:
	/* 0x318d: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_318f:
	/* 0x318f: jmp    10b <generic_sleepable_preload+0x10b> */
	return 267ULL;
x86_l_3194:
	/* 0x3194: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_319c:
	/* 0x319c: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_31a4:
	/* 0x31a4: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_31a8:
	/* 0x31a8: jne    e1 <generic_sleepable_preload+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 225ULL;
	}
x86_l_31ae:
	/* 0x31ae: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31b3:
	/* 0x31b3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31b8:
	/* 0x31b8: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_31bd:
	/* 0x31bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31bf:
	/* 0x31bf: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31c4:
	/* 0x31c4: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_31cc:
	/* 0x31cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_31d3:
	/* 0x31d3: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_31d8:
	/* 0x31d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31dd:
	/* 0x31dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31df:
	/* 0x31df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31e2:
	/* 0x31e2: je     e1 <generic_sleepable_preload+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 225ULL;
	}
x86_l_31e8:
	/* 0x31e8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_31eb:
	/* 0x31eb: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31f0:
	/* 0x31f0: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_31f3:
	/* 0x31f3: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_31fa:
	/* 0x31fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31fc:
	/* 0x31fc: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_31ff:
	/* 0x31ff: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3204:
	/* 0x3204: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3209:
	/* 0x3209: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_320c:
	/* 0x320c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_320f:
	/* 0x320f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3211:
	/* 0x3211: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3213:
	/* 0x3213: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3218:
	/* 0x3218: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_321b:
	/* 0x321b: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_321e:
	/* 0x321e: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3223:
	/* 0x3223: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3226:
	/* 0x3226: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_3229:
	/* 0x3229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_322b:
	/* 0x322b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_322e:
	/* 0x322e: je     e1 <generic_sleepable_preload+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 225ULL;
	}
x86_l_3234:
	/* 0x3234: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3239:
	/* 0x3239: jne    2d51 <generic_sleepable_preload+0x2d51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d51;
	}
x86_l_323f:
	/* 0x323f: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3243:
	/* 0x3243: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3245:
	/* 0x3245: jmp    e1 <generic_sleepable_preload+0xe1> */
	return 225ULL;
x86_l_324a:
	/* 0x324a: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_3252:
	/* 0x3252: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_325a:
	/* 0x325a: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_325e:
	/* 0x325e: jne    ef <generic_sleepable_preload+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 239ULL;
	}
x86_l_3264:
	/* 0x3264: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3269:
	/* 0x3269: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_326e:
	/* 0x326e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3273:
	/* 0x3273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 12917ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12930ULL: goto x86_l_3282;
	case 12937ULL: goto x86_l_3289;
	case 12942ULL: goto x86_l_328e;
	case 12947ULL: goto x86_l_3293;
	case 12949ULL: goto x86_l_3295;
	case 12952ULL: goto x86_l_3298;
	case 12958ULL: goto x86_l_329e;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12969ULL: goto x86_l_32a9;
	case 12976ULL: goto x86_l_32b0;
	case 12978ULL: goto x86_l_32b2;
	case 12981ULL: goto x86_l_32b5;
	case 12986ULL: goto x86_l_32ba;
	case 12991ULL: goto x86_l_32bf;
	case 12994ULL: goto x86_l_32c2;
	case 12997ULL: goto x86_l_32c5;
	case 12999ULL: goto x86_l_32c7;
	case 13001ULL: goto x86_l_32c9;
	case 13006ULL: goto x86_l_32ce;
	case 13009ULL: goto x86_l_32d1;
	case 13012ULL: goto x86_l_32d4;
	case 13017ULL: goto x86_l_32d9;
	case 13020ULL: goto x86_l_32dc;
	case 13023ULL: goto x86_l_32df;
	case 13025ULL: goto x86_l_32e1;
	case 13028ULL: goto x86_l_32e4;
	case 13034ULL: goto x86_l_32ea;
	case 13039ULL: goto x86_l_32ef;
	case 13045ULL: goto x86_l_32f5;
	case 13049ULL: goto x86_l_32f9;
	case 13051ULL: goto x86_l_32fb;
	case 13056ULL: goto x86_l_3300;
	case 13064ULL: goto x86_l_3308;
	case 13072ULL: goto x86_l_3310;
	case 13076ULL: goto x86_l_3314;
	case 13082ULL: goto x86_l_331a;
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13099ULL: goto x86_l_332b;
	case 13104ULL: goto x86_l_3330;
	case 13112ULL: goto x86_l_3338;
	case 13119ULL: goto x86_l_333f;
	case 13124ULL: goto x86_l_3344;
	case 13129ULL: goto x86_l_3349;
	case 13131ULL: goto x86_l_334b;
	case 13134ULL: goto x86_l_334e;
	case 13140ULL: goto x86_l_3354;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13151ULL: goto x86_l_335f;
	case 13158ULL: goto x86_l_3366;
	case 13160ULL: goto x86_l_3368;
	case 13163ULL: goto x86_l_336b;
	case 13168ULL: goto x86_l_3370;
	case 13173ULL: goto x86_l_3375;
	case 13176ULL: goto x86_l_3378;
	case 13179ULL: goto x86_l_337b;
	case 13181ULL: goto x86_l_337d;
	case 13183ULL: goto x86_l_337f;
	case 13188ULL: goto x86_l_3384;
	case 13191ULL: goto x86_l_3387;
	case 13194ULL: goto x86_l_338a;
	case 13199ULL: goto x86_l_338f;
	case 13202ULL: goto x86_l_3392;
	case 13205ULL: goto x86_l_3395;
	case 13207ULL: goto x86_l_3397;
	case 13210ULL: goto x86_l_339a;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13227ULL: goto x86_l_33ab;
	case 13231ULL: goto x86_l_33af;
	case 13233ULL: goto x86_l_33b1;
	case 13238ULL: goto x86_l_33b6;
	case 13246ULL: goto x86_l_33be;
	case 13254ULL: goto x86_l_33c6;
	case 13259ULL: goto x86_l_33cb;
	case 13267ULL: goto x86_l_33d3;
	case 13275ULL: goto x86_l_33db;
	case 13280ULL: goto x86_l_33e0;
	case 13288ULL: goto x86_l_33e8;
	case 13296ULL: goto x86_l_33f0;
	case 13301ULL: goto x86_l_33f5;
	case 13309ULL: goto x86_l_33fd;
	case 13317ULL: goto x86_l_3405;
	case 13322ULL: goto x86_l_340a;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13343ULL: goto x86_l_341f;
	case 13351ULL: goto x86_l_3427;
	case 13355ULL: goto x86_l_342b;
	case 13361ULL: goto x86_l_3431;
	case 13366ULL: goto x86_l_3436;
	case 13369ULL: goto x86_l_3439;
	case 13374ULL: goto x86_l_343e;
	case 13378ULL: goto x86_l_3442;
	case 13384ULL: goto x86_l_3448;
	case 13389ULL: goto x86_l_344d;
	case 13397ULL: goto x86_l_3455;
	case 13405ULL: goto x86_l_345d;
	case 13409ULL: goto x86_l_3461;
	case 13415ULL: goto x86_l_3467;
	case 13420ULL: goto x86_l_346c;
	case 13428ULL: goto x86_l_3474;
	case 13436ULL: goto x86_l_347c;
	case 13440ULL: goto x86_l_3480;
	case 13446ULL: goto x86_l_3486;
	case 13451ULL: goto x86_l_348b;
	case 13459ULL: goto x86_l_3493;
	case 13467ULL: goto x86_l_349b;
	case 13471ULL: goto x86_l_349f;
	case 13477ULL: goto x86_l_34a5;
	case 13482ULL: goto x86_l_34aa;
	case 13490ULL: goto x86_l_34b2;
	case 13495ULL: goto x86_l_34b7;
	case 13503ULL: goto x86_l_34bf;
	case 13508ULL: goto x86_l_34c4;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13529ULL: goto x86_l_34d9;
	case 13534ULL: goto x86_l_34de;
	case 13539ULL: goto x86_l_34e3;
	case 13544ULL: goto x86_l_34e8;
	case 13552ULL: goto x86_l_34f0;
	case 13557ULL: goto x86_l_34f5;
	case 13562ULL: goto x86_l_34fa;
	case 13567ULL: goto x86_l_34ff;
	case 13575ULL: goto x86_l_3507;
	case 13580ULL: goto x86_l_350c;
	case 13588ULL: goto x86_l_3514;
	case 13593ULL: goto x86_l_3519;
	case 13601ULL: goto x86_l_3521;
	case 13606ULL: goto x86_l_3526;
	case 13614ULL: goto x86_l_352e;
	case 13619ULL: goto x86_l_3533;
	case 13627ULL: goto x86_l_353b;
	case 13632ULL: goto x86_l_3540;
	case 13640ULL: goto x86_l_3548;
	case 13645ULL: goto x86_l_354d;
	case 13653ULL: goto x86_l_3555;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3275:
	/* 0x3275: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_327a:
	/* 0x327a: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_3282:
	/* 0x3282: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3289:
	/* 0x3289: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_328e:
	/* 0x328e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3293:
	/* 0x3293: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3295:
	/* 0x3295: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3298:
	/* 0x3298: je     ef <generic_sleepable_preload+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 239ULL;
	}
x86_l_329e:
	/* 0x329e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_32a1:
	/* 0x32a1: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32a6:
	/* 0x32a6: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_32a9:
	/* 0x32a9: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_32b0:
	/* 0x32b0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32b2:
	/* 0x32b2: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_32b5:
	/* 0x32b5: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32ba:
	/* 0x32ba: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32bf:
	/* 0x32bf: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32c2:
	/* 0x32c2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_32c5:
	/* 0x32c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32c7:
	/* 0x32c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c9:
	/* 0x32c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32ce:
	/* 0x32ce: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32d1:
	/* 0x32d1: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_32d4:
	/* 0x32d4: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32d9:
	/* 0x32d9: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_32dc:
	/* 0x32dc: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_32df:
	/* 0x32df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e1:
	/* 0x32e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32e4:
	/* 0x32e4: je     ef <generic_sleepable_preload+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 239ULL;
	}
x86_l_32ea:
	/* 0x32ea: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_32ef:
	/* 0x32ef: jne    2e4c <generic_sleepable_preload+0x2e4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11852ULL;
	}
x86_l_32f5:
	/* 0x32f5: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_32f9:
	/* 0x32f9: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32fb:
	/* 0x32fb: jmp    ef <generic_sleepable_preload+0xef> */
	return 239ULL;
x86_l_3300:
	/* 0x3300: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_3308:
	/* 0x3308: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3310:
	/* 0x3310: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3314:
	/* 0x3314: jne    fd <generic_sleepable_preload+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 253ULL;
	}
x86_l_331a:
	/* 0x331a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_331f:
	/* 0x331f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3324:
	/* 0x3324: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3329:
	/* 0x3329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332b:
	/* 0x332b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3330:
	/* 0x3330: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_3338:
	/* 0x3338: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_333f:
	/* 0x333f: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3344:
	/* 0x3344: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3349:
	/* 0x3349: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334b:
	/* 0x334b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_334e:
	/* 0x334e: je     fd <generic_sleepable_preload+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 253ULL;
	}
x86_l_3354:
	/* 0x3354: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3357:
	/* 0x3357: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_335c:
	/* 0x335c: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_335f:
	/* 0x335f: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3366:
	/* 0x3366: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3368:
	/* 0x3368: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_336b:
	/* 0x336b: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3370:
	/* 0x3370: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3375:
	/* 0x3375: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3378:
	/* 0x3378: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_337b:
	/* 0x337b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_337d:
	/* 0x337d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337f:
	/* 0x337f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3384:
	/* 0x3384: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3387:
	/* 0x3387: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_338a:
	/* 0x338a: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_338f:
	/* 0x338f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3392:
	/* 0x3392: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_3395:
	/* 0x3395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3397:
	/* 0x3397: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_339a:
	/* 0x339a: je     fd <generic_sleepable_preload+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 253ULL;
	}
x86_l_33a0:
	/* 0x33a0: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_33a5:
	/* 0x33a5: jne    2f47 <generic_sleepable_preload+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12103ULL;
	}
x86_l_33ab:
	/* 0x33ab: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_33af:
	/* 0x33af: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33b1:
	/* 0x33b1: jmp    fd <generic_sleepable_preload+0xfd> */
	return 253ULL;
x86_l_33b6:
	/* 0x33b6: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_33be:
	/* 0x33be: mov    DWORD PTR [rsp+0x18],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215112ULL);
x86_l_33c6:
	/* 0x33c6: jmp    2bcc <generic_sleepable_preload+0x2bcc> */
	return 11212ULL;
x86_l_33cb:
	/* 0x33cb: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_33d3:
	/* 0x33d3: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_33db:
	/* 0x33db: jmp    2c99 <generic_sleepable_preload+0x2c99> */
	return 11417ULL;
x86_l_33e0:
	/* 0x33e0: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_33e8:
	/* 0x33e8: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_33f0:
	/* 0x33f0: jmp    2d94 <generic_sleepable_preload+0x2d94> */
	return 11668ULL;
x86_l_33f5:
	/* 0x33f5: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_33fd:
	/* 0x33fd: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_3405:
	/* 0x3405: jmp    2e8f <generic_sleepable_preload+0x2e8f> */
	return 11919ULL;
x86_l_340a:
	/* 0x340a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_340d:
	/* 0x340d: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_3412:
	/* 0x3412: jmp    2f82 <generic_sleepable_preload+0x2f82> */
	return 12162ULL;
x86_l_3417:
	/* 0x3417: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_341f:
	/* 0x341f: mov    DWORD PTR [rsp+0x18],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215112ULL);
x86_l_3427:
	/* 0x3427: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_342b:
	/* 0x342b: jne    d7 <generic_sleepable_preload+0xd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 215ULL;
	}
x86_l_3431:
	/* 0x3431: jmp    3020 <generic_sleepable_preload+0x3020> */
	return 12320ULL;
x86_l_3436:
	/* 0x3436: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3439:
	/* 0x3439: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_343e:
	/* 0x343e: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_3442:
	/* 0x3442: jne    10b <generic_sleepable_preload+0x10b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 267ULL;
	}
x86_l_3448:
	/* 0x3448: jmp    30f5 <generic_sleepable_preload+0x30f5> */
	return 12533ULL;
x86_l_344d:
	/* 0x344d: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3455:
	/* 0x3455: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_345d:
	/* 0x345d: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3461:
	/* 0x3461: jne    e1 <generic_sleepable_preload+0xe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 225ULL;
	}
x86_l_3467:
	/* 0x3467: jmp    31ae <generic_sleepable_preload+0x31ae> */
	return 12718ULL;
x86_l_346c:
	/* 0x346c: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3474:
	/* 0x3474: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_347c:
	/* 0x347c: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3480:
	/* 0x3480: jne    ef <generic_sleepable_preload+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 239ULL;
	}
x86_l_3486:
	/* 0x3486: jmp    3264 <generic_sleepable_preload+0x3264> */
	return 12900ULL;
x86_l_348b:
	/* 0x348b: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3493:
	/* 0x3493: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_349b:
	/* 0x349b: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_349f:
	/* 0x349f: jne    fd <generic_sleepable_preload+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 253ULL;
	}
x86_l_34a5:
	/* 0x34a5: jmp    331a <generic_sleepable_preload+0x331a> */
	goto x86_l_331a;
x86_l_34aa:
	/* 0x34aa: mov    DWORD PTR [rsp+0x18],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215113ULL);
x86_l_34b2:
	/* 0x34b2: jmp    2bc4 <generic_sleepable_preload+0x2bc4> */
	return 11204ULL;
x86_l_34b7:
	/* 0x34b7: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_34bf:
	/* 0x34bf: jmp    2c91 <generic_sleepable_preload+0x2c91> */
	return 11409ULL;
x86_l_34c4:
	/* 0x34c4: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_34cc:
	/* 0x34cc: jmp    2d8c <generic_sleepable_preload+0x2d8c> */
	return 11660ULL;
x86_l_34d1:
	/* 0x34d1: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_34d9:
	/* 0x34d9: jmp    2e87 <generic_sleepable_preload+0x2e87> */
	return 11911ULL;
x86_l_34de:
	/* 0x34de: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_34e3:
	/* 0x34e3: jmp    2f7f <generic_sleepable_preload+0x2f7f> */
	return 12159ULL;
x86_l_34e8:
	/* 0x34e8: mov    DWORD PTR [rsp+0x18],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215113ULL);
x86_l_34f0:
	/* 0x34f0: jmp    300e <generic_sleepable_preload+0x300e> */
	return 12302ULL;
x86_l_34f5:
	/* 0x34f5: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_34fa:
	/* 0x34fa: jmp    30e8 <generic_sleepable_preload+0x30e8> */
	return 12520ULL;
x86_l_34ff:
	/* 0x34ff: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_3507:
	/* 0x3507: jmp    319c <generic_sleepable_preload+0x319c> */
	return 12700ULL;
x86_l_350c:
	/* 0x350c: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_3514:
	/* 0x3514: jmp    3252 <generic_sleepable_preload+0x3252> */
	return 12882ULL;
x86_l_3519:
	/* 0x3519: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_3521:
	/* 0x3521: jmp    3308 <generic_sleepable_preload+0x3308> */
	goto x86_l_3308;
x86_l_3526:
	/* 0x3526: mov    DWORD PTR [rsp+0x18],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215114ULL);
x86_l_352e:
	/* 0x352e: jmp    2bc4 <generic_sleepable_preload+0x2bc4> */
	return 11204ULL;
x86_l_3533:
	/* 0x3533: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_353b:
	/* 0x353b: jmp    2c91 <generic_sleepable_preload+0x2c91> */
	return 11409ULL;
x86_l_3540:
	/* 0x3540: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_3548:
	/* 0x3548: jmp    2d8c <generic_sleepable_preload+0x2d8c> */
	return 11660ULL;
x86_l_354d:
	/* 0x354d: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_3555:
	/* 0x3555: jmp    2e87 <generic_sleepable_preload+0x2e87> */
	return 11911ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 11328U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1772ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1778ULL && __x86_pc <= 3646ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3652ULL && __x86_pc <= 5555ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5560ULL && __x86_pc <= 7391ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7396ULL && __x86_pc <= 9307ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9313ULL && __x86_pc <= 11320ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11327ULL && __x86_pc <= 12915ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12917ULL && __x86_pc <= 13653ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

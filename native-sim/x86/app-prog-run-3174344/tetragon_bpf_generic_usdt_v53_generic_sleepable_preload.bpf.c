extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_0(
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
	case 94ULL: goto x86_l_5e;
	case 98ULL: goto x86_l_62;
	case 103ULL: goto x86_l_67;
	case 107ULL: goto x86_l_6b;
	case 115ULL: goto x86_l_73;
	case 119ULL: goto x86_l_77;
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
	case 175ULL: goto x86_l_af;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 188ULL: goto x86_l_bc;
	case 193ULL: goto x86_l_c1;
	case 197ULL: goto x86_l_c5;
	case 202ULL: goto x86_l_ca;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 215ULL: goto x86_l_d7;
	case 220ULL: goto x86_l_dc;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 230ULL: goto x86_l_e6;
	case 233ULL: goto x86_l_e9;
	case 238ULL: goto x86_l_ee;
	case 244ULL: goto x86_l_f4;
	case 247ULL: goto x86_l_f7;
	case 252ULL: goto x86_l_fc;
	case 258ULL: goto x86_l_102;
	case 261ULL: goto x86_l_105;
	case 266ULL: goto x86_l_10a;
	case 272ULL: goto x86_l_110;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 286ULL: goto x86_l_11e;
	case 288ULL: goto x86_l_120;
	case 295ULL: goto x86_l_127;
	case 297ULL: goto x86_l_129;
	case 298ULL: goto x86_l_12a;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 311ULL: goto x86_l_137;
	case 318ULL: goto x86_l_13e;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 338ULL: goto x86_l_152;
	case 341ULL: goto x86_l_155;
	case 347ULL: goto x86_l_15b;
	case 353ULL: goto x86_l_161;
	case 359ULL: goto x86_l_167;
	case 362ULL: goto x86_l_16a;
	case 367ULL: goto x86_l_16f;
	case 372ULL: goto x86_l_174;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 384ULL: goto x86_l_180;
	case 386ULL: goto x86_l_182;
	case 392ULL: goto x86_l_188;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 401ULL: goto x86_l_191;
	case 407ULL: goto x86_l_197;
	case 414ULL: goto x86_l_19e;
	case 416ULL: goto x86_l_1a0;
	case 419ULL: goto x86_l_1a3;
	case 425ULL: goto x86_l_1a9;
	case 428ULL: goto x86_l_1ac;
	case 434ULL: goto x86_l_1b2;
	case 437ULL: goto x86_l_1b5;
	case 443ULL: goto x86_l_1bb;
	case 449ULL: goto x86_l_1c1;
	case 455ULL: goto x86_l_1c7;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 480ULL: goto x86_l_1e0;
	case 482ULL: goto x86_l_1e2;
	case 488ULL: goto x86_l_1e8;
	case 490ULL: goto x86_l_1ea;
	case 495ULL: goto x86_l_1ef;
	case 497ULL: goto x86_l_1f1;
	case 503ULL: goto x86_l_1f7;
	case 510ULL: goto x86_l_1fe;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 521ULL: goto x86_l_209;
	case 524ULL: goto x86_l_20c;
	case 530ULL: goto x86_l_212;
	case 533ULL: goto x86_l_215;
	case 539ULL: goto x86_l_21b;
	case 545ULL: goto x86_l_221;
	case 551ULL: goto x86_l_227;
	case 554ULL: goto x86_l_22a;
	case 559ULL: goto x86_l_22f;
	case 564ULL: goto x86_l_234;
	case 569ULL: goto x86_l_239;
	case 574ULL: goto x86_l_23e;
	case 576ULL: goto x86_l_240;
	case 578ULL: goto x86_l_242;
	case 584ULL: goto x86_l_248;
	case 586ULL: goto x86_l_24a;
	case 591ULL: goto x86_l_24f;
	case 593ULL: goto x86_l_251;
	case 599ULL: goto x86_l_257;
	case 606ULL: goto x86_l_25e;
	case 608ULL: goto x86_l_260;
	case 611ULL: goto x86_l_263;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 626ULL: goto x86_l_272;
	case 629ULL: goto x86_l_275;
	case 635ULL: goto x86_l_27b;
	case 641ULL: goto x86_l_281;
	case 647ULL: goto x86_l_287;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 660ULL: goto x86_l_294;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 672ULL: goto x86_l_2a0;
	case 674ULL: goto x86_l_2a2;
	case 680ULL: goto x86_l_2a8;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 689ULL: goto x86_l_2b1;
	case 695ULL: goto x86_l_2b7;
	case 702ULL: goto x86_l_2be;
	case 704ULL: goto x86_l_2c0;
	case 707ULL: goto x86_l_2c3;
	case 713ULL: goto x86_l_2c9;
	case 716ULL: goto x86_l_2cc;
	case 722ULL: goto x86_l_2d2;
	case 725ULL: goto x86_l_2d5;
	case 731ULL: goto x86_l_2db;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 755ULL: goto x86_l_2f3;
	case 760ULL: goto x86_l_2f8;
	case 765ULL: goto x86_l_2fd;
	case 768ULL: goto x86_l_300;
	case 770ULL: goto x86_l_302;
	case 772ULL: goto x86_l_304;
	case 778ULL: goto x86_l_30a;
	case 780ULL: goto x86_l_30c;
	case 785ULL: goto x86_l_311;
	case 792ULL: goto x86_l_318;
	case 799ULL: goto x86_l_31f;
	case 805ULL: goto x86_l_325;
	case 807ULL: goto x86_l_327;
	case 810ULL: goto x86_l_32a;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 828ULL: goto x86_l_33c;
	case 834ULL: goto x86_l_342;
	case 842ULL: goto x86_l_34a;
	case 845ULL: goto x86_l_34d;
	case 851ULL: goto x86_l_353;
	case 856ULL: goto x86_l_358;
	case 859ULL: goto x86_l_35b;
	case 865ULL: goto x86_l_361;
	case 868ULL: goto x86_l_364;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 884ULL: goto x86_l_374;
	case 891ULL: goto x86_l_37b;
	case 898ULL: goto x86_l_382;
	case 904ULL: goto x86_l_388;
	case 906ULL: goto x86_l_38a;
	case 909ULL: goto x86_l_38d;
	case 915ULL: goto x86_l_393;
	case 918ULL: goto x86_l_396;
	case 924ULL: goto x86_l_39c;
	case 927ULL: goto x86_l_39f;
	case 933ULL: goto x86_l_3a5;
	case 941ULL: goto x86_l_3ad;
	case 944ULL: goto x86_l_3b0;
	case 950ULL: goto x86_l_3b6;
	case 955ULL: goto x86_l_3bb;
	case 958ULL: goto x86_l_3be;
	case 964ULL: goto x86_l_3c4;
	case 969ULL: goto x86_l_3c9;
	case 972ULL: goto x86_l_3cc;
	case 978ULL: goto x86_l_3d2;
	case 983ULL: goto x86_l_3d7;
	case 990ULL: goto x86_l_3de;
	case 997ULL: goto x86_l_3e5;
	case 1003ULL: goto x86_l_3eb;
	case 1005ULL: goto x86_l_3ed;
	case 1008ULL: goto x86_l_3f0;
	case 1014ULL: goto x86_l_3f6;
	case 1017ULL: goto x86_l_3f9;
	case 1023ULL: goto x86_l_3ff;
	case 1026ULL: goto x86_l_402;
	case 1032ULL: goto x86_l_408;
	case 1040ULL: goto x86_l_410;
	case 1043ULL: goto x86_l_413;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1057ULL: goto x86_l_421;
	case 1063ULL: goto x86_l_427;
	case 1068ULL: goto x86_l_42c;
	case 1071ULL: goto x86_l_42f;
	case 1077ULL: goto x86_l_435;
	case 1082ULL: goto x86_l_43a;
	case 1089ULL: goto x86_l_441;
	case 1096ULL: goto x86_l_448;
	case 1102ULL: goto x86_l_44e;
	case 1104ULL: goto x86_l_450;
	case 1107ULL: goto x86_l_453;
	case 1113ULL: goto x86_l_459;
	case 1116ULL: goto x86_l_45c;
	case 1122ULL: goto x86_l_462;
	case 1125ULL: goto x86_l_465;
	case 1131ULL: goto x86_l_46b;
	case 1139ULL: goto x86_l_473;
	case 1142ULL: goto x86_l_476;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1156ULL: goto x86_l_484;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1170ULL: goto x86_l_492;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1188ULL: goto x86_l_4a4;
	case 1195ULL: goto x86_l_4ab;
	case 1201ULL: goto x86_l_4b1;
	case 1203ULL: goto x86_l_4b3;
	case 1206ULL: goto x86_l_4b6;
	case 1212ULL: goto x86_l_4bc;
	case 1215ULL: goto x86_l_4bf;
	case 1221ULL: goto x86_l_4c5;
	case 1224ULL: goto x86_l_4c8;
	case 1230ULL: goto x86_l_4ce;
	case 1238ULL: goto x86_l_4d6;
	case 1241ULL: goto x86_l_4d9;
	case 1247ULL: goto x86_l_4df;
	case 1252ULL: goto x86_l_4e4;
	case 1255ULL: goto x86_l_4e7;
	case 1261ULL: goto x86_l_4ed;
	case 1266ULL: goto x86_l_4f2;
	case 1269ULL: goto x86_l_4f5;
	case 1275ULL: goto x86_l_4fb;
	case 1280ULL: goto x86_l_500;
	case 1283ULL: goto x86_l_503;
	case 1289ULL: goto x86_l_509;
	case 1292ULL: goto x86_l_50c;
	case 1298ULL: goto x86_l_512;
	case 1304ULL: goto x86_l_518;
	case 1310ULL: goto x86_l_51e;
	case 1313ULL: goto x86_l_521;
	case 1318ULL: goto x86_l_526;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1335ULL: goto x86_l_537;
	case 1337ULL: goto x86_l_539;
	case 1343ULL: goto x86_l_53f;
	case 1349ULL: goto x86_l_545;
	case 1355ULL: goto x86_l_54b;
	case 1358ULL: goto x86_l_54e;
	case 1361ULL: goto x86_l_551;
	case 1366ULL: goto x86_l_556;
	case 1371ULL: goto x86_l_55b;
	case 1376ULL: goto x86_l_560;
	case 1378ULL: goto x86_l_562;
	case 1380ULL: goto x86_l_564;
	case 1386ULL: goto x86_l_56a;
	case 1393ULL: goto x86_l_571;
	case 1399ULL: goto x86_l_577;
	case 1406ULL: goto x86_l_57e;
	case 1411ULL: goto x86_l_583;
	case 1414ULL: goto x86_l_586;
	case 1419ULL: goto x86_l_58b;
	case 1424ULL: goto x86_l_590;
	case 1429ULL: goto x86_l_595;
	case 1436ULL: goto x86_l_59c;
	case 1442ULL: goto x86_l_5a2;
	case 1449ULL: goto x86_l_5a9;
	case 1454ULL: goto x86_l_5ae;
	case 1457ULL: goto x86_l_5b1;
	case 1462ULL: goto x86_l_5b6;
	case 1464ULL: goto x86_l_5b8;
	case 1466ULL: goto x86_l_5ba;
	case 1472ULL: goto x86_l_5c0;
	case 1477ULL: goto x86_l_5c5;
	case 1480ULL: goto x86_l_5c8;
	case 1486ULL: goto x86_l_5ce;
	case 1489ULL: goto x86_l_5d1;
	case 1495ULL: goto x86_l_5d7;
	case 1501ULL: goto x86_l_5dd;
	case 1507ULL: goto x86_l_5e3;
	case 1510ULL: goto x86_l_5e6;
	case 1515ULL: goto x86_l_5eb;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1532ULL: goto x86_l_5fc;
	case 1534ULL: goto x86_l_5fe;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1552ULL: goto x86_l_610;
	case 1557ULL: goto x86_l_615;
	case 1562ULL: goto x86_l_61a;
	case 1567ULL: goto x86_l_61f;
	case 1572ULL: goto x86_l_624;
	case 1579ULL: goto x86_l_62b;
	case 1584ULL: goto x86_l_630;
	case 1586ULL: goto x86_l_632;
	case 1588ULL: goto x86_l_634;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1602ULL: goto x86_l_642;
	case 1608ULL: goto x86_l_648;
	case 1611ULL: goto x86_l_64b;
	case 1617ULL: goto x86_l_651;
	case 1623ULL: goto x86_l_657;
	case 1629ULL: goto x86_l_65d;
	case 1632ULL: goto x86_l_660;
	case 1637ULL: goto x86_l_665;
	case 1642ULL: goto x86_l_66a;
	case 1647ULL: goto x86_l_66f;
	case 1652ULL: goto x86_l_674;
	case 1654ULL: goto x86_l_676;
	case 1656ULL: goto x86_l_678;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1694ULL: goto x86_l_69e;
	case 1701ULL: goto x86_l_6a5;
	case 1706ULL: goto x86_l_6aa;
	case 1708ULL: goto x86_l_6ac;
	case 1710ULL: goto x86_l_6ae;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1724ULL: goto x86_l_6bc;
	case 1730ULL: goto x86_l_6c2;
	case 1733ULL: goto x86_l_6c5;
	case 1739ULL: goto x86_l_6cb;
	case 1745ULL: goto x86_l_6d1;
	case 1751ULL: goto x86_l_6d7;
	case 1754ULL: goto x86_l_6da;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1776ULL: goto x86_l_6f0;
	case 1778ULL: goto x86_l_6f2;
	case 1784ULL: goto x86_l_6f8;
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
	/* 0x31: je     11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e;
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
	/* 0x56: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5e:
	/* 0x5e: lea    rax,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_62:
	/* 0x62: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_67:
	/* 0x67: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6b:
	/* 0x6b: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_73:
	/* 0x73: lea    rax,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7c:
	/* 0x7c: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_80:
	/* 0x80: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_88:
	/* 0x88: lea    rax,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8c:
	/* 0x8c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_91:
	/* 0x91: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_95:
	/* 0x95: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9d:
	/* 0x9d: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a1:
	/* 0xa1: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a6:
	/* 0xa6: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_af:
	/* 0xaf: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b3:
	/* 0xb3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b8:
	/* 0xb8: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bc:
	/* 0xbc: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c1:
	/* 0xc1: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c5:
	/* 0xc5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca:
	/* 0xca: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce:
	/* 0xce: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d3:
	/* 0xd3: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7:
	/* 0xd7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_dc:
	/* 0xdc: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df:
	/* 0xdf: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e4:
	/* 0xe4: jne    12f <generic_sleepable_preload+0x12f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12f;
	}
x86_l_e6:
	/* 0xe6: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e9:
	/* 0xe9: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_ee:
	/* 0xee: jne    18f <generic_sleepable_preload+0x18f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18f;
	}
x86_l_f4:
	/* 0xf4: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f7:
	/* 0xf7: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_fc:
	/* 0xfc: jne    1ef <generic_sleepable_preload+0x1ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ef;
	}
x86_l_102:
	/* 0x102: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_105:
	/* 0x105: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_10a:
	/* 0x10a: jne    24f <generic_sleepable_preload+0x24f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f;
	}
x86_l_110:
	/* 0x110: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_113:
	/* 0x113: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_118:
	/* 0x118: jne    2af <generic_sleepable_preload+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2af;
	}
x86_l_11e:
	/* 0x11e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_120:
	/* 0x120: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_127:
	/* 0x127: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_129:
	/* 0x129: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: jmp    38bb <generic_sleepable_preload+0x38bb> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_12f:
	/* 0x12f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_131:
	/* 0x131: js     311 <generic_sleepable_preload+0x311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_311;
	}
x86_l_137:
	/* 0x137: movzx  eax,BYTE PTR [rbx+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_13e:
	/* 0x13e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_140:
	/* 0x140: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_143:
	/* 0x143: jg     500 <generic_sleepable_preload+0x500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_500;
	}
x86_l_149:
	/* 0x149: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c:
	/* 0x14c: je     a46 <generic_sleepable_preload+0xa46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2630ULL;
	}
x86_l_152:
	/* 0x152: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_155:
	/* 0x155: jne    bb1 <generic_sleepable_preload+0xbb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2993ULL;
	}
x86_l_15b:
	/* 0x15b: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_161:
	/* 0x161: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_167:
	/* 0x167: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16a:
	/* 0x16a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16f:
	/* 0x16f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_174:
	/* 0x174: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_179:
	/* 0x179: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17e:
	/* 0x17e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180:
	/* 0x180: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_182:
	/* 0x182: je     a52 <generic_sleepable_preload+0xa52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2642ULL;
	}
x86_l_188:
	/* 0x188: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18a:
	/* 0x18a: jmp    bb1 <generic_sleepable_preload+0xbb1> */
	return 2993ULL;
x86_l_18f:
	/* 0x18f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_191:
	/* 0x191: js     374 <generic_sleepable_preload+0x374> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_374;
	}
x86_l_197:
	/* 0x197: movzx  eax,BYTE PTR [rbx+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_19e:
	/* 0x19e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0:
	/* 0x1a0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a3:
	/* 0x1a3: jg     5c5 <generic_sleepable_preload+0x5c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5c5;
	}
x86_l_1a9:
	/* 0x1a9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ac:
	/* 0x1ac: je     a7a <generic_sleepable_preload+0xa7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2682ULL;
	}
x86_l_1b2:
	/* 0x1b2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b5:
	/* 0x1b5: jne    f52 <generic_sleepable_preload+0xf52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3922ULL;
	}
x86_l_1bb:
	/* 0x1bb: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_1c1:
	/* 0x1c1: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c7:
	/* 0x1c7: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ca:
	/* 0x1ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cf:
	/* 0x1cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d4:
	/* 0x1d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d9:
	/* 0x1d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1de:
	/* 0x1de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0:
	/* 0x1e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e2:
	/* 0x1e2: je     a86 <generic_sleepable_preload+0xa86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2694ULL;
	}
x86_l_1e8:
	/* 0x1e8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ea:
	/* 0x1ea: jmp    f52 <generic_sleepable_preload+0xf52> */
	return 3922ULL;
x86_l_1ef:
	/* 0x1ef: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1f1:
	/* 0x1f1: js     3d7 <generic_sleepable_preload+0x3d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d7;
	}
x86_l_1f7:
	/* 0x1f7: movzx  eax,BYTE PTR [rbx+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_1fe:
	/* 0x1fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_200:
	/* 0x200: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_203:
	/* 0x203: jg     63f <generic_sleepable_preload+0x63f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_63f;
	}
x86_l_209:
	/* 0x209: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20c:
	/* 0x20c: je     ab3 <generic_sleepable_preload+0xab3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2739ULL;
	}
x86_l_212:
	/* 0x212: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_215:
	/* 0x215: jne    1305 <generic_sleepable_preload+0x1305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4869ULL;
	}
x86_l_21b:
	/* 0x21b: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_221:
	/* 0x221: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_227:
	/* 0x227: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22a:
	/* 0x22a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f:
	/* 0x22f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_234:
	/* 0x234: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_239:
	/* 0x239: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23e:
	/* 0x23e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240:
	/* 0x240: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_242:
	/* 0x242: je     abf <generic_sleepable_preload+0xabf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2751ULL;
	}
x86_l_248:
	/* 0x248: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24a:
	/* 0x24a: jmp    1305 <generic_sleepable_preload+0x1305> */
	return 4869ULL;
x86_l_24f:
	/* 0x24f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_251:
	/* 0x251: js     43a <generic_sleepable_preload+0x43a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_43a;
	}
x86_l_257:
	/* 0x257: movzx  eax,BYTE PTR [rbx+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_25e:
	/* 0x25e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_260:
	/* 0x260: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_263:
	/* 0x263: jg     6b9 <generic_sleepable_preload+0x6b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6b9;
	}
x86_l_269:
	/* 0x269: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26c:
	/* 0x26c: je     ae7 <generic_sleepable_preload+0xae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2791ULL;
	}
x86_l_272:
	/* 0x272: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_275:
	/* 0x275: jne    16b8 <generic_sleepable_preload+0x16b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5816ULL;
	}
x86_l_27b:
	/* 0x27b: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_281:
	/* 0x281: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_287:
	/* 0x287: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28a:
	/* 0x28a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28f:
	/* 0x28f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_294:
	/* 0x294: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_299:
	/* 0x299: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29e:
	/* 0x29e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0:
	/* 0x2a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a2:
	/* 0x2a2: je     af3 <generic_sleepable_preload+0xaf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2803ULL;
	}
x86_l_2a8:
	/* 0x2a8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aa:
	/* 0x2aa: jmp    16b8 <generic_sleepable_preload+0x16b8> */
	return 5816ULL;
x86_l_2af:
	/* 0x2af: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2b1:
	/* 0x2b1: js     49d <generic_sleepable_preload+0x49d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_49d;
	}
x86_l_2b7:
	/* 0x2b7: movzx  eax,BYTE PTR [rbx+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_2be:
	/* 0x2be: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c0:
	/* 0x2c0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c3:
	/* 0x2c3: jg     733 <generic_sleepable_preload+0x733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1843ULL;
	}
x86_l_2c9:
	/* 0x2c9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cc:
	/* 0x2cc: je     b1b <generic_sleepable_preload+0xb1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2843ULL;
	}
x86_l_2d2:
	/* 0x2d2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d5:
	/* 0x2d5: jne    1a6d <generic_sleepable_preload+0x1a6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6765ULL;
	}
x86_l_2db:
	/* 0x2db: mov    eax,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_2e1:
	/* 0x2e1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e6:
	/* 0x2e6: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e9:
	/* 0x2e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ee:
	/* 0x2ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f3:
	/* 0x2f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f8:
	/* 0x2f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd:
	/* 0x2fd: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_300:
	/* 0x300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_302:
	/* 0x302: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_304:
	/* 0x304: je     b27 <generic_sleepable_preload+0xb27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2855ULL;
	}
x86_l_30a:
	/* 0x30a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30c:
	/* 0x30c: jmp    1a6d <generic_sleepable_preload+0x1a6d> */
	return 6765ULL;
x86_l_311:
	/* 0x311: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_318:
	/* 0x318: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_31f:
	/* 0x31f: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_325:
	/* 0x325: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_327:
	/* 0x327: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_32a:
	/* 0x32a: jle    7af <generic_sleepable_preload+0x7af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1967ULL;
	}
x86_l_330:
	/* 0x330: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_333:
	/* 0x333: jle    893 <generic_sleepable_preload+0x893> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2195ULL;
	}
x86_l_339:
	/* 0x339: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_33c:
	/* 0x33c: jle    1fa5 <generic_sleepable_preload+0x1fa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8101ULL;
	}
x86_l_342:
	/* 0x342: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_34a:
	/* 0x34a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_34d:
	/* 0x34d: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8124ULL;
	}
x86_l_353:
	/* 0x353: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_358:
	/* 0x358: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_35b:
	/* 0x35b: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8124ULL;
	}
x86_l_361:
	/* 0x361: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_364:
	/* 0x364: jne    1fcf <generic_sleepable_preload+0x1fcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8143ULL;
	}
x86_l_36a:
	/* 0x36a: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_36f:
	/* 0x36f: jmp    1fbc <generic_sleepable_preload+0x1fbc> */
	return 8124ULL;
x86_l_374:
	/* 0x374: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_37b:
	/* 0x37b: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_382:
	/* 0x382: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_388:
	/* 0x388: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38a:
	/* 0x38a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_38d:
	/* 0x38d: jle    7df <generic_sleepable_preload+0x7df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2015ULL;
	}
x86_l_393:
	/* 0x393: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_396:
	/* 0x396: jle    8c0 <generic_sleepable_preload+0x8c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2240ULL;
	}
x86_l_39c:
	/* 0x39c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_39f:
	/* 0x39f: jle    22a0 <generic_sleepable_preload+0x22a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8864ULL;
	}
x86_l_3a5:
	/* 0x3a5: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3ad:
	/* 0x3ad: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3b0:
	/* 0x3b0: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_3b6:
	/* 0x3b6: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3bb:
	/* 0x3bb: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3be:
	/* 0x3be: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_3c4:
	/* 0x3c4: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3c9:
	/* 0x3c9: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3cc:
	/* 0x3cc: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_3d2:
	/* 0x3d2: jmp    2677 <generic_sleepable_preload+0x2677> */
	return 9847ULL;
x86_l_3d7:
	/* 0x3d7: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_3de:
	/* 0x3de: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_3e5:
	/* 0x3e5: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3eb:
	/* 0x3eb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ed:
	/* 0x3ed: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3f0:
	/* 0x3f0: jle    80c <generic_sleepable_preload+0x80c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2060ULL;
	}
x86_l_3f6:
	/* 0x3f6: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f9:
	/* 0x3f9: jle    8ed <generic_sleepable_preload+0x8ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2285ULL;
	}
x86_l_3ff:
	/* 0x3ff: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_402:
	/* 0x402: jle    22c4 <generic_sleepable_preload+0x22c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8900ULL;
	}
x86_l_408:
	/* 0x408: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_410:
	/* 0x410: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_413:
	/* 0x413: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_419:
	/* 0x419: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_41e:
	/* 0x41e: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_421:
	/* 0x421: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_427:
	/* 0x427: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_42c:
	/* 0x42c: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_42f:
	/* 0x42f: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_435:
	/* 0x435: jmp    297b <generic_sleepable_preload+0x297b> */
	return 10619ULL;
x86_l_43a:
	/* 0x43a: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_441:
	/* 0x441: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_448:
	/* 0x448: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_44e:
	/* 0x44e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_450:
	/* 0x450: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_453:
	/* 0x453: jle    839 <generic_sleepable_preload+0x839> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2105ULL;
	}
x86_l_459:
	/* 0x459: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_45c:
	/* 0x45c: jle    91a <generic_sleepable_preload+0x91a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2330ULL;
	}
x86_l_462:
	/* 0x462: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_465:
	/* 0x465: jle    22e8 <generic_sleepable_preload+0x22e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8936ULL;
	}
x86_l_46b:
	/* 0x46b: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_473:
	/* 0x473: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_476:
	/* 0x476: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_47c:
	/* 0x47c: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_481:
	/* 0x481: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_484:
	/* 0x484: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_48a:
	/* 0x48a: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_48f:
	/* 0x48f: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_492:
	/* 0x492: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_498:
	/* 0x498: jmp    2c7f <generic_sleepable_preload+0x2c7f> */
	return 11391ULL;
x86_l_49d:
	/* 0x49d: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4a4:
	/* 0x4a4: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4ab:
	/* 0x4ab: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_4b1:
	/* 0x4b1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b3:
	/* 0x4b3: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4b6:
	/* 0x4b6: jle    866 <generic_sleepable_preload+0x866> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2150ULL;
	}
x86_l_4bc:
	/* 0x4bc: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4bf:
	/* 0x4bf: jle    947 <generic_sleepable_preload+0x947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2375ULL;
	}
x86_l_4c5:
	/* 0x4c5: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4c8:
	/* 0x4c8: jle    230c <generic_sleepable_preload+0x230c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8972ULL;
	}
x86_l_4ce:
	/* 0x4ce: mov    r14,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4d6:
	/* 0x4d6: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_4d9:
	/* 0x4d9: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_4df:
	/* 0x4df: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4e4:
	/* 0x4e4: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4e7:
	/* 0x4e7: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_4ed:
	/* 0x4ed: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4f2:
	/* 0x4f2: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4f5:
	/* 0x4f5: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_4fb:
	/* 0x4fb: jmp    2336 <generic_sleepable_preload+0x2336> */
	return 9014ULL;
x86_l_500:
	/* 0x500: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_503:
	/* 0x503: je     b4f <generic_sleepable_preload+0xb4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2895ULL;
	}
x86_l_509:
	/* 0x509: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50c:
	/* 0x50c: jne    bb1 <generic_sleepable_preload+0xbb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2993ULL;
	}
x86_l_512:
	/* 0x512: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_518:
	/* 0x518: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_51e:
	/* 0x51e: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_521:
	/* 0x521: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_526:
	/* 0x526: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_52b:
	/* 0x52b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_530:
	/* 0x530: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_535:
	/* 0x535: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_537:
	/* 0x537: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_539:
	/* 0x539: jne    bae <generic_sleepable_preload+0xbae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2990ULL;
	}
x86_l_53f:
	/* 0x53f: mov    edx,DWORD PTR [rbx+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_545:
	/* 0x545: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_54b:
	/* 0x54b: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_54e:
	/* 0x54e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_551:
	/* 0x551: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_556:
	/* 0x556: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55b:
	/* 0x55b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_560:
	/* 0x560: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_562:
	/* 0x562: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_564:
	/* 0x564: jne    bae <generic_sleepable_preload+0xbae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2990ULL;
	}
x86_l_56a:
	/* 0x56a: movzx  eax,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_571:
	/* 0x571: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_577:
	/* 0x577: mov    rcx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_57e:
	/* 0x57e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_583:
	/* 0x583: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_586:
	/* 0x586: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58b:
	/* 0x58b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_590:
	/* 0x590: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_595:
	/* 0x595: movzx  ecx,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_59c:
	/* 0x59c: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_5a2:
	/* 0x5a2: mov    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_5a9:
	/* 0x5a9: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5ae:
	/* 0x5ae: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5b1:
	/* 0x5b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b6:
	/* 0x5b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b8:
	/* 0x5b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ba:
	/* 0x5ba: jne    bae <generic_sleepable_preload+0xbae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2990ULL;
	}
x86_l_5c0:
	/* 0x5c0: jmp    a52 <generic_sleepable_preload+0xa52> */
	return 2642ULL;
x86_l_5c5:
	/* 0x5c5: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5c8:
	/* 0x5c8: je     ea5 <generic_sleepable_preload+0xea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3749ULL;
	}
x86_l_5ce:
	/* 0x5ce: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5d1:
	/* 0x5d1: jne    f52 <generic_sleepable_preload+0xf52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3922ULL;
	}
x86_l_5d7:
	/* 0x5d7: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_5dd:
	/* 0x5dd: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5e3:
	/* 0x5e3: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e6:
	/* 0x5e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5eb:
	/* 0x5eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f0:
	/* 0x5f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f5:
	/* 0x5f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fa:
	/* 0x5fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fc:
	/* 0x5fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fe:
	/* 0x5fe: jne    f4f <generic_sleepable_preload+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3919ULL;
	}
x86_l_604:
	/* 0x604: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_609:
	/* 0x609: add    rcx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_610:
	/* 0x610: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_615:
	/* 0x615: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_61a:
	/* 0x61a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_61f:
	/* 0x61f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_624:
	/* 0x624: add    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_62b:
	/* 0x62b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_630:
	/* 0x630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_632:
	/* 0x632: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_634:
	/* 0x634: jne    f4f <generic_sleepable_preload+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3919ULL;
	}
x86_l_63a:
	/* 0x63a: jmp    a86 <generic_sleepable_preload+0xa86> */
	return 2694ULL;
x86_l_63f:
	/* 0x63f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_642:
	/* 0x642: je     1258 <generic_sleepable_preload+0x1258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4696ULL;
	}
x86_l_648:
	/* 0x648: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_64b:
	/* 0x64b: jne    1305 <generic_sleepable_preload+0x1305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4869ULL;
	}
x86_l_651:
	/* 0x651: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_657:
	/* 0x657: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_65d:
	/* 0x65d: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_660:
	/* 0x660: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_665:
	/* 0x665: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66a:
	/* 0x66a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66f:
	/* 0x66f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_674:
	/* 0x674: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676:
	/* 0x676: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_678:
	/* 0x678: jne    1302 <generic_sleepable_preload+0x1302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4866ULL;
	}
x86_l_67e:
	/* 0x67e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_683:
	/* 0x683: add    rcx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_68a:
	/* 0x68a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68f:
	/* 0x68f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_694:
	/* 0x694: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_699:
	/* 0x699: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69e:
	/* 0x69e: add    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_6a5:
	/* 0x6a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6aa:
	/* 0x6aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ac:
	/* 0x6ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6ae:
	/* 0x6ae: jne    1302 <generic_sleepable_preload+0x1302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4866ULL;
	}
x86_l_6b4:
	/* 0x6b4: jmp    abf <generic_sleepable_preload+0xabf> */
	return 2751ULL;
x86_l_6b9:
	/* 0x6b9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6bc:
	/* 0x6bc: je     160b <generic_sleepable_preload+0x160b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5643ULL;
	}
x86_l_6c2:
	/* 0x6c2: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6c5:
	/* 0x6c5: jne    16b8 <generic_sleepable_preload+0x16b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5816ULL;
	}
x86_l_6cb:
	/* 0x6cb: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_6d1:
	/* 0x6d1: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6d7:
	/* 0x6d7: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6da:
	/* 0x6da: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6df:
	/* 0x6df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6e4:
	/* 0x6e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6e9:
	/* 0x6e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ee:
	/* 0x6ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f0:
	/* 0x6f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6f2:
	/* 0x6f2: jne    16b5 <generic_sleepable_preload+0x16b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5813ULL;
	}
x86_l_6f8:
	/* 0x6f8: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 1789ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1789ULL: goto x86_l_6fd;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1806ULL: goto x86_l_70e;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1830ULL: goto x86_l_726;
	case 1832ULL: goto x86_l_728;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1846ULL: goto x86_l_736;
	case 1852ULL: goto x86_l_73c;
	case 1855ULL: goto x86_l_73f;
	case 1861ULL: goto x86_l_745;
	case 1867ULL: goto x86_l_74b;
	case 1872ULL: goto x86_l_750;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1898ULL: goto x86_l_76a;
	case 1900ULL: goto x86_l_76c;
	case 1902ULL: goto x86_l_76e;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1954ULL: goto x86_l_7a2;
	case 1956ULL: goto x86_l_7a4;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1970ULL: goto x86_l_7b2;
	case 1976ULL: goto x86_l_7b8;
	case 1979ULL: goto x86_l_7bb;
	case 1985ULL: goto x86_l_7c1;
	case 1988ULL: goto x86_l_7c4;
	case 1990ULL: goto x86_l_7c6;
	case 1996ULL: goto x86_l_7cc;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2010ULL: goto x86_l_7da;
	case 2015ULL: goto x86_l_7df;
	case 2018ULL: goto x86_l_7e2;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2033ULL: goto x86_l_7f1;
	case 2035ULL: goto x86_l_7f3;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2049ULL: goto x86_l_801;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2063ULL: goto x86_l_80f;
	case 2069ULL: goto x86_l_815;
	case 2072ULL: goto x86_l_818;
	case 2078ULL: goto x86_l_81e;
	case 2080ULL: goto x86_l_820;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2094ULL: goto x86_l_82e;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2108ULL: goto x86_l_83c;
	case 2114ULL: goto x86_l_842;
	case 2117ULL: goto x86_l_845;
	case 2123ULL: goto x86_l_84b;
	case 2125ULL: goto x86_l_84d;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2139ULL: goto x86_l_85b;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2153ULL: goto x86_l_869;
	case 2159ULL: goto x86_l_86f;
	case 2162ULL: goto x86_l_872;
	case 2168ULL: goto x86_l_878;
	case 2170ULL: goto x86_l_87a;
	case 2176ULL: goto x86_l_880;
	case 2179ULL: goto x86_l_883;
	case 2184ULL: goto x86_l_888;
	case 2190ULL: goto x86_l_88e;
	case 2195ULL: goto x86_l_893;
	case 2198ULL: goto x86_l_896;
	case 2204ULL: goto x86_l_89c;
	case 2212ULL: goto x86_l_8a4;
	case 2215ULL: goto x86_l_8a7;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2229ULL: goto x86_l_8b5;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2249ULL: goto x86_l_8c9;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2274ULL: goto x86_l_8e2;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2288ULL: goto x86_l_8f0;
	case 2294ULL: goto x86_l_8f6;
	case 2302ULL: goto x86_l_8fe;
	case 2305ULL: goto x86_l_901;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2319ULL: goto x86_l_90f;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2333ULL: goto x86_l_91d;
	case 2339ULL: goto x86_l_923;
	case 2347ULL: goto x86_l_92b;
	case 2350ULL: goto x86_l_92e;
	case 2356ULL: goto x86_l_934;
	case 2361ULL: goto x86_l_939;
	case 2364ULL: goto x86_l_93c;
	case 2370ULL: goto x86_l_942;
	case 2375ULL: goto x86_l_947;
	case 2378ULL: goto x86_l_94a;
	case 2384ULL: goto x86_l_950;
	case 2392ULL: goto x86_l_958;
	case 2395ULL: goto x86_l_95b;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2409ULL: goto x86_l_969;
	case 2415ULL: goto x86_l_96f;
	case 2420ULL: goto x86_l_974;
	case 2423ULL: goto x86_l_977;
	case 2429ULL: goto x86_l_97d;
	case 2434ULL: goto x86_l_982;
	case 2437ULL: goto x86_l_985;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2451ULL: goto x86_l_993;
	case 2457ULL: goto x86_l_999;
	case 2462ULL: goto x86_l_99e;
	case 2465ULL: goto x86_l_9a1;
	case 2471ULL: goto x86_l_9a7;
	case 2476ULL: goto x86_l_9ac;
	case 2479ULL: goto x86_l_9af;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2493ULL: goto x86_l_9bd;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2507ULL: goto x86_l_9cb;
	case 2513ULL: goto x86_l_9d1;
	case 2518ULL: goto x86_l_9d6;
	case 2521ULL: goto x86_l_9d9;
	case 2527ULL: goto x86_l_9df;
	case 2532ULL: goto x86_l_9e4;
	case 2535ULL: goto x86_l_9e7;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2549ULL: goto x86_l_9f5;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2563ULL: goto x86_l_a03;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2577ULL: goto x86_l_a11;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2591ULL: goto x86_l_a1f;
	case 2597ULL: goto x86_l_a25;
	case 2602ULL: goto x86_l_a2a;
	case 2605ULL: goto x86_l_a2d;
	case 2611ULL: goto x86_l_a33;
	case 2616ULL: goto x86_l_a38;
	case 2619ULL: goto x86_l_a3b;
	case 2625ULL: goto x86_l_a41;
	case 2630ULL: goto x86_l_a46;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2649ULL: goto x86_l_a59;
	case 2656ULL: goto x86_l_a60;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2673ULL: goto x86_l_a71;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2689ULL: goto x86_l_a81;
	case 2694ULL: goto x86_l_a86;
	case 2701ULL: goto x86_l_a8d;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2720ULL: goto x86_l_aa0;
	case 2725ULL: goto x86_l_aa5;
	case 2730ULL: goto x86_l_aaa;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2758ULL: goto x86_l_ac6;
	case 2765ULL: goto x86_l_acd;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2798ULL: goto x86_l_aee;
	case 2803ULL: goto x86_l_af3;
	case 2810ULL: goto x86_l_afa;
	case 2817ULL: goto x86_l_b01;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2834ULL: goto x86_l_b12;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2850ULL: goto x86_l_b22;
	case 2855ULL: goto x86_l_b27;
	case 2862ULL: goto x86_l_b2e;
	case 2869ULL: goto x86_l_b35;
	case 2876ULL: goto x86_l_b3c;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2901ULL: goto x86_l_b55;
	case 2907ULL: goto x86_l_b5b;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2934ULL: goto x86_l_b76;
	case 2936ULL: goto x86_l_b78;
	case 2941ULL: goto x86_l_b7d;
	case 2948ULL: goto x86_l_b84;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2982ULL: goto x86_l_ba6;
	case 2984ULL: goto x86_l_ba8;
	case 2990ULL: goto x86_l_bae;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3001ULL: goto x86_l_bb9;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3015ULL: goto x86_l_bc7;
	case 3018ULL: goto x86_l_bca;
	case 3021ULL: goto x86_l_bcd;
	case 3026ULL: goto x86_l_bd2;
	case 3031ULL: goto x86_l_bd7;
	case 3033ULL: goto x86_l_bd9;
	case 3038ULL: goto x86_l_bde;
	case 3043ULL: goto x86_l_be3;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3058ULL: goto x86_l_bf2;
	case 3060ULL: goto x86_l_bf4;
	case 3062ULL: goto x86_l_bf6;
	case 3068ULL: goto x86_l_bfc;
	case 3073ULL: goto x86_l_c01;
	case 3079ULL: goto x86_l_c07;
	case 3082ULL: goto x86_l_c0a;
	case 3087ULL: goto x86_l_c0f;
	case 3092ULL: goto x86_l_c14;
	case 3097ULL: goto x86_l_c19;
	case 3099ULL: goto x86_l_c1b;
	case 3104ULL: goto x86_l_c20;
	case 3109ULL: goto x86_l_c25;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3126ULL: goto x86_l_c36;
	case 3128ULL: goto x86_l_c38;
	case 3134ULL: goto x86_l_c3e;
	case 3142ULL: goto x86_l_c46;
	case 3148ULL: goto x86_l_c4c;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3164ULL: goto x86_l_c5c;
	case 3172ULL: goto x86_l_c64;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3201ULL: goto x86_l_c81;
	case 3203ULL: goto x86_l_c83;
	case 3209ULL: goto x86_l_c89;
	case 3217ULL: goto x86_l_c91;
	case 3223ULL: goto x86_l_c97;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3247ULL: goto x86_l_caf;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3276ULL: goto x86_l_ccc;
	case 3278ULL: goto x86_l_cce;
	case 3284ULL: goto x86_l_cd4;
	case 3292ULL: goto x86_l_cdc;
	case 3298ULL: goto x86_l_ce2;
	case 3304ULL: goto x86_l_ce8;
	case 3309ULL: goto x86_l_ced;
	case 3314ULL: goto x86_l_cf2;
	case 3322ULL: goto x86_l_cfa;
	case 3324ULL: goto x86_l_cfc;
	case 3329ULL: goto x86_l_d01;
	case 3334ULL: goto x86_l_d06;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3351ULL: goto x86_l_d17;
	case 3353ULL: goto x86_l_d19;
	case 3359ULL: goto x86_l_d1f;
	case 3367ULL: goto x86_l_d27;
	case 3373ULL: goto x86_l_d2d;
	case 3379ULL: goto x86_l_d33;
	case 3384ULL: goto x86_l_d38;
	case 3389ULL: goto x86_l_d3d;
	case 3397ULL: goto x86_l_d45;
	case 3399ULL: goto x86_l_d47;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3426ULL: goto x86_l_d62;
	case 3428ULL: goto x86_l_d64;
	case 3434ULL: goto x86_l_d6a;
	case 3442ULL: goto x86_l_d72;
	case 3448ULL: goto x86_l_d78;
	case 3454ULL: goto x86_l_d7e;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3472ULL: goto x86_l_d90;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3489ULL: goto x86_l_da1;
	case 3494ULL: goto x86_l_da6;
	case 3499ULL: goto x86_l_dab;
	case 3501ULL: goto x86_l_dad;
	case 3503ULL: goto x86_l_daf;
	case 3509ULL: goto x86_l_db5;
	case 3517ULL: goto x86_l_dbd;
	case 3523ULL: goto x86_l_dc3;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3574ULL: goto x86_l_df6;
	case 3576ULL: goto x86_l_df8;
	case 3578ULL: goto x86_l_dfa;
	case 3584ULL: goto x86_l_e00;
	case 3592ULL: goto x86_l_e08;
	case 3598ULL: goto x86_l_e0e;
	case 3604ULL: goto x86_l_e14;
	case 3609ULL: goto x86_l_e19;
	case 3614ULL: goto x86_l_e1e;
	case 3622ULL: goto x86_l_e26;
	case 3624ULL: goto x86_l_e28;
	case 3629ULL: goto x86_l_e2d;
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3651ULL: goto x86_l_e43;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6fd:
	/* 0x6fd: add    rcx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_704:
	/* 0x704: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_709:
	/* 0x709: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_70e:
	/* 0x70e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_713:
	/* 0x713: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_718:
	/* 0x718: add    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_71f:
	/* 0x71f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_724:
	/* 0x724: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_726:
	/* 0x726: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_728:
	/* 0x728: jne    16b5 <generic_sleepable_preload+0x16b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5813ULL;
	}
x86_l_72e:
	/* 0x72e: jmp    af3 <generic_sleepable_preload+0xaf3> */
	goto x86_l_af3;
x86_l_733:
	/* 0x733: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_736:
	/* 0x736: je     19be <generic_sleepable_preload+0x19be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6590ULL;
	}
x86_l_73c:
	/* 0x73c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_73f:
	/* 0x73f: jne    1a6d <generic_sleepable_preload+0x1a6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6765ULL;
	}
x86_l_745:
	/* 0x745: mov    eax,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_74b:
	/* 0x74b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_750:
	/* 0x750: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_753:
	/* 0x753: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_758:
	/* 0x758: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_75d:
	/* 0x75d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_762:
	/* 0x762: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_767:
	/* 0x767: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_76a:
	/* 0x76a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76c:
	/* 0x76c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_76e:
	/* 0x76e: jne    1a6a <generic_sleepable_preload+0x1a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6762ULL;
	}
x86_l_774:
	/* 0x774: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_779:
	/* 0x779: add    rcx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_780:
	/* 0x780: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_785:
	/* 0x785: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_78a:
	/* 0x78a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_78f:
	/* 0x78f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_794:
	/* 0x794: add    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_79b:
	/* 0x79b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a0:
	/* 0x7a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a2:
	/* 0x7a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7a4:
	/* 0x7a4: jne    1a6a <generic_sleepable_preload+0x1a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6762ULL;
	}
x86_l_7aa:
	/* 0x7aa: jmp    b27 <generic_sleepable_preload+0xb27> */
	goto x86_l_b27;
x86_l_7af:
	/* 0x7af: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_7b2:
	/* 0x7b2: jg     974 <generic_sleepable_preload+0x974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_974;
	}
x86_l_7b8:
	/* 0x7b8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7bb:
	/* 0x7bb: jg     1e5b <generic_sleepable_preload+0x1e5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7771ULL;
	}
x86_l_7c1:
	/* 0x7c1: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_7c4:
	/* 0x7c4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_7c6:
	/* 0x7c6: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8124ULL;
	}
x86_l_7cc:
	/* 0x7cc: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7d1:
	/* 0x7d1: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7d4:
	/* 0x7d4: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8124ULL;
	}
x86_l_7da:
	/* 0x7da: jmp    1fcf <generic_sleepable_preload+0x1fcf> */
	return 8143ULL;
x86_l_7df:
	/* 0x7df: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_7e2:
	/* 0x7e2: jg     99e <generic_sleepable_preload+0x99e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_99e;
	}
x86_l_7e8:
	/* 0x7e8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7eb:
	/* 0x7eb: jg     1e7c <generic_sleepable_preload+0x1e7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7804ULL;
	}
x86_l_7f1:
	/* 0x7f1: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_7f3:
	/* 0x7f3: je     2661 <generic_sleepable_preload+0x2661> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9825ULL;
	}
x86_l_7f9:
	/* 0x7f9: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7fe:
	/* 0x7fe: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_801:
	/* 0x801: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_807:
	/* 0x807: jmp    2677 <generic_sleepable_preload+0x2677> */
	return 9847ULL;
x86_l_80c:
	/* 0x80c: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_80f:
	/* 0x80f: jg     9c8 <generic_sleepable_preload+0x9c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_9c8;
	}
x86_l_815:
	/* 0x815: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_818:
	/* 0x818: jg     1e9d <generic_sleepable_preload+0x1e9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7837ULL;
	}
x86_l_81e:
	/* 0x81e: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_820:
	/* 0x820: je     2965 <generic_sleepable_preload+0x2965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10597ULL;
	}
x86_l_826:
	/* 0x826: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_82b:
	/* 0x82b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_82e:
	/* 0x82e: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_834:
	/* 0x834: jmp    297b <generic_sleepable_preload+0x297b> */
	return 10619ULL;
x86_l_839:
	/* 0x839: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_83c:
	/* 0x83c: jg     9f2 <generic_sleepable_preload+0x9f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_9f2;
	}
x86_l_842:
	/* 0x842: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_845:
	/* 0x845: jg     1ebe <generic_sleepable_preload+0x1ebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7870ULL;
	}
x86_l_84b:
	/* 0x84b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_84d:
	/* 0x84d: je     2c69 <generic_sleepable_preload+0x2c69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11369ULL;
	}
x86_l_853:
	/* 0x853: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_858:
	/* 0x858: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_85b:
	/* 0x85b: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_861:
	/* 0x861: jmp    2c7f <generic_sleepable_preload+0x2c7f> */
	return 11391ULL;
x86_l_866:
	/* 0x866: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_869:
	/* 0x869: jg     a1c <generic_sleepable_preload+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a1c;
	}
x86_l_86f:
	/* 0x86f: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_872:
	/* 0x872: jg     1edf <generic_sleepable_preload+0x1edf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7903ULL;
	}
x86_l_878:
	/* 0x878: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_87a:
	/* 0x87a: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_880:
	/* 0x880: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_883:
	/* 0x883: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_888:
	/* 0x888: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_88e:
	/* 0x88e: jmp    2336 <generic_sleepable_preload+0x2336> */
	return 9014ULL;
x86_l_893:
	/* 0x893: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_896:
	/* 0x896: jg     1da7 <generic_sleepable_preload+0x1da7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7591ULL;
	}
x86_l_89c:
	/* 0x89c: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a4:
	/* 0x8a4: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8a7:
	/* 0x8a7: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8124ULL;
	}
x86_l_8ad:
	/* 0x8ad: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8b2:
	/* 0x8b2: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8b5:
	/* 0x8b5: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8124ULL;
	}
x86_l_8bb:
	/* 0x8bb: jmp    1fcf <generic_sleepable_preload+0x1fcf> */
	return 8143ULL;
x86_l_8c0:
	/* 0x8c0: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8c3:
	/* 0x8c3: jg     1dcb <generic_sleepable_preload+0x1dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7627ULL;
	}
x86_l_8c9:
	/* 0x8c9: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8d1:
	/* 0x8d1: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8d4:
	/* 0x8d4: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_8da:
	/* 0x8da: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8df:
	/* 0x8df: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8e2:
	/* 0x8e2: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_8e8:
	/* 0x8e8: jmp    2677 <generic_sleepable_preload+0x2677> */
	return 9847ULL;
x86_l_8ed:
	/* 0x8ed: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8f0:
	/* 0x8f0: jg     1def <generic_sleepable_preload+0x1def> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7663ULL;
	}
x86_l_8f6:
	/* 0x8f6: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8fe:
	/* 0x8fe: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_901:
	/* 0x901: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_907:
	/* 0x907: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_90c:
	/* 0x90c: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_90f:
	/* 0x90f: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_915:
	/* 0x915: jmp    297b <generic_sleepable_preload+0x297b> */
	return 10619ULL;
x86_l_91a:
	/* 0x91a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_91d:
	/* 0x91d: jg     1e13 <generic_sleepable_preload+0x1e13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7699ULL;
	}
x86_l_923:
	/* 0x923: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_92b:
	/* 0x92b: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_92e:
	/* 0x92e: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_934:
	/* 0x934: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_939:
	/* 0x939: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_93c:
	/* 0x93c: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_942:
	/* 0x942: jmp    2c7f <generic_sleepable_preload+0x2c7f> */
	return 11391ULL;
x86_l_947:
	/* 0x947: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_94a:
	/* 0x94a: jg     1e37 <generic_sleepable_preload+0x1e37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7735ULL;
	}
x86_l_950:
	/* 0x950: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_958:
	/* 0x958: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_95b:
	/* 0x95b: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_961:
	/* 0x961: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_966:
	/* 0x966: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_969:
	/* 0x969: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_96f:
	/* 0x96f: jmp    2336 <generic_sleepable_preload+0x2336> */
	return 9014ULL;
x86_l_974:
	/* 0x974: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_977:
	/* 0x977: jg     1f00 <generic_sleepable_preload+0x1f00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7936ULL;
	}
x86_l_97d:
	/* 0x97d: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_982:
	/* 0x982: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_985:
	/* 0x985: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8124ULL;
	}
x86_l_98b:
	/* 0x98b: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_990:
	/* 0x990: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_993:
	/* 0x993: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8124ULL;
	}
x86_l_999:
	/* 0x999: jmp    1fcf <generic_sleepable_preload+0x1fcf> */
	return 8143ULL;
x86_l_99e:
	/* 0x99e: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9a1:
	/* 0x9a1: jg     1f21 <generic_sleepable_preload+0x1f21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7969ULL;
	}
x86_l_9a7:
	/* 0x9a7: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9ac:
	/* 0x9ac: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9af:
	/* 0x9af: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_9b5:
	/* 0x9b5: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9ba:
	/* 0x9ba: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9bd:
	/* 0x9bd: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_9c3:
	/* 0x9c3: jmp    2677 <generic_sleepable_preload+0x2677> */
	return 9847ULL;
x86_l_9c8:
	/* 0x9c8: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9cb:
	/* 0x9cb: jg     1f42 <generic_sleepable_preload+0x1f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8002ULL;
	}
x86_l_9d1:
	/* 0x9d1: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9d6:
	/* 0x9d6: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9d9:
	/* 0x9d9: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_9df:
	/* 0x9df: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9e4:
	/* 0x9e4: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9e7:
	/* 0x9e7: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_9ed:
	/* 0x9ed: jmp    297b <generic_sleepable_preload+0x297b> */
	return 10619ULL;
x86_l_9f2:
	/* 0x9f2: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9f5:
	/* 0x9f5: jg     1f63 <generic_sleepable_preload+0x1f63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8035ULL;
	}
x86_l_9fb:
	/* 0x9fb: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a00:
	/* 0xa00: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_a03:
	/* 0xa03: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_a09:
	/* 0xa09: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a0e:
	/* 0xa0e: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_a11:
	/* 0xa11: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_a17:
	/* 0xa17: jmp    2c7f <generic_sleepable_preload+0x2c7f> */
	return 11391ULL;
x86_l_a1c:
	/* 0xa1c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_a1f:
	/* 0xa1f: jg     1f84 <generic_sleepable_preload+0x1f84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8068ULL;
	}
x86_l_a25:
	/* 0xa25: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a2a:
	/* 0xa2a: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_a2d:
	/* 0xa2d: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_a33:
	/* 0xa33: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a38:
	/* 0xa38: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_a3b:
	/* 0xa3b: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8995ULL;
	}
x86_l_a41:
	/* 0xa41: jmp    2336 <generic_sleepable_preload+0x2336> */
	return 9014ULL;
x86_l_a46:
	/* 0xa46: mov    rax,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_a4d:
	/* 0xa4d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a52:
	/* 0xa52: movzx  eax,BYTE PTR [rbx+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_a59:
	/* 0xa59: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_a60:
	/* 0xa60: cmp    BYTE PTR [rbx+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_a67:
	/* 0xa67: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_a6c:
	/* 0xa6c: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_a71:
	/* 0xa71: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_a75:
	/* 0xa75: jmp    bb1 <generic_sleepable_preload+0xbb1> */
	goto x86_l_bb1;
x86_l_a7a:
	/* 0xa7a: mov    rax,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_a81:
	/* 0xa81: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a86:
	/* 0xa86: movzx  eax,BYTE PTR [rbx+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_a8d:
	/* 0xa8d: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_a94:
	/* 0xa94: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a99:
	/* 0xa99: cmp    BYTE PTR [rbx+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_aa0:
	/* 0xaa0: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_aa5:
	/* 0xaa5: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_aaa:
	/* 0xaaa: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_aae:
	/* 0xaae: jmp    f52 <generic_sleepable_preload+0xf52> */
	return 3922ULL;
x86_l_ab3:
	/* 0xab3: mov    rax,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_aba:
	/* 0xaba: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_abf:
	/* 0xabf: movzx  eax,BYTE PTR [rbx+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_ac6:
	/* 0xac6: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_acd:
	/* 0xacd: cmp    BYTE PTR [rbx+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_ad4:
	/* 0xad4: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_ad9:
	/* 0xad9: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_ade:
	/* 0xade: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_ae2:
	/* 0xae2: jmp    1305 <generic_sleepable_preload+0x1305> */
	return 4869ULL;
x86_l_ae7:
	/* 0xae7: mov    rax,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_aee:
	/* 0xaee: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af3:
	/* 0xaf3: movzx  eax,BYTE PTR [rbx+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_afa:
	/* 0xafa: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_b01:
	/* 0xb01: cmp    BYTE PTR [rbx+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_b08:
	/* 0xb08: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_b0d:
	/* 0xb0d: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_b12:
	/* 0xb12: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_b16:
	/* 0xb16: jmp    16b8 <generic_sleepable_preload+0x16b8> */
	return 5816ULL;
x86_l_b1b:
	/* 0xb1b: mov    rax,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_b22:
	/* 0xb22: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b27:
	/* 0xb27: movzx  eax,BYTE PTR [rbx+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_b2e:
	/* 0xb2e: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_b35:
	/* 0xb35: cmp    BYTE PTR [rbx+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_b3c:
	/* 0xb3c: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_b41:
	/* 0xb41: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_b46:
	/* 0xb46: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_b4a:
	/* 0xb4a: jmp    1a6d <generic_sleepable_preload+0x1a6d> */
	return 6765ULL;
x86_l_b4f:
	/* 0xb4f: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_b55:
	/* 0xb55: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b5b:
	/* 0xb5b: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b5e:
	/* 0xb5e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b63:
	/* 0xb63: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b68:
	/* 0xb68: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b6d:
	/* 0xb6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b72:
	/* 0xb72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b74:
	/* 0xb74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b76:
	/* 0xb76: jne    bae <generic_sleepable_preload+0xbae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bae;
	}
x86_l_b78:
	/* 0xb78: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b7d:
	/* 0xb7d: add    rcx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_b84:
	/* 0xb84: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b89:
	/* 0xb89: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b8e:
	/* 0xb8e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b93:
	/* 0xb93: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b98:
	/* 0xb98: add    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_b9f:
	/* 0xb9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ba4:
	/* 0xba4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba6:
	/* 0xba6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ba8:
	/* 0xba8: je     a52 <generic_sleepable_preload+0xa52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a52;
	}
x86_l_bae:
	/* 0xbae: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_bb1:
	/* 0xbb1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb6:
	/* 0xbb6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb9:
	/* 0xbb9: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_bbc:
	/* 0xbbc: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_bc1:
	/* 0xbc1: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_bc7:
	/* 0xbc7: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bca:
	/* 0xbca: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bcd:
	/* 0xbcd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bd2:
	/* 0xbd2: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_bd7:
	/* 0xbd7: je     bfc <generic_sleepable_preload+0xbfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bfc;
	}
x86_l_bd9:
	/* 0xbd9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bde:
	/* 0xbde: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_be3:
	/* 0xbe3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_be8:
	/* 0xbe8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bed:
	/* 0xbed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf2:
	/* 0xbf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf4:
	/* 0xbf4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bf6:
	/* 0xbf6: js     1d71 <generic_sleepable_preload+0x1d71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7537ULL;
	}
x86_l_bfc:
	/* 0xbfc: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_c01:
	/* 0xc01: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_c07:
	/* 0xc07: mov    ecx,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c0a:
	/* 0xc0a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c0f:
	/* 0xc0f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c14:
	/* 0xc14: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_c19:
	/* 0xc19: je     c3e <generic_sleepable_preload+0xc3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c3e;
	}
x86_l_c1b:
	/* 0xc1b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c20:
	/* 0xc20: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c25:
	/* 0xc25: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c2a:
	/* 0xc2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2f:
	/* 0xc2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c34:
	/* 0xc34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c36:
	/* 0xc36: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c38:
	/* 0xc38: js     2616 <generic_sleepable_preload+0x2616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9750ULL;
	}
x86_l_c3e:
	/* 0xc3e: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_c46:
	/* 0xc46: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_c4c:
	/* 0xc4c: mov    ecx,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c52:
	/* 0xc52: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c57:
	/* 0xc57: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c5c:
	/* 0xc5c: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_c64:
	/* 0xc64: je     c89 <generic_sleepable_preload+0xc89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c89;
	}
x86_l_c66:
	/* 0xc66: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c6b:
	/* 0xc6b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c70:
	/* 0xc70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c75:
	/* 0xc75: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c7a:
	/* 0xc7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c7f:
	/* 0xc7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c81:
	/* 0xc81: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c83:
	/* 0xc83: js     2f6d <generic_sleepable_preload+0x2f6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12141ULL;
	}
x86_l_c89:
	/* 0xc89: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_c91:
	/* 0xc91: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_c97:
	/* 0xc97: mov    ecx,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c9d:
	/* 0xc9d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca7:
	/* 0xca7: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_caf:
	/* 0xcaf: je     cd4 <generic_sleepable_preload+0xcd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd4;
	}
x86_l_cb1:
	/* 0xcb1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cb6:
	/* 0xcb6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_cbb:
	/* 0xcbb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_cc0:
	/* 0xcc0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc5:
	/* 0xcc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cca:
	/* 0xcca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ccc:
	/* 0xccc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cce:
	/* 0xcce: js     2fd9 <generic_sleepable_preload+0x2fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12249ULL;
	}
x86_l_cd4:
	/* 0xcd4: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_cdc:
	/* 0xcdc: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_ce2:
	/* 0xce2: mov    ecx,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ce8:
	/* 0xce8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ced:
	/* 0xced: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf2:
	/* 0xcf2: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_cfa:
	/* 0xcfa: je     d1f <generic_sleepable_preload+0xd1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1f;
	}
x86_l_cfc:
	/* 0xcfc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d01:
	/* 0xd01: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d06:
	/* 0xd06: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d0b:
	/* 0xd0b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d10:
	/* 0xd10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d15:
	/* 0xd15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d17:
	/* 0xd17: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d19:
	/* 0xd19: js     3045 <generic_sleepable_preload+0x3045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12357ULL;
	}
x86_l_d1f:
	/* 0xd1f: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_d27:
	/* 0xd27: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_d2d:
	/* 0xd2d: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d33:
	/* 0xd33: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d38:
	/* 0xd38: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d3d:
	/* 0xd3d: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_d45:
	/* 0xd45: je     d6a <generic_sleepable_preload+0xd6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6a;
	}
x86_l_d47:
	/* 0xd47: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4c:
	/* 0xd4c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d51:
	/* 0xd51: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d56:
	/* 0xd56: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5b:
	/* 0xd5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d60:
	/* 0xd60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d62:
	/* 0xd62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d64:
	/* 0xd64: js     30b1 <generic_sleepable_preload+0x30b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12465ULL;
	}
x86_l_d6a:
	/* 0xd6a: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_d72:
	/* 0xd72: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_d78:
	/* 0xd78: mov    ecx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d7e:
	/* 0xd7e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d83:
	/* 0xd83: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d88:
	/* 0xd88: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_d90:
	/* 0xd90: je     db5 <generic_sleepable_preload+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db5;
	}
x86_l_d92:
	/* 0xd92: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d97:
	/* 0xd97: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d9c:
	/* 0xd9c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_da1:
	/* 0xda1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da6:
	/* 0xda6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dab:
	/* 0xdab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dad:
	/* 0xdad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_daf:
	/* 0xdaf: js     311a <generic_sleepable_preload+0x311a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12570ULL;
	}
x86_l_db5:
	/* 0xdb5: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_dbd:
	/* 0xdbd: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_dc3:
	/* 0xdc3: mov    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_dc9:
	/* 0xdc9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_dce:
	/* 0xdce: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dd3:
	/* 0xdd3: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_ddb:
	/* 0xddb: je     e00 <generic_sleepable_preload+0xe00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e00;
	}
x86_l_ddd:
	/* 0xddd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de2:
	/* 0xde2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_de7:
	/* 0xde7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_dec:
	/* 0xdec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df1:
	/* 0xdf1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_df6:
	/* 0xdf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df8:
	/* 0xdf8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dfa:
	/* 0xdfa: js     379b <generic_sleepable_preload+0x379b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14235ULL;
	}
x86_l_e00:
	/* 0xe00: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_e08:
	/* 0xe08: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_e0e:
	/* 0xe0e: mov    ecx,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e14:
	/* 0xe14: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e19:
	/* 0xe19: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e1e:
	/* 0xe1e: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_e26:
	/* 0xe26: je     e4b <generic_sleepable_preload+0xe4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3659ULL;
	}
x86_l_e28:
	/* 0xe28: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e2d:
	/* 0xe2d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e32:
	/* 0xe32: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e37:
	/* 0xe37: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3c:
	/* 0xe3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e41:
	/* 0xe41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e43:
	/* 0xe43: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 3653ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3653ULL: goto x86_l_e45;
	case 3659ULL: goto x86_l_e4b;
	case 3667ULL: goto x86_l_e53;
	case 3673ULL: goto x86_l_e59;
	case 3679ULL: goto x86_l_e5f;
	case 3684ULL: goto x86_l_e64;
	case 3689ULL: goto x86_l_e69;
	case 3697ULL: goto x86_l_e71;
	case 3703ULL: goto x86_l_e77;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3718ULL: goto x86_l_e86;
	case 3723ULL: goto x86_l_e8b;
	case 3728ULL: goto x86_l_e90;
	case 3730ULL: goto x86_l_e92;
	case 3732ULL: goto x86_l_e94;
	case 3738ULL: goto x86_l_e9a;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3755ULL: goto x86_l_eab;
	case 3761ULL: goto x86_l_eb1;
	case 3764ULL: goto x86_l_eb4;
	case 3769ULL: goto x86_l_eb9;
	case 3774ULL: goto x86_l_ebe;
	case 3779ULL: goto x86_l_ec3;
	case 3784ULL: goto x86_l_ec8;
	case 3786ULL: goto x86_l_eca;
	case 3788ULL: goto x86_l_ecc;
	case 3794ULL: goto x86_l_ed2;
	case 3800ULL: goto x86_l_ed8;
	case 3806ULL: goto x86_l_ede;
	case 3809ULL: goto x86_l_ee1;
	case 3812ULL: goto x86_l_ee4;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3827ULL: goto x86_l_ef3;
	case 3829ULL: goto x86_l_ef5;
	case 3831ULL: goto x86_l_ef7;
	case 3833ULL: goto x86_l_ef9;
	case 3840ULL: goto x86_l_f00;
	case 3846ULL: goto x86_l_f06;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3883ULL: goto x86_l_f2b;
	case 3889ULL: goto x86_l_f31;
	case 3896ULL: goto x86_l_f38;
	case 3901ULL: goto x86_l_f3d;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3911ULL: goto x86_l_f47;
	case 3913ULL: goto x86_l_f49;
	case 3919ULL: goto x86_l_f4f;
	case 3922ULL: goto x86_l_f52;
	case 3927ULL: goto x86_l_f57;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3941ULL: goto x86_l_f65;
	case 3947ULL: goto x86_l_f6b;
	case 3953ULL: goto x86_l_f71;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3969ULL: goto x86_l_f81;
	case 3971ULL: goto x86_l_f83;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4000ULL: goto x86_l_fa0;
	case 4006ULL: goto x86_l_fa6;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4026ULL: goto x86_l_fba;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4066ULL: goto x86_l_fe2;
	case 4071ULL: goto x86_l_fe7;
	case 4073ULL: goto x86_l_fe9;
	case 4075ULL: goto x86_l_feb;
	case 4081ULL: goto x86_l_ff1;
	case 4089ULL: goto x86_l_ff9;
	case 4095ULL: goto x86_l_fff;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4119ULL: goto x86_l_1017;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4148ULL: goto x86_l_1034;
	case 4150ULL: goto x86_l_1036;
	case 4156ULL: goto x86_l_103c;
	case 4164ULL: goto x86_l_1044;
	case 4170ULL: goto x86_l_104a;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4194ULL: goto x86_l_1062;
	case 4196ULL: goto x86_l_1064;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4216ULL: goto x86_l_1078;
	case 4221ULL: goto x86_l_107d;
	case 4223ULL: goto x86_l_107f;
	case 4225ULL: goto x86_l_1081;
	case 4231ULL: goto x86_l_1087;
	case 4239ULL: goto x86_l_108f;
	case 4245ULL: goto x86_l_1095;
	case 4251ULL: goto x86_l_109b;
	case 4256ULL: goto x86_l_10a0;
	case 4261ULL: goto x86_l_10a5;
	case 4269ULL: goto x86_l_10ad;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4291ULL: goto x86_l_10c3;
	case 4296ULL: goto x86_l_10c8;
	case 4298ULL: goto x86_l_10ca;
	case 4300ULL: goto x86_l_10cc;
	case 4306ULL: goto x86_l_10d2;
	case 4314ULL: goto x86_l_10da;
	case 4320ULL: goto x86_l_10e0;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4344ULL: goto x86_l_10f8;
	case 4346ULL: goto x86_l_10fa;
	case 4351ULL: goto x86_l_10ff;
	case 4356ULL: goto x86_l_1104;
	case 4361ULL: goto x86_l_1109;
	case 4366ULL: goto x86_l_110e;
	case 4371ULL: goto x86_l_1113;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4381ULL: goto x86_l_111d;
	case 4389ULL: goto x86_l_1125;
	case 4395ULL: goto x86_l_112b;
	case 4401ULL: goto x86_l_1131;
	case 4406ULL: goto x86_l_1136;
	case 4411ULL: goto x86_l_113b;
	case 4419ULL: goto x86_l_1143;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4446ULL: goto x86_l_115e;
	case 4448ULL: goto x86_l_1160;
	case 4450ULL: goto x86_l_1162;
	case 4456ULL: goto x86_l_1168;
	case 4464ULL: goto x86_l_1170;
	case 4470ULL: goto x86_l_1176;
	case 4476ULL: goto x86_l_117c;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4494ULL: goto x86_l_118e;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4511ULL: goto x86_l_119f;
	case 4516ULL: goto x86_l_11a4;
	case 4521ULL: goto x86_l_11a9;
	case 4523ULL: goto x86_l_11ab;
	case 4525ULL: goto x86_l_11ad;
	case 4531ULL: goto x86_l_11b3;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4551ULL: goto x86_l_11c7;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4569ULL: goto x86_l_11d9;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4596ULL: goto x86_l_11f4;
	case 4598ULL: goto x86_l_11f6;
	case 4600ULL: goto x86_l_11f8;
	case 4606ULL: goto x86_l_11fe;
	case 4614ULL: goto x86_l_1206;
	case 4620ULL: goto x86_l_120c;
	case 4626ULL: goto x86_l_1212;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4644ULL: goto x86_l_1224;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4670ULL: goto x86_l_123e;
	case 4675ULL: goto x86_l_1243;
	case 4677ULL: goto x86_l_1245;
	case 4679ULL: goto x86_l_1247;
	case 4685ULL: goto x86_l_124d;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4702ULL: goto x86_l_125e;
	case 4708ULL: goto x86_l_1264;
	case 4711ULL: goto x86_l_1267;
	case 4716ULL: goto x86_l_126c;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4735ULL: goto x86_l_127f;
	case 4741ULL: goto x86_l_1285;
	case 4747ULL: goto x86_l_128b;
	case 4753ULL: goto x86_l_1291;
	case 4756ULL: goto x86_l_1294;
	case 4759ULL: goto x86_l_1297;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4774ULL: goto x86_l_12a6;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4780ULL: goto x86_l_12ac;
	case 4787ULL: goto x86_l_12b3;
	case 4793ULL: goto x86_l_12b9;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4830ULL: goto x86_l_12de;
	case 4836ULL: goto x86_l_12e4;
	case 4843ULL: goto x86_l_12eb;
	case 4848ULL: goto x86_l_12f0;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4858ULL: goto x86_l_12fa;
	case 4860ULL: goto x86_l_12fc;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4877ULL: goto x86_l_130d;
	case 4880ULL: goto x86_l_1310;
	case 4888ULL: goto x86_l_1318;
	case 4894ULL: goto x86_l_131e;
	case 4900ULL: goto x86_l_1324;
	case 4903ULL: goto x86_l_1327;
	case 4908ULL: goto x86_l_132c;
	case 4916ULL: goto x86_l_1334;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4945ULL: goto x86_l_1351;
	case 4947ULL: goto x86_l_1353;
	case 4953ULL: goto x86_l_1359;
	case 4961ULL: goto x86_l_1361;
	case 4967ULL: goto x86_l_1367;
	case 4973ULL: goto x86_l_136d;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4991ULL: goto x86_l_137f;
	case 4993ULL: goto x86_l_1381;
	case 4998ULL: goto x86_l_1386;
	case 5003ULL: goto x86_l_138b;
	case 5008ULL: goto x86_l_1390;
	case 5013ULL: goto x86_l_1395;
	case 5018ULL: goto x86_l_139a;
	case 5020ULL: goto x86_l_139c;
	case 5022ULL: goto x86_l_139e;
	case 5028ULL: goto x86_l_13a4;
	case 5036ULL: goto x86_l_13ac;
	case 5042ULL: goto x86_l_13b2;
	case 5048ULL: goto x86_l_13b8;
	case 5053ULL: goto x86_l_13bd;
	case 5058ULL: goto x86_l_13c2;
	case 5066ULL: goto x86_l_13ca;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5095ULL: goto x86_l_13e7;
	case 5097ULL: goto x86_l_13e9;
	case 5103ULL: goto x86_l_13ef;
	case 5111ULL: goto x86_l_13f7;
	case 5117ULL: goto x86_l_13fd;
	case 5123ULL: goto x86_l_1403;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5141ULL: goto x86_l_1415;
	case 5143ULL: goto x86_l_1417;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5168ULL: goto x86_l_1430;
	case 5170ULL: goto x86_l_1432;
	case 5172ULL: goto x86_l_1434;
	case 5178ULL: goto x86_l_143a;
	case 5186ULL: goto x86_l_1442;
	case 5192ULL: goto x86_l_1448;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5208ULL: goto x86_l_1458;
	case 5216ULL: goto x86_l_1460;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5245ULL: goto x86_l_147d;
	case 5247ULL: goto x86_l_147f;
	case 5253ULL: goto x86_l_1485;
	case 5261ULL: goto x86_l_148d;
	case 5267ULL: goto x86_l_1493;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5291ULL: goto x86_l_14ab;
	case 5293ULL: goto x86_l_14ad;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5318ULL: goto x86_l_14c6;
	case 5320ULL: goto x86_l_14c8;
	case 5322ULL: goto x86_l_14ca;
	case 5328ULL: goto x86_l_14d0;
	case 5336ULL: goto x86_l_14d8;
	case 5342ULL: goto x86_l_14de;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5366ULL: goto x86_l_14f6;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5383ULL: goto x86_l_1507;
	case 5388ULL: goto x86_l_150c;
	case 5393ULL: goto x86_l_1511;
	case 5395ULL: goto x86_l_1513;
	case 5397ULL: goto x86_l_1515;
	case 5403ULL: goto x86_l_151b;
	case 5411ULL: goto x86_l_1523;
	case 5417ULL: goto x86_l_1529;
	case 5423ULL: goto x86_l_152f;
	case 5428ULL: goto x86_l_1534;
	case 5433ULL: goto x86_l_1539;
	case 5441ULL: goto x86_l_1541;
	case 5443ULL: goto x86_l_1543;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5458ULL: goto x86_l_1552;
	case 5463ULL: goto x86_l_1557;
	case 5468ULL: goto x86_l_155c;
	case 5470ULL: goto x86_l_155e;
	case 5472ULL: goto x86_l_1560;
	case 5478ULL: goto x86_l_1566;
	case 5486ULL: goto x86_l_156e;
	case 5492ULL: goto x86_l_1574;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5516ULL: goto x86_l_158c;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5528ULL: goto x86_l_1598;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e45:
	/* 0xe45: js     384f <generic_sleepable_preload+0x384f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14415ULL;
	}
x86_l_e4b:
	/* 0xe4b: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_e53:
	/* 0xe53: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_e59:
	/* 0xe59: mov    ecx,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_e5f:
	/* 0xe5f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e64:
	/* 0xe64: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e69:
	/* 0xe69: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_e71:
	/* 0xe71: je     3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12578ULL;
	}
x86_l_e77:
	/* 0xe77: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e7c:
	/* 0xe7c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e81:
	/* 0xe81: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e86:
	/* 0xe86: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8b:
	/* 0xe8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e90:
	/* 0xe90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e92:
	/* 0xe92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e94:
	/* 0xe94: jns    3122 <generic_sleepable_preload+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12578ULL;
	}
x86_l_e9a:
	/* 0xe9a: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_ea0:
	/* 0xea0: jmp    3120 <generic_sleepable_preload+0x3120> */
	return 12576ULL;
x86_l_ea5:
	/* 0xea5: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_eab:
	/* 0xeab: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_eb1:
	/* 0xeb1: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_eb4:
	/* 0xeb4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb9:
	/* 0xeb9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ebe:
	/* 0xebe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ec3:
	/* 0xec3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ec8:
	/* 0xec8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eca:
	/* 0xeca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ecc:
	/* 0xecc: jne    f4f <generic_sleepable_preload+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f4f;
	}
x86_l_ed2:
	/* 0xed2: mov    edx,DWORD PTR [rbx+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_ed8:
	/* 0xed8: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ede:
	/* 0xede: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ee1:
	/* 0xee1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ee4:
	/* 0xee4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ee9:
	/* 0xee9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eee:
	/* 0xeee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ef3:
	/* 0xef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef5:
	/* 0xef5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ef7:
	/* 0xef7: jne    f4f <generic_sleepable_preload+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f4f;
	}
x86_l_ef9:
	/* 0xef9: movzx  eax,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_f00:
	/* 0xf00: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_f06:
	/* 0xf06: mov    rcx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_f0d:
	/* 0xf0d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_f12:
	/* 0xf12: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f15:
	/* 0xf15: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f1a:
	/* 0xf1a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f1f:
	/* 0xf1f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f24:
	/* 0xf24: movzx  ecx,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_f2b:
	/* 0xf2b: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_f31:
	/* 0xf31: mov    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_f38:
	/* 0xf38: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_f3d:
	/* 0xf3d: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f40:
	/* 0xf40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f45:
	/* 0xf45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f47:
	/* 0xf47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f49:
	/* 0xf49: je     a86 <generic_sleepable_preload+0xa86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2694ULL;
	}
x86_l_f4f:
	/* 0xf4f: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_f52:
	/* 0xf52: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f57:
	/* 0xf57: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f5a:
	/* 0xf5a: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_f5d:
	/* 0xf5d: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_f65:
	/* 0xf65: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_f6b:
	/* 0xf6b: mov    eax,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_f71:
	/* 0xf71: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f74:
	/* 0xf74: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f79:
	/* 0xf79: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_f81:
	/* 0xf81: je     fa6 <generic_sleepable_preload+0xfa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fa6;
	}
x86_l_f83:
	/* 0xf83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f88:
	/* 0xf88: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f8d:
	/* 0xf8d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f92:
	/* 0xf92: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f97:
	/* 0xf97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f9c:
	/* 0xf9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9e:
	/* 0xf9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fa0:
	/* 0xfa0: js     1d7c <generic_sleepable_preload+0x1d7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7548ULL;
	}
x86_l_fa6:
	/* 0xfa6: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_fae:
	/* 0xfae: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_fb4:
	/* 0xfb4: mov    ecx,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_fba:
	/* 0xfba: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fbf:
	/* 0xfbf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fc4:
	/* 0xfc4: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_fcc:
	/* 0xfcc: je     ff1 <generic_sleepable_preload+0xff1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ff1;
	}
x86_l_fce:
	/* 0xfce: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd3:
	/* 0xfd3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fd8:
	/* 0xfd8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_fdd:
	/* 0xfdd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe2:
	/* 0xfe2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fe7:
	/* 0xfe7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe9:
	/* 0xfe9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_feb:
	/* 0xfeb: js     2621 <generic_sleepable_preload+0x2621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9761ULL;
	}
x86_l_ff1:
	/* 0xff1: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_ff9:
	/* 0xff9: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_fff:
	/* 0xfff: mov    ecx,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1005:
	/* 0x1005: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_100a:
	/* 0x100a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_100f:
	/* 0x100f: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_1017:
	/* 0x1017: je     103c <generic_sleepable_preload+0x103c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103c;
	}
x86_l_1019:
	/* 0x1019: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_101e:
	/* 0x101e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1023:
	/* 0x1023: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1028:
	/* 0x1028: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102d:
	/* 0x102d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1032:
	/* 0x1032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1034:
	/* 0x1034: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1036:
	/* 0x1036: js     2f78 <generic_sleepable_preload+0x2f78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12152ULL;
	}
x86_l_103c:
	/* 0x103c: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_1044:
	/* 0x1044: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_104a:
	/* 0x104a: mov    ecx,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1050:
	/* 0x1050: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1055:
	/* 0x1055: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_105a:
	/* 0x105a: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_1062:
	/* 0x1062: je     1087 <generic_sleepable_preload+0x1087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1087;
	}
x86_l_1064:
	/* 0x1064: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1069:
	/* 0x1069: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_106e:
	/* 0x106e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1073:
	/* 0x1073: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1078:
	/* 0x1078: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_107d:
	/* 0x107d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107f:
	/* 0x107f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1081:
	/* 0x1081: js     2fe4 <generic_sleepable_preload+0x2fe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12260ULL;
	}
x86_l_1087:
	/* 0x1087: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_108f:
	/* 0x108f: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_1095:
	/* 0x1095: mov    ecx,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_109b:
	/* 0x109b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10a0:
	/* 0x10a0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10a5:
	/* 0x10a5: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_10ad:
	/* 0x10ad: je     10d2 <generic_sleepable_preload+0x10d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d2;
	}
x86_l_10af:
	/* 0x10af: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10b4:
	/* 0x10b4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_10b9:
	/* 0x10b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10be:
	/* 0x10be: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10c3:
	/* 0x10c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10c8:
	/* 0x10c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ca:
	/* 0x10ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10cc:
	/* 0x10cc: js     3050 <generic_sleepable_preload+0x3050> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12368ULL;
	}
x86_l_10d2:
	/* 0x10d2: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_10da:
	/* 0x10da: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_10e0:
	/* 0x10e0: mov    ecx,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_10e6:
	/* 0x10e6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10eb:
	/* 0x10eb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f0:
	/* 0x10f0: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_10f8:
	/* 0x10f8: je     111d <generic_sleepable_preload+0x111d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_111d;
	}
x86_l_10fa:
	/* 0x10fa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ff:
	/* 0x10ff: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1104:
	/* 0x1104: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1109:
	/* 0x1109: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_110e:
	/* 0x110e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1113:
	/* 0x1113: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1115:
	/* 0x1115: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1117:
	/* 0x1117: js     30b9 <generic_sleepable_preload+0x30b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12473ULL;
	}
x86_l_111d:
	/* 0x111d: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_1125:
	/* 0x1125: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_112b:
	/* 0x112b: mov    ecx,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1131:
	/* 0x1131: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1136:
	/* 0x1136: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_113b:
	/* 0x113b: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_1143:
	/* 0x1143: je     1168 <generic_sleepable_preload+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1168;
	}
x86_l_1145:
	/* 0x1145: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114a:
	/* 0x114a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_114f:
	/* 0x114f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1154:
	/* 0x1154: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x1162: js     31b0 <generic_sleepable_preload+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12720ULL;
	}
x86_l_1168:
	/* 0x1168: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_1170:
	/* 0x1170: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_1176:
	/* 0x1176: mov    ecx,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_117c:
	/* 0x117c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1181:
	/* 0x1181: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1186:
	/* 0x1186: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_118e:
	/* 0x118e: je     11b3 <generic_sleepable_preload+0x11b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b3;
	}
x86_l_1190:
	/* 0x1190: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1195:
	/* 0x1195: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_119a:
	/* 0x119a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_119f:
	/* 0x119f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a4:
	/* 0x11a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11a9:
	/* 0x11a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ab:
	/* 0x11ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11ad:
	/* 0x11ad: js     37a8 <generic_sleepable_preload+0x37a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14248ULL;
	}
x86_l_11b3:
	/* 0x11b3: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_11bb:
	/* 0x11bb: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_11c1:
	/* 0x11c1: mov    ecx,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_11c7:
	/* 0x11c7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_11cc:
	/* 0x11cc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d1:
	/* 0x11d1: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_11d9:
	/* 0x11d9: je     11fe <generic_sleepable_preload+0x11fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11fe;
	}
x86_l_11db:
	/* 0x11db: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11e0:
	/* 0x11e0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11e5:
	/* 0x11e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11ea:
	/* 0x11ea: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ef:
	/* 0x11ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11f4:
	/* 0x11f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f6:
	/* 0x11f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11f8:
	/* 0x11f8: js     385a <generic_sleepable_preload+0x385a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14426ULL;
	}
x86_l_11fe:
	/* 0x11fe: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_1206:
	/* 0x1206: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_120c:
	/* 0x120c: mov    ecx,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1212:
	/* 0x1212: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1217:
	/* 0x1217: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_121c:
	/* 0x121c: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_1224:
	/* 0x1224: je     31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12728ULL;
	}
x86_l_122a:
	/* 0x122a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122f:
	/* 0x122f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1234:
	/* 0x1234: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1239:
	/* 0x1239: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_123e:
	/* 0x123e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1243:
	/* 0x1243: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1245:
	/* 0x1245: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1247:
	/* 0x1247: jns    31b8 <generic_sleepable_preload+0x31b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12728ULL;
	}
x86_l_124d:
	/* 0x124d: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1253:
	/* 0x1253: jmp    31b6 <generic_sleepable_preload+0x31b6> */
	return 12726ULL;
x86_l_1258:
	/* 0x1258: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_125e:
	/* 0x125e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1264:
	/* 0x1264: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1267:
	/* 0x1267: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_126c:
	/* 0x126c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1271:
	/* 0x1271: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
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
	/* 0x127f: jne    1302 <generic_sleepable_preload+0x1302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1302;
	}
x86_l_1285:
	/* 0x1285: mov    edx,DWORD PTR [rbx+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_128b:
	/* 0x128b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1291:
	/* 0x1291: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1294:
	/* 0x1294: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1297:
	/* 0x1297: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_129c:
	/* 0x129c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12a1:
	/* 0x12a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a6:
	/* 0x12a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a8:
	/* 0x12a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12aa:
	/* 0x12aa: jne    1302 <generic_sleepable_preload+0x1302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1302;
	}
x86_l_12ac:
	/* 0x12ac: movzx  eax,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_12b3:
	/* 0x12b3: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_12b9:
	/* 0x12b9: mov    rcx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_12c0:
	/* 0x12c0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_12c5:
	/* 0x12c5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12c8:
	/* 0x12c8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12cd:
	/* 0x12cd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12d2:
	/* 0x12d2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12d7:
	/* 0x12d7: movzx  ecx,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_12de:
	/* 0x12de: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_12e4:
	/* 0x12e4: mov    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_12eb:
	/* 0x12eb: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_12f0:
	/* 0x12f0: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12f3:
	/* 0x12f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12f8:
	/* 0x12f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fa:
	/* 0x12fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12fc:
	/* 0x12fc: je     abf <generic_sleepable_preload+0xabf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2751ULL;
	}
x86_l_1302:
	/* 0x1302: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1305:
	/* 0x1305: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130a:
	/* 0x130a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_130d:
	/* 0x130d: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1310:
	/* 0x1310: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_1318:
	/* 0x1318: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_131e:
	/* 0x131e: mov    eax,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1324:
	/* 0x1324: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1327:
	/* 0x1327: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_132c:
	/* 0x132c: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_1334:
	/* 0x1334: je     1359 <generic_sleepable_preload+0x1359> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1359;
	}
x86_l_1336:
	/* 0x1336: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_133b:
	/* 0x133b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1340:
	/* 0x1340: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1345:
	/* 0x1345: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_134a:
	/* 0x134a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_134f:
	/* 0x134f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1351:
	/* 0x1351: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1353:
	/* 0x1353: js     1d87 <generic_sleepable_preload+0x1d87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7559ULL;
	}
x86_l_1359:
	/* 0x1359: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_1361:
	/* 0x1361: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_1367:
	/* 0x1367: mov    ecx,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_136d:
	/* 0x136d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1372:
	/* 0x1372: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1377:
	/* 0x1377: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_137f:
	/* 0x137f: je     13a4 <generic_sleepable_preload+0x13a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a4;
	}
x86_l_1381:
	/* 0x1381: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1386:
	/* 0x1386: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_138b:
	/* 0x138b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1390:
	/* 0x1390: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1395:
	/* 0x1395: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_139a:
	/* 0x139a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139c:
	/* 0x139c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_139e:
	/* 0x139e: js     262c <generic_sleepable_preload+0x262c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9772ULL;
	}
x86_l_13a4:
	/* 0x13a4: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_13ac:
	/* 0x13ac: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_13b2:
	/* 0x13b2: mov    ecx,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_13b8:
	/* 0x13b8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_13bd:
	/* 0x13bd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13c2:
	/* 0x13c2: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_13ca:
	/* 0x13ca: je     13ef <generic_sleepable_preload+0x13ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ef;
	}
x86_l_13cc:
	/* 0x13cc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d1:
	/* 0x13d1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_13d6:
	/* 0x13d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13db:
	/* 0x13db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e0:
	/* 0x13e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13e5:
	/* 0x13e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e7:
	/* 0x13e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13e9:
	/* 0x13e9: js     2f83 <generic_sleepable_preload+0x2f83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12163ULL;
	}
x86_l_13ef:
	/* 0x13ef: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_13f7:
	/* 0x13f7: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_13fd:
	/* 0x13fd: mov    ecx,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1403:
	/* 0x1403: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1408:
	/* 0x1408: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_140d:
	/* 0x140d: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_1415:
	/* 0x1415: je     143a <generic_sleepable_preload+0x143a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_143a;
	}
x86_l_1417:
	/* 0x1417: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_141c:
	/* 0x141c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1421:
	/* 0x1421: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1426:
	/* 0x1426: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_142b:
	/* 0x142b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1430:
	/* 0x1430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1432:
	/* 0x1432: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1434:
	/* 0x1434: js     2fef <generic_sleepable_preload+0x2fef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12271ULL;
	}
x86_l_143a:
	/* 0x143a: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_1442:
	/* 0x1442: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_1448:
	/* 0x1448: mov    ecx,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_144e:
	/* 0x144e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1453:
	/* 0x1453: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1458:
	/* 0x1458: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_1460:
	/* 0x1460: je     1485 <generic_sleepable_preload+0x1485> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1485;
	}
x86_l_1462:
	/* 0x1462: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1467:
	/* 0x1467: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_146c:
	/* 0x146c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1471:
	/* 0x1471: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1476:
	/* 0x1476: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_147b:
	/* 0x147b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147d:
	/* 0x147d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_147f:
	/* 0x147f: js     305b <generic_sleepable_preload+0x305b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12379ULL;
	}
x86_l_1485:
	/* 0x1485: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_148d:
	/* 0x148d: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_1493:
	/* 0x1493: mov    ecx,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_1499:
	/* 0x1499: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_149e:
	/* 0x149e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a3:
	/* 0x14a3: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_14ab:
	/* 0x14ab: je     14d0 <generic_sleepable_preload+0x14d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14d0;
	}
x86_l_14ad:
	/* 0x14ad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b2:
	/* 0x14b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14b7:
	/* 0x14b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14bc:
	/* 0x14bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c1:
	/* 0x14c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c6:
	/* 0x14c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c8:
	/* 0x14c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14ca:
	/* 0x14ca: js     30c4 <generic_sleepable_preload+0x30c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12484ULL;
	}
x86_l_14d0:
	/* 0x14d0: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_14d8:
	/* 0x14d8: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_14de:
	/* 0x14de: mov    ecx,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_14e4:
	/* 0x14e4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_14e9:
	/* 0x14e9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ee:
	/* 0x14ee: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_14f6:
	/* 0x14f6: je     151b <generic_sleepable_preload+0x151b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_151b;
	}
x86_l_14f8:
	/* 0x14f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14fd:
	/* 0x14fd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1502:
	/* 0x1502: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1507:
	/* 0x1507: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_150c:
	/* 0x150c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1511:
	/* 0x1511: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1513:
	/* 0x1513: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1515:
	/* 0x1515: js     3243 <generic_sleepable_preload+0x3243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12867ULL;
	}
x86_l_151b:
	/* 0x151b: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_1523:
	/* 0x1523: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_1529:
	/* 0x1529: mov    ecx,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_152f:
	/* 0x152f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1534:
	/* 0x1534: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1539:
	/* 0x1539: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_1541:
	/* 0x1541: je     1566 <generic_sleepable_preload+0x1566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1566;
	}
x86_l_1543:
	/* 0x1543: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1548:
	/* 0x1548: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_154d:
	/* 0x154d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1552:
	/* 0x1552: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1557:
	/* 0x1557: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_155c:
	/* 0x155c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155e:
	/* 0x155e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1560:
	/* 0x1560: js     37b5 <generic_sleepable_preload+0x37b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14261ULL;
	}
x86_l_1566:
	/* 0x1566: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_156e:
	/* 0x156e: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_1574:
	/* 0x1574: mov    ecx,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_157a:
	/* 0x157a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_157f:
	/* 0x157f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1584:
	/* 0x1584: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_158c:
	/* 0x158c: je     15b1 <generic_sleepable_preload+0x15b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5553ULL;
	}
x86_l_158e:
	/* 0x158e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1593:
	/* 0x1593: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1598:
	/* 0x1598: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_159d:
	/* 0x159d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a2:
	/* 0x15a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 5543ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5543ULL: goto x86_l_15a7;
	case 5545ULL: goto x86_l_15a9;
	case 5547ULL: goto x86_l_15ab;
	case 5553ULL: goto x86_l_15b1;
	case 5561ULL: goto x86_l_15b9;
	case 5567ULL: goto x86_l_15bf;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5583ULL: goto x86_l_15cf;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5602ULL: goto x86_l_15e2;
	case 5607ULL: goto x86_l_15e7;
	case 5612ULL: goto x86_l_15ec;
	case 5617ULL: goto x86_l_15f1;
	case 5622ULL: goto x86_l_15f6;
	case 5624ULL: goto x86_l_15f8;
	case 5626ULL: goto x86_l_15fa;
	case 5632ULL: goto x86_l_1600;
	case 5638ULL: goto x86_l_1606;
	case 5643ULL: goto x86_l_160b;
	case 5649ULL: goto x86_l_1611;
	case 5655ULL: goto x86_l_1617;
	case 5658ULL: goto x86_l_161a;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5680ULL: goto x86_l_1630;
	case 5682ULL: goto x86_l_1632;
	case 5688ULL: goto x86_l_1638;
	case 5694ULL: goto x86_l_163e;
	case 5700ULL: goto x86_l_1644;
	case 5703ULL: goto x86_l_1647;
	case 5706ULL: goto x86_l_164a;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5723ULL: goto x86_l_165b;
	case 5725ULL: goto x86_l_165d;
	case 5727ULL: goto x86_l_165f;
	case 5734ULL: goto x86_l_1666;
	case 5740ULL: goto x86_l_166c;
	case 5747ULL: goto x86_l_1673;
	case 5752ULL: goto x86_l_1678;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5777ULL: goto x86_l_1691;
	case 5783ULL: goto x86_l_1697;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5798ULL: goto x86_l_16a6;
	case 5803ULL: goto x86_l_16ab;
	case 5805ULL: goto x86_l_16ad;
	case 5807ULL: goto x86_l_16af;
	case 5813ULL: goto x86_l_16b5;
	case 5816ULL: goto x86_l_16b8;
	case 5821ULL: goto x86_l_16bd;
	case 5824ULL: goto x86_l_16c0;
	case 5827ULL: goto x86_l_16c3;
	case 5835ULL: goto x86_l_16cb;
	case 5841ULL: goto x86_l_16d1;
	case 5847ULL: goto x86_l_16d7;
	case 5850ULL: goto x86_l_16da;
	case 5855ULL: goto x86_l_16df;
	case 5863ULL: goto x86_l_16e7;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5892ULL: goto x86_l_1704;
	case 5894ULL: goto x86_l_1706;
	case 5900ULL: goto x86_l_170c;
	case 5908ULL: goto x86_l_1714;
	case 5914ULL: goto x86_l_171a;
	case 5920ULL: goto x86_l_1720;
	case 5925ULL: goto x86_l_1725;
	case 5930ULL: goto x86_l_172a;
	case 5938ULL: goto x86_l_1732;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5965ULL: goto x86_l_174d;
	case 5967ULL: goto x86_l_174f;
	case 5969ULL: goto x86_l_1751;
	case 5975ULL: goto x86_l_1757;
	case 5983ULL: goto x86_l_175f;
	case 5989ULL: goto x86_l_1765;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6005ULL: goto x86_l_1775;
	case 6013ULL: goto x86_l_177d;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6042ULL: goto x86_l_179a;
	case 6044ULL: goto x86_l_179c;
	case 6050ULL: goto x86_l_17a2;
	case 6058ULL: goto x86_l_17aa;
	case 6064ULL: goto x86_l_17b0;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6080ULL: goto x86_l_17c0;
	case 6088ULL: goto x86_l_17c8;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6125ULL: goto x86_l_17ed;
	case 6133ULL: goto x86_l_17f5;
	case 6139ULL: goto x86_l_17fb;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6163ULL: goto x86_l_1813;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6190ULL: goto x86_l_182e;
	case 6192ULL: goto x86_l_1830;
	case 6194ULL: goto x86_l_1832;
	case 6200ULL: goto x86_l_1838;
	case 6208ULL: goto x86_l_1840;
	case 6214ULL: goto x86_l_1846;
	case 6220ULL: goto x86_l_184c;
	case 6225ULL: goto x86_l_1851;
	case 6230ULL: goto x86_l_1856;
	case 6238ULL: goto x86_l_185e;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6250ULL: goto x86_l_186a;
	case 6255ULL: goto x86_l_186f;
	case 6260ULL: goto x86_l_1874;
	case 6265ULL: goto x86_l_1879;
	case 6267ULL: goto x86_l_187b;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6283ULL: goto x86_l_188b;
	case 6289ULL: goto x86_l_1891;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6305ULL: goto x86_l_18a1;
	case 6313ULL: goto x86_l_18a9;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6330ULL: goto x86_l_18ba;
	case 6335ULL: goto x86_l_18bf;
	case 6340ULL: goto x86_l_18c4;
	case 6342ULL: goto x86_l_18c6;
	case 6344ULL: goto x86_l_18c8;
	case 6350ULL: goto x86_l_18ce;
	case 6358ULL: goto x86_l_18d6;
	case 6364ULL: goto x86_l_18dc;
	case 6370ULL: goto x86_l_18e2;
	case 6375ULL: goto x86_l_18e7;
	case 6380ULL: goto x86_l_18ec;
	case 6388ULL: goto x86_l_18f4;
	case 6390ULL: goto x86_l_18f6;
	case 6395ULL: goto x86_l_18fb;
	case 6400ULL: goto x86_l_1900;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6419ULL: goto x86_l_1913;
	case 6425ULL: goto x86_l_1919;
	case 6433ULL: goto x86_l_1921;
	case 6439ULL: goto x86_l_1927;
	case 6445ULL: goto x86_l_192d;
	case 6450ULL: goto x86_l_1932;
	case 6455ULL: goto x86_l_1937;
	case 6463ULL: goto x86_l_193f;
	case 6465ULL: goto x86_l_1941;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6480ULL: goto x86_l_1950;
	case 6485ULL: goto x86_l_1955;
	case 6490ULL: goto x86_l_195a;
	case 6492ULL: goto x86_l_195c;
	case 6494ULL: goto x86_l_195e;
	case 6500ULL: goto x86_l_1964;
	case 6508ULL: goto x86_l_196c;
	case 6514ULL: goto x86_l_1972;
	case 6520ULL: goto x86_l_1978;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6538ULL: goto x86_l_198a;
	case 6544ULL: goto x86_l_1990;
	case 6549ULL: goto x86_l_1995;
	case 6554ULL: goto x86_l_199a;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6571ULL: goto x86_l_19ab;
	case 6573ULL: goto x86_l_19ad;
	case 6579ULL: goto x86_l_19b3;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6596ULL: goto x86_l_19c4;
	case 6602ULL: goto x86_l_19ca;
	case 6605ULL: goto x86_l_19cd;
	case 6610ULL: goto x86_l_19d2;
	case 6615ULL: goto x86_l_19d7;
	case 6620ULL: goto x86_l_19dc;
	case 6625ULL: goto x86_l_19e1;
	case 6627ULL: goto x86_l_19e3;
	case 6629ULL: goto x86_l_19e5;
	case 6635ULL: goto x86_l_19eb;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6670ULL: goto x86_l_1a0e;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6676ULL: goto x86_l_1a14;
	case 6683ULL: goto x86_l_1a1b;
	case 6689ULL: goto x86_l_1a21;
	case 6696ULL: goto x86_l_1a28;
	case 6701ULL: goto x86_l_1a2d;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6726ULL: goto x86_l_1a46;
	case 6732ULL: goto x86_l_1a4c;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6754ULL: goto x86_l_1a62;
	case 6756ULL: goto x86_l_1a64;
	case 6762ULL: goto x86_l_1a6a;
	case 6765ULL: goto x86_l_1a6d;
	case 6770ULL: goto x86_l_1a72;
	case 6772ULL: goto x86_l_1a74;
	case 6775ULL: goto x86_l_1a77;
	case 6783ULL: goto x86_l_1a7f;
	case 6789ULL: goto x86_l_1a85;
	case 6795ULL: goto x86_l_1a8b;
	case 6798ULL: goto x86_l_1a8e;
	case 6803ULL: goto x86_l_1a93;
	case 6811ULL: goto x86_l_1a9b;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6840ULL: goto x86_l_1ab8;
	case 6842ULL: goto x86_l_1aba;
	case 6848ULL: goto x86_l_1ac0;
	case 6856ULL: goto x86_l_1ac8;
	case 6862ULL: goto x86_l_1ace;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6878ULL: goto x86_l_1ade;
	case 6886ULL: goto x86_l_1ae6;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6915ULL: goto x86_l_1b03;
	case 6917ULL: goto x86_l_1b05;
	case 6923ULL: goto x86_l_1b0b;
	case 6931ULL: goto x86_l_1b13;
	case 6937ULL: goto x86_l_1b19;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6961ULL: goto x86_l_1b31;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6988ULL: goto x86_l_1b4c;
	case 6990ULL: goto x86_l_1b4e;
	case 6992ULL: goto x86_l_1b50;
	case 6998ULL: goto x86_l_1b56;
	case 7006ULL: goto x86_l_1b5e;
	case 7012ULL: goto x86_l_1b64;
	case 7018ULL: goto x86_l_1b6a;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7036ULL: goto x86_l_1b7c;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7065ULL: goto x86_l_1b99;
	case 7067ULL: goto x86_l_1b9b;
	case 7073ULL: goto x86_l_1ba1;
	case 7081ULL: goto x86_l_1ba9;
	case 7087ULL: goto x86_l_1baf;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	case 7103ULL: goto x86_l_1bbf;
	case 7111ULL: goto x86_l_1bc7;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7140ULL: goto x86_l_1be4;
	case 7142ULL: goto x86_l_1be6;
	case 7148ULL: goto x86_l_1bec;
	case 7156ULL: goto x86_l_1bf4;
	case 7162ULL: goto x86_l_1bfa;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7178ULL: goto x86_l_1c0a;
	case 7186ULL: goto x86_l_1c12;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7215ULL: goto x86_l_1c2f;
	case 7217ULL: goto x86_l_1c31;
	case 7223ULL: goto x86_l_1c37;
	case 7231ULL: goto x86_l_1c3f;
	case 7237ULL: goto x86_l_1c45;
	case 7243ULL: goto x86_l_1c4b;
	case 7248ULL: goto x86_l_1c50;
	case 7253ULL: goto x86_l_1c55;
	case 7261ULL: goto x86_l_1c5d;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7273ULL: goto x86_l_1c69;
	case 7278ULL: goto x86_l_1c6e;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7290ULL: goto x86_l_1c7a;
	case 7292ULL: goto x86_l_1c7c;
	case 7298ULL: goto x86_l_1c82;
	case 7306ULL: goto x86_l_1c8a;
	case 7312ULL: goto x86_l_1c90;
	case 7318ULL: goto x86_l_1c96;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7336ULL: goto x86_l_1ca8;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7365ULL: goto x86_l_1cc5;
	case 7367ULL: goto x86_l_1cc7;
	case 7373ULL: goto x86_l_1ccd;
	case 7381ULL: goto x86_l_1cd5;
	case 7387ULL: goto x86_l_1cdb;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7403ULL: goto x86_l_1ceb;
	case 7411ULL: goto x86_l_1cf3;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15a7:
	/* 0x15a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a9:
	/* 0x15a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15ab:
	/* 0x15ab: js     3865 <generic_sleepable_preload+0x3865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14437ULL;
	}
x86_l_15b1:
	/* 0x15b1: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_15b9:
	/* 0x15b9: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_15bf:
	/* 0x15bf: mov    ecx,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_15c5:
	/* 0x15c5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_15ca:
	/* 0x15ca: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15cf:
	/* 0x15cf: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_15d7:
	/* 0x15d7: je     324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12875ULL;
	}
x86_l_15dd:
	/* 0x15dd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e2:
	/* 0x15e2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15e7:
	/* 0x15e7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15ec:
	/* 0x15ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15f1:
	/* 0x15f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15f6:
	/* 0x15f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f8:
	/* 0x15f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15fa:
	/* 0x15fa: jns    324b <generic_sleepable_preload+0x324b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12875ULL;
	}
x86_l_1600:
	/* 0x1600: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1606:
	/* 0x1606: jmp    3249 <generic_sleepable_preload+0x3249> */
	return 12873ULL;
x86_l_160b:
	/* 0x160b: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_1611:
	/* 0x1611: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1617:
	/* 0x1617: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_161a:
	/* 0x161a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161f:
	/* 0x161f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1624:
	/* 0x1624: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1629:
	/* 0x1629: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_162e:
	/* 0x162e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1630:
	/* 0x1630: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1632:
	/* 0x1632: jne    16b5 <generic_sleepable_preload+0x16b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16b5;
	}
x86_l_1638:
	/* 0x1638: mov    edx,DWORD PTR [rbx+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_163e:
	/* 0x163e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1644:
	/* 0x1644: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1647:
	/* 0x1647: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_164a:
	/* 0x164a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_164f:
	/* 0x164f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1654:
	/* 0x1654: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1659:
	/* 0x1659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165b:
	/* 0x165b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_165d:
	/* 0x165d: jne    16b5 <generic_sleepable_preload+0x16b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16b5;
	}
x86_l_165f:
	/* 0x165f: movzx  eax,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_1666:
	/* 0x1666: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_166c:
	/* 0x166c: mov    rcx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_1673:
	/* 0x1673: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1678:
	/* 0x1678: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_167b:
	/* 0x167b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1680:
	/* 0x1680: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1685:
	/* 0x1685: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_168a:
	/* 0x168a: movzx  ecx,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_1691:
	/* 0x1691: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_1697:
	/* 0x1697: mov    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_169e:
	/* 0x169e: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_16a3:
	/* 0x16a3: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16a6:
	/* 0x16a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16ab:
	/* 0x16ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ad:
	/* 0x16ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16af:
	/* 0x16af: je     af3 <generic_sleepable_preload+0xaf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2803ULL;
	}
x86_l_16b5:
	/* 0x16b5: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_16b8:
	/* 0x16b8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16bd:
	/* 0x16bd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c0:
	/* 0x16c0: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_16c3:
	/* 0x16c3: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_16cb:
	/* 0x16cb: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_16d1:
	/* 0x16d1: mov    eax,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_16d7:
	/* 0x16d7: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16da:
	/* 0x16da: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16df:
	/* 0x16df: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_16e7:
	/* 0x16e7: je     170c <generic_sleepable_preload+0x170c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_170c;
	}
x86_l_16e9:
	/* 0x16e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16ee:
	/* 0x16ee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16f3:
	/* 0x16f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16f8:
	/* 0x16f8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16fd:
	/* 0x16fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1702:
	/* 0x1702: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1704:
	/* 0x1704: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1706:
	/* 0x1706: js     1d92 <generic_sleepable_preload+0x1d92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7570ULL;
	}
x86_l_170c:
	/* 0x170c: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_1714:
	/* 0x1714: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_171a:
	/* 0x171a: mov    ecx,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_1720:
	/* 0x1720: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1725:
	/* 0x1725: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_172a:
	/* 0x172a: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_1732:
	/* 0x1732: je     1757 <generic_sleepable_preload+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1757;
	}
x86_l_1734:
	/* 0x1734: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1739:
	/* 0x1739: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_173e:
	/* 0x173e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1743:
	/* 0x1743: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1748:
	/* 0x1748: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_174d:
	/* 0x174d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174f:
	/* 0x174f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1751:
	/* 0x1751: js     2637 <generic_sleepable_preload+0x2637> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9783ULL;
	}
x86_l_1757:
	/* 0x1757: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_175f:
	/* 0x175f: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_1765:
	/* 0x1765: mov    ecx,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_176b:
	/* 0x176b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1770:
	/* 0x1770: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1775:
	/* 0x1775: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_177d:
	/* 0x177d: je     17a2 <generic_sleepable_preload+0x17a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17a2;
	}
x86_l_177f:
	/* 0x177f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1784:
	/* 0x1784: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1789:
	/* 0x1789: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_178e:
	/* 0x178e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1793:
	/* 0x1793: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1798:
	/* 0x1798: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179a:
	/* 0x179a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_179c:
	/* 0x179c: js     2f8e <generic_sleepable_preload+0x2f8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12174ULL;
	}
x86_l_17a2:
	/* 0x17a2: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_17aa:
	/* 0x17aa: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_17b0:
	/* 0x17b0: mov    ecx,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_17b6:
	/* 0x17b6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17bb:
	/* 0x17bb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c0:
	/* 0x17c0: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_17c8:
	/* 0x17c8: je     17ed <generic_sleepable_preload+0x17ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ed;
	}
x86_l_17ca:
	/* 0x17ca: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17cf:
	/* 0x17cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17d4:
	/* 0x17d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17d9:
	/* 0x17d9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17de:
	/* 0x17de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17e3:
	/* 0x17e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e5:
	/* 0x17e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17e7:
	/* 0x17e7: js     2ffa <generic_sleepable_preload+0x2ffa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12282ULL;
	}
x86_l_17ed:
	/* 0x17ed: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_17f5:
	/* 0x17f5: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_17fb:
	/* 0x17fb: mov    ecx,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_1801:
	/* 0x1801: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1806:
	/* 0x1806: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_180b:
	/* 0x180b: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_1813:
	/* 0x1813: je     1838 <generic_sleepable_preload+0x1838> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1838;
	}
x86_l_1815:
	/* 0x1815: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_181a:
	/* 0x181a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_181f:
	/* 0x181f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1824:
	/* 0x1824: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1829:
	/* 0x1829: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_182e:
	/* 0x182e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1830:
	/* 0x1830: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1832:
	/* 0x1832: js     3066 <generic_sleepable_preload+0x3066> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12390ULL;
	}
x86_l_1838:
	/* 0x1838: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_1840:
	/* 0x1840: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_1846:
	/* 0x1846: mov    ecx,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_184c:
	/* 0x184c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1851:
	/* 0x1851: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1856:
	/* 0x1856: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_185e:
	/* 0x185e: je     1883 <generic_sleepable_preload+0x1883> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1883;
	}
x86_l_1860:
	/* 0x1860: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1865:
	/* 0x1865: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_186a:
	/* 0x186a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_186f:
	/* 0x186f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1874:
	/* 0x1874: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1879:
	/* 0x1879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187b:
	/* 0x187b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_187d:
	/* 0x187d: js     30cf <generic_sleepable_preload+0x30cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12495ULL;
	}
x86_l_1883:
	/* 0x1883: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_188b:
	/* 0x188b: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_1891:
	/* 0x1891: mov    ecx,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_1897:
	/* 0x1897: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_189c:
	/* 0x189c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18a1:
	/* 0x18a1: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_18a9:
	/* 0x18a9: je     18ce <generic_sleepable_preload+0x18ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ce;
	}
x86_l_18ab:
	/* 0x18ab: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18b0:
	/* 0x18b0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18b5:
	/* 0x18b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18ba:
	/* 0x18ba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18bf:
	/* 0x18bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c4:
	/* 0x18c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c6:
	/* 0x18c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18c8:
	/* 0x18c8: js     32d6 <generic_sleepable_preload+0x32d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13014ULL;
	}
x86_l_18ce:
	/* 0x18ce: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_18d6:
	/* 0x18d6: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_18dc:
	/* 0x18dc: mov    ecx,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_18e2:
	/* 0x18e2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_18e7:
	/* 0x18e7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18ec:
	/* 0x18ec: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_18f4:
	/* 0x18f4: je     1919 <generic_sleepable_preload+0x1919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1919;
	}
x86_l_18f6:
	/* 0x18f6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18fb:
	/* 0x18fb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1900:
	/* 0x1900: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1905:
	/* 0x1905: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190a:
	/* 0x190a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190f:
	/* 0x190f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1911:
	/* 0x1911: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1913:
	/* 0x1913: js     37c2 <generic_sleepable_preload+0x37c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14274ULL;
	}
x86_l_1919:
	/* 0x1919: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_1921:
	/* 0x1921: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_1927:
	/* 0x1927: mov    ecx,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_192d:
	/* 0x192d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1932:
	/* 0x1932: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1937:
	/* 0x1937: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_193f:
	/* 0x193f: je     1964 <generic_sleepable_preload+0x1964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1964;
	}
x86_l_1941:
	/* 0x1941: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1946:
	/* 0x1946: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_194b:
	/* 0x194b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1950:
	/* 0x1950: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1955:
	/* 0x1955: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_195a:
	/* 0x195a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195c:
	/* 0x195c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195e:
	/* 0x195e: js     3870 <generic_sleepable_preload+0x3870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14448ULL;
	}
x86_l_1964:
	/* 0x1964: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_196c:
	/* 0x196c: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_1972:
	/* 0x1972: mov    ecx,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_1978:
	/* 0x1978: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_197d:
	/* 0x197d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1982:
	/* 0x1982: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_198a:
	/* 0x198a: je     32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13022ULL;
	}
x86_l_1990:
	/* 0x1990: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1995:
	/* 0x1995: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_199a:
	/* 0x199a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_199f:
	/* 0x199f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a4:
	/* 0x19a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19a9:
	/* 0x19a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ab:
	/* 0x19ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19ad:
	/* 0x19ad: jns    32de <generic_sleepable_preload+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13022ULL;
	}
x86_l_19b3:
	/* 0x19b3: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_19b9:
	/* 0x19b9: jmp    32dc <generic_sleepable_preload+0x32dc> */
	return 13020ULL;
x86_l_19be:
	/* 0x19be: mov    edx,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_19c4:
	/* 0x19c4: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19ca:
	/* 0x19ca: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19cd:
	/* 0x19cd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19d2:
	/* 0x19d2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19d7:
	/* 0x19d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19dc:
	/* 0x19dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19e1:
	/* 0x19e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e3:
	/* 0x19e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19e5:
	/* 0x19e5: jne    1a6a <generic_sleepable_preload+0x1a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a6a;
	}
x86_l_19eb:
	/* 0x19eb: mov    eax,DWORD PTR [rbx+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_19f1:
	/* 0x19f1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19f6:
	/* 0x19f6: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19f9:
	/* 0x19f9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19fc:
	/* 0x19fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a01:
	/* 0x1a01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a06:
	/* 0x1a06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a0b:
	/* 0x1a0b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1a0e:
	/* 0x1a0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a10:
	/* 0x1a10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a12:
	/* 0x1a12: jne    1a6a <generic_sleepable_preload+0x1a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a6a;
	}
x86_l_1a14:
	/* 0x1a14: movzx  eax,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_1a1b:
	/* 0x1a1b: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_1a21:
	/* 0x1a21: mov    rcx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_1a28:
	/* 0x1a28: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1a2d:
	/* 0x1a2d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a30:
	/* 0x1a30: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a35:
	/* 0x1a35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a3f:
	/* 0x1a3f: movzx  ecx,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_1a46:
	/* 0x1a46: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_1a4c:
	/* 0x1a4c: mov    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_1a53:
	/* 0x1a53: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1a58:
	/* 0x1a58: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a5b:
	/* 0x1a5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a60:
	/* 0x1a60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a62:
	/* 0x1a62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a64:
	/* 0x1a64: je     b27 <generic_sleepable_preload+0xb27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2855ULL;
	}
x86_l_1a6a:
	/* 0x1a6a: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1a6d:
	/* 0x1a6d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a72:
	/* 0x1a72: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a74:
	/* 0x1a74: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1a77:
	/* 0x1a77: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_1a7f:
	/* 0x1a7f: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1a85:
	/* 0x1a85: mov    eax,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_1a8b:
	/* 0x1a8b: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a8e:
	/* 0x1a8e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a93:
	/* 0x1a93: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_1a9b:
	/* 0x1a9b: je     1ac0 <generic_sleepable_preload+0x1ac0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac0;
	}
x86_l_1a9d:
	/* 0x1a9d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1aac:
	/* 0x1aac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab1:
	/* 0x1ab1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ab6:
	/* 0x1ab6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab8:
	/* 0x1ab8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aba:
	/* 0x1aba: js     1d9d <generic_sleepable_preload+0x1d9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7581ULL;
	}
x86_l_1ac0:
	/* 0x1ac0: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_1ac8:
	/* 0x1ac8: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1ace:
	/* 0x1ace: mov    ecx,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_1ad4:
	/* 0x1ad4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ad9:
	/* 0x1ad9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ade:
	/* 0x1ade: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_1ae6:
	/* 0x1ae6: je     1b0b <generic_sleepable_preload+0x1b0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b0b;
	}
x86_l_1ae8:
	/* 0x1ae8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aed:
	/* 0x1aed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1af2:
	/* 0x1af2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1af7:
	/* 0x1af7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1afc:
	/* 0x1afc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b01:
	/* 0x1b01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b03:
	/* 0x1b03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b05:
	/* 0x1b05: js     2642 <generic_sleepable_preload+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9794ULL;
	}
x86_l_1b0b:
	/* 0x1b0b: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_1b13:
	/* 0x1b13: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1b19:
	/* 0x1b19: mov    ecx,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_1b1f:
	/* 0x1b1f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b24:
	/* 0x1b24: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b29:
	/* 0x1b29: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_1b31:
	/* 0x1b31: je     1b56 <generic_sleepable_preload+0x1b56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b56;
	}
x86_l_1b33:
	/* 0x1b33: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b38:
	/* 0x1b38: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b42:
	/* 0x1b42: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b47:
	/* 0x1b47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b4c:
	/* 0x1b4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4e:
	/* 0x1b4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b50:
	/* 0x1b50: js     2f99 <generic_sleepable_preload+0x2f99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12185ULL;
	}
x86_l_1b56:
	/* 0x1b56: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_1b5e:
	/* 0x1b5e: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1b64:
	/* 0x1b64: mov    ecx,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_1b6a:
	/* 0x1b6a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b6f:
	/* 0x1b6f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b74:
	/* 0x1b74: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_1b7c:
	/* 0x1b7c: je     1ba1 <generic_sleepable_preload+0x1ba1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ba1;
	}
x86_l_1b7e:
	/* 0x1b7e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b83:
	/* 0x1b83: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b88:
	/* 0x1b88: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b92:
	/* 0x1b92: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b97:
	/* 0x1b97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b99:
	/* 0x1b99: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b9b:
	/* 0x1b9b: js     3005 <generic_sleepable_preload+0x3005> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12293ULL;
	}
x86_l_1ba1:
	/* 0x1ba1: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_1ba9:
	/* 0x1ba9: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1baf:
	/* 0x1baf: mov    ecx,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_1bb5:
	/* 0x1bb5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1bba:
	/* 0x1bba: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bbf:
	/* 0x1bbf: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_1bc7:
	/* 0x1bc7: je     1bec <generic_sleepable_preload+0x1bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bec;
	}
x86_l_1bc9:
	/* 0x1bc9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bce:
	/* 0x1bce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bdd:
	/* 0x1bdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1be2:
	/* 0x1be2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be4:
	/* 0x1be4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1be6:
	/* 0x1be6: js     3071 <generic_sleepable_preload+0x3071> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12401ULL;
	}
x86_l_1bec:
	/* 0x1bec: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_1bf4:
	/* 0x1bf4: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1bfa:
	/* 0x1bfa: mov    ecx,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_1c00:
	/* 0x1c00: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c05:
	/* 0x1c05: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c0a:
	/* 0x1c0a: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_1c12:
	/* 0x1c12: je     1c37 <generic_sleepable_preload+0x1c37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c37;
	}
x86_l_1c14:
	/* 0x1c14: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c19:
	/* 0x1c19: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c23:
	/* 0x1c23: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c28:
	/* 0x1c28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c2d:
	/* 0x1c2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2f:
	/* 0x1c2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c31:
	/* 0x1c31: js     30da <generic_sleepable_preload+0x30da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12506ULL;
	}
x86_l_1c37:
	/* 0x1c37: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_1c3f:
	/* 0x1c3f: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1c45:
	/* 0x1c45: mov    ecx,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_1c4b:
	/* 0x1c4b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c50:
	/* 0x1c50: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c55:
	/* 0x1c55: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_1c5d:
	/* 0x1c5d: je     1c82 <generic_sleepable_preload+0x1c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c82;
	}
x86_l_1c5f:
	/* 0x1c5f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c64:
	/* 0x1c64: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c69:
	/* 0x1c69: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c6e:
	/* 0x1c6e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c73:
	/* 0x1c73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c78:
	/* 0x1c78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7a:
	/* 0x1c7a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c7c:
	/* 0x1c7c: js     3369 <generic_sleepable_preload+0x3369> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13161ULL;
	}
x86_l_1c82:
	/* 0x1c82: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_1c8a:
	/* 0x1c8a: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1c90:
	/* 0x1c90: mov    ecx,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_1c96:
	/* 0x1c96: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c9b:
	/* 0x1c9b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca0:
	/* 0x1ca0: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_1ca8:
	/* 0x1ca8: je     1ccd <generic_sleepable_preload+0x1ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ccd;
	}
x86_l_1caa:
	/* 0x1caa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1caf:
	/* 0x1caf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cc3:
	/* 0x1cc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc5:
	/* 0x1cc5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cc7:
	/* 0x1cc7: js     37cf <generic_sleepable_preload+0x37cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14287ULL;
	}
x86_l_1ccd:
	/* 0x1ccd: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_1cd5:
	/* 0x1cd5: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1cdb:
	/* 0x1cdb: mov    ecx,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1ce1:
	/* 0x1ce1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ceb:
	/* 0x1ceb: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_1cf3:
	/* 0x1cf3: je     1d18 <generic_sleepable_preload+0x1d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7448ULL;
	}
x86_l_1cf5:
	/* 0x1cf5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 7423ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7440ULL: goto x86_l_1d10;
	case 7442ULL: goto x86_l_1d12;
	case 7448ULL: goto x86_l_1d18;
	case 7456ULL: goto x86_l_1d20;
	case 7462ULL: goto x86_l_1d26;
	case 7468ULL: goto x86_l_1d2c;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7486ULL: goto x86_l_1d3e;
	case 7492ULL: goto x86_l_1d44;
	case 7497ULL: goto x86_l_1d49;
	case 7502ULL: goto x86_l_1d4e;
	case 7507ULL: goto x86_l_1d53;
	case 7512ULL: goto x86_l_1d58;
	case 7517ULL: goto x86_l_1d5d;
	case 7519ULL: goto x86_l_1d5f;
	case 7521ULL: goto x86_l_1d61;
	case 7527ULL: goto x86_l_1d67;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7554ULL: goto x86_l_1d82;
	case 7559ULL: goto x86_l_1d87;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7576ULL: goto x86_l_1d98;
	case 7581ULL: goto x86_l_1d9d;
	case 7586ULL: goto x86_l_1da2;
	case 7591ULL: goto x86_l_1da7;
	case 7599ULL: goto x86_l_1daf;
	case 7602ULL: goto x86_l_1db2;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7635ULL: goto x86_l_1dd3;
	case 7638ULL: goto x86_l_1dd6;
	case 7644ULL: goto x86_l_1ddc;
	case 7649ULL: goto x86_l_1de1;
	case 7652ULL: goto x86_l_1de4;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7688ULL: goto x86_l_1e08;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7707ULL: goto x86_l_1e1b;
	case 7710ULL: goto x86_l_1e1e;
	case 7716ULL: goto x86_l_1e24;
	case 7721ULL: goto x86_l_1e29;
	case 7724ULL: goto x86_l_1e2c;
	case 7730ULL: goto x86_l_1e32;
	case 7735ULL: goto x86_l_1e37;
	case 7743ULL: goto x86_l_1e3f;
	case 7746ULL: goto x86_l_1e42;
	case 7752ULL: goto x86_l_1e48;
	case 7757ULL: goto x86_l_1e4d;
	case 7760ULL: goto x86_l_1e50;
	case 7766ULL: goto x86_l_1e56;
	case 7771ULL: goto x86_l_1e5b;
	case 7776ULL: goto x86_l_1e60;
	case 7779ULL: goto x86_l_1e63;
	case 7785ULL: goto x86_l_1e69;
	case 7790ULL: goto x86_l_1e6e;
	case 7793ULL: goto x86_l_1e71;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7812ULL: goto x86_l_1e84;
	case 7818ULL: goto x86_l_1e8a;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7842ULL: goto x86_l_1ea2;
	case 7845ULL: goto x86_l_1ea5;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7859ULL: goto x86_l_1eb3;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7878ULL: goto x86_l_1ec6;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7892ULL: goto x86_l_1ed4;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7908ULL: goto x86_l_1ee4;
	case 7911ULL: goto x86_l_1ee7;
	case 7917ULL: goto x86_l_1eed;
	case 7922ULL: goto x86_l_1ef2;
	case 7925ULL: goto x86_l_1ef5;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7944ULL: goto x86_l_1f08;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7958ULL: goto x86_l_1f16;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7974ULL: goto x86_l_1f26;
	case 7977ULL: goto x86_l_1f29;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7991ULL: goto x86_l_1f37;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8010ULL: goto x86_l_1f4a;
	case 8016ULL: goto x86_l_1f50;
	case 8021ULL: goto x86_l_1f55;
	case 8024ULL: goto x86_l_1f58;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8040ULL: goto x86_l_1f68;
	case 8043ULL: goto x86_l_1f6b;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8057ULL: goto x86_l_1f79;
	case 8063ULL: goto x86_l_1f7f;
	case 8068ULL: goto x86_l_1f84;
	case 8073ULL: goto x86_l_1f89;
	case 8076ULL: goto x86_l_1f8c;
	case 8082ULL: goto x86_l_1f92;
	case 8087ULL: goto x86_l_1f97;
	case 8090ULL: goto x86_l_1f9a;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8109ULL: goto x86_l_1fad;
	case 8112ULL: goto x86_l_1fb0;
	case 8114ULL: goto x86_l_1fb2;
	case 8119ULL: goto x86_l_1fb7;
	case 8122ULL: goto x86_l_1fba;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8129ULL: goto x86_l_1fc1;
	case 8131ULL: goto x86_l_1fc3;
	case 8136ULL: goto x86_l_1fc8;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8147ULL: goto x86_l_1fd3;
	case 8151ULL: goto x86_l_1fd7;
	case 8154ULL: goto x86_l_1fda;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8168ULL: goto x86_l_1fe8;
	case 8171ULL: goto x86_l_1feb;
	case 8174ULL: goto x86_l_1fee;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8185ULL: goto x86_l_1ff9;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8202ULL: goto x86_l_200a;
	case 8207ULL: goto x86_l_200f;
	case 8209ULL: goto x86_l_2011;
	case 8211ULL: goto x86_l_2013;
	case 8217ULL: goto x86_l_2019;
	case 8222ULL: goto x86_l_201e;
	case 8228ULL: goto x86_l_2024;
	case 8231ULL: goto x86_l_2027;
	case 8235ULL: goto x86_l_202b;
	case 8239ULL: goto x86_l_202f;
	case 8244ULL: goto x86_l_2034;
	case 8246ULL: goto x86_l_2036;
	case 8249ULL: goto x86_l_2039;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8263ULL: goto x86_l_2047;
	case 8268ULL: goto x86_l_204c;
	case 8270ULL: goto x86_l_204e;
	case 8272ULL: goto x86_l_2050;
	case 8278ULL: goto x86_l_2056;
	case 8286ULL: goto x86_l_205e;
	case 8292ULL: goto x86_l_2064;
	case 8298ULL: goto x86_l_206a;
	case 8302ULL: goto x86_l_206e;
	case 8306ULL: goto x86_l_2072;
	case 8314ULL: goto x86_l_207a;
	case 8316ULL: goto x86_l_207c;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8329ULL: goto x86_l_2089;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8340ULL: goto x86_l_2094;
	case 8342ULL: goto x86_l_2096;
	case 8348ULL: goto x86_l_209c;
	case 8356ULL: goto x86_l_20a4;
	case 8362ULL: goto x86_l_20aa;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8376ULL: goto x86_l_20b8;
	case 8384ULL: goto x86_l_20c0;
	case 8386ULL: goto x86_l_20c2;
	case 8389ULL: goto x86_l_20c5;
	case 8394ULL: goto x86_l_20ca;
	case 8399ULL: goto x86_l_20cf;
	case 8403ULL: goto x86_l_20d3;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8418ULL: goto x86_l_20e2;
	case 8426ULL: goto x86_l_20ea;
	case 8432ULL: goto x86_l_20f0;
	case 8438ULL: goto x86_l_20f6;
	case 8442ULL: goto x86_l_20fa;
	case 8446ULL: goto x86_l_20fe;
	case 8454ULL: goto x86_l_2106;
	case 8456ULL: goto x86_l_2108;
	case 8459ULL: goto x86_l_210b;
	case 8464ULL: goto x86_l_2110;
	case 8469ULL: goto x86_l_2115;
	case 8473ULL: goto x86_l_2119;
	case 8478ULL: goto x86_l_211e;
	case 8480ULL: goto x86_l_2120;
	case 8482ULL: goto x86_l_2122;
	case 8488ULL: goto x86_l_2128;
	case 8496ULL: goto x86_l_2130;
	case 8502ULL: goto x86_l_2136;
	case 8508ULL: goto x86_l_213c;
	case 8512ULL: goto x86_l_2140;
	case 8516ULL: goto x86_l_2144;
	case 8524ULL: goto x86_l_214c;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8550ULL: goto x86_l_2166;
	case 8552ULL: goto x86_l_2168;
	case 8558ULL: goto x86_l_216e;
	case 8566ULL: goto x86_l_2176;
	case 8572ULL: goto x86_l_217c;
	case 8578ULL: goto x86_l_2182;
	case 8582ULL: goto x86_l_2186;
	case 8586ULL: goto x86_l_218a;
	case 8594ULL: goto x86_l_2192;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8613ULL: goto x86_l_21a5;
	case 8618ULL: goto x86_l_21aa;
	case 8620ULL: goto x86_l_21ac;
	case 8622ULL: goto x86_l_21ae;
	case 8628ULL: goto x86_l_21b4;
	case 8636ULL: goto x86_l_21bc;
	case 8642ULL: goto x86_l_21c2;
	case 8648ULL: goto x86_l_21c8;
	case 8652ULL: goto x86_l_21cc;
	case 8656ULL: goto x86_l_21d0;
	case 8664ULL: goto x86_l_21d8;
	case 8666ULL: goto x86_l_21da;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	case 8679ULL: goto x86_l_21e7;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8692ULL: goto x86_l_21f4;
	case 8698ULL: goto x86_l_21fa;
	case 8706ULL: goto x86_l_2202;
	case 8712ULL: goto x86_l_2208;
	case 8718ULL: goto x86_l_220e;
	case 8722ULL: goto x86_l_2212;
	case 8726ULL: goto x86_l_2216;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8760ULL: goto x86_l_2238;
	case 8762ULL: goto x86_l_223a;
	case 8768ULL: goto x86_l_2240;
	case 8776ULL: goto x86_l_2248;
	case 8782ULL: goto x86_l_224e;
	case 8788ULL: goto x86_l_2254;
	case 8792ULL: goto x86_l_2258;
	case 8796ULL: goto x86_l_225c;
	case 8804ULL: goto x86_l_2264;
	case 8810ULL: goto x86_l_226a;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8823ULL: goto x86_l_2277;
	case 8827ULL: goto x86_l_227b;
	case 8832ULL: goto x86_l_2280;
	case 8834ULL: goto x86_l_2282;
	case 8836ULL: goto x86_l_2284;
	case 8842ULL: goto x86_l_228a;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8872ULL: goto x86_l_22a8;
	case 8875ULL: goto x86_l_22ab;
	case 8881ULL: goto x86_l_22b1;
	case 8886ULL: goto x86_l_22b6;
	case 8889ULL: goto x86_l_22b9;
	case 8895ULL: goto x86_l_22bf;
	case 8900ULL: goto x86_l_22c4;
	case 8908ULL: goto x86_l_22cc;
	case 8911ULL: goto x86_l_22cf;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8925ULL: goto x86_l_22dd;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8944ULL: goto x86_l_22f0;
	case 8947ULL: goto x86_l_22f3;
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8961ULL: goto x86_l_2301;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8980ULL: goto x86_l_2314;
	case 8983ULL: goto x86_l_2317;
	case 8985ULL: goto x86_l_2319;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8995ULL: goto x86_l_2323;
	case 8998ULL: goto x86_l_2326;
	case 9000ULL: goto x86_l_2328;
	case 9002ULL: goto x86_l_232a;
	case 9007ULL: goto x86_l_232f;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9018ULL: goto x86_l_233a;
	case 9022ULL: goto x86_l_233e;
	case 9024ULL: goto x86_l_2340;
	case 9027ULL: goto x86_l_2343;
	case 9035ULL: goto x86_l_234b;
	case 9041ULL: goto x86_l_2351;
	case 9047ULL: goto x86_l_2357;
	case 9050ULL: goto x86_l_235a;
	case 9054ULL: goto x86_l_235e;
	case 9062ULL: goto x86_l_2366;
	case 9064ULL: goto x86_l_2368;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9088ULL: goto x86_l_2380;
	case 9090ULL: goto x86_l_2382;
	case 9096ULL: goto x86_l_2388;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9116ULL: goto x86_l_239c;
	case 9120ULL: goto x86_l_23a0;
	case 9124ULL: goto x86_l_23a4;
	case 9132ULL: goto x86_l_23ac;
	case 9134ULL: goto x86_l_23ae;
	case 9137ULL: goto x86_l_23b1;
	case 9142ULL: goto x86_l_23b6;
	case 9147ULL: goto x86_l_23bb;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9158ULL: goto x86_l_23c6;
	case 9160ULL: goto x86_l_23c8;
	case 9166ULL: goto x86_l_23ce;
	case 9174ULL: goto x86_l_23d6;
	case 9180ULL: goto x86_l_23dc;
	case 9186ULL: goto x86_l_23e2;
	case 9190ULL: goto x86_l_23e6;
	case 9194ULL: goto x86_l_23ea;
	case 9202ULL: goto x86_l_23f2;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1cff:
	/* 0x1cff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d04:
	/* 0x1d04: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d09:
	/* 0x1d09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d0e:
	/* 0x1d0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d10:
	/* 0x1d10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d12:
	/* 0x1d12: js     387b <generic_sleepable_preload+0x387b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14459ULL;
	}
x86_l_1d18:
	/* 0x1d18: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_1d20:
	/* 0x1d20: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1d26:
	/* 0x1d26: mov    ecx,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_1d2c:
	/* 0x1d2c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d31:
	/* 0x1d31: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d36:
	/* 0x1d36: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_1d3e:
	/* 0x1d3e: je     3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13169ULL;
	}
x86_l_1d44:
	/* 0x1d44: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d49:
	/* 0x1d49: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d4e:
	/* 0x1d4e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d53:
	/* 0x1d53: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d58:
	/* 0x1d58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d5d:
	/* 0x1d5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d5f:
	/* 0x1d5f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d61:
	/* 0x1d61: jns    3371 <generic_sleepable_preload+0x3371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13169ULL;
	}
x86_l_1d67:
	/* 0x1d67: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1d6c:
	/* 0x1d6c: jmp    336e <generic_sleepable_preload+0x336e> */
	return 13166ULL;
x86_l_1d71:
	/* 0x1d71: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1d77:
	/* 0x1d77: jmp    3120 <generic_sleepable_preload+0x3120> */
	return 12576ULL;
x86_l_1d7c:
	/* 0x1d7c: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1d82:
	/* 0x1d82: jmp    31b6 <generic_sleepable_preload+0x31b6> */
	return 12726ULL;
x86_l_1d87:
	/* 0x1d87: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1d8d:
	/* 0x1d8d: jmp    3249 <generic_sleepable_preload+0x3249> */
	return 12873ULL;
x86_l_1d92:
	/* 0x1d92: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1d98:
	/* 0x1d98: jmp    32dc <generic_sleepable_preload+0x32dc> */
	return 13020ULL;
x86_l_1d9d:
	/* 0x1d9d: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1da2:
	/* 0x1da2: jmp    336e <generic_sleepable_preload+0x336e> */
	return 13166ULL;
x86_l_1da7:
	/* 0x1da7: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1daf:
	/* 0x1daf: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1db2:
	/* 0x1db2: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbc;
	}
x86_l_1db8:
	/* 0x1db8: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1dbd:
	/* 0x1dbd: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1dc0:
	/* 0x1dc0: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbc;
	}
x86_l_1dc6:
	/* 0x1dc6: jmp    1fcf <generic_sleepable_preload+0x1fcf> */
	goto x86_l_1fcf;
x86_l_1dcb:
	/* 0x1dcb: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1dd3:
	/* 0x1dd3: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1dd6:
	/* 0x1dd6: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_1ddc:
	/* 0x1ddc: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1de1:
	/* 0x1de1: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1de4:
	/* 0x1de4: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_1dea:
	/* 0x1dea: jmp    2677 <generic_sleepable_preload+0x2677> */
	return 9847ULL;
x86_l_1def:
	/* 0x1def: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1df7:
	/* 0x1df7: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1dfa:
	/* 0x1dfa: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_1e00:
	/* 0x1e00: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e05:
	/* 0x1e05: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e08:
	/* 0x1e08: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_1e0e:
	/* 0x1e0e: jmp    297b <generic_sleepable_preload+0x297b> */
	return 10619ULL;
x86_l_1e13:
	/* 0x1e13: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e1b:
	/* 0x1e1b: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1e1e:
	/* 0x1e1e: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_1e24:
	/* 0x1e24: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e29:
	/* 0x1e29: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e2c:
	/* 0x1e2c: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_1e32:
	/* 0x1e32: jmp    2c7f <generic_sleepable_preload+0x2c7f> */
	return 11391ULL;
x86_l_1e37:
	/* 0x1e37: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e3f:
	/* 0x1e3f: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1e42:
	/* 0x1e42: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2323;
	}
x86_l_1e48:
	/* 0x1e48: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e4d:
	/* 0x1e4d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e50:
	/* 0x1e50: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2323;
	}
x86_l_1e56:
	/* 0x1e56: jmp    2336 <generic_sleepable_preload+0x2336> */
	goto x86_l_2336;
x86_l_1e5b:
	/* 0x1e5b: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e60:
	/* 0x1e60: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1e63:
	/* 0x1e63: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbc;
	}
x86_l_1e69:
	/* 0x1e69: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e6e:
	/* 0x1e6e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1e71:
	/* 0x1e71: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbc;
	}
x86_l_1e77:
	/* 0x1e77: jmp    1fcf <generic_sleepable_preload+0x1fcf> */
	goto x86_l_1fcf;
x86_l_1e7c:
	/* 0x1e7c: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e81:
	/* 0x1e81: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1e84:
	/* 0x1e84: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_1e8a:
	/* 0x1e8a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e8f:
	/* 0x1e8f: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1e92:
	/* 0x1e92: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_1e98:
	/* 0x1e98: jmp    2677 <generic_sleepable_preload+0x2677> */
	return 9847ULL;
x86_l_1e9d:
	/* 0x1e9d: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ea2:
	/* 0x1ea2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1ea5:
	/* 0x1ea5: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_1eab:
	/* 0x1eab: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eb0:
	/* 0x1eb0: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1eb3:
	/* 0x1eb3: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_1eb9:
	/* 0x1eb9: jmp    297b <generic_sleepable_preload+0x297b> */
	return 10619ULL;
x86_l_1ebe:
	/* 0x1ebe: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ec3:
	/* 0x1ec3: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1ec6:
	/* 0x1ec6: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_1ecc:
	/* 0x1ecc: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ed1:
	/* 0x1ed1: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ed4:
	/* 0x1ed4: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_1eda:
	/* 0x1eda: jmp    2c7f <generic_sleepable_preload+0x2c7f> */
	return 11391ULL;
x86_l_1edf:
	/* 0x1edf: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ee4:
	/* 0x1ee4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1ee7:
	/* 0x1ee7: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2323;
	}
x86_l_1eed:
	/* 0x1eed: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ef2:
	/* 0x1ef2: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ef5:
	/* 0x1ef5: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2323;
	}
x86_l_1efb:
	/* 0x1efb: jmp    2336 <generic_sleepable_preload+0x2336> */
	goto x86_l_2336;
x86_l_1f00:
	/* 0x1f00: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f05:
	/* 0x1f05: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f08:
	/* 0x1f08: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbc;
	}
x86_l_1f0e:
	/* 0x1f0e: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f13:
	/* 0x1f13: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f16:
	/* 0x1f16: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbc;
	}
x86_l_1f1c:
	/* 0x1f1c: jmp    1fcf <generic_sleepable_preload+0x1fcf> */
	goto x86_l_1fcf;
x86_l_1f21:
	/* 0x1f21: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f26:
	/* 0x1f26: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f29:
	/* 0x1f29: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_1f2f:
	/* 0x1f2f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f34:
	/* 0x1f34: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f37:
	/* 0x1f37: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_1f3d:
	/* 0x1f3d: jmp    2677 <generic_sleepable_preload+0x2677> */
	return 9847ULL;
x86_l_1f42:
	/* 0x1f42: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f47:
	/* 0x1f47: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f4a:
	/* 0x1f4a: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_1f50:
	/* 0x1f50: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f55:
	/* 0x1f55: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f58:
	/* 0x1f58: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_1f5e:
	/* 0x1f5e: jmp    297b <generic_sleepable_preload+0x297b> */
	return 10619ULL;
x86_l_1f63:
	/* 0x1f63: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f68:
	/* 0x1f68: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f6b:
	/* 0x1f6b: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_1f71:
	/* 0x1f71: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f76:
	/* 0x1f76: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f79:
	/* 0x1f79: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_1f7f:
	/* 0x1f7f: jmp    2c7f <generic_sleepable_preload+0x2c7f> */
	return 11391ULL;
x86_l_1f84:
	/* 0x1f84: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f89:
	/* 0x1f89: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f8c:
	/* 0x1f8c: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2323;
	}
x86_l_1f92:
	/* 0x1f92: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f97:
	/* 0x1f97: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f9a:
	/* 0x1f9a: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2323;
	}
x86_l_1fa0:
	/* 0x1fa0: jmp    2336 <generic_sleepable_preload+0x2336> */
	goto x86_l_2336;
x86_l_1fa5:
	/* 0x1fa5: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1fad:
	/* 0x1fad: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1fb0:
	/* 0x1fb0: je     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbc;
	}
x86_l_1fb2:
	/* 0x1fb2: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1fb7:
	/* 0x1fb7: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1fba:
	/* 0x1fba: jne    1fcf <generic_sleepable_preload+0x1fcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fcf;
	}
x86_l_1fbc:
	/* 0x1fbc: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1fc1:
	/* 0x1fc1: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1fc3:
	/* 0x1fc3: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1fc8:
	/* 0x1fc8: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fca:
	/* 0x1fca: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1fcf:
	/* 0x1fcf: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fd3:
	/* 0x1fd3: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fd7:
	/* 0x1fd7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fda:
	/* 0x1fda: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1fdd:
	/* 0x1fdd: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1fe2:
	/* 0x1fe2: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_1fe8:
	/* 0x1fe8: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1feb:
	/* 0x1feb: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fee:
	/* 0x1fee: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff2:
	/* 0x1ff2: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_1ff7:
	/* 0x1ff7: je     2019 <generic_sleepable_preload+0x2019> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2019;
	}
x86_l_1ff9:
	/* 0x1ff9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ffc:
	/* 0x1ffc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2001:
	/* 0x2001: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2006:
	/* 0x2006: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_200a:
	/* 0x200a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_200f:
	/* 0x200f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2011:
	/* 0x2011: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2013:
	/* 0x2013: js     2295 <generic_sleepable_preload+0x2295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2295;
	}
x86_l_2019:
	/* 0x2019: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_201e:
	/* 0x201e: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_2024:
	/* 0x2024: mov    ecx,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2027:
	/* 0x2027: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_202b:
	/* 0x202b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202f:
	/* 0x202f: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_2034:
	/* 0x2034: je     2056 <generic_sleepable_preload+0x2056> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2056;
	}
x86_l_2036:
	/* 0x2036: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2039:
	/* 0x2039: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_203e:
	/* 0x203e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2043:
	/* 0x2043: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2047:
	/* 0x2047: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_204c:
	/* 0x204c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204e:
	/* 0x204e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2050:
	/* 0x2050: js     264c <generic_sleepable_preload+0x264c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9804ULL;
	}
x86_l_2056:
	/* 0x2056: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_205e:
	/* 0x205e: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_2064:
	/* 0x2064: mov    ecx,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_206a:
	/* 0x206a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_206e:
	/* 0x206e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2072:
	/* 0x2072: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_207a:
	/* 0x207a: je     209c <generic_sleepable_preload+0x209c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209c;
	}
x86_l_207c:
	/* 0x207c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_207f:
	/* 0x207f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2084:
	/* 0x2084: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2089:
	/* 0x2089: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_208d:
	/* 0x208d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2092:
	/* 0x2092: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2094:
	/* 0x2094: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2096:
	/* 0x2096: js     2fa3 <generic_sleepable_preload+0x2fa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12195ULL;
	}
x86_l_209c:
	/* 0x209c: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_20a4:
	/* 0x20a4: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_20aa:
	/* 0x20aa: mov    ecx,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20b0:
	/* 0x20b0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20b4:
	/* 0x20b4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b8:
	/* 0x20b8: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_20c0:
	/* 0x20c0: je     20e2 <generic_sleepable_preload+0x20e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e2;
	}
x86_l_20c2:
	/* 0x20c2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20c5:
	/* 0x20c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20ca:
	/* 0x20ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20cf:
	/* 0x20cf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d3:
	/* 0x20d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20d8:
	/* 0x20d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20da:
	/* 0x20da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20dc:
	/* 0x20dc: js     300f <generic_sleepable_preload+0x300f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12303ULL;
	}
x86_l_20e2:
	/* 0x20e2: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_20ea:
	/* 0x20ea: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_20f0:
	/* 0x20f0: mov    ecx,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_20f6:
	/* 0x20f6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20fa:
	/* 0x20fa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20fe:
	/* 0x20fe: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_2106:
	/* 0x2106: je     2128 <generic_sleepable_preload+0x2128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2128;
	}
x86_l_2108:
	/* 0x2108: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_210b:
	/* 0x210b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2110:
	/* 0x2110: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2115:
	/* 0x2115: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2119:
	/* 0x2119: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_211e:
	/* 0x211e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2120:
	/* 0x2120: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2122:
	/* 0x2122: js     307b <generic_sleepable_preload+0x307b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12411ULL;
	}
x86_l_2128:
	/* 0x2128: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_2130:
	/* 0x2130: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_2136:
	/* 0x2136: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_213c:
	/* 0x213c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2140:
	/* 0x2140: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2144:
	/* 0x2144: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_214c:
	/* 0x214c: je     216e <generic_sleepable_preload+0x216e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216e;
	}
x86_l_214e:
	/* 0x214e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2151:
	/* 0x2151: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2156:
	/* 0x2156: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_215b:
	/* 0x215b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215f:
	/* 0x215f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2164:
	/* 0x2164: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2166:
	/* 0x2166: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2168:
	/* 0x2168: js     30e4 <generic_sleepable_preload+0x30e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12516ULL;
	}
x86_l_216e:
	/* 0x216e: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_2176:
	/* 0x2176: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_217c:
	/* 0x217c: mov    ecx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2182:
	/* 0x2182: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2186:
	/* 0x2186: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_218a:
	/* 0x218a: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_2192:
	/* 0x2192: je     21b4 <generic_sleepable_preload+0x21b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21b4;
	}
x86_l_2194:
	/* 0x2194: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2197:
	/* 0x2197: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_219c:
	/* 0x219c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21a1:
	/* 0x21a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a5:
	/* 0x21a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21aa:
	/* 0x21aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ac:
	/* 0x21ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21ae:
	/* 0x21ae: js     33f2 <generic_sleepable_preload+0x33f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13298ULL;
	}
x86_l_21b4:
	/* 0x21b4: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_21bc:
	/* 0x21bc: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_21c2:
	/* 0x21c2: mov    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_21c8:
	/* 0x21c8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21cc:
	/* 0x21cc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21d0:
	/* 0x21d0: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_21d8:
	/* 0x21d8: je     21fa <generic_sleepable_preload+0x21fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21fa;
	}
x86_l_21da:
	/* 0x21da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21dd:
	/* 0x21dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21e2:
	/* 0x21e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21e7:
	/* 0x21e7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21eb:
	/* 0x21eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f0:
	/* 0x21f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f2:
	/* 0x21f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21f4:
	/* 0x21f4: js     37dc <generic_sleepable_preload+0x37dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14300ULL;
	}
x86_l_21fa:
	/* 0x21fa: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_2202:
	/* 0x2202: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_2208:
	/* 0x2208: mov    ecx,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_220e:
	/* 0x220e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2212:
	/* 0x2212: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2216:
	/* 0x2216: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_221e:
	/* 0x221e: je     2240 <generic_sleepable_preload+0x2240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2240;
	}
x86_l_2220:
	/* 0x2220: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2223:
	/* 0x2223: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2228:
	/* 0x2228: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_222d:
	/* 0x222d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2231:
	/* 0x2231: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2236:
	/* 0x2236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2238:
	/* 0x2238: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_223a:
	/* 0x223a: js     3885 <generic_sleepable_preload+0x3885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14469ULL;
	}
x86_l_2240:
	/* 0x2240: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_2248:
	/* 0x2248: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
	}
x86_l_224e:
	/* 0x224e: mov    ecx,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2254:
	/* 0x2254: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2258:
	/* 0x2258: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225c:
	/* 0x225c: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_2264:
	/* 0x2264: je     33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13306ULL;
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
	/* 0x2277: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227b:
	/* 0x227b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2280:
	/* 0x2280: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2282:
	/* 0x2282: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2284:
	/* 0x2284: jns    33fa <generic_sleepable_preload+0x33fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13306ULL;
	}
x86_l_228a:
	/* 0x228a: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_2290:
	/* 0x2290: jmp    33f8 <generic_sleepable_preload+0x33f8> */
	return 13304ULL;
x86_l_2295:
	/* 0x2295: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_229b:
	/* 0x229b: jmp    33f8 <generic_sleepable_preload+0x33f8> */
	return 13304ULL;
x86_l_22a0:
	/* 0x22a0: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22a8:
	/* 0x22a8: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_22ab:
	/* 0x22ab: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_22b1:
	/* 0x22b1: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22b6:
	/* 0x22b6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_22b9:
	/* 0x22b9: je     2664 <generic_sleepable_preload+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_22bf:
	/* 0x22bf: jmp    2677 <generic_sleepable_preload+0x2677> */
	return 9847ULL;
x86_l_22c4:
	/* 0x22c4: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22cc:
	/* 0x22cc: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_22cf:
	/* 0x22cf: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_22d5:
	/* 0x22d5: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22da:
	/* 0x22da: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_22dd:
	/* 0x22dd: je     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10600ULL;
	}
x86_l_22e3:
	/* 0x22e3: jmp    297b <generic_sleepable_preload+0x297b> */
	return 10619ULL;
x86_l_22e8:
	/* 0x22e8: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22f0:
	/* 0x22f0: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_22f3:
	/* 0x22f3: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_22f9:
	/* 0x22f9: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22fe:
	/* 0x22fe: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2301:
	/* 0x2301: je     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11372ULL;
	}
x86_l_2307:
	/* 0x2307: jmp    2c7f <generic_sleepable_preload+0x2c7f> */
	return 11391ULL;
x86_l_230c:
	/* 0x230c: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2314:
	/* 0x2314: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2317:
	/* 0x2317: je     2323 <generic_sleepable_preload+0x2323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2323;
	}
x86_l_2319:
	/* 0x2319: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_231e:
	/* 0x231e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2321:
	/* 0x2321: jne    2336 <generic_sleepable_preload+0x2336> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2336;
	}
x86_l_2323:
	/* 0x2323: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2326:
	/* 0x2326: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_2328:
	/* 0x2328: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_232a:
	/* 0x232a: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_232f:
	/* 0x232f: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2331:
	/* 0x2331: bzhi   rcx,QWORD PTR [r14],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2336:
	/* 0x2336: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_233a:
	/* 0x233a: mov    r14d,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_233e:
	/* 0x233e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2340:
	/* 0x2340: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_2343:
	/* 0x2343: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_234b:
	/* 0x234b: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_2351:
	/* 0x2351: mov    eax,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_2357:
	/* 0x2357: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_235a:
	/* 0x235a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_235e:
	/* 0x235e: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_2366:
	/* 0x2366: je     2388 <generic_sleepable_preload+0x2388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2388;
	}
x86_l_2368:
	/* 0x2368: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_236b:
	/* 0x236b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2370:
	/* 0x2370: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2375:
	/* 0x2375: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2379:
	/* 0x2379: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_237e:
	/* 0x237e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2380:
	/* 0x2380: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2382:
	/* 0x2382: js     260c <generic_sleepable_preload+0x260c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9740ULL;
	}
x86_l_2388:
	/* 0x2388: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_2390:
	/* 0x2390: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_2396:
	/* 0x2396: mov    ecx,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_239c:
	/* 0x239c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23a0:
	/* 0x23a0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a4:
	/* 0x23a4: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_23ac:
	/* 0x23ac: je     23ce <generic_sleepable_preload+0x23ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ce;
	}
x86_l_23ae:
	/* 0x23ae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23b1:
	/* 0x23b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23b6:
	/* 0x23b6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23bb:
	/* 0x23bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23bf:
	/* 0x23bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23c4:
	/* 0x23c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c6:
	/* 0x23c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c8:
	/* 0x23c8: js     2657 <generic_sleepable_preload+0x2657> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9815ULL;
	}
x86_l_23ce:
	/* 0x23ce: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_23d6:
	/* 0x23d6: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_23dc:
	/* 0x23dc: mov    ecx,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_23e2:
	/* 0x23e2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23e6:
	/* 0x23e6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ea:
	/* 0x23ea: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_23f2:
	/* 0x23f2: je     2414 <generic_sleepable_preload+0x2414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9236ULL;
	}
x86_l_23f4:
	/* 0x23f4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23f7:
	/* 0x23f7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 9212ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9236ULL: goto x86_l_2414;
	case 9244ULL: goto x86_l_241c;
	case 9250ULL: goto x86_l_2422;
	case 9256ULL: goto x86_l_2428;
	case 9260ULL: goto x86_l_242c;
	case 9264ULL: goto x86_l_2430;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9277ULL: goto x86_l_243d;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9291ULL: goto x86_l_244b;
	case 9296ULL: goto x86_l_2450;
	case 9298ULL: goto x86_l_2452;
	case 9300ULL: goto x86_l_2454;
	case 9306ULL: goto x86_l_245a;
	case 9314ULL: goto x86_l_2462;
	case 9320ULL: goto x86_l_2468;
	case 9326ULL: goto x86_l_246e;
	case 9330ULL: goto x86_l_2472;
	case 9334ULL: goto x86_l_2476;
	case 9342ULL: goto x86_l_247e;
	case 9344ULL: goto x86_l_2480;
	case 9347ULL: goto x86_l_2483;
	case 9352ULL: goto x86_l_2488;
	case 9357ULL: goto x86_l_248d;
	case 9361ULL: goto x86_l_2491;
	case 9366ULL: goto x86_l_2496;
	case 9368ULL: goto x86_l_2498;
	case 9370ULL: goto x86_l_249a;
	case 9376ULL: goto x86_l_24a0;
	case 9384ULL: goto x86_l_24a8;
	case 9390ULL: goto x86_l_24ae;
	case 9396ULL: goto x86_l_24b4;
	case 9400ULL: goto x86_l_24b8;
	case 9404ULL: goto x86_l_24bc;
	case 9412ULL: goto x86_l_24c4;
	case 9414ULL: goto x86_l_24c6;
	case 9417ULL: goto x86_l_24c9;
	case 9422ULL: goto x86_l_24ce;
	case 9427ULL: goto x86_l_24d3;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9438ULL: goto x86_l_24de;
	case 9440ULL: goto x86_l_24e0;
	case 9446ULL: goto x86_l_24e6;
	case 9454ULL: goto x86_l_24ee;
	case 9460ULL: goto x86_l_24f4;
	case 9466ULL: goto x86_l_24fa;
	case 9470ULL: goto x86_l_24fe;
	case 9474ULL: goto x86_l_2502;
	case 9482ULL: goto x86_l_250a;
	case 9484ULL: goto x86_l_250c;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9497ULL: goto x86_l_2519;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9508ULL: goto x86_l_2524;
	case 9510ULL: goto x86_l_2526;
	case 9516ULL: goto x86_l_252c;
	case 9524ULL: goto x86_l_2534;
	case 9530ULL: goto x86_l_253a;
	case 9536ULL: goto x86_l_2540;
	case 9540ULL: goto x86_l_2544;
	case 9544ULL: goto x86_l_2548;
	case 9552ULL: goto x86_l_2550;
	case 9554ULL: goto x86_l_2552;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9578ULL: goto x86_l_256a;
	case 9580ULL: goto x86_l_256c;
	case 9586ULL: goto x86_l_2572;
	case 9594ULL: goto x86_l_257a;
	case 9600ULL: goto x86_l_2580;
	case 9606ULL: goto x86_l_2586;
	case 9610ULL: goto x86_l_258a;
	case 9614ULL: goto x86_l_258e;
	case 9622ULL: goto x86_l_2596;
	case 9624ULL: goto x86_l_2598;
	case 9627ULL: goto x86_l_259b;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9648ULL: goto x86_l_25b0;
	case 9650ULL: goto x86_l_25b2;
	case 9656ULL: goto x86_l_25b8;
	case 9664ULL: goto x86_l_25c0;
	case 9670ULL: goto x86_l_25c6;
	case 9676ULL: goto x86_l_25cc;
	case 9680ULL: goto x86_l_25d0;
	case 9684ULL: goto x86_l_25d4;
	case 9692ULL: goto x86_l_25dc;
	case 9698ULL: goto x86_l_25e2;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9722ULL: goto x86_l_25fa;
	case 9724ULL: goto x86_l_25fc;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9745ULL: goto x86_l_2611;
	case 9750ULL: goto x86_l_2616;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9778ULL: goto x86_l_2632;
	case 9783ULL: goto x86_l_2637;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9804ULL: goto x86_l_264c;
	case 9810ULL: goto x86_l_2652;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9825ULL: goto x86_l_2661;
	case 9828ULL: goto x86_l_2664;
	case 9831ULL: goto x86_l_2667;
	case 9833ULL: goto x86_l_2669;
	case 9835ULL: goto x86_l_266b;
	case 9840ULL: goto x86_l_2670;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9851ULL: goto x86_l_267b;
	case 9855ULL: goto x86_l_267f;
	case 9858ULL: goto x86_l_2682;
	case 9861ULL: goto x86_l_2685;
	case 9869ULL: goto x86_l_268d;
	case 9875ULL: goto x86_l_2693;
	case 9881ULL: goto x86_l_2699;
	case 9884ULL: goto x86_l_269c;
	case 9888ULL: goto x86_l_26a0;
	case 9896ULL: goto x86_l_26a8;
	case 9898ULL: goto x86_l_26aa;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9922ULL: goto x86_l_26c2;
	case 9924ULL: goto x86_l_26c4;
	case 9930ULL: goto x86_l_26ca;
	case 9938ULL: goto x86_l_26d2;
	case 9944ULL: goto x86_l_26d8;
	case 9950ULL: goto x86_l_26de;
	case 9954ULL: goto x86_l_26e2;
	case 9958ULL: goto x86_l_26e6;
	case 9966ULL: goto x86_l_26ee;
	case 9968ULL: goto x86_l_26f0;
	case 9971ULL: goto x86_l_26f3;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9985ULL: goto x86_l_2701;
	case 9990ULL: goto x86_l_2706;
	case 9992ULL: goto x86_l_2708;
	case 9994ULL: goto x86_l_270a;
	case 10000ULL: goto x86_l_2710;
	case 10008ULL: goto x86_l_2718;
	case 10014ULL: goto x86_l_271e;
	case 10020ULL: goto x86_l_2724;
	case 10024ULL: goto x86_l_2728;
	case 10028ULL: goto x86_l_272c;
	case 10036ULL: goto x86_l_2734;
	case 10038ULL: goto x86_l_2736;
	case 10041ULL: goto x86_l_2739;
	case 10046ULL: goto x86_l_273e;
	case 10051ULL: goto x86_l_2743;
	case 10055ULL: goto x86_l_2747;
	case 10060ULL: goto x86_l_274c;
	case 10062ULL: goto x86_l_274e;
	case 10064ULL: goto x86_l_2750;
	case 10070ULL: goto x86_l_2756;
	case 10078ULL: goto x86_l_275e;
	case 10084ULL: goto x86_l_2764;
	case 10090ULL: goto x86_l_276a;
	case 10094ULL: goto x86_l_276e;
	case 10098ULL: goto x86_l_2772;
	case 10106ULL: goto x86_l_277a;
	case 10108ULL: goto x86_l_277c;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10121ULL: goto x86_l_2789;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10134ULL: goto x86_l_2796;
	case 10140ULL: goto x86_l_279c;
	case 10148ULL: goto x86_l_27a4;
	case 10154ULL: goto x86_l_27aa;
	case 10160ULL: goto x86_l_27b0;
	case 10164ULL: goto x86_l_27b4;
	case 10168ULL: goto x86_l_27b8;
	case 10176ULL: goto x86_l_27c0;
	case 10178ULL: goto x86_l_27c2;
	case 10181ULL: goto x86_l_27c5;
	case 10186ULL: goto x86_l_27ca;
	case 10191ULL: goto x86_l_27cf;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10204ULL: goto x86_l_27dc;
	case 10210ULL: goto x86_l_27e2;
	case 10218ULL: goto x86_l_27ea;
	case 10224ULL: goto x86_l_27f0;
	case 10230ULL: goto x86_l_27f6;
	case 10234ULL: goto x86_l_27fa;
	case 10238ULL: goto x86_l_27fe;
	case 10246ULL: goto x86_l_2806;
	case 10248ULL: goto x86_l_2808;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10261ULL: goto x86_l_2815;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10272ULL: goto x86_l_2820;
	case 10274ULL: goto x86_l_2822;
	case 10280ULL: goto x86_l_2828;
	case 10288ULL: goto x86_l_2830;
	case 10294ULL: goto x86_l_2836;
	case 10300ULL: goto x86_l_283c;
	case 10304ULL: goto x86_l_2840;
	case 10308ULL: goto x86_l_2844;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10321ULL: goto x86_l_2851;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10342ULL: goto x86_l_2866;
	case 10344ULL: goto x86_l_2868;
	case 10350ULL: goto x86_l_286e;
	case 10358ULL: goto x86_l_2876;
	case 10364ULL: goto x86_l_287c;
	case 10370ULL: goto x86_l_2882;
	case 10374ULL: goto x86_l_2886;
	case 10378ULL: goto x86_l_288a;
	case 10386ULL: goto x86_l_2892;
	case 10388ULL: goto x86_l_2894;
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10401ULL: goto x86_l_28a1;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10412ULL: goto x86_l_28ac;
	case 10414ULL: goto x86_l_28ae;
	case 10420ULL: goto x86_l_28b4;
	case 10428ULL: goto x86_l_28bc;
	case 10434ULL: goto x86_l_28c2;
	case 10440ULL: goto x86_l_28c8;
	case 10444ULL: goto x86_l_28cc;
	case 10448ULL: goto x86_l_28d0;
	case 10456ULL: goto x86_l_28d8;
	case 10458ULL: goto x86_l_28da;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10471ULL: goto x86_l_28e7;
	case 10475ULL: goto x86_l_28eb;
	case 10480ULL: goto x86_l_28f0;
	case 10482ULL: goto x86_l_28f2;
	case 10484ULL: goto x86_l_28f4;
	case 10490ULL: goto x86_l_28fa;
	case 10498ULL: goto x86_l_2902;
	case 10504ULL: goto x86_l_2908;
	case 10510ULL: goto x86_l_290e;
	case 10514ULL: goto x86_l_2912;
	case 10518ULL: goto x86_l_2916;
	case 10526ULL: goto x86_l_291e;
	case 10532ULL: goto x86_l_2924;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10556ULL: goto x86_l_293c;
	case 10558ULL: goto x86_l_293e;
	case 10564ULL: goto x86_l_2944;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10600ULL: goto x86_l_2968;
	case 10603ULL: goto x86_l_296b;
	case 10605ULL: goto x86_l_296d;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10614ULL: goto x86_l_2976;
	case 10619ULL: goto x86_l_297b;
	case 10623ULL: goto x86_l_297f;
	case 10627ULL: goto x86_l_2983;
	case 10630ULL: goto x86_l_2986;
	case 10633ULL: goto x86_l_2989;
	case 10641ULL: goto x86_l_2991;
	case 10647ULL: goto x86_l_2997;
	case 10653ULL: goto x86_l_299d;
	case 10656ULL: goto x86_l_29a0;
	case 10660ULL: goto x86_l_29a4;
	case 10668ULL: goto x86_l_29ac;
	case 10670ULL: goto x86_l_29ae;
	case 10673ULL: goto x86_l_29b1;
	case 10678ULL: goto x86_l_29b6;
	case 10683ULL: goto x86_l_29bb;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10694ULL: goto x86_l_29c6;
	case 10696ULL: goto x86_l_29c8;
	case 10702ULL: goto x86_l_29ce;
	case 10710ULL: goto x86_l_29d6;
	case 10716ULL: goto x86_l_29dc;
	case 10722ULL: goto x86_l_29e2;
	case 10726ULL: goto x86_l_29e6;
	case 10730ULL: goto x86_l_29ea;
	case 10738ULL: goto x86_l_29f2;
	case 10740ULL: goto x86_l_29f4;
	case 10743ULL: goto x86_l_29f7;
	case 10748ULL: goto x86_l_29fc;
	case 10753ULL: goto x86_l_2a01;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10764ULL: goto x86_l_2a0c;
	case 10766ULL: goto x86_l_2a0e;
	case 10772ULL: goto x86_l_2a14;
	case 10780ULL: goto x86_l_2a1c;
	case 10786ULL: goto x86_l_2a22;
	case 10792ULL: goto x86_l_2a28;
	case 10796ULL: goto x86_l_2a2c;
	case 10800ULL: goto x86_l_2a30;
	case 10808ULL: goto x86_l_2a38;
	case 10810ULL: goto x86_l_2a3a;
	case 10813ULL: goto x86_l_2a3d;
	case 10818ULL: goto x86_l_2a42;
	case 10823ULL: goto x86_l_2a47;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10834ULL: goto x86_l_2a52;
	case 10836ULL: goto x86_l_2a54;
	case 10842ULL: goto x86_l_2a5a;
	case 10850ULL: goto x86_l_2a62;
	case 10856ULL: goto x86_l_2a68;
	case 10862ULL: goto x86_l_2a6e;
	case 10866ULL: goto x86_l_2a72;
	case 10870ULL: goto x86_l_2a76;
	case 10878ULL: goto x86_l_2a7e;
	case 10880ULL: goto x86_l_2a80;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10893ULL: goto x86_l_2a8d;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10904ULL: goto x86_l_2a98;
	case 10906ULL: goto x86_l_2a9a;
	case 10912ULL: goto x86_l_2aa0;
	case 10920ULL: goto x86_l_2aa8;
	case 10926ULL: goto x86_l_2aae;
	case 10932ULL: goto x86_l_2ab4;
	case 10936ULL: goto x86_l_2ab8;
	case 10940ULL: goto x86_l_2abc;
	case 10948ULL: goto x86_l_2ac4;
	case 10950ULL: goto x86_l_2ac6;
	case 10953ULL: goto x86_l_2ac9;
	case 10958ULL: goto x86_l_2ace;
	case 10963ULL: goto x86_l_2ad3;
	case 10967ULL: goto x86_l_2ad7;
	case 10972ULL: goto x86_l_2adc;
	case 10974ULL: goto x86_l_2ade;
	case 10976ULL: goto x86_l_2ae0;
	case 10982ULL: goto x86_l_2ae6;
	case 10990ULL: goto x86_l_2aee;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23fc:
	/* 0x23fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2401:
	/* 0x2401: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2405:
	/* 0x2405: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_240a:
	/* 0x240a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240c:
	/* 0x240c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_240e:
	/* 0x240e: js     2fae <generic_sleepable_preload+0x2fae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12206ULL;
	}
x86_l_2414:
	/* 0x2414: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_241c:
	/* 0x241c: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_2422:
	/* 0x2422: mov    ecx,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_2428:
	/* 0x2428: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_242c:
	/* 0x242c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2430:
	/* 0x2430: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_2438:
	/* 0x2438: je     245a <generic_sleepable_preload+0x245a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_245a;
	}
x86_l_243a:
	/* 0x243a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_243d:
	/* 0x243d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2442:
	/* 0x2442: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2447:
	/* 0x2447: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_244b:
	/* 0x244b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2450:
	/* 0x2450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2452:
	/* 0x2452: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2454:
	/* 0x2454: js     301a <generic_sleepable_preload+0x301a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12314ULL;
	}
x86_l_245a:
	/* 0x245a: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_2462:
	/* 0x2462: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_2468:
	/* 0x2468: mov    ecx,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_246e:
	/* 0x246e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2472:
	/* 0x2472: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2476:
	/* 0x2476: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_247e:
	/* 0x247e: je     24a0 <generic_sleepable_preload+0x24a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a0;
	}
x86_l_2480:
	/* 0x2480: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2483:
	/* 0x2483: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2488:
	/* 0x2488: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_248d:
	/* 0x248d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2491:
	/* 0x2491: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2496:
	/* 0x2496: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2498:
	/* 0x2498: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_249a:
	/* 0x249a: js     3086 <generic_sleepable_preload+0x3086> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12422ULL;
	}
x86_l_24a0:
	/* 0x24a0: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_24a8:
	/* 0x24a8: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_24ae:
	/* 0x24ae: mov    ecx,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_24b4:
	/* 0x24b4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24b8:
	/* 0x24b8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24bc:
	/* 0x24bc: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_24c4:
	/* 0x24c4: je     24e6 <generic_sleepable_preload+0x24e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e6;
	}
x86_l_24c6:
	/* 0x24c6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24c9:
	/* 0x24c9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24ce:
	/* 0x24ce: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24d3:
	/* 0x24d3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24d7:
	/* 0x24d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24dc:
	/* 0x24dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24de:
	/* 0x24de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24e0:
	/* 0x24e0: js     30ef <generic_sleepable_preload+0x30ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12527ULL;
	}
x86_l_24e6:
	/* 0x24e6: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_24ee:
	/* 0x24ee: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_24f4:
	/* 0x24f4: mov    ecx,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_24fa:
	/* 0x24fa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24fe:
	/* 0x24fe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2502:
	/* 0x2502: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_250a:
	/* 0x250a: je     252c <generic_sleepable_preload+0x252c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_252c;
	}
x86_l_250c:
	/* 0x250c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_250f:
	/* 0x250f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2514:
	/* 0x2514: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2519:
	/* 0x2519: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_251d:
	/* 0x251d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2522:
	/* 0x2522: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2524:
	/* 0x2524: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2526:
	/* 0x2526: js     34ae <generic_sleepable_preload+0x34ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13486ULL;
	}
x86_l_252c:
	/* 0x252c: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_2534:
	/* 0x2534: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_253a:
	/* 0x253a: mov    ecx,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_2540:
	/* 0x2540: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2544:
	/* 0x2544: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2548:
	/* 0x2548: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_2550:
	/* 0x2550: je     2572 <generic_sleepable_preload+0x2572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2572;
	}
x86_l_2552:
	/* 0x2552: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2555:
	/* 0x2555: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_255a:
	/* 0x255a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_255f:
	/* 0x255f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2563:
	/* 0x2563: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2568:
	/* 0x2568: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256a:
	/* 0x256a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_256c:
	/* 0x256c: js     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14323ULL;
	}
x86_l_2572:
	/* 0x2572: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_257a:
	/* 0x257a: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_2580:
	/* 0x2580: mov    ecx,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_2586:
	/* 0x2586: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_258a:
	/* 0x258a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_258e:
	/* 0x258e: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_2596:
	/* 0x2596: je     25b8 <generic_sleepable_preload+0x25b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b8;
	}
x86_l_2598:
	/* 0x2598: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_259b:
	/* 0x259b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25a0:
	/* 0x25a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25a5:
	/* 0x25a5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25a9:
	/* 0x25a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25ae:
	/* 0x25ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b0:
	/* 0x25b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25b2:
	/* 0x25b2: js     3890 <generic_sleepable_preload+0x3890> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14480ULL;
	}
x86_l_25b8:
	/* 0x25b8: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_25c0:
	/* 0x25c0: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_25c6:
	/* 0x25c6: mov    ecx,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_25cc:
	/* 0x25cc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25d0:
	/* 0x25d0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25d4:
	/* 0x25d4: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_25dc:
	/* 0x25dc: je     34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_25e2:
	/* 0x25e2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_25e5:
	/* 0x25e5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25ea:
	/* 0x25ea: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25ef:
	/* 0x25ef: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f3:
	/* 0x25f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25f8:
	/* 0x25f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25fa:
	/* 0x25fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25fc:
	/* 0x25fc: jns    34b6 <generic_sleepable_preload+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13494ULL;
	}
x86_l_2602:
	/* 0x2602: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2607:
	/* 0x2607: jmp    34b3 <generic_sleepable_preload+0x34b3> */
	return 13491ULL;
x86_l_260c:
	/* 0x260c: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2611:
	/* 0x2611: jmp    34b3 <generic_sleepable_preload+0x34b3> */
	return 13491ULL;
x86_l_2616:
	/* 0x2616: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_261c:
	/* 0x261c: jmp    3120 <generic_sleepable_preload+0x3120> */
	return 12576ULL;
x86_l_2621:
	/* 0x2621: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2627:
	/* 0x2627: jmp    31b6 <generic_sleepable_preload+0x31b6> */
	return 12726ULL;
x86_l_262c:
	/* 0x262c: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2632:
	/* 0x2632: jmp    3249 <generic_sleepable_preload+0x3249> */
	return 12873ULL;
x86_l_2637:
	/* 0x2637: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_263d:
	/* 0x263d: jmp    32dc <generic_sleepable_preload+0x32dc> */
	return 13020ULL;
x86_l_2642:
	/* 0x2642: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2647:
	/* 0x2647: jmp    336e <generic_sleepable_preload+0x336e> */
	return 13166ULL;
x86_l_264c:
	/* 0x264c: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2652:
	/* 0x2652: jmp    33f8 <generic_sleepable_preload+0x33f8> */
	return 13304ULL;
x86_l_2657:
	/* 0x2657: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_265c:
	/* 0x265c: jmp    34b3 <generic_sleepable_preload+0x34b3> */
	return 13491ULL;
x86_l_2661:
	/* 0x2661: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2664:
	/* 0x2664: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2667:
	/* 0x2667: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_2669:
	/* 0x2669: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_266b:
	/* 0x266b: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2670:
	/* 0x2670: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2672:
	/* 0x2672: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2677:
	/* 0x2677: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267b:
	/* 0x267b: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_267f:
	/* 0x267f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2682:
	/* 0x2682: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2685:
	/* 0x2685: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_268d:
	/* 0x268d: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_2693:
	/* 0x2693: mov    eax,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2699:
	/* 0x2699: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_269c:
	/* 0x269c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a0:
	/* 0x26a0: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_26a8:
	/* 0x26a8: je     26ca <generic_sleepable_preload+0x26ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26ca;
	}
x86_l_26aa:
	/* 0x26aa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26ad:
	/* 0x26ad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26b2:
	/* 0x26b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26b7:
	/* 0x26b7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26bb:
	/* 0x26bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26c0:
	/* 0x26c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c2:
	/* 0x26c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26c4:
	/* 0x26c4: js     294f <generic_sleepable_preload+0x294f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_294f;
	}
x86_l_26ca:
	/* 0x26ca: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_26d2:
	/* 0x26d2: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_26d8:
	/* 0x26d8: mov    ecx,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_26de:
	/* 0x26de: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26e2:
	/* 0x26e2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e6:
	/* 0x26e6: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_26ee:
	/* 0x26ee: je     2710 <generic_sleepable_preload+0x2710> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2710;
	}
x86_l_26f0:
	/* 0x26f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26f3:
	/* 0x26f3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26f8:
	/* 0x26f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26fd:
	/* 0x26fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2701:
	/* 0x2701: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2706:
	/* 0x2706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2708:
	/* 0x2708: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_270a:
	/* 0x270a: js     295a <generic_sleepable_preload+0x295a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_295a;
	}
x86_l_2710:
	/* 0x2710: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2718:
	/* 0x2718: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_271e:
	/* 0x271e: mov    ecx,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2724:
	/* 0x2724: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2728:
	/* 0x2728: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_272c:
	/* 0x272c: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2734:
	/* 0x2734: je     2756 <generic_sleepable_preload+0x2756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2756;
	}
x86_l_2736:
	/* 0x2736: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2739:
	/* 0x2739: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_273e:
	/* 0x273e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2743:
	/* 0x2743: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2747:
	/* 0x2747: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_274c:
	/* 0x274c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274e:
	/* 0x274e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2750:
	/* 0x2750: js     2fb8 <generic_sleepable_preload+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12216ULL;
	}
x86_l_2756:
	/* 0x2756: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_275e:
	/* 0x275e: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_2764:
	/* 0x2764: mov    ecx,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_276a:
	/* 0x276a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_276e:
	/* 0x276e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2772:
	/* 0x2772: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_277a:
	/* 0x277a: je     279c <generic_sleepable_preload+0x279c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_279c;
	}
x86_l_277c:
	/* 0x277c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_277f:
	/* 0x277f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2784:
	/* 0x2784: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2789:
	/* 0x2789: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_278d:
	/* 0x278d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2792:
	/* 0x2792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2794:
	/* 0x2794: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2796:
	/* 0x2796: js     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12324ULL;
	}
x86_l_279c:
	/* 0x279c: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_27a4:
	/* 0x27a4: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_27aa:
	/* 0x27aa: mov    ecx,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_27b0:
	/* 0x27b0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27b4:
	/* 0x27b4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b8:
	/* 0x27b8: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_27c0:
	/* 0x27c0: je     27e2 <generic_sleepable_preload+0x27e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e2;
	}
x86_l_27c2:
	/* 0x27c2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27c5:
	/* 0x27c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27ca:
	/* 0x27ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27cf:
	/* 0x27cf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x27dc: js     3090 <generic_sleepable_preload+0x3090> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12432ULL;
	}
x86_l_27e2:
	/* 0x27e2: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_27ea:
	/* 0x27ea: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_27f0:
	/* 0x27f0: mov    ecx,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_27f6:
	/* 0x27f6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27fa:
	/* 0x27fa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27fe:
	/* 0x27fe: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2806:
	/* 0x2806: je     2828 <generic_sleepable_preload+0x2828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2828;
	}
x86_l_2808:
	/* 0x2808: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_280b:
	/* 0x280b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2810:
	/* 0x2810: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2815:
	/* 0x2815: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2819:
	/* 0x2819: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_281e:
	/* 0x281e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2820:
	/* 0x2820: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2822:
	/* 0x2822: js     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12537ULL;
	}
x86_l_2828:
	/* 0x2828: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2830:
	/* 0x2830: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_2836:
	/* 0x2836: mov    ecx,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_283c:
	/* 0x283c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2840:
	/* 0x2840: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2844:
	/* 0x2844: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_284c:
	/* 0x284c: je     286e <generic_sleepable_preload+0x286e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_286e;
	}
x86_l_284e:
	/* 0x284e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2851:
	/* 0x2851: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2856:
	/* 0x2856: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_285b:
	/* 0x285b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_285f:
	/* 0x285f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2864:
	/* 0x2864: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2866:
	/* 0x2866: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2868:
	/* 0x2868: js     355e <generic_sleepable_preload+0x355e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13662ULL;
	}
x86_l_286e:
	/* 0x286e: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2876:
	/* 0x2876: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_287c:
	/* 0x287c: mov    ecx,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2882:
	/* 0x2882: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2886:
	/* 0x2886: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_288a:
	/* 0x288a: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2892:
	/* 0x2892: je     28b4 <generic_sleepable_preload+0x28b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28b4;
	}
x86_l_2894:
	/* 0x2894: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2897:
	/* 0x2897: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_289c:
	/* 0x289c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28a1:
	/* 0x28a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a5:
	/* 0x28a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28aa:
	/* 0x28aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ac:
	/* 0x28ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28ae:
	/* 0x28ae: js     380a <generic_sleepable_preload+0x380a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14346ULL;
	}
x86_l_28b4:
	/* 0x28b4: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_28bc:
	/* 0x28bc: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_28c2:
	/* 0x28c2: mov    ecx,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_28c8:
	/* 0x28c8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28cc:
	/* 0x28cc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d0:
	/* 0x28d0: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_28d8:
	/* 0x28d8: je     28fa <generic_sleepable_preload+0x28fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28fa;
	}
x86_l_28da:
	/* 0x28da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28dd:
	/* 0x28dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28e2:
	/* 0x28e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28e7:
	/* 0x28e7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28eb:
	/* 0x28eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28f0:
	/* 0x28f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f2:
	/* 0x28f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28f4:
	/* 0x28f4: js     389a <generic_sleepable_preload+0x389a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14490ULL;
	}
x86_l_28fa:
	/* 0x28fa: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2902:
	/* 0x2902: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_2908:
	/* 0x2908: mov    ecx,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_290e:
	/* 0x290e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2912:
	/* 0x2912: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2916:
	/* 0x2916: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_291e:
	/* 0x291e: je     3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13670ULL;
	}
x86_l_2924:
	/* 0x2924: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2927:
	/* 0x2927: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_292c:
	/* 0x292c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2931:
	/* 0x2931: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2935:
	/* 0x2935: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_293a:
	/* 0x293a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293c:
	/* 0x293c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_293e:
	/* 0x293e: jns    3566 <generic_sleepable_preload+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13670ULL;
	}
x86_l_2944:
	/* 0x2944: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_294a:
	/* 0x294a: jmp    3564 <generic_sleepable_preload+0x3564> */
	return 13668ULL;
x86_l_294f:
	/* 0x294f: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2955:
	/* 0x2955: jmp    3564 <generic_sleepable_preload+0x3564> */
	return 13668ULL;
x86_l_295a:
	/* 0x295a: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2960:
	/* 0x2960: jmp    3564 <generic_sleepable_preload+0x3564> */
	return 13668ULL;
x86_l_2965:
	/* 0x2965: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2968:
	/* 0x2968: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_296b:
	/* 0x296b: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_296d:
	/* 0x296d: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_296f:
	/* 0x296f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2974:
	/* 0x2974: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2976:
	/* 0x2976: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_297b:
	/* 0x297b: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297f:
	/* 0x297f: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2983:
	/* 0x2983: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2986:
	/* 0x2986: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2989:
	/* 0x2989: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2991:
	/* 0x2991: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2997:
	/* 0x2997: mov    eax,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_299d:
	/* 0x299d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29a0:
	/* 0x29a0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a4:
	/* 0x29a4: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_29ac:
	/* 0x29ac: je     29ce <generic_sleepable_preload+0x29ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29ce;
	}
x86_l_29ae:
	/* 0x29ae: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29b1:
	/* 0x29b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29b6:
	/* 0x29b6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29bb:
	/* 0x29bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29bf:
	/* 0x29bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c4:
	/* 0x29c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c6:
	/* 0x29c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29c8:
	/* 0x29c8: js     2c53 <generic_sleepable_preload+0x2c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11347ULL;
	}
x86_l_29ce:
	/* 0x29ce: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_29d6:
	/* 0x29d6: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_29dc:
	/* 0x29dc: mov    ecx,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_29e2:
	/* 0x29e2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29e6:
	/* 0x29e6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ea:
	/* 0x29ea: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_29f2:
	/* 0x29f2: je     2a14 <generic_sleepable_preload+0x2a14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a14;
	}
x86_l_29f4:
	/* 0x29f4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29f7:
	/* 0x29f7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29fc:
	/* 0x29fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a01:
	/* 0x2a01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a05:
	/* 0x2a05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a0a:
	/* 0x2a0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0c:
	/* 0x2a0c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a0e:
	/* 0x2a0e: js     2c5e <generic_sleepable_preload+0x2c5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11358ULL;
	}
x86_l_2a14:
	/* 0x2a14: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2a1c:
	/* 0x2a1c: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2a22:
	/* 0x2a22: mov    ecx,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2a28:
	/* 0x2a28: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a2c:
	/* 0x2a2c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a30:
	/* 0x2a30: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2a38:
	/* 0x2a38: je     2a5a <generic_sleepable_preload+0x2a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a5a;
	}
x86_l_2a3a:
	/* 0x2a3a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a3d:
	/* 0x2a3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a42:
	/* 0x2a42: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a47:
	/* 0x2a47: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x2a54: js     2fc3 <generic_sleepable_preload+0x2fc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12227ULL;
	}
x86_l_2a5a:
	/* 0x2a5a: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2a62:
	/* 0x2a62: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2a68:
	/* 0x2a68: mov    ecx,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2a6e:
	/* 0x2a6e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a72:
	/* 0x2a72: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a76:
	/* 0x2a76: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2a7e:
	/* 0x2a7e: je     2aa0 <generic_sleepable_preload+0x2aa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa0;
	}
x86_l_2a80:
	/* 0x2a80: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a83:
	/* 0x2a83: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a88:
	/* 0x2a88: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a8d:
	/* 0x2a8d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a91:
	/* 0x2a91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a96:
	/* 0x2a96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a98:
	/* 0x2a98: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a9a:
	/* 0x2a9a: js     302f <generic_sleepable_preload+0x302f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12335ULL;
	}
x86_l_2aa0:
	/* 0x2aa0: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2aa8:
	/* 0x2aa8: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2aae:
	/* 0x2aae: mov    ecx,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2ab4:
	/* 0x2ab4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ab8:
	/* 0x2ab8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2abc:
	/* 0x2abc: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2ac4:
	/* 0x2ac4: je     2ae6 <generic_sleepable_preload+0x2ae6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae6;
	}
x86_l_2ac6:
	/* 0x2ac6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ac9:
	/* 0x2ac9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ace:
	/* 0x2ace: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ad3:
	/* 0x2ad3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad7:
	/* 0x2ad7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2adc:
	/* 0x2adc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ade:
	/* 0x2ade: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ae0:
	/* 0x2ae0: js     309b <generic_sleepable_preload+0x309b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12443ULL;
	}
x86_l_2ae6:
	/* 0x2ae6: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2aee:
	/* 0x2aee: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
	return 10996ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10996ULL: goto x86_l_2af4;
	case 11002ULL: goto x86_l_2afa;
	case 11006ULL: goto x86_l_2afe;
	case 11010ULL: goto x86_l_2b02;
	case 11018ULL: goto x86_l_2b0a;
	case 11020ULL: goto x86_l_2b0c;
	case 11023ULL: goto x86_l_2b0f;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11037ULL: goto x86_l_2b1d;
	case 11042ULL: goto x86_l_2b22;
	case 11044ULL: goto x86_l_2b24;
	case 11046ULL: goto x86_l_2b26;
	case 11052ULL: goto x86_l_2b2c;
	case 11060ULL: goto x86_l_2b34;
	case 11066ULL: goto x86_l_2b3a;
	case 11072ULL: goto x86_l_2b40;
	case 11076ULL: goto x86_l_2b44;
	case 11080ULL: goto x86_l_2b48;
	case 11088ULL: goto x86_l_2b50;
	case 11090ULL: goto x86_l_2b52;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11103ULL: goto x86_l_2b5f;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11114ULL: goto x86_l_2b6a;
	case 11116ULL: goto x86_l_2b6c;
	case 11122ULL: goto x86_l_2b72;
	case 11130ULL: goto x86_l_2b7a;
	case 11136ULL: goto x86_l_2b80;
	case 11142ULL: goto x86_l_2b86;
	case 11146ULL: goto x86_l_2b8a;
	case 11150ULL: goto x86_l_2b8e;
	case 11158ULL: goto x86_l_2b96;
	case 11160ULL: goto x86_l_2b98;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11177ULL: goto x86_l_2ba9;
	case 11182ULL: goto x86_l_2bae;
	case 11184ULL: goto x86_l_2bb0;
	case 11186ULL: goto x86_l_2bb2;
	case 11192ULL: goto x86_l_2bb8;
	case 11200ULL: goto x86_l_2bc0;
	case 11206ULL: goto x86_l_2bc6;
	case 11212ULL: goto x86_l_2bcc;
	case 11216ULL: goto x86_l_2bd0;
	case 11220ULL: goto x86_l_2bd4;
	case 11228ULL: goto x86_l_2bdc;
	case 11230ULL: goto x86_l_2bde;
	case 11233ULL: goto x86_l_2be1;
	case 11238ULL: goto x86_l_2be6;
	case 11243ULL: goto x86_l_2beb;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11254ULL: goto x86_l_2bf6;
	case 11256ULL: goto x86_l_2bf8;
	case 11262ULL: goto x86_l_2bfe;
	case 11270ULL: goto x86_l_2c06;
	case 11276ULL: goto x86_l_2c0c;
	case 11282ULL: goto x86_l_2c12;
	case 11286ULL: goto x86_l_2c16;
	case 11290ULL: goto x86_l_2c1a;
	case 11298ULL: goto x86_l_2c22;
	case 11304ULL: goto x86_l_2c28;
	case 11307ULL: goto x86_l_2c2b;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11321ULL: goto x86_l_2c39;
	case 11326ULL: goto x86_l_2c3e;
	case 11328ULL: goto x86_l_2c40;
	case 11330ULL: goto x86_l_2c42;
	case 11336ULL: goto x86_l_2c48;
	case 11342ULL: goto x86_l_2c4e;
	case 11347ULL: goto x86_l_2c53;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11364ULL: goto x86_l_2c64;
	case 11369ULL: goto x86_l_2c69;
	case 11372ULL: goto x86_l_2c6c;
	case 11375ULL: goto x86_l_2c6f;
	case 11377ULL: goto x86_l_2c71;
	case 11379ULL: goto x86_l_2c73;
	case 11384ULL: goto x86_l_2c78;
	case 11386ULL: goto x86_l_2c7a;
	case 11391ULL: goto x86_l_2c7f;
	case 11395ULL: goto x86_l_2c83;
	case 11399ULL: goto x86_l_2c87;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11413ULL: goto x86_l_2c95;
	case 11419ULL: goto x86_l_2c9b;
	case 11425ULL: goto x86_l_2ca1;
	case 11428ULL: goto x86_l_2ca4;
	case 11432ULL: goto x86_l_2ca8;
	case 11440ULL: goto x86_l_2cb0;
	case 11442ULL: goto x86_l_2cb2;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11455ULL: goto x86_l_2cbf;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11466ULL: goto x86_l_2cca;
	case 11468ULL: goto x86_l_2ccc;
	case 11474ULL: goto x86_l_2cd2;
	case 11482ULL: goto x86_l_2cda;
	case 11488ULL: goto x86_l_2ce0;
	case 11494ULL: goto x86_l_2ce6;
	case 11498ULL: goto x86_l_2cea;
	case 11502ULL: goto x86_l_2cee;
	case 11510ULL: goto x86_l_2cf6;
	case 11512ULL: goto x86_l_2cf8;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11536ULL: goto x86_l_2d10;
	case 11538ULL: goto x86_l_2d12;
	case 11544ULL: goto x86_l_2d18;
	case 11552ULL: goto x86_l_2d20;
	case 11558ULL: goto x86_l_2d26;
	case 11564ULL: goto x86_l_2d2c;
	case 11568ULL: goto x86_l_2d30;
	case 11572ULL: goto x86_l_2d34;
	case 11580ULL: goto x86_l_2d3c;
	case 11582ULL: goto x86_l_2d3e;
	case 11585ULL: goto x86_l_2d41;
	case 11590ULL: goto x86_l_2d46;
	case 11595ULL: goto x86_l_2d4b;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11606ULL: goto x86_l_2d56;
	case 11608ULL: goto x86_l_2d58;
	case 11614ULL: goto x86_l_2d5e;
	case 11622ULL: goto x86_l_2d66;
	case 11628ULL: goto x86_l_2d6c;
	case 11634ULL: goto x86_l_2d72;
	case 11638ULL: goto x86_l_2d76;
	case 11642ULL: goto x86_l_2d7a;
	case 11650ULL: goto x86_l_2d82;
	case 11652ULL: goto x86_l_2d84;
	case 11655ULL: goto x86_l_2d87;
	case 11660ULL: goto x86_l_2d8c;
	case 11665ULL: goto x86_l_2d91;
	case 11669ULL: goto x86_l_2d95;
	case 11674ULL: goto x86_l_2d9a;
	case 11676ULL: goto x86_l_2d9c;
	case 11678ULL: goto x86_l_2d9e;
	case 11684ULL: goto x86_l_2da4;
	case 11692ULL: goto x86_l_2dac;
	case 11698ULL: goto x86_l_2db2;
	case 11704ULL: goto x86_l_2db8;
	case 11708ULL: goto x86_l_2dbc;
	case 11712ULL: goto x86_l_2dc0;
	case 11720ULL: goto x86_l_2dc8;
	case 11722ULL: goto x86_l_2dca;
	case 11725ULL: goto x86_l_2dcd;
	case 11730ULL: goto x86_l_2dd2;
	case 11735ULL: goto x86_l_2dd7;
	case 11739ULL: goto x86_l_2ddb;
	case 11744ULL: goto x86_l_2de0;
	case 11746ULL: goto x86_l_2de2;
	case 11748ULL: goto x86_l_2de4;
	case 11754ULL: goto x86_l_2dea;
	case 11762ULL: goto x86_l_2df2;
	case 11768ULL: goto x86_l_2df8;
	case 11774ULL: goto x86_l_2dfe;
	case 11778ULL: goto x86_l_2e02;
	case 11782ULL: goto x86_l_2e06;
	case 11790ULL: goto x86_l_2e0e;
	case 11792ULL: goto x86_l_2e10;
	case 11795ULL: goto x86_l_2e13;
	case 11800ULL: goto x86_l_2e18;
	case 11805ULL: goto x86_l_2e1d;
	case 11809ULL: goto x86_l_2e21;
	case 11814ULL: goto x86_l_2e26;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11824ULL: goto x86_l_2e30;
	case 11832ULL: goto x86_l_2e38;
	case 11838ULL: goto x86_l_2e3e;
	case 11844ULL: goto x86_l_2e44;
	case 11848ULL: goto x86_l_2e48;
	case 11852ULL: goto x86_l_2e4c;
	case 11860ULL: goto x86_l_2e54;
	case 11862ULL: goto x86_l_2e56;
	case 11865ULL: goto x86_l_2e59;
	case 11870ULL: goto x86_l_2e5e;
	case 11875ULL: goto x86_l_2e63;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11886ULL: goto x86_l_2e6e;
	case 11888ULL: goto x86_l_2e70;
	case 11894ULL: goto x86_l_2e76;
	case 11902ULL: goto x86_l_2e7e;
	case 11908ULL: goto x86_l_2e84;
	case 11914ULL: goto x86_l_2e8a;
	case 11918ULL: goto x86_l_2e8e;
	case 11922ULL: goto x86_l_2e92;
	case 11930ULL: goto x86_l_2e9a;
	case 11932ULL: goto x86_l_2e9c;
	case 11935ULL: goto x86_l_2e9f;
	case 11940ULL: goto x86_l_2ea4;
	case 11945ULL: goto x86_l_2ea9;
	case 11949ULL: goto x86_l_2ead;
	case 11954ULL: goto x86_l_2eb2;
	case 11956ULL: goto x86_l_2eb4;
	case 11958ULL: goto x86_l_2eb6;
	case 11964ULL: goto x86_l_2ebc;
	case 11972ULL: goto x86_l_2ec4;
	case 11978ULL: goto x86_l_2eca;
	case 11984ULL: goto x86_l_2ed0;
	case 11988ULL: goto x86_l_2ed4;
	case 11992ULL: goto x86_l_2ed8;
	case 12000ULL: goto x86_l_2ee0;
	case 12002ULL: goto x86_l_2ee2;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12026ULL: goto x86_l_2efa;
	case 12028ULL: goto x86_l_2efc;
	case 12034ULL: goto x86_l_2f02;
	case 12042ULL: goto x86_l_2f0a;
	case 12048ULL: goto x86_l_2f10;
	case 12054ULL: goto x86_l_2f16;
	case 12058ULL: goto x86_l_2f1a;
	case 12062ULL: goto x86_l_2f1e;
	case 12070ULL: goto x86_l_2f26;
	case 12076ULL: goto x86_l_2f2c;
	case 12079ULL: goto x86_l_2f2f;
	case 12084ULL: goto x86_l_2f34;
	case 12089ULL: goto x86_l_2f39;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12100ULL: goto x86_l_2f44;
	case 12102ULL: goto x86_l_2f46;
	case 12108ULL: goto x86_l_2f4c;
	case 12114ULL: goto x86_l_2f52;
	case 12119ULL: goto x86_l_2f57;
	case 12125ULL: goto x86_l_2f5d;
	case 12130ULL: goto x86_l_2f62;
	case 12136ULL: goto x86_l_2f68;
	case 12141ULL: goto x86_l_2f6d;
	case 12147ULL: goto x86_l_2f73;
	case 12152ULL: goto x86_l_2f78;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12169ULL: goto x86_l_2f89;
	case 12174ULL: goto x86_l_2f8e;
	case 12180ULL: goto x86_l_2f94;
	case 12185ULL: goto x86_l_2f99;
	case 12190ULL: goto x86_l_2f9e;
	case 12195ULL: goto x86_l_2fa3;
	case 12201ULL: goto x86_l_2fa9;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12244ULL: goto x86_l_2fd4;
	case 12249ULL: goto x86_l_2fd9;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12266ULL: goto x86_l_2fea;
	case 12271ULL: goto x86_l_2fef;
	case 12277ULL: goto x86_l_2ff5;
	case 12282ULL: goto x86_l_2ffa;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12298ULL: goto x86_l_300a;
	case 12303ULL: goto x86_l_300f;
	case 12309ULL: goto x86_l_3015;
	case 12314ULL: goto x86_l_301a;
	case 12319ULL: goto x86_l_301f;
	case 12324ULL: goto x86_l_3024;
	case 12330ULL: goto x86_l_302a;
	case 12335ULL: goto x86_l_302f;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12363ULL: goto x86_l_304b;
	case 12368ULL: goto x86_l_3050;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12385ULL: goto x86_l_3061;
	case 12390ULL: goto x86_l_3066;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12406ULL: goto x86_l_3076;
	case 12411ULL: goto x86_l_307b;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12427ULL: goto x86_l_308b;
	case 12432ULL: goto x86_l_3090;
	case 12438ULL: goto x86_l_3096;
	case 12443ULL: goto x86_l_309b;
	case 12449ULL: goto x86_l_30a1;
	case 12454ULL: goto x86_l_30a6;
	case 12460ULL: goto x86_l_30ac;
	case 12465ULL: goto x86_l_30b1;
	case 12471ULL: goto x86_l_30b7;
	case 12473ULL: goto x86_l_30b9;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12490ULL: goto x86_l_30ca;
	case 12495ULL: goto x86_l_30cf;
	case 12501ULL: goto x86_l_30d5;
	case 12506ULL: goto x86_l_30da;
	case 12511ULL: goto x86_l_30df;
	case 12516ULL: goto x86_l_30e4;
	case 12522ULL: goto x86_l_30ea;
	case 12527ULL: goto x86_l_30ef;
	case 12532ULL: goto x86_l_30f4;
	case 12537ULL: goto x86_l_30f9;
	case 12543ULL: goto x86_l_30ff;
	case 12548ULL: goto x86_l_3104;
	case 12554ULL: goto x86_l_310a;
	case 12559ULL: goto x86_l_310f;
	case 12565ULL: goto x86_l_3115;
	case 12570ULL: goto x86_l_311a;
	case 12576ULL: goto x86_l_3120;
	case 12578ULL: goto x86_l_3122;
	case 12582ULL: goto x86_l_3126;
	case 12587ULL: goto x86_l_312b;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12602ULL: goto x86_l_313a;
	case 12605ULL: goto x86_l_313d;
	case 12607ULL: goto x86_l_313f;
	case 12611ULL: goto x86_l_3143;
	case 12617ULL: goto x86_l_3149;
	case 12622ULL: goto x86_l_314e;
	case 12627ULL: goto x86_l_3153;
	case 12632ULL: goto x86_l_3158;
	case 12634ULL: goto x86_l_315a;
	case 12639ULL: goto x86_l_315f;
	case 12646ULL: goto x86_l_3166;
	case 12653ULL: goto x86_l_316d;
	case 12656ULL: goto x86_l_3170;
	case 12661ULL: goto x86_l_3175;
	case 12663ULL: goto x86_l_3177;
	case 12666ULL: goto x86_l_317a;
	case 12672ULL: goto x86_l_3180;
	case 12675ULL: goto x86_l_3183;
	case 12678ULL: goto x86_l_3186;
	case 12681ULL: goto x86_l_3189;
	case 12688ULL: goto x86_l_3190;
	case 12690ULL: goto x86_l_3192;
	case 12695ULL: goto x86_l_3197;
	case 12700ULL: goto x86_l_319c;
	case 12703ULL: goto x86_l_319f;
	case 12706ULL: goto x86_l_31a2;
	case 12708ULL: goto x86_l_31a4;
	case 12710ULL: goto x86_l_31a6;
	case 12715ULL: goto x86_l_31ab;
	case 12720ULL: goto x86_l_31b0;
	case 12726ULL: goto x86_l_31b6;
	case 12728ULL: goto x86_l_31b8;
	case 12732ULL: goto x86_l_31bc;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12752ULL: goto x86_l_31d0;
	case 12755ULL: goto x86_l_31d3;
	case 12757ULL: goto x86_l_31d5;
	case 12761ULL: goto x86_l_31d9;
	case 12767ULL: goto x86_l_31df;
	case 12772ULL: goto x86_l_31e4;
	case 12777ULL: goto x86_l_31e9;
	case 12782ULL: goto x86_l_31ee;
	case 12784ULL: goto x86_l_31f0;
	case 12789ULL: goto x86_l_31f5;
	case 12796ULL: goto x86_l_31fc;
	case 12803ULL: goto x86_l_3203;
	case 12806ULL: goto x86_l_3206;
	case 12811ULL: goto x86_l_320b;
	case 12813ULL: goto x86_l_320d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2af4:
	/* 0x2af4: mov    ecx,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2afa:
	/* 0x2afa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2afe:
	/* 0x2afe: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b02:
	/* 0x2b02: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2b0a:
	/* 0x2b0a: je     2b2c <generic_sleepable_preload+0x2b2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b2c;
	}
x86_l_2b0c:
	/* 0x2b0c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b0f:
	/* 0x2b0f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b14:
	/* 0x2b14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b19:
	/* 0x2b19: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b1d:
	/* 0x2b1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b22:
	/* 0x2b22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b24:
	/* 0x2b24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b26:
	/* 0x2b26: js     3104 <generic_sleepable_preload+0x3104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3104;
	}
x86_l_2b2c:
	/* 0x2b2c: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2b34:
	/* 0x2b34: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2b3a:
	/* 0x2b3a: mov    ecx,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2b40:
	/* 0x2b40: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b44:
	/* 0x2b44: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b48:
	/* 0x2b48: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2b50:
	/* 0x2b50: je     2b72 <generic_sleepable_preload+0x2b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b72;
	}
x86_l_2b52:
	/* 0x2b52: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b55:
	/* 0x2b55: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b5a:
	/* 0x2b5a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b5f:
	/* 0x2b5f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b63:
	/* 0x2b63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b68:
	/* 0x2b68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6a:
	/* 0x2b6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b6c:
	/* 0x2b6c: js     361d <generic_sleepable_preload+0x361d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13853ULL;
	}
x86_l_2b72:
	/* 0x2b72: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2b7a:
	/* 0x2b7a: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2b80:
	/* 0x2b80: mov    ecx,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2b86:
	/* 0x2b86: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b8a:
	/* 0x2b8a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b8e:
	/* 0x2b8e: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2b96:
	/* 0x2b96: je     2bb8 <generic_sleepable_preload+0x2bb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bb8;
	}
x86_l_2b98:
	/* 0x2b98: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b9b:
	/* 0x2b9b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ba5:
	/* 0x2ba5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ba9:
	/* 0x2ba9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bae:
	/* 0x2bae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb0:
	/* 0x2bb0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bb2:
	/* 0x2bb2: js     3821 <generic_sleepable_preload+0x3821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14369ULL;
	}
x86_l_2bb8:
	/* 0x2bb8: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2bc0:
	/* 0x2bc0: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2bc6:
	/* 0x2bc6: mov    ecx,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2bcc:
	/* 0x2bcc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bd0:
	/* 0x2bd0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd4:
	/* 0x2bd4: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2bdc:
	/* 0x2bdc: je     2bfe <generic_sleepable_preload+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bfe;
	}
x86_l_2bde:
	/* 0x2bde: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2be1:
	/* 0x2be1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2be6:
	/* 0x2be6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2beb:
	/* 0x2beb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bef:
	/* 0x2bef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bf4:
	/* 0x2bf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf6:
	/* 0x2bf6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bf8:
	/* 0x2bf8: js     38a5 <generic_sleepable_preload+0x38a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14501ULL;
	}
x86_l_2bfe:
	/* 0x2bfe: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2c06:
	/* 0x2c06: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2c0c:
	/* 0x2c0c: mov    ecx,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2c12:
	/* 0x2c12: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c16:
	/* 0x2c16: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c1a:
	/* 0x2c1a: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2c22:
	/* 0x2c22: je     3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13861ULL;
	}
x86_l_2c28:
	/* 0x2c28: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c2b:
	/* 0x2c2b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c30:
	/* 0x2c30: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c35:
	/* 0x2c35: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c39:
	/* 0x2c39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c3e:
	/* 0x2c3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c40:
	/* 0x2c40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c42:
	/* 0x2c42: jns    3625 <generic_sleepable_preload+0x3625> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13861ULL;
	}
x86_l_2c48:
	/* 0x2c48: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_2c4e:
	/* 0x2c4e: jmp    3623 <generic_sleepable_preload+0x3623> */
	return 13859ULL;
x86_l_2c53:
	/* 0x2c53: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2c59:
	/* 0x2c59: jmp    3623 <generic_sleepable_preload+0x3623> */
	return 13859ULL;
x86_l_2c5e:
	/* 0x2c5e: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2c64:
	/* 0x2c64: jmp    3623 <generic_sleepable_preload+0x3623> */
	return 13859ULL;
x86_l_2c69:
	/* 0x2c69: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2c6c:
	/* 0x2c6c: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2c6f:
	/* 0x2c6f: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_2c71:
	/* 0x2c71: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2c73:
	/* 0x2c73: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2c78:
	/* 0x2c78: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c7a:
	/* 0x2c7a: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2c7f:
	/* 0x2c7f: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c83:
	/* 0x2c83: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c87:
	/* 0x2c87: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c8a:
	/* 0x2c8a: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2c8d:
	/* 0x2c8d: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_2c95:
	/* 0x2c95: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2c9b:
	/* 0x2c9b: mov    eax,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_2ca1:
	/* 0x2ca1: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ca4:
	/* 0x2ca4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca8:
	/* 0x2ca8: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_2cb0:
	/* 0x2cb0: je     2cd2 <generic_sleepable_preload+0x2cd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cd2;
	}
x86_l_2cb2:
	/* 0x2cb2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2cb5:
	/* 0x2cb5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cba:
	/* 0x2cba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cbf:
	/* 0x2cbf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cc8:
	/* 0x2cc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cca:
	/* 0x2cca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ccc:
	/* 0x2ccc: js     2f57 <generic_sleepable_preload+0x2f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f57;
	}
x86_l_2cd2:
	/* 0x2cd2: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_2cda:
	/* 0x2cda: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2ce0:
	/* 0x2ce0: mov    ecx,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_2ce6:
	/* 0x2ce6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2cea:
	/* 0x2cea: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cee:
	/* 0x2cee: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_2cf6:
	/* 0x2cf6: je     2d18 <generic_sleepable_preload+0x2d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d18;
	}
x86_l_2cf8:
	/* 0x2cf8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2cfb:
	/* 0x2cfb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d00:
	/* 0x2d00: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d05:
	/* 0x2d05: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d09:
	/* 0x2d09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d0e:
	/* 0x2d0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d10:
	/* 0x2d10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d12:
	/* 0x2d12: js     2f62 <generic_sleepable_preload+0x2f62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f62;
	}
x86_l_2d18:
	/* 0x2d18: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_2d20:
	/* 0x2d20: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2d26:
	/* 0x2d26: mov    ecx,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_2d2c:
	/* 0x2d2c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d30:
	/* 0x2d30: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d34:
	/* 0x2d34: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_2d3c:
	/* 0x2d3c: je     2d5e <generic_sleepable_preload+0x2d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d5e;
	}
x86_l_2d3e:
	/* 0x2d3e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d41:
	/* 0x2d41: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d46:
	/* 0x2d46: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d4f:
	/* 0x2d4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d54:
	/* 0x2d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d56:
	/* 0x2d56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d58:
	/* 0x2d58: js     2fce <generic_sleepable_preload+0x2fce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2fce;
	}
x86_l_2d5e:
	/* 0x2d5e: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_2d66:
	/* 0x2d66: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2d6c:
	/* 0x2d6c: mov    ecx,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_2d72:
	/* 0x2d72: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d76:
	/* 0x2d76: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d7a:
	/* 0x2d7a: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_2d82:
	/* 0x2d82: je     2da4 <generic_sleepable_preload+0x2da4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2da4;
	}
x86_l_2d84:
	/* 0x2d84: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d87:
	/* 0x2d87: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d8c:
	/* 0x2d8c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d91:
	/* 0x2d91: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d95:
	/* 0x2d95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d9a:
	/* 0x2d9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9c:
	/* 0x2d9c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d9e:
	/* 0x2d9e: js     303a <generic_sleepable_preload+0x303a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_303a;
	}
x86_l_2da4:
	/* 0x2da4: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_2dac:
	/* 0x2dac: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2db2:
	/* 0x2db2: mov    ecx,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_2db8:
	/* 0x2db8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2dbc:
	/* 0x2dbc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dc0:
	/* 0x2dc0: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_2dc8:
	/* 0x2dc8: je     2dea <generic_sleepable_preload+0x2dea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dea;
	}
x86_l_2dca:
	/* 0x2dca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2dcd:
	/* 0x2dcd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2dd2:
	/* 0x2dd2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2dd7:
	/* 0x2dd7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ddb:
	/* 0x2ddb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2de0:
	/* 0x2de0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de2:
	/* 0x2de2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2de4:
	/* 0x2de4: js     30a6 <generic_sleepable_preload+0x30a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_30a6;
	}
x86_l_2dea:
	/* 0x2dea: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_2df2:
	/* 0x2df2: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2df8:
	/* 0x2df8: mov    ecx,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_2dfe:
	/* 0x2dfe: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e02:
	/* 0x2e02: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e06:
	/* 0x2e06: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_2e0e:
	/* 0x2e0e: je     2e30 <generic_sleepable_preload+0x2e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e30;
	}
x86_l_2e10:
	/* 0x2e10: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e13:
	/* 0x2e13: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e18:
	/* 0x2e18: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e1d:
	/* 0x2e1d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e21:
	/* 0x2e21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e26:
	/* 0x2e26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e28:
	/* 0x2e28: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e2a:
	/* 0x2e2a: js     310f <generic_sleepable_preload+0x310f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_310f;
	}
x86_l_2e30:
	/* 0x2e30: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_2e38:
	/* 0x2e38: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2e3e:
	/* 0x2e3e: mov    ecx,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_2e44:
	/* 0x2e44: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e48:
	/* 0x2e48: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e4c:
	/* 0x2e4c: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_2e54:
	/* 0x2e54: je     2e76 <generic_sleepable_preload+0x2e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e76;
	}
x86_l_2e56:
	/* 0x2e56: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e59:
	/* 0x2e59: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e5e:
	/* 0x2e5e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e63:
	/* 0x2e63: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e67:
	/* 0x2e67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e6c:
	/* 0x2e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6e:
	/* 0x2e6e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e70:
	/* 0x2e70: js     36dc <generic_sleepable_preload+0x36dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14044ULL;
	}
x86_l_2e76:
	/* 0x2e76: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_2e7e:
	/* 0x2e7e: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2e84:
	/* 0x2e84: mov    ecx,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_2e8a:
	/* 0x2e8a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e8e:
	/* 0x2e8e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e92:
	/* 0x2e92: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_2e9a:
	/* 0x2e9a: je     2ebc <generic_sleepable_preload+0x2ebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ebc;
	}
x86_l_2e9c:
	/* 0x2e9c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e9f:
	/* 0x2e9f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ea4:
	/* 0x2ea4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ea9:
	/* 0x2ea9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ead:
	/* 0x2ead: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb2:
	/* 0x2eb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb4:
	/* 0x2eb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2eb6:
	/* 0x2eb6: js     3838 <generic_sleepable_preload+0x3838> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14392ULL;
	}
x86_l_2ebc:
	/* 0x2ebc: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_2ec4:
	/* 0x2ec4: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2eca:
	/* 0x2eca: mov    ecx,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_2ed0:
	/* 0x2ed0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ed4:
	/* 0x2ed4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed8:
	/* 0x2ed8: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_2ee0:
	/* 0x2ee0: je     2f02 <generic_sleepable_preload+0x2f02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f02;
	}
x86_l_2ee2:
	/* 0x2ee2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ee5:
	/* 0x2ee5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2eea:
	/* 0x2eea: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2eef:
	/* 0x2eef: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef3:
	/* 0x2ef3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ef8:
	/* 0x2ef8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2efa:
	/* 0x2efa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2efc:
	/* 0x2efc: js     38b0 <generic_sleepable_preload+0x38b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14512ULL;
	}
x86_l_2f02:
	/* 0x2f02: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_2f0a:
	/* 0x2f0a: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2f10:
	/* 0x2f10: mov    ecx,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_2f16:
	/* 0x2f16: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f1a:
	/* 0x2f1a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f1e:
	/* 0x2f1e: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_2f26:
	/* 0x2f26: je     36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14052ULL;
	}
x86_l_2f2c:
	/* 0x2f2c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f2f:
	/* 0x2f2f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f34:
	/* 0x2f34: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f39:
	/* 0x2f39: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f3d:
	/* 0x2f3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f42:
	/* 0x2f42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f44:
	/* 0x2f44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f46:
	/* 0x2f46: jns    36e4 <generic_sleepable_preload+0x36e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 14052ULL;
	}
x86_l_2f4c:
	/* 0x2f4c: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_2f52:
	/* 0x2f52: jmp    36e2 <generic_sleepable_preload+0x36e2> */
	return 14050ULL;
x86_l_2f57:
	/* 0x2f57: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2f5d:
	/* 0x2f5d: jmp    36e2 <generic_sleepable_preload+0x36e2> */
	return 14050ULL;
x86_l_2f62:
	/* 0x2f62: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2f68:
	/* 0x2f68: jmp    36e2 <generic_sleepable_preload+0x36e2> */
	return 14050ULL;
x86_l_2f6d:
	/* 0x2f6d: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2f73:
	/* 0x2f73: jmp    3120 <generic_sleepable_preload+0x3120> */
	goto x86_l_3120;
x86_l_2f78:
	/* 0x2f78: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2f7e:
	/* 0x2f7e: jmp    31b6 <generic_sleepable_preload+0x31b6> */
	goto x86_l_31b6;
x86_l_2f83:
	/* 0x2f83: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2f89:
	/* 0x2f89: jmp    3249 <generic_sleepable_preload+0x3249> */
	return 12873ULL;
x86_l_2f8e:
	/* 0x2f8e: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2f94:
	/* 0x2f94: jmp    32dc <generic_sleepable_preload+0x32dc> */
	return 13020ULL;
x86_l_2f99:
	/* 0x2f99: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2f9e:
	/* 0x2f9e: jmp    336e <generic_sleepable_preload+0x336e> */
	return 13166ULL;
x86_l_2fa3:
	/* 0x2fa3: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2fa9:
	/* 0x2fa9: jmp    33f8 <generic_sleepable_preload+0x33f8> */
	return 13304ULL;
x86_l_2fae:
	/* 0x2fae: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2fb3:
	/* 0x2fb3: jmp    34b3 <generic_sleepable_preload+0x34b3> */
	return 13491ULL;
x86_l_2fb8:
	/* 0x2fb8: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2fbe:
	/* 0x2fbe: jmp    3564 <generic_sleepable_preload+0x3564> */
	return 13668ULL;
x86_l_2fc3:
	/* 0x2fc3: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2fc9:
	/* 0x2fc9: jmp    3623 <generic_sleepable_preload+0x3623> */
	return 13859ULL;
x86_l_2fce:
	/* 0x2fce: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2fd4:
	/* 0x2fd4: jmp    36e2 <generic_sleepable_preload+0x36e2> */
	return 14050ULL;
x86_l_2fd9:
	/* 0x2fd9: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_2fdf:
	/* 0x2fdf: jmp    3120 <generic_sleepable_preload+0x3120> */
	goto x86_l_3120;
x86_l_2fe4:
	/* 0x2fe4: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2fea:
	/* 0x2fea: jmp    31b6 <generic_sleepable_preload+0x31b6> */
	goto x86_l_31b6;
x86_l_2fef:
	/* 0x2fef: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2ff5:
	/* 0x2ff5: jmp    3249 <generic_sleepable_preload+0x3249> */
	return 12873ULL;
x86_l_2ffa:
	/* 0x2ffa: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3000:
	/* 0x3000: jmp    32dc <generic_sleepable_preload+0x32dc> */
	return 13020ULL;
x86_l_3005:
	/* 0x3005: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_300a:
	/* 0x300a: jmp    336e <generic_sleepable_preload+0x336e> */
	return 13166ULL;
x86_l_300f:
	/* 0x300f: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3015:
	/* 0x3015: jmp    33f8 <generic_sleepable_preload+0x33f8> */
	return 13304ULL;
x86_l_301a:
	/* 0x301a: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_301f:
	/* 0x301f: jmp    34b3 <generic_sleepable_preload+0x34b3> */
	return 13491ULL;
x86_l_3024:
	/* 0x3024: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_302a:
	/* 0x302a: jmp    3564 <generic_sleepable_preload+0x3564> */
	return 13668ULL;
x86_l_302f:
	/* 0x302f: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3035:
	/* 0x3035: jmp    3623 <generic_sleepable_preload+0x3623> */
	return 13859ULL;
x86_l_303a:
	/* 0x303a: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3040:
	/* 0x3040: jmp    36e2 <generic_sleepable_preload+0x36e2> */
	return 14050ULL;
x86_l_3045:
	/* 0x3045: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_304b:
	/* 0x304b: jmp    3120 <generic_sleepable_preload+0x3120> */
	goto x86_l_3120;
x86_l_3050:
	/* 0x3050: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_3056:
	/* 0x3056: jmp    31b6 <generic_sleepable_preload+0x31b6> */
	goto x86_l_31b6;
x86_l_305b:
	/* 0x305b: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_3061:
	/* 0x3061: jmp    3249 <generic_sleepable_preload+0x3249> */
	return 12873ULL;
x86_l_3066:
	/* 0x3066: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_306c:
	/* 0x306c: jmp    32dc <generic_sleepable_preload+0x32dc> */
	return 13020ULL;
x86_l_3071:
	/* 0x3071: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_3076:
	/* 0x3076: jmp    336e <generic_sleepable_preload+0x336e> */
	return 13166ULL;
x86_l_307b:
	/* 0x307b: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_3081:
	/* 0x3081: jmp    33f8 <generic_sleepable_preload+0x33f8> */
	return 13304ULL;
x86_l_3086:
	/* 0x3086: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_308b:
	/* 0x308b: jmp    34b3 <generic_sleepable_preload+0x34b3> */
	return 13491ULL;
x86_l_3090:
	/* 0x3090: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_3096:
	/* 0x3096: jmp    3564 <generic_sleepable_preload+0x3564> */
	return 13668ULL;
x86_l_309b:
	/* 0x309b: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_30a1:
	/* 0x30a1: jmp    3623 <generic_sleepable_preload+0x3623> */
	return 13859ULL;
x86_l_30a6:
	/* 0x30a6: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_30ac:
	/* 0x30ac: jmp    36e2 <generic_sleepable_preload+0x36e2> */
	return 14050ULL;
x86_l_30b1:
	/* 0x30b1: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_30b7:
	/* 0x30b7: jmp    3120 <generic_sleepable_preload+0x3120> */
	goto x86_l_3120;
x86_l_30b9:
	/* 0x30b9: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_30bf:
	/* 0x30bf: jmp    31b6 <generic_sleepable_preload+0x31b6> */
	goto x86_l_31b6;
x86_l_30c4:
	/* 0x30c4: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_30ca:
	/* 0x30ca: jmp    3249 <generic_sleepable_preload+0x3249> */
	return 12873ULL;
x86_l_30cf:
	/* 0x30cf: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_30d5:
	/* 0x30d5: jmp    32dc <generic_sleepable_preload+0x32dc> */
	return 13020ULL;
x86_l_30da:
	/* 0x30da: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_30df:
	/* 0x30df: jmp    336e <generic_sleepable_preload+0x336e> */
	return 13166ULL;
x86_l_30e4:
	/* 0x30e4: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_30ea:
	/* 0x30ea: jmp    33f8 <generic_sleepable_preload+0x33f8> */
	return 13304ULL;
x86_l_30ef:
	/* 0x30ef: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_30f4:
	/* 0x30f4: jmp    34b3 <generic_sleepable_preload+0x34b3> */
	return 13491ULL;
x86_l_30f9:
	/* 0x30f9: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_30ff:
	/* 0x30ff: jmp    3564 <generic_sleepable_preload+0x3564> */
	return 13668ULL;
x86_l_3104:
	/* 0x3104: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_310a:
	/* 0x310a: jmp    3623 <generic_sleepable_preload+0x3623> */
	return 13859ULL;
x86_l_310f:
	/* 0x310f: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_3115:
	/* 0x3115: jmp    36e2 <generic_sleepable_preload+0x36e2> */
	return 14050ULL;
x86_l_311a:
	/* 0x311a: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_3120:
	/* 0x3120: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3122:
	/* 0x3122: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3126:
	/* 0x3126: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_312b:
	/* 0x312b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3130:
	/* 0x3130: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3135:
	/* 0x3135: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_313a:
	/* 0x313a: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_313d:
	/* 0x313d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_313f:
	/* 0x313f: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3143:
	/* 0x3143: jne    e6 <generic_sleepable_preload+0xe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 230ULL;
	}
x86_l_3149:
	/* 0x3149: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_314e:
	/* 0x314e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3153:
	/* 0x3153: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3158:
	/* 0x3158: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_315a:
	/* 0x315a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_315f:
	/* 0x315f: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3166:
	/* 0x3166: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_316d:
	/* 0x316d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3170:
	/* 0x3170: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3175:
	/* 0x3175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3177:
	/* 0x3177: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_317a:
	/* 0x317a: je     e6 <generic_sleepable_preload+0xe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 230ULL;
	}
x86_l_3180:
	/* 0x3180: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3183:
	/* 0x3183: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_3186:
	/* 0x3186: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_3189:
	/* 0x3189: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3190:
	/* 0x3190: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3192:
	/* 0x3192: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3197:
	/* 0x3197: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_319c:
	/* 0x319c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_319f:
	/* 0x319f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_31a2:
	/* 0x31a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31a4:
	/* 0x31a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a6:
	/* 0x31a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31ab:
	/* 0x31ab: jmp    3468 <generic_sleepable_preload+0x3468> */
	return 13416ULL;
x86_l_31b0:
	/* 0x31b0: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_31b6:
	/* 0x31b6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31b8:
	/* 0x31b8: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31bc:
	/* 0x31bc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c1:
	/* 0x31c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31c6:
	/* 0x31c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31cb:
	/* 0x31cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d0:
	/* 0x31d0: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_31d3:
	/* 0x31d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d5:
	/* 0x31d5: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_31d9:
	/* 0x31d9: jne    f4 <generic_sleepable_preload+0xf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 244ULL;
	}
x86_l_31df:
	/* 0x31df: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e4:
	/* 0x31e4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31e9:
	/* 0x31e9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_31ee:
	/* 0x31ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f0:
	/* 0x31f0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31f5:
	/* 0x31f5: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31fc:
	/* 0x31fc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3203:
	/* 0x3203: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3206:
	/* 0x3206: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_320b:
	/* 0x320b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320d:
	/* 0x320d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 12816ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12816ULL: goto x86_l_3210;
	case 12822ULL: goto x86_l_3216;
	case 12825ULL: goto x86_l_3219;
	case 12832ULL: goto x86_l_3220;
	case 12834ULL: goto x86_l_3222;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12850ULL: goto x86_l_3232;
	case 12853ULL: goto x86_l_3235;
	case 12855ULL: goto x86_l_3237;
	case 12857ULL: goto x86_l_3239;
	case 12862ULL: goto x86_l_323e;
	case 12867ULL: goto x86_l_3243;
	case 12873ULL: goto x86_l_3249;
	case 12875ULL: goto x86_l_324b;
	case 12879ULL: goto x86_l_324f;
	case 12884ULL: goto x86_l_3254;
	case 12889ULL: goto x86_l_3259;
	case 12894ULL: goto x86_l_325e;
	case 12899ULL: goto x86_l_3263;
	case 12902ULL: goto x86_l_3266;
	case 12904ULL: goto x86_l_3268;
	case 12908ULL: goto x86_l_326c;
	case 12914ULL: goto x86_l_3272;
	case 12919ULL: goto x86_l_3277;
	case 12924ULL: goto x86_l_327c;
	case 12929ULL: goto x86_l_3281;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12943ULL: goto x86_l_328f;
	case 12950ULL: goto x86_l_3296;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12960ULL: goto x86_l_32a0;
	case 12963ULL: goto x86_l_32a3;
	case 12969ULL: goto x86_l_32a9;
	case 12972ULL: goto x86_l_32ac;
	case 12979ULL: goto x86_l_32b3;
	case 12981ULL: goto x86_l_32b5;
	case 12984ULL: goto x86_l_32b8;
	case 12989ULL: goto x86_l_32bd;
	case 12994ULL: goto x86_l_32c2;
	case 12997ULL: goto x86_l_32c5;
	case 13000ULL: goto x86_l_32c8;
	case 13002ULL: goto x86_l_32ca;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13020ULL: goto x86_l_32dc;
	case 13022ULL: goto x86_l_32de;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13049ULL: goto x86_l_32f9;
	case 13051ULL: goto x86_l_32fb;
	case 13055ULL: goto x86_l_32ff;
	case 13061ULL: goto x86_l_3305;
	case 13066ULL: goto x86_l_330a;
	case 13071ULL: goto x86_l_330f;
	case 13076ULL: goto x86_l_3314;
	case 13078ULL: goto x86_l_3316;
	case 13083ULL: goto x86_l_331b;
	case 13090ULL: goto x86_l_3322;
	case 13097ULL: goto x86_l_3329;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13107ULL: goto x86_l_3333;
	case 13110ULL: goto x86_l_3336;
	case 13116ULL: goto x86_l_333c;
	case 13119ULL: goto x86_l_333f;
	case 13126ULL: goto x86_l_3346;
	case 13128ULL: goto x86_l_3348;
	case 13131ULL: goto x86_l_334b;
	case 13136ULL: goto x86_l_3350;
	case 13141ULL: goto x86_l_3355;
	case 13144ULL: goto x86_l_3358;
	case 13147ULL: goto x86_l_335b;
	case 13149ULL: goto x86_l_335d;
	case 13151ULL: goto x86_l_335f;
	case 13156ULL: goto x86_l_3364;
	case 13161ULL: goto x86_l_3369;
	case 13166ULL: goto x86_l_336e;
	case 13169ULL: goto x86_l_3371;
	case 13172ULL: goto x86_l_3374;
	case 13177ULL: goto x86_l_3379;
	case 13182ULL: goto x86_l_337e;
	case 13187ULL: goto x86_l_3383;
	case 13192ULL: goto x86_l_3388;
	case 13195ULL: goto x86_l_338b;
	case 13197ULL: goto x86_l_338d;
	case 13200ULL: goto x86_l_3390;
	case 13206ULL: goto x86_l_3396;
	case 13211ULL: goto x86_l_339b;
	case 13216ULL: goto x86_l_33a0;
	case 13218ULL: goto x86_l_33a2;
	case 13223ULL: goto x86_l_33a7;
	case 13230ULL: goto x86_l_33ae;
	case 13237ULL: goto x86_l_33b5;
	case 13240ULL: goto x86_l_33b8;
	case 13245ULL: goto x86_l_33bd;
	case 13247ULL: goto x86_l_33bf;
	case 13250ULL: goto x86_l_33c2;
	case 13256ULL: goto x86_l_33c8;
	case 13259ULL: goto x86_l_33cb;
	case 13266ULL: goto x86_l_33d2;
	case 13268ULL: goto x86_l_33d4;
	case 13273ULL: goto x86_l_33d9;
	case 13278ULL: goto x86_l_33de;
	case 13281ULL: goto x86_l_33e1;
	case 13284ULL: goto x86_l_33e4;
	case 13286ULL: goto x86_l_33e6;
	case 13288ULL: goto x86_l_33e8;
	case 13293ULL: goto x86_l_33ed;
	case 13298ULL: goto x86_l_33f2;
	case 13304ULL: goto x86_l_33f8;
	case 13306ULL: goto x86_l_33fa;
	case 13310ULL: goto x86_l_33fe;
	case 13316ULL: goto x86_l_3404;
	case 13320ULL: goto x86_l_3408;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13332ULL: goto x86_l_3414;
	case 13337ULL: goto x86_l_3419;
	case 13345ULL: goto x86_l_3421;
	case 13352ULL: goto x86_l_3428;
	case 13357ULL: goto x86_l_342d;
	case 13362ULL: goto x86_l_3432;
	case 13364ULL: goto x86_l_3434;
	case 13367ULL: goto x86_l_3437;
	case 13373ULL: goto x86_l_343d;
	case 13376ULL: goto x86_l_3440;
	case 13379ULL: goto x86_l_3443;
	case 13382ULL: goto x86_l_3446;
	case 13389ULL: goto x86_l_344d;
	case 13391ULL: goto x86_l_344f;
	case 13396ULL: goto x86_l_3454;
	case 13401ULL: goto x86_l_3459;
	case 13404ULL: goto x86_l_345c;
	case 13407ULL: goto x86_l_345f;
	case 13409ULL: goto x86_l_3461;
	case 13411ULL: goto x86_l_3463;
	case 13416ULL: goto x86_l_3468;
	case 13419ULL: goto x86_l_346b;
	case 13422ULL: goto x86_l_346e;
	case 13424ULL: goto x86_l_3470;
	case 13427ULL: goto x86_l_3473;
	case 13433ULL: goto x86_l_3479;
	case 13436ULL: goto x86_l_347c;
	case 13438ULL: goto x86_l_347e;
	case 13441ULL: goto x86_l_3481;
	case 13445ULL: goto x86_l_3485;
	case 13450ULL: goto x86_l_348a;
	case 13455ULL: goto x86_l_348f;
	case 13457ULL: goto x86_l_3491;
	case 13460ULL: goto x86_l_3494;
	case 13465ULL: goto x86_l_3499;
	case 13467ULL: goto x86_l_349b;
	case 13470ULL: goto x86_l_349e;
	case 13472ULL: goto x86_l_34a0;
	case 13474ULL: goto x86_l_34a2;
	case 13479ULL: goto x86_l_34a7;
	case 13481ULL: goto x86_l_34a9;
	case 13486ULL: goto x86_l_34ae;
	case 13491ULL: goto x86_l_34b3;
	case 13494ULL: goto x86_l_34b6;
	case 13498ULL: goto x86_l_34ba;
	case 13504ULL: goto x86_l_34c0;
	case 13508ULL: goto x86_l_34c4;
	case 13513ULL: goto x86_l_34c9;
	case 13515ULL: goto x86_l_34cb;
	case 13520ULL: goto x86_l_34d0;
	case 13528ULL: goto x86_l_34d8;
	case 13535ULL: goto x86_l_34df;
	case 13540ULL: goto x86_l_34e4;
	case 13545ULL: goto x86_l_34e9;
	case 13547ULL: goto x86_l_34eb;
	case 13550ULL: goto x86_l_34ee;
	case 13556ULL: goto x86_l_34f4;
	case 13559ULL: goto x86_l_34f7;
	case 13566ULL: goto x86_l_34fe;
	case 13568ULL: goto x86_l_3500;
	case 13573ULL: goto x86_l_3505;
	case 13578ULL: goto x86_l_350a;
	case 13581ULL: goto x86_l_350d;
	case 13584ULL: goto x86_l_3510;
	case 13586ULL: goto x86_l_3512;
	case 13588ULL: goto x86_l_3514;
	case 13593ULL: goto x86_l_3519;
	case 13596ULL: goto x86_l_351c;
	case 13599ULL: goto x86_l_351f;
	case 13601ULL: goto x86_l_3521;
	case 13604ULL: goto x86_l_3524;
	case 13610ULL: goto x86_l_352a;
	case 13613ULL: goto x86_l_352d;
	case 13615ULL: goto x86_l_352f;
	case 13618ULL: goto x86_l_3532;
	case 13622ULL: goto x86_l_3536;
	case 13627ULL: goto x86_l_353b;
	case 13630ULL: goto x86_l_353e;
	case 13632ULL: goto x86_l_3540;
	case 13635ULL: goto x86_l_3543;
	case 13640ULL: goto x86_l_3548;
	case 13642ULL: goto x86_l_354a;
	case 13645ULL: goto x86_l_354d;
	case 13647ULL: goto x86_l_354f;
	case 13652ULL: goto x86_l_3554;
	case 13655ULL: goto x86_l_3557;
	case 13657ULL: goto x86_l_3559;
	case 13662ULL: goto x86_l_355e;
	case 13668ULL: goto x86_l_3564;
	case 13670ULL: goto x86_l_3566;
	case 13674ULL: goto x86_l_356a;
	case 13680ULL: goto x86_l_3570;
	case 13684ULL: goto x86_l_3574;
	case 13689ULL: goto x86_l_3579;
	case 13694ULL: goto x86_l_357e;
	case 13696ULL: goto x86_l_3580;
	case 13701ULL: goto x86_l_3585;
	case 13709ULL: goto x86_l_358d;
	case 13716ULL: goto x86_l_3594;
	case 13721ULL: goto x86_l_3599;
	case 13726ULL: goto x86_l_359e;
	case 13728ULL: goto x86_l_35a0;
	case 13731ULL: goto x86_l_35a3;
	case 13737ULL: goto x86_l_35a9;
	case 13740ULL: goto x86_l_35ac;
	case 13747ULL: goto x86_l_35b3;
	case 13749ULL: goto x86_l_35b5;
	case 13752ULL: goto x86_l_35b8;
	case 13757ULL: goto x86_l_35bd;
	case 13762ULL: goto x86_l_35c2;
	case 13765ULL: goto x86_l_35c5;
	case 13768ULL: goto x86_l_35c8;
	case 13770ULL: goto x86_l_35ca;
	case 13772ULL: goto x86_l_35cc;
	case 13777ULL: goto x86_l_35d1;
	case 13780ULL: goto x86_l_35d4;
	case 13783ULL: goto x86_l_35d7;
	case 13786ULL: goto x86_l_35da;
	case 13788ULL: goto x86_l_35dc;
	case 13791ULL: goto x86_l_35df;
	case 13797ULL: goto x86_l_35e5;
	case 13800ULL: goto x86_l_35e8;
	case 13802ULL: goto x86_l_35ea;
	case 13805ULL: goto x86_l_35ed;
	case 13809ULL: goto x86_l_35f1;
	case 13814ULL: goto x86_l_35f6;
	case 13819ULL: goto x86_l_35fb;
	case 13821ULL: goto x86_l_35fd;
	case 13824ULL: goto x86_l_3600;
	case 13829ULL: goto x86_l_3605;
	case 13831ULL: goto x86_l_3607;
	case 13834ULL: goto x86_l_360a;
	case 13836ULL: goto x86_l_360c;
	case 13841ULL: goto x86_l_3611;
	case 13845ULL: goto x86_l_3615;
	case 13848ULL: goto x86_l_3618;
	case 13853ULL: goto x86_l_361d;
	case 13859ULL: goto x86_l_3623;
	case 13861ULL: goto x86_l_3625;
	case 13865ULL: goto x86_l_3629;
	case 13871ULL: goto x86_l_362f;
	case 13875ULL: goto x86_l_3633;
	case 13880ULL: goto x86_l_3638;
	case 13885ULL: goto x86_l_363d;
	case 13887ULL: goto x86_l_363f;
	case 13892ULL: goto x86_l_3644;
	case 13900ULL: goto x86_l_364c;
	case 13907ULL: goto x86_l_3653;
	case 13912ULL: goto x86_l_3658;
	case 13917ULL: goto x86_l_365d;
	case 13919ULL: goto x86_l_365f;
	case 13922ULL: goto x86_l_3662;
	case 13928ULL: goto x86_l_3668;
	case 13931ULL: goto x86_l_366b;
	case 13938ULL: goto x86_l_3672;
	case 13940ULL: goto x86_l_3674;
	case 13943ULL: goto x86_l_3677;
	case 13948ULL: goto x86_l_367c;
	case 13953ULL: goto x86_l_3681;
	case 13956ULL: goto x86_l_3684;
	case 13959ULL: goto x86_l_3687;
	case 13961ULL: goto x86_l_3689;
	case 13963ULL: goto x86_l_368b;
	case 13968ULL: goto x86_l_3690;
	case 13971ULL: goto x86_l_3693;
	case 13974ULL: goto x86_l_3696;
	case 13977ULL: goto x86_l_3699;
	case 13979ULL: goto x86_l_369b;
	case 13982ULL: goto x86_l_369e;
	case 13988ULL: goto x86_l_36a4;
	case 13991ULL: goto x86_l_36a7;
	case 13993ULL: goto x86_l_36a9;
	case 13996ULL: goto x86_l_36ac;
	case 14000ULL: goto x86_l_36b0;
	case 14005ULL: goto x86_l_36b5;
	case 14010ULL: goto x86_l_36ba;
	case 14012ULL: goto x86_l_36bc;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14022ULL: goto x86_l_36c6;
	case 14025ULL: goto x86_l_36c9;
	case 14027ULL: goto x86_l_36cb;
	case 14032ULL: goto x86_l_36d0;
	case 14036ULL: goto x86_l_36d4;
	case 14039ULL: goto x86_l_36d7;
	case 14044ULL: goto x86_l_36dc;
	case 14050ULL: goto x86_l_36e2;
	case 14052ULL: goto x86_l_36e4;
	case 14056ULL: goto x86_l_36e8;
	case 14062ULL: goto x86_l_36ee;
	case 14066ULL: goto x86_l_36f2;
	case 14071ULL: goto x86_l_36f7;
	case 14076ULL: goto x86_l_36fc;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14091ULL: goto x86_l_370b;
	case 14098ULL: goto x86_l_3712;
	case 14103ULL: goto x86_l_3717;
	case 14108ULL: goto x86_l_371c;
	case 14110ULL: goto x86_l_371e;
	case 14113ULL: goto x86_l_3721;
	case 14119ULL: goto x86_l_3727;
	case 14122ULL: goto x86_l_372a;
	case 14129ULL: goto x86_l_3731;
	case 14131ULL: goto x86_l_3733;
	case 14134ULL: goto x86_l_3736;
	case 14139ULL: goto x86_l_373b;
	case 14144ULL: goto x86_l_3740;
	case 14147ULL: goto x86_l_3743;
	case 14150ULL: goto x86_l_3746;
	case 14152ULL: goto x86_l_3748;
	case 14154ULL: goto x86_l_374a;
	case 14159ULL: goto x86_l_374f;
	case 14162ULL: goto x86_l_3752;
	case 14165ULL: goto x86_l_3755;
	case 14168ULL: goto x86_l_3758;
	case 14170ULL: goto x86_l_375a;
	case 14173ULL: goto x86_l_375d;
	case 14179ULL: goto x86_l_3763;
	case 14182ULL: goto x86_l_3766;
	case 14184ULL: goto x86_l_3768;
	case 14187ULL: goto x86_l_376b;
	case 14191ULL: goto x86_l_376f;
	case 14196ULL: goto x86_l_3774;
	case 14201ULL: goto x86_l_3779;
	case 14203ULL: goto x86_l_377b;
	case 14206ULL: goto x86_l_377e;
	case 14211ULL: goto x86_l_3783;
	case 14213ULL: goto x86_l_3785;
	case 14216ULL: goto x86_l_3788;
	case 14218ULL: goto x86_l_378a;
	case 14223ULL: goto x86_l_378f;
	case 14227ULL: goto x86_l_3793;
	case 14230ULL: goto x86_l_3796;
	case 14235ULL: goto x86_l_379b;
	case 14237ULL: goto x86_l_379d;
	case 14243ULL: goto x86_l_37a3;
	case 14248ULL: goto x86_l_37a8;
	case 14250ULL: goto x86_l_37aa;
	case 14256ULL: goto x86_l_37b0;
	case 14261ULL: goto x86_l_37b5;
	case 14263ULL: goto x86_l_37b7;
	case 14269ULL: goto x86_l_37bd;
	case 14274ULL: goto x86_l_37c2;
	case 14276ULL: goto x86_l_37c4;
	case 14282ULL: goto x86_l_37ca;
	case 14287ULL: goto x86_l_37cf;
	case 14290ULL: goto x86_l_37d2;
	case 14295ULL: goto x86_l_37d7;
	case 14300ULL: goto x86_l_37dc;
	case 14302ULL: goto x86_l_37de;
	case 14308ULL: goto x86_l_37e4;
	case 14312ULL: goto x86_l_37e8;
	case 14318ULL: goto x86_l_37ee;
	case 14323ULL: goto x86_l_37f3;
	case 14326ULL: goto x86_l_37f6;
	case 14331ULL: goto x86_l_37fb;
	case 14335ULL: goto x86_l_37ff;
	case 14341ULL: goto x86_l_3805;
	case 14346ULL: goto x86_l_380a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3210:
	/* 0x3210: je     f4 <generic_sleepable_preload+0xf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 244ULL;
	}
x86_l_3216:
	/* 0x3216: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3219:
	/* 0x3219: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3220:
	/* 0x3220: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3222:
	/* 0x3222: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_3225:
	/* 0x3225: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_322a:
	/* 0x322a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_322f:
	/* 0x322f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3232:
	/* 0x3232: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3235:
	/* 0x3235: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3237:
	/* 0x3237: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3239:
	/* 0x3239: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_323e:
	/* 0x323e: jmp    35d1 <generic_sleepable_preload+0x35d1> */
	goto x86_l_35d1;
x86_l_3243:
	/* 0x3243: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_3249:
	/* 0x3249: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_324b:
	/* 0x324b: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_324f:
	/* 0x324f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3254:
	/* 0x3254: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3259:
	/* 0x3259: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_325e:
	/* 0x325e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3263:
	/* 0x3263: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3266:
	/* 0x3266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3268:
	/* 0x3268: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_326c:
	/* 0x326c: jne    102 <generic_sleepable_preload+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 258ULL;
	}
x86_l_3272:
	/* 0x3272: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3277:
	/* 0x3277: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_327c:
	/* 0x327c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3281:
	/* 0x3281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3283:
	/* 0x3283: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3288:
	/* 0x3288: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_328f:
	/* 0x328f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3296:
	/* 0x3296: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3299:
	/* 0x3299: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_329e:
	/* 0x329e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a0:
	/* 0x32a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32a3:
	/* 0x32a3: je     102 <generic_sleepable_preload+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 258ULL;
	}
x86_l_32a9:
	/* 0x32a9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_32ac:
	/* 0x32ac: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_32b3:
	/* 0x32b3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32b5:
	/* 0x32b5: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_32b8:
	/* 0x32b8: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32bd:
	/* 0x32bd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32c2:
	/* 0x32c2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32c5:
	/* 0x32c5: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_32c8:
	/* 0x32c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32ca:
	/* 0x32ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32cc:
	/* 0x32cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32d1:
	/* 0x32d1: jmp    3690 <generic_sleepable_preload+0x3690> */
	goto x86_l_3690;
x86_l_32d6:
	/* 0x32d6: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_32dc:
	/* 0x32dc: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32de:
	/* 0x32de: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32e2:
	/* 0x32e2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32e7:
	/* 0x32e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32ec:
	/* 0x32ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32f1:
	/* 0x32f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32f6:
	/* 0x32f6: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_32f9:
	/* 0x32f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32fb:
	/* 0x32fb: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_32ff:
	/* 0x32ff: jne    110 <generic_sleepable_preload+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_3305:
	/* 0x3305: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_330a:
	/* 0x330a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_330f:
	/* 0x330f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3314:
	/* 0x3314: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3316:
	/* 0x3316: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_331b:
	/* 0x331b: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3322:
	/* 0x3322: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3329:
	/* 0x3329: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_332c:
	/* 0x332c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3331:
	/* 0x3331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3333:
	/* 0x3333: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3336:
	/* 0x3336: je     110 <generic_sleepable_preload+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 272ULL;
	}
x86_l_333c:
	/* 0x333c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_333f:
	/* 0x333f: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3346:
	/* 0x3346: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3348:
	/* 0x3348: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_334b:
	/* 0x334b: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3350:
	/* 0x3350: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3355:
	/* 0x3355: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3358:
	/* 0x3358: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_335b:
	/* 0x335b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_335d:
	/* 0x335d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335f:
	/* 0x335f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3364:
	/* 0x3364: jmp    374f <generic_sleepable_preload+0x374f> */
	goto x86_l_374f;
x86_l_3369:
	/* 0x3369: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_336e:
	/* 0x336e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3371:
	/* 0x3371: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3374:
	/* 0x3374: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3379:
	/* 0x3379: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_337e:
	/* 0x337e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3383:
	/* 0x3383: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3388:
	/* 0x3388: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_338b:
	/* 0x338b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338d:
	/* 0x338d: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3390:
	/* 0x3390: jne    11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 286ULL;
	}
x86_l_3396:
	/* 0x3396: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_339b:
	/* 0x339b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_33a0:
	/* 0x33a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a2:
	/* 0x33a2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33a7:
	/* 0x33a7: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33ae:
	/* 0x33ae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_33b5:
	/* 0x33b5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_33b8:
	/* 0x33b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33bd:
	/* 0x33bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33bf:
	/* 0x33bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33c2:
	/* 0x33c2: je     11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 286ULL;
	}
x86_l_33c8:
	/* 0x33c8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_33cb:
	/* 0x33cb: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_33d2:
	/* 0x33d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33d4:
	/* 0x33d4: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d9:
	/* 0x33d9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_33de:
	/* 0x33de: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_33e1:
	/* 0x33e1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_33e4:
	/* 0x33e4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33e6:
	/* 0x33e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e8:
	/* 0x33e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33ed:
	/* 0x33ed: jmp    3519 <generic_sleepable_preload+0x3519> */
	goto x86_l_3519;
x86_l_33f2:
	/* 0x33f2: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_33f8:
	/* 0x33f8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33fa:
	/* 0x33fa: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_33fe:
	/* 0x33fe: jne    e6 <generic_sleepable_preload+0xe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 230ULL;
	}
x86_l_3404:
	/* 0x3404: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3408:
	/* 0x3408: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_340d:
	/* 0x340d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3412:
	/* 0x3412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3414:
	/* 0x3414: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3419:
	/* 0x3419: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3421:
	/* 0x3421: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3428:
	/* 0x3428: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_342d:
	/* 0x342d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3432:
	/* 0x3432: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3434:
	/* 0x3434: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3437:
	/* 0x3437: je     e6 <generic_sleepable_preload+0xe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 230ULL;
	}
x86_l_343d:
	/* 0x343d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3440:
	/* 0x3440: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_3443:
	/* 0x3443: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_3446:
	/* 0x3446: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_344d:
	/* 0x344d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_344f:
	/* 0x344f: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3454:
	/* 0x3454: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3459:
	/* 0x3459: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_345c:
	/* 0x345c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_345f:
	/* 0x345f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3461:
	/* 0x3461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3463:
	/* 0x3463: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3468:
	/* 0x3468: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_346b:
	/* 0x346b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_346e:
	/* 0x346e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3470:
	/* 0x3470: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3473:
	/* 0x3473: je     e6 <generic_sleepable_preload+0xe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 230ULL;
	}
x86_l_3479:
	/* 0x3479: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_347c:
	/* 0x347c: je     34a7 <generic_sleepable_preload+0x34a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34a7;
	}
x86_l_347e:
	/* 0x347e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3481:
	/* 0x3481: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3485:
	/* 0x3485: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_348a:
	/* 0x348a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_348f:
	/* 0x348f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3491:
	/* 0x3491: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3494:
	/* 0x3494: call   3499 <generic_sleepable_preload+0x3499> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3499:
	/* 0x3499: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_349b:
	/* 0x349b: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_349e:
	/* 0x349e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_34a0:
	/* 0x34a0: jns    34a7 <generic_sleepable_preload+0x34a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_34a7;
	}
x86_l_34a2:
	/* 0x34a2: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_34a7:
	/* 0x34a7: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34a9:
	/* 0x34a9: jmp    e6 <generic_sleepable_preload+0xe6> */
	return 230ULL;
x86_l_34ae:
	/* 0x34ae: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_34b3:
	/* 0x34b3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34b6:
	/* 0x34b6: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_34ba:
	/* 0x34ba: jne    11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 286ULL;
	}
x86_l_34c0:
	/* 0x34c0: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c4:
	/* 0x34c4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_34c9:
	/* 0x34c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34cb:
	/* 0x34cb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d0:
	/* 0x34d0: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_34d8:
	/* 0x34d8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_34df:
	/* 0x34df: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34e4:
	/* 0x34e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34e9:
	/* 0x34e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34eb:
	/* 0x34eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34ee:
	/* 0x34ee: je     11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 286ULL;
	}
x86_l_34f4:
	/* 0x34f4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_34f7:
	/* 0x34f7: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_34fe:
	/* 0x34fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3500:
	/* 0x3500: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3505:
	/* 0x3505: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_350a:
	/* 0x350a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_350d:
	/* 0x350d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3510:
	/* 0x3510: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3512:
	/* 0x3512: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3514:
	/* 0x3514: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3519:
	/* 0x3519: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_351c:
	/* 0x351c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_351f:
	/* 0x351f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3521:
	/* 0x3521: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3524:
	/* 0x3524: je     11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 286ULL;
	}
x86_l_352a:
	/* 0x352a: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_352d:
	/* 0x352d: je     3557 <generic_sleepable_preload+0x3557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3557;
	}
x86_l_352f:
	/* 0x352f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3532:
	/* 0x3532: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3536:
	/* 0x3536: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_353b:
	/* 0x353b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_353e:
	/* 0x353e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3540:
	/* 0x3540: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3543:
	/* 0x3543: call   3548 <generic_sleepable_preload+0x3548> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3548:
	/* 0x3548: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_354a:
	/* 0x354a: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_354d:
	/* 0x354d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_354f:
	/* 0x354f: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3554:
	/* 0x3554: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3557:
	/* 0x3557: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3559:
	/* 0x3559: jmp    11e <generic_sleepable_preload+0x11e> */
	return 286ULL;
x86_l_355e:
	/* 0x355e: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_3564:
	/* 0x3564: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3566:
	/* 0x3566: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_356a:
	/* 0x356a: jne    f4 <generic_sleepable_preload+0xf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 244ULL;
	}
x86_l_3570:
	/* 0x3570: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3574:
	/* 0x3574: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3579:
	/* 0x3579: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_357e:
	/* 0x357e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3580:
	/* 0x3580: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3585:
	/* 0x3585: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_358d:
	/* 0x358d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3594:
	/* 0x3594: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3599:
	/* 0x3599: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_359e:
	/* 0x359e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a0:
	/* 0x35a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35a3:
	/* 0x35a3: je     f4 <generic_sleepable_preload+0xf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 244ULL;
	}
x86_l_35a9:
	/* 0x35a9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_35ac:
	/* 0x35ac: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_35b3:
	/* 0x35b3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35b5:
	/* 0x35b5: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_35b8:
	/* 0x35b8: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35bd:
	/* 0x35bd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35c2:
	/* 0x35c2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_35c5:
	/* 0x35c5: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_35c8:
	/* 0x35c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35ca:
	/* 0x35ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35cc:
	/* 0x35cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35d1:
	/* 0x35d1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_35d4:
	/* 0x35d4: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_35d7:
	/* 0x35d7: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_35da:
	/* 0x35da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35dc:
	/* 0x35dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35df:
	/* 0x35df: je     f4 <generic_sleepable_preload+0xf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 244ULL;
	}
x86_l_35e5:
	/* 0x35e5: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_35e8:
	/* 0x35e8: je     3615 <generic_sleepable_preload+0x3615> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3615;
	}
x86_l_35ea:
	/* 0x35ea: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_35ed:
	/* 0x35ed: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_35f1:
	/* 0x35f1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35f6:
	/* 0x35f6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35fb:
	/* 0x35fb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35fd:
	/* 0x35fd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3600:
	/* 0x3600: call   3605 <generic_sleepable_preload+0x3605> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3605:
	/* 0x3605: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3607:
	/* 0x3607: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_360a:
	/* 0x360a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_360c:
	/* 0x360c: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3611:
	/* 0x3611: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3615:
	/* 0x3615: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3618:
	/* 0x3618: jmp    f4 <generic_sleepable_preload+0xf4> */
	return 244ULL;
x86_l_361d:
	/* 0x361d: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_3623:
	/* 0x3623: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3625:
	/* 0x3625: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3629:
	/* 0x3629: jne    102 <generic_sleepable_preload+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 258ULL;
	}
x86_l_362f:
	/* 0x362f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3633:
	/* 0x3633: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3638:
	/* 0x3638: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_363d:
	/* 0x363d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_363f:
	/* 0x363f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3644:
	/* 0x3644: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_364c:
	/* 0x364c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3653:
	/* 0x3653: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3658:
	/* 0x3658: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_365d:
	/* 0x365d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_365f:
	/* 0x365f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3662:
	/* 0x3662: je     102 <generic_sleepable_preload+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 258ULL;
	}
x86_l_3668:
	/* 0x3668: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_366b:
	/* 0x366b: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3672:
	/* 0x3672: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3674:
	/* 0x3674: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_3677:
	/* 0x3677: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_367c:
	/* 0x367c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3681:
	/* 0x3681: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3684:
	/* 0x3684: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3687:
	/* 0x3687: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3689:
	/* 0x3689: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_368b:
	/* 0x368b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3690:
	/* 0x3690: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3693:
	/* 0x3693: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3696:
	/* 0x3696: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_3699:
	/* 0x3699: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_369b:
	/* 0x369b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_369e:
	/* 0x369e: je     102 <generic_sleepable_preload+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 258ULL;
	}
x86_l_36a4:
	/* 0x36a4: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_36a7:
	/* 0x36a7: je     36d4 <generic_sleepable_preload+0x36d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36d4;
	}
x86_l_36a9:
	/* 0x36a9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_36ac:
	/* 0x36ac: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_36b0:
	/* 0x36b0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36b5:
	/* 0x36b5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36ba:
	/* 0x36ba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36bc:
	/* 0x36bc: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_36bf:
	/* 0x36bf: call   36c4 <generic_sleepable_preload+0x36c4> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_36c4:
	/* 0x36c4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_36c6:
	/* 0x36c6: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_36c9:
	/* 0x36c9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_36cb:
	/* 0x36cb: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_36d0:
	/* 0x36d0: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_36d4:
	/* 0x36d4: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36d7:
	/* 0x36d7: jmp    102 <generic_sleepable_preload+0x102> */
	return 258ULL;
x86_l_36dc:
	/* 0x36dc: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_36e2:
	/* 0x36e2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36e4:
	/* 0x36e4: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_36e8:
	/* 0x36e8: jne    110 <generic_sleepable_preload+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_36ee:
	/* 0x36ee: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36f2:
	/* 0x36f2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36f7:
	/* 0x36f7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_36fc:
	/* 0x36fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36fe:
	/* 0x36fe: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3703:
	/* 0x3703: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_370b:
	/* 0x370b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3712:
	/* 0x3712: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3717:
	/* 0x3717: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_371c:
	/* 0x371c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_371e:
	/* 0x371e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3721:
	/* 0x3721: je     110 <generic_sleepable_preload+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 272ULL;
	}
x86_l_3727:
	/* 0x3727: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_372a:
	/* 0x372a: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3731:
	/* 0x3731: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3733:
	/* 0x3733: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_3736:
	/* 0x3736: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_373b:
	/* 0x373b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3740:
	/* 0x3740: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3743:
	/* 0x3743: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3746:
	/* 0x3746: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3748:
	/* 0x3748: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_374a:
	/* 0x374a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_374f:
	/* 0x374f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3752:
	/* 0x3752: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3755:
	/* 0x3755: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_3758:
	/* 0x3758: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_375a:
	/* 0x375a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_375d:
	/* 0x375d: je     110 <generic_sleepable_preload+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 272ULL;
	}
x86_l_3763:
	/* 0x3763: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_3766:
	/* 0x3766: je     3793 <generic_sleepable_preload+0x3793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3793;
	}
x86_l_3768:
	/* 0x3768: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_376b:
	/* 0x376b: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_376f:
	/* 0x376f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3774:
	/* 0x3774: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3779:
	/* 0x3779: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_377b:
	/* 0x377b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_377e:
	/* 0x377e: call   3783 <generic_sleepable_preload+0x3783> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3783:
	/* 0x3783: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3785:
	/* 0x3785: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_3788:
	/* 0x3788: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_378a:
	/* 0x378a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_378f:
	/* 0x378f: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3793:
	/* 0x3793: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3796:
	/* 0x3796: jmp    110 <generic_sleepable_preload+0x110> */
	return 272ULL;
x86_l_379b:
	/* 0x379b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_379d:
	/* 0x379d: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_37a3:
	/* 0x37a3: jmp    3122 <generic_sleepable_preload+0x3122> */
	return 12578ULL;
x86_l_37a8:
	/* 0x37a8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37aa:
	/* 0x37aa: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_37b0:
	/* 0x37b0: jmp    31b8 <generic_sleepable_preload+0x31b8> */
	return 12728ULL;
x86_l_37b5:
	/* 0x37b5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37b7:
	/* 0x37b7: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_37bd:
	/* 0x37bd: jmp    324b <generic_sleepable_preload+0x324b> */
	goto x86_l_324b;
x86_l_37c2:
	/* 0x37c2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37c4:
	/* 0x37c4: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_37ca:
	/* 0x37ca: jmp    32de <generic_sleepable_preload+0x32de> */
	goto x86_l_32de;
x86_l_37cf:
	/* 0x37cf: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37d2:
	/* 0x37d2: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_37d7:
	/* 0x37d7: jmp    3371 <generic_sleepable_preload+0x3371> */
	goto x86_l_3371;
x86_l_37dc:
	/* 0x37dc: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37de:
	/* 0x37de: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_37e4:
	/* 0x37e4: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_37e8:
	/* 0x37e8: jne    e6 <generic_sleepable_preload+0xe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 230ULL;
	}
x86_l_37ee:
	/* 0x37ee: jmp    3404 <generic_sleepable_preload+0x3404> */
	goto x86_l_3404;
x86_l_37f3:
	/* 0x37f3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37f6:
	/* 0x37f6: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_37fb:
	/* 0x37fb: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_37ff:
	/* 0x37ff: jne    11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 286ULL;
	}
x86_l_3805:
	/* 0x3805: jmp    34c0 <generic_sleepable_preload+0x34c0> */
	goto x86_l_34c0;
x86_l_380a:
	/* 0x380a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
	return 14348ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14348ULL: goto x86_l_380c;
	case 14354ULL: goto x86_l_3812;
	case 14358ULL: goto x86_l_3816;
	case 14364ULL: goto x86_l_381c;
	case 14369ULL: goto x86_l_3821;
	case 14371ULL: goto x86_l_3823;
	case 14377ULL: goto x86_l_3829;
	case 14381ULL: goto x86_l_382d;
	case 14387ULL: goto x86_l_3833;
	case 14392ULL: goto x86_l_3838;
	case 14394ULL: goto x86_l_383a;
	case 14400ULL: goto x86_l_3840;
	case 14404ULL: goto x86_l_3844;
	case 14410ULL: goto x86_l_384a;
	case 14415ULL: goto x86_l_384f;
	case 14421ULL: goto x86_l_3855;
	case 14426ULL: goto x86_l_385a;
	case 14432ULL: goto x86_l_3860;
	case 14437ULL: goto x86_l_3865;
	case 14443ULL: goto x86_l_386b;
	case 14448ULL: goto x86_l_3870;
	case 14454ULL: goto x86_l_3876;
	case 14459ULL: goto x86_l_387b;
	case 14464ULL: goto x86_l_3880;
	case 14469ULL: goto x86_l_3885;
	case 14475ULL: goto x86_l_388b;
	case 14480ULL: goto x86_l_3890;
	case 14485ULL: goto x86_l_3895;
	case 14490ULL: goto x86_l_389a;
	case 14496ULL: goto x86_l_38a0;
	case 14501ULL: goto x86_l_38a5;
	case 14507ULL: goto x86_l_38ab;
	case 14512ULL: goto x86_l_38b0;
	case 14518ULL: goto x86_l_38b6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_380c:
	/* 0x380c: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3812:
	/* 0x3812: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3816:
	/* 0x3816: jne    f4 <generic_sleepable_preload+0xf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 244ULL;
	}
x86_l_381c:
	/* 0x381c: jmp    3570 <generic_sleepable_preload+0x3570> */
	return 13680ULL;
x86_l_3821:
	/* 0x3821: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3823:
	/* 0x3823: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3829:
	/* 0x3829: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_382d:
	/* 0x382d: jne    102 <generic_sleepable_preload+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 258ULL;
	}
x86_l_3833:
	/* 0x3833: jmp    362f <generic_sleepable_preload+0x362f> */
	return 13871ULL;
x86_l_3838:
	/* 0x3838: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_383a:
	/* 0x383a: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3840:
	/* 0x3840: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3844:
	/* 0x3844: jne    110 <generic_sleepable_preload+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_384a:
	/* 0x384a: jmp    36ee <generic_sleepable_preload+0x36ee> */
	return 14062ULL;
x86_l_384f:
	/* 0x384f: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_3855:
	/* 0x3855: jmp    3120 <generic_sleepable_preload+0x3120> */
	return 12576ULL;
x86_l_385a:
	/* 0x385a: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_3860:
	/* 0x3860: jmp    31b6 <generic_sleepable_preload+0x31b6> */
	return 12726ULL;
x86_l_3865:
	/* 0x3865: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_386b:
	/* 0x386b: jmp    3249 <generic_sleepable_preload+0x3249> */
	return 12873ULL;
x86_l_3870:
	/* 0x3870: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_3876:
	/* 0x3876: jmp    32dc <generic_sleepable_preload+0x32dc> */
	return 13020ULL;
x86_l_387b:
	/* 0x387b: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_3880:
	/* 0x3880: jmp    336e <generic_sleepable_preload+0x336e> */
	return 13166ULL;
x86_l_3885:
	/* 0x3885: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_388b:
	/* 0x388b: jmp    33f8 <generic_sleepable_preload+0x33f8> */
	return 13304ULL;
x86_l_3890:
	/* 0x3890: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_3895:
	/* 0x3895: jmp    34b3 <generic_sleepable_preload+0x34b3> */
	return 13491ULL;
x86_l_389a:
	/* 0x389a: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_38a0:
	/* 0x38a0: jmp    3564 <generic_sleepable_preload+0x3564> */
	return 13668ULL;
x86_l_38a5:
	/* 0x38a5: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_38ab:
	/* 0x38ab: jmp    3623 <generic_sleepable_preload+0x3623> */
	return 13859ULL;
x86_l_38b0:
	/* 0x38b0: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_38b6:
	/* 0x38b6: jmp    36e2 <generic_sleepable_preload+0x36e2> */
	return 14050ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12424U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1784ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1789ULL && __x86_pc <= 3651ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3653ULL && __x86_pc <= 5538ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5543ULL && __x86_pc <= 7418ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7423ULL && __x86_pc <= 9207ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9212ULL && __x86_pc <= 10990ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10996ULL && __x86_pc <= 12813ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12816ULL && __x86_pc <= 14346ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14348ULL && __x86_pc <= 14518ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
